# Análisis Alternativo: TP2 Ejercicio 2 - Multitask (por Claude)

> Este documento es un **complemento** al Walkthrough original creado por Gemini. No reemplaza ni modifica el existente. Ofrece una segunda perspectiva sobre la misma solución, profundizando en aspectos técnicos y de memoria.

---

## Enunciado Oficial: Ejercicio 2 (Multitask)
Simular la ejecución concurrente de tres procesos independientes (A, B y C) mediante un planificador Round-Robin con un **Quantum de 2 interrupciones de reloj**. El sistema debe resguardar y restaurar el contexto completo (registros) de cada proceso utilizando una estructura de datos (PCB) y pilas independientes.

---

## Mi Enfoque: Ver el Problema desde la Pila

Gemini lo explicó brillantemente con la analogía del televisor y los hermanos. Yo voy a usar una analogía diferente que se enfoca más en lo que pasa **adentro de la memoria**, porque ahí es donde realmente sucede toda la magia.

### La Analogía del Escritorio Compartido

Imaginá una oficina con un solo escritorio (la CPU) y tres empleados (A, B, C). Cada empleado tiene su propia caja de zapatos (su Stack/Pila) donde guarda sus papeles de trabajo.

Cuando suena la campana (Timer):
1. El empleado actual mete **todos sus papeles** dentro de su caja (GUARDAR_CONTEXTO).
2. Un guardia (el Kernel) anota cuál era la caja que estaba usando (guarda el SP en el PCB).
3. El guardia saca la caja del siguiente empleado y la pone en el escritorio (carga el SP nuevo).
4. El nuevo empleado saca sus papeles de la caja (RESTAURAR_CONTEXTO) y sigue trabajando.

La diferencia con la analogía del televisor es que acá queda claro que **el escritorio es el mismo, pero los papeles cambian**. Y eso es lo que realmente pasa: la CPU es una sola, y lo que cambiamos son los registros que tiene cargados.

---

## Análisis Detallado de la Solución

### 1. El PCB Minimalista: ¿Por qué alcanza con guardar solo el SP?

La guía de Gemini ya explicó que solo guardamos el Stack Pointer. Pero profundicemos en el **por qué** con un diagrama de lo que pasa en la memoria:

```
PILA DEL PROCESO B (stackB[128]) después de ser interrumpido:
┌───────────────┐ ← stackB[0]
│ PC (dirección)│  ← Lo puso el hardware automáticamente al entrar a la ISR
├───────────────┤
│ SR (status)   │  ← Lo puso el hardware automáticamente
├───────────────┤
│ W0            │  ← Lo pusimos nosotros con GUARDAR_CONTEXTO
├───────────────┤
│ W1            │
├───────────────┤
│ W2            │
├───────────────┤
│ ...           │
├───────────────┤
│ W14           │
├───────────────┤
│ (vacío)       │ ← El SP apunta ACÁ (justo arriba del último dato guardado)
├───────────────┤
│ ...           │
└───────────────┘ ← stackB[127]
```

¿Ves? Con **una sola dirección** (el SP) sabemos exactamente dónde arrancar a hacer `pop` para sacar los 15 registros, y debajo de ellos están el PC y el SR que el hardware sacará solo con el `RETFIE`. Es como un cajón perfectamente apilado: si sabés dónde está la tapa, podés sacar todo en orden.

---

### 2. La Inicialización Fantasma: El Truco Más Elegante

Acá quiero profundizar en algo que la guía de Gemini menciona pero que merece más atención: **¿por qué `stackB[17]` y no `stackB[2]`?**

Hagamos la cuenta de lo que necesita estar "debajo" del SP cuando el planificador intente restaurar el proceso B por primera vez:

```
Posición en stackB:    ¿Qué hay guardado?
─────────────────────────────────────────
stackB[0]              PC bajo (dirección de procesoB)
stackB[1]              SR (Status Register = 0x0000)
stackB[2]              W0  (valor inicial = 0, basura, no importa)
stackB[3]              W1
stackB[4]              W2
stackB[5]              W3
stackB[6]              W4
stackB[7]              W5
stackB[8]              W6
stackB[9]              W7
stackB[10]             W8
stackB[11]             W9
stackB[12]             W10
stackB[13]             W11
stackB[14]             W12
stackB[15]             W13
stackB[16]             W14
─── SP apunta acá ───> stackB[17]  (primera posición LIBRE)
```

**La cuenta:** 2 posiciones (PC + SR) + 15 posiciones (W0 a W14) = **17 posiciones ocupadas**. 
Por eso `procesos[1].sp = &stackB[17]` — apunta justo arriba de los 17 datos falsificados.

Cuando RESTAURAR_CONTEXTO haga `pop`, va a sacar los valores de `stackB[16]` hacia abajo (W14 primero, W0 último). Y cuando el `RETFIE` final se ejecute, va a sacar el PC de `stackB[0]` y saltará a `procesoB()`.

> **Punto de discusión:** En la solución actual, los valores iniciales de W0-W14 para B y C son basura de memoria (lo que sea que haya en esas posiciones del arreglo). Esto funciona porque `procesoB()` y `procesoC()` inicializan sus propias variables locales (`a=1; b=3;` etc.) antes de usarlas. Si algún proceso dependiera de un registro sin inicializar, tendríamos un bug fantasma.

---

### 3. El push.d: ¿Qué significa la "d"?

La guía menciona las macros de Assembly pero no profundiza en qué hace `push.d`. La "d" viene de **"double"** (doble). En el dsPIC:

- `push w0` → guarda **1 solo** registro (W0) en la pila.
- `push.d w0` → guarda **2 registros consecutivos** (W0 y W1) en la pila de un solo golpe.

Por eso la macro usa:
```asm
push.d w0    → guarda W0 y W1
push.d w2    → guarda W2 y W3
push.d w4    → guarda W4 y W5
push.d w6    → guarda W6 y W7
push.d w8    → guarda W8 y W9
push.d w10   → guarda W10 y W11
push.d w12   → guarda W12 y W13
push w14     → guarda W14 solo (porque es el último, no tiene pareja)
```

**Total: 7 instrucciones dobles + 1 simple = 15 registros guardados (W0 a W14).**

El `pop` (restaurar) se hace en **orden inverso** porque la pila es LIFO (Last In, First Out): lo último que entró es lo primero que sale.

---

### 4. El Momento Crítico: ¿Qué pasa con la pila del _T1Interrupt?

Hay un detalle sutil que ni la guía de Gemini ni los comentarios del código mencionan explícitamente: cuando la interrupción del Timer salta, el dsPIC **ya estaba usando la pila del proceso actual**. Esto significa que:

1. El Proceso A está corriendo, usando `stackA` (o más precisamente, la pila general del programa, ya que A arranca desde `main()`).
2. El Timer interrumpe. El hardware automáticamente pushea el PC y SR **en la misma pila que estaba usando el Proceso A**.
3. Nuestra macro `GUARDAR_CONTEXTO()` pushea W0-W14 **también en la pila de A**.
4. Guardamos el SP en `procesos[0].sp`.
5. Cambiamos WREG15 a la pila de B.
6. `RESTAURAR_CONTEXTO()` popea W0-W14 **de la pila de B**.
7. `RETFIE` popea PC y SR **de la pila de B** → salta a `procesoB()`.

**El punto clave:** En los pasos 2-4, estamos operando sobre la pila de A. En los pasos 6-7, sobre la pila de B. El "truco" es que el cambio de `WREG15` en el paso 5 es lo que mueve la "realidad" de una pila a otra. Es literalmente como cambiar los rieles de un tren mientras está en movimiento.

---

### 5. Un Detalle del Proceso A que es Diferente a B y C

Hay una asimetría interesante: el Proceso A **nunca usa stackA[]**. ¿Por qué?

Porque A arranca directamente desde `main()`, que usa la **pila principal del programa** (la que el compilador y el linker configuran automáticamente al arrancar el microcontrolador). El arreglo `stackA[128]` está declarado en `kernel.c` pero nunca se referencia en ninguna parte del código.

Esto significa que cuando el Kernel guarda el SP de A (`procesos[0].sp = WREG15`), está guardando una dirección que apunta a la **pila general del sistema**, no a `stackA[]`. Cuando lo restaure, volverá a esa misma pila general.

> **Esto funciona correctamente**, pero hay que tener conciencia de que A tiene un "privilegio" especial: su pila es más grande y está en una zona de memoria diferente a la de B y C.

---

### 6. ¿Qué pasa si el Quantum fuera 1 en vez de 2?

Con `quantum = 1`, cada interrupción del Timer provocaría un cambio de contexto. Esto significa:
- **Más equidad:** Cada proceso recibe exactamente 1 tick de CPU antes de ser sacado.
- **Más overhead:** El cambio de contexto tiene un costo (guardar 15 registros, cargar otros 15, llamar al planificador). Si el Timer interrumpe cada 1ms y el cambio de contexto toma 20us, con quantum=1 estamos perdiendo el 2% del tiempo de CPU solo en burocracia administrativa.
- Con `quantum = 2`, el cambio ocurre cada 2 ticks, reduciendo el overhead a la mitad.

Es un balance clásico de Sistemas Operativos: **más quantum = más eficiencia pero menos responsividad**.

---

### 7. Tabla Resumen: ¿Quién Hace Qué?

| Componente | Responsabilidad | Archivo |
|---|---|---|
| `procesoA/B/C()` | Ejecutan su lógica de negocio sin saber que son interrumpidos | `main.c` |
| `boot()` | Orquesta el arranque: inicializa pilas + configura Timer | `kernel.c` |
| `init()` | Falsifica las pilas de B y C para que el planificador las pueda restaurar | `kernel.c` |
| `confReloj()` | Configura Timer1 como "latido" periódico del SO | `kernel.c` |
| `planificador()` | Algoritmo Round-Robin: decide quién sigue y renueva quantum | `kernel.c` |
| `_T1Interrupt()` | El corazón: ejecuta el cambio de contexto completo | `kernel.c` |
| `GUARDAR_CONTEXTO` | Macro ASM: empuja W0-W14 a la pila actual | `kernel.c` |
| `RESTAURAR_CONTEXTO` | Macro ASM: saca W0-W14 de la pila nueva | `kernel.c` |
| Hardware (RETFIE) | Automáticamente restaura PC y SR al salir de la ISR | CPU física |

---

## Conclusión: Lo que ambos modelos coincidimos

La solución del kernel se resume en **3 trucos fundamentales**:
1. **Aislar las pilas** → Cada proceso tiene su propia memoria para variables y registros.
2. **Falsificar el arranque** → Los procesos B y C nunca corrieron, pero armamos sus pilas como si los hubieran interrumpido antes.
3. **Intercambiar el WREG15** → Una sola línea de código (`WREG15 = procesos[procesoActual].sp`) es lo que hace posible toda la ilusión de la multitarea.

La diferencia entre las explicaciones es de **enfoque**: Gemini se centra en la narrativa y la construcción paso a paso (ideal para entender el flujo); este análisis se centra en **qué pasa exactamente en la memoria** (ideal para entender el "por qué" de cada número mágico como el 17, y para depurar si algo sale mal en el simulador).
