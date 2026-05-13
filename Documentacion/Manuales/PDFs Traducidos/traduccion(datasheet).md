Esta es la traducción de la primera sección: **Resumen del Dispositivo y Familias de Productos**.

---

# # dsPIC33FJXXXGPX06/X08/X10

## Controladores Digitales de Señales de 16 Bits de Alto Rendimiento

[cite_start]**Hoja de Datos (Data Sheet)** [cite: 24, 25, 27]

### Rango de Operación:

- [cite_start]Funcionamiento de hasta 40 MIPS (a 3.0-3.6V). [cite: 56]
- [cite_start]Rango de temperatura industrial ($-40^{\circ}C$ a $+85^{\circ}C$). [cite: 56]

### CPU de alto rendimiento (DSC):

- [cite_start]Arquitectura Harvard modificada. [cite: 57]
- [cite_start]Conjunto de instrucciones optimizado para compilador C. [cite: 58]
- [cite_start]Ruta de datos de 16 bits de ancho y de instrucciones de 24 bits. [cite: 58, 59]
- [cite_start]Direccionamiento lineal de memoria de programa hasta 4M de palabras de instrucción. [cite: 60]
- [cite_start]Direccionamiento lineal de memoria de datos hasta 64 Kbytes. [cite: 61]
- [cite_start]83 instrucciones base: la mayoría de 1 palabra/1 ciclo. [cite: 61]
- [cite_start]Dieciséis registros de propósito general de 16 bits. [cite: 61]
- [cite_start]Dos acumuladores de 40 bits con opciones de redondeo y saturación. [cite: 61, 62]
- [cite_start]Multiplicaciones fraccionarias/enteras de $16\times16$ y divisiones de $32/16$ y $16/16$. [cite: 64]
- [cite_start]Multiplicación y acumulación en un solo ciclo (MAC) con escritura retrospectiva en el acumulador para operaciones DSP. [cite: 65]

### Acceso Directo a Memoria (DMA):

- [cite_start]DMA de hardware de 8 canales. [cite: 67]
- [cite_start]2 Kbytes de área de búfer DMA de doble puerto (DMA RAM). [cite: 68]
- [cite_start]Permite la transferencia de datos entre la RAM y un periférico mientras la CPU ejecuta código (sin robo de ciclos). [cite: 68]

### Periféricos Digitales e I/O:

- [cite_start]Hasta 85 pines de E/S digitales programables. [cite: 76]
- [cite_start]Pines de entrada tolerantes a 5V. [cite: 79]
- [cite_start]Controlador de interrupciones con latencia de 5 ciclos y hasta 63 fuentes disponibles. [cite: 70, 71, 72]
- [cite_start]Hasta nueve temporizadores de 16 bits (pueden emparejarse para formar temporizadores de 32 bits). [cite: 98]
- [cite_start]Módulos de Captura de Entrada y Comparación de Salida (hasta 8 canales cada uno). [cite: 100, 102]

### Módulos de Comunicación:

- [cite_start]Hasta dos módulos SPI (3 cables), compatibles con 8 y 16 bits. [cite: 107, 109]
- [cite_start]Hasta dos módulos I2C™ con soporte maestro/esclavo completo. [cite: 111, 112]
- [cite_start]Hasta dos módulos UART con soporte para bus LIN e IrDA®. [cite: 117, 122, 123]
- [cite_start]Interfaz de Convertidor de Datos (DCI) compatible con protocolos I2S y AC'97. [cite: 125, 126]
- [cite_start]CAN mejorado (ECAN™) 2.0B activo (hasta 2 módulos). [cite: 129, 130]

### Convertidores Analógico a Digital (ADC):

- [cite_start]Hasta dos módulos ADC de 10 bits (1.1 Msps) o 12 bits (500 ksps). [cite: 139, 141]
- [cite_start]Hasta 32 canales de entrada con escaneo automático. [cite: 142]

---

[cite_start]**Nota:** He omitido las tablas detalladas de variantes de dispositivos por su gran extensión técnica, pero están disponibles si necesitas comparar modelos específicos (como el dsPIC33FJ256GP710). [cite: 155, 163]

---

Esta es la traducción de la sección 2.0: **Diagramas de Pines**.

Dado que esta sección es puramente visual y contiene los esquemas de conexión del chip, he procedido a generar la representación del diagrama de pines principal para el modelo de 100 pines (TQFP), traduciendo las etiquetas y leyendas pertinentes.

---

## 2.0 Diagramas de Pines

Esta sección muestra la configuración de los pines para las diferentes variantes de empaquetado. Un punto clave a recordar es que muchos pines comparten múltiples funciones (multiplexación).

### Diagrama de Pines: 100-Pin TQFP (Ejemplo dsPIC33FJ256GP710)

### Resumen de Funciones de Pines (Traducción de términos clave):

- **ANx:** Entrada de canal analógico.
- **VREF+ / VREF-:** Voltaje de referencia (positivo/negativo) para el ADC.
- **VSS / VDD:** Tierra (0V) y Alimentación positiva (3.3V).
- **AVSS / AVDD:** Tierra y Alimentación específica para los módulos analógicos (limpieza de ruido).
- **MCLR:** Master Clear (Reinicio/Reset del dispositivo). Es activo en bajo.
- **PGECx / PGEDx:** Pines de reloj y datos para programación y depuración ICSP™.
- **OSC1 / OSC2:** Pines para la conexión del oscilador de cristal externo.
- **RPn:** Pines de Periféricos Remapeables (permiten asignar funciones digitales a diferentes pines por software).
- **U1TX / U1RX:** Transmisión y Recepción del módulo UART 1.
- **SCLx / SDAx:** Reloj y Datos para el bus I2C™.

---

> **Nota técnica:** En los diagramas originales, notarás que algunos pines están sombreados. Esto indica que son pines "Tolerantes a 5V", lo que significa que pueden recibir señales digitales de 5V aunque el chip funcione a 3.3V, facilitando la conexión con sistemas más antiguos.

---

[cite_start]Esta es la traducción de la sección **2.0: Directrices para empezar con los Controladores Digitales de Señales de 16 bits** (anteriormente referenciada como 3.0, según la actualización de la revisión C del datasheet [cite: 17]).

Esta sección es crucial para el diseño de hardware, ya que detalla las conexiones mínimas obligatorias para que el chip funcione correctamente.

---

## 2.0 Directrices para empezar con DSC de 16 bits

### 2.1 Conexiones de Alimentación Básicas

Todos los pines de alimentación (**VDD**) y tierra (**VSS**) deben estar conectados. [cite_start]Se recomienda el uso de planos de alimentación en la placa de circuito impreso (PCB)[cite: 4].

**Requisitos de condensadores de desacoplo:**

- [cite_start]Se debe colocar un condensador cerámico de **0.1 $\mu$F** (100 nF) lo más cerca posible de cada par de pines VDD/VSS[cite: 4].
- [cite_start]Los condensadores deben tener una baja Resistencia Serie Equivalente (ESR) y soportar al menos 10V[cite: 4].

### 2.2 Condensador del Regulador de Voltaje (VCAP/VDDCORE)

El dsPIC33F incluye un regulador de voltaje interno de 2.5V para el núcleo.

- [cite_start]Es **obligatorio** conectar un condensador de baja ESR al pin **VCAP/VDDCORE**[cite: 4].
- [cite_start]Se recomienda un valor de **10 $\mu$F** (mínimo 4.7 $\mu$F)[cite: 4].
- [cite_start]Este condensador debe estar conectado a tierra (VSS)[cite: 4].

### 2.3 Pin de Reinicio Maestro (MCLR)

El pin MCLR se utiliza para reiniciar el dispositivo. Para un funcionamiento estable:

- [cite_start]Se recomienda una resistencia de pull-up (**R**) de **10 k$\Omega$** conectada a VDD[cite: 4].
- [cite_start]Se puede añadir una resistencia en serie (**R1**) de hasta **470 $\Omega$** para proteger contra descargas electrostáticas (ESD)[cite: 4].

### 2.4 Pines de Programación ICSP (PGECx/PGEDx)

[cite_start]Estos pines se utilizan para la programación y depuración (In-Circuit Serial Programming™)[cite: 4].

- [cite_start]Mantenga las pistas entre el conector ICSP y los pines del chip lo más cortas posible[cite: 4].
- [cite_start]**No se recomienda** el uso de resistencias de pull-up, diodos o condensadores en las líneas PGECx/PGEDx, ya que pueden interferir con la señal de datos/reloj durante la programación[cite: 4].

---

Esta es la traducción de la sección **3.0: CPU**, que detalla la arquitectura interna, los registros y el funcionamiento del núcleo del dsPIC33F.

---

## 3.0 CPU

[cite_start]El módulo CPU de los dispositivos dsPIC33F posee una arquitectura **Harvard modificada** de 16 bits (datos) con un conjunto de instrucciones mejorado que incluye un soporte significativo para el procesamiento digital de señales (**DSP**)[cite: 3].

### 3.1 Características Principales

- [cite_start]**Palabra de instrucción:** 24 bits de ancho con un campo de código de operación (opcode) de longitud variable[cite: 3].
- [cite_start]**Contador de Programa (PC):** 23 bits de ancho, permitiendo direccionar hasta 4M x 24 bits de espacio de memoria de programa de usuario[cite: 3].
- **Ejecución:** Mecanismo de pre-lectura (prefetch) de ciclo único que mantiene el rendimiento y proporciona una ejecución predecible. [cite_start]Casi todas las instrucciones se ejecutan en un **solo ciclo**[cite: 3].
- **Registros de trabajo:** Dispone de **dieciséis registros de 16 bits** (W0 a W15). [cite_start]El registro **W15** actúa como el Puntero de Pila (Stack Pointer - SP) de software para interrupciones y llamadas[cite: 3].

### 3.2 Modelo del Programador

[cite_start]La CPU integra de forma transparente dos clases de instrucciones: **MCU** y **DSP**[cite: 3]. [cite_start]El conjunto de instrucciones está diseñado para una eficiencia óptima con el compilador C[cite: 3].

#### Registros Principales del Núcleo:

- [cite_start]**W0-W15:** Registros de trabajo que pueden servir como datos, direcciones o desplazamientos (offsets) de dirección[cite: 3, 8].
- [cite_start]**ACCA, ACCB:** Dos acumuladores de 40 bits para operaciones DSP de alta precisión[cite: 3].
- [cite_start]**SR (Status Register):** Registro de estado de la CPU que contiene banderas de aritmética (Z, C, N, OV), el nivel de prioridad de interrupción (IPL) y banderas de estado DSP (como saturación y desbordamiento)[cite: 4, 11].
- [cite_start]**CORCON (Core Control Register):** Controla el modo de operación de la CPU, incluyendo configuraciones de saturación, redondeo y visibilidad del espacio de programa (PSV)[cite: 5].

### 3.3 Direccionamiento de Datos

[cite_start]El espacio de datos se puede direccionar como 64 Kbytes y está dividido en dos bloques: **Memoria X** y **Memoria Y**[cite: 3].

- [cite_start]Cada bloque tiene su propia Unidad de Generación de Direcciones (AGU) independiente[cite: 3].
- [cite_start]Soporta **Modo de Direccionamiento de Módulo** (búferes circulares), lo que elimina la sobrecarga de software para verificar límites en algoritmos DSP[cite: 3].
- [cite_start]La AGU X también admite **Direccionamiento de Bits Revertidos** (Bit-Reversed), simplificando el reordenamiento de datos para algoritmos FFT de radical-2[cite: 3, 21].

---

Esta es la traducción de la sección **4.0: Organización de la Memoria**, la cual explica cómo el dsPIC33F gestiona los espacios separados para instrucciones (programa) y datos.

---

## 4.0 Organización de la Memoria

[cite_start]La arquitectura de los dispositivos dsPIC33F presenta espacios de memoria y buses **separados** para el programa y los datos[cite: 12]. [cite_start]Esta estructura de tipo **Harvard modificada** permite, además, el acceso directo a la memoria de programa desde el espacio de datos durante la ejecución del código[cite: 12].

### 4.1 Espacio de Direccionamiento de Programa

[cite_start]El espacio de memoria de programa tiene una capacidad de **4M de instrucciones**[cite: 12].

- [cite_start]**Direccionamiento:** Se utiliza un valor de 24 bits derivado del Contador de Programa (PC) de 23 bits o mediante operaciones de tabla[cite: 12].
- [cite_start]**Acceso de Usuario:** El acceso está restringido a la mitad inferior del rango de direcciones (0x000000 a 0x7FFFFF)[cite: 12].
- [cite_start]**Vectores Críticos:** Incluye el **Vector de Reset** (0x000000) y las Tablas de Vectores de Interrupción[cite: 23].

### 4.2 Espacio de Memoria de Datos

[cite_start]El espacio de datos es de 16 bits de ancho y se organiza de la siguiente manera[cite: 12]:

- [cite_start]**Registros de Funciones Especiales (SFR):** Los primeros 2 Kbytes (0x0000 a 0x07FF) están reservados para el control de periféricos y el núcleo[cite: 5].
- **Memoria RAM de Datos:** El resto del espacio se utiliza para variables de usuario. [cite_start]Se divide en **Memoria X** y **Memoria Y** para permitir que las instrucciones DSP realicen dos lecturas de datos simultáneas en un solo ciclo[cite: 3].
- [cite_start]**DMA RAM:** Incluye un área específica (hasta 2 Kbytes) para el búfer del controlador de Acceso Directo a Memoria, que permite mover datos sin intervención de la CPU[cite: 17].

### 4.3 Pila de Software (Stack)

[cite_start]El registro **W15** se utiliza automáticamente como el **Puntero de Pila (Stack Pointer)**[cite: 11].

- [cite_start]Crece de direcciones bajas a altas[cite: 11].
- [cite_start]El registro **SPLIM** (Límite de Pila) se utiliza para evitar que la pila invada otras áreas de memoria, generando una trampa (error) si se sobrepasa el límite establecido[cite: 11].

### 4.4 Visibilidad del Espacio de Programa (PSV)

[cite_start]Esta característica permite que los 32 Kbytes superiores del espacio de datos se mapeen a cualquier "página" de 16K palabras de la memoria de programa[cite: 13]. [cite_start]Esto permite leer constantes almacenadas en la Flash (como tablas de filtros o mensajes de texto) como si fueran variables normales en RAM, utilizando punteros estándar de 16 bits[cite: 13].

---

[cite_start]Esta es la traducción de la sección **5.0: Memoria de Programa Flash**, que explica cómo se almacena el código y cómo el propio dispositivo puede modificar su memoria en tiempo de ejecución. [cite: 6]

---

## 5.0 Memoria de Programa Flash

[cite_start]Los dispositivos dsPIC33F contienen memoria Flash interna para almacenar y ejecutar el código de la aplicación. [cite: 6] [cite_start]Esta memoria se puede leer, escribir y borrar durante el funcionamiento normal en todo el rango de voltaje de alimentación (VDD). [cite: 6]

### 5.1 Métodos de Programación

[cite_start]Existen dos formas principales de programar la memoria Flash: [cite: 6]

1.  [cite_start]**In-Circuit Serial Programming™ (ICSP™):** Permite programar el dispositivo de forma serial mientras está en el circuito de la aplicación final mediante dos líneas (reloj y datos: PGECx/PGEDx). [cite: 6]
2.  [cite_start]**Auto-programación en tiempo de ejecución (Run-Time Self-Programming - RTSP):** Se realiza mediante instrucciones de tabla (**TBLRD** y **TBLWT**). [cite: 6] [cite_start]Permite que el usuario escriba datos en bloques o "filas" y borre bloques en "páginas" mientras la aplicación se ejecuta. [cite: 6]

### 5.2 Operación RTSP

[cite_start]La memoria Flash está organizada en **filas de 64 instrucciones** (192 bytes). [cite: 6]

- [cite_start]**Borrado:** Se realiza por "páginas", donde cada página consta de ocho filas (**512 instrucciones**). [cite: 6]
- [cite_start]**Escritura:** El usuario puede programar una fila completa o una sola palabra de memoria a la vez. [cite: 6]
- [cite_start]**Búferes de retención:** Antes de escribir, los datos deben cargarse secuencialmente en búferes que pueden contener las 64 instrucciones. [cite: 6]

### 5.3 Direccionamiento (Instrucciones de Tabla)

[cite_start]Para acceder a la memoria de programa (24 bits) desde el espacio de datos (16 bits), se utilizan las instrucciones de lectura/escritura de tabla: [cite: 6]

- [cite_start]**TBLPAG:** Registro de 8 bits que selecciona la página de la memoria de programa. [cite: 6]
- [cite_start]**TBLRDL / TBLWTL:** Acceden a los 16 bits inferiores (bits <15:0>). [cite: 6]
- [cite_start]**TBLRDH / TBLWTH:** Acceden a los 8 bits superiores (bits <23:16>). [cite: 6]

### 5.4 Registros de Control

[cite_start]Se utilizan dos registros específicos para gestionar la programación: [cite: 6]

- [cite_start]**NVMCON:** Controla qué bloques se borrarán, qué tipo de memoria se programará y el inicio del ciclo de escritura (bit **WR**). [cite: 6]
- **NVMKEY:** Registro de solo escritura utilizado para protección. [cite_start]Para iniciar una secuencia de borrado o escritura, el usuario debe escribir consecutivamente los valores **55h** y **AAh** en este registro. [cite: 6]

---

[cite_start]Esta es la traducción de la sección **6.0: Reset (Restablecimiento)**, que explica cómo el dispositivo vuelve a un estado inicial conocido tras diversas condiciones de error o eventos del sistema[cite: 4].

---

## 6.0 Reset (Restablecimiento)

[cite_start]El módulo de Reset combina todas las fuentes de restablecimiento y controla la señal principal de Reset del sistema, **SYSRST**[cite: 4]. Las fuentes de Reset del dispositivo son las siguientes:

- [cite_start]**POR:** Reset de Encendido (Power-on Reset)[cite: 4].
- [cite_start]**BOR:** Reset por caída de tensión (Brown-out Reset)[cite: 4].
- [cite_start]**MCLR:** Reset por pin Master Clear externo[cite: 4].
- [cite_start]**SWR:** Instrucción de software RESET[cite: 4].
- [cite_start]**WDT:** Reset por tiempo agotado del Perro Guardián (Watchdog Timer)[cite: 4].
- [cite_start]**TRAPR:** Reset por conflicto de trampa (Trap)[cite: 4].
- [cite_start]**IOPUWR:** Reset por código de operación ilegal o uso de registro W no inicializado[cite: 4].

### Funcionamiento General

[cite_start]Cualquier fuente de Reset activa hará que la señal **SYSRST** se active[cite: 4]. [cite_start]Esto fuerza a muchos registros de la CPU y periféricos a un estado conocido[cite: 4]. [cite_start]Sin embargo, la mayoría de los registros no se ven afectados por un Reset; su estado es desconocido tras un POR y se mantiene sin cambios tras otros tipos de Reset[cite: 4].

### Registro RCON (Control de Reset)

[cite_start]Cada tipo de Reset establece un bit de estado correspondiente en el registro **RCON** para identificar qué causó el reinicio[cite: 4]. [cite_start]El usuario puede leer y luego limpiar estos bits mediante software para prepararse para detectar el próximo evento[cite: 4].

### Resumen de Bits en RCON (Registro 6-1):

- [cite_start]**TRAPR (bit 15):** Indica si ocurrió un reset por conflicto de trampa[cite: 4].
- [cite_start]**IOPUWR (bit 14):** Indica un reset por código ilegal o acceso a memoria no inicializada[cite: 4].
- [cite_start]**EXTR (bit 7):** Indica si el reset fue provocado por el pin externo MCLR[cite: 4].
- [cite_start]**SWR (bit 6):** Indica si se ejecutó la instrucción RESET por software[cite: 4].
- [cite_start]**WDTO (bit 4):** Indica un tiempo agotado del Watchdog Timer[cite: 4].
- [cite_start]**BOR/POR (bits 1/0):** Indican problemas de voltaje o el encendido inicial del chip[cite: 4].

---

[cite_start]Esta es la traducción de la sección **7.0: Controlador de Interrupciones**, la cual explica cómo el dsPIC33F gestiona las peticiones de servicio de los periféricos y errores del sistema[cite: 3].

---

## 7.0 Controlador de Interrupciones

[cite_start]El controlador de interrupciones del dsPIC33F organiza y gestiona las solicitudes de interrupción provenientes de múltiples fuentes[cite: 3]. Este módulo reduce la carga de la CPU al permitir que los periféricos soliciten atención solo cuando sea necesario.

### 7.1 Características Principales

- [cite_start]**Latencia de interrupción:** 5 ciclos de instrucción[cite: 59, 60].
- [cite_start]**Fuentes disponibles:** Hasta 63 fuentes de interrupción y 5 excepciones del procesador (trampas o _traps_)[cite: 61, 63].
- [cite_start]**Niveles de prioridad:** Siete niveles de prioridad programables para cada interrupción[cite: 62].
- [cite_start]**Interrupciones externas:** Hasta cinco interrupciones externas dedicadas (**INT0** a **INT4**)[cite: 61, 283].

### 7.2 Tabla de Vectores de Interrupción (IVT)

[cite_start]Cada fuente de interrupción tiene asignado un "vector" único, que es una dirección en la memoria de programa donde reside la rutina de servicio a la interrupción (ISR)[cite: 4, 10].

- [cite_start]**IVT Estándar:** Ubicada al inicio de la memoria de programa[cite: 10].
- [cite_start]**IVT Alternativa (AIVT):** Se puede habilitar mediante el bit **ALTIVT** para facilitar la depuración o el uso de _bootloaders_[cite: 4, 5].

### 7.3 Registros de Control

El funcionamiento se gestiona a través de varios grupos de registros:

- [cite_start]**IFSx (Interrupt Flag Status):** Contienen los bits de bandera que se ponen a '1' cuando ocurre un evento de interrupción[cite: 5]. [cite_start]El software debe limpiar estas banderas dentro de la ISR[cite: 5].
- [cite_start]**IECx (Interrupt Enable Control):** Se utilizan para habilitar o deshabilitar fuentes de interrupción específicas[cite: 5].
- [cite_start]**IPCx (Interrupt Priority Control):** Permiten asignar un nivel de prioridad (0-7) a cada interrupción[cite: 6, 7].
- [cite_start]**INTCON1 / INTCON2:** Registros de control global que manejan el anidamiento de interrupciones, la detección de errores de traps y la polaridad de los bordes de interrupción externa[cite: 2, 5].

### 7.4 Tipos de Interrupciones y Prioridades

1.  [cite_start]**Trampas (Traps):** Son las de mayor prioridad y se activan por errores graves (ej. división por cero, error de pila, error de oscilador)[cite: 2].
2.  **Interrupciones de Usuario:** Periféricos como Timers, UART o ADC. [cite_start]Si dos interrupciones de la misma prioridad ocurren a la vez, se resuelve mediante una jerarquía de "prioridad natural" fija basada en el número de vector[cite: 4, 8].

---

Esta es la traducción de la sección **8.0: Acceso Directo a Memoria (DMA)**. Esta sección es una de las más importantes para el rendimiento, ya que permite que los periféricos muevan datos sin ocupar tiempo de procesamiento de la CPU.

---

## 8.0 Acceso Directo a Memoria (DMA)

El Acceso Directo a Memoria (DMA) es una característica que permite la transferencia de datos entre la memoria RAM y los periféricos sin la intervención de la CPU. Esto maximiza el rendimiento del sistema al permitir que la CPU ejecute código mientras se realizan transferencias de datos en segundo plano.

### 8.1 Características Principales

- **8 canales independientes:** Cada canal puede ser configurado para un periférico específico.
- **Sin robo de ciclos:** El controlador DMA tiene su propio bus de datos y direcciones, por lo que no detiene la ejecución de la CPU.
- **Direccionamiento de hasta 2 Kbytes:** Utiliza un área dedicada de RAM de doble puerto denominada **DMA RAM**.
- **Modos de transferencia:** Soporta transferencias de bloque, transferencias continuas y modos de ping-pong (uso de dos búferes para procesamiento ininterrumpido).

### 8.2 Periféricos Soportados

El módulo DMA puede conectarse con los siguientes periféricos:

- Convertidor Analógico a Digital (ADC).
- UART (Transmisión y Recepción).
- SPI (Transmisión y Recepción).
- ECAN™ (Módulos de comunicación CAN).
- Input Capture (Captura de Entrada).
- Output Compare (Comparación de Salida).

### 8.3 Funcionamiento en Modo Ping-Pong

Este modo permite que el DMA llene un búfer mientras la CPU procesa el otro. Cuando el primer búfer se llena, el DMA cambia automáticamente al segundo y genera una interrupción, asegurando que no se pierdan datos en aplicaciones de alta velocidad (como audio o muestreo ADC).

### 8.4 Registros de Control del DMA

- **DMAxCON:** Configura el modo de funcionamiento, el tamaño de los datos (byte o palabra) y la dirección de la transferencia.
- **DMAxREQ:** Selecciona qué periférico activará la transferencia del canal (por ejemplo, cuando llega un dato a la UART).
- **DMAxSTA / DMAxSTB:** Registros de dirección de inicio para los búferes A y B (en modo ping-pong).
- **DMAxCNT:** Especifica el número de transferencias de datos (conteo de bloque).

---

[cite_start]Esta es la traducción de la sección **9.0: Configuración del Oscilador**[cite: 6]. Esta parte es fundamental, ya que describe cómo generar la señal de reloj que determina la velocidad de procesamiento del dispositivo.

---

## 9.0 Configuración del Oscilador

El sistema del oscilador del dsPIC33F proporciona:

- [cite_start]Varias opciones de oscilador externo e interno como fuentes de reloj[cite: 6].
- [cite_start]Un **PLL (Bucle de Enganche de Fase)** integrado para escalar la frecuencia de operación interna hasta la velocidad requerida por el sistema[cite: 6].
- [cite_start]La posibilidad de usar el oscilador interno **FRC** con el PLL, permitiendo el funcionamiento a máxima velocidad sin necesidad de componentes externos[cite: 6].
- [cite_start]Cambio de reloj (_Clock switching_) entre diversas fuentes en tiempo real[cite: 6].
- [cite_start]Un monitor de reloj a prueba de fallos (**FSCM**) que detecta fallos en el reloj y toma medidas de seguridad[cite: 6].

### 9.1 Fuentes de Reloj del Sistema

[cite_start]Existen siete opciones principales para el reloj del sistema[cite: 6]:

1.  [cite_start]**Oscilador FRC (Fast RC):** Un oscilador interno rápido que corre a una frecuencia nominal de **7.37 MHz**[cite: 6]. [cite_start]Se puede ajustar mediante software y dividir su frecuencia (de 1:2 a 1:256)[cite: 6].
2.  **Oscilador Primario (XT, HS o EC):**
    - [cite_start]**XT (Cristal):** Cristales o resonadores cerámicos de entre 3 MHz y 10 MHz[cite: 6].
    - [cite_start]**HS (Cristal de Alta Velocidad):** Cristales de entre 10 MHz y 40 MHz[cite: 6].
    - [cite_start]**EC (Reloj Externo):** Señal de reloj externa aplicada directamente al pin OSC1[cite: 6].
3.  [cite_start]**Oscilador Secundario (LP):** Diseñado para bajo consumo, utiliza un cristal de **32.768 kHz** (típicamente para relojes de tiempo real)[cite: 6].
4.  [cite_start]**Oscilador LPRC (Low-Power RC):** Oscilador interno de bajo consumo que corre a unos **32.768 kHz**[cite: 6]. [cite_start]Es la referencia para el Perro Guardián (WDT) y el monitor de fallos (FSCM)[cite: 6].

### 9.2 Configuración del PLL

[cite_start]El PLL permite alcanzar velocidades de hasta **40 MIPS** (millones de instrucciones por segundo)[cite: 3, 6]. Para su cálculo se utilizan tres factores configurables por registros:

- [cite_start]**N1 (Pre-escalador):** Divide la frecuencia de entrada (FIN) para que esté entre 0.8 MHz y 8 MHz[cite: 6].
- [cite_start]**M (Multiplicador):** Multiplica la señal para que el VCO interno oscile entre 100 MHz y 200 MHz[cite: 6].
- [cite_start]**N2 (Post-escalador):** Divide la salida del VCO (por 2, 4 u 8) para obtener la frecuencia final de reloj (**FOSC**)[cite: 6].

[cite_start]**Frecuencia de instrucción ($F_{CY}$):** La velocidad real a la que se ejecutan las instrucciones es siempre la mitad de la frecuencia del oscilador ($F_{CY} = F_{OSC} / 2$)[cite: 6].

---

Esta es la traducción de la **Sección 12.0: Timer1** y la **Sección 13.0: Timer2/3, 4/5, 6/7 y 8/9**. [cite_start]He combinado estas secciones para ofrecerte una visión completa de los temporizadores del dispositivo[cite: 1, 12, 13].

---

Para mantener el orden del manual, aquí tienes los módulos que nos saltamos (Capítulos 11 y 22), que aunque son más sencillos, son muy útiles para el diseño de hardware.

---

## 11.0 Puertos de Entrada/Salida (I/O)

Este capítulo explica cómo el chip interactúa físicamente con el mundo a través de sus pines.

- **Registros TRIS:** Controlan la dirección del pin (0 = Salida, 1 = Entrada).
- **Registros PORT:** Para leer el estado actual de los pines.
- **Registros LAT:** Para escribir datos en el pin (Latch). Es la forma recomendada para escribir en salidas y evitar el problema de "Lectura-Modificación-Escritura".
- **Cambio de Notificación (Change Notification):** Los pines pueden generar una interrupción automática cuando detectan un cambio de estado (de alto a bajo o viceversa), lo que es ideal para leer teclados o botones sin gastar ciclos de CPU.
- **Pines Tolerantes a 5V:** Muchos pines del dsPIC33F (que funciona a 3.3V) pueden recibir señales de 5V sin dañarse, facilitando la conexión con circuitos más antiguos.

---

## 12.0 Timer1

[cite_start]El módulo Timer1 es un temporizador de 16 bits que puede funcionar como contador de tiempo para un reloj de tiempo real o como un temporizador/contador de intervalos de funcionamiento libre[cite: 12].

### Características principales:

- [cite_start]Temporizador de 16 bits[cite: 12].
- [cite_start]Contador síncrono de 16 bits[cite: 12].
- [cite_start]Contador asíncrono de 16 bits[cite: 12].
- [cite_start]Funcionamiento de puerta del temporizador (gate operation)[cite: 12].
- [cite_start]Ajustes de pre-escalador seleccionables (1:1, 1:8, 1:64, 1:256)[cite: 12].
- [cite_start]Funcionamiento durante los modos Idle y Sleep de la CPU[cite: 12].
- [cite_start]Interrupción al coincidir con el registro de periodo de 16 bits (PR1)[cite: 12].

---

## 13.0 Timer2/3, Timer4/5, Timer6/7 y Timer8/9

[cite_start]Estos módulos son temporizadores de 32 bits que también pueden configurarse como ocho temporizadores independientes de 16 bits[cite: 13].

### Modos de funcionamiento de 32 bits:

- [cite_start]**Dos temporizadores independientes de 16 bits:** Por ejemplo, Timer2 y Timer3 trabajando por separado[cite: 13].
- [cite_start]**Temporizador único de 32 bits:** Combina dos módulos para conteos largos[cite: 13].
- [cite_start]**Contador síncrono único de 32 bits**[cite: 13].

### Funcionalidades adicionales:

- [cite_start]**Disparador de eventos ADC:** Los temporizadores pueden iniciar automáticamente una conversión analógica-digital (Timer2/3 para ADC1 y Timer4/5 para ADC2)[cite: 13].
- [cite_start]**Base de tiempo para Captura e Interrupción:** Sirven como referencia de tiempo para los módulos de Input Capture y Output Compare[cite: 13].

---

### Registro de Control T1CON (Resumen)

- **TON (bit 15):** 1 = Inicia el Timer; [cite_start]0 = Detiene el Timer[cite: 12].
- [cite_start]**TSIDL (bit 13):** Controla si el temporizador se detiene o continúa en modo Idle[cite: 12].
- [cite_start]**TCKPS<1:0> (bits 5-4):** Selecciona el pre-escalador (división de frecuencia)[cite: 12].
- [cite_start]**TCS (bit 1):** Selecciona la fuente de reloj (interna $F_{CY}$ o externa por el pin T1CK)[cite: 12].

---

Esta es la traducción de la **Sección 14.0: Captura de Entrada (Input Capture)**. Esta función es vital para medir la duración de pulsos, periodos de señales externas o para capturar el tiempo exacto en que ocurre un evento.

---

## 14.0 Captura de Entrada (Input Capture)

El módulo de Captura de Entrada se utiliza para capturar un valor del temporizador (Timer) ante un evento en un pin de entrada. Es ideal para aplicaciones que requieren mediciones de frecuencia, ciclo de trabajo o intervalos de tiempo.

### 14.1 Características principales

- **Fuentes de tiempo:** Se puede seleccionar entre el Timer2 o el Timer3 como base de tiempo.
- **Modos de captura:**
  - Captura en cada borde descendente.
  - Captura en cada borde ascendente.
  - Captura en cada 4º borde ascendente.
  - Captura en cada 16º borde ascendente.
  - Captura en cada borde (ascendente y descendente).
- **FIFO de hardware:** Posee un búfer FIFO de hasta 4 niveles para almacenar las capturas antes de que la CPU necesite leerlas.
- **Generación de interrupciones:** Se puede configurar para generar una interrupción después de 1, 2, 3 o 4 eventos de captura.

### 14.2 Funcionamiento del Módulo

Cuando ocurre un evento en el pin **ICx** (donde 'x' es el número del módulo), el valor del temporizador seleccionado se copia en el registro **ICxBUF**. Si el búfer se llena y ocurre otra captura, se genera una condición de desbordamiento, aunque el módulo sigue funcionando.

### 14.3 Registro de Control ICxCON (Resumen)

- **ICSIDL (bit 13):** Controla si el módulo se detiene en modo _Idle_.
- **ICTMR (bit 7):** Selecciona la base de tiempo (0 = Timer3, 1 = Timer2).
- **ICI<1:0> (bits 6-5):** Determina cuántas capturas deben ocurrir antes de disparar la interrupción.
- **ICBNE (bit 3):** Bit de solo lectura que indica si el búfer FIFO no está vacío.
- **ICM<2:0> (bits 2-0):** Selecciona el modo de captura (ej. 011 para cada borde ascendente, 000 para desactivar).

---

Esta es la traducción de la **Sección 15.0: Comparación de Salida (Output Compare)**. Este módulo es fundamental para generar señales de control, como el ancho de pulso modulado (**PWM**), utilizado habitualmente para controlar motores, luces o para la conversión digital a analógica.

---

## 15.0 Comparación de Salida (Output Compare)

El módulo de Comparación de Salida se utiliza para generar señales de salida controladas por tiempo. Compara constantemente el valor de un temporizador seleccionado con el valor de uno o dos registros de comparación.

### 15.1 Características Principales

- **Modos de funcionamiento:**
  - **Single Shot:** Genera un único pulso.
  - **Continuous Pulse:** Genera un tren de pulsos continuo.
  - **PWM:** Genera señales de modulación por ancho de pulso con o sin pines de falla.
- **Fuentes de tiempo:** Puede utilizar el **Timer2** o el **Timer3** como base de tiempo de 16 bits.
- **Resolución:** Alta precisión en la generación de flancos de señal.

### 15.2 Modulación por Ancho de Pulso (PWM)

En el modo PWM, el módulo utiliza el registro **OCxRS** para determinar el ciclo de trabajo (Duty Cycle) y el registro de periodo del Timer para determinar la frecuencia de la señal.

- El pin de salida se pone en 'alto' cuando el temporizador inicia.
- El pin de salida se pone en 'bajo' cuando el temporizador coincide con el registro de comparación.

### 15.3 Registros de Control OCxCON (Resumen)

- **OCSIDL (bit 13):** Detiene el módulo cuando la CPU entra en modo _Idle_.
- **OCTSEL (bit 3):** Selecciona el temporizador (0 = Timer2, 1 = Timer3).
- **OCM<2:0> (bits 2-0):** Selecciona el modo de comparación:
  - `110`: Modo PWM sin protección de pin de falla.
  - `111`: Modo PWM con protección de pin de falla (el pin se apaga si se detecta un error externo).
  - `001`: Genera un flanco de subida al coincidir.
  - `010`: Genera un flanco de bajada al coincidir.

---

Esta es la traducción de la **Sección 16.0: Interfaz de Bus Serial (SPI)**. [cite_start]Este módulo es una interfaz síncrona esencial para comunicar el dsPIC33F con periféricos externos como memorias EEPROM, registros de desplazamiento, controladores de pantalla o convertidores ADC/DAC externos[cite: 14].

---

## 16.0 Interfaz de Bus Serial (SPI)

[cite_start]El módulo SPI permite la comunicación serial síncrona con otros dispositivos periféricos o microcontroladores[cite: 14]. [cite_start]Es totalmente compatible con los protocolos SPI y SIOP de Motorola®[cite: 14].

### 16.1 Estructura del Módulo

[cite_start]Cada módulo SPI consta de los siguientes componentes clave[cite: 14]:

- [cite_start]**SPIxSR:** Un registro de desplazamiento de 16 bits que se encarga de mover los datos hacia adentro y hacia afuera del chip[cite: 14].
- [cite_start]**SPIxBUF:** Un registro de búfer donde el software lee los datos recibidos o escribe los datos que se van a enviar[cite: 14].
- [cite_start]**SPIxCON1 / SPIxCON2:** Registros para configurar el modo de operación, la velocidad y el formato de los datos[cite: 14, 15].
- [cite_start]**SPIxSTAT:** Registro de estado que indica si el búfer está lleno, si hay errores o si la transmisión ha finalizado[cite: 14].

### 16.2 Pines de la Interfaz

[cite_start]El bus utiliza hasta 4 pines para su funcionamiento[cite: 6, 14]:

1.  [cite_start]**SDIx (Serial Data Input):** Entrada de datos seriales[cite: 6, 14].
2.  [cite_start]**SDOx (Serial Data Output):** Salida de datos seriales[cite: 6, 14].
3.  [cite_start]**SCKx (Serial Clock):** Reloj síncrono que puede actuar como entrada (modo esclavo) o salida (modo maestro)[cite: 6, 14].
4.  [cite_start]**SSx (Slave Select):** Pin de selección de esclavo o pulso de trama, opcional según la configuración[cite: 6, 14].

### 16.3 Características Destacadas

- [cite_start]**Soporte de datos:** Puede trabajar con palabras de **8 bits** o **16 bits**[cite: 4].
- [cite_start]**Modos Maestro y Esclavo:** El dispositivo puede iniciar la comunicación o responder a un maestro externo[cite: 14].
- [cite_start]**Reloj configurable:** Permite ajustar la polaridad y la fase del reloj para adaptarse a diferentes dispositivos periféricos[cite: 4].
- [cite_start]**Modo Framed:** Incluye soporte para interfaces tipo códec mediante señales de sincronización de trama[cite: 4, 15].

### 16.4 Interrupciones

[cite_start]El módulo puede generar dos tipos de interrupciones[cite: 10]:

- [cite_start]**SPI1 / SPI2:** Se activa cuando una transferencia de datos se ha completado con éxito[cite: 10].
- [cite_start]**SPI1E / SPI2E:** Se activa si ocurre un error, como un desbordamiento del búfer de recepción (cuando llega un dato nuevo antes de leer el anterior)[cite: 10].

---

Esta es la traducción de la **Sección 17.0: Interfaz I2C (Inter-Integrated Circuit)**. El protocolo I2C es fundamental para la comunicación con sensores, memorias EEPROM y otros integrados mediante solo dos cables.

---

## 17.0 Interfaz I2C™

El módulo Inter-Integrated Circuit (I2C) ofrece soporte completo para la comunicación en bus serial de 2 cables. El dsPIC33F puede funcionar tanto como **Maestro (Master)** como **Esclavo (Slave)**.

### 17.1 Características Principales

- **Soporte de velocidad:** Funciona a 100 kHz (Estándar), 400 kHz (Rápido) y 1 MHz.
- **Direccionamiento:** Soporta direcciones de 7 bits y 10 bits.
- **Multimaestro:** Capacidad para manejar colisiones y arbitraje en buses con varios maestros.
- **Ahorro de energía:** El módulo puede despertar a la CPU del modo _Sleep_ tras detectar una coincidencia de dirección en modo esclavo.
- **SMBus:** Compatible con los niveles lógicos de SMBus.

### 17.2 Componentes del Bus

El bus I2C utiliza dos pines de drenador abierto (requieren resistencias de pull-up externas):

1.  **SCLx (Serial Clock):** Pin de reloj síncrono.
2.  **SDAx (Serial Data):** Pin de datos seriales bidireccionales.

### 17.3 Registros de Control I2Cx

- **I2CxCON:** Configura el funcionamiento general (habilitación, modo maestro/esclavo, control de ACK).
- **I2CxSTAT:** Contiene bits de estado críticos como detección de bit de START/STOP, colisión de bus o si el búfer está lleno.
- **I2CxMSK:** Registro de máscara de dirección (permite al esclavo responder a un rango de direcciones).
- **I2CxBRG:** Registro del generador de velocidad de baudios (Baud Rate Generator) para definir la frecuencia del reloj en modo maestro.

### 17.4 Operaciones de Hardware

El hardware gestiona automáticamente los protocolos de bajo nivel, incluyendo:

- Generación de condiciones de **Inicio (Start)**, **Reinicio (Repeat Start)** y **Parada (Stop)**.
- Generación y detección de bits de **Acknowledge (ACK/NACK)**.
- Estiramiento del reloj (Clock Stretching) en modo esclavo para dar tiempo a la CPU a procesar datos.

---

Esta es la traducción de la **Sección 18.0: Transmisor Receptor Asíncrono Universal (UART)**. Este módulo es uno de los más utilizados para la comunicación con PC (vía RS-232 o USB-Serial), módulos Bluetooth, GPS y otros microcontroladores.

---

## 18.0 Transmisor Receptor Asíncrono Universal (UART)

El módulo UART es una interfaz de comunicación serial full-duplex (transmisión y recepción simultánea). Los dispositivos dsPIC33F pueden incluir hasta dos módulos UART independientes.

### 18.1 Características Principales

- **Velocidad de Baudios:** Generador de 16 bits dedicado que permite una amplia gama de velocidades (desde unos pocos bits por segundo hasta varios Mbps).
- **Formatos de Datos:** Soporta datos de 8 o 9 bits, con o sin paridad (par, impar o ninguna) y con 1 o 2 bits de parada (Stop bits).
- **Detección de Errores:** Identificación por hardware de errores de paridad, de trama (Framing Error) y de desbordamiento (Overrun Error).
- **Soporte de Bus LIN:** Capacidad de enviar y detectar caracteres de "Break" para redes LIN 1.2 y 2.0.
- **Protocolo IrDA®:** Codificador y decodificador integrado para comunicación por infrarrojos.
- **Control de Flujo:** Soporte por hardware para los pines de control **UxRTS** (Ready-to-Send) y **UxCTS** (Clear-to-Send).

### 18.2 Búferes FIFO

Para reducir la carga de la CPU, el UART incluye:

- Un búfer de transmisión (TX) de **4 niveles**.
- Un búfer de recepción (RX) de **4 niveles**.
  Esto permite que el chip envíe o reciba hasta 4 bytes antes de que la CPU tenga que intervenir para cargar o leer más datos.

### 18.3 Registros de Control UART

- **UxMODE:** Configura la habilitación del módulo, el formato de datos, el número de bits de parada, el modo de bajo consumo y la operación IrDA.
- **UxSTA:** Registro de estado y control de interrupciones. Aquí se activan/desactivan las transmisiones y se monitorean los errores de comunicación.
- **UxBRG:** Registro del generador de velocidad de baudios. Determina la velocidad de transferencia basada en el reloj del sistema.
- **UxTXREG / UxRXREG:** Registros donde se escriben los datos a enviar y se leen los datos recibidos, respectivamente.

### 18.4 Modos de Alta Velocidad

El dsPIC33F tiene un bit llamado **BRGH** en el registro UxMODE. Si se activa, el generador de baudios funciona a una frecuencia 4 veces mayor de lo normal, lo que permite alcanzar velocidades de comunicación extremadamente altas, ideales para aplicaciones que requieren un gran ancho de banda.

---

Esta es la traducción de la **Sección 19.0: Módulo CAN Mejorado (ECAN™)**. [cite_start]Este módulo es vital para comunicaciones robustas en entornos con mucho ruido eléctrico, siendo el estándar en la industria automotriz e industrial[cite: 11].

---

## 19.0 Módulo CAN Mejorado (ECAN™)

[cite_start]El módulo de Red de Área de Controlador Mejorado (ECAN) es una interfaz serial diseñada para permitir la comunicación entre módulos CAN o microcontroladores en entornos ruidosos[cite: 11]. [cite_start]Los dispositivos dsPIC33F pueden contener hasta dos módulos ECAN que implementan el protocolo CAN 2.0 A/B[cite: 11].

### 19.1 Características Principales

- [cite_start]**Protocolos soportados:** Implementación completa de CAN 1.2, 2.0A, 2.0B Pasivo y 2.0B Activo[cite: 11].
- [cite_start]**Tramas de datos:** Soporta tramas estándar y extendidas con longitudes de datos de 0 a 8 bytes[cite: 11].
- [cite_start]**Velocidad de bits:** Programable hasta **1 Mbit/seg**[cite: 11].
- **Búferes de Mensajes:**
  - [cite_start]Hasta **8 búferes de transmisión** con priorización programable[cite: 11].
  - [cite_start]Hasta **32 búferes de recepción**[cite: 11].
- [cite_start]**Filtros y Máscaras:** Incluye 16 filtros de aceptación completa y 3 máscaras para identificar qué mensajes deben ser recibidos[cite: 11].
- [cite_start]**Soporte DMA:** Permite el uso de un modo FIFO mediante el acceso directo a memoria (DMA), lo que reduce drásticamente la carga de la CPU[cite: 11].
- [cite_start]**Modo Loopback:** Permite realizar auto-pruebas internas del funcionamiento del módulo sin estar conectado al bus físico[cite: 11, 12].

### 19.2 Modos de Operación

[cite_start]El módulo puede configurarse en varios modos mediante el registro **CiCTRL1**[cite: 12]:

1.  **Modo Normal:** Operación estándar en el bus.
2.  **Modo de Deshabilitación:** El módulo se apaga para ahorrar energía.
3.  **Modo Loopback:** Para pruebas internas.
4.  **Modo Listen Only:** El módulo recibe mensajes pero no envía ni reconoce (ACK), útil para monitoreo de bus sin interferir.
5.  **Modo Listen All Messages:** Recibe todos los mensajes válidos independientemente de los filtros.
6.  **Modo de Configuración:** Necesario para cambiar parámetros críticos como la velocidad de baudios.

### 19.3 Registros de Control Clave

- [cite_start]**CiCTRL1 y CiCTRL2:** Controlan los modos de operación y funciones de aborto de transmisión[cite: 12, 18].
- [cite_start]**CiCFG1 y CiCFG2:** Registros de configuración de la velocidad de baudios y sincronización del tiempo de bit[cite: 18].
- [cite_start]**CiFEN1:** Habilita o deshabilita los filtros de aceptación[cite: 13, 18].
- [cite_start]**CiINTF / CiINTE:** Banderas y habilitación de interrupciones (errores, recepción de mensajes, búfer lleno, etc.)[cite: 18].
- [cite_start]**CiRXFUL1/2:** Indican qué búferes de recepción contienen datos nuevos[cite: 18].

---

Esta es la traducción de la **Sección 20.0: Interfaz del Convertidor de Datos (DCI)**. Este módulo es bastante específico y potente, diseñado para manejar flujos de datos de audio y comunicación con chips DSP externos.

---

## 20.0 Interfaz del Convertidor de Datos (DCI)

El módulo de Interfaz del Convertidor de Datos (DCI) permite la conexión del dsPIC33F con dispositivos externos como códecs de audio (por ejemplo, los usados en telefonía o sonido de alta fidelidad), chips ADC/DAC multicanal y otros procesadores de señales digitales.

### 20.1 Características Principales

- **Protocolos Soportados:** Totalmente compatible con los estándares industriales **I2S**, **AC'97** y protocolos de multiplexación por división de tiempo (TDM).
- **Control de Trama (Frame):** Soporta tramas de hasta 16 palabras de datos.
- **Tamaño de Palabra:** Configurable para 8, 10, 12 o 16 bits de ancho.
- **Canales:** Capacidad para manejar hasta 16 canales de datos de forma multiplexada.
- **Búferes:** Posee registros de búfer de transmisión y recepción de 4 niveles para reducir la carga de la CPU.

### 20.2 Pines del Módulo DCI

El módulo utiliza cuatro pines para la comunicación:

1.  **CSCK (Serial Clock):** El reloj de datos bidireccional.
2.  **CSDO (Serial Data Output):** Salida de datos seriales hacia el códec.
3.  **CSDI (Serial Data Input):** Entrada de datos seriales desde el códec.
4.  **COFS (Frame Sync):** Señal de sincronización que marca el inicio de una trama de datos.

### 20.3 Funcionamiento con Cómputo DSP

El DCI es especialmente útil cuando se trabaja con el motor DSP del dsPIC, ya que permite recibir datos de audio, procesarlos en tiempo real (aplicando filtros, por ejemplo) y enviarlos de vuelta al códec sin introducir retardos significativos de sincronización.

### 20.4 Registros de Control

- **DCICON1:** Configura el modo de operación (Maestro/Esclavo), el formato de los datos y el protocolo (I2S, AC'97 o TDM).
- **DCICON2:** Define la longitud de la palabra de datos y el número de palabras por trama.
- **DCISTAT:** Registro de estado para verificar si el búfer está lleno, vacío o si ha ocurrido un error de sincronización.
- **RSCON / TSCON:** Registros de control de ranura (Slot) que permiten habilitar o deshabilitar canales específicos dentro de una trama.

---

Esta es la traducción de la **Sección 21.0: Convertidor Analógico a Digital (ADC)**. Este módulo es uno de los más potentes y complejos, ya que permite al microprocesador "leer" voltajes del mundo real.

---

## 21.0 Convertidor Analógico a Digital (ADC) de 10/12 bits

El módulo ADC de los dispositivos dsPIC33F puede configurarse como un convertidor de **10 bits y 1.1 Msps** (muestras por segundo) de alta velocidad, o como un convertidor de **12 bits y 500 ksps** de alta resolución.

### 21.1 Características principales

- **Resolución:** Seleccionable entre 10 bits o 12 bits.
- **Canales de entrada:** Hasta 32 canales de entrada analógica.
- **Muestreo simultáneo:** Puede muestrear hasta 4 entradas simultáneamente (en modo de 10 bits).
- **Muestreo y Conversión Automática:** El hardware puede encargarse de todo el proceso de muestreo y conversión sin intervención de la CPU.
- **Búfer de resultados:** Dispone de un búfer de 16 palabras para almacenar los resultados de las conversiones.
- **Referencia de voltaje:** Se puede usar el voltaje de alimentación (VDD/VSS) o referencias externas en los pines VREF+/VREF-.

### 21.2 Diferencias entre modos

1.  **Modo de 10 bits:**
    - Velocidad máxima de 1.1 millones de muestras por segundo (Msps).
    - 4 amplificadores de muestreo y retención (Sample-and-Hold).
    - Ideal para aplicaciones de control de motores de alta velocidad o fuentes de alimentación conmutadas.
2.  **Modo de 12 bits:**
    - Velocidad máxima de 500 mil muestras por segundo (ksps).
    - 1 amplificador de muestreo y retención.
    - Ideal para aplicaciones que requieren mayor precisión, como sensores industriales o instrumentación médica.

### 21.3 Registros de Control Clave

- **ADxCON1:** Configura el modo de operación (10/12 bits), el formato de los datos (entero, fraccionario, etc.) y cómo se inicia la conversión.
- **ADxCON2:** Controla la referencia de voltaje, el escaneo de canales y la interrupción tras un número determinado de conversiones.
- **ADxCON3:** Define el tiempo de muestreo y la fuente de reloj del ADC.
- **ADxCHS0/ADxCHS123:** Registros de selección de canales de entrada analógica.
- **ADxPCFGL/H:** Configuran si un pin se usará como entrada analógica o como entrada/salida digital.

### 21.4 Soporte para DMA

El ADC está diseñado para trabajar en conjunto con el controlador DMA. Esto permite que el ADC llene automáticamente una tabla en la memoria RAM con las lecturas de los sensores, generando una interrupción solo cuando se ha recolectado una cantidad significativa de datos, lo que ahorra mucho tiempo de procesamiento.

---

## 22.0 Módulo Comparador y Referencia de Voltaje

Este módulo permite comparar señales analógicas sin usar el ADC, lo cual es mucho más rápido.

### 22.1 Comparadores Analógicos

El dispositivo incluye comparadores que pueden:

- Comparar dos voltajes externos.
- Comparar un voltaje externo contra una referencia interna programable.
- Generar una interrupción o un evento de Reset cuando una señal cruza un umbral.
- **Uso común:** Detección de sobrecorriente o detección de cruce por cero en fuentes de poder.

### 22.2 Referencia de Voltaje (CVREF)

Es un convertidor digital a analógico (DAC) interno muy básico de 16 pasos.

- Se utiliza principalmente para proporcionar un voltaje de comparación al módulo comparador.
- Se puede configurar para que el voltaje de referencia salga por un pin externo y alimentar otros componentes de tu placa.

---

## 22.3 Reloj de Tiempo Real y Calendario (RTCC)

_(Nota: Algunos modelos del dsPIC33F incluyen este módulo específico)_.

Este módulo mantiene la hora y la fecha con compensación de años bisiestos.

- **Funcionamiento:** Utiliza el oscilador secundario externo de 32.768 kHz.
- **Alarma:** Puede generar interrupciones basadas en segundos, minutos, horas, días o meses.
- **Seguridad:** Tiene una secuencia de desbloqueo especial para evitar que el software cambie la hora accidentalmente.

---

Esta es la traducción de la **Sección 23.0: Resumen del Conjunto de Instrucciones**. Esta parte explica cómo se estructuran las órdenes que la CPU ejecuta y qué tipos de operaciones puede realizar.

---

## 23.0 Resumen del Conjunto de Instrucciones

El conjunto de instrucciones del dsPIC33F está diseñado para ofrecer un rendimiento óptimo en aplicaciones de control y procesamiento digital de señales (DSP), siendo altamente eficiente para el uso de compiladores de lenguaje C.

### 23.1 Estructura de las Instrucciones

- **Tamaño:** Todas las instrucciones tienen un ancho de **24 bits**.
- **Ejecución:** La mayoría de las instrucciones se ejecutan en un **solo ciclo de instrucción**.
- **Instrucciones de flujo:** Las instrucciones que alteran el Contador de Programa (como saltos `GOTO`, llamadas a subrutina `CALL` o retornos `RETURN`) requieren dos ciclos para completarse.
- **Tipos de datos:** Soporta operaciones con bytes (8 bits) y palabras (16 bits).

### 23.2 Tipos de Operaciones

El conjunto de instrucciones se divide en dos grandes grupos:

#### 1. Instrucciones de MCU (Microcontrolador):

- **Aritméticas:** Suma, resta, multiplicación y división de enteros.
- **Lógicas:** AND, OR, XOR, NOT y desplazamientos de bits.
- **Movimiento de datos:** Transferencia entre registros de trabajo (W) y memoria de datos.
- **Control de flujo:** Saltos condicionales e incondicionales.

#### 2. Instrucciones DSP (Procesamiento Digital de Señales):

Estas instrucciones aprovechan el hardware especializado para realizar cálculos matemáticos complejos rápidamente:

- **MAC (Multiply and Accumulate):** Realiza una multiplicación y suma el resultado a uno de los acumuladores de 40 bits en un solo ciclo.
- **Lecturas duales:** Permite leer dos operandos de la memoria simultáneamente (uno de la memoria X y otro de la Y).
- **Escalado y Redondeo:** Instrucciones específicas para gestionar datos fraccionarios y evitar errores de precisión.

### 23.3 Modos de Direccionamiento

El dsPIC33F ofrece una gran flexibilidad para acceder a los datos:

- **Literal:** El valor está incluido en la propia instrucción.
- **Directo:** Se especifica la dirección de memoria.
- **Indirecto:** Se utiliza un registro W como puntero a la dirección de memoria.
- **Con pre/post-incremento:** El puntero se actualiza automáticamente antes o después del acceso (ideal para recorrer arreglos o tablas).

---

**Nota:** El manual contiene una tabla detallada con las 83 instrucciones base. Si necesitas conocer la sintaxis de una instrucción en particular (como `ADD`, `MOV` o `MPY`), dímelo.

---

Esta es la traducción de la **Sección 24.0: Características Especiales**, que trata sobre la configuración interna, la protección de seguridad del código y los mecanismos de seguridad del procesador.

---

## 24.0 Características Especiales

Los dispositivos dsPIC33F incluyen una serie de características diseñadas para maximizar la fiabilidad del sistema, minimizar el costo de los componentes externos y proporcionar protección de la propiedad intelectual.

### 24.1 Bits de Configuración

A diferencia de los registros normales, los bits de configuración se almacenan en la memoria de programa y se cargan al encender el dispositivo. Estos controlan aspectos críticos como:

- **Selección del Oscilador:** Define la fuente de reloj principal.
- **Watchdog Timer (WDT):** Habilita o deshabilita el temporizador de seguridad.
- **Protección de Código:** Evita la lectura no autorizada de la memoria Flash.
- **JTAG:** Habilita o deshabilita la interfaz de prueba JTAG.

### 24.2 Watchdog Timer (WDT)

El Perro Guardián es un temporizador que funciona con su propio oscilador interno de baja potencia (LPRC) de 32 kHz. Su función es reiniciar el dispositivo si el software se "congela" o entra en un bucle infinito.

- Para evitar un reinicio, el programador debe ejecutar la instrucción `CLRWDT` periódicamente.
- Tiene un pre-escalador y un post-escalador configurables para ajustar el tiempo de espera desde milisegundos hasta varios segundos.

### 24.3 Seguridad de Código CodeGuard™

Esta es una característica avanzada que permite dividir la memoria Flash en segmentos con diferentes niveles de protección:

1.  **Boot Segment (BS):** Para el cargador de arranque (bootloader).
2.  **Secure Segment (SS):** Para algoritmos propietarios o claves de cifrado.
3.  **General Segment (GS):** Para el resto del código de la aplicación.

Cada segmento puede tener permisos de lectura o escritura restringidos para evitar que un segmento acceda accidentalmente (o malintencionadamente) a otro.

### 24.4 In-Circuit Serial Programming™ (ICSP™)

Los dispositivos se pueden programar serialmente mientras están instalados en la placa final. Esto se hace a través de los pines de alimentación (VDD/VSS), el pin de reset (MCLR) y dos pines de datos/reloj (PGECx/PGEDx).

### 24.5 In-Circuit Debugger (ICD)

El dsPIC33F tiene lógica de depuración integrada. Al usar un programador compatible (como el MPLAB ICD), se pueden establecer puntos de interrupción (_breakpoints_), ejecutar el código paso a paso y observar el valor de todos los registros internos en tiempo real.

---

Esta sección es crucial para no "quemar" el chip y asegurar que el diseño de tu placa sea estable. El **Capítulo 26.0: Especificaciones Eléctricas** define los límites operativos y las características de consumo del dsPIC33F.

---

## 26.0 Especificaciones Eléctricas

Esta sección proporciona las características térmicas y eléctricas de los dispositivos. Es fundamental respetar los **Valores Máximos Absolutos**, ya que excederlos puede causar daños permanentes.

### 26.1 Valores Máximos Absolutos

- **Voltaje en VDD (con respecto a VSS):** -0.3V a +4.0V.
- **Voltaje en cualquier pin (que no sea 5V tolerante):** -0.3V a (VDD + 0.3V).
- **Voltaje en pines tolerantes a 5V:** -0.3V a +5.5V.
- **Corriente máxima de salida (por cualquier pin de I/O):** 4 mA (algunos modelos permiten hasta 8 mA).
- **Corriente total máxima por los pines de alimentación:** 250 mA.
- **Temperatura de almacenamiento:** -65°C a +150°C.

> **Advertencia:** La exposición prolongada a los valores máximos absolutos puede afectar la fiabilidad del dispositivo.

### 26.2 Condiciones de Operación DC

El dsPIC33F está diseñado para operar en los siguientes rangos:

- **Voltaje de operación (VDD):** 3.0V a 3.6V.
- **Temperatura ambiente de funcionamiento:**
  - Rango Industrial: -40°C a +85°C.
  - Rango Extendido: -40°C a +125°C.

### 26.3 Consumo de Corriente (IDD)

El consumo de energía depende directamente de la frecuencia de reloj ($F_{CY}$) y del voltaje.

- **Modo Operativo:** A 40 MIPS (máxima velocidad), el chip puede consumir aproximadamente **50-80 mA**, dependiendo de cuántos periféricos estén activos.
- **Modo Idle (Inactivo):** La CPU se detiene pero los periféricos siguen funcionando. El consumo baja significativamente (aprox. **15-25 mA**).
- **Modo Sleep (Sueño):** Todo se detiene excepto el regulador y el Watchdog (si está activo). El consumo cae a niveles de microamperios (**μA**), ideal para dispositivos a batería.

### 26.4 Características de los Pines de I/O

- **VIL (Voltaje de entrada nivel bajo):** Máximo 0.2 VDD.
- **VIH (Voltaje de entrada nivel alto):** Mínimo 0.8 VDD.
- **VOL (Voltaje de salida nivel bajo):** Máximo 0.4V cuando drena corriente nominal.
- **VOH (Voltaje de salida nivel alto):** Mínimo 2.4V (para VDD = 3.3V).

### 26.5 Regulador de Voltaje Interno

El núcleo del dsPIC33F (Core) funciona internamente a **2.5V**. El chip incluye un regulador de voltaje (LDO) que convierte los 3.3V de entrada a los 2.5V necesarios.

- **Importante:** Se requiere un condensador cerámico de baja ESR (típicamente **10 μF**) conectado entre el pin **VCAP** y **VSS** para estabilizar este regulador interno.

---



Nemónico,Operandos,Descripción,Ciclos
MOV,"f, Wnd",Mueve el contenido de la dirección de memoria 'f' al registro de trabajo 'Wnd'.,1
MOV,"Wns, f",Mueve el contenido del registro 'Wns' a la dirección de memoria 'f'.,1
ADD,"Wb, Ws, Wd",Suma 'Wb' mas 'Ws' y guarda el resultado en 'Wd'.,1
SUB,"Wb, Ws, Wd",Resta 'Ws' de 'Wb' y guarda el resultado en 'Wd'.,1
BRA,Expr,Salto incondicional a la dirección 'Expr'.,2
BTSC,"Ws, #bit",Prueba el bit '#bit' en 'Ws'; salta la siguiente instrucción si es '0'.,1 (2 si salta)
BTSS,"Ws, #bit",Prueba el bit '#bit' en 'Ws'; salta la siguiente instrucción si es '1'.,1 (2 si salta)
GOTO,Expr,Salto incondicional a la dirección de 24 bits 'Expr'.,2
CALL,Expr,Llama a la subrutina en la dirección 'Expr'.,2
RETURN,,Retorna de una subrutina.,2
BSET,"f, #bit",Pone a '1' el bit '#bit' en la dirección de memoria 'f'.,1
BCLR,"f, #bit",Pone a '0' el bit '#bit' en la dirección de memoria 'f'.,1
MPY,"Wm*Wn, Acc",(DSP) Multiplica Wm por Wn y suma el resultado al Acumulador Acc (40 bits).,1
MAC,"Wm*Wn, Acc","(DSP) Multiplica Wm por Wn, suma el resultado a Acc y realiza lecturas duales (X,Y).",1
DO,"#Expr, final",(DSP) Inicia un bucle de hardware que se repite 'Expr' veces hasta la dirección 'final'.,2
