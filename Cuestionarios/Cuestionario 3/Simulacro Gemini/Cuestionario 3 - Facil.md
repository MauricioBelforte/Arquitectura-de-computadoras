# ARQUITECTURA DE COMPUTADORAS
**DIT - UNPSJB - Facultad de Ingeniería**  
**SIMULACRO CUESTIONARIO N° 3 — NIVEL: FÁCIL**  

**Alumno/a:** ________________________  
**Fecha:** ____/____/2026  
**Tema:** Conceptos básicos del Conversor Analógico-Digital (ADC) en el dsPIC33F.  

---

## PARTE 1: Preguntas para Completar (Vacías)

### 1. Resolución del conversor (Seleccione la/s correcta/s):
El módulo ADC1 del dsPIC33F puede configurarse para operar con dos niveles de resolución (10 bits y 12 bits). Con respecto a esto:
* **[ ] A)** En el modo de 12 bits, el conversor produce un rango de salida digital de 0 a 1023.
* **[ ] B)** La resolución de 10 bits permite cuantizar la señal analógica de entrada en 4096 niveles discretos.
* **[ ] C)** La resolución de 12 bits ofrece una mayor precisión (4096 niveles) pero limita el número de amplificadores Sample & Hold activos a solo uno.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 2. Configuración de pines analógicos (Seleccione la/s correcta/s):
Para utilizar el pin físico **AN5** como entrada analógica al ADC1, ¿cuál es la configuración correcta de los puertos?
* **[ ] A)** Se debe poner `TRISBbits.TRISB5 = 0` (salida) y `AD1PCFGLbits.PCFG5 = 0` (analógico).
* **[ ] B)** Se debe poner `TRISBbits.TRISB5 = 1` (entrada) y `AD1PCFGLbits.PCFG5 = 0` (analógico).
* **[ ] C)** Se debe poner `TRISBbits.TRISB5 = 1` (entrada) y `AD1PCFGLbits.PCFG5 = 1` (digital).
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 3. El tiempo de reloj del ADC — TAD (Seleccione la/s correcta/s):
El parámetro **TAD** (A/D Conversion Clock Time) es un concepto clave en la temporización del ADC. ¿Cuál es su definición física?
* **[ ] A)** Es el tiempo total que tarda la CPU en ejecutar la ISR de la interrupción del ADC.
* **[ ] B)** Es el tiempo mínimo requerido por el circuito interno de Aproximación Sucesiva (SAR) para procesar y resolver un único bit.
* **[ ] C)** Es igual a $T_{cy}$ (tiempo de ciclo de instrucción de la CPU) y no puede ser modificado por registros.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 4. Ciclos TAD requeridos para conversión (Seleccione la/s correcta/s):
Físicamente, una vez terminado el tiempo de muestreo, el conversor digitaliza la muestra retenida bit a bit. ¿Cuántos ciclos TAD requiere este proceso en cada modo de resolución?
* **[ ] A)** 10 bits requiere 10 TAD; 12 bits requiere 12 TAD.
* **[ ] B)** 10 bits requiere 12 TAD; 12 bits requiere 14 TAD.
* **[ ] C)** Ambos modos requieren exactamente 16 TAD debido al tamaño del registro de salida de 16 bits.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 5. Inicio manual del muestreo (Seleccione la/s correcta/s):
En un control por software (sin disparo automático ni temporizado), ¿cómo se inicia manualmente la fase de muestreo (Sampling) en el ADC1?
* **[ ] A)** Poniendo a uno el bit `AD1CON1bits.DONE`.
* **[ ] B)** Poniendo a cero el bit `AD1CON1bits.ADON`.
* **[ ] C)** Poniendo a uno el bit `AD1CON1bits.SAMP`.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 6. Control del fin de conversión — Polling (Seleccione la/s correcta/s):
Si estamos operando el ADC por software (polling), ¿cuál es el bit que debemos monitorear para saber que la conversión ha finalizado y el dato está listo en el buffer?
* **[ ] A)** Esperar a que `AD1CON1bits.SAMP` cambie a 1.
* **[ ] B)** Monitorear mediante un bucle que `AD1CON1bits.DONE` sea igual a 1.
* **[ ] C)** Monitorear que el bit `IFS0bits.AD1IF` cambie a 0.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 7. Ubicación física del registro buffer (Seleccione la/s correcta/s):
¿Dónde se almacenan físicamente los resultados de conversión del conversor (registro `ADC1BUF0`) y el resto de los registros de control del módulo?
* **[ ] A)** En la Memoria de Programa (Flash), a partir de la dirección `0x000000`.
* **[ ] B)** En los registros de trabajo de la CPU (WREG0 a WREG15).
* **[ ] C)** En la Memoria de Datos (RAM), dentro del bloque SFR (Special Function Registers), en el rango inicial `0x0000` - `0x07FF`.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 8. Capacidad de muestreo simultáneo (Seleccione la/s correcta/s):
El dsPIC33F posee 32 pines físicos externos marcados como analógicos (`AN0` a `AN31`). Sin embargo, la cantidad de canales Sample & Hold (S/H) internos limita el muestreo simultáneo. ¿A cuántos canales de muestreo simultáneo reales se limita el ADC1 en modo de 10 bits?
* **[ ] A)** A 32 canales S/H simultáneos.
* **[ ] B)** A 1 canal S/H simultáneo.
* **[ ] C)** A 4 canales S/H simultáneos (CH0, CH1, CH2 y CH3).
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 9. El bit de encendido del módulo — ADON (Seleccione la/s correcta/s):
Para habilitar el funcionamiento general del módulo ADC1 se utiliza el bit `ADON` de `AD1CON1`. ¿Qué implicancia física tiene este bit?
* **[ ] A)** Cuando `ADON = 0`, el módulo está encendido y consume corriente de forma normal.
* **[ ] B)** Poner `ADON = 1` alimenta físicamente los bloques analógicos internos del conversor; se debe esperar un breve tiempo de estabilización antes de iniciar el muestreo.
* **[ ] C)** `ADON` debe ser conmutado de 1 a 0 para forzar el fin de una conversión analógica de forma segura.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 10. Relación entre pines analógicos y registros de control (Seleccione la/s correcta/s):
¿Cuál es la forma correcta de comprender conceptualmente la relación entre un pin físico analógico (como `AN0`) y los registros de configuración del microcontrolador?
* **[ ] A)** El pin analógico reside "dentro" de los registros `AD1CON1` y `AD1CON2`.
* **[ ] B)** Los pines analógicos externos son componentes de hardware físico. Los registros SFR de la RAM controlan multiplexores y switches de hardware internos que "apuntan" o "conectan" esos pines a los amplificadores de muestreo S/H del conversor.
* **[ ] C)** Al cambiar la configuración en los registros SFR, los pines físicos del chip se desconectan físicamente de la placa de circuito impreso.
* **[ ] D)** Ninguna de las anteriores es correcta.

---
---

## PARTE 2: Clave de Respuestas y Explicaciones Detalladas

A continuación se presentan las respuestas correctas y el desglose de su justificación teórica y de hardware.

### 1. Respuesta Correcta: C
* **Explicación:** La resolución de 12 bits permite cuantizar en $2^{12} = 4096$ niveles digitales discretos (de `0` a `4095`), mientras que la de 10 bits permite $2^{10} = 1024$ niveles (de `0` a `1023`). Por lo tanto, la opción **A** y **B** son matemáticamente incorrectas. La opción **C** es la correcta: el modo de 12 bits ofrece mayor resolución (4096 niveles) pero limita por diseño de hardware el uso de amplificadores de muestreo S/H a **solamente uno** (`CH0`), anulando la capacidad de muestreo simultáneo de múltiples canales.

### 2. Respuesta Correcta: B
* **Explicación:** Para configurar de forma correcta un pin físico como entrada analógica:
  1. Debe configurarse el pin del puerto correspondiente como **entrada** en el registro de dirección (`TRISBbits.TRISB5 = 1`). Si se configurara como salida (`TRIS = 0`), el microcontrolador forzaría un nivel de tensión digital en el pin (0V o 3.3V) interfiriendo o dañando el sensor externo conectado.
  2. Debe deshabilitarse la circuitería digital de entrada en el pin mediante el registro de control analógico (`AD1PCFGLbits.PCFG5 = 0`). Un `0` en el bit `PCFGx` configura el pin como **analógico**. Un `1` lo configura como digital.

### 3. Respuesta Correcta: B
* **Explicación:** **TAD** (A/D Conversion Clock Time) es el período del reloj que rige el conversor analógico-digital. Físicamente, representa el tiempo que le toma a la máquina de estados de aproximaciones sucesivas (SAR) resolver **exactamente un bit** de la conversión analógica a digital. No tiene relación con los tiempos de ejecución de software (opción **A**). Se calcula mediante fórmulas configurando un prescaler a partir de $T_{cy}$ (opción **C** incorrecta).

### 4. Respuesta Correcta: B
* **Explicación:** El hardware de aproximaciones sucesivas (SAR) del dsPIC33F requiere:
  * En modo de **10 bits**: Un total de **12 ciclos TAD** (10 ciclos de resolución para los 10 bits + 2 ciclos de sincronización/overhead).
  * En modo de **12 bits**: Un total de **14 ciclos TAD** (12 ciclos de resolución para los 12 bits + 2 ciclos de sincronización/overhead).
  * La opción **C** es incorrecta porque describe el tamaño del buffer, no los ciclos de conversión reales del hardware analógico.

### 5. Respuesta Correcta: C
* **Explicación:** En un esquema de control manual por software, para iniciar la adquisición del voltaje (muestreo), el software debe poner en `1` el bit `SAMP` del registro `AD1CON1` (`AD1CON1bits.SAMP = 1`). Esto cierra el interruptor analógico interno conectando el pin analógico seleccionado al capacitor de retención del canal S/H. El bit `DONE` (opción **A**) es de solo lectura en modo manual o se pone a cero de forma automática, y `ADON` (opción **B**) apaga el módulo por completo.

### 6. Respuesta Correcta: B
* **Explicación:** El bit `DONE` del registro `AD1CON1` es controlado directamente por el hardware del conversor. Cuando finaliza el proceso de digitalización de la muestra, el hardware pone este bit en `1` (`DONE = 1`) y guarda el dato en el buffer. Por tanto, el software realiza polling sobre este bit con una instrucción como `while (!AD1CON1bits.DONE);`. La bandera `AD1IF` (opción **C**) cambia a `1` al terminar la conversión, no a `0`.

### 7. Respuesta Correcta: C
* **Explicación:** Todos los registros de control de periféricos y los buffers de datos de hardware (como `ADC1BUF0`) en el dsPIC33F pertenecen al grupo de registros de función especial (**SFR - Special Function Registers**). Arquitectónicamente, estos registros SFR residen físicamente en el mapa de la **Memoria de Datos (RAM)**, ocupando las direcciones más bajas de la misma (desde `0x0000` hasta `0x07FF`). No se ubican en la memoria Flash de programa (opción **A**) ni actúan como registros de la CPU WREG (opción **B**).

### 8. Respuesta Correcta: C
* **Explicación:** Aunque el chip cuente con 32 terminales de conexión externos multiplexados (`AN0` a `AN31`), a nivel de hardware interno el conversor ADC1 del dsPIC33F tiene un límite máximo de **4 amplificadores con capacitores de muestreo y retención (S/H)** denominados `CH0`, `CH1`, `CH2` y `CH3`. Por lo tanto, el sistema no puede muestrear de forma simultánea más de **4 señales analógicas** concurrentes en un instante de tiempo.

### 9. Respuesta Correcta: B
* **Explicación:** El bit `ADON` (Active/Off) controla el flujo de alimentación a la sección analógica del conversor. Cuando `ADON = 0`, el módulo analógico del ADC está completamente apagado y consume corriente cero (opción **A** incorrecta). Cuando `ADON = 1`, los circuitos analógicos internos (amplificadores, referencias) se encienden. Es de vital importancia esperar un pequeño tiempo de estabilización física (del orden de microsegundos) antes de iniciar el muestreo manual para evitar lecturas de voltaje erráticas.

### 10. Respuesta Correcta: B
* **Explicación:** Esta es una distinción fundamental de hardware: los pines son conexiones físicas de cobre del chip al exterior de la placa. No residen dentro de la RAM ni desaparecen de la placa. La configuración por registros de función especial (SFR) manipula interruptores internos de estado sólido (multiplexores y decodificadores analógicos) que abren o cierran el camino eléctrico que conecta el pin físico externo con los capacitores y amplificadores S/H internos del chip.
