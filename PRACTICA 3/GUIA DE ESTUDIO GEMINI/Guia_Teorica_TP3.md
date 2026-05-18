# Guía Teórica - Trabajo Práctico 3 (ADC y DMA)
Este resumen integra los conceptos fundamentales sobre el **Conversor Analógico-Digital (ADC)** y el **Acceso Directo a Memoria (DMA)** para el microcontrolador dsPIC33F, combinando la teoría de las diapositivas de la cátedra con los manuales de referencia de Microchip.

---

## 1. Conversor Analógico-Digital (ADC)

### 1.1 Conceptos Generales de Conversión A/D
Un **Conversor Analógico-Digital (ADC)** transforma un valor de voltaje analógico continuo (leído desde un pin de entrada) en un número entero discreto que la CPU puede procesar.

*   **Rango de Referencia:** El conversor trabaja dentro de un rango de voltaje definido (ej: 0V a 5V). En nuestras prácticas, usaremos el voltaje de alimentación del microcontrolador como referencia:
    *   **AVDD (Analog Supply Voltage):** Es el voltaje de alimentación analógica positiva (típicamente 3.3V o 5V). Define el límite superior del rango de medición.
    *   **AVSS (Analog Ground Reference):** Es la tierra o referencia de 0V para los circuitos analógicos. Define el límite inferior del rango.
    *   *Nota:* Se usan pines separados (A/V) en lugar de los digitales (V/V) para evitar que el ruido de los circuitos lógicos afecte la precisión de la conversión analógica.
*   **Resolución:** La cantidad de bits del resultado determina la precisión:
    *   **10 bits:** El rango se divide en **1024 escalones** discretos (0 a 1023). Resolución: `5V / 1024 = 4,88 mV` por escalón.
    *   **12 bits:** El rango se divide en **4096 escalones** discretos (0 a 4095). Resolución: `5V / 4096 = 1,22 mV` por escalón.
*   **Fórmula de Conversión:** Para obtener el voltaje real a partir del valor digital:
    ```
    Voltaje = (Valor_Digital × VREF) / (2^N - 1)
    ```
    *   **VREF (Voltage Reference):** Voltaje de Referencia. Es el rango total de tensión que el ADC puede medir (normalmente la diferencia entre `AVDD` y `AVSS`).
    
    *Ejemplo de cálculo (10 bits, VREF = 5V):* Si el conversor arroja un `Valor_Digital` de **481**, el cálculo de la tensión física real que está leyendo el pin sería:
    `(481 × 5V) / 1023 = 2,35V`

    > **💡 Detalle Técnico de la Fórmula:**
    > *   **¿De dónde sale el 481?** Es simplemente un valor numérico de ejemplo (leído del registro `ADC1BUF0`) que representa lo que midió el sensor.
    > *   **¿Por qué se divide por 1023 y no por 1024?** Con 10 bits tienes **1024 estados** o "escalones" diferentes. Sin embargo, como el primer estado es el **0**, el valor más alto posible al que puede llegar el contador es **1023** (todos los bits en '1'). Si al pin le entran los 5V completos de referencia, el ADC arrojará un 1023. Por eso, para sacar la proporción, dividimos por el valor máximo (`2^N - 1`), que en este caso es 1023.
*   **Transductores:** En la práctica, el voltaje proviene de un **transductor** (sensor de temperatura, humedad, presión, etc.) que convierte una magnitud física en un voltaje eléctrico dentro del rango del ADC.

### 1.2 Secuencia de Sampling/Holding
Cada conversión se divide en dos fases temporales:

1.  **Tiempo de Muestreo (Sampling):** El amplificador **Sample/Hold (S/H)** se conecta al pin de entrada analógica y captura el voltaje. Se controla por software mediante el bit `SAMP` (la notación `AD1CON1<1>` de los manuales significa exactamente eso: es el **bit número 1** del registro `AD1CON1`).
2.  **Tiempo de Conversión (Holding):** El amplificador se **desconecta** de la entrada y mantiene el voltaje estable mientras el circuito SAR (Aproximación Sucesiva) realiza la conversión bit a bit.
    *   **10 bits:** Requiere **12 ciclos TAD** para la conversión completa.
    *   **12 bits:** Requiere **14 ciclos TAD** para la conversión completa.
    
    > **⏱️ ¿Qué es un ciclo TAD?**
    > **TAD (A/D Conversion Clock Time)** es el "tic de reloj" base dedicado exclusivamente al módulo ADC. Físicamente, representa el tiempo mínimo que tarda el hardware (circuito SAR) en calcular y resolver **un solo bit** del resultado final. Por eso, para resolver 10 bits, necesita al menos 10 TADs más 2 ciclos adicionales de overhead por el funcionamiento del circuito (total 12 TAD).

El **tiempo total de conversión** = Tiempo de Muestreo + Tiempo de Conversión.

### 1.3 Arquitectura del ADC en el dsPIC33F
*   El dsPIC33F posee **dos módulos ADC** independientes: **ADC1** y **ADC2**.
    > **💡 Módulo vs. Registro:** 
    > *   Un **Módulo** es el bloque físico de hardware (la "máquina" que hace la conversión).
    > *   Los **Registros** (como `AD1CON1`) son el panel de control de ese módulo. 
    > *   Si usas el módulo **ADC1**, sus registros se llaman `AD1CON1`, `AD1CON2`, etc. Si usaras el **ADC2**, sus registros serían `AD2CON1`, `AD2CON2`, etc. Cada módulo tiene su propio juego completo de registros independientes.
    > **📍 Nota de Arquitectura:** Todos los registros **SFR** (Special Function Registers) residen físicamente en la **Memoria de Datos (RAM)**, ocupando el rango inicial desde la dirección `0x0000` hasta la `0x07FF` (los primeros 2 KB del mapa de datos).
*   **Pines de Entrada Analógica (AN0 a AN31):** Son los pines físicos externos del chip. 
    > **⚠️ ¡Cuidado!:** Los pines **no** están dentro de `AD1CON1`. 
    > *   Para decirle al chip que un pin sea analógico, usas **`AD1PCFGL`**.
    > *   Para elegir cuál de todos esos pines quieres medir en este momento, usas **`AD1CHS0`** (el selector/multiplexor).
    *   ADC1 puede usar hasta 32 pines; ADC2 suele estar limitado a los primeros 16 (AN0-AN15).
*   El módulo posee **4 amplificadores Sample/Hold** (CH0, CH1, CH2, CH3) en modo de 10 bits, pero **solo CH0** en modo de 12 bits.
*   Las entradas analógicas se conectan a los canales S/H a través de un **multiplexor de entrada**. El multiplexor tiene dos configuraciones programables: **MUX A** y **MUX B**, que pueden alternarse entre conversiones.
*   El resultado se almacena en un **buffer de una sola palabra** (`ADC1BUF0`). Para almacenar múltiples resultados, se debe usar **DMA**.

### 1.4 Registros de Control del ADC (Los más importantes)

> **💡 Resumen de Roles para no confundirse:**
> *   **`AD1CON1` (Interruptor y Modo):** Es el panel general. Controla si el módulo está prendido, si mide en 10 o 12 bits y quién da la orden de empezar. **No elige el pin.**
> *   **`AD1PCFGL` (Configuración de Puertos):** Le dice al chip: *"Che, el pin AN5 no es un botón digital, trátalo como una entrada analógica"*.
> *   **`AD1CHS0` (Selección de Canal):** Es el **selector (multiplexor)**. Aquí escribes el número del pin (ej: `5`) para decirle a la máquina: *"Ahora conéctate al pin AN5 y mide lo que hay ahí"*.
> *   **`ADC1BUF0` (Buffer de Resultado):** Es el **buzón de salida**. Una vez que la máquina termina de convertir, deja el número final aquí para que tú lo leas desde el código (`valor = ADC1BUF0;`).

*   **`AD1CON1`:** Control principal: 
    *   Encendido (`ADON`) (bit 15)
    *   Resolución (`AD12B`) (bit 10)
    *   Formato de salida (`FORM`) (bits 9-8)
    *   Fuente de trigger (`SSRC`) (bits 7-5)
    *   Auto-muestreo (`ASAM`) (bit 2)
    *   Bit de muestreo (`SAMP`) (bit 1)
    *   Fin de conversión (`DONE`) (bit 0)
*   **`AD1CON2`:** 
    *   Referencia de voltaje (`VCFG`) (bits 15-13)
    *   Escaneo de entradas (`CSCNA`) (bit 10)
    *   Selección de canales (`CHPS`) (bits 9-8)
    *   Tasa de interrupción/DMA (`SMPI`) (bits 5-2)
*   **`AD1CON3`:** 
    *   Fuente de reloj del ADC (`ADRC`) (bit 15)
    *   Tiempo de auto-muestreo (`SAMC`) (bits 12-8)
    *   Divisor de reloj (`ADCS`) (bits 7-0)
*   **`AD1CON4`:** 
    *   Tamaño del buffer DMA por entrada analógica (`DMABL`) (bits 2-0)
*   **`AD1CHS0`:** Selección de la entrada analógica conectada a **CH0**:
    *   Entrada positiva (`CH0SA`) (bits 12-8)
    *   Entrada negativa (`CH0NA`) (bit 0)
*   **`AD1CHS123`:** 
    *   Selección de entradas para CH1, CH2 y CH3 (solo modo 10 bits) (bits 10-9 y 2-0)
*   **`AD1PCFGL`:** Configuración de pines AN0-AN15: 
    *   `0` = Analógico (por defecto) (bits 15-0)
    *   `1` = Digital (bits 15-0)
    *   **Nota:** Es obligatorio poner en 0 los bits de los pines que se van a usar como entrada analógica.
*   **`AD1CSSL`:** 
    *   Selección de entradas para escaneo secuencial automático (bits 15-0)

### 1.5 Bits Clave de `AD1CON1` (Detalle y Sintaxis C)

*   **`ADON`** (bit 15): Control de energía del módulo.
    *   `AD1CON1bits.ADON = 1;` → Enciende el conversor.
    *   `AD1CON1bits.ADON = 0;` → Apaga el conversor (se usa para detener conversiones continuas automáticas o ahorrar energía, como en la rutina de tu Cuestionario 3).
*   **`AD12B`** (bit 10): Selecciona la resolución.
    *   `AD1CON1bits.AD12B = 1;` → Modo de 12 bits (rango 0-4095).
    *   `AD1CON1bits.AD12B = 0;` → Modo de 10 bits (rango 0-1023).
*   **`FORM<1:0>`** (bits 9-8): Formato de salida de datos.
    *   `AD1CON1bits.FORM = 0;` // `00` = Entero sin signo (el estándar que usamos siempre).
    *   `AD1CON1bits.FORM = 1;` // `01` = Entero con signo.
    *   `AD1CON1bits.FORM = 2;` // `10` = Fraccionario sin signo.
    *   `AD1CON1bits.FORM = 3;` // `11` = Fraccionario con signo.
*   **`SSRC<2:0>`** (bits 7-5): Fuente que dispara la conversión (es decir, qué evento corta el tiempo de muestreo):
    *   `AD1CON1bits.SSRC = 0;` // `000` = Modo manual (tienes que borrar `SAMP` por código).
    *   `AD1CON1bits.SSRC = 2;` // `010` = Disparado por hardware (Timer3 o Timer5).
    *   `AD1CON1bits.SSRC = 7;` // `111` = Modo automático (el reloj interno cuenta los TADs y dispara solo).
*   **`ASAM`** (bit 2): Control de auto-muestreo.
    *   `AD1CON1bits.ASAM = 1;` → Apenas termina una conversión, el hardware cierra la llave y empieza a muestrear la siguiente automáticamente.
    *   `AD1CON1bits.ASAM = 0;` → Se requiere que el programador encienda `SAMP` manualmente para volver a muestrear.
*   **`SAMP`** (bit 1): Bit de control manual de la llave (Sample/Hold).
    *   `AD1CON1bits.SAMP = 1;` → **Inicia el muestreo** (conecta la patita externa al capacitor interno).
    *   `AD1CON1bits.SAMP = 0;` → **Inicia la conversión** (desconecta la patita externa, el voltaje queda atrapado y empieza la digitalización). *Ojo: esto solo funciona si SSRC está configurado en 0 (manual).*
*   **`DONE`** (bit 0): Bandera de estado manejada por el hardware.
    *   `while(!AD1CON1bits.DONE);` → Bucle de "Polling". El programa se traba en esta línea esperando hasta que el hardware reemplace el `0` por un `1` (indicando que la conversión terminó y puedes leer el `ADC1BUF0`).

### 1.6 Bits Clave de `AD1CHS0` (Detalle y Sintaxis C)

*   **`CH0SA<4:0>`** (bits 12-8): Selección de Entrada Positiva del Canal 0 (multiplexor).
    *   `AD1CHS0bits.CH0SA = 0;` // `00000` = Conecta el pin físico AN0 como entrada positiva del CH0.
    *   `AD1CHS0bits.CH0SA = 1;` // `00001` = Conecta el pin físico AN1 como entrada positiva del CH0.
    *   `AD1CHS0bits.CH0SA = 2;` // `00010` = Conecta el pin físico AN2 como entrada positiva del CH0.
    *   `AD1CHS0bits.CH0SA = 3;` // `00011` = Conecta el pin físico AN3 como entrada positiva del CH0.
        ... (los bits del 4 al 30)
    *   `AD1CHS0bits.CH0SA = 31;` // `11111` = Conecta el pin físico AN31 como entrada positiva del CH0.
*   **`CH0NA`** (bit 0): Selección de Entrada Negativa del Canal 0.
    *   `AD1CHS0bits.CH0NA = 0;` → Conecta la entrada negativa del CH0 al pin de referencia negativo (`VREF-` o `AVSS`). *Es lo normal.*
    *   `AD1CHS0bits.CH0NA = 1;` → Conecta la entrada negativa del CH0 a la entrada analógica `AN1`. *Útil para mediciones diferenciales.*

### 1.7 Bits Clave de `AD1PCFGL` (Detalle y Sintaxis C)

*   **`PCFG0`** (bit 0 de `AD1PCFGL`): Configuración de Pin Analógico o Digital para AN0.
    *   `AD1PCFGLbits.PCFG0 = 1;` → Configura el pin AN0 como **Digital**.
    *   `AD1PCFGLbits.PCFG0 = 0;` → Configura el pin AN0 como **Analógico** (ADC).
*   **`PCFG1`** (bit 1 de `AD1PCFGL`): Configuración de Pin Analógico o Digital para AN1.
*   **`PCFG2`** (bit 2 de `AD1PCFGL`): Configuración de Pin Analógico o Digital para AN2.
*   **`PCFG3`** (bit 3 de `AD1PCFGL`): Configuración de Pin Analógico o Digital para AN3.
    ... (los bits del 4 al 14)
*   **`PCFG15`** (bit 15 de `AD1PCFGL`): Configuración de Pin Analógico o Digital para AN15.
    *   *Nota masiva:* `AD1PCFGL = 0xFFFF;` vuelve a los 16 pines del registro 100% digitales. Si vas a medir en AN0, AN1 y AN2, puedes escribir `AD1PCFGL = 0xFFF8;` (bits 0, 1 y 2 en 0, resto en 1).

### 1.8 Pasos para Configurar una Conversión ADC
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

### 1.9 Detección del Fin de Conversión
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

> **💡 Resumen de Roles del DMA para no confundirse:**
> *   **`DMA0CON` (El Jefe de Logística):** Define *cómo* se mueve la carga (tamaño, dirección, si es continuo o si se detiene al terminar).
> *   **`DMA0REQ` (El Activador):** Es el que escucha al periférico. Le dices: *"Cuando el ADC grite que terminó de convertir, vos movés el dato"*.
> *   **`DMA0PAD` (Origen/Destino Periférico):** Le dice al DMA *en qué caja del periférico* tiene que buscar o dejar los datos (ej: apuntarlo al buzón `ADC1BUF0`).
> *   **`DMA0STA` / `DMA0STB` (Direcciones en RAM):** Le dicen al DMA *en qué parte de la RAM* tiene que guardar o leer la información que está moviendo.
> *   **`DMA0CNT` (El Contador):** Le dice *cuántos* paquetes tiene que mover en total antes de dar por terminado el trabajo y avisarle a la CPU.

*   **`DMA0CON`:** 
    *   Habilitación del canal (`CHEN`) (bit 15)
    *   Tamaño de transferencia byte/palabra (`SIZE`) (bit 14)
    *   Dirección (`DIR`) (bit 13)
    *   Interrupción de mitad de bloque (`HALF`) (bit 12)
    *   Modo de direccionamiento (`AMODE`) (bits 5-4)
    *   Modo de operación (`MODE`) (bits 1-0)
*   **`DMA0REQ`:** 
    *   Asocia el canal con un periférico específico (`IRQSEL`) (bits 6-0)
    *   Permite forzar una transferencia manual (`FORCE`) (bit 15)
*   **`DMA0STA`:** 
    *   Dirección de inicio **primaria (Buffer A)** en la DPSRAM (bits 15-0)
*   **`DMA0STB`:** 
    *   Dirección de inicio **secundaria (Buffer B)** en la DPSRAM (para modo Ping-Pong) (bits 15-0)
*   **`DMA0PAD`:** 
    *   Dirección del registro de datos del **periférico** origen/destino (ej: `&ADC1BUF0`) (bits 15-0)
*   **`DMA0CNT`:** 
    *   Número de transferencias antes de considerar el bloque completo (bits 9-0)
    *   Fórmula: `DMA0CNT + 1` = cantidad de elementos a transferir

### 2.5 Bits Clave de `DMA0CON` (Detalle y Sintaxis C)

*   **`CHEN`** (bit 15): Control de encendido del canal DMA.
    *   `DMA0CONbits.CHEN = 1;` → Habilita el canal (empieza a escuchar al periférico).
    *   `DMA0CONbits.CHEN = 0;` → Apaga el canal.
*   **`SIZE`** (bit 14): Tamaño de los datos a transferir.
    *   `DMA0CONbits.SIZE = 0;` → Transfiere Palabras o Words (16 bits). Es lo normal para el ADC.
    *   `DMA0CONbits.SIZE = 1;` → Transfiere Bytes (8 bits). Útil para enviar letras por UART.
*   **`DIR`** (bit 13): Dirección del flujo de datos (¿Hacia dónde van?).
    *   `DMA0CONbits.DIR = 0;` → Del Periférico a la RAM (Ej: ADC → RAM).
    *   `DMA0CONbits.DIR = 1;` → De la RAM al Periférico (Ej: RAM → UART TX).
*   **`HALF`** (bit 12): Interrupción de mitad de bloque.
    *   `DMA0CONbits.HALF = 1;` → Avisa (interrumpe a la CPU) cuando el buffer se llenó hasta la mitad.
    *   `DMA0CONbits.HALF = 0;` → Avisa solo cuando el buffer se llenó completo.
*   **`AMODE<1:0>`** (bits 5-4): Modo de direccionamiento (¿Cómo avanza por la RAM?).
    *   `DMA0CONbits.AMODE = 0;` // `00` = Post-Incremento. *El más usado.* (Guarda un dato y avanza un casillero en la RAM automáticamente).
    *   `DMA0CONbits.AMODE = 1;` // `01` = Sin incremento (Sobreescribe siempre en la misma dirección de RAM).
    *   `DMA0CONbits.AMODE = 2;` // `10` = Direccionamiento Periférico Indirecto.
*   **`MODE<1:0>`** (bits 1-0): Modo de operación del buffer.
    *   `DMA0CONbits.MODE = 0;` // `00` = Continuo, sin Ping-Pong. (Vuelve al principio del Buffer A cuando lo llena).
    *   `DMA0CONbits.MODE = 1;` // `01` = One-Shot, sin Ping-Pong. (Llena el Buffer A una sola vez y se desactiva `CHEN`).
    *   `DMA0CONbits.MODE = 2;` // `10` = Continuo, con Ping-Pong. (Llena el A, luego el B, luego el A...).
    *   `DMA0CONbits.MODE = 3;` // `11` = One-Shot, con Ping-Pong. (Llena el A, luego el B, y se apaga `CHEN`).

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

## 5. Anexo Técnico: Funcionamiento Detallado del Registro `DMAxPAD`

El registro **`DMAxPAD`** (DMA Channel x Peripheral Address Register) es fundamental para el funcionamiento del módulo de Acceso Directo a Memoria, ya que actúa como el "puente" que conecta un canal de DMA con un periférico específico.

A continuación, se detalla qué información maneja este registro y por qué es vital para el **ADC1**:

### 5.1 ¿Qué es físicamente el `DMAxPAD`?
Este registro contiene la **dirección estática del registro de datos del periférico** con el que el DMA va a intercambiar información. 
*   **En una lectura (ADC -> RAM):** El DMA usa la dirección en `DMAxPAD` para saber de dónde "sacar" el dato convertido.
*   **En una escritura (RAM -> UART/DAC):** El DMA usa esa dirección para saber dónde "depositar" el dato que trae de la memoria.

### 5.2 La relación específica con el ADC1
Para que el DMA pueda automatizar la captura de datos del conversor analógico-digital, debe apuntar al registro donde el conversor deja sus resultados:
*   **El Registro Buffer:** Para el ADC1, este registro es el **`ADC1BUF0`**.
*   **La Dirección Física:** Según el mapa de registros del dsPIC33F, la dirección hexadecimal de `ADC1BUF0` es **`0x0300`**.
*   **Sintaxis en C:** En la programación real, es más seguro y legible usar el operador de dirección: 
    ```c
    DMAxPAD = (int)&ADC1BUF0;
    ```

### 5.3 ¿Por qué es una dirección "estática"?
A diferencia de las direcciones en la RAM (donde el DMA va saltando de posición en posición usando los registros `DMAxSTA` y `DMAxSTB`), la dirección del periférico en el `DMAxPAD` **no cambia** durante la transferencia de un bloque. El DMA siempre vuelve al mismo "buzón" (`ADC1BUF0`) para recoger cada nueva muestra que el ADC termina de procesar.

### 5.4 Resumen de configuración para el TP3 (ADC + DMA)
Para que el ejercicio del brazo robot (ADC-DMA) funcione, debés asociar tres registros clave:
1.  **`DMAxREQ`:** Se carga con el valor **13** para que el DMA sepa que debe actuar cada vez que el **ADC1** termine una conversión.
2.  **`DMAxPAD`:** Se carga con **`&ADC1BUF0`** (o `0x0300`) para que el DMA sepa de dónde leer el dato.
3.  **`DMAxSTA / STB`:** Se cargan con la dirección del **arreglo en RAM** donde querés guardar los valores (ej. el buffer de 6 posiciones del brazo robot).

> [!TIP]
> **Dato técnico adicional:** Si por error configurás el `DMAxPAD` con una dirección que no corresponde a un periférico válido para DMA, el controlador simplemente ignorará las escrituras o leerá ceros, lo que causaría que tu programa no reciba ningún dato del ADC.

---

## 📚 ¿Dónde ampliar el tema en tus fuentes oficiales?

1.  **Configuración y Registros del ADC:**
    *   **`dsPIC33 - Analog to Digital Converter-DS70183A_es.md`**: Sección 16.4 (Configuración del módulo) y Sección 16.21 (Ejemplos de código).
    *   **`Conversor Analógico_Digital_es.md`**: Diapositivas de la cátedra con conceptos generales y resolución.
2.  **Arquitectura y Registros del DMA:**
    *   **`DsPIC33 - DMA -DS70182b_es.md`**: Sección 22.5 (Configuración) y Sección 22.6 (Modos de operación).
3.  **Tabla de Asociación DMA-Periférico:**
    *   **`DsPIC33 - DMA -DS70182b_es.md`**: Tabla 22-1, que lista los valores de `IRQSEL` y `PAD` para cada periférico.

