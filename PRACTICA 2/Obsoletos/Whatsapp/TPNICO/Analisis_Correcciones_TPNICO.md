# 🔍 Análisis y Correcciones — Solución de Nico (TPNICO)
**Materia:** Arquitectura de Computadoras 2026
**Tema:** Trabajo Práctico 2 - Ejercicio 2 (Multitask)

---

## 📜 Enunciado Oficial (Ejercicio 2)

> **Multitask:** Escribir un programa que simule la ejecución de tres procesos independientes (`procesoA`, `procesoB` y `procesoC`) y concurrentes. El programa debe constar de los tres procesos, una rutina de atención para la interrupción de un reloj y un planificador que alterna el uso de la CPU entre los tres procesos.
>
> Para resolver este ejercicio tomen como base el `proyectobase2b.X` entregado por la cátedra. En este proyecto encontrarán un esqueleto de solución. **El código de los tres procesos ya está presente** y se recomienda NO modificarlos. El código de la función `boot()` en `kernel.c` también está completo. Si ejecutan el proyecto tal cual está, sólo se ejecutará el `procesoA`.
>
> **Requerimientos:**
> - Asignar idéntico quantum (2 interrupciones de reloj).
> - El planificador debe resguardar los registros del proceso actual (estado), recuperar el estado del siguiente y restablecer el quantum.
> - Estructura de datos apropiada para contener el estado de los procesos.
>
> *Nota: Se puede asignar el nombre de una función a una variable para obtener su dirección (`direccion = procesoA;`).*

---

## 🧐 ¿Por qué el enunciado dice que los procesos "ya están"?
Si no los ves en tu proyecto, es probable que estés mirando `kernel.c`. El enunciado se refiere a que el archivo **`main.c`** ya trae las funciones `procesoA`, `procesoB` y `procesoC` escritas. Tú solo debes ocuparte de la "magia" en el kernel para que el micro salte de una a otra.

---

## 📋 Resumen del Análisis de TPNICO
1. Simular la ejecución de **3 procesos independientes** (`procesoA`, `procesoB`, `procesoC`) de forma **concurrente**.
2. El programa debe tener: los 3 procesos, una **rutina de atención de interrupción de un reloj** y un **planificador** que alterne el uso de la CPU.
3. Los procesos tienen asignado un **quantum idéntico de 2 interrupciones de reloj**.
4. Cuando expira el quantum, la ISR invoca al planificador.
5. El planificador debe:
   - **Resguardar** los valores de los registros del proceso actual (estado).
   - **Recuperar** el estado del proceso siguiente.
   - **Restablecer** el quantum.
6. Se debe usar un **Timer** para generar las interrupciones de reloj.
7. Los procesos (`procesoA`, `procesoB`, `procesoC`) **NO deben modificarse**.

---

## 📁 Archivos analizados

| Archivo | Rol |
|---|---|
| `kernel.h` | Constantes y prototipos |
| `kernel.c` | `init()`, `confReloj()`, `boot()`, `planificador()`, ISR del Timer |
| `main.c` | Definición de los 3 procesos + `main()` |

---

## 🔎 Archivo 1: `kernel.h`

```c
#define TOPE_ARREGLOS 38
#define QUANTUM 2
#define DESPLAZAMIENTO 38
#define VALOR_PR1 6000       // 150us con prescaler 1:1

void boot(void);
```

### Observaciones

| # | Severidad | Detalle |
|---|---|---|
| H.1 | ⚠️ Riesgo | `TOPE_ARREGLOS = 38` y `DESPLAZAMIENTO = 38` son valores "mágicos". No hay documentación de cómo se calcularon. Si los procesos usan más stack del esperado (por ejemplo, si el compilador agrega variables temporales extra), estos valores quedan cortos y se corrompe la memoria. |
| H.2 | ℹ️ Nota | `VALOR_PR1 = 6000` con prescaler 1:1 da exactamente 150µs a 40 MHz (Fcy). Esto está **correcto** si el reloj del sistema es 40 MHz. |
| H.3 | ℹ️ Nota | El `#define` de `TOPE_ARREGLOS` está **fuera** del bloque `#ifndef KERNEL_H`. No causa error de compilación porque el preprocesador lo procesa igual, pero es mala práctica: si alguien incluye `kernel.h` dos veces, esos `#define` se duplicarían (aunque sin consecuencia funcional por ser idénticos). |

---

## 🔎 Archivo 2: `main.c`

```c
#include <p33FJ256GP710.h>
#include "xc.h"
#include <stdio.h>
#include <stdlib.h>
#include "kernel.h"

void procesoA(void) { /* ... while(1) ... */ }
void procesoB(void) { /* ... while(1) ... */ }
void procesoC(void) { /* ... while(1) ... */ }

int main(int argc, char** argv) {
    unsigned int dirA=(unsigned int)procesoA;
    unsigned int dirB=(unsigned int)procesoB;
    unsigned int dirC=(unsigned int)procesoC;
    boot();
    procesoA();
    return (EXIT_SUCCESS);
}
```

### ✅ Lo que está bien
- Los 3 procesos (`procesoA`, `procesoB`, `procesoC`) son idénticos al proyecto base de la cátedra. **No los modificó**, tal como pide el enunciado. ✔️
- Se llama a `boot()` antes de `procesoA()`, respetando la secuencia de arranque. ✔️
- La idea de capturar las direcciones de las funciones (`dirA`, `dirB`, `dirC`) es correcta conceptualmente, tal como sugiere la "Nota" del enunciado.

### 🐛 Errores encontrados

| # | Severidad | Línea(s) | Descripción |
|---|---|---|---|
| M.1 | 🔴 **Crítico** | `main()` | **`dirA`, `dirB` y `dirC` son variables locales**, pero en `kernel.c` se las declara como `extern`. El linker (`ld`) **no las encontrará** porque las variables locales viven en el stack de `main` y no tienen enlace externo (external linkage). Esto generará un **error de compilación/enlace**: `undefined reference to 'dirA'`. |

**Corrección para M.1:** Mover las tres declaraciones **fuera** de la función `main()` para que sean variables globales:
```c
unsigned int dirA;
unsigned int dirB;
unsigned int dirC;

int main(int argc, char** argv) {
    dirA = (unsigned int)procesoA;
    dirB = (unsigned int)procesoB;
    dirC = (unsigned int)procesoC;
    boot();
    procesoA();
    return (EXIT_SUCCESS);
}
```

---

## 🔎 Archivo 3: `kernel.c` (El corazón del kernel)

Este es el archivo más extenso y donde se concentran los problemas. Lo analizo función por función.

---

### 3.1 — Variables Globales

```c
extern unsigned int dirA;
extern unsigned int dirB;
extern unsigned int dirC;

unsigned int arregloProcA[TOPE_ARREGLOS];  // 38 posiciones
unsigned int arregloProcB[TOPE_ARREGLOS];
unsigned int arregloProcC[TOPE_ARREGLOS];
int contT1 = 0;
int estadoProceso = 0;
```

| # | Severidad | Detalle |
|---|---|---|
| K.1 | 🔴 Crítico | `extern unsigned int dirA/dirB/dirC` — Enlaza con las variables de `main.c`, pero como se indicó en **M.1**, esas variables son locales y el `extern` **fallará en la compilación**. |
| K.2 | ⚠️ Diseño | Usar 3 arreglos de 38 `unsigned int` (= 228 bytes de RAM) para simular la pila es **costoso en memoria** para el dsPIC33F. La técnica de multi-stack (punteros de pila separados) usa la misma cantidad de RAM pero sin necesidad de copiar datos. |

---

### 3.2 — Función `init()`

```c
void init(void){
    int i;
    for(i=0; i<TOPE_ARREGLOS; i++){
        arregloProcA[i] = 0;
        arregloProcB[i] = 0;
        arregloProcC[i] = 0;
    }
    arregloProcA[0] = dirA;
    arregloProcB[0] = dirB;
    arregloProcC[0] = dirC;
}
```

| # | Severidad | Detalle |
|---|---|---|
| K.3 | 🔴 **Crítico** | **Inicialización incompleta del Stack Frame.** Solo guarda la dirección de la función en `[0]`. Pero cuando el dsPIC ejecuta `RETFIE` (retorno de interrupción), espera encontrar en el stack al menos: `PC_Low` (dirección de retorno baja), `PC_High/SR` (bits altos del PC + Status Register). Al tener solo 1 valor y el resto en ceros, el `RETFIE` podría funcionar parcialmente (SR=0 no es fatal), pero el **orden de los datos en el stack no coincide con lo que el hardware espera** al salir de la interrupción. |
| K.4 | ⚠️ Riesgo | **No se inicializan los registros W0-W14 en los arreglos.** Cuando el planificador intente "restaurar" el Proceso B por primera vez, escribirá ceros en los registros de trabajo. Esto es un problema menor porque los procesos reinicializan sus variables al entrar, pero es una fragilidad: si un proceso dependiera de un valor inicial en un registro, fallaría silenciosamente. |

**¿Qué debería tener un stack frame inicial correcto?**
En el dsPIC33F, una interrupción apila automáticamente (en este orden de abajo hacia arriba):
1. `PC[15:0]` — 16 bits bajos del Program Counter
2. `PC[22:16]` + `SR` — empaquetados en una sola palabra de 16 bits

Después, el código del kernel debería apilar los registros de trabajo `W0` a `W14` (15 posiciones más).
Total mínimo = **17 posiciones** ocupadas antes de que el proceso empiece a usar su propio stack.

---

### 3.3 — Función `confReloj()`

```c
void confReloj(void){
    T1CON = 0;
    T1CONbits.TCS = 0;    // Reloj interno
    T1CONbits.TCKPS = 0;  // Prescaler 1:1
    PR1 = VALOR_PR1;      // 6000 → 150µs

    IFS0bits.T1IF = 0;
    IPC0bits.T1IP = 5;
    IEC0bits.T1IE = 1;
    T1CONbits.TON = 1;
}
```

| # | Severidad | Detalle |
|---|---|---|
| K.5 | ✅ Correcto | La configuración del Timer1 es funcional. Prescaler 1:1, PR1=6000 da 150µs @ Fcy=40MHz. |
| K.6 | ℹ️ Nota | `T1IP = 5` es una prioridad media-alta. Para un kernel, puede funcionar, pero vale la pena documentarlo para la defensa oral. |
| K.7 | ℹ️ Menor | Falta `TMR1 = 0;` para asegurar que el contador del timer arranca desde cero. No es crítico porque `T1CON = 0` ya resetea la mayoría de los bits, pero es buena práctica. |

---

### 3.4 — Función `planificador()` — ⚠️ SECCIÓN MÁS PROBLEMÁTICA

```c
void planificador(void){
    unsigned int* puntero = WREG15 - DESPLAZAMIENTO;
    int i;
    switch(estadoProceso){
        case 0: // A → B
            for(i=0; i<TOPE_ARREGLOS; i++){
                arregloProcA[i] = *puntero;    // Guarda stack actual en arreglo A
                *puntero = arregloProcB[i];    // Escribe arreglo B en el stack
                puntero++;
            }
            estadoProceso++;
            break;
        case 1: // B → C
            for(i=0; i<TOPE_ARREGLOS; i++){
                arregloProcB[i] = *puntero;
                *puntero = arregloProcC[i];
                puntero++;
            }
            estadoProceso++;
            break;
        case 2: // C → A
            for(i=0; i<TOPE_ARREGLOS; i++){
                arregloProcC[i] = *puntero;
                *puntero = arregloProcA[i];
                puntero++;
            }
            estadoProceso = 0;
            break;
    }
}
```

| # | Severidad | Detalle |
|---|---|---|
| K.8 | 🔴 **Crítico** | **No se resguardan los registros W0-W14 antes de intercambiar.** El enunciado dice textualmente: *"El planificador debe resguardar los valores de los registros del proceso actual"*. Nico intenta leer directamente de la memoria del stack, pero los registros de trabajo (`W0` a `W14`) **están en los registros del CPU, no en el stack**. Si no se hace `PUSH W0`...`PUSH W14` **antes** de entrar al planificador, los valores de esos registros del proceso actual se pierden irreversiblemente al ser sobreescritos por el código del propio planificador. |
| K.9 | 🔴 **Crítico** | **El cálculo `WREG15 - DESPLAZAMIENTO` es frágil y potencialmente incorrecto.** `WREG15` apunta al tope del stack en el momento en que se ejecuta esta línea. Pero para cuando el código llega aquí, ya se apilaron: el frame de interrupción (PC+SR = ~3 palabras), el frame de la ISR `_T1Interrupt` (variables locales del compilador), y el frame de `planificador()` (variable `puntero`, `i`, dirección de retorno). El `DESPLAZAMIENTO = 38` es un intento de "retroceder" hasta el fondo del stack del proceso interrumpido, pero este valor **depende del nivel de optimización del compilador** y de cuántas funciones anidadas haya. Si el compilador cambia la cantidad de variables temporales, 38 deja de ser correcto y se corrompe toda la memoria. |
| K.10 | 🔴 **Crítico** | **El intercambio de memoria (swap in-place) modifica el stack MIENTRAS la ISR lo está usando.** Cuando `planificador()` escribe valores del Proceso B sobre el stack actual, está pisando las direcciones de retorno de `planificador()` y de `_T1Interrupt()`. Al hacer `return` del planificador, el CPU leerá una dirección de retorno que pertenece al Proceso B, que fue calculada asumiendo que el proceso B estaba en un punto diferente del código. Esto provocaría un **salto a una dirección arbitraria** y un crash inmediato. |
| K.11 | ⚠️ Rendimiento | **Copiar 38 palabras dentro de una ISR es muy lento.** El loop `for` ejecuta ~38 × 4 instrucciones ≈ 152 instrucciones extra por cambio de contexto. En comparación, la técnica de cambio de W15 necesita solo ~2 instrucciones (`MOV WREG15` + `MOV` al nuevo valor). Nico genera un overhead de **~75 veces más ciclos** que lo necesario. |

**K.8, K.9 y K.10 son errores fatales.** Cualquiera de los tres, por separado, haría que el programa falle. Juntos, hacen que la solución sea **no funcional** tal como está.

---

### 3.5 — ISR del Timer (`_T1Interrupt`)

```c
void __attribute__((interrupt, auto_psv)) _T1Interrupt( void ){
    IFS0bits.T1IF = 0;
    if(++contT1 == QUANTUM){
        planificador();
    }
}
```

| # | Severidad | Detalle |
|---|---|---|
| K.12 | 🔴 **Crítico** | **`contT1` nunca se resetea a 0.** Después del primer cambio de contexto (`contT1` llega a 2), el contador sigue incrementándose: 3, 4, 5... La condición `contT1 == QUANTUM` **nunca más se cumple**. Resultado: el planificador se ejecuta **una sola vez** y luego el Proceso B corre para siempre sin que nadie lo interrumpa. Los procesos A y C mueren. |
| K.13 | ℹ️ Menor | Falta un `else` o `return` explícito. Si el quantum no expiró, la ISR solo baja la bandera y vuelve, lo cual es correcto. Pero por legibilidad convendría documentar ese caso. |

**Corrección para K.12:** Agregar `contT1 = 0;` dentro del `if`:
```c
if(++contT1 == QUANTUM){
    contT1 = 0;   // ← FALTABA ESTO
    planificador();
}
```

---

## 📊 Resumen de Errores

| ID | Archivo | Severidad | Descripción corta |
|---|---|---|---|
| **M.1** | `main.c` | 🔴 Crítico | Variables `dirA/B/C` son locales → `extern` falla en compilación |
| **K.3** | `kernel.c` | 🔴 Crítico | Stack frame inicial incompleto (falta SR, orden incorrecto) |
| **K.8** | `kernel.c` | 🔴 Crítico | No se hace PUSH/POP de W0-W14 (registros del proceso actual) |
| **K.9** | `kernel.c` | 🔴 Crítico | `DESPLAZAMIENTO` fijo = frágil, depende del compilador |
| **K.10** | `kernel.c` | 🔴 Crítico | Swap in-place pisa direcciones de retorno de la propia ISR |
| **K.12** | `kernel.c` | 🔴 Crítico | `contT1` no se resetea → planificador corre solo 1 vez |
| H.1 | `kernel.h` | ⚠️ Riesgo | Constantes mágicas sin justificación documentada |
| K.2 | `kernel.c` | ⚠️ Diseño | Uso excesivo de RAM para copiar stacks completos |
| K.11 | `kernel.c` | ⚠️ Rendimiento | ~152 instrucciones extra por context switch dentro de ISR |
| H.3 | `kernel.h` | ℹ️ Menor | `#define` fuera del `#ifndef` guard |
| K.7 | `kernel.c` | ℹ️ Menor | Falta `TMR1 = 0` explícito |

---

## 💡 Veredicto y Método del Profesor

Tras revisar las fotos de la pizarra, confirmamos que el profesor requiere el método de **Copia de Stack (Stack Swapping)**. 

### ¿Cómo funciona este método?
En lugar de tener muchas pilas, tenemos **una sola pila física** (el stack de hardware) y tres arreglos en RAM que actúan como "depósitos". 
1. Cuando hay cambio de proceso, el planificador "vacía" la pila actual en el arreglo del proceso que sale.
2. Luego "llena" la pila con los datos del arreglo del proceso que entra.

### Correcciones necesarias al método de Nico para que funcione:
Aunque usemos el método de la pizarra, el código de Nico necesita 3 ajustes vitales:
1. **Resguardo de Registros W0-W14:** Aunque el profesor no lo dibuje en cada esquema, es obligatorio guardar los registros de trabajo antes de vaciar la pila, de lo contrario los cálculos se corrompen.
2. **Reset de Quantum:** Hay que poner `contT1 = 0` dentro del `if`.
3. **Cálculo del Puntero:** El `DESPLAZAMIENTO` debe ser preciso para no pisar la propia función del planificador.

---

**Para la defensa oral:** Si les preguntan por qué no usaron el enfoque de "swap de memoria", pueden explicar que:
- Es conceptualmente válido pero **peligroso** porque depende de constantes que varían según el compilador.
- Es **ineficiente** porque copia N palabras por cada context switch en lugar de mover un solo puntero.
- El estándar en sistemas operativos reales (FreeRTOS, µC/OS) es usar **punteros de pila separados**.
