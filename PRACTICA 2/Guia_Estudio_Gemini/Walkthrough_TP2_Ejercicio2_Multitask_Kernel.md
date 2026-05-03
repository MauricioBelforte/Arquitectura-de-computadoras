# Tutorial Paso a Paso: TP2 Ejercicio 2 (Multitarea / Kernel)

Este documento explica de forma pedagógica y cronológica cómo construir un **Micro-Kernel Multitarea** para el dsPIC33F desde cero. Si el Ejercicio 1 era sobre comunicación, este es sobre el **control absoluto de la CPU**.

---

## 1. El Concepto: Multitarea Preventiva (Preemptive Multitasking)

Imaginá que tenés un solo televisor (la CPU) y tres hermanos (Proceso A, B y C) que quieren ver canales distintos. Como no pueden verlo al mismo tiempo, vos (el Kernel) hacés lo siguiente:
1.  Le das el control al Hermano A por 2 minutos (**Quantum**).
2.  Cuando suena el despertador (**Timer**), entrás al living, le sacás el control remoto, anotás exactamente por qué minuto de la película iba, y lo mandás a dormir.
3.  Despertás al Hermano B, le das el control remoto y le decís: "Seguí viendo tu película desde el minuto 10 que fue donde te quedaste la última vez".

---

## PASO 1: El Bloque de Control de Proceso (PCB)

Para poder "anotar dónde se quedó" cada hermano, necesitamos una libreta. En informática, esa libreta se llama **PCB (Process Control Block)**.

```c
typedef struct {
    unsigned int sp; // Acá guardamos el Stack Pointer (Puntero de Pila, W15)
} PCB;

PCB procesos[3];         // Nuestra libreta para los 3 hermanos (A, B y C)
int procesoActual = 0;   // ¿Quién tiene el control remoto ahora?
int quantum = 2;         // Crédito de tiempo: cada 2 interrupciones cambiamos de hermano.
```

> **¿Por qué solo guardamos el SP?** Porque el `SP` es la dirección de la memoria (Pila) donde están guardados todos los demás secretos del proceso (sus variables locales y sus registros de trabajo). Si sabemos dónde empieza su pila, sabemos todo.

---

## PASO 2: Las Pilas Propias (Stacks)

Si los tres hermanos usan el mismo sillón (la misma pila), cuando el Hermano B se siente, va a aplastar las cosas que dejó el Hermano A. Por eso, necesitamos **tres sillones independientes**.

```c
unsigned int stackA[128]; // Sillón para el Proceso A
unsigned int stackB[128]; // Sillón para el Proceso B
unsigned int stackC[128]; // Sillón para el Proceso C
```

---

## PASO 3: El Engaño Maestro (Falsificando la Pila)

El Proceso A arranca solo desde el `main()`. Pero los procesos B y C están "dormidos" y nunca fueron ejecutados. Tenemos que **mentirle a la CPU** y armar sus pilas como si ya hubieran estado corriendo antes.

En el dsPIC, cuando una interrupción "congela" a alguien, guarda automáticamente:
1.  **PC (Program Counter):** La dirección de la línea de código.
2.  **SR (Status Register):** El estado de las banderas.

```c
void init(void) {
    // Falsificamos la pila del Proceso B
    stackB[0] = (unsigned int)procesoB; // Le decimos que cuando "despierte" salte a la función procesoB
    stackB[1] = 0x0000;                 // Status Register en cero
    
    // Luego simulamos que ya guardamos los 15 registros de trabajo (W0-W14).
    // Dejamos 15 espacios vacíos y apuntamos el SP al final de ese hueco.
    procesos[1].sp = (unsigned int)&stackB[17]; 

    // Repetimos con el Proceso C
    stackC[0] = (unsigned int)procesoC;
    stackC[1] = 0x0000;
    procesos[2].sp = (unsigned int)&stackC[17];
}
```

---

## PASO 4: El Resguardo del Estado (Cambio de Contexto)

Como el lenguaje C no sabe cómo guardar "todos los registros de la CPU de un solo golpe", tenemos que usar un poquito de **Ensamblador (Assembly)**. Creamos dos macros: una para guardar y otra para recuperar.

```c
// GUARDAR: Metemos W0 hasta W14 en la pila (push)
#define GUARDAR_CONTEXTO() \
    asm volatile("push.d w0 \n push.d w2 \n push.d w4 \n push.d w6 \n push.d w8 \n push.d w10 \n push.d w12 \n push w14")

// RESTAURAR: Sacamos de la pila hacia los registros (pop)
#define RESTAURAR_CONTEXTO() \
    asm volatile("pop w14 \n pop.d w12 \n pop.d w10 \n pop.d w8 \n pop.d w6 \n pop.d w4 \n pop.d w2 \n pop.d w0")
```

---

## PASO 5: El Planificador (La Calesita)

El planificador es el que decide quién sigue. En este ejercicio es un simple **Round-Robin** (uno tras otro).

```c
void planificador(void) {
    procesoActual++; // Pasamos al siguiente
    if (procesoActual > 2) {
        procesoActual = 0; // Si llegamos a C, volvemos a A
    }
    quantum = 2; // ¡Súper importante! Le renovamos el crédito de tiempo al nuevo hermano.
}
```

---

## PASO 6: El Gran Final (La Interrupción del Reloj)

Todo ocurre adentro de la interrupción del Timer. Es el árbitro que decide cuándo se acaba el tiempo.

```c
void __attribute__((interrupt, auto_psv)) _T1Interrupt( void ) {
    IFS0bits.T1IF = 0; // Bajamos bandera
    quantum--;         // Restamos tiempo
    
    if (quantum == 0) {
        // --- INICIA CAMBIO DE CONTEXTO ---
        
        // 1. Guardamos registros (W0-W14) en la pila actual
        GUARDAR_CONTEXTO();
        
        // 2. Guardamos el Puntero de Pila (WREG15) en nuestra libreta (PCB)
        procesos[procesoActual].sp = WREG15;
        
        // 3. Cambiamos de procesoActual y reseteamos quantum
        planificador();
        
        // 4. CAMBIAMOS EL SILLÓN: Le cargamos a la CPU el Stack Pointer del nuevo proceso
        WREG15 = procesos[procesoActual].sp;
        
        // 5. Sacamos los registros de la nueva pila
        RESTAURAR_CONTEXTO();
        
        // Al salir de la función, el hardware ejecuta RETFIE. 
        // Como cambiamos la pila, el RETFIE leerá el PC que falsificamos en el PASO 3
        // y saltará mágicamente a ejecutar el Proceso B o C.
    }
}
```

---

## Resumen de la Lección
Para lograr que un microcontrolador de un solo núcleo haga "multitarea", no necesitamos magia, necesitamos **engañar al Stack Pointer**.
1.  **Aislamos** a los procesos en pilas distintas.
2.  **Falsificamos** el inicio de sus pilas para que la CPU crea que ya estaban corriendo.
3.  **Interrumpimos** periódicamente para intercambiar esas pilas.

Este es el principio básico de cómo funcionan Windows, Linux o Android, pero reducido a su mínima expresión en un dsPIC.
