# 🧠 Walkthrough: Trabajo Práctico 2 - Ejercicio 2 (El Método de la Pizarra)
**Materia:** Arquitectura de Computadoras
**Arquitectura:** dsPIC33F (Arquitectura Harvard)

Este documento detalla el funcionamiento exacto del Ejercicio 2 (entregado y aprobado). Se explican los mecanismos físicos de manipulación del Puntero de Pila (WREG15) para lograr un intercambio de contexto (Context Switching) mediante Round-Robin.

---

## 🌟 1. La Idea Central: Intercambio de Memoria de Datos (Stack Swapping)

En este ejercicio, queremos que 3 procesos (A, B y C) compartan el tiempo de una única CPU. Para lograrlo, implementaremos un kernel multitarea cooperativo basado en el método de **Copia de Stack** (El Método de la Pizarra).

En la arquitectura dsPIC, la pila (Stack) y la memoria de datos (RAM) comparten el mismo espacio físico. El registro `WREG15` funciona como el Stack Pointer global. Como solo existe un Stack Pointer por hardware, todos los procesos deben utilizar la misma región de memoria de datos para sus contextos. Cuando ocurre la interrupción del `Timer1`:

1. El proceso actual detiene su ejecución. El hardware apila automáticamente el **Program Counter (PC)** y el **Status Register (SR)**. Luego, nuestro software apila el resto del contexto (**Registros de Trabajo W0...W14**) en la RAM apuntada por `WREG15`.
2. El kernel **copia** este bloque de memoria física (el stack actual) hacia un **Arreglo en RAM** dedicado a ese proceso para resguardarlo.
3. El kernel **sobrescribe** la región física del stack con la información guardada del *siguiente* proceso.
4. La CPU ejecuta un retorno de interrupción (`RETFIE`), desapilando los registros y el Program Counter (PC) del nuevo contexto, retomando su ejecución.

### 📊 Componentes Técnicos
| Componente | Función Técnica |
| :--- | :--- |
| **Memoria de Datos (Stack)** | Región de RAM donde se apilan dinámicamente el PC, SR, Registros W y variables. |
| **Arreglos (`arregloProc`)** | Estructuras estáticas en RAM para resguardar el contexto completo de los procesos inactivos. |
| **Timer 1 (`_T1Interrupt`)** | Generador de interrupciones que delimita el tiempo de CPU (Quantum). |
| **Puntero de Pila (WREG15)** | Registro físico que contiene la dirección actual del tope de la pila en memoria. |

---

## 🎯 2. Estrategia Práctica: ¿Cómo calcular el "DESPLAZAMIENTO"?

El valor de `DESPLAZAMIENTO` es el "salto mágico" que debemos dar hacia atrás en la Pila para encontrar dónde está guardado el Program Counter (PC) del proceso interrumpido. No es un número al azar, depende del hardware y de qué registros guarde el compilador. Para encontrarlo (en nuestro caso, `18`), seguimos esta estrategia en MPLAB X:

1. **Punto Cero (Inicio de la Pila):** 
   Ponemos un Breakpoint justo antes de entrar al bucle infinito del primer proceso. **En `main.c`, línea 60 (`procesoA();`)**. Anotamos el valor del Puntero de Pila (`W15`).
   *Ejemplo: `W15` = `0x0862`*

2. **Pausa en el Planificador:**
   Ponemos un Breakpoint en la primera línea de la función planificador. **En `kernel.c`, línea 47 (`unsigned int* puntero=WREG15;`)**. Dejamos correr el programa (F5) hasta que el Timer dispare la interrupción y se detenga allí. Anotamos el nuevo valor de `W15`.
   *Ejemplo: `W15` = `0x0892`*

3. **La Caza del PC (Búsqueda manual en RAM):**
   Sabemos que el hardware empujó primero el PC de la tarea (Proceso A) a la pila. Abrimos la ventana **File Registers** y revisamos la RAM a partir de `0x0862`. Buscamos un número que corresponda a una dirección de la **Memoria de Programa** (ej. `0x0454`).
   *Ejemplo: Encontramos el PC en la dirección de RAM `0x086E`.*

4. **El Cálculo Matemático:**
   Ahora que sabemos dónde estamos parados (`W15 actual = 0x0892`) y dónde queremos aterrizar (`PC objetivo = 0x086E`), restamos ambas direcciones de RAM:
   `0x0892 - 0x086E = 0x0024` (que es **36** en decimal).
   Como el dsPIC avanza el `W15` en "Words" (saltos de 2 bytes), dividimos por 2:
   `36 bytes / 2 bytes por Word = 18 posiciones`.

> [!TIP]
> **¿Por qué 0x0454 y no otro valor (ej. 0x04AA)?**
> En la RAM verás muchos números. Para identificar el PC real, usamos dos filtros:
> 1. **Filtro de Desplazamiento:** Si calculamos que el salto es de **18**, debemos tomar el valor que esté exactamente a esa distancia del `W15` actual. En la captura, al restar 18 de la posición actual, caemos en `0x086E`, donde reside el **`0x0454`**.
> 2. **Filtro de Proximidad:** El PC debe ser una dirección de Flash cercana al inicio de tu proceso. Si el proceso A empieza en `0x0444`, un PC de `0x0454` (unas pocas instrucciones después) tiene mucho más sentido que otros valores aleatorios.

```text
DISTINGUIENDO EL PC (CRITERIO TÉCNICO)
─────────────────────────────────────────────────────────────
[0x0862] 0x04AA  <-- ¡CUIDADO! Es un valor de Flash, pero está muy lejos (a 24 words).
...
[0x086E] 0x0454  <-- ¡BINGO! Está a 18 words de distancia. Este es el que el código usará.
...
[0x0892] (W15)   <-- Punto de partida para la resta.
─────────────────────────────────────────────────────────────
```
[0x0862] (Fondo de la pila original)
...
[0x086E] 0x0454 (¡Bingo! Aquí está el PC de retorno de A)   <─┐
[0x0870] 0x0000 (SR guardado)                                 │
[0x0872] W0 guardado                                          │
...                                                           │ DISTANCIA A SALTAR:
[0x0888] W14 guardado                                         │ 36 bytes = 18 words
[0x088A] PC de llamada a la función planificador              │
...                                                           │
[0x0892] (Espacio Libre)    <-- W15 actual (Estamos aquí)   <─┘
─────────────────────────────────────────────────────────────
```
¡Así obtenemos matemáticamente `DESPLAZAMIENTO = 18`! Ya podemos inyectar esto en el código para que sea automático.

---

## 🛠️ 3. Construcción del Contexto Inicial (`init`)

En este sistema, **A, B y C** representan tres **Procesos o Tareas independientes** (hilos de ejecución) que compiten por el tiempo de la CPU. Cada uno es una función de C con un bucle infinito.

Antes de correr los procesos, se necesita "falsificar" los contextos iniciales en la función `init()`:
```c
void init(void){
    // ... inicialización de registros en 0 ...
    arregloProcA[0]=dirA; // PC inicial del Proceso A
    arregloProcB[0]=dirB; // PC inicial del Proceso B
    arregloProcC[0]=dirC; // PC inicial del Proceso C
}
```

#### 📋 ¿Qué hay exactamente dentro del arreglo? (Mapa de Memoria)
| Índice del Arreglo | Contenido Técnico | Descripción |
| :--- | :--- | :--- |
| `[0]` | **Program Counter (PC)** | La dirección física en la **Memoria de Programa** donde comienza el código. |
| `[1]` | **Status Register (SR)** | El estado de las banderas (Z, C, N) del micro. |
| `[2]` al `[16]` | **Registros W0...W14** | Los valores temporales que el proceso estaba usando. |

#### ⚠️ Diferencia Crítica: Arquitectura Harvard
Es vital no confundir los dos espacios de memoria del dsPIC:
*   **Memoria de Programa (Flash):** Contiene las instrucciones del código. El **Program Counter (PC)** apunta aquí. Las variables `dirA`, `dirB` y `dirC` son direcciones de este espacio.
*   **Memoria de Datos (RAM):** Contiene las variables, los arreglos y la **Pila (Stack)**. El **Stack Pointer (WREG15)** apunta aquí.

> [!IMPORTANT]
> Lo que hacemos en `init()` es **guardar una dirección de la Memoria de Programa (PC) dentro de la Memoria de Datos (Stack/Arreglo)**. Es como anotar la dirección de una casa (Flash) en un papel (RAM).

---

## ⚙️ 4. El Planificador y la Aritmética de Punteros

El corazón del ejercicio es la función `planificador()`, la cual trasplanta los bloques de memoria.

### Puntero de Pila (WREG15) y Desplazamiento
```c
unsigned int* puntero=WREG15;   
puntero-=DESPLAZAMIENTO;        
```
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
// ... (Repite para B->C y C->A)
```
**Operación a bajo nivel:**
1.  **Lectura:** `*puntero` accede a la Pila física en RAM. Lee el valor y lo resguarda a salvo en la variable global `arregloProcA[i]`.
2.  **Escritura:** Inmediatamente después, inserta en esa misma dirección de memoria física el contenido guardado en `arregloProcB[i]`.

> [!IMPORTANT]
> **Diferencia Crítica:** Nota que aquí **no guardamos la dirección del Puntero de Pila (WREG15)**. Mantenemos el `W15` intacto y realizamos una sobreescritura directa (`swap`) del bloque de datos contenido en la memoria de datos (El Método de la Pizarra).

---

## ⏱️ 5. El Ciclo de Interrupción (`_T1Interrupt`)

```c
void __attribute__((interrupt, auto_psv)) _T1Interrupt( void ){
    IFS0bits.T1IF = 0;
    if(++contT1==QUANTUM){  
        contT1=0;           
        planificador();     
    }
}
```
*   **QUANTUM:** Tiempo máximo otorgado a un proceso para utilizar la CPU. 
*   **Alternancia Constante:** Al salir del planificador, la función ejecuta `RETFIE`. Esa instrucción saca de la pila el PC (que ahora es el del siguiente proceso) y salta al código nuevo sin que este lo note.

---

## 🔬 6. Guía de Testeo y Simulación en MPLAB X (Direcciones Reales)

Para validar el "Método de la Pizarra", observamos las entrañas del dsPIC33F.

### Paso 1: Preparación del Entorno
> **Punto de Control Técnico:** 
> 1. El `QUANTUM` está configurado en **2**.
> 2. El `DESPLAZAMIENTO` es **18**.
> 3. En el menú: `Window -> Debugging`, abrí **Watches**, **Variables** y **Disassembly**.

### Paso 2: Ubicación Estratégica de Breakpoints
1.  **En `main.c`, línea 60 (`procesoA();`):**
    *   **Valores Reales observados:**
        *   **`W15` = `0x0862`**: El Puntero de Pila está en la zona alta de la RAM de datos.
        *   **`arregloProcA[0]` = `0x0444`**: Dirección física en la Memoria de Programa (Flash) de `procesoA`.
    
    ```text
    ESTADO DE LA MEMORIA (Arranque)
    ───────────────────────────────────────────────
    RAM (Variables)
    [0x0840] arregloProcA[0] = 0x0444  <-- PC inicial de A
    [0x0842] arregloProcA[1] = 0x0000
    
    RAM (Pila/Stack)
    [0x0860] (Datos anteriores)
    [0x0862] (Espacio Libre)         <-- W15 apunta aquí
    ───────────────────────────────────────────────
    ```
2.  **En `kernel.c`, línea 80 (dentro de `_T1Interrupt`):**
    *   **Valores Reales observados:**
        *   **`W15` = `0x0888`**: La pila creció porque el hardware empujó (PUSH) el Program Counter y el Status Register del **Proceso A**.

    ```text
    ESTADO DE LA MEMORIA (Interrupción del Timer)
    ───────────────────────────────────────────────
    RAM (Pila/Stack)
    [0x0862] ... (Basura o variables locales de A)
    ...
    [0x086E] 0x0454 (PC retorno)     <-- Hardware guardó dónde se quedó A
    [0x0870] 0x0000 (SR guardado)
    [0x0872] W0 guardado             <-- Software (GUARDAR_REGISTROS)
    ...
    [0x0888] (Espacio Libre)         <-- W15 subió hasta aquí automáticamente
    ───────────────────────────────────────────────
    ```
3.  **En `kernel.c`, línea 47 (primera línea de `planificador()`):**
    *   **Valores Reales observados:**
        *   **`W15` = `0x0892`** (RAM): El puntero creció por llamar a la función `planificador()`.
        *   **`puntero` = `0x086E`** (RAM): Tras ejecutar `puntero-=18`, retrocedimos a la base del "marco de interrupción".
        *   **`*puntero` = `0x0454`** (Flash): ¡Dirección de retorno! El proceso A fue interrumpido exactamente aquí.

    ```text
    ESTADO DE LA MEMORIA (Aritmética de Punteros)
    ───────────────────────────────────────────────
    RAM (Pila/Stack)
    [0x086E] 0x0454 (PC de A)        <-- 'puntero' (W15 - 18) aterrizó exactamente aquí
    [0x0870] 0x0000 (SR de A)
    ...
    [0x088A] PC retorno planificador <-- W15 subió por culpa del CALL a la función
    ...
    [0x0892] (Espacio Libre)         <-- W15 actual
    ───────────────────────────────────────────────
    ```

### Paso 3: El "Trasplante" de Memoria
Con el programa detenido en el `planificador()`, ejecutamos el `for` paso a paso (F8):
*   **Guardado:** `arregloProcA[0]` cambia de `0x0444` a `0x0454`. Se guardó el punto exacto de la interrupción en la RAM.
*   **Carga:** La Pila física (`0x086E`) es sobrescrita por el valor de `arregloProcB[0]`.
*   **Dirección de B:** El valor inyectado es **`0x045C`** (Flash).

    ```text
    EL TRASPLANTE (EL MÉTODO DE LA PIZARRA EN ACCIÓN)
    ─────────────────────────────────────────────────────────────
    ANTES (Vuelta 0 del FOR):
    [ Arreglo A ]  arregloProcA[0]  = 0x0444 (Inicio original)
    [ RAM FÍSICA]  Pila en 0x086E   = 0x0454 (PC de interrupción de A)
    [ Arreglo B ]  arregloProcB[0]  = 0x045C (Inicio de B)

    DESPUÉS (Vuelta 0 del FOR terminada):
    [ Arreglo A ]  arregloProcA[0]  = 0x0454  <-- A guardó su estado
    [ RAM FÍSICA]  Pila en 0x086E   = 0x045C  <-- B invadió la pila
    [ Arreglo B ]  arregloProcB[0]  = 0x045C
    ─────────────────────────────────────────────────────────────
    ```

### Paso 4: El Salto Final (RETFIE)
1.  **Salir de la Interrupción:** Usamos **F5 (Continue)**.
2.  **El Efecto Mariposa:** La instrucción `RETFIE` saca de la pila el Program Counter. Como pusimos `0x045C`, la CPU salta inmediatamente a esa dirección. ¡El cambio de contexto ha sido un éxito!

---

## 📝 7. Resumen para la Defensa: El Flujo de la Conciencia

Si el profesor te pregunta cómo funciona tu código, recuerda estas palabras clave y el flujo de la "Conciencia" del Micro:

1. **Persistencia (Flash):** El código de las funciones A, B y C nunca se mueve de la Memoria de Programa.
2. **Resguardo (Arreglo en RAM):** Cuando un proceso no está corriendo, su "punto de retorno" (PC) está guardado de forma segura en su Arreglo de contexto.
3. **Activación (Stack en RAM):** El planificador mueve ese PC desde el Arreglo hacia el Stack (Stack Swapping).
4. **Ejecución (Registro PC):** Al ejecutar `RETFIE`, el hardware mueve ese PC desde el Stack hacia el **Registro Físico Program Counter (PC)** de la CPU.

El `DESPLAZAMIENTO` es crítico porque es el GPS matemático que le permite al puntero aterrizar exactamente en la dirección de RAM donde el hardware espera encontrar el PC para cargarlo en la CPU. Si fallamos por un solo byte, el micro saltará a una dirección errónea y el sistema colapsará (Address Error Trap).
