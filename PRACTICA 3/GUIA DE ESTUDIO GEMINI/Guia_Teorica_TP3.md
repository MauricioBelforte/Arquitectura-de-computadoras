# Guía Teórica - Trabajo Práctico 3 (ADC y DMA)
Este resumen integra los conceptos fundamentales sobre el **Conversor Analógico-Digital (ADC)** y el **Acceso Directo a Memoria (DMA)** para el microcontrolador dsPIC33F, combinando la teoría de las diapositivas de la cátedra con los manuales de referencia de Microchip.

---

## 1. Conversor Analógico-Digital (ADC)

### 1.1 Conceptos Generales de Conversión A/D
Un **Conversor Analógico-Digital (ADC)** transforma un valor de voltaje analógico continuo (leído desde un pin de entrada) en un número entero discreto que la CPU puede procesar.

*   **Rango de Referencia:** El conversor trabaja dentro de un rango de voltaje definido (ej: 0V a 5V). En nuestras prácticas, usaremos el voltaje de alimentación del microcontrolador (`AVDD` y `AVSS`) como referencia.
*   **Resolución:** La cantidad de bits del resultado determina la precisión:
    *   **10 bits:** El rango se divide en **1024 escalones** discretos (0 a 1023). Resolución: `5V / 1024 = 4,88 mV` por escalón.
    *   **12 bits:** El rango se divide en **4096 escalones** discretos (0 a 4095). Resolución: `5V / 4096 = 1,22 mV` por escalón.
*   **Fórmula de Conversión:** Para obtener el voltaje real a partir del valor digital:
    ```
    Voltaje = (Valor_Digital × VREF) / (2^N - 1)
    ```
    Ejemplo (10 bits, VREF = 5V): `(481 × 5V) / 1023 = 2,35V`
*   **Transductores:** En la práctica, el voltaje proviene de un **transductor** (sensor de temperatura, humedad, presión, etc.) que convierte una magnitud física en un voltaje eléctrico dentro del rango del ADC.

### 1.2 Secuencia de Sampling/Holding
Cada conversión se divide en dos fases temporales:

1.  **Tiempo de Muestreo (Sampling):** El amplificador **Sample/Hold (S/H)** se conecta al pin de entrada analógica y captura el voltaje. Se controla con el bit `SAMP` (`AD1CON1<1>`).
2.  **Tiempo de Conversión (Holding):** El amplificador se **desconecta** de la entrada y mantiene el voltaje estable mientras el circuito SAR (Aproximación Sucesiva) realiza la conversión bit a bit.
    *   **10 bits:** Requiere **12 ciclos TAD** para la conversión completa.
    *   **12 bits:** Requiere **14 ciclos TAD** para la conversión completa.

El **tiempo total de conversión** = Tiempo de Muestreo + Tiempo de Conversión.

### 1.3 Arquitectura del ADC en el dsPIC33F
*   El dsPIC33F posee **dos módulos ADC** independientes: **ADC1** y **ADC2**, cada uno con su propio conjunto de registros SFR.
*   Hasta **32 pines de entrada analógica** (AN0 a AN31). ADC1 puede usar todos; ADC2 solo AN0-AN15.
*   El módulo posee **4 amplificadores Sample/Hold** (CH0, CH1, CH2, CH3) en modo de 10 bits, pero **solo CH0** en modo de 12 bits.
*   Las entradas analógicas se conectan a los canales S/H a través de un **multiplexor de entrada**. El multiplexor tiene dos configuraciones programables: **MUX A** y **MUX B**, que pueden alternarse entre conversiones.
*   El resultado se almacena en un **buffer de una sola palabra** (`ADC1BUF0`). Para almacenar múltiples resultados, se debe usar **DMA**.

### 1.4 Registros de Control del ADC (Los más importantes)

| Registro | Función Principal |
| :--- | :--- |
| **`AD1CON1`** | Control principal: encendido (`ADON`), resolución (`AD12B`), formato de salida (`FORM`), fuente de trigger (`SSRC`), auto-muestreo (`ASAM`), bit de muestreo (`SAMP`), fin de conversión (`DONE`). |
| **`AD1CON2`** | Referencia de voltaje (`VCFG`), escaneo de entradas (`CSCNA`), selección de canales (`CHPS`), tasa de interrupción/DMA (`SMPI`). |
| **`AD1CON3`** | Fuente de reloj del ADC (`ADRC`), tiempo de auto-muestreo (`SAMC`), divisor de reloj (`ADCS`). |
| **`AD1CON4`** | Tamaño del buffer DMA por entrada analógica (`DMABL`). |
| **`AD1CHS0`** | Selección de la entrada analógica conectada a **CH0** (entrada positiva `CH0SA` y negativa `CH0NA`). |
| **`AD1CHS123`** | Selección de entradas para CH1, CH2 y CH3 (solo modo 10 bits). |
| **`AD1PCFGL`** | Configuración de pines AN0-AN15: `0` = Analógico (por defecto), `1` = Digital. **Es obligatorio poner en 0 los bits de los pines que se van a usar como entrada analógica.** |
| **`AD1CSSL`** | Selección de entradas para escaneo secuencial automático. |

### 1.5 Bits Clave de `AD1CON1` (Detalle)

*   **`ADON`** (bit 15): Enciende (`1`) o apaga (`0`) el módulo ADC.
*   **`AD12B`** (bit 10): Selecciona modo de **12 bits** (`1`) o **10 bits y 4 canales** (`0`).
*   **`FORM<1:0>`** (bits 9-8): Formato de salida de datos:
    *   `00` = Entero sin signo (el más común para nosotros).
    *   `01` = Entero con signo.
    *   `10` = Fraccionario sin signo.
    *   `11` = Fraccionario con signo.
*   **`SSRC<2:0>`** (bits 7-5): Fuente que finaliza el muestreo e inicia la conversión:
    *   `000` = Manual (borrar el bit `SAMP` por software).
    *   `010` = Timer3 (para ADC1) / Timer5 (para ADC2) dispara la conversión.
    *   `111` = Conversión automática (el contador interno finaliza el muestreo).
*   **`ASAM`** (bit 2): Si está en `1`, el muestreo **comienza automáticamente** después de la última conversión.
*   **`SAMP`** (bit 1): Bit de control de muestreo. Si `ASAM=0`, se debe poner en `1` manualmente para iniciar el muestreo. Si `SSRC=000`, se borra manualmente para iniciar la conversión.
*   **`DONE`** (bit 0): El hardware lo pone en `1` cuando la conversión se completa. Se puede leer por **Polling** para saber cuándo el resultado está listo.

### 1.6 Pasos para Configurar una Conversión ADC
Según el manual de referencia (Sección 16.4), la secuencia de configuración es:

1.  Seleccionar modo 10 o 12 bits (`AD12B`).
2.  Seleccionar fuente de referencia de voltaje (`VCFG`).
3.  Seleccionar el reloj de conversión (`ADCS`).
4.  Configurar los pines como **entradas analógicas** (`AD1PCFGL`).
5.  Asignar la entrada analógica al canal S/H (`AD1CHS0`).
6.  Seleccionar cuántos canales S/H usar (`CHPS`).
7.  Configurar el muestreo (manual o automático, `ASAM`).
8.  Seleccionar la fuente de trigger de conversión (`SSRC`).
9.  Seleccionar el formato de datos de salida (`FORM`).
10. Encender el módulo (`ADON = 1`).

### 1.7 Detección del Fin de Conversión
Existen tres métodos para saber que la conversión terminó:

1.  **Polling:** Consultar en un bucle el bit `DONE` de `AD1CON1`. Es el método más simple.
2.  **Interrupciones:** Habilitar la interrupción del ADC (`AD1IE`) y atenderla con una ISR (`_AD1Interrupt`).
3.  **DMA:** El dato convertido se transfiere automáticamente a un buffer en RAM sin intervención de la CPU.

---

## 2. Acceso Directo a Memoria (DMA)

### 2.1 Concepto Fundamental
El **DMA (Direct Memory Access)** es un subsistema de hardware que permite transferir datos entre un **periférico** (como el ADC) y la **memoria RAM** sin intervenir la CPU. Esto libera al procesador para que ejecute otras tareas mientras las transferencias ocurren en paralelo.

*   **Ventaja Principal:** Eliminación de la sobrecarga de la CPU. No se requieren ciclos de instrucción del programa principal para mover datos.
*   **Uso Típico:** Cuando se necesitan **muchas conversiones ADC continuas** (como muestreo de sensores de temperatura en un brazo robótico), el DMA llena automáticamente un buffer en RAM y solo avisa a la CPU cuando el buffer está completo.

### 2.2 Arquitectura DMA del dsPIC33F
A diferencia de otras arquitecturas, el DMA del dsPIC33F **no roba ciclos a la CPU**:

*   El dsPIC33F posee una memoria SRAM de **doble puerto (DPSRAM)**.
    *   **Puerto 1:** Accedido por la CPU a través del bus X estándar.
    *   **Puerto 2:** Accedido exclusivamente por el controlador DMA a través de un bus DMA dedicado.
*   Esto permite que la CPU y el DMA **trabajen simultáneamente** sin interferencias ni paradas.
*   El controlador DMA dispone de **8 canales independientes** (Canal 0 a Canal 7).
*   Cada canal es **unidireccional**: para leer y escribir en un mismo periférico, se necesitan dos canales DMA.
*   Cada canal puede mover un bloque de hasta **1024 elementos** de datos antes de generar una interrupción.

### 2.3 Periféricos Compatibles con DMA
El controlador DMA puede trabajar con los siguientes periféricos:
*   Convertidor Analógico-Digital (**ADC1, ADC2**)
*   UART (Transmisión y Recepción)
*   SPI (Interfaz Periférica Serie)
*   Timers (Timer2, Timer3)
*   ECAN (Controlador CAN)
*   Captura de Entrada / Comparación de Salida
*   Interrupciones Externas (`INT0`)

### 2.4 Registros de Control DMA (Por Canal)
Cada uno de los 8 canales tiene **6 registros**:

| Registro | Función |
| :--- | :--- |
| **`DMA0CON`** | Habilitación del canal (`CHEN`), tamaño de transferencia byte/palabra (`SIZE`), dirección (`DIR`), modo de operación (`MODE`) y modo de direccionamiento (`AMODE`). |
| **`DMA0REQ`** | Asocia el canal con un periférico específico mediante `IRQSEL<6:0>`. También permite forzar una transferencia manual (`FORCE`). |
| **`DMA0STA`** | Dirección de inicio **primaria (Buffer A)** en la DPSRAM. |
| **`DMA0STB`** | Dirección de inicio **secundaria (Buffer B)** en la DPSRAM (para modo Ping-Pong). |
| **`DMA0PAD`** | Dirección del registro de datos del **periférico** origen/destino (ej: `&ADC1BUF0`). |
| **`DMA0CNT`** | Número de transferencias antes de considerar el bloque completo. `DMA0CNT + 1` = cantidad de elementos a transferir. |

### 2.5 Bits Clave de `DMA0CON` (Detalle)

*   **`CHEN`** (bit 15): Habilita (`1`) o deshabilita (`0`) el canal.
*   **`SIZE`** (bit 14): Tamaño de transferencia: `0` = Palabra (16 bits), `1` = Byte (8 bits).
*   **`DIR`** (bit 13): Dirección de la transferencia:
    *   `0` = Leer desde el periférico, escribir en DPSRAM (ej: ADC → RAM).
    *   `1` = Leer desde DPSRAM, escribir en el periférico (ej: RAM → UART TX).
*   **`HALF`** (bit 12): Si está en `1`, genera interrupción cuando se ha transferido **la mitad** del bloque.
*   **`AMODE<1:0>`** (bits 5-4): Modo de direccionamiento:
    *   `00` = Registro Indirecto con Post-Incremento (la dirección avanza automáticamente).
    *   `01` = Registro Indirecto sin Post-Incremento (dirección fija).
    *   `10` = Direccionamiento Indirecto de Periférico (el periférico genera la dirección).
*   **`MODE<1:0>`** (bits 1-0): Modo de operación:
    *   `00` = Continuo, sin Ping-Pong (llena el buffer A indefinidamente).
    *   `01` = One-Shot, sin Ping-Pong (una sola transferencia de bloque y se detiene).
    *   `10` = Continuo, con Ping-Pong (alterna entre Buffer A y Buffer B automáticamente).
    *   `11` = One-Shot, con Ping-Pong.

### 2.6 Asociación Canal DMA ↔ Periférico
Para conectar un canal DMA a un periférico, se necesitan dos datos:

1.  **`IRQSEL<6:0>`** en `DMA0REQ`: Selecciona **qué evento dispara** la transferencia DMA.
    *   Ejemplo: `0001101` = ADC1 (conversión completada).
    *   Ejemplo: `0000111` = Timer2.
2.  **`DMA0PAD`**: La **dirección del registro de datos** del periférico.
    *   Para ADC1: se carga con la dirección de `ADC1BUF0` (`(volatile unsigned int)&ADC1BUF0`).

### 2.7 Modo Ping-Pong
Es un mecanismo clave para procesamiento continuo de datos:
*   El DMA alterna automáticamente entre **Buffer A** (`DMA0STA`) y **Buffer B** (`DMA0STB`).
*   Mientras el DMA llena un buffer, la CPU puede procesar el otro buffer que ya está completo.
*   El registro `DMACS1` indica mediante los bits `PPSTx` qué buffer está seleccionado actualmente.

### 2.8 Pasos para Configurar un Canal DMA con ADC
1.  Configurar el ADC normalmente (ver Sección 1.6).
2.  Declarar el buffer en memoria DMA: `int BufferA[N] __attribute__((space(dma)));`
3.  Configurar `DMA0CON`: dirección de lectura (`DIR=0`), modo continuo, post-incremento.
4.  Configurar `DMA0REQ`: asociar con ADC1 (`IRQSEL = 0b0001101`).
5.  Configurar `DMA0STA`: cargar con `__builtin_dmaoffset(BufferA)`.
6.  Configurar `DMA0PAD`: cargar con la dirección de `ADC1BUF0`.
7.  Configurar `DMA0CNT`: número de transferencias - 1 (ej: para 6 muestras, cargar `5`).
8.  Habilitar la interrupción DMA (`IEC0bits.DMA0IE = 1`).
9.  Habilitar el canal (`DMA0CONbits.CHEN = 1`).
10. Encender el ADC (`AD1CON1bits.ADON = 1`).

---

## 3. Aplicación Práctica (Trabajo Práctico 3)

### Ejercicio 1 — ADC por Polling
*   **Objetivo:** Monitorear 2 pulsadores (RD6 y RD7). Según cuál se presione, realizar una conversión ADC diferente:
    *   RD6 → Convertir **AN2**, 12 bits, Entero con signo.
    *   RD7 → Convertir **AN5**, 10 bits, Entero sin signo.
*   **Técnica:** Polling del bit `DONE` para detectar el fin de la conversión.
*   **Almacenamiento:** Dos buffers circulares de 8 posiciones. Contador global que se incrementa cuando el valor convertido es 0, mostrando el resultado en **PORTE**.

### Ejercicio 2 — ADC con DMA
*   **Objetivo:** Muestrear temperatura por **AN0** y **AN1** de forma continua y alternada usando DMA.
*   **Buffer DMA:** 6 posiciones (3 muestras de AN0 + 3 muestras de AN1).
*   **Programa Principal:** Mientras el DMA se encarga de las conversiones, el `main()` monitorea comandos de un joystick por **PORTB** (UP, DOWN, HOLD, RELEASE) y reporta su estado por **PORTE** con un formato de tipo/valor (ej: DOWN = `0x12`, buffer DMA lleno = `0x30`).

---

## 📚 ¿Dónde ampliar el tema en tus fuentes oficiales?

1.  **Configuración y Registros del ADC:**
    *   **`dsPIC33 - Analog to Digital Converter-DS70183A_es.md`**: Sección 16.4 (Configuración del módulo) y Sección 16.21 (Ejemplos de código).
    *   **`Conversor Analógico_Digital_es.md`**: Diapositivas de la cátedra con conceptos generales y resolución.
2.  **Arquitectura y Registros del DMA:**
    *   **`DsPIC33 - DMA -DS70182b_es.md`**: Sección 22.5 (Configuración) y Sección 22.6 (Modos de operación).
3.  **Tabla de Asociación DMA-Periférico:**
    *   **`DsPIC33 - DMA -DS70182b_es.md`**: Tabla 22-1, que lista los valores de `IRQSEL` y `PAD` para cada periférico.
