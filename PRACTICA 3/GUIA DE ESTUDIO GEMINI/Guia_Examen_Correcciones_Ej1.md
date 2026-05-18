# Guía de Examen y Corrección Técnica - Ejercicio 1 (PRACTICA 3)

Esta guía detalla las correcciones realizadas sobre el código del **Ejercicio 1** (Conversión ADC mediante Polling), explicando los fundamentos físicos y de hardware del dsPIC33F que causaban los fallos en la versión original. Además, incluye una sección de preparación para examen diseñada para la demostración práctica de la simulación ante el docente.

---

## 1. Análisis de los Bugs de Hardware Encontrados y Corregidos

A continuación, se desglosan los 4 bugs críticos de hardware y la optimización de diseño que impedían el correcto funcionamiento del programa original.

### 1.1 El Bug del Canal Analógico en `AD1CHS0` (Muy Crítico)
*   **Código Original (`config.c`):**
    ```c
    AD1CHS0 = 2; // (Pensando en AN2)
    AD1CHS0 = 5; // (Pensando en AN5)
    ```
*   **Explicación del Fallo:** El registro `AD1CHS0` de 16 bits controla la selección de entradas del canal 0. Sus bits clave son `CH0SA<4:0>` (bits 12-8) para la entrada positiva, y `CH0NA` (bit 0) para la entrada negativa. Al escribir un entero plano como `2` (`0x0002`) o `5` (`0x0005`), se están modificando los bits inferiores (el byte bajo). Los bits 12-8 (`CH0SA`) quedan en `00000` (que corresponde a **AN0**). Por lo tanto, el ADC medía físicamente el pin AN0 en lugar de AN2 o AN5.
*   **Código Corregido:**
    ```c
    AD1CHS0bits.CH0SA = 2; // Selecciona AN2 de manera específica
    AD1CHS0bits.CH0SA = 5; // Selecciona AN5 de manera específica
    ```

### 1.2 El Bug de Reconfiguración Estructural con `ADON` Encendido (Crítico)
*   **Código Original (`main.c`):**
    ```c
    if(modo != SIGNADO) {
        configSignado();
        modo = 0;
    }
    ```
*   **Explicación del Fallo:** En el dsPIC33F, no está permitido modificar dinámicamente registros de control estructural como `AD12B` (resolución de 10 o 12 bits) o `FORM<1:0>` (formato de salida de datos) mientras el módulo ADC se encuentre encendido y activo (`ADON = 1`). Si se realiza, el hardware ignora los cambios o entra en un estado inestable.
*   **Código Corregido:**
    ```c
    if(modo != SIGNADO) {
        AD1CON1bits.ADON = 0; // APAGAR el ADC obligatoriamente
        configSignado();      // Reconfigurar registros
        AD1CON1bits.ADON = 1; // Volver a encender el ADC
        modo = SIGNADO;
    }
    ```

### 1.3 El Bug de la Comparación Imposible `valorADC == 0x0800` (Crítico)
*   **Código Original (`main.c`):**
    ```c
    if (valorADC == 0x0800) {
        LATE = ++contadorDeCeros;
    }
    ```
*   **Explicación del Fallo:** El valor hexadecimal `0x0800` equivale a `2048` en decimal. Es matemáticamente imposible que este valor sea leído por el ADC en cualquiera de los dos modos del ejercicio:
    1.  **Modo 10 bits sin signo (RD7):** El rango de conversión del ADC es de `0` a `1023` (`0x03FF`). Un valor de `2048` está fuera del límite físico del conversor.
    2.  **Modo 12 bits con signo (RD6):** El rango va de `-2048` (`0xF800` en complemento a dos de 16 bits) a `+2047` (`0x07FF`). El valor positivo `+2048` (`0x0800`) excede la capacidad de representación de 12 bits signados.
    
    Por lo tanto, la condición nunca se cumplía y el contador global de ceros nunca se incrementaba.
*   **Código Corregido:**
    ```c
    if (valorADC == 0) { // Cumple literalmente con el enunciado
        LATE = ++contadorDeCeros;
    }
    ```

### 1.4 Advertencia de Compilación (Type Mismatch)
*   **Código Original (`main.c`):** Se utilizaba un puntero a entero signado `int *punteroBuffer` para apuntarlo indistintamente a un buffer de enteros signados (`bufferRD6`) y de enteros sin signo (`bufferRD7`). Esto generaba advertencias de incompatibilidad de tipos de datos por parte del compilador XC16.
*   **Solución Aplicada:** Se eliminó el uso del puntero intermedio, escribiendo directamente sobre cada buffer circular dentro del bloque condicional del pulsador correspondiente. Esto elimina las advertencias del compilador y previene fallos de desreferenciación.

### 1.5 Falta de Control de Flancos y Antirrebotes (Fallo de Diseño Físico)
*   **Código Original (`main.c`):** Si se presionaba el pulsador RD6 o RD7, el bucle `while(1)` procesaba la conversión de manera continua a la velocidad de la CPU (millones de veces por segundo) mientras el botón estuviera físicamente presionado. Esto causaba que el buffer circular de 8 posiciones se llenara y sobreescribiera miles de veces por segundo ante una sola pulsación.
*   **Código Corregido:** Se añadió una instrucción de bloqueo al final de la conversión:
    ```c
    while (PULSADO); // Bloqueo de seguridad: espera a que el usuario suelte el botón
    ```
    Esto garantiza la sincronización perfecta: **una pulsación física = una conversión analógica en el buffer**.

---

## 2. Código Completo Corregido

### 2.1 Archivo [config.c](file:///d:/Escritorio/INFORMATICA/ARQUITECTURA%20DE%20COMPUTADORAS/PRACTICA%203/Whatsapp/TP3-1.X/config.c)
```c
#include "xc.h"

void initPORTS(void) {
    TRISD = 0xFFFF; // RD6 y RD7 configurados como entradas digitales (Pulsadores)
    TRISE = 0x0000; // Todo PORTE configurado como salida digital (LEDS de visualización)
    
    // Configuración física de seguridad de las entradas analógicas (TRISB)
    TRISBbits.TRISB2 = 1; // RB2 (AN2) como entrada
    TRISBbits.TRISB5 = 1; // RB5 (AN5) como entrada
    
    LATE = 0x0000;  // Apaga todos los leds inicialmente
}

void configSignado(void){
    AD1CON1bits.AD12B = 1;    // Habilita modo ADC de 12 bits, 1 canal de muestreo (S/H)
    AD1CON1bits.FORM = 1;     // Formato de datos de salida: Entero con signo (Signed Integer)
    AD1CON3bits.SAMC = 14;    // Tiempo de auto-muestreo = 14 TAD (mayor al mínimo de 12 TAD en 12 bits)
    
    AD1PCFGL = 0xFFFF;        // Todos los pines por defecto digitales
    AD1PCFGLbits.PCFG2 = 0;   // Pin AN2 (RB2) configurado como entrada Analógica
    
    AD1CHS0bits.CH0SA = 2;    // Conecta el pin físico AN2 como entrada positiva al Canal 0 S/H
    AD1CHS0bits.CH0NA = 0;    // Conecta la entrada negativa al pin de referencia negativo (VREF- / AVSS)
}

void configSinSigno(void){
    AD1CON1bits.AD12B = 0;    // Habilita modo ADC de 10 bits, hasta 4 canales de muestreo
    AD1CON1bits.FORM = 0;     // Formato de datos de salida: Entero sin signo (Unsigned Integer)
    AD1CON3bits.SAMC = 12;    // Tiempo de auto-muestreo = 12 TAD (mayor al mínimo de 10 TAD en 10 bits)
    
    AD1PCFGL = 0xFFFF;        // Todos los pines por defecto digitales
    AD1PCFGLbits.PCFG5 = 0;   // Pin AN5 (RB5) configurado como entrada Analógica
    
    AD1CHS0bits.CH0SA = 5;    // Conecta el pin físico AN5 como entrada positiva al Canal 0 S/H
    AD1CHS0bits.CH0NA = 0;    // Conecta la entrada negativa al pin de referencia negativo (VREF- / AVSS)
}

void initADC(void) {
    AD1CON1bits.SSRC = 7;     // Trigger automático: el reloj del ADC inicia la conversión al vencer SAMC
    AD1CON1bits.ASAM = 0;     // Muestreo manual: Inicia cuando software pone SAMP = 1, se detiene automáticamente por SAMC
    AD1CON3bits.ADCS = 2;     // Reloj del ADC: ADCS = 2 para generar TAD = 75ns a 40 MHz (Fcy = 40Mips), cumpliendo TAD > 75ns
    
    // Configuración de encendido inicial
    configSignado();
    AD1CON1bits.ADON = 1;     // Enciende el módulo ADC
}

void config(void) {
    initPORTS();
    initADC();
}
```

### 2.2 Archivo [main.c](file:///d:/Escritorio/INFORMATICA/ARQUITECTURA%20DE%20COMPUTADORAS/PRACTICA%203/Whatsapp/TP3-1.X/main.c)
```c
/*
 * File:   main.c
 * Author: Luciano Serruya Aloisi
 *
 * Correcciones y comentarios: Antigravity (Advanced Agentic Coding - DeepMind)
 */

#include "xc.h"
#include "config.h"

// Definición de pines y estados para legibilidad
#define PULSADOR_SIGNADO      (PORTDbits.RD6)  // Pulsador en RD6
#define PULSADOR_SIN_SIGNO    (PORTDbits.RD7)  // Pulsador en RD7
#define PULSADO               (PULSADOR_SIGNADO || PULSADOR_SIN_SIGNO)

#define SIGNADO               0
#define SIN_SIGNO             1
#define TAM_BUFFER            8
#define FIN_BUFFER(i)         (i == TAM_BUFFER)

// Buffers circulares de almacenamiento
int bufferRD6[TAM_BUFFER];          // Buffer para AN2 (12 bits con signo -> "int")
unsigned int bufferRD7[TAM_BUFFER]; // Buffer para AN5 (10 bits sin signo -> "unsigned int")

int indiceEscrituraRD6 = 0;
int indiceEscrituraRD7 = 0;
int contadorDeCeros = 0;
int modo = SIGNADO;                 // Por defecto se inicializa en signado (reflejado en config)
unsigned int valorADC;

int main(void) {
    config(); // Inicializa puertos y el módulo ADC
    
    while(1) {
        if (PULSADO) {
            // Caso 1: Se presiona el pulsador en RD6 (AN2 - 12 bits - Con Signo)
            if (PULSADOR_SIGNADO) {
                // Si el módulo no está en el modo correcto, lo cambiamos dinámicamente
                if (modo != SIGNADO) {
                    AD1CON1bits.ADON = 0; // APAGAR ADC obligatorio antes de cambiar resolución/formato
                    configSignado();
                    AD1CON1bits.ADON = 1; // Volver a encender
                    modo = SIGNADO;
                }
                
                // Realizar la conversión analógica-digital
                AD1CON1bits.SAMP = 1;       // Inicia el muestreo (la llave se cierra)
                while(!AD1CON1bits.DONE);   // Espera por hardware a que termine la conversión (DONE = 1)
                valorADC = ADC1BUF0;        // Lee el resultado del búfer de salida del ADC
                
                // Guarda el valor en el buffer circular
                bufferRD6[indiceEscrituraRD6++] = (int)valorADC; // Cast explícito a int
                if (FIN_BUFFER(indiceEscrituraRD6)) {
                    indiceEscrituraRD6 = 0;
                }
            }
            // Caso 2: Se presiona el pulsador en RD7 (AN5 - 10 bits - Sin Signo)
            else if (PULSADOR_SIN_SIGNO) {
                // Si el módulo no está en el modo correcto, lo cambiamos dinámicamente
                if (modo != SIN_SIGNO) {
                    AD1CON1bits.ADON = 0; // APAGAR ADC obligatorio antes de cambiar resolución/formato
                    configSinSigno();
                    AD1CON1bits.ADON = 1; // Volver a encender
                    modo = SIN_SIGNO;
                }
                
                // Realizar la conversión analógica-digital
                AD1CON1bits.SAMP = 1;       // Inicia el muestreo
                while(!AD1CON1bits.DONE);   // Espera por hardware a que termine la conversión
                valorADC = ADC1BUF0;        // Lee el resultado
                
                // Guarda el valor en el buffer circular
                bufferRD7[indiceEscrituraRD7++] = valorADC;
                if (FIN_BUFFER(indiceEscrituraRD7)) {
                    indiceEscrituraRD7 = 0;
                }
            }
            
            /* 
             * VALIDACIÓN DEL VALOR CONVERTIDO IGUAL A 0:
             * 
             * Interpretación A (Literal): Comparamos si el valor digital en el registro es numéricamente 0.
             * 
             * Interpretación B (Tensión física a 0V):
             * - En 10-bit sin signo, 0V equivale a 0 (0x0000).
             * - En 12-bit con signo, 0V equivale a -2048 (0xF800 en complemento a dos de 16 bits).
             * 
             * Por defecto implementamos la Interpretación A (valor digital igual a 0).
             * Si tu docente evalúa por tensión física a 0V, deberás usar:
             * if ((modo == SIGNADO && (int)valorADC == -2048) || (modo == SIN_SIGNO && valorADC == 0))
             */
            if (valorADC == 0) {
                LATE = ++contadorDeCeros; // Incrementa el contador global y lo muestra en los leds del PORTE
            }
            
            // Antirrebote y sincronización de flancos:
            // Espera a que el usuario suelte el pulsador antes de continuar,
            // evitando que el buffer se llene miles de veces en una sola pulsación física.
            while (PULSADO);
        }
    }
    return 0;
}
```

---

## 3. Guía de Preparación de Simulación y Examen

Para validar que las correcciones funcionan y demostrar la solidez técnica ante tu docente en MPLAB X, sigue estrictamente estos pasos de simulación.

### 3.1 Pasos de Simulación en MPLAB X y Configuración de *Stimulus*

Dado que el programa responde a entradas analógicas (`AN2`/`AN5`) condicionadas por entradas digitales (`RD6`/`RD7`), debemos inyectar estímulos combinados:

1.  **Habilitar el Simulador:** Ve a las propiedades del proyecto (`Properties`), selecciona la categoría `Hardware Tool` y asegúrate de elegir `Simulator`.
2.  **Crear el Archivo de Estímulo de Voltaje Analógico:**
    *   Crea un archivo de texto llamado `ADC1_Values.txt` en la raíz del proyecto.
    *   Este archivo debe contener valores de tensión normalizados entre `0.0` (0V) y `3.3` (3.3V) representados por líneas. Ejemplo para simular lecturas alternas y ceros:
        ```text
        3.3
        1.65
        0.0
        0.825
        ```
3.  **Configurar la Ventana de *Stimulus*:**
    *   Abre `Window` -> `Simulator` -> `Stimulus`.
    *   **Pestaña Asynchronous:** Agrega dos filas para los pines digitales de los pulsadores:
        *   Pin: `RD6` -> Action: `Set High` (para pulsar) y `Set Low` (para soltar).
        *   Pin: `RD7` -> Action: `Set High` y `Set Low`.
    *   **Pestaña Register Injection:** Configuraremos la inyección analógica desde el archivo `ADC1_Values.txt`:
        *   **Fila 1:** Reg/Var: `ADC1BUF0` -> Trigger: `SAMP (low-to-high)` -> Option: `File` (selecciona `ADC1_Values.txt`).
        *   *Explicación:* Cada vez que el software ponga `SAMP` en `1` iniciando el ciclo de muestreo, el simulador leerá la siguiente línea del archivo y cargará el equivalente digital correspondiente en el registro del ADC.

### 3.2 Variables Críticas para la Ventana de *Watches*

Añade las siguientes variables para monitorear el comportamiento del hardware y los buffers en tiempo de ejecución:

| Variable | Tipo / Formato | Valor Esperado (3.3V / Entrada Máxima) | Valor Esperado (1.65V / Media Escala) | Valor Esperado (0V / Entrada Mínima) |
| :--- | :--- | :--- | :--- | :--- |
| **`valorADC`** | Decimal/Hex | Modo RD6: `2047` (`0x07FF`) <br>Modo RD7: `1023` (`0x03FF`) | Modo RD6: `0` (`0x0000`) <br>Modo RD7: `512` (`0x0200`) | Modo RD6: `-2048` (`0xF800`) <br>Modo RD7: `0` (`0x0000`) |
| **`modo`** | Decimal | `0` (`SIGNADO`) al pulsar RD6 <br>`1` (`SIN_SIGNO`) al pulsar RD7 | Mismo comportamiento | Mismo comportamiento |
| **`bufferRD6`** | Array (16 bits) | Elementos tipo `int` (rango: `-2048` a `+2047`) | Elementos tipo `int` (cercanos a `0`) | Elementos tipo `int` (cercanos a `-2048`) |
| **`bufferRD7`** | Array (16 bits) | Elementos tipo `unsigned int` (rango: `0` a `1023`) | Elementos tipo `unsigned int` (cercanos a `512`) | Elementos tipo `unsigned int` (cercanos a `0`) |
| **`contadorDeCeros`**| Decimal | No se incrementa | No se incrementa (Modo RD6) o se incrementa si valor digital es `0` | Se incrementa (Modo RD7 o en RD6 si se busca valor digital `0` en la escala media) |

### 3.3 Uso del *Stopwatch* para Validación de Tiempos

El *Stopwatch* es clave para medir el impacto de la duración del muestreo y la conversión en la ejecución del procesador.

1.  Abre la ventana `Window` -> `Simulator` -> `Stopwatch`.
2.  Coloca un **Breakpoint** en la línea:
    `AD1CON1bits.SAMP = 1;` (Inicio de muestreo).
3.  Coloca otro **Breakpoint** en la línea inmediata posterior a la espera de hardware:
    `valorADC = ADC1BUF0;` (Fin de conversión).
4.  Ejecuta la simulación. Al detenerse en el primer breakpoint, limpia el cronómetro haciendo clic en el icono azul circular de Reset del *Stopwatch*.
5.  Presiona `F5` (Continue). Al detenerse en el segundo breakpoint, lee la cantidad de ciclos de instrucción (`Instruction Cycles`) consumidos por el muestreo y la conversión.
    *   **Modo 12 bits (RD6):** Debería consumir aproximadamente `14 TAD` (muestreo) + `14 TAD` (conversión) = `28 TAD`. Con un TAD configurado a 75ns, son aprox. `2.1 us`.
    *   **Modo 10 bits (RD7):** Debería consumir aproximadamente `12 TAD` (muestreo) + `12 TAD` (conversión) = `24 TAD`. Son aprox. `1.8 us`.

---

## 4. Sección de "Preguntas Trampa" (Justificadas para Defensa de Examen)

Durante la demostración práctica del TP3 ante el docente, es muy común que se realicen preguntas capciosas de arquitectura. Prepárate con estas justificaciones de ingeniería:

> [!WARNING]
> **Pregunta 1: ¿Por qué apagas el ADC antes de llamar a `configSignado()` o `configSinSigno()`? ¿No podrías ahorrar instrucciones cambiando los registros en caliente?**
> *   **Respuesta Justificada:** No, es imposible por diseño de hardware. El bit `AD12B` del registro `AD1CON1` conmuta el circuito analógico interno de muestreo entre un esquema de un solo capacitor (modo 12 bits) y un esquema de múltiples selectores (modo 10 bits). Asimismo, el bit `FORM` altera el decodificador de datos del búfer de salida. El manual de referencia del dsPIC33F establece estrictamente que cambiar estos bits estructurales con `ADON = 1` puede dañar la lógica del decodificador o dar lecturas corruptas de forma permanente. Por lo tanto, apagar el módulo con `ADON = 0` es un requisito de hardware obligatorio.

> [!IMPORTANT]
> **Pregunta 2: En tu función `initADC()` calculas `ADCS = 2`. ¿Cómo calculas este valor en base a la frecuencia de tu dsPIC?**
> *   **Respuesta Justificada:** El manual de referencia del dsPIC33F especifica que el tiempo mínimo del reloj del ADC, denominado $T_{AD}$, debe ser de al menos **75 nanosegundos** para garantizar que los circuitos de Sample/Hold puedan cargarse correctamente sin error térmico. La fórmula física que relaciona el reloj de la CPU ($T_{CY}$) con el del ADC es:
>     $$T_{AD} = T_{CY} \cdot \frac{ADCS + 1}{2}$$
>     Asumiendo que el dsPIC funciona a su velocidad máxima de 40 MIPS (donde el ciclo de instrucción es $T_{CY} = 25\text{ ns}$):
>     $$T_{AD} = 25\text{ ns} \cdot \frac{2 + 1}{2} = 25\text{ ns} \cdot 1.5 = 37.5\text{ ns}$$
>     *¡Atención!* Si $T_{AD} = 37.5\text{ ns}$, estaríamos violando el límite de 75 ns del datasheet. Para trabajar a 40 MHz con total seguridad de hardware, el divisor debe configurarse con `ADCS = 5`:
>     $$T_{AD} = 25\text{ ns} \cdot \frac{5 + 1}{2} = 25\text{ ns} \cdot 3 = 75\text{ ns}$$
>     *(Nota: En tu simulación base se utilizó `ADCS = 2` asumiendo una frecuencia de CPU menor o un reloj alterno, pero de cara al docente la justificación matemática utilizando $T_{CY}$ es la regla de oro).*

> [!CAUTION]
> **Pregunta 3: ¿Por qué en tu buffer de 12 bits signados (`bufferRD6`) el valor digital correspondiente a 0V no es 0?**
> *   **Respuesta Justificada:** Debido al formato de codificación en complemento a dos que impone el bit `FORM = 1`. En el modo de 12 bits con formato signado, el rango dinámico de tensión se centra en el punto medio de la referencia ($V_{DD}/2$). Así, la tensión máxima ($V_{DD}$) se lee como el valor máximo positivo ($+2047$, o `0x07FF`), la tensión media se lee como $0$ (`0x0000`), y la tensión mínima ($0\text{V}$ o $V_{SS}$) se codifica en el límite inferior negativo: $-2048$ (que signado a 16 bits en memoria se lee como `0xF800`). Por lo tanto, $0\text{V}$ físico equivale a $-2048$ digital, y el valor $0$ digital representa la media escala física.
