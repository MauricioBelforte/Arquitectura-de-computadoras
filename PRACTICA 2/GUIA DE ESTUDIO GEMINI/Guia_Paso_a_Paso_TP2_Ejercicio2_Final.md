# 🧠 Guía Paso a Paso: Multitarea por Copia de Stack (El Método de la Pizarra)
**Materia:** Arquitectura de Computadoras | **Ejercicio:** TP2 - Ejercicio 2

---

## 🌟 La Idea Central: Intercambio de Memoria de Datos (Stack Swapping)

En este ejercicio, queremos que 3 procesos (A, B y C) compartan el tiempo de una única CPU. Para lograrlo, implementaremos un kernel multitarea cooperativo basado en el método de **Copia de Stack**.

En la arquitectura dsPIC, la pila (Stack) y la memoria de datos (RAM) comparten el mismo espacio físico. El registro `WREG15` funciona como el Stack Pointer (SP / WREG15) global. Como solo existe un Stack Pointer (SP / WREG15) por hardware, todos los procesos deben utilizar la misma región de memoria de datos para sus contextos. Cuando el Quantum de un proceso expira:
1. El proceso actual detiene su ejecución por la interrupción. El hardware apila automáticamente el **Program Counter (PC)** y el **Status Register (SR)** (que incluye el Interrupt Priority Level - IPL). Luego, nuestro software apila el resto del contexto (**Registros de Trabajo (WREG0...WREG14)**) en la memoria RAM apuntada por el Puntero de Pila (SP / WREG15).
2. El kernel copia este bloque de memoria física (el stack actual) hacia un **Arreglo en RAM** dedicado a ese proceso para resguardarlo.
3. El kernel copia el bloque de memoria desde el arreglo del *siguiente* proceso hacia la región física del stack.
4. La CPU ejecuta un retorno de interrupción (`RETFIE`), desapilando los Registros de Trabajo (WREG0...WREG14) y el Program Counter (PC) del nuevo contexto, retomando su ejecución.

### 📊 Componentes Técnicos

| Componente | Función Técnica |
| :--- | :--- |
| **Memoria de Datos (Stack)** | Región de RAM donde se apilan dinámicamente el Program Counter (PC), Status Register (SR), Registros de Trabajo (WREG0...W14) y variables locales. |
| **Arreglos (`arregloProc`)** | Estructuras estáticas en RAM para resguardar el contexto completo de los procesos inactivos. |
| **Timer 1 (`_T1Interrupt`)** | Generador de interrupciones de hardware que delimita el tiempo de CPU (Quantum) asignado a cada proceso. |
| **`planificador()`** | Rutina de software (Scheduler) encargada de realizar la copia de bloques mediante aritmética de punteros. |
| **Puntero de Pila (SP / WREG15)** | Registro físico del dsPIC que contiene la dirección actual del tope de la pila en memoria. |

---

## 🚀 Estado Inicial del Sistema

Antes de que el primer proceso empiece a correr, el microcontrolador debe estar preparado:

1.  **Inicialización del W15:** Al encenderse, el compilador configura el **Puntero de Pila (SP / WREG15)** para que apunte al inicio del área de Stack en la **Memoria de Datos (RAM)**. Habitualmente, esto es la dirección **`0x0800`** (o inmediatamente después de las variables globales).
2.  **Arranque del Proceso A:** El `main()` llama directamente a la función `procesoA()`. En este momento, el `W15` empieza a subir a medida que el Proceso A usa la pila para sus cálculos.
3.  **Primer "Click" del Timer:** El sistema corre normalmente hasta que el Timer 1 genera la primera interrupción. Es en ese instante cuando el `W15` tiene un valor real (ej. `0x0888`) y el planificador entra a hacer el primer cambio.

---

## 🛠️ Paso 1: Buffers de Contexto (Los Arreglos)

Como el microcontrolador dsPIC33F posee un único Puntero de Pila (SP / WREG15) físico, necesitamos asignar bloques de memoria estática en RAM para resguardar el contexto de los procesos suspendidos.

```c
#define TOPE_ARREGLOS 18
unsigned int arregloProcA[TOPE_ARREGLOS];
unsigned int arregloProcB[TOPE_ARREGLOS];
unsigned int arregloProcC[TOPE_ARREGLOS];
```

#### 📋 ¿Qué hay exactamente dentro del arreglo? (Mapa de Memoria)

| Índice del Arreglo | Contenido Técnico | Descripción |
| :--- | :--- | :--- |
| `[0]` | **Program Counter (PC)** | La dirección de la línea de código donde debe volver el proceso. |
| `[1]` | **Status Register (SR)** | El estado de las banderas (Z, C, N) y bits de control del micro. |
| `[2]` al `[16]` | **Registros de Trabajo (WREG0...WREG14)** | Los valores temporales de las cuentas y variables que el proceso estaba usando. |
| `[17]` | **Pila Local / Extra** | Espacio de reserva para alineación. |

Usamos **18** posiciones (palabras de 16 bits) para el contexto básico del hardware.

---

## 🛠️ Paso 2: Construcción del Contexto Inicial (`init`)

Al arrancar el sistema, los procesos B y C nunca han sido ejecutados. Sus arreglos (`arregloProcB` y `arregloProcC`) están inicializados en cero por defecto. Si el planificador intentara volcar este contexto nulo en la Pila de Hardware, la instrucción de retorno cargaría un `0x0000` en el Program Counter (PC), causando una excepción de hardware (Address Error). Por ello, debemos pre-cargar manualmente su punto de entrada (`dirB` y `dirC`) en el índice `[0]` de la estructura.

#### ⚠️ Diferencia Crítica: Arquitectura Harvard
Es vital no confundir los dos espacios de memoria del dsPIC:
*   **Memoria de Programa (Flash):** Contiene las instrucciones del código. El **Program Counter (PC)** apunta aquí.
*   **Memoria de Datos (RAM):** Contiene las variables, los arreglos y la **Pila (Stack)**. El **Stack Pointer (SP / WREG15)** apunta aquí.

```c
void init(void) {
    arregloProcB[0] = dirB; // El Program Counter (PC) inicial de B
    arregloProcC[0] = dirC; // El Program Counter (PC) inicial de C
}
```

---

## 🛠️ Paso 3: El Planificador y la Regla del Match

Esta es la función algorítmica central del sistema. Utiliza aritmética de punteros para recorrer la memoria de datos (RAM física apuntada por W15).

```c
void planificador(void) {
    unsigned int* puntero = (unsigned int*)WREG15; 
    puntero -= DESPLAZAMIENTO; 
    // ... ciclo for de intercambio ...
}
```

### 🔬 Aritmética de Punteros: Ejemplo Real

1.  **Punto Cero:** El stack nace en `0x0862`.
2.  **Captura:** En la interrupción, el `W15` vale **`0x0892`**.
3.  **Caza del PC:** Escaneamos la RAM buscando el valor de Flash (ej. `0x0454`). Lo encontramos en **`0x086E`**.

![File Register](File_register.png)
*Figura 1: Vista de File Registers en MPLAB X. El PC se encuentra exactamente a 18 words del tope.*

4.  **Validación Matemática:**
    *   `0x0892` (Tope) - `0x086E` (PC) = `0x24` bytes.
    *   `0x24` / 2 = **18 words**.
    *   Por lo tanto, **`DESPLAZAMIENTO = 18`**.

---

## 📝 Resumen para la defensa:

Si el profesor te pregunta cómo funciona tu código, recuerda estas palabras clave:

1.  **Contexto:** Es el conjunto de PC, SR y W0-W14. Es la "mente" del proceso.
2.  **Stack Swapping:** Es la técnica de intercambiar el contenido de la pila física con arreglos en RAM.
3.  **Quantum:** Es el tiempo de vida (en ticks de Timer1) que le damos a cada proceso.
4.  **Aritmética de Punteros:** Es lo que nos permite mover bloques de memoria sin mover el `W15`.

---
> [!TIP]
> **Conclusión Técnica:** El desplazamiento es 18 porque el hardware del dsPIC guarda exactamente ese tamaño de contexto antes de que nuestro código tome el control en el planificador.
