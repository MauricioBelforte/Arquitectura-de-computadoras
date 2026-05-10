# Análisis Alternativo: TP2 Ejercicio 1 - Productor/Consumidor (por Claude)

> Este documento es un **complemento** al Walkthrough original creado por Gemini. No reemplaza ni modifica el existente. Ofrece una segunda perspectiva enfocada en **qué pasa exactamente en la memoria** cuando el sistema corre.

---

## Enunciado Oficial: Ejercicio 1 (Productor/Consumidor)
Implementar un buffer circular gestionado por interrupciones. Un Productor (ISR de INT1) filtra y almacena caracteres válidos. Un Consumidor (main) los traslada a un Log de Operaciones con temporización dinámica (150us base, incremento lineal hasta 900us).

---

## Mi Enfoque: Ver la Memoria en Acción

La guía de Gemini explica todo con la analogía de la pizzería (cocinero, mostrador, mozo). Es perfecta para entender el flujo. Yo voy a hacer algo distinto: voy a **dibujar la memoria** en cada momento clave para que veas físicamente cómo se mueven los datos por los arreglos.

---

## 1. El Buffer Circular: Anatomía de la Memoria

El buffer tiene **10 posiciones** (`TAM_BUFFER = 10`). Arrancan todas vacías.

```
Estado Inicial:
                    indBuffer = 0 (aguja de ESCRITURA)
                    indConsum = 0 (aguja de LECTURA)
                    caracteresPendientes = 0

buffer[]:  [ _ ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ]
             ↑
         indBuffer = 0
         indConsum = 0
         (Las dos agujas están juntas: no hay nada que leer)
```

### ¿Qué pasa cuando llegan 3 caracteres válidos por INT1?

Supongamos que alguien manda `'5'`, luego `'+'`, luego `'3'` por el Puerto B:

```
Después de INT1 #1 (llega '5'):
buffer[]:  [ 5 ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ]
                  ↑
              indBuffer = 1
  indConsum = 0 ──┘ (sigue en 0, no consumimos nada todavía)
  caracteresPendientes = 1

Después de INT1 #2 (llega '+'):
buffer[]:  [ 5 ][ + ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ]
                       ↑
                   indBuffer = 2
  indConsum = 0
  caracteresPendientes = 2

Después de INT1 #3 (llega '3'):
buffer[]:  [ 5 ][ + ][ 3 ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ]
                              ↑
                          indBuffer = 3
  indConsum = 0
  caracteresPendientes = 3
```

**Observá que `indConsum` no se movió.** El Productor y el Consumidor avanzan por la misma "pista circular" pero con agujas distintas. El Productor va adelante dejando datos; el Consumidor va atrás recogiéndolos.

### ¿Qué pasa cuando el Consumidor procesa esos 3 caracteres?

```
Antes de consumir:
buffer[]:  [ 5 ][ + ][ 3 ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ]
             ↑              ↑
         indConsum=0    indBuffer=3

logOperaciones[]: [ _ ][ _ ][ _ ][ _ ][ _ ]...[ _ ]  (50 posiciones vacías)
                    ↑
                indLog=0

--- consumirDatos(3) se ejecuta ---

Iteración i=0: lee buffer[0]='5' → logOperaciones[0]='5', indConsum=1, indLog=1
Iteración i=1: lee buffer[1]='+' → logOperaciones[1]='+', indConsum=2, indLog=2
Iteración i=2: lee buffer[2]='3' → logOperaciones[2]='3', indConsum=3, indLog=3

Resultado final:
buffer[]:  [ 5 ][ + ][ 3 ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ][ _ ]
                              ↑
                    indConsum=3 (alcanzó a indBuffer)
                    indBuffer=3

logOperaciones[]: [ 5 ][ + ][ 3 ][ _ ][ _ ]...[ _ ]
                                   ↑
                               indLog=3
```

> **Dato importante:** Fijate que el buffer NO se borra después de consumir. Los caracteres `'5'`, `'+'`, `'3'` siguen ahí en la memoria. Simplemente ya no importan porque `indConsum` los pasó de largo. Cuando `indBuffer` vuelva a escribir en esas posiciones, los pisará naturalmente. Esa es la belleza del buffer circular: **no se necesita limpiar memoria**.

---

## 2. El Momento Circular: ¿Qué pasa cuando se llena?

Si `indBuffer` llega a la posición 10 (que no existe porque el arreglo va de 0 a 9):

```c
if (indBuffer >= TAM_BUFFER) {
    indBuffer = 0;  // ¡Vuelta al principio!
}
```

Veamos esto gráficamente. Supongamos que ya escribimos hasta la posición 9:

```
buffer[]:  [ 5 ][ + ][ 3 ][ 7 ][ - ][ 2 ][ * ][ 8 ][ / ][ 1 ]
                                                               ↑
                                                         indBuffer = 10
                                                         ¡OVERFLOW! → se resetea a 0

Después del reset:
buffer[]:  [ 5 ][ + ][ 3 ][ 7 ][ - ][ 2 ][ * ][ 8 ][ / ][ 1 ]
             ↑
         indBuffer = 0  (el próximo carácter pisará al '5' viejo)
```

Lo mismo pasa con `indConsum` y con `indLog` (el Log tiene 50 posiciones, `TAM_LOG = 50`).

---

## 3. El Filtro ASCII: ¿Qué pasa a nivel de bits?

La macro `ES_CARACTER_VALIDO(c)` trabaja con la **tabla ASCII**. En la memoria, cada carácter es un número:

| Carácter | Valor ASCII (decimal) | Valor en binario |
|---|---|---|
| `'0'` | 48 | 0011 0000 |
| `'1'` | 49 | 0011 0001 |
| `'9'` | 57 | 0011 1001 |
| `'+'` | 43 | 0010 1011 |
| `'-'` | 45 | 0010 1101 |
| `'*'` | 42 | 0010 1010 |
| `'/'` | 47 | 0010 1111 |
| `'A'` | 65 | 0100 0001 |
| `'a'` | 97 | 0110 0001 |

Cuando el código hace `c >= '0' && c <= '9'`, la CPU realmente compara: **¿el número 48 es menor o igual que `c` Y `c` es menor o igual que 57?** No hay magia: los caracteres son números y las comparaciones son aritméticas normales.

Por eso `'A'` (65) no pasa el filtro: 65 no está entre 48 y 57, y 65 no es igual a 43, 45, 42 ni 47.

---

## 4. La Condición de Carrera: Diagrama Temporal

Este es el bug más sutil del ejercicio. Gemini lo explica con la analogía del mozo. Yo lo voy a mostrar con una **línea de tiempo** de lo que pasa en la CPU, instrucción por instrucción.

### Escenario del Bug (sin protección):

```
TIEMPO ──────────────────────────────────────────────────────────►

main():    lee caracteresPendientes = 3
           │
           ├── consumirDatos(3)  ← tarda varios ciclos de CPU
           │       │
           │       │   ── INTERRUPCIÓN INT1 ──────────────┐
           │       │   │  Llega un '7' nuevo por PORTB    │
           │       │   │  caracteresPendientes++ → ahora es 4  │
           │       │   └──────────────────────────────────┘
           │       │
           │       └── (termina de consumir los 3)
           │
           ├── caracteresPendientes = 0;    ← ¡¡¡DESASTRE!!!
           │   (Debería ser 1, porque hay un '7' nuevo sin procesar)
           │   (Ese '7' se pierde para siempre)
```

### Escenario Corregido (con protección):

```
TIEMPO ──────────────────────────────────────────────────────────►

main():    procesados = caracteresPendientes  → procesados = 3
           │
           ├── consumirDatos(3)
           │       │
           │       │   ── INTERRUPCIÓN INT1 ──────────────┐
           │       │   │  Llega un '7' nuevo              │
           │       │   │  caracteresPendientes++ → ahora es 4  │
           │       │   └──────────────────────────────────┘
           │       │
           │       └── (termina de consumir los 3)
           │
           ├── IEC1bits.INT1IE = 0;           ← Cerramos la puerta
           ├── caracteresPendientes -= 3;     ← 4 - 3 = 1 ✅ ¡Correcto!
           ├── IEC1bits.INT1IE = 1;           ← Abrimos la puerta
           │
           │   (El '7' sigue contabilizado, se consumirá la próxima vez)
```

**¿Por qué apagamos INT1 para la resta?** Porque la operación `caracteresPendientes -= procesados` en Assembly se traduce en 3 instrucciones:
1. Cargar `caracteresPendientes` desde la RAM a un registro.
2. Restar `procesados`.
3. Guardar el resultado de vuelta en la RAM.

Si la interrupción salta **entre el paso 1 y el paso 3**, la ISR modifica el valor en RAM, pero nuestro registro todavía tiene el valor viejo. Al hacer el paso 3, pisamos el cambio de la ISR. Deshabilitando la interrupción por esos 3 ciclos, garantizamos que nadie toque la variable mientras la estamos modificando.

---

## 5. La Temporización Dinámica: La Máquina de Estados en la Memoria

La variable `cantFallas` actúa como un **multiplicador del tiempo de espera**. Veamos cómo evoluciona:

```
Estado de las variables en cada ciclo del main:

Ciclo 1: counterTimer llega a > 0 (cantFallas=0)
         → Revisa buffer: vacío → cantFallas = 1
         → Tiempo para próxima revisión: necesita counterTimer > 1
         → Equivale a 1 × 150us = 150us (en realidad 2 × 150us = 300us)

Ciclo 2: counterTimer llega a > 1 (cantFallas=1)
         → Revisa buffer: vacío → cantFallas = 2
         → Próxima revisión: counterTimer > 2
         → Equivale a 3 × 150us = 450us

Ciclo 3: counterTimer llega a > 2 (cantFallas=2)
         → Revisa buffer: vacío → cantFallas = 3
         → Próxima revisión: counterTimer > 3
         → Equivale a 4 × 150us = 600us

...sigue hasta...

Ciclo 6: counterTimer llega a > 5 (cantFallas=5 = MAX_FALLAS)
         → Revisa buffer: vacío → cantFallas se queda en 5 (tope)
         → Próxima revisión: counterTimer > 5
         → Equivale a 6 × 150us = 900us ← TOPE MÁXIMO

Si en cualquier momento hay datos:
         → cantFallas = 0 (reset inmediato)
         → Vuelve a revisar cada counterTimer > 0
         → Equivale a 1 × 150us = 150us
```

> **Detalle técnico:** La condición es `counterTimer > cantFallas`, no `>=`. Esto significa que siempre hay 1 tick de espera mínima. Cuando `cantFallas = 0`, esperamos `counterTimer > 0`, o sea, al menos 1 interrupción del Timer (150us). Cuando `cantFallas = 5`, esperamos `counterTimer > 5`, o sea, al menos 6 interrupciones (900us).

---

## 6. La Macro CAR_GUARDADO: Un Truco con Efectos Secundarios

En `config.h` hay una definición que puede confundir:

```c
#define CAR_GUARDADO buffer[indBuffer++]
```

Cuando el código en `config.c` hace:
```c
CAR_GUARDADO = c;
```

El preprocesador de C lo **reemplaza textualmente** antes de compilar, convirtiéndolo en:
```c
buffer[indBuffer++] = c;
```

Esto hace **dos cosas en una sola línea**:
1. Guarda `c` en `buffer[indBuffer]`.
2. Incrementa `indBuffer` en 1 (el `++` postfijo).

Es compacto pero peligroso si no sabés que el `++` está escondido. Si alguien usara `CAR_GUARDADO` dos veces en la misma línea, `indBuffer` avanzaría dos veces sin querer.

Lo mismo pasa con `LOG_ACTUAL`:
```c
#define LOG_ACTUAL logOperaciones[indLog++]
```

---

## 7. Tabla Resumen: Mapa Completo del Sistema

| Variable | Vive en | Quién la escribe | Quién la lee | Riesgo de concurrencia |
|---|---|---|---|---|
| `buffer[10]` | `config.c` (global) | ISR de INT1 | `consumirDatos()` en main | No (escriben posiciones distintas) |
| `indBuffer` | `config.c` (global) | ISR de INT1 | Solo la ISR | No |
| `indConsum` | `main.c` (global) | `consumirDatos()` | Solo el main | No |
| `caracteresPendientes` | `main.c` (global) | ISR de INT1 (++) y main (-=) | main | **SÍ** → protegido con IEC1 |
| `counterTimer` | `main.c` (global) | ISR del Timer1 | main | Bajo (solo lectura en main) |
| `cantFallas` | `main.c` (global) | main | main | No (solo el main la toca) |
| `logOperaciones[50]` | `main.c` (global) | `consumirDatos()` | Nadie más | No |

> **La regla de oro:** El único caso peligroso es cuando **dos actores (ISR + main) escriben la misma variable**. En este ejercicio, solo `caracteresPendientes` tiene ese problema, y por eso la protegemos.

---

## 8. ¿Por qué `extern` y no una sola declaración?

En el código vas a ver esto:

En `config.c`:
```c
char buffer[TAM_BUFFER];  // Acá se CREA el arreglo (ocupa memoria física)
```

En `main.c`:
```c
extern char buffer[];     // Acá se REFERENCIA (le decimos al compilador: "existe en otro archivo")
```

**¿Por qué no definirlo en los dos archivos?** Porque si ponés `char buffer[10];` tanto en `config.c` como en `main.c`, el linker crearía **dos arreglos distintos** en dos zonas de memoria diferentes. La ISR escribiría en uno y el main leería del otro. Nunca se encontrarían los datos.

`extern` es como decir: "Este arreglo ya existe en algún lado, no crees uno nuevo, solo dejame usarlo".

---

## 9. ¿Dónde Viven Físicamente el Buffer y el Log en la Memoria?

Tanto el `buffer[10]` como el `logOperaciones[50]` se ubican en la **memoria de datos (RAM)** del dsPIC33F. Pero no en cualquier zona: viven en los **GPR (General Purpose Registers)**, que es la zona de RAM libre para el programador.

### Mapa de la Memoria de Datos del dsPIC33FJ256GP710

```
DIRECCIÓN          CONTENIDO
─────────────────────────────────────────────────
0x0000 - 0x07FF   SFR (Registros de Funciones Especiales)
                   → Acá viven TMR1, PR1, T1CON, IFS0, IEC1,
                     PORTB, LATA, y todos los registros de
                     control del hardware.
                   → Son 2 KB reservados exclusivamente para
                     el microcontrolador. NO podés usarlos
                     para tus variables.
─────────────────────────────────────────────────
0x0800 - ...       GPR (Registros de Propósito General)
                   → Acá caen TODAS las variables globales
                     que vos declarás en tu código C:
                     buffer[], logOperaciones[], indBuffer,
                     indConsum, caracteresPendientes, etc.
                   → La dirección exacta de cada variable
                     la decide el Linker del compilador XC16,
                     según el orden de declaración y el tamaño.
─────────────────────────────────────────────────
... - Final RAM    PILA (Stack)
                   → Crece hacia direcciones ascendentes.
                   → Acá se guardan las variables locales
                     de las funciones, los parámetros, y el
                     PC + SR cuando ocurre una interrupción.
─────────────────────────────────────────────────
```

> **Dato clave:** No hay una dirección "fija" para el buffer o el log. Su ubicación exacta depende de: (1) el orden en que declaraste las variables en el `.c`, (2) el tamaño de cada arreglo (un `char` ocupa 1 byte), y (3) las decisiones de optimización del Linker. Para saber la dirección real, hay que mirar la ventana de Variables del simulador.

---

## 10. Herramientas de MPLAB X para Depurar Este Ejercicio

Para verificar que todo funciona, el IDE tiene un simulador integrado llamado **MPLAB X SIM**. Se configura en *Project Properties > Conf > Simulator*. Una vez activo, disponés de estas ventanas:

### Ventana de Variables (`Window > Debugging > Variables`)
- Muestra las variables de tu código C con su **dirección de memoria** (Address) y su **valor actual** (Value).
- Podés ver en tiempo real cómo `caracteresPendientes` sube cuando la ISR de INT1 se dispara, y cómo baja cuando el `main` consume.
- Los valores que cambian entre pasos se **resaltan en rojo**.

### Ventana de SFR (`Window > Debugging > SFRs`)
- Muestra **todos los registros de control del hardware** (direcciones 0x0000 a 0x07FF).
- Acá podés buscar `TMR1` para ver cómo el contador sube físicamente de 0 a 6000, `PR1` para verificar que tiene el valor correcto, y `T1CON` para confirmar la configuración del prescaler.
- También podés monitorear `IFS0bits.T1IF` y `IFS1bits.INT1IF` para ver las banderas subir y bajar.

### Ventana de Memoria de Datos (`Window > Debugging > File Registers`)
- Muestra el **mapa completo de la RAM** en una cuadrícula de bytes.
- Podés navegar a la dirección 0x0800 en adelante y ver cómo se llenan las posiciones del `buffer[]` y del `logOperaciones[]` con los valores ASCII.

### Ejecución Paso a Paso
- **Step Into (F7):** Entra dentro de cada función (incluyendo las ISR).
- **Step Over (F8):** Ejecuta la línea completa sin entrar a sub-funciones.
- **Breakpoints:** Hacé clic en el número de línea para poner un punto de detención. Podés poner uno en `IFS1bits.INT1IF = 0;` dentro de la ISR de INT1 para "atrapar" cada interrupción y ver el estado de la memoria en ese instante exacto.

### Disassembly Listing
- Muestra cómo tu código C se traduce a instrucciones de **ensamblador** del dsPIC.
- Útil para entender por qué `caracteresPendientes -= procesados` son **3 instrucciones** (MOV, SUB, MOV) y por qué necesitamos protegerla con `IEC1bits.INT1IE`.

---

## 11. ¿Cómo se Guarda el PC y el SR Durante una Interrupción?

Cuando el dsPIC33F acepta una interrupción (por ejemplo, la de INT1 o Timer1), el hardware realiza automáticamente un **push** de información crítica hacia la Pila (Stack), usando el registro W15 (Stack Pointer).

### ¿Qué se resguarda exactamente?

| Dato | Tamaño | Descripción |
|---|---|---|
| **PC** (Program Counter) | 23 bits | La dirección exacta de la instrucción a la que hay que volver cuando termine la ISR |
| **SRL** (Status Register Low) | 8 bits | Las banderas aritméticas (Z, C, N, OV) y el nivel de prioridad actual (IPL) |
| **IPL3** (bit de CORCON) | 1 bit | Indica si se está atendiendo una trampa (trap) |

Este resguardo ocupa **2 palabras de 16 bits** en la pila, por lo que W15 se incrementa en 4 unidades (2 bytes × 2 palabras).

### Visualización en la Pila

```
PILA (Stack) — Antes de la interrupción:
┌─────────────┐
│   ...       │
├─────────────┤ ← W15 apunta acá (ej. 0x0850)
│  (vacío)    │
└─────────────┘

PILA (Stack) — Después de entrar a la ISR:
┌─────────────┐
│   ...       │
├─────────────┤ ← 0x0850 (dirección original de W15)
│ PC[15:0]    │  ← Los 16 bits bajos de la dirección de retorno
├─────────────┤ ← 0x0852
│ PC[22:16]   │  ← Los 7 bits altos del PC + SRL (banderas)
│ + SRL       │
├─────────────┤ ← W15 ahora apunta acá (0x0854, aumentó en 4)
│  (vacío)    │
└─────────────┘
```

### ¿Cómo verlo en MPLAB X?

1. **Poné un Breakpoint** dentro de tu ISR (ej. en la línea `IFS0bits.T1IF = 0;`).
2. **Anotá el valor de W15** antes de que ocurra la interrupción (ventana SFR, buscá W15).
3. Cuando el simulador se detenga en el breakpoint, verás que **W15 aumentó en 4**.
4. En la ventana de **File Registers (Data Memory)**, andá a la dirección original de W15. Ahí vas a ver los valores del PC y el SR guardados, **resaltados en rojo**.
5. La ventana **Call Stack** (`Window > Debugging > Call Stack`) te muestra directamente la dirección de retorno en formato legible.
6. Cuando el simulador ejecute la instrucción **RETFIE** (Return from Interrupt), W15 volverá a su valor original y el procesador saltará de vuelta a la línea exacta donde fue interrumpido.

> **Conexión con el Ejercicio 2 (Multitask):** En ese ejercicio, nosotros manipulamos este mecanismo a propósito. Falsificamos las pilas de los procesos B y C colocando un PC inventado (la dirección de `procesoB` o `procesoC`) para que el `RETFIE` salte a un proceso que nunca fue ejecutado. Entender cómo el hardware guarda el PC acá es la base para entender el truco del Kernel.

---

## Conclusión: Lo que ambos modelos coincidimos

El Ejercicio 1 se resume en **3 actores independientes** que comparten memoria:
1. **INT1** escribe en el buffer y avanza `indBuffer`.
2. **Timer1** incrementa un contador de tiempo (`counterTimer`).
3. **main** lee el buffer, avanza `indConsum`, y usa `counterTimer` para decidir cuándo actuar.

La diferencia entre las explicaciones: Gemini narra el flujo como una historia (ideal para la primera lectura). Este análisis muestra **el estado de la memoria paso a paso** (ideal para depurar en el simulador de MPLAB X, donde podés ver las variables en tiempo real y comparar con estos diagramas).
