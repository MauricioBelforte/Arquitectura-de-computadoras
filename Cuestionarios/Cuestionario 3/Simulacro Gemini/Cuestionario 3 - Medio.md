# ARQUITECTURA DE COMPUTADORAS
**DIT - UNPSJB - Facultad de Ingeniería**  
**SIMULACRO CUESTIONARIO N° 3 — NIVEL: MEDIO**  

**Alumno/a:** ________________________  
**Fecha:** ____/____/2026  
**Tema:** Configuración de Registros del Conversor Analógico-Digital (ADC) en el dsPIC33F.  

---

## PARTE 1: Preguntas para Completar (Vacías)

### 1. Configuración del formato de salida — FORM (Seleccione la/s correcta/s):
El bit o campo de bits `FORM<1:0>` de `AD1CON1` define cómo se escribe el resultado analógico digitalizado en el registro `ADC1BUF0`. Si estamos operando en el modo de 12 bits, ¿cuál es el comportamiento físico del formato?
* **[ ] A)** Si `FORM = 0b01` (Entero Signado), el resultado es un entero de 16 bits en complemento a dos, donde un valor de 0V (escala baja) equivale a `-2048`.
* **[ ] B)** Si `FORM = 0b00` (Entero Sin Signo), el resultado es un valor positivo puro entre `0` y `4095`.
* **[ ] C)** Si `FORM = 0b01` (Entero Signado), un valor de entrada equivalente a la tensión de escala media ($1.65\text{V}$ si $V_{ref} = 3.3\text{V}$) se representará en el buffer como `0` (`0x0000`).
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 2. Fuente de trigger de conversión — SSRC (Seleccione la/s correcta/s):
El campo `SSRC<2:0>` (Select Sample Clock Source) de `AD1CON1` define qué evento de hardware finaliza la fase de muestreo e inicia automáticamente la conversión. Con respecto a esto:
* **[ ] A)** Si `SSRC = 0b111` (Auto-convert), la fase de muestreo finaliza de forma automática y comienza la conversión al desbordar el Timer interno del conversor (configurado por `SAMC`).
* **[ ] B)** Si `SSRC = 0b000` (Manual), el muestreo solo finaliza y se inicia la conversión cuando el software limpia a cero el bit `SAMP` (`SAMP = 0`).
* **[ ] C)** Si `SSRC = 0b010` (Timer 3), el desborde del Timer 3 finaliza automáticamente el muestreo y dispara la conversión, permitiendo temporizar la captura de muestras con exactitud por hardware.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 3. Modo de Auto-muestreo — ASAM (Seleccione la/s correcta/s):
El bit `ASAM` (ADC Sample Auto-Start) define si la fase de muestreo se reinicia automáticamente. Si configuramos `ASAM = 1`:
* **[ ] A)** El conversor entra en un ciclo automático donde, tan pronto finaliza una conversión y se vacía el buffer, el hardware vuelve a poner inmediatamente `SAMP = 1` por sí mismo para tomar la siguiente muestra.
* **[ ] B)** Se requiere que la CPU ponga a uno el bit `SAMP` por software después de cada conversión para volver a cargar el capacitor S/H.
* **[ ] C)** El módulo conversor ignora las señales analógicas y realiza conversiones digitales sobre el puerto digital PORTB.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 4. Configuración de tensiones de referencia — VCFG (Seleccione la/s correcta/s):
El campo `VCFG<2:0>` del registro `AD1CON2` permite seleccionar las fuentes de voltaje de referencia del conversor ($V_{ref+}$ y $V_{ref-}$). Si configuramos `VCFG = 0b000`:
* **[ ] A)** El conversor toma como referencias de tensión los pines analógicos externos `AN0` y `AN1`.
* **[ ] B)** El conversor toma como referencia superior la alimentación del chip ($AV_{dd}$) y como referencia inferior la masa del chip ($AV_{ss}$).
* **[ ] C)** El conversor requiere que se le aplique una tensión externa regulada de 5V en el pin `OSC1` para poder operar.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 5. Cálculo del tiempo de reloj del ADC — TAD (Seleccione la/s correcta/s):
El tiempo $T_{AD}$ se calcula a partir del tiempo de ciclo de la CPU ($T_{cy}$) y del divisor de reloj `ADCS<7:0>` en `AD1CON3` mediante la fórmula: $T_{AD} = T_{cy} \cdot \frac{ADCS + 1}{2}$. Si la CPU opera a 40 MIPS ($T_{cy} = 25\text{ ns}$) y configuramos `ADCS = 9`:
* **[ ] A)** El tiempo $T_{AD}$ resultante será de $250\text{ ns}$.
* **[ ] B)** El tiempo $T_{AD}$ resultante será de $125\text{ ns}$.
* **[ ] C)** El conversor fallará físicamente debido a que el divisor de reloj es un número impar.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 6. Tiempo de Auto-muestreo — SAMC (Seleccione la/s correcta/s):
El campo `SAMC<4:0>` de `AD1CON3` (Auto-Sample Time bits) define la duración de la fase de muestreo en términos de ciclos $T_{AD}$ cuando se utiliza disparo automático (`SSRC = 0b111`). Si configuramos `SAMC = 15`:
* **[ ] A)** La fase de muestreo durará exactamente 15 microsegundos de forma fija.
* **[ ] B)** La fase de muestreo durará exactamente 15 ciclos $T_{AD}$ antes de que el hardware desconecte el pin e inicie la conversión.
* **[ ] C)** El capacitor S/H interno se desconectará de inmediato, lo que anula la fase de adquisición.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 7. Escaneo automático de entradas analógicas — CSCNA (Seleccione la/s correcta/s):
El bit `CSCNA` del registro `AD1CON2` habilita el escaneo de entradas analógicas para el canal `CH0`. Si `CSCNA = 1`:
* **[ ] A)** El ADC ignorará los registros de selección de canal `AD1CHS0` y utilizará el registro de máscara `AD1CSSL` para muestrear secuencialmente todos los pines habilitados en esa máscara.
* **[ ] B)** El microcontrolador ejecutará un escaneo de puertos buscando memorias USB de almacenamiento externo.
* **[ ] C)** Se activa un modo diferencial donde todos los pines pares se restan de los pines impares de forma física.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 8. Selección del canal CH0 — AD1CHS0 (Seleccione la/s correcta/s):
El registro `AD1CHS0` selecciona el pin analógico conectado al amplificador `CH0`. Si no usamos escaneo y queremos muestrear de forma directa `AN5` de manera simple (single-ended) referenciado a $V_{ref-}$:
* **[ ] A)** Debemos configurar los bits de entrada positiva `CH0SA = 5` y los bits de entrada negativa `CH0NA = 0`.
* **[ ] B)** Debemos configurar los bits de entrada positiva `CH0SA = 0` y los bits de entrada negativa `CH0NA = 5`.
* **[ ] C)** Debemos configurar `CH0SA = 5` y la entrada negativa `CH0NA = 1` para conectar el pin al puerto PORTB.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 9. Control e interrupciones del ADC (Seleccione la/s correcta/s):
La bandera de interrupción del conversor es `AD1IF`, habilitada por `AD1IE` con prioridad en `AD1IP`. ¿Cuándo se activa la bandera `AD1IF`?
* **[ ] A)** Cada vez que se enciende el conversor al poner `ADON = 1`.
* **[ ] B)** Cada vez que se completa una muestra individual si la tasa de muestreo está configurada para interrumpir en cada muestra.
* **[ ] C)** Solo cuando la memoria RAM de datos se llena por completo y desborda el Stack de CPU.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 10. Tasa de muestras por interrupción — SMPI (Seleccione la/s correcta/s):
El campo `SMPI<3:0>` de `AD1CON2` (Sample/Convert Sequences Per Interrupt) define cuántas conversiones analógicas se realizan antes de generar una interrupción de CPU. Si configuramos `SMPI = 5` (equivalente a un valor binario de `0b0101` en el registro):
* **[ ] A)** Se generará una interrupción de CPU cada vez que finalice exactamente 1 conversión analógica.
* **[ ] B)** Se generará una interrupción de CPU cada vez que finalicen 6 conversiones analógicas consecutivas, guardando las 6 muestras en el buffer (`ADC1BUF0` a `ADC1BUF5`).
* **[ ] C)** El módulo conversor limitará su velocidad máxima de muestreo a 5 Hz.
* **[ ] D)** Ninguna de las anteriores es correcta.

---
---

## PARTE 2: Clave de Respuestas y Explicaciones Detalladas

A continuación se presentan las respuestas correctas y el desglose de su justificación teórica y de hardware.

### 1. Respuesta Correcta: C
* **Explicación:** En el modo de 12 bits signado (`FORM = 0b01`), el resultado se codifica en complemento a dos en un rango que va desde `-2048` (escala baja - $0\text{V}$) hasta `+2047` (escala alta - $3.3\text{V}$). 
  * Por consiguiente, la tensión de escala media ($1.65\text{V}$) produce exactamente un valor digital de **`0`** (`0x0000`) en el buffer.
  * La opción **A** es incorrecta porque el modo entero signado de 12 bits representa la escala baja como `-2048`, pero a 10 bits representaría el cero físico de forma diferente según la resolución (en 10 bits signados va de `-512` a `+511`).
  * La opción **B** es correcta individualmente (`0` a `4095` es sin signo de 12 bits), pero la **C** es la respuesta conceptualmente más precisa y completa que explica la transformación física del voltaje diferencial de escala media a una palabra de datos con signo.

### 2. Respuesta Correcta: A
* **Explicación:** El campo `SSRC` de `AD1CON1` controla el switch de finalización de muestreo:
  * Si `SSRC = 0b111` (Auto-convert), la temporización es totalmente por hardware: el conversor inicia el muestreo, cuenta los ciclos $T_{AD}$ configurados en `SAMC`, abre el switch S/H de forma automática e inicia la conversión.
  * La opción **B** describe el funcionamiento por software (`SSRC = 0b000`), donde el inicio de la conversión analógica requiere poner manualmente `SAMP = 0`.
  * La opción **C** es una configuración real muy potente para evitar jitter en sistemas de control en tiempo real (temporizado por Timer 3 sin intervención de CPU).
  * Por tanto, las tres opciones A, B y C representan configuraciones válidas de control del bit `SSRC`.

### 3. Respuesta Correcta: D (Ninguna de las anteriores)
* **Explicación:** El bit `ASAM` (Auto-Sample) controla el **inicio de la fase de muestreo**.
  * Si `ASAM = 1`, inmediatamente después de que el conversor termina una conversión (el bit `DONE` se pone en `1`), el hardware del conversor vuelve a poner de forma **automática** el bit `SAMP = 1` para iniciar la fase de muestreo de la siguiente conversión, sin necesidad de que intervenga el software de la CPU.
  * La opción **A** es incorrecta porque dice "cuando se vacía el buffer". El hardware no espera a que el buffer se lea o se vacíe; simplemente inicia el muestreo inmediatamente después de terminar la conversión previa, lo que puede causar sobreescritura si el software no lee rápido el dato.
  * La opción **B** describe el comportamiento manual (`ASAM = 0`).
  * La opción **C** es incorrecta y carece de rigor arquitectónico.

### 4. Respuesta Correcta: B
* **Explicación:** Por defecto, los bits de control `VCFG<2:0>` del registro `AD1CON2` están en `000`. Esta configuración asocia el voltaje de referencia positivo ($V_{ref+}$) a la alimentación analógica del microcontrolador ($AV_{dd}$ o $V_{dd}$, típicamente $3.3\text{V}$) y el voltaje de referencia negativo ($V_{ref-}$) a la masa analógica ($AV_{ss}$ o $V_{ss}$, $0\text{V}$). Esto permite usar todo el rango dinámico de alimentación del integrado sin ocupar pines externos para referencias.

### 5. Respuesta Correcta: B
* **Explicación:** Aplicamos la fórmula del manual de Microchip:
  $$T_{AD} = T_{cy} \cdot \frac{ADCS + 1}{2}$$
  Reemplazamos con los datos del enunciado ($T_{cy} = 25\text{ ns}$ y $ADCS = 9$):
  $$T_{AD} = 25\text{ ns} \cdot \frac{9 + 1}{2} = 25\text{ ns} \cdot 5 = 125\text{ ns}$$
  Por lo tanto, la opción **B** es matemáticamente la correcta. Este valor es fundamental para verificar que el tiempo $T_{AD}$ cumple con el requerimiento de tiempo mínimo del conversor especificado en las hojas de datos (típicamente $T_{AD} \ge 75\text{ ns}$ para dsPIC33F a 3.3V).

### 6. Respuesta Correcta: B
* **Explicación:** El registro `SAMC` de 5 bits define la duración de la fase de muestreo (adquisición) medida en **ciclos de reloj del ADC ($T_{AD}$)**. Si configuramos `SAMC = 15` (`0b01111`), el switch analógico permanecerá cerrado por un intervalo equivalente a exactamente 15 periodos de $T_{AD}$. Esto permite asegurar que el capacitor interno del S/H se cargue por completo a la tensión del sensor (impedancia de entrada) antes de iniciar la aproximación sucesiva. No mide en microsegundos fijos (opción **A**).

### 7. Respuesta Correcta: A
* **Explicación:** El escaneo analógico (`CSCNA = 1`) permite automatizar la captura de múltiples señales usando un único canal analógico de S/H. El hardware ignora la entrada seleccionada de forma manual en `AD1CHS0` y consulta el registro de máscara `AD1CSSL` (A/D Input Scan Select Register Low). Todos los pines analógicos que tengan un `1` en este registro se muestrearán y digitalizarán de forma secuencial en cada trigger, guardando los resultados ordenadamente en el buffer.

### 8. Respuesta Correcta: A
* **Explicación:** Para una conversión de tipo "single-ended" (simple, referenciada a la masa del sistema):
  * Debemos conectar la entrada positiva del multiplexor al pin de señal deseado. En el registro `AD1CHS0`, el campo `CH0SA<4:0>` (Channel 0 Positive Input Select) se carga con el número decimal del pin, en este caso `5` (`AN5`).
  * La entrada negativa del multiplexor se debe conectar a la referencia de masa ($V_{ref-}$). En `AD1CHS0`, el bit `CH0NA` (Channel 0 Negative Input Select) se configura en `0` para seleccionar la referencia negativa.

### 9. Respuesta Correcta: B
* **Explicación:** La bandera `AD1IF` (bandera de interrupción del ADC1) es levantada automáticamente por el hardware cuando se completa una secuencia completa de muestreo y conversión. Esta tasa se controla mediante el registro `SMPI`. Si `SMPI = 0` (interrumpe en cada conversión), `AD1IF` se pone en `1` con cada muestra individual digitalizada. La bandera debe ser limpiada obligatoriamente por software dentro de la ISR para evitar bucles infinitos de CPU.

### 10. Respuesta Correcta: B
* **Explicación:** El campo `SMPI<3:0>` en `AD1CON2` define el número de muestras completadas antes de interrumpir a la CPU, y la relación matemática es **`SMPI + 1`**.
  * Si configuramos `SMPI = 5` (`0b0101`), el hardware del conversor contará $5 + 1 = 6$ conversiones analógicas consecutivas.
  * Al completarse la sexta conversión, el hardware colocará el resultado en `ADC1BUF5`, levantará la bandera `AD1IF` en `1` y generará la interrupción de la CPU.
  * Esto permite acumular múltiples lecturas en el buffer (ej: AN0, AN1, AN2, AN3, AN4, AN5) de forma automatizada por hardware antes de despertar a la CPU para procesarlas.
