# 🧠 Walkthrough: Multitarea por Copia de Stack (El Método de la Pizarra)
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
3.  **Primer "Click" del Timer:** El sistema corre normalmente hasta que el Timer 1 genera la primera interrupción. Es en ese instante cuando el `W15` tiene un valor real (ej. `0x1026`) y el planificador entra a hacer el primer cambio.

---

## 🛠️ Paso 1: Buffers de Contexto (Los Arreglos)

Como el microcontrolador dsPIC33F posee un único Puntero de Pila (SP / WREG15) físico, necesitamos asignar bloques de memoria estática en RAM para resguardar el contexto de los procesos suspendidos.

```c
#define TOPE_ARREGLOS 38
unsigned int arregloProcA[TOPE_ARREGLOS];
unsigned int arregloProcB[TOPE_ARREGLOS];
unsigned int arregloProcC[TOPE_ARREGLOS];
```
Cada arreglo es una "copia de seguridad" de lo que había en la **Pila de Hardware (la zona de memoria RAM apuntada por el Puntero de Pila (SP / WREG15))** cuando el proceso fue interrumpido. 

#### 📋 ¿Qué hay exactamente dentro del arreglo? (Mapa de Memoria)

| Índice del Arreglo | Contenido Técnico | Descripción |
| :--- | :--- | :--- |
| `[0]` | **Program Counter (PC)** | La dirección de la línea de código donde debe volver el proceso. |
| `[1]` | **Status Register (SR)** | El estado de las banderas (Z, C, N) y bits de control del micro. |
| `[2]` al `[16]` | **Registros de Trabajo (WREG0...WREG14)** | Los valores temporales de las cuentas y variables que el proceso estaba usando. |
| `[17]` en adelante | **Pila Local (Stack Local)** | Variables locales y direcciones de retorno de funciones que el proceso llamó. |

Usamos **38** posiciones (palabras de 16 bits) para asegurarnos de que quepa todo este contexto completo sin desbordar la memoria.

---

## 🛠️ Paso 2: Construcción del Contexto Inicial (`init`)

Al arrancar el sistema, los procesos B y C nunca han sido ejecutados. Sus arreglos (`arregloProcB` y `arregloProcC`) están inicializados en cero por defecto. Si el planificador intentara volcar este contexto nulo en la Pila de Hardware, la instrucción de retorno cargaría un `0x0000` en el Program Counter (PC), causando una excepción de hardware (Address Error). Por ello, debemos pre-cargar manualmente su punto de entrada (`dirB` y `dirC`) en el índice `[0]` de la estructura.

#### 📍 ¿De dónde salen `dirB` y `dirC`?
Estas variables contienen la dirección física en la **Memoria de Programa (Flash)** donde reside el código de cada proceso. En C, el nombre de una función es automáticamente su dirección de memoria. Las inicializamos así (generalmente antes del `main` o al principio):

```c
// Rescatamos las direcciones de las funciones
unsigned int dirB = (unsigned int)procesoB;
unsigned int dirC = (unsigned int)procesoC;
```

#### ⚠️ Diferencia Crítica: Arquitectura Harvard
Es vital no confundir los dos espacios de memoria del dsPIC:
*   **Memoria de Programa (Flash):** Contiene las instrucciones del código. El **Program Counter (PC)** apunta aquí para saber qué instrucción ejecutar. Las variables `dirB` y `dirC` son direcciones de este espacio.
*   **Memoria de Datos (RAM):** Contiene las variables, los arreglos y la **Pila (Stack)**. El **Stack Pointer (SP / WREG15)** apunta aquí para gestionar los datos temporales.

> [!IMPORTANT]
> Lo que hacemos en nuestro código es **guardar una dirección de la Memoria de Programa (PC) dentro de la Memoria de Datos (Stack/Arreglo)**. Es como anotar la dirección de una casa (Flash) en un papel (RAM).

> [!NOTE]
> **Contexto del Proceso A:**
> El proceso A no requiere esta pre-carga manual porque conforma el flujo principal que arranca inherentemente desde `main()`. Al dispararse la primera interrupción del Timer, el hardware y la rutina de atención apilarán naturalmente su contexto de ejecución real en la RAM física, y el planificador copiará dicho bloque a `arregloProcA`.

```c
void init(void) {
    // Ponemos la dirección de la función en el inicio del arreglo (índice [0])
    arregloProcB[0] = dirB; // El Program Counter (PC) inicial
    arregloProcC[0] = dirC; 
}
```
Al colocar la dirección de la función en la posición `[0]`, configuramos el valor que adoptará el Program Counter (PC). Al volcar el arreglo a la pila física, la instrucción `RETFIE` extraerá esta dirección asumiendo que es un retorno de interrupción válido, iniciando así la ejecución del proceso B o C.

---

## 🛠️ Paso 3: El Gestor de Ticks (La ISR del Timer)

El Timer genera interrupciones periódicas de hardware que el kernel utiliza para medir el tiempo de CPU. El **Quantum** establecido es de 2 ticks. 

```c
void __attribute__((interrupt, auto_psv)) _T1Interrupt(void) {
    IFS0bits.T1IF = 0; // Bajamos la bandera
    
    if (++contT1 == QUANTUM) {
        contT1 = 0; // IMPORTANTE: Resetear para la próxima vuelta
        
        // --- AQUÍ EMPIEZA LA MAGIA ---
        
        // 1. Apilamos los Registros de Trabajo (WREG0...WREG14) en la memoria RAM (Stack actual)
        GUARDAR_REGISTROS(); 
        
        // 2. Invocamos al scheduler para realizar el volcado de memoria (Stack Swapping)
        planificador();
        
        // 3. Desapilamos los Registros de Trabajo (WREG0...WREG14) del nuevo proceso desde la memoria RAM hacia la CPU
        RESTAURAR_REGISTROS();
    }
}
```

> [!IMPORTANT]
> **¿Por qué usamos `GUARDAR_REGISTROS()`?**
> Porque los procesos A, B y C usan los **Registros de Trabajo (WREG0...WREG14)** para sus cuentas. Si no los metemos en el stack antes de copiarlo, esos valores se perderían y las cuentas darían mal.

---

## 🛠️ Paso 4: El Planificador (Stack Swapping)

Esta es la función algorítmica central del sistema. Utiliza aritmética de punteros para recorrer la memoria de datos (RAM física apuntada por W15) y una estructura condicional `switch` para gestionar el estado del cambio de contexto.

```c
void planificador(void) {
    // Calculamos la base de la zona de stack a intercambiar
    // USAMOS el valor del Puntero de Pila (SP / WREG15) como referencia, pero NO lo guardamos.
    unsigned int* puntero = (unsigned int*)WREG15; 
    puntero -= DESPLAZAMIENTO; 
    int i;

    switch(estadoProceso) {
        case 0: // Saliendo A -> Entrando B
            for(i=0; i<TOPE_ARREGLOS; i++) {
                arregloProcA[i] = *puntero;    // Guardo CONTENIDO de A
                *puntero = arregloProcB[i];    // Cargo CONTENIDO de B
                puntero++;
            }
            estadoProceso = 1; 
            break;

        case 1: // Saliendo B -> Entrando C
            for(i=0; i<TOPE_ARREGLOS; i++) {
                arregloProcB[i] = *puntero;    // Guardo CONTENIDO de B
                *puntero = arregloProcC[i];    // Cargo CONTENIDO de C
                puntero++;
            }
            estadoProceso = 2; 
            break;

        case 2: // Saliendo C -> Entrando A
            for(i=0; i<TOPE_ARREGLOS; i++) {
                arregloProcC[i] = *puntero;    // Guardo CONTENIDO de C
                *puntero = arregloProcA[i];    // Cargo CONTENIDO de A
                puntero++;
            }
            estadoProceso = 0; 
            break;
    }
}
```

> [!IMPORTANT]
> **Diferencia Crítica:**
> Nota que aquí **no guardamos la dirección del Puntero de Pila (SP / WREG15)** en ninguna variable. El Puntero de Pila (SP / WREG15) físico del microcontrolador opera constantemente sobre el mismo rango de memoria RAM de datos (la pila global del sistema, que habitualmente inicia en la dirección física **`0x0800`** en arquitecturas dsPIC33). 
> 
> En arquitecturas con este diseño, el hardware asume un stack unificado. En lugar de modificar el registro apuntador `W15` para que referencie distintos bloques de RAM (como se haría en un RTOS avanzado con pilas múltiples), mantenemos el `W15` intacto y realizamos una sobreescritura directa (`swap`) del bloque de datos contenido en la memoria de datos.

### 🔬 Aritmética de Punteros: Ejemplo con Direcciones Físicas

Analicemos la manipulación de memoria a bajo nivel (Hexadecimal). 

Vamos a usar direcciones realistas para este ejemplo:
*   El **Proceso B** empieza en la dirección de programa `0x0300` (`dirB = 0x0300`).
*   Su arreglo `arregloProcB` está en la base de la RAM a partir de la dirección **`0x084C`** (zona de variables globales).
*   La **Pila (Stack)** donde trabaja el micro está más arriba, por ejemplo en la dirección **`0x1000`**.
*   El **Puntero de Pila (SP / WREG15)** va subiendo desde `0x1000` a medida que se guarda información.

#### 1. ¿Cómo quedó el arreglo de B después de `init()`?
En el arranque, hicimos `arregloProcB[0] = dirB;`. Si miramos la RAM en `0x084C`, se ve así:
*   `0x084C` (`arregloProcB[0]`): **`0x0300`** *(El PC de B)*
*   `0x084E` (`arregloProcB[1]`): `0x0000` *(El SR de B)*
*   `0x0850` (`arregloProcB[2]`): `0x0000` *(Registro W0)*
*   ...y así sucesivamente hasta completar las 38 posiciones.

#### 2. Entra la Interrupción (El Micro se congela)
El Proceso A estaba corriendo felizmente. ¡PUM! Suena el Timer 1.
1. **El Hardware (La CPU de forma automática)** empuja el PC actual de A y el SR al stack. Supongamos que el stack estaba en `0x1000`. Entonces en `0x1000` se guarda el PC de A, en `0x1002` el SR, y el **Puntero de Pila (SP / WREG15)** sube automáticamente.
2. Nuestro código ejecuta `GUARDAR_REGISTROS()`, empujando `W0-W14`. El **Puntero de Pila (SP / WREG15)** sigue subiendo.
3. Entramos a `planificador()`. Al ser una llamada a función por software (instrucción `CALL`), la CPU empuja **solamente el Program Counter (PC) de retorno** al stack. Esto hace que el `W15` suba un poco más. (Nota la diferencia: una función normal no guarda el SR, solo las interrupciones lo hacen).
4. **Estado final:** Ahora el **Puntero de Pila (SP / WREG15)** vale, por ejemplo, **`0x1026`**. 

> [!NOTE]
> Fíjate que el Stack (`0x1000`) está "lejos" del arreglo (`0x084C`). Por eso necesitamos los bucles `for`: para mover físicamente los datos de un lugar de la RAM al otro.

Míralo gráficamente:
```text
DIRECCIÓN DE RAM │ CONTENIDO DEL STACK (PILA FÍSICA)
─────────────────┼────────────────────────────────────
...              │ Variables locales del Proceso A...
0x1000           │ PC del Proceso A (Aquí debe ir dirB)  <-- QUEREMOS APUNTAR ACÁ
0x1002           │ SR del Proceso A
0x1004           │ W0 de A
...              │ ... (W1 al W14) ...
0x1024           │ PC de retorno del planificador
0x1026           │ Espacio Libre                         <-- WREG15 ACTUAL ESTÁ ACÁ
```

#### 4. La Aritmética de Punteros (`puntero -= DESPLAZAMIENTO`)
El código dice: `unsigned int* puntero = (unsigned int*)WREG15;`
Ahora `puntero` vale **`0x1026`**.

Sin embargo, para garantizar la integridad del contexto, la transferencia de bloques no debe iniciar desde el tope actual, sino **desde la base del marco de interrupción** (desde `0x1000`). Esto asegura que copiemos el PC apilado y evitemos sobreescribir el marco propio del `planificador`.
¿Cuál es la distancia entre `0x1026` y `0x1000`? Son **`0x26` bytes** (que equivalen a 38 en decimal).
Como nuestro puntero es de tipo `unsigned int*` (palabras de 2 bytes), 38 bytes / 2 = **19 posiciones**.

Por lo tanto, **`DESPLAZAMIENTO` tiene que valer 19**.
Al hacer `puntero -= 19;`, el puntero retrocede y ahora **`puntero` vale exactamente `0x1000`**. ¡Bingo! Estamos apuntando a la base del bloque.

![File Register](File_register.png)
*Figura 1: Vista de File Registers en MPLAB X. El PC se encuentra a la distancia calculada del tope.*

#### 5. El Bucle `for`: La magia del intercambio
Ahora entra el bucle:
```c
for(i=0; i<TOPE_ARREGLOS; i++) {
    arregloProcA[i] = *puntero;    
    *puntero = arregloProcB[i];    
    puntero++;
}
```
**Vuelta 0 (`i=0`):**
1. Guarda lo que hay en `0x1000` (El PC de A) dentro de `arregloProcA[0]`.
2. Escribe en `0x1000` lo que hay en `arregloProcB[0]`. ¿Recuerdas qué había ahí? **¡El `0x0300` (dirB)!**
3. `puntero++`. Ahora el puntero vale `0x1002`.

**Vuelta 1 (`i=1`):**
1. Guarda el SR de A.
2. Escribe en `0x1002` el SR de B (`0x0000`).
3. `puntero++`. Ahora vale `0x1004`.

**Al terminar el bucle:**
Hemos pisado las 19 o 35 posiciones del stack físico con los datos de B. 
Cuando el código termine y ejecute la instrucción **`RETFIE`** (Return from Interrupt), el hardware automáticamente irá a buscar el PC a la dirección base (`0x1000`). 
¿Y qué hay ahora en `0x1000`? Está el **`0x0300`**. 
El microcontrolador salta a esa dirección y ¡puf!, **el Proceso B comienza a ejecutarse**.

#### 5. Ciclo de Ejecución (Round-Robin)
La alternancia de procesos se mantiene indefinidamente mediante transiciones circulares:
*   Al expirar el Quantum de **B**, el planificador guarda su bloque y transfiere el contexto de **C** a la RAM. La instrucción `RETFIE` reanuda la ejecución en el PC de **C**.
*   Al expirar el Quantum de **C**, el proceso se repite, volcando el estado salvado previamente de **A** a la RAM. La instrucción `RETFIE` reanuda la ejecución de **A** en la instrucción exacta donde había sido suspendido.

Debido a que la topología lógica de los procesos A, B y C es de bucle infinito (`while(1)`), estos no alcanzan una condición de terminación (`return`). Su contexto permanece persistente y cicla entre la ejecución en CPU y la retención pasiva en los arreglos estáticos de RAM.

> [!IMPORTANT]
> **Conclusión para tu examen: El flujo de la "Conciencia" del Micro**
> En este sistema multitarea, la información fluye así:
> 1. **Persistencia (Flash):** El código de las funciones A, B y C nunca se mueve de la Memoria de Programa.
> 2. **Resguardo (Arreglo en RAM):** Cuando un proceso no está corriendo, su "punto de retorno" (PC) está guardado de forma segura en su Arreglo de contexto.
> 3. **Activación (Stack en RAM):** El planificador mueve ese PC desde el Arreglo hacia el Stack.
> 4. **Ejecución (Registro PC):** Al ejecutar `RETFIE`, el hardware mueve ese PC desde el Stack hacia el **Registro Físico Program Counter (PC)** de la CPU.
>
> El `DESPLAZAMIENTO` es crítico porque es el GPS matemático que le permite al puntero aterrizar exactamente en la dirección de RAM donde el hardware espera encontrar el PC para cargarlo en la CPU. Si fallamos por un solo byte, el micro saltará a una dirección errónea y el sistema colapsará (Address Error Trap).

---

## 📝 Resumen para la defensa:

Si el profesor te pregunta cómo funciona tu código, recuerda estas palabras clave:

1.  **Contexto:** Es el conjunto de Program Counter (PC), Status Register (SR) y Registros de Trabajo (WREG0...WREG14). Es la "mente" del proceso.
2.  **Stack Swapping:** Es la técnica de intercambiar el contenido de la pila física con arreglos en RAM.
3.  **Puntero de Pila (SP / WREG15):** Lo usamos como referencia para saber desde dónde copiar.
4.  **Quantum:** Es el tiempo de vida que le damos a cada proceso antes de sacarlo a la fuerza.

---
> [!TIP]
> **Comparativa de Rendimiento Arquitectónico:**
> El método de cambiar el puntero `W15` (Múltiples Pilas) es computacionalmente más eficiente con un costo constante de ejecución $O(1)$. El método actual (Stack Swapping / Pizarra) requiere copiar memoria secuencialmente, generando una penalización en ciclos de instrucción $O(N)$ proporcional al tamaño de `TOPE_ARREGLOS`. No obstante, implementarlo requiere un control matemático de la aritmética de punteros que demuestra profundo entendimiento del hardware.
