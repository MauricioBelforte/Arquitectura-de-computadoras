# Walkthrough: Trabajo Práctico 2 - Ejercicio 2 (Kernel Multitarea - Stack Swap)
**Materia:** Arquitectura de Computadoras
**Arquitectura:** dsPIC33F (Arquitectura Harvard)

Este documento detalla el funcionamiento exacto del Ejercicio 2 (entregado y aprobado). Se explican los mecanismos físicos de manipulación del Puntero de Pila (WREG15) para lograr un intercambio de contexto (Context Switching) mediante Round-Robin.

---

## 1. Concepto de Context Switching (Stack Swap)

A diferencia de un flujo normal donde los procesos corren hasta terminar (`return`), en este kernel ejecutamos 3 tareas de bucle infinito (`procesoA`, `procesoB`, `procesoC`).
La única forma de alternar entre ellos es engañar al hardware. Cuando ocurre la interrupción del `Timer1`:
1.  El microcontrolador guarda el estado de la tarea actual en la **Pila física (Stack)**.
2.  El Kernel **copia** toda la información de la pila a un "Arreglo de Resguardo" (ej. `arregloProcA`).
3.  El Kernel **sobrescribe** la pila física con la información guardada del siguiente proceso (ej. `arregloProcB`).
4.  Al forzar el retorno de interrupción (`RETFIE`), el hardware obedece a la nueva pila y salta directamente a la siguiente tarea.

---

## 2. Identificación e Inicialización de Tareas (A, B y C)

En este sistema, **A, B y C** representan tres **Procesos o Tareas independientes** (hilos de ejecución) que compiten por el tiempo de la CPU. Cada uno es una función de C con un bucle infinito que realiza una acción específica (ej. parpadear un LED o incrementar un contador).

*   **Proceso A, B y C:** Son las entidades lógicas que el Kernel debe alternar.
*   **`dirA`, `dirB`, `dirC`**: Son las direcciones físicas en la **Memoria de Programa** donde comienza el código de cada función.

Antes de correr los procesos, se necesita "falsificar" los contextos iniciales en la función `init()`:
```c
void init(void){
    // ... inicialización de registros en 0 ...
    arregloProcA[0]=dirA; // PC inicial del Proceso A
    arregloProcB[0]=dirB; // PC inicial del Proceso B
    arregloProcC[0]=dirC; // PC inicial del Proceso C
}
```
En las direcciones `[0]` de los arreglos se guardan las direcciones base de las funciones. Esto garantiza que la primera vez que el planificador cargue el contexto en la pila física, el hardware encuentre la dirección correcta (Program Counter) para saltar a la tarea.

---

## 3. El Planificador y la Aritmética de Punteros

El corazón del ejercicio es la función `planificador()`, la cual trasplanta los bloques de memoria.

### Puntero de Pila (WREG15) y Desplazamiento
```c
unsigned int* puntero=WREG15;   
puntero-=DESPLAZAMIENTO;        
```
Cuando entramos a la interrupción de Timer1 y luego a la función `planificador()`, el Puntero de Pila (`WREG15`) se encuentra en el "tope" de la pila, habiendo apilado registros adicionales para la llamada a la función.
Para copiar todo el **marco de interrupción**, es imperativo retroceder el puntero hasta la "base" de los datos del proceso interrumpido. `DESPLAZAMIENTO` representa la cantidad matemática exacta de saltos (words / 16 bits) que el puntero debe retroceder para apuntar al primer elemento empujado por el hardware: el **Program Counter (PC)**.

### El Intercambio en el Switch-Case
```c
switch(estadoProceso){
    case 0: //A hacia B
        for(i=0; i<TOPE_ARREGLOS ; i++){
            arregloProcA[i]=*puntero;   // Guarda pila de A
            *puntero=arregloProcB[i];   // Reemplaza por pila de B
            puntero++;
        }
        estadoProceso++;
        break;
// ... (Repite para B->C y C->A)
```
**Operación a bajo nivel:**
1.  **Lectura:** `*puntero` accede a la Pila física en RAM. Lee el valor (PC, SR o registros W) y lo resguarda a salvo en la variable global `arregloProcA[i]`.
2.  **Escritura:** Inmediatamente después, inserta en esa misma dirección de memoria física de la Pila el contenido guardado en `arregloProcB[i]`.
3.  **Avance:** `puntero++` avanza a la siguiente dirección del Stack (subiendo en la RAM).

Cuando termina el ciclo for, toda la "conciencia" del Proceso A está respaldada estáticamente en RAM, y la Pila física está completamente dominada por el contexto del Proceso B. 

---

## 4. El Ciclo de Interrupción (`_T1Interrupt`)

```c
void __attribute__((interrupt, auto_psv)) _T1Interrupt( void ){
    IFS0bits.T1IF = 0;
    if(++contT1==QUANTUM){  
        contT1=0;           
        planificador();     
    }
}
```
*   **QUANTUM:** Representa la porción de tiempo máxima otorgada a un proceso para utilizar la CPU. Como el `Timer1` se dispara en intervalos configurables, se requieren varios disparos (`contT1`) para alcanzar el `QUANTUM` completo.
*   **Alternancia Constante:** Cuando se llega al `QUANTUM`, se llama al planificador. Al salir del planificador, la función termina y ejecuta por hardware un `RETFIE`. Esa instrucción saca de la pila el PC (que ahora es el de Proceso B) y salta al código del proceso nuevo sin que este lo note.

---

## 5. Guía de Testeo y Simulación en MPLAB X (Direcciones Reales)

Para validar que el Kernel está "trasplantando" los contextos correctamente, debemos observar las entrañas del dsPIC33F durante la simulación. Esta sección la construiremos juntos mientras analizas tu entorno de MPLAB X.

### Paso 1: Preparación del Entorno
Antes de empezar, asegurate de tener el proyecto abierto y configurado para simulación (*Simulator*).

> **Punto de Control Técnico:** 
> 1. El `QUANTUM` está configurado en **2** (se requieren 2 disparos del Timer1 para cambiar de proceso).
> 2. El `DESPLAZAMIENTO` es **18** (esto es lo que retrocedemos `W15` para encontrar el contexto guardado).
> 3. En el menú de MPLAB X: `Window -> Debugging`, ¿tenés abiertas las ventanas de **Watches**, **Variables** y **Disassembly**?
> 4. **Misión:** Buscá en **Disassembly** las funciones `procesoA`, `procesoB` y `procesoC`. Pasame las direcciones hexadecimales (`0x...`) donde comienzan.

---

### Paso 2: Ubicación Estratégica de Breakpoints
Para observar el trasplante de memoria, colocá los siguientes puntos de parada haciendo clic en el número de línea:

1.  **En `main.c`, línea 60 (`procesoA();`):**
    *   **Propósito:** Ver que las direcciones de inicio ya se cargaron en los arreglos.
    *   **Valores Reales observados:**
        *   **`W15` = `0x0862`**: El Puntero de Pila está en la zona alta de la RAM de datos.
        *   **`arregloProcA[0]` = `0x0444`**: Esta es la dirección física en la Memoria de Programa donde vive la función `procesoA`.
    *   **Qué observar:** Abrí la ventana de **Watches**, agregá `arregloProcA` y verificá que coincida con lo que ves en el **Disassembly**.
2.  **En `kernel.c`, línea 80 (dentro de `_T1Interrupt`):**
    *   **Propósito:** Detectar el momento exacto en que el Timer1 decide que es hora de cambiar de proceso.
    *   **Valores Reales observados:**
        *   **`W15` = `0x0888`**: Observamos que la pila creció (de `0x0862` a `0x0888`). Esto ocurre porque el hardware y el compilador "empujaron" (PUSH) el Program Counter y los registros de trabajo para no perder el estado del Proceso A.
    *   **Acción:** Dale a **Play (F5)** y espera a que se detenga ahí.
3.  **En `kernel.c`, línea 47 (primera línea de `planificador()`):**
    *   **Propósito:** Ver la aritmética de punteros. 
    *   **Qué observar:** Agregá el registro **W15** a los Watches. Mirá su valor. Luego, dale a **Step Over (F8)** para ejecutar `puntero-=DESPLAZAMIENTO;` y fijate cómo el puntero ahora apunta 18 posiciones más abajo en la RAM.

---

### Paso 3: El "Trasplante" de Memoria
Con el programa detenido en el `planificador()` (Paso 2.3), hacé lo siguiente:

1.  **Inspección de Pila:** Buscá la dirección de RAM que tiene el `puntero` (W15 - 18).
2.  **Ejecución Paso a Paso:** Usá **F8** para entrar al ciclo `for`. 
3.  **La Pregunta Clave:** 
    *   ¿Ves cómo el valor en `arregloProcA[i]` cambia por un número que parece una dirección de memoria? 
    *   ¿Y cómo el valor en la Pila (RAM física) cambia por el contenido de `arregloProcB[i]`?

> **Punto de Control para el usuario:**
> Pasame los valores que ves en:
> *   `W15` (antes de entrar al planificador).
> *   `arregloProcA[0]` (después de que se ejecute la primera línea del `for`).
> *   La dirección de memoria a la que apunta `puntero`.

