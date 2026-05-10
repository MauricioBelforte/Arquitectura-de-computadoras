# Guía de Preparación para Examen: Práctica 2
**Materia:** Arquitectura de Computadoras
**Arquitectura:** dsPIC33F

Esta guía es de uso exclusivo para preparar la demostración en vivo de los códigos aprobados y entregados ante el docente. Contiene la configuración estricta del simulador y posibles preguntas trampa.

---

## 1. Ejercicio 1: Productor / Consumidor

### Simulación en MPLAB X
1. **Configuración del Stimulus:**
   - Crear un archivo `.sbs`. Configurar una acción de "Asynchronous Stimulus".
   - **Pin/SFR:** Seleccionar `PORTB`.
   - **Action:** Set High o Toggle para simular la pulsación de las teclas.
   - *Nota:* Como la interrupción `INT1` se dispara por flanco en un pin, en el Stimulus debés asegurarte de generar el flanco (Toggle) o usar la función específica de inyección de registro para el valor ASCII.
2. **Ventana de Watches Variables Clave:**
   - `caracteresPendientes` (debe subir a 1 con la pulsación y bajar a 0 cuando el main pasa).
   - `indBuffer` e `indConsum` (deben verse cíclicos, volviendo a 0 al llegar a los límites).
   - `buffer` y `logOperaciones` (Visualizarlos como arreglos para ver los valores Hexadecimales o ASCII que caen allí).
   - `cantFallas` (debe verse cómo se resetea a 0 cuando hay un caracter nuevo, y sube hasta `MAX_FALLAS` si no los hay).

### Preguntas Trampa del Docente (Ej 1)

**Pregunta 1:** *"En tu `main.c`, hacés `caracteresPendientes = 0;`. ¿Qué pasa si justo en ese instante el hardware lanza una interrupción INT1, entra un caracter nuevo, y la variable vale 1?"*
**Respuesta:** (Manejalo con altura académica). "Efectivamente profesor, existe una condición de carrera (Race Condition). El código en C se desglosa en varias instrucciones ensamblador. Si la interrupción `_INT1Interrupt` incrementa `caracteresPendientes` justo antes de que el `main` ejecute el *clear* final, ese dato se perdería lógicamente. Para un diseño estrictamente seguro, se debería envolver esa línea deshabilitando brevemente la interrupción con `IEC1bits.INT1IE = 0;`, operar la variable restando la cantidad procesada, y restaurando el bit `IEC1bits.INT1IE = 1;`."

**Pregunta 2:** *"¿Por qué configuras `PR1` en 6000 con prescaler 1:1?"*
**Respuesta:** "Dado que Fosc es 40MHz, Fcy es 20MHz. El ciclo de instrucción Tcy tarda 0.05µs. Si el Timer usa prescaler 1:1, cada pulso del timer tarda 0.05µs. Si quiero 150µs, la división 150 / 0.05 es 3000. *Wait, revisar el código!* Mi código dice `PR1 = 6000` asumiendo `Tcy = 0.025µs` (lo que implica Fcy de 40MHz, que viene de Fosc de 80MHz con PLL). Es importante aclarar que se asume ese Tcy basado en la constante 6000 para cumplir 150µs."

---

## 2. Ejercicio 2: Kernel Multitarea (Stack Swap)

### Simulación en MPLAB X
1. **Puntos de Breakpoint (Fundamentales):**
   - Dentro del bucle `while(1)` de `procesoA()`, `procesoB()` y `procesoC()`.
   - Dentro del `_T1Interrupt()`.
   - Dentro del `planificador()` justo antes y después del `switch(estadoProceso)`.
2. **Uso del Stopwatch:**
   - Ubicá un breakpoint en `_T1Interrupt()`. 
   - Limpiá el Stopwatch. Dale *Run*.
   - El simulador parará al entrar a la interrupción. Si verificas el tiempo, debe haber pasado `VALOR_PR1` ciclos de instrucción multiplicado por el `QUANTUM` para ver cuánto demora un proceso en soltar la CPU.
3. **Ventana de Watches Variables Clave:**
   - `WREG15` (Importantísimo ver su valor en Hexadecimal).
   - `estadoProceso` (para ver las transiciones 0 -> 1 -> 2 -> 0).
   - `arregloProcA`, `arregloProcB`, `arregloProcC`.

### Preguntas Trampa del Docente (Ej 2)

**Pregunta 1:** *"¿Por qué le restas `DESPLAZAMIENTO` al WREG15 dentro del planificador?"*
**Respuesta:** "Porque al invocar al `planificador()` desde la interrupción `_T1Interrupt`, la CPU apiló más registros, como el PC de retorno de la propia función `planificador()`. El `WREG15` está en lo más alto del bloque apilado. Para copiar correctamente el contexto original que fue interrumpido, necesito retroceder el puntero exactamente hasta la base del marco de interrupción (donde se encuentra el Program Counter original del proceso)."

**Pregunta 2:** *"¿Qué contiene la dirección `arregloProcB[0]` cuando llamas a `init()`?"*
**Respuesta:** "Contiene la dirección base en la Memoria de Programa (Flash) de la función `procesoB()`. Es el Program Counter (PC) inicial. Cuando el planificador escriba ese valor en la base física de la Pila RAM, la instrucción de retorno `RETFIE` lo cargará en el PC de la CPU, ejecutando el proceso por primera vez."

**Pregunta 3:** *"¿Podemos usar registros globales para las variables `x,y,z` o `a,b,c` de los procesos?"*
**Respuesta:** "No es recomendable sin protección por mutex. Al tratarse de concurrencia, si usamos globales (GPR), múltiples tareas podrían pisar la misma dirección de memoria, perdiendo la integridad de sus cálculos."
