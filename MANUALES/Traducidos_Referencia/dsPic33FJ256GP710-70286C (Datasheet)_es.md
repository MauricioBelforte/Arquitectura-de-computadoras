# Traducción de d:\Escritorio\INFORMATICA\ARQUITECTURA DE COMPUTADORAS\dsPic33FJ256GP710-70286C (Datasheet).pdf

© 2009 Microchip Technology Inc.
DS70286C
dsPIC33FJXXXGPX06/X08/X10
Hoja de datos
alto rendimiento,
Controladores de señal digitales de 16 bits

DS70286C-página ii 
© 2009 Microchip Technology Inc. 
Información contenida en esta publicación sobre el dispositivo. 
aplicaciones y similares se proporcionan sólo para su conveniencia 
y puede ser reemplazado por actualizaciones. Es tu responsabilidad 
asegúrese de que su aplicación cumpla con sus especificaciones. 
PASTILLA 
MARCAS 
NO 
REPRESENTACIONES 
O 
GARANTÍAS DE NINGÚN TIPO YA SEA EXPRESA O 
IMPLÍCITO, 
ESCRITO 
O 
ORAL, 
ESTATUTARIO 
O 
DE LO CONTRARIO, 
RELACIONADO 
A 
EL 
INFORMACIÓN, 
INCLUYENDO PERO NO LIMITADO A SU CONDICIÓN, 
CALIDAD, 
ACTUACIÓN, 
COMERCIABILIDAD 
O 
IDONEIDAD PARA EL PROPÓSITO. Microchip se exime de toda responsabilidad 
que surjan de esta información y su uso. Uso de microchip 
dispositivos en aplicaciones de soporte vital y/o seguridad está completamente en 
riesgo del comprador, y el comprador se compromete a defender, indemnizar y 
eximir de responsabilidad a Microchip de todos y cada uno de los daños, reclamaciones, 
demandas o gastos resultantes de dicho uso. No hay licencias 
transmitido, implícitamente o de otro modo, bajo cualquier Microchip 
derechos de propiedad intelectual. 
Marcas registradas 
El nombre y el logotipo de Microchip, el logotipo de Microchip, Accuron, 
dsPIC, KEELOQ, logotipo de KEELOQ, MPLAB, PIC, PICmicro, 
PICSTART, rfPIC, SmartShunt y UNI/O están registrados 
marcas comerciales de Microchip Technology Incorporated en el 
Estados Unidos y otros países. 
FilterLab, termistor activo lineal, MXDEV, MXLAB, 
SEEVAL, SmartSensor y las soluciones de control integradas 
La empresa son marcas registradas de Microchip Technology 
Constituida en EE.UU. 
Analógico para la era digital, Application Maestro, CodeGuard, 
dsPICDEM, dsPICDEM.net, dsPICworks, dsSPEAK, ECAN, 
ECONOMONITOR, FanSense, serie en circuito 
Programación, ICSP, ICEPIC, Mindi, MiWi, MPASM, MPLAB 
Logotipo certificado, MPLIB, MPLINK, mTouch, nanoWatt XLP, 
PICkit, PICDEM, PICDEM.net, PICtail, logotipo PIC32, PowerCal, 
PowerInfo, PowerMate, PowerTool, REAL ICE, rfLAB, Seleccionar 
Modo, Resistencia Total, TSHARC, WiperLock y ZENA son 
marcas comerciales de Microchip Technology Incorporated en el 
Estados Unidos y otros países. 
SQTP es una marca de servicio de Microchip Technology Incorporated 
en los EE.UU. 
Todas las demás marcas comerciales mencionadas en este documento son propiedad de sus 
respectivas empresas. 
© 2009, Microchip Technology Incorporated, Impreso en el 
EE.UU., todos los derechos reservados. 
Impreso en papel reciclado. 
Tenga en cuenta los siguientes detalles de la función de protección de código en dispositivos Microchip: 

> Error de traducción: •
Los productos Microchip cumplen con las especificaciones contenidas en su particular Hoja de Datos de Microchip. 

> Error de traducción: •
Microchip cree que su familia de productos es una de las más seguras de su tipo en el mercado hoy en día, cuando se utiliza en el 
forma prevista y en condiciones normales. 

> Error de traducción: •
Se utilizan métodos deshonestos y posiblemente ilegales para violar la función de protección del código. Todos estos métodos, a nuestra 
conocimiento, requieren el uso de los productos de Microchip de una manera fuera de las especificaciones operativas contenidas en los Datos de Microchip. 
Hojas. Lo más probable es que la persona que lo haga se dedique al robo de propiedad intelectual. 

> Error de traducción: •
Microchip está dispuesto a trabajar con el cliente que está preocupado por la integridad de su código. 

> Error de traducción: •
Ni Microchip ni ningún otro fabricante de semiconductores pueden garantizar la seguridad de su código. La protección del código no 
Esto significa que garantizamos que el producto es “irrompible”. 
La protección del código está en constante evolución. En Microchip estamos comprometidos a mejorar continuamente las funciones de protección de código de nuestro 
productos. Los intentos de violar la función de protección del código de Microchip pueden constituir una violación de la Ley de derechos de autor del milenio digital. Si tales actos 
permite el acceso no autorizado a su software u otro trabajo protegido por derechos de autor, es posible que tenga derecho a demandar para obtener reparación en virtud de esa Ley. 
Microchip recibió la certificación ISO/TS-16949:2002 para su 
sede, instalaciones de diseño y fabricación de obleas en Chandler y 
Tempe, Arizona; Gresham, Oregon y centros de diseño en California 
e India. Los procesos y procedimientos del sistema de calidad de la Compañía. 
son para sus MCU PIC® y DSC dsPIC®, salto de código KEELOQ® 
dispositivos, EEPROM seriales, microperiféricos, memoria no volátil y 
productos analógicos. Además, el sistema de calidad de Microchip para el diseño 
y la fabricación de sistemas de desarrollo cuenta con la certificación ISO 9001:2000. 

© 2009 Microchip Technology Inc.
DS70286C-página 1
dsPIC33FJXXXGPX06/X08/X10
Rango de operación:
• Funcionamiento de hasta 40 MIPS (a 3,0-3,6 V): 
- Rango de temperatura industrial 
(-40°C a +85°C)
CPU DSC de alto rendimiento:
• Arquitectura de Harvard modificada
• Conjunto de instrucciones optimizadas para el compilador de C
• Ruta de datos de 16 bits de ancho
• Instrucciones de 24 bits de ancho
• Memoria de programa lineal con direcciones de hasta 4 M 
palabras de instrucción
• Memoria de datos lineal con direcciones de hasta 64 Kbytes
• 83 instrucciones básicas: principalmente 1 palabra/1 ciclo
• Dieciséis registros de uso general de 16 bits
• Dos acumuladores de 40 bits:
- Con opciones de redondeo y saturación.
• Modos de direccionamiento flexibles y potentes:
- Indirecto, Módulo y Bit-Invertido
• Pila de software
• 16 x 16 operaciones de multiplicación fraccionaria/entera
• Operaciones de división 32/16 y 16/16
• Multiplicación y acumulación de ciclo único:
- Reescritura del acumulador para operaciones DSP
- Recuperación de datos dual
• Desplazamientos de hasta ±16 bits para datos de hasta 40 bits
Acceso directo a memoria (DMA):
• DMA de hardware de 8 canales:
• Área de buffer DMA de doble puerto de 2 Kbytes 
(DMA RAM) para almacenar datos transferidos a través de DMA:
- Permite la transferencia de datos entre la RAM y un 
periférico mientras la CPU está ejecutando código 
(sin robo de ciclo)
• La mayoría de los periféricos admiten DMA
Controlador de interrupción:
• Latencia de 5 ciclos
• Hasta 63 fuentes de interrupción disponibles
• Hasta cinco interrupciones externas
• Siete niveles de prioridad programables
• Cinco excepciones de procesador
E/S digitales:
• Hasta 85 pines de E/S digitales programables
• Activación/Interrupción al cambiar en hasta 24 pines
• Los pines de salida pueden conducir de 3,0 V a 3,6 V
• Todos los pines de entrada digital son tolerantes a 5V
• Disipador de 4 mA en todos los pines de E/S
Flash en chip y SRAM:
• Memoria flash para programas, hasta 256 Kbytes
• Datos SRAM, hasta 30 Kbytes (incluye 2 Kbytes 
de RAM DMA): 
Gestión del sistema:
• Opciones de reloj flexibles:
- Externo, cristal, resonador, RC interno
- PLL totalmente integrado
- PLL de fluctuación extremadamente baja
• Temporizador de encendido
• Temporizador/estabilizador de inicio del oscilador
• Temporizador de vigilancia con su propio oscilador RC
• Monitor de reloj a prueba de fallos
• Restablecer por múltiples fuentes
Gestión de energía:
• Regulador de voltaje de 2,5 V en chip
• Cambiar entre fuentes de reloj en tiempo real
• Modos inactivo, suspendido y dormido con despertador rápido
Temporizadores/Captura/Comparar/PWM:
• Temporizador/Contadores, hasta nueve temporizadores de 16 bits:
- Puede emparejarse para crear cuatro temporizadores de 32 bits
- 1 temporizador funciona como reloj en tiempo real con externo 
Oscilador de 32,768 kHz
- Preescalador programable
• Captura de entrada (hasta ocho canales):
- Capture hacia arriba, hacia abajo o en ambos bordes
- Funciones de entrada de captura de 16 bits
- FIFO de 4 profundidades en cada captura
• Comparación de salida (hasta ocho canales):
- Modo de comparación simple o dual de 16 bits
- Modo PWM sin fallos de 16 bits
Controladores de señal digital de 16 bits de alto rendimiento

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 2
© 2009 Microchip Technology Inc.
Módulos de comunicación:
• SPI de 3 hilos (hasta dos módulos):
- El marco admite una interfaz de E/S sencilla 
códecs
- Admite datos de 8 y 16 bits
- Admite todos los formatos de reloj en serie y 
modos de muestreo
• I2C™ (hasta dos módulos):
- Compatibilidad total con el modo esclavo multimaestro
- Direccionamiento de 7 y 10 bits
- Detección y arbitraje de colisiones de autobuses.
- Acondicionamiento de señal integrado
- Enmascaramiento de dirección de esclavo
• UART (hasta dos módulos):
- Interrupción al detectar el bit de dirección
- Interrupción por error de UART
- Despertar en el bit de inicio desde el modo de suspensión
- Búfers FIFO TX y RX de 4 caracteres
- Soporte de autobús LIN
- Codificación y decodificación IrDA® en hardware
- Modo baudios de alta velocidad
- Control de flujo de hardware con CTS y RTS
• Módulo de interfaz de convertidor de datos (DCI):
- Interfaz de códec
- Soporta protocolos I2S y AC'97
- Hasta palabras de datos de 16 bits, hasta 16 palabras por 
marco
- Búferes TX y RX de profundidad de 4 palabras
• CAN mejorado (módulo ECAN™) 2.0B activo 
(hasta 2 módulos):
- Hasta ocho buffers de transmisión y hasta 32 buffers de recepción 
- 16 filtros de recepción y tres máscaras.
- Bucle invertido, escuchar solo y escuchar todo 
Modos de mensajes para diagnóstico y bus. 
monitoreo
- Despertar con mensaje CAN
- Procesamiento automático de Remoto 
Solicitudes de transmisión
- Modo FIFO usando DMA
- Soporte de direccionamiento DeviceNet™
Convertidores analógicos a digitales (ADC):
• Hasta dos módulos ADC en un dispositivo
• Conversión de 10 bits, 1,1 Msps o 12 bits, 500 ksps:
- Dos, cuatro u ocho muestras simultáneas
- Hasta 32 canales de entrada con escaneo automático
- El inicio de la conversión puede ser manual o 
sincronizado con una de las cuatro fuentes de disparo
- Conversión posible en modo de suspensión
- ±1 LSb máx. no linealidad integral
- ±1 LSb máx. no linealidad diferencial
Tecnología de flash CMOS:
• Tecnología Flash de baja potencia y alta velocidad
• Diseño completamente estático
• Voltaje de funcionamiento de 3,3 V (±10 %)
• Temperatura industrial
• Bajo consumo de energía
Embalaje:
• TQFP de 100 pines (14x14x1 mm y 12x12x1 mm)
• TQFP de 80 pines (12x12x1 mm)
• TQFP de 64 pines (10x10x1 mm)
 
Nota:
Consulte las tablas de variantes del dispositivo para obtener información exacta.
características periféricas por dispositivo.

© 2009 Microchip Technology Inc.
DS70286C-página 3
dsPIC33FJXXXGPX06/X08/X10
FAMILIAS DE PRODUCTOS dsPIC33F
La familia de dispositivos de uso general dsPIC33F
Son ideales para una amplia variedad de MCU integrados de 16 bits.
aplicaciones. Los controladores con interfaces de códec son
bien adaptado 
para 
discurso 
y 
sonido 
procesamiento
aplicaciones.
Los nombres de los dispositivos, número de pines, tamaños de memoria y
La disponibilidad periférica de cada familia se enumera a continuación,
seguido de sus diagramas de distribución de pines.
Controladores de la familia de uso general dsPIC33F
Dispositivo
Pines
Programa 
destello 
Memoria 
(Kbytes)
RAM
(Kbytes)(1)
Temporizador de 16 bits
Captura de entrada
Comparación de salida
Estándar PWM
Códec
Interfaz
CAD
UART
SPI
I2C™
Mejorado
CAN™
Pines de E/S (máx.)(2)
Paquetes
dsPIC33FJ64GP206
64
64
8
9
8
8
1
1 ADC, 18 
ch
2
2
1
0
53
PT
dsPIC33FJ64GP306
64
64
16
9
8
8
1
1 ADC, 18 
ch
2
2
2
0
53
PT
dsPIC33FJ64GP310
100
64
16
9
8
8
1
1 CAD, 32 
ch
2
2
2
0
85
FP, PT
dsPIC33FJ64GP706
64
64
16
9
8
8
1
2 CAD, 18 
ch
2
2
2
2
53
PT
dsPIC33FJ64GP708
80
64
16
9
8
8
1
2 CAD, 24 
ch
2
2
2
2
69
PT
dsPIC33FJ64GP710
100
64
16
9
8
8
1
2 CAD, 32 
ch
2
2
2
2
85
FP, PT
dsPIC33FJ128GP206
64
128
8
9
8
8
1
1 ADC, 18 
ch
2
2
1
0
53
PT
dsPIC33FJ128GP306
64
128
16
9
8
8
1
1 ADC, 18 
ch
2
2
2
0
53
PT
dsPIC33FJ128GP310
100
128
16
9
8
8
1
1 CAD, 32 
ch
2
2
2
0
85
FP, PT
dsPIC33FJ128GP706
64
128
16
9
8
8
1
2 CAD, 18 
ch
2
2
2
2
53
PT
dsPIC33FJ128GP708
80
128
16
9
8
8
1
2 CAD, 24 
ch
2
2
2
2
69
PT
dsPIC33FJ128GP710
100
128
16
9
8
8
1
2 CAD, 32 
ch
2
2
2
2
85
FP, PT
dsPIC33FJ256GP506
64
256
16
9
8
8
1
1 ADC, 18 
ch
2
2
2
1
53
PT
dsPIC33FJ256GP510
100
256
16
9
8
8
1
1 CAD, 32 
ch
2
2
2
1
85
FP, PT
dsPIC33FJ256GP710
100
256
30
9
8
8
1
2 CAD, 32 
ch
2
2
2
2
85
FP, PT
Nota
1:
El tamaño de la RAM incluye 2 Kbytes de RAM DMA.
2:
El número máximo de pines de E/S incluye pines compartidos por las funciones periféricas.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 4
© 2009 Microchip Technology Inc.
Diagramas de pines
TQFP de 64 pines
1
2
3
4
5
6
7
8
9
10
11
12
13
36
35
34
33
32
31
30
29
28
27
26
64
63
62
61
60
59
58
57
56
14
15
16
17
18
19
20
21
22
23
24
25
PGEC2/SOSCO/T1CK/CN0/RC14
PGED2/SOSCI/T4CK/CN1/RC13
OC1/RD0
IC4/INT4/RD11
IC2/U1CTS/INT2/RD9
IC1/INT1/RD8
VSS
OSC2/CLKO/RC15
OSC1/CLKIN/RC12
VDD
SCL1/RG2
U1RTS/SCK1/INT0/RF6
U1RX/SDI1/RF2
U1TX/SDO1/RF3
COFS/RG15
AN16/T2CK/T7CK/RC1
AN17/T3CK/T6CK/RC2
SCK2/CN8/RG6
SDI2/CN9/RG7
SDO2/CN10/RG8
MCLR
VSS
VDD
AN3/CN5/RB3
AN2/SS1/CN4/RB2
PGEC3/AN1/VREF-/CN3/RB1
PGED3/AN0/VREF+/CN2/RB0
OC8/CN16/RD7
CSDO/RG13
CSDI/RG12
CSCK/RG14
VCAP/VDDCORE
RG1
RF1
RG0
OC2/RD1
OC3/RD2
PGEC1/AN6/OCFA/RB6
PGED1/AN7/RB7
AVDD
AVSS
U2CTS/AN8/RB8
AN9/RB9
TMS/AN10/RB10
TDO/AN11/RB11
VSS
VDD
TCK/AN12/RB12
TDI/AN13/RB13
U2RTS/AN14/RB14
AN15/OCFB/CN12/RB15
U2TX/CN18/RF5
U2RX/CN17/RF4
SDA1/RG3
43
42
41
40
39
38
37
44
48
47
46
50
49
51
54
53
52
55
45
SS2/CN11/RG9
AN5/IC8/CN7/RB5
AN4/IC7/CN6/RB4
IC3/INT3/RD10
VDD
RF0
OC4/RD3
OC7/CN15/RD6
OC6/IC6/CN14/RD5
OC5/IC5/CN13/RD4
dsPIC33FJ64GP206
dsPIC33FJ128GP206
= Los pines son tolerantes hasta 5V

© 2009 Microchip Technology Inc.
DS70286C-página 5
dsPIC33FJXXXGPX06/X08/X10
Diagramas de pines (continuación)
TQFP de 64 pines
1
2
3
4
5
6
7
8
9
10
11
12
13
36
35
34
33
32
31
30
29
28
27
26
64
63
62
61
60
59
58
57
56
14
15
16
17
18
19
20
21
22
23
24
25
PGEC2/SOSCO/T1CK/CN0/RC14
PGED2/SOSCI/T4CK/CN1/RC13
OC1/RD0
IC4/INT4/RD11
IC2/U1CTS/INT2/RD9
IC1/INT1/RD8
VSS
OSC2/CLKO/RC15
OSC1/CLKIN/RC12
VDD
SCL1/RG2
U1RTS/SCK1/INT0/RF6
U1RX/SDI1/RF2
U1TX/SDO1/RF3
COFS/RG15
AN16/T2CK/T7CK/RC1
AN17/T3CK/T6CK/RC2
SCK2/CN8/RG6
SDI2/CN9/RG7
SDO2/CN10/RG8
MCLR
VSS
VDD
AN3/CN5/RB3
AN2/SS1/CN4/RB2
PGEC3/AN1/VREF-/CN3/RB1
PGED3/AN0/VREF+/CN2/RB0
OC8/CN16/RD7
CSDO/RG13
CSDI/RG12
CSCK/RG14
VCAP/VDDCORE
RG1
RF1
RG0
OC2/RD1
OC3/RD2
PGEC1/AN6/OCFA/RB6
PGED1/AN7/RB7
AVDD
AVSS
U2CTS/AN8/RB8
AN9/RB9
TMS/AN10/RB10
TDO/AN11/RB11
VSS
VDD
TCK/AN12/RB12
TDI/AN13/RB13
U2RTS/AN14/RB14
AN15/OCFB/CN12/RB15
U2TX/SCL2/CN18/RF5
U2RX/SDA2/CN17/RF4
SDA1/RG3
43
42
41
40
39
38
37
44
48
47
46
50
49
51
54
53
52
55
45
SS2/CN11/RG9
AN5/IC8/CN7/RB5
AN4/IC7/CN6/RB4
IC3/INT3/RD10
VDD
RF0
OC4/RD3
OC7/CN15/RD6
OC6/IC6/CN14/RD5
OC5/IC5/CN13/RD4
dsPIC33FJ64GP306
dsPIC33FJ128GP306
= Los pines son tolerantes hasta 5V

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 6
© 2009 Microchip Technology Inc.
Diagramas de pines (continuación)
TQFP de 64 pines
1
2
3
4
5
6
7
8
9
10
11
12
13
36
35
34
33
32
31
30
29
28
27
26
64
63
62
61
60
59
58
57
56
14
15
16
17
18
19
20
21
22
23
24
25
PGEC2/SOSCO/T1CK/CN0/RC14
PGED2/SOSCI/T4CK/CN1/RC13
OC1/RD0
IC4/INT4/RD11
IC2/U1CTS/INT2/RD9
IC1/INT1/RD8
VSS
OSC2/CLKO/RC15
OSC1/CLKIN/RC12
VDD
SCL1/RG2
U1RTS/SCK1/INT0/RF6
U1RX/SDI1/RF2
U1TX/SDO1/RF3
COFS/RG15
AN16/T2CK/T7CK/RC1
AN17/T3CK/T6CK/RC2
SCK2/CN8/RG6
SDI2/CN9/RG7
SDO2/CN10/RG8
MCLR
VSS
VDD
AN3/CN5/RB3
AN2/SS1/CN4/RB2
PGEC3/AN1/VREF-/CN3/RB1
PGED3/AN0/VREF+/CN2/RB0
OC8/CN16/RD7
CSDO/RG13
CSDI/RG12
CSCK/RG14
VCAP/VDDCORE
RG1
C1TX/RF1
RG0
OC2/RD1
OC3/RD2
PGEC1/AN6/OCFA/RB6
PGED1/AN7/RB7
AVDD
AVSS
U2CTS/AN8/RB8
AN9/RB9
TMS/AN10/RB10
TDO/AN11/RB11
VSS
VDD
TCK/AN12/RB12
TDI/AN13/RB13
U2RTS/AN14/RB14
AN15/OCFB/CN12/RB15
U2TX/SCL2/CN18/RF5
U2RX/SDA2/CN17/RF4
SDA1/RG3
43
42
41
40
39
38
37
44
48
47
46
50
49
51
54
53
52
55
45
SS2/CN11/RG9
AN5/IC8/CN7/RB5
AN4/IC7/CN6/RB4
IC3/INT3/RD10
VDD
C1RX/RF0
OC4/RD3
OC7/CN15/RD6
OC6/IC6/CN14/RD5
OC5/IC5/CN13/RD4
dsPIC33FJ256GP506
= Los pines son tolerantes hasta 5V

© 2009 Microchip Technology Inc.
DS70286C-página 7
dsPIC33FJXXXGPX06/X08/X10
Diagramas de pines (continuación)
TQFP de 64 pines
1
2
3
4
5
6
7
8
9
10
11
12
13
36
35
34
33
32
31
30
29
28
27
26
64
63
62
61
60
59
58
57
56
14
15
16
17
18
19
20
21
22
23
24
25
PGEC2/SOSCO/T1CK/CN0/RC14
PGED2/SOSCI/T4CK/CN1/RC13
OC1/RD0
IC4/INT4/RD11
IC2/U1CTS/INT2/RD9
IC1/INT1/RD8
VSS
OSC2/CLKO/RC15
OSC1/CLKIN/RC12
VDD
SCL1/RG2
U1RTS/SCK1/INT0/RF6
U1RX/SDI1/RF2
U1TX/SDO1/RF3
COFS/RG15
AN16/T2CK/T7CK/RC1
AN17/T3CK/T6CK/RC2
SCK2/CN8/RG6
SDI2/CN9/RG7
SDO2/CN10/RG8
MCLR
VSS
VDD
AN3/CN5/RB3
AN2/SS1/CN4/RB2
PGEC3/AN1/VREF-/CN3/RB1
PGED3/AN0/VREF+/CN2/RB0
OC8/CN16/RD7
CSDO/RG13
CSDI/RG12
CSCK/RG14
VCAP/VDDCORE
C2TX/RG1
C1TX/RF1
C2RX/RG0
OC2/RD1
OC3/RD2
PGEC1/AN6/OCFA/RB6
PGED1/AN7/RB7
AVDD
AVSS
U2CTS/AN8/RB8
AN9/RB9
TMS/AN10/RB10
TDO/AN11/RB11
VSS
VDD
TCK/AN12/RB12
TDI/AN13/RB13
U2RTS/AN14/RB14
AN15/OCFB/CN12/RB15
U2TX/SCL2/CN18/RF5
U2RX/SDA2/CN17/RF4
SDA1/RG3
43
42
41
40
39
38
37
44
48
47
46
50
49
51
54
53
52
55
45
SS2/CN11/RG9
AN5/IC8/CN7/RB5
AN4/IC7/CN6/RB4
IC3/INT3/RD10
VDD
C1RX/RF0
OC4/RD3
OC7/CN15/RD6
OC6/IC6/CN14/RD5
OC5/IC5/CN13/RD4
dsPIC33FJ64GP706
dsPIC33FJ128GP706
= Los pines son tolerantes hasta 5V

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 8
© 2009 Microchip Technology Inc.
Diagramas de pines (continuación)
TQFP de 80 pines
72
74
73
71
70
69
68
67
66
65
64
63
62
61
20
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
50
49
48
47
46
45
44
21
41
40
39
38
37
36
35
34
23
24
25
26
27
28
29
30
31
32
33
dsPIC33FJ64GP708
17
18
19
75
1
57
56
55
54
53
52
51
60
59
58
43
42
76
78
77
79
22
80
IC5/RD12
OC4/RD3
OC3/RD2
OC2/RD1
CSCK/RG14
AN23/CN23/RA7
AN22/CN22/RA6
C2RX/RG0
C2TX/RG1
C1TX/RF1
C1RX/RF0
CSDO/RG13
CSDI/RG12
OC8/CN16/RD7
OC6/CN14/RD5
OC1/RD0
IC4/RD11
IC2/RD9
IC1/RD8
IC3/RD10
VSS
OSC1/CLKIN/RC12
VDD
SCL1/RG2
U1RX/RF2
U1TX/RF3
PGEC2/SOSCO/T1CK/CN0/RC14
PGED2/SOSCI/CN1/RC13
VREF+/RA10
VREF-/RA9
AVDD
AVSS
U2CTS/AN8/RB8
AN9/RB9
AN10/RB10
AN11/RB11
VDD
U2RX/CN17/RF4
IC8/U1RTS/CN21/RD15
U2TX/CN18/RF5
PGEC1/AN6/OCFA/RB6
PGED1/AN7/RB7
AN17/T3CK/T6CK/RC2
AN18/T4CK/T9CK/RC3
AN19/T5CK/T8CK/RC4
SCK2/CN8/RG6
SDI2/CN9/RG7
SDO2/CN10/RG8
MCLR
SS2/CN11/RG9
AN4/CN6/RB4
AN3/CN5/RB3
AN2/SS1/CN4/RB2
PGEC3/AN1/CN3/RB1
PGED3/AN0/CN2/RB0
VSS
VDD
COFS/RG15
AN16/T2CK/T7CK/RC1
TDO/AN21/INT2/RA13
TMS/AN20/INT1/RA12
TCK/AN12/RB12
TDI/AN13/RB13
U2RTS/AN14/RB14
AN15/OCFB/CN12/RB15
VDD
VCAP/VDDCORE
OC5/CN13/RD4
IC6/CN19/RD13
SDA1/RG3
SDI1/RF7
SDO1/RF8
AN5/CN7/RB5
VSS
OSC2/CLKO/RC15
OC7/CN15/RD6
SCK1/INT0/RF6
IC7/U1CTS/CN20/RD14
SDA2/INT4/RA3
SCL2/INT3/RA2
dsPIC33FJ128GP708
= Los pines son tolerantes hasta 5V

© 2009 Microchip Technology Inc.
DS70286C-página 9
dsPIC33FJXXXGPX06/X08/X10
Diagramas de pines (continuación) 
92
94
93
91
90
89
88
87
86
85
84
83
82
81
80
79
78
20
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
65
64
63
62
61
60
59
26
56
45
44
43
42
41
40
39
28
29
30
31
32
33
34
35
36
37
38
17
18
19
21
22
95
1
76
77
72
71
70
69
68
67
66
75
74
73
58
57
24
23
25
96
98
97
99
27
46
47
48
49
50
55
54
53
52
51
OC6/CN14/RD5
OC5/CN13/RD4
IC6/CN19/RD13
IC5/RD12
OC4/RD3
OC3/RD2
OC2/RD1
AN23/CN23/RA7
AN22/CN22/RA6
AN26/RE2
CSDO/RG13
CSDI/RG12
CSCK/RG14
AN25/RE1
AN24/RE0
RG0
AN28/RE4
AN27/RE3
RF0
VCAP/VDDCORE
PGED2/SOSCI/CN1/RC13
OC1/RD0
IC3/RD10
IC2/RD9
IC1/RD8
IC4/RD11
SDA2/RA3
SCL2/RA2
OSC2/CLKO/RC15
OSC1/CLKIN/RC12
VDD
SCL1/RG2
SCK1/INT0/RF6
SDI1/RF7
SDO1/RF8
SDA1/RG3
U1RX/RF2
U1TX/RF3
VSS
PGEC2/SOSCO/T1CK/CN0/RC14
VREF+/RA10
VREF-/RA9
AVDD
AVSS
AN8/RB8
AN9/RB9
AN10/RB10
AN11/RB11
VDD
U2CTS/RF12
U2RTS/RF13
IC7/U1CTS/CN20/RD14
IC8/U1RTS/CN21/RD15
VDD
VSS
PGEC1/AN6/OCFA/RB6
PGED1/AN7/RB7
U2TX/CN18/RF5
U2RX/CN17/RF4
AN29/RE5
AN30/RE6
AN31/RE7
AN16/T2CK/T7CK/RC1
AN17/T3CK/T6CK/RC2
AN18/T4CK/T9CK/RC3
AN19/T5CK/T8CK/RC4
SCK2/CN8/RG6
VDD
TMS/RA0
AN20/INT1/RA12
AN21/INT2/RA13
AN5/CN7/RB5
AN4/CN6/RB4
AN3/CN5/RB3
AN2/SS1/CN4/RB2
SDI2/CN9/RG7
SDO2/CN10/RG8
PGEC3/AN1/CN3/RB1
PGED3/AN0/CN2/RB0
COFS/RG15
VDD
SS2/CN11/RG9
MCLR
AN12/RB12
AN13/RB13
AN14/RB14
AN15/OCFB/CN12/RB15
RG1
RF1
OC8/CN16/RD7
OC7/CN15/RD6
TDO/RA5
INT4/RA15
INT3/RA14
VSS
VSS
VSS
VDD
TDI/RA4
TCK/RA1
 TQFP de 100 pines
dsPIC33FJ64GP310
dsPIC33FJ128GP310
100
= Los pines son tolerantes hasta 5V

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 10
© 2009 Microchip Technology Inc.
Diagramas de pines (continuación)
92
94
93
91
90
89
88
87
86
85
84
83
82
81
80
79
78
20
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
65
64
63
62
61
60
59
26
56
45
44
43
42
41
40
39
28
29
30
31
32
33
34
35
36
37
38
17
18
19
21
22
95
1
76
77
72
71
70
69
68
67
66
75
74
73
58
57
24
23
25
96
98
97
99
27
46
47
48
49
50
55
54
53
52
51
OC6/CN14/RD5
OC5/CN13/RD4
IC6/CN19/RD13
IC5/RD12
OC4/RD3
OC3/RD2
OC2/RD1
AN23/CN23/RA7
AN22/CN22/RA6
AN26/RE2
CSDO/RG13
CSDI/RG12
CSCK/RG14
AN25/RE1
AN24/RE0
RG0
AN28/RE4
AN27/RE3
C1RX/RF0
VCAP/VDDCORE
PGED2/SOSCI/CN1/RC13
OC1/RD0
IC3/RD10
IC2/RD9
IC1/RD8
IC4/RD11
SDA2/RA3
SCL2/RA2
OSC2/CLKO/RC15
OSC1/CLKIN/RC12
VDD
SCL1/RG2
SCK1/INT0/RF6
SDI1/RF7
SDO1/RF8
SDA1/RG3
U1RX/RF2
U1TX/RF3
VSS
PGEC2/SOSCO/T1CK/CN0/RC14
VREF+/RA10
VREF-/RA9
AVDD
AVSS
AN8/RB8
AN9/RB9
AN10/RB10
AN11/RB11
VDD
U2CTS/RF12
U2RTS/RF13
IC7/U1CTS/CN20/RD14
IC8/U1RTS/CN21/RD15
VDD
VSS
PGEC1/AN6/OCFA/RB6
PGED1/AN7/RB7
U2TX/CN18/RF5
U2RX/CN17/RF4
AN29/RE5
AN30/RE6
AN31/RE7
AN16/T2CK/T7CK/RC1
AN17/T3CK/T6CK/RC2
AN18/T4CK/T9CK/RC3
AN19/T5CK/T8CK/RC4
SCK2/CN8/RG6
VDD
TMS/RA0
AN20/INT1/RA12
AN21/INT2/RA13
AN5/CN7/RB5
AN4/CN6/RB4
AN3/CN5/RB3
AN2/SS1/CN4/RB2
SDI2/CN9/RG7
SDO2/CN10/RG8
PGEC3/AN1/CN3/RB1
PGED3/AN0/CN2/RB0
COFS/RG15
VDD
SS2/CN11/RG9
MCLR
AN12/RB12
AN13/RB13
AN14/RB14
AN15/OCFB/CN12/RB15
RG1
C1TX/RF1
OC8/CN16/RD7
OC7/CN15/RD6
TDO/RA5
INT4/RA15
INT3/RA14
VSS
VSS
VSS
VDD
TDI/RA4
TCK/RA1
 TQFP de 100 pines
dsPIC33FJ256GP510
100
= Los pines son tolerantes hasta 5V

© 2009 Microchip Technology Inc.
DS70286C-página 11
dsPIC33FJXXXGPX06/X08/X10
Diagramas de pines (continuación)
92
94
93
91
90
89
88
87
86
85
84
83
82
81
80
79
78
20
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
65
64
63
62
61
60
59
26
56
45
44
43
42
41
40
39
28
29
30
31
32
33
34
35
36
37
38
17
18
19
21
22
95
1
76
77
72
71
70
69
68
67
66
75
74
73
58
57
24
23
25
96
98
97
99
27
46
47
48
49
50
55
54
53
52
51
OC6/CN14/RD5
OC5/CN13/RD4
IC6/CN19/RD13
IC5/RD12
OC4/RD3
OC3/RD2
OC2/RD1
AN23/CN23/RA7
AN22/CN22/RA6
AN26/RE2
CSDO/RG13
CSDI/RG12
CSCK/RG14
AN25/RE1
AN24/RE0
C2RX/RG0
AN28/RE4
AN27/RE3
C1RX/RF0
VCAP/VDDCORE
PGED2/SOSCI/CN1/RC13
OC1/RD0
IC3/RD10
IC2/RD9
IC1/RD8
IC4/RD11
SDA2/RA3
SCL2/RA2
OSC2/CLKO/RC15
OSC1/CLKIN/RC12
VDD
SCL1/RG2
SCK1/INT0/RF6
SDI1/RF7
SDO1/RF8
SDA1/RG3
U1RX/RF2
U1TX/RF3
VSS
PGEC2/SOSCO/T1CK/CN0/RC14
VREF+/RA10
VREF-/RA9
AVDD
AVSS
AN8/RB8
AN9/RB9
AN10/RB10
AN11/RB11
VDD
U2CTS/RF12
U2RTS/RF13
IC7/U1CTS/CN20/RD14
IC8/U1RTS/CN21/RD15
VDD
VSS
PGEC1/AN6/OCFA/RB6
PGED1/AN7/RB7
U2TX/CN18/RF5
U2RX/CN17/RF4
AN29/RE5
AN30/RE6
AN31/RE7
AN16/T2CK/T7CK/RC1
AN17/T3CK/T6CK/RC2
AN18/T4CK/T9CK/RC3
AN19/T5CK/T8CK/RC4
SCK2/CN8/RG6
VDD
TMS/RA0
AN20/INT1/RA12
AN21/INT2/RA13
AN5/CN7/RB5
AN4/CN6/RB4
AN3/CN5/RB3
AN2/SS1/CN4/RB2
SDI2/CN9/RG7
SDO2/CN10/RG8
PGEC3/AN1/CN3/RB1
PGED3/AN0/CN2/RB0
COFS/RG15
VDD
SS2/CN11/RG9
MCLR
AN12/RB12
AN13/RB13
AN14/RB14
AN15/OCFB/CN12/RB15
C2TX/RG1
C1TX/RF1
OC8/CN16/RD7
OC7/CN15/RD6
TDO/RA5
INT4/RA15
INT3/RA14
VSS
VSS
VSS
VDD
TDI/RA4
TCK/RA1
 TQFP de 100 pines
dsPIC33FJ128GP710
100
dsPIC33FJ256GP710
dsPIC33FJ64GP710
= Los pines son tolerantes hasta 5V

dsPIC33FJXXXGPX06/X08/X10 
DS70286C-página 12 
© 2009 Microchip Technology Inc. 
Tabla de contenido 
Familias de productos dsPIC33F ................................................................................................................................................................ 3 
1.0 
Descripción general del dispositivo ........................................................................................................................................................ 13 
2.0 
Directrices para empezar a utilizar controladores de señal digital de 16 bits.................................................................... 17 
3.0 
CPU................................................................................................................................................................................................ 21 
4.0 
Organización de la memoria ................................................................................................................................................................ 33 
5.0 
Memoria de programa flash................................................................................................................................................... 71 
6.0 
Restablecer ........................................................................................................................................................................................ 77 
7.0 
Controlador de interrupciones ................................................................................................................................................................ 81 
8.0 
Acceso directo a memoria (DMA) ................................................................................................................................................ 127 
9.0 
Configuración del oscilador ................................................................................................................................................................ 137 
10.0 Funciones de ahorro de energía................................................................................................................................................. 147 
11.0 Puertos de E/S ................................................................................................................................................................................ 155 
12.0 Temporizador1 ................................................................................................................................................................................ 157 
13.0 Temporizador 2/3, Temporizador 4/5, Temporizador 6/7 y Temporizador 8/9 ................................................................................................................ 159 
14.0 Captura de entrada................................................................................................................................................................ 165 
15.0 Comparación de salida................................................................................................................................................................ 167 
16.0 Interfaz periférica serie (SPI)................................................................................................................................................. 171 
17.0 Circuito Inter-Integrado™ (I2C™)................................................................................................................................................ 177 
18.0 Transmisor receptor asíncrono universal (UART) ................................................................................................. 185 
Módulo CAN mejorado 19.0 (ECAN™).................................................................................................................................... 191 
Módulo de interfaz de convertidor de datos (DCI) 20.0................................................................................................................... 217 
21.0 Convertidor analógico a digital (ADC) de 10 bits/12 bits ........................................................................................................ 225 
22.0 Funciones especiales ................................................................................................................................................................ 237 
23.0 Resumen del conjunto de instrucciones ................................................................................................................................................ 245 
24.0 Apoyo al desarrollo................................................................................................................................................................ 253 
25.0 Características eléctricas ................................................................................................................................................................ 257 
26.0 Información de embalaje................................................................................................................................................ 297 
Apéndice A: Historial de revisiones................................................................................................................................................................ 307 
Índice ................................................................................................................................................................................................ 313 
El sitio web de Microchip................................................................................................................................................................ 317 
Servicio de notificación de cambios de cliente ................................................................................................................................................ 317 
Atención al cliente................................................................................................................................................................................ 317 
Respuesta del lector ................................................................................................................................................................................ 318 
Sistema de identificación de productos................................................................................................................................................................ 319 
A NUESTROS VALIOSOS CLIENTES 
Nuestra intención es proporcionar a nuestros valiosos clientes la mejor documentación posible para garantizar el uso exitoso de su Microchip. 
productos. Con este fin, continuaremos mejorando nuestras publicaciones para adaptarlas mejor a sus necesidades. Nuestras publicaciones serán refinadas y 
mejorado a medida que se introducen nuevos volúmenes y actualizaciones. 
Si tiene alguna pregunta o comentario sobre esta publicación, comuníquese con el Departamento de Comunicaciones de Marketing a través de 
Envíe un correo electrónico a docerrors@microchip.com o envíe por fax el formulario de respuesta del lector que se encuentra al dorso de esta hoja de datos al (480) 792-4150. Nosotros 
Error 500 (Server Error)!!1500.That’s an error.There was an error. Please try again later.That’s all we know. 
Hoja de datos más actualizada 
Para obtener la versión más actualizada de esta hoja de datos, regístrese en nuestro sitio web mundial en: 
http://www.microchip.com 
Puede determinar la versión de una hoja de datos examinando el número de literatura que se encuentra en la esquina exterior inferior de cualquier página. 
El último carácter del número de literatura es el número de versión (por ejemplo, DS30000A es la versión A del documento DS30000). 
Erratas 
Es posible que exista una hoja de erratas que describa diferencias operativas menores con respecto a la hoja de datos y soluciones alternativas recomendadas para los equipos actuales. 
dispositivos. A medida que tengamos conocimiento de problemas con el dispositivo o la documentación, publicaremos una hoja de erratas. Las erratas especificarán la revisión. 
de silicio y revisión del documento al que aplica. 
Para determinar si existe una hoja de erratas para un dispositivo en particular, consulte uno de los siguientes: 
• Sitio web mundial de Microchip; http://www.microchip.com 
• Su oficina de ventas local de Microchip (consulte la última página) 
Cuando se comunique con una oficina de ventas, especifique qué dispositivo, revisión de silicio y hoja de datos (incluya el número de literatura) está 
usando. 
Sistema de notificación al cliente 
Regístrese en nuestro sitio web en www.microchip.com para recibir la información más actualizada sobre todos nuestros productos. 

© 2009 Microchip Technology Inc.
DS70286C-página 13
dsPIC33FJXXXGPX06/X08/X10
1.0
DESCRIPCIÓN GENERAL DEL DISPOSITIVO
Este documento contiene información específica del dispositivo para
los siguientes dispositivos:
• dsPIC33FJ64GP206
• dsPIC33FJ64GP306
• dsPIC33FJ64GP310
• dsPIC33FJ64GP706
• dsPIC33FJ64GP708
• dsPIC33FJ64GP710
• dsPIC33FJ128GP206
• dsPIC33FJ128GP306
• dsPIC33FJ128GP310
• dsPIC33FJ128GP706
• dsPIC33FJ128GP708
• dsPIC33FJ128GP710
• dsPIC33FJ256GP506
• dsPIC33FJ256GP510
• dsPIC33FJ256GP710
El dsPIC33FJXXXGPX06/X08/X10 de uso general
La familia de dispositivos incluye dispositivos con una amplia gama de
recuento de pines (64, 80 y 100), diferente memoria de programa
tamaños (64 Kbytes, 128 Kbytes y 256 Kbytes) y
diferentes tamaños de RAM (8 Kbytes, 16 Kbytes y
30 Kbytes).
Esta característica hace que la familia sea adecuada para una amplia variedad
de aplicaciones de control de señales digitales de alto rendimiento.
El dispositivo es compatible con pines de la familia PIC24H de
dispositivos, y también comparten un grado muy alto de
compatibilidad con los dispositivos de la familia dsPIC30F. esto
permite una fácil migración entre familias de dispositivos según sea posible
ser 
necesario 
por 
el 
específico 
funcionalidad,
recursos computacionales y requisitos de costos del sistema de
la aplicación.
La familia de dispositivos dsPIC33FJXXXGPX06/X08/X10
emplea una poderosa arquitectura de 16 bits que perfectamente
integra las funciones de control de un microcontrolador
(MCU) con las capacidades computacionales de un Digital
Procesador de señal (DSP). La funcionalidad resultante es
Ideal para aplicaciones que dependen de alta velocidad y repetitivas.
cálculos, así como control.
El motor DSP, acumuladores duales de 40 bits, hardware.
soporte para operaciones de división, palanca de cambios de barril, 17 x 17
multiplicador, una gran variedad de registros de trabajo de 16 bits y
una amplia variedad de modos de direccionamiento de datos, juntos
proporcione la central dsPIC33FJXXXGPX06/X08/X10
Unidad de procesamiento (CPU) con extensa matemática
capacidad de procesamiento. Flexible y determinista
manejo de interrupciones, junto con una poderosa variedad de
periféricos, 
renderiza 
el
Dispositivos dsPIC33FJXXXGPX06/X08/X10 adecuados para
aplicaciones de control. Además, acceso directo a la memoria
(DMA) permite la transferencia de datos sin gastos generales entre
varios periféricos y una RAM DMA dedicada.
Memoria de programa Flash confiable y programable en campo
asegura 
escalabilidad 
de 
aplicaciones 
eso 
usar
Dispositivos dsPIC33FJXXXGPX06/X08/X10.
La Figura 1-1 ilustra un diagrama de bloques general del
varios 
núcleo 
y 
periférico 
módulos 
en 
el
Familia de dispositivos dsPIC33FJXXXGPX06/X08/X10.
La Tabla 1-1 proporciona las funciones de los distintos pines.
ilustrado en los diagramas de distribución de pines.
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la última familia
secciones de referencia del archivo “dsPIC33F
Manual de referencia familiar”, que es
disponible en el sitio web de Microchip
(www.microchip.com).

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 14
© 2009 Microchip Technology Inc.
FIGURA 1-1:
dsPIC33FJXXXGPX06/X08/X10 DIAGRAMA DE BLOQUES GENERAL
 16
OSC1/CLKI
OSC2/CLKO
VDD, VSS
Sincronización
Generación
MCLR
encendido
Temporizador
Oscilador
Temporizador de inicio
Encendido
Reiniciar
perro guardián
Temporizador
apagón
Reiniciar
Precisión
Referencia
Banda prohibida
FRC/LPRC
Osciladores
Regulador
voltaje
VCAP/VDDCORE
UART1,2
ECAN1,2
DCI
IC1-8
SPI1,2
I2C1,2
OC/
PORTA
Nota:
No todos los pines o funciones están implementados en todas las configuraciones de pines del dispositivo. Consulte los diagramas de distribución de pines para los pines específicos.
y funciones presentes en cada dispositivo.
PWM1-8
CN1-23
Instrucción
Decodificar y
controlar
PCH PCL
16
Contador de programas
Aluminio de 16 bits
23
23
24
23
Registro de instrucciones
UCP
 
16 x 16
Matriz de registros W
Pestillo ROM
16
EAMUX
 16
 16
8
interrumpir
Controlador
PSV y tabla
Acceso a datos
Bloque de control
pila
controlar 
Lógica
Bucle
controlar
Lógica
Bloqueo de datos
Dirección
pestillo
Pestillo de dirección
Memoria de programa
Bloqueo de datos
   
     Datos literales
 16
 16
16
 
 16
Bloqueo de datos
Dirección
pestillo
16
RAM X
RAM
16
 
Bus de datos Y
Bus de datos X
 
      
Motor DSP
Dividir el apoyo
16
DMA
RAM
DMA
Controlador
Señales de control 
a varios bloques
ADC1,2
Temporizadores
PUERTO
PORTC
PORTADO
PORTE
PORTAF
PUERTO
Unidades generadoras de direcciones
1-9

© 2009 Microchip Technology Inc.
DS70286C-página 15
dsPIC33FJXXXGPX06/X08/X10
TABLA 1-1:
DESCRIPCIONES DE E/S DE PINOUT
Nombre del PIN
Alfiler
Tipo
búfer
Tipo
Descripción
AN0-AN31
yo
Analógico
Canales de entrada analógica. 
AVDD
pag
pag
Alimentación positiva para módulos analógicos. Este pin debe estar conectado en todo momento.
AVSS
pag
pag
Referencia de tierra para módulos analógicos.
CLKI
CLKO
yo
oh
ST/CMOS
—
Entrada de fuente de reloj externa. Siempre asociado a la función del pin OSC1.
Salida de cristal oscilador. Se conecta al cristal o resonador en Crystal Oscillator 
modo. Opcionalmente funciona como CLKO en modos RC y EC. Siempre asociado 
con función de pin OSC2.
CN0-CN23
yo
ST
Entradas de notificación de cambio de entrada.
Puede programarse por software para pull-ups débiles internos en todas las entradas.
COFS
CSCK
CSDI
CSDO
E/S
E/S
yo
oh
ST
ST
ST
—
Pin de sincronización del marco de la interfaz del convertidor de datos.
Pin de entrada/salida del reloj serie de la interfaz del convertidor de datos.
Pin de entrada de datos en serie de la interfaz del convertidor de datos.
Pin de salida de datos en serie de la interfaz del convertidor de datos.
C1RX
C1TX
C2RX
C2TX
yo
oh
yo
oh
ST
—
ST
—
Pin de recepción del bus ECAN1.
Pin de transmisión del bus ECAN1.
Pin de recepción del bus ECAN2.
Pin de transmisión del bus ECAN2.
PGED1
PGEC1
PGED2
PGEC2
PGED3
PGEC3
E/S
yo
E/S
yo
E/S
yo
ST
ST
ST
ST
ST
ST
Pin de E/S de datos para programar/depurar el canal de comunicación 1.
Pin de entrada de reloj para programación/depuración del canal de comunicación 1.
Pin de E/S de datos para programación/depuración del canal de comunicación 2.
Pin de entrada de reloj para programación/depuración del canal de comunicación 2.
Pin de E/S de datos para programar/depurar el canal de comunicación 3.
Pin de entrada de reloj para programación/depuración del canal de comunicación 3.
IC1-IC8
yo
ST
Capture las entradas 1 a 8.
INT0
INT1
INT2
INT3
INT4
yo
yo
yo
yo
yo
ST
ST
ST
ST
ST
Interrupción externa 0.
Interrupción externa 1.
Interrupción externa 2.
Interrupción externa 3.
Interrupción externa 4.
MCLR
I/P
ST
Entrada de borrado maestro (reinicio). Este pin es un reinicio activo-bajo del dispositivo.
OCFA
OCFB
OC1-OC8
yo
yo
oh
ST
ST
—
Compare la entrada de Falla A (para comparar los canales 1, 2, 3 y 4).
Compare la entrada de falla B (para comparar los canales 5, 6, 7 y 8).
Compare las salidas 1 a 8.
OSC1
OSC2
yo
E/S
ST/CMOS
—
Entrada de cristal oscilador. Búfer ST cuando se configura en modo RC; 
CMOS en caso contrario.
Salida de cristal oscilador. Se conecta al cristal o resonador en Crystal Oscillator 
modo. Opcionalmente funciona como CLKO en modos RC y EC.
RA0-RA7
RA9-RA10
RA12-RA15
E/S
E/S
E/S
ST
ST
ST
PORTA es un puerto de E/S bidireccional.
RB0-RB15
E/S
ST
PORTB es un puerto de E/S bidireccional.
RC1-RC4
RC12-RC15
E/S
E/S
ST
ST
PORTC es un puerto de E/S bidireccional.
RD0-RD15
E/S
ST
PORTD es un puerto de E/S bidireccional.
RE0-RE7
E/S
ST
PORTE es un puerto de E/S bidireccional.
RF0-RF8 
RF12-RF13
E/S
E/S
ST
ST
PORTF es un puerto de E/S bidireccional.
Leyenda:
CMOS = entrada o salida compatible con CMOS;
Analógico = Entrada analógica;
P = potencia
ST = Entrada Schmitt Trigger con niveles CMOS;
O = Salida;
Yo = entrada

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 16
© 2009 Microchip Technology Inc.
RG0-RG3
RG6-RG9
RG12-RG15
E/S
E/S
E/S
ST
ST
ST
PORTG es un puerto de E/S bidireccional.
SCK1
IDE1
SDO1
SS1
SCK2
SDI2
SDO2
SS2
E/S
yo
oh
E/S
E/S
yo
oh
E/S
ST
ST
—
ST
ST
ST
—
ST
Entrada/salida de reloj serial síncrono para SPI1.
Datos SPI1 en.
Salida de datos SPI1.
Sincronización de esclavo SPI1 o E/S de pulso de cuadro.
Entrada/salida de reloj serial síncrono para SPI2.
Datos SPI2 en.
Salida de datos SPI2.
Sincronización de esclavos SPI2 o E/S de pulsos de cuadro.
SCL1
SDA1
SCL2
SDA2
E/S
E/S
E/S
E/S
ST
ST
ST
ST
Entrada/salida de reloj serie síncrona para I2C1.
Entrada/salida de datos serie síncrona para I2C1.
Entrada/salida de reloj serie síncrona para I2C2.
Entrada/salida de datos serie síncrona para I2C2.
SOSCI
SOSCO
yo
oh
ST/CMOS
—
Entrada de cristal oscilador de baja potencia de 32,768 kHz; CMOS en caso contrario.
Salida de cristal oscilador de baja potencia de 32,768 kHz. 
TMS
TCK
TDI
TDO
yo
yo
yo
oh
ST
ST
ST
—
Pin de selección del modo de prueba JTAG.
Pin de entrada del reloj de prueba JTAG.
Pin de entrada de datos de prueba JTAG.
Pin de salida de datos de prueba JTAG.
T1CK
T2CK
T3CK
T4CK
T5CK
T6CK
T7CK
T8CK
T9CK
yo
yo
yo
yo
yo
yo
yo
yo
yo
ST
ST
ST
ST
ST
ST
ST
ST
ST
Entrada de reloj externo Timer1.
Entrada de reloj externo Timer2.
Entrada de reloj externo Timer3.
Entrada de reloj externo Timer4.
Entrada de reloj externo Timer5.
Entrada de reloj externo Timer6.
Entrada de reloj externo Timer7.
Entrada de reloj externo Timer8.
Entrada de reloj externo Timer9.
U1CTS
U1RTS
U1RX
U1TX
U2CTS
U2RTS
U2RX
U2TX
yo
oh
yo
oh
yo
oh
yo
oh
ST
—
ST
—
ST
—
ST
—
UART1 listo para enviar.
UART1 listo para enviar.
Recepción UART1.
Transmisión UART1.
UART2 listo para enviar.
UART2 listo para enviar.
Recepción UART2.
Transmisión UART2.
VDD
pag
—
Suministro positivo para lógica periférica y pines de E/S.
VCAP/VDDCORE
pag
—
Conexión del condensador del filtro lógico de la CPU.
VSS
pag
—
Referencia a tierra para pines lógicos y de E/S.
VREF+
yo
Analógico
Entrada de referencia de voltaje analógico (alta).
VREF-
yo
Analógico
Entrada de referencia de voltaje analógico (baja).
TABLA 1-1:
DESCRIPCIONES DE E/S DE PINOUT (CONTINUACIÓN)
Nombre del PIN
Alfiler
Tipo
búfer
Tipo
Descripción
Leyenda:
CMOS = entrada o salida compatible con CMOS;
Analógico = Entrada analógica;
P = potencia
ST = Entrada Schmitt Trigger con niveles CMOS;
O = Salida;
Yo = entrada

© 2009 Microchip Technology Inc.
DS70286C-página 17
dsPIC33FJXXXGPX06/X08/X10
2.0
PAUTAS PARA OBTENER 
COMENZÓ CON 16 BITS 
SEÑAL DIGITAL 
CONTROLADORES
2.1
Requisitos básicos de conexión
Conseguir 
comenzó 
con 
el
dsPIC33FJXXXGPX06/X08/X10 familia de dispositivos digitales de 16 bits
Los controladores de señal (DSC) requieren atención a
conjunto mínimo de conexiones de pines del dispositivo antes
continuando con el desarrollo. La siguiente es una lista de
nombres de pin, que siempre deben estar conectados:
• Todos los pines VDD y VSS 
(consulte la Sección 2.2 “Condensadores de desacoplamiento”)
• Todos los pines AVDD y AVSS (independientemente de si el módulo ADC 
no se utiliza) 
(consulte la Sección 2.2 “Condensadores de desacoplamiento”)
• VCAP/VDDCORE 
(consulte la Sección 2.3 “Condensador en tensión interna 
Regulador (VCAP/VDDCORE)”) 
• clavija MCLR 
(consulte la Sección 2.4 “Pin de borrado maestro (MCLR)”)
• Pines PGECx/PGEDx utilizados para serie en circuito 
Programación™ (ICSP™) y fines de depuración 
(consulte la Sección 2.5 “Pasadores ICSP”)
• Pines OSC1 y OSC2 cuando se utiliza oscilador externo 
se utiliza la fuente 
(consulte la Sección 2.6 “Pasadores del oscilador externo”)
Además, es posible que se requieran los siguientes pines:
• Pines VREF+/VREF- utilizados cuando hay tensión externa. 
Se implementa la referencia para el módulo ADC.
2.2
Condensadores de desacoplamiento
El uso de condensadores de desacoplamiento en cada par de
pines de fuente de alimentación, como VDD, VSS, AVDD y
Se requiere AVSS. 
Considere los siguientes criterios al utilizar el desacoplamiento
condensadores:
• Valor y tipo de condensador: Recomendación 
de 0,1 µF (100 nF), 10-20 V. Este condensador debe 
ser una ESR baja y tener una frecuencia de resonancia en 
el rango de 20 MHz y superior. es 
Se recomienda utilizar condensadores cerámicos.
• Colocación en la placa de circuito impreso: El 
Los condensadores de desacoplamiento deben colocarse lo más cerca 
a los pines como sea posible. Se recomienda 
Coloque los condensadores en el mismo lado del 
placa como dispositivo. Si el espacio es limitado, el 
El condensador se puede colocar en otra capa del 
PCB usando una vía; sin embargo, asegúrese de que el rastro 
La longitud desde el pin hasta el capacitor está dentro 
un cuarto de pulgada (6 mm) de largo.
• Manejo de ruido de alta frecuencia: Si la placa está 
experimentando ruido de alta frecuencia, por encima de 
decenas de MHz, agregue un segundo capacitor de tipo cerámico 
Paralelamente al desacoplamiento descrito anteriormente. 
condensador. El valor del segundo condensador puede 
estar en el rango de 0,01 µF a 0,001 µF. Coloca esto 
segundo condensador al lado del desacoplamiento primario 
condensador. En diseños de circuitos de alta velocidad, considere 
implementar un par de capacitancias decenales como 
lo más cerca posible de los pines de alimentación y tierra. 
Por ejemplo, 0,1 µF en paralelo con 0,001 µF.
• Maximizar el rendimiento: diseño en el tablero 
del circuito de alimentación, encienda la alimentación y 
return las trazas a los condensadores de desacoplamiento primero, 
y luego a los pines del dispositivo. Esto asegura que el 
Los condensadores de desacoplamiento son los primeros en la cadena eléctrica. 
Igualmente importante es mantener la longitud del rastro. 
entre el condensador y los pines de alimentación a un 
mínimo, reduciendo así la inductancia de la pista de PCB.
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. No pretende ser un
fuente de referencia completa. a
complementar la información de estos datos
hoja, consulte la “Familia dsPIC33F
Manual de referencia”, que está disponible
de 
el 
Microchip 
sitio web
(www.microchip.com).
Nota:
Los pines AVDD y AVSS deben estar
conectado independientemente del ADC
fuente de referencia de voltaje.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 18
© 2009 Microchip Technology Inc.
FIGURA 2-1:
RECOMENDADO 
CONEXIÓN MÍNIMA 
2.2.1
CONDENSADORES DE TANQUE
En tableros con líneas de energía de más de seis
pulgadas de largo, se sugiere utilizar un capacitor de tanque
para circuitos integrados, incluidos DSC, para alimentar una red local
fuente de energía. El valor del condensador del tanque debe
determinarse basándose en la resistencia traza que con-
conecta la fuente de alimentación al dispositivo y el
Corriente máxima consumida por el dispositivo en la aplicación.
ción. En otras palabras, seleccione el condensador del tanque para que
cumple con la caída de voltaje aceptable en el dispositivo. Típico
los valores oscilan entre 4,7 µF y 47 µF.
2.3
Condensador en voltaje interno 
Regulador (VCAP/VDDCORE)
Se requiere un condensador de baja ESR (< 5 ohmios) en el
Pin VCAP/VDDCORE, que se utiliza para estabilizar el
voltaje de salida del regulador de voltaje. El VCAP/VDDCORE
El pin no debe estar conectado a VDD y debe tener un
Condensador entre 4,7 µF y 10 µF, 16 V conectado a
suelo. El tipo puede ser cerámico o tantalio. Consulte
Sección 25.0 
“Eléctrico 
Características” 
para
información adicional.
La ubicación de este condensador debe estar cerca del
VCAP/VDDCORE. Se recomienda que el rastro
La longitud no debe exceder un cuarto de pulgada (6 mm). Consulte
Sección 22.2 “Regulador de voltaje en chip” para
detalles.
2.4
Pasador de limpieza maestra (MCLR)
El pin MCLR proporciona dos dispositivos específicos
funciones: 
• Restablecimiento del dispositivo
• Programación y depuración de dispositivos 
Durante la programación y depuración del dispositivo, el
resistencia y capacitancia que se pueden agregar a la
Se debe considerar el pasador. Programadores de dispositivos y
Los depuradores accionan el pin MCLR. En consecuencia,
niveles de voltaje específicos (VIH y VIL) y señal rápida
las transiciones no deben verse afectadas negativamente. Por lo tanto,
Será necesario ajustar los valores específicos de R y C.
según la aplicación y los requisitos de PCB.
Para 
ejemplo, 
como 
mostrado 
en 
Figura 2-2, 
eso 
es
Se recomienda aislar el condensador C de
el pin MCLR durante la programación y depuración
operaciones.
Coloque los componentes que se muestran en la Figura 2-2 dentro
un cuarto de pulgada (6 mm) del pasador MCLR.
FIGURA 2-2:
EJEMPLO DE PIN MCLR 
CONEXIONES
dsPIC33F
VDD
VSS
VDD
VSS
VSS
VDD
AVDD
AVSS
VDD
VSS
0,1 µF
Cerámica
0,1 µF
Cerámica
0,1 µF
Cerámica
0,1 µF
Cerámica
c
R
VDD
MCLR
0,1 µF
Cerámica
VCAP/VDDCORE
10 Ω
R1
Nota 1:
Se recomienda R ≤ 10 kΩ. Un sugerido
El valor inicial es 10 kΩ. Asegúrese de que el
Se cumplen las especificaciones MCLR pin VIH y VIL.
2:
R1 ≤ 470Ω limitará cualquier corriente que fluya hacia
MCLR del condensador externo C, en el
caso de rotura del pin MCLR, debido a
Descarga electrostática (ESD) o descarga eléctrica
Sobreestrés (EOS). Asegúrese de que el pin MCLR
Se cumplen las especificaciones VIH y VIL.
c
R1
R
VDD
MCLR
dsPIC33F
J.P.

© 2009 Microchip Technology Inc.
DS70286C-página 19
dsPIC33FJXXXGPX06/X08/X10
2.5
Pines ICSP
Los pines PGECx y PGEDx se utilizan para conexiones en circuito.
Serial Programming™ (ICSP™) y propósito de depuración.
plantea. Se recomienda mantener la longitud del rastro.
entre el conector ICSP y los pines ICSP en el
dispositivo lo más corto posible. Si el conector ICSP está
Se espera que experimente un evento ESD, una resistencia en serie
se recomienda, con el valor en el rango de unos pocos
decenas de ohmios, sin exceder los 100 ohmios. 
Resistencias pull-up, diodos en serie y condensadores en el
No se recomiendan los pines PGECx y PGEDx ya que
interferirá con la comunicación del programador/depurador.
cationes al dispositivo. Si tales componentes discretos son
un requisito de aplicación, deben eliminarse
del circuito durante la programación y depuración.
Alternativamente, consulte las características de CA/CC y
información sobre los requisitos de tiempo en el respectivo
especificación de programación Flash del dispositivo para obtener información
sobre límites de carga capacitiva y voltaje de entrada de pin alto
(VIH) y requisitos de entrada baja (VIL).
Asegúrese de que la “Selección de canal de comunicación” (es decir,
Pines PGECx/PGEDx) programados en el dispositivo
coincide con las conexiones físicas para que el ICSP
MPLAB® ICD 2, MPLAB ICD 3 o MPLAB REAL
HIELO™.
Para más información sobre ICD 2, ICD 3 y REAL ICE
requisitos de conexión, consulte lo siguiente
documentos que están disponibles en el sitio web de Microchip.
• “Guía del usuario del depurador en circuito MPLAB® ICD 2 
Guía” DS51331
• “Uso de MPLAB® ICD 2” (póster) DS51265
• “Asesoramiento de diseño MPLAB® ICD 2” DS51566
• “Uso del depurador en circuito MPLAB® ICD 3” 
(póster) DS51765
• “Asesoramiento de diseño MPLAB® ICD 3” DS51764
• “Guía del usuario del emulador en circuito MPLAB® REAL ICE™ 
Guía” DS51616
• “Uso de MPLAB® REAL ICE™” (póster) DS51749
2.6
Pines del oscilador externo
Muchos DSC tienen opciones para al menos dos osciladores: un
oscilador primario de alta frecuencia y un oscilador de baja frecuencia
oscilador secundario (consulte la Sección 9.0 “Oscilador
Configuración” para más detalles). 
El circuito oscilador debe colocarse en el mismo
lado del tablero como dispositivo. Además, coloque el
circuito oscilador cerca de los respectivos pines del oscilador,
que no exceda la distancia de media pulgada (12 mm)
entre ellos. Los condensadores de carga deben colocarse
al lado del propio oscilador, en el mismo lado del
tablero. Utilice un vertido de cobre conectado a tierra alrededor del
circuito oscilador para aislarlos de los alrededores.
circuitos. El vertido de cobre conectado a tierra debe encaminarse
directamente a la tierra de la MCU. No ejecutar ninguna señal
rastros o rastros de energía dentro del vertido del suelo. Además, si
Usando un tablero de dos caras, evite cualquier rastro en el
otro lado del tablero donde se coloca el cristal. un
El diseño sugerido se muestra en la Figura 2-3. 
FIGURA 2-3:
UBICACIÓN SUGERIDA 
DEL OSCILADOR 
CIRCUITO
13
Oscilador principal
Anillo de guardia
Rastreo de guardia
Secundaria
Oscilador
14
15
16
17
18
19
20

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 20
© 2009 Microchip Technology Inc.
2.7
Condiciones de valor del oscilador activadas 
Inicio del dispositivo
Si el PLL del dispositivo de destino está habilitado y
configurado para el oscilador de inicio del dispositivo, el
La frecuencia máxima de la fuente del oscilador debe ser limitada.
a 4 MHz < FIN < 8 MHz para cumplir con el PLL del dispositivo
condiciones de arranque. Esto significa que si el exterior
frecuencia del oscilador está fuera de este rango, el
La aplicación debe iniciarse primero en el modo FRC. el
Configuración predeterminada de PLL después de un POR con un oscilador
La frecuencia fuera de este rango violará el dispositivo.
velocidad de funcionamiento.
Una vez que el dispositivo se enciende, el firmware de la aplicación
puede inicializar los PLL SFR, CLKDIV y PLLDBF a un
valor adecuado y luego realice un cambio de reloj al
Oscilador + fuente de reloj PLL. Tenga en cuenta que el cambio de reloj
debe estar habilitado en la palabra de configuración del dispositivo. 
2.8
Configuración de analógico y 
Pines digitales durante ICSP 
Operaciones
Si se selecciona MPLAB ICD 2, ICD 3 o REAL ICE como
depurador, inicializa automáticamente todas las entradas A/D
pines (ANx) como pines "digitales", configurando todos los bits en el
Registros ADPCFG y ADPCFG2.
Los bits en los registros que corresponden a los pines A/D
que se inicializan mediante MPLAB ICD 2, ICD 3 o REAL
ICE, no debe ser borrado por la aplicación del usuario.
firmware; de lo contrario, se producirán errores de comunicación.
entre el depurador y el dispositivo.
Si su aplicación necesita usar ciertos pines A/D como
pines de entrada analógica durante la sesión de depuración, el usuario
La aplicación debe borrar los bits correspondientes en el
Registros ADPCFG y ADPCFG2 durante la inicialización
del módulo ADC. 
Cuando se utiliza MPLAB ICD 2, ICD 3 o REAL ICE como
programador, el firmware de la aplicación de usuario debe
configurar correctamente ADPCFG y ADPCFG2
registros. La inicialización automática de estos registros es
solo se hace durante la operación del depurador. No
configurar correctamente los registros resultará en todos los A/D
Los pines se reconocen como pines de entrada analógica, lo que resulta en
el valor del puerto se lee como un '0' lógico, lo que puede
afectar la funcionalidad de la aplicación del usuario.
2.9
E/S no utilizadas
Los pines de E/S no utilizados deben configurarse como salidas y
llevado a un estado de lógica baja.
Alternativamente, conecte una resistencia de 1k a 10k al VSS en
pines no utilizados y llevar la salida a lógica baja.

© 2009 Microchip Technology Inc. 
DS70286C-página 21 
dsPIC33FJXXXGPX06/X08/X10 
3.0 
UPC 
El módulo de CPU dsPIC33FJXXXGPX06/X08/X10 tiene un 
Arquitectura Harvard modificada de 16 bits (datos) con un 
conjunto de instrucciones mejorado, incluido un soporte significativo para 
DSP. La CPU tiene una palabra de instrucción de 24 bits con una variable 
campo de código de operación de longitud. El contador de programa (PC) es de 23 bits. 
de ancho y direcciones de hasta 4M x 24 bits de programa de usuario 
espacio de memoria. La cantidad real de memoria del programa. 
implementado varía según el dispositivo. Una instrucción de un solo ciclo 
El mecanismo de captación previa se utiliza para ayudar a mantener el rendimiento. 
y proporciona una ejecución predecible. Todas las instrucciones se ejecutan. 
en un solo ciclo, a excepción de las instrucciones que 
cambiar el flujo del programa, la palabra doble mover (MOV.D) 
instrucciones y las instrucciones de la tabla. Pro sin gastos generales 
Las construcciones de bucles de gramo se admiten mediante DO y 
REPETIR instrucciones, las cuales son interrumpibles en cualquier 
punto. 
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 tienen dieciséis, 
Registros de trabajo de 16 bits en el modelo del programador. cada uno de 
los registros de trabajo pueden servir como dato, dirección o 
registro de compensación de dirección. El 16º registro de trabajo (W15) 
funciona como un software Stack Pointer (SP) para interrupciones y 
llamadas. 
El conjunto de instrucciones dsPIC33FJXXXGPX06/X08/X10 tiene 
dos clases de instrucciones: MCU y DSP. estos dos 
Las clases de instrucción se integran perfectamente en un solo 
UPC. El conjunto de instrucciones incluye muchos modos de direccionamiento. 
y está diseñado para una eficiencia óptima del compilador de C. Para la mayoría 
instrucciones, el dsPIC33FJXXXGPX06/X08/X10 es capaz 
capaz de ejecutar una lectura de memoria de datos (o datos de programa), una 
lectura del registro de trabajo (datos), una escritura de memoria de datos y una 
Memoria de programa (instrucción) leída por ciclo de instrucción. Como 
Como resultado, se pueden admitir tres instrucciones de parámetros, 
permitiendo que las operaciones A + B = C se ejecuten en una sola 
ciclo. 
En la Figura 3-1 se muestra un diagrama de bloques de la CPU. El 
programas 
modelo 
para 
el 
dsPIC33FJXXXGPX06/X08/X10 se muestra en la Figura 3-2. 
3.1 
Descripción general del direccionamiento de datos 
El espacio de datos se puede direccionar como 32K palabras o 
64 Kbytes y está dividido en dos bloques, denominados X y 
Memoria de datos Y. Cada bloque de memoria tiene su propia 
Unidad de Generación de Direcciones (AGU) de Dent. La clase MCU de 
Las instrucciones funcionan únicamente a través de la memoria X AGU, 
que accede a todo el mapa de memoria como un dato lineal 
espacio. Ciertas instrucciones DSP operan a través de X y 
Y AGU para admitir lecturas de operandos duales, lo que divide el 
espacio de direcciones de datos en dos partes. El espacio de datos X e Y 
El límite es específico del dispositivo. 
Búfers circulares sin sobrecarga (modo de direccionamiento de módulo) 
son compatibles con los espacios de direcciones X e Y. El módulo 
El direccionamiento elimina la supervisión de los límites del software. 
Dirígete a los algoritmos DSP. Además, la circular X AGU 
El direccionamiento se puede utilizar con cualquiera de las clases MCU de 
instrucciones. La X AGU también admite Bit-Reversed 
Direccionamiento para simplificar enormemente los datos de entrada o salida. 
Reordenamiento para algoritmos FFT radix-2. 
Los 32 Kbytes superiores del mapa de memoria del espacio de datos pueden 
opcionalmente puede asignarse al espacio del programa en cualquier programa de 16K. 
Límite de palabra de gramo definido por el espacio de programa de 8 bits. 
Registro de la Página de Visibilidad (PSVPAG). El programa de datos. 
La función de mapeo espacial permite que cualquier programa de acceso a instrucciones 
espacio como si fuera espacio de datos. El espacio de datos también incluye 
2 Kbytes de RAM DMA, que se utiliza principalmente para DMA 
transferencias de datos, pero puede usarse como RAM de uso general. 
3.2 
Descripción general del motor DSP 
El motor DSP presenta una velocidad de 17 bits por 17 bits. 
multiplicador, una ALU de 40 bits, dos acumuladores de saturación de 40 bits. 
Tors y una palanca de cambios de barril bidireccional de 40 bits. el barril 
Shifter es capaz de cambiar un valor de 40 bits, hasta 16 bits. 
derecha o izquierda, en un solo ciclo. Las instrucciones DSP funcionan 
perfectamente con todas las demás instrucciones y han sido 
Diseñado para un rendimiento óptimo en tiempo real. El MAC 
instrucción y otras instrucciones asociadas pueden concurrir 
rápidamente recuperar dos operandos de datos de la memoria mientras 
ejecutando dos registros W y acumulando y opcionalmente 
saturando el resultado en el mismo ciclo. esta instrucción 
La funcionalidad requiere que el espacio de datos de la memoria RAM sea 
dividido para estas instrucciones y lineal para todas las demás. Datos 
La partición del espacio se logra de forma transparente y flexible. 
manera mediante la dedicación de determinados registros de trabajo a 
cada espacio de direcciones. 
3.3 
Características especiales de la MCU 
El dsPIC33FJXXXGPX06/X08/X10 cuenta con una interfaz de 17 bits por 
Multiplicador de ciclo único de 17 bits que comparten tanto el 
Motor MCU ALU y DSP. El multiplicador puede funcionar 
multiplicación con signo, sin signo y de signos mixtos. Usando un 
Multiplicador de 17 bits por 17 bits para multiplicación de 16 bits por 16 bits 
no sólo le permite realizar multiplicaciones de signos mixtos, sino que 
también logra resultados precisos para operaciones especiales, 
como por ejemplo (-1,0) x (-1,0). 
El dsPIC33FJXXXGPX06/X08/X10 admite 16/16 y 
Operaciones de división 32/16, tanto fraccionarias como enteras. Todo 
Las instrucciones de división son operaciones iterativas. Deben ser 
ejecutado dentro de un bucle REPEAT, lo que resulta en una ejecución total. 
tiempo de ejecución de 19 ciclos de instrucción. La operación de división puede 
ser interrumpido durante cualquiera de esos 19 ciclos sin pérdida 
de datos. 
Se utiliza una palanca de cambios de barril de 40 bits para realizar hasta 16 bits, izquierda 
o desplazamiento a la derecha en un solo ciclo. Se puede utilizar la palanca de cambios de barril. 
por instrucciones tanto de MCU como de DSP. 
Nota: 
Esta hoja de datos resume las características 
del dsPIC33FJXXXGPX06/X08/X10 
familia de dispositivos. Sin embargo, no es 
pretende ser una referencia completa 
fuente. Para complementar la información en 
esta hoja de datos, consulte la Sección 2. “CPU” 
(DS70204) en la “Referencia de la familia dsPIC33F”. 
Manual de referencia”, que está disponible en 
el 
Pastilla 
web 
sitio 
(www.microchip.com). 

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 22
© 2009 Microchip Technology Inc.
FIGURA 3-1:
DIAGRAMA DE BLOQUES DEL NÚCLEO DE CPU dsPIC33FJXXXGPX06/X08/X10
Instrucción
Decodificar y
controlar
PCH PCL
Contador de programas
Aluminio de 16 bits
24
23
Registro de instrucciones
UCP
 
16 x 16
Matriz de registros W
Pestillo ROM
EAMUX
interrumpir
Controlador
pila
controlar
Lógica
Bucle
controlar
Lógica
Bloqueo de datos
Dirección
pestillo
Señales de control
a varios bloques
     Datos literales
 16
 16
16
A módulos periféricos
 
Bloqueo de datos
Dirección
pestillo
16
RAM X
RAM
Unidades generadoras de direcciones
16
 
Bus de datos Y
Bus de datos X
DMA
 Controlador
DMA
RAM
Motor DSP
Dividir el apoyo
16
16
23
23
 16
8
PSV y tabla
Acceso a datos
Bloque de control
 16
   16
 16
16
Memoria de programa
Bloqueo de datos
Pestillo de dirección

© 2009 Microchip Technology Inc.
DS70286C-página 23
dsPIC33FJXXXGPX06/X08/X10
FIGURA 3-2:
dsPIC33FJXXXGPX06/X08/X10 MODELO DEL PROGRAMADOR
       PC22
PC0
7
 0
D0
D15
Contador de programas
Dirección de la página de la tabla de datos
ESTADO Registrarse
Registros de trabajo
Operando DSP
Registros
W1
W2
W3
W4
W5
W6
W7
W8
W9
W10
W11
Compensación W12/DSP
W13/DSP Reescritura
W14/Puntero de marco
W15/Puntero de pila
Dirección DSP
Registros
39 d.C.
AD0
AD31
DSP
Acumuladores
AccA
AccB
7
 0
Dirección de la página de visibilidad del espacio del programa
z
0
OA
OB
SA
SB
RCONTAR
15
 0
REPETIR contador de bucles
DCUENTO
15
 0
Contador de bucle DO
DOSTART
   22
 0
Dirección de inicio del bucle DO
IPL2 IPL1
SPLIM
Registro de límite de puntero de pila
15 d.C.
srl
PUSH.S Sombra
HACER sombra
OAB SAB
15
 0
Registro de configuración principal 
Leyenda
CORCÓN
DA
CC
RA
norte
TBLPAG
PSVPAG
IPL0
VO
W0/WREG
SSR
Dirección final del bucle DO
FINALIZAR
   22
c

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 24
© 2009 Microchip Technology Inc.
3.4
Registros de control de CPU
Los registros de control de la CPU incluyen:
• SR: REGISTRO DE ESTADO DE LA CPU
• CORCON: REGISTRO DE CONTROL PRINCIPAL
      
REGÍSTRESE 3-1:
SR: REGISTRO DE ESTADO DE CPU
R-0
R-0
R/C-0
R/C-0
R-0
R/C-0
-0
R/W-0
OA
OB
SA(1)
SB(1)
VH
SAB
DA
CC
poco 15
poco 8
R/W-0(2)
R/W-0(3)
R/W-0(3)
R-0
R/W-0
R/W-0
R/W-0
R/W-0
IPL<2:0>(2)
RA
norte
VO
z
c
poco 7
poco 0
Leyenda:
C = Borrar solo bit
R = bit legible
U = Bit no implementado, leído como '0'
S = Establecer solo bit
W = bit grabable
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
OA: Bit de estado de desbordamiento del acumulador A
1 = Acumulador A desbordado
0 = El acumulador A no se ha desbordado
poco 14
OB: Bit de estado de desbordamiento del acumulador B
1 = Acumulador B desbordado
0 = El acumulador B no se ha desbordado
poco 13
SA: Bit de estado "pegajoso" de saturación del acumulador A(1)
1 = El acumulador A está saturado o ha estado saturado en algún momento
0 = El acumulador A no está saturado
poco 12
SB: Bit de estado "pegajoso" de saturación del acumulador B (1)
1 = El acumulador B está saturado o ha estado saturado en algún momento
0 = Acumulador B no está saturado
poco 11
VHA: OA || Bit de estado de desbordamiento del acumulador combinado de OB
1 = Los acumuladores A o B se han desbordado
0 = Ni los acumuladores A ni B se han desbordado
poco 10
SAB: SA || Bit de estado "pegajoso" del acumulador combinado SB
1 = Los acumuladores A o B están saturados o han estado saturados en algún momento del pasado
0 = Ni el Acumulador A ni el B están saturados
Nota:
Este bit puede leerse o borrarse (no establecerse). Al borrar este bit se borrarán SA y SB.
poco 9
DA: bit activo del bucle DO
1 = bucle DO en curso
0 = bucle DO no en progreso
Nota 1: Este bit puede leerse o borrarse (no establecerse).
2: Los bits IPL<2:0> se concatenan con el bit IPL<3> (CORCON<3>) para formar la prioridad de interrupción de la CPU.
Nivel. El valor entre paréntesis indica la IPL si IPL<3> = 1. Las interrupciones del usuario se desactivan cuando
IPL<3> = 1.
3: Los bits de estado de IPL<2:0> se leen solo cuando NSTDIS = 1 (INTCON1<15>).

© 2009 Microchip Technology Inc.
DS70286C-página 25
dsPIC33FJXXXGPX06/X08/X10
  
poco 8
DC: MCU ALU Medio acarreo/bit de préstamo
1 = Una transferencia desde el cuarto bit de orden inferior (para datos de tamaño de byte) o el octavo bit de orden inferior (para datos de tamaño de palabra)
del resultado ocurrido
0 = Sin transferencia desde el cuarto bit de orden inferior (para datos de tamaño byte) o el octavo bit de orden inferior (para datos de tamaño de palabra).
datos) del resultado ocurrido
bits 7-5
IPL<2:0>: Bits de estado de nivel de prioridad de interrupción de CPU(2)
111 = El nivel de prioridad de interrupción de la CPU es 7 (15), las interrupciones del usuario están deshabilitadas
110 = El nivel de prioridad de interrupción de la CPU es 6 (14)
101 = El nivel de prioridad de interrupción de la CPU es 5 (13)
100 = El nivel de prioridad de interrupción de la CPU es 4 (12)
011 = El nivel de prioridad de interrupción de la CPU es 3 (11)
010 = El nivel de prioridad de interrupción de la CPU es 2 (10)
001 = El nivel de prioridad de interrupción de la CPU es 1 (9)
000 = El nivel de prioridad de interrupción de la CPU es 0 (8)
poco 4
RA: REPETIR bit activo del bucle
1 = REPETIR bucle en curso
0 = bucle REPETIR no en curso
poco 3
N: bit negativo MCU ALU
1 = El resultado fue negativo
0 = El resultado no fue negativo (cero o positivo)
poco 2
OV: Bit de desbordamiento MCU ALU
Este bit se utiliza para aritmética con signos (complemento a 2). Indica un desbordamiento de la magnitud que
hace que el bit de signo cambie de estado. 
1 = Se produjo un desbordamiento para la aritmética con signo (en esta operación aritmética)
0 = No se produjo ningún desbordamiento
poco 1
Z: MCU ALU bit cero
1 = Una operación que afecta el bit Z lo ha configurado en algún momento en el pasado
0 = La operación más reciente que afecta el bit Z lo ha borrado (es decir, un resultado distinto de cero)
poco 0
C: Bit de transporte/préstamo MCU ALU
1 = Se produjo una transferencia del bit más significativo del resultado
0 = No se realizó ninguna transferencia del bit más significativo del resultado
REGÍSTRESE 3-1:
SR: REGISTRO DE ESTADO DE CPU (CONTINUACIÓN)
Nota 1: Este bit puede leerse o borrarse (no establecerse).
2: Los bits IPL<2:0> se concatenan con el bit IPL<3> (CORCON<3>) para formar la prioridad de interrupción de la CPU.
Nivel. El valor entre paréntesis indica la IPL si IPL<3> = 1. Las interrupciones del usuario se desactivan cuando
IPL<3> = 1.
3: Los bits de estado de IPL<2:0> se leen solo cuando NSTDIS = 1 (INTCON1<15>).

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 26
© 2009 Microchip Technology Inc.
REGISTRO 3-2:
CORCON: REGISTRO DE CONTROL PRINCIPAL
U-0
U-0
U-0
R/W-0
R/W-0
R-0
R-0
R-0
—
—
—
Estados Unidos
hora del este(1)
DL<2:0>
poco 15
poco 8
R/W-0
R/W-0
R/W-1
R/W-0
R/C-0
R/W-0
R/W-0
R/W-0
sata
SATB
SATDW
ACCESAT
IPL3(2)
PSV
RND
SI
poco 7
poco 0
Leyenda:
C = Borrar solo bit
R = bit legible
W = bit grabable
-n = Valor en POR
'1' = El bit está configurado
0’ = El bit se borra
'x = El bit es desconocido
U = Bit no implementado, leído como '0'
bits 15-13
No implementado: leído como "0"
poco 12
EE. UU.: DSP multiplica el bit de control sin signo/con signo
1 = las multiplicaciones del motor DSP no están firmadas 
0 = los multiplicadores del motor DSP están firmados
poco 11
EDT: bit de control de terminación temprana del bucle DO (1)
1 = Terminar la ejecución del bucle DO al final de la iteración del bucle actual
0 = Sin efecto
bits 10-8
DL<2:0>: Bits de estado del nivel de anidamiento del bucle DO
111 = 7 bucles DO activos
•
•
•
001 = 1 bucle DO activo
000 = 0 bucles DO activos
poco 7
SATA: bit de habilitación de saturación AccA
1 = Saturación del acumulador A habilitada
0 = Saturación del acumulador A deshabilitada
poco 6
SATB: bit de habilitación de saturación AccB
1 = Saturación del acumulador B habilitada
0 = Saturación del acumulador B deshabilitada
poco 5
SATDW: Escritura en espacio de datos desde el bit de habilitación de saturación del motor DSP
1 = Saturación de escritura del espacio de datos habilitada
0 = Saturación de escritura del espacio de datos deshabilitada
poco 4
ACCSAT: Bit de selección del modo de saturación del acumulador
1 = 9,31 de saturación (supersaturación)
0 = 1,31 de saturación (saturación normal)
poco 3
IPL3: Bit de estado 3(2) del nivel de prioridad de interrupción de la CPU
1 = el nivel de prioridad de interrupción de la CPU es mayor que 7
0 = el nivel de prioridad de interrupción de la CPU es 7 o menos
poco 2
PSV: Visibilidad del espacio del programa en el bit de habilitación del espacio de datos
1 = Espacio de programa visible en el espacio de datos
0 = Espacio de programa no visible en el espacio de datos
poco 1
RND: bit de selección de modo de redondeo
1 = Redondeo sesgado (convencional) habilitado
0 = Redondeo imparcial (convergente) habilitado
poco 0
IF: Modo multiplicador entero o fraccionario Seleccionar bit
1 = Modo entero habilitado para operaciones multiplicadas DSP
0 = Modo fraccionario habilitado para operaciones múltiples de DSP
Nota 1: Este bit siempre se leerá como "0".
2: El bit IPL3 se concatena con los bits IPL<2:0> (SR<7:5>) para formar el nivel de prioridad de interrupción de la CPU.

© 2009 Microchip Technology Inc.
DS70286C-página 27
dsPIC33FJXXXGPX06/X08/X10
3.5
Unidad Aritmética Lógica (ALU)
El dsPIC33FJXXXGPX06/X08/X10 ALU es de 16 bits
de ancho y es capaz de realizar sumas, restas y cambios de bits
y operaciones lógicas. A menos que se mencione lo contrario,
Las operaciones aritméticas son de naturaleza complemento a 2.
Dependiendo de la operación, la ALU puede afectar la
valores de Carry (C), Cero (Z), Negativo (N),
Bits de estado de desbordamiento (OV) y acarreo de dígitos (DC) en el
Registro SR. Los bits de estado C y DC funcionan como Bor-
bits de fila y dígitos prestados, respectivamente, para resta
operaciones. 
La ALU puede realizar operaciones de 8 o 16 bits,
dependiendo del modo de la instrucción que se utilice.
Los datos para el funcionamiento de la ALU pueden provenir del W
matriz de registros o memoria de datos, según el
modo de direccionamiento de la instrucción. Asimismo, la salida
Los datos de la ALU se pueden escribir en la matriz de registros W.
o una ubicación de memoria de datos.
Consulte la “Referencia del programador dsPIC30F/33F
Manual” (DS70157) para obtener información sobre los bits SR
afectados por cada instrucción.
el 
dsPIC33FJXXXGPX06/X08/X10 
CPU
incorpora soporte hardware tanto para multiplicación
y división. Esto incluye un hardware dedicado.
hardware multiplicador y soporte para divisor de 16 bits
división. 
3.5.1
MULTIPLICADOR
Usando el multiplicador de alta velocidad de 17 bits x 17 bits del DSP
motor, la ALU admite señales sin firmar, firmadas o mixtas.
funcionamiento en varios modos de multiplicación de MCU:
1.
16 bits x 16 bits firmados
2.
16 bits x 16 bits sin firmar
3.
16 bits con signo x 5 bits (literal) sin signo
4.
16 bits sin firmar x 16 bits sin firmar
5.
16 bits sin signo x 5 bits (literal) sin signo
6.
16 bits sin firmar x 16 bits con firma
7.
8 bits sin firmar x 8 bits sin firmar 
3.5.2
DIVISOR
El bloque de división admite 32 bits/16 bits y 16 bits/16 bits
operaciones de división de enteros con y sin signo con el
siguientes tamaños de datos:
1.
División con signo de 32 bits/signo de 16 bits
2.
División de 32 bits sin signo/16 bits sin signo
3.
División de 16 bits con signo/16 bits con signo
4.
División de 16 bits sin signo/16 bits sin signo
El cociente de todas las instrucciones de división termina en W0
y el resto en W1. 16 bits firmados y sin firmar
Las instrucciones DIV pueden especificar cualquier registro W tanto para el
Divisor de 16 bits (Wn) y cualquier par de registros W (alineados)
(W(m + 1):Wm) para el dividendo de 32 bits. La división
El algoritmo toma un ciclo por bit de divisor, por lo que ambos
Las instrucciones de 32 bits/16 bits y 16 bits/16 bits toman el
mismo número de ciclos a ejecutar.
3.6
Motor DSP
el 
DSP 
motor 
consiste 
de 
un 
alta velocidad,
Multiplicador de 17 bits x 17 bits, palanca de cambios de barril y 40 bits
sumador/resta (con dos acumuladores de objetivos, redondos
y lógica de saturación).
El dsPIC33FJXXXGPX06/X08/X10 es un ciclo único,
arquitectura de flujo de instrucciones; por lo tanto, concurrente
El funcionamiento del motor DSP con el flujo de instrucciones MCU es
No es posible. Sin embargo, algunos motores MCU ALU y DSP
Los recursos pueden ser utilizados simultáneamente por el mismo
instrucción (por ejemplo, ED, EDAC).
El motor DSP también tiene la capacidad de realizar
operaciones inherentes de acumulador a acumulador que
no requieren datos adicionales. Estas instrucciones son AGREGAR,
SUB y NEG.
El motor DSP tiene varias opciones seleccionadas a través de
varios bits en el registro de control del núcleo de la CPU
(CORCON), como se detalla a continuación:
1.
Multiplicación DSP fraccionaria o entera (IF).
2.
Multiplicación de DSP con o sin signo (EE. UU.).
3.
Redondeo convencional o convergente (RND).
4.
Encendido/apagado automático de saturación para AccA (SATA).
5.
Encendido/apagado automático de saturación para AccB (SATB).
6.
Activación/desactivación automática de saturación para escritura de datos
memoria (SATDW).
7.
Selección del modo de saturación del acumulador (ACCSAT).
La Tabla 3-1 proporciona un resumen de las instrucciones DSP. un
El diagrama de bloques del motor DSP se muestra en
Figura 3-3.
TABLA 3-1:
INSTRUCCIONES DEL DSP 
RESUMEN
Instrucción
algebraico 
Operación
Escritura ACC 
Atrás
CLR
Una = 0
si
DE
A = (x – y)2
No
EDAC
A = A + (x – y)2
No
MAC
A = A + (x * y)
si
MAC
A = A + x2
No
MOVSAC
Sin cambios en A
si
MPY
A = x * y
No
MPY
A = x 2
No
MPY.N
A = – x * y
No
MSC
A = A – x * y
si

  

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 28
© 2009 Microchip Technology Inc.
FIGURA 3-3:
DIAGRAMA DE BLOQUES DEL MOTOR DSP
Reabastecimiento cero
Firmar-Extender
barril
palanca de cambios
Batería A de 40 bits
Acumulador B de 40 bits
redondo
Lógica
Bus de datos X
Hacia/desde matriz W
sumador
saturar
Negar
32
32
33
16
16
16
16 
40
40
40
40
S
un
t
ura
te
Bus de datos Y
40
Llevar/pedir prestado
Llevar/pedir prestado
16
40
Multiplicador/Escalador
17 bits

© 2009 Microchip Technology Inc. 
DS70286C-página 29 
dsPIC33FJXXXGPX06/X08/X10 
3.6.1 
MULTIPLICADOR 
El multiplicador de 17 bits x 17 bits es capaz de realizar operaciones con signo o 
operación sin firmar y puede multiplexar su salida usando un 
escalador para admitir 1.31 fraccionario (Q31) o 32 bits 
resultados enteros. Los operandos sin signo están extendidos a cero 
en el bit 17 del valor de entrada del multiplicador. Firmado 
Los operandos tienen extensión de signo hasta el bit 17 del 
valor de entrada del multiplicador. La salida de 17 bits x 17 bits. 
multiplicador/escalador 
es 
a 
33 bits 
valor 
cual 
es 
signo extendido a 40 bits. Los datos enteros son inherentemente 
representado como un valor en complemento a dos con signo, 
donde el bit más significativo (MSb) se define como un 
bit de signo. En términos generales, el rango de dos de N bits 
El entero complemento es -2N-1 a 2N-1 - 1. Para un sistema de 16 bits 
entero, el rango de datos es -32768 (0x8000) a 32767 
(0x7FFF) incluido 0. Para un entero de 32 bits, los datos 
rango 
es 
-2.147.483.648 
(0x8000 0000) 
a 
2,147,483,647 (0x7FFF FFFF). 
Cuando el multiplicador está configurado para fraccionario 
multiplicación, los datos se representan como dos 
fracción del complemento, donde el MSb se define como una 
bit de signo y se supone que el punto de base se encuentra justo después del 
bit de signo (formato QX). El rango de un dos de N bits 
La fracción del complemento con este punto de base implícito es -1,0. 
a (1 - 21-N). Para una fracción de 16 bits, el rango de datos Q15 es 
-1,0 (0x8000) a 0,999969482 (0x7FFF) incluido 0 
y tiene una precisión de 3.01518x10-5. En fraccionario 
modo, la operación de multiplicación de 16 x 16 genera un 1,31 
producto que tiene una precisión de 4,65661 x 10-10. 
El mismo multiplicador se utiliza para soportar la MCU. 
multiplicar instrucciones que incluyen números enteros de 16 bits 
Se multiplica el signo firmado, no firmado y mixto. 
La instrucción MUL puede estar dirigida a utilizar bytes o 
operandos del tamaño de una palabra. Los operandos de bytes dirigirán un sistema de 16 bits. 
resultado, y los operandos de palabra dirigirán un resultado de 32 bits a 
los registros especificados en la matriz W. 
3.6.2 
ACUMULADORES DE DATOS Y 
SUMA/RESTA 
El 
datos 
acumulador 
consiste 
de 
a 
40 bits 
Sumador/resta con lógica de extensión automática de signos. Él 
Puede seleccionar uno de los dos acumuladores (A o B) como su 
preacumulación 
fuente 
y 
post-acumulación 
destino. Para las instrucciones ADD y LAC, los datos 
a acumular o cargar se puede escalar opcionalmente 
a través de la palanca de cambios del barril antes de la acumulación. 
3.6.2.1 
Sumador/Resta, Desbordamiento y 
Saturación 
El sumador/restador es un sumador de 40 bits con un opcional 
entrada cero en un lado, y ya sea verdadero o complemento 
datos a la otra entrada. En el caso de la suma, el 
La entrada Llevar/Préstamo está activa-alta y la otra entrada está 
datos verdaderos (no complementados), mientras que en el caso de 
resta, la entrada Carry/Borrow está activa-baja y 
la otra entrada se complementa. El sumador/resta 
genera bits de estado de desbordamiento, SA/SB y OA/OB, 
que están bloqueados y reflejados en el ESTADO 
registro: 
• Desbordamiento del bit 39: esto es catastrófico 
desbordamiento en el que el signo del acumulador es 
destruido. 
• Desbordamiento en los bits de protección 32 a 39: este es un 
desbordamiento recuperable. Este bit se establece siempre que todos 
Los bits de protección no son idénticos entre sí. 
El sumador tiene un bloque de saturación adicional que 
controla la saturación de datos del acumulador, si se selecciona. Él 
utiliza el resultado del sumador, los bits de estado de desbordamiento 
descrito anteriormente y el SAT<A:B> (CORCON<7:6>) 
y bits de control del modo ACCSAT (CORCON<4>) para 
determinar cuándo y hasta qué valor saturar. 
Se han proporcionado seis bits de registro de ESTADO para 
apoyar la saturación y el desbordamiento; ellos son: 
1. 
AA: 
AccA se desbordó en bits de guardia 
2. 
TRANSMISIÓN EXTERIOR: 
AccB se desbordó en bits de guardia 
3. 
EN: 
AccA saturado (bit 31 desbordamiento y saturación) 
o 
AccA se desbordó en bits de protección y se saturó 
(bit 39 desbordamiento y saturación) 
4. 
SB: 
AccB saturado (bit 31 desbordamiento y saturación) 
o 
AccB se desbordó en bits de guardia y se saturó 
(bit 39 desbordamiento y saturación) 
5. 
VH: 
O lógico de OA y OB 
6. 
SAB: 
O lógico de SA y SB 
Los bits OA y OB se modifican cada vez que se transmiten datos. 
pasa por el sumador/restador. Cuando se configuran, 
indicar que la operación más reciente se ha desbordado 
en los bits de protección del acumulador (bits 32 a 39). 
Los bits OA y OB también pueden generar opcionalmente un 
aritmética 
advertencia 
trampa 
cuando 
colocar 
y 
el 
correspondientes bits de habilitación del indicador de trampa de desbordamiento (OVATE, 
OVBTE) en el registro INTCON1 (consulte la Sección 7.0 
“Controlador de interrupciones”) están configurados. Esto permite al usuario 
tomar medidas inmediatas, por ejemplo, para corregir el sistema 
ganar. 

dsPIC33FJXXXGPX06/X08/X10 
DS70286C-página 30 
© 2009 Microchip Technology Inc. 
Los bits SA y SB se modifican cada vez que se transmiten datos. 
pasa por el sumador/resta, pero sólo puede ser 
borrado por el usuario. Cuando se configuran, indican que el 
El acumulador ha rebasado su rango máximo (bit 31). 
para saturación de 32 bits o bit 39 para saturación de 40 bits) y 
se saturará (si la saturación está habilitada). Cuando 
la saturación no está habilitada, SA y SB están predeterminados en el bit 39 
desbordamiento y, por lo tanto, indican que una catastrófica 
se ha producido un desbordamiento. Si el bit COVTE en el 
El registro INTCON1 está configurado, los bits SA y SB generarán 
una trampa de advertencia aritmética cuando la saturación está desactivada. 
Los bits de estado de desbordamiento y saturación pueden opcionalmente 
ser visto en el Registro STATUS (SR) como el registro lógico 
OR de OA y OB (en bit OAB) y el OR lógico de SA 
y SB (en bits SAB). Esto permite a los programadores comprobar 
un bit en el registro STATUS para determinar si 
acumulador se ha desbordado, o un bit para determinar si 
cualquiera de los acumuladores se ha saturado. esto seria util 
para aritmética de números complejos que normalmente utiliza 
ambos acumuladores. 
El dispositivo admite tres niveles de saturación y desbordamiento. 
modos: 
1. 
Bit 39 Desbordamiento y Saturación: 
Cuando se produce el desbordamiento y la saturación del bit 39, el 
la lógica de saturación carga el máximo positivo 9.31 
(0x7FFFFFFFFF), o máximo negativo 9,31 
valor 
(0x8000000000), 
en 
el 
objetivo 
acumulador. El bit SA o SB está establecido y permanece 
establecido hasta que el usuario lo borre. Esto se conoce como 
"supersaturación" y proporciona protección contra 
erróneo 
datos 
o 
inesperado 
algoritmo 
problemas (por ejemplo, cálculos de ganancia). 
2. 
Bit 31 Desbordamiento y Saturación: 
Cuando se produce el desbordamiento y la saturación del bit 31, el 
La lógica de saturación luego carga al máximo 
positivo 
1.31 
valor 
(0x007FFFFFFFF), 
o 
valor máximo negativo 1,31 (0x0080000000), 
en el acumulador de destino. El bit SA o SB es 
configurado y permanece así hasta que el usuario lo borre. 
Cuando este modo de saturación está en efecto, el 
Los bits de guarda no se utilizan (por lo que OA, OB u OAB 
los bits nunca se establecen). 
3. 
Bit 39 Desbordamiento catastrófico: 
El bit 39 de estado de desbordamiento del sumador es 
se utiliza para configurar el bit SA o SB, que permanece configurado 
hasta que el usuario lo autorice. Sin operación de saturación 
se realiza y se permite que el acumulador 
desbordamiento (destruyendo su signo). Si el COVTE mordió 
el registro INTCON1 está configurado, un catastrófico 
el desbordamiento puede iniciar una excepción de trampa. 
3.6.2.2 
Acumulador "Reescritura" 
La clase MAC de instrucciones (con la excepción de 
MPY, MPY.N, ED y EDAC) pueden escribir opcionalmente un 
versión redondeada de la palabra alta (bits 31 a 16) 
del acumulador que no está apuntado por la instrucción 
en la memoria del espacio de datos. La escritura se realiza a lo largo 
el bus X en el espacio de direcciones combinado X e Y. El 
Se admiten los siguientes modos de direccionamiento: 
1. 
W13, Registro directo: 
El contenido redondeado del no objetivo. 
acumulador se escriben en W13 como un 
1,15 fracción. 
2. 
[W13]+ = 2, Registro Indirecto con Post-Incremento: 
El contenido redondeado del no objetivo. 
acumulador se escriben en la dirección señalada 
por W13 como fracción de 1,15. W13 es entonces 
incrementado en 2 (para escribir una palabra). 
3.6.2.3 
Lógica redonda 
La lógica redonda es un bloque combinacional que 
realiza un convencional (sesgado) o convergente 
Función redonda (imparcial) durante una escritura del acumulador 
(almacenar). El modo Redondo está determinado por el estado de 
el bit RND en el registro CORCON. Genera un 
Valor de datos de 16 bits y 1,15 que se pasa a los datos 
Lógica de saturación de escritura espacial. Si no se indica el redondeo 
mediante la instrucción, se almacena un valor de datos truncado de 1,15 
y la palabra menos significativa simplemente se descarta. 
El redondeo a cero convencional extiende el bit 15 del 
acumulador y lo suma a la palabra ACCxH (bits 16 
hasta 31 del acumulador). Si la palabra ACCxL 
(bits 0 a 15 del acumulador) está entre 
0x8000 y 0xFFFF (0x8000 incluido), ACCxH es 
incrementado. Si ACCxL está entre 0x0000 y 0x7FFF, 
ACCxH no se modifica. Una consecuencia de esto 
algoritmo es que sobre una sucesión de redondeo aleatorio 
operaciones, el valor tiende a estar ligeramente sesgado 
positivo. 
El redondeo convergente (o insesgado) opera en el 
misma manera que el redondeo convencional, excepto cuando 
ACCxL es igual a 0x8000. En este caso, el menor 
El bit significativo (bit 16 del acumulador) de ACCxH es 
examinado. Si es '1', se incrementa ACCxH. Si es '0', 
ACCxH no se modifica. Suponiendo que el bit 16 es 
efectivamente aleatorio por naturaleza, este esquema elimina cualquier 
sesgo de redondeo que puede acumularse. 
Las instrucciones SAC y SAC.R almacenan ya sea un 
versión truncada (SAC) o redondeada (SAC.R) del 
contenido del acumulador de destino a la memoria de datos a través 
el 
incógnita 
autobús, 
sujeto 
a 
datos 
saturación 
(ver 
Sección 3.6.2.4 “Saturación de escritura en el espacio de datos”). Para 
la clase MAC de instrucciones, el acumulador 
la operación de reescritura funcionará de la misma manera, 
abordar el espacio de datos combinado de MCU (X e Y) 
a través del autobús X. Para esta clase de instrucciones, los datos 
siempre está sujeto a redondeo. 

© 2009 Microchip Technology Inc.
DS70286C-página 31
dsPIC33FJXXXGPX06/X08/X10
3.6.2.4
Saturación de escritura en el espacio de datos
Además de la saturación del sumador/restador, escribe en los datos
El espacio también se puede saturar pero sin afectar la
contenido del acumulador fuente. El espacio de datos
El bloque lógico de saturación de escritura acepta 16 bits, 1,15
valor fraccionario del bloque lógico redondo como entrada,
junto con el estado de desbordamiento de la fuente original
(acumulador) y el sumador redondo de 16 bits. Estas entradas
se combinan y se utilizan para seleccionar el 1,15 adecuado
valor fraccionario como salida para escribir en el espacio de datos
memoria.
Si se establece el bit SATDW en el registro CORCON, los datos
(después del redondeo o truncamiento) se prueba para detectar desbordamiento y
ajustado en consecuencia, para datos de entrada mayores que
0x007FFF, los datos escritos en la memoria se fuerzan al
valor máximo positivo 1,15, 0x7FFF. Para datos de entrada
menos de 0xFF8000, los datos escritos en la memoria se fuerzan
al valor máximo negativo 1,15, 0x8000. el
El bit más significativo de la fuente (bit 39) se utiliza para
determinar el signo del operando que se está probando.
Si el bit SATDW en el registro CORCON no está establecido, el
Los datos de entrada siempre se pasan sin modificar en
todas las condiciones.
3.6.3
CAMBIADOR DE BARRIL
La palanca de cambios de barril es capaz de funcionar con hasta 16 bits.
desplazamientos aritméticos o lógicos a la derecha, o desplazamientos a la izquierda de hasta 16 bits
en un solo ciclo. La fuente puede ser cualquiera de las dos.
acumuladores DSP o el bus X (para soportar multi-bit
cambios de registro o datos de memoria).
La palanca de cambios requiere un valor binario con signo para determinar
tanto la magnitud (número de bits) como la dirección de la
operación de turno. Un valor positivo desplaza el operando hacia la derecha.
Un valor negativo desplaza el operando hacia la izquierda. Un valor de '0'
no modifica el operando.
La palanca de cambio de barril tiene 40 bits de ancho, obteniendo así una
Resultado de 40 bits para operaciones de cambio de DSP y resultado de 16 bits
para operaciones de turno de MCU. Los datos del bus X son
presentado a la palanca de cambios del cañón entre las posiciones de la broca 16
a 31 para desplazamientos a la derecha y entre las posiciones de bits 0 a 16
para turnos a la izquierda.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 32
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70286C-página 33
dsPIC33FJXXXGPX06/X08/X10
4.0
ORGANIZACIÓN DE LA MEMORIA
el 
dsPIC33FJXXXGPX06/X08/X10 
arquitectura
cuenta con espacios separados de memoria de programas y datos
y autobuses. Esta arquitectura también permite la conexión directa
acceso a la memoria del programa desde el espacio de datos durante
ejecución de código.
4.1
Espacio de direcciones del programa
el 
programa 
dirección 
memoria 
espacio 
de 
el
dsPIC33FJXXXGPX06/X08/X10 
dispositivos 
es 
4M
instrucciones. El espacio es direccionable mediante un sistema de 24 bits.
valor derivado del contador de programa de 23 bits
(PC) durante la ejecución del programa o desde la operación de la tabla
o reasignación del espacio de datos como se describe en la Sección 4.6
“Programa de interfaz y espacios de memoria de datos”. 
El acceso del usuario al espacio de la memoria del programa está restringido
a la mitad inferior del rango de direcciones (0x000000 a
0x7FFFFF). La excepción es el uso de TBLRD/TBLWT.
operaciones, que utilizan TBLPAG<7> para permitir el acceso a
las secciones Bits de configuración e ID del dispositivo de la
espacio de memoria de configuración. Uso de memoria para el
dsPIC33FJXXXGPX06/X08/X10 de dispositivos se muestra en
Figura 4-1.
FIGURA 4-1:
MEMORIA DE PROGRAMA PARA DISPOSITIVOS dsPIC33FJXXXGPX06/X08/X10 
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 3. “Datos
Memoria” (DS70202) y Sección 4.
“Memoria de programa” (DS70203) en el
“Manual de referencia de la familia dsPIC33F”,
que está disponible en la web de Microchip
sitio (www.microchip.com).
Restablecer dirección
0x000000
0x0000FE
0x000002
0x000100
Configuración del dispositivo
Programa de usuario
Memoria flash
0x00AC00
0x00ABFE
(22K instrucciones)
0x800000
0xF80000
Registros 
0xF80017
0xF80010
DEVIDO (2)
0xFEFFFE
0xFF0000
0xFFFFFE
0xF7FFFE
No implementado
(Lea '0's)
Instrucción IR A
0x000004
Reservado
0x7FFFFE
Reservado
0x000200
0x0001FE
0x000104
Tabla de vectores alternativos
Reservado
Tabla de vectores de interrupción
Restablecer dirección
Configuración del dispositivo
Registros 
DEVIDO (2)
No implementado
(Lea '0's)
Instrucción IR A
Reservado
Reservado
Tabla de vectores alternativos
Reservado
Tabla de vectores de interrupción
Restablecer dirección
Configuración del dispositivo
Programa de usuario
Memoria flash
(88K instrucciones)
Registros 
DEVIDO (2)
Instrucción IR A
Reservado
Reservado
Tabla de vectores alternativos
Reservado
Tabla de vectores de interrupción
dsPIC33FJ64GPXXX
dsPIC33FJ128GPXXX
dsPIC33FJ256GPXXX
Espacio de memoria de configuración
Espacio de memoria del usuario
0x015800
0x0157FE
Nota:
Las áreas de memoria no se muestran a escala.
Programa de usuario
(Instrucciones de 44K)
Memoria flash
(Lea '0's)
No implementado
0x02AC00
0x02ABFE

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 34
© 2009 Microchip Technology Inc.
4.1.1
MEMORIA DE PROGRAMA 
ORGANIZACIÓN
El espacio de memoria del programa está organizado en
bloques direccionables por palabras. Aunque es tratado como
24 bits de ancho, es más apropiado pensar en cada uno
Dirección de la memoria del programa como inferior y superior.
palabra, siendo el byte superior de la palabra superior
no implementado. La palabra inferior siempre tiene un par
dirección, mientras que la palabra superior tiene una dirección impar
(Figura 4-2). 
Las direcciones de memoria del programa siempre están alineadas con palabras.
en la palabra inferior y las direcciones se incrementan o
disminuido en dos durante la ejecución del código. esto
La disposición también proporciona compatibilidad con los datos.
direccionamiento del espacio de memoria y permite
acceder a los datos en el espacio de memoria del programa.
4.1.2
VECTORES DE INTERRUPCIÓN Y TRAMPA
Reserva de todos los dispositivos dsPIC33FJXXXGPX06/X08/X10
las direcciones entre 0x00000 y 0x000200 para
vectores de ejecución de programas codificados. un hardware
Se proporciona un vector de reinicio para redirigir la ejecución del código.
desde el valor predeterminado de la PC en el dispositivo Restablecer al
inicio real del código. Se programa una instrucción GOTO
por el usuario en 0x000000, con la dirección real del
inicio del código en 0x000002. 
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 también tienen
dos tablas de vectores de interrupción, ubicadas desde 0x000004 hasta
0x0000FF y 0x000100 a 0x0001FF. Estos vectores
Las tablas permiten cada una de las muchas fuentes de interrupción del dispositivo.
ser manejado por Rutinas de Servicio de Interrupción separadas
(ISR). Una discusión más detallada sobre la interrupción.
Las tablas de vectores se proporcionan en la Sección 7.1 “Interrupción
Tabla de vectores”.
FIGURA 4-2:
ORGANIZACIÓN DE LA MEMORIA DEL PROGRAMA
0
8
16
Dirección de PC
0x000000
0x000002
0x000004
0x000006
23
00000000
00000000
00000000
00000000
Memoria de programa
Byte 'fantasma'
(leído como '0')
palabra menos significativa
palabra más significativa
Ancho de instrucción
0x000001
0x000003
0x000005
0x000007
msw
Dirección
(dirección lsw)

© 2009 Microchip Technology Inc. 
DS70286C-página 35 
dsPIC33FJXXXGPX06/X08/X10 
4.2 
Espacio de direcciones de datos 
La CPU dsPIC33FJXXXGPX06/X08/X10 tiene una 
espacio de memoria de datos separado de 16 bits de ancho. los datos 
Se accede al espacio mediante generación de direcciones separada. 
Unidades (AGU) para operaciones de lectura y escritura. Datos 
Los mapas de memoria de dispositivos con diferentes tamaños de RAM son 
se muestra en la Figura 4-3 a la Figura 4-5. 
Todas las direcciones efectivas (EA) en el espacio de memoria de datos 
tienen 16 bits de ancho y apuntan a bytes dentro del espacio de datos. 
Esta disposición proporciona un rango de direcciones de espacio de datos de 
64 Kbytes o 32 K palabras. La mitad inferior de los datos. 
espacio de memoria (es decir, cuando EA<15> = 0) se utiliza para 
direcciones de memoria implementadas, mientras que la mitad superior 
(EA<15> = 1) está reservado para el espacio del programa 
Área de visibilidad (consulte la Sección 4.6.3 “Lectura de datos de 
Memoria de programa utilizando la visibilidad del espacio de programa”). 
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 implementan un 
total de hasta 30 Kbytes de memoria de datos. ¿Debería un EA 
apuntar a una ubicación fuera de esta área, una palabra de ceros 
o se devolverá un byte. 
4.2.1 
ANCHO DE ESPACIO DE DATOS 
El espacio de la memoria de datos está organizado en bytes. 
bloques direccionables de 16 bits de ancho. Los datos están alineados en datos. 
memoria y registros como palabras de 16 bits, pero todos los datos 
Los EA de espacio se resuelven en bytes. El menos significativo 
Los bytes (LSB) de cada palabra tienen direcciones pares, mientras que 
los bytes más significativos (MSB) tienen valores impares 
direcciones. 
4.2.2 
ORGANIZACIÓN DE LA MEMORIA DE DATOS 
Y ALINEACIÓN 
Para mantener la compatibilidad con versiones anteriores de PIC® MCU 
dispositivos y mejorar el uso de la memoria del espacio de datos 
eficiencia, 
el 
dsPIC33FJXXXGPX06/X08/X10 
El conjunto de instrucciones admite operaciones de palabras y bytes. 
Como consecuencia de la accesibilidad de bytes, todos los efectivos 
los cálculos de direcciones se escalan internamente al paso 
a través de la memoria alineada con palabras. Por ejemplo, el núcleo 
reconoce 
eso 
Post-modificado 
Registro 
Indirecto 
El modo de direccionamiento [Ws++] dará como resultado un valor de Ws + 1 
para operaciones de bytes y Ws + 2 para operaciones de palabras. 
Las lecturas de bytes de datos leerán la palabra completa que 
contiene el byte, utilizando el LSb de cualquier EA para determinar 
qué byte seleccionar. El byte seleccionado se coloca en 
el LSb de la ruta de datos. Es decir, memoria de datos y 
Los registros están organizados como dos bytes paralelos. 
entidades con dirección compartida (palabra) decodifican pero 
líneas de escritura separadas. Las escrituras de bytes de datos solo se escriben en el 
lado correspondiente de la matriz o registro que 
coincide con la dirección del byte. 
Todos los accesos a palabras deben estar alineados con una dirección par. 
No se admiten recuperaciones de datos de palabras desalineadas, por lo que 
Se debe tener cuidado al mezclar bytes y palabras. 
operaciones o traducción de código MCU de 8 bits. si un 
Se intenta una lectura o escritura desalineada, un error de dirección 
Se genera trampa. Si el error ocurrió en una lectura, el 
se completa la instrucción en curso; si ocurrió en un 
escribir, la instrucción se ejecutará pero la escritura no 
no ocurrir. En cualquier caso, se ejecuta una trampa, 
permitiendo al sistema y/o al usuario examinar el 
Estado de la máquina antes de la ejecución de la dirección de fallo. 
Todas las cargas de bytes en cualquier registro W se cargan en el 
Byte menos significativo. El byte más significativo no es 
modificado. 
Se proporciona una instrucción de extensión de signo (SE) para permitir 
usuarios para traducir datos firmados de 8 bits a datos firmados de 16 bits 
valores. Alternativamente, para datos sin firmar de 16 bits, los usuarios 
Puede borrar el MSb de cualquier registro W ejecutando un 
instrucción de extensión cero (ZE) en el correspondiente 
DIRECCIÓN. 
4.2.3 
ESPACIO SFR 
Los primeros 2 Kbytes del Near Data Space, desde 0x0000 
a 0x07FF, está ocupado principalmente por función especial 
Registros 
(SFR). 
Estos 
son 
usado 
por 
el 
dsPIC33FJXXXGPX06/X08/X10 núcleo y periférico 
Módulos para controlar el funcionamiento del dispositivo. 
Los SFR se distribuyen entre los módulos que 
control, y generalmente se agrupan por módulo. 
Gran parte del espacio SFR contiene direcciones no utilizadas; 
estos se leen como "0". Una lista completa de implementadas 
Los SFR, incluidas sus direcciones, se muestran en la Tabla 4-1. 
a través de la Tabla 4-34. 
4.2.4 
CERCA DEL ESPACIO DE DATOS 
El área de 8 Kbytes entre 0x0000 y 0x1FFF es 
denominado Espacio Cercano a los Datos. Ubicaciones en este 
El espacio es direccionable directamente a través de un absoluto de 13 bits. 
campo de dirección dentro de todas las instrucciones directas de memoria. 
Además, todo el espacio de datos es direccionable mediante 
Instrucciones MOV, que admiten Memory Direct 
Modo de direccionamiento con un campo de dirección de 16 bits, o mediante 
usando el modo de direccionamiento indirecto usando un 
registrarse como puntero de dirección. 
Nota: 
El conjunto real de características periféricas y 
Las interrupciones varían según el dispositivo. Por favor 
consulte las tablas de dispositivos correspondientes 
y diagramas de distribución de pines para dispositivos específicos 
información. 

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 36
© 2009 Microchip Technology Inc.
FIGURA 4-3:
MAPA DE MEMORIA DE DATOS PARA DISPOSITIVOS dsPIC33FJXXXGPX06/X08/X10 DE 8 KBS 
RAM 
0x0000
0x07FE
0x17FE
0xFFFE
LSB
Dirección
16 bits
LSB
MSB
MSB
Dirección
0x0001
0x07FF
0x17FF
0xFFFF
Opcionalmente
mapeado
en el programa
Memoria
0x27FF
0x27FE
0x0801
0x0800
0x1801
0x1800
2 KB
Espacio SFR
8 KB
Espacio SRAM
0x8001
0x8000
0x2800
0x2801
 
0x1FFE
0x2000
0x1FFF
0x2001
espacio
Datos
cerca
8 KB
Espacio SFR
X RAM de datos (X)
X datos
No implementado (X)
RAM DMA
RAM de datos (Y)

© 2009 Microchip Technology Inc.
DS70286C-página 37
dsPIC33FJXXXGPX06/X08/X10
FIGURA 4-4:
MAPA DE MEMORIA DE DATOS PARA DISPOSITIVOS dsPIC33FJXXXGPX06/X08/X10 DE 16 KB 
RAM 
0x0000
0x07FE
0x27FE
0xFFFE
LSB
Dirección
16 bits
LSB
MSB
MSB
Dirección
0x0001
0x07FF
0x27FF
0xFFFF
Opcionalmente
mapeado
en el programa
Memoria
0x47FF
0x47FE
0x0801
0x0800
0x2801
0x2800
cerca
Datos
 
2 KB
Espacio SFR
16 Kbytes
Espacio SRAM
8 KB
espacio
0x8001
0x8000
0x4800
0x4801
 
0x3FFE
0x4000
0x3FFF
0x4001
0x1FFE
0x1FFF
Espacio SFR
X RAM de datos (X)
X datos
No implementado (X)
RAM DMA
RAM de datos (Y)

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 38
© 2009 Microchip Technology Inc.
FIGURA 4-5:
MAPA DE MEMORIA DE DATOS PARA DISPOSITIVOS dsPIC33FJXXXGPX06/X08/X10 DE 30 KB 
RAM 
0x0000
0x07FE
Espacio SFR
0xFFFE
X RAM de datos (X)
    
16 bits
LSB
MSB
0x0001
0x07FF
0xFFFF
X datos 
Opcionalmente
mapeado
en el programa
Memoria
No implementado (X)
0x0801
0x0800
   
2 KB
Espacio SFR
0x4800
0x47FE
0x4801
0x47FF
0x7FFE
0x8000
30 KB
Espacio SRAM
0x7FFF
0x8001
RAM de datos (Y)
cerca
Datos
8 KB
espacio
0x77FE
0x7800
0x77FF
0x7800
LSB
Dirección
MSB
Dirección
RAM DMA

© 2009 Microchip Technology Inc.
DS70286C-página 39
dsPIC33FJXXXGPX06/X08/X10
4.2.5
ESPACIOS DE DATOS X E Y
El núcleo tiene dos espacios de datos, X e Y. Estos datos
Los espacios pueden considerarse separados (para algunos
instrucciones DSP), o como una dirección lineal unificada
rango (para instrucciones de MCU). Los espacios de datos son
Se accede mediante dos unidades de generación de direcciones (AGU)
y rutas de datos separadas. Esta característica permite ciertos
instrucciones para recuperar simultáneamente dos palabras de la RAM,
permitiendo así la ejecución eficiente de algoritmos DSP
como el filtrado de respuesta de impulso finito (FIR) y
Transformada Rápida de Fourier (FFT).
El espacio de datos X es utilizado por todas las instrucciones y
Soporta todos los modos de direccionamiento. hay separados
leer y escribir buses de datos para el espacio de datos X. La X lee
El bus de datos es la ruta de lectura de datos para todas las instrucciones que
Ver el espacio de datos como espacio de direcciones X e Y combinado.
También es la ruta de captación previa de datos X para el operando dual.
Instrucciones DSP (clase MAC). 
El espacio de datos Y se utiliza junto con los datos X.
espacio por la clase MAC de instrucciones (CLR, ED,
EDAC, MAC, MOVSAC, MPY, MPY.N y MSC) para proporcionar
dos rutas de lectura de datos simultáneas. 
Tanto el espacio de datos X como el Y soportan Módulo
Modo de direccionamiento para todas las instrucciones, sujeto a
Restricciones de modo de direccionamiento. Direccionamiento de bits invertidos
El modo solo se admite para escrituras en el espacio de datos X.
Todas las escrituras de datos en la memoria, incluidas las instrucciones DSP,
Ver el espacio de datos como espacio de direcciones X e Y combinado.
El límite entre los espacios de datos X e Y es
Depende del dispositivo y no es programable por el usuario. 
Todas las direcciones efectivas tienen 16 bits de ancho y apuntan a
bytes dentro del espacio de datos. Por tanto, el espacio de datos
El rango de direcciones es de 64 Kbytes o 32 K palabras, aunque el
Las ubicaciones de memoria implementadas varían según el dispositivo.
4.2.6
RAM DMA
Cada dispositivo dsPIC33FJXXXGPX06/X08/X10 contiene
2 Kbytes de RAM DMA de doble puerto ubicada al final de
Espacio de datos Y. Las ubicaciones de memoria son parte de la RAM de datos Y
y está en el espacio DMA RAM son accesibles
simultáneamente por la CPU y el controlador DMA
módulo. El controlador DMA utiliza RAM DMA para
almacenar datos para transferirlos a varios periféricos utilizando
DMA, así como los datos transferidos desde varios
periféricos mediante DMA. La RAM DMA puede ser
accedido por el controlador DMA sin tener que robar
ciclos de la CPU.
Cuando la CPU y el controlador DMA intentan
escribe simultáneamente en la misma ubicación de DMA RAM, el
El hardware garantiza que la CPU tenga prioridad en
acceder a la ubicación de DMA RAM. Por lo tanto, la DMA
La RAM proporciona un medio confiable para transferir DMA
datos sin tener que detener la CPU.
Nota:
DMA RAM se puede utilizar para fines generales.
propósito de almacenamiento de datos si la función DMA
no es obligatorio en una solicitud.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 40
© 2009 Microchip Technology Inc.
 
TABLA 4-1:
MAPA DE REGISTROS DEL NÚCLEO DE CPU
Nombre SFR
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
WREG0
0000
Registro de trabajo 0
0000
WREG1
0002
Registro de trabajo 1
0000
WREG2
0004
Registro de Trabajo 2
0000
WREG3
0006
Registro de Trabajo 3
0000
WREG4
0008
Registro de Trabajo 4
0000
WREG5
000A
Registro de Trabajo 5
0000
WREG6
000C
Registro de Trabajo 6
0000
WREG7
000E
Registro de Trabajo 7
0000
WREG8
0010
Registro de Trabajo 8
0000
WREG9
0012
Registro de Trabajo 9
0000
WREG10
0014
Registro de Trabajo 10
0000
WREG11
0016
Registro de Trabajo 11
0000
WREG12
0018
Registro de Trabajo 12
0000
WREG13
001A
Registro de Trabajo 13
0000
WREG14
001C
Registro de Trabajo 14
0000
WREG15
001E
Registro de Trabajo 15
0800
SPLIM
0020
Registro de límite de puntero de pila
xxxx
ACCAL
0022
Acumulador Un registro de palabras bajas
0000
ACCA
0024
Acumulador Un registro de palabras altas
0000
ACCA
0026
Acumulador A Registro de palabras superiores
0000
ACBL
0028
Registro de palabras bajas del acumulador B
0000
ACBH
002A
Registro de palabras altas del acumulador B
0000
ACBU
002C
Registro de palabras superiores del acumulador B
0000
PCL
002E
Registro de palabras bajas del contador de programa
0000
PCH
0030
—
—
—
—
—
—
—
—
Registro de bytes altos del contador de programa
0000
TBLPAG
0032
—
—
—
—
—
—
—
—
Registro de puntero de dirección de página de tabla
0000
PSVPAG
0034
—
—
—
—
—
—
—
—
Registro de puntero de dirección de página de visibilidad de memoria de programa
0000
RCONTAR
0036
Repetir registro del contador de bucles
xxxx
DCUENTO
0038
DCUENTO<15:0>
xxxx
DOSTARL
003A
DOSTARL<15:1>
0
xxxx
DOSTARTH
003C
—
—
—
—
—
—
—
—
—
—
DOSTARTH<5:0>
00xx
DOENDL
003E
DOENDL<15:1>
0
xxxx
DOENDH
0040
—
—
—
—
—
—
—
—
—
—
DOENDH
00xx
SR
0042
OA
OB
SA
SB
VH
SAB
DA
CC
IPL2
IPL1
IPL0
RA
norte
VO
z
c
0000
CORCÓN
0044
—
—
—
Estados Unidos
hora del Este
DL<2:0>
sata
SATB
SATDW
ACCESAT
IPL3
PSV
RND
SI
0020
MODCON
0046
XMODEN
YMODEN
—
—
BWM<3:0>
JUM<3:0>
XWM<3:0>
0000
XMODSRT
0048
XS<15:1>
0
xxxx
XMODEND
004A
XE<15:1>
1
xxxx
YMODSRT
004C
SÍ<15:1>
0
xxxx
YMODEND
004E
SÍ<15:1>
1
xxxx
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

© 2009 Microchip Technology Inc.
DS70286C-página 41
dsPIC33FJXXXGPX06/X08/X10
XBREV
0050
BREN
XB<14:0>
xxxx
DISICTO
0052
—
—
Deshabilitar el registro del contador de interrupciones
xxxx
BSRAM
0750
—
—
—
—
—
—
—
—
—
—
—
—
—
IW_BSR
IR_BSR
RL_BSR
0000
SSRAM
0752
—
—
—
—
—
—
—
—
—
—
—
—
—
IW_SSR
IR_SSR
RL_SSR
0000
TABLA 4-1:
MAPA DE REGISTROS DEL NÚCLEO DE CPU (CONTINUACIÓN)
Nombre SFR
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 42
© 2009 Microchip Technology Inc.
TABLA 4-2:
CAMBIAR EL MAPA DE REGISTRO DE NOTIFICACIONES PARA DISPOSITIVOS dsPIC33FJXXXGPX10
SFR 
 Nombre
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
CNEN1
0060
CN15IE
CN14IE
CN13IE
CN12IE
CN11IE
CN10IE
CN9IE
CN8IE
CN7IE
CN6IE
CN5IE
CN4IE
CN3IE
CN2IE
CN1IE
CN0IE
0000
CNEN2
0062
—
—
—
—
—
—
—
—
CN23IE
CN22IE
CN21IE
CN20IE
CN19IE
CN18IE
CN17IE
CN16IE
0000
CNPU1
0068
CN15PUE CN14PUE CN13PUE CN12PUE CN11PUE
CN10PUE
CN9PUE
CN8PUE
CN7PUE
CN6PUE
CN5PUE
CN4PUE
CN3PUE
CN2PUE
CN1PUE
CN0PUE
0000
CNPU2
006A
—
—
—
—
—
—
—
—
CN23PUE CN22PUE CN21PUE CN20PUE CN19PUE CN18PUE CN17PUE CN16PUE
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.
TABLA 4-3:
CAMBIAR MAPA DE REGISTRO DE NOTIFICACIONES PARA DISPOSITIVOS dsPIC33FJXXXGPX08
SFR 
 Nombre
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
CNEN1
0060
CN15IE
CN14IE
CN13IE
CN12IE
CN11IE
CN10IE
CN9IE
CN8IE
CN7IE
CN6IE
CN5IE
CN4IE
CN3IE
CN2IE
CN1IE
CN0IE
0000
CNEN2
0062
—
—
—
—
—
—
—
—
—
—
CN21IE
CN20IE
CN19IE
CN18IE
CN17IE
CN16IE
0000
CNPU1
0068
CN15PUE CN14PUE CN13PUE CN12PUE CN11PUE
CN10PUE
CN9PUE
CN8PUE
CN7PUE
CN6PUE
CN5PUE
CN4PUE
CN3PUE
CN2PUE
CN1PUE
CN0PUE
0000
CNPU2
006A
—
—
—
—
—
—
—
—
—
—
CN21PUE CN20PUE CN19PUE CN18PUE CN17PUE CN16PUE
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.
TABLA 4-4:
CAMBIAR MAPA DE REGISTRO DE NOTIFICACIONES PARA DISPOSITIVOS dsPIC33FJXXXGPX06
SFR 
 Nombre
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
CNEN1
0060
CN15IE
CN14IE
CN13IE
CN12IE
CN11IE
CN10IE
CN9IE
CN8IE
CN7IE
CN6IE
CN5IE
CN4IE
CN3IE
CN2IE
CN1IE
CN0IE
0000
CNEN2
0062
—
—
—
—
—
—
—
—
—
—
CN21IE
CN20IE
—
CN18IE
CN17IE
CN16IE
0000
CNPU1
0068
CN15PUE CN14PUE CN13PUE CN12PUE CN11PUE
CN10PUE
CN9PUE
CN8PUE
CN7PUE
CN6PUE
CN5PUE
CN4PUE
CN3PUE
CN2PUE
CN1PUE
CN0PUE
0000
CNPU2
006A
—
—
—
—
—
—
—
—
—
—
CN21PUE CN20PUE
—
CN18PUE CN17PUE CN16PUE
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

© 2009 Microchip Technology Inc.
DS70286C-página 43
dsPIC33FJXXXGPX06/X08/X10
 
TABLA 4-5:
MAPA DE REGISTRO DEL CONTROLADOR DE INTERRUPCIONES
SFR 
Nombre
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos
Se reinicia
INTCON1
0080
NSTDIS
OVAERR
OVBERR COVAERR COVBERR
OVADO
OVBTE
COVTE
SFTACERR DIV0ERR DMACERR MATHERR DIRECCIÓN
STKERR
OSCFAIL
—
0000
INTCON2
0082
ALTIVT
DISI
—
—
—
—
—
—
—
—
—
INT4EP
INT3EP
INT2EP
INT1EP
INT0EP
0000
IFS0
0084
—
DMA1IF
AD1IF
U1TXIF
U1RXIF
SPI1IF
SPI1EIF
T3IF
T2IF
OC2IF
IC2IF
DMA0IF
T1IF
OC1IF
IC1IF
INT0IF
0000
IFS1
0086
U2TXIF
U2RXIF
INT2IF
T5IF
T4IF
OC4IF
OC3IF
DMA2IF
IC8IF
IC7IF
AD2IF
INT1IF
CNIF
—
MI2C1IF
SI2C1IF
0000
IFS2
0088
T6IF
DMA4IF
—
OC8IF
OC7IF
OC6IF
OC5IF
IC6IF
IC5IF
IC4IF
IC3IF
DMA3IF
C1IF
C1RXIF
SPI2IF
SPI2EIF
0000
IFS3
008A
—
—
DMA5IF
DCIIF
DCIEIF
—
—
C2IF
C2RXIF
INT4IF
INT3IF
T9IF
T8IF
MI2C2IF
SI2C2IF
T7IF
0000
IFS4
008C
—
—
—
—
—
—
—
—
C2TXIF
C1TXIF
DMA7IF
DMA6IF
—
U2EIF
U1EIF
—
0000
IEC0
0094
—
DMA1IE
AD1IE
U1TXIE
U1RXIE
SPI1IE
SPI1EIE
T3IE
T2IE
OC2IE
IC2IE
DMA0IE
T1IE
OC1IE
IC1IE
INT0IE
0000
IEC1
0096
U2TXIE
U2RXIE
INT2IE
T5IE
T4IE
OC4IE
OC3IE
DMA2IE
IC8IE
IC7IE
AD2IE
INT1IE
CNIE
—
MI2C1IE
SI2C1IE
0000
IEC2
0098
T6IE
DMA4IE
—
OC8IE
OC7IE
OC6IE
OC5IE
IC6IE
IC5IE
IC4IE
IC3IE
DMA3IE
C1IE
C1RXIE
SPI2IE
SPI2EIE
0000
IEC3
009A
—
—
DMA5IE
DCIIE
DCIEIE
—
—
C2IE
C2RXIE
INT4IE
INT3IE
T9IE
T8IE
MI2C2IE
SI2C2IE
T7IE
0000
IEC4
009C
—
—
—
—
—
—
—
—
C2TXIE
C1TXIE
DMA7IE
DMA6IE
—
U2EIE
U1EIE
—
0000
IPC0
00A4
—
T1IP<2:0>
—
OC1IP<2:0>
—
IC1IP<2:0>
—
INT0IP<2:0>
4444
IPC1
00A6
—
T2IP<2:0>
—
OC2IP<2:0>
—
IC2IP<2:0>
—
DMA0IP<2:0>
4444
IPC2
00A8
—
U1RXIP<2:0>
—
SPI1IP<2:0>
—
SPI1EIP<2:0>
—
T3IP<2:0>
4444
IPC3
00AA
—
—
—
—
—
DMA1IP<2:0>
—
AD1IP<2:0>
—
U1TXIP<2:0>
0444
IPC4
00AC
—
CNIP<2:0>
—
—
—
—
—
MI2C1IP<2:0>
—
SI2C1IP<2:0>
4044
IPC5
00AE
—
IC8IP<2:0>
—
IC7IP<2:0>
—
AD2IP<2:0>
—
INT1IP<2:0>
4444
IPC6
00B0
—
T4IP<2:0>
—
OC4IP<2:0>
—
OC3IP<2:0>
—
DMA2IP<2:0>
4444
IPC7
00B2
—
U2TXIP<2:0>
—
U2RXIP<2:0>
—
INT2IP<2:0>
—
T5IP<2:0>
4444
IPC8
00B4
—
C1IP<2:0>
—
C1RXIP<2:0>
—
SPI2IP<2:0>
—
SPI2EIP<2:0>
4444
IPC9
00B6
—
IC5IP<2:0>
—
IC4IP<2:0>
—
IC3IP<2:0>
—
DMA3IP<2:0>
4444
CIP10
00B8
—
OC7IP<2:0>
—
OC6IP<2:0>
—
OC5IP<2:0>
—
IC6IP<2:0>
4444
CIP11
00BA
—
T6IP<2:0>
—
DMA4IP<2:0>
—
—
—
—
—
OC8IP<2:0>
4404
CIP12
00 aC
—
T8IP<2:0>
—
MI2C2IP<2:0>
—
SI2C2IP<2:0>
—
T7IP<2:0>
4444
CIP13
00BE
—
C2RXIP<2:0>
—
INT4IP<2:0>
—
INT3IP<2:0>
—
T9IP<2:0>
4444
CIP14
00C0
—
DCIEIP<2:0>
—
—
—
—
—
—
—
—
—
C2IP<2:0>
4004
CIP15
00C2
—
—
—
—
—
—
—
—
—
DMA5IP<2:0>
—
DCIIP<2:0>
0044
CIP16
00C4
—
—
—
—
—
U2EIP<2:0>
—
U1EIP<2:0>
—
—
—
—
0440
CIP17
00C6
—
C2TXIP<2:0>
—
C1TXIP<2:0>
—
DMA7IP<2:0>
—
DMA6IP<2:0>
4444
INTREG
00E0
—
—
—
—
ILR<3:0>
—
VECNUM<6:0>
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 44
© 2009 Microchip Technology Inc.
TABLA 4-6:
MAPA DE REGISTRO DEL TEMPORIZADOR
SFR 
Nombre
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
TMR1
0100
Temporizador1 Registrarse
xxxx
PR1
0102
Registro de período 1
FFFFF
T1CON
0104
TONELADA
—
TSIDL
—
—
—
—
—
—
TGATE
TCKPS<1:0>
—
SINCRONIZACIÓN
TCS
—
0000
TMR2
0106
Temporizador2 Registrarse
xxxx
TMR3HLD
0108
Registro de retención Timer3 (solo para operaciones de temporizador de 32 bits)
xxxx
TMR3
010A
Temporizador3 Registrarse
xxxx
PR2
010C
Registro de período 2
FFFFF
PR3
010E
Registro de período 3
FFFFF
T2CON
0110
TONELADA
—
TSIDL
—
—
—
—
—
—
TGATE
TCKPS<1:0>
T32
—
TCS
—
0000
T3CON
0112
TONELADA
—
TSIDL
—
—
—
—
—
—
TGATE
TCKPS<1:0>
—
—
TCS
—
0000
TMR4
0114
Registro Timer4
xxxx
TMR5HLD
0116
Registro de retención Timer5 (solo para operaciones de 32 bits)
xxxx
TMR5
0118
Temporizador5 Registrarse
xxxx
PR4
011A
Registro de período 4
FFFFF
PR5
011C
Registro de periodo 5
FFFFF
T4CON
011E
TONELADA
—
TSIDL
—
—
—
—
—
—
TGATE
TCKPS<1:0>
T32
—
TCS
—
0000
T5CON
0120
TONELADA
—
TSIDL
—
—
—
—
—
—
TGATE
TCKPS<1:0>
—
—
TCS
—
0000
TMR6
0122
Registro del temporizador6
xxxx
TMR7HLD
0124
Registro de retención Timer7 (solo para operaciones de 32 bits)
xxxx
TMR7
0126
Registro Timer7
xxxx
PR6
0128
Registro de período 6
FFFFF
PR7
012A
Registro de período 7
FFFFF
T6CON
012C
TONELADA
—
TSIDL
—
—
—
—
—
—
TGATE
TCKPS<1:0>
T32
—
TCS
—
0000
T7CON
012E
TONELADA
—
TSIDL
—
—
—
—
—
—
TGATE
TCKPS<1:0>
—
—
TCS
—
0000
TMR8
0130
Registro Timer8
xxxx
TMR9HLD
0132
Registro de retención Timer9 (solo para operaciones de 32 bits)
xxxx
TMR9
0134
Registro Timer9
xxxx
PR8
0136
Registro de período 8
FFFFF
PR9
0138
Registro de período 9
FFFFF
T8CON
013A
TONELADA
—
TSIDL
—
—
—
—
—
—
TGATE
TCKPS<1:0>
T32
—
TCS
—
0000
T9CON
013C
TONELADA
—
TSIDL
—
—
—
—
—
—
TGATE
TCKPS<1:0>
—
—
TCS
—
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

© 2009 Microchip Technology Inc.
DS70286C-página 45
dsPIC33FJXXXGPX06/X08/X10
TABLA 4-7:
MAPA DE REGISTRO DE CAPTURA DE ENTRADA
Nombre SFR
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
IC1BUF
0140
Registro de captura de entrada 1
xxxx
IC1CON
0142
—
—
ICSIDL
—
—
—
—
—
TICMR
ICI<1:0>
ICOV
ICBNE
MIC<2:0>
0000
IC2BUF
0144
Registro de captura de entrada 2
xxxx
IC2CON
0146
—
—
ICSIDL
—
—
—
—
—
TICMR
ICI<1:0>
ICOV
ICBNE
MIC<2:0>
0000
IC3BUF
0148
Registro de captura de entrada 3
xxxx
IC3CON
014A
—
—
ICSIDL
—
—
—
—
—
TICMR
ICI<1:0>
ICOV
ICBNE
MIC<2:0>
0000
IC4BUF
014C
Registro de captura de entrada 4
xxxx
IC4CON
014E
—
—
ICSIDL
—
—
—
—
—
TICMR
ICI<1:0>
ICOV
ICBNE
MIC<2:0>
0000
IC5BUF
0150
Entrada 5 Registro de captura
xxxx
IC5CON
0152
—
—
ICSIDL
—
—
—
—
—
TICMR
ICI<1:0>
ICOV
ICBNE
MIC<2:0>
0000
IC6BUF
0154
Entrada 6 Registro de captura
xxxx
IC6CON
0156
—
—
ICSIDL
—
—
—
—
—
TICMR
ICI<1:0>
ICOV
ICBNE
MIC<2:0>
0000
IC7BUF
0158
Entrada 7 Registro de captura
xxxx
IC7CON
015A
—
—
ICSIDL
—
—
—
—
—
TICMR
ICI<1:0>
ICOV
ICBNE
MIC<2:0>
0000
IC8BUF
015C
Entrada 8 Registro de captura
xxxx
IC8CON
015E
—
—
ICSIDL
—
—
—
—
—
TICMR
ICI<1:0>
ICOV
ICBNE
MIC<2:0>
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 46
© 2009 Microchip Technology Inc.
TABLA 4-8:
SALIDA COMPARAR MAPA DE REGISTRO
Nombre SFR
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
OC1RS
0180
Comparación de salida 1 registro secundario
xxxx
OC1R
0182
Salida Comparar 1 Registro
xxxx
OC1CON
0184
—
—
OCSIDL
—
—
—
—
—
—
—
—
OCFLT
OCTSEL
OCM<2:0>
0000
OC2RS
0186
Salida Comparar 2 Registro Secundario
xxxx
OC2R
0188
Salida Comparar 2 Registro
xxxx
OC2CON
018A
—
—
OCSIDL
—
—
—
—
—
—
—
—
OCFLT
OCTSEL
OCM<2:0>
0000
OC3RS
018C
Comparación de salida 3 registro secundario
xxxx
OC3R
018E
Salida Comparar 3 Registro
xxxx
OC3CON
0190
—
—
OCSIDL
—
—
—
—
—
—
—
—
OCFLT
OCTSEL
OCM<2:0>
0000
OC4RS
0192
Comparación de salida 4 registro secundario
xxxx
OC4R
0194
Salida Comparar 4 Registro
xxxx
OC4CON
0196
—
—
OCSIDL
—
—
—
—
—
—
—
—
OCFLT
OCTSEL
OCM<2:0>
0000
OC5RS
0198
Comparación de salida 5 registro secundario
xxxx
OC5R
019A
Salida Comparar 5 Registro
xxxx
OC5CON
019C
—
—
OCSIDL
—
—
—
—
—
—
—
—
OCFLT
OCTSEL
OCM<2:0>
0000
OC6RS
019E
Comparación de salida 6 Registro secundario
xxxx
OC6R
01A0
Salida Comparar 6 Registro
xxxx
OC6CON
01A2
—
—
OCSIDL
—
—
—
—
—
—
—
—
OCFLT
OCTSEL
OCM<2:0>
0000
OC7RS
01A4
Comparación de salida 7 Registro secundario
xxxx
OC7R
01A6
Salida Comparar 7 Registro
xxxx
OC7CON
01A8
—
—
OCSIDL
—
—
—
—
—
—
—
—
OCFLT
OCTSEL
OCM<2:0>
0000
OC8RS
01AA
Comparación de salida 8 Registro secundario
xxxx
OC8R
01AC
Salida Comparar 8 Registro
xxxx
OC8CON
01AE
—
—
OCSIDL
—
—
—
—
—
—
—
—
OCFLT
OCTSEL
OCM<2:0>
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

© 2009 Microchip Technology Inc.
DS70286C-página 47
dsPIC33FJXXXGPX06/X08/X10
TABLA 4-9:
MAPA DE REGISTRO I2C1
Nombre SFR
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
I2C1RCV
0200
—
—
—
—
—
—
—
—
Recibir Registrarse
0000
I2C1TRN
0202
—
—
—
—
—
—
—
—
Transmitir Registro
00FF
I2C1BRG
0204
—
—
—
—
—
—
—
Registro del generador de velocidad en baudios
0000
I2C1CON
0206
I2CEN
—
I2CSIDL
ESCLREL
IPMIEN
A10M
DISSLW
SMEN
GCEN
ESTRENAR
ACKDT
ACEN
RCEN
BOLÍGRAFO
RSEN
SEN
1000
I2C1STAT
0208
ACKSTAT
TRSTAT
—
—
—
BCL
GCSTAT
AGREGAR10
IWCOL
I2COV
D_A
pag
S
R_W
FBR
TBF
0000
I2C1ADD
020A
—
—
—
—
—
—
Registro de direcciones
0000
I2C1MSK
020C
—
—
—
—
—
—
Registro de máscara de dirección
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.
TABLA 4-10:
MAPA DE REGISTRO I2C2
Nombre SFR
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
I2C2RCV
0210
—
—
—
—
—
—
—
—
Recibir Registrarse
0000
I2C2TRN
0212
—
—
—
—
—
—
—
—
Transmitir Registro
00FF
I2C2BRG
0214
—
—
—
—
—
—
—
Registro del generador de velocidad en baudios
0000
I2C2CON
0216
I2CEN
—
I2CSIDL
ESCLREL
IPMIEN
A10M
DISSLW
SMEN
GCEN
ESTRENAR
ACKDT
ACEN
RCEN
BOLÍGRAFO
RSEN
SEN
1000
I2C2STAT
0218
ACKSTAT
TRSTAT
—
—
—
BCL
GCSTAT
AGREGAR10
IWCOL
I2COV
D_A
pag
S
R_W
FBR
TBF
0000
I2C2ADD
021A
—
—
—
—
—
—
Registro de direcciones
0000
I2C2MSK
021C
—
—
—
—
—
—
Registro de máscara de dirección
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 48
© 2009 Microchip Technology Inc.
TABLA 4-11:
MAPA DE REGISTRO UART1
Nombre SFR
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
MODO U1
0220
UARTEN
—
USIDL
IRÉN
RTSMD
—
UEN1
UEN0
DESPERTAR
LPBACK
ABAUD
URXINV
BRGH
PDSEL<1:0>
STSEL
0000
U1STA
0222
UTXISEL1
UTXINV
UTXISEL0
—
UTXBRK
UTXEN
UTXBF
TRMT
URXISEL<1:0>
AGREGAR
Acertijo
PERR
FERRO
REA
URXDA
0110
U1TXREG
0224
—
—
—
—
—
—
—
Registro de transmisión UART
xxxx
U1RXREG
0226
—
—
—
—
—
—
—
Registro de recepción UART
0000
U1BRG
0228
Preescalador del generador de velocidad en baudios
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.
TABLA 4-12:
MAPA DE REGISTRO UART2
SFR 
Nombre
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
MODO U2
0230
UARTEN
—
USIDL
IRÉN
RTSMD
—
UEN1
UEN0
DESPERTAR
LPBACK
ABAUD
URXINV
BRGH
PDSEL<1:0>
STSEL
0000
U2STA
0232
UTXISEL1
UTXINV
UTXISEL0
—
UTXBRK
UTXEN
UTXBF
TRMT
URXISEL<1:0>
AGREGAR
Acertijo
PERR
FERRO
REA
URXDA
0110
U2TXREG
0234
—
—
—
—
—
—
—
Registro de transmisión UART
xxxx
U2RXREG
0236
—
—
—
—
—
—
—
Registro de recepción UART
0000
U2BRG
0238
Preescalador del generador de velocidad en baudios
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.
TABLA 4-13:
MAPA DE REGISTRO SPI1
SFR 
Nombre
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
SPI1STAT
0240
ESPIEN
—
SPISIDL
—
—
—
—
—
—
ESPÍROV
—
—
—
—
SPITBF
ESPIRBF
0000
SPI1CON1
0242
—
—
—
DISCO
DISSDO
MODO16
SMP
CKE
SSEN
CKP
MSTEN
SPRE<2:0>
PPRE<1:0>
0000
SPI1CON2
0244
FRMEN
SPIFSD
FRMPOL
—
—
—
—
—
—
—
—
—
—
—
FRMDLY
—
0000
SPI1BUF
0248
Registro de búfer de transmisión y recepción SPI1
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.
TABLA 4-14:
MAPA DE REGISTRO SPI2
Nombre SFR
SFR 
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
SPI2STAT
0260
ESPIEN
—
SPISIDL
—
—
—
—
—
—
ESPÍROV
—
—
—
—
SPITBF
ESPIRBF
0000
SPI2CON1
0262
—
—
—
DISCO
DISSDO
MODO16
SMP
CKE
SSEN
CKP
MSTEN
SPRE<2:0>
PPRE<1:0>
0000
SPI2CON2
0264
FRMEN
SPIFSD
FRMPOL
—
—
—
—
—
—
—
—
—
—
—
FRMDLY
—
0000
SPI2BUF
0268
Registro de búfer de transmisión y recepción SPI2
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

© 2009 Microchip Technology Inc.
DS70286C-página 49
dsPIC33FJXXXGPX06/X08/X10
 
 
TABLA 4-15:
MAPA DE REGISTRO ADC1
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
ADC1BUF0
0300
Búfer de datos ADC 0
xxxx
AD1CON1
0320
ADÓN
—
ADSIDL
ADDMABM
—
AD12B
FORMATO<1:0>
SSRC<2:0>
—
SIMSAM
ASAM
MUESTRA
HECHO
0000
AD1CON2
0322
VCFG<2:0>
—
—
CSCNA
CHPS<1:0>
BUFS
—
SMPI<3:0>
BUFM
ALTAS
0000
AD1CON3
0324
ADRC
—
—
SAMC<4:0>
ADCS<7:0>
0000
AD1CHS123
0326
—
—
—
—
—
CH123NB<1:0>
CH123SB
—
—
—
—
—
CH123NA<1:0>
CH123SA
0000
AD1CHS0
0328
CH0NB
—
—
CH0SB<4:0>
CH0NA
—
—
CH0SA<4:0>
0000
AD1PCFGH(1)
032A
PCFG31
PCFG30
PCFG29
PCFG28
PCFG27
PCFG26
PCFG25
PCFG24
PCFG23
PCFG22
PCFG21
PCFG20
PCFG19
PCFG18
PCFG17
PCFG16
0000
AD1PCFGL
032C
PCFG15
PCFG14
PCFG13
PCFG12
PCFG11
PCFG10
PCFG9
PCFG8
PCFG7
PCFG6
PCFG5
PCFG4
PCFG3
PCFG2
PCFG1
PCFG0
0000
AD1CSSH(1)
032E
CSS31
CSS30
CSS29
CSS28
CSS27
CSS26
CSS25
CSS24
CSS23
CSS22
CSS21
CSS20
CSS19
CSS18
CSS17
CSS16
0000
AD1CSSL
0330
CSS15
CSS14
CSS13
CSS12
CSS11
CSS10
CSS9
CSS8
CSS7
CSS6
CSS5
CSS4
CSS3
CSS2
CSS1
CSS0
0000
AD1CON4
0332
—
—
—
—
—
—
—
—
—
—
—
—
—
DMABL<2:0>
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.
Nota
1:
No todas las entradas ANx están disponibles en todos los dispositivos. Consulte los diagramas de pines del dispositivo para conocer las entradas ANx disponibles.
TABLA 4-16:
MAPA DE REGISTRO ADC2
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
ADC2BUF0
0340
Búfer de datos ADC 0
xxxx
AD2CON1
0360
ADÓN
—
ADSIDL
ADDMABM
—
AD12B
FORMATO<1:0>
SSRC<2:0>
—
SIMSAM
ASAM
MUESTRA
HECHO
0000
AD2CON2
   0362
VCFG<2:0>
—
—
CSCNA
CHPS<1:0>
BUFS
—
SMPI<3:0>
BUFM
ALTAS
0000
AD2CON3
0364
ADRC
—
—
SAMC<4:0>
ADCS<7:0>
0000
AD2CHS123
0366
—
—
—
—
—
CH123NB<1:0>
CH123SB
—
—
—
—
—
CH123NA<1:0>
CH123SA
0000
AD2CHS0
0368
CH0NB
—
—
—
CH0SB<3:0>
CH0NA
—
—
—
CH0SA<3:0>
0000
Reservado
036A
—
—
—
—
—
—
—
—
—
—
—
—
—
—
—
—
0000
AD2PCFGL
036C
PCFG15
PCFG14
PCFG13
PCFG12
PCFG11
PCFG10
PCFG9
PCFG8
PCFG7
PCFG6
PCFG5
PCFG4
PCFG3
PCFG2
PCFG1
PCFG0
0000
Reservado
036E
—
—
—
—
—
—
—
—
—
—
—
—
—
—
—
—
0000
AD2CSSL
0370
CSS15
CSS14
CSS13
CSS12
CSS11
CSS10
CSS9
CSS8
CSS7
CSS6
CSS5
CSS4
CSS3
CSS2
CSS1
CSS0
0000
AD2CON4
0372
—
—
—
—
—
—
—
—
—
—
—
—
—
DMABL<2:0>
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 50
© 2009 Microchip Technology Inc.
TABLA 4-17:
MAPA DE REGISTRO DMA
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
DMA0CON
0380
CHEN
TAMAÑO
dirección
MITAD
NULO
—
—
—
—
—
MODO<1:0>
—
—
MODO<1:0>
0000
DMA0REQ
0382
FUERZA
—
—
—
—
—
—
—
—
IRQSEL<6:0>
0000
DMA0STA
0384
STA<15:0>
0000
DMA0STB
0386
STB<15:0>
0000
DMA0PAD
0388
PAD<15:0>
0000
DMA0CNT
038A
—
—
—
—
—
—
CNT<9:0>
0000
DMA1CON
038C
CHEN
TAMAÑO
dirección
MITAD
NULO
—
—
—
—
—
MODO<1:0>
—
—
MODO<1:0>
0000
DMA1REQ
038E
FUERZA
—
—
—
—
—
—
—
—
IRQSEL<6:0>
0000
DMA1STA
0390
STA<15:0>
0000
DMA1STB
0392
STB<15:0>
0000
DMA1PAD
0394
PAD<15:0>
0000
DMA1CNT
0396
—
—
—
—
—
—
CNT<9:0>
0000
DMA2CON
0398
CHEN
TAMAÑO
dirección
MITAD
NULO
—
—
—
—
—
MODO<1:0>
—
—
MODO<1:0>
0000
DMA2REQ
039A
FUERZA
—
—
—
—
—
—
—
—
IRQSEL<6:0>
0000
DMA2STA
039C
STA<15:0>
0000
DMA2STB
039E
STB<15:0>
0000
DMA2PAD
03A0
PAD<15:0>
0000
DMA2CNT
03A2
—
—
—
—
—
—
CNT<9:0>
0000
DMA3CON
03A4
CHEN
TAMAÑO
dirección
MITAD
NULO
—
—
—
—
—
MODO<1:0>
—
—
MODO<1:0>
0000
DMA3REQ
03A6
FUERZA
—
—
—
—
—
—
—
—
IRQSEL<6:0>
0000
DMA3STA
03A8
STA<15:0>
0000
DMA3STB
03AA
STB<15:0>
0000
DMA3PAD
03AC
PAD<15:0>
0000
DMA3CNT
03AE
—
—
—
—
—
—
CNT<9:0>
0000
DMA4CON
03B0
CHEN
TAMAÑO
dirección
MITAD
NULO
—
—
—
—
—
MODO<1:0>
—
—
MODO<1:0>
0000
DMA4REQ
03B2
FUERZA
—
—
—
—
—
—
—
—
IRQSEL<6:0>
0000
DMA4STA
03B4
STA<15:0>
0000
DMA4STB
03B6
STB<15:0>
0000
DMA4PAD
03B8
PAD<15:0>
0000
DMA4CNT
03BA
—
—
—
—
—
—
CNT<9:0>
0000
DMA5CON 03BC
CHEN
TAMAÑO
dirección
MITAD
NULO
—
—
—
—
—
MODO<1:0>
—
—
MODO<1:0>
0000
DMA5REQ
03BE
FUERZA
—
—
—
—
—
—
—
—
IRQSEL<6:0>
0000
DMA5STA
03C0
STA<15:0>
0000
DMA5STB
03C2
STB<15:0>
0000
DMA5PAD
03C4
PAD<15:0>
0000
Leyenda:
— = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

© 2009 Microchip Technology Inc.
DS70286C-página 51
dsPIC33FJXXXGPX06/X08/X10
DMA5CNT
03C6
—
—
—
—
—
—
CNT<9:0>
0000
DMA6CON
03C8
CHEN
TAMAÑO
dirección
MITAD
NULO
—
—
—
—
—
MODO<1:0>
—
—
MODO<1:0>
0000
DMA6REQ
03CA
FUERZA
—
—
—
—
—
—
—
—
IRQSEL<6:0>
0000
DMA6STA
03CC
STA<15:0>
0000
DMA6STB
03CE
STB<15:0>
0000
DMA6PAD
03D0
PAD<15:0>
0000
DMA6CNT
03D2
—
—
—
—
—
—
CNT<9:0>
0000
DMA7CON
03D4
CHEN
TAMAÑO
dirección
MITAD
NULO
—
—
—
—
—
MODO<1:0>
—
—
MODO<1:0>
0000
DMA7REQ
03D6
FUERZA
—
—
—
—
—
—
—
—
IRQSEL<6:0>
0000
DMA7STA
03D8
STA<15:0>
0000
DMA7STB
03DA
STB<15:0>
0000
DMA7PAD
03DC
PAD<15:0>
0000
DMA7CNT
03DE
—
—
—
—
—
—
CNT<9:0>
0000
DMACS0
03E0 PWCOL7 PWCOL6 PWCOL5 PWCOL4 PWCOL3
PWCOL2 PWCOL1 PWCOL0
XWCOL7
XWCOL6
XWCOL5
XWCOL4
XWCOL3
XWCOL2
XWCOL1
XWCOL0
0000
DMACS1
03E2
—
—
—
—
LSTCH<3:0>
PPST7
PPST6
PPST5
PPST4
PPST3
PPST2
PPST1
PPST0
0000
DSADR
03E4
DSADR<15:0>
0000
TABLA 4-17:
MAPA DE REGISTRO DMA (CONTINUACIÓN)
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
Leyenda:
— = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 52
© 2009 Microchip Technology Inc.
      
  
TABLA 4-18:
MAPA DE REGISTRO ECAN1 CUANDO C1CTRL1.WIN = 0 O 1 SÓLO PARA DISPOSITIVOS dsPIC33FJXXXGP506/510/706/708/710
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
C1CTRL1
0400
—
—
CSIDL
ABAT
—
REQOP<2:0>
MODOOP<2:0>
—
CANCAP
—
—
GANAR
0480
C1CTRL2
0402
—
—
—
—
—
—
—
—
—
—
—
DNCNT<4:0>
0000
C1VEC
0404
—
—
—
FILHIT<4:0>
—
ICODIO<6:0>
0000
C1FCTRL
0406
DMABS<2:0>
—
—
—
—
—
—
—
—
FSA<4:0>
0000
C1FIFO
0408
—
—
FBP<5:0>
—
—
FNRB<5:0>
0000
C1INTF
040A
—
—
TXBO
TXBP
RXBP
TXWAR
RXWAR
ADVERTENCIA
IVRIF
WAKIF
ERROR
—
FIFOIF
RBOVIF
RBIF
TBIF
0000
C1INTE
040C
—
—
—
—
—
—
—
—
IVRIE
WAKIE
ERRÍE
—
FIFOIE
RBOVIE
RBIE
TBIE
0000
C1EC
040E
TERRCENTE<7:0>
ERRCNT<7:0>
0000
C1CFG1
0410
—
—
—
—
—
—
—
—
SJW<1:0>
BRP<5:0>
0000
C1CFG2
0412
—
WAKFIL
—
—
—
SEG2PH<2:0>
SEG2PHTS
Sam
SEG1PH<2:0>
PRSEG<2:0>
0000
C1FEN1
0414
FLTEN15
FLTEN14
FLTEN13
FLTEN12
FLTEN11
FLTEN10
FLTEN9
FLTEN8
FLTEN7
FLTEN6
FLTEN5
FLTEN4
FLTEN3
FLTEN2
FLTEN1 FLTEN0
FFFFF
C1FMSKSEL1
0418
F7MSK<1:0>
F6MSK<1:0>
F5MSK<1:0>
F4MSK<1:0>
F3MSK<1:0>
F2MSK<1:0>
F1MSK<1:0>
F0MSK<1:0>
0000
C1FMSKSEL2
041A
F15MSK<1:0>
F14MSK<1:0>
F13MSK<1:0>
F12MSK<1:0>
F11MSK<1:0>
F10MSK<1:0>
F9MSK<1:0>
F8MSK<1:0>
0000
Leyenda:
— = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.
TABLA 4-19:
MAPA DE REGISTRO ECAN1 CUANDO C1CTRL1.WIN = 0 SÓLO PARA DISPOSITIVOS dsPIC33FJXXXGP506/510/706/708/710
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
0400-
041E
Ver definición cuando WIN = x
C1RXFUL1
0420
RXFUL15 RXFUL14 RXFUL13 RXFUL12 RXFUL11 RXFUL10
RXFUL9
RXFUL8
RXFUL7
RXFUL6
RXFUL5
RXFUL4
RXFUL3
RXFUL2
RXFUL1
RXFUL0
0000
C1RXFUL2
0422
RXFUL31
RXFUL30 RXFUL29 RXFUL28 RXFUL27 RXFUL26 RXFUL25 RXFUL24 RXFUL23 RXFUL22 RXFUL21 RXFUL20 RXFUL19 RXFUL18 RXFUL17 RXFUL16
0000
C1RXOVF1
0428
RXOVF15 RXOVF14 RXOVF13 RXOVF12 RXOVF11 RXOVF10
RXOVF9
RXOVF8
RXOVF7
RXOVF6
RXOVF5
RXOVF4
RXOVF3
RXOVF2
RXOVF1
RXOVF0
0000
C1RXOVF2
042A
RXOVF31 RXOVF30 RXOVF29 RXOVF28 RXOVF27 RXOVF26 RXOVF25 RXOVF24 RXOVF23 RXOVF22 RXOVF21 RXOVF20 RXOVF19 RXOVF18 RXOVF17 RXOVF16
0000
C1TR01CON
0430
TXEN1
TXABT1
TXLARB1
TXERR1
TXREQ1
RTREN1
TX1PRI<1:0>
TXEN0
TXABAT0
TXLARB0
TXERR0
TXREQ0
RTREN0
TX0PRI<1:0>
0000
C1TR23CON
0432
TXEN3
TXABT3
TXLARB3
TXERR3
TXREQ3
RTREN3
TX3PRI<1:0>
TXEN2
TXABAT2
TXLARB2
TXERR2
TXREQ2
RTREN2
TX2PRI<1:0>
0000
C1TR45CON
0434
TXEN5
TXABT5
TXLARB5
TXERR5
TXREQ5
RTREN5
TX5PRI<1:0>
TXEN4
TXABAT4
TXLARB4
TXERR4
TXREQ4
RTREN4
TX4PRI<1:0>
0000
C1TR67CON
0436
TXEN7
TXABT7
TXLARB7
TXERR7
TXREQ7
RTREN7
TX7PRI<1:0>
TXEN6
TXABAT6
TXLARB6
TXERR6
TXREQ6
RTREN6
TX6PRI<1:0>
xxxx
C1RXD
0440
Palabra de datos recibidos
xxxx
C1TXD
0442
Transmitir palabra de datos
xxxx
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

© 2009 Microchip Technology Inc.
DS70286C-página 53
dsPIC33FJXXXGPX06/X08/X10
TABLA 4-20:
MAPA DE REGISTRO ECAN1 CUANDO C1CTRL1.WIN = 1 SÓLO PARA DISPOSITIVOS dsPIC33FJXXXGP506/510/706/708/710
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
0400-
041E
Ver definición cuando WIN = x
C1BUFPNT1
0420
F3BP<3:0>
F2BP<3:0>
F1BP<3:0>
F0BP<3:0>
0000
C1BUFPNT2
0422
F7BP<3:0>
F6BP<3:0>
F5BP<3:0>
F4BP<3:0>
0000
C1BUFPNT3
0424
F11BP<3:0>
F10BP<3:0>
F9BP<3:0>
F8BP<3:0>
0000
C1BUFPNT4
0426
F15BP<3:0>
F14BP<3:0>
F13BP<3:0>
F12BP<3:0>
0000
C1RXM0SID
0430
ID<10:3>
ID<2:0>
—
MIDE
—
EID<17:16>
xxxx
C1RXM0EID
0432
IDE<15:8>
IDE<7:0>
xxxx
C1RXM1SID
0434
ID<10:3>
ID<2:0>
—
MIDE
—
EID<17:16>
xxxx
C1RXM1EID
0436
IDE<15:8>
IDE<7:0>
xxxx
C1RXM2SID
0438
ID<10:3>
ID<2:0>
—
MIDE
—
EID<17:16>
xxxx
C1RXM2EID
043A
IDE<15:8>
IDE<7:0>
xxxx
C1RXF0SID
0440
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF0EID
0442
IDE<15:8>
IDE<7:0>
xxxx
C1RXF1SID
0444
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF1EID
0446
IDE<15:8>
IDE<7:0>
xxxx
C1RXF2SID
0448
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF2EID
044A
IDE<15:8>
IDE<7:0>
xxxx
C1RXF3SID
044C
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF3EID
044E
IDE<15:8>
IDE<7:0>
xxxx
C1RXF4SID
0450
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF4EID
0452
IDE<15:8>
IDE<7:0>
xxxx
C1RXF5SID
0454
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF5EID
0456
IDE<15:8>
IDE<7:0>
xxxx
C1RXF6SID
0458
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF6EID
045A
IDE<15:8>
IDE<7:0>
xxxx
C1RXF7SID
045C
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF7EID
045E
IDE<15:8>
IDE<7:0>
xxxx
C1RXF8SID
0460
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF8EID
0462
IDE<15:8>
IDE<7:0>
xxxx
C1RXF9SID
0464
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF9EID
0466
IDE<15:8>
IDE<7:0>
xxxx
C1RXF10SID
0468
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF10EID
046A
IDE<15:8>
IDE<7:0>
xxxx
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 54
© 2009 Microchip Technology Inc.
C1RXF11SID
046C
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF11EID
046E
IDE<15:8>
IDE<7:0>
xxxx
C1RXF12SID
0470
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF12EID
0472
IDE<15:8>
IDE<7:0>
xxxx
C1RXF13SID
0474
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF13EID
0476
IDE<15:8>
IDE<7:0>
xxxx
C1RXF14SID
0478
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF14EID
047A
IDE<15:8>
IDE<7:0>
xxxx
C1RXF15SID
047C
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C1RXF15EID
047E
IDE<15:8>
IDE<7:0>
xxxx
TABLA 4-20:
MAPA DE REGISTRO ECAN1 CUANDO C1CTRL1.WIN = 1 SÓLO PARA DISPOSITIVOS dsPIC33FJXXXGP506/510/706/708/710 (CONTINUACIÓN)
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

© 2009 Microchip Technology Inc.
DS70286C-página 55
dsPIC33FJXXXGPX06/X08/X10
      
  
TABLA 4-21:
MAPA DE REGISTRO ECAN2 CUANDO C2CTRL1.WIN = 0 O 1 SÓLO PARA DISPOSITIVOS dsPIC33FJXXXGP706/708/710
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
C2CTRL1
0500
—
—
CSIDL
ABAT
—
REQOP<2:0>
MODOOP<2:0>
—
CANCAP
—
—
GANAR
0480
C2CTRL2
0502
—
—
—
—
—
—
—
—
—
—
—
DNCNT<4:0>
0000
C2VEC
0504
—
—
—
FILHIT<4:0>
—
ICODIO<6:0>
0000
C2FCTRL
0506
DMABS<2:0>
—
—
—
—
—
—
—
—
FSA<4:0>
0000
C2FIFO
0508
—
—
FBP<5:0>
—
—
FNRB<5:0>
0000
C2INTF
050A
—
—
TXBO
TXBP
RXBP
TXWAR
RXWAR
ADVERTENCIA
IVRIF
WAKIF
ERROR
—
FIFOIF
RBOVIF
RBIF
TBIF
0000
C2INTE
050C
—
—
—
—
—
—
—
—
IVRIE
WAKIE
ERRÍE
—
FIFOIE
RBOVIE
RBIE
TBIE
0000
C2EC
050E
TERRCENTE<7:0>
ERRCNT<7:0>
0000
C2CFG1
0510
—
—
—
—
—
—
—
—
SJW<1:0>
BRP<5:0>
0000
C2CFG2
0512
—
WAKFIL
—
—
—
SEG2PH<2:0>
SEG2PHTS
Sam
SEG1PH<2:0>
PRSEG<2:0>
0000
C2FEN1
0514
FLTEN15
FLTEN14
FLTEN13
FLTEN12
FLTEN11
FLTEN10
FLTEN9
FLTEN8
FLTEN7
FLTEN6
FLTEN5 FLTEN4
FLTEN3
FLTEN2
FLTEN1
FLTEN0
FFFFF
C2FMSKSEL1
0518
F7MSK<1:0>
F6MSK<1:0>
F5MSK<1:0>
F4MSK<1:0>
F3MSK<1:0>
F2MSK<1:0>
F1MSK<1:0>
F0MSK<1:0>
0000
C2FMSKEL2
051A
F15MSK<1:0>
F14MSK<1:0>
F13MSK<1:0>
F12MSK<1:0>
F11MSK<1:0>
F10MSK<1:0>
F9MSK<1:0>
F8MSK<1:0>
0000
Leyenda:
— = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.
TABLA 4-22:
MAPA DE REGISTRO ECAN2 CUANDO C2CTRL1.WIN = 0 SÓLO PARA DISPOSITIVOS dsPIC33FJXXXGP706/708/710
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
0500-
051E
Ver definición cuando WIN = x
C2RXFUL1
0520
RXFUL15 RXFUL14 RXFUL13 RXFUL12 RXFUL11 RXFUL10
RXFUL9
RXFUL8
RXFUL7
RXFUL6
RXFUL5
RXFUL4
RXFUL3
RXFUL2
RXFUL1
RXFUL0
0000
C2RXFUL2
0522
RXFUL31 RXFUL30 RXFUL29 RXFUL28 RXFUL27 RXFUL26 RXFUL25 RXFUL24
RXFUL23
RXFUL22
RXFUL21 RXFUL20 RXFUL19 RXFUL18 RXFUL17 RXFUL16
0000
C2RXOVF1
0528
RXOVF15 RXOVF14 RXOVF13 RXOVF12 RXOVF11 RXOVF10 RXOVF09 RXOVF08
RXOVF7
RXOVF6
RXOVF5
RXOVF4
RXOVF3
RXOVF2
RXOVF1
RXOVF0
0000
C2RXOVF2
052A
RXOVF31 RXOVF30 RXOVF29 RXOVF28 RXOVF27 RXOVF26 RXOVF25 RXOVF24 RXOVF23 RXOVF22 RXOVF21 RXOVF20 RXOVF19 RXOVF18 RXOVF17 RXOVF16
0000
C2TR01CON
0530
TXEN1
Texas
ABAT1
Texas
LARB1
Texas
ERR1
Texas
REQ1
RTREN1
TX1PRI<1:0>
TXEN0
Texas
ABAT0
Texas
LARB0
Texas
ERR0
Texas
REQ0
RTREN0
TX0PRI<1:0>
0000
C2TR23CON
0532
TXEN3
Texas
ABAT3
Texas
LARB3
Texas
ERR3
Texas
REQ3
RTREN3
TX3PRI<1:0>
TXEN2
Texas
ABAT2
Texas
LARB2
Texas
ERR2
Texas
REQ2
RTREN2
TX2PRI<1:0>
0000
C2TR45CON
0534
TXEN5
Texas
ABAT5
Texas
LARB5
Texas
ERR5
Texas
REQ5
RTREN5
TX5PRI<1:0>
TXEN4
Texas
ABAT4
Texas
LARB4
Texas
ERR4
Texas
REQ4
RTREN4
TX4PRI<1:0>
0000
C2TR67CON
0536
TXEN7
Texas
ABAT7
Texas
LARB7
Texas
ERR7
Texas
REQ7
RTREN7
TX7PRI<1:0>
TXEN6
Texas
ABAT6
Texas
LARB6
Texas
ERR6
Texas
REQ6
RTREN6
TX6PRI<1:0>
xxxx
C2RXD
0540
Palabra de datos recibida
xxxx
C2TXD
0542
Transmitir palabra de datos
xxxx
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 56
© 2009 Microchip Technology Inc.
 
TABLA 4-23:
MAPA DE REGISTRO ECAN2 CUANDO C2CTRL1.WIN = 1 SÓLO PARA DISPOSITIVOS dsPIC33FJXXXGP706/708/710
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
0500
-
051E
Ver definición cuando WIN = x
C2BUFPNT1
0520
F3BP<3:0>
F2BP<3:0>
F1BP<3:0>
F0BP<3:0>
0000
C2BUFPNT2
0522
F7BP<3:0>
F6BP<3:0>
F5BP<3:0>
F4BP<3:0>
0000
C2BUFPNT3
0524
F11BP<3:0>
F10BP<3:0>
F9BP<3:0>
F8BP<3:0>
0000
C2BUFPNT4
0526
F15BP<3:0>
F14BP<3:0>
F13BP<3:0>
F12BP<3:0>
0000
C2RXM0SID
0530
ID<10:3>
ID<2:0>
—
MIDE
—
EID<17:16>
xxxx
C2RXM0EID
0532
IDE<15:8>
IDE<7:0>
xxxx
C2RXM1SID
0534
ID<10:3>
ID<2:0>
—
MIDE
—
EID<17:16>
xxxx
C2RXM1EID
0536
IDE<15:8>
IDE<7:0>
xxxx
C2RXM2SID
0538
ID<10:3>
ID<2:0>
—
MIDE
—
EID<17:16>
xxxx
C2RXM2EID
053A
IDE<15:8>
IDE<7:0>
xxxx
C2RXF0SID
0540
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF0EID
0542
IDE<15:8>
IDE<7:0>
xxxx
C2RXF1SID
0544
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF1EID
0546
IDE<15:8>
IDE<7:0>
xxxx
C2RXF2SID
0548
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF2EID
054A
IDE<15:8>
IDE<7:0>
xxxx
C2RXF3SID
054C
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF3EID
054E
IDE<15:8>
IDE<7:0>
xxxx
C2RXF4SID
0550
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF4EID
0552
IDE<15:8>
IDE<7:0>
xxxx
C2RXF5SID
0554
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF5EID
0556
IDE<15:8>
IDE<7:0>
xxxx
C2RXF6SID
0558
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF6EID
055A
IDE<15:8>
IDE<7:0>
xxxx
C2RXF7SID
055C
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF7EID
055E
IDE<15:8>
IDE<7:0>
xxxx
C2RXF8SID
0560
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF8EID
0562
IDE<15:8>
IDE<7:0>
xxxx
C2RXF9SID
0564
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF9EID
0566
IDE<15:8>
IDE<7:0>
xxxx
C2RXF10SID
0568
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

© 2009 Microchip Technology Inc.
DS70286C-página 57
dsPIC33FJXXXGPX06/X08/X10
C2RXF10EID
056A
IDE<15:8>
IDE<7:0>
xxxx
C2RXF11SID
056C
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF11EID
056E
IDE<15:8>
IDE<7:0>
xxxx
C2RXF12SID
0570
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF12EID
0572
IDE<15:8>
IDE<7:0>
xxxx
C2RXF13SID
0574
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF13EID
0576
IDE<15:8>
IDE<7:0>
xxxx
C2RXF14SID
0578
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF14EID
057A
IDE<15:8>
IDE<7:0>
xxxx
C2RXF15SID
057C
ID<10:3>
ID<2:0>
—
EXIDE
—
EID<17:16>
xxxx
C2RXF15EID
057E
IDE<15:8>
IDE<7:0>
xxxx
TABLA 4-23:
MAPA DE REGISTRO ECAN2 CUANDO C2CTRL1.WIN = 1 SÓLO PARA DISPOSITIVOS dsPIC33FJXXXGP706/708/710 (CONTINUACIÓN)
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 58
© 2009 Microchip Technology Inc.
 
TABLA 4-24:
MAPA DE REGISTRO DCI
SFR 
Nombre
Dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Restablecer estado
DCICON1
0280
DCIEN
—
DCISIDL
—
DLOOP
CSCKD
CSCKE
COFSD
UNFM
CSDOM
DJST
—
—
—
COFSM1
COFSM0
0000 0000 0000 0000
DCICON2
0282
—
—
—
—
BLEN1
BLEN0
—
COFSG<3:0>
—
WS<3:0>
0000 0000 0000 0000
DCICON3
0284
—
—
—
—
BCG<11:0>
0000 0000 0000 0000
DCISTAT
0286
—
—
—
—
RANURA3
RANURA2
RANURA1
RANURA0
—
—
—
—
ROV
RFUL
TUNF
TMPTY
0000 0000 0000 0000
TSCON
0288
EET15
EET14
EET13
EET12
EET11
EET10
EET9
EET8
EET7
EET6
EET5
EET4
EET3
EET2
EET1
EET0
0000 0000 0000 0000
RSCON
028C
RSE15
RSE14
RSE13
RSE12
RSE11
RSE10
RSE9
RSE8
RSE7
RSE6
RSE5
RSE4
RSE3
RSE2
RSE1
RSE0
0000 0000 0000 0000
RXBUF0
0290
Recibir registro de datos del buffer #0
0000 0000 0000 0000
RXBUF1
0292
Recibir registro de datos del buffer n.° 1
0000 0000 0000 0000
RXBUF2
0294
Recibir registro de datos del buffer n.° 2
0000 0000 0000 0000
RXBUF3
0296
Recibir registro de datos del buffer n.° 3
0000 0000 0000 0000
TXBUF0
0298
Registro de datos del buffer de transmisión #0
0000 0000 0000 0000
TXBUF1
029A
Registro de datos del buffer de transmisión #1
0000 0000 0000 0000
TXBUF2
029C
Registro de datos del buffer de transmisión #2
0000 0000 0000 0000
TXBUF3
029E
Registro de datos del buffer de transmisión #3
0000 0000 0000 0000
Leyenda:
— = no implementado, leído como '0'. 
Nota
1:
Consulte el “Manual de referencia de la familia dsPIC33F” para obtener descripciones de los campos de bits de registro.
TABLA 4-25:
MAPA DE REGISTRO PORTA(1)
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
TRISA
02C0
TRISA15
TRISA14
TRISA13
TRISA12
—
TRISA10
TRISA9
—
TRISA7
TRISA6
TRISA5
TRISA4
TRISA3
TRISA2
TRISA1
TRISA0
F6FF
PORTA
02C2
RA15
RA14
RA13
RA12
—
RA10
RA9
—
RA7
RA6
RA5
RA4
RA3
RA2
RA1
RA0
xxxx
LATA
02C4
LATA15
LATA14
LATA13
LATA12
—
LATA10
LATA9
—
LATA7
LATA6
LATA5
LATA4
LATA3
LATA2
LATA1
LATA0
xxxx
ODCA(2)
06C0
ODCA15
ODCA14
—
—
—
—
—
—
—
—
ODCA5
ODCA4
ODCA3
ODCA2
ODCA1
ODCA0
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal para dispositivos PinHigh.
Nota
1:
El conjunto real de pines del puerto de E/S varía de un dispositivo a otro. Consulte los diagramas de distribución de pines correspondientes.
TABLA 4-26:
MAPA DE REGISTRO DEL PORTB(1)
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
trisb
02C6
TRISB15
trisb14
TRISB13
trisb12
trisb11
trisb10
TRISB9
TRISB8
TRISB7
TRISB6
TRISB5
TRISB4
TRISB3
TRISB2
TRISB1
TRISB0
FFFFF
PUERTO
02C8
RB15
RB14
RB13
RB12
RB11
RB10
RB9
RB8
RB7
RB6
RB5
RB4
RB3
RB2
RB1
RB0
xxxx
LATB
02CA
LATB15
LATB14
LATB13
LATB12
LATB11
LATB10
LATB9
LATB8
LATB7
LATB6
LATB5
LATB4
LATB3
LATB2
LATB1
LATB0
xxxx
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal para dispositivos PinHigh.
Nota
1:
El conjunto real de pines del puerto de E/S varía de un dispositivo a otro. Consulte los diagramas de distribución de pines correspondientes.

© 2009 Microchip Technology Inc.
DS70286C-página 59
dsPIC33FJXXXGPX06/X08/X10
TABLA 4-27:
MAPA DE REGISTRO DEL PUERTO(1)
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
TRISC
02CC
TRISC15
TRISC14
TRISC13
TRISC12
—
—
—
—
—
—
—
TRISC4
TRISC3
TRISC2
TRISC1
—
F01E
PORTC
02CE
RC15
RC14
RC13
RC12
—
—
—
—
—
—
—
RC4
RC3
RC2
RC1
—
xxxx
LATC
02D0
LATC15
LATC14
LATC13
LATC12
—
—
—
—
—
—
—
LATC4
LATC3
LATC2
LATC1
—
xxxx
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal para dispositivos PinHigh.
Nota
1:
El conjunto real de pines del puerto de E/S varía de un dispositivo a otro. Consulte los diagramas de distribución de pines correspondientes.
TABLA 4-28:
MAPA DE REGISTRO DEL PUERTO(1)
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
TRISD
02D2
TRISD15
TRISD14
TRISD13
TRISD12
TRISD11
TRISD10
TRISD9
TRISD8
TRISD7
TRISD6
TRISD5
TRISD4
TRISD3
TRISD2
TRISD1
TRISD0
FFFFF
PORTADO
02D4
RD15
RD14
RD13
RD12
RD11
RD10
RD9
RD8
RD7
RD6
RD5
RD4
RD3
RD2
RD1
RD0
xxxx
LATD
02D6
LATD15
LATD14
LATD13
LATD12
LATD11
LATD10
LATD9
LATD8
LATD7
LATD6
LATD5
LATD4
LATD3
LATD2
LATD1
LATD0
xxxx
TOCD
06D2
ODCD15
ODCD14
ODCD13
ODCD12
ODCD11
ODCD10
ODCD9
OCD8
ODCD7
ODCD6
OCD5
OCD4
OCD3
OCD2
ODCD1
ODCD0
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal para dispositivos PinHigh.
Nota
1:
El conjunto real de pines del puerto de E/S varía de un dispositivo a otro. Consulte los diagramas de distribución de pines correspondientes.
TABLA 4-29:
MAPA DE REGISTRO DE PORTE(1)
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
TRISE
02D8
—
—
—
—
—
—
—
—
TRISE7
TRISE6
TRISE5
TRISE4
TRISE3
TRISE2
TRISE1
TRISE0
00FF
PORTE
02DA
—
—
—
—
—
—
—
—
RE7
RE6
RE5
RE4
RE3
RE2
RE1
RE0
xxxx
TARDE
02DC
—
—
—
—
—
—
—
—
TARDE7
TARDE6
TARDE5
TARDE4
TARDE3
TARDE2
TARDE1
TARDE0
xxxx
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal para dispositivos PinHigh.
Nota
1:
El conjunto real de pines del puerto de E/S varía de un dispositivo a otro. Consulte los diagramas de distribución de pines correspondientes.
TABLA 4-30:
MAPA DE REGISTRO PORTF(1)
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos los reinicios
TRISF
02DE
—
—
TRISF13
TRISF12
—
—
—
TRISF8
TRISF7
TRISF6
TRISF5
TRISF4
TRISF3
TRISF2
TRISF1
TRISF0
31FF
PORTAF
02E0
—
—
RF13
RF12
—
—
—
RF8
RF7
RF6
RF5
RF4
RF3
RF2
RF1
RF0
xxxx
LATF
02E2
—
—
LATF13
LATF12
—
—
—
LATF8
LATF7
LATF6
LATF5
LATF4
LATF3
LATF2
LATF1
LATF0
xxxx
ODCF
06DE
—
—
ODCF13
ODCF12
—
—
—
ODCF8
ODCF7
ODCF6
ODCF5
ODCF4
ODCF3
ODCF2
ODCF1
ODCF0
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal para dispositivos PinHigh.
Nota
1:
El conjunto real de pines del puerto de E/S varía de un dispositivo a otro. Consulte los diagramas de distribución de pines correspondientes.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 60
© 2009 Microchip Technology Inc.
 
TABLA 4-31:
MAPA DE REGISTRO PORTG(1)
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
TRIGO
02E4
TRISG15
TRISG14
TRISG13
TRISG12
—
—
TRISG9
TRISG8
TRISG7
TRISG6
—
—
TRISG3
TRISG2
TRISG1
TRISG0
F3CF
PUERTO
02E6
RG15
RG14
RG13
RG12
—
—
RG9
RG8
RG7
RG6
—
—
RG3
RG2
RG1
RG0
xxxx
LATG
02E8
LATG15
LATG14
LATG13
LATG12
—
—
LATG9
LATG8
LATG7
LATG6
—
—
LATG3
LATG2
LATG1
LATG0
xxxx
ODCG
06E4
ODCG15
ODCG14
ODCG13
ODCG12
—
—
ODCG9
ODCG8
ODCG7
ODCG6
—
—
ODCG3
ODCG2
ODCG1
ODCG0
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal para dispositivos PinHigh.
Nota
1:
El conjunto real de pines del puerto de E/S varía de un dispositivo a otro. Consulte los diagramas de distribución de pines correspondientes.
TABLA 4-32:
MAPA DE REGISTRO DE CONTROL DEL SISTEMA
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
RCON
0740
TRAMPA
IOPUWR
—
—
—
—
—
VREGS
EXTRA
ROE
SWDTEN
WDTO
DORMIR
INACTIVO
BOR
POR
xxxx(1)
OSCCON
0742
—
COSC<2:0>
—
NOSC<2:0>
CLKLOCK
—
BLOQUEAR
—
FQ
—
LPOSCEN
oswen
0300(2)
CLKDIV
0744
retorno de la inversión
DORMIR<2:0>
DOCENA
FRCDIV<2:0>
PLLPOST<1:0>
—
PLLPRE<4:0>
3040
PLLFBD
0746
—
—
—
—
—
—
—
PLLDIV<8:0>
0030
OSCTÚN
0748
—
—
—
—
—
—
—
—
—
—
SINTONIZAR<5:0>
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.
Nota
1:
Registro RCON Los valores de reinicio dependen del tipo de reinicio. 
2:
Registro OSCCON Valores de reinicio que dependen de los bits de configuración FOSC y por tipo de reinicio. 
TABLA 4-33:
MAPA DE REGISTRO NVM
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
NVMCON
0760
WR
reyezuelo
WRERR
—
—
—
—
—
—
BORRAR
—
—
NVMOP<3:0>
0000(1)
LLAVE NVM
0766
—
—
—
—
—
—
—
—
CLAVE NVM<7:0>
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.
Nota
1:
El valor de reinicio que se muestra es solo para POR. El valor de otros estados de reinicio depende del estado de las operaciones de escritura o borrado de memoria en el momento del reinicio.
TABLA 4-34:
MAPA DE REGISTRO PMD
Nombre de archivo
dirección
Bit 15
Bit 14
Bit 13
Bit 12
Bit 11
Bit 10
Bit 9
Bit 8
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
Todos 
Se reinicia
PMD1
0770
T5MD
T4MD
T3MD
T2MD
DM1
—
—
DCIMD
I2C1MD
U2MD
U1MD
SPI2MD
SPI1MD
C2MD
C1MD
AD1MD
0000
PMD2
0772
IC8MD
IC7MD
IC6MD
IC5MD
IC4MD
IC3MD
IC2MD
IC1MD
OC8MD
OC7MD
OC6MD
OC5MD
OC4MD
OC3MD
OC2MD
OC1MD
0000
PMD3
0774
T9MD
T8MD
T7MD
T6MD
—
—
—
—
—
—
—
—
—
—
I2C2MD
AD2MD
0000
Leyenda:
x = valor desconocido al restablecer, — = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

© 2009 Microchip Technology Inc. 
DS70286C-página 61 
dsPIC33FJXXXGPX06/X08/X10 
4.2.7 
PILA DE SOFTWARE 
Además de su uso como registro de trabajo, el W15 
registrarse en los dispositivos dsPIC33FJXXXGPX06/X08/X10 
También se utiliza como software Stack Pointer. La pila 
El puntero siempre apunta a la primera palabra libre disponible. 
y crece de direcciones inferiores a superiores. Él 
pre-decrementos para stack pops y post-incrementos para 
empuja la pila, como se muestra en la Figura 4-6. Para un empujón de PC 
durante cualquier instrucción CALL, el MSb de la PC se 
cero extendido antes del empuje, asegurando que el MSb 
siempre es claro. 
El registro de límite de puntero de pila (SPLIM) asociado 
con el puntero de pila establece un límite de dirección superior 
para la pila. SPLIM no se inicializa en el reinicio. como es el 
En el caso del puntero de pila, SPLIM<0> se fuerza a '0' 
porque todas las operaciones de pila deben estar alineadas con palabras. 
Siempre que se genere un EA utilizando W15 como fuente 
o puntero de destino, la dirección resultante es 
comparado con el valor en SPLIM. Si el contenido de 
el puntero de pila (W15) y el registro SPLIM están 
igual y se realiza una operación de inserción, se produce un error de pila 
la trampa no ocurrirá. La trampa de error de pila ocurrirá en un 
operación de empuje posterior. Así, por ejemplo, si es 
Es deseable causar una trampa de error de pila cuando la pila 
crece más allá de la dirección 0x2000 en RAM, inicialice el 
SPLIM con el valor 0x1FFE. 
De manera similar, se detecta una trampa de desbordamiento insuficiente (error de pila) del puntero de pila. 
generado cuando se encuentra que la dirección del puntero de pila 
ser menor que 0x0800. Esto evita que la pila 
interferir con el Registro de Función Especial (SFR) 
espacio. 
Una escritura en el registro SPLIM no debe realizarse inmediatamente. 
seguido de una operación de lectura indirecta utilizando W15. 
FIGURA 4-6: 
MARCO DE PILA DE LLAMADA 
4.2.8 
FUNCIÓN DE PROTECCIÓN DE RAM DE DATOS 
La familia de productos dsPIC33F admite RAM de datos 
funciones de protección que permiten que segmentos de RAM 
estar protegido cuando se utiliza junto con Boot y 
Seguridad del segmento de código seguro. BSRAM (RAM segura 
segmento para BS) sólo es accesible desde el Boot 
Código Flash de segmento cuando está habilitado. SSRAM (seguro 
segmento RAM para RAM) sólo es accesible desde el 
Código Flash de segmento seguro cuando está habilitado. Ver 
Tabla 4-1 para una descripción general de BSRAM y SSRAM 
SFR. 
4.3 
Modos de direccionamiento de instrucciones 
Los modos de direccionamiento en la Tabla 4-35 forman la base de 
los modos de direccionamiento optimizados para soportar las necesidades específicas 
características de las instrucciones individuales. el direccionamiento 
Los modos proporcionados en la clase MAC de instrucciones son 
algo diferentes a los de la otra instrucción 
tipos. 
4.3.1 
INSTRUCCIONES DE REGISTRO DE ARCHIVO 
La mayoría de las instrucciones de registro de archivos utilizan un campo de dirección de 13 bits. 
(f) abordar directamente los datos presentes en el primer 8192 
bytes de memoria de datos (Near Data Space). La mayoría de archivos 
Las instrucciones de registro emplean un registro de trabajo, W0, 
que se indica como WREG en estas instrucciones. El 
El destino suele ser el mismo registro de archivo o 
WREG (a excepción de la instrucción MUL), 
que escribe el resultado en un registro o par de registros. El 
La instrucción MOV permite flexibilidad adicional y puede 
acceder a todo el espacio de datos. 
4.3.2 
INSTRUCCIONES DE LA MCU 
Las instrucciones de la MCU de 3 operandos tienen la forma: 
Operando 3 = Operando 1 <función> Operando 2 
donde el operando 1 es siempre un registro de trabajo (es decir, el 
El modo de direccionamiento sólo puede ser de registro directo), lo cual es 
denominado Wb. El operando 2 puede ser un registro W, 
obtenido de la memoria de datos, o un literal de 5 bits. El resultado 
La ubicación puede ser un registro W o una memoria de datos. 
ubicación. Los siguientes modos de direccionamiento son 
apoyado por instrucciones de MCU: 
• Regístrate directamente 
• Registrarse indirectamente 
• Registro Indirecto Post-Modificado 
• Registrar Indirecto Pre-Modificado 
• Literal de 5 o 10 bits 
Nota: 
Un envío de PC durante el procesamiento de excepciones 
concatena el registro SRL al MSb 
del PC antes del empuje. 
<Palabra libre> 
ordenador<15:0> 
000000000 
0 
15 
W15 (antes de LLAMADA) 
W15 (después de LLAMADA) 
La pila crece hacia 
dirección superior 
0x0000 
PC<22:16> 
ESTALLIDO 
: [--W15] 
EMPUJAR: [W15++] 
Nota: 
No todas las instrucciones soportan todos los 
modos de direccionamiento indicados anteriormente. Individual 
Las instrucciones pueden admitir diferentes subconjuntos. 
de estos modos de direccionamiento. 

dsPIC33FJXXXGPX06/X08/X10 
DS70286C-página 62 
© 2009 Microchip Technology Inc. 
TABLA 4-35: 
MODOS DE DIRECCIONAMIENTO FUNDAMENTALES COMPATIBLES 
4.3.3 
MOVER Y ACUMULADOR 
INSTRUCCIONES 
Mover instrucciones y la clase de acumulador DSP de 
Las instrucciones proporcionan un mayor grado de direccionamiento. 
flexibilidad que otras instrucciones. Además de la 
Direccionamiento 
modos 
apoyado 
por 
mayoría 
MCU 
Instrucciones, instrucciones de movimiento y acumulador también. 
apoyo 
Registro 
Indirecto 
con 
Registro 
Compensar 
Modo de direccionamiento, también conocido como Registro Indexado 
modo. 
En resumen, los siguientes modos de direccionamiento son 
apoyado por instrucciones de movimiento y acumulador: 
• Regístrate directamente 
• Registrarse indirectamente 
• Registro Indirecto Post-modificado 
• Registro Indirecto Pre-modificado 
• Registro indirecto con compensación de registro (indexado) 
• Registro indirecto con compensación literal 
• Literales de 8 bits 
• Literales de 16 bits 
4.3.4 
INSTRUCCIONES MAC 
Las instrucciones DSP de operando de fuente dual (CLR, ED, 
EDAC, MAC, MPY, MPY.N, MOVSAC y MSC), también referido 
como instrucciones MAC, utilice un conjunto simplificado de 
modos de direccionamiento para permitir al usuario 
manipular los punteros de datos a través del registro indirecto 
mesas. 
Los registros de captación previa del operando de 2 fuentes deben 
miembros del conjunto {W8, W9, W10, W11}. Para datos 
lecturas, W8 y W9 siempre se dirigen al X RAGU 
y W10 y W11 siempre estarán dirigidos a la Y 
AGU. Las direcciones efectivas generadas (antes y 
después de la modificación) deben, por lo tanto, ser direcciones válidas 
dentro del espacio de datos X para W8 y W9 y el espacio de datos Y 
para W10 y W11. 
En resumen, los siguientes modos de direccionamiento son 
soportado por la clase MAC de instrucciones: 
• Registrarse indirectamente 
• Registro Indirecto Post-Modificado por 2 
• Registro Indirecto Post-Modificado por 4 
• Registro Indirecto Post-Modificado por 6 
• Registro indirecto con compensación de registro (indexado) 
4.3.5 
OTRAS INSTRUCCIONES 
Además de los diversos modos de direccionamiento descritos anteriormente, 
Algunas instrucciones utilizan constantes literales de varios tamaños. 
Por ejemplo, las instrucciones BRA (branch) utilizan archivos firmados de 16 bits. 
literales para especificar el destino de la sucursal directamente, mientras que 
la instrucción DISI utiliza un campo literal sin signo de 14 bits. En 
algunas instrucciones, como ADD Acc, la fuente de un 
El operando o resultado está implícito en el propio código de operación. Cierto 
Las operaciones, como NOP, no tienen operandos. 
4.4 
Direccionamiento de módulo 
El modo de direccionamiento de módulo es un método para proporcionar una 
medios automatizados para soportar buffers de datos circulares utilizando 
hardware. El objetivo es eliminar la necesidad de 
software para realizar verificaciones de límites de direcciones de datos 
al ejecutar código de bucle cerrado, como es típico en 
muchos algoritmos DSP. 
El direccionamiento de módulo puede funcionar tanto en datos como en programas. 
espacio (ya que el mecanismo del puntero de datos es esencialmente 
lo mismo para ambos). Se puede admitir un buffer circular 
en cada una de las X (que también proporciona los punteros a 
espacio de programa) y espacios de datos Y. Direccionamiento de módulo 
Modo de direccionamiento 
Descripción 
Archivo Registro Directo 
La dirección del registro del archivo se especifica explícitamente. 
Regístrate Directo 
Se accede directamente al contenido de un registro. 
Registrarse Indirecto 
El contenido de Wn forma el EA. 
Registro Indirecto Post-Modificado 
El contenido de Wn forma el EA. Wn se modifica posteriormente (incrementado o 
decrementado) por un valor constante. 
Registro Indirecto Pre-Modificado 
Wn se modifica previamente (incrementa o disminuye) mediante un valor constante con signo 
para formar la EA. 
Registro indirecto con compensación de registro 
La suma de Wn y Wb forma el EA. 
Registrar indirecto con compensación literal 
La suma de Wn y un literal forma el EA. 
Nota: 
Para las instrucciones MOV, el Direccionamiento 
El modo especificado en las instrucciones puede diferir. 
para el EA de origen y de destino. 
Sin embargo, el Wb (desplazamiento de registro) de 4 bits 
El campo se comparte entre la fuente y 
destino (pero normalmente sólo lo utiliza 
uno). 
Nota: 
No todas las instrucciones soportan todos los 
Modos de direccionamiento indicados anteriormente. Individual 
Las instrucciones pueden admitir diferentes subconjuntos. 
de estos modos de direccionamiento. 
Nota: 
Registro indirecto con compensación de registro 
El modo de direccionamiento solo está disponible para W9 
(en el espacio X) y W11 (en el espacio Y). 

© 2009 Microchip Technology Inc.
DS70286C-página 63
dsPIC33FJXXXGPX06/X08/X10
Puede operar en cualquier puntero de registro W. Sin embargo, no es
Se recomienda utilizar W14 o W15 para el direccionamiento de módulo.
ya que estos dos registros se utilizan como marco de pila
Puntero y puntero de pila, respectivamente. 
En general, cualquier buffer circular en particular sólo puede ser
configurado para operar en una dirección ya que hay
ciertas restricciones en la dirección de inicio del búfer (para incrementos)
memorias intermedias) o dirección final (para disminuir
buffers), basándose en la dirección del buffer. 
La única excepción a las restricciones de uso es para
buffers que tienen una longitud de potencia de 2. Como estos
buffers satisfacen los criterios de dirección inicial y final,
puede funcionar en modo bidireccional (es decir, dirección
Se realizarán verificaciones de límites tanto en la parte inferior
y límites superiores de dirección).
4.4.1
DIRECCIÓN INICIO Y FINAL
El esquema de direccionamiento de módulo requiere que un
y la dirección final se especificarán y cargarán en el
Registros de dirección de búfer de módulo de 16 bits: XMODSRT,
XMODEND, 
YMODSRT 
y 
YMODEND 
(ver
Tabla 4-1).
La longitud de un búfer circular no se especifica directamente. eso
es 
determinado 
por 
el 
diferencia 
entre 
el
direcciones de inicio y fin correspondientes. el maximo
La longitud posible del buffer circular es de 32K palabras.
(64 Kbytes).
4.4.2
W REGISTRO DE DIRECCIÓN 
SELECCIÓN
El control de direccionamiento de módulo y bit invertido
El registro, MODCON<15:0>, también contiene indicadores de habilitación.
como campo de registro W para especificar los registros de dirección W.
Los campos XWM y YWM seleccionan qué registros
operar con direccionamiento de módulo. Si XWM = 15, X RAGU
y el direccionamiento del módulo X WAGU está deshabilitado. De manera similar, si
YWM = 15, Y El direccionamiento del módulo AGU está deshabilitado.
El registro W del puntero del espacio de direcciones X (XWM), para
cuyo módulo de direccionamiento se aplicará, se almacena en
MODCON<3:0> (ver Tabla 4-1). El direccionamiento de módulo es
habilitado para el espacio de datos X cuando XWM se establece en cualquier valor
distinto de '15' y el bit XMODEN está establecido en
MODCON<15>.
El registro W del puntero del espacio de direcciones Y (YWM) para
qué módulo direccionamiento se aplicará se almacena en
MODCON<7:4>. El direccionamiento de módulo está habilitado para Y
espacio de datos cuando YWM se establece en cualquier valor distinto de
'15' y el bit YMODEN se establece en MODCON<14>.
FIGURA 4-7:
EJEMPLO DE OPERACIÓN DE DIRECCIONAMIENTO DE MÓDULO
Nota:
Y 
espacio 
módulo 
Dirigiéndose 
EA
Los cálculos asumen datos del tamaño de una palabra (LSb
de cada EA siempre está claro). 
0x1100
0x1163
Dirección de inicio = 0x1100
Dirección final = 0x1163
Longitud = 0x0032 palabras
byte
Dirección
MOVIMIENTO
#0x1100, W0
MOVIMIENTO
W0, XMODSRT
;establecer la dirección de inicio del módulo
MOVIMIENTO
#0x1163, W0
MOVIMIENTO
W0, MODERNO
;establecer la dirección final del módulo
MOVIMIENTO
#0x8001, W0
MOVIMIENTO
W0, MODCON
;habilitar W1, X AGU para módulo
MOVIMIENTO
#0x0000, W0
;W0 mantiene el valor de llenado del buffer
MOVIMIENTO
#0x1110, W1
;apunta W1 al búfer
HACER
OTRA VEZ, #0x31
;llenar las 50 ubicaciones de buffer
MOVIMIENTO
W0, [W1++]
;llene la siguiente ubicación
OTRA VEZ:
INC W0, W0
;incrementar el valor de relleno

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 64
© 2009 Microchip Technology Inc.
4.4.3
DIRECCIONAMIENTO DEL MÓDULO 
APLICABILIDAD
El direccionamiento de módulo se puede aplicar al efectivo
Cálculo de dirección (EA) asociado con cualquier W
registrarse. Es importante tener en cuenta que la dirección
límites comprobar si hay direcciones menores o mayores
que, el superior (para incrementar los buffers) y el inferior (para
buffers decrecientes) direcciones límite (no solo
igual a). Por lo tanto, los cambios de dirección pueden saltar
más allá de los límites y aún así ajustarse correctamente.
4.5
Direccionamiento de bits invertidos
El modo de direccionamiento de bits invertidos pretende simplificar
Reordenamiento de datos para algoritmos FFT radix-2. es 
admitido por la X AGU solo para escritura de datos.
El modificador, que puede ser un valor constante o un registro.
contenido, se considera que tiene el orden de los bits invertido. el
El origen y el destino de las direcciones se mantienen en orden normal.
Por tanto, el único operando que requiere inversión es el modificador.
4.5.1
DIRECCIONAMIENTO DE BIT INVERTIDO 
IMPLEMENTACIÓN
El modo de direccionamiento de bits invertidos se habilita cuando:
1.
Bits BWM (selección de registro W) en el
El registro MODCON tiene cualquier valor distinto de '15'
(el 
pila 
no puedo 
ser 
accedido 
usando
Direccionamiento de bits invertidos).
2.
El bit BREN se establece en el registro XBREV.
3.
El modo de direccionamiento utilizado es Registro Indirecto.
con Pre-Incremento o Post-Incremento.
Si la longitud de un búfer de bits invertidos es M = 2N bytes,
los últimos 'N' bits de la dirección de inicio del búfer de datos deben
ser ceros. 
XB<14:0> es el modificador de dirección de bits invertidos, o
"punto de pivote", que suele ser una constante. En el caso de
un cálculo FFT, su valor es igual a la mitad de la FFT
Tamaño del buffer de datos. 
Cuando está activado, el direccionamiento de bits invertidos sólo es
ejecutado para Registro Indirecto con Pre-Incremento o
Direccionamiento post-incremento y escritura de datos de tamaño palabra.
No funcionará para ningún otro modo de direccionamiento ni para
Se generan datos de tamaño byte y direcciones normales.
en cambio. Cuando el direccionamiento de bits invertidos está activo, el
W El puntero de dirección siempre se agrega a la dirección.
modificador (XB) y el desplazamiento asociado con el registro.
ter Se ignora el modo de direccionamiento indirecto. Además, como
Los datos del tamaño de una palabra son un requisito, el LSb del EA es
ignorado (y siempre claro). 
Si ya se ha habilitado el direccionamiento de bits invertidos
configurando el bit BREN (XBREV<15>), luego una escritura en
el registro XBREV no debe seguirse inmediatamente
mediante una operación de lectura indirecta utilizando el registro W que
ha sido designado como el puntero de bits invertidos.
Nota:
La dirección efectiva corregida en módulo es
escrito de nuevo en el registro sólo cuando
Direccionamiento previo o posterior a la modificación
El modo se utiliza para calcular el efectivo.
dirección. Cuando una dirección se desplaza (p. ej.,
[W7+W2]), Dirección de módulo
se realiza la corrección pero el contenido de
el registro permanece sin cambios. 
Nota:
Todos los cálculos de EA con bits invertidos suponen
datos del tamaño de una palabra (LSb de cada EA es
siempre claro). El valor XB se escala
en consecuencia para generar compatible (byte)
direcciones.
Nota:
Direccionamiento de módulo y bit invertido
Dirigiéndose 
debería 
no 
ser 
habilitado
juntos. En caso de que el usuario intente
Para hacerlo, el direccionamiento de bits invertidos
asume prioridad cuando está activo para la X
Direccionamiento de módulo WAGU y X WAGU
voluntad 
ser 
discapacitado. 
Sin embargo, 
módulo
El direccionamiento seguirá funcionando en el X
RAGU.

© 2009 Microchip Technology Inc.
DS70286C-página 65
dsPIC33FJXXXGPX06/X08/X10
FIGURA 4-8:
EJEMPLO DE DIRECCIÓN DE BIT INVERTIDO
TABLA 4-36:
SECUENCIA DE DIRECCIÓN INVERTIDA DE BIT (16 ENTRADAS)
b3 b2 b1 0
b2 b3 b4 0
Ubicaciones de bits intercambiadas de izquierda a derecha
Alrededor del centro del valor binario
Dirección de bits invertidos
XB = 0x0008 para un búfer de bits invertidos de 16 palabras
b7 b6 b5 b1
b7 b6 b5 b4
b11 b10 b9 b8
b11 b10 b9 b8
b15 b14 b13 b12
b15 b14 b13 b12
Dirección secuencial
Punto de pivote
Dirección normal
Dirección de bits invertidos
A3
A2
A1
A0
decimales
A3
A2
A1
A0
decimales
0
0
0
0
0
0
0
0
0
0
0
0
0
1
1
1
0
0
0
8
0
0
1
0
2
0
1
0
0
4
0
0
1
1
3
1
1
0
0
12
0
1
0
0
4
0
0
1
0
2
0
1
0
1
5
1
0
1
0
10
0
1
1
0
6
0
1
1
0
6
0
1
1
1
7
1
1
1
0
14
1
0
0
0
8
0
0
0
1
1
1
0
0
1
9
1
0
0
1
9
1
0
1
0
10
0
1
0
1
5
1
0
1
1
11
1
1
0
1
13
1
1
0
0
12
0
0
1
1
3
1
1
0
1
13
1
0
1
1
11
1
1
1
0
14
0
1
1
1
7
1
1
1
1
15
1
1
1
1
15

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 66
© 2009 Microchip Technology Inc.
4.6
Programa de interfaz y datos 
Espacios de memoria
La arquitectura dsPIC33FJXXXGPX06/X08/X10 utiliza
un espacio de programa de 24 bits de ancho y un espacio de datos de 16 bits de ancho
espacio. La arquitectura también es una Harvard modificada.
esquema, lo que significa que los datos también pueden estar presentes en el
espacio del programa. Para utilizar estos datos con éxito, debe
ser accedido de una manera que preserve la alineación de
información en ambos espacios.
aparte 
de 
normales 
ejecución, 
el
La arquitectura dsPIC33FJXXXGPX06/X08/X10 proporciona
Dos métodos mediante los cuales se puede acceder al espacio del programa.
durante la operación: 
• Uso de instrucciones de tabla para acceder a bytes individuales 
o palabras en cualquier lugar del espacio del programa
• Reasignar una parte del espacio del programa a 
el espacio de datos (visibilidad del espacio del programa)
Las instrucciones de la tabla permiten que una aplicación lea o escriba
a pequeñas áreas de la memoria del programa. Esta capacidad
hace que el método sea ideal para acceder a tablas de datos que
necesitan ser actualizados de vez en cuando. También permite
acceso a todos los bytes de la palabra del programa. el
El método de reasignación permite que una aplicación acceda a una
gran bloque de datos en modo de sólo lectura, lo cual es ideal
para búsquedas en una tabla grande de datos estáticos. Sólo puede
acceder a la palabra menos significativa de la palabra del programa.
4.6.1
DIRECCIÓN DEL ESPACIO DEL PROGRAMA
Dado que los rangos de direcciones para los datos y el programa
los espacios son de 16 y 24 bits, respectivamente, un método es
necesario para crear una dirección de programa de 23 o 24 bits
a partir de registros de datos de 16 bits. La solución depende de la
método de interfaz a utilizar.
Para operaciones de tabla, el registro de página de tabla de 8 bits
(TBLPAG) se utiliza para definir una región de palabras de 32 K dentro
el espacio del programa. Esto está concatenado con un 16 bits.
EA para llegar a una dirección de espacio de programa completo de 24 bits. en
En este formato, se utiliza el bit más significativo de TBLPAG.
para determinar si la operación ocurre en la memoria del usuario
(TBLPAG<7> = 0) o la memoria de configuración
(TBLPAG<7> = 1).
Para operaciones de reasignación, el espacio de programa de 8 bits
El registro de visibilidad (PSVPAG) se utiliza para definir un
Página de 16K palabras en el espacio del programa. cuando más
Una parte importante del EA es '1', PSVPAG está concatenado
con los 15 bits inferiores del EA para formar un programa de 23 bits
dirección espacial. A diferencia de las operaciones de tabla, esto limita
operaciones de reasignación estrictamente al área de memoria del usuario.
La Tabla 4-37 y la Figura 4-9 muestran cómo se ejecuta el programa EA.
creado para operaciones de tablas y accesos de reasignación
a partir de los datos del EA. Aquí, P<23:0> se refiere a un programa
palabra de espacio, mientras que D<15:0> se refiere a un espacio de datos
palabra.
TABLA 4-37:
CONSTRUCCIÓN DE DIRECCIÓN DEL ESPACIO DEL PROGRAMA
Tipo de acceso
Acceso
espacio
Dirección del espacio del programa
<23>
<22:16>
<15>
<14:1>
<0>
Acceso a instrucciones
(Ejecución de código)
Usuario
0
ordenador<22:1>
0
0xx
xxxx
xxxx
xxxx
xxxxxxx0
TBLRD/TBLWT
(Byte/Palabra Lectura/Escritura)
Usuario
TBLPAG<7:0>
Datos EA<15:0>
      0xxx xxxx
xxxx xxxx xxxx xxxxx
Configuración 
TBLPAG<7:0>
Datos EA<15:0>
      1xxx xxxx
xxxx xxxx xxxx xxxxx
Visibilidad del espacio del programa
(Reasignación de bloques/Lectura)
Usuario
0
PSVPAG<7:0>
Datos EA<14:0>(1)
   0 xxxx xxxxx
xxx xxxx xxxx xxxxx
Nota 1:
Los datos EA<15> siempre son '1' en este caso, pero no se utilizan para calcular la dirección del espacio del programa. Bit 15 de 
la dirección es PSVPAG<0>.

© 2009 Microchip Technology Inc.
DS70286C-página 67
dsPIC33FJXXXGPX06/X08/X10
FIGURA 4-9:
ACCESO A DATOS DESDE LA GENERACIÓN DE DIRECCIONES DEL ESPACIO DEL PROGRAMA
0
Contador de programas
23 bits
1
PSVPAG
8 bits
EA
15 bits
Contador de programa(1)
Seleccionar
TBLPAG
8 bits
EA
16 bits
Selección de bytes
0
0
1/0
Usuario/Configuración
Operaciones de mesa(2)
Visibilidad del espacio del programa(1)
Seleccionar espacio
24 bits
23 bits
(Reasignación)
1/0
0
Nota 1: El LSb de las direcciones del espacio del programa siempre se fija en '0' para mantener la palabra
Alineación de datos en el programa y espacios de datos.
2: No es necesario que las operaciones de tabla estén alineadas por palabras. Se permiten operaciones de lectura de tablas.
en el espacio de la memoria de configuración.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 68
© 2009 Microchip Technology Inc.
4.6.2
ACCESO A LOS DATOS DESDE EL PROGRAMA 
TABLA DE USO DE MEMORIA 
INSTRUCCIONES
Las instrucciones TBLRDL y TBLWTL ofrecen una conexión directa
método de lectura o escritura de la palabra inferior de cualquier
dirección dentro del espacio del programa sin ir
a través del espacio de datos. El TBLRDH y el TBLWTH
Las instrucciones son el único método para leer o escribir el
8 bits superiores de una palabra de espacio de programa como datos.
El PC se incrementa en dos por cada paso sucesivo.
Palabra de programa de 24 bits. Esto permite que la memoria del programa
direcciones para asignarlas directamente a direcciones del espacio de datos.
Por tanto, la memoria de programa puede considerarse como dos módulos de 16 bits.
espacios de direcciones de toda la palabra, que residen uno al lado del otro, cada uno
con el mismo rango de direcciones. TBLRDL y TBLWTL
acceder al espacio que contiene el menos significativo
palabra de datos y TBLRDH y TBLWTH acceden al espacio
que contiene el byte de datos superior. 
Se proporcionan dos instrucciones de tabla para mover bytes o
datos de tamaño palabra (16 bits) hacia y desde el espacio del programa.
Ambos funcionan como operaciones de bytes o de palabras.
1.
TBLRDL (Lectura baja de tabla): en modo Word,
mapea la palabra inferior del espacio del programa 
ubicación (P<15:0>) a una dirección de datos (D<15:0>).
En modo Byte, ya sea el byte superior o inferior de
la palabra de programa inferior se asigna a la palabra de programa inferior
byte de una dirección de datos. El byte superior es
seleccionado cuando Byte Select es '1'; el byte inferior
se selecciona cuando es '0'.
2.
TBLRDH (Lectura alta de tabla): en modo Word,
asigna toda la palabra superior de la dirección de un programa
(P<23:16>) a una dirección de datos. Tenga en cuenta que
D<15:8>, el 'byte fantasma', siempre será '0'.
En modo Byte, asigna el byte superior o inferior de
la palabra de programa a D<7:0> de los datos
dirección, como arriba. Tenga en cuenta que los datos
siempre será '0' cuando el byte 'fantasma' superior esté
seleccionado (Selección de bytes = 1).
De manera similar, dos instrucciones de tabla, TBLWTH
y TBLWTL, se utilizan para escribir bytes individuales o
palabras a una dirección de espacio de programa. Los detalles de
su funcionamiento se explica en la Sección 5.0 “Flash
Memoria de programa”.
Para todas las operaciones de tabla, el área de memoria del programa
El espacio al que se accederá está determinado por la página de la tabla.
registro (TBLPAG). TBLPAG cubre todo el programa
espacio de memoria del dispositivo, incluido el usuario y
espacios de configuración. Cuando TBLPAG<7> = 0, la tabla
La página se encuentra en el espacio de memoria del usuario. cuando
TBLPAG<7> = 1, la página se encuentra en configuración
espacio. 
FIGURA 4-10:
ACCEDER A LA MEMORIA DEL PROGRAMA CON TABLA DE INSTRUCCIONES
0
8
16
23
00000000
00000000
00000000
00000000
Byte 'fantasma'
TBLRDH.B (Wn<0> = 0)
TBLRDL.W
TBLRDL.B (Wn<0> = 1)
TBLRDL.B (Wn<0> = 0)
23
15
0
TBLPAG
02
0x000000
0x800000
0x020000
0x030000
Espacio del programa
La dirección para la operación de la tabla está determinada por los datos EA
dentro de la página definida por el registro TBLPAG. 
Sólo se muestran las operaciones de lectura; Las operaciones de escritura también son válidas en
el área de memoria del usuario.

© 2009 Microchip Technology Inc.
DS70286C-página 69
dsPIC33FJXXXGPX06/X08/X10
4.6.3
LECTURA DE DATOS DEL PROGRAMA 
MEMORIA USANDO ESPACIO DE PROGRAMA 
VISIBILIDAD
Los 32 Kbytes superiores de espacio de datos pueden opcionalmente
mapeado en cualquier página de 16K palabras del espacio del programa.
Esta opción proporciona acceso transparente a los archivos almacenados.
datos constantes del espacio de datos sin necesidad de
utilice instrucciones especiales (es decir, TBLRDL/H). 
Se produce el acceso al espacio del programa a través del espacio de datos.
si el bit más significativo del espacio de datos EA es '1' y
La visibilidad del espacio del programa se habilita configurando el PSV.
bit en el registro de control central (CORCON<2>). el
Ubicación del espacio de memoria del programa que se va a asignar.
en el espacio de datos está determinado por el programa
Registro de página de visibilidad espacial (PSVPAG). Este 8 bits
registro define cualquiera de las 256 posibles páginas de
16.000 palabras en el espacio del programa. En efecto, PSVPAG
Funciona como los 8 bits superiores de la memoria del programa.
dirección, con los 15 bits del EA funcionando como
bits inferiores. Tenga en cuenta que al incrementar el PC en 2 para
cada palabra de memoria de programa, los 15 bits de datos inferiores
Las direcciones de espacio se asignan directamente a los 15 bits inferiores del
direcciones de espacio de programa correspondientes. 
Las lecturas de datos en esta área añaden un ciclo adicional al
instrucción que se está ejecutando, ya que dos memorias de programa
se requieren recuperaciones. 
Aunque cada dirección de espacio de datos, 8000h y superiores,
se asigna directamente a la memoria de programa correspondiente
dirección (consulte la Figura 4-11), solo los 16 bits inferiores de la
Para contener los datos se utilizan palabras de programa de 24 bits. el
8 bits superiores de cualquier ubicación del espacio de programa utilizada como
los datos deben programarse con '1111 1111' o
'0000 0000' para forzar un NOP. Esto evita posibles
problemas en caso de que el área del código alguna vez sea accidentalmente
ejecutado.
Para operaciones que utilizan PSV y se ejecutan fuera
un bucle REPEAT, las instrucciones MOV y MOV.D
requieren un ciclo de instrucción además del especificado
tiempo de ejecución. Todas las demás instrucciones requieren dos
ciclos de instrucción además de la ejecución especificada
tiempo.
Para operaciones que utilizan PSV, que se ejecutan dentro
un bucle REPEAT, habrá algunos casos en los que
requieren dos ciclos de instrucción además del
tiempo de ejecución especificado de la instrucción:
• Ejecución en la primera iteración.
• Ejecución en la última iteración.
• Ejecución antes de salir del bucle debido a un 
interrumpir
• Ejecución al volver a entrar al bucle después de un 
la interrupción es atendida
Cualquier otra iteración del bucle REPEAT permitirá que el
instrucción que accede a los datos, utilizando PSV, para ejecutar en un
ciclo único.
FIGURA 4-11:
OPERACIÓN DE VISIBILIDAD ESPACIAL DEL PROGRAMA
Nota:
El acceso al PSV está temporalmente deshabilitado durante
lecturas/escrituras de tablas.
23
15
0
PSVPAG
Espacio de datos
Espacio del programa
0x0000
0x8000
0xFFFF
02
0x000000
0x800000
0x010000
0x018000
Cuando CORCON<2> = 1 y EA<15> = 1:
Los datos de la pagina. 
designado por el PSV-
PAG está mapeado en 
la mitad superior del 
memoria de datos 
espacio...
Datos EA<14:0>
...mientras que los 15 bits inferiores 
del EA especifican una 
dirección exacta dentro 
el área del PSV. esto 
corresponde exactamente a 
los mismos 15 bits inferiores 
del programa real 
dirección espacial.
Área del PSV

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 70
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70286C-página 71
dsPIC33FJXXXGPX06/X08/X10
5.0
MEMORIA DE PROGRAMA FLASH
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 contienen
Memoria interna de programas Flash para almacenar y
ejecutando el código de la aplicación. La memoria es legible,
grabable y borrable durante el funcionamiento normal a través del
toda la gama VDD.
La memoria flash se puede programar de dos formas:
1.
Programación en serie en circuito™ (ICSP™) 
capacidad de programación
2.
Autoprogramación en tiempo de ejecución (RTSP)
ICSP permite un dispositivo dsPIC33FJXXXGPX06/X08/X10
Para ser programado en serie mientras se encuentra en la aplicación final.
circuito. Esto se hace simplemente con dos líneas para
reloj de programación y datos de programación (uno de los
pares de pines de programación alternativos: PGECx/PGEDx), y
Otras tres líneas para alimentación (VDD), tierra (VSS) y
Borrado maestro (MCLR). Esto permite a los clientes fabricar
fabricar tableros con dispositivos no programados y luego
Programe el controlador de señal digital justo antes del envío.
el producto. Esto también permite que el firmware más reciente
o un firmware personalizado para ser programado.
RTSP se logra usando TBLRD (lectura de tabla) y
Instrucciones TBLWT (escritura de tabla). Con RTSP, el usuario
puede escribir datos de la memoria del programa ya sea en bloques o
'filas' de 64 instrucciones (192 bytes) a la vez o una sola
palabra de memoria del programa y borre la memoria del programa en
bloques o "páginas" de 512 instrucciones (1536 bytes) a la vez
tiempo.
5.1
Instrucciones de tabla y flash 
Programación
Independientemente del método utilizado, toda la programación de
La memoria flash se realiza con la tabla leída y la tabla.
escribir instrucciones. Estos permiten lectura y escritura directa.
acceso al espacio de memoria del programa desde los datos
memoria mientras el dispositivo está en modo de funcionamiento normal.
La dirección de destino de 24 bits en la memoria del programa es
formado utilizando los bits <7:0> del registro TBLPAG y el
Dirección efectiva (EA) de un registro W especificado en
instrucciones de la tabla, como se muestra en la Figura 5-1.
Las instrucciones TBLRDL y TBLWTL se utilizan para
leer o escribir en bits<15:0> de la memoria del programa.
TBLRDL y TBLWTL pueden acceder a la memoria del programa en
tanto en modo Palabra como Byte.
Las instrucciones TBLRDH y TBLWTH se utilizan para leer
o escribir en bits<23:16> de la memoria del programa. TBLRDH
y TBLWTH también puede acceder a la memoria del programa en Word
o modo Byte.
FIGURA 5-1:
DIRECCIONAMIENTO PARA REGISTROS DE MESA 
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 5. “Flash
Programación” 
(DS70191) 
en 
el
“Manual de referencia de la familia dsPIC33F”,
que está disponible en la web de Microchip
sitio (www.microchip.com).
0
Contador de programas
24 bits
Contador de programas
Registro TBLPAG
8 bits
Registro de trabajo EA
16 bits
byte
EA de 24 bits
0
1/0
Seleccionar
Usando
Instrucción de mesa
Usando
Usuario/Configuración
Seleccionar espacio

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 72
© 2009 Microchip Technology Inc.
5.2
Operación RTSP
El programa Flash dsPIC33FJXXXGPX06/X08/X10
La matriz de memoria está organizada en filas de 64 instrucciones.
o 192 bytes. RTSP permite al usuario borrar una página de
memoria, que consta de ocho filas (512 instrucciones)
a la vez, y programar una fila o una palabra a la vez.
tiempo. La Tabla 25-12 ilustra el borrado y la programación típicos.
tiempos de ming. Las páginas de borrado de 8 filas y una sola fila
Las filas de escritura están alineadas con los bordes, desde el comienzo del proceso.
memoria de gramos, en límites de 1536 bytes y 192
bytes, respectivamente.
La memoria del programa implementa buffers de retención que
Puede contener 64 instrucciones de datos de programación. anterior
a la operación de programación real, los datos de escritura
deben cargarse en los buffers en orden secuencial. el
Las palabras de instrucción cargadas siempre deben ser de un grupo.
de 64 límites.
La secuencia básica para la programación RTSP es configurar
un puntero de tabla, luego realice una serie de instrucciones TBLWT
para cargar los buffers. La programación se realiza mediante
configurar los bits de control en el registro NVMCON. un total
Se requieren 64 instrucciones TBLWTL y TBLWTH
para cargar las instrucciones.
Todas las operaciones de escritura de tablas son escrituras de una sola palabra.
(dos ciclos de instrucción) porque sólo los buffers son
escrito. Se requiere un ciclo de programación para
programando cada fila.
5.3
Operaciones de programación
Es necesaria una secuencia de programación completa para
programar o borrar el Flash interno en RTSP
modo. 
el 
procesador 
puestos 
(espera) 
hasta 
el
La operación de programación ha finalizado. 
El tiempo de programación depende de la precisión del FRC.
(ver Tabla 25-19) y el valor del oscilador FRC
Registro de sintonización (ver Registro 9-4). Utilice lo siguiente
fórmula para calcular los valores mínimo y máximo
para el tiempo de escritura de fila, el tiempo de borrado de página y Word
Escriba los parámetros de tiempo de ciclo (consulte la Tabla 25-12).
ECUACIÓN 5-1:
TIEMPO DE PROGRAMACIÓN
Por ejemplo, si el dispositivo funciona a +85°C, el
La precisión del FRC será ±2%. Si los bits TUN<5:0> (ver
Registro 9-4) están configurados en 'b111111, el mínimo
El tiempo de escritura de fila es:
y el tiempo máximo de escritura de fila es:
Al configurar el bit WR (NVMCON<15>) se inicia la operación.
ción, y el bit WR se borra automáticamente cuando el
la operación ha terminado.
5.4
Registros de control
Hay dos SFR que se utilizan para leer y escribir el
memoria flash del programa: 
• NVMCON: Registro de control de memoria flash
• NVMKEY: Registro de clave de memoria no volátil
El registro NVMCON (Registro 5-1) controla qué
bloques se van a borrar, qué tipo de memoria se debe
programado y el inicio del ciclo de programación.
NVMKEY (Registro 5-2) es un registro de sólo escritura que se
Se utiliza para protección contra escritura. Para iniciar una programación o
secuencia de borrado, el usuario debe escribir consecutivamente 55h
y AAh al registro NVMKEY. Consulte la Sección 5.3
“Operaciones de programación” para más detalles.
t
7,37MHz
Precisión del FRC
(
)%
Sintonización FRC
(
)%
×
×
-------------------------------------------------------------------------------------------------------------------------
TRW
11064 ciclos
7,37MHz
1
0,02
+
(
)
1
0.00375
–
(
)
×
×
----------------------------------------------------------------------------------------------
1,48 ms
=
=
TRW
11064 ciclos
7,37MHz
1
0,02
–
(
)
1
0.00375
–
(
)
×
×
---------------------------------------------------------------------------------------
1,54 ms
=
=

© 2009 Microchip Technology Inc.
DS70286C-página 73
dsPIC33FJXXXGPX06/X08/X10
              REGÍSTRESE 5-1:
NVMCON: REGISTRO DE CONTROL DE MEMORIA FLASH
R/SO-0(1)
R/W-0(1)
R/W-0(1)
U-0
U-0
U-0
U-0
U-0
WR
reyezuelo
WRERR
—
—
—
—
—
poco 15
poco 8
U-0
R/W-0(1)
U-0
U-0
R/W-0(1)
R/W-0(1)
R/W-0(1)
R/W-0(1)
—
BORRAR
—
—
NVMOP<3:0>(2)
poco 7
poco 0
Leyenda:
SO = Bit sólo configurable
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
WR: bit de control de escritura
1 = Inicia un programa de memoria Flash o una operación de borrado. La operación es autotemporizada y la broca es
borrado por el hardware una vez que se completa la operación 
0 = La operación de programación o borrado está completa e inactiva
poco 14
WREN: bit de habilitación de escritura
1 = Habilitar operaciones de programación/borrado de Flash
0 = Inhibir operaciones de programa/borrado de Flash
poco 13
WRERR: Bit de indicador de error de secuencia de escritura
1 = Se ha producido un programa incorrecto o un intento o terminación de secuencia de borrado (el bit está establecido 
automáticamente en cualquier intento de establecer el bit WR)
0 = La operación de programa o borrado se completó normalmente
bit 12-7
No implementado: leído como "0"
poco 6
BORRAR: Bit de borrado/habilitación de programa
1 = Realizar la operación de borrado especificada por NVMOP<3:0> en el siguiente comando WR
0 = Realizar la operación del programa especificada por NVMOP<3:0> en el siguiente comando WR
bit 5-4
No implementado: leído como "0"
poco 3-0
NVMOP<3:0>: Operación NVM Seleccionar bits(2) 
Si BORRAR = 1:
1111 = Operación de borrado masivo de memoria
1110 = Reservado
1101 = Borrar segmento general
1100 = Borrar segmento seguro
1011 = Reservado
0011 = Sin operación
0010 = Operación de borrado de página de memoria
0001 = Sin operación
0000 = Borrar un único byte del registro de configuración
Si BORRAR = 0:
1111 = Sin operación
1110 = Reservado
1101 = Sin operación
1100 = Sin operación
1011 = Reservado
0011 = Operación del programa de palabra de memoria
0010 = Sin operación
0001 = Operación del programa de fila de memoria
0000 = Programar un solo byte de registro de configuración
Nota 1: Estos bits solo se pueden restablecer en POR.
2: Todas las demás combinaciones de NVMOP<3:0> no están implementadas.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 74
© 2009 Microchip Technology Inc.
              
REGISTRO 5-2:
NVMKEY: REGISTRO DE CLAVE DE MEMORIA NO VOLÁTIL
U-0
U-0
U-0
U-0
U-0
U-0
U-0
U-0
—
—
—
—
—
—
—
—
poco 15
poco 8
W-0
W-0
W-0
W-0
W-0
W-0
W-0
W-0
CLAVE NVM<7:0>
poco 7
poco 0
Leyenda:
SO = Bit sólo configurable
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bit 15-8
No implementado: leído como "0"
poco 7-0
NVMKEY<7:0>: bits de registro de clave (solo escritura)

© 2009 Microchip Technology Inc.
DS70286C-página 75
dsPIC33FJXXXGPX06/X08/X10
5.4.1
ALGORITMO DE PROGRAMACIÓN PARA 
MEMORIA DE PROGRAMA FLASH
El usuario puede programar una fila del programa Flash.
memoria a la vez. Para ello es necesario borrar
la página de borrado de 8 filas que contiene la fila deseada.
El proceso general es:
1.
leer 
ocho 
filas 
de 
programa 
memoria
(512 instrucciones) y almacenar en la RAM de datos.
2.
Actualice los datos del programa en la RAM con el
nuevos datos deseados.
3.
Borre el bloque (ver Ejemplo 5-1):
a)
Establezca los bits NVMOP (NVMCON<3:0>) en
'0010' para configurar el borrado de bloques. Establecer el
BORRAR 
(NVMCON<6>) 
y 
reyezuelo
(NVMCON<14>) bits.
b)
Escriba la dirección inicial de la página a ser
borrado en los registros TBLPAG y W.
c)
Escribe 55h en NVMKEY.
d)
Escriba AAh en NVMKEY.
mi)
Establezca el bit WR (NVMCON<15>). el borrado
El ciclo comienza y la CPU se detiene durante el
duración del ciclo de borrado. Cuando el borrado es
Hecho, el bit WR se borra automáticamente.
4.
Escriba las primeras 64 instrucciones de la RAM de datos en
los buffers de memoria del programa (ver Ejemplo 5-2).
5.
Escriba el bloque de programa en la memoria Flash:
a)
Establezca los bits NVMOP en '0001' para configurar
para programación de filas. Borrar el bit BORRAR
y configure el bit WREN.
b)
Escriba #0x55 en NVMKEY.
c)
Escriba #0xAA en NVMKEY.
d)
Establezca el bit WR. El ciclo de programación
comienza y la CPU se detiene durante el tiempo
el ciclo de escritura. Cuando se escribe en Flash
la memoria está terminada, el bit WR se borra
automáticamente.
6.
Repita los pasos 4 y 5, utilizando el siguiente disponible
64 instrucciones del bloque en la RAM de datos por
incrementando el valor en TBLPAG, hasta que todos
512 instrucciones se escriben en la memoria Flash. 
Para protección contra operaciones accidentales, la escritura
Se debe utilizar la secuencia de inicio para NVMKEY para permitir
cualquier operación de borrado o programa para continuar. Después del
El comando de programación ha sido ejecutado, el usuario
debe esperar el tiempo de programación hasta programar
está completo. Las dos instrucciones que siguen al inicio de
la secuencia de programación debe ser NOP, como se muestra
en el ejemplo 5-3.
EJEMPLO 5-1:
BORRAR UNA PÁGINA DE MEMORIA DE PROGRAMA 
; Configure NVMCON para la operación de borrado de bloques
MOVIMIENTO
#0x4042, W0
;
MOVIMIENTO
W0, NVMCON
; Inicializar NVMCON
; Puntero de inicio a la fila que se va a BORRAR
MOVIMIENTO
#tblpage(PROG_ADDR), W0
; 
MOVIMIENTO
W0, TBLPAG
; Inicializar el límite de la página PM SFR
MOVIMIENTO
#tbloffset(PROG_ADDR), W0
; Inicializar el puntero EA[15:0] en la página
TBLWTL
W0, [W0]    
; Establecer la dirección base del bloque de borrado
DISI
#5
; Bloquear todas las interrupciones con prioridad <7
; para las próximas 5 instrucciones
MOVIMIENTO
#0x55, W0                  
MOVIMIENTO
W0, CLAVE NVM 
; Escribe la clave 55
 
MOVIMIENTO   
#0xAA, W1                 
;
MOVIMIENTO
W1, CLAVE NVM  
; Escribe la clave AA
BSET
NVMCON, #WR
; Iniciar la secuencia de borrado 
NOP 
; Inserte dos NOP después del borrado.
NOP
; el comando es afirmado

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 76
© 2009 Microchip Technology Inc.
EJEMPLO 5-2:
CARGANDO LOS BUFFERS DE ESCRITURA 
EJEMPLO 5-3:
INICIO DE UNA SECUENCIA DE PROGRAMACIÓN 
; Configure NVMCON para operaciones de programación de filas
MOVIMIENTO
#0x4001, W0
;
MOVIMIENTO
W0, NVMCON
; Inicializar NVMCON
; Configure un puntero a la primera ubicación de memoria del programa que se escribirá
; memoria de programa seleccionada y escritura habilitada
MOVIMIENTO
#0x0000, W0
; 
MOVIMIENTO
W0, TBLPAG
; Inicializar el límite de la página PM SFR
MOVIMIENTO
#0x6000, W0
; Un ejemplo de dirección de memoria de programa
; Realice las instrucciones TBLWT para escribir los pestillos
; 0th_program_word
MOVIMIENTO
#LOW_WORD_0, W2
; 
MOVIMIENTO
#HIGH_BYTE_0, W3
; 
TBLWTL
W2, [W0]
; Escribir palabra baja de PM en el pestillo del programa
TBLWTH
W3, [W0++]
; Escriba el byte alto de PM en el pestillo del programa
; 1er_programa_palabra
MOVIMIENTO
#LOW_WORD_1, W2
; 
MOVIMIENTO
#HIGH_BYTE_1, W3 
; 
TBLWTL
W2, [W0]
; Escribir palabra baja de PM en el pestillo del programa
TBLWTH
W3, [W0++] 
; Escriba el byte alto de PM en el pestillo del programa
;  2da_palabra_programa
MOVIMIENTO
#LOW_WORD_2, W2
; 
MOVIMIENTO
#HIGH_BYTE_2, W3
; 
TBLWTL
W2, [W0] 
; Escribir palabra baja de PM en el pestillo del programa
TBLWTH
W3, [W0++]
; Escriba el byte alto de PM en el pestillo del programa
•
•
•
; 63rd_program_word
MOVIMIENTO
#LOW_WORD_31, W2
; 
MOVIMIENTO
#HIGH_BYTE_31, W3
; 
TBLWTL
W2, [W0] 
; Escribir palabra baja de PM en el pestillo del programa
TBLWTH
W3, [W0++]
; Escriba el byte alto de PM en el pestillo del programa
DISI
#5
; Bloquear todas las interrupciones con prioridad <7
; para las próximas 5 instrucciones
MOVIMIENTO
#0x55, W0
MOVIMIENTO
W0, CLAVE NVM 
; Escribe la clave 55 
MOVIMIENTO   
#0xAA, W1             
;
MOVIMIENTO
W1, CLAVE NVM  
; Escribe la clave AA
BSET
NVMCON, #WR
; Iniciar la secuencia de borrado 
NOP 
; Inserte dos NOP después del
NOP
; se afirma el comando de borrado

© 2009 Microchip Technology Inc.
DS70286C-página 77
dsPIC33FJXXXGPX06/X08/X10
6.0
REINICIAR 
El módulo Restablecer combina todas las fuentes de Restablecimiento y
controla la señal de reinicio maestro del dispositivo, SYSRST. el
A continuación se muestra una lista de fuentes de reinicio del dispositivo:
• POR: Reinicio de encendido 
• BOR: Reinicio de caída
• MCLR: Restablecimiento de PIN de borrado maestro
• ROE: Instrucción RESET
• WDT: reinicio del temporizador de vigilancia
• TRAPR: Restablecimiento del conflicto de trampas
• IOPUWR: Código de operación ilegal y W no inicializado 
Registrarse Restablecer
Se muestra un diagrama de bloques simplificado del módulo Reset.
se muestra en la Figura 6-1.
Cualquier fuente activa de reinicio hará que SYSRST
señal activa. Muchos registros asociados con la CPU.
y los periféricos se ven obligados a un estado de reinicio conocido.
La mayoría de los registros no se ven afectados por un reinicio; su estado es
desconocido en POR y sin cambios por todos los demás reinicios.
Todos los tipos de dispositivo Restablecer establecerán un estado correspondiente
bit en el registro RCON para indicar el tipo de Reset
(ver Registro 6-1). Un POR borrará todos los bits, excepto
el bit POR (RCON<0>), que están establecidos. El usuario puede configurar
o borre cualquier bit en cualquier momento durante la ejecución del código. el
Los bits RCON sólo sirven como bits de estado. Establecer un particular
Restablecer el bit de estado en el software no causa un dispositivo
Reiniciar para ocurrir. 
El registro RCON también tiene otros bits asociados con
el temporizador de vigilancia y los estados de ahorro de energía del dispositivo.
La función de estos bits se analiza en otras secciones.
de este manual. 
FIGURA 6-1:
DIAGRAMA DE BLOQUES DEL SISTEMA DE RESTABLECIMIENTO
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 8.
“Restablecer” (DS70192) en el “dsPIC33F
Manual de referencia familiar”, que está disponible
capaz 
de 
el 
Microchip 
web 
sitio
(www.microchip.com).
Nota:
Consulte el periférico o CPU específico
sección de este manual para restablecer el registro
estados.
Nota:
Los bits de estado en el registro RCON
deben borrarse después de leerse para que
que el siguiente valor del registro RCON después de un
El reinicio del dispositivo será significativo. 
MCLR
VDD
Interno
Regulador
BOR
Dormir o inactivo
Instrucción RESET
WDT
Módulo
Filtro de falla
Conflicto trampa
Código de operación ilegal
Registro W no inicializado
SYSRST
Aumento del VDD
detectar
POR

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 78
© 2009 Microchip Technology Inc.
            REGISTRO 6-1:
RCON: REINICIAR REGISTRO DE CONTROL(1)
R/W-0
R/W-0
U-0
U-0
U-0
U-0
U-0
R/W-0
TRAMPA
IOPUWR
—
—
—
—
—
VREGS
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-1
R/W-1
EXTRA
ROE
SWDTEN(2)
WDTO
DORMIR
INACTIVO
BOR
POR
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
TRAPR: Bit de bandera de reinicio de trampa
1 = Se ha producido un reinicio del conflicto de trampas
0 = No se ha producido un reinicio del conflicto de trampas
poco 14
IOPUWR: Código de operación ilegal o bit de indicador de reinicio de acceso W no inicializado
1 = Una detección de código de operación ilegal, un modo de dirección ilegal o un registro W no inicializado utilizado como
El puntero de dirección provocó un reinicio
0 = No se ha producido un código de operación ilegal o un reinicio W no inicializado
bit 13-9
No implementado: leído como "0"
poco 8
VREGS: bit de espera del regulador de voltaje durante el modo de suspensión
1 = El regulador de voltaje está activo durante el modo de suspensión
0 = El regulador de voltaje pasa al modo de espera durante el modo de suspensión
poco 7
EXTR: Bit de pin de reinicio externo (MCLR)
1 = Se ha producido un reinicio maestro de borrado (pin)
0 = No se ha producido un reinicio de borrado maestro (pin)
poco 6
SWR: bit de indicador de reinicio de software (instrucción)
1 = Se ha ejecutado una instrucción RESET
0 = No se ha ejecutado una instrucción RESET
poco 5
SWDTEN: software habilitado/deshabilitado del bit WDT (2)
1 = WDT está habilitado
0 = WDT está deshabilitado
poco 4
WDTO: Bit de bandera de tiempo de espera del temporizador de vigilancia
1 = Se ha producido el tiempo de espera de WDT
0 = No se ha producido el tiempo de espera de WDT
poco 3
DORMIR: Despertar del bit de bandera de suspensión
1 = El dispositivo ha estado en modo de suspensión
0 = El dispositivo no ha estado en modo de suspensión
poco 2
IDLE: Activación desde el bit de bandera inactiva
1 = El dispositivo estaba en modo inactivo
0 = El dispositivo no estaba en modo inactivo
poco 1
BOR: Bit de bandera de reinicio de apagón
1 = Se ha producido un reinicio por caída de tensión
0 = No se ha producido un reinicio por caída
poco 0
POR: Bit de indicador de reinicio de encendido
1 = Se ha producido un reinicio de encendido
0 = No se ha producido un reinicio de encendido
Nota 1: Todos los bits de estado de reinicio se pueden configurar o borrar en el software. Configurar uno de estos bits en el software no
provocar un reinicio del dispositivo.
2: Si el bit de configuración FWDTEN es '1' (no programado), el WDT siempre está habilitado, independientemente del
Configuración de bits SWDTEN.

© 2009 Microchip Technology Inc.
DS70286C-página 79
dsPIC33FJXXXGPX06/X08/X10
TABLA 6-1:
RESTABLECER OPERACIÓN DEL BITS DE BANDERA
6.1
Selección de fuente de reloj al reiniciar
Si el cambio de reloj está habilitado, la fuente del reloj del sistema en
Se elige Restablecer dispositivo, como se muestra en la Tabla 6-2. si reloj
La conmutación está deshabilitada, la fuente del reloj del sistema siempre está
seleccionado según los bits de configuración del oscilador.
Consulte la Sección 9.0 “Configuración del oscilador” para
más detalles.
TABLA 6-2:
SELECCIÓN DE OSCILADOR VS 
TIPO DE RESET (RELOJ 
CONMUTACIÓN HABILITADA)
6.2
Tiempos de reinicio del dispositivo
Los tiempos de reinicio para varios tipos de reinicio de dispositivos son
resumido en la Tabla 6-3. La señal de reinicio del sistema,
SYSRST, se libera después del retraso de POR y PWRT
los tiempos expiran.
El momento en el que el dispositivo realmente comienza a ejecutarse.
El código también depende de los retrasos del oscilador del sistema,
que incluyen el temporizador de inicio del oscilador (OST) y
el tiempo de bloqueo del PLL. Se producen los tiempos de bloqueo de OST y PLL.
en paralelo con los tiempos de retardo SYSRST aplicables.
El retraso de FSCM determina el momento en el que
FSCM comienza a monitorear la fuente del reloj del sistema después
se libera la señal SYSRST.
Bit de bandera
Evento de configuración
Evento de compensación
TRAMPA (RCON<15>)
Evento de conflicto trampa
POR, BOR
IOPUWR (RCON<14>)
Código de operación ilegal o no inicializado 
Acceso al registro W
POR, BOR
EXTR (RCON<7>)
Restablecer MCLR
POR
ROE (RCON<6>)
instrucción RESET
POR, BOR
WDTO (RCON<4>)
Tiempo de espera WDT
Instrucción PWRSAV, POR, BOR
DORMIR (RCON<3>)
Instrucción PWRSAV #SLEEP
POR, BOR
INACTIVO (RCON<2>)
Instrucción PWRSAV #IDLE
POR, BOR
BOR (RCON<1>)
BOR, POR
—
POR (RCON<0>)
POR
—
Nota:
El software del usuario puede configurar o borrar todos los bits del indicador de reinicio.
Tipo de reinicio
Determinante de la fuente del reloj
POR
Bits de configuración del oscilador
(FNOSC<2:0>)
BOR
MCLR
Puntas de control COSC 
(OSCCON<14:12>)
WDTR
ROE

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 80
© 2009 Microchip Technology Inc.
TABLA 6-3:
TIEMPOS DE RETARDO DE RESTABLECIMIENTO PARA VARIOS RESTABLECIMIENTOS DE DISPOSITIVOS
6.2.1
OSCILADOR POR Y LARGO 
TIEMPOS DE ARRANQUE
El circuito de arranque del oscilador y su retardo asociado.
Los temporizadores no están vinculados al dispositivo. Restablecer los retrasos que
ocurrir en el encendido. Algunos circuitos de cristal (especialmente
cristales de baja frecuencia) tienen un inicio relativamente largo
tiempo. Por lo tanto, una o más de las siguientes condiciones
es posible después de que se publique SYSRST:
• El circuito oscilador no ha comenzado a oscilar.
• El temporizador de inicio del oscilador no ha expirado (si 
Se utiliza un oscilador de cristal).
• El PLL no ha logrado un bloqueo (si se utiliza PLL).
El dispositivo no comenzará a ejecutar código hasta que se realice una verificación válida.
La fuente del reloj ha sido liberada al sistema.
Por lo tanto, los retrasos en el inicio del oscilador y del PLL deben
ser considerado cuando el tiempo de retardo de reinicio debe ser
conocido. 
6.2.2
MONITOR DEL RELOJ A PRUEBA DE FALLOS 
(FSCM) Y RESTABLECIMIENTOS DEL DISPOSITIVO
Si el FSCM está habilitado, comienza a monitorear el sistema.
fuente de reloj cuando se libera SYSRST. Si un reloj válido
fuente no está disponible en este momento, el dispositivo
cambia automáticamente al oscilador FRC y el
El usuario puede cambiar al oscilador de cristal deseado en el
Rutina de servicio de trampa.
6.2.2.1
Retraso FSCM para Crystal y PLL 
Fuentes de reloj
Cuando la fuente del reloj del sistema es proporcionada por un cristal
oscilador y/o el PLL, se activa automáticamente un pequeño retardo, TFSCM.
insertado automáticamente después del retardo POR y PWRT
veces. El FSCM no comienza a monitorear el sistema.
fuente de reloj hasta que expire este retraso. El retraso del FSCM
El tiempo es nominalmente de 500 μs y proporciona tiempo adicional.
para que el oscilador y/o PLL se estabilicen. En la mayoría de los casos,
El retardo de FSCM evita una trampa de falla del oscilador en un
El dispositivo se reinicia cuando el PWRT está desactivado.
6.3
Restablecimiento del registro de función especial 
Estados
La mayoría de los registros de funciones especiales (SFR) asociados
conectados con la CPU y los periféricos se restablecen a un
valor particular en un dispositivo Restablecer. Los SFR son
agrupados por su función de periférico o CPU y su
Los valores de reinicio se especifican en cada sección de este manual.
El valor de Reset para cada SFR no depende del
tipo de Reset, a excepción de dos registros. el
Valor de reinicio para el registro de control de reinicio, RCON,
Depende del tipo de dispositivo Restablecer. El valor de reinicio
para el registro de control del oscilador, OSCCON, depende
del tipo de Reset y de los valores programados del
Bits de configuración del oscilador en la configuración FOSC.
registrarse.
Tipo de reinicio
Fuente del reloj
Retraso SYSRST
Reloj del sistema
Retraso
FCM
Retraso
 Notas
POR
CE, FRC, LPRC
TPOR + TINICIO + TRST
—
—
1, 2, 3
ECPL, FRCPLL
TPOR + TINICIO + TRST
TLOCK
TFSCM
1, 2, 3, 5, 6
XT, SA, SOSC
TPOR + TINICIO + TRST
TOSTAR
TFSCM
1, 2, 3, 4, 6
XTPLL, HSPLL
TPOR + TINICIO + TRST
TOST + TLOCK
TFSCM
1, 2, 3, 4, 5, 6
BOR
CE, FRC, LPRC
TINICIO + PRUEBA
—
—
3
ECPL, FRCPLL
TINICIO + PRUEBA
TLOCK
TFSCM
3, 5, 6
XT, SA, SOSC
TINICIO + PRUEBA
TOSTAR
TFSCM
3, 4, 6
XTPLL, HSPLL
TINICIO + PRUEBA
TOST + TLOCK
TFSCM
3, 4, 5, 6
MCLR
Cualquier reloj
TRST
—
—
3
WDT
Cualquier reloj
TRST
—
—
3
programas
Cualquier reloj
TRST
—
—
3
Código de operación ilegal
Cualquier reloj
TRST
—
—
3
W no inicializado
Cualquier reloj
TRST
—
—
3
Conflicto trampa
Cualquier reloj
TRST
—
—
3
Nota 1:
TPOR = Retardo de reinicio de encendido (10 μs nominal).
2:
TSTARTUP = retardo POR condicional de 20 μs nominal (si el regulador en chip está habilitado) o 64 ms nominal 
Retardo del temporizador de encendido (si el regulador está deshabilitado). TSTARTUP también se aplica a todas las devoluciones desde apagado 
estados, incluido el despertar del modo de suspensión, solo si el regulador está habilitado. 
3:
TRST = Tiempo de reinicio del estado interno (20 μs nominal).
4:
TOST = Temporizador de inicio del oscilador. Un contador de 10 bits cuenta 1024 periodos de oscilador antes de soltar el 
reloj oscilador al sistema.
5:
TLOCK = tiempo de bloqueo de PLL (20 μs nominal).
6:
TFSCM = Retardo del monitor de reloj a prueba de fallos (100 μs nominales).

© 2009 Microchip Technology Inc.
DS70286C-página 81
dsPIC33FJXXXGPX06/X08/X10
7.0
CONTROLADOR DE INTERRUPCIONES
el 
dsPIC33FJXXXGPX06/X08/X10 
interrumpir
El controlador reduce las numerosas interrupciones periféricas.
señales de solicitud a una única señal de solicitud de interrupción a
la CPU dsPIC33FJXXXGPX06/X08/X10. tiene el
siguientes características:
• Hasta 8 excepciones de procesador y trampas de software
• 7 niveles de prioridad seleccionables por el usuario
• Tabla de vectores de interrupción (IVT) con hasta 118 vectores
• Un vector único para cada interrupción o excepción 
fuente
• Prioridad fija dentro de un nivel de prioridad de usuario específico
• Tabla de vectores de interrupción alternativa (AIVT) para depuración 
apoyo
• Se corrigieron las latencias de entrada y retorno de interrupciones.
7.1
Tabla de vectores de interrupción
La tabla de vectores de interrupción se muestra en la Figura 7-1. el
IVT reside en la memoria del programa, comenzando en la ubicación
000004h. El IVT contiene 126 vectores que constan de
8 vectores trampa no enmascarables más hasta 118 fuentes de
interrumpir. En general, cada fuente de interrupción tiene su propia
vector. Cada vector de interrupción contiene un ancho de 24 bits.
dirección. El valor programado en cada interrupción.
La ubicación del vector es la dirección inicial del asociado.
Rutina de servicio de interrupción (ISR).
Los vectores de interrupción se priorizan en términos de su naturaleza natural.
prioridad; Esta prioridad está ligada a su posición en el
tabla de vectores. En igualdad de condiciones, menor
las direcciones tienen una prioridad natural más alta. Por ejemplo,
la interrupción asociada al vector 0 tendrá prioridad
sobre interrupciones en cualquier otra dirección vectorial.
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 se implementan
hasta 67 interrupciones únicas y 5 trampas no enmascarables.
Estos se resumen en la Tabla 7-1 y la Tabla 7-2.
7.1.1
TABLA DE VECTORES ALTERNOS
La tabla de vectores de interrupción alternativa (AIVT) se encuentra
después de la IVT, como se muestra en la Figura 7-1. Acceso a la
AIVT es proporcionado por el bit de control ALTIVT
(INTCON2<15>). Si el bit ALTIVT está establecido, todas las interrupciones
y los procesos de excepción utilizan los vectores alternativos
en lugar de los vectores predeterminados. Los vectores alternativos son
organizados de la misma manera que los vectores predeterminados.
El AIVT apoya la depuración proporcionando un medio para
cambiar entre una aplicación y un soporte
ambiente sin requerir que los vectores de interrupción
ser reprogramado. Esta característica también permite cambiar
entre solicitudes de evaluación de diferentes
Algoritmos de software en tiempo de ejecución. Si el AIVT no es
necesario, el AIVT debe programarse con el
mismas direcciones utilizadas en el IVT.
7.2
Restablecer secuencia
Un reinicio del dispositivo no es una verdadera excepción porque el
El controlador de interrupciones no participa en el proceso de reinicio.
El dispositivo dsPIC33FJXXXGPX06/X08/X10 borra su
se registra en respuesta a un reinicio, lo que fuerza a la PC
a cero. El controlador de señal digital comienza entonces
ejecución del programa en la ubicación 0x000000. el usuario
programa una instrucción GOTO en la dirección de reinicio
que redirige la ejecución del programa al lugar apropiado
rutina de arranque.
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 6.
“Interrupciones” (DS70184) en el “dsPIC33F
Manual de referencia familiar”, que está disponible
capaz 
de 
el 
Microchip 
web 
sitio
(www.microchip.com).
Nota:
Cualquier vector no implementado o no utilizado
Las ubicaciones en el IVT y AIVT deben ser
programado con la dirección de un defecto
Rutina de manejo de interrupciones que contiene una
Instrucción RESET.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 82
© 2009 Microchip Technology Inc.
FIGURA 7-1:
dsPIC33FJXXXGPX06/X08/X10 TABLA DE VECTORES DE INTERRUPCIÓN
Restablecer – Instrucción GOTO
0x000000
Restablecer – IR A Dirección
0x000002
Reservado
0x000004
Vector de trampa de falla del oscilador
Vector de trampa de error de dirección
Vector de trampa de error de pila
Vector de trampa de error matemático
Vector de trampa de error DMA
Reservado
Reservado
Vector de interrupción 0
0x000014
Vector de interrupción 1
~
~
~
Vector de interrupción 52
0x00007C
Vector de interrupción 53
0x00007E
Vector de interrupción 54
0x000080
~
~
~
Vector de interrupción 116
0x0000FC
Vector de interrupción 117
0x0000FE
Reservado
0x000100
Reservado
0x000102
Reservado
Vector de trampa de falla del oscilador
Vector de trampa de error de dirección
Vector de trampa de error de pila
Vector de trampa de error matemático
Vector de trampa de error DMA
Reservado
Reservado
Vector de interrupción 0
0x000114
Vector de interrupción 1
~
~
~
Vector de interrupción 52
0x00017C
Vector de interrupción 53
0x00017E
Vector de interrupción 54
0x000180
~
~
~
Vector de interrupción 116
Vector de interrupción 117
0x0001FE
Inicio del código
0x000200
Prioridad decreciente del orden natural
Tabla de vectores de interrupción (IVT)(1) 
Tabla de vectores de interrupción alternativa (AIVT) (1) 
Nota 1:
Consulte la Tabla 7-1 para obtener la lista de vectores de interrupción implementados.

© 2009 Microchip Technology Inc.
DS70286C-página 83
dsPIC33FJXXXGPX06/X08/X10
TABLA 7-1:
VECTORES DE INTERRUPCIÓN
Vector 
Número
interrumpir 
Solicitud (IRQ) 
Número
Dirección IVT
Dirección AIVT
Fuente de interrupción
8
0
0x000014
0x000114
INT0 – Interrupción externa 0
9
1
0x000016
0x000116
IC1 – Comparación de entrada 1
10
2
0x000018
0x000118
OC1 – Comparación de salida 1
11
3
0x00001A
0x00011A
T1 – Temporizador1
12
4
0x00001C
0x00011C
DMA0 – DMA Canal 0
13
5
0x00001E
0x00011E
IC2 – Captura de entrada 2
14
6
0x000020
0x000120
OC2 – Comparación de salida 2
15
7
0x000022
0x000122
T2 – Temporizador2
16
8
0x000024
0x000124
T3 – Temporizador3
17
9
0x000026
0x000126
SPI1E – Error SPI1 
18
10
0x000028
0x000128
SPI1 – Transferencia SPI1 realizada
19
11
0x00002A
0x00012A
U1RX – Receptor UART1
20
12
0x00002C
0x00012C
U1TX – Transmisor UART1
21
13
0x00002E
0x00012E
CAD1 – CAD1
22
14
0x000030
0x000130
DMA1 – DMA Canal 1
23
15
0x000032
0x000132
Reservado
24
16
0x000034
0x000134
SI2C1 – Eventos esclavos I2C1
25
17
0x000036
0x000136
MI2C1 – Eventos Maestros I2C1
26
18
0x000038
0x000138
Reservado
27
19
0x00003A
0x00013A
Interrupción de notificación de cambio
28
20
0x00003C
0x00013C
INT1 – Interrupción externa 1
29
21
0x00003E
0x00013E
CAD2 – CAD2
30 
22
 0x000040
 0x000140
IC7 – Captura de entrada 7
31 
23
0x000042
0x000142
IC8 – Captura de entrada 8
32
24
0x000044
0x000144
DMA2 – DMA Canal 2
33
25
0x000046
0x000146
OC3 – Comparación de salida 3
34
26
0x000048
0x000148
OC4 – Comparación de salida 4
35
27
0x00004A
0x00014A
T4 – Temporizador4
36
28
0x00004C
0x00014C
T5 – Temporizador5
37
29
0x00004E
0x00014E
INT2 – Interrupción externa 2
38
30
0x000050
0x000150
U2RX – Receptor UART2
39
31
0x000052
0x000152
U2TX – Transmisor UART2
40
32
0x000054
0x000154
SPI2E – Error SPI2
41
33
0x000056
0x000156
SPI1 – Transferencia SPI1 realizada
42
34
0x000058
0x000158
C1RX – ECAN1 Recibir datos listos 
43
35
0x00005A
0x00015A
C1 – Evento ECAN1
44
36
0x00005C
0x00015C
DMA3 – DMA Canal 3
45
37
0x00005E
0x00015E
IC3 – Captura de entrada 3
46
38
0x000060
0x000160
IC4 – Captura de entrada 4
47
39
0x000062
0x000162
IC5 – Captura de entrada 5
48
40
0x000064
0x000164
IC6 – Captura de entrada 6
49
41
0x000066
0x000166
OC5 – Comparación de salida 5
50
42
0x000068
0x000168
OC6 – Comparación de salida 6
51
43
0x00006A
0x00016A
OC7 – Comparación de salida 7
52
44
0x00006C
0x00016C
OC8 – Comparación de salida 8
53
45
0x00006E
0x00016E
Reservado

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 84
© 2009 Microchip Technology Inc.
TABLA 7-2:
VECTORES DE TRAMPA
54
46
0x000070
0x000170
DMA4 – DMA Canal 4
55
47
0x000072
0x000172
T6 – Temporizador6
56
48
0x000074
0x000174
T7 – Temporizador7
57
49
0x000076
0x000176
SI2C2 – Eventos esclavos I2C2
58
50
0x000078
0x000178
MI2C2 – Eventos Maestros I2C2
59
51
0x00007A
0x00017A
T8 – Temporizador8
60
52
0x00007C
0x00017C
T9 – Temporizador9
61
53
0x00007E
0x00017E
INT3 – Interrupción externa 3
62
54
0x000080
0x000180
INT4 – Interrupción externa 4
63
55
0x000082
0x000182
C2RX – ECAN2 Recibir datos listos 
64
56
0x000084
0x000184
C2 – Evento ECAN2
65
57
0x000086
0x000186
Reservado
66
58
0x000088
0x000188
Reservado
67
59
0x00008A
0x00018A
DCIE-Error DCI
68
60
0x00008C
0x00018C
DCID – Transferencia DCI realizada
69
61
0x00008E
0x00018E
DMA5 – DMA Canal 5
70
62
0x000090
0x000190
Reservado
71
63
0x000092
0x000192
Reservado
72
64
0x000094
0x000194
Reservado
73
65
0x000096
0x000196
U1E – Error UART1
74
66
0x000098
0x000198
U2E – Error UART2
75
67
0x00009A
0x00019A
Reservado
76
68
0x00009C
0x00019C
DMA6 – DMA Canal 6
77
69
0x00009E
0x00019E
DMA7 – DMA Canal 7
78
70
0x0000A0
0x0001A0
C1TX – Solicitud de transmisión de datos ECAN1
79
71
0x0000A2
0x0001A2
C2TX – Solicitud de transmisión de datos ECAN2
80-125
72-117
0x0000A4-0x0000
FE
0x0001A4-0x0001
FE
Reservado
Número vectorial
Dirección IVT
Dirección AIVT
Fuente de trampa
0
 0x000004
0x000104
Reservado
1
0x000006
0x000106
Fallo del oscilador
2
0x000008
0x000108
Error de dirección
3
0x00000A
0x00010A
Error de pila
4
0x00000C
0x00010C
Error matemático
5
0x00000E
0x00010E
Trampa de errores de DMA
6
0x000010
0x000110
Reservado
7
0x000012
0x000112
Reservado
TABLA 7-1:
VECTORES DE INTERRUPCIÓN (CONTINUACIÓN)
Vector 
Número
interrumpir 
Solicitud (IRQ) 
Número
Dirección IVT
Dirección AIVT
Fuente de interrupción

© 2009 Microchip Technology Inc.
DS70286C-página 85
dsPIC33FJXXXGPX06/X08/X10
7.3
Control y estado de interrupción 
Registros
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 implementan un
Total de 30 registros para el controlador de interrupciones: 
• INTCON1 
• INTCON2 
• IFS0 a IFS4
• IEC0 a IEC4
• IPC0 a IPC17 
• INTTREG
Las funciones de control de interrupción global se controlan desde
INTCON1 e INTCON2. INTCON1 contiene el
Bit de desactivación de anidamiento de interrupción (NSTDIS), así como el bit
indicadores de control y estado para las fuentes de captura del procesador.
El registro INTCON2 controla la interrupción externa.
solicitar el comportamiento de la señal y el uso de la alternativa
Tabla de vectores de interrupción.
Los registros IFS mantienen todas las solicitudes de interrupción.
banderas. Cada fuente de interrupción tiene un bit de estado, que es
establecidos por los respectivos periféricos o señal externa y
se borra mediante software.
Los registros IEC mantienen toda la habilitación de interrupciones.
bits. Estos bits de control se utilizan para habilitar individualmente
interrupciones de los periféricos o señales externas.
Los registros IPC se utilizan para establecer la prioridad de interrupción.
nivel para cada fuente de interrupción. Cada usuario interrumpe
La fuente se puede asignar a uno de los ocho niveles de prioridad. 
El registro INTTREG contiene los datos asociados.
número de vector de interrupción y la nueva interrupción de CPU
nivel de prioridad, que están bloqueados en el número de vector
(VECNUM<6:0>) y bit de nivel de interrupción (ILR<3:0>)
campos en el registro INTTREG. La nueva interrupción
El nivel de prioridad es la prioridad de la interrupción pendiente. 
Las fuentes de interrupción están asignadas a IFSx, IECx
y los registros IPCx en la misma secuencia en la que están
enumerados en la Tabla 7-1. Por ejemplo, el INT0 (externo
La interrupción 0) se muestra con el vector número 8 y un
prioridad de orden natural de 0. Por lo tanto, el bit INT0IF se encuentra
en IFS0<0>, el bit INT0IE en IEC0<0> y el INT0IP
bits en la primera posición de IPC0 (IPC0<2:0>). 
Aunque no son específicamente parte de la interrupción
hardware de control, dos de los registros de control de la CPU
contienen bits que controlan la funcionalidad de interrupción. La CPU
El registro STATUS, SR, contiene los bits IPL<2:0>
(SR<7:5>). Estos bits indican la CPU actual.
nivel de prioridad de interrupción. El usuario puede cambiar el actual.
Nivel de prioridad de la CPU escribiendo en los bits de IPL. 
El registro CORCON contiene el bit IPL3 que,
junto con IPL<2:0>, también indica la CPU actual
nivel de prioridad. IPL3 es un bit de sólo lectura para que los eventos de captura
no puede ser enmascarado por el software del usuario.
Todos los registros de interrupción se describen en el Registro 7-1.
a través del Registro 7-32, en las siguientes páginas.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 86
© 2009 Microchip Technology Inc.
   
  
REGÍSTRESE 7-1:
SR: REGISTRO DE ESTADO DE CPU(1)
R-0
R-0
R/C-0
R/C-0
R-0
R/C-0
-0
R/W-0
OA
OB
SA
SB
VH
SAB
DA
CC
poco 15
poco 8
R/W-0(3)
R/W-0(3)
R/W-0(3)
R-0
R/W-0
R/W-0
R/W-0
R/W-0
IPL2(2)
IPL1(2)
IPL0(2)
RA
norte
VO
z
c
poco 7
poco 0
Leyenda:
C = Borrar solo bit
R = bit legible
U = Bit no implementado, leído como '0'
S = Establecer solo bit
W = bit grabable
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 7-5
IPL<2:0>: Bits de estado de nivel de prioridad de interrupción de CPU(2)
111 = El nivel de prioridad de interrupción de la CPU es 7 (15), las interrupciones del usuario están deshabilitadas
110 = El nivel de prioridad de interrupción de la CPU es 6 (14)
101 = El nivel de prioridad de interrupción de la CPU es 5 (13)
100 = El nivel de prioridad de interrupción de la CPU es 4 (12)
011 = El nivel de prioridad de interrupción de la CPU es 3 (11)
010 = El nivel de prioridad de interrupción de la CPU es 2 (10)
001 = El nivel de prioridad de interrupción de la CPU es 1 (9)
000 = El nivel de prioridad de interrupción de la CPU es 0 (8)
Nota 1: Para obtener detalles completos del registro, consulte Registro 3-1: “SR: REGISTRO DE ESTADO DE CPU”.
2: Los bits IPL<2:0> se concatenan con el bit IPL<3> (CORCON<3>) para formar la prioridad de interrupción de la CPU.
Nivel. El valor entre paréntesis indica la IPL si IPL<3> = 1. Las interrupciones del usuario se desactivan cuando
IPL<3> = 1.
3: Los bits de estado de IPL<2:0> son de solo lectura cuando NSTDIS (INTCON1<15>) = 1.
REGISTRO 7-2:
CORCON: REGISTRO DE CONTROL PRINCIPAL(1)
U-0
U-0
U-0
R/W-0
R/W-0
R-0
R-0
R-0
—
—
—
Estados Unidos
hora del Este
DL<2:0>
poco 15
poco 8
R/W-0
R/W-0
R/W-1
R/W-0
R/C-0
R/W-0
R/W-0
R/W-0
sata
SATB
SATDW
ACCESAT
IPL3(2)
PSV
RND
SI
poco 7
poco 0
Leyenda:
C = Borrar solo bit
R = bit legible
W = bit grabable
-n = Valor en POR
'1' = El bit está configurado
0’ = El bit se borra
'x = El bit es desconocido
U = Bit no implementado, leído como '0'
poco 3
IPL3: Bit de estado 3(2) del nivel de prioridad de interrupción de la CPU
1 = el nivel de prioridad de interrupción de la CPU es mayor que 7
0 = el nivel de prioridad de interrupción de la CPU es 7 o menos
Nota 1: Para obtener detalles completos del registro, consulte el Registro 3-2: “CORCON: REGISTRO DE CONTROL DEL NÚCLEO”.
2: El bit IPL3 se concatena con los bits IPL<2:0> (SR<7:5>) para formar el nivel de prioridad de interrupción de la CPU.

© 2009 Microchip Technology Inc.
DS70286C-página 87
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 7-3:
INTCON1: REGISTRO DE CONTROL DE INTERRUPCIONES 1
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
NSTDIS
OVAERR
OVBERR
COVAERR
COVBERR
OVADO
OVBTE
COVTE
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
U-0
SFTACERR
DIV0ERR
DMACERR
MATHERR
DIRECCIÓN
STKERR
OSCFAIL
—
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
NSTDIS: Bit de desactivación de anidamiento de interrupción
1 = Interrumpir el anidamiento está deshabilitado
0 = Interrumpir el anidamiento está habilitado
poco 14
OVAERR: Bit de bandera de trampa de desbordamiento del acumulador A
1 = La trampa fue causada por el desbordamiento del Acumulador A
0 = La trampa no fue causada por el desbordamiento del Acumulador A
poco 13
OVBERR: Bit de bandera de trampa de desbordamiento del acumulador B
1 = La trampa fue causada por el desbordamiento del Acumulador B
0 = La trampa no fue causada por el desbordamiento del Acumulador B
poco 12
COVAERR: Bit de bandera de trampa de desbordamiento catastrófico del acumulador A
1 = La trampa fue causada por un desbordamiento catastrófico del Acumulador A 
0 = La trampa no fue causada por un desbordamiento catastrófico del Acumulador A
poco 11
COVBERR: Bit de bandera de trampa de desbordamiento catastrófico del acumulador B
1 = La trampa fue causada por un desbordamiento catastrófico del Acumulador B 
0 = La trampa no fue causada por un desbordamiento catastrófico del Acumulador B
poco 10
OVATE: Bit de habilitación de trampa de desbordamiento del acumulador A
1 = Desbordamiento de trampa del Acumulador A
0 = Trampa deshabilitada
poco 9
OVBTE: Bit de habilitación de trampa de desbordamiento del acumulador B
1 = Desbordamiento de trampa del Acumulador B
0 = Trampa deshabilitada
poco 8
COVTE: Bit de habilitación de trampa de desbordamiento catastrófico
1 = Trampa por desbordamiento catastrófico del Acumulador A o B habilitada
0 = Trampa deshabilitada
poco 7
SFTACERR: Bit de estado de error del acumulador de cambios
1 = La trampa de error matemático fue causada por un cambio de acumulador no válido
0 = La trampa de error matemático no fue causada por un cambio de acumulador no válido
poco 6
DIV0ERR: Bit de estado de error aritmético
1 = La trampa del error matemático fue causada por una división por cero
0 = La trampa de error matemático no fue causada por una división entre cero
poco 5
DMACERR: Bit de estado de error del controlador DMA
1 = Se ha producido una trampa de error del controlador DMA
0 = No se ha producido la captura de error del controlador DMA
poco 4
MATHERR: Bit de estado de error aritmético
1 = Se ha producido una trampa de error matemático
0 = No se ha producido la trampa de error matemático

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 88
© 2009 Microchip Technology Inc.
poco 3
ADDRERR: Bit de estado de captura de error de dirección
1 = Se ha producido una trampa de error de dirección
0 = No se ha producido la captura de error de dirección
poco 2
STKERR: Bit de estado de captura de error de pila
1 = Se ha producido una trampa de error de pila
0 = No se ha producido la captura de error de pila
poco 1
OSCFAIL: bit de estado de captura de falla del oscilador
1 = Se ha producido una trampa de falla del oscilador
0 = No se ha producido la trampa de falla del oscilador
poco 0
No implementado: leído como "0"
REGISTRO 7-3:
INTCON1: REGISTRO DE CONTROL DE INTERRUPCIONES 1 (CONTINUACIÓN)

© 2009 Microchip Technology Inc.
DS70286C-página 89
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRAR 7-4:
INTCON2: REGISTRO DE CONTROL DE INTERRUPCIONES 2
R/W-0
R-0
U-0
U-0
U-0
U-0
U-0
U-0
ALTIVT
DISI
—
—
—
—
—
—
poco 15
poco 8
U-0
U-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
—
—
—
INT4EP
INT3EP
INT2EP
INT1EP
INT0EP
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
ALTIVT: Habilitar bit de tabla de vectores de interrupción alternativa
1 = Usar tabla de vectores alternativa
0 = Usar tabla de vectores estándar (predeterminada)
poco 14
DISI: bit de estado de instrucción DISI
1 = la instrucción DISI está activa
0 = la instrucción DISI no está activa
bit 13-5
No implementado: leído como "0"
poco 4
INT4EP: Bit de selección de polaridad de detección de flanco de interrupción externa 4
1 = Interrupción en flanco negativo 
0 = Interrupción en flanco positivo
poco 3
INT3EP: Bit de selección de polaridad de detección de flanco de interrupción externa 3
1 = Interrupción en flanco negativo 
0 = Interrupción en flanco positivo
poco 2
INT2EP: Bit de selección de polaridad de detección de borde de interrupción externa 2
1 = Interrupción en flanco negativo 
0 = Interrupción en flanco positivo
poco 1
INT1EP: Bit de selección de polaridad de detección de flanco de interrupción externa 1
1 = Interrupción en flanco negativo 
0 = Interrupción en flanco positivo
poco 0
INT0EP: Interrupción externa 0 Bit de selección de polaridad de detección de flanco
1 = Interrupción en flanco negativo 
0 = Interrupción en flanco positivo

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 90
© 2009 Microchip Technology Inc.
     
REGÍSTRESE 7-5:
IFS0: REGISTRO DE ESTADO DE INDICADOR DE INTERRUPCIÓN 0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
—
DMA1IF
AD1IF
U1TXIF
U1RXIF
SPI1IF
SPI1EIF
T3IF
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
T2IF
OC2IF
IC2IF
DMA01IF
T1IF
OC1IF
IC1IF
INT0IF
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
poco 14
DMA1IF: Transferencia de datos del canal 1 de DMA completa Bit de estado del indicador de interrupción
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 13
AD1IF: Conversión ADC1 completa Bit de estado del indicador de interrupción
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 12
U1TXIF: Bit de estado del indicador de interrupción del transmisor UART1
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 11
U1RXIF: Bit de estado del indicador de interrupción del receptor UART1
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 10
SPI1IF: Bit de estado del indicador de interrupción de evento SPI1
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 9
SPI1EIF: Bit de estado del indicador de interrupción de falla SPI1
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 8
T3IF: Bit de estado del indicador de interrupción del temporizador 3
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 7
T2IF: Bit de estado del indicador de interrupción del temporizador 2
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 6
OC2IF: Bit de estado del indicador de interrupción del canal 2 de comparación de salida
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 5
IC2IF: Bit de estado del indicador de interrupción del canal 2 de captura de entrada
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 4
DMA01IF: Transferencia de datos del canal 0 de DMA completa Bit de estado del indicador de interrupción
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 3
T1IF: Bit de estado del indicador de interrupción del temporizador 1
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido

© 2009 Microchip Technology Inc.
DS70286C-página 91
dsPIC33FJXXXGPX06/X08/X10
poco 2
OC1IF: Bit de estado del indicador de interrupción del canal 1 de comparación de salida
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 1
IC1IF: Bit de estado del indicador de interrupción del canal 1 de captura de entrada
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 0
INT0IF: Bit de estado de indicador de interrupción externa 0
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
REGÍSTRESE 7-5:
IFS0: REGISTRO DE ESTADO DE INDICADOR DE INTERRUPCIÓN 0 (CONTINUACIÓN)

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 92
© 2009 Microchip Technology Inc.
     
REGISTRAR 7-6:
IFS1: REGISTRO DE ESTADO DE INDICADOR DE INTERRUPCIÓN 1
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
U2TXIF
U2RXIF
INT2IF
T5IF
T4IF
OC4IF
OC3IF
DMA21IF
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
U-0
R/W-0
R/W-0
IC8IF
IC7IF
AD2IF
INT1IF
CNIF
—
MI2C1IF
SI2C1IF
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
U2TXIF: Bit de estado del indicador de interrupción del transmisor UART2
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 14
U2RXIF: Bit de estado del indicador de interrupción del receptor UART2
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 13
INT2IF: Bit de estado de indicador de interrupción externa 2
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 12
T5IF: Bit de estado del indicador de interrupción del temporizador 5
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 11
T4IF: Bit de estado del indicador de interrupción del temporizador 4
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 10
OC4IF: Bit de estado del indicador de interrupción del canal 4 de comparación de salida
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 9
OC3IF: Bit de estado del indicador de interrupción del canal 3 de comparación de salida
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 8
DMA21IF: Transferencia de datos del canal 2 de DMA completa Bit de estado del indicador de interrupción
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 7
IC8IF: Bit de estado del indicador de interrupción del canal 8 de captura de entrada
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 6
IC7IF: Bit de estado del indicador de interrupción del canal 7 de captura de entrada
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 5
AD2IF: Bit de estado del indicador de interrupción completa de conversión ADC2
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 4
INT1IF: Bit de estado de indicador de interrupción externa 1
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido

© 2009 Microchip Technology Inc.
DS70286C-página 93
dsPIC33FJXXXGPX06/X08/X10
poco 3
CNIF: bit de estado de indicador de interrupción de notificación de cambio de entrada
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 2
No implementado: leído como "0"
poco 1
MI2C1IF: Bit de estado del indicador de interrupción de eventos maestros I2C1
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 0
SI2C1IF: Bit de estado del indicador de interrupción de eventos del esclavo I2C1
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
REGISTRAR 7-6:
IFS1: REGISTRO 1 DE ESTADO DE INDICADOR DE INTERRUPCIÓN (CONTINUACIÓN)

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 94
© 2009 Microchip Technology Inc.
  
REGÍSTRESE 7-7:
IFS2: REGISTRO DE ESTADO DE INDICADOR DE INTERRUPCIÓN 2
R/W-0
R/W-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
T6IF
DMA4IF
—
OC8IF
OC7IF
OC6IF
OC5IF
IC6IF
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
IC5IF
IC4IF
IC3IF
DMA3IF
C1IF
C1RXIF
SPI2IF
SPI2EIF
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
T6IF: Bit de estado del indicador de interrupción del temporizador 6
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 14
DMA4IF: Transferencia de datos del canal 4 de DMA completa Bit de estado del indicador de interrupción
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 13
No implementado: leído como "0"
poco 12
OC8IF: Bit de estado del indicador de interrupción del canal 8 de comparación de salida
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 11
OC7IF: Bit de estado del indicador de interrupción del canal 7 de comparación de salida
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 10
OC6IF: Bit de estado del indicador de interrupción del canal 6 de comparación de salida
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 9
OC5IF: Bit de estado del indicador de interrupción del canal 5 de comparación de salida
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 8
IC6IF: Bit de estado del indicador de interrupción del canal 6 de captura de entrada
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 7
IC5IF: Bit de estado del indicador de interrupción del canal 5 de captura de entrada
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 6
IC4IF: Bit de estado del indicador de interrupción del canal 4 de captura de entrada
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 5
IC3IF: Bit de estado del indicador de interrupción del canal 3 de captura de entrada
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 4
DMA3IF: Transferencia de datos del canal 3 de DMA completa Bit de estado del indicador de interrupción
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 3
C1IF: Bit de estado del indicador de interrupción de evento ECAN1
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido

© 2009 Microchip Technology Inc.
DS70286C-página 95
dsPIC33FJXXXGPX06/X08/X10
poco 2
C1RXIF: ECAN1 Recibir datos listos Bit de estado del indicador de interrupción
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 1
SPI2IF: Bit de estado del indicador de interrupción de evento SPI2
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 0
SPI2EIF: Bit de estado del indicador de interrupción de error SPI2
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
REGÍSTRESE 7-7:
IFS2: REGISTRO DE ESTADO DE INDICADOR DE INTERRUPCIÓN 2 (CONTINUACIÓN)

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 96
© 2009 Microchip Technology Inc.
     
REGISTRO 7-8:
IFS3: REGISTRO DE ESTADO DE INDICADOR DE INTERRUPCIÓN 3
U-0
U-0
R/W-0
R/W-0
R/W-0
U-0
U-0
R/W-0
—
—
DMA5IF
DCIIF
DCIEIF
—
—
C2IF
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
C2RXIF
INT4IF
INT3IF
T9IF
T8IF
MI2C2IF
SI2C2IF
T7IF
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-14
No implementado: leído como "0"
poco 13
DMA5IF: Transferencia de datos del canal 5 de DMA completa Bit de estado del indicador de interrupción
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 12
DCIIF: Bit de estado del indicador de interrupción de evento DCI
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 11
DCIEIF: Bit de estado del indicador de interrupción de error DCI
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
bits 10-9
No implementado: leído como "0"
poco 8
C2IF: Bit de estado del indicador de interrupción de evento ECAN2
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 7
C2RXIF: ECAN2 Recibir datos listos Bit de estado del indicador de interrupción
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 6
INT4IF: Bit de estado de indicador de interrupción externa 4
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 5
INT3IF: Bit de estado de indicador de interrupción externa 3
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 4
T9IF: Bit de estado del indicador de interrupción del temporizador 9
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 3
T8IF: Bit de estado del indicador de interrupción del temporizador 8
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 2
MI2C2IF: Bit de estado del indicador de interrupción de eventos maestros I2C2
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 1
SI2C2IF: Bit de estado del indicador de interrupción de eventos del esclavo I2C2
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 0
T7IF: Bit de estado del indicador de interrupción del temporizador 7
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido

© 2009 Microchip Technology Inc.
DS70286C-página 97
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 7-9:
IFS4: REGISTRO DE ESTADO DE INDICADOR DE INTERRUPCIÓN 4
U-0
U-0
U-0
U-0
U-0
U-0
U-0
U-0
—
—
—
—
—
—
—
—
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
U-0
R/W-0
R/W-0
U-0
C2TXIF
C1TXIF
DMA7IF
DMA6IF
—
U2EIF
U1EIF
—
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bit 15-8
No implementado: leído como "0"
poco 7
C2TXIF: Bit de estado del indicador de interrupción de solicitud de datos de transmisión ECAN2
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 6
C1TXIF: Bit de estado del indicador de interrupción de solicitud de datos de transmisión ECAN1
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 5
DMA7IF: Transferencia de datos del canal 7 de DMA completa Bit de estado del indicador de interrupción
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 4
DMA6IF: Transferencia de datos del canal 6 de DMA completa Bit de estado del indicador de interrupción
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 3
No implementado: leído como "0"
poco 2
U2EIF: Bit de estado del indicador de interrupción de error UART2
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 1
U1EIF: Bit de estado del indicador de interrupción de error UART1
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 0
No implementado: leído como "0"

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 98
© 2009 Microchip Technology Inc.
     
REGISTRO 7-10:
IEC0: REGISTRO DE CONTROL DE HABILITACIÓN DE INTERRUPCIÓN 0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
—
DMA1IE
AD1IE
U1TXIE
U1RXIE
SPI1IE
SPI1EIE
T3IE
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
T2IE
OC2IE
IC2IE
DMA0IE
T1IE
OC1IE
IC1IE
INT0IE
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
poco 14
DMA1IE: Bit de habilitación de interrupción completa de transferencia de datos del canal 1 de DMA
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 13
AD1IE: Bit de habilitación de interrupción completa de conversión ADC1
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 12
U1TXIE: Bit de habilitación de interrupción del transmisor UART1
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 11
U1RXIE: Bit de habilitación de interrupción del receptor UART1
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 10
SPI1IE: Bit de habilitación de interrupción de evento SPI1
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 9
SPI1EIE: Bit de habilitación de interrupción de error SPI1
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 8
T3IE: Bit de habilitación de interrupción del temporizador 3
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 7
T2IE: Bit de habilitación de interrupción del temporizador 2
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 6
OC2IE: Bit de habilitación de interrupción del canal 2 de comparación de salida
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 5
IC2IE: Bit de habilitación de interrupción del canal 2 de captura de entrada
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 4
DMA0IE: Bit de habilitación de interrupción completa de transferencia de datos del canal 0 de DMA
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 3
T1IE: Bit de habilitación de interrupción del temporizador 1
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada

© 2009 Microchip Technology Inc.
DS70286C-página 99
dsPIC33FJXXXGPX06/X08/X10
poco 2
OC1IE: Bit de habilitación de interrupción del canal 1 de comparación de salida
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 1
IC1IE: Bit de habilitación de interrupción del canal 1 de captura de entrada
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 0
INT0IE: Interrupción externa 0 bit de habilitación
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
REGISTRO 7-10:
IEC0: REGISTRO DE CONTROL DE HABILITACIÓN DE INTERRUPCIÓN 0 (CONTINUACIÓN)

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 100
© 2009 Microchip Technology Inc.
     
REGISTRO 7-11:
IEC1: REGISTRO DE CONTROL DE HABILITACIÓN DE INTERRUPCIÓN 1
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
U2TXIE
U2RXIE
INT2IE
T5IE
T4IE
OC4IE
OC3IE
DMA2IE
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
U-0
R/W-0
R/W-0
IC8IE
IC7IE
AD2IE
INT1IE
CNIE
—
MI2C1IE
SI2C1IE
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
U2TXIE: Bit de habilitación de interrupción del transmisor UART2
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 14
U2RXIE: Bit de habilitación de interrupción del receptor UART2
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 13
INT2IE: Bit de habilitación de interrupción externa 2
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 12
T5IE: Bit de habilitación de interrupción del temporizador 5
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 11
T4IE: Bit de habilitación de interrupción del temporizador 4
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 10
OC4IE: Bit de habilitación de interrupción del canal 4 de comparación de salida
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 9
OC3IE: Bit de habilitación de interrupción del canal 3 de comparación de salida
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 8
DMA2IE: Bit de habilitación de interrupción completa de transferencia de datos del canal 2 de DMA
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 7
IC8IE: Bit de habilitación de interrupción del canal 8 de captura de entrada
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 6
IC7IE: Bit de habilitación de interrupción del canal 7 de captura de entrada
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 5
AD2IE: Bit de habilitación de interrupción completa de conversión ADC2
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 4
INT1IE: Interrupción externa 1 bit de habilitación
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada

© 2009 Microchip Technology Inc.
DS70286C-página 101
dsPIC33FJXXXGPX06/X08/X10
poco 3
CNIE: Bit de habilitación de interrupción de notificación de cambio de entrada
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 2
No implementado: leído como "0"
poco 1
MI2C1IE: Bit de habilitación de interrupción de eventos maestros I2C1
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 0
SI2C1IE: Bit de habilitación de interrupción de eventos esclavos I2C1
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
REGISTRO 7-11:
IEC1: REGISTRO DE CONTROL DE HABILITACIÓN DE INTERRUPCIÓN 1 (CONTINUACIÓN)

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 102
© 2009 Microchip Technology Inc.
     
REGISTRO 7-12:
IEC2: REGISTRO DE CONTROL DE HABILITACIÓN DE INTERRUPCIÓN 2
R/W-0
R/W-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
T6IE
DMA4IE
—
OC8IE
OC7IE
OC6IE
OC5IE
IC6IE
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
IC5IE
IC4IE
IC3IE
DMA3IE
C1IE
C1RXIE
SPI2IE
SPI2EIE
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
T6IE: Bit de habilitación de interrupción del temporizador 6
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 14
DMA4IE: Bit de habilitación de interrupción completa de transferencia de datos del canal 4 de DMA
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 13
No implementado: leído como "0" 
poco 12
OC8IE: Bit de habilitación de interrupción del canal 8 de comparación de salida
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 11
OC7IE: Bit de habilitación de interrupción del canal 7 de comparación de salida
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 10
OC6IE: Bit de habilitación de interrupción del canal 6 de comparación de salida
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 9
OC5IE: Bit de habilitación de interrupción del canal 5 de comparación de salida
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 8
IC6IE: Bit de habilitación de interrupción del canal 6 de captura de entrada
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 7
IC5IE: Bit de habilitación de interrupción del canal 5 de captura de entrada
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 6
IC4IE: Bit de habilitación de interrupción del canal 4 de captura de entrada
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 5
IC3IE: Bit de habilitación de interrupción del canal 3 de captura de entrada
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 4
DMA3IE: Bit de habilitación de interrupción completa de transferencia de datos del canal 3 de DMA
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 3
C1IE: Bit de habilitación de interrupción de evento ECAN1
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada

© 2009 Microchip Technology Inc.
DS70286C-página 103
dsPIC33FJXXXGPX06/X08/X10
poco 2
C1RXIE: ECAN1 Recibir datos listo Interrumpir bit de habilitación
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 1
SPI2IE: Bit de habilitación de interrupción de evento SPI2
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 0
SPI2EIE: Bit de habilitación de interrupción de error SPI2
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
REGISTRO 7-12:
IEC2: REGISTRO DE CONTROL DE HABILITACIÓN DE INTERRUPCIÓN 2 (CONTINUACIÓN)

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 104
© 2009 Microchip Technology Inc.
     
REGISTRO 7-13:
IEC3: REGISTRO DE CONTROL DE HABILITACIÓN DE INTERRUPCIÓN 3
U-0
U-0
R/W-0
R/W-0
R/W-0
U-0
U-0
R/W-0
—
—
DMA5IE
DCIIE
DCIEIE
—
—
C2IE
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
C2RXIE
INT4IE
INT3IE
T9IE
T8IE
MI2C2IE
SI2C2IE
T7IE
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-14
No implementado: leído como "0"
poco 13
DMA5IE: Bit de habilitación de interrupción completa de transferencia de datos del canal 5 de DMA
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 12
DCIIE: Bit de habilitación de interrupción de evento DCI
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 11
DCIEIE: Bit de habilitación de interrupción de error DCI
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
bits 10-9
No implementado: leído como "0"
poco 8
C2IE: Bit de habilitación de interrupción de evento ECAN2
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 7
C2RXIE: ECAN2 Recibir datos listo Interrumpir bit de habilitación
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 6
INT4IE: Interrupción externa 4 bit de habilitación
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 5
INT3IE: Interrupción externa 3 bit de habilitación
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 4
T9IE: Bit de habilitación de interrupción del temporizador 9
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 3
T8IE: Bit de habilitación de interrupción del Timer8
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 2
MI2C2IE: Bit de habilitación de interrupción de eventos maestros I2C2
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 1
SI2C2IE: Bit de habilitación de interrupción de eventos esclavos I2C2
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 0
T7IE: Bit de habilitación de interrupción del temporizador 7
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada

© 2009 Microchip Technology Inc.
DS70286C-página 105
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 7-14:
IEC4: REGISTRO DE CONTROL DE HABILITACIÓN DE INTERRUPCIÓN 4
U-0
U-0
U-0
U-0
U-0
U-0
U-0
U-0
—
—
—
—
—
—
—
—
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
U-0
R/W-0
R/W-0
U-0
C2TXIE
C1TXIE
DMA7IE
DMA6IE
—
U2EIE
U1EIE
—
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bit 15-8
No implementado: leído como "0"
poco 7
C2TXIE: Bit de habilitación de interrupción de solicitud de transmisión de datos de ECAN2
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 6
C1TXIE: Bit de habilitación de interrupción de solicitud de transmisión de datos de ECAN1
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 5
DMA7IE: Bit de estado de habilitación completa de transferencia de datos del canal 7 de DMA
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 4
DMA6IE: Bit de estado de habilitación completa de transferencia de datos del canal 6 de DMA
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 3
No implementado: leído como "0"
poco 2
U2EIE: Bit de habilitación de interrupción de error UART2
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 1
U1EIE: Bit de habilitación de interrupción de error UART1
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 0
No implementado: leído como "0"

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 106
© 2009 Microchip Technology Inc.
     
REGÍSTRESE 7-15:
IPC0: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 0
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
T1IP<2:0>
—
OC1IP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
IC1IP<2:0>
—
INT0IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
T1IP<2:0>: Bits de prioridad de interrupción del temporizador 1
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 11
No implementado: leído como "0"
bits 10-8
OC1IP<2:0>: Bits de prioridad de interrupción del canal 1 de comparación de salida
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
IC1IP<2:0>: Bits de prioridad de interrupción del canal 1 de captura de entrada
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
INT0IP<2:0>: Interrupción externa 0 bits de prioridad
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

© 2009 Microchip Technology Inc.
DS70286C-página 107
dsPIC33FJXXXGPX06/X08/X10
    
REGÍSTRESE 7-16:
IPC1: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 1
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
T2IP<2:0>
—
OC2IP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
IC2IP<2:0>
—
DMA0IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
T2IP<2:0>: Bits de prioridad de interrupción del temporizador 2
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 11
No implementado: leído como "0"
bits 10-8
OC2IP<2:0>: Bits de prioridad de interrupción del canal 2 de comparación de salida
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
IC2IP<2:0>: Bits de prioridad de interrupción del canal 2 de captura de entrada
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
DMA0IP<2:0>: Bits de prioridad de interrupción completa de transferencia de datos del canal 0 de DMA
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 108
© 2009 Microchip Technology Inc.
    
REGÍSTRESE 7-17:
IPC2: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 2
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
U1RXIP<2:0>
—
SPI1IP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
SPI1EIP<2:0>
—
T3IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
U1RXIP<2:0>: Bits de prioridad de interrupción del receptor UART1
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 11
No implementado: leído como "0"
bits 10-8
SPI1IP<2:0>: Bits de prioridad de interrupción de evento SPI1
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
SPI1EIP<2:0>: Bits de prioridad de interrupción de error SPI1
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
T3IP<2:0>: Bits de prioridad de interrupción del temporizador 3
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

© 2009 Microchip Technology Inc.
DS70286C-página 109
dsPIC33FJXXXGPX06/X08/X10
    
REGÍSTRESE 7-18:
IPC3: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 3
U-0
U-0
U-0
U-0
U-0
R/W-1
R/W-0
R/W-0
—
—
—
—
—
DMA1IP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
AD1IP<2:0>
—
U1TXIP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-11
No implementado: leído como "0"
bits 10-8
DMA1IP<2:0>: Bits de prioridad de interrupción completa de transferencia de datos del canal 1 de DMA
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
AD1IP<2:0>: Conversión ADC1 completa bits de prioridad de interrupción
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
U1TXIP<2:0>: Bits de prioridad de interrupción del transmisor UART1
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 110
© 2009 Microchip Technology Inc.
REGÍSTRESE 7-19:
IPC4: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 4
U-0
R/W-1
R/W-0
R/W-0
U-0
U-0
U-0
U-0
—
CNIP<2:0>
—
—
—
—
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
MI2C1IP<2:0>
—
SI2C1IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
CNIP<2:0>: Cambiar bits de prioridad de interrupción de notificación
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
bit 11-7
No implementado: leído como "0"
bits 6-4
MI2C1IP<2:0>: Bits de prioridad de interrupción de eventos maestros I2C1
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
SI2C1IP<2:0>: Bits de prioridad de interrupción de eventos esclavos I2C1
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

© 2009 Microchip Technology Inc.
DS70286C-página 111
dsPIC33FJXXXGPX06/X08/X10
   
REGÍSTRESE 7-20:
IPC5: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 5
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
IC8IP<2:0>
—
IC7IP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
AD2IP<2:0>
—
INT1IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
IC8IP<2:0>: Bits de prioridad de interrupción del canal 8 de captura de entrada
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 11
No implementado: leído como "0"
bits 10-8
IC7IP<2:0>: Bits de prioridad de interrupción del canal 7 de captura de entrada
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
AD2IP<2:0>: Conversión ADC2 completa bits de prioridad de interrupción
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
INT1IP<2:0>: Bits de prioridad de interrupción externa 1
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 112
© 2009 Microchip Technology Inc.
   
REGÍSTRESE 7-21:
IPC6: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 6
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
T4IP<2:0>
—
OC4IP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
OC3IP<2:0>
—
DMA2IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
T4IP<2:0>: Bits de prioridad de interrupción del temporizador 4
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 11
No implementado: leído como "0"
bits 10-8
OC4IP<2:0>: Bits de prioridad de interrupción del canal 4 de comparación de salida
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
OC3IP<2:0>: Bits de prioridad de interrupción del canal 3 de comparación de salida
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
DMA2IP<2:0>: Bits de prioridad de interrupción completa de transferencia de datos del canal 2 de DMA
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

© 2009 Microchip Technology Inc.
DS70286C-página 113
dsPIC33FJXXXGPX06/X08/X10
    
REGISTRO 7-22:
IPC7: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 7
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
U2TXIP<2:0>
—
U2RXIP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
INT2IP<2:0>
—
T5IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
U2TXIP<2:0>: Bits de prioridad de interrupción del transmisor UART2
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 11
No implementado: leído como "0"
bits 10-8
U2RXIP<2:0>: Bits de prioridad de interrupción del receptor UART2
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
INT2IP<2:0>: Interrupción externa 2 bits de prioridad
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
T5IP<2:0>: Bits de prioridad de interrupción del temporizador 5
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 114
© 2009 Microchip Technology Inc.
    
REGISTRO 7-23:
IPC8: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
C1IP<2:0>
—
C1RXIP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
SPI2IP<2:0>
—
SPI2EIP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
C1IP<2:0>: Bits de prioridad de interrupción de evento ECAN1
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 11
No implementado: leído como "0"
bits 10-8
C1RXIP<2:0>: ECAN1 Recibir datos listos Bits de prioridad de interrupción
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
SPI2IP<2:0>: Bits de prioridad de interrupción de evento SPI2
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
SPI2EIP<2:0>: Bits de prioridad de interrupción de error SPI2
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

© 2009 Microchip Technology Inc.
DS70286C-página 115
dsPIC33FJXXXGPX06/X08/X10
    
REGÍSTRESE 7-24:
IPC9: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 9
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
IC5IP<2:0>
—
IC4IP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
IC3IP<2:0>
—
DMA3IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
IC5IP<2:0>: Bits de prioridad de interrupción del canal 5 de captura de entrada
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 11
No implementado: leído como "0"
bits 10-8
IC4IP<2:0>: Bits de prioridad de interrupción del canal 4 de captura de entrada
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
IC3IP<2:0>: Bits de prioridad de interrupción del canal 3 de captura de entrada
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
DMA3IP<2:0>: Bits de prioridad de interrupción completa de transferencia de datos del canal 3 de DMA
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 116
© 2009 Microchip Technology Inc.
    
REGÍSTRESE 7-25:
IPC10: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 10
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
OC7IP<2:0>
—
OC6IP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
OC5IP<2:0>
—
IC6IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
OC7IP<2:0>: Bits de prioridad de interrupción del canal 7 de comparación de salida
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 11
No implementado: leído como "0"
bits 10-8
OC6IP<2:0>: Bits de prioridad de interrupción del canal 6 de comparación de salida
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
OC5IP<2:0>: Bits de prioridad de interrupción del canal 5 de comparación de salida
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
IC6IP<2:0>: Bits de prioridad de interrupción del canal 6 de captura de entrada
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

© 2009 Microchip Technology Inc.
DS70286C-página 117
dsPIC33FJXXXGPX06/X08/X10
    
REGÍSTRESE 7-26:
IPC11: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 11
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
T6IP<2:0>
—
DMA4IP<2:0>
poco 15
poco 8
U-0
U-0
U-0
U-0
U-0
R/W-1
R/W-0
R/W-0
—
—
—
—
—
OC8IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
T6IP<2:0>: Bits de prioridad de interrupción del temporizador 6
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 11
No implementado: leído como "0"
bits 10-8
DMA4IP<2:0>: Bits de prioridad de interrupción completa de transferencia de datos del canal 4 de DMA
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
bit 7-3
No implementado: leído como "0"
poco 2-0
OC8IP<2:0>: Bits de prioridad de interrupción del canal 8 de comparación de salida
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 118
© 2009 Microchip Technology Inc.
    
REGÍSTRESE 7-27:
IPC12: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 12
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
T8IP<2:0>
—
MI2C2IP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
SI2C2IP<2:0>
—
T7IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
T8IP<2:0>: Bits de prioridad de interrupción del temporizador 8
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 11
No implementado: leído como "0"
bits 10-8
MI2C2IP<2:0>: Bits de prioridad de interrupción de eventos maestros I2C2
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
SI2C2IP<2:0>: Bits de prioridad de interrupción de eventos esclavos I2C2
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
T7IP<2:0>: Bits de prioridad de interrupción del temporizador 7
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

© 2009 Microchip Technology Inc.
DS70286C-página 119
dsPIC33FJXXXGPX06/X08/X10
    
REGISTRO 7-28:
IPC13: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 13
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
C2RXIP<2:0>
—
INT4IP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
INT3IP<2:0>
—
T9IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
C2RXIP<2:0>: ECAN2 Recibir datos listos Bits de prioridad de interrupción
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 11
No implementado: leído como "0"
bits 10-8
INT4IP<2:0>: Interrupción externa 4 bits de prioridad
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
INT3IP<2:0>: Interrupción externa 3 bits de prioridad
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
T9IP<2:0>: Bits de prioridad de interrupción del temporizador 9
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 120
© 2009 Microchip Technology Inc.
    
REGISTRO 7-29:
IPC14: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 14
U-0
R/W-1
R/W-0
R/W-0
U-0
U-0
U-0
U-0
—
DCIEIP<2:0>
—
—
—
—
poco 15
poco 8
U-0
U-0
U-0
U-0
U-0
R/W-1
R/W-0
R/W-0
—
—
—
—
—
C2IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
DCIEIP<2:0>: Bits de prioridad de interrupción de error DCI
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
bit 11-3
No implementado: leído como "0"
poco 2-0
C2IP<2:0>: Bits de prioridad de interrupción de evento ECAN2
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

© 2009 Microchip Technology Inc.
DS70286C-página 121
dsPIC33FJXXXGPX06/X08/X10
REGÍSTRESE 7-30:
IPC15: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 15
U-0
U-0
U-0
U-0
U-0
U-0
U-0
U-0
—
—
—
—
—
—
—
—
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
DMA5IP<2:0>
—
DCIIP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bit 15-7
No implementado: leído como "0"
bits 6-4
DMA5IP<2:0>: Bits de prioridad de interrupción completa de transferencia de datos del canal 5 de DMA
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
DCIIP<2:0>: Bits de prioridad de interrupción de evento DCI
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 122
© 2009 Microchip Technology Inc.
    
REGISTRO 7-31:
IPC16: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 16
U-0
U-0
U-0
U-0
U-0
R/W-1
R/W-0
R/W-0
—
—
—
—
—
U2EIP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
U-0
U-0
U-0
—
U1EIP<2:0>
—
—
—
—
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-11
No implementado: leído como "0"
bits 10-8
U2EIP<2:0>: Bits de prioridad de interrupción de error de UART2
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
U1EIP<2:0>: Bits de prioridad de interrupción de error UART1
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3-0
No implementado: leído como "0"

© 2009 Microchip Technology Inc.
DS70286C-página 123
dsPIC33FJXXXGPX06/X08/X10
 
   
REGISTRO 7-32:
IPC17: REGISTRO DE CONTROL DE PRIORIDAD DE INTERRUPCIÓN 17
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
C2TXIP<2:0>
—
C1TXIP<2:0>
poco 15
poco 8
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
DMA7IP<2:0>
—
DMA6IP<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
C2TXIP<2:0>: Bits de prioridad de interrupción de solicitud de datos de transmisión ECAN2
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 11
No implementado: leído como "0"
bits 10-8
C1TXIP<2:0>: Bits de prioridad de interrupción de solicitud de datos de transmisión ECAN1
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
DMA7IP<2:0>: Bits de prioridad de interrupción completa de transferencia de datos del canal 7 de DMA
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
DMA6IP<2:0>: Bits de prioridad de interrupción completa de transferencia de datos del canal 6 de DMA
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 124
© 2009 Microchip Technology Inc.
REGISTRO 7-33:
INTTREG: CONTROL DE INTERRUPCIONES Y REGISTRO DE ESTADO
U-0
U-0
U-0
U-0
R-0
R-0
R-0
R-0
—
—
—
—
ILR<3:0>
poco 15
poco 8
U-0
R-0
R-0
R-0
R-0
R-0
R-0
R-0
—
VECNUM<6:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-12
No implementado: leído como "0"
bits 11-8
ILR<3:0>: Nuevos bits de nivel de prioridad de interrupción de CPU
1111 = El nivel de prioridad de interrupción de la CPU es 15 
•
•
•
0001 = El nivel de prioridad de interrupción de la CPU es 1
0000 = El nivel de prioridad de interrupción de la CPU es 0
poco 7
No implementado: leído como "0"
poco 6-0
VECNUM<6:0>: Número vectorial de bits de interrupción pendientes
0111111 = Vector de interrupción pendiente es el número 135 
•
•
•
0000001 = El vector de interrupción pendiente es el número 9
0000000 = El vector de interrupción pendiente es el número 8

© 2009 Microchip Technology Inc.
DS70286C-página 125
dsPIC33FJXXXGPX06/X08/X10
7.4
Procedimientos de configuración de interrupción
7.4.1
INICIALIZACIÓN
Para configurar una fuente de interrupción:
1.
Establezca el bit NSTDIS (INTCON1<15>) si está anidado
No se desean interrupciones.
2.
Seleccione el nivel de prioridad asignado por el usuario para el
fuente de interrupción escribiendo los bits de control en el
registro IPCx apropiado. El nivel de prioridad será
Depende de la aplicación específica y del tipo de
fuente de interrupción. Si no hay varios niveles de prioridad
deseado, los bits de control del registro IPCx para todos
las fuentes de interrupción habilitadas pueden programarse
al mismo valor distinto de cero.
3.
Borre el bit de estado del indicador de interrupción asociado con
el periférico en el registro IFSx asociado.
4.
Habilite la fuente de interrupción configurando el
bit de control de habilitación de interrupción asociado con el
fuente en el registro IECx apropiado.
7.4.2
RUTINA DE SERVICIO DE INTERRUPCIÓN
El método que se utiliza para declarar un ISR e inicializar
el IVT con la dirección vectorial correcta dependerá de
el lenguaje de programación (es decir, C o ensamblador) y
el conjunto de herramientas de desarrollo de lenguajes que se utiliza para
desarrollar la aplicación. En general, el usuario debe borrar
el indicador de interrupción en el registro IFSx apropiado para el
fuente de interrupción que maneja el ISR. De lo contrario, el
El ISR se volverá a ingresar inmediatamente después de salir del
rutina. Si el ISR está codificado en lenguaje ensamblador,
debe terminarse usando una instrucción RETFIE para
desapilar el valor de PC guardado, el valor SRL y la CPU antigua
nivel de prioridad.
7.4.3
RUTINA DE SERVICIO DE TRAMPA
Una Rutina de Servicio de Trampas (TSR) está codificada como un ISR,
excepto que el indicador de estado de trampa apropiado en el
El registro INTCON1 debe borrarse para evitar el reingreso
en el TSR.
7.4.4
INTERRUMPIR DESACTIVAR
Todas las interrupciones del usuario se pueden desactivar usando lo siguiente
procedimiento:
1.
Introduzca el valor SR actual en el software
apilar usando la instrucción PUSH.
2.
Forzar la CPU al nivel de prioridad 7 inclusive
OR del valor OEh con SRL.
Para permitir interrupciones del usuario, la instrucción POP puede ser
Se utiliza para restaurar el valor SR anterior.
Tenga en cuenta que sólo el usuario interrumpe con un nivel de prioridad de 7 o
menos se puede desactivar. Fuentes de trampa (nivel 8-nivel 15)
no se puede desactivar.
La instrucción DISI proporciona una manera conveniente de
deshabilitar las interrupciones de los niveles de prioridad 1-6 durante un período fijo
de tiempo. Las fuentes de interrupción de nivel 7 no están desactivadas por
la instrucción DISI.
Nota:
En un reinicio del dispositivo, los registros IPCx se
inicializado, de modo que todos los usuarios interrumpan
Las fuentes se asignan al nivel de prioridad 4.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 126
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70286C-página 127
dsPIC33FJXXXGPX06/X08/X10
8.0
ACCESO DIRECTO A LA MEMORIA 
(DMA)
El acceso directo a memoria (DMA) es un sistema muy eficiente.
Mecanismo de copia de datos entre SFR periféricos.
(por ejemplo, registro de recepción UART, búfer de captura de entrada 1),
y buffers o variables almacenadas en la RAM, con un mínimo
CPU 
intervención. 
el 
DMA 
controlador 
puede
copiar automáticamente bloques enteros de datos sin
Requerir que el software del usuario lea o escriba el
Registros de funciones especiales (SFR) periféricos cada
momento en que se produce una interrupción periférica. El controlador DMA
utiliza un bus dedicado para las transferencias de datos y por lo tanto,
no roba ciclos del flujo de ejecución del código de
la CPU. Para explotar la capacidad DMA, el
Los buffers o variables de usuario correspondientes deben ser
ubicado en DMA RAM.
Los periféricos dsPIC33FJXXXGPX06/X08/X10 que
pueden utilizar DMA se enumeran en la Tabla 8-1 junto con sus
números de solicitud de interrupción (IRQ) asociados.
TABLA 8-1:
PERIFÉRICOS CON DMA 
SOPORTE
El controlador DMA presenta ocho datos idénticos
canales de transferencia.
Cada canal tiene su propio conjunto de control y estado.
registros. Cada canal DMA se puede configurar para
copiar datos desde buffers almacenados en DMA de doble puerto
RAM a SFR periféricos, o desde SFR periféricos a
buffers en DMA RAM. 
El controlador DMA admite las siguientes funciones:
• Transferencias de datos de tamaño palabra o byte.
• Transferencias desde periféricos a DMA RAM o DMA 
RAM al periférico.
• Direccionamiento indirecto de ubicaciones de DMA RAM con o 
sin post-incremento automático.
• Direccionamiento indirecto periférico: en algunos 
periféricos, las direcciones de lectura/escritura de DMA RAM 
puede derivarse parcialmente del periférico.
• Transferencias en bloque de una sola vez: terminación de DMA 
transferencia después de una transferencia en bloque.
• Transferencias en bloque continuas: recarga de DMA 
Dirección de inicio del búfer RAM después de cada bloque 
la transferencia está completa.
• Modo Ping-Pong: cambio entre dos DMA 
Direcciones de inicio de RAM entre bloques sucesivos 
transferencias, llenando así dos buffers alternativamente.
• Inicio automático o manual de transferencias en bloque
• Cada canal puede seleccionar entre 20 posibles 
fuentes de datos fuentes o destinos.
Para cada canal DMA, se envía una solicitud de interrupción DMA.
generado cuando se completa una transferencia en bloque.
Alternativamente, se puede generar una interrupción cuando la mitad de
el bloque se ha llenado. 
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 22.
“Directo 
Memoria 
Acceso 
(DMA)”
(DS70182) en la “familia dsPIC33F
Manual de referencia”, que está disponible
de 
el 
Microchip 
web 
sitio
(www.microchip.com).
periférico
Número de IRQ
INT0
0
Captura de entrada 1
1
Captura de entrada 2
5
Comparación de salida 1
2
Comparación de salida 2
6
Temporizador2
7
Temporizador3
8
SPI1
10
SPI2
33
Recepción UART1
11
Transmisión UART1
12
Recepción UART2
30
Transmisión UART2
31
ADC1
13
ADC2
21
DCI
60
Recepción ECAN1
34
Transmisión ECAN1
70
Recepción ECAN2
55
Transmisión ECAN2
71

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 128
© 2009 Microchip Technology Inc.
FIGURA 8-1:
ARQUITECTURA DEL SISTEMA DE NIVEL SUPERIOR QUE UTILIZA UN BUS DE TRANSACCIONES DEDICADO
8.1
Registros DMAC
Cada canal DMAC x (x = 0, 1, 2, 3, 4, 5, 6 o 7)
contiene los siguientes registros:
• Un registro de control de canal DMA de 16 bits 
(DMAXCON)
• Un registro de selección IRQ de canal DMA de 16 bits 
(DMAxREQ)
• Un desplazamiento de dirección de inicio primaria de DMA RAM de 16 bits 
registro (DMAxSTA)
• Una dirección de inicio secundaria de DMA RAM de 16 bits 
Registro de compensación (DMAxSTB)
• Un registro de dirección periférica DMA de 16 bits 
(DMAxPAD)
• Un registro de recuento de transferencias DMA de 10 bits (DMAxCNT)
Un par adicional de registros de estado, DMACS0 y
DMACS1, son comunes a todos los canales DMAC.
CPU
SRAM
RAM DMA
Bus DS de periféricos de CPU
Periférico 3
DMA
periférico
Sin DMA
SRAM X-Bus
PUERTO 2
PUERTO 1
Periférico 1
DMA
Listo
Periférico 2
DMA
Listo
Listo
Listo
Autobús DMA DS
DMA de la CPU
DMA de la CPU
DMA de la CPU
Dirección indirecta periférica
Nota: Los buses de direcciones de CPU y DMA no se muestran para mayor claridad.
DMA
controlar
Controlador DMA
DMA
Canales

© 2009 Microchip Technology Inc.
DS70286C-página 129
dsPIC33FJXXXGPX06/X08/X10
     
REGÍSTRESE 8-1:
DMAxCON: CANAL DMA x REGISTRO DE CONTROL
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
U-0
U-0
U-0
CHEN
TAMAÑO
dirección
MITAD
NULO
—
—
—
poco 15
poco 8
U-0
U-0
R/W-0
R/W-0
U-0
U-0
R/W-0
R/W-0
—
—
MODO<1:0>
—
—
MODO<1:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
CHEN: bit de habilitación de canal
1 = Canal habilitado
0 = Canal deshabilitado
poco 14
TAMAÑO: Bit de tamaño de transferencia de datos
1 = byte
0 = Palabra
poco 13
DIR: Bit de dirección de transferencia (selección de bus de origen/destino)
1 = Leer desde la dirección DMA RAM, escribir en la dirección periférica
0 = Leer desde la dirección del periférico, escribir en la dirección DMA RAM
poco 12
MITAD: Bit de selección de interrupción completa de transferencia anticipada en bloque
1 = Iniciar transferencia en bloque, interrupción completa cuando se ha movido la mitad de los datos
0 = Iniciar la transferencia en bloque y completar la interrupción cuando se hayan movido todos los datos
poco 11
NULLW: bit de selección de modo de escritura periférica de datos nulos
1 = Escritura de datos nulos en el periférico además de la escritura en DMA RAM (el bit DIR también debe estar limpio) 
0 = funcionamiento normal
bit 10-6
No implementado: leído como "0"
bit 5-4
AMODE<1:0>: Bits de selección del modo de funcionamiento del canal DMA
11 = Reservado
10 = Modo de direccionamiento indirecto de periféricos
01 = Registro Indirecto sin modo Post-Incremento
00 = Registrar Indirecto con modo Post-Incremento
bit 3-2
No implementado: leído como "0"
poco 1-0
MODE<1:0>: Bits de selección del modo de funcionamiento del canal DMA
11 = Modos One-Shot, Ping-Pong habilitados (una transferencia en bloque desde/hacia cada búfer RAM DMA)
10 = Continuo, modos Ping-Pong habilitados
01 = Modos One-Shot, Ping-Pong deshabilitados
00 = Continuo, modos Ping-Pong deshabilitados

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 130
© 2009 Microchip Technology Inc.
     
REGÍSTRESE 8-2:
DMAxREQ: CANAL DMA x IRQ SELECCIONAR REGISTRO
R/W-0
U-0
U-0
U-0
U-0
U-0
U-0
U-0
FUERZA(1)
—
—
—
—
—
—
—
poco 15
poco 8
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
—
IRQSEL6(2)
IRQSEL5(2)
IRQSEL4(2)
IRQSEL3(2)
IRQSEL2(2)
IRQSEL1(2)
IRQSEL0(2)
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
FUERZA: Forzar bit de transferencia DMA (1)
1 = Forzar una única transferencia DMA (modo manual)
0 = Iniciación automática de transferencia DMA mediante solicitud de DMA
bit 14-7
No implementado: leído como "0"
poco 6-0
IRQSEL<6:0>: Bits de selección de número IRQ periférico DMA(2)
0000000-1111111 = DMAIRQ0-DMAIRQ127 seleccionado para ser el canal DMAREQ
Nota 1: El usuario no puede borrar el bit FORCE. El hardware borra el bit FORCE cuando se activa el bit FORCE.
La transferencia DMA está completa.
2: Consulte la Tabla 8-1 para obtener una lista completa de los números IRQ para todas las fuentes de interrupción.

© 2009 Microchip Technology Inc.
DS70286C-página 131
dsPIC33FJXXXGPX06/X08/X10
     
     
REGISTRO 8-3:
DMaxSTA: CANAL DMA x RAM DIRECCIÓN DE INICIO REGISTRO DE COMPENSACIÓN A
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
STA<15:8>
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
ESTA<7:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
STA<15:0>: Bits de dirección de inicio de RAM DMA primaria (origen o destino)
REGÍSTRESE 8-4:
DMaxSTB: CANAL DMA x RAM DIRECCIÓN DE INICIO REGISTRO DE COMPENSACIÓN B
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
STB<15:8>
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
STB<7:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
STB<15:0>: Bits de dirección de inicio de RAM DMA secundaria (origen o destino)

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 132
© 2009 Microchip Technology Inc.
     
     
REGÍSTRESE 8-5:
DMaxPAD: CANAL DMA x REGISTRO DE DIRECCIÓN PERIFÉRICA(1)
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
ALMOHADILLA<15:8>
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
PAD<7:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
PAD<15:0>: Bits de registro de dirección periférica
Nota 1: Si el canal está habilitado (es decir, activo), las escrituras en este registro pueden provocar un comportamiento impredecible del
Canal DMA y debe evitarse.
REGÍSTRESE 8-6:
DMAxCNT: CANAL DMA x REGISTRO DE CUENTA DE TRANSFERENCIAS(1)
U-0
U-0
U-0
U-0
U-0
U-0
R/W-0
R/W-0
—
—
—
—
—
—
CNT<9:8>(2)
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
CNT<7:0>(2)
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-10
No implementado: leído como "0"
poco 9-0
CNT<9:0>: Bits de registro de recuento de transferencia DMA(2)
Nota 1: Si el canal está habilitado (es decir, activo), las escrituras en este registro pueden provocar un comportamiento impredecible del
Canal DMA y debe evitarse.
2: Número de transferencias DMA = CNT<9:0> + 1.

© 2009 Microchip Technology Inc.
DS70286C-página 133
dsPIC33FJXXXGPX06/X08/X10
     
REGÍSTRESE 8-7:
DMACS0: REGISTRO DE ESTADO DEL CONTROLADOR DMA 0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
PWCOL7
PWCOL6
PWCOL5
PWCOL4
PWCOL3
PWCOL2
PWCOL1
PWCOL0
poco 15
poco 8
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
XWCOL7
XWCOL6
XWCOL5
XWCOL4
XWCOL3
XWCOL2
XWCOL1
XWCOL0
poco 7
poco 0
Leyenda:
C = Borrar solo bit
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
PWCOL7: Bit de bandera de colisión de escritura periférica del canal 7
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 14
PWCOL6: Bit de bandera de colisión de escritura periférica del canal 6
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 13
PWCOL5: Bit de bandera de colisión de escritura periférica del canal 5
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 12
PWCOL4: Bit de bandera de colisión de escritura periférica del canal 4
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 11
PWCOL3: Bit de bandera de colisión de escritura periférica del canal 3
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 10
PWCOL2: Bit de bandera de colisión de escritura periférica del canal 2
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 9
PWCOL1: Bit de bandera de colisión de escritura periférica del canal 1
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 8
PWCOL0: Bit de bandera de colisión de escritura periférica del canal 0
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 7
XWCOL7: Bit de indicador de colisión de escritura de RAM DMA del canal 7
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 6
XWCOL6: Bit de indicador de colisión de escritura de RAM DMA del canal 6
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 5
XWCOL5: Bit de indicador de colisión de escritura de RAM DMA del canal 5
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 4
XWCOL4: Bit de indicador de colisión de escritura de RAM DMA del canal 4
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 134
© 2009 Microchip Technology Inc.
poco 3
XWCOL3: Bit de indicador de colisión de escritura de RAM DMA del canal 3
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 2
XWCOL2: Bit de indicador de colisión de escritura de RAM DMA del canal 2
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 1
XWCOL1: Bit de indicador de colisión de escritura de RAM DMA del canal 1
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 0
XWCOL0: Bit de bandera de colisión de escritura de RAM DMA del canal 0
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
REGÍSTRESE 8-7:
DMACS0: REGISTRO DE ESTADO DEL CONTROLADOR DMA 0 (CONTINUACIÓN)

© 2009 Microchip Technology Inc.
DS70286C-página 135
dsPIC33FJXXXGPX06/X08/X10
     
REGÍSTRESE 8-8:
DMACS1: REGISTRO DE ESTADO DEL CONTROLADOR DMA 1
U-0
U-0
U-0
U-0
R-1
R-1
R-1
R-1
—
—
—
—
LSTCH<3:0>
poco 15
poco 8
R-0
R-0
R-0
R-0
R-0
R-0
R-0
R-0
PPST7
PPST6
PPST5
PPST4
PPST3
PPST2
PPST1
PPST0
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-12
No implementado: leído como "0"
bits 11-8
LSTCH<3:0>: Últimos bits activos del canal DMA
1111 = No se ha producido ninguna transferencia DMA desde el reinicio del sistema
1110-1000 = Reservado
0111 = La última transferencia de datos fue por DMA Canal 7
0110 = La última transferencia de datos fue por DMA Canal 6
0101 = La última transferencia de datos fue por DMA Canal 5
0100 = La última transferencia de datos fue por DMA Canal 4
0011 = La última transferencia de datos fue por DMA Canal 3
0010 = La última transferencia de datos fue por DMA Canal 2
0001 = La última transferencia de datos fue por DMA Canal 1
0000 = La última transferencia de datos fue por DMA Canal 0
poco 7
PPST7: Bit de indicador de estado del modo ping-pong del canal 7
1 = registro DMA7STB seleccionado
0 = registro DMA7STA seleccionado
poco 6
PPST6: Bit de indicador de estado del modo ping-pong del canal 6
1 = registro DMA6STB seleccionado
0 = registro DMA6STA seleccionado
poco 5
PPST5: Bit de indicador de estado del modo ping-pong del canal 5
1 = registro DMA5STB seleccionado
0 = registro DMA5STA seleccionado
poco 4
PPST4: Bit de indicador de estado del modo ping-pong del canal 4
1 = registro DMA4STB seleccionado
0 = registro DMA4STA seleccionado
poco 3
PPST3: Bit de indicador de estado del modo ping-pong del canal 3
1 = registro DMA3STB seleccionado
0 = registro DMA3STA seleccionado
poco 2
PPST2: Bit de indicador de estado del modo ping-pong del canal 2
1 = registro DMA2STB seleccionado
0 = registro DMA2STA seleccionado
poco 1
PPST1: Bit de indicador de estado del modo ping-pong del canal 1
1 = registro DMA1STB seleccionado
0 = registro DMA1STA seleccionado
poco 0
PPST0: Bit de indicador de estado del modo ping-pong del canal 0
1 = registro DMA0STB seleccionado
0 = registro DMA0STA seleccionado

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 136
© 2009 Microchip Technology Inc.
     
REGISTRAR 8-9:
DSADR: DIRECCIÓN RAM DMA MÁS RECIENTE
R-0
R-0
R-0
R-0
R-0
R-0
R-0
R-0
DSADR<15:8>
poco 15
poco 8
R-0
R-0
R-0
R-0
R-0
R-0
R-0
R-0
DSADR<7:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
DSADR<15:0>: dirección RAM DMA más reciente a la que acceden los bits del controlador DMA

© 2009 Microchip Technology Inc.
DS70286C-página 137
dsPIC33FJXXXGPX06/X08/X10
9.0
OSCILADOR 
CONFIGURACIÓN
El sistema oscilador dsPIC33FJXXXGPX06/X08/X10
proporciona:
• Varias opciones de oscilador externo e interno como 
fuentes de reloj
• Un PLL en chip para escalar el funcionamiento interno 
frecuencia a la frecuencia de reloj del sistema requerida
• El oscilador FRC interno también se puede utilizar con 
el PLL, lo que permite un funcionamiento a máxima velocidad 
sin ningún hardware de generación de reloj externo
• Cambio de reloj entre varias fuentes de reloj
• Postescalador de reloj programable para alimentación del sistema 
ahorros
• Un monitor de reloj a prueba de fallos (FSCM) que detecta 
falla del reloj y toma medidas a prueba de fallas
• Un registro de control de reloj (OSCCON)
• Bits de configuración no volátiles para el oscilador principal 
selección.
Se muestra un diagrama simplificado del sistema oscilador.
en la Figura 9-1.
FIGURA 9-1:
dsPIC33FJXXXGPX06/X08/X10 DIAGRAMA DEL SISTEMA OSCILADOR 
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 7.
“Oscilador” (DS70186) en el “dsPIC33F
Manual de referencia familiar”, que es
disponible en el sitio web de Microchip
(www.microchip.com).
dsPIC33F
Oscilador secundario
LPOSCEN
SOSCO
SOSCI
Temporizador 1
XTPLL, HSPLL,
XT, SA, CE
FRCDIV<2:0> 
WDT, PWRT, 
FCM
FRCDIVN
SOSC
FRCDIV16
ECPL, FRCPLL
NOSC<2:0> FNOSC<2:0>
Reiniciar
FRC
Oscilador
LPRC
Oscilador
DORMIR<2:0>
T3
T1
T2
T1/T3
T7
T6
FRC 
LPRC
S0
T5
T4
÷ 16
Interruptor de reloj
T7
Fallo del reloj
÷ 2
SINTONIZAR<5:0>
PLL(1)
FCY
FOSC
FRCDIV
DORMIR
Nota 1:
Consulte la Figura 9-2 para obtener detalles de PLL.
2:
Si el oscilador se utiliza con los modos XT o HS, se debe conectar una resistencia paralela extendida con un valor de 1 MΩ.
OSC2
OSC1
Oscilador primario
R(2)
POSCMD<1:0>
FP

dsPIC33FJXXXGPX06/X08/X10 
DS70286C-página 138 
© 2009 Microchip Technology Inc. 
9.1 
Sistema de reloj de CPU 
Hay siete opciones de reloj del sistema proporcionadas por el 
dsPIC33FJXXXGPX06/X08/X10: 
• Oscilador FRC 
• Oscilador FRC con PLL 
• Oscilador primario (XT, HS o EC) 
• Oscilador primario con PLL 
• Oscilador secundario (LP) 
• Oscilador LPRC 
• Oscilador FRC con postescalador 
9.1.1 
FUENTES DEL RELOJ DEL SISTEMA 
El oscilador interno FRC (Fast RC) funciona a una velocidad nominal 
frecuencia de 7,37 MHz. El software del usuario puede ajustar el 
Frecuencia CRF. El software del usuario puede especificar opcionalmente un 
factor (que varía de 1:2 a 1:256) por el cual el FRC 
La frecuencia del reloj se divide. Este factor se selecciona usando 
los bits FRCDIV<2:0> (CLKDIV<10:8>). 
El oscilador primario puede utilizar uno de los siguientes como 
su fuente de reloj: 
1. 
XT (Cristal): Cristales y resonadores cerámicos en 
el rango de 3 MHz a 10 MHz. El cristal es 
conectado a los pines OSC1 y OSC2. 
2. 
HS (Cristal de alta velocidad): Cristales en el rango 
de 10 MHz a 40 MHz. El cristal está conectado. 
a los pines OSC1 y OSC2. 
3. 
EC (reloj externo): la señal del reloj externo es 
aplicado directamente al pin OSC1. 
El oscilador secundario (LP) está diseñado para baja potencia. 
y utiliza un resonador cerámico o de cristal de 32,768 kHz. 
El oscilador LP utiliza los pines SOSCI y SOSCO. 
El oscilador interno LPRC (Low-Power RC) funciona a una 
frecuencia nominal de 32,768 kHz. También se utiliza como 
reloj de referencia mediante el temporizador de vigilancia (WDT) y 
Monitor de reloj a prueba de fallos (FSCM). 
Las señales de reloj generadas por el FRC y el primario. 
Los osciladores se pueden aplicar opcionalmente a un chip. 
Bucle de bloqueo de fase (PLL) para proporcionar una amplia gama de 
producción 
frecuencias 
para 
dispositivo 
operación. 
PLL 
La configuración se describe en la Sección 9.1.3 “PLL 
Configuración". 
La frecuencia de FRC depende de la precisión de FRC 
(ver Tabla 25-19) y el valor del oscilador FRC 
Registro de sintonización (ver Registro 9-4). 
9.1.2 
SELECCIÓN DEL RELOJ DEL SISTEMA 
La fuente del oscilador que se utiliza en un dispositivo Encendido 
El evento de reinicio se selecciona usando la configuración de bits de configuración. 
Los ajustes de los bits de configuración del oscilador se encuentran en la 
Registros de configuración en la memoria del programa. (Referirse a 
Sección 22.1 “Bits de configuración” para obtener más detalles.) 
Los bits de configuración de selección de oscilador inicial, 
FNOSC<2:0> (FOSCSEL<2:0>), y el Primario 
Oscilador 
Modo 
Seleccionar 
Configuración 
bits, 
POSCMD<1:0> (FOSC<1:0>), seleccione el oscilador 
fuente que se utiliza en un reinicio de encendido. El FRC 
El oscilador primario es el predeterminado (no programado). 
selección. 
Los bits de configuración permiten a los usuarios elegir entre 
doce modos de reloj diferentes, que se muestran en la Tabla 9-1. 
La salida del oscilador (o la salida del PLL si 
se ha seleccionado un modo PLL) FOSC se divide por 2 para 
generar el reloj de instrucciones del dispositivo (FCY) y el 
Base de tiempo del reloj periférico (FP). FCY define el 
velocidad de funcionamiento del dispositivo y velocidades de hasta 40 
megahercio 
son 
apoyado 
por 
el 
Arquitectura dsPIC33FJXXXGPX06/X08/X10. 
Velocidad de ejecución de instrucciones o funcionamiento del dispositivo. 
La frecuencia, FCY, está dada por: 
ECUACIÓN 9-1: 
FUNCIONAMIENTO DEL DISPOSITIVO 
FRECUENCIA 
9.1.3 
CONFIGURACIÓN DEL PLL 
El oscilador primario y el oscilador interno FRC pueden 
opcionalmente use un PLL en chip para obtener velocidades más altas 
de operación. El PLL proporciona una cantidad significativa de 
flexibilidad en la selección de la velocidad de funcionamiento del dispositivo. A 
El diagrama de bloques del PLL se muestra en la Figura 9-2. 
La salida del oscilador primario o FRC, denotada como 
'FIN', se divide por un factor de preescala (N1) de 2, 3, 
... o 33 antes de ser suministrado al voltaje del PLL 
Oscilador controlado (VCO). La entrada al VCO debe 
seleccionarse para que esté en el rango de 0,8 MHz a 8 MHz. 
Dado que el factor mínimo de preescala es 2, esto implica que 
Se debe elegir FIN para que esté en el rango de 1,6 MHz a 16 
Megahercio. El factor de preescala 'N1' se selecciona utilizando el 
PLLPRE<4:0> bits (CLKDIV<4:0>). 
El divisor de retroalimentación PLL, seleccionado usando el 
PLLDIV<8:0> bits (PLLFBD<8:0>), proporciona un factor 'M', 
por el cual se multiplica la entrada al VCO. este factor 
debe seleccionarse de modo que la salida VCO resultante 
La frecuencia está en el rango de 100 MHz a 200 MHz. 
La salida del VCO se divide además por un factor de posescala. 
'N2'. Este factor se selecciona usando PLLPOST<1:0> 
bits (CLKDIV<7:6>). 'N2' puede ser 2, 4 u 8, y 
debe seleccionarse de modo que la frecuencia de salida del PLL 
(FOSC) está en el rango de 12,5 MHz a 80 MHz, lo que 
Genera velocidades de funcionamiento del dispositivo de 6,25 a 40 MIPS. 
Para un oscilador primario u oscilador FRC, salida 'FIN', 
la salida PLL 'FOSC' viene dada por: 
ECUACIÓN 9-2: 
CÁLCULO FOSC 
FCY 
OSCURO 
2 

> Error de traducción: -------------

> Error de traducción: =
OSCURO 
ALETA 
METRO 
N1 N2 

> Error de traducción: ⋅

> Error de traducción: ------------------

> Error de traducción: ⎝

> Error de traducción: ⎠

> Error de traducción: ⎛

> Error de traducción: ⎞

> Error de traducción: ⋅

> Error de traducción: =

© 2009 Microchip Technology Inc.
DS70286C-página 139
dsPIC33FJXXXGPX06/X08/X10
Por ejemplo, supongamos que se utiliza un cristal de 10 MHz,
siendo “XT con PLL” el modo de oscilador seleccionado.
Si PLLPRE<4:0> = 0, entonces N1 = 2. Esto produce un VCO
entrada de 10/2 = 5 MHz, que está dentro de lo aceptable
rango de 0,8-8 MHz. Si PLLDIV<8:0> = 0x1E, entonces 
M = 32. Esto produce una salida VCO de 5 x 32 = 160 MHz,
que está dentro del rango necesario de 100-200 MHz.
Si PLLPOST<1:0> = 0, entonces N2 = 2. Esto proporciona una
Fosc de 160/2 = 80 MHz. El dispositivo resultante funcionando
La velocidad es 80/2 = 40 MIPS.
ECUACIÓN 9-3:
XT CON MODO PLL 
EJEMPLO
FIGURA 9-2:
dsPIC33FJXXXGPX06/X08/X10 DIAGRAMA DE BLOQUES PLL 
TABLA 9-1:
VALORES DE BITS DE CONFIGURACIÓN PARA LA SELECCIÓN DEL RELOJ
FCY
FOSC
2
-------------
1
2-- 10000000 32
⋅
2 2
⋅
---------------------------------
⎝
⎠
⎛
⎞
40 MIPS
=
=
=
Modo oscilador
Fuente del oscilador
POSCMD<1:0>
FNOSC<2:0>
Nota
Oscilador RC rápido con división por N 
(FRCDIVN)
Interno
xx
111
1, 2
Oscilador RC rápido con división por 16 
(FRCDIV16)
Interno
xx
110
1
Oscilador RC de baja potencia (LPRC)
Interno
xx
101
1
Oscilador secundario (Timer1) (SOSC)
Secundaria
xx
100
1
Oscilador primario (HS) con PLL 
(HSPLL)
Primaria
10
011
—
Oscilador primario (XT) con PLL 
(XTPLL)
Primaria
01
011
—
Oscilador primario (EC) con PLL 
(ECPL)
Primaria
00
011
1
Oscilador primario (HS)
Primaria
10
010
—
Oscilador primario (XT)
Primaria
01
010
—
Oscilador primario (EC)
Primaria
00
010
1
Oscilador RC rápido con PLL (FRCPLL)
Interno
xx
001
1
Oscilador RC rápido (FRC)
Interno
xx
000
1
Nota 1:
La función del pin OSC2 está determinada por el bit de configuración OSCIOFNC.
2:
Este es el modo de oscilador predeterminado para un dispositivo no programado (borrado).
0,8-8,0 MHz
Aquí(1)
100-200MHz
Aquí(1)
dividir por
2, 4, 8
dividir por
2-513
dividir por
2-33
Fuente (cristal, reloj externo
PLLPRE
x
VCO
PLLDIV
POST
o RC interno)
12,5-80MHz
Aquí(1)
FOSC
Nota 1: Este rango de frecuencia debe cumplirse en todo momento.
FVCO
N1
m
N2

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 140
© 2009 Microchip Technology Inc.
     
REGÍSTRESE 9-1:
OSCCON: REGISTRO DE CONTROL DEL OSCILADOR(1)
U-0
R-0
R-0
R-0
U-0
R/W-y
R/W-y
R/W-y
—
COSC<2:0>
—
NOSC<2:0>(2)
poco 15
poco 8
R/W-0
U-0
R-0
U-0
R/C-0
U-0
R/W-0
R/W-0
CLKLOCK
—
BLOQUEAR
—
FQ
—
LPOSCEN
oswen
poco 7
poco 0
Leyenda:
y = Valor establecido desde los bits de configuración en POR
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
bits 14-12
COSC<2:0>: Bits de selección del oscilador actual (solo lectura) 
000 = Oscilador RC rápido (FRC)
001 = Oscilador RC rápido (FRC) con PLL 
010 = Oscilador primario (XT, HS, EC)
011 = Oscilador primario (XT, HS, EC) con PLL 
100 = Oscilador secundario (SOSC)
101 = Oscilador RC de baja potencia (LPRC)
110 = Oscilador RC rápido (FRC) con división por 16
111 = Oscilador RC rápido (FRC) con división por n
poco 11
No implementado: leído como "0"
bits 10-8
NOSC<2:0>: Nuevos bits de selección de oscilador(2)
000 = Oscilador RC rápido (FRC)
001 = Oscilador RC rápido (FRC) con PLL 
010 = Oscilador primario (XT, HS, EC)
011 = Oscilador primario (XT, HS, EC) con PLL 
100 = Oscilador secundario (SOSC)
101 = Oscilador RC de baja potencia (LPRC)
110 = Oscilador RC rápido (FRC) con división por 16
111 = Oscilador RC rápido (FRC) con división por n
poco 7
CLKLOCK: bit de habilitación de bloqueo de reloj 
1 = Si (FCKSM0 = 1), entonces las configuraciones de reloj y PLL están bloqueadas 
Si (FCKSM0 = 0), entonces las configuraciones de reloj y PLL pueden modificarse
0 = Las selecciones de reloj y PLL no están bloqueadas, las configuraciones pueden modificarse
poco 6
No implementado: leído como "0"
poco 5
LOCK: Bit de estado de bloqueo PLL (solo lectura) 
1 = Indica que PLL está bloqueado o que se ha cumplido el temporizador de inicio de PLL
0 = Indica que PLL está desbloqueado, el temporizador de inicio está en progreso o PLL está deshabilitado
poco 4
No implementado: leído como "0"
poco 3
CF: bit de detección de fallo de reloj (lectura/borrado por aplicación) 
1 = FSCM ha detectado una falla en el reloj
0 = FSCM no ha detectado falla de reloj
poco 2
No implementado: leído como "0"
Nota 1: Las escrituras en este registro requieren una secuencia de desbloqueo. Consulte la Sección 7. “Oscilador” (DS70186) en la
Consulte el “Manual de referencia de la familia dsPIC33F” (disponible en el sitio web de Microchip) para obtener más detalles.
2: No se permiten cambios de reloj directo entre cualquier modo de oscilador primario con modo PLL y FRCPLL.
Esto se aplica a los interruptores de reloj en cualquier dirección. En estos casos, la aplicación debe cambiar al modo FRC.
como fuente de reloj de transición entre los dos modos PLL.

© 2009 Microchip Technology Inc.
DS70286C-página 141
dsPIC33FJXXXGPX06/X08/X10
poco 1
LPOSCEN: bit de habilitación del oscilador secundario (LP)
1 = Habilitar oscilador secundario
0 = Desactivar oscilador secundario
poco 0
OSWEN: Bit de habilitación del interruptor del oscilador
1 = Solicitar cambio de oscilador a la selección especificada por los bits NOSC<2:0>
0 = El interruptor del oscilador está completo
REGÍSTRESE 9-1:
OSCCON: REGISTRO DE CONTROL DEL OSCILADOR(1) (CONTINUACIÓN)
Nota 1: Las escrituras en este registro requieren una secuencia de desbloqueo. Consulte la Sección 7. “Oscilador” (DS70186) en la
Consulte el “Manual de referencia de la familia dsPIC33F” (disponible en el sitio web de Microchip) para obtener más detalles.
2: No se permiten cambios de reloj directo entre cualquier modo de oscilador primario con modo PLL y FRCPLL.
Esto se aplica a los interruptores de reloj en cualquier dirección. En estos casos, la aplicación debe cambiar al modo FRC.
como fuente de reloj de transición entre los dos modos PLL.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 142
© 2009 Microchip Technology Inc.
     
REGISTRO 9-2:
CLKDIV: REGISTRO DIVISOR DE RELOJ
R/W-0
R/W-0
R/W-1
R/W-1
R/W-0
R/W-0
R/W-0
R/W-0
retorno de la inversión
DORMIR<2:0>
DOCE(1)
FRCDIV<2:0>
poco 15
poco 8
R/W-0
R/W-1
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
PLLPOST<1:0>
—
PLLPRE<4:0>
poco 7
poco 0
Leyenda:
y = Valor establecido desde los bits de configuración en POR
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
ROI: recuperarse en el bit de interrupción
1 = Las interrupciones borrarán el bit DOZEN y la relación de reloj del procesador/reloj periférico se establecerá en 1:1
0 = Las interrupciones no tienen efecto en el bit DOCENA
bits 14-12
DOZE<2:0>: Bits de selección de reducción del reloj del procesador
000 = FCY/1
001 = FCY/2
010 = FCY/4
011 = FCY/8 (predeterminado)
100 = FCY/16
101 = FCY/32
110 = FCY/64
111 = FCY/128
poco 11
DOZEN: Modo DOZE Bit de habilitación(1)
1 = DOZE<2:0> campo especifica la relación entre los relojes periféricos y los relojes del procesador
0 = Relación de reloj del procesador/reloj periférico forzada a 1:1
bits 10-8
FRCDIV<2:0>: Bits postescaladores del oscilador RC rápido interno
000 = FRC dividir por 1 (predeterminado)
001 = FRC dividir por 2
010 = FRC dividir por 4
011 = FRC dividir por 8
100 = FRC dividido por 16
101 = FRC dividido por 32
110 = FRC dividido por 64
111 = FRC dividido por 256
bits 7-6
PLLPOST<1:0>: Bits de selección del divisor de salida PLL VCO (también denominado 'N2', postescalador PLL)
00 = Salida/2 
01 = Salida/4 (predeterminado) 
10 = Reservado
11 = Salida/8 
poco 5
No implementado: leído como "0"
poco 4-0
PLLPRE<4:0>: Bits divisores de entrada del detector de fase PLL (también denominados 'N1', preescalador de PLL)
00000 = Entrada/2 (predeterminado)
00001 = Entrada/3
 •
 • 
 • 
11111 = Entrada/33
Nota 1: Este bit se borra cuando se establece el bit ROI y se produce una interrupción.

© 2009 Microchip Technology Inc.
DS70286C-página 143
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 9-3:
PLLFBD: REGISTRO DIVISOR DE COMENTARIOS DE PLL
U-0
U-0
U-0
U-0
U-0
U-0
U-0
R/W-0(1)
—
—
—
—
—
—
—
PLLDIV<8>
poco 15
poco 8
R/W-0
R/W-0
R/W-1
R/W-1
R/W-0
R/W-0
R/W-0
R/W-0
PLLDIV<7:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bit 15-9
No implementado: leído como "0"
poco 8-0
PLLDIV<8:0>: Bits divisores de retroalimentación de PLL (también denominados 'M', multiplicador de PLL)
000000000 = 2
000000001 = 3
000000010 = 4
•
•
•
000110000 = 50 (predeterminado)
•
•
•
111111111 = 513

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 144
© 2009 Microchip Technology Inc.
     
 
REGÍSTRESE 9-4:
OSCTUN: REGISTRO DE SINTONIZACIÓN DEL OSCILADOR FRC
U-0
U-0
U-0
U-0
U-0
U-0
U-0
U-0
—
—
—
—
—
—
—
—
poco 15
poco 8
U-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
—
—
SINTONIZAR<5:0>(1)
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bit 15-6
No implementado: leído como "0"
poco 5-0
TUN<5:0>: Bits de sintonización del oscilador FRC(1)
011111 = Frecuencia central + 11,625% (8,23 MHz)
011110 = Frecuencia central + 11,25% (8,20 MHz)
•  
•
•
000001 = Frecuencia central + 0,375% (7,40 MHz) 
000000 = Frecuencia central (7,37 MHz nominal)
111111 = Frecuencia central - 0,375% (7,345 MHz) 
•
•
•
100001 = Frecuencia central - 11,625% (6,52 MHz) 
100000 = Frecuencia central - 12% (6,49 MHz)
Nota 1: La funcionalidad OSCTUN se ha proporcionado para ayudar a los clientes a compensar los efectos de la temperatura en el
Frecuencia FRC en un amplio rango de temperaturas. El tamaño del paso de sintonización es una aproximación y no es ni
caracterizado ni probado.

© 2009 Microchip Technology Inc. 
DS70286C-página 145 
dsPIC33FJXXXGPX06/X08/X10 
9.2 
Operación de cambio de reloj 
Las aplicaciones son libres de cambiar entre cualquiera de los cuatro 
fuentes de reloj (primaria, LP, FRC y LPRC) en 
control del software en cualquier momento. Para limitar el posible lado 
efectos 
eso 
podría 
resultado 
de 
este 
flexibilidad, 
dsPIC33FJXXXGPX06/X08/X10 
dispositivos 
tener 
a 
Bloqueo de protección integrado en el proceso de conmutación. 
9.2.1 
HABILITAR EL CAMBIO DE RELOJ 
Para habilitar el cambio de reloj, la configuración FCKSM1 
El bit en el registro de configuración debe programarse para 
'0'. (Consulte la Sección 22.1 “Bits de configuración” para 
más detalles.) Si el bit de configuración FCKSM1 está 
sin programar (“1”), la función de cambio de reloj y 
La función Monitor de reloj a prueba de fallos está desactivada. Esto es 
la configuración predeterminada. 
Los bits de control NOSC (OSCCON<10:8>) no 
controlar la selección del reloj cuando el cambio de reloj está activado 
desactivado. Sin embargo, los bits COSC (OSCCON<14:12>) 
reflejar la fuente de reloj seleccionada por el FNOSC 
Bits de configuración. 
El bit de control OSWEN (OSCCON<0>) no tiene ningún efecto 
cuando el cambio de reloj está desactivado. Se mantiene en '0' en absoluto 
veces. 
9.2.2 
SECUENCIA DE CONMUTACIÓN DEL OSCILADOR 
Como mínimo, realizar un cambio de reloj requiere esto 
secuencia básica: 
1. 
Si 
deseado, 
leer 
el 
PREVENCIÓN 
bits 
(OSCCON<14:12>) para determinar la corriente 
fuente del oscilador. 
2. 
Realice la secuencia de desbloqueo para permitir una escritura en 
el byte alto del registro OSCCON. 
3. 
Escriba el valor apropiado en el control NOSC. 
bits (OSCCON<10:8>) para el nuevo oscilador 
fuente. 
4. 
Realice la secuencia de desbloqueo para permitir una escritura en 
el byte bajo del registro OSCCON. 
5. 
Establezca el bit OSWEN para iniciar el oscilador. 
cambiar. 
Una vez completada la secuencia básica, el sistema 
El hardware del reloj responde automáticamente de la siguiente manera: 
1. 
El hardware de conmutación del reloj compara el 
Bits de estado COSC con el nuevo valor del 
Bits de control NOSC. Si son iguales, entonces el 
El cambio de reloj es una operación redundante. en esto 
En este caso, el bit OSWEN se borra automáticamente. 
y se cancela el cambio de reloj. 
2. 
Si se ha iniciado un cambio de reloj válido, el 
CERRAR 
(OSCCON<5>) 
y 
el 
FQ 
(OSCCON<3>) los bits de estado se borran. 
3. 
El nuevo oscilador es activado por el hardware. 
si no se está ejecutando actualmente. Si un oscilador de cristal 
debe estar encendido, el hardware espera hasta que 
El temporizador de inicio del oscilador (OST) expira. si el 
nueva fuente está usando el PLL, el hardware espera 
hasta que se detecte un bloqueo de PLL (LOCK = 1). 
4. 
El hardware espera 10 ciclos de reloj desde el 
nueva fuente de reloj y luego realiza el reloj 
cambiar. 
5. 
El hardware borra el bit OSWEN para indicar una 
transición de reloj exitosa. Además, el NOSC 
Los valores de los bits se transfieren a los bits de estado del COSC. 
6. 
La fuente del reloj antiguo está apagada en este momento, 
con la excepción de LPRC (si WDT o FSCM 
están habilitados) o LP (si LPOSCEN permanece configurado). 
9.3 
Monitor de reloj a prueba de fallos (FSCM) 
El monitor de reloj a prueba de fallos (FSCM) permite al dispositivo 
seguir funcionando incluso en caso de oscilador 
falla. La función FSCM se habilita mediante programación. 
Si la función FSCM está habilitada, el LPRC interno 
El oscilador funciona en todo momento (excepto durante el modo de suspensión). 
y no está sujeto al control del temporizador de vigilancia. 
En caso de falla del oscilador, el FSCM 
genera un evento de trampa de falla del reloj y cambia el 
el reloj del sistema pasa al oscilador FRC. Entonces el 
El programa de aplicación puede intentar reiniciar el 
oscilador o ejecutar un apagado controlado. la trampa 
puede tratarse como un reinicio en caliente simplemente cargando el 
Restablezca la dirección en el vector de captura de falla del oscilador. 
Si el multiplicador PLL se utiliza para escalar el reloj del sistema, 
el FRC interno también se multiplica por el mismo factor 
en fallo del reloj. Básicamente, el dispositivo cambia a 
FRC con PLL en una falla de reloj. 
Nota: 
El modo de oscilador primario tiene tres diferentes 
submodos (XT, HS y EC) que son 
determinado 
por 
el 
POSCMD<1:0> 
Bits de configuración. Mientras que una aplicación 
puede cambiar hacia y desde el oscilador primario 
modo en el software, no puede cambiar 
entre los diferentes submodos primarios 
sin reprogramar el dispositivo. 
Nota 1: el procesador continúa ejecutando código 
durante toda la secuencia de conmutación del reloj. 
El código sensible al tiempo no debe ser 
ejecutado durante este tiempo. 
2: El reloj directo cambia entre cualquier primario 
modo oscilador con PLL y FRCPLL 
modo no están permitidos. Esto se aplica a 
el reloj cambia en cualquier dirección. En estos 
En algunos casos, la aplicación debe cambiar a 
Modo FRC como fuente de reloj de transición 
entre los dos modos PLL. 
3: referir 
a 
Sección 
7. 
"Oscilador" 
(DS70186) en la “familia dsPIC33F 
Manual de referencia” para obtener más detalles. 

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 146
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70286C-página 147
dsPIC33FJXXXGPX06/X08/X10
10.0
FUNCIONES DE AHORRO DE ENERGÍA
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 proporcionan
la capacidad de gestionar el consumo de energía selectivamente
gestionar el reloj de la CPU y los periféricos. en
En general, una frecuencia de reloj más baja y una reducción en el
El número de circuitos sincronizados constituye un menor
consumido 
poder. 
dsPIC33FJXXXGPX06/X08/X10
Los dispositivos pueden gestionar el consumo de energía en cuatro
diferentes maneras:
• Frecuencia del reloj
• Modos de suspensión e inactividad basados en instrucciones
• Modo Doze controlado por software
• Control selectivo de periféricos en software
Se pueden utilizar combinaciones de estos métodos para
adaptar selectivamente el consumo de energía de una aplicación
manteniendo al mismo tiempo las funciones críticas de la aplicación, como
como comunicaciones sensibles al tiempo.
10.1
Frecuencia de reloj y reloj 
Conmutación
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 permiten una amplia
rango de frecuencias de reloj que se seleccionarán en
control de aplicaciones. Si la configuración del reloj del sistema es
no 
bloqueado, 
usuarios 
puede 
elegir 
baja potencia 
o
osciladores de alta precisión simplemente cambiando el
Bits NOSC (OSCCON<10:8>). El proceso de
cambiar el reloj del sistema durante el funcionamiento, así como
Las limitaciones del proceso se analizan con más detalle.
en la Sección 9.0 “Configuración del oscilador”.
10.2
Ahorro de energía basado en instrucciones 
Modos
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 tienen dos
Modos especiales de ahorro de energía a los que se accede a través de
la ejecución de una instrucción especial PWRSAV. Dormir
El modo detiene el funcionamiento del reloj y detiene todo el código.
ejecución. El modo inactivo detiene la CPU y el código
ejecución, pero permite que los módulos periféricos continúen
operación. La sintaxis ensambladora del PWRSAV.
La instrucción se muestra en el ejemplo 10-1.
Los modos de suspensión e inactividad se pueden salir como resultado de una
interrupción habilitada, tiempo de espera WDT o reinicio del dispositivo. cuando
el dispositivo sale de estos modos, se dice que "se despierta".
10.2.1
MODO SUEÑO 
El modo de suspensión tiene estas características: 
• La fuente del reloj del sistema está apagada. si un 
Se utiliza el oscilador en chip, se apaga.
• El consumo de corriente del dispositivo se reduce a un 
mínimo, siempre que no haya ningún pin de E/S conectado 
actual.
• El monitor de reloj a prueba de fallos no funciona 
durante el modo de suspensión desde la fuente del reloj del sistema 
está deshabilitado.
• El reloj LPRC continúa funcionando en modo de suspensión si 
el WDT está habilitado.
• El WDT, si está habilitado, se borra automáticamente 
antes de ingresar al modo de suspensión. 
• Es posible que algunas funciones del dispositivo o periféricos continúen 
para operar en modo de suspensión. Esto incluye elementos tales 
como notificación de cambio de entrada en los puertos de E/S, o 
periféricos que utilizan una entrada de reloj externa. Cualquiera 
periférico que requiere la fuente de reloj del sistema para 
su funcionamiento está deshabilitado en modo Suspensión.
El dispositivo se reactivará del modo de suspensión en cualquiera de
estos eventos:
• Cualquier fuente de interrupción que esté habilitada individualmente.
• Cualquier forma de reinicio del dispositivo.
• Un tiempo de espera WDT.
Al salir de la suspensión, el procesador se reinicia con el
misma fuente de reloj que estaba activa cuando el modo de suspensión
fue ingresado. 
EJEMPLO 10-1:
SINTaxis DE INSTRUCCIONES PWRSAV
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 9.
“Temporizador de vigilancia y ahorro de energía
Modos” (DS70196) en el “dsPIC33F
Manual de referencia familiar”, que está disponible
capaz 
de 
el 
Microchip 
web 
sitio
(www.microchip.com).
Nota:
SLEEP_MODE e IDLE_MODE son
constantes definidas en el ensamblador
incluir archivo para el dispositivo seleccionado.
PWRSAV
#SLEEP_MODE
; Ponga el dispositivo en modo SLEEP
PWRSAV
#IDLE_MODE
; Ponga el dispositivo en modo IDLE

dsPIC33FJXXXGPX06/X08/X10 
DS70286C-página 148 
© 2009 Microchip Technology Inc. 
10.2.2 
MODO INACTIVO 
El modo inactivo tiene estas características: 
• La CPU deja de ejecutar instrucciones. 
• El WDT se borra automáticamente. 
• La fuente del reloj del sistema permanece activa. Por 
De forma predeterminada, todos los módulos periféricos continúan funcionando. 
normalmente desde la fuente del reloj del sistema, pero puede 
también puede desactivarse selectivamente (consulte la Sección 10.4 
“Desactivar módulo periférico”). 
• Si el WDT o FSCM está habilitado, el LPRC también 
permanece activo. 
El dispositivo se reactivará del modo inactivo en cualquiera de estos 
eventos: 
• Cualquier interrupción que esté habilitada individualmente. 
• Restablecer cualquier dispositivo. 
• Un tiempo de espera WDT. 
Al despertar desde el estado inactivo, el reloj se vuelve a aplicar a la CPU 
y la ejecución de la instrucción comienza inmediatamente, comenzando 
con la instrucción que sigue a la instrucción PWRSAV, o 
la primera instrucción en el ISR. 
10.2.3 
INTERRUPCIONES COINCIDENTES CON 
INSTRUCCIONES DE AHORRO DE ENERGÍA 
Cualquier interrupción que coincida con la ejecución de una 
La instrucción PWRSAV se retiene hasta que se entra en suspensión o 
Se completó el modo inactivo. Luego el dispositivo se despierta 
desde el modo de suspensión o inactivo. 
10.3 
Modo Dormir 
Generalmente, cambiar la velocidad del reloj e invocar uno de los 
Los modos de ahorro de energía son las estrategias preferidas para 
reduciendo 
fuerza 
consumo. 
Allá 
puede 
ser 
circunstancias, sin embargo, en las que esto no sea práctico. Para 
Por ejemplo, puede ser necesario que una solicitud 
mantener una comunicación sincrónica ininterrumpida, 
incluso cuando no hace nada más. Sistema reductor 
La velocidad del reloj puede introducir errores de comunicación, mientras que 
El uso de un modo de ahorro de energía puede detener las comunicaciones. 
completamente. 
El modo Doze es un método alternativo simple y efectivo 
para reducir el consumo de energía mientras el dispositivo aún está 
ejecutando código. En este modo, el reloj del sistema 
continúa operando desde la misma fuente y en el 
misma velocidad. Los módulos periféricos continúan siendo 
sincronizada a la misma velocidad, mientras que la velocidad del reloj de la CPU 
se reduce. Sincronización entre los dos relojes. 
dominios se mantiene, permitiendo que los periféricos 
acceder a los SFR mientras la CPU ejecuta código en un 
ritmo más lento. 
El modo Doze se habilita configurando el bit DOZEN (CLK- 
DIV<11>). La relación entre el reloj periférico y el central. 
La velocidad está determinada por los bits DOZE<2:0> (CLK- 
DIV<14:12>). Hay ocho configuraciones posibles, 
de 1:1 a 1:128, siendo 1:1 la configuración predeterminada. 
También es posible utilizar el modo Doze para seleccionar 
reducir 
fuerza 
consumo 
en 
impulsado por eventos 
aplicaciones. Esto permite funciones sensibles al reloj, 
como comunicaciones sincrónicas, para continuar 
sin interrupción mientras la CPU está inactiva, esperando 
algo para invocar una rutina de interrupción. Habilitando el 
retorno automático al funcionamiento de la CPU a máxima velocidad 
Las interrupciones se habilitan configurando el bit ROI (CLK- 
DIV<15>). De forma predeterminada, los eventos de interrupción no tienen ningún efecto. 
en funcionamiento en modo Doze. 
Por ejemplo, supongamos que el dispositivo está funcionando a 
20 MIPS y el módulo CAN ha sido configurado para 
500 kbps según la velocidad operativa de este dispositivo. si el 
El dispositivo ahora está colocado en modo Doze con un reloj. 
relación de frecuencia de 1:4, el módulo CAN continúa 
comunicarse a la velocidad de bits requerida de 500 kbps, pero 
La CPU ahora comienza a ejecutar instrucciones en un 
Frecuencia de 5 MIPS. 
10.4 
Desactivación del módulo periférico 
Los registros de desactivación del módulo periférico (PMD) 
proporcionar un método para desactivar un módulo periférico 
deteniendo todas las fuentes de reloj suministradas a ese módulo. 
Cuando un periférico se desactiva a través del PMD apropiado 
bit de control, el periférico está en una potencia mínima 
estado de consumo. Los registros de control y estado. 
asociados con el periférico también están deshabilitados, por lo que 
Las escrituras en esos registros no tendrán ningún efecto y se leerán. 
los valores no serán válidos. 
Un módulo periférico sólo está habilitado si tanto el 
El bit asociado en el registro PMD se borra y el 
El periférico es compatible con el dsPIC® DSC específico. 
variante. Si el periférico está presente en el dispositivo, es 
habilitado en el registro PMD de forma predeterminada. 
Nota: 
Si se establece un bit PMD, el correspondiente 
El módulo se desactiva después de un retraso de 1 
ciclo de instrucción. De manera similar, si un bit PMD es 
borrado, el módulo correspondiente es 
habilitado después de un retraso de 1 ciclo de instrucción 
(suponiendo que los registros de control del módulo 
ya están configurados para habilitar el módulo 
operación). 

© 2009 Microchip Technology Inc.
DS70286C-página 149
dsPIC33FJXXXGPX06/X08/X10
REGISTRO 10-1:
PMD1: MÓDULO PERIFÉRICO DESACTIVAR REGISTRO DE CONTROL 1
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
U-0
U-0
R/W-0
T5MD
T4MD
T3MD
T2MD
DM1
—
—
DCIMD
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
I2C1MD
U2MD
U1MD
SPI2MD
SPI1MD
C2MD
C1MD
AD1MD
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
T5MD: Bit de desactivación del módulo Timer5
1 = El módulo Timer5 está deshabilitado
0 = El módulo Timer5 está habilitado
poco 14
T4MD: Bit de desactivación del módulo Timer4
1 = El módulo Timer4 está deshabilitado
0 = El módulo Timer4 está habilitado
poco 13
T3MD: Bit de desactivación del módulo Timer3
1 = El módulo Timer3 está deshabilitado
0 = El módulo Timer3 está habilitado
poco 12
T2MD: Bit de desactivación del módulo Timer2
1 = El módulo Timer2 está deshabilitado
0 = El módulo Timer2 está habilitado
poco 11
T1MD: Bit de desactivación del módulo Timer1
1 = El módulo Timer1 está deshabilitado
0 = El módulo Timer1 está habilitado
bits 10-9
No implementado: leído como "0"
poco 8
DCIMD: Bit de desactivación del módulo DCI
1 = el módulo DCI está deshabilitado
0 = el módulo DCI está habilitado
poco 7
I2C1MD: Bit de desactivación del módulo I2C1
1 = el módulo I2C1 está deshabilitado
0 = el módulo I2C1 está habilitado
poco 6
U2MD: Bit de desactivación del módulo UART2
1 = el módulo UART2 está deshabilitado
0 = el módulo UART2 está habilitado
poco 5
U1MD: Bit de desactivación del módulo UART1
1 = el módulo UART1 está deshabilitado
0 = el módulo UART1 está habilitado
poco 4
SPI2MD: Bit de desactivación del módulo SPI2
1 = el módulo SPI2 está deshabilitado
0 = el módulo SPI2 está habilitado
poco 3
SPI1MD: Bit de desactivación del módulo SPI1
1 = el módulo SPI1 está deshabilitado
0 = el módulo SPI1 está habilitado
poco 2
C2MD: Bit de desactivación del módulo ECAN2
1 = el módulo ECAN2 está deshabilitado
0 = el módulo ECAN2 está habilitado

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 150
© 2009 Microchip Technology Inc.
poco 1
C1MD: Bit de desactivación del módulo ECAN2
1 = el módulo ECAN1 está deshabilitado
0 = el módulo ECAN1 está habilitado
poco 0
AD1MD: Bit de desactivación del módulo ADC1
1 = el módulo ADC1 está deshabilitado
0 = el módulo ADC1 está habilitado
REGISTRO 10-1:
PMD1: MÓDULO PERIFÉRICO DESACTIVAR REGISTRO DE CONTROL 1 (CONTINUACIÓN)

© 2009 Microchip Technology Inc.
DS70286C-página 151
dsPIC33FJXXXGPX06/X08/X10
REGISTRO 10-2:
PMD2: MÓDULO PERIFÉRICO DESACTIVAR REGISTRO DE CONTROL 2
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
IC8MD
IC7MD
IC6MD
IC5MD
IC4MD
IC3MD
IC2MD
IC1MD
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
OC8MD
OC7MD
OC6MD
OC5MD
OC4MD
OC3MD
OC2MD
OC1MD
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
IC8MD: bit de desactivación del módulo de captura de entrada 8
1 = El módulo de captura de entrada 8 está deshabilitado
0 = El módulo de captura de entrada 8 está habilitado
poco 14
IC7MD: bit de desactivación del módulo de captura de entrada 7
1 = El módulo de captura de entrada 7 está deshabilitado
0 = El módulo de captura de entrada 7 está habilitado
poco 13
IC6MD: Bit de desactivación del módulo de captura de entrada 6
1 = El módulo de captura de entrada 6 está deshabilitado
0 = El módulo de captura de entrada 6 está habilitado
poco 12
IC5MD: bit de desactivación del módulo de captura de entrada 5
1 = El módulo de captura de entrada 5 está deshabilitado
0 = El módulo de captura de entrada 5 está habilitado
poco 11
IC4MD: Bit de desactivación del módulo 4 de captura de entrada
1 = El módulo de captura de entrada 4 está deshabilitado
0 = El módulo de captura de entrada 4 está habilitado
poco 10
IC3MD: bit de desactivación del módulo de captura de entrada 3
1 = El módulo de captura de entrada 3 está deshabilitado
0 = El módulo de captura de entrada 3 está habilitado
poco 9
IC2MD: Bit de desactivación del módulo de captura de entrada 2
1 = El módulo de captura de entrada 2 está deshabilitado
0 = El módulo de captura de entrada 2 está habilitado
poco 8
IC1MD: Bit de desactivación del módulo de captura de entrada 1
1 = El módulo de captura de entrada 1 está deshabilitado
0 = El módulo de captura de entrada 1 está habilitado
poco 7
OC8MD: Bit de desactivación de 8 módulos de comparación de salida
1 = El módulo de comparación de salida 8 está deshabilitado
0 = El módulo de comparación de salida 8 está habilitado
poco 6
OC7MD: Bit de desactivación de 4 módulos de comparación de salida
1 = El módulo de comparación de salida 7 está deshabilitado
0 = El módulo de comparación de salida 7 está habilitado
poco 5
OC6MD: Bit de desactivación de 6 módulos de comparación de salida
1 = El módulo de comparación de salida 6 está deshabilitado
0 = El módulo de comparación de salida 6 está habilitado
poco 4
OC5MD: Bit de desactivación de 5 módulos de comparación de salida
1 = El módulo de comparación de salida 5 está deshabilitado
0 = El módulo de comparación de salida 5 está habilitado

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 152
© 2009 Microchip Technology Inc.
poco 3
OC4MD: Bit de desactivación de 4 módulos de comparación de salida
1 = El módulo de comparación de salida 4 está deshabilitado
0 = El módulo de comparación de salida 4 está habilitado
poco 2
OC3MD: Bit de desactivación de 3 módulos de comparación de salida
1 = El módulo de comparación de salida 3 está deshabilitado
0 = El módulo de comparación de salida 3 está habilitado
poco 1
OC2MD: Bit de desactivación de módulo de comparación de salida 2
1 = El módulo de comparación de salida 2 está deshabilitado
0 = El módulo de comparación de salida 2 está habilitado
poco 0
OC1MD: Bit de desactivación de módulo de comparación de salida 1
1 = Comparación de salida 1 módulo está deshabilitado
0 = Comparación de salida 1 módulo habilitado
REGISTRO 10-2:
PMD2: MÓDULO PERIFÉRICO DESACTIVAR REGISTRO DE CONTROL 2 (CONTINUACIÓN)

© 2009 Microchip Technology Inc.
DS70286C-página 153
dsPIC33FJXXXGPX06/X08/X10
REGISTRO 10-3:
PMD3: MÓDULO PERIFÉRICO DESACTIVAR REGISTRO DE CONTROL 3
R/W-0
R/W-0
R/W-0
R/W-0
U-0
U-0
U-0
U-0
T9MD
T8MD
T7MD
T6MD
—
—
—
—
poco 15
poco 8
U-0
U-0
U-0
U-0
U-0
U-0
R/W-0
R/W-0
—
—
—
—
—
—
I2C2MD
AD2MD
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
T9MD: Bit de desactivación del módulo Timer9
1 = El módulo Timer9 está deshabilitado
0 = El módulo Timer9 está habilitado
poco 14
T8MD: Bit de desactivación del módulo Timer8
1 = El módulo Timer8 está deshabilitado
0 = El módulo Timer8 está habilitado
poco 13
T7MD: Bit de desactivación del módulo Timer7
1 = El módulo Timer7 está deshabilitado
0 = El módulo Timer7 está habilitado
poco 12
T6MD: Bit de desactivación del módulo Timer6
1 = El módulo Timer6 está deshabilitado
0 = El módulo Timer6 está habilitado
bit 11-2
No implementado: leído como "0"
poco 1
I2C2MD: Bit de desactivación del módulo I2C2
1 = el módulo I2C2 está deshabilitado
0 = módulo I2C2 está habilitado
poco 0
AD2MD: Bit de desactivación del módulo AD2
1 = el módulo AD2 está deshabilitado
0 = módulo AD2 habilitado

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 154
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70286C-página 155
dsPIC33FJXXXGPX06/X08/X10
11.0
PUERTOS DE E/S
Todos los pines del dispositivo (excepto VDD, VSS, MCLR y
OSC1/CLKIN) se comparten entre los periféricos y
los puertos de E/S paralelos. Todos los puertos de entrada de E/S cuentan con Schmitt
Entradas de disparo para mejorar la inmunidad al ruido.
11.1
Puertos de E/S paralelas (PIO)
Un puerto de E/S paralelo que comparte un pin con un periférico es,
en general, subordinado a lo periférico. el
Los datos del buffer de salida del periférico y las señales de control son
proporcionado a un par de multiplexores. los multiplexores
seleccionar si el periférico o el puerto asociado
tiene propiedad de los datos de salida y señales de control de
el pin de E/S. La lógica también evita el “bucle”, en
que la salida digital de un puerto puede controlar la entrada de un
periférico que comparte el mismo pin. Figura 11-1 ilustra-
Trata cómo se comparten los puertos con otros periféricos y
el pin de E/S asociado al que están conectados. 
Cuando un periférico está habilitado y activa activamente un
pin asociado, el uso del pin como un propósito general
El pin de salida está deshabilitado. El pin de E/S puede leerse, pero el
El controlador de salida para el bit del puerto paralelo se desactivará. si
un periférico está habilitado, pero el periférico no está
impulsando activamente un pasador, ese pasador puede ser impulsado por un puerto.
Todos los pines de los puertos tienen tres registros directamente asociados.
con su funcionamiento como E/S digitales. La dirección de los datos.
registro (TRISx) determina si el pin es una entrada
o una salida. Si el bit de dirección de datos es un '1', entonces el pin
es una entrada. Todos los pines del puerto se definen como entradas después de un
Reiniciar. Lee desde el pestillo (LATx), lee el pestillo.
Escribe en el pestillo, escribe el pestillo. Lee desde el puerto
(PORTx), lee los pines del puerto, mientras escribe en el puerto
pines, escribe el pestillo.
Cualquier bit y sus datos y registros de control asociados.
que no sean válidos para un dispositivo en particular serán
discapacitado. Eso significa el LATx correspondiente y
TRISx se registra y los pines del puerto se leerán como ceros.
Cuando un pin se comparte con otro periférico o
función que se define sólo como entrada, es
Sin embargo, se considera un puerto exclusivo porque
no hay otra fuente de producción que compita. un
El ejemplo es el pin INT4.
FIGURA 11-1:
DIAGRAMA DE BLOQUES DE UNA ESTRUCTURA TÍPICA PORTUARIA COMPARTIDA 
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 10. “E/S
Puertos” (DS70193) en el “dsPIC33F
Manual de referencia familiar”, que está disponible
capaz 
de 
el 
Microchip 
web 
sitio
(www.microchip.com).
Nota:
El voltaje en un pin de entrada digital puede ser
entre -0,3 V y 5,6 V.
q
re
CK
WR LAT +
Pestillo TRIS
Pin de E/S
PUERTO WR
Autobús de datos
q
re
CK
Bloqueo de datos
Leer puerto
Leer TRIS
1
0
1
0
WR TRIS
Datos de salida periféricos
Habilitar salida
Datos de entrada periféricos
E/S
Módulo periférico
Habilitación de salida periférica
Módulo PIO
Multiplexores de salida
Datos de salida
Datos de entrada
Habilitación del módulo periférico
Leer LAT

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 156
© 2009 Microchip Technology Inc.
11.2
Configuración de drenaje abierto
Además de los registros PORT, LAT y TRIS para
control de datos, algunos pines de puerto también pueden ser individualmente
configurado para salida digital o de drenaje abierto. esto es
controlado por el registro de control de drenaje abierto, ODCx,
asociados a cada puerto. Configurando cualquiera de los bits
configura el pin correspondiente para que actúe como
salida de drenaje abierto. 
La característica de drenaje abierto permite la generación de
salidas superiores a VDD (por ejemplo, 5 V) en cualquier
pines solo digitales mediante el uso de resistencias pull-up externas. el
El voltaje máximo de drenaje abierto permitido es el mismo que el
la máxima especificación VIH.
Consulte "Diagramas de pines" para conocer los pines disponibles y sus
funcionalidad.
11.3
Configuración de pines de puertos analógicos
El uso de ADxPCFGH, ADxPCFGL y TRIS
Los registros controlan el funcionamiento de los pines del puerto ADC.
Los pines del puerto que se desean como entradas analógicas deben
tener su correspondiente bit TRIS configurado (entrada). si el
Se borra el bit TRIS (salida), el nivel de salida digital (VOH
o VOL) se convierte. 
Borrar cualquier bit en ADxPCFGH o ADxPCFGL
El registro configura el bit correspondiente para que sea un
pin analógico. Este es también el estado de reinicio de cualquier pin de E/S.
que tiene una función analógica (ANx) asociada. 
Al leer el registro PORT, todos los pines configurados como
Los canales de entrada analógica se leerán como borrados (un nivel bajo).
Los pines configurados como entradas digitales no convertirán un
entrada analógica. Niveles analógicos en cualquier pin que esté definido como
una entrada digital (incluidos los pines ANx) puede causar
buffer de entrada para consumir corriente que exceda el
especificaciones del dispositivo.
11.4
Temporización de escritura/lectura del puerto de E/S
Se requiere un ciclo de instrucción entre un puerto
operación de cambio de dirección o escritura de puerto y una lectura
explotación del mismo puerto. Normalmente, esta instrucción
sería un NOP.
11.5
Notificación de cambio de entrada
La función de notificación de cambio de entrada de los puertos de E/S
permite que los dispositivos dsPIC33FJXXXGPX06/X08/X10
generar solicitudes de interrupción al procesador en
respuesta a un cambio de estado en pines de entrada seleccionados.
esto 
característica 
es 
capaz 
de 
detectando 
entrada
cambios de estado incluso en modo de suspensión, cuando los relojes
están deshabilitados. Dependiendo del número de pines del dispositivo, hay
Hay hasta 24 señales externas (CN0 a CN23) que
Se puede seleccionar (habilitar) para generar una interrupción.
solicitud de cambio de estado.
Existen cuatro registros de control asociados a la CN
módulo. Los registros CNEN1 y CNEN2 contienen los
Bits de control de habilitación de interrupción CN (CNxIE) para cada uno de los
Pines de entrada CN. Configurar cualquiera de estos bits habilita un CN
interrupción para los pines correspondientes.
Cada pin CN también tiene un pull-up débil conectado.
Los pull-ups actúan como una fuente de corriente que se conecta
al pin y elimina la necesidad de resistencias externas
cuando se conectan dispositivos de pulsador o teclado.
Las dominadas se habilitan por separado usando el CNPU1
y registros CNPU2, que contienen el pull-up débil
bits de habilitación (CNxPUE) para cada uno de los pines CN. Configuración
cualquiera de los bits de control permite los pull-ups débiles para el
pines correspondientes.
EJEMPLO 11-1:
EJEMPLO DE ESCRITURA/LECTURA DE PUERTO
Nota:
En dispositivos con dos módulos ADC, si el
correspondiente 
PCFG 
poco 
en 
ya sea
AD1PCFGH(L) y AD2PCFGH(L) es
borrado, el pin se configura como un analógico
entrada.
Nota:
El voltaje en un pin de entrada analógica puede ser
entre -0,3V y (VDD + 0,3V).
Nota:
Pull-ups sobre pines de notificación de cambios
siempre debe estar desactivado cuando el
El pin del puerto está configurado como salida digital.
MOVIMIENTO
0xFF00, W0
; Configurar PORTB<15:8> como entradas
MOVIMIENTO
W0, TRISBB
; y PORTB<7:0> como salidas
NOP
; Retraso 1 ciclo
btss
PUERTO, #13
; Siguiente instrucción

© 2009 Microchip Technology Inc.
DS70286C-página 157
dsPIC33FJXXXGPX06/X08/X10
12.0
TEMPORIZADOR1
El módulo Timer1 es un temporizador de 16 bits, que puede servir
como contador de tiempo para el reloj de tiempo real, o operar
como temporizador/contador de intervalos de funcionamiento libre. Temporizador1 puede
operar en tres modos:
• Temporizador de 16 bits
• Contador síncrono de 16 bits
• Contador asíncrono de 16 bits
Timer1 también admite estas funciones:
• Operación de puerta con temporizador
• Configuraciones de preescalador seleccionables
• Operación del temporizador durante la CPU inactiva y en suspensión 
modos
• Interrupción en caso de coincidencia o caída del registro de período de 16 bits 
Borde de la señal de puerta externa.
La Figura 12-1 presenta un diagrama de bloques del sistema de 16 bits.
módulo temporizador.
Para configurar el Timer1 para su funcionamiento:
1.
Establezca el bit TON (= 1) en el registro T1CON.
2.
Seleccione la proporción del preescalador del temporizador usando el
TCKPS<1:0> bits en el registro T1CON.
3.
Configure los modos de reloj y puerta usando el TCS
y bits TGATE en el registro T1CON.
4.
Establezca o borre el bit TSYNC en T1CON para seleccionar
funcionamiento sincrónico o asincrónico.
5.
Cargue el valor del período del temporizador en el PR1
registrarse.
6.
Si se requieren interrupciones, configure la habilitación de interrupción
poco, T1IE. Utilice los bits de prioridad, T1IP<2:0>, para configurar
la prioridad de interrupción.
FIGURA 12-1:
DIAGRAMA DE BLOQUES DEL MÓDULO TIMER1 DE 16 BITS 
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 11.
“Temporizadores” (DS70205) en el “dsPIC33F
Manual de referencia familiar”, que es
disponible en el sitio web de Microchip
(www.microchip.com).
         
TONELADA 
SOSCI
SOSCO/
PR1
Establecer T1IF
igual
Comparador
 
TMR1
Reiniciar
SOSCEN
1
0
SINCRONIZACIÓN
q
q
re
CK
TCKPS<1:0>
Preescalador
1, 8, 64, 256
2
TGATE
TCY
1
0
T1CK
TCS
1x
01
TGATE
00
Sincronizar
Puerta
Sincronizar

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 158
© 2009 Microchip Technology Inc.
     
REGISTRO 12-1:
T1CON: REGISTRO DE CONTROL DEL TIMER1
R/W-0
U-0
R/W-0
U-0
U-0
U-0
U-0
U-0
TONELADA
—
TSIDL
—
—
—
—
—
poco 15
poco 8
U-0
R/W-0
R/W-0
R/W-0
U-0
R/W-0
R/W-0
U-0
—
 TGATE
TCKPS<1:0>
—
SINCRONIZACIÓN
TCS
—
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
TONELADA: Temporizador1 activado bit
1 = Inicia el temporizador 1 de 16 bits
0 = Detiene el temporizador 1 de 16 bits
poco 14
No implementado: leído como "0"
poco 13
TSIDL: bit de parada en modo inactivo
1 = Interrumpir la operación del módulo cuando el dispositivo ingresa al modo inactivo
0 = Continuar la operación del módulo en modo inactivo
bit 12-7
No implementado: leído como "0"
poco 6
TGATE: Bit de habilitación de acumulación de tiempo activado del temporizador 1
Cuando T1CS = 1: 
Este bit se ignora.
Cuando T1CS = 0: 
1 = Acumulación de tiempo activada
0 = Acumulación de tiempo de puerta deshabilitada
bit 5-4
TCKPS<1:0>: Bits de selección de preescala de reloj de entrada del temporizador 1
11 = 1:256 
10 = 1:64
01 = 1:8 
00 = 1:1
poco 3
No implementado: leído como "0"
poco 2
TSYNC: Bit de selección de sincronización de entrada de reloj externo del temporizador 1
Cuando TCS = 1: 
1 = Sincronizar entrada de reloj externo
0 = No sincronizar la entrada del reloj externo
Cuando TCS = 0: 
Este bit se ignora.
poco 1
TCS: Bit de selección de fuente de reloj del temporizador 1
1 = Reloj externo desde el pin T1CK (en el flanco ascendente) 
0 = Reloj interno (FCY)
poco 0
No implementado: leído como "0"

© 2009 Microchip Technology Inc. 
DS70286C-página 159 
dsPIC33FJXXXGPX06/X08/X10 
13.0 
TEMPORIZADOR2/3, TEMPORIZADOR4/5, TEMPORIZADOR6/7 
Y TEMPORIZADOR8/9 
El temporizador 2/3, el temporizador 4/5, el temporizador 6/7 y el temporizador 8/9 
Los módulos son temporizadores de 32 bits, que también pueden ser 
configurado como cuatro temporizadores independientes de 16 bits con 
Modos de funcionamiento seleccionables. 
Como temporizador de 32 bits, Timer2/3, Timer4/5, Timer6/7 y 
Timer8/9 funciona en tres modos: 
• Dos temporizadores independientes de 16 bits (por ejemplo, Timer2 y 
Timer3) con todos los modos de funcionamiento de 16 bits (excepto 
Modo contador asíncrono) 
• Temporizador único de 32 bits 
• Contador síncrono único de 32 bits 
También admiten estas características: 
• Operación de puerta con temporizador 
• Configuraciones de preescalador seleccionables 
• Operación del temporizador durante los modos inactivo y de suspensión 
• Interrumpir en una coincidencia de registro de período de 32 bits 
• Base de tiempo para captura de entrada y comparación de salida 
Módulos (solo Timer2 y Timer3) 
• Activador de evento ADC1 (sólo temporizador 2/3) 
• Activador de evento ADC2 (sólo Timer4/5) 
Individualmente, los ocho temporizadores de 16 bits pueden funcionar como 
Temporizadores o contadores síncronos. También ofrecen la 
características enumeradas anteriormente, excepto el activador de eventos; este 
se implementa sólo con Timer2/3. El operativo 
Los modos y funciones habilitadas se determinan configurando 
los bits apropiados en T2CON, T3CON, T4CON, 
T5CON, T6CON, T7CON, T8CON y T9CON 
registros. T2CON, T4CON, T6CON y T8CON son 
se muestra en forma genérica en el Registro 13-1. T3CON, 
T5CON, 
T7CON 
y 
T9CON 
son 
mostrado 
en 
Registro 13-2. 
Para operación de temporizador/contador de 32 bits, Timer2, Timer4, 
Timer6 o Timer8 es la palabra menos significativa; temporizador3, 
Timer5, Timer7 o Timer9 es la palabra más significativa 
de los temporizadores de 32 bits. 
Para configurar Timer2/3, Timer4/5, Timer6/7 o Timer8/9 
para funcionamiento de 32 bits: 
1. 
Configure el bit de control T32 correspondiente. 
2. 
Seleccione la relación del preescalador para Timer2, Timer4, 
Timer6 o Timer8 usando los bits TCKPS<1:0>. 
3. 
Configure los modos Reloj y Puerta usando el 
bits TCS y TGATE correspondientes. 
4. 
Cargue el valor del período del temporizador. PR3, PR5, PR7 o 
PR9 contiene la palabra más significativa del 
valor, mientras que PR2, PR4, PR6 o PR8 contiene el 
palabra menos significativa. 
5. 
Si se requieren interrupciones, configure la habilitación de interrupción 
bit, T3IE, T5IE, T7IE o T9IE. Usa la prioridad 
bits, T3IP<2:0>, T5IP<2:0>, T7IP<2:0> o 
T9IP<2:0>, para establecer la prioridad de interrupción. Mientras 
Timer2, Timer4, Timer6 o Timer8 controlan el 
temporizador, la interrupción aparece como Timer3, Timer5, 
Interrupción del Timer7 o Timer9. 
6. 
Establezca el bit TON correspondiente. 
El valor del temporizador en cualquier punto se almacena en el registro. 
par, TMR3:TMR2, TMR5:TMR4, TMR7:TMR6 o 
TMR9: TMR8. TMR3, TMR5, TMR7 o TMR9 siempre 
contiene la palabra más significativa del conteo, mientras que 
TMR2, TMR4, TMR6 o TMR8 contienen la menor cantidad 
palabra significativa. 
Para configurar cualquiera de los temporizadores para 16 bits individuales 
operación: 
1. 
Borre el bit T32 correspondiente a ese temporizador. 
2. 
Seleccione la proporción del preescalador del temporizador usando el 
TCKPS<1:0> bits. 
3. 
Configure los modos de reloj y puerta usando el TCS 
y bits TGATE. 
4. 
Cargue el valor del período del temporizador en el PRx 
registro. 
5. 
Si se requieren interrupciones, configure la habilitación de interrupción 
poco, TxIE. Utilice los bits de prioridad, TxIP<2:0>, para configurar 
la prioridad de interrupción. 
6. 
Establezca el bit TON. 
Un diagrama de bloques para un par de temporizadores de 32 bits (Timer4/5) 
El ejemplo se muestra en la Figura 13-1 y un temporizador (Timer4) 
El ejemplo de funcionamiento en modo de 16 bits se muestra en 
Figura 13-2. 
Nota: 
Esta hoja de datos resume las características 
del dsPIC33FJXXXGPX06/X08/X10 
familia de dispositivos. Sin embargo, no es 
pretende ser una referencia completa 
fuente. Para complementar la información en 
esta hoja de datos, consulte la Sección 11. 
“Temporizadores” (DS70205) en el “dsPIC33F 
Manual de referencia familiar”, que es 
disponible en el sitio web de Microchip 
(www.microchip.com). 
Nota: 
Para funcionamiento de 32 bits, T3CON, T5CON, 
Los bits de control T7CON y T9CON son 
ignorado. Sólo T2CON, T4CON, T6CON 
y los bits de control T8CON se utilizan para la configuración 
y controlar. Temporizador2, Temporizador4, Temporizador6 y 
Se utilizan entradas de puerta y reloj Timer8 
para los módulos de temporizador de 32 bits, pero un 
La interrupción se genera con el Timer3, 
Interrupción de Timer5, Ttimer7 y Timer9 
banderas. 
Nota: 
Sólo Timer2 y Timer3 pueden activar una 
Transferencia de datos DMA. 

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 160
© 2009 Microchip Technology Inc.
FIGURA 13-1:
DIAGRAMA DE BLOQUES DEL TEMPORIZADOR 2/3 (32 BITS) (1)
Establecer T3IF
igual
Comparador
PR3
PR2
Reiniciar
LSB
MSb
Nota
1:
El bit de control del temporizador de 32 bits, T32, debe configurarse para el funcionamiento del temporizador/contador de 32 bits. Todos los bits de control son respectivos. 
al registro T2CON.
2:
El activador de eventos ADC solo está disponible en Timer2/3.
Bus de datos<15:0>
TMR3HLD
Leer TMR2
Escribir TMR2
16
16
16
q
q
re
CK
TGATE
0
1
         
TONELADA
TCKPS<1:0>
2
TCY
TCS
1x
01
TGATE
00
T2CK
Activador de evento ADC(2)
Puerta
Sincronizar
Preescalador
1, 8, 64, 256
Sincronizar
TMR3
TMR2
16

© 2009 Microchip Technology Inc.
DS70286C-página 161
dsPIC33FJXXXGPX06/X08/X10
FIGURA 13-2:
DIAGRAMA DE BLOQUES DEL TIMER2 (16 BITS) 
         
TONELADA
TCKPS<1:0>
Preescalador
1, 8, 64, 256
2
TCY
TCS
TGATE
T2CK
PR2
Establecer T2IF
igual
Comparador
 
TMR2
Reiniciar
q
q
re
CK
TGATE
1
0
Puerta
Sincronizar
1x
01
00
Sincronizar

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 162
© 2009 Microchip Technology Inc.
     
REGISTRO 13-1:
REGISTRO DE CONTROL TxCON (T2CON, T4CON, T6CON O T8CON)
R/W-0
U-0
R/W-0
U-0
U-0
U-0
U-0
U-0
TONELADA
—
TSIDL
—
—
—
—
—
poco 15
poco 8
U-0
R/W-0
R/W-0
R/W-0
R/W-0
U-0
R/W-0
U-0
—
TGATE
TCKPS<1:0>
T32
—
TC(1)
—
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
TONELADA: Timerx activado bit
Cuando T32 = 1:
1 = Inicia el temporizador de 32 bitsx/y
0 = Detiene el temporizador de 32 bitsx/y
Cuando T32 = 0:
1 = Inicia el temporizador de 16 bitsx
0 = Detiene el temporizador de 16 bitsx
poco 14
No implementado: leído como "0"
poco 13
TSIDL: bit de parada en modo inactivo
1 = Interrumpir la operación del módulo cuando el dispositivo ingresa al modo inactivo
0 = Continuar la operación del módulo en modo inactivo
bit 12-7
No implementado: leído como "0"
poco 6
TGATE: bit de habilitación de acumulación de tiempo activado Timerx
Cuando TCS = 1: 
Este bit se ignora.
Cuando TCS = 0: 
1 = Acumulación de tiempo activada
0 = Acumulación de tiempo de puerta deshabilitada
bit 5-4
TCKPS<1:0>: Bits de selección de preescala de reloj de entrada Timerx
11 = 1:256 
10 = 1:64
01 = 1:8 
00 = 1:1
poco 3
T32: bit de selección de modo de temporizador de 32 bits
1 = Timerx y Timery forman un único temporizador de 32 bits
0 = Timerx y Timery actúan como dos temporizadores de 16 bits
poco 2
No implementado: leído como "0"
poco 1
TCS: Bit de selección de fuente de reloj Timerx (1)
1 = Reloj externo desde el pin TxCK (en el flanco ascendente) 
0 = Reloj interno (FCY)
poco 0
No implementado: leído como "0"
Nota 1: El pin TxCK no está disponible en todos los temporizadores. Consulte la sección "Diagramas de pines" para conocer los pines disponibles.

© 2009 Microchip Technology Inc.
DS70286C-página 163
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 13-2:
REGISTRO DE CONTROL TyCON (T3CON, T5CON, T7CON O T9CON)
R/W-0
U-0
R/W-0
U-0
U-0
U-0
U-0
U-0
TONELADA(1)
—
TSIDL(2)
—
—
—
—
—
poco 15
poco 8
U-0
R/W-0
R/W-0
R/W-0
U-0
U-0
R/W-0
U-0
—
PUERTA TG(1)
TCKPS<1:0>(1)
—
—
TC(1,3)
—
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
TON: Temporizador activado bit(1)
1 = Inicia el temporizador de 16 bits
0 = Detiene el temporizador de 16 bits
poco 14
No implementado: leído como "0"
poco 13
TSIDL: Detener en modo inactivo bit(2)
1 = Interrumpir la operación del módulo cuando el dispositivo ingresa al modo inactivo
0 = Continuar la operación del módulo en modo inactivo
bit 12-7
No implementado: leído como "0"
poco 6
TGATE: bit de habilitación de acumulación de tiempo activado por temporizador (1)
Cuando TCS = 1: 
Este bit se ignora.
Cuando TCS = 0: 
1 = Acumulación de tiempo activada
0 = Acumulación de tiempo de puerta deshabilitada
bit 5-4
TCKPS<1:0>: Bits de selección de preescala de reloj de entrada del temporizador 3 (1)
11 = 1:256 
10 = 1:64
01 = 1:8 
00 = 1:1
bit 3-2
No implementado: leído como "0"
poco 1
TCS: Bit de selección de fuente de reloj temporizador (1,3)
1 = Reloj externo del pin TyCK (en el flanco ascendente) 
0 = Reloj interno (FCY)
poco 0
No implementado: leído como "0"
Nota 1: Cuando la operación de 32 bits está habilitada (T2CON<3> = 1), estos bits no tienen ningún efecto en la operación del temporizador; todo el temporizador
Las funciones se configuran a través de T2CON.
2: Cuando se habilita la operación del temporizador de 32 bits (T32 = 1) en el registro de control del temporizador (TxCON<3>), el bit TSIDL
debe borrarse para operar el temporizador de 32 bits en modo inactivo.
3: El pin TyCK no está disponible en todos los temporizadores. Consulte la sección "Diagramas de pines" para conocer los pines disponibles.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 164
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70286C-página 165
dsPIC33FJXXXGPX06/X08/X10
14.0
CAPTURA DE ENTRADA
El módulo de captura de entrada es útil en aplicaciones.
que requieren medición de frecuencia (período) y pulso.
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 admiten
hasta ocho canales de captura de entrada. 
El módulo de captura de entrada captura el valor de 16 bits de
el registro de base de tiempo seleccionado cuando ocurre un evento
en el pin ICx. Los eventos que causan un evento de captura.
se enumeran a continuación en tres categorías:
1.
Modos de eventos de captura simple
-Capturar el valor del temporizador en cada flanco descendente de 
entrada en el pin ICx
-Capturar el valor del temporizador en cada flanco ascendente de 
entrada en el pin ICx
2.
Capture el valor del temporizador en cada flanco (ascendente y
cayendo)
3.
Modos de eventos de captura del preescalador
-Capturar el valor del temporizador en cada cuarto flanco ascendente 
de entrada en el pin ICx
-Capturar el valor del temporizador cada 16 ascendentes. 
borde de entrada en el pin ICx
Cada canal de captura de entrada puede seleccionar entre uno de
dos temporizadores de 16 bits (Timer2 o Timer3) para la base de tiempo.
El temporizador seleccionado puede utilizar un temporizador interno o
reloj externo.
Otras características operativas incluyen:
• Activación del dispositivo desde el pin de captura durante la CPU 
Modos de suspensión e inactividad
• Interrupción en evento de captura de entrada
• Búfer FIFO de 4 palabras para valores de captura
- Interrupción generada opcionalmente después de 1, 2, 3 o 
4 ubicaciones de buffer están llenas
• La captura de entrada también se puede utilizar para proporcionar 
fuentes adicionales de interrupciones externas
FIGURA 14-1:
DIAGRAMA DE BLOQUES DE CAPTURA DE ENTRADA 
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 12.
“Captura de entrada” (DS70198) en el
“Manual de referencia de la familia dsPIC33F”,
que está disponible en la web de Microchip
sitio (www.microchip.com).
Nota:
Solo IC1 e IC2 pueden activar datos DMA
transferencia. Si las transferencias de datos DMA son
necesario, se debe establecer el tamaño del búfer FIFO
a 1 (ICI<1:0> = 00).
ICxBUF 
Pasador ICx
ICM<2:0> (ICxCON<2:0>)
Seleccionar modo
3
1
0
Establecer bandera ICxIF
(en Registro IFSn)
TMRy TMRz
Lógica de detección de bordes
16
16
FIFO
R/E
Lógica
ICxI<1:0>
ICOV, ICBNE (ICxCON<4:3>)
ICxCON
interrumpir
Lógica
Autobús del sistema
Desde temporizadores de 16 bits
TICMR
(ICxCON<7>)
FIFO 
Preescalador
Contador
(1, 4, 16)
y
Sincronizador de reloj
Nota: Una 'x' en una señal, registro o nombre de bit indica el número del canal de captura.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 166
© 2009 Microchip Technology Inc.
14.1
Registros de captura de entrada
     
REGISTRO 14-1:
ICxCON: CAPTURA DE ENTRADA x REGISTRO DE CONTROL
U-0
U-0
R/W-0
U-0
U-0
U-0
U-0
U-0
—
—
ICSIDL
—
—
—
—
—
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R-0, HC
R-0, HC
R/W-0
R/W-0
R/W-0
TICMR(1)
ICI<1:0>
ICOV
ICBNE
MIC<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-14
No implementado: leído como "0"
poco 13
ICSIDL: parada del módulo de captura de entrada en bit de control inactivo 
1 = El módulo de captura de entrada se detendrá en el modo inactivo de la CPU
0 = El módulo de captura de entrada continuará funcionando en modo inactivo de la CPU
bits 12-8
No implementado: leído como "0"
poco 7
ICTMR: Bits de selección del temporizador de captura de entrada (1)
1 = El contenido de TMR2 se captura en el evento de captura
0 = El contenido de TMR3 se captura en el evento de captura.
bits 6-5
ICI<1:0>: seleccione el número de capturas por bits de interrupción
11 = Interrumpir cada cuarto evento de captura
10 = Interrumpir cada tercer evento de captura
01 = Interrumpir cada segundo evento de captura
00 = Interrumpir en cada evento de captura
poco 4
ICOV: Bit de indicador de estado de desbordamiento de captura de entrada (solo lectura)
1 = Se produjo un desbordamiento de captura de entrada
0 = No se produjo ningún desbordamiento de captura de entrada
poco 3
ICBNE: bit de estado vacío del búfer de captura de entrada (solo lectura)
1 = El búfer de captura de entrada no está vacío, se puede leer al menos un valor de captura más
0 = El búfer de captura de entrada está vacío
poco 2-0
ICM<2:0>: bits de selección del modo de captura de entrada
111 = La captura de entrada funciona como pin de interrupción solo cuando el dispositivo está en modo de suspensión o inactivo
(Solo detección de flanco ascendente, todos los demás bits de control no son aplicables).
110 = No utilizado (módulo deshabilitado)
101 = Modo de captura, cada 16.º flanco ascendente
100 = Modo de captura, cada 4º flanco ascendente
011 = Modo de captura, cada flanco ascendente
010 = Modo de captura, cada flanco descendente
001 = Modo de captura, cada borde (ascendente y descendente)
(Los bits ICI<1:0> no controlan la generación de interrupciones para este modo).
000 = Módulo de captura de entrada apagado
Nota 1: Las selecciones del temporizador pueden variar. Consulte la hoja de datos del dispositivo para obtener más detalles.

© 2009 Microchip Technology Inc.
DS70286C-página 167
dsPIC33FJXXXGPX06/X08/X10
15.0
COMPARACIÓN DE SALIDA
El módulo de comparación de salida puede seleccionar Timer2 o
Timer3 para su base de tiempo. El módulo compara el
valor del temporizador con el valor de uno o dos Comparar
registros dependiendo del modo de funcionamiento seleccionado.
El estado del pin de salida cambia cuando el temporizador
El valor coincide con el valor del registro de comparación. la salida
El módulo de comparación genera una única salida
pulso, o una secuencia de pulsos de salida, cambiando el
Estado del pin de salida en los eventos de comparación.
El módulo de comparación de salida también puede generar
interrupciones en eventos de comparación de partidos.
El módulo de comparación de salida tiene múltiples funciones
modos:
• Modo activo-bajo de un solo disparo
• Modo One-Shot activo-alto
• Modo de alternancia
• Modo One-Shot retrasado
• Modo de pulso continuo
• Modo PWM sin protección contra fallas
• Modo PWM con protección contra fallas
FIGURA 15-1:
DIAGRAMA DE BLOQUES DEL MÓDULO DE COMPARACIÓN DE SALIDA
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familias de dispositivos. No se pretende que sea
una fuente de referencia completa. a
complementar la información de estos datos
hoja, consulte la Sección 13. “Salida
Comparar” (DS70209) en el “dsPIC33F
Manual de referencia familiar”, que está disponible
capaz 
en 
el 
Microchip 
web 
sitio
(www.microchip.com).
 
OCxR(1)
Comparador
 
    
Salida
Lógica
OCM<2:0>
Habilitar salida
OCx(1)
Establecer bit de bandera
OCxIF(1)
OCxRS(1)
Seleccionar modo
3
0
1
 
    
OCTSEL
0
1
16
 16
OCFA
TMR2
TMR2
q
S
R
TMR3
TMR3
Rollover
Rollover
Nota 1:
 Una 'x' en una señal, registro o nombre de bit indica el número de canales de comparación de salida.
2:
El pin OCFA controla de OC1 a OC4. El pin OCFB controla de OC5 a OC8.
o
OCFB(2)

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 168
© 2009 Microchip Technology Inc.
15.1
Modos de comparación de salida
Configure los modos de comparación de salida configurando el
bits apropiados del modo de comparación de salida (OCM<2:0>) en
el registro de control de comparación de salida (OCxCON<2:0>).
La Tabla 15-1 enumera las diferentes configuraciones de bits para la salida
Comparar modos. La figura 15-2 ilustra el resultado.
comparar el funcionamiento de varios modos. el usuario
La aplicación debe desactivar el temporizador asociado cuando
escribir en los registros de control de comparación de salida para
evitar averías.
TABLA 15-1:
MODOS DE COMPARACIÓN DE SALIDA
FIGURA 15-2:
OPERACIÓN DE COMPARACIÓN DE SALIDA
Nota:
Consulte la Sección 13. “Comparación de resultados”
(DS70209) en la “Referencia de la familia dsPIC33F”.
Manual de referencia” para OCxR y OCxRS
restricciones de registro.
OCM<2:0>
Modo
Estado inicial del pin OCx
Generación de interrupciones OCx
000
Módulo deshabilitado
Controlado por registro GPIO
—
001
One-Shot activo-bajo
0
flanco ascendente de OCx 
010
One-Shot activo-alto
1
OCx flanco descendente
011
Alternar
La producción actual se mantiene
Borde ascendente y descendente de OCx
100
One-Shot retrasado
0
OCx flanco descendente
101
Pulso continuo
0
OCx flanco descendente
110
PWM sin protección contra fallas
'0', si OCxR es cero
'1', si OCxR es distinto de cero
Sin interrupción
111
PWM con protección contra fallas
'0', si OCxR es cero
'1', si OCxR es distinto de cero
Borde descendente de OCFA para OC1 a OC4
OCxRS
TMRy
OCxR
El temporizador se reinicia
Coincidencia de período
Pulso continuo
(OCM = 101)
PWM
(OCM = 110 o 111)
One-Shot activo-bajo
(OCM = 001)
One-Shot activo-alto
(OCM = 010)
Alternar
(OCM = 011)
One-Shot retrasado
(OCM = 100)
Comparación de salida 
Modo habilitado

© 2009 Microchip Technology Inc.
DS70286C-página 169
dsPIC33FJXXXGPX06/X08/X10
 
REGISTRO 15-1:
OCxCON: COMPARACIÓN DE SALIDA x REGISTRO DE CONTROL (x = 1, 2)
U-0
U-0
R/W-0
U-0
U-0
U-0
U-0
U-0
—
—
OCSIDL 
—
—
—
—
—
poco 15
poco 8
U-0
U-0
U-0
R-0, HC
R/W-0
R/W-0
R/W-0
R/W-0
—
—
—
OCFLT 
OCTSEL
OCM<2:0>
poco 7
poco 0
Leyenda:
HC = Bit borrable por hardware
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-14
No implementado: leído como "0"
poco 13
OCSIDL: detener la comparación de salida en el bit de control del modo inactivo 
1 = Comparación de salida x se detiene en el modo inactivo de la CPU
0 = Comparación de salida x continúa funcionando en modo inactivo de CPU
bit 12-5
No implementado: leído como "0"
poco 4
OCFLT: Bit de estado de condición de falla de PWM
1 = Se ha producido una condición de fallo de PWM (se borra solo en el hardware)
0 = No se ha producido ninguna condición de fallo de PWM (este bit solo se utiliza cuando OCM<2:0> = 111)
poco 3
OCTSEL: Bit de selección del temporizador de comparación de salida
1 = Timer3 es la fuente de reloj para Comparar x
0 = Timer2 es la fuente de reloj para Comparar x
poco 2-0
OCM<2:0>: Bits de selección del modo de comparación de salida
111 = Modo PWM en OCx, pin de falla habilitado
110 = Modo PWM en OCx, pin de falla deshabilitado
101 = Inicializa el pin OCx bajo, genera pulsos de salida continuos en el pin OCx
100 = Inicializa el pin OCx bajo, genera un pulso de salida único en el pin OCx
011 = Comparar evento alterna pin OCx
010 = Inicializar pin OCx alto, comparar las fuerzas del evento pin OCx bajo
001 = Inicializar pin OCx bajo, comparar las fuerzas del evento pin OCx alto 
000 = El canal de comparación de salida está deshabilitado

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 170
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70286C-página 171
dsPIC33FJXXXGPX06/X08/X10
16.0
PERIFÉRICO SERIE 
INTERFAZ (SPI)
El módulo de interfaz periférica serie (SPI) es un
Interfaz serial síncrona útil para comunicarse.
con otros dispositivos periféricos o microcontroladores. Estos
Los dispositivos periféricos pueden ser EEPROM en serie, cambio
registros, controladores de pantalla, ADC, etc. El módulo SPI es
compatible con SPI y SIOP de Motorola®.
Cada módulo SPI consta de un registro de desplazamiento de 16 bits,
SPIxSR (donde x = 1 o 2), utilizado para desplazar datos en y
salida y un registro de búfer, SPIxBUF. Un registro de control,
SPIxCON, configura el módulo. Además, un estado
El registro, SPIXSTAT, indica varias condiciones de estado.
La interfaz serie consta de 4 pines: SDIx (datos serie
entrada), SDOx (salida de datos en serie), SCKx (entrada de reloj de cambio
o salida) y SSx (selección de esclavo activo-bajo).
En el funcionamiento en modo Maestro, SCK es una salida de reloj, pero en
Modo esclavo, es una entrada de reloj.
FIGURA 16-1:
DIAGRAMA DE BLOQUES DEL MÓDULO SPI 
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 18.
“Serie 
periférico 
Interfaz 
(IPS)”
(DS70206) en la “Familia dsPIC33F
Manual de referencia”, que está disponible
de 
el 
Microchip 
web 
sitio
(www.microchip.com).
Nota:
En esta sección, los módulos SPI son
denominados juntos como SPIx, o por separado
como SPI1 y SPI2. Función especial
Los registros seguirán una notación similar. Para
Por ejemplo, SPIxCON se refiere al control
regístrese para el módulo SPI1 o SPI2.
Bus de datos interno
SDix
SDOx
SSx
SCKx
SPIxSR
poco 0
Control de cambios
Borde
Seleccionar
FCY
Primaria
1:1/4/16/64
Habilitar 
Preescalador
Sincronizar
SPIxBUF
controlar
Transferir
Transferir
Escribir SPIxBUF
Leer SPIxBUF
16
SPIxCON1<1:0>
SPIxCON1<4:2>
Reloj Maestro
Reloj
controlar
Secundaria
Preescalador
1:1 a 1:8
SPIxRXB
SPIxTXB

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 172
© 2009 Microchip Technology Inc.
    
REGISTRO 16-1:
SPIxSTAT: REGISTRO DE ESTADO Y CONTROL DE SPIx
R/W-0
U-0
R/W-0
U-0
U-0
U-0
U-0
U-0
ESPIEN
—
SPISIDL
—
—
—
—
—
poco 15
poco 8
U-0
R/C-0
U-0
U-0
U-0
U-0
R-0
R-0
—
ESPÍROV
—
—
—
—
SPITBF
ESPIRBF
poco 7
poco 0
Leyenda:
C = bit borrable
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
SPIEN: bit de habilitación SPIx
1 = Habilita el módulo y configura SCKx, SDOx, SDIx y SSx como pines del puerto serie
0 = Desactiva el módulo
poco 14
No implementado: leído como "0"
poco 13
SPISIDL: bit de parada en modo inactivo
1 = Interrumpir la operación del módulo cuando el dispositivo ingresa al modo inactivo
0 = Continuar la operación del módulo en modo inactivo
bit 12-7
No implementado: leído como "0"
poco 6
SPIROV: Recibir bit de bandera de desbordamiento
1 = Se recibe y descarta por completo un nuevo byte/palabra. El software del usuario no ha leído el 
datos anteriores en el registro SPIxBUF
0 = No se ha producido ningún desbordamiento
bit 5-2
No implementado: leído como "0"
poco 1
SPITBF: bit de estado completo del búfer de transmisión SPIx
1 = La transmisión aún no ha comenzado, SPIxTXB está lleno
0 = Transmisión iniciada, SPIxTXB está vacío
Se configura automáticamente en el hardware cuando la CPU escribe la ubicación de SPIxBUF, cargando SPIxTXB.
Se borra automáticamente en el hardware cuando el módulo SPIx transfiere datos de SPIxTXB a SPIxSR.
poco 0
SPIRBF: bit de estado completo del búfer de recepción SPIx
1 = Recepción completa, SPIxRXB está lleno
0 = La recepción no está completa, SPIxRXB está vacío
Se configura automáticamente en el hardware cuando SPIx transfiere datos de SPIxSR a SPIxRXB.
Se borra automáticamente en el hardware cuando el núcleo lee la ubicación de SPIxBUF y lee SPIxRXB.

© 2009 Microchip Technology Inc.
DS70286C-página 173
dsPIC33FJXXXGPX06/X08/X10
    
REGISTRO 16-2:
SPIXCON1: REGISTRO DE CONTROL SPIx 1
U-0
U-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
—
—
—
DISCO
DISSDO
MODO16
SMP
CKE(1)
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
SSEN(3)
CKP
MSTEN
SPRE<2:0>(2)
PPRE<1:0>(2)
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-13
No implementado: leído como "0"
poco 12
DISSCK: deshabilita el pin bit SCKx (solo modos SPI Master)
1 = El reloj SPI interno está deshabilitado, el pin funciona como E/S
0 = El reloj SPI interno está habilitado
poco 11
DISSDO: Desactivar el bit pin SDOx
1 = El módulo no utiliza el pin SDOx; El pin funciona como E/S.
0 = El pin SDOx está controlado por el módulo
poco 10
MODE16: Bit de selección de comunicación de palabra/byte
1 = La comunicación es a nivel de palabra (16 bits)
0 = La comunicación es de bytes (8 bits)
poco 9
SMP: bit de fase de muestra de entrada de datos SPIx
Modo maestro:
1 = Datos de entrada muestreados al final del tiempo de salida de datos
0 = Datos de entrada muestreados a mitad del tiempo de salida de datos
Modo esclavo:
SMP debe borrarse cuando se utiliza SPIx en modo esclavo.
poco 8
CKE: bit de selección de borde de reloj SPIx (1)
1 = Los datos de salida serie cambian al pasar del estado de reloj activo al estado de reloj inactivo (ver bit 6)
0 = Los datos de salida serie cambian en la transición del estado de reloj inactivo al estado de reloj activo (ver bit 6)
poco 7
SSEN: Bit de habilitación de selección de esclavo (modo esclavo)(3)
1 = pin SSx usado para el modo esclavo
0 = pin SSx no utilizado por el módulo. Pin controlado por la función del puerto
poco 6
CKP: bit de selección de polaridad del reloj
1 = El estado inactivo del reloj es de nivel alto; El estado activo es un nivel bajo.
0 = El estado inactivo del reloj es un nivel bajo; El estado activo es un nivel alto.
poco 5
MSTEN: Bit de habilitación del modo maestro
1 = modo maestro
0 = modo esclavo
Nota 1: El bit CKE no se utiliza en los modos SPI enmarcados. El usuario debe programar este bit en '0' para Enmarcado.
Modos SPI (FRMEN = 1).
2: No establezca los preescaladores primario y secundario en un valor de 1:1.
3: Este bit debe borrarse cuando FRMEN = 1.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 174
© 2009 Microchip Technology Inc.
bit 4-2
SPRE<2:0>: Bits de preescala secundaria (modo maestro)(2)
111 = Preescala secundaria 1:1
110 = Preescala secundaria 2:1
•
•
•
000 = Preescala secundaria 8:1
poco 1-0
PPRE<1:0>: Bits de preescala primarios (modo maestro)(2)
11 = Preescala primaria 1:1
10 = Preescala primaria 4:1
01 = Preescala primaria 16:1
00 = Preescala primaria 64:1
REGISTRO 16-2:
SPIXCON1: REGISTRO DE CONTROL SPIx 1 (CONTINUACIÓN)
Nota 1: El bit CKE no se utiliza en los modos SPI enmarcados. El usuario debe programar este bit en '0' para Enmarcado.
Modos SPI (FRMEN = 1).
2: No establezca los preescaladores primario y secundario en un valor de 1:1.
3: Este bit debe borrarse cuando FRMEN = 1.

© 2009 Microchip Technology Inc.
DS70286C-página 175
dsPIC33FJXXXGPX06/X08/X10
   
REGISTRO 16-3:
SPIxCON2: REGISTRO DE CONTROL SPIx 2
R/W-0
R/W-0
R/W-0
U-0
U-0
U-0
U-0
U-0
FRMEN
SPIFSD
FRMPOL
—
—
—
—
—
poco 15
poco 8
U-0
U-0
U-0
U-0
U-0
U-0
R/W-0
U-0
—
—
—
—
—
—
FRMDLY
—
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
FRMEN: Bit de soporte SPIx enmarcado
1 = Compatibilidad con SPIx enmarcado habilitado (pin SSx utilizado como entrada/salida de pulso de sincronización de cuadro)
0 = soporte SPIx enmarcado deshabilitado
poco 14
SPIFSD: bit de control de dirección de pulso de sincronización de trama
1 = Entrada de pulso de sincronización de cuadro (esclavo)
0 = Salida de pulso de sincronización de cuadro (maestro)
poco 13
FRMPOL: Bit de polaridad del pulso de sincronización de trama
1 = El pulso de sincronización de cuadro está activo-alto
0 = El pulso de sincronización de cuadro está activo-bajo
bit 12-2
No implementado: leído como "0"
poco 1
FRMDLY: Bit de selección de flanco de pulso de sincronización de trama
1 = El pulso de sincronización de trama coincide con el reloj del primer bit
0 = El pulso de sincronización de trama precede al reloj del primer bit
poco 0
No implementado: la aplicación del usuario no debe establecer este bit en "1"

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 176
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70286C-página 177
dsPIC33FJXXXGPX06/X08/X10
17.0
INTERINTEGRADOS 
CIRCUITO™ (I2C™)
El módulo de circuito interintegrado (I2C) proporciona
soporte completo de hardware tanto para Slave como para
Modos Multi-Master de la comunicación serie I2C
estándar, con una interfaz de 16 bits. 
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 tienen hasta
a dos módulos de interfaz I2C, denominados I2C1 y
I2C2. Cada módulo I2C tiene una interfaz de 2 pines: el SCLx
El pin es reloj y el pin SDAx son datos. 
Cada módulo I2C 'x' (x = 1 o 2) ofrece la siguiente clave
características:
• Interfaz I2C que admite tanto maestro como esclavo 
operación.
• El modo esclavo I2C admite direcciones de 7 y 10 bits.
• El modo Maestro I2C admite direcciones de 7 y 10 bits.
• El puerto I2C permite transferencias bidireccionales entre 
amo y esclavos.
• Se puede sincronizar el reloj en serie para el puerto I2C. 
utilizado como mecanismo de apretón de manos para suspender y 
reanudar la transferencia en serie (control SCLREL).
• I2C admite operación multimaestro; detecta autobús 
colisión y arbitrará en consecuencia.
17.1
Modos de funcionamiento
El hardware implementa completamente todas las funciones maestras y esclavas.
funciones del modo estándar y rápido I2C
especificaciones, así como direccionamiento de 7 y 10 bits.
El módulo I2C puede funcionar como esclavo o como
maestro en un bus I2C.
Se admiten los siguientes tipos de operación I2C:
• Operación esclava I2C con dirección de 7 bits
• Operación esclava I2C con dirección de 10 bits
• Operación maestra I2C con dirección de 7 o 10 bits
Para obtener detalles sobre la secuencia de comunicación en cada
de estos modos, consulte la “Familia dsPIC33F
Manual de referencia”.
17.2
Registros I2C
I2CxCON e I2CxSTAT son control y estado
registros, respectivamente. El registro I2CxCON es
legible y escribible. Los seis bits inferiores de I2CxSTAT
son de solo lectura. Los bits restantes del I2CSTAT son
leer/escribir.
I2CxRSR es el registro de desplazamiento utilizado para cambiar datos,
mientras que I2CxRCV es el registro de búfer al que se envían los datos.
se escriben bytes o del cual se leen bytes de datos.
I2CxRCV es el búfer de recepción. I2CxTRN es la transmisión
Registro en el que se escriben los bytes durante una transmisión.
operación.
El registro I2CxADD contiene la dirección del esclavo. un
El bit de estado, ADD10, indica el modo de dirección de 10 bits. el
I2CxBRG actúa como generador de velocidad en baudios (BRG)
valor de recarga. 
En operaciones de recepción, I2CxRSR e I2CxRCV juntos
formar un receptor de doble buffer. Cuando I2CxRSR
recibe un byte completo, se transfiere a I2CxRCV
y se genera un pulso de interrupción. 
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 19.
“Interintegrado 
Circuito™ 
(I2C™)”
(DS70195) en la “familia dsPIC33F
Manual de referencia”, que está disponible
de 
el 
Microchip 
web 
sitio
(www.microchip.com).

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 178
© 2009 Microchip Technology Inc.
FIGURA 17-1:
DIAGRAMA DE BLOQUES I2C™ (X = 1 O 2) 
Interno
Autobús de datos
SCLx
SDax
turno
Detección de coincidencias
I2CxADD
Iniciar y detener
Detección de bits
Reloj
Coincidencia de direcciones
Reloj
Estiramiento
I2CxTRN
LSB
Reloj de turno
Contador inferior BRG
recargar
controlar
TCY/2
Iniciar y detener
Generación de bits
Reconocer
Generación
colisión
detectar
I2CxCON
I2CxSTAT
Lógica de control
leer
LSB
escribir
leer
I2CxBRG
I2CxRSR
escribir
leer
escribir
leer
escribir
leer
escribir
leer
escribir
leer
I2CxMSK
I2CxRCV

© 2009 Microchip Technology Inc.
DS70286C-página 179
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 17-1:
I2CxCON: REGISTRO DE CONTROL I2Cx
R/W-0
U-0
R/W-0
R/W-1HC
R/W-0
R/W-0
R/W-0
R/W-0
I2CEN
—
I2CSIDL
ESCLREL
IPMIEN
A10M
DISSLW
SMEN
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0HC
R/W-0HC
R/W-0HC
R/W-0HC
R/W-0HC
GCEN
ESTRENAR
ACKDT
ACEN
RCEN
BOLÍGRAFO
RSEN
SEN
poco 7
poco 0
Leyenda:
U = Bit no implementado, leído como '0'
R = bit legible
W = bit grabable
HS = Montado en hardware
HC = Borrado en hardware
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
I2CEN: bit de habilitación I2Cx 
1 = Habilita el módulo I2Cx y configura los pines SDAx y SCLx como pines del puerto serie
0 = Desactiva el módulo I2Cx. Todos los pines I2C están controlados por funciones de puerto
poco 14
No implementado: leído como "0"
poco 13
I2CSIDL: bit de parada en modo inactivo
1 = Interrumpir el funcionamiento del módulo cuando el dispositivo entra en modo inactivo
0 = Continuar la operación del módulo en modo inactivo
poco 12
SCLREL: bit de control de liberación SCLx (cuando se opera como esclavo I2C)
1 = Liberar reloj SCLx
0 = Mantener el reloj SCLx bajo (estiramiento del reloj)
Si ESTRÉN = 1: 
El bit es R/W (es decir, el software puede escribir '0' para iniciar la extensión y escribir '1' para liberar el reloj). Borrar hardware
al comienzo de la transmisión esclava. Hardware limpio al final de la recepción del esclavo.
Si ESTRÉN = 0: 
El bit es R/S (es decir, el software sólo puede escribir "1" para liberar el reloj). Hardware limpio al comienzo del esclavo
transmisión.
poco 11
IPMIEN: Bit de habilitación de interfaz de gestión de periféricos inteligentes (IPMI)
1 = el modo IPMI está habilitado; todas las direcciones reconocidas
0 = modo IPMI deshabilitado
poco 10
A10M: bit de dirección esclava de 10 bits
1 = I2CxADD es una dirección esclava de 10 bits
0 = I2CxADD es una dirección esclava de 7 bits
poco 9
DISSLW: Desactivar el bit de control de velocidad de giro
1 = Control de velocidad de giro deshabilitado
0 = Control de velocidad de giro habilitado
poco 8
SMEN: bit de niveles de entrada SMBus
1 = Habilitar umbrales de pines de E/S que cumplan con la especificación SMBus
0 = Desactivar umbrales de entrada SMBus
poco 7
GCEN: bit de habilitación de llamada general (cuando se opera como esclavo I2C)
1 = Habilitar interrupción cuando se recibe una dirección de llamada general en el I2CxRSR
(el módulo está habilitado para recepción)
0 = Dirección de llamada general deshabilitada
poco 6
STREN: Bit de habilitación de extensión de reloj SCLx (cuando se opera como esclavo I2C)
Se utiliza junto con la broca SCLREL.
1 = Habilitar software o recibir ampliación de reloj
0 = Desactivar software o recibir ampliación de reloj

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 180
© 2009 Microchip Technology Inc.
poco 5
ACKDT: bit de confirmación de datos (cuando se opera como maestro I2C, aplicable durante la recepción maestra)
Valor que se transmitirá cuando el software inicie una secuencia de Reconocimiento.
1 = Enviar NACK durante el reconocimiento
0 = Enviar ACK durante el reconocimiento
poco 4
ACKEN: Bit de habilitación de secuencia de reconocimiento 
(cuando se opera como maestro I2C, aplicable durante la recepción maestra)
1 = Iniciar secuencia de reconocimiento en los pines SDAx y SCLx y transmitir el bit de datos ACKDT. 
Hardware limpio al final de la secuencia de reconocimiento maestro
0 = Secuencia de reconocimiento no en progreso
poco 3
RCEN: recibir bit de habilitación (cuando se opera como maestro I2C)
1 = Habilita el modo de recepción para I2C. Borrado de hardware al final del octavo bit del byte de datos de recepción maestro
0 = Recibir secuencia no en progreso
poco 2
PEN: Bit de habilitación de condición de parada (cuando se opera como maestro I2C)
1 = Iniciar condición de parada en los pines SDAx y SCLx. Hardware borrado al final de la secuencia de parada maestra
0 = Condición de parada no en progreso
poco 1
RSEN: Bit de habilitación de condición de inicio repetido (cuando se opera como maestro I2C)
1 = Iniciar condición de inicio repetido en los pines SDAx y SCLx. Hardware limpio al final de 
Secuencia de inicio repetida maestra
0 = Condición de inicio repetido no en progreso
poco 0
SEN: Bit de habilitación de condición de inicio (cuando se opera como maestro I2C)
1 = Iniciar condición de inicio en los pines SDAx y SCLx. Hardware borrado al final de la secuencia de inicio maestra
0 = Condición de inicio no en progreso
REGISTRO 17-1:
I2CxCON: REGISTRO DE CONTROL I2Cx (CONTINUACIÓN)

© 2009 Microchip Technology Inc.
DS70286C-página 181
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 17-2:
I2CxSTAT: REGISTRO DE ESTADO I2Cx
R-0 HSC
R-0 HSC
U-0
U-0
U-0
R/C-0 SA
R-0 HSC
R-0 HSC
ACKSTAT
TRSTAT
—
—
—
BCL
GCSTAT
AGREGAR10
poco 15
poco 8
R/C-0 SA
R/C-0 SA
R-0 HSC
R/C-0 HSC
R/C-0 HSC
R-0 HSC
R-0 HSC
R-0 HSC
IWCOL
I2COV
D_A
pag
S
R_W
FBR
TBF
poco 7
poco 0
Leyenda:
U = Bit no implementado, leído como '0'
       C = Borrar solo bit
R = bit legible
W = bit grabable
HS = Montado en hardware
HSC = Hardware configurado/borrado
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
ACKSTAT: bit de estado de confirmación 
(cuando se opera como maestro I2C, aplicable a la operación de transmisión maestra)
1 = NACK recibido del esclavo
0 = ACK recibido del esclavo
Hardware configurado o borrado al final del reconocimiento esclavo.
poco 14
TRSTAT: bit de estado de transmisión (cuando se opera como maestro I2C, aplicable a la operación de transmisión maestra)
1 = La transmisión maestra está en progreso (8 bits + ACK)
0 = La transmisión maestra no está en progreso
Hardware configurado al comienzo de la transmisión maestra. Hardware limpio al final del reconocimiento esclavo.
bits 13-11
No implementado: leído como "0"
poco 10
BCL: bit de detección de colisión del bus maestro
1 = Se ha detectado una colisión de bus durante una operación maestra
0 = Sin colisión
Hardware configurado en la detección de colisión de autobús.
poco 9
GCSTAT: bit de estado de llamada general
1 = Se recibió la dirección de llamada general
0 = No se recibió la dirección de llamada general
Hardware configurado cuando la dirección coincide con la dirección de llamada general. Hardware limpio al detener la detección.
poco 8
ADD10: bit de estado de dirección de 10 bits
1 = la dirección de 10 bits coincidió
0 = la dirección de 10 bits no coincidió
Hardware configurado en la coincidencia del segundo byte de la dirección de 10 bits coincidente. Hardware limpio al detener la detección.
poco 7
IWCOL: escribir bit de detección de colisión
1 = Falló un intento de escribir el registro I2CxTRN porque el módulo I2C está ocupado 
0 = Sin colisión
Hardware configurado cuando ocurre una escritura en I2CxTRN mientras está ocupado (borrado por software).
poco 6
I2COV: Recibir bit de bandera de desbordamiento
1 = Se recibió un byte mientras el registro I2CxRCV todavía contiene el byte anterior
0 = Sin desbordamiento
Hardware configurado al intentar transferir I2CxRSR a I2CxRCV (borrado por software).
poco 5
D_A: bit de datos/dirección (cuando se opera como esclavo I2C)
1 = Indica que el último byte recibido fue de datos
0 = Indica que el último byte recibido fue la dirección del dispositivo
Hardware borrado al coincidir la dirección del dispositivo. Hardware configurado por la recepción del byte esclavo.
poco 4
P: bit de parada 
1 = Indica que se ha detectado un bit de parada por última vez
0 = El bit de parada no se detectó por última vez
El hardware se configura o se borra cuando se detecta inicio, inicio repetido o parada.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 182
© 2009 Microchip Technology Inc.
poco 3
S: bit de inicio 
1 = Indica que se ha detectado por última vez un bit de inicio (o inicio repetido)
0 = El bit de inicio no se detectó por última vez
El hardware se configura o se borra cuando se detecta inicio, inicio repetido o parada.
poco 2
R_W: bit de información de lectura/escritura (cuando se opera como esclavo I2C)
1 = Lectura: indica que la transferencia de datos se realiza desde el esclavo
0 = Escritura: indica que la transferencia de datos se ingresa al esclavo
Hardware configurado o borrado después de la recepción del byte de dirección del dispositivo I2C.
poco 1
RBF: bit de estado completo del búfer de recepción 
1 = Recepción completa, I2CxRCV está lleno
0 = Recepción no completa, I2CxRCV está vacío
Hardware configurado cuando I2CxRCV se escribe con el byte recibido. Hardware claro cuando software 
lee I2CxRCV.
poco 0
TBF: bit de estado completo del búfer de transmisión
1 = Transmisión en curso, I2CxTRN está lleno
0 = Transmisión completa, I2CxTRN está vacío
Hardware configurado cuando el software escribe I2CxTRN. Hardware limpio al finalizar la transmisión de datos.
REGISTRO 17-2:
I2CxSTAT: REGISTRO DE ESTADO I2Cx (CONTINUACIÓN)

© 2009 Microchip Technology Inc.
DS70286C-página 183
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 17-3:
I2CxMSK: REGISTRO DE MÁSCARA DE DIRECCIÓN DEL MODO ESCLAVO I2Cx
U-0
U-0
U-0
U-0
U-0
U-0
R/W-0
R/W-0
—
—
—
—
—
—
AMSK9
AMSK8
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
AMSK7
AMSK6
AMSK5
AMSK4
AMSK3
AMSK2
AMSK1
AMSK0
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-10
No implementado: leído como "0"
poco 9-0
AMSKx: Máscara para bit de dirección x bit de selección
1 = Habilitar enmascaramiento para el bit x de la dirección del mensaje entrante; No se requiere coincidencia de bits en esta posición
0 = Deshabilitar el enmascaramiento para el bit x; Se requiere coincidencia de bits en esta posición

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 184
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70286C-página 185
dsPIC33FJXXXGPX06/X08/X10
18.0
UNIVERSAL ASÍNCRONO 
TRANSMISOR RECEPTOR 
(UART)
El transmisor receptor asíncrono universal
El módulo (UART) es uno de los módulos de E/S serie
disponible 
en 
el 
dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. El UART es un sistema asíncrono full-duplex.
sistema que puede comunicarse con dispositivos periféricos,
como ordenadores personales, LIN, RS-232 y RS-485
interfaces. El módulo también admite un flujo de hardware.
opción de control con los pines UxCTS y UxRTS y
También incluye un codificador y decodificador IrDA®.
Las características principales del módulo UART son:
• Transmisión de datos Full-Duplex, de 8 o 9 bits a través de 
los pines UxTX y UxRX
• Opciones de paridad par, impar o sin paridad (para datos de 8 bits)
• Uno o dos bits de parada
• Opción de control de flujo de hardware con UxCTS y 
Pines UxRTS
• Generador de velocidad en baudios totalmente integrado con 16 bits 
Preescalador
• Velocidades de baudios que van desde 1 Mbps a 15 bps a 16x 
modo a 40 MIPS
• Velocidades de baudios que van desde 4 Mbps a 61 bps en modo 4x 
a 40 MIPS
• Transmisión de datos de 4 profundidades, primero en entrar, primero en salir (FIFO) 
búfer
• Búfer de recepción de datos FIFO de 4 profundidades
• Detección de errores de paridad, encuadre y desbordamiento del búfer
• Compatibilidad con el modo de 9 bits con detección de dirección 
(noveno bit = 1)
• Transmitir y recibir interrupciones
• Una interrupción separada para todas las condiciones de error de UART
• Modo loopback para soporte de diagnóstico
• Soporte para sincronizar y romper personajes
• Admite detección automática de velocidad en baudios
• Lógica de codificador y decodificador IrDA®
• Salida de reloj de 16x baudios para compatibilidad con IrDA®
En la figura se muestra un diagrama de bloques simplificado de la UART.
Figura 18-1. El módulo UART consta de la clave
elementos de hardware importantes:
• Generador de velocidad en baudios
• Transmisor asíncrono
• Receptor asíncrono
FIGURA 18-1:
DIAGRAMA DE BLOQUES SIMPLIFICADO UART 
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 17.
“UART” (DS70188) en el “dsPIC33F
Manual de referencia familiar”, que es
disponible en el sitio web de Microchip
(www.microchip.com).
Nota 1: Tanto UART1 como UART2 pueden desencadenar una transferencia de datos DMA. Si se selecciona U1TX, U1RX, U2TX o U2RX como
una fuente DMA IRQ, se produce una transferencia DMA cuando el bit U1TXIF, U1RXIF, U2TXIF o U2RXIF se establece como
como resultado de una transmisión o recepción UART1 o UART2. 
2: Si se requieren transferencias DMA, el búfer UART TX/RX FIFO debe configurarse en un tamaño de 1 byte/palabra (es decir,
UTXISEL<1:0> = 00 y URXISEL<1:0> = 00).
Ux RX
Control de flujo de hardware
Receptor UART
Transmisor UART
UxTX
BCLK
Generador de velocidad de baudios
UxRTS
IrDA®
UxCTS

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 186
© 2009 Microchip Technology Inc.
     
REGISTRO 18-1:
UxMODE: REGISTRO DE MODO UARTx
R/W-0
U-0
R/W-0
R/W-0
R/W-0
U-0
R/W-0
R/W-0
UARTEN(1)
—
USIDL
IREN(2)
RTSMD
—
UES<1:0>
poco 15
poco 8
R/W-0HC
R/W-0
R/W-0HC
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
DESPERTAR
LPBACK
ABAUD
URXINV
BRGH
PDSEL<1:0>
STSEL
poco 7
poco 0
Leyenda:
HC = Hardware borrado
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
UARTEN: bit de habilitación UARTx (1)
1 = UARTx está habilitado; todos los pines UARTx están controlados por UARTx según lo definido por UEN<1:0>
0 = UARTx está deshabilitado; todos los pines UARTx están controlados por pestillos de puerto; Consumo de energía UARTx 
mínimo
poco 14
No implementado: leído como "0"
poco 13
USIDL: bit de parada en modo inactivo
1 = Interrumpir la operación del módulo cuando el dispositivo ingresa al modo inactivo
0 = Continuar la operación del módulo en modo inactivo
poco 12
IREN: Bit de habilitación del codificador y decodificador IrDA® (2)
1 = Codificador y decodificador IrDA® habilitados
0 = Codificador y decodificador IrDA® deshabilitados
poco 11
RTSMD: Selección de modo para el bit Pin UxRTS
1 = pin UxRTS en modo Simplex
0 = pin UxRTS en modo Control de flujo
poco 10
No implementado: leído como "0"
bits 9-8
UEN<1:0>: bits de habilitación UARTx 
11 = Los pines UxTX, UxRX y BCLK están habilitados y utilizados; Pin UxCTS controlado por pestillos de puerto
10 = Los pines UxTX, UxRX, UxCTS y UxRTS están habilitados y utilizados
01 = Los pines UxTX, UxRX y UxRTS están habilitados y utilizados; Pin UxCTS controlado por pestillos de puerto
00 = Los pines UxTX y UxRX están habilitados y utilizados; Pines UxCTS y UxRTS/BCLK controlados por 
 pestillos de puerto
poco 7
WAKE: Despertar al iniciar bit Detectar durante el modo de suspensión Bit de habilitación
1 = UARTx continuará muestreando el pin UxRX; interrupción generada en el flanco descendente; poco despejado 
en hardware en el siguiente flanco ascendente
0 = No hay despertador habilitado
poco 6
LPBACK: Bit de selección del modo de bucle invertido UARTx
1 = Habilitar el modo Loopback
0 = El modo loopback está deshabilitado
poco 5
ABAUD: Bit de habilitación de auto-baudios
1 = Habilitar la medición de la velocidad en baudios en el siguiente carácter; requiere la recepción de un campo de sincronización (55 h)
antes que otros datos; borrado en el hardware al finalizar
0 = Medición de velocidad en baudios deshabilitada o completada
Nota 1: Consulte la Sección 17. “UART” (DS70188) en el “Manual de referencia de la familia dsPIC33F” para obtener información sobre
habilitando el módulo UART para la operación de recepción o transmisión.
2: Esta función solo está disponible para el modo BRG 16x (BRGH = 0).

© 2009 Microchip Technology Inc.
DS70286C-página 187
dsPIC33FJXXXGPX06/X08/X10
poco 4
URXINV: Recibir bit de inversión de polaridad 
1 = El estado inactivo de UxRX es '0'
0 = El estado inactivo de UxRX es '1'
poco 3
BRGH: bit de habilitación de alta velocidad en baudios
1 = BRG genera 4 relojes por período de bit (reloj de 4x baudios, modo de alta velocidad)
0 = BRG genera 16 relojes por período de bit (reloj de 16x baudios, modo estándar)
poco 2-1
PDSEL<1:0>: Bits de paridad y selección de datos
11 = datos de 9 bits, sin paridad
10 = datos de 8 bits, paridad impar
01 = datos de 8 bits, paridad par
00 = datos de 8 bits, sin paridad
poco 0
STSEL: bit de selección de bit de parada
1 = Dos bits de parada
0 = Un bit de parada
REGISTRO 18-1:
UxMODE: REGISTRO DEL MODO UARTx (CONTINUACIÓN)
Nota 1: Consulte la Sección 17. “UART” (DS70188) en el “Manual de referencia de la familia dsPIC33F” para obtener información sobre
habilitando el módulo UART para la operación de recepción o transmisión.
2: Esta función solo está disponible para el modo BRG 16x (BRGH = 0).

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 188
© 2009 Microchip Technology Inc.
     
REGISTRO 18-2:
UxSTA: REGISTRO DE ESTADO Y CONTROL DE UARTx
R/W-0
R/W-0
R/W-0
U-0
R/W-0HC
R/W-0
R-0
R-1
UTXISEL1
UTXINV
UTXISEL0
—
UTXBRK
UTXEN(1)
UTXBF
TRMT
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R-1
R-0
R-0
R/C-0
R-0
URXISEL<1:0>
AGREGAR
Acertijo
PERR
FERRO
REA
URXDA
poco 7
poco 0
Leyenda:
HC = Hardware borrado
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15,13
UTXISEL<1:0>: bits de selección del modo de interrupción de transmisión 
11 = Reservado; no usar
10 = Interrumpir cuando se transfiere un carácter al Registro de cambio de transmisión y, como resultado, el 
el buffer de transmisión queda vacío
01 = Interrumpir cuando el último carácter se desplaza fuera del Registro de desplazamiento de transmisión; todos transmiten 
las operaciones se completan
00 = Interrumpir cuando se transfiere un carácter al Registro de cambio de transmisión (esto implica que hay 
 al menos un carácter abierto en el buffer de transmisión)
poco 14
UTXINV: bit de inversión de polaridad de transmisión
Si IREN = 0:
1 = El estado inactivo de UxTX es '0'
0 = UxTX El estado inactivo es '1'
Si IREN = 1:
1 = El estado inactivo de UxTX codificado con IrDA® es '1'
0 = El estado inactivo de UxTX codificado con IrDA® es '0'
poco 12
No implementado: leído como "0"
poco 11
UTXBRK: bit de interrupción de transmisión 
1 = Enviar interrupción de sincronización en la siguiente transmisión: bit de inicio, seguido de doce bits "0", seguido del bit de parada;
borrado por hardware al finalizar
0 = Transmisión de interrupción de sincronización deshabilitada o completada
poco 10
UTXEN: bit de habilitación de transmisión (1)
1 = Transmisión habilitada, pin UxTX controlado por UARTx
0 = Transmisión deshabilitada, cualquier transmisión pendiente se cancela y se restablece el búfer. Controlado por pin UxTX
por puerto
poco 9
UTXBF: bit de estado completo del búfer de transmisión (solo lectura)
1 = El buffer de transmisión está lleno
0 = El buffer de transmisión no está lleno, se puede escribir al menos un carácter más
poco 8
TRMT: bit vacío del registro de desplazamiento de transmisión (solo lectura)
1 = El registro de cambio de transmisión está vacío y el búfer de transmisión está vacío (la última transmisión se ha completado)
0 = El registro de cambio de transmisión no está vacío, hay una transmisión en progreso o en cola
bits 7-6
URXISEL<1:0>: Recibir bits de selección del modo de interrupción 
11 = La interrupción está configurada en la transferencia UxRSR, lo que hace que el búfer de recepción esté lleno (es decir, tiene 4 caracteres de datos)
10 = La interrupción se establece en la transferencia UxRSR, lo que hace que el búfer de recepción esté lleno hasta 3/4 (es decir, tiene 3 caracteres de datos)
0x = La interrupción se establece cuando se recibe y transfiere cualquier carácter desde el UxRSR al receptor
búfer. El búfer de recepción tiene uno o más caracteres
Nota 1: Consulte la Sección 17. “UART” (DS70188) en el “Manual de referencia de la familia dsPIC33F” para obtener información sobre
habilitando el módulo UART para la operación de transmisión.

© 2009 Microchip Technology Inc.
DS70286C-página 189
dsPIC33FJXXXGPX06/X08/X10
poco 5
ADDEN: Bit de detección de caracteres de dirección (bit 8 de datos recibidos = 1)
1 = Modo de detección de dirección habilitado. Si no se selecciona el modo de 9 bits, esto no tiene efecto
0 = Modo de detección de dirección deshabilitado
poco 4
RIDLE: Bit de inactividad del receptor (solo lectura)
1 = El receptor está inactivo
0 = El receptor está activo
poco 3
PERR: bit de estado de error de paridad (solo lectura)
1 = Se ha detectado un error de paridad para el carácter actual (carácter en la parte superior del FIFO de recepción)
0 = No se ha detectado el error de paridad
poco 2
FERR: bit de estado de error de trama (solo lectura)
1 = Se ha detectado un error de encuadre para el carácter actual (carácter en la parte superior del mensaje de recepción).
FIFO)
0 = No se ha detectado el error de encuadre
poco 1
OERR: bit de estado de error de desbordamiento del búfer de recepción (solo lectura/borrado)
1 = El búfer de recepción se ha desbordado
0 = El búfer de recepción no se ha desbordado. Al borrar un bit OERR previamente establecido (transición 1 →0) se restablecerá
el buffer del receptor y el UxRSR al estado vacío
poco 0
URXDA: bit disponible de datos del búfer de recepción (solo lectura)
1 = El búfer de recepción tiene datos, se puede leer al menos un carácter más
0 = El búfer de recepción está vacío
REGISTRO 18-2:
UxSTA: REGISTRO DE ESTADO Y CONTROL DE UARTx (CONTINUACIÓN)
Nota 1: Consulte la Sección 17. “UART” (DS70188) en el “Manual de referencia de la familia dsPIC33F” para obtener información sobre
habilitando el módulo UART para la operación de transmisión.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 190
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc. 
DS70286C-página 191 
dsPIC33FJXXXGPX06/X08/X10 
19.0 
LATA MEJORADA (ECAN™) 
MÓDULO 
19.1 
Descripción general 
El módulo de red de área de controlador mejorada (ECAN) 
ule es una interfaz serie, útil para comunicarse con 
otros módulos CAN o dispositivos microcontroladores. Este 
La interfaz/protocolo fue diseñado para permitir la comunicación. 
ciones 
dentro 
ruidoso 
ambientes. 
El 
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 contienen hasta 
Dos módulos ECAN. 
El módulo CAN es un controlador de comunicación implementado 
mencionar el protocolo CAN 2.0 A/B, tal como se define en el 
Especificación BOSCH. El módulo admitirá CAN 1,2, 
CAN 2.0A, CAN 2.0B Pasivo y CAN 2.0B Activo 
Versiones del protocolo. La implementación del módulo es 
un sistema CAN completo. La especificación CAN no está cubierta 
dentro de esta hoja de datos. El lector puede consultar el 
Especificación BOSCH CAN para más detalles. 
Las características del módulo son las siguientes: 
• Implementación del protocolo CAN, CAN 1.2, 
CAN 2.0A y CAN 2.0B 
• Marcos de datos estándar y extendidos 
• Longitud de datos de 0 a 8 bytes 
• Velocidad de bits programable de hasta 1 Mbit/seg. 
• Respuesta automática a la transmisión remota 
solicitudes 
• Hasta 8 buffers de transmisión con la aplicación especificada 
capacidad de priorización y aborto (cada buffer puede 
contener hasta 8 bytes de datos) 
• Hasta 32 buffers de recepción (cada buffer puede contener 
hasta 8 bytes de datos) 
• Hasta 16 completos (identificador estándar/extendido) 
filtros de aceptación 
• 3 mascarillas con filtro de aceptación total 
• Compatibilidad con direccionamiento DeviceNet™ 
• Funcionalidad de despertador programable con 
filtro de paso bajo integrado 
• El modo Loopback programable admite la autoprueba 
operación 
• Señalización mediante capacidades de interrupción para todos los CAN 
Estados de error del receptor y del transmisor. 
• Fuente de reloj programable 
• Enlace programable al módulo de captura de entrada (IC2 
tanto para CAN1 como para CAN2) para sellado de tiempo y 
sincronización de red 
• Modo de suspensión e inactividad de bajo consumo de energía 
El módulo de bus CAN consta de un motor de protocolo y 
almacenamiento/control de mensajes. El motor del protocolo CAN 
maneja todas las funciones para recibir y transmitir 
mensajes en el bus CAN. Los mensajes se transmiten 
cargando primero los registros de datos apropiados. Estado 
y los errores se pueden comprobar leyendo el correspondiente 
registros. Cualquier mensaje detectado en el bus CAN es 
verificado en busca de errores y luego comparado con filtros para 
ver si debe recibirse y almacenarse en uno de los 
recibir registros. 
19.2 
Tipos de marco 
El módulo CAN transmite varios tipos de tramas. 
que incluyen mensajes de datos, o transmisión remota 
solicitudes iniciadas por el usuario, como otras tramas que son 
generado automáticamente con fines de control. El 
Se admiten los siguientes tipos de fotogramas: 
• Marco de datos estándar: 
Un marco de datos estándar es generado por un nodo. 
cuando el nodo desea transmitir datos. incluye 
un identificador estándar (SID) de 11 bits, pero no un 
Identificador extendido (EID) de 18 bits. 
• Marco de datos extendido: 
Un marco de datos extendido es similar a un estándar 
marco de datos, pero incluye un identificador extendido como 
Bueno. 
• Marco remoto: 
Es posible que un nodo de destino solicite la 
datos de la fuente. Para este propósito, el 
El nodo de destino envía una trama remota con un 
identificador que coincide con el identificador del requerido 
marco de datos. El nodo de origen de datos apropiado 
luego envíe un marco de datos como respuesta a esto 
solicitud remota. 
• Marco de error: 
Un marco de error es generado por cualquier nodo que 
detecta un error de bus. Un cuadro de error consta de dos 
campos: un campo de indicador de error y un delimitador de error 
campo. 
• Marco de sobrecarga: 
Un nodo puede generar un marco de sobrecarga como 
resultado de dos condiciones. Primero, el nodo detecta 
un bit dominante durante el espacio entre tramas que es un 
condición ilegal. En segundo lugar, debido a condiciones internas 
ciones, el nodo aún no puede iniciar la recepción de 
el siguiente mensaje. Un nodo puede generar un máximo 
Máximo de 2 cuadros de sobrecarga secuenciales para retrasar el 
inicio del siguiente mensaje. 
• Espacio entre cuadros: 
El espacio entre cuadros separa un cuadro en curso. 
(de cualquier tipo) desde un siguiente dato o remoto 
marco. 
Nota: 
Esta hoja de datos resume las características 
del dsPIC33FJXXXGPX06/X08/X10 
familia de dispositivos. Sin embargo, no es 
pretende ser una referencia completa 
fuente. Para complementar la información en 
esta hoja de datos, consulte la Sección 21. 
“Red de área de controlador mejorada 
(ECAN™)” (DS70185) en el “dsPIC33F 
Manual de referencia familiar”, que es 
disponible en el sitio web de Microchip 
(www.microchip.com). 

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 192
© 2009 Microchip Technology Inc.
FIGURA 19-1:
DIAGRAMA DE BLOQUES DEL MÓDULO ECAN™
Asamblea de mensajes
Protocolo CAN
motor
CiTX(1)
búfer
CiRX(1)
Filtro RXF14
Filtro RXF13
Filtro RXF12
Filtro RXF11
Filtro RXF10
Filtro RXF9
Filtro RXF8
Filtro RXF7
Filtro RXF6
Filtro RXF5
Filtro RXF4
Filtro RXF3
Filtro RXF2
Filtro RXF1
Filtro RXF0
transmitir byte
Secuenciador
RXM1 Mascarilla
RXM0 Mascarilla
controlar
Configuración
Lógica
CPU
autobús
    Interrumpe
TRB0 Registro de control del búfer TX/RX
Controlador DMA
Filtro RXF15
RXM2 Mascarilla
Registro de control del búfer TRB7 TX/RX
TRB6 Registro de control del búfer TX/RX
Registro de control del búfer TRB5 TX/RX
Registro de control del búfer TRB4 TX/RX
Registro de control del búfer TRB3 TX/RX
Registro de control del búfer TRB2 TX/RX
TRB1 Registro de control del búfer TX/RX
Nota 1: i = 1 o 2 se refiere a un módulo ECAN™ particular (ECAN1 o ECAN2).

© 2009 Microchip Technology Inc. 
DS70286C-página 193 
dsPIC33FJXXXGPX06/X08/X10 
19.3 
Modos de operación 
El módulo CAN puede funcionar en una de varias operaciones 
modos seleccionados por el usuario. Estos modos incluyen: 
• Modo de inicialización 
• Desactivar modo 
• Modo de funcionamiento normal 
• Modo sólo escuchar 
• Modo Escuchar todos los mensajes 
• Modo de bucle invertido 
Los modos se solicitan configurando los bits REQOP<2:0> 
(CiCTRL1<10:8>). Se reconoce la entrada a un modo 
por 
escucha 
el 
MODO ACTUALIZADO<2:0> 
bits 
(CiCTRL1<7:5>). El módulo no cambiará el modo. 
y los bits OPMODE hasta que se produzca un cambio de modo. 
aceptable, generalmente durante el tiempo de inactividad del autobús, que es 
definido como al menos 11 bits recesivos consecutivos. 
19.3.1 
MODO DE INICIALIZACIÓN 
En el modo de inicialización, el módulo no transmitirá ni 
recibir. Los contadores de errores se borran y el 
Los indicadores de interrupción permanecen sin cambios. El programador 
tener acceso a los registros de configuración a los que se accede 
restringido en otros modos. El módulo protegerá el 
usuario de violar accidentalmente el protocolo CAN 
mediante errores de programación. Todos los registros que controlan 
La configuración del módulo no se puede modificar. 
mientras el módulo está en línea. El módulo CAN no 
se le permitirá ingresar al modo de configuración mientras 
se está produciendo la transmisión. El modo de configuración 
Sirve como candado para proteger los siguientes registros: 
• Todos los registros de control del módulo 
• Registros de configuración de interrupciones y velocidad en baudios 
• Registros de tiempos de autobuses 
• Registros de filtro de aceptación de identificadores 
• Registros de máscara de aceptación de identificador 
19.3.2 
MODO DESACTIVAR 
En el modo Desactivar, el módulo no transmitirá ni 
recibir. El módulo tiene la capacidad de configurar el bit WAKIF 
Sin embargo, debido a la actividad del autobús, cualquier interrupción pendiente 
permanecerán y los contadores de errores conservarán su valor. 
Si los bits REQOP<2:0> (CiCTRL1<10:8>) = 001, el 
El módulo entrará en el modo de desactivación del módulo. Si el módulo 
está activo, el módulo esperará 11 bits recesivos en el 
Bus CAN, detecta esa condición como un bus inactivo y luego 
acepte el comando de desactivación del módulo. cuando el 
MODO ACTUALIZADO<2:0> 
bits 
(CiCTRL1<7:5>) = 001, 
eso 
indica si el módulo entró exitosamente en 
Modo de desactivación del módulo. Los pines de E/S volverán a la normalidad. 
Función de E/S cuando el módulo está en el modo Module Disable 
modo. 
El módulo se puede programar para aplicar un paso bajo 
función de filtro a la línea de entrada CiRX mientras el módulo o 
la CPU está en modo de suspensión. El bit WAKFIL 
(CiCFG2<14>) habilita o deshabilita el filtro. 
19.3.3 
MODO DE FUNCIONAMIENTO NORMAL 
Normal 
Operación 
modo 
es 
seleccionado 
cuando 
REQOP<2:0> = 000. En este modo, el módulo está 
activado y los pines de E/S asumirán el bus CAN. 
funciones. El módulo transmitirá y recibirá CAN 
mensajes de bus a través de los pines CiTX y CiRX. 
19.3.4 
MODO SÓLO ESCUCHAR 
Si el modo Solo escuchar está activado, el módulo en el 
El bus CAN es pasivo. Los buffers del transmisor vuelven a 
la función de E/S del puerto. Los pines de recepción siguen siendo entradas. 
Para el receptor, no hay indicadores de error ni señales de reconocimiento. 
son enviados. Los contadores de errores están desactivados en este 
estado. El modo Sólo escucha se puede utilizar para detectar 
la velocidad en baudios en el bus CAN. Para usar esto, es 
necesario que haya al menos dos nodos más que 
comunicarse entre sí. 
19.3.5 
MODO ESCUCHAR TODOS LOS MENSAJES 
El módulo se puede configurar para ignorar todos los errores y recibir 
cualquier mensaje. El modo Escuchar todos los mensajes es 
se activa configurando REQOP<2:0> = '111'. en esto 
modo, los datos que están en el búfer de ensamblaje de mensajes 
fer, hasta el momento en que ocurrió un error, se copia en el 
búfer de recepción y se puede leer a través de la interfaz de la CPU. 
19.3.6 
MODO BUCLE ATRÁS 
Si el modo Loopback está activado, el módulo 
Conecte la señal de transmisión interna al conector interno. 
Recibir señal en el límite del módulo. la transmisión 
y los pines de recepción vuelven a su función de E/S de puerto. 
Nota: 
Normalmente, si se permite que el módulo CAN 
transmitir en un modo particular de operación 
y 
a 
transmisión 
es 
solicitado 
inmediatamente después de que el módulo CAN haya 
sido colocado en ese modo de operación, el 
El módulo espera 11 recesivas consecutivas. 
bits 
en 
el 
autobús 
antes 
a partir de 
transmisión. Si el usuario cambia a 
Desactive el modo dentro de este período de 11 bits, luego 
esta transmisión se cancela y el correspondiente 
El bit TXABT correspondiente está establecido y el bit TXREQ 
está despejado. 

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 194
© 2009 Microchip Technology Inc.
     
REGISTRO 19-1:
CiCTRL1: REGISTRO DE CONTROL ECAN™ 1
U-0
U-0
R/W-0
R/W-0
r-0
R/W-1
R/W-0
R/W-0
—
—
CSIDL
ABAT
—
REQOP<2:0>
poco 15
poco 8
R-1
R-0
R-0
U-0
R/W-0
U-0
U-0
R/W-0
MODOOP<2:0>
—
CANCAP
—
—
GANAR
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
r = El bit está reservado
bits 15-14
No implementado: leído como "0"
poco 13
CSIDL: bit de parada en modo inactivo
1 = Interrumpir la operación del módulo cuando el dispositivo ingresa al modo inactivo
0 = Continuar la operación del módulo en modo inactivo
poco 12
ABAT: bit de cancelación de todas las transmisiones pendientes
Señale a todos los buffers de transmisión que cancelen la transmisión. El módulo borrará este bit cuando todas las transmisiones 
son abortados
poco 11
Reservado: No utilizar
bits 10-8
REQOP<2:0>: Solicitar bits del modo de operación
000 = Establecer el modo de funcionamiento normal
001 = Establecer modo de desactivación
010 = Establecer modo de bucle invertido
011 = Establecer modo de solo escucha
100 = Establecer modo de configuración 
101 = Reservado - no usar 
110 = Reservado - no usar 
111 = Establecer el modo Escuchar todos los mensajes
bits 7-5
OPMODE<2:0>: bits del modo de operación
000 = El módulo está en modo de funcionamiento normal.
001 = El módulo está en modo Desactivado
010 = El módulo está en modo Loopback
011 = El módulo está en modo Solo escucha
100 = El módulo está en modo de configuración
101 = Reservado
110 = Reservado
111 = El módulo está en modo Escuchar todos los mensajes
poco 4
No implementado: leído como "0"
poco 3
CANCAP: Bit de habilitación de evento de captura del temporizador de recepción de mensaje CAN
1 = Habilitar captura de entrada según la recepción del mensaje CAN   
0 = Deshabilitar captura CAN
poco 2-1
No implementado: leído como "0"
poco 0
GANAR: Bit de selección de ventana de mapa SFR
1 = Usar ventana de filtro  
0 = Usar ventana de búfer

© 2009 Microchip Technology Inc.
DS70286C-página 195
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 19-2:
CiCTRL2: REGISTRO DE CONTROL 2 ECAN™
U-0
U-0
U-0
U-0
U-0
U-0
U-0
U-0
—
—
—
—
—
—
—
—
poco 15
poco 8
U-0
U-0
U-0
R-0
R-0
R-0
R-0
R-0
—
—
—
DNCNT<4:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-5
No implementado: leído como "0"
poco 4-0
DNCNT<4:0>: Bits de número de bits de filtro DeviceNet™
10010-11111 = Selección no válida 
10001 = Comparar hasta el byte de datos 3, bit 6 con EID<17>
•
•
•
00001 = Comparar hasta el byte de datos 1, bit 7 con EID<0>
00000 = No comparar bytes de datos

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 196
© 2009 Microchip Technology Inc.
     
REGISTRO 19-3:
CiVEC: REGISTRO DE CÓDIGOS DE INTERRUPCIÓN ECAN™
U-0
U-0
U-0
R-0
R-0
R-0
R-0
R-0
—
—
—
FILHIT<4:0>
poco 15
poco 8
U-0
R-1
R-0
R-0
R-0
R-0
R-0
R-0
—
ICODIO<6:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-13
No implementado: leído como "0"
bits 12-8
FILHIT<4:0>: Filtrar bits de número de aciertos
10000-11111 = Reservado
01111 = Filtro 15
•
•
•
00001 = Filtro 1
00000 = Filtro 0
poco 7
No implementado: leído como "0"
poco 6-0
ICODE<6:0>: Bits de código de bandera de interrupción
1000101-1111111 = Reservado
1000100 = FIFO interrupción casi completa
1000011 = Interrupción por desbordamiento del receptor
1000010 = interrupción de despertar
1000001 = interrupción por error
1000000 = Sin interrupción
0010000-0111111 = Reservado
0001111 = Interrupción del buffer RB15 
•
•
•
0001001 = interrupción del búfer RB9 
0001000 = interrupción del búfer RB8 
0000111 = interrupción del búfer TRB7
0000110 = interrupción del búfer TRB6
0000101 = interrupción del búfer TRB5
0000100 = interrupción del búfer TRB4
0000011 = interrupción del búfer TRB3
0000010 = interrupción del búfer TRB2
0000001 = interrupción del búfer TRB1
0000000 = TRB0 Interrupción del búfer

© 2009 Microchip Technology Inc.
DS70286C-página 197
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 19-4:
CiFCTRL: REGISTRO DE CONTROL FIFO ECAN™
R/W-0
R/W-0
R/W-0
U-0
U-0
U-0
U-0
U-0
DMABS<2:0>
—
—
—
—
—
poco 15
poco 8
U-0
U-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
—
—
—
FSA<4:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-13
DMABS<2:0>: bits de tamaño de búfer DMA  
111 = Reservado
110 = 32 buffers en DMA RAM
101 = 24 buffers en DMA RAM
100 = 16 buffers en DMA RAM
011 = 12 buffers en DMA RAM
010 = 8 buffers en DMA RAM
001 = 6 buffers en DMA RAM
000 = 4 buffers en DMA RAM
bit 12-5
No implementado: leído como "0"
poco 4-0
FSA<4:0>: el área FIFO comienza con bits de búfer
11111 = búfer RB31
11110 = búfer RB30
•
•
•
00001 = búfer TRB1
00000 = búfer TRB0

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 198
© 2009 Microchip Technology Inc.
     
REGISTRO 19-5:
CiFIFO: REGISTRO DE ESTADO FIFO ECAN™
U-0
U-0
R-0
R-0
R-0
R-0
R-0
R-0
—
—
FBP<5:0>
poco 15
poco 8
U-0
U-0
R-0
R-0
R-0
R-0
R-0
R-0
—
—
FNRB<5:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-14
No implementado: leído como "0"
bit 13-8
FBP<5:0>: Bits de puntero del búfer de escritura FIFO
011111 = búfer RB31
011110 = búfer RB30
•
•
•
000001 = búfer TRB1
000000 = búfer TRB0
bits 7-6
No implementado: leído como "0"
poco 5-0
FNRB<5:0>: FIFO Siguiente lectura de bits de puntero del búfer
011111 = búfer RB31
011110 = búfer RB30
•
•
•
000001 = búfer TRB1
000000 = búfer TRB0

© 2009 Microchip Technology Inc.
DS70286C-página 199
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 19-6:
CiINTF: REGISTRO DE BANDERA DE INTERRUPCIÓN ECAN™
U-0
U-0
R-0
R-0
R-0
R-0
R-0
R-0
—
—
TXBO
TXBP
RXBP
TXWAR
RXWAR
ADVERTENCIA
poco 15
poco 8
R/C-0
R/C-0
R/C-0
U-0
R/C-0
R/C-0
R/C-0
R/C-0
IVRIF
WAKIF
ERROR
—
FIFOIF
RBOVIF
RBIF
TBIF
poco 7
poco 0
Leyenda:
C = Borrar solo bit
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-14
No implementado: leído como "0"
poco 13
TXBO: Transmisor en estado de error Bit de bus apagado
poco 12
TXBP: Transmisor en estado de error Bit pasivo del bus
poco 11
RXBP: Receptor en estado de error Bit pasivo del bus
poco 10
TXWAR: Transmisor en estado de error Bit de advertencia
poco 9
RXWAR: Receptor en estado de error Bit de advertencia
poco 8
EWARN: Transmisor o receptor en estado de error Bit de advertencia
poco 7
IVRIF: Bit de indicador de interrupción recibido mensaje no válido
poco 6
WAKIF: Bit de indicador de interrupción de actividad de activación del autobús
poco 5
ERRIF: Bit de indicador de interrupción de error (varias fuentes en el registro CiINTF<13:8>)
poco 4
No implementado: leído como "0"
poco 3
FIFOIF: Bit de bandera de interrupción casi completa FIFO
poco 2
RBOVIF: Bit de indicador de interrupción de desbordamiento del búfer RX
poco 1
RBIF: bit de indicador de interrupción del búfer RX
poco 0
TBIF: bit de indicador de interrupción del búfer TX

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 200
© 2009 Microchip Technology Inc.
     
REGISTRO 19-7:
CiINTE: REGISTRO DE HABILITACIÓN DE INTERRUPCIÓN ECAN™
U-0
U-0
U-0
U-0
U-0
U-0
U-0
U-0
—
—
—
—
—
—
—
—
poco 15
poco 8
R/W-0
R/W-0
R/W-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
IVRIE
WAKIE
ERRÍE
—
FIFOIE
RBOVIE
RBIE
TBIE
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bit 15-8
No implementado: leído como "0"
poco 7
IVRIE: mensaje no válido recibido bit de habilitación de interrupción
poco 6
WAKIE: Bit de indicador de interrupción de actividad de activación del autobús
poco 5
ERRIE: Bit de habilitación de interrupción de error
poco 4
No implementado: leído como "0"
poco 3
FIFOIE: bit de habilitación de interrupción casi completa FIFO
poco 2
RBOVIE: Bit de habilitación de interrupción de desbordamiento del búfer RX
poco 1
RBIE: Bit de habilitación de interrupción del búfer RX
poco 0
TBIE: Bit de habilitación de interrupción del búfer TX

© 2009 Microchip Technology Inc.
DS70286C-página 201
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 19-8:
CiEC: REGISTRO DE RECUENTO DE ERRORES DE TRANSMISIÓN/RECEPCIÓN ECAN™
R-0
R-0
R-0
R-0
R-0
R-0
R-0
R-0
TERRCENTE<7:0>
poco 15
poco 8
R-0
R-0
R-0
R-0
R-0
R-0
R-0
R-0
ERRCNT<7:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bit 15-8
TERRCNT<7:0>: Bits de recuento de errores de transmisión
poco 7-0
RERRCNT<7:0>: recibir bits de recuento de errores

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 202
© 2009 Microchip Technology Inc.
     
REGISTRO 19-9:
CiCFG1: REGISTRO 1 DE CONFIGURACIÓN DE VELOCIDAD DE BAUDIOS ECAN™
U-0
U-0
U-0
U-0
U-0
U-0
U-0
U-0
—
—
—
—
—
—
—
—
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
SJW<1:0>
BRP<5:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bit 15-8
No implementado: leído como "0"
bits 7-6
SJW<1:0>: Bits de ancho de salto de sincronización
11 = La longitud es 4 x TQ  
10 = La longitud es 3 x TQ  
01 = La longitud es 2 x TQ  
00 = La longitud es 1 x TQ 
poco 5-0
BRP<5:0>: bits del preescalador de velocidad en baudios
11 1111 = TQ = 2 x 64 x 1/FCAN
•
•
•  
00 0010 = TQ = 2 x 3 x 1/FCAN
00 0001 = TQ = 2 x 2 x 1/FCAN 
00 0000 = TQ = 2 x 1 x 1/FCAN

© 2009 Microchip Technology Inc.
DS70286C-página 203
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 19-10: CiCFG2: REGISTRO 2 DE CONFIGURACIÓN DE VELOCIDAD DE BAUDIOS ECAN™
U-0
R/W-x
U-0
U-0
U-0
R/W-x
R/W-x
R/W-x
—
WAKFIL
—
—
—
SEG2PH<2:0>
poco 15
poco 8
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
SEG2PHTS
Sam
SEG1PH<2:0>
PRSEG<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
No implementado: leído como "0"
poco 14
WAKFIL: seleccione el filtro de línea del bus CAN para el bit de activación
1 = Usar filtro de línea de bus CAN para despertar
0 = El filtro de línea de bus CAN no se utiliza para despertar
bits 13-11
No implementado: leído como "0"
bits 10-8
SEG2PH<2:0>: Segmento de buffer de fase 2 bits
111 = La longitud es 8 x TQ 
000 = La longitud es 1 x TQ
poco 7
SEG2PHTS: Bit de selección de tiempo del segmento de fase 2
1 = libremente programable
0 = Máximo de bits SEG1PH o Tiempo de procesamiento de información (IPT), lo que sea mayor
poco 6
SAM: Muestra del bit de línea del bus CAN
1 = La línea de autobús se muestrea tres veces en el punto de muestreo 
0 = La línea de autobús se muestrea una vez en el punto de muestreo
bit 5-3
SEG1PH<2:0>: bits del segmento 1 del buffer de fase
111 = La longitud es 8 x TQ 
000 = La longitud es 1 x TQ
poco 2-0
PRSEG<2:0>: bits del segmento de tiempo de propagación
111 = La longitud es 8 x TQ 
000 = La longitud es 1 x TQ

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 204
© 2009 Microchip Technology Inc.
    
     
REGISTRO 19-11: CiFEN1: FILTRO DE ACEPTACIÓN ECAN™ HABILITAR REGISTRO
R/W-1
R/W-1
R/W-1
R/W-1
R/W-1
R/W-1
R/W-1
R/W-1
FLTEN15
FLTEN14
FLTEN13
FLTEN12
FLTEN11
FLTEN10
FLTEN9
FLTEN8
poco 15
poco 8
R/W-1
R/W-1
R/W-1
R/W-1
R/W-1
R/W-1
R/W-1
R/W-1
FLTEN7
FLTEN6
FLTEN5
FLTEN4
FLTEN3
FLTEN2
FLTEN1
FLTEN0
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
FLTENn: habilite el filtro n para aceptar bits de mensajes
1 = Habilitar filtro n
0 = Desactivar filtro n
REGISTRO 19-12: CiBUFPNT1: FILTRO ECAN™ 0-3 REGISTRO DE PUNTERO DE BUFFER
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
F3BP<3:0>
F2BP<3:0>
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
F1BP<3:0>
F0BP<3:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-12
F3BP<3:0>: Búfer RX escrito cuando el filtro 3 alcanza bits
bits 11-8
F2BP<3:0>: Búfer RX escrito cuando el filtro 2 alcanza bits
bit 7-4
F1BP<3:0>: Búfer RX escrito cuando el filtro 1 alcanza bits
poco 3-0
F0BP<3:0>: Búfer RX escrito cuando el filtro 0 alcanza los bits
1111 = Aciertos de filtro recibidos en el buffer RX FIFO
1110 = Accesos de filtro recibidos en RX Buffer 14
•
•
•
0001 = Aciertos de filtro recibidos en el búfer RX 1
0000 = Accesos de filtro recibidos en RX Buffer 0

© 2009 Microchip Technology Inc.
DS70286C-página 205
dsPIC33FJXXXGPX06/X08/X10
     
     
REGISTRO 19-13: CiBUFPNT2: FILTRO ECAN™ 4-7 REGISTRO DEL PUNTERO DE BUFFER
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
F7BP<3:0>
F6BP<3:0>
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
F5BP<3:0>
F4BP<3:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-12
F7BP<3:0>: Búfer RX escrito cuando el filtro 7 alcanza bits
bits 11-8
F6BP<3:0>: Búfer RX escrito cuando el filtro 6 alcanza bits
bit 7-4
F5BP<3:0>: Búfer RX escrito cuando el filtro 5 alcanza bits
poco 3-0
F4BP<3:0>: Búfer RX escrito cuando el filtro 4 alcanza bits
REGISTRO 19-14: CiBUFPNT3: FILTRO ECAN™ 8-11 REGISTRO DEL PUNTERO DE BUFFER
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
F11BP<3:0>
F10BP<3:0>
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
F9BP<3:0>
F8BP<3:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-12
F11BP<3:0>: Búfer RX escrito cuando el filtro 11 alcanza bits
bits 11-8
F10BP<3:0>: Búfer RX escrito cuando el filtro 10 alcanza bits
bit 7-4
F9BP<3:0>: Búfer RX escrito cuando el filtro 9 alcanza bits
poco 3-0
F8BP<3:0>: Búfer RX escrito cuando el filtro 8 alcanza bits

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 206
© 2009 Microchip Technology Inc.
     
REGISTRO 19-15: CiBUFPNT4: FILTRO ECAN™ 12-15 REGISTRO PUNTERO BUFFER
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
F15BP<3:0>
F14BP<3:0>
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
F13BP<3:0>
F12BP<3:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-12
F15BP<3:0>: Búfer RX escrito cuando el filtro 15 alcanza bits
bits 11-8
F14BP<3:0>: Búfer RX escrito cuando el filtro 14 alcanza bits
bit 7-4
F13BP<3:0>: Búfer RX escrito cuando el filtro 13 alcanza bits
poco 3-0
F12BP<3:0>: Búfer RX escrito cuando el filtro 12 alcanza bits

© 2009 Microchip Technology Inc.
DS70286C-página 207
dsPIC33FJXXXGPX06/X08/X10
    
    
REGISTRO 19-16: CiRXFnSID: FILTRO DE ACEPTACIÓN ECAN™ n IDENTIFICADOR ESTÁNDAR (n = 0, 1, 
..., 15)
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
SID10
SID9
SID8
SID7
SID6
SID5
SID4
SID3
poco 15
poco 8
R/W-x
R/W-x
R/W-x
U-0
R/W-x
U-0
R/W-x
R/W-x
SID2
SID1
SID0
—
EXIDE
—
EID17
EID16
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-5
SID<10:0>: Bits de identificador estándar
1 = El bit de dirección del mensaje SIDx debe ser '1' para coincidir con el filtro
0 = El bit de dirección del mensaje SIDx debe ser '0' para coincidir con el filtro
poco 4
No implementado: leído como "0"
poco 3
EXIDE: Bit de habilitación de identificador extendido
Si MIDE = 1 entonces:
1 = Coincidir solo con mensajes con direcciones de identificador extendidas
0 = Coincidir sólo con mensajes con direcciones de identificador estándar
Si MIDE = 0 entonces:
 Ignorar el bit EXIDE.
poco 2
No implementado: leído como "0"
poco 1-0
EID<17:16>: bits de identificador extendido
1 = El bit de dirección del mensaje EIDx debe ser '1' para coincidir con el filtro
0 = El bit de dirección del mensaje EIDx debe ser '0' para coincidir con el filtro
REGISTRO 19-17:
CiRXFnEID: FILTRO DE ACEPTACIÓN ECAN™ n IDENTIFICADOR EXTENDIDO (n = 0, 1, ..., 
15)
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
EID15
EID14
EID13
EID12
EID11
EID10
EID9
EID8
poco 15
poco 8
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
EID7
EID6
EID5
EID4
EID3
EID2
EID1
EID0
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
EID<15:0>: bits de identificador extendido
1 = El bit de dirección del mensaje EIDx debe ser '1' para coincidir con el filtro
0 = El bit de dirección del mensaje EIDx debe ser '0' para coincidir con el filtro

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 208
© 2009 Microchip Technology Inc.
     
REGISTRO 19-18: CiFMSKSEL1: REGISTRO DE SELECCIÓN DE MASCARILLA FILTRO ECAN™ 7-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
F7MSK<1:0>
F6MSK<1:0>
F5MSK<1:0>
F4MSK<1:0>
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
F3MSK<1:0>
F2MSK<1:0>
F1MSK<1:0>
F0MSK<1:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-14
F7MSK<1:0>: Fuente de máscara para filtro de 7 bits
bits 13-12
F6MSK<1:0>: Fuente de máscara para filtro de 6 bits
bits 11-10
F5MSK<1:0>: Fuente de máscara para filtro de 5 bits
bits 9-8
F4MSK<1:0>: Fuente de máscara para filtro de 4 bits
bits 7-6
F3MSK<1:0>: Fuente de máscara para filtro de 3 bits
bit 5-4
F2MSK<1:0>: Fuente de máscara para filtro de 2 bits
bit 3-2
F1MSK<1:0>: Fuente de máscara para filtro de 1 bit
poco 1-0
F0MSK<1:0>: Fuente de máscara para filtro de 0 bits
11 = Reservado
10 = Máscara de aceptación 2 registros contienen máscara
01 = Máscara de aceptación 1 los registros contienen máscara
00 = Máscara de aceptación 0 registros contienen máscara

© 2009 Microchip Technology Inc.
DS70286C-página 209
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 19-19: CiFMSKSEL2: REGISTRO DE SELECCIÓN DE MASCARILLAS FILTRO ECAN™ 15-8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
F15MSK<1:0>
F14MSK<1:0>
F13MSK<1:0>
F12MSK<1:0>
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
F11MSK<1:0>
F10MSK<1:0>
F9MSK<1:0>
F8MSK<1:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-14
F15MSK<1:0>: Fuente de máscara para filtro de 15 bits
11 = Reservado
10 = Máscara de aceptación 2 registros contienen máscara
01 = Máscara de aceptación 1 los registros contienen máscara
00 = Máscara de aceptación 0 registros contienen máscara
bits 13-12
F14MSK<1:0>: Fuente de máscara para filtro de 14 bits (los mismos valores que los bits 15-14)
bits 11-10
F13MSK<1:0>: Fuente de máscara para filtro de 13 bits (los mismos valores que los bits 15-14)
bits 9-8
F12MSK<1:0>: Fuente de máscara para filtro de 12 bits (los mismos valores que los bits 15-14)
bits 7-6
F11MSK<1:0>: Fuente de máscara para filtro de 11 bits (los mismos valores que los bits 15-14)
bit 5-4
F10MSK<1:0>: Fuente de máscara para filtro de 10 bits (los mismos valores que los bits 15-14)
bit 3-2
F9MSK<1:0>: Fuente de máscara para filtro de 9 bits (los mismos valores que los bits 15-14)
poco 1-0
F8MSK<1:0>: Fuente de máscara para filtro de 8 bits (los mismos valores que los bits 15-14)

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 210
© 2009 Microchip Technology Inc.
     
REGISTRO 19-20: CiRXMnSID: MASCARILLA FILTRANTE DE ACEPTACIÓN ECAN™ n IDENTIFICADOR ESTÁNDAR
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
SID10
SID9
SID8
SID7
SID6
SID5
SID4
SID3
poco 15
poco 8
R/W-x
R/W-x
R/W-x
U-0
R/W-x
U-0
R/W-x
R/W-x
SID2
SID1
SID0
—
MIDE
—
EID17
EID16
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-5
SID<10:0>: Bits de identificador estándar
1 = Incluir bit SIDx en comparación de filtros
0 = Bit SIDx no tiene importancia en la comparación de filtros
poco 4
No implementado: leído como "0"
poco 3
MIDE: Bit de modo de recepción de identificador
1 = Coincide únicamente con los tipos de mensajes (dirección estándar o extendida) que corresponden al bit EXIDE en el filtro 
0 = Coincide con el mensaje de dirección estándar o extendido si los filtros coinciden 
(es decir, si (Filtro SID) = (Mensaje SID) o si (Filtro SID/EID) = (Mensaje SID/EID))
poco 2
No implementado: leído como "0"
poco 1-0
EID<17:16>: bits de identificador extendido
1 = Incluir el bit EIDx en la comparación de filtros
0 = Bit EIDx no importa en la comparación de filtros
REGISTRO 19-21: CiRXMnEID: MASCARILLA CON FILTRO DE ACEPTACIÓN ECAN™ n IDENTIFICADOR EXTENDIDO
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
EID15
EID14
EID13
EID12
EID11
EID10
EID9
EID8
poco 15
poco 8
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
EID7
EID6
EID5
EID4
EID3
EID2
EID1
EID0
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
EID<15:0>: bits de identificador extendido
1 = Incluir el bit EIDx en la comparación de filtros
0 = Bit EIDx no importa en la comparación de filtros

© 2009 Microchip Technology Inc.
DS70286C-página 211
dsPIC33FJXXXGPX06/X08/X10
     
     
REGISTRO 19-22: CiRXFUL1: BÚFER DE RECEPCIÓN ECAN™ REGISTRO COMPLETO 1
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
RXFUL15
RXFUL14
RXFUL13
RXFUL12
RXFUL11
RXFUL10
RXFUL9
RXFUL8
poco 15
poco 8
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
RXFUL7
RXFUL6
RXFUL5
RXFUL4
RXFUL3
RXFUL2
RXFUL1
RXFUL0
poco 7
poco 0
Leyenda:
C = Borrar solo bit
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
RXFUL<15:0>: Búfer de recepción n bits completos
1 = El búfer está lleno (establecido por el módulo) 
0 = El búfer está vacío (borrarlo mediante el software de la aplicación)
REGISTRO 19-23: CiRXFUL2: BUFFER DE RECEPCIÓN ECAN™ REGISTRO COMPLETO 2
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
RXFUL31
RXFUL30
RXFUL29
RXFUL28
RXFUL27
RXFUL26
RXFUL25
RXFUL24
poco 15
poco 8
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
RXFUL23
RXFUL22
RXFUL21
RXFUL20
RXFUL19
RXFUL18
RXFUL17
RXFUL16
poco 7
poco 0
Leyenda:
C = Borrar solo bit
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
RXFUL<31:16>: Búfer de recepción n bits completos
1 = El búfer está lleno (establecido por el módulo) 
0 = El búfer está vacío (borrarlo mediante el software de la aplicación)

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 212
© 2009 Microchip Technology Inc.
    
 
    
REGISTRO 19-24: CiRXOVF1: REGISTRO 1 DE DESBORDAMIENTO DEL BUFFER DE RECEPCIÓN ECAN™
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
RXOVF15
RXOVF14
RXOVF13
RXOVF12
RXOVF11
RXOVF10
RXOVF9
RXOVF8
poco 15
poco 8
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
RXOVF7
RXOVF6
RXOVF5
RXOVF4
RXOVF3
RXOVF2
RXOVF1
RXOVF0
poco 7
poco 0
Leyenda:
C = Borrar solo bit
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
RXOVF<15:0>: Recibir búfer n bits de desbordamiento
1 = El módulo apuntó una escritura a un búfer lleno (establecido por el módulo) 
0 = Se borra el desbordamiento (se borra mediante el software de la aplicación)
REGISTRO 19-25: CiRXOVF2: REGISTRO 2 DE DESBORDAMIENTO DEL BUFFER DE RECEPCIÓN ECAN™
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
RXOVF31
RXOVF30
RXOVF29
RXOVF28
RXOVF27
RXOVF26
RXOVF25
RXOVF24
poco 15
poco 8
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
R/C-0
RXOVF23
RXOVF22
RXOVF21
RXOVF20
RXOVF19
RXOVF18
RXOVF17
RXOVF16
poco 7
poco 0
Leyenda:
C = Borrar solo bit
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
RXOVF<31:16>: Recibir búfer n bits de desbordamiento
1 = El módulo apuntó una escritura a un búfer lleno (establecido por el módulo) 
0 = Se borra el desbordamiento (se borra mediante el software de la aplicación)

© 2009 Microchip Technology Inc.
DS70286C-página 213
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 19-26:
CiTRmnCON: ECAN™ TX/RX BUFFER m REGISTRO DE CONTROL (m = 0,2,4,6; n = 
1,3,5,7)
R/W-0
R-0
R-0
R-0
R/W-0
R/W-0
R/W-0
R/W-0
TXENn
TXABTn
TXLARBn
TXERRn
TXREQn
RTRENn
TXnPRI<1:0>
poco 15
poco 8
R/W-0
R-0
R-0
R-0
R/W-0
R/W-0
R/W-0
R/W-0
TXENm
TXABTm(1)
TXLARBm(1)
TXERRm(1)
TXREQm
RTRENm
TXmPRI<1:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bit 15-8
Consulte la definición de los bits 7-0, búfer de controles n.
poco 7
TXENm: bit de selección de búfer TX/RX
1 = Buffer TRBn es un buffer de transmisión
0 = Buffer TRBn es un buffer de recepción
poco 6
TXABTm: Mensaje abortado bit(1)
1 = El mensaje fue cancelado
0 = Mensaje completado con éxito
poco 5
TXLARBm: Mensaje perdido bit de arbitraje (1)
1 = Mensaje perdido en el arbitraje mientras se enviaba
0 = El mensaje no perdió el arbitraje mientras se enviaba
poco 4
TXERRm:  Error Detected During Transmission bit(1)
1 = Se produjo un error de bus mientras se enviaba el mensaje
0 = No ocurrió un error de bus mientras se enviaba el mensaje
poco 3
TXREQm: bit de solicitud de envío de mensaje
Establecer este bit en '1' solicita el envío de un mensaje. El bit se borrará automáticamente cuando aparezca el mensaje.
se envía exitosamente. Al borrar el bit a '0' mientras está configurado, se solicitará la cancelación del mensaje.
poco 2
RTRENm: Bit de habilitación de transmisión remota automática 
1 = Cuando se recibe una transmisión remota, se configurará TXREQ
0 = Cuando se recibe una transmisión remota, TXREQ no se verá afectado
poco 1-0
TXmPRI<1:0>: Bits de prioridad de transmisión de mensajes
11 = Máxima prioridad de mensaje
10 = Prioridad de mensaje intermedia alta
01 = Prioridad de mensaje intermedia baja
00 = Prioridad de mensaje más baja
Nota 1: Este bit se borra cuando se establece TXREQ.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 214
© 2009 Microchip Technology Inc.
     
      
Nota:
Los buffers, los registros SID, EID, DLC, campo de datos y estado de recepción se encuentran en DMA RAM.
REGISTRO 19-27: CiTRBnSID: BUFFER ECAN™ n IDENTIFICADOR ESTÁNDAR (n = 0, 1, ..., 31)
U-0
U-0
U-0
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
—
—
—
SID10
SID9
SID8
SID7
SID6
poco 15
poco 8
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
SID5
SID4
SID3
SID2
SID1
SID0
SRR
IDE
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-13
No implementado: leído como "0"
bit 12-2
SID<10:0>: Bits de identificador estándar
poco 1
SRR: Sustituir bit de solicitud remota
1 = El mensaje solicitará transmisión remota 
0 = mensaje normal
poco 0
IDE: bit de identificador extendido
1 = El mensaje transmitirá el identificador extendido 
0 = El mensaje transmitirá el identificador estándar
REGISTRO 19-28: CiTRBnEID: ECAN™ BUFFER n IDENTIFICADOR EXTENDIDO (n = 0, 1, ..., 31)
U-0
U-0
U-0
U-0
R/W-x
R/W-x
R/W-x
R/W-x
—
—
—
—
EID17
EID16
EID15
EID14
poco 15
poco 8
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
EID13
EID12
EID11
EID10
EID9
EID8
EID7
EID6
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-12
No implementado: leído como "0"
bit 11-0
EID<17:6>: bits de identificador extendido

© 2009 Microchip Technology Inc.
DS70286C-página 215
dsPIC33FJXXXGPX06/X08/X10
     
  
     
REGISTRO 19-29: CiTRBnDLC: BUFFER ECAN™ n CONTROL DE LONGITUD DE DATOS (n = 0, 1, ..., 31)
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
EID5
EID4
EID3
EID2
EID1
EID0
RTR
RB1
poco 15
poco 8
U-0
U-0
U-0
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
—
—
—
RB0
DLC3
DLC2
DLC1
DLC0
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-10
EID<5:0>:  Extended Identifier bits
poco 9
RTR: bit de solicitud de transmisión remota 
1 = El mensaje solicitará transmisión remota 
0 = mensaje normal
poco 8
RB1: Bit reservado 1
El usuario debe configurar este bit en "0" según el protocolo CAN.
bits 7-5
No implementado: leído como "0"
poco 4
RB0: Bit reservado 0
El usuario debe configurar este bit en "0" según el protocolo CAN.
poco 3-0
DLC<3:0>: bits de código de longitud de datos
INSCRIPCIÓN 19-30:
CiTRBnDm: BÚFER ECAN™ n BYTE DE CAMPO DE DATOS m (n = 0, 1, ..., 31; m = 0, 1, ..., 
7)(1)
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
TRBnDm7
TRBnDm6
TRBnDm5
TRBnDm4
TRBnDm3
TRBnDm2
TRBnDm1
TRBnDm0
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 7-0
TRBnDm<7:0>: Búfer de campo de datos 'n' Byte 'm' bits
Nota 1: El byte más significativo contiene el byte (m + 1) del búfer.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 216
© 2009 Microchip Technology Inc.
     
REGISTRO 19-31: CiTRBnSTAT: ECAN™ RECIBIR BUFFER n ESTADO (n = 0, 1, ..., 31) 
U-0
U-0
U-0
R/W-x
R/W-x
R/W-x
R/W-x
R/W-x
—
—
—
FILHIT4
FILHIT3
FILHIT2
FILHIT1
FILHIT0
poco 15
poco 8
U-0
U-0
U-0
U-0
U-0
U-0
U-0
U-0
—
—
—
—
—
—
—
—
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-13
No implementado: leído como "0"
bits 12-8
FILHIT<4:0>: Bits de código de acierto de filtro (solo escritos por el módulo para los buffers de recepción, no utilizados para los buffers de transmisión)
Codifica el número de filtro que resultó en la escritura de este búfer. 
poco 7-0
No implementado: leído como "0"

© 2009 Microchip Technology Inc. 
DS70286C-página 217 
dsPIC33FJXXXGPX06/X08/X10 
20.0 
CONVERTIDOR DE DATOS 
MÓDULO DE INTERFAZ (DCI) 
20.1 
Introducción al módulo 
El convertidor de datos dsPIC33FJXXXGPX06/X08/X10 
El módulo de interfaz (DCI) permite una interfaz sencilla de 
dispositivos, como codificadores/decodificadores de audio (Codecs), ADC 
y convertidores D/A. Se admiten las siguientes interfaces. 
portado: 
• Transferencia en serie síncrona enmarcada (simple o 
Multicanal) 
• Interfaz de sonido Inter-IC (I2S) 
• Modo compatible con AC-Link 
El módulo DCI proporciona la siguiente información general 
características: 
• Tamaño de palabra programable de hasta 16 bits 
• Admite hasta 16 franjas horarias, para un máximo 
tamaño de trama de 256 bits 
• Almacenamiento en búfer de datos para hasta 4 muestras sin CPU 
arriba 
20.2 
Pines de E/S del módulo 
Hay cuatro pines de E/S asociados con el módulo. 
Cuando está habilitado, el módulo controla la dirección de los datos. 
de cada uno de los cuatro pines. 
20.2.1 
PIN CSCK 
El pin CSCK proporciona el reloj serie para el DCI. 
módulo. El pin CSCK se puede configurar como entrada 
o salida usando el bit de control CSCKD en el DCICON1 
SFR. Cuando se configura como salida, el reloj serie es 
proporcionado por el dsPIC33FJXXXGPX06/X08/X10. 
Cuando se configura como entrada, el reloj serie debe estar 
proporcionado por un dispositivo externo. 
20.2.2 
PIN CSDO 
El pin de salida de datos en serie (CSDO) está configurado como un 
pin de salida única cuando el módulo está habilitado. El 
El pin CSDO controla el bus serie siempre que se van a enviar datos. 
transmitido. El pin CSDO tiene tres estados o está conducido a '0', 
durante los períodos CSCK en los que no se transmiten datos 
dependiendo del estado del bit de control CSDOM. Este 
permite que otros dispositivos coloquen datos en el bus serie 
durante los períodos de transmisión no utilizados por el DCI 
módulo. 
20.2.3 
PIN CSDI 
El pin de entrada de datos en serie (CSDI) está configurado como un 
pin de entrada únicamente cuando el módulo está habilitado. 
20.2.3.1 
COFS Chapa 
Se utiliza el pin Codec Frame Synchronization (COFS) 
para sincronizar las transferencias de datos que ocurren en el CSDO 
y pines CSDI. El pin COFS se puede configurar como un 
entrada o una salida. La dirección de datos para el pin COFS. 
está determinado por el bit de control COFSD en el 
Registro DCICON1. 
El módulo DCI accede a los registros ocultos mientras 
la CPU está en el proceso de acceder a la memoria 
registros de buffer mapeados. 
20.2.4 
ALINEACIÓN DE DATOS DEL BUFFER 
Los valores de datos siempre se almacenan justificados a la izquierda en el 
buffers ya que la mayoría de los datos del Codec se representan como un 
Número fraccionario en complemento a 2 con signo. si el 
La longitud de la palabra recibida es inferior a 16 bits, la palabra no utilizada 
Los bits menos significativos en los registros del buffer de recepción son 
establecido en '0' por el módulo. Si la longitud de la palabra transmitida 
es inferior a 16 bits, los LSbs no utilizados en la transmisión 
El módulo ignora los registros de búfer. la palabra 
La configuración de longitud se describe en las secciones siguientes de este 
documento. 
20.2.5 
TRANSMITIR/RECEPIR CAMBIO 
REGISTRO 
El módulo DCI tiene un registro de desplazamiento de 16 bits para cambiar 
datos seriales dentro y fuera del módulo. Los datos se cambian 
entrada/salida del registro de desplazamiento, MSb primero, desde audio PCM 
los datos se transmiten en formato complemento a 2 con signo. 
20.2.6 
CONTROL DEL BÚFER DCI 
El módulo DCI contiene una unidad de control de buffer para 
transferir datos entre la memoria intermedia de sombra 
y el registro de desplazamiento en serie. La unidad de control del buffer es un 
contador de direcciones simple de 2 bits que apunta a la ubicación de palabras. 
ciones en la memoria intermedia de sombra. para recibir 
espacio de memoria (parte de dirección alta del búfer DCI 
memoria), el contador de direcciones se concatena con una 
'0' en la ubicación de MSb para formar una dirección de 3 bits. Para el 
transmitir espacio de memoria (parte alta del búfer DCI 
memoria), el contador de direcciones se concatena con una 
'1' en la ubicación de MSb. 
Nota: 
Esta hoja de datos resume las características 
del dsPIC33FJXXXGPX06/X08/X10 
familia de dispositivos. Sin embargo, no es 
pretende ser una referencia completa 
fuente. Para complementar la información en 
esta hoja de datos, consulte la Sección 20. “Datos 
Interfaz del convertidor (DCI)” (DS70288) en 
el “Manual de referencia de la familia dsPIC33F”, 
que está disponible en la web de Microchip 
sitio (www.microchip.com). 
Nota: 
La unidad de control del buffer DCI siempre 
accede a la misma ubicación relativa en el 
transmitir y recibir buffers, por lo que solo uno 
Se proporciona contador de direcciones. 

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 218
© 2009 Microchip Technology Inc.
FIGURA 20-1:
DCI MODULE BLOCK DIAGRAM
Brocas de control BCG
Autobús de datos de 16 bits
Frecuencia de muestreo
Generador
ERCD
FSD
Búfer DCI
marco
Sincronización
Generador
Unidad de control
Registro de turno DCI
Recibir búfer 
Registros con sombra 
FOSC/4
Bits de selección de tamaño de palabra
Bits de selección de longitud de trama
Bits de selección de modo DCI
CSCK
COFS
CSDI
CSDO
15
0
Búfer de transmisión 
Registros con sombra

© 2009 Microchip Technology Inc.
DS70286C-página 219
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 20-1:
DCICON1: REGISTRO DE CONTROL DCI 1
R/W-0
U-0
R/W-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
DCIEN
—
DCISIDL
—
DLOOP
CSCKD
CSCKE
COFSD
poco 15
poco 8
R/W-0
R/W-0
R/W-0
U-0
U-0
U-0
R/W-0
R/W-0
UNFM
CSDOM
DJST
—
—
—
COFSM<1:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
DCIEN: bit de habilitación del módulo DCI
1 = Module is enabled
0 = El módulo está deshabilitado
poco 14
No implementado: leído como "0"
poco 13
DCISIDL: Parada DCI en bit de control inactivo
1 = El módulo se detendrá en el modo inactivo de la CPU
0 = El módulo seguirá funcionando en modo inactivo de la CPU
poco 12
No implementado: leído como "0"
poco 11
DLOOP: Bit de control del modo Loopback digital
1 = El modo de bucle invertido digital está habilitado. Pines CSDI y CSDO conectados internamente
0 = El modo de bucle invertido digital está deshabilitado
poco 10
CSCKD: bit de control de dirección del reloj de muestra
1 = El pin CSCK es una entrada cuando el módulo DCI está habilitado
0 = El pin CSCK es una salida cuando el módulo DCI está habilitado
poco 9
CSCKE: bit de control de borde de reloj de muestra
1 = Cambios de datos en el flanco descendente del reloj en serie, muestreados en el flanco ascendente del reloj en serie
0 = Cambios de datos en el flanco ascendente del reloj en serie, muestreados en el flanco descendente del reloj en serie
poco 8
COFSD: bit de control de dirección de sincronización de trama
1 = El pin COFS es una entrada cuando el módulo DCI está habilitado
0 = El pin COFS es una salida cuando el módulo DCI está habilitado
poco 7
UNFM: bit de modo de desbordamiento insuficiente
1 = Transmitir el último valor escrito en los registros de transmisión en un desbordamiento insuficiente de transmisión
0 = Transmitir '0's en un desbordamiento insuficiente de transmisión
poco 6
CSDOM: bit de modo de salida de datos en serie
1 = El pin CSDO tendrá tres estados durante los intervalos de tiempo de transmisión deshabilitados
0 = El pin CSDO impulsa '0' durante los intervalos de tiempo de transmisión deshabilitados
poco 5
DJST: bit de control de justificación de datos DCI
1 = La transmisión/recepción de datos comienza durante el mismo ciclo de reloj en serie que la trama 
pulso de sincronización
0 = La transmisión/recepción de datos comienza un ciclo de reloj en serie después del pulso de sincronización de trama
bit 4-2
No implementado: leído como "0"
poco 1-0
COFSM<1:0>: bits del modo de sincronización de cuadros
11 = modo AC-Link de 20 bits
10 = modo AC-Link de 16 bits
01 = Modo de sincronización de trama I2S
00 = Modo de sincronización de cuadros multicanal

dsPIC33FJXXXGPX06/X08/X10
DS70286C-page 220
© 2009 Microchip Technology Inc.
     
REGISTRO 20-2:
DCICON2: REGISTRO DE CONTROL DCI 2
U-0
U-0
U-0
U-0
R/W-0
R/W-0
U-0
R/W-0
—
—
—
—
BLEN<1:0>
—
COFSG3
poco 15
poco 8
R/W-0
R/W-0
R/W-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
COFSG<2:0>
—
WS<3:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-12
No implementado: leído como "0"
bits 11-10
BLEN<1:0>: Bits de control de longitud del búfer
11 = Se almacenarán cuatro palabras de datos entre interrupciones.
10 = Se almacenarán tres palabras de datos entre interrupciones.
01 = Se almacenarán dos palabras de datos entre interrupciones.
00 = Se almacenará una palabra de datos entre interrupciones.
poco 9
No implementado: leído como "0"
bits 8-5
COFSG<3:0>: Bits de control del generador de sincronización de tramas
1111 = El marco de datos tiene 16 palabras
•
• 
•
0010 = El marco de datos tiene 3 palabras
0001 = El marco de datos tiene 2 palabras
0000 = El marco de datos tiene 1 palabra
poco 4
No implementado: leído como "0"
poco 3-0
WS<3:0>: bits de tamaño de palabra de datos DCI
1111 = El tamaño de la palabra de datos es de 16 bits
• 
•
•
0100 = El tamaño de la palabra de datos es de 5 bits
0011 = El tamaño de la palabra de datos es de 4 bits
0010 = Selección no válida. No lo use. Pueden ocurrir resultados inesperados
0001 = Selección no válida. No lo use. Pueden ocurrir resultados inesperados
0000 = Selección no válida. No lo use. Pueden ocurrir resultados inesperados

© 2009 Microchip Technology Inc.
DS70286C-página 221
dsPIC33FJXXXGPX06/X08/X10
    
REGISTRO 20-3:
DCICON3: DCI CONTROL REGISTER 3
U-0
U-0
U-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
—
—
—
—
BCG<11:8>
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
BCG<7:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-12
No implementado: leído como "0"
bit 11-0
BCG<11:0>: Bits de control del generador de reloj de bits DCI

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 222
© 2009 Microchip Technology Inc.
     
REGISTRO 20-4:
DCISTAT: REGISTRO DE ESTADO DCI
U-0
U-0
U-0
U-0
R-0
R-0
R-0
R-0
—
—
—
—
RANURA<3:0>
poco 15
poco 8
U-0
U-0
U-0
U-0
R-0
R-0
R-0
R-0
—
—
—
—
ROV
RFUL
TUNF
TMPTY
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-12
No implementado: leído como "0"
bits 11-8
SLOT<3:0>: Bits de estado de ranura DCI
1111 = La ranura n.º 15 está actualmente activa
•
• 
•
0010 = La ranura n.º 2 está actualmente activa
0001 = La ranura #1 está actualmente activa
0000 = La ranura #0 está actualmente activa
bit 7-4
No implementado: leído como "0"
poco 3
ROV: Recibir bit de estado de desbordamiento
1 = A receive overflow has occurred for at least one receive register
0 = No se ha producido un desbordamiento de recepción
poco 2
RFUL: bit de estado completo del búfer de recepción
1 = Hay nuevos datos disponibles en los registros de recepción
0 = Los registros de recepción tienen datos antiguos
poco 1
TUNF: bit de estado de desbordamiento insuficiente del búfer de transmisión
1 = Se ha producido un desbordamiento insuficiente de transmisión para al menos un registro de transmisión
0 = No se ha producido un desbordamiento insuficiente en la transmisión
poco 0
TMPTY: bit de estado vacío del búfer de transmisión
1 = Los registros de transmisión están vacíos
0 = Los registros de transmisión no están vacíos

© 2009 Microchip Technology Inc.
DS70286C-página 223
dsPIC33FJXXXGPX06/X08/X10
     
     
REGISTRO 20-5:
RSCON: REGISTRO DE CONTROL DE RANURA DE RECEPCIÓN DCI
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
RSE15
RSE14
RSE13
RSE12
RSE11
RSE10
RSE9
RSE8
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
RSE7
RSE6
RSE5
RSE4
RSE3
RSE2
RSE1
RSE0
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
RSE<15:0>: Bits de habilitación de ranura de recepción
1 = Los datos CSDI se reciben durante el intervalo de tiempo individual n
0 = los datos CSDI se ignoran durante el intervalo de tiempo individual n
REGISTRO 20-6:
TSCON: REGISTRO DE CONTROL DE RANURA DE TRANSMISIÓN DCI
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
EET15
EET14
EET13
EET12
EET11
EET10
EET9
EET8
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
EET7
EET6
EET5
EET4
EET3
EET2
EET1
EET0
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
TSE<15:0>: Bits de control de habilitación de ranura de transmisión
1 = El contenido del buffer de transmisión se envía durante el intervalo de tiempo individual n
0 = El pin CSDO tiene tres estados o se conduce a un '0' lógico, durante el intervalo de tiempo individual, dependiendo del estado.
del bit CSDOM

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 224
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc. 
DS70286C-página 225 
dsPIC33FJXXXGPX06/X08/X10 
21.0 
10 bits/12 bits 
ANALÓGICO A DIGITAL 
CONVERTIDOR (ADC) 
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 tienen hasta 
a 32 canales de entrada ADC. Estos dispositivos también tienen hasta 
a 2 módulos ADC (ADCx, donde 'x' = 1 o 2), cada uno con 
su propio conjunto de Registros de Funciones Especiales. 
El bit AD12B (ADxCON1<10>) permite que cada uno de los 
Los módulos ADC deben ser configurados por el usuario como 
ADC de 10 bits, 4 muestras/retención (configuración predeterminada) o un 
ADC de 12 bits, 1 muestra/retención. 
21.1 
Características clave 
La configuración del ADC de 10 bits tiene la siguiente clave 
características: 
• Conversión de aproximación sucesiva (SAR) 
• Velocidades de conversión de hasta 1,1 Msps 
• Hasta 32 pines de entrada analógica 
• Pines de entrada de referencia de voltaje externo 
• Muestreo simultáneo de hasta cuatro entradas analógicas 
patas 
• Modo de búsqueda automática de canales 
• Fuente de activación de conversión seleccionable 
• Modos de llenado de búfer seleccionables 
• Cuatro opciones de alineación de resultados (firmado/sin firmar, 
fraccionario/entero) 
• Operación durante los modos de suspensión e inactividad de la CPU 
La configuración ADC de 12 bits admite todo lo anterior 
características, excepto: 
• En la configuración de 12 bits, las velocidades de conversión de 
Se admiten hasta 500 ksps. 
• Sólo hay 1 amplificador de muestra/retención en el modo de 12 bits. 
configuración, por lo que el muestreo simultáneo de 
No se admiten varios canales. 
Dependiendo del pinout del dispositivo particular, el ADC 
Puede tener hasta 32 pines de entrada analógica, designados AN0. 
a través de AN31. Además, hay dos entradas analógicas. 
pines para conexiones de referencia de voltaje externo. Estos 
Las entradas de referencia de voltaje pueden compartirse con otras 
pines de entrada analógica. El número real de entradas analógicas. 
Configuración de pines y entrada de referencia de voltaje externo. 
Dependerá del dispositivo específico. Consulte el dispositivo 
hoja de datos para más detalles. 
En la Figura 21-1 se muestra un diagrama de bloques del ADC. 
21.2 
Inicialización del ADC 
Se deben realizar los siguientes pasos de configuración. 
1. 
Configure el módulo ADC: 
a) 
Seleccionar 
puerto 
patas 
como 
cosa análoga 
entradas 
(ADxPCFGH<15:0> o ADxPCFGL<15:0>) 
b) 
Seleccione la fuente de referencia de voltaje que coincida 
esperado 
rango 
en 
cosa análoga 
entradas 
(ADxCON2<15:13>) 
do) 
Seleccione el reloj de conversión analógico para 
igualar la velocidad de datos deseada con el procesador 
reloj (ADxCON3<7:0>) 
d) 
Determine cuántos canales S/H habrá 
usado 
(ADxCON2<9:8> 
y 
ADxPCFGH<15:0> o ADxPCFGL<15:0>) 
mi) 
Seleccione la muestra/conversión adecuada 
secuencia 
(ADxCON1<7:5> 
y 
ADxCON3<12:8>) 
F) 
Seleccionar 
cómo 
conversión 
resultados 
son 
presentado en el búfer (ADxCON1<9:8>) 
gramo) 
Encienda el módulo ADC (ADxCON1<15>) 
2. 
Configure la interrupción ADC (si es necesario): 
a) 
Borrar el bit ADxIF 
b) 
Seleccione la prioridad de interrupción ADC 
21.3 
ADC y DMA 
Si es necesario almacenar en el búfer más de un resultado de conversión 
antes de desencadenar una interrupción, las transferencias de datos DMA pueden 
utilizarse. Tanto ADC1 como ADC2 pueden activar datos DMA 
transferir. Si se selecciona ADC1 o ADC2 como DMA IRQ 
fuente, se produce una transferencia DMA cuando el AD1IF o 
El bit AD2IF se establece como resultado de un ADC1 o ADC2 
secuencia de conversión de muestra. 
Los bits SMPI<3:0> (ADxCON2<5:2>) se utilizan para 
Seleccione la frecuencia con la que se muestra el puntero del búfer DMA RAM. 
incrementado. 
El bit ADDMABM (ADxCON1<12>) determina cómo 
los resultados de la conversión se completan en el búfer DMA RAM 
área que se utiliza para ADC. Si este bit está establecido, los buffers DMA 
se escriben en el orden de conversión. El módulo 
proporcionar una dirección al canal DMA que es el 
igual que la dirección utilizada para el no-DMA 
búfer independiente. Si se borra el bit ADDMABM, entonces 
Los buffers DMA se escriben en modo Scatter/Gather. El 
El módulo proporcionará una dirección de dispersión/reunión al 
Canal DMA, basado en el índice de la entrada analógica. 
y el tamaño del buffer DMA. 
Nota: 
Esta hoja de datos resume las características 
del dsPIC33FJXXXGPX06/X08/X10 
familia de dispositivos. Sin embargo, no es 
pretende ser una referencia completa 
fuente. Para complementar la información en 
esta hoja de datos, consulte la Sección 16. 
“Convertidor analógico a digital (ADC)” 
(DS70183) en la “familia dsPIC33F 
Manual de referencia”, que está disponible 
de 
el 
Pastilla 
web 
sitio 
(www.microchip.com). 
Nota: 
El módulo ADC debe estar desactivado 
antes de modificar el bit AD12B. 

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 226
© 2009 Microchip Technology Inc.
FIGURA 21-1:
DIAGRAMA DE BLOQUES DEL MÓDULO ADCx   
ADC SAR
S/H0
S/H1
ADC1BUF0
AN0
Cualquiera(3)
AN1
VREF-
CH0SB<4:0>
CH0NA
CH0NB
+
-
AN0
AN3
CH123SA
AN9
VREF-
CH123SB
CH123NA CH123NB
AN6
+
-
S/H2
AN1
AN4
CH123SA
AN10
VREF-
CH123SB
CH123NA CH123NB
AN7
+
-
S/H3
AN2
AN5
CH123SA
AN11
VREF-
CH123SB
CH123NA CH123NB
AN8
+
-
CH1(2)
CH0
CH2(2)
CH3(2)
CH0SA<4:0>
CANAL
ESCANEAR
CSCNA
alternativo 
VREF+(1) AVDD
AVSS
VREF-(1)
Nota
1:
Las entradas VREF+, VREF- se pueden multiplexar con otras entradas analógicas.
2:
Los canales 1, 2 y 3 no son aplicables para el modo de operación de 12 bits.
3:
Para dispositivos de 64 pines, y = 17; para dispositivos de 80 pines, y = 23; para dispositivos de 100 pines, y = 31; para ADC2, y = 15.
Selección de entrada
VREFH
VREFL

© 2009 Microchip Technology Inc.
DS70286C-página 227
dsPIC33FJXXXGPX06/X08/X10
FIGURA 21-2:
DIAGRAMA DE BLOQUES DEL PERIODO DE RELOJ DE CONVERSIÓN ADC
0
1
CAD interno 
Reloj RC(2) 
TOSC(1)
X2
Conversión ADC 
Multiplicador de reloj
1, 2, 3, 4, 5,..., 64
ADxCON3<15>
TCY
TAD
6
ADxCON3<5:0>
Nota 1:
Consulte la Figura 9-2 para obtener la derivación de FOSC cuando el PLL está habilitado. Si no se utiliza el PLL, FOSC es igual a
la frecuencia de la fuente del reloj. TOSC = 1/FOSC.
2:
Consulte las especificaciones eléctricas del ADC para conocer el valor exacto del reloj RC.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 228
© 2009 Microchip Technology Inc.
     
REGISTRO 21-1:
ADxCON1: REGISTRO DE CONTROL ADCx 1 (donde x = 1 o 2)
R/W-0
U-0
R/W-0
R/W-0
U-0
R/W-0
R/W-0
R/W-0
ADÓN
—
ADSIDL
ADDMABM
—
AD12B
FORMATO<1:0>
poco 15
poco 8
R/W-0
R/W-0
R/W-0
U-0
R/W-0
R/W-0
R/W-0
HC,HS
R/C-0
HC, SA
SSRC<2:0>
—
SIMSAM
ASAM
MUESTRA
HECHO
poco 7
poco 0
Leyenda:
HC = Borrado por hardware
HS = Configurado por hardware
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
ADON: bit de modo de funcionamiento ADC
1 = el módulo ADC está funcionando
0 = ADC está apagado
poco 14
No implementado: leído como "0"
poco 13
ADSIDL: bit de parada en modo inactivo
1 = Interrumpir la operación del módulo cuando el dispositivo ingresa al modo inactivo
0 = Continuar la operación del módulo en modo inactivo
poco 12
ADDMABM: bit de modo de construcción de búfer DMA
1 = Los buffers DMA se escriben en el orden de conversión. El módulo proporcionará una dirección al DMA
canal que es la misma que la dirección utilizada para el búfer independiente no DMA
0 = Los buffers DMA se escriben en modo Scatter/Gather. El módulo proporcionará una dirección de dispersión/reunión
al canal DMA, según el índice de la entrada analógica y el tamaño del búfer DMA
poco 11
No implementado: leído como "0"
poco 10
AD12B: bit de modo de operación de 10 o 12 bits
1 = operación ADC de 1 canal y 12 bits
0 = operación ADC de 10 bits y 4 canales
bits 9-8
FORM<1:0>: Bits de formato de salida de datos
Para operación de 10 bits:
11 = Fraccionario con signo (DOUT = sddd dddd dd00 0000, donde s = .NOT.d<9>)
10 = Fraccionario (DOUT = dddd dddd dd00 0000)
01 = Entero con signo (DOUT = ssss sssd dddd dddd, donde s = .NOT.d<9>)
00 = Entero (DOUT = 0000 00dd dddd dddd)
Para funcionamiento de 12 bits:
11 = Fraccionario con signo (DOUT = sddd dddd dddd 0000, donde s = .NOT.d<11>)
10 = Fraccionario (DOUT = dddd dddd dddd 0000)
01 = Entero con signo (DOUT = ssss sddd dddd dddd, donde s = .NOT.d<11>)
00 = Entero (DOUT = 0000 dddd dddd dddd)
bits 7-5
SSRC<2:0>: Bits de selección de fuente de reloj de muestra
111 = El contador interno finaliza el muestreo y comienza la conversión (conversión automática)
110 = Reservado
101 = Reservado
100 = Reservado
011 = El intervalo MPWM finaliza el muestreo y comienza la conversión.
010 = Temporizador GP (Timer3 para ADC1, Timer5 para ADC2) compara, finaliza el muestreo e inicia la conversión
001 = La transición activa en el pin INT0 finaliza el muestreo y comienza la conversión
000 = Borrar el bit de muestra finaliza el muestreo y comienza la conversión
poco 4
No implementado: leído como "0"

© 2009 Microchip Technology Inc.
DS70286C-página 229
dsPIC33FJXXXGPX06/X08/X10
poco 3
SIMSAM: Bit de selección de muestra simultánea (solo aplicable cuando CHPS<1:0> = 01 o 1x)
Cuando AD12B = 1, SIMSAM es: U-0, no implementado, leído como '0'
1 = Muestras CH0, CH1, CH2, CH3 simultáneamente (cuando CHPS<1:0> = 1x); o
Muestras CH0 y CH1 simultáneamente (cuando CHPS<1:0> = 01)
0 = Muestra múltiples canales individualmente en secuencia
poco 2
ASAM: bit de inicio automático de muestra de ADC
1 = El muestreo comienza inmediatamente después de la última conversión. El bit SAMP se configura automáticamente
0 = El muestreo comienza cuando se establece el bit SAMP
poco 1
SAMP: bit de habilitación de muestra ADC
1 = Los amplificadores de muestreo/retención del ADC están muestreando
0 = Los amplificadores de muestra/retención del ADC están en espera
Si ASAM = 0, el software puede escribir "1" para comenzar el muestreo. Configurado automáticamente por hardware si ASAM = 1.
Si SSRC = 000, el software puede escribir "0" para finalizar el muestreo e iniciar la conversión. Si SSRC ≠ 000, 
borrado automáticamente por el hardware para finalizar el muestreo e iniciar la conversión.
poco 0
HECHO: bit de estado de conversión de ADC 
1 = el ciclo de conversión ADC se completa
0 = conversión ADC no iniciada o en progreso
Configurado automáticamente por hardware cuando se completa la conversión ADC. El software puede escribir "0" para borrar
Estado HECHO (el software no puede escribir '1'). Borrar este bit NO afectará ninguna operación en el programa.
ress. El hardware lo borra automáticamente al inicio de una nueva conversión.
REGISTRO 21-1:
ADxCON1: REGISTRO DE CONTROL ADCx 1 (donde x = 1 o 2) (CONTINUACIÓN)

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 230
© 2009 Microchip Technology Inc.
     
REGISTRO 21-2:
ADxCON2: REGISTRO DE CONTROL ADCx 2 (donde x = 1 o 2)
R/W-0
R/W-0
R/W-0
U-0
U-0
R/W-0
R/W-0
R/W-0
VCFG<2:0>
—
—
CSCNA
CHPS<1:0>
poco 15
poco 8
R-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
BUFS
—
SMPI<3:0>
BUFM
ALTAS
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-13
VCFG<2:0>: Bits de configuración de referencia de voltaje del convertidor    
bits 12-11
No implementado: leído como "0"
poco 10
CSCNA: Escanear selecciones de entrada para CH0+ durante el bit de muestra A
1 = Escanear entradas
0 = No escanear entradas
bits 9-8
CHPS<1:0>: Selecciona los bits utilizados de los canales
Cuando AD12B = 1, CHPS<1:0> es: U-0, no implementado, leído como '0' 
1x = Convierte CH0, CH1, CH2 y CH3
01 = Convierte CH0 y CH1
00 = Convierte CH0
poco 7
BUFS: Bit de estado de llenado del búfer (solo válido cuando BUFM = 1)
1 = ADC está llenando actualmente la segunda mitad del búfer, el usuario debe acceder a los datos en la primera mitad
0 = ADC está llenando actualmente la primera mitad del búfer, el usuario debe acceder a los datos en la segunda mitad
poco 6
No implementado: leído como "0"
bit 5-2
SMPI<3:0>: Selecciona la tasa de incremento para los bits de direcciones DMA o el número de muestra/conversión 
operaciones por interrupción
1111 = Incrementa la dirección DMA o genera una interrupción después de completar cada 16
operación de muestra/conversión
1110 = Incrementa la dirección DMA o genera una interrupción después de completar cada 15
operación de muestra/conversión
• 
•
•
0001 = Incrementa la dirección DMA o genera una interrupción después de completar cada segundo
operación de muestra/conversión
0000 = Incrementa la dirección DMA o genera una interrupción después de completar cada
operación de muestra/conversión
poco 1
BUFM: Bit de selección del modo de llenado del búfer
1 = Comienza a llenar la primera mitad del búfer en la primera interrupción y la segunda mitad del búfer en la siguiente interrupción.
0 = Siempre comienza a llenar el buffer desde el principio
poco 0
ALTS: bit de selección de modo de muestra de entrada alternativa
1 = Utiliza selecciones de entrada de canal para la muestra A en la primera muestra y la muestra B en la siguiente muestra.
0 = Siempre utiliza selecciones de entrada de canal para la muestra A
VREF+
VREF-
000
AVDD
AVSS
001
VREF+ externo
AVSS
010
AVDD
VREF externo-
011
VREF+ externo
VREF externo-
1x
AVDD
Avss

© 2009 Microchip Technology Inc.
DS70286C-página 231
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 21-3:
ADxCON3: REGISTRO DE CONTROL ADCx 3
R/W-0
U-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
ADRC
—
—
SAMC<4:0>(1)
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
ADCS<7:0>(2)
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
ADRC: bit de fuente de reloj de conversión ADC
1 = reloj RC interno ADC
0 = Reloj derivado del reloj del sistema
bits 14-13
No implementado: leído como "0"
bits 12-8
SAMC<4:0>: bits de tiempo de muestreo automático(1)
11111 = 31 TAD
• 
• 
•
00001 = 1 TAD
00000 = 0 TAD
poco 7-0
ADCS<7:0>: Bits de selección de reloj de conversión ADC(2)
11111111 = Reservado
•
•
•
01000000 = Reservado
00111111 = TCY · (ADCS<7:0> + 1) = 64 · TCY = TAD
•
•
•
00000010 = TCY · (ADCS<7:0> + 1) = 3 · TCY = TAD 
00000001 = TCY · (ADCS<7:0> + 1) = 2 · TCY = TAD
00000000 = TCY · (ADCS<7:0> + 1) = 1 · TCY = TAD
Nota 1: Este bit solo se usa si ADxCON1<SSRC> = 1.
2: Este bit no se utiliza si ADxCON3<ADRC> = 1.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 232
© 2009 Microchip Technology Inc.
     
REGISTRO 21-4:
ADxCON4: REGISTRO DE CONTROL ADCx 4
U-0
U-0
U-0
U-0
U-0
U-0
U-0
U-0
—
—
—
—
—
—
—
—
poco 15
poco 8
U-0
U-0
U-0
U-0
U-0
R/W-0
R/W-0
R/W-0
—
—
—
—
—
DMABL<2:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bit 15-3
No implementado: leído como "0"
poco 2-0
DMABL<2:0>: selecciona el número de ubicaciones del búfer DMA por bits de entrada analógica
111 = Asigna 128 palabras de buffer a cada entrada analógica
110 = Asigna 64 palabras de buffer a cada entrada analógica
101 = Asigna 32 palabras de buffer a cada entrada analógica
100 = Asigna 16 palabras de buffer a cada entrada analógica
011 = Asigna 8 palabras de buffer a cada entrada analógica
010 = Asigna 4 palabras de buffer a cada entrada analógica
001 = Asigna 2 palabras de buffer a cada entrada analógica
000 = Asigna 1 palabra de buffer a cada entrada analógica

© 2009 Microchip Technology Inc.
DS70286C-página 233
dsPIC33FJXXXGPX06/X08/X10
     
REGISTRO 21-5:
ADxCHS123: CANAL DE ENTRADA ADCx 1, 2, 3 SELECCIONAR REGISTRO
U-0
U-0
U-0
U-0
U-0
R/W-0
R/W-0
R/W-0
—
—
—
—
—
CH123NB<1:0> 
CH123SB
poco 15
poco 8
U-0
U-0
U-0
U-0
U-0
R/W-0
R/W-0
R/W-0
—
—
—
—
—
CH123NA<1:0> 
CH123SA
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
bits 15-11
No implementado: leído como "0"
bits 10-9
CH123NB<1:0>: Selección de entrada negativa del canal 1, 2, 3 para bits de muestra B
Cuando AD12B = 1, CHxNB es: U-0, no implementado, leído como '0'
11 = La entrada negativa de CH1 es AN9, la entrada negativa de CH2 es AN10, la entrada negativa de CH3 es AN11
10 = La entrada negativa de CH1 es AN6, la entrada negativa de CH2 es AN7, la entrada negativa de CH3 es AN8
0x = CH1, CH2, CH3 la entrada negativa es VREF-
poco 8
CH123SB: Selección de entrada positiva del canal 1, 2, 3 para el bit de muestra B
Cuando AD12B = 1, CHxSB es: U-0, no implementado, leído como '0'
1 = La entrada positiva CH1 es AN3, la entrada positiva CH2 es AN4, la entrada positiva CH3 es AN5
0 = La entrada positiva de CH1 es AN0, la entrada positiva de CH2 es AN1, la entrada positiva de CH3 es AN2
bit 7-3
No implementado: leído como "0"
poco 2-1
CH123NA<1:0>: Selección de entrada negativa del canal 1, 2, 3 para bits de muestra A
Cuando AD12B = 1, CHxNA es: U-0, no implementado, leído como '0'
11 = La entrada negativa de CH1 es AN9, la entrada negativa de CH2 es AN10, la entrada negativa de CH3 es AN11
10 = La entrada negativa de CH1 es AN6, la entrada negativa de CH2 es AN7, la entrada negativa de CH3 es AN8
0x = CH1, CH2, CH3 la entrada negativa es VREF-
poco 0
CH123SA: Canal 1, 2, 3 Selección de entrada positiva para muestra A bit
Cuando AD12B = 1, CHxSA es: U-0, no implementado, leído como '0'
1 = La entrada positiva CH1 es AN3, la entrada positiva CH2 es AN4, la entrada positiva CH3 es AN5
0 = La entrada positiva de CH1 es AN0, la entrada positiva de CH2 es AN1, la entrada positiva de CH3 es AN2

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 234
© 2009 Microchip Technology Inc.
     
REGISTRO 21-6:
ADxCHS0: CANAL DE ENTRADA ADCx 0 SELECCIONAR REGISTRO
R/W-0
U-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
CH0NB
—
—
CH0SB<4:0>
poco 15
poco 8
R/W-0
U-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
CH0NA
—
—
CH0SA<4:0>
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15
CH0NB: Selección de entrada negativa del canal 0 para el bit de muestra B
Misma definición que el bit 7.
bits 14-13
No implementado: leído como "0"
bits 12-8
CH0SB<4:0>: Selección de entrada positiva del canal 0 para bits de muestra B
Misma definición que bit<4:0>.
poco 7
CH0NA: Selección de entrada negativa del canal 0 para un bit de muestra
1 = La entrada negativa del canal 0 es AN1
0 = La entrada negativa del canal 0 es VREF-
bits 6-5
No implementado: leído como "0"
poco 4-0
CH0SA<4:0>: Selección de entrada positiva del canal 0 para bits de muestra A
11111 = La entrada positiva del canal 0 es AN31
11110 = La entrada positiva del canal 0 es AN30
•
• 
•
00010 = La entrada positiva del canal 0 es AN2
00001 = La entrada positiva del canal 0 es AN1
00000 = La entrada positiva del canal 0 es AN0
Nota:
ADC2 solo puede seleccionar AN0 a AN15 como entrada positiva.

© 2009 Microchip Technology Inc.
DS70286C-página 235
dsPIC33FJXXXGPX06/X08/X10
     
     
REGÍSTRESE 21-7:
ADxCSSH: REGISTRO DE SELECCION DE ESCANEO DE ENTRADA ADCx ALTO (1,2)
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
CSS31
CSS30
CSS29
CSS28
CSS27
CSS26
CSS25
CSS24
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
CSS23
CSS22
CSS21
CSS20
CSS19
CSS18
CSS17
CSS16
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
CSS <31:16>: bits de selección de escaneo de entrada de ADC
1 = Seleccione ANx para escaneo de entrada
0 = Saltar ANx para escaneo de entrada
Nota 1: En dispositivos sin 32 entradas analógicas, el usuario puede seleccionar todos los bits ADxCSSH. Sin embargo, las entradas seleccionadas
para escanear sin una entrada correspondiente en el dispositivo convertirá VREFL.
2: CSSx = ANx, donde x = 16 a 31.
REGISTRO 21-8:
ADxCSSL: REGISTRO DE SELECCION DE ESCANEO DE ENTRADA ADCx BAJO (1,2)
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
CSS15
CSS14
CSS13
CSS12
CSS11
CSS10
CSS9
CSS8
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
CSS7
CSS6
CSS5
CSS4
CSS3
CSS2
CSS1
CSS0
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
CSS<15:0>: bits de selección de escaneo de entrada ADC
1 = Seleccione ANx para escaneo de entrada
0 = Saltar ANx para escaneo de entrada
Nota 1: En dispositivos sin 16 entradas analógicas, el usuario puede seleccionar todos los bits ADxCSSL. Sin embargo, las entradas seleccionadas
para escanear sin una entrada correspondiente en el dispositivo convertirá VREFL.
2: CSSx = ANx, donde x = 0 a 15.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 236
© 2009 Microchip Technology Inc.
     
     
REGISTRO 21-9:
AD1PCFGH: REGISTRO DE CONFIGURACIÓN DEL PUERTO ADC1 ALTO (1,2,3)
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
PCFG31
PCFG30
PCFG29
PCFG28
PCFG27
PCFG26
PCFG25
PCFG24
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
PCFG23
PCFG22
PCFG21
PCFG20
PCFG19
PCFG18
PCFG17
PCFG16
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
PCFG<31:16>: bits de control de configuración del puerto ADC
1 = Pin de puerto en modo digital, entrada de lectura de puerto habilitada, multiplexor de entrada ADC conectado a AVSS
0 = Pin de puerto en modo analógico, entrada de lectura de puerto deshabilitada, ADC muestra el voltaje del pin
Nota 1: En dispositivos sin 32 entradas analógicas, todos los bits PCFG son R/W por el usuario. Sin embargo, los bits PCFG se ignoran en
puertos sin una entrada correspondiente en el dispositivo.
2: ADC2 solo admite entradas analógicas AN0-AN15; por lo tanto, no existe ningún registro de configuración del puerto ADC2.
3: PCFGx = ANx, donde x = 16 a 31.
REGISTRO 21-10: ADxPCFGL: REGISTRO DE CONFIGURACIÓN DEL PUERTO ADCx BAJO (1,2,3)
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
PCFG15
PCFG14
PCFG13
PCFG12
PCFG11
PCFG10
PCFG9
PCFG8
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
PCFG7
PCFG6
PCFG5
PCFG4
PCFG3
PCFG2
PCFG1
PCFG0
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
U = Bit no implementado, leído como '0'
-n = Valor en POR
'1' = El bit está configurado
'0' = El bit se borra
x = El bit es desconocido
poco 15-0
PCFG<15:0>: Bits de control de configuración del puerto ADC
1 = Pin de puerto en modo digital, entrada de lectura de puerto habilitada, multiplexor de entrada ADC conectado a AVSS
0 = Pin de puerto en modo analógico, entrada de lectura de puerto deshabilitada, ADC muestra el voltaje del pin
Nota 1: En dispositivos sin 16 entradas analógicas, todos los bits PCFG son R/W por el usuario. Sin embargo, los bits PCFG se ignoran en
puertos sin una entrada correspondiente en el dispositivo.
2: En dispositivos con dos módulos analógicos a digitales, tanto AD1PCFGL como AD2PCFGL afectarán la 
Configuración de pines de puerto multiplexados con AN0-AN15.
3: PCFGx = ANx, donde x = 0 a 15.

© 2009 Microchip Technology Inc.
DS70286C-página 237
dsPIC33FJXXXGPX06/X08/X10
22.0
CARACTERÍSTICAS ESPECIALES
dsPIC33FJXXXGPX06/X08/X10 
dispositivos 
incluir
varias características destinadas a maximizar la aplicación
flexibilidad y confiabilidad, y minimizar el costo mediante la eliminación
inación de componentes externos. Estos son:
• Configuración flexible
• Temporizador de vigilancia (WDT)
• Protección de código y seguridad CodeGuard™
• Interfaz de escaneo de límites JTAG
• Programación en serie en circuito™ (ICSP™)
• Emulación en circuito
22.1
Bits de configuración
Los bits de configuración se pueden programar (léase como
'0'), o dejarlo sin programar (leer como '1'), para seleccionar
varias configuraciones de dispositivos. Estos bits están mapeados
comenzando en la ubicación de memoria del programa 0xF80000. 
El mapa del registro de configuración del dispositivo se muestra en
Tabla 22-1.
Las descripciones de bits de configuración individuales para el
FBS, FSS, FGS, FOSCSEL, FOSC, FWDT, FPOR y
Los registros de configuración FICD se muestran en la Tabla 22-2.
Tenga en cuenta que la dirección 0xF80000 está más allá del programa de usuario
espacio de memoria. De hecho, pertenece a la configuración.
espacio de memoria (0x800000-0xFFFFFF) que sólo puede ser
se accede mediante lecturas y escrituras de tablas.
El byte superior de todos los registros de configuración del dispositivo.
siempre debe ser '1111 1111'. Esto los hace
parecen ser instrucciones NOP en el caso remoto de que
sus ubicaciones alguna vez se ejecutan por accidente. desde
Los bits de configuración no están implementados en el
ubicaciones correspondientes, escribiendo '1's en estas ubicaciones
no tiene ningún efecto sobre el funcionamiento del dispositivo. 
Para evitar cambios de configuración involuntarios durante
ejecución de código, todos los bits de configuración programables
son de escritura una vez. Después de programar inicialmente un bit durante
Después de un ciclo de energía, no se puede volver a escribir en él. Cambiando
la configuración de un dispositivo requiere que el suministro de energía al dispositivo
ser ciclado.
TABLA 22-1:
MAPA DE REGISTRO DE CONFIGURACIÓN DEL DISPOSITIVO 
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la Sección 23.
“Seguridad CodeGuard™” (DS70199),
Sección 
24. 
“Programación 
y
Diagnóstico” (DS70207) y Sección
25. “Configuración del dispositivo” (DS70194)
en la “Referencia de la familia dsPIC33F
Manual”, que está disponible en el
Sitio web de Microchip (www.microchip.com).
Dirección
Nombre
Bit 7
Bit 6
Bit 5
Bit 4
Bit 3
Bit 2
Bit 1
Bit 0
0xF80000 FBS
RB<1:0>
—
—
BSS<2:0>
BWRP
0xF80002 FSS
RSS<1:0>
—
—
SSS<2:0>
SWRP
0xF80004 FGS
—
—
—
—
—
GSS1
GSS0
GWRP
0xF80006 FOSCSEL
IESO
Reservado(2)
—
—
—
FNOSC<2:0>
0xF80008 FOSC
FCKSM<1:0>
—
—
—
OSCIOFNC
POSCMD<1:0>
0xF8000A DSV
FWDTEN
VIENTO
—
WDTPRE
WDTPOST<3:0>
0xF8000C FPOR
—
—
—
—
—
FPWRT<2:0>
0xF8000E FICD
Reservado(1)
JTAGEN
—
—
—
ICS<1:0>
0xF80010 FUID0
ID de unidad de usuario Byte 0
0xF80012 FUID1
ID de unidad de usuario Byte 1
0xF80014 FUID2
ID de unidad de usuario Byte 2
0xF80016 FUID3
ID de unidad de usuario Byte 3
Nota 1: Cuando se lean, estos bits aparecerán como "1". Cuando escriba en estos bits, configúrelos en "1".
2: Cuando se lee, este bit devuelve el valor programado actual.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 238
© 2009 Microchip Technology Inc.
TABLA 22-2:
dsPIC33FJXXXGPX06/X08/X10 DESCRIPCIÓN DE BITS DE CONFIGURACIÓN
Campo de bits
Registrarse
Descripción
BWRP
FBS
Protección contra escritura flash del programa de segmento de arranque
1 = Se puede escribir el segmento de arranque
0 = El segmento de arranque está protegido contra escritura
BSS<2:0>
FBS
Tamaño de protección del código flash del programa de segmento de arranque
X11 = No hay segmento Flash del programa de arranque
El espacio de arranque es 1K IW menos VS
110 = Seguridad estándar; El segmento Flash del programa de arranque comienza al final de VS y termina 
a las 0007FEh
010 = Alta seguridad; El segmento Flash del programa de arranque comienza al final de VS y termina en 
0007FEh
El espacio de arranque es 4K IW menos VS
101 = Seguridad estándar; El segmento Flash del programa de arranque comienza al final de VS y termina 
en 001FFEh
001 = Alta seguridad; El segmento Flash del programa de arranque comienza al final de VS y termina en 
001FFEh
El espacio de arranque es 8K IW menos VS
100 = Seguridad estándar; El segmento Flash del programa de arranque comienza al final de VS y termina 
en 003FFEh
000 = Alta seguridad; El segmento Flash del programa de arranque comienza al final de VS y termina en 
003FFEh
RB<1:0>
FBS
Protección del código RAM del segmento de arranque
11 = No hay RAM de arranque definida
10 = La RAM de arranque es de 128 bytes
01 = La RAM de arranque es de 256 bytes
00 = La RAM de arranque es 1024 bytes
SWRP
FSS
Protección contra escritura flash del programa de segmento seguro
1 = Se puede escribir un segmento seguro
0 = El segmento seguro está protegido contra escritura

© 2009 Microchip Technology Inc.
DS70286C-página 239
dsPIC33FJXXXGPX06/X08/X10
SSS<2:0>
FSS
Tamaño de protección del código flash del programa de segmento seguro 
(PARA DISPOSITIVOS 128K y 256K)
X11 = Sin segmento Flash de programa seguro
El espacio seguro es 8K IW menos BS
110 = Seguridad estándar; El segmento Flash del programa seguro comienza al final de BS, 
termina en 0x003FFE
010 = Alta seguridad; El segmento Flash del programa seguro comienza al final de BS y termina en 
0x003FFE
El espacio seguro es de 16K IW menos BS
101 = Seguridad estándar; El segmento Flash del programa seguro comienza al final de BS, 
termina en 0x007FFE
001 = Alta seguridad; El segmento Flash del programa seguro comienza al final de BS y termina en 
0x007FFE
El espacio seguro es 32K IW menos BS
100 = Seguridad estándar; El segmento Flash del programa seguro comienza al final de BS, 
termina en 0x00FFFE
000 = Alta seguridad; El segmento Flash del programa seguro comienza al final de BS y termina en 
0x00FFFE
(PARA DISPOSITIVOS 64K)
X11 = Sin segmento Flash de programa seguro
El espacio seguro es 4K IW menos BS
110 = Seguridad estándar; El segmento Flash del programa seguro comienza al final de BS, 
termina en 0x001FFE
010 = Alta seguridad; El segmento Flash del programa seguro comienza al final de BS y termina en 
0x001FFE
El espacio seguro es 8K IW menos BS
101 = Seguridad estándar; El segmento Flash del programa seguro comienza al final de BS, 
termina en 0x003FFE
001 = Alta seguridad; El segmento Flash del programa seguro comienza al final de BS y termina en 
0x003FFE
El espacio seguro es de 16K IW menos BS
100 = Seguridad estándar; El segmento Flash del programa seguro comienza al final de BS, 
termina en 007FFEh
000 = Alta seguridad; El segmento Flash del programa seguro comienza al final de BS y termina en 
0x007FFE
RSS<1:0>
FSS
Protección de código RAM de segmento seguro
11 = No se ha definido ninguna RAM segura
10 = La RAM segura es 256 bytes menos BS RAM
01 = La RAM segura es 2048 bytes menos BS RAM
00 = La RAM segura es 4096 bytes menos BS RAM
GSS<1:0>
FGS
Bit de protección de código de segmento general
11 = La memoria del programa de usuario no está protegida por código
10 = Seguridad estándar; El segmento Flash del programa general comienza al final de SS, 
termina en la MOE
0x = Alta seguridad; El segmento Flash del programa general comienza al final de SS y termina en 
MOE
GWRP
FGS
Bit de protección contra escritura de segmento general
1 = La memoria del programa de usuario no está protegida contra escritura
0 = La memoria del programa de usuario está protegida contra escritura
TABLA 22-2:
dsPIC33FJXXXGPX06/X08/X10 DESCRIPCIÓN DE BITS DE CONFIGURACIÓN (CONTINUACIÓN)
Campo de bits
Registrarse
Descripción

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 240
© 2009 Microchip Technology Inc.
IESO
FOSCSEL
Bit de habilitación de inicio del oscilador de dos velocidades
1 = Iniciar el dispositivo con FRC, luego cambiar automáticamente al seleccionado por el usuario 
fuente del oscilador cuando esté listo
0 = Dispositivo de arranque con fuente de oscilador seleccionada por el usuario
FNOSC<2:0>
FOSCSEL
Bits de selección de fuente inicial del oscilador
111 = Oscilador interno Fast RC (FRC) con postescalador
110 = Oscilador interno Fast RC (FRC) con división por 16
101 = oscilador LPRC
100 = oscilador secundario (LP)
011 = Oscilador primario (XT, HS, EC) con PLL
010 = Oscilador primario (XT, HS, EC)
001 = Oscilador interno Fast RC (FRC) con PLL
000 = oscilador FRC
FCKSM<1:0>
FOSC
Bits de modo de conmutación de reloj
1x = El cambio de reloj está deshabilitado, el Monitor de reloj a prueba de fallos está deshabilitado
01 = El cambio de reloj está habilitado, el monitor de reloj a prueba de fallas está deshabilitado
00 = El cambio de reloj está habilitado, el Monitor de reloj a prueba de fallos está habilitado
OSCIOFNC
FOSC
Bit de función de pin OSC2 (excepto en los modos XT y HS)
1 = OSC2 es salida de reloj
0 = OSC2 es un pin de E/S digital de uso general
POSCMD<1:0>
FOSC
Modo de oscilador primario Seleccionar bits
11 = Oscilador primario deshabilitado
10 = Modo oscilador de cristal HS
01 = modo oscilador de cristal XT
00 = modo EC (reloj externo)
FWDTEN
FWDT
Bit de habilitación del temporizador de vigilancia
1 = Temporizador de vigilancia siempre habilitado (el oscilador LPRC no se puede deshabilitar).
el bit SWDTEN en el registro RCON no tendrá ningún efecto.)
0 = Temporizador de vigilancia activado/desactivado por el software del usuario (LPRC se puede desactivar
borrando el bit SWDTEN en el registro RCON)
VIENTO
FWDT
Bit de habilitación de ventana del temporizador de vigilancia
1 = Temporizador de vigilancia en modo sin ventana
0 = Temporizador de vigilancia en modo Ventana
WDTPRE
FWDT
Bit preescalador del temporizador de vigilancia
1 = 1:128
0 = 1:32
WDTPOST
FWDT
Bits del postescalador del temporizador de vigilancia
1111 = 1:32,768
1110 = 1:16,384
    .
    .
    .
0001 = 1:2
0000 = 1:1
JTAGEN
FICD
Bits de habilitación JTAG
1 = JTAG habilitado
0 = JTAG deshabilitado
ICS<1:0>
FICD
Bits de selección de canal de comunicación ICD
11 = Comunicar en PGEC1 y PGED1
10 = Comunicar en PGEC2 y PGED2
01 = Comunicar en PGEC3 y PGED3
00 = Reservado
TABLA 22-2:
dsPIC33FJXXXGPX06/X08/X10 DESCRIPCIÓN DE BITS DE CONFIGURACIÓN (CONTINUACIÓN)
Campo de bits
Registrarse
Descripción

© 2009 Microchip Technology Inc.
DS70286C-página 241
dsPIC33FJXXXGPX06/X08/X10
22.2
Regulador de voltaje en chip
Todos los dispositivos dsPIC33FJXXXGPX06/X08/X10
alimentan su lógica digital central a 2,5 V nominales. esto
puede crear un problema para los diseños que deben
funcionan a un voltaje típico más alto, como 3,3 V. a
simplificar 
sistema 
diseño, 
todos 
dispositivos 
en 
el
La familia dsPIC33FJXXXGPX06/X08/X10 incorpora un
regulador en chip que permite que el dispositivo ejecute su núcleo
lógica de VDD.
El regulador proporciona energía al núcleo desde el
otros pines VDD. El regulador requiere que un
Condensador de baja ESR (menos de 5 ohmios) (como
tantalio 
o 
cerámica) 
ser 
conectado 
a 
el
Pasador VCAP/VDDCORE (Figura 22-1). Esto ayuda a
mantener 
el 
estabilidad 
de 
el 
regulador. 
el
El valor recomendado para el condensador del filtro es
proporcionado en la Tabla 25-13 de la Sección 25.0 “Equipos eléctricos
Características”.
En un POR, se necesitan aproximadamente 20 μs para que el chip
regulador de voltaje para generar un voltaje de salida. durante
esta vez, designada como TSTARTUP, la ejecución del código es
discapacitado. TSTARTUP se aplica cada vez que el dispositivo
reanuda el funcionamiento después de cualquier apagado.
FIGURA 22-1:
CONEXIONES PARA EL 
VOLTAJE EN EL CHIP 
REGULADOR(1)
22.3
BOR: Reinicio de caída
El módulo BOR (Brown-out Reset) se basa en un
circuito de referencia de voltaje interno que monitorea el
tensión regulada VCAP/VDDCORE. El objetivo principal de
El módulo BOR es para generar un reinicio del dispositivo cuando
se produce una condición de apagón. Las condiciones de caída de tensión son
generalmente causado por fallas en la red eléctrica de CA (es decir,
porciones faltantes de la forma de onda del ciclo de CA debido a una mala
líneas de transmisión de energía o caídas de voltaje debido a
Consumo excesivo de corriente cuando se aplica una carga inductiva grande.
encendido).
Un BOR generará un pulso de reinicio que restablecerá el
dispositivo. El BOR seleccionará la fuente del reloj, basándose en
los valores de bits de configuración del dispositivo (FNOSC<2:0> y
POSCMD<1:0>). Además, si se utiliza un modo de oscilador
seleccionado, el BOR activará el arranque del oscilador
Temporizador (OST). El reloj del sistema se mantiene hasta que OST
caduca. Si se utiliza el PLL, entonces el reloj se mantendrá
hasta que el bit LOCK (OSCCON<5>) sea '1'.
Al mismo tiempo, se activará el tiempo de espera PWRT (TPWRT).
se aplica antes de que se libere el reinicio interno. si
TPWRT = 0 y se está utilizando un oscilador de cristal, entonces
Se aplica un retraso nominal de TFSCM = 100. el total
El retraso en este caso es TFSCM.
El bit de estado BOR (RCON<1>) se configurará para indicar
que se ha producido un BOR. El circuito BOR continúa
funcionará en los modos de suspensión o inactivo y restablecerá el
dispositivo en caso de que VDD caiga por debajo del umbral BOR
voltaje.
Nota:
Es importante que el condensador de baja ESR
colocarse lo más cerca posible del
Pasador VCAP/VDDCORE.
Nota
1:
Estos son voltajes de funcionamiento típicos. Consulte 
TABLA 25-13: “Regulador de voltaje interno 
Especificaciones” ubicadas en la Sección 25.1 “DC 
Características” para todos los rangos operativos 
de VDD y VCAP/VDDCORE.
2:
Es importante que el condensador de baja ESR esté 
colocado lo más cerca posible del 
Pasador VCAP/VDDCORE.
VDD
VCAP/VDDCORE
VSS
dsPIC33F
CEFC
3,3 V

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 242
© 2009 Microchip Technology Inc.
22.4
Temporizador de vigilancia (WDT)
Para dispositivos dsPIC33FJXXXGPX06/X08/X10, el WDT
es impulsado por el oscilador LPRC. Cuando el WDT es
habilitada, la fuente del reloj también está habilitada.
La fuente de reloj WDT nominal de LPRC es de 32 kHz.
Esto alimenta un preescalador y luego se puede configurar para
ya sea de 5 bits (división por 32) o de 7 bits (división por 128)
operación. El preescalador lo establece el WDTPRE
Bit de configuración. Con una entrada de 32 kHz, el preescalador
produce un período de tiempo de espera WDT nominal (TWDT) de 1 ms
en modo de 5 bits, o 4 ms en modo de 7 bits.
Un posescalador variable divide el preescalador WDT
salida y permite una amplia gama de períodos de tiempo de espera.
El postescalador está controlado por WDTPOST<3:0>
Bits de configuración (FWDT<3:0>) que permiten
selección de un total de 16 ajustes, desde 1:1 hasta 1:32.768.
Usando el prescaler y postscaler, períodos de tiempo de espera
Se puede lograr un rango de 1 ms a 131 segundos.
Se restablecen el WDT, el prescaler y el postscaler:
• En cualquier dispositivo Restablecer
• Al finalizar un cambio de reloj, si 
invocado por el software (es decir, configurando el bit OSWEN 
después de cambiar los bits NOSC) o por hardware 
(es decir, monitor de reloj a prueba de fallos)
• Cuando se ejecuta una instrucción PWRSAV 
(es decir, se ingresa al modo de suspensión o inactivo)
• Cuando el dispositivo sale del modo de suspensión o inactivo para 
reanudar el funcionamiento normal
• Mediante una instrucción CLRWDT durante la ejecución normal
Si el WDT está habilitado, continuará ejecutándose durante la suspensión
o Modos inactivos. Cuando ocurre el tiempo de espera de WDT, el
El dispositivo lo activará y la ejecución del código se iniciará.
continuar desde donde se recibió la instrucción PWRSAV
ejecutado. Los bits SLEEP o IDLE correspondientes
(RCON<3,2>) deberá borrarse en el software después de
el dispositivo se despierta. 
El bit de bandera WDT, WDTO (RCON<4>), no se activa automáticamente.
borrado después de un tiempo de espera WDT. Para detectar posteriores
eventos WDT, la bandera debe borrarse en el software.  
El WDT es habilitado o deshabilitado por el FWDTEN
Bit de configuración en el registro de configuración FWDT.
Cuando el bit de configuración FWDTEN está establecido, el WDT se activa.
siempre habilitado. 
El WDT se puede controlar opcionalmente mediante software cuando
el bit de configuración FWDTEN ha sido programado
a '0'. El WDT se habilita en el software configurando el
Bit de control SWDTEN (RCON<5>). El SWDTEN
El bit de control se borra en cualquier dispositivo. Restablecer. El software
La opción WDT permite al usuario habilitar el WDT para
segmentos de código críticos y desactivar el WDT durante
segmentos no críticos para máximo ahorro de energía.
FIGURA 22-2:
DIAGRAMA DE BLOQUES WDT
Nota:
Las instrucciones CLRWDT y PWRSAV
borrar los recuentos del preescalador y postescalador
cuando se ejecuta.
Nota:
Si se borra el bit WINDIS (FWDT<6>), el
La instrucción CLRWDT debe ser ejecutada por
el software de la aplicación sólo durante el último
1/4 del período WDT. Este CLRWDT
La ventana se puede determinar usando un temporizador.
Si se ejecuta una instrucción CLRWDT antes
En esta ventana, se produce un reinicio de WDT. 
Todos los reinicios del dispositivo
Transición a una nueva fuente de reloj
Salir del modo de suspensión o inactivo
Instrucción PWRSAV
Instrucción CLRWDT
0
1
WDTPRE
WDTPOST<3:0>
Temporizador de vigilancia
Preescalador
(dividir por N1)
Postescalador
(dividir por N2)
Dormir/Inactivo
WDT 
Seleccionar ventana WDT
VIENTO
WDT 
Instrucción CLRWDT
SWDTEN
FWDTEN
LPRC Reloj
RS
RS
despertar
Reiniciar

© 2009 Microchip Technology Inc.
DS70286C-página 243
dsPIC33FJXXXGPX06/X08/X10
22,5
Interfaz JTAG
Los dispositivos dsPIC33FJXXXGPX06/X08/X10 implementan un
Interfaz JTAG, que admite dispositivos de escaneo de límites
pruebas, así como programación en circuito. Detallado
La información sobre la interfaz se proporcionará en el futuro.
revisiones del documento.
22.6
Protección de código y 
Seguridad CodeGuard™
Las familias de productos dsPIC33F ofrecen la avanzada
implementación de CodeGuard™ Security. CódigoGuard™
La seguridad permite que varias partes compartan de forma segura
recursos (memoria, interrupciones y periféricos) en un
un solo chip. Esta característica ayuda a proteger al individuo
Propiedad Intelectual en diseños de sistemas colaborativos.
Cuando se combina con bibliotecas de cifrado de software,
CodeGuard Security se puede utilizar para actualizar de forma segura
Flash incluso cuando varias IP residen en una única
chip. Las funciones de protección del código varían según
el dsPIC33F real implementado. lo siguiente
Las secciones proporcionan una descripción general de estas características.
Las funciones de protección del código están controladas por el
Registros de configuración: FBS, FSS y FGS.
22.7
 Programación en serie en circuito
Señal digital familiar dsPIC33FJXXXGPX06/X08/X10
Los controladores se pueden programar en serie mientras que al final
circuito de aplicación. Esto se hace simplemente con dos líneas para
reloj y datos y otras tres líneas para energía, tierra
y 
el 
programación 
secuencia. 
esto 
permite
clientes para fabricar tableros con no programados
dispositivos y luego programar el controlador de señal digital
justo antes de enviar el producto. Esto también permite que el
firmware más reciente o un firmware personalizado, para ser
programado. Consulte el documento “dsPIC33F/PIC24H
destello 
Programación 
Especificación” 
(DS70152)
documento para obtener detalles sobre ICSP.
Cualquiera de tres pares de reloj/datos de programación
Se pueden utilizar alfileres: 
• PGEC1 y PGED1
• PGEC2 y PGED2
• PGEC3 y PGED3
22.8
Depurador en circuito
Cuando se selecciona MPLAB® ICD 2 como depurador, el
La funcionalidad de depuración en circuito está habilitada. esto
La función permite funciones de depuración simples cuando se usa.
con MPLAB IDE. La funcionalidad de depuración está controlada
a través del PGECx (Reloj de emulación/depuración) y
Funciones de pin PGEDx (emulación/datos de depuración). 
Cualquiera de tres pares de pines de reloj/datos de depuración
se puede utilizar: 
• PGEC1 y PGED1
• PGEC2 y PGED2
• PGEC3 y PGED3
Para utilizar la función de depuración en circuito del dispositivo,
El diseño debe implementar conexiones ICSP para
MCLR, VDD, VSS y el par de pines PGEDx/PGECx. en
Además, cuando la función está habilitada, algunos de los
Los recursos no están disponibles para uso general. Estos
Los recursos incluyen los primeros 80 bytes de RAM de datos y
dos pines de E/S.
Nota:
Consulte la Sección 23. “CodeGuard™
Seguridad” (DS70199) en el archivo “dsPIC33F
Manual de referencia familiar” para obtener más información.
información sobre uso, configuración y
funcionamiento de CodeGuard™ Security.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 244
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70286C-página 245
dsPIC33FJXXXGPX06/X08/X10
23.0
RESUMEN DEL JUEGO DE INSTRUCCIONES
El conjunto de instrucciones dsPIC33F es idéntico al del
dsPIC30F. 
La mayoría de las instrucciones son una sola palabra de memoria de programa.
(24 bits). Sólo tres instrucciones requieren dos programas
ubicaciones de memoria. 
Cada instrucción de una sola palabra es una palabra de 24 bits, dividida
en un código de operación de 8 bits, que especifica la instrucción
tipo y uno o más operandos, que especifican con más detalle
el funcionamiento de la instrucción. 
El conjunto de instrucciones es altamente ortogonal y está agrupado
en cinco categorías básicas:
• Operaciones orientadas a palabras o bytes
• Operaciones orientadas a bits
• Operaciones literales
• Operaciones DSP
• Controlar operaciones
La tabla 23-1 ilustra los símbolos generales utilizados en
describiendo las instrucciones. 
El resumen del conjunto de instrucciones dsPIC33F en la Tabla 23-2
proporciona todas las instrucciones, junto con las banderas de estado
afectados por cada instrucción. 
La mayoría de las instrucciones de registro W orientadas a palabras o bytes
(incluyendo 
barril 
turno 
instrucciones) 
tener 
tres
operandos: 
• El primer operando fuente, que normalmente es un 
registrar 'Wb' sin ningún modificador de dirección
• El segundo operando fuente, que normalmente es un 
registrar 'Ws' con o sin un modificador de dirección
• El destino del resultado, que normalmente es un 
registrar 'Wd' con o sin un modificador de dirección 
Sin embargo, las instrucciones de registro de archivos orientadas a palabras o bytes
tener dos operandos:
• El registro de archivo especificado por el valor 'f'
• El destino, que podría ser el archivo 
registro 'f' o el registro W0, que se denota como 
'WREG'
la mayoría 
orientado a bits 
instrucciones 
(incluyendo 
sencillo
instrucciones de rotación/desplazamiento) tienen dos operandos:
• El registro W (con o sin dirección) 
modificador) o registro de archivo (especificado por el valor de 
'Ws' o 'f') 
• El bit en el registro W o registro de archivo 
(especificado por un valor literal o indirectamente por el 
contenido del registro 'Wb') 
Las instrucciones literales que impliquen movimiento de datos podrán
Utilice algunos de los siguientes operandos:
• Un valor literal que se cargará en un registro o archivo W 
registro (especificado por el valor de 'k') 
• El registro W o registro de archivo donde se encuentra el literal 
se va a cargar el valor (especificado por 'Wb' o 'f')
Sin embargo, las instrucciones literales que involucran aritmética o
Las operaciones lógicas utilizan algunos de los siguientes operandos:
• El primer operando fuente que es un registro 'Wb' 
sin ningún modificador de dirección
• El segundo operando fuente, que es un literal. 
valor
• El destino del resultado (sólo si no es el mismo 
como primer operando fuente) que normalmente es un 
registrar 'Wd' con o sin un modificador de dirección
La clase MAC de instrucciones DSP puede utilizar algunas de las
siguientes operandos:
• El acumulador (A o B) a utilizar (requerido 
operando)
• Los registros W se utilizarán como dos operandos.
• Las operaciones de captación previa del espacio de direcciones X e Y
• Los destinos de captación previa del espacio de direcciones X e Y
• El destino de reescritura del acumulador
Las otras instrucciones DSP no implican ningún
multiplicación y puede incluir:
• El acumulador a utilizar (requerido)
• El operando de origen o destino (designado como 
Wso o Wdo, respectivamente) con o sin 
modificador de dirección 
• La cantidad de desplazamiento especificada por un registro W 'Wn' 
o un valor literal
Las instrucciones de control pueden utilizar algunos de los siguientes
operandos:
• Una dirección de memoria de programa 
• El modo de lectura y escritura de la tabla. 
instrucciones 
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
familia de dispositivos. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la sección relacionada
en la “Referencia de la familia dsPIC33F
Manual”, que está disponible en el
Sitio web de Microchip (www.microchip.com).

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 246
© 2009 Microchip Technology Inc.
Todas las instrucciones son una sola palabra, excepto ciertas
doble palabra 
instrucciones, 
cual 
fueron 
hecho
instrucciones de dos palabras para que todos los requeridos
La información está disponible en estos 48 bits. en el segundo
Es decir, los 8 MSbs son '0'. Si esta segunda palabra es
ejecutado como una instrucción (por sí mismo), se ejecutará como
un NOP. 
La mayoría de las instrucciones de una sola palabra se ejecutan en una sola
ciclo de instrucción, a menos que una prueba condicional sea verdadera, o la
El contador del programa cambia como resultado de la
instrucción. En estos casos, la ejecución tarda dos
ciclos de instrucción con el ciclo(s) de instrucción adicional
ejecutado como NOP. Las excepciones notables son el BRA
(rama incondicional/calculada), CALL/GOTO indirecto,
todas las tablas leen y escriben y RETURN/RETFIE
instrucciones, que son instrucciones de una sola palabra pero que toman
dos o tres ciclos. Ciertas instrucciones que implican saltarse
ping sobre la instrucción posterior requiere dos
o tres ciclos si se realiza el salto, dependiendo de
si la instrucción que se omite es una sola palabra o
instrucción de dos palabras. Además, los movimientos de dos palabras
requieren dos ciclos. Las instrucciones de dos palabras.
ejecutar en dos ciclos de instrucción. 
  
Nota:
Para obtener más detalles sobre el conjunto de instrucciones,
consulte el “Manual del programador dsPIC30F/33F”.
Manual de referencia” (DS70157).
TABLA 23-1:
SÍMBOLOS UTILIZADOS EN LAS DESCRIPCIONES DE CÓDIGOS DE OPCIÓN
campo
Descripción
#texto
Significa literal definido por "texto"
(texto)
Significa "contenido del texto"
[texto]
Significa "la ubicación a la que se dirige el texto"
{ }
Campo u operación opcional
<n:m>
Campo de bits de registro
.b
Selección del modo de bytes
.d
Selección del modo de doble palabra
.S
Seleccionar registro de sombra
.w
Selección de modo de palabra (predeterminado)
Acc
Uno de los dos acumuladores {A, B}
AWB
Registro de dirección de destino de reescritura del acumulador ∈ {W13, [W13]+ = 2}
bit4
Campo de selección de bits de 4 bits (utilizado en instrucciones con dirección de palabra) ∈ {0...15}
C, CC, N, OV, Z
Bits de estado de MCU: acarreo, acarreo de dígitos, negativo, desbordamiento, cero fijo
Expr.
Dirección, etiqueta o expresión absoluta (resuelta por el vinculador)
f
Dirección de registro de archivo ∈ {0x0000...0x1FFF}
lit1
Literal sin signo de 1 bit ∈ {0,1}
lit4
Literal sin signo de 4 bits ∈ {0...15}
lit5
Literal sin signo de 5 bits ∈ {0...31}
lit8
Literal sin signo de 8 bits ∈ {0...255}
iluminado10
Literal sin signo de 10 bits ∈ {0...255} para el modo Byte, {0:1023} para el modo Word
iluminado14
Literal sin signo de 14 bits ∈ {0...16384}
iluminado16
Literal sin signo de 16 bits ∈ {0...65535}
lit23
Literal sin signo de 23 bits ∈ {0...8388608}; LSb debe ser '0'
Ninguno
El campo no requiere entrada, puede estar en blanco
OA, OB, SA, SB
Bits de estado DSP: AccA Overflow, AccB Overflow, AccA Saturate, AccB Saturate
ordenador personal
Contador de programas
hendidura10
Literal con signo de 10 bits ∈ {-512...511}
hendidura16
Literal con signo de 16 bits ∈ {-32768...32767}
rendija6
Literal con signo de 6 bits ∈ {-16...16}
Wb
Registro base W ∈ {W0..W15}
Wd
Registro W de destino ∈ { Wd, [Wd], [Wd++], [Wd--], [++Wd], [--Wd] }
wdo
Registro W de destino ∈ 
{ Viento, [Viento], [Viento++], [Viento--], [++Viento], [--Viento], [Viento+Wb] } 
Wm,Wn
Dividendo, par de registros de trabajo del divisor (direccionamiento directo)

© 2009 Microchip Technology Inc.
DS70286C-página 247
dsPIC33FJXXXGPX06/X08/X10
Wm*Wm
Par de registros de trabajo multiplicando y multiplicador para instrucciones Square ∈ 
{W4 * W4,W5 * W5,W6 * W6,W7 * W7} 
Wm*Wn
Par de registros de trabajo multiplicando y multiplicador para instrucciones DSP ∈
{W4 * W5,W4 * W6,W4 * W7,W5 * W6,W5 * W7,W6 * W7}
Wn
Uno de los 16 registros de trabajo ∈ {W0..W15}
viento
Uno de los 16 registros de trabajo de destino ∈ {W0...W15}
Wns
Uno de los 16 registros de trabajo fuente ∈ {W0...W15}
WREG
W0 (registro de trabajo utilizado en las instrucciones de registro de archivos)
Ws
Registro fuente W ∈ { Ws, [Ws], [Ws++], [Ws--], [++Ws], [--Ws] }
Wso
Registro fuente W ∈ 
{ Wns, [Wns], [Wns++], [Wns--], [++Wns], [--Wns], [Wns+Wb] } 
Wx
Registro de dirección de captación previa del espacio de datos X para instrucciones DSP 
∈{[W8]+ = 6, [W8]+ = 4, [W8]+ = 2, [W8], [W8]- = 6, [W8]- = 4, [W8]- = 2,
     [W9]+ = 6, [W9]+ = 4, [W9]+ = 2, [W9], [W9]- = 6, [W9]- = 4, [W9]- = 2,
     [S9 + W12], ninguno}
Wxd
Registro de destino de captación previa del espacio de datos X para instrucciones DSP ∈ {W4...W7}
Wy
Registro de direcciones de captación previa del espacio de datos Y para instrucciones DSP 
∈{[W10]+ = 6, [W10]+ = 4, [W10]+ = 2, [W10], [W10]- = 6, [W10]- = 4, [W10]- = 2,
     [W11]+ = 6, [W11]+ = 4, [W11]+ = 2, [W11], [W11]- = 6, [W11]- = 4, [W11]- = 2,
     [W11 + W12], ninguno}
Wyd
Registro de destino de captación previa del espacio de datos Y para instrucciones DSP ∈ {W4...W7}
TABLA 23-1:
SÍMBOLOS UTILIZADOS EN LAS DESCRIPCIONES DE CÓDIGOS DE OPCIÓN (CONTINUACIÓN)
campo
Descripción

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 248
© 2009 Microchip Technology Inc.
TABLA 23-2:
RESUMEN DEL JUEGO DE INSTRUCCIONES    
bases
instrucción
#
Asamblea
mnemotécnico
Sintaxis de ensamblaje
Descripción
# de 
palabras
# de 
Ciclos
Banderas de estado 
Afectados
1
AÑADIR
AÑADIR
Acc
Agregar acumuladores
1
1
OA, OB, SA, SB
AÑADIR
f
f = f + WREG
1
1
C,CC,N,OV,Z
AÑADIR
f,WREG
WREG = f + WREG
1
1
C,CC,N,OV,Z
AÑADIR
#lit10,Wn
Wd = lit10 + Wd
1
1
C,CC,N,OV,Z
AÑADIR
Wb,Ws,Wd
Wd = Wb + Ws
1
1
C,CC,N,OV,Z
AÑADIR
Wb,#lit5,Wd
Wd = Wb + lit5
1
1
C,CC,N,OV,Z
AÑADIR
Wso,#Slit4,Acc
Agregar al acumulador firmado de 16 bits
1
1
OA, OB, SA, SB
2
ADDC
ADDC
f
f = f + WREG + (C)
1
1
C,CC,N,OV,Z
ADDC
f,WREG
WREG = f + WREG + (C)
1
1
C,CC,N,OV,Z
ADDC
#lit10,Wn
Wd = lit10 + Wd + (C)
1
1
C,CC,N,OV,Z
ADDC
Wb,Ws,Wd
Wd = Wb + Ws + (C)
1
1
C,CC,N,OV,Z
ADDC
Wb,#lit5,Wd
Wd = Wb + lit5 + (C)
1
1
C,CC,N,OV,Z
3
Y
Y
f
f = f .Y. WREG
1
1
N,Z
Y
f,WREG
WREG = f .Y. WREG
1
1
N,Z
Y
#lit10,Wn
Wd = lit10 .Y. Wd
1
1
N,Z
Y
Wb,Ws,Wd
Wd = Wb .Y. Ws
1
1
N,Z
Y
Wb,#lit5,Wd
Wd = Wb .Y. lit5
1
1
N,Z
4
ASR
ASR
f
f = Desplazamiento aritmético a la derecha f
1
1
C,N,OV,Z
ASR
f,WREG
WREG = Desplazamiento aritmético a la derecha f
1
1
C,N,OV,Z
ASR
Ws,Wd
Wd = Desplazamiento aritmético a la derecha Ws
1
1
C,N,OV,Z
ASR
Wb,Wns,Wnd
Wnd = Desplazamiento aritmético a la derecha Wb por Wns
1
1
N,Z
ASR
Wb,#lit5,Wnd
Wnd = Desplazamiento aritmético a la derecha Wb por lit5
1
1
N,Z
5
BCLR
BCLR
f,#bit4
Borrar bits f
1
1
Ninguno
BCLR
Ws,#bit4
Borrar bits Ws
1
1
Ninguno
6
sujetador
sujetador
C,expr.
Rama si lleva
1
1 (2)
Ninguno
sujetador
GE,expr.
Rama si es mayor o igual
1
1 (2)
Ninguno
sujetador
GEU,expr.
Rama si no está firmada mayor o igual
1
1 (2)
Ninguno
sujetador
GT,Exp.
Rama si es mayor que
1
1 (2)
Ninguno
sujetador
GTU,expr.
Rama si no está firmada mayor que
1
1 (2)
Ninguno
sujetador
LE, Expr.
Rama si es menor o igual
1
1 (2)
Ninguno
sujetador
LEU,expr.
Rama si no está firmada menor o igual
1
1 (2)
Ninguno
sujetador
LT,expr.
Sucursal si es menor que
1
1 (2)
Ninguno
sujetador
LTU,expr.
Rama si no está firmada menos de
1
1 (2)
Ninguno
sujetador
N,expr.
Rama si es negativo
1
1 (2)
Ninguno
sujetador
NC, Expr.
Rama si no se lleva
1
1 (2)
Ninguno
sujetador
NN, Expr
Rama si no es negativo
1
1 (2)
Ninguno
sujetador
NOV, exp.
Rama si no se desborda
1
1 (2)
Ninguno
sujetador
Nueva Zelanda, Expr.
Rama si no es cero
1
1 (2)
Ninguno
sujetador
OA,expr.
Rama si el acumulador A se desborda
1
1 (2)
Ninguno
sujetador
OB,expr.
Rama si el acumulador B se desborda
1
1 (2)
Ninguno
sujetador
OV,expr.
Rama si se desborda
1
1 (2)
Ninguno
sujetador
SA,expr.
Rama si el acumulador A está saturado
1
1 (2)
Ninguno
sujetador
SB,expr.
Ramifica si el acumulador B está saturado
1
1 (2)
Ninguno
sujetador
Expr.
Ramificar incondicionalmente 
1
2
Ninguno
sujetador
Z, Expr
Rama si cero
1
1 (2)
Ninguno
sujetador
Wn
Rama Computada
1
2
Ninguno
7
BSET
BSET
f,#bit4
Juego de bits f
1
1
Ninguno
BSET
Ws,#bit4
Juego de puntas Ws
1
1
Ninguno
8
BSW
BSW.C
Ws,Wb
Escribe el bit C en Ws<Wb>
1
1
Ninguno
BSW.Z
Ws,Wb
Escribe el bit Z en Ws<Wb>
1
1
Ninguno
9
BTG
BTG
f,#bit4
Cambio de bits f
1
1
Ninguno
BTG
Ws,#bit4
Cambio de bits Ws
1
1
Ninguno

© 2009 Microchip Technology Inc.
DS70286C-página 249
dsPIC33FJXXXGPX06/X08/X10
10
BTSC
BTSC
f,#bit4
Prueba de bits f, omitir si está claro
1
1 
(2 o 3)
Ninguno
BTSC
Ws,#bit4
Prueba de bits Ws, omitir si está claro
1
1 
(2 o 3)
Ninguno
11
BTSS
BTSS
f,#bit4
Prueba de bits f, omitir si está configurado
1
1 
(2 o 3)
Ninguno
BTSS
Ws,#bit4
Prueba de bits Ws, omitir si está configurado
1
1 
(2 o 3)
Ninguno
12
BTST
BTST
f,#bit4
Prueba de bits f
1
1
z
BTST.C
Ws,#bit4
Prueba de bits Ws a C
1
1
c
BTST.Z
Ws,#bit4
Prueba de bits Ws a Z
1
1
z
BTST.C
Ws,Wb
Prueba de bits Ws<Wb> a C 
1
1
c
BTST.Z
Ws,Wb
Prueba de bits Ws<Wb> a Z
1
1
z
13
BTSTS
BTSTS
f,#bit4
Prueba de bits y luego configure f
1
1
z
BTSTS.C
Ws,#bit4
Prueba de bits Ws a C, luego configurar
1
1
c
BTSTS.Z
Ws,#bit4
Prueba de bits Ws a Z, luego establece
1
1
z
14
LLAMADA
LLAMADA
lit23
Llamar a subrutina
2
2
Ninguno
LLAMADA
Wn
Llamar a subrutina indirecta
1
2
Ninguno
15
CLR
CLR
f
f = 0x0000
1
1
Ninguno
CLR
WREG
WREG = 0x0000
1
1
Ninguno
CLR
Ws
Ws = 0x0000
1
1
Ninguno
CLR
Acc,Wx,Wxd,Wy,Wyd,AWB
Limpiar acumulador
1
1
OA, OB, SA, SB
16
CLRWDT
CLRWDT
Borrar temporizador de vigilancia
1
1
WDTO, dormir
17
COM
COM
f
f = f
1
1
N,Z
COM
f,WREG
WREG = f
1
1
N,Z
COM
Ws,Wd
Wd = Ws
1
1
N,Z
18
CP
CP
f
Comparar f con WREG
1
1
C,CC,N,OV,Z
CP
Wb,#encendido5
Comparar Wb con lit5
1
1
C,CC,N,OV,Z
CP
Wb,Ws
Comparar Wb con Ws (Wb – Ws)
1
1
C,CC,N,OV,Z
19
CP0
CP0
f
Comparar f con 0x0000
1
1
C,CC,N,OV,Z
CP0
Ws
Comparar Ws con 0x0000
1
1
C,CC,N,OV,Z
20
CPB
CPB
f
Comparar f con WREG, con Borrow
1
1
C,CC,N,OV,Z
CPB
Wb,#encendido5
Comparar Wb con lit5, con Borrow
1
1
C,CC,N,OV,Z
CPB
Wb,Ws
Compare Wb con Ws, con Préstamo
 (Wb – Ws – C)
1
1
C,CC,N,OV,Z
21
CPSEQ
CPSEQ
Wb, Wn
Compare Wb con Wn, omita si =
1
1 
(2 o 3)
Ninguno
22
CPSGT
CPSGT
Wb, Wn
Compare Wb con Wn, omita si >
1
1 
(2 o 3)
Ninguno
23
CPSLT
CPSLT
Wb, Wn
Compare Wb con Wn, omita si <
1
1 
(2 o 3)
Ninguno
24
CPSNE
CPSNE
Wb, Wn
Compare Wb con Wn, omita si ≠
1
1 
(2 o 3)
Ninguno
25
DAW
DAW
Wn
Wn = ajuste decimal Wn
1
1
c
26
DIC
DIC
f
f = f – 1
1
1
C,CC,N,OV,Z
DIC
f,WREG
WREG = f – 1
1
1
C,CC,N,OV,Z
DIC
Ws,Wd
Wd = Ws – 1
1
1
C,CC,N,OV,Z
27
DIC2
DIC2
f
f = f – 2
1
1
C,CC,N,OV,Z
DIC2
f,WREG
WREG = f – 2
1
1
C,CC,N,OV,Z
DIC2
Ws,Wd
Wd = Ws – 2
1
1
C,CC,N,OV,Z
28
DISI
DISI
#lit14
Deshabilitar interrupciones para k ciclos de instrucción
1
1
Ninguno
TABLA 23-2:
RESUMEN DEL CONJUNTO DE INSTRUCCIONES (CONTINUACIÓN)   
bases
instrucción
#
Asamblea
mnemotécnico
Sintaxis de ensamblaje
Descripción
# de 
palabras
# de 
Ciclos
Banderas de estado 
Afectados

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 250
© 2009 Microchip Technology Inc.
29
DIV
DIV.S 
Wm,Wn
División entera de 16/16 bits con signo
1
18
N, Z, C, OV
DIV.SD
Wm,Wn
División entera de 32/16 bits con signo
1
18
N, Z, C, OV
DIV.U
Wm,Wn
División entera de 16/16 bits sin signo
1
18
N, Z, C, OV
DIV.UD
Wm,Wn
División entera de 32/16 bits sin signo
1
18
N, Z, C, OV
30
DIVF
DIVF Wm,Wn
División fraccionaria firmada de 16/16 bits
1
18
N, Z, C, OV
31
HACER
HACER
#lit14,expr.
Hacer código a PC + Expr, lit14 + 1 veces
2
2
Ninguno
HACER
Wn, Expr
Hacer código a PC + Expr, (Wn) + 1 veces
2
2
Ninguno
32
DE
DE
Wm*Wm,Acc,Wx,Wy,Wxd
Distancia euclidiana (sin acumulación)
1
1
OA,OB,OAB,
SA,SB,SAB
33
EDAC
EDAC
Wm*Wm,Acc,Wx,Wy,Wxd
Distancia euclidiana 
1
1
OA,OB,OAB,
SA,SB,SAB
34
EXCH
EXCH
Wns,Wnd
Intercambiar Wns con Wnd 
1
1
Ninguno
35
FBCL
FBCL
Ws, viento
Buscar cambio de bits desde el lado izquierdo (MSb) 
1
1
c
36
FF1L
FF1L
Ws, viento
Encuentre el primero desde el lado izquierdo (MSb) 
1
1
c
37
FF1R
FF1R
Ws, viento
Encuentre el primero desde el lado derecho (LSb) 
1
1
c
38
IR A
IR A
Expr.
Ir a la dirección
2
2
Ninguno
IR A
Wn
Ir a indirecto
1
2
Ninguno
39
INC
INC
f
f = f + 1
1
1
C,CC,N,OV,Z
INC
f,WREG
WREG = f + 1
1
1
C,CC,N,OV,Z
INC
Ws,Wd
Wd = Ws + 1
1
1
C,CC,N,OV,Z
40
INC2
INC2
f
f = f + 2
1
1
C,CC,N,OV,Z
INC2
f,WREG
WREG = f + 2
1
1
C,CC,N,OV,Z
INC2
Ws,Wd
Wd = Ws + 2
1
1
C,CC,N,OV,Z
41
IOR
IOR
f
f = f .IOR. WREG
1
1
N,Z
IOR
f,WREG
WREG = f .IOR. WREG
1
1
N,Z
IOR
#lit10,Wn
Wd = lit10 .IOR. Wd
1
1
N,Z
IOR
Wb,Ws,Wd
Wd = Wb .IOR. Ws
1
1
N,Z
IOR
Wb,#lit5,Wd
Wd = Wb .IOR. lit5
1
1
N,Z
42
ALC
ALC
Wso,#Slit4,Acc
Acumulador de carga
1
1
OA,OB,OAB,
SA,SB,SAB
43
LNK
LNK
#lit14
Puntero de marco de enlace
1
1
Ninguno
44
LSR
LSR
f
f = Desplazamiento lógico a la derecha f
1
1
C,N,OV,Z
LSR
f,WREG
WREG = Desplazamiento lógico a la derecha f
1
1
C,N,OV,Z
LSR
Ws,Wd
Wd = Desplazamiento lógico a la derecha Ws
1
1
C,N,OV,Z
LSR
Wb,Wns,Wnd
Wnd = Desplazamiento lógico a la derecha Wb por Wns
1
1
N,Z
LSR
Wb,#lit5,Wnd
Wnd = Desplazamiento lógico a la derecha Wb por lit5
1
1
N,Z
45
MAC
MAC
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd
,
AWB
Multiplicar y acumular
1
1
OA,OB,OAB,
SA,SB,SAB
MAC
Wm*Wm,Acc,Wx,Wxd,Wy,Wyd
Cuadrar y acumular
1
1
OA,OB,OAB,
SA,SB,SAB
46
MOVIMIENTO
MOVIMIENTO
f,Wn
Mover f a Wn
1
1
Ninguno
MOVIMIENTO
f
Mover f a f
1
1
N,Z
MOVIMIENTO
f,WREG
Mover f a WREG
1
1
N,Z
MOVIMIENTO
#lit16,Wn
Mover literal de 16 bits a Wn
1
1
Ninguno
MOV.b
#lit8,Wn
Mover literal de 8 bits a Wn
1
1
Ninguno
MOVIMIENTO
Wn,f
Mover Wn a f
1
1
Ninguno
MOVIMIENTO
Wso,Wdo
Mover Ws a Wd
1
1
Ninguno
MOVIMIENTO
WREG,f
Mover WREG a f
1
1
N,Z
MOV.D Wns,Wd
Mover el doble de W(ns):W(ns + 1) a Wd
1
2
Ninguno
MOV.D Ws,Wnd
Mover el doble de Ws a W(nd + 1):W(nd) 
1
2
Ninguno
47
MOVSAC
MOVSAC
Acc,Wx,Wxd,Wy,Wyd,AWB
Precargar y almacenar acumulador
1
1
Ninguno
TABLA 23-2:
RESUMEN DEL CONJUNTO DE INSTRUCCIONES (CONTINUACIÓN)   
bases
instrucción
#
Asamblea
mnemotécnico
Sintaxis de ensamblaje
Descripción
# de 
palabras
# de 
Ciclos
Banderas de estado 
Afectados

© 2009 Microchip Technology Inc.
DS70286C-página 251
dsPIC33FJXXXGPX06/X08/X10
48
MPY
MPY            
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd
Multiplique Wm por Wn al acumulador
1
1
OA,OB,OAB,
SA,SB,SAB
MPY            
Wm*Wm,Acc,Wx,Wxd,Wy,Wyd
Wm cuadrado a acumulador
1
1
OA,OB,OAB,
SA,SB,SAB
49
MPY.N
MPY.N         
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd
-(Multiplicar Wm por Wn) al acumulador
1
1
Ninguno
50
MSC
MSC
Wm*Wm,Acc,Wx,Wxd,Wy,Wyd
,
AWB
Multiplicar y restar del acumulador
1
1
OA,OB,OAB,
SA,SB,SAB
51
MUL
MUL.SS
Wb,Ws,Wnd
{Wnd + 1, Wnd} = firmado(Wb) * firmado(Ws)
1
1
Ninguno
MUL.SU
Wb,Ws,Wnd
{Wnd + 1, Wnd} = con signo (Wb) * sin signo (Ws)
1
1
Ninguno
MUL.US
Wb,Ws,Wnd
{Wnd + 1, Wnd} = sin firmar (Wb) * con signo (Ws)
1
1
Ninguno
MUL.UU
Wb,Ws,Wnd
{Wnd + 1, Wnd} = sin firmar (Wb) * 
sin firmar(Ws)
1
1
Ninguno
MUL.SU
Wb,#lit5,Wnd
{Wnd + 1, Wnd} = firmado(Wb) * sin firmar(lit5)
1
1
Ninguno
MUL.UU
Wb,#lit5,Wnd
{Wnd + 1, Wnd} = sin firmar (Wb) * 
sin firmar (lit5)
1
1
Ninguno
MUL
f
W3:W2 = f * WREG 
1
1
Ninguno
52
NEG
NEG
Acc
Negar acumulador
1
1
OA,OB,OAB,
SA,SB,SAB
NEG
f
f = f + 1
1
1
C,CC,N,OV,Z
NEG
f,WREG
WREG = f + 1
1
1
C,CC,N,OV,Z
NEG
Ws,Wd
Wd = Ws + 1
1
1
C,CC,N,OV,Z
53
NOP
NOP
Sin operación
1
1
Ninguno
NOPR
Sin operación
1
1
Ninguno
54
POP
POP
f
Pop f desde la parte superior de la pila (TOS)
1
1
Ninguno
POP
wdo
Pop del Top-of-Stack (TOS) a Wdo
1
1
Ninguno
POP.D
viento
Pop desde Top-of-Stack (TOS) a 
W(nd):W(nd + 1)
1
2
Ninguno
POP.S
Registros de sombras pop
1
1
Todos
55
EMPUJAR
EMPUJAR
f
Empuje f a la parte superior de la pila (TOS)
1
1
Ninguno
EMPUJAR
Wso
Empuje Wso a la parte superior de la pila (TOS)
1
1
Ninguno
EMPUJAR.D
Wns
Empuje W(ns):W(ns + 1) a la parte superior de la pila (TOS)
1
2
Ninguno
EMPUJAR.S
Empujar registros de sombra
1
1
Ninguno
56
PWRSAV
PWRSAV #lit1
Entra en modo de suspensión o inactivo
1
1
WDTO, dormir
57
LLAMADA
LLAMADA
Expr.
Llamada relativa
1
2
Ninguno
LLAMADA
Wn
Llamada computada
1
2
Ninguno
58
REPETIR
REPETIR
#lit14
Repita la siguiente instrucción lit14 + 1 veces
1
1
Ninguno
REPETIR
Wn
Repita la siguiente instrucción (Wn) + 1 veces
1
1 
Ninguno
59
REINICIAR
REINICIAR
Restablecer dispositivo de software
1
1 
Ninguno
60
REFIE
REFIE
Regreso de la interrupción 
1
3 (2)
Ninguno
61
RETLW
RETLW
#lit10,Wn
Regresar con literal en Wn
1
3 (2)
Ninguno
62
VOLVER
VOLVER
Regresar de la subrutina
1
3 (2)
Ninguno
63
RLC
RLC
f
f = Girar hacia la izquierda hasta Llevar f
1
1
C,N,Z
RLC
f,WREG
WREG = Girar a la izquierda hasta Llevar f
1
1
C,N,Z
RLC
Ws,Wd
Wd = Girar a la izquierda a través de Llevar Ws
1
1
C,N,Z
64
RLNC
RLNC
f
f = Girar a la izquierda (sin transporte) f
1
1
N,Z
RLNC
f,WREG
WREG = Girar a la izquierda (sin transporte) f
1
1
N,Z
RLNC
Ws,Wd
Wd = Girar a la izquierda (sin transporte) Ws
1
1
N,Z
65
RRC
RRC
f
f = Girar a la derecha hasta Llevar f
1
1
C,N,Z
RRC
f,WREG
WREG = Girar a la derecha hasta Llevar f
1
1
C,N,Z
RRC
Ws,Wd
Wd = Girar a la derecha a través de Llevar Ws
1
1
C,N,Z
TABLA 23-2:
RESUMEN DEL CONJUNTO DE INSTRUCCIONES (CONTINUACIÓN)   
bases
instrucción
#
Asamblea
mnemotécnico
Sintaxis de ensamblaje
Descripción
# de 
palabras
# de 
Ciclos
Banderas de estado 
Afectados

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 252
© 2009 Microchip Technology Inc.
66
RRNC
RRNC
f
f = Girar a la derecha (sin transporte) f
1
1
N,Z
RRNC
f,WREG
WREG = Girar a la derecha (sin transporte) f
1
1
N,Z
RRNC
Ws,Wd
Wd = Girar a la derecha (sin transporte) Ws
1
1
N,Z
67
SACO
SACO
Acc,#Slit4,Wdo
Acumulador de tienda
1
1
Ninguno
SAC.R
Acc,#Slit4,Wdo
Almacenar acumulador redondeado
1
1
Ninguno
68
SE
SE
Ws, viento
Wnd = Ws con signo extendido
1
1
C,N,Z
69
SETM
SETM
f
f = 0xFFFF
1
1
Ninguno
SETM
WREG
WREG = 0xFFFF
1
1
Ninguno
SETM
Ws
Ws = 0xFFFF
1
1
Ninguno
70
SFTAC
SFTAC
Acc, Wn
Acumulador de desplazamiento aritmético por (Wn)
1
1
OA,OB,OAB,
SA,SB,SAB
SFTAC
Acc,#Rendija6
Acumulador de desplazamiento aritmético de Slit6 
1
1
OA,OB,OAB,
SA,SB,SAB
71
SL
SL
f
f = Desplazamiento a la izquierda f
1
1
C,N,OV,Z
SL
f,WREG
WREG = Desplazamiento a la izquierda f
1
1
C,N,OV,Z
SL
Ws,Wd
Wd = Desplazamiento a la izquierda Ws
1
1
C,N,OV,Z
SL
Wb,Wns,Wnd
Wnd = Desplazamiento a la izquierda Wb por Wns
1
1
N,Z
SL
Wb,#lit5,Wnd
Wnd = Desplazamiento a la izquierda Wb por lit5
1
1
N,Z
72
SUB
SUB
Acc
Restar acumuladores
1
1
OA,OB,OAB,
SA,SB,SAB
SUB
f
f = f – WREG
1
1
C,CC,N,OV,Z
SUB
f,WREG
WREG = f – WREG
1
1
C,CC,N,OV,Z
SUB
#lit10,Wn
Wn = Wn – lit10
1
1
C,CC,N,OV,Z
SUB
Wb,Ws,Wd
Wd = Wb – Ws
1
1
C,CC,N,OV,Z
SUB
Wb,#lit5,Wd
Wd = Wb – lit5
1
1
C,CC,N,OV,Z
73
SUBB
SUBB
f
f = f – WREG – (C)
1
1
C,CC,N,OV,Z
SUBB
f,WREG
WREG = f – WREG – (C)
1
1
C,CC,N,OV,Z
SUBB
#lit10,Wn
Wn = Wn – lit10 – (C)
1
1
C,CC,N,OV,Z
SUBB
Wb,Ws,Wd
Wd = Wb – Ws – (C)
1
1
C,CC,N,OV,Z
SUBB
Wb,#lit5,Wd
Wd = Wb – lit5 – (C)
1
1
C,CC,N,OV,Z
74
SUBR
SUBR
f
f = WREG-f
1
1
C,CC,N,OV,Z
SUBR
f,WREG
WREG = WREG – f
1
1
C,CC,N,OV,Z
SUBR
Wb,Ws,Wd
Wd = Ws – Wb
1
1
C,CC,N,OV,Z
SUBR
Wb,#lit5,Wd
Wd = lit5 – Wb
1
1
C,CC,N,OV,Z
75
SUBBR
SUBBR
f
f = WREG – f – (C)
1
1
C,CC,N,OV,Z
SUBBR
f,WREG
WREG = WREG – f – (C)
1
1
C,CC,N,OV,Z
SUBBR
Wb,Ws,Wd
Wd = Ws – Wb – (C)
1
1
C,CC,N,OV,Z
SUBBR
Wb,#lit5,Wd
Wd = lit5 – Wb – (C)
1
1
C,CC,N,OV,Z
76
INTERCAMBIAR
INTERCAMBIO.b
Wn
Wn = intercambio de mordiscos Wn
1
1
Ninguno
INTERCAMBIAR
Wn
Wn = intercambio de bytes Wn
1
1
Ninguno
77
TBLRDH
TBLRDH
Ws,Wd
Leer Prog<23:16> a Wd<7:0>
1
2
Ninguno
78
TBLRDL
TBLRDL
Ws,Wd
Leer Prog<15:0> a Wd
1
2
Ninguno
79
TBLWTH
TBLWTH
Ws,Wd
Escriba Ws<7:0> en Prog<23:16>
1
2
Ninguno
80
TBLWTL
TBLWTL
Ws,Wd
Escribir Ws en Prog<15:0>
1
2
Ninguno
81
ULNK
ULNK
Puntero de marco de desvinculación
1
1
Ninguno
82
XOR
XOR
f
f = f .XOR. WREG
1
1
N,Z
XOR
f,WREG
WREG = f .XOR. WREG
1
1
N,Z
XOR
#lit10,Wn
Wd = lit10 .XOR. Wd
1
1
N,Z
XOR
Wb,Ws,Wd
Wd = Wb .XOR. Ws
1
1
N,Z
XOR
Wb,#lit5,Wd
Wd = Wb .XOR. lit5
1
1
N,Z
83
ZE
ZE
Ws, viento
Wnd = Ws de extensión cero
1
1
C,Z,N
TABLA 23-2:
RESUMEN DEL CONJUNTO DE INSTRUCCIONES (CONTINUACIÓN)   
bases
instrucción
#
Asamblea
mnemotécnico
Sintaxis de ensamblaje
Descripción
# de 
palabras
# de 
Ciclos
Banderas de estado 
Afectados

© 2009 Microchip Technology Inc.
DS70286C-página 253
dsPIC33FJXXXGPX06/X08/X10
24.0
APOYO AL DESARROLLO
Los microcontroladores PIC® son compatibles con una completa
gama de herramientas de desarrollo de hardware y software:
• Entorno de desarrollo integrado
-Software IDE MPLAB®
• Ensambladores/Compiladores/Enlazadores
- Ensamblador MPASMTM
- Compiladores MPLAB C18 y MPLAB C30 C
- Vinculador de objetos MPLINKTM/
Biblioteca de objetos MPLIBTM
- Ensamblador/Enlazador/Biblioteca MPLAB ASM30
• Simuladores
- Simulador de software MPLAB SIM
• Emuladores
- Emulador en circuito MPLAB ICE 2000
- Emulador en circuito MPLAB REAL ICE™
• Depurador en circuito
-MPLAB ICD 2
• Programadores de dispositivos
- Programador de desarrollo PICSTART® Plus
- Programador de dispositivos MPLAB PM3
- Programador de desarrollo PICkit™ 2
• Demostración y desarrollo de bajo costo 
Placas y kits de evaluación
24.1
Desarrollo Integrado MPLAB 
Software de entorno
El software MPLAB IDE ofrece una facilidad de software
Desarrollo nunca antes visto en 8/16 bits.
mercado de microcontroladores. El IDE MPLAB es un Windows®
Aplicación basada en sistema operativo que contiene:
• Una única interfaz gráfica para todas las herramientas de depuración
- Simulador
- Programador (se vende por separado)
- Emulador (se vende por separado)
- Depurador en circuito (se vende por separado)
• Un editor con todas las funciones y contexto codificado por colores
• Un director de proyectos múltiples
• Ventanas de datos personalizables con edición directa de 
contenidos
• Depuración de código fuente de alto nivel
• Inicializador visual del dispositivo para un registro sencillo 
inicialización
• Pase el mouse sobre la inspección de variables
• Arrastre y suelte variables desde la fuente para observarlas 
ventanas
• Amplia ayuda en línea
• Integración de herramientas selectas de terceros, como 
Compiladores C de software de alta tecnología e IAR 
Compiladores C
El IDE MPLAB le permite:
• Edite sus archivos fuente (ya sean ensamblados o C)
• Ensamblar (o compilar) y descargar con un solo toque 
al emulador PIC MCU y herramientas de simulación 
(actualiza automáticamente toda la información del proyecto)
• Depurar usando:
- Archivos fuente (ensamblado o C)
- Montaje mixto y C
- Código de máquina
MPLAB IDE admite múltiples herramientas de depuración en un
paradigma único de desarrollo, desde la rentabilidad
simuladores, a través de depuradores en circuito de bajo costo, para
emuladores con todas las funciones. Esto elimina el aprendizaje.
curva al actualizar a herramientas con mayor flexibilidad
y poder.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 254
© 2009 Microchip Technology Inc.
24.2
Ensamblador MPASM
El ensamblador MPASM es un ensamblador universal con todas las funciones
Ensamblador de macros para todas las MCU PIC. 
El ensamblador MPASM genera un objeto reubicable
archivos para MPLINK Object Linker, estándar Intel® HEX
archivos, archivos MAP para detallar el uso de la memoria y los símbolos
referencia, archivos LST absolutos que contienen líneas fuente
y código de máquina generado y archivos COFF para
depuración.
Las características del ensamblador MPASM incluyen:
• Integración en proyectos MPLAB IDE
• Macros definidas por el usuario para optimizar 
código ensamblador
• Montaje condicional para usos múltiples. 
archivos fuente
• Directivas que permiten un control total sobre la 
proceso de montaje
24.3
MPLAB C18 y MPLAB C30 
Compiladores C
Desarrollo de código MPLAB C18 y MPLAB C30
Los sistemas son compiladores ANSI C completos para
Microchips 
PIC18 
y 
PIC24 
familias 
de
Microcontroladores y la familia dsPIC30 y dsPIC33.
de controladores de señales digitales. Estos compiladores proporcionan
poderoso 
integración 
capacidades, 
superior 
código
optimización y facilidad de uso que no se encuentran en otros
compiladores. 
Para una fácil depuración a nivel de fuente, los compiladores proporcionan
Información de símbolos optimizada para MPLAB IDE.
depurador.
24.4
Vinculador de objetos MPLINK/
Biblioteca de objetos MPLIB
El MPLINK Object Linker combina reubicable
objetos creados por MPASM Assembler y el
Compilador MPLAB C18 C. Puede vincular objetos reubicables.
de bibliotecas precompiladas, utilizando directivas de un
secuencia de comandos del enlazador. 
La biblioteca de objetos MPLIB gestiona la creación y
modificación de archivos de biblioteca de código precompilado. cuando
una rutina de una biblioteca se llama desde un archivo fuente, sólo
los módulos que contienen esa rutina estarán vinculados en
con la aplicación. Esto permite que grandes bibliotecas sean
utilizado eficientemente en muchas aplicaciones diferentes. 
Las características del vinculador/biblioteca de objetos incluyen:
• Vinculación eficiente de bibliotecas individuales en lugar de muchas 
archivos más pequeños
• Mantenibilidad de código mejorada mediante agrupación 
módulos relacionados juntos
• Creación flexible de bibliotecas con módulo sencillo. 
listado, reemplazo, eliminación y extracción
24,5
Ensamblador, enlazador MPLAB ASM30 
y bibliotecario
MPLAB ASM30 Assembler produce reubicable
código de máquina a partir de lenguaje ensamblador simbólico para
Dispositivos dsPIC30F. El compilador MPLAB C30 C utiliza el
ensamblador para producir su archivo objeto. el ensamblador
genera archivos de objetos reubicables que luego pueden ser
archivado o vinculado con otros archivos de objetos reubicables y
archives para crear un archivo ejecutable. Características notables
del ensamblador incluyen:
• Compatibilidad con todo el conjunto de instrucciones dsPIC30F
• Soporte para datos de punto fijo y punto flotante
• Interfaz de línea de comando
• Amplio conjunto de directivas
• Lenguaje de macros flexible
• Compatibilidad MPLAB-IDE
24.6
Simulador de software MPLAB SIM
El simulador de software MPLAB SIM permite código
desarrollo 
en 
un 
alojado en PC 
medio ambiente 
por
Simulación de PIC MCU y dsPIC® DSC en un
nivel de instrucción. En cualquier instrucción dada, los datos
áreas pueden ser examinadas o modificadas y los estímulos pueden ser
aplicado desde un controlador de estímulos integral.
Los registros se pueden registrar en archivos para mayor tiempo de ejecución
análisis. La pantalla del búfer de seguimiento y del analizador lógico
ampliar el poder del simulador para registrar y rastrear
ejecución de programas, acciones en E/S, la mayoría de los periféricos
y registros internos. 
El simulador de software MPLAB SIM es totalmente compatible
depuración simbólica utilizando el MPLAB C18 y
Compiladores MPLAB C30 C y MPASM y
Ensambladores MPLAB ASM30. El simulador de software
ofrece la flexibilidad de desarrollar y depurar código fuera
del entorno del laboratorio de hardware, convirtiéndolo en un
Excelente y económica herramienta de desarrollo de software.

© 2009 Microchip Technology Inc. 
DS70286C-página 255 
dsPIC33FJXXXGPX06/X08/X10 
24.7 
MPLAB HIELO 2000 
Alto rendimiento 
Emulador en circuito 
El emulador en circuito MPLAB ICE 2000 está diseñado 
Proporcionar al ingeniero de desarrollo de productos una 
conjunto completo de herramientas de diseño de microcontroladores para PIC 
microcontroladores. Control por software del MPLAB ICE 
2000 In-Circuit Emulator es avanzado por MPLAB 
Entorno de Desarrollo Integrado, que permite 
edición, construcción, descarga y depuración de código fuente 
desde un único entorno. 
El MPLAB ICE 2000 es un emulador con todas las funciones 
sistema con rastreo, activación y datos mejorados 
escucha 
características. 
Intercambiable 
procesador 
Los módulos permiten que el sistema se reconfigure fácilmente para 
Emulación de diferentes procesadores. La arquitectura de 
El emulador en circuito MPLAB ICE 2000 permite 
Ampliación para soportar nuevos microcontroladores PIC. 
El sistema emulador en circuito MPLAB ICE 2000 tiene 
ha sido diseñado como un sistema de emulación en tiempo real con 
funciones avanzadas que normalmente se encuentran en más 
costosas herramientas de desarrollo. La plataforma PC y 
El sistema operativo Microsoft® Windows® de 32 bits fue 
elegido para que estas funciones estén disponibles de la mejor manera 
Aplicación sencilla y unificada. 
24.8 
MPLAB REAL ICE en circuito 
Sistema emulador 
El sistema emulador en circuito MPLAB REAL ICE es 
El emulador de alta velocidad de próxima generación de Microchip para 
Dispositivos Microchip Flash DSC y MCU. Se depura y 
programas PIC® Flash MCU y dsPIC® Flash DSC 
con la potente y fácil de usar interfaz gráfica de usuario de 
el entorno de desarrollo integrado MPLAB (IDE), 
incluido con cada kit. 
La sonda MPLAB REAL ICE se conecta al diseño. 
PC del ingeniero mediante una interfaz USB 2.0 de alta velocidad y 
está conectado al objetivo con un conector 
compatible con el popular sistema MPLAB ICD 2 
(RJ11) o con el nuevo de alta velocidad, tolerante al ruido, 
Interconexión de señal diferencial de bajo voltaje (LVDS) 
(CAT5). 
MPLAB REAL ICE se puede actualizar en campo en el futuro 
Descargas de firmware en MPLAB IDE. En próximos 
lanzamientos de MPLAB IDE, nuevos dispositivos serán 
compatible y se agregarán nuevas funciones, como 
puntos de interrupción de software y seguimiento de código ensamblador. 
MPLAB REAL ICE ofrece importantes ventajas sobre 
emuladores competitivos, incluidos los de bajo coste y alta velocidad. 
emulación, vigilancia variable en tiempo real, análisis de trazas, 
puntos de interrupción complejos, una interfaz de sonda robusta y 
cables de interconexión de largo (hasta tres metros). 
24.9 
Depurador en circuito MPLAB ICD 2 
El depurador en circuito de Microchip, MPLAB ICD 2, es un 
poderoso, 
bajo costo, 
tiempo de ejecución 
desarrollo 
herramienta, 
Conexión a la PC host a través de un RS-232 o de alta velocidad. 
Interfaz USB. Esta herramienta está basada en Flash PIC. 
MCU y se puede utilizar para desarrollar estos y otros 
MCU PIC y DSC dsPIC. El MPLAB ICD 2 utiliza 
la capacidad de depuración en circuito integrada en Flash 
dispositivos. Esta característica, junto con la función In-Circuit de Microchip 
De serie 
ProgramaciónTM 
(ICSPTM) 
protocolo, 
ofertas 
Depuración Flash rentable y en circuito desde el 
interfaz gráfica de usuario de MPLAB Integrated 
Entorno de desarrollo. Esto permite al diseñador 
desarrollar y depurar código fuente estableciendo puntos de interrupción, 
variables de paso y observación únicas y CPU 
estados y registros periféricos. Running at full speed 
Permite probar hardware y aplicaciones en condiciones reales. 
tiempo. MPLAB ICD 2 también sirve como desarrollo 
Programador para dispositivos PIC seleccionados. 
24.10 Programador de dispositivos MPLAB PM3 
El programador de dispositivos MPLAB PM3 es universal, 
Programador de dispositivos compatible con CE con programable 
verificación de voltaje en VDDMIN y VDDMAX para 
máxima fiabilidad. Cuenta con una gran pantalla LCD 
(128 x 64) para menús y mensajes de error y un 
conjunto de enchufe modular y desmontable para soportar 
varios tipos de paquetes. El conjunto de cables ICSP está 
incluido como artículo estándar. En modo autónomo, el 
El programador de dispositivos MPLAB PM3 puede leer, verificar y 
programar dispositivos PIC sin una conexión a PC. Puede 
También configure la protección del código en este modo. El MPLAB PM3 
Se conecta a la PC host a través de un cable RS-232 o USB. 
El MPLAB PM3 tiene comunicaciones de alta velocidad y 
algoritmos optimizados para una programación rápida de grandes 
dispositivos de memoria e incorpora una tarjeta SD/MMC para 
almacenamiento de archivos y aplicaciones de datos seguras. 

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 256
© 2009 Microchip Technology Inc.
24.11
Desarrollo PICSTART Plus 
programador
El programador de desarrollo PICSTART Plus es un
Programador prototipo fácil de usar y de bajo costo. eso
Se conecta al PC a través de un puerto COM (RS-232). MPLAB
El software de entorno de desarrollo integrado hace
Utilizar el programador de forma sencilla y eficiente. el
El programador de desarrollo PICSTART Plus admite
la mayoría de los dispositivos PIC en paquetes DIP de hasta 40 pines.
Dispositivos con mayor número de pines, como el PIC16C92X y
PIC17C76X, puede ser compatible con un zócalo adaptador.
El programador de desarrollo PICSTART Plus es CE
compatible.
24.12 Programador de desarrollo PICkit 2
El programador de desarrollo PICkit 2 es un programa de bajo costo
programador y depurador del dispositivo Flash seleccionado con
una interfaz fácil de usar para programar muchos de
Las familias de productos básicos, de gama media y PIC18F de Microchip
Microcontroladores de memoria flash. El kit de inicio PICkit 2
Incluye una placa de desarrollo de prototipos, doce
lecciones secuenciales, software y PICC™ de HI-TECH
Compilador Lite C y está diseñado para ayudar a ponerse al día
rápidamente utilizando microcontroladores PIC. El kit proporciona
todo lo necesario para programar, evaluar y desarrollar
aplicaciones que utilizan el potente procesador de gama media de Microchip.
Familia de microcontroladores de memoria flash.
24.13 Demostración, Desarrollo y 
Juntas de evaluación
Una amplia variedad de programas de demostración, desarrollo y
placas de evaluación para varias MCU PIC y dsPIC
Los DSC permiten un desarrollo rápido de aplicaciones en su totalidad.
sistemas funcionales. La mayoría de las placas incluyen prototipos.
Áreas para agregar circuitos personalizados y proporcionar aplicaciones.
firmware y código fuente para su examen y
modificación.
Las placas admiten una variedad de funciones, incluidas LED,
sensores de temperatura, interruptores, parlantes, RS-232
interfaces, pantallas LCD, potenciómetros y accesorios
Memoria EEPROM.
Las placas de demostración y desarrollo pueden ser
utilizado en entornos de enseñanza, para la creación de prototipos personalizados
circuitos y para aprender sobre varios microcontroladores
aplicaciones.
Además de PICDEM™ y dsPICDEM™
Serie de circuitos de placa de demostración/desarrollo,
Microchip 
tiene 
un 
linea 
de 
evaluación 
equipos 
y
software de demostración para el diseño de filtros analógicos,
Circuitos integrados de seguridad KEELOQ®, CAN, IrDA®, PowerSmart
gestión de baterías, sistema de evaluación SEEVAL®,
ADC Sigma-Delta, detección de caudal y muchos más.
Consulte la página web de Microchip (www.microchip.com)
para ver la lista completa de demostraciones, desarrollo
y kits de evaluación.

© 2009 Microchip Technology Inc.
DS70286C-página 257
dsPIC33FJXXXGPX06/X08/X10
25.0
CARACTERÍSTICAS ELÉCTRICAS
Esta sección proporciona una descripción general de las características eléctricas de dsPIC33FJXXXGPX06/X08/X10. Información adicional
se proporcionará en futuras revisiones de este documento a medida que esté disponible. 
Las clasificaciones máximas absolutas para la familia dsPIC33FJXXXGPX06/X08/X10 se enumeran a continuación. La exposición a estos máximos
Las condiciones de clasificación durante períodos prolongados pueden afectar la confiabilidad del dispositivo. Funcionamiento funcional del dispositivo en estos o en cualquier
No se implican otras condiciones por encima de los parámetros indicados en los listados de operaciones de esta especificación.
Calificaciones máximas absolutas(1) 
Temperatura ambiente bajo polarización................................................................................................... -40°C a +85°C
Temperatura de almacenamiento ................................................................................................................. -65°C a +150°C
Tensión en VDD con respecto a VSS ......................................................................................................... -0,3 V a +4,0 V
Voltaje en cualquier pin analógico y digital combinado y MCLR, con respecto a VSS ......................... -0,3 V a (VDD + 0,3 V)
Voltaje en cualquier pin solo digital con respecto a VSS ................................................................................. -0,3 V a +5,6 V
Voltaje en VCAP/VDDCORE con respecto a VSS ................................................................................. 2,25 V a 2,75 V
Corriente máxima fuera del pin VSS ................................................................................................................300 mA
Corriente máxima en el pin VDD (2).................................................................................................................250 mA
Corriente de salida máxima hundida por cualquier pin de E/S(3).................................................................................................4 mA
Corriente de salida máxima generada por cualquier pin de E/S (3)....................................................................................4 mA
Corriente máxima hundida por todos los puertos .........................................................................................................................200 mA
Corriente máxima generada por todos los puertos(2).................................................................................................................200 mA
    
Nota 1: Las tensiones superiores a las enumeradas en "Clasificaciones máximas absolutas" pueden causar daños permanentes al
dispositivo. Esta es solo una clasificación de estrés y operación funcional del dispositivo en esas o cualquier otra condición.
por encima de los indicados en los listados de operaciones de esta especificación no está implícito. Exposición al máximo
Las condiciones de clasificación durante períodos prolongados pueden afectar la confiabilidad del dispositivo.
2: La corriente máxima permitida es una función de la disipación de potencia máxima del dispositivo (consulte la Tabla 25-2).
3: Las excepciones son CLKOUT, que puede absorber/generar 25 mA, y VREF+, VREF-, SCLx, SDAx, PGECx.
y pines PGEDx, que pueden absorber/generar 12 mA.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 258
© 2009 Microchip Technology Inc.
25.1
Características de CC 
TABLA 25-1:
MIPS DE OPERACIÓN VS. VOLTAJE
Característica
Gama VDD
(en voltios)
Rango de temperatura
(en °C)
MIPS máx.
dsPIC33FJXXXGPX06/X08/X10
DC5
3,0-3,6 V
-40°C a +85°C
40
TABLA 25-2:
CONDICIONES TÉRMICAS DE FUNCIONAMIENTO
Calificación
Símbolo
mín.
tipo
máx.
Unidad
dsPIC33FJXXXGPX06/X08/X10
Rango de temperatura de funcionamiento de la unión
T.J.
-40
—
+125
°C
Rango de temperatura ambiente de funcionamiento
asistencia técnica
-40
—
+85
°C
Disipación de energía:
Disipación de potencia del chip interno:
PINTA = VDD x (IDD - Σ IOH) 
PD
PINTA + PI/O
W.
Disipación de energía del pin de E/S:
E/S = Σ ({VDD - VOH} x IOH) + Σ (VOL x IOL) 
Disipación de potencia máxima permitida
PDMAX
(TJ - TA)/θJA
W.
TABLA 25-3:
CARACTERÍSTICAS DEL EMBALAJE TÉRMICO
Característica
Símbolo
tipo
máx.
Unidad
Notas
Resistencia térmica del paquete, TQFP de 100 pines (14x14x1 mm)
θJA
40
—
°C/W
1
Resistencia térmica del paquete, TQFP de 100 pines (12x12x1 mm)
θJA
40
—
°C/W
1
Resistencia térmica del paquete, TQFP de 80 pines (12x12x1 mm)
θJA
40
—
°C/W
1
Resistencia térmica del paquete, TQFP de 64 pines (10x10x1 mm)
θJA
40
—
°C/W
1
Nota 1:
La unión a la resistencia térmica ambiental, los números Theta-JA (θJA) se logran mediante simulaciones de paquetes.

© 2009 Microchip Technology Inc.
DS70286C-página 259
dsPIC33FJXXXGPX06/X08/X10
TABLA 25-4:
ESPECIFICACIONES DE TEMPERATURA Y VOLTAJE DE CC
CARACTERÍSTICAS DE LA CC
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro 
No. 
Símbolo
Característica
mín.
Tipo(1)
máx.
Unidades
Condiciones
Voltaje de funcionamiento
DC10
Voltaje de suministro
VDD
—
3.0
—
3.6
V
—
DC12
VDR
Voltaje de retención de datos RAM(2)
1.8
—
—
V
—
DC16
VPOR
Voltaje de arranque VDD(4)
para garantizar interna 
Señal de reinicio de encendido
—
—
VSS
V
—
DC17
SVDD
Tasa de aumento de VDD
para garantizar interna
Señal de reinicio de encendido
0,03 
—
—
V/ms
0-3,0 V en 0,1 s
DC18
VCORE
Núcleo VDD(3)
Tensión del regulador interno
2.25
—
2,75
V
El voltaje depende de 
carga, temperatura y 
VDD
Nota 1:
Los datos en la columna "Típico" son de 3,3 V, 25 °C a menos que se indique lo contrario.
2:
Este es el límite al que se puede reducir el VDD sin perder datos de la RAM.
3:
Estos parámetros se caracterizan pero no se prueban en la fabricación.
4:
El voltaje VDD debe permanecer en VSS durante un mínimo de 200 μs para garantizar POR.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 260
© 2009 Microchip Technology Inc.
TABLA 25-5:
CARACTERÍSTICAS DE CC: CORRIENTE DE FUNCIONAMIENTO (IDD)  
CARACTERÍSTICAS DE LA CC
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
Parámetro 
No.
Típico(1)
máx.
Unidades
Condiciones 
Corriente de funcionamiento (IDD)(2)
DC20d
27
30
ma
-40°C
3,3 V
10 MIPS
DC20a
27
30
ma
+25°C
DC20b
27
30
ma
+85°C
DC21d
36
40
ma
-40°C
3,3 V
16 MIPS
DC21a
37
40
ma
+25°C
DC21b
38
45
ma
+85°C
DC22d
43
50
ma
-40°C
3,3 V
20 MIPS
DC22a
46
50
ma
+25°C
DC22b
46
55
ma
+85°C
DC23d
65
70
ma
-40°C
3,3 V
30 MIPS
DC23a
65
70
ma
+25°C
DC23b
65
70
ma
+85°C
DC24d
84
90
ma
-40°C
3,3 V
40 MIPS
DC24a
84
90
ma
+25°C
DC24b
84
90
ma
+85°C
Nota 1:
Los datos de la columna "Típico" son de 3,3 V, 25 °C, a menos que se indique lo contrario.
2:
La corriente de suministro es principalmente una función del voltaje y la frecuencia de operación. Otros factores, como E/S 
La velocidad de carga y conmutación de pines, el tipo de oscilador, el patrón de ejecución del código interno y la temperatura, también tienen 
un impacto en el consumo actual. Las condiciones de prueba para todas las mediciones de IDD son las siguientes: OSC1 
impulsado con onda cuadrada externa de carril a carril. Todos los pines de E/S se configuran como entradas y se conectan a VSS. 
MCLR = VDD, WDT y FSCM están deshabilitados. CPU, SRAM, memoria de programa y memoria de datos son 
operativo. No hay ningún módulo periférico en funcionamiento; sin embargo, cada periférico está sincronizado (bits PMD 
están todos puestos a cero).

© 2009 Microchip Technology Inc.
DS70286C-página 261
dsPIC33FJXXXGPX06/X08/X10
TABLA 25-6:
CARACTERÍSTICAS DE CC: CORRIENTE INACTIVA (IIDLE)  
CARACTERÍSTICAS DE LA CC
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
Parámetro 
No.
Típico(1)
máx.
Unidades
Condiciones
Corriente inactiva (IIDLE): Núcleo APAGADO Reloj ENCENDIDO Corriente base (2)
DC40d
3
25
ma
-40°C
3,3 V
10 MIPS
DC40a
3
25
ma
+25°C
DC40b
3
25
ma
+85°C
DC41d
4
25
ma
-40°C
3,3 V
16 MIPS
DC41a
5
25
ma
+25°C
DC41b
6
25
ma
+85°C
DC42d
8
25
ma
-40°C
3,3 V
20 MIPS
DC42a
9
25
ma
+25°C
DC42b
10
25
ma
+85°C
DC43a
15
25
ma
+25°C
3,3 V
30 MIPS
25
DC43d
15
ma
-40°C
DC43b
15
25
ma
+85°C
DC44d
16
25
ma
-40°C
3,3 V
40 MIPS
DC44a
16
25
ma
+25°C
DC44b
16
25
ma
+85°C
Nota 1:
Los datos de la columna "Típico" son de 3,3 V, 25 °C, a menos que se indique lo contrario.
2:
La corriente base IIDLE se mide con el núcleo apagado, el reloj encendido y todos los módulos apagados. Módulo periférico 
Los registros SFR deshabilitados se ponen a cero. Todos los pines de E/S se configuran como entradas y se conectan a VSS.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 262
© 2009 Microchip Technology Inc.
TABLA 25-7:
CARACTERÍSTICAS DE CC: CORRIENTE DE APAGADO (IPD)  
CARACTERÍSTICAS DE LA CC
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
Parámetro 
No.
Típico(1)
máx.
Unidades
Condiciones
Corriente de apagado (IPD)(2)
DC60d
55
500
µA
-40°C
3,3 V
Corriente de apagado base (3,4)
DC60a
211
500
µA
+25°C
DC60b
244
500
µA
+85°C
DC61d
8
13
µA
-40°C
3,3 V
Corriente del temporizador de vigilancia: ΔIWDT(3)
DC61a
10
15
µA
+25°C
DC61b
12
20
µA
+85°C
Nota 1:
Los datos de la columna Típica son de 3,3 V, 25 °C, a menos que se indique lo contrario.
2:
El IPD base se mide con todos los periféricos y relojes apagados. Todas las E/S están configuradas como entradas y 
tirado a VSS. WDT, etc., están todos apagados y VREGS (RCON<8>) = 1.
3:
La corriente Δ es la corriente adicional consumida cuando el módulo está habilitado. Esta corriente debe ser 
agregado a la corriente IPD base.
4:
Estas corrientes se miden en el dispositivo que contiene más memoria de esta familia.
TABLA 25-8:
CARACTERÍSTICAS DC: CORRIENTE DOZE (IDOZE)
CARACTERÍSTICAS DE LA CC
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
Parámetro 
No.
Típico(1)
máx.
Relación de sueño
Unidades
Condiciones
DC73a
11
35
1:2
ma
-40°C
3,3 V
40 MIPS
DC73f
11
30
1:64
ma
DC73g
11
30
1:128
ma
DC70a
42
50
1:2
ma
+25°C
3,3 V
40 MIPS
DC70f
26
30
1:64
ma
CC70g
25
30
1:128
ma
DC71a
41
50
1:2
ma
+85°C
3,3 V
40 MIPS
DC71f
25
30
1:64
ma
DC71g
24
30
1:128
ma
Nota 1:
Los datos de la columna Típica son de 3,3 V, 25 °C, a menos que se indique lo contrario.

© 2009 Microchip Technology Inc.
DS70286C-página 263
dsPIC33FJXXXGPX06/X08/X10
TABLA 25-9:
CARACTERÍSTICAS DE CC: ESPECIFICACIONES DE ENTRADA DE PIN DE E/S
CARACTERÍSTICAS DE LA CC
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial 
parámetro
 No.
Símbolo
Característica
mín.
Tipo(1)
máx.
Unidades
Condiciones
vil
Entrada de bajo voltaje
DI10
pines de E/S
VSS
—
0,2 VDD
V
DI15
MCLR
VSS
—
0,2 VDD
V
DI16
Pines de E/S con OSC1 o SOSCI
VSS
—
0,2 VDD
V
DI18
Pines de E/S con I2C
VSS
—
0,3 VDD
V
SMbus deshabilitado
DI19
Pines de E/S con I2C 
VSS
—
0,2 VDD
V
SMbus habilitado
vih
Entrada de alto voltaje
DI20
Pines de E/S que no toleran 5 V(4)
Pines de E/S tolerante a 5 V(4)
0,8 VDD
0,8 VDD
—
—
VDD
5.5
V
V
Pines de E/S que no toleran 5 V(4)
Pines de E/S tolerante a 5 V(4)
2
2
—
—
VDD
5.5
V
V
VDD = 3,3 V
VDD = 3,3 V
DI26
Pines de E/S con OSC1 o SOSCI
0,7 VDD
—
VDD
V
DI28
Pines de E/S con I2C
0,7 VDD
—
5.5
V
SMbus deshabilitado
DI29
Pines de E/S con I2C 
0,8 VDD
—
5.5
V
SMbus habilitado
CINPU
Corriente de arranque CNx
DI30
50
250
400
µA
VDD = 3,3 V, VPIN = VSS
IIL
Corriente de fuga de entrada (2,3)
DI50
Pines de E/S
—
—
±2
µA
VSS≤VPIN≤VDD,
Pin en alta impedancia
DI51
Pines de E/S que no toleran 5 V(4)
—
—
±2
µA
VSS≤VPIN≤VDD,
Pin en alta impedancia
DI51a
Pines de E/S que no toleran 5 V(4)
—
—
±2
µA
Compartido con referencia externa. 
alfileres
DI51b
Pines de E/S que no toleran 5 V(4)
—
—
±3,5
µA
VSS ≤ VPIN ≤ VDD, Pin en 
alta impedancia
DI51c
Pines de E/S que no toleran 5 V(4)
—
—
±8
µA
Pines analógicos compartidos con 
pines de referencia externos
DI55
MCLR
—
—
±2
µA
VSS ≤ VPIN ≤ VDD
DI56
OSC1
—
—
±2
µA
VSS≤VPIN≤VDD, 
Modos XT y HS
Nota 1:
Los datos en la columna "Típico" son de 3,3 V, 25 °C a menos que se indique lo contrario.
2:
La corriente de fuga en el pin MCLR depende en gran medida del nivel de voltaje aplicado. El especificado 
Los niveles representan condiciones normales de funcionamiento. Se puede medir una corriente de fuga más alta en diferentes entradas 
voltajes.
3:
La corriente negativa se define como la corriente generada por el pin.
4:
Consulte "Diagramas de pines" para obtener una lista de pines tolerantes a 5 V.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 264
© 2009 Microchip Technology Inc.
 
TABLA 25-10: CARACTERÍSTICAS DE CC: ESPECIFICACIONES DE SALIDA DE PIN DE E/S  
CARACTERÍSTICAS DE LA CC
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro
 No.
Símbolo
Característica
mín.
tipo
máx.
Unidades
Condiciones
VOL
Salida de bajo voltaje
DO10
Puertos de E/S
—
—
0,4
V
LIO = 2 mA, VDD = 3,3 V
DO16
OSC2/CLKO
—
—
0,4
V
LIO = 2 mA, VDD = 3,3 V
VOH
Alto voltaje de salida
DO20
Puertos de E/S
2.40
—
—
V
IOH = -2,3 mA, VDD = 3,3 V
DO26
OSC2/CLKO
2.41
—
—
V
IOH = -1,3 mA, VDD = 3,3 V
TABLA 25-11:
CARACTERÍSTICAS ELÉCTRICAS: BOR
CARACTERÍSTICAS DE LA CC
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro
No.
Símbolo
Característica
Mín(1)
tipo
Máx(1)
Unidades
Condiciones
BO10
VBOR
Evento BOR sobre la transición VDD 
de mayor a menor
El evento BOR está vinculado al voltaje del núcleo VDD 
disminuir
2.40
—
2.55
V
—
Nota 1:
Los parámetros son solo una guía de diseño y no se prueban en la fabricación.

© 2009 Microchip Technology Inc.
DS70286C-página 265
dsPIC33FJXXXGPX06/X08/X10
TABLA 25-13: ESPECIFICACIONES DEL REGULADOR DE VOLTAJE INTERNO
TABLA 25-12: CARACTERÍSTICAS DE CC: MEMORIA DE PROGRAMA
CARACTERÍSTICAS DE LA CC
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro
No.
Símbolo
Característica
mín.
Tipo(1)
máx.
Unidades
Condiciones
Programar memoria flash
D130a
PE
Resistencia celular
100
1000
—
E/O
Ver nota 2
D131
VPR
VDD para lectura
VMIN
—
3.6
V
VMIN = Mínimo operativo 
voltaje
D132B
VPEW
VDD para escritura autoprogramada
VMIN
—
3.6
V
VMIN = Mínimo operativo 
voltaje
D134
TRETT
Retención característica
20
—
—
Año
No proporcionó otras especificaciones 
son violados
D135
IDDP
Corriente de suministro durante 
Programación
—
10
—
ma
D136a
TRW
Tiempo de escritura de fila
1.32
—
1.74
señora
TRW = 11064 ciclos FRC, 
Ver nota 2
D137a
TPE
Tiempo de borrado de página
20.1
—
26,5
señora
TPE = 168517 ciclos FRC, 
Ver nota 2
D138a
tww
Tiempo del ciclo de escritura de palabras
42.3
—
55,9
µs
TWW = 355 ciclos FRC, 
Ver nota 2
Nota 1:
Los datos en la columna "Típico" son de 3,3 V, 25 °C a menos que se indique lo contrario.
2:
Otras condiciones: FRC = 7,37 MHz, TUN<5:0> = b'011111 (para Min), TUN<5:0> = b'100000 (para Max). 
Este parámetro depende de la precisión del FRC (consulte la Tabla 25-19) y del valor del oscilador FRC. 
Registro de sintonización (ver Registro 9-4). Para obtener detalles completos sobre el cálculo del tiempo mínimo y máximo 
consulte la Sección 5.3 “Operaciones de programación”.
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro
No.
Símbolo
Características
mín.
tipo 
máx.
Unidades
Comentarios
CEFC
Condensador de filtro externo 
Valor
4.7
10
—
µF
El condensador debe estar bajo. 
resistencia en serie 
(< 5 ohmios)

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 266
© 2009 Microchip Technology Inc.
25.2
Características y sincronización de CA 
Parámetros 
La información contenida en esta sección define
dsPIC33FJXXXGPX06/X08/X10 Características de CA
y parámetros de sincronización.
TABLA 25-14: ESPECIFICACIONES DE TEMPERATURA Y VOLTAJE – CA  
FIGURA 25-1:
CONDICIONES DE CARGA PARA LAS ESPECIFICACIONES DE TIEMPO DEL DISPOSITIVO 
TABLA 25-15: REQUISITOS DE CARGA CAPACITIVA EN PINS DE SALIDA
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial 
Rango de voltaje de funcionamiento VDD como se describe en la Sección 25.0 “Conexiones eléctricas 
Características”. 
parámetro
 No.
Símbolo
Característica
mín.
tipo
máx.
Unidades
Condiciones
DO50
COSC2
Patilla OSC2/SOSC2
—
—
15
pF
En los modos XT y HS cuando 
El reloj externo se utiliza para conducir. 
OSC1
DO56
CIO
Todos los pines de E/S y OSC2 
—
—
50
pF
modo CE 
DO58
CB
SCLx, SDAx
—
—
400
pF
En modo I2C™
VDD/2
CL
rl
Alfiler
Alfiler
VSS
VSS
CL
RL = 464Ω
CL = 50 pF para todos los pines excepto OSC2
15 pF para salida OSC2
Condición de carga 1: para todos los pines excepto OSC2
Condición de carga 2 - para OSC2

© 2009 Microchip Technology Inc.
DS70286C-página 267
dsPIC33FJXXXGPX06/X08/X10
FIGURA 25-2:
TEMPORIZACIÓN DEL RELOJ EXTERNO    
TABLA 25-16: REQUISITOS DE TIEMPO DEL RELOJ EXTERNO 
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro
No.
sim
bollo
Característica
mín.
Tipo(1)
máx.
Unidades
Condiciones
OS10
aleta
Frecuencia CLKI externa
(Solo se permiten relojes externos
en modos EC y ECPLL)
CC
—
40
MHz
CE
Frecuencia del cristal del oscilador
3.5
10
—
—
—
—
10
40
33
MHz
MHz
kilociclos
xt
SA
SOSC
OS20
TOSC
TOSC = 1/FOSC
12.5
—
CC
ns
—
OS25
TCY
Tiempo del ciclo de instrucción(2)
25
—
CC
ns
—
OS30
tosl,
TosH
Entrada de reloj externo (OSC1)
Tiempo alto o bajo
0,375 x TOSC
—
0,625 x TOSC
ns
CE
OS31
TOSR,
tosf
Entrada de reloj externo (OSC1)
Tiempo de subida o bajada
—
—
20
ns
CE
OS40
TckR
Tiempo de subida de CLKO(3) 
—
5.2
—
ns
—
OS41
TckF
Tiempo de caída de CLKO(3)
—
5.2
—
ns
—
OS42
GM
Oscilador externo 
Transconductancia(4)
14
16
18
mA/V
VDD = 3,3 V
TA = +25ºC
Nota 1:
Los datos en la columna "Típico" son de 3,3 V, 25 °C a menos que se indique lo contrario.
2:
El período del ciclo de instrucción (TCY) es igual a dos veces el período de base de tiempo del oscilador de entrada. Todos los valores especificados 
se basan en datos de caracterización para ese tipo de oscilador en particular en condiciones de funcionamiento estándar 
con el dispositivo ejecutando el código. Exceder estos límites especificados puede resultar en un oscilador inestable 
funcionamiento y/o consumo actual superior al esperado. Todos los dispositivos se prueban para funcionar a "mínimo". 
valores con un reloj externo aplicado al pin OSC1/CLKI. Cuando se utiliza una entrada de reloj externo, el 
"máximo". El límite de tiempo del ciclo es “DC” (sin reloj) para todos los dispositivos.
3:
Las mediciones se toman en modo EC. La señal CLKO se mide en el pin OSC2. 
4:
Los datos para este parámetro son preliminares. Este parámetro se caracteriza, pero no se prueba en la fabricación.
Q1
 Q2
 Q3
Q4
OSC1
CLKO
Q1
Q2
T3 T4
OS20
OS25
OS30
OS30
OS40
OS41
OS31
OS31

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 268
© 2009 Microchip Technology Inc.
TABLA 25-17: ESPECIFICACIONES DE TEMPORIZACIÓN DEL RELOJ PLL (VDD = 3,0 V A 3,6 V)  
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V (a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro
No.
Símbolo
Característica
mín.
Tipo(1)
máx.
Unidades
Condiciones
OS50
FPLLI
PLL controlado por voltaje 
Entrada de oscilador (VCO) 
Rango de frecuencia(2)
0,8
—
8.0
MHz
ECPLL, HSPLL, XTPLL 
modos
OS51
FSYS
Sistema VCO en chip 
Frecuencia
100
—
200
MHz
—
OS52
TLOCK
Tiempo de inicio de PLL (tiempo de bloqueo)
0,9
1.5
3.1
señora
—
OS53
DCLK
Estabilidad CLKO (jitter)
-3.0
0,5
3.0
%
Medido durante 100 ms 
periodo
Nota 1:
Los datos en la columna "Típico" son de 3,3 V, 25 °C a menos que se indique lo contrario.
TABLA 25-18: CARACTERÍSTICAS DE CA: PRECISIÓN INTERNA DEL FRC
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V (a menos que se indique lo contrario)
 Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro 
No.
Característica
mín.
tipo
máx.
Unidades
Condiciones
Precisión interna de FRC a frecuencia FRC = 7,37 MHz(1,2)
F20
FRC
-2
—
+2
%
-40°C ≤ TA ≤ +85°C
VDD = 3,0-3,6 V
Nota 1:
Frecuencia calibrada a 25°C y 3,3V. Los bits TUN se pueden utilizar para compensar la variación de temperatura.
2:
FRC se establece en la frecuencia inicial de 7,37 MHz (±2%) a 25 °C FRC.
TABLA 25-19: PRECISIÓN INTERNA DEL LPRC
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V (a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro
No.
Característica
mín.
tipo
máx.
Unidades
Condiciones
LPRC a 32,768 kHz(1)
F21
LPRC
-20
±6
+20
%
-40°C ≤ TA ≤ +85°C
VDD = 3,0-3,6 V
Nota 1:
Cambio de frecuencia LPRC a medida que cambia VDD.

© 2009 Microchip Technology Inc.
DS70286C-página 269
dsPIC33FJXXXGPX06/X08/X10
FIGURA 25-3:
CLKO Y CARACTERÍSTICAS DE TIEMPO DE E/S   
TABLA 25-20: REQUISITOS DE TEMPORIZACIÓN DE E/S 
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V 
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro
No.
Símbolo
Característica
mín.
Tipo(1)
máx.
Unidades
Condiciones
DO31
TIOR
Tiempo de subida de salida del puerto 
—
10
25
ns
—
DO32
TIOF
Tiempo de caída de salida del puerto
—
10
25
ns
—
DI35
TINP
INTx Pin Tiempo alto o bajo (salida)
20
—
—
ns
—
DI40
TRBP
CNx Tiempo alto o bajo (entrada)
2
—
—
TCY
—
Nota 1:
Los datos en la columna "Típico" son de 3,3 V, 25 °C a menos que se indique lo contrario.
Nota: Consulte la Figura 25-1 para conocer las condiciones de carga.
Pin de E/S
(Entrada)
Pin de E/S
(Salida)
DI35
Valor antiguo
Nuevo valor
DI40
DO31
DO32

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 270
© 2009 Microchip Technology Inc.
FIGURA 25-4:
RESET, TEMPORIZADOR WATCHDOG, TEMPORIZADOR DE ARRANQUE DEL OSCILADOR Y ENCENDIDO 
CARACTERÍSTICAS DEL TEMPORIZADOR       
VDD
MCLR
Interno
POR
PWRT
Tiempo muerto
OSC
Tiempo muerto
Interno
Reiniciar
perro guardián
Temporizador
Reiniciar
SY11
SY10
SY20
SY13
Pines de E/S
SY13
Nota: Consulte la Figura 25-1 para conocer las condiciones de carga.
FCM 
Retraso
SY35 
SY30
SY12

© 2009 Microchip Technology Inc.
DS70286C-página 271
dsPIC33FJXXXGPX06/X08/X10
                               
TABLA 25-21: RESET, TEMPORIZADOR DE VIGILANCIA, TEMPORIZADOR DE ARRANQUE DEL OSCILADOR, TEMPORIZADOR DE ENCENDIDO 
REQUISITOS DE TIEMPO
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro
No.
Símbolo
Característica(1)
mín.
Tipo(2)
máx.
Unidades
Condiciones
SY10
TMCL
Ancho de pulso MCLR (bajo)
2 
—
—
μs
-40°C a +85°C
SY11
TPWRT
Período del temporizador de encendido
—
—
—
—
—
—
—
2
4
8
16
32
64
128
—
—
—
—
—
—
—
señora 
-40°C a +85°C
Programable por el usuario
SY12
TPOR
Retardo de reinicio de encendido
3
10
30
μs
-40°C a +85°C
SY13
TIOZ
E/S de alta impedancia desde 
MCLR bajo o perro guardián 
Reinicio del temporizador
0,68
0,72
1.2
μs
—
SY20
TWDT1
Temporizador de vigilancia 
Período de tiempo de espera 
—
—
—
—
Consulte la Sección 22.4 “Entidad de vigilancia 
Temporizador (WDT)” y LPRC 
especificación F21 (Tabla 25-19)
SY30
TOSTAR
Temporizador de inicio del oscilador 
Periodo
—
1024 TOSC
—
—
TOSC = período OSC1
SY35
TFSCM
Monitor de reloj a prueba de fallos 
Retraso
—
500
900
μs
-40°C a +85°C
Nota 1:
Estos parámetros se caracterizan pero no se prueban en la fabricación.
2:
Los datos en la columna "Típico" son de 3,3 V, 25 °C a menos que se indique lo contrario.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 272
© 2009 Microchip Technology Inc.
FIGURA 25-5:
TIMER1, 2, 3, 4, 5, 6, 7, 8 Y 9 CARACTERÍSTICAS DE TEMPORIZACIÓN DEL RELOJ EXTERNO     
 
      
Nota: Consulte la Figura 25-1 para conocer las condiciones de carga.
Tx11
Tx15
Tx10
Tx20
TMRx
OS60
TxCK
TABLA 25-22: REQUISITOS DE TIEMPO DEL RELOJ EXTERNO DEL TIMER1(1)
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial 
parámetro
No.
Símbolo
Característica
mín.
tipo
máx.
Unidades
Condiciones
TA10
TTXH
Hora alta de TxCK
sincrónico,
sin preescalador
0,5 TCY + 20
—
—
ns
También debe cumplir 
parámetro TA15
sincrónico,
con preescalador
10
—
—
ns
Asíncrono
10
—
—
ns
TA11
TTXL
Tiempo bajo de TxCK
sincrónico,
sin preescalador
0,5 TCY + 20
—
—
ns
También debe cumplir 
parámetro TA15
sincrónico,
con preescalador
10
—
—
ns
Asíncrono
10
—
—
ns
TA15
TTXP
Período de entrada TxCK síncrono,
sin preescalador
TCY + 40
—
—
ns
—
sincrónico,
con preescalador
Mayor de:
20 ns o
(TCY + 40)/N
—
—
—
N = preescala 
valor
(1, 8, 64, 256)
Asíncrono
20
—
—
ns
—
OS60
ft1
Entrada del oscilador SOSC1/T1CK 
Rango de frecuencia (oscilador habilitado 
configurando el bit TCS (T1CON<1>))
CC
—
50
kilociclos
—
TA20
TCKEXTMRL
Retraso del reloj TxCK externo 
Incremento de borde a temporizador
0,5 TCY
—
1,5 TCY
—
—
Nota 1:
Timer1 es un tipo A.

© 2009 Microchip Technology Inc.
DS70286C-página 273
dsPIC33FJXXXGPX06/X08/X10
      
      
TABLA 25-23: TIMER2, TIMER4, TIMER6 Y TIMER8 TEMPORIZACIÓN DEL RELOJ EXTERNO 
REQUISITOS
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro
No.
Símbolo
Característica
mín.
tipo
máx.
Unidades
Condiciones
TB10
TtxH
Hora alta de TxCK
sincrónico,
sin preescalador
0,5 TCY + 20
—
—
ns
También debe cumplir 
parámetro TB15
sincrónico,
con preescalador
10 
—
—
ns
TB11
TtxL
Tiempo bajo de TxCK
sincrónico,
sin preescalador
0,5 TCY + 20
—
—
ns
También debe cumplir 
parámetro TB15
sincrónico,
con preescalador
10
—
—
ns
TB15
TtxP
Entrada TxCK 
Periodo
sincrónico,
sin preescalador
TCY + 40
—
—
ns
N = preescala        
valor
(1, 8, 64, 256)
sincrónico,
con preescalador
Mayor de:
20 ns o
(TCY + 40)/N
TB20
TCKEXT-
LMR
Retraso del reloj TxCK externo 
Incremento de borde a temporizador
0,5 TCY
—
1,5 TCY
—
—
TABLA 25-24: TIMER3, TIMER5, TIMER7 Y TIMER9 TEMPORIZACIÓN DEL RELOJ EXTERNO 
REQUISITOS
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C 
parámetro
No.
Símbolo
Característica
mín.
tipo
máx.
Unidades
Condiciones
TC10
TtxH
Hora alta de TxCK
sincrónico
0,5 TCY + 20
—
—
ns
También debe cumplir 
parámetro TC15
TC11
TtxL
Tiempo bajo de TxCK
sincrónico
0,5 TCY + 20
—
—
ns
También debe cumplir 
parámetro TC15
TC15
TtxP
Período de entrada de TxCK
sincrónico,
sin preescalador
TCY + 40
—
—
ns
N = preescala
valor 
(1, 8, 64, 256)
sincrónico,
con preescalador
Mayor de:
20 ns o 
(TCY + 40)/N
TC20
Retraso TCKEXTMRL del reloj TxCK externo 
Incremento de borde a temporizador
0,5 TCY
—
1.5 
TCY
—
—

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 274
© 2009 Microchip Technology Inc.
FIGURA 25-6:
CARACTERÍSTICAS DE TIEMPO DE CAPTURA DE ENTRADA (CAPx)     
      
FIGURA 25-7:
CARACTERÍSTICAS DE TIEMPO DEL MÓDULO DE COMPARACIÓN DE SALIDA (OCx)      
     
TABLA 25-25: REQUISITOS DE TIEMPO DE CAPTURA DE ENTRADA
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C
parámetro
No.
Símbolo
Característica(1)
mín.
máx.
Unidades
Condiciones
IC10
TccL
Tiempo bajo de entrada ICx
Sin preescalador
0,5 TCY + 20
—
ns
—
Con preescalador
10 
—
ns
IC11
TcH
Tiempo alto de entrada ICx
Sin preescalador
0,5 TCY + 20
—
ns
—
Con preescalador
10 
—
ns
IC15
TCP
Período de entrada ICx
(TCY + 40)/N
—
ns
N = preescala 
valor (1, 4, 16)
Nota 1:
Estos parámetros se caracterizan pero no se prueban en la fabricación.
TABLA 25-26: REQUISITOS DE TIEMPO DEL MÓDULO DE COMPARACIÓN DE SALIDA
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C 
parámetro 
No.
Símbolo
Característica(1)
mín.
tipo
máx.
Unidades
Condiciones
OC10
TccF
Tiempo de caída de salida de OCx
—
—
—
ns
Ver parámetro D032
OC11
TccR
Tiempo de subida de salida de OCx
—
—
—
ns
Ver parámetro D031
Nota 1:
Estos parámetros se caracterizan pero no se prueban en la fabricación.
ICx
IC10
IC11
IC15
Nota: Consulte la Figura 25-1 para conocer las condiciones de carga.
OCx
OC11
OC10
(Comparación de salida
Nota: Consulte la Figura 25-1 para conocer las condiciones de carga.
o modo PWM)

© 2009 Microchip Technology Inc.
DS70286C-página 275
dsPIC33FJXXXGPX06/X08/X10
FIGURA 25-8:
CARACTERÍSTICAS DE TEMPORIZACIÓN DEL MÓDULO OC/PWM    
    
TABLA 25-27: REQUISITOS DE TIEMPO DEL MODO OC/PWM SIMPLE
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C
parámetro 
No.
Símbolo
Característica(1)
mín.
tipo
máx.
Unidades
Condiciones
OC15
TFD
Entrada de fallo a E/S PWM 
Cambiar
—
—
50
ns
—
OC20
TFLT
Ancho de pulso de entrada de falla
50
—
—
ns
—
Nota 1:
Estos parámetros se caracterizan pero no se prueban en la fabricación.
OCFA/OCFB
OCx
 OC20
 OC15

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 276
© 2009 Microchip Technology Inc.
FIGURA 25-9:
MODO MAESTRO DEL MÓDULO SPIx (CKE = 0) CARACTERÍSTICAS DE TEMPORIZACIÓN   
     
SCKx
(CKP = 0)
SCKx
(PCK = 1)
SDOx
SDix
SP11
SP10
SP40 SP41
SP21
SP20
SP35
SP20
SP21
MSb
LSB
Bit 14 - - - - - -1
MSb en
LSb en
Bit 14 - - - -1
SP30
SP31
Nota: Consulte la Figura 25-1 para conocer las condiciones de carga.
TABLA 25-28: REQUISITOS DE TIEMPO DEL MODO MAESTRO SPIx (CKE = 0)
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C 
parámetro
No.
Símbolo
Característica(1)
mín.
Tipo(2)
máx.
Unidades
Condiciones
SP10
Tscl
Tiempo bajo de salida SCKx
TCY/2
—
—
ns
Ver nota 3
SP11
TscH
Tiempo alto de salida SCKx
TCY/2
—
—
ns
Ver nota 3
SP20
TscF
Tiempo de caída de salida SCKx
—
—
—
ns
Ver parámetro D032 
y nota 4
SP21
TscR
Tiempo de subida de salida SCKx
—
—
—
ns
Ver parámetro D031 
y nota 4
SP30
TdF
Tiempo de caída de la salida de datos SDOx
—
—
—
ns
Ver parámetro D032 
y nota 4
SP31
TdoR
Tiempo de subida de salida de datos SDOx
—
—
—
ns
Ver parámetro D031 
y nota 4
SP35
TscH2doV,
TscL2doV
Salida de datos SDOx Válido después 
Borde SCKx
—
6
20
ns
—
SP40
TdiV2scH,
TdiV2scL
Tiempo de configuración de la entrada de datos SDIx
al borde SCKx
23
—
—
ns
—
SP41
TscH2diL,
TscL2diL
Tiempo de retención de la entrada de datos SDIx
al borde SCKx 
30
—
—
ns
—
Nota 1:
Estos parámetros se caracterizan pero no se prueban en la fabricación.
2:
Los datos en la columna "Típico" son de 3,3 V, 25 °C a menos que se indique lo contrario.
3:
El período de reloj mínimo para SCKx es 100 ns. Por lo tanto, el reloj generado en modo Maestro no debe 
violar esta especificación.
4:
Asume una carga de 50 pF en todos los pines SPIx.

© 2009 Microchip Technology Inc.
DS70286C-página 277
dsPIC33FJXXXGPX06/X08/X10
FIGURA 25-10:
MODO MAESTRO DEL MÓDULO SPIx (CKE = 1) CARACTERÍSTICAS DE TEMPORIZACIÓN     
TABLA 25-29: REQUISITOS DE TIEMPO DEL MODO MAESTRO DEL MÓDULO SPIx (CKE = 1)     
SCKX
(CKP = 0)
SCKX
(PCK = 1)
SDOX
SDIX
SP36
SP30,SP31
SP35
MSb
MSb en
Bit 14 - - - - - -1
LSb en
Bit 14 - - - -1
LSB
Nota: Consulte la Figura 25-1 para conocer las condiciones de carga.
SP11
SP10
SP20
SP21
SP21
SP20
SP40
SP41
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C 
parámetro
No.
Símbolo
Característica(1)
mín.
Tipo(2)
máx.
Unidades
Condiciones
SP10
Tscl
Tiempo bajo de salida SCKx(3)
TCY/2
—
—
ns
—
SP11
TscH
Tiempo alto de salida SCKx(3)
TCY/2
—
—
ns
—
SP20
TscF
Tiempo de caída de salida SCKx(4)
—
—
—
ns
Ver parámetro D032
SP21
TscR
Tiempo de subida de salida SCKx(4)
—
—
—
ns
Ver parámetro D031
SP30
TdF
Caída de la producción de datos SDOx 
Tiempo(4)
—
—
—
ns
Ver parámetro D032
SP31
TdoR
Aumento de la producción de datos SDOx 
Tiempo(4)
—
—
—
ns
Ver parámetro D031
SP35
TscH2doV,
TscL2doV
Salida de datos SDOx Válido después
Borde SCKx
—
6
20
ns
—
SP36
TdoV2sc, 
TdoV2scL
Configuración de salida de datos SDOx para
Primer borde SCKx
30
—
—
ns
—
SP40
TdiV2scH, 
TdiV2scL
Tiempo de configuración de datos SDIx 
Entrada a SCKx Edge
23
—
—
ns
—
SP41
TscH2diL, 
TscL2diL
Tiempo de retención de la entrada de datos SDIx
al borde SCKx 
30
—
—
ns
—
Nota 1:
Estos parámetros se caracterizan pero no se prueban en la fabricación.
2:
Los datos en la columna "Típico" son de 3,3 V, 25 °C a menos que se indique lo contrario.
3:
El período de reloj mínimo para SCKx es 100 ns. Por lo tanto, el reloj generado en modo Maestro no debe 
violar esta especificación.
4:
Asume una carga de 50 pF en todos los pines SPIx.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 278
© 2009 Microchip Technology Inc.
FIGURA 25-11:
MODO ESCLAVO DEL MÓDULO SPIx (CKE = 0) CARACTERÍSTICAS DE TEMPORIZACIÓN   
 
SSX
SCKX
(CKP = 0)
SCKX
(PCK = 1)
SDOX
SP50
SP40
SP41
SP30,SP31
SP51
SP35
MSb
LSB
Bit 14 - - - - - -1
MSb en
Bit 14 - - - -1
LSb en
SP52
SP73
SP72
SP72
SP73
SP71
SP70
Nota: Consulte la Figura 25-1 para conocer las condiciones de carga.
SDIX
TABLA 25-30: REQUISITOS DE TIEMPO DEL MODO ESCLAVO DEL MÓDULO SPIx (CKE = 0)        
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C
parámetro
No.
Símbolo
Característica(1)
mín.
Tipo(2)
máx.
Unidades
Condiciones
SP70
Tscl
Tiempo bajo de entrada SCKx 
30
—
—
ns
—
SP71
TscH
Hora alta de entrada SCKx 
30
—
—
ns
—
SP72
TscF
Tiempo de caída de entrada SCKx(3)
—
10
25
ns
—
SP73
TscR
Tiempo de subida de entrada SCKx(3)
—
10
25
ns
—
SP30
TdF
Tiempo de caída de la salida de datos SDOx(3)
—
—
—
ns
Ver parámetro D032
SP31
TdoR
Tiempo de subida de salida de datos SDOx(3)
—
—
—
ns
Ver parámetro D031
SP35
TscH2doV,
TscL2doV
Salida de datos SDOx Válido después
Borde SCKx
—
—
30
ns
—
SP40
TdiV2scH, 
TdiV2scL
Tiempo de configuración de la entrada de datos SDIx
al borde SCKx
20
—
—
ns
—
SP41
TscH2diL, 
TscL2diL
Tiempo de retención de la entrada de datos SDIx
al borde SCKx 
20
—
—
ns
—
SP50
TssL2scH, 
TssL2scL
SSx ↓ a SCKx ↑ o entrada SCKx
120
—
—
ns
—
SP51
TssH2doZ
SSx ↑ a salida SDOx
Alta impedancia(3)
10
—
50
ns
—
SP52
TscH2ssH
TscL2ssH
SSx después del borde SCKx
1,5 TCY + 40
—
—
ns
—
Nota 1:
Estos parámetros se caracterizan pero no se prueban en la fabricación.
2:
Los datos en la columna "Típico" son de 3,3 V, 25 °C a menos que se indique lo contrario.
3:
Asume una carga de 50 pF en todos los pines SPIx.

© 2009 Microchip Technology Inc.
DS70286C-página 279
dsPIC33FJXXXGPX06/X08/X10
FIGURA 25-12:
MODO ESCLAVO DEL MÓDULO SPIx (CKE = 1) CARACTERÍSTICAS DE TEMPORIZACIÓN     
SSx
SCKx
(CKP = 0)
SCKx
(PCK = 1)
SDOx
IDE
SP50
SP60
SDix
SP30,SP31
MSb
Bit 14 - - - - - -1
LSB
SP51
MSb en
Bit 14 - - - -1
LSb en
SP35
SP52
SP52
SP73
SP72
SP72
SP73
SP71
SP70
SP40
SP41
Nota: Consulte la Figura 25-1 para conocer las condiciones de carga.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 280
© 2009 Microchip Technology Inc.
TABLA 25-31: REQUISITOS DE TEMPORIZACIÓN DEL MODO ESCLAVO DEL MÓDULO SPIx (CKE = 1)    
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C 
parámetro
No.
Símbolo
Característica(1)
mín.
Tipo(2)
máx.
Unidades
Condiciones
SP70
Tscl
Tiempo bajo de entrada SCKx
30
—
—
ns
—
SP71
TscH
Hora alta de entrada SCKx
30
—
—
ns
—
SP72
TscF
Tiempo de caída de entrada SCKx(3)
—
10
25
ns
—
SP73
TscR
Tiempo de subida de entrada SCKx(3)
—
10
25
ns
—
SP30
TdF
Tiempo de caída de la salida de datos SDOx(3)
—
—
—
ns
Ver parámetro D032
SP31
TdoR
Tiempo de subida de salida de datos SDOx(3)
—
—
—
ns
Ver parámetro D031
SP35
TscH2doV,
TscL2doV
Salida de datos SDOx Válido después
Borde SCKx
—
—
30
ns
—
SP40
TdiV2scH, 
TdiV2scL
Tiempo de configuración de la entrada de datos SDIx
al borde SCKx
20
—
—
ns
—
SP41
TscH2diL, 
TscL2diL
Tiempo de retención de la entrada de datos SDIx
al borde SCKx
20
—
—
ns
—
SP50
TssL2scH, 
TssL2scL
SSx ↓ a SCKx ↓ o SCKx ↑ 
Entrada
120
—
—
ns
—
SP51
TssH2doZ SSx ↑ a salida SDOX
Alta impedancia(4)
10
—
50
ns
—
SP52
TscH2ssH
TscL2ssH
SSx ↑ después de SCKx Edge
1,5 TCY + 40
—
—
ns
—
SP60
TssL2doV
Salida de datos SDOx Válido después
Borde SSx
—
—
50
ns
—
Nota 1:
Estos parámetros se caracterizan pero no se prueban en la fabricación.
2:
Los datos en la columna "Típico" son de 3,3 V, 25 °C a menos que se indique lo contrario.
3:
El período de reloj mínimo para SCKx es 100 ns. Por lo tanto, el reloj generado en modo Maestro no debe 
violar esta especificación.
4:
Asume una carga de 50 pF en todos los pines SPIx.

© 2009 Microchip Technology Inc.
DS70286C-página 281
dsPIC33FJXXXGPX06/X08/X10
FIGURA 25-13:
CARACTERÍSTICAS DE TIEMPO DE LOS BITS DE ARRANQUE/PARA DEL BUS I2Cx (MODO MAESTRO)   
FIGURA 25-14:
CARACTERÍSTICAS DE TEMPORIZACIÓN DE DATOS DEL BUS I2Cx (MODO MAESTRO)   
IM31
IM34
SCLx
SDax
Empezar
Condición
Detener
Condición
IM30
IM33
Nota: Consulte la Figura 25-1 para conocer las condiciones de carga.
IM11
IM10
IM33
IM11
IM10
IM20
IM26
IM25
IM40
IM40
IM45
IM21
SCLx
SDax
en
SDax
Fuera
Nota: Consulte la Figura 25-1 para conocer las condiciones de carga.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 282
© 2009 Microchip Technology Inc.
   
TABLA 25-32: REQUISITOS DE TIEMPO DE DATOS DEL BUS I2Cx (MODO MAESTRO)
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C
parámetro
No.
Símbolo
Característica
Mín(1)
máx.
Unidades
Condiciones
IM10
TLO:SCL
Hora baja del reloj
modo de 100kHz
TCY/2 (BRG + 1)
—
μs
—
modo de 400kHz
TCY/2 (BRG + 1)
—
μs
—
Modo de 1MHz(2)
TCY/2 (BRG + 1)
—
μs
—
IM11
THI:SCL
Reloj Hora Alta Modo 100 kHz
TCY/2 (BRG + 1)
—
μs
—
modo de 400kHz
TCY/2 (BRG + 1)
—
μs
—
Modo de 1MHz(2)
TCY/2 (BRG + 1)
—
μs
—
IM20
TF:SCL
SDAx y SCLx
tiempo de otoño
modo de 100kHz 
—
300
ns
Se especifica que CB es 
de 10 a 400 pF
modo de 400kHz
20 + 0,1 CB
300
ns
Modo de 1MHz(2)
—
100
ns
IM21
TR:SCL
SDAx y SCLx
tiempo de subida
modo de 100kHz 
—
1000
ns
Se especifica que CB es 
de 10 a 400 pF
modo de 400kHz
20 + 0,1 CB
300 
ns
Modo de 1MHz(2)
—
300
ns
IM25
TSU:DAT
Entrada de datos
Tiempo de configuración
modo de 100kHz
250 
—
ns
—
modo de 400kHz
100 
—
ns
Modo de 1MHz(2)
40 
—
ns
IM26
THD: Entrada de datos DAT
Tiempo de espera
modo de 100kHz
0
—
μs
—
modo de 400kHz
0
0,9
μs
Modo de 1MHz(2)
0,2
—
μs
IM30
TSU:STA
Condición de inicio
Tiempo de configuración
modo de 100kHz
TCY/2 (BRG + 1)
—
μs
Sólo relevante para 
Inicio repetido
condición
modo de 400kHz
TCY/2 (BRG + 1)
—
μs
Modo de 1MHz(2)
TCY/2 (BRG + 1)
—
μs
IM31
THD:STA
Condición de inicio 
Tiempo de espera 
modo de 100kHz
TCY/2 (BRG + 1)
—
μs
Después de este período el
El primer pulso del reloj es
generado
modo de 400kHz
TCY/2 (BRG + 1)
—
μs
Modo de 1MHz(2)
TCY/2 (BRG + 1)
—
μs
IM33
TSU:STO
Condición de parada 
Tiempo de configuración
modo de 100kHz
TCY/2 (BRG + 1)
—
μs
—
modo de 400kHz
TCY/2 (BRG + 1)
—
μs
Modo de 1MHz(2)
TCY/2 (BRG + 1)
—
μs
IM34
THD: Condición de parada STO
modo de 100kHz
TCY/2 (BRG + 1)
—
ns
—
Tiempo de espera
modo de 400kHz
TCY/2 (BRG + 1)
—
ns
Modo de 1MHz(2)
TCY/2 (BRG + 1)
—
ns
IM40
TAA: SCL
Salida válida 
Desde el reloj
modo de 100kHz
—
3500 
ns
—
modo de 400kHz
—
1000 
ns
—
Modo de 1MHz(2)
—
400
ns
—
IM45
TBF: SDA
Tiempo libre en autobús
modo de 100kHz
4.7 
—
μs
Hora que debe estar el autobús 
libre ante un nuevo
la transmisión puede comenzar
modo de 400kHz
1.3
—
μs
Modo de 1MHz(2)
0,5
—
μs
IM50
CB
Carga capacitiva del bus
—
 400 
pF 
—
Nota 1:
BRG es el valor del generador de velocidad de baudios I2C. Consulte la Sección 19. “Circuito Interintegrado™ 
(I2C™)” en el “Manual de referencia de la familia dsPIC33F”.
2:
Capacitancia máxima de pines = 10 pF para todos los pines I2Cx (solo para el modo de 1 MHz).

© 2009 Microchip Technology Inc.
DS70286C-página 283
dsPIC33FJXXXGPX06/X08/X10
FIGURA 25-15:
CARACTERÍSTICAS DE TEMPORIZACIÓN DE LOS BITS DE ARRANQUE/PARA DEL BUS I2Cx (MODO ESCLAVO)   
  
FIGURA 25-16:
CARACTERÍSTICAS DE TEMPORIZACIÓN DE DATOS DEL BUS I2Cx (MODO ESCLAVO)   
IS31
IS34
SCLx
SDax
Empezar
Condición
Detener
Condición
IS30
IS33
IS30
IS31
IS33
IS11
IS10
IS20
IS26
IS25
IS40
IS40
IS45
IS21
SCLx
SDax
en
SDax
Fuera

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 284
© 2009 Microchip Technology Inc.
 
TABLA 25-33: REQUISITOS DE TIEMPO DE DATOS DEL BUS I2Cx (MODO ESCLAVO)
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro
No.
Símbolo
Característica
mín.
máx.
Unidades
Condiciones
IS10
TLO:SCL
Hora baja del reloj
modo de 100kHz
4.7
—
μs
El dispositivo debe funcionar a una 
mínimo de 1,5 MHz
modo de 400kHz
1.3
—
μs
El dispositivo debe funcionar a una 
mínimo de 10 MHz
Modo 1MHz(1)
0,5
—
μs
—
IS11
THI:SCL
Hora alta del reloj
modo de 100kHz
4.0
—
μs
El dispositivo debe funcionar a una 
mínimo de 1,5 MHz
modo de 400kHz
0,6
—
μs
El dispositivo debe funcionar a una 
mínimo de 10 MHz
Modo 1MHz(1)
0,5
—
μs
—
IS20
TF:SCL
SDAx y SCLx
tiempo de otoño
modo de 100kHz 
—
300
ns
Se especifica que CB es de
10 a 400 pF
modo de 400kHz
20 + 0,1 CB
300
ns
Modo 1MHz(1)
—
100
ns
IS21
TR:SCL
SDAx y SCLx
tiempo de subida
modo de 100kHz 
—
1000
ns
Se especifica que CB es de
10 a 400 pF
modo de 400kHz
20 + 0,1 CB
300
ns
Modo 1MHz(1)
—
300
ns
IS25
TSU:DAT
Entrada de datos
Tiempo de configuración
modo de 100kHz
250
—
ns
—
modo de 400kHz
100
—
ns
Modo 1MHz(1)
100
—
ns
IS26
THD:DAT
Entrada de datos
Tiempo de espera
modo de 100kHz 
0
—
μs
—
modo de 400kHz
0
0,9
μs
Modo 1MHz(1)
0
0.3
μs
IS30
TSU:STA
Condición de inicio
Tiempo de configuración
modo de 100kHz
4.7
—
μs
Sólo relevante para Repetido 
Condición de inicio
modo de 400kHz
0,6
—
μs
Modo 1MHz(1)
0,25
—
μs
IS31
THD:STA
Condición de inicio 
Tiempo de espera 
modo de 100kHz
4.0
—
μs
Después de este período, la primera 
se genera el pulso del reloj
modo de 400kHz
0,6
—
μs
Modo 1MHz(1)
0,25
—
μs
IS33
TSU:STO
Condición de parada 
Tiempo de configuración
modo de 100kHz
4.7
—
μs
—
modo de 400kHz
0,6
—
μs
Modo 1MHz(1)
0,6
—
μs
IS34
THD: Condición de parada STO
Tiempo de espera
modo de 100kHz 
4000
—
ns
—
modo de 400kHz
600
—
ns
Modo 1MHz(1)
250
ns
IS40
TAA: SCL
Salida válida 
Desde el reloj
modo de 100kHz
0
3500
ns
—
modo de 400kHz
0
1000
ns
Modo 1MHz(1)
0
350
ns
IS45
TBF: SDA
Tiempo libre en autobús
modo de 100kHz
4.7
—
μs
Hora en que el autobús debe estar libre. 
ante una nueva transmisión 
puede empezar
modo de 400kHz
1.3
—
μs
Modo 1MHz(1)
0,5
—
μs
IS50
CB
Carga capacitiva del bus
—
 400
pF 
—
Nota 1:
Capacitancia máxima de pines = 10 pF para todos los pines I2Cx (solo para el modo de 1 MHz).

© 2009 Microchip Technology Inc.
DS70286C-página 285
dsPIC33FJXXXGPX06/X08/X10
FIGURA 25-17:
MÓDULO DCI (MULTICANAL, MODOS I2S) CARACTERÍSTICAS DE TEMPORIZACIÓN    
COFS
CSCK
(SCKE = 0)
CSCK
(SCKE = 1)
CSDO
CSDI
CS11
CS10
CS40 CS41
CS21
CS20
CS35
CS21
MSb
LSB
MSb en
LSb en
CS31
Z alta
Z alta
70
CS30
CS51
CS50
CS55
Nota: Consulte la Figura 25-1 para conocer las condiciones de carga.
CS20
CS56

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 286
© 2009 Microchip Technology Inc.
       
TABLA 25-34: REQUISITOS DE TEMPORIZACIÓN DEL MÓDULO DCI (MULTICANAL, MODOS I2S)
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C para Industrial
parámetro
No.
Símbolo
Característica(1)
mín.
Tipo(2)
máx.
Unidades
Condiciones
CS10
TCSCKL
Tiempo bajo de entrada CSCK
(El pin CSCK es una entrada)
TCY/2 + 20
—
—
ns
—
Tiempo bajo de salida CSCK(3)
(El pin CSCK es una salida)
30
—
—
ns
—
CS11
TCSCKH
Hora alta de entrada CSCK
(El pin CSCK es una entrada)
TCY/2 + 20
—
—
ns
—
Tiempo alto de salida CSCK(3)
(El pin CSCK es una salida)
30
—
—
ns
—
CS20
TCSCKF
Tiempo de caída de salida CSCK(4)
(El pin CSCK es una salida)
—
10
25
ns
—
CS21
TCSCKR
Tiempo de subida de salida CSCK(4)
(El pin CSCK es una salida)
—
10
25
ns
—
CS30
TCSDOF
Tiempo de caída de la salida de datos de CSDO(4)
—
10
25
ns
—
CS31
TCSDOR
Tiempo de aumento de la salida de datos de CSDO(4)
—
10
25
ns
—
CS35
TDV
Borde del reloj a datos CSDO válidos
—
—
10
ns
—
CS36
TDIV
Borde de reloj a CSDO Tri-Stated
10
—
20
ns
—
CS40
TCSDI
Tiempo de configuración de la entrada de datos CSDI 
a
Borde CSCK (se introduce el pin CSCK
o salida)
20
—
—
ns
—
CS41
THCSDI
Tiempo de retención de la entrada de datos CSDI en
Borde CSCK (se introduce el pin CSCK
o salida)
20
—
—
ns
—
CS50
TCOFSF
Tiempo de caída de COFS
(Se emite el pin COFS)
—
10
25
ns
Ver Nota 1
CS51
TCOFSR
Tiempo de subida del COFS
(Se emite el pin COFS)
—
10
25
ns
Ver Nota 1
CS55
TSCOFS
Tiempo de configuración de la entrada de datos COFS 
a CSCK Edge (el pin COFS está 
entrada)
20
—
—
ns
—
CS56
THCOFS
Tiempo de retención de la entrada de datos COFS para
CSCK Edge (se ingresa el pin COFS)
20
—
—
ns
—
Nota 1:
Estos parámetros se caracterizan pero no se prueban en la fabricación.
2:
Los datos en la columna "Típico" son de 3,3 V, 25 °C a menos que se indique lo contrario. Los parámetros son solo una guía de diseño. 
y no son probados.
3:
El período de reloj mínimo para CSCK es 100 ns. Por lo tanto, el reloj generado en modo Maestro no debe 
violar esta especificación.
4:
 Asume una carga de 50 pF en todos los pines DCI.

© 2009 Microchip Technology Inc.
DS70286C-página 287
dsPIC33FJXXXGPX06/X08/X10
FIGURA 25-18:
CARACTERÍSTICAS DE TEMPORIZACIÓN DEL MÓDULO DCI (MODO AC-LINK)      
     
TABLA 25-35: REQUISITOS DE TEMPORIZACIÓN DEL MÓDULO DCI (MODO AC-LINK)
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C 
parámetro
No.
Símbolo
Característica(1,2)
mín.
Tipo(3)
máx.
Unidades
Condiciones
CS60
TBCLKL
BIT_CLK Tiempo bajo
36
40,7
45
ns
—
CS61
TBCLKH
BIT_CLK hora alta
36
40,7
45
ns
—
CS62
TBCLK
Período BIT_CLK
—
81,4
—
ns
Se introduce el reloj de bits
CS65
TSACL
Tiempo de configuración de entrada para
Borde descendente de BIT_CLK
—
—
10
ns
—
CS66
TACL
Tiempo de retención de entrada desde
Borde descendente de BIT_CLK
—
—
10
ns
—
CS70
TSYNCLO
Tiempo bajo de salida de datos de SYNC
—
19.5
—
μs
Ver Nota 1
CS71
TSYNCHI
Hora alta de salida de datos de SYNC
—
1.3
—
μs
Ver Nota 1
CS72
SINCRONIZACIÓN
Período de salida de datos de SYNC
—
20.8
—
μs
Ver Nota 1
CS75
TRACL
Tiempo de subida, SINCRONIZACIÓN, SDATA_OUT
—
10
25
ns
CARGA = 50 pF, VDD = 5V
CS76
TFACL
Tiempo de caída, SINCRONIZACIÓN, SDATA_OUT
—
10
25
ns
CARGA = 50 pF, VDD = 5V
CS77
TRACL
Tiempo de subida, SINCRONIZACIÓN, SDATA_OUT
—
—
30
ns
CARGA = 50 pF, VDD = 3V
CS78
TFACL
Tiempo de caída, SINCRONIZACIÓN, SDATA_OUT
—
—
30
ns
CARGA = 50 pF, VDD = 3V
CS80
TOVDACL
Retraso válido de salida desde el aumento 
Borde de BIT_CLK
—
—
15
ns
—
Nota 1:
Estos parámetros se caracterizan pero no se prueban en la fabricación.
2:
Estos valores suponen que la frecuencia BIT_CLK es 12,288 MHz.
3:
Los datos en la columna "Típico" son de 3,3 V, 25 °C a menos que se indique lo contrario. Los parámetros son solo una guía de diseño. 
y no son probados.
SINCRONIZACIÓN
BIT_CLK
SDOx
SDix
CS61
CS60
CS65 CS66
CS80
CS21
MSb en
CS75
LSB
CS76
(COF)
(CSK)
LSB
MSb
CS72
CS71
CS70
CS76
CS75
(ODSC)
(CSDI)
CS62
CS20

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 288
© 2009 Microchip Technology Inc.
FIGURA 25-19:
CARACTERÍSTICAS DE TEMPORIZACIÓN DE E/S DEL MÓDULO CAN    
          
CiTx Pin
(salida)
CA10 CA11
Valor antiguo
Nuevo valor
CA20
CiRx Chapa
(entrada)
TABLA 25-36: REQUISITOS DE TEMPORIZACIÓN DE E/S DEL MÓDULO ECAN™
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento
-40°C ≤ TA ≤ +85°C
parámetro
No.
Símbolo
Característica(1)
mín.
tipo
máx.
Unidades
Condiciones
CA10
TioF
Tiempo de caída de salida del puerto
—
—
—
ns
Ver parámetro D032
CA11
TioR
Tiempo de subida de salida del puerto 
—
—
—
ns
Ver parámetro D031
CA20
Tcwf
Ancho de pulso para disparar
Filtro de activación CAN
120
—
—
ns
—
Nota 1:
Estos parámetros se caracterizan pero no se prueban en la fabricación.

© 2009 Microchip Technology Inc.
DS70286C-página 289
dsPIC33FJXXXGPX06/X08/X10
      
TABLA 25-37: ESPECIFICACIONES DEL MÓDULO ADC
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento 
-40°C ≤ TA ≤ +85°C para Industrial
parámetro 
No.
Símbolo
Característica
Mín.
tipo
Máx.
Unidades
Condiciones
Suministro de dispositivos
AD01
AVDD
Suministro de módulo VDD 
mayor de
VDD - 0,3
o 3.0
—
menor de
VDD + 0,3
o 3.6
V
—
AD02
AVSS
Suministro de módulo VSS 
VSS - 0,3
—
VSS + 0,3
V
—
Entradas de referencia 
AD05
VREFH
Voltaje de referencia alto AVSS + 2,7
—
AVDD
V
Ver nota 2
AD05a
3.0
—
3.6
V
VREFH = AVDD
VREFL = AVSS = 0
AD06
VREFL
Voltaje de referencia bajo
AVSS
—
AVDD - 2.7
V
Ver nota 2
AD06a
0
—
0
V
VREFH = AVDD
VREFL = AVSS = 0
AD07
VREF
Referencia absoluta 
voltaje
3.0
—
3.6
V
VREF = VREFH - VREFL
AD08
IREF
Drenaje actual
—
—
250
—
550
1
µΑ
µΑ
ADC en funcionamiento, consulte la Nota 2
ADC apagado, consulte la Nota 2
AD08a
DIA
Corriente de funcionamiento
—
—
7.0
2.7
9.0
3.2
ma
ma
Modo ADC de 10 bits, consulte la Nota 3
Modo ADC de 12 bits, consulte la Nota 3
Entrada analógica
AD12
vinh
Rango de voltaje de entrada 
vinh
vinil
—
VREFH
V
Este voltaje refleja la muestra 
y mantenga presionados los canales 0, 1, 2, 
y 3 (CH0-CH3), positivo 
entrada. Ver Nota 1
AD13
vinil
Rango de voltaje de entrada 
vinil
VREFL
—
AVSS + 1V
V
Este voltaje refleja la muestra 
y mantenga presionados los canales 0, 1, 2, 
y 3 (CH0-CH3), negativo 
entrada. Ver Nota 1
AD17
Rin
Impedido recomendado
Aspecto del voltaje analógico 
Fuente
—
—
200
200
Ω
Ω
10 bits
12 bits
Nota 1:
El resultado de la conversión ADC nunca disminuye con un aumento en el voltaje de entrada y no falta 
códigos.
2:
Estos parámetros no se caracterizan ni se prueban en la fabricación.
3:
Estos parámetros se caracterizan; pero no se prueban en la fabricación.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 290
© 2009 Microchip Technology Inc.
TABLA 25-38: ESPECIFICACIONES DEL MÓDULO ADC (MODO DE 12 BITS)
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento 
-40°C ≤ TA ≤ +85°C para Industrial
parámetro 
No.
Símbolo
Característica
Mín.
tipo
Máx.
Unidades
Condiciones
Precisión ADC (modo 12 bits) - Mediciones con VREF+/VREF- externo
AD20a
nº
Resolución
12 bits de datos
bits
AD21a
ENL
No linealidad integral
-2
—
+2
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD22a
DNL
No linealidad diferencial
>-1
—
<1
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD23a
GERR
Error de ganancia
1.25
1.5
3
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD24a
EOFF
Error de compensación
1.25
1,52
2
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD25a
—
Monotonicidad(1)
—
—
—
—
Garantizado
Precisión ADC (modo de 12 bits): mediciones con VREF+/VREF- interno
AD20a
nº
Resolución
12 bits de datos
bits
AD21a
ENL
No linealidad integral
-2
—
+2
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD22a
DNL
No linealidad diferencial
>-1
—
<1
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD23a
GERR
Error de ganancia
2
3
7
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD24a
EOFF
Error de compensación
2
3
5
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD25a
—
Monotonicidad(1)
—
—
—
—
Garantizado
Rendimiento dinámico (modo de 12 bits)
AD30a
THD
Distorsión armónica total
-77
-69
-61
dB
—
AD31a
SINAD
Señal a Ruido y
distorsión 
59
63
64
dB
—
AD32a
SFDR
Dinámica libre espuria
Rango
63
72
74
dB
—
AD33a
FNYQ
Ancho de banda de la señal de entrada
—
—
250
kilociclos
—
AD34a
ENOB
Número efectivo de bits
10,95
11.1
—
bits
—
Nota 1:
El resultado de la conversión ADC nunca disminuye con un aumento en el voltaje de entrada y no falta 
códigos.

© 2009 Microchip Technology Inc.
DS70286C-página 291
dsPIC33FJXXXGPX06/X08/X10
TABLA 25-39: ESPECIFICACIONES DEL MÓDULO ADC (MODO DE 10 BITS)
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento 
-40°C ≤ TA ≤ +85°C para Industrial
parámetro 
No.
Símbolo
Característica
Mín.
tipo
Máx.
Unidades
Condiciones
Precisión ADC (modo de 10 bits) - Mediciones con VREF+/VREF- externo
AD20b
nº
Resolución
10 bits de datos
bits
AD21b
ENL
No linealidad integral
-1,5
—
+1.5
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD22b
DNL
No linealidad diferencial
>-1
—
<1
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD23b
GERR
Error de ganancia
1
3
6
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD24b
EOFF
Error de compensación
1
2
5
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD25b
—
Monotonicidad(1)
—
—
—
—
Garantizado
Precisión ADC (modo de 10 bits): mediciones con VREF+/VREF- interno
AD20b
nº
Resolución
10 bits de datos
bits
AD21b
ENL
No linealidad integral
-1
—
+1
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD22b
DNL
No linealidad diferencial
>-1
—
<1
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD23b
GERR
Error de ganancia
1
5
6
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD24b
EOFF
Error de compensación
1
2
3
LSB
VINL = AVSS = VREFL = 
0 V, AVDD = VREFH = 3,6 V
AD25b
—
Monotonicidad(1)
—
—
—
—
Garantizado
Rendimiento dinámico (modo de 10 bits)
AD30b
THD
Distorsión armónica total
—
-64
-67
dB
—
AD31b
SINAD
Señal a Ruido y
distorsión 
—
57
58
dB
—
AD32b
SFDR
Dinámica libre espuria
Rango
—
60
62
dB
—
AD33b
FNYQ
Ancho de banda de la señal de entrada
—
—
550
kilociclos
—
AD34b
ENOB
Número efectivo de bits
9.1
9.7
9.8
bits
—
Nota 1:
El resultado de la conversión ADC nunca disminuye con un aumento en el voltaje de entrada y no falta 
códigos.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 292
© 2009 Microchip Technology Inc.
FIGURA 25-20:
CARACTERÍSTICAS DE TIEMPO DE CONVERSIÓN ADC (MODO DE 12 BITS) 
(ASAM = 0, SSRC<2:0> = 000)   
55 d.C.
TSAMP
Borrar SAMP
Establecer muestra
61 d.C.
ADCLK
Instrucción
MUESTRA
ch0_dischrg
ch0_samp
60 d.C.
CONV.
ADxIF
Búfer(0)
1
2
3
4
5
6
8
7
1 – El software configura ADxCON. SAMP para iniciar el muestreo.
2 – El muestreo comienza después del período de alta. TSAMP se describe 
3 – El software borra ADxCON. SAMP para iniciar la conversión.
4 – Finaliza el muestreo, comienza la secuencia de conversión.
5 – Convertir el bit 11.
9 – Un TAD para el final de la conversión.
50 d.C.
eoc
9
6 – Convertir el bit 10.
7 – Convertir el bit 1.
8 – Convertir el bit 0.
 Ejecución
en la Sección 16. “Convertidor analógico a digital (ADC)” 
(DS70183) en el “Manual de referencia de la familia dsPIC33F”.

© 2009 Microchip Technology Inc.
DS70286C-página 293
dsPIC33FJXXXGPX06/X08/X10
TABLA 25-40: REQUISITOS DE TIEMPO DE CONVERSIÓN ADC (MODO DE 12 BITS) 
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento 
-40°C ≤ TA ≤ +85°C para Industrial 
parámetro 
No.
Símbolo
Característica
Mín.
Tipo(1)
Máx.
Unidades
Condiciones
Parámetros del reloj
AD50a
TAD
Período de reloj ADC
117,6
—
—
ns
—
AD51a
tRC
Oscilador RC interno ADC 
Periodo
—
250
—
ns
—
Tasa de conversión
AD55a
tCONV
Tiempo de conversión
—
14 poco
ns
—
AD56a
FCNV
Tasa de rendimiento
—
—
500
kps
—
AD57a
TSAMP
Tiempo de muestra
3 poco
—
—
—
—
Parámetros de sincronización
dC60a
tPCS
Conversión a partir de la muestra 
Gatillo(2)
2.0 TAD
—
3.0 TAD
—
Activador de conversión automática 
(SSRC<2:0> = 111) no 
seleccionado
AD61a
tPSS
Ejemplo de inicio desde la configuración
Bit de muestra (SAMP) (2)
2.0 TAD
—
3.0 TAD
—
—
AD62a
tCSS
Finalización de la conversión a
Inicio de muestra (ASAM = 1)(2)
—
0,5 TAD
—
—
—
AD63a
tDPU
Es hora de estabilizar la etapa analógica
de ADC apagado a ADC encendido (2,3)
—
—
20
μs
—
Nota 1:
Estos parámetros se caracterizan pero no se prueban en la fabricación.
2:
Debido a que las tapas de muestra eventualmente perderán carga, las frecuencias de reloj por debajo de 10 kHz pueden afectar la linealidad. 
rendimiento, especialmente a temperaturas elevadas.
3:
tDPU es el tiempo necesario para que el módulo ADC se estabilice cuando se enciende (AD1CON1<ADON> = 1). 
Durante este tiempo, el resultado del ADC es indeterminado.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 294
© 2009 Microchip Technology Inc.
FIGURA 25-21:
CARACTERÍSTICAS DE TIEMPO DE CONVERSIÓN ADC (MODO DE 10 BITS)
(CHPS<1:0> = 01, SIMSAM = 0, ASAM = 0, SSRC<2:0> = 000)    
55 d.C.
TSAMP
Borrar SAMP
Establecer muestra
61 d.C.
ADCLK
Instrucción
MUESTRA
ch0_dischrg
ch1_samp
60 d.C.
CONV.
ADxIF
Búfer(0)
Búfer(1)
1
2
3
4
5
6
8
5
6
7
1 – El software configura ADxCON. SAMP para iniciar el muestreo.
2 – El muestreo comienza después del período de alta. TSAMP se describe en la Sección 16. “Convertidor analógico a digital (ADC)” 
3 – El software borra ADxCON. SAMP para iniciar la conversión.
4 – Finaliza el muestreo, comienza la secuencia de conversión.
5 – Convertir el bit 9.
8 – Un TAD para el final de la conversión.
50 d.C.
ch0_samp
ch1_dischrg
eoc
7
55 d.C.
8
6 – Convertir el bit 8.
7 – Convertir el bit 0.
 Ejecución
 (DS70183) en el “Manual de referencia de la familia dsPIC33F”.

© 2009 Microchip Technology Inc.
DS70286C-página 295
dsPIC33FJXXXGPX06/X08/X10
FIGURA 25-22:
CONVERSIÓN ADC (MODO DE 10 BITS) CARACTERÍSTICAS DE TIEMPO (CHPS<1:0> = 01, 
SIMSAM = 0, ASAM = 1, SSRC<2:0> = 111, SAMC<4:0> = 00001)    
55 d.C.
TSAMP
Conjunto ADON
ADCLK
Instrucción 
MUESTRA
ch0_dischrg
ch1_samp
CONV.
ADxIF
Búfer(0)
Búfer(1)
1
2
3
4
5
6
4
5
6
8
1 – El software configura ADxCON. ADON para iniciar la operación AD.
2 – El muestreo comienza después del período de alta. TSAMP se describe 
3 – Convertir el bit 9.
4 – Convertir el bit 8.
5 – Convertir el bit 0.
50 d.C.
ch0_samp
ch1_dischrg
eoc
7
3
55 d.C.
6 – Un TAD para el final de la conversión.
7 – Comienza la conversión del siguiente canal.
8 – Muestra durante el tiempo especificado por SAMC<4:0>.
TSAMP
TCONV
3
4
Ejecución
en la Sección 16. “Convertidor analógico a digital (ADC)” 
(DS70183) en el “Manual de referencia de la familia dsPIC33F”.

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 296
© 2009 Microchip Technology Inc.
TABLA 25-41: REQUISITOS DE TIEMPO DE CONVERSIÓN ADC (MODO DE 10 BITS) 
CARACTERÍSTICAS DE LA CA
Condiciones de funcionamiento estándar: 3,0 V a 3,6 V
(a menos que se indique lo contrario)
Temperatura de funcionamiento 
-40°C ≤ TA ≤ +85°C para Industrial 
parámetro 
No.
Símbolo
Característica
Mín.
Tipo(1)
Máx.
Unidades
Condiciones
Parámetros del reloj
AD50b TAD
Período de reloj ADC
65
—
—
ns
—
AD51b CVR
Período del oscilador RC interno del ADC
—
250
—
ns
—
Tasa de conversión
AD55b TCONV
Tiempo de conversión
—
12 poco
—
—
—
AD56b FCNV
Tasa de rendimiento
—
—
1.1
msps
—
AD57b TSAMP
Tiempo de muestra
2 poco
—
—
—
—
Parámetros de sincronización
AD60b TPCS
Conversión a partir de la muestra
Gatillo(2)
2.0 TAD
—
3.0 TAD
—
Activador de conversión automática 
(SSRC<2:0> = 111) no 
seleccionado
AD61b TPSS
Ejemplo de inicio desde la configuración
Bit de muestra (SAMP) (2)
2.0 TAD
—
3.0 TAD
—
—
AD62b TCSS
Finalización de la conversión a
Inicio de muestra (ASAM = 1)(2)
—
0,5 TAD
—
—
—
AD63b TDPU
Es hora de estabilizar la etapa analógica 
de ADC apagado a ADC encendido (2,3)
—
—
20
μs
—
Nota 1:
Estos parámetros se caracterizan pero no se prueban en la fabricación.
2:
Debido a que las tapas de muestra eventualmente perderán carga, las frecuencias de reloj por debajo de 10 kHz pueden afectar la linealidad. 
rendimiento, especialmente a temperaturas elevadas.
3:
TDPU es el tiempo necesario para que el módulo ADC se estabilice cuando se enciende (AD1CON1<ADON> = 1). 
Durante este tiempo, el resultado del ADC es indeterminado.

© 2009 Microchip Technology Inc.
DS70286C-página 297
dsPIC33FJXXXGPX06/X08/X10
26.0
INFORMACIÓN DEL EMBALAJE
26.1
Información de marcado del paquete          
TQFP de 64 derivaciones (10x10x1 mm)
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
AAWWNNN
Ejemplo
dsPIC33FJ
256GP706
0510017
TQFP de 80 derivaciones (12x12x1 mm)
XXXXXXXXXXXX
XXXXXXXXXXXX
AAWWNNN
Ejemplo
dsPIC33FJ128
0510017
Leyenda:
XX...X
Información específica del cliente
Y
Código de año (último dígito del año calendario)
AA
Código de año (últimos 2 dígitos del año calendario)
WW
Código de semana (la semana del 1 de enero es la semana '01')
NNN
Código de trazabilidad alfanumérico
  
Designador JEDEC libre de Pb para estaño mate (Sn)
*
Este paquete no contiene Pb. El designador JEDEC libre de Pb ( )
se puede encontrar en el embalaje exterior de este paquete.
Nota:
En caso de que no se pueda marcar el número de pieza completo del Microchip en una línea,
se trasladará a la siguiente línea, lo que limitará el número de líneas disponibles.
caracteres para información específica del cliente.
3
mi
3
mi
TQFP de 100 derivaciones (12x12x1 mm)
XXXXXXXXXXXX
XXXXXXXXXXXX
AAWWNNN
Ejemplo
dsPIC33FJ256
GP710-I/PT
0510017
GP708-I/PT
TQFP de 100 derivaciones (14x14x1 mm)
XXXXXXXXXXXX
XXXXXXXXXXXX
AAWWNNN
TQFP de 100 derivaciones (14x14x1 mm)
dsPIC33FJ256
GP710-I/PF
0510017
-I/PT
3
mi
3
mi
3
mi
3
mi

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 298
© 2009 Microchip Technology Inc.
26.2
Detalles del paquete     
Paquete plano cuádruple delgado (PT) de plástico de 64 conductores: cuerpo de 10 x 10 x 1 mm, espacio de 2,00 mm [TQFP]
Notas:
1. La característica de índice visual del pin 1 puede variar, pero debe ubicarse dentro del área sombreada.
2. Los chaflanes en las esquinas son opcionales; el tamaño puede variar.
3. Las dimensiones D1 y E1 no incluyen rebabas ni protuberancias del molde. Las rebabas o protuberancias del molde no deberán exceder los 0,25 mm por lado.
4. Dimensionamiento y tolerancias según ASME Y14.5M.
BSC: Dimensión Básica. Valor teóricamente exacto mostrado sin tolerancias.
REF: Dimensión de Referencia, normalmente sin tolerancia, sólo a título informativo.
Nota:
Para obtener los dibujos de paquetes más actualizados, consulte la Especificación de embalaje de microchip ubicada en 
http://www.microchip.com/packaging
Unidades
MILÍMETROS
Límites de dimensión
MÍNIMO
NOMBRE
MÁXIMO
Número de clientes potenciales
norte
64
Lanzamiento principal
mi
0,50 BSC
Altura total
un
–
–
1.20
Grosor del paquete moldeado
A2
0,95
1.00
1.05
enfrentamiento  
A1
0,05
–
0,15
Longitud del pie
l
0,45
0,60
0,75
Huella
L1
1,00 REF
Ángulo del pie
φ
0°
3,5°
7°
Ancho total
mi
12.00 BSC
Longitud total
re
12.00 BSC
Ancho del paquete moldeado
E1
10.00 BSC
Longitud del paquete moldeado
D1
10.00 BSC
Grosor del plomo
c
0,09
–
0,20
Ancho de avance
segundo
0,17
0,22
0,27
Parte superior del ángulo de tiro del molde
α
11°
12°
13°
Parte inferior del ángulo de tiro del molde
b
11°
12°
13°
re
D1
mi
E1
mi
segundo
norte
NOTA 1
1 2 3
NOTA 2
c
l
A1
L1
A2
un
φ
b
α
Dibujo de tecnología de microchip C04-085B

© 2009 Microchip Technology Inc.
DS70286C-página 299
dsPIC33FJXXXGPX06/X08/X10
	

			
	
!"#$%
&
' 
(
 
	!"
#!$!%&'#(##!	
)%*!

! y !
!!+,,''' "	

", %

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 300
© 2009 Microchip Technology Inc.
Paquete plano cuádruple delgado (PT) de plástico de 80 conductores: cuerpo de 12 x 12 x 1 mm, espacio de 2,00 mm [TQFP]
Notas:
1. La característica de índice visual del pin 1 puede variar, pero debe ubicarse dentro del área sombreada.
2. Los chaflanes en las esquinas son opcionales; el tamaño puede variar.
3. Las dimensiones D1 y E1 no incluyen rebabas ni protuberancias del molde. Las rebabas o protuberancias del molde no deberán exceder los 0,25 mm por lado.
4. Dimensionamiento y tolerancias según ASME Y14.5M.
BSC: Dimensión Básica. Valor teóricamente exacto mostrado sin tolerancias.
REF: Dimensión de Referencia, normalmente sin tolerancia, sólo a título informativo.
Nota:
Para obtener los dibujos de paquetes más actualizados, consulte la Especificación de embalaje de microchip ubicada en 
http://www.microchip.com/packaging
Unidades
MILÍMETROS
Límites de dimensión
MÍNIMO
NOMBRE
MÁXIMO
Número de clientes potenciales
norte
80
Lanzamiento principal
mi
0,50 BSC
Altura total
un
–
–
1.20
Grosor del paquete moldeado
A2
0,95
1.00
1.05
enfrentamiento  
A1
0,05
–
0,15
Longitud del pie
l
0,45
0,60
0,75
Huella
L1
1,00 REF
Ángulo del pie
φ
0°
3,5°
7°
Ancho total
mi
14.00 BSC
Longitud total
re
14.00 BSC
Ancho del paquete moldeado
E1
12.00 BSC
Longitud del paquete moldeado
D1
12.00 BSC
Grosor del plomo
c
0,09
–
0,20
Ancho de avance
segundo
0,17
0,22
0,27
Parte superior del ángulo de tiro del molde
α
11°
12°
13°
Parte inferior del ángulo de tiro del molde
b
11°
12°
13°
re
D1
mi
E1
mi
segundo
norte
NOTA 1
12 3
NOTA 2
un
A2
L1
A1
l
c
α
b
φ
Dibujo de tecnología de microchip C04-092B

© 2009 Microchip Technology Inc.
DS70286C-página 301
dsPIC33FJXXXGPX06/X08/X10
)	

			
	
# #!" #$ %
&
' 
(
 
	!"
#!$!%&'#(##!	
)%*!

! y !
!!+,,''' "	

", %

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 302
© 2009 Microchip Technology Inc.
Paquete plano cuádruple delgado (PT) de plástico de 100 conductores: cuerpo de 12 x 12 x 1 mm, espacio de 2,00 mm [TQFP]
Notas:
1. La característica de índice visual del pin 1 puede variar, pero debe ubicarse dentro del área sombreada.
2. Los chaflanes en las esquinas son opcionales; el tamaño puede variar.
3. Las dimensiones D1 y E1 no incluyen rebabas ni protuberancias del molde. Las rebabas o protuberancias del molde no deberán exceder los 0,25 mm por lado.
4. Dimensionamiento y tolerancias según ASME Y14.5M.
BSC: Dimensión Básica. Valor teóricamente exacto mostrado sin tolerancias.
REF: Dimensión de Referencia, normalmente sin tolerancia, sólo a título informativo.
Nota:
Para obtener los dibujos de paquetes más actualizados, consulte la Especificación de embalaje de microchip ubicada en 
http://www.microchip.com/packaging
Unidades
MILÍMETROS
Límites de dimensión
MÍNIMO
NOMBRE
MÁXIMO
Número de clientes potenciales
norte
100
Lanzamiento principal
mi
0,40 BSC
Altura total
un
–
–
1.20
Grosor del paquete moldeado
A2
0,95
1.00
1.05
enfrentamiento  
A1
0,05
–
0,15
Longitud del pie
l
0,45
0,60
0,75
Huella
L1
1,00 REF
Ángulo del pie
φ
0°
3,5°
7°
Ancho total
mi
14.00 BSC
Longitud total
re
14.00 BSC
Ancho del paquete moldeado
E1
12.00 BSC
Longitud del paquete moldeado
D1
12.00 BSC
Grosor del plomo
c
0,09
–
0,20
Ancho de avance
segundo
0,13
0,18
0,23
Parte superior del ángulo de tiro del molde
α
11°
12°
13°
Parte inferior del ángulo de tiro del molde
b
11°
12°
13°
re
D1
mi
E1
mi
segundo
norte
123
NOTA 1
NOTA 2
c
l
A1
L1
un
A2
α
b
φ
Dibujo de tecnología de microchip C04-100B

© 2009 Microchip Technology Inc.
DS70286C-página 303
dsPIC33FJXXXGPX06/X08/X10
	

			
	
# #!" #$ %
&
' 
(
 
	!"
#!$!%&'#(##!	
)%*!

! y !
!!+,,''' "	

", %

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 304
© 2009 Microchip Technology Inc.
Paquete plano cuádruple delgado (PF) de plástico de 100 conductores: cuerpo de 14 x 14 x 1 mm, espacio de 2,00 mm [TQFP]
Notas:
1. La característica de índice visual del pin 1 puede variar, pero debe ubicarse dentro del área sombreada.
2. Los chaflanes en las esquinas son opcionales; el tamaño puede variar.
3. Las dimensiones D1 y E1 no incluyen rebabas ni protuberancias del molde. Las rebabas o protuberancias del molde no deberán exceder los 0,25 mm por lado.
4. Dimensionamiento y tolerancias según ASME Y14.5M.
BSC: Dimensión Básica. Valor teóricamente exacto mostrado sin tolerancias.
REF: Dimensión de Referencia, normalmente sin tolerancia, sólo a título informativo.
Nota:
Para obtener los dibujos de paquetes más actualizados, consulte la Especificación de embalaje de microchip ubicada en 
http://www.microchip.com/packaging
Unidades
MILÍMETROS
Límites de dimensión
MÍNIMO
NOMBRE
MÁXIMO
Número de clientes potenciales
norte
100
Lanzamiento principal
mi
0,50 BSC
Altura total
un
–
–
1.20
Grosor del paquete moldeado
A2
0,95
1.00
1.05
enfrentamiento  
A1
0,05
–
0,15
Longitud del pie
l
0,45
0,60
0,75
Huella
L1
1,00 REF
Ángulo del pie
φ
0°
3,5°
7°
Ancho total
mi
16.00 BSC
Longitud total
re
16.00 BSC
Ancho del paquete moldeado
E1
14.00 BSC
Longitud del paquete moldeado
D1
14.00 BSC
Grosor del plomo
c
0,09
–
0,20
Ancho de avance
segundo
0,17
0,22
0,27
Parte superior del ángulo de tiro del molde
α
11°
12°
13°
Parte inferior del ángulo de tiro del molde
b
11°
12°
13°
re
D1
mi
segundo
E1
mi
norte
NOTA 1
NOTA 2
1 23
c
l
A1
L1
A2
un
φ
b
α
Dibujo de tecnología de microchip C04-110B

© 2009 Microchip Technology Inc.
DS70286C-página 305
dsPIC33FJXXXGPX06/X08/X10
	

			
	
!"#$ %
&
' 
(
 
	!"
#!$!%&'#(##!	
)%*!

! y !
!!+,,''' "	

", %

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 306
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70286C-página 307
dsPIC33FJXXXGPX06/X08/X10
APÉNDICE A:
HISTORIAL DE REVISIONES
Revisión A (octubre de 2006)
Publicación inicial de este documento.
Revisión B (marzo de 2008)
Esta revisión incluye modificaciones tipográficas y
cambios de formato en todo el texto de la hoja de datos.
Los principales cambios están referenciados por sus respectivos
sección de la siguiente tabla.
TABLA A-1:
ACTUALIZACIONES PRINCIPALES DE LA SECCIÓN
Nombre de la sección
Descripción de la actualización
Sección 1.0 “Descripción general del dispositivo”
Se agregó información del pin de interrupción externa (INT0 a INT4) a 
Tabla 1-1.
Sección 3.0 “Organización de la memoria”
Se actualizó el título de la tabla del mapa de registro de notificaciones de cambios para reflejarlo. 
aplicación con dispositivos dsPIC33FJXXXMCX10 (Tabla 3-2).
Se agregaron tablas de mapas de registro de notificaciones de cambios (Tabla 3-3 y 
Tabla 3-4) para dsPIC33FJXXXMCX08 y dsPIC33FJXXXMCX06 
dispositivos, respectivamente.
Se actualizó el rango de bits para AD1CON3 (ADCS<7:0>) en el ADC1 
Mapa de registro y se agregó la Nota 1 (Tabla 3-15).
Se actualizó el rango de bits para AD2CON3 (ADCS<7:0>) en el ADC2 
Mapa de Registro (Tabla 3-16).
Se actualizó el valor de reinicio para C1FEN1 (FFFF) en el registro ECAN1. 
Map Cuando C1CTRL1.WIN = 0 o 1 (Tabla 3-18) y actualizó el 
título para reflejar los dispositivos aplicables.
Se actualizó el título en el mapa de registro ECAN1 cuando C1CTRL1.WIN 
= 0 para reflejar los dispositivos aplicables (Tabla 3-19).
Se actualizó el título en el mapa de registro ECAN1 cuando C1CTRL1.WIN 
= 1 para reflejar los dispositivos aplicables (Tabla 3-20).
Se actualizó el valor de reinicio para C2FEN1 (FFFF) en el registro ECAN2. 
Map Cuando C2CTRL1.WIN = 0 o 1 (Tabla 3-21) y actualizó el 
título para reflejar los dispositivos aplicables.
Se actualizó el título del mapa de registro ECAN2 cuando C2CTRL1.WIN 
= 0 para reflejar los dispositivos aplicables (Tabla 3-22).
Se actualizó el título del mapa de registro ECAN2 cuando C2CTRL1.WIN 
= 1 para reflejar los dispositivos aplicables (Tabla 3-23).
Se actualizó el valor de reinicio para TRISA (C6FF) y se cambiaron los bits 12 y 
Valores del bit 13 para ODCA no implementados en el Registro PORTA 
Mapa (Tabla 3-25).
Se cambiaron los valores de bit 10 y bit 9 para PMD1 a no implementados en 
el mapa de registro PMD (Tabla 3-34).
Sección 5.0 “Restablecer”
Se agregaron referencias POR y BOR en la operación de reinicio del bit de bandera. 
(Tabla 5-1).
Sección 7.0 “Acceso directo a memoria (DMA)” Se actualizó la referencia cruzada de la tabla en la Nota 2 en DMAxREQ 
registro (Registro 7-2).

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 308
© 2009 Microchip Technology Inc.
Sección 8.0 “Configuración del oscilador”
Se actualizó el tercer elemento de fuente de reloj (Reloj externo) en 
Sección 8.1.1 “Fuentes del reloj del sistema”.
Se agregó la frecuencia central en el registro OSCTUN para el FRC. 
Bits de sintonización (TUN<5:0>) valor 011111 y actualizó el centro 
frecuencia para el valor de bits 011110 (Registro 8-4).
Sección 15.0 “Interfaz periférica serie 
(IPS)”
Se eliminó información redundante, que ahora está disponible en el 
sección relacionada en el Manual de referencia de la familia dsPIC33F, mientras 
conservando el diagrama de bloques del módulo SPI (Figura 15-1).
Sección 16.0 “Circuito Interintegrado™ 
(I2C™)”
Se eliminaron las secciones 16.3 a 16.13, manteniendo el bloque I2C. 
Diagrama (Figura 16-1) (información redundante, que ahora se 
disponible en la sección relacionada en la Referencia de la familia dsPIC33F 
manuales).
Sección 17.0 “Asíncrono Universal 
Transmisor receptor (UART)”
Se eliminaron las secciones 17.1 a 17.7 (información redundante, que 
ahora está disponible en la sección relacionada en la familia dsPIC33F 
Manual de referencia).
Sección 18.0 “CAN mejorado (ECAN™) 
Módulo”
Se eliminaron las secciones 18.4 a 18.6 (información redundante, que 
ahora está disponible en la sección relacionada en la familia dsPIC33F 
Manual de referencia).
Valores de bits actualizados del preescalador de velocidad en baudios (BRP<5:0>) en CiCFG1 
registro (Registro 18-9).
Se cambió el valor de bit predeterminado de '0' a '1' para los bits 6 a 15 
(FLTEN6-FLTEN15) en el registro CiFEN1 (Registro 18-11).
Sección 19.0 “Interfaz del convertidor de datos 
(Módulo DCI)”
Se eliminaron las secciones 19.3 a 19.7 (información redundante, que 
ahora está disponible en la sección relacionada en la familia dsPIC33F 
Manual de referencia).
Sección 20.0 “10 bits/12 bits 
Convertidor analógico a digital (ADC)”
Se eliminó la ecuación 20-1 (período de reloj de conversión de ADC) y la figura. 
20-3 (Función de transferencia ADC (ejemplo de 10 bits).
Valores ADC AN14 y AN15 actualizados en el bloque del módulo ADC2 
Diagrama (FIGURA 20-2: “Diagrama de bloques del módulo ADC2 (1)”).
Se agregó la Nota 2 al diagrama de bloques del período de reloj de conversión de ADC 
(Figura 20-3).
Bits de selección de reloj de conversión ADC actualizados en ADxCON3 
regístrese de ADCS<5:0> a ADCS<7:0>. Cualquier referencia a estos 
Los bits también se han actualizado a lo largo de esta hoja de datos. 
(Registro 20-3).
Se agregó una nota al registro ADxCHS0 (Registro 21-6).
Sección 21.0 “Características especiales”
Dirección actualizada 0xF8000E en el registro de configuración del dispositivo 
Mapa (Tabla 21-1).
Se agregó contenido de registro FICD (BKBUG, COE, JTAGEN y 
ICS<1:0>) a la descripción de bits de configuración dsPIC33F y 
eliminó las dos últimas filas (Tabla 21-2).
Se agregó una nota después del segundo párrafo de la Sección 21.2 “En chip 
Regulador de voltaje”.
TABLA A-1:
ACTUALIZACIONES PRINCIPALES DE LA SECCIÓN (CONTINUACIÓN)
Nombre de la sección
Descripción de la actualización

© 2009 Microchip Technology Inc.
DS70286C-página 309
dsPIC33FJXXXGPX06/X08/X10
Sección 24.0 “Características Eléctricas”
Valor típico actualizado para el parámetro AD08 (Tabla 24-37).
Mínimo y máximo actualizados (tanto internos como externos). 
Valores VREF+/VREF-) para el parámetro AD21a (Tabla 24-38).
Mínimo, típico y máximo actualizado (VREF+/VREF- externo) 
valores para el parámetro AD24a (Tabla 24-38).
Valor máximo actualizado para el parámetro AD32a (Tabla 24-38).
Mínimo y máximo actualizados (tanto internos como externos). 
Valores VREF+/VREF-) para el parámetro AD21a (Tabla 24-38).
Valores mínimos y máximos actualizados (VREF+/VREF- externos) para 
parámetro AD21b (Tabla 24-39).
Valores típicos y máximos actualizados para el parámetro AD32b 
(Tabla 24-39).
Valores mínimos, típicos y máximos actualizados para el parámetro 
AD60a (Tabla 24-40 y Tabla 24-41).
Valores mínimos y máximos actualizados para el parámetro AD61a 
(Tabla 24-40 y Tabla 24-41).
Valores mínimos y máximos actualizados para el parámetro AD63a 
(Tabla 24-40 y Tabla 24-41).
Se agregó la Nota 3 a la sincronización de conversión de ADC (modo de 12 bits) 
Requisitos (Tabla 24-40 y Tabla 24-41).
TABLA A-1:
ACTUALIZACIONES PRINCIPALES DE LA SECCIÓN (CONTINUACIÓN)
Nombre de la sección
Descripción de la actualización

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 310
© 2009 Microchip Technology Inc.
Revisión C (marzo de 2009)
Esta revisión incluye modificaciones tipográficas y
cambios de formato en todo el texto de la hoja de datos.
Los cambios globales incluyen:
• Se cambiaron todas las instancias de OSCI a OSC1 y 
OSCO a OSC2
• Se cambiaron todas las instancias de VDDCORE y 
VDDCORE/VCAP a VCAP/VDDCORE
Los demás cambios están referenciados por sus respectivos
sección de la siguiente tabla.
TABLA A-2:
ACTUALIZACIONES PRINCIPALES DE LA SECCIÓN
Nombre de la sección
Descripción de la actualización
“Alto rendimiento, 16 bits digitales 
Controladores de señal”
Se actualizaron todos los diagramas de pines para indicar la tolerancia de voltaje de los pines (consulte “Pin 
Diagramas”).
Se agregó la Nota 2 a los diagramas de pines QFN-S de 28 pines y QFN de 44 pines, que 
hace referencia a conexiones de pines a VSS.
Sección 1.0 “Descripción general del dispositivo”
AVDD actualizado en las descripciones de E/S PINOUT (consulte la Tabla 1-1).
Sección 2.0 “Pautas para obtener 
Comenzó con señal digital de 16 bits 
Controladores”
Se agregó una nueva sección a la hoja de datos que proporciona pautas para obtener 
comenzó con controladores de señal digital de 16 bits.
Sección 4.0 “Organización de la memoria”
Agregue los SFR del acumulador A y B (ACCAL, ACCAH, ACCAU, ACCBL, 
ACCBH y ACCBU) y actualizó el valor de reinicio para CORCON en el 
Mapa de registro del núcleo de la CPU (consulte la Tabla 4-1).
Valores de reinicio actualizados para IPC3, IPC4, IPC11 e IPC13-IPC15 en el 
Mapa de registro del controlador de interrupciones (consulte la Tabla 4-5).
Se actualizó el valor de reinicio para CLKDIV en el mapa de registro de control del sistema. 
(ver Tabla 4-32).
Sección 5.0 “Memoria de programa flash”
Se actualizó la Sección 5.3 “Operaciones de programación” con programación 
fórmula del tiempo.
Sección 9.0 “Configuración del oscilador” Se agregó la Nota 2 al diagrama del sistema del oscilador (consulte la Figura 9-1).
Valores de bits predeterminados actualizados para DOZE<2:0> y FRCDIV<2:0> en el reloj 
Registro Divisor (CLKDIV) (ver Registro 9-2).
Se agregó un párrafo sobre la precisión del FRC al final de la Sección 9.1.1. 
“Fuentes del reloj del sistema”.
Se agregó la Nota 1 al Registro de sintonización del oscilador FRC (OSCTUN) (consulte 
Registro 9-4).
Sección 10.0 “Ahorro de energía 
Características”
Se agregaron los siguientes registros:
• PMD1: Módulo periférico deshabilita el registro de control 1 (registro 10-1)
• PMD2: Módulo periférico deshabilita el registro de control 2 (registro 10-2)
• PMD3: Registro 3 de control de desactivación del módulo periférico (Registro 10-3)
Sección 11.0 “Puertos de E/S”
Se agregó referencia a los diagramas de pines para conocer la disponibilidad y funcionalidad de los pines de E/S. 
(consulte la Sección 11.2 “Configuración de drenaje abierto”).
Sección 16.0 “Periférico serie 
Interfaz (SPI)”
Se agregó la Nota 2 al registro SPIxCON1 (ver Registro 16-2).
Sección 18.0 “Universal 
Transmisor receptor asíncrono 
(UART)”
Se actualizó la configuración de bits UTXINV en el registro UxSTA (consulte 
Registro 18-2).

© 2009 Microchip Technology Inc.
DS70286C-página 311
dsPIC33FJXXXGPX06/X08/X10
Sección 19.0 “CAN mejorada 
(ECAN™) Módulo”
Se cambió el bit 11 en el Registro de control 1 de ECAN (CiCTRL1) a Reservado 
(ver Registro 19-1).
Se agregó el registro de selección de máscara del filtro ECAN 15-8 (CiFMSKSEL2) (consulte 
Registro 19-19).
Sección 21.0 “10 bits/12 bits 
Convertidor analógico a digital (ADC)”
Se reemplazó el diagrama de bloques del módulo ADC (consulte la Figura 21-1) y se eliminó. 
Figura 21-2.
Sección 22.0 “Características especiales”
Se agregó la Nota 2 al mapa de registro de configuración del dispositivo (consulte la Tabla 22-1).
Sección 25.0 “Eléctricos 
Características”
Valores típicos actualizados para las características de embalaje térmico (consulte 
Tabla 25-3).
Valores mínimos y máximos actualizados para el parámetro DC12 (retención de datos RAM). 
Voltaje) y agregó la Nota 4 (consulte la Tabla 25-4).
Se actualizaron los valores máximos de corriente de apagado para los parámetros DC60b y 
DC60c (ver Tabla 25-7).
Características actualizadas para las especificaciones de entrada de pines de E/S (consulte la Tabla 25-9).
Valores de memoria de programa actualizados para los parámetros 136, 137 y 138 
(renombrado a 136a, 137a y 138a), se agregaron los parámetros 136b, 137b y 
138b, y agregó la Nota 2 (ver Tabla 25-12).
Se agregó el parámetro OS42 (GM) a los requisitos de temporización del reloj externo. 
(ver Tabla 25-16).
Se actualizó el parámetro SY20 del período de tiempo de espera del temporizador de vigilancia (consulte 
Tabla 25-21).
TABLA A-2:
ACTUALIZACIONES PRINCIPALES DE LA SECCIÓN (CONTINUACIÓN)
Nombre de la sección
Descripción de la actualización

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 312
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc. 
DS70286C-página 313 
dsPIC33FJXXXGPX06/X08/X10 
ÍNDICE 
A 
Convertidor A/D ................................................................ 225 
DMA................................................................................ 225 
Inicialización ................................................................ 225 
Características clave................................................................ 225 
Características del aire acondicionado ................................................ 266 
Precisión RC interna................................................ 268 
Condiciones de carga................................................ 266 
Módulo ADC 
Mapa de registro ADC11................................................ 49 
Mapa de registro ADC2................................................ 49 
Tabla de vectores de interrupción alternativa (AIVT) ................................ 81 
Unidad Aritmético Lógica (ALU)................................................. 27 
Ensamblador 
Montaje MPASM................................................ 254 
B 
Cambiador de cañón ................................................................ 31 
Direccionamiento de bits invertidos ................................................ 64 
Ejemplo................................................................................ 65 
Implementación ................................................................ 64 
Tabla de secuencia (16 entradas)................................. 65 
Diagramas de bloques 
Módulo Temporizador1 de 16 bits................................ 157 
Módulo A/D ................................................................ 226 
Conexiones para el regulador de voltaje en chip....241 
Módulo DCI................................................................ 218 
Reloj del dispositivo................................................ 137, 139 
Motor DSP ................................................................ 28 
dsPIC33F................................................................ 14 
Núcleo de CPU dsPIC33F................................................ 22 
Módulo ECAN ................................................................ 192 
Captura de entrada ........................................................ 165 
Comparación de salida ................................................ 167 
PLL................................................................................ 139 
Reiniciar el sistema................................................................ 77 
Estructura portuaria compartida ................................................ 155 
SPI................................................................................ 171 
Temporizador2 (16 bits) ................................................ 161 
Temporizador 2/3 (32 bits) ................................................ 160 
UART................................................................................ 185 
Temporizador de vigilancia (WDT)................................................. 242 
do 
Compiladores C 
MPLAB C18 ................................................................ 254 
MPLAB C30 ................................................................ 254 
Cambio de reloj................................................................ 145 
Habilitación................................................................... 145 
Secuencia................................................................ 145 
Ejemplos de código 
Borrar una página de memoria de programa................................ 75 
Iniciar una secuencia de programación................................ 76 
Cargando buffers de escritura ................................................ 76 
Escritura/lectura de puerto ................................................ 156 
Sintaxis de la instrucción PWRSAV................................ 147 
Código de protección ........................................................ 237, 243 
Bits de configuración................................................................ 237 
Descripción (Tabla)................................................. 238 
Mapa de registro de configuración ................................................ 237 
Configuración de pines del puerto analógico................................ 156 
UPC 
Registro de control................................................................ 24 
Sistema de reloj de CPU ................................................ 138 
Opciones ........................................................................ 138 
Selección................................................................................ 138 
Servicio de notificación de cambio de cliente................... 317 
Servicio de notificación al cliente ........................................ 317 
Atención al cliente................................................................ 317 
D 
Acumuladores de datos y sumador/restador ................. 29 
Saturación de escritura en el espacio de datos................................ 31 
Desbordamiento y saturación................................................ 29 
Lógica redonda ................................................................ 30 
Escribir en respuesta ................................................................ 30 
Espacio de direcciones de datos................................................ 35 
Alineación................................................................................ 35 
Mapa de memoria para dispositivos dsPIC33FJXXXGPX06/X08/X10 
es con 16 KB de RAM................................................ 37 
Mapa de memoria para dispositivos dsPIC33FJXXXGPX06/X08/X10 
es con 30 KB de RAM................................................ 38 
Mapa de memoria para dispositivos dsPIC33FJXXXGPX06/X08/X10 
es con 8 KB de RAM................................................ 36 
Espacio de datos cercano................................................ 35 
Pila de software ................................................................ 61 
Ancho ................................................................................ 35 
Módulo de interfaz de convertidor de datos (DCI)................................ 217 
Características de CC................................................................ 258 
Especificaciones de entrada de pines de E/S ................................ 263 
Especificaciones de salida de pines de E/S................................ 264 
Corriente inactiva (IIDLE)................................................. 261 
Corriente de funcionamiento (IDD) ................................................ 260 
Corriente de apagado (IPD)................................................. 262 
Memoria de programa................................................ 265 
Especificaciones de temperatura y voltaje................. 259 
DCI 
Control de búfer ................................................ 217 
Alineación de datos del búfer ................................ 217 
Introducción................................................................ 217 
Registro de desplazamiento de transmisión/recepción................................ 217 
Pines de E/S DCI................................................................ 217 
COFS................................................................................ 217 
CSCK................................................................................ 217 
CSDI................................................................................ 217 
CSDO ................................................................................ 217 
Módulo DCI 
Mapa de registro ................................................................ 58 
Apoyo al desarrollo................................................................ 253 
Módulo DMA 
Mapa de registro DMA ................................................ 50 
Registros DMAC................................................................ 128 
DMAxCNT ................................................................ 128 
DMAxCON................................................................ 128 
DMaxPAD ................................................................ 128 
DMAxREQ................................................................ 128 
DMAxSTA................................................................ 128 
DMAxSTB................................................................ 128 
Motor DSP ........................................................................ 27 
Multiplicador ................................................................................ 29 
mi 
Módulo ECAN 
Registro CiFMSKSEL2 ................................................ 209 
Mapa de registro ECAN1 (C1CTRL1.WIN = 0 o 1)... 52 
Mapa de registro ECAN1 (C1CTRL1.WIN = 0)................. 52 
Mapa de registro ECAN1 (C1CTRL1.WIN = 1)................ 53 

dsPIC33FJXXXGPX06/X08/X10 
DS70286C-página 314 
© 2009 Microchip Technology Inc. 
Mapa de registro ECAN2 (C2CTRL1.WIN = 0 o 1)... 55 
Mapa de registro ECAN2 (C2CTRL1.WIN = 0) ........ 55, 56 
Tipos de marco................................................................ 191 
Modos de operación ................................................ 193 
Descripción general................................................................ 191 
Registros ECAN 
Filtro 15-8 Registro de selección de máscara (CiFMSKSEL2). 209 
Características eléctricas................................................................ 257 
CA ................................................................................ 266 
Módulo CAN mejorado................................................ 191 
Ecuaciones 
Frecuencia de funcionamiento del dispositivo ................................... 138 
Fe de erratas ................................................................................ 12 
F 
Memoria de programa flash................................................ 71 
Registros de control ................................................ 72 
Operaciones ................................................................ 72 
Algoritmo de programación ................................................ 75 
Operación RTSP................................................................ 72 
Instrucciones de la tabla................................................ 71 
Configuración flexible ................................................................ 237 
FCM 
Retardo para fuentes de reloj de cristal y PLL................. 80 
Restablecimientos del dispositivo................................................ 80 
I 
Puertos de E/S................................................................................ 155 
E/S paralelas (PIO)................................................. 155 
Tiempo de escritura/lectura................................................ 156 
I2C 
Modos de funcionamiento ................................................ 177 
Registros................................................................ 177 
Módulo I2C 
Mapa de registro I2C1 ................................................ 47 
Mapa de registro I2C2 ................................................ 47 
Depurador en circuito................................................................ 243 
Emulación en circuito................................................................ 237 
Programación en serie en circuito (ICSP) ........................237, 243 
Captura de entrada 
Registros................................................................ 166 
Módulo de notificación de cambio de entrada................................ 156 
Modos de direccionamiento de instrucciones................................ 61 
Instrucciones de registro de archivos ................................ 61 
Modos fundamentales admitidos................................ 62 
Instrucciones MAC................................................................ 62 
Instrucciones de la MCU ................................................ 61 
Instrucciones de movimiento y acumulador................... 62 
Otras instrucciones................................................................ 62 
Conjunto de instrucciones 
Descripción general................................................................ 248 
Resumen................................................................ 245 
Modos de ahorro de energía basados ​​en instrucciones.................... 147 
Inactivo ................................................................................ 148 
Dormir................................................................................ 147 
Oscilador RC interno 
Uso con WDT ................................................................ 242 
Dirección de Internet................................................................ 317 
Registros de estado y control de interrupciones................................ 85 
IECx................................................................................ 85 
IFSx................................................................................ 85 
INTCON1 ................................................................ 85 
INTCON2 ................................................................ 85 
IPCx ................................................................................ 85 
Procedimientos de configuración de interrupción................................ 125 
Inicialización ................................................................ 125 
Desactivación de interrupción ................................................ 125 
Rutina de servicio de interrupción................................ 125 
Rutina de servicio de trampa................................. 125 
Tabla de vectores de interrupción (IVT)................................................. 81 
Interrupciones coincidentes con instrucciones de ahorro de energía... 148 
j 
Interfaz de escaneo de límites JTAG................................ 237 
METRO 
Organización de la memoria ........................................................ 33 
Sitio web de Internet de Microchip................................ 317 
Modos de operación 
Desactivar................................................................................ 193 
Inicialización................................................................ 193 
Escuchar todos los mensajes................................................ 193 
Escuchar sólo................................................................ 193 
Bucle invertido ................................................................ 193 
Funcionamiento normal ................................................ 193 
Direccionamiento de módulo................................................................ 62 
Aplicabilidad................................................................ 64 
Ejemplo de operación................................................ 63 
Dirección inicial y final ................................................ 63 
W Selección del registro de dirección................................ 63 
MPLAB ASM30 Ensamblador, enlazador, bibliotecario................. 254 
Depurador en circuito MPLAB ICD 2 ................................ 255 
MPLAB ICE 2000 Em-circuito universal de alto rendimiento 
ulador................................................................................ 255 
Software de entorno de desarrollo integrado MPLAB.. 253 
Programador de dispositivos MPLAB PM3 ................................ 255 
Sistema emulador en circuito MPLAB REAL ICE ................ 255 
Enlazador de objetos MPLINK/Biblioteca de objetos MPLIB................ 254 
norte 
Módulo NVM 
Mapa de registro ................................................................ 60 
oh 
Configuración de drenaje abierto................................................ 156 
Comparación de salida ................................................................ 167 
PAG 
Embalaje................................................................................ 297 
Detalles................................................................................ 298 
Marcado................................................................................ 297 
Desactivación del módulo periférico (PMD) ................................... 148 
Programador de desarrollo PICSTART Plus................ 256 
Descripciones de distribución de pines de E/S (tabla)................................. 15 
Módulo PMD 
Mapa de registro ................................................................ 60 
POR y tiempos largos de inicio del oscilador ................. 80 
PORTA 
Mapa de registro ................................................................ 58 
PUERTO 
Mapa de registro ................................................................ 58 
PORTC 
Mapa de registro ................................................................ 59 
PORTADO 
Mapa de registro ................................................................ 59 
PORTE 
Mapa de registro ................................................................ 59 
PORTAF 
Mapa de registro ................................................................ 59 
PUERTO 
Mapa de registro ................................................................ 60 
Funciones de ahorro de energía ........................................ 147 

© 2009 Microchip Technology Inc. 
DS70286C-página 315 
dsPIC33FJXXXGPX06/X08/X10 
Frecuencia de reloj y conmutación................................ 147 
Espacio de direcciones del programa................................................ 33 
Construcción................................................................ 66 
Acceso a datos desde la memoria del programa usando el programa 
Visibilidad espacial................................................ 69 
Acceso a datos desde la memoria del programa mediante instrucciones de tabla. 
ciones ................................................................ 68 
Acceso a datos desde, generación de direcciones................... 67 
Mapa de memoria................................................................ 33 
Instrucciones de lectura de tabla 
TBLRDH ................................................................ 68 
TBLRDL................................................................ 68 
Operación de visibilidad ................................................ 69 
Memoria de programa 
Vector de interrupción ........................................................ 34 
Organización................................................................ 34 
Restablecer vectores ................................................................ 34 
R 
Respuesta del lector ................................................................ 318 
Registros 
ADxCHS0 (Selección del canal 0 de entrada ADCx ................ 234 
ADxCHS123 (Selección del canal de entrada ADCx 1, 2, 3) ... 233 
ADxCON1 (Control ADCx 1)................................. 228 
ADxCON2 (Control ADCx 2)................................. 230 
ADxCON3 (Control ADCx 3)................................. 231 
ADxCON4 (Control ADCx 4)................................. 232 
ADxCSSH (Selección alta de exploración de entrada ADCx).... 235 
ADxCSSL (selección baja de exploración de entrada ADCx) ................ 235 
ADxPCFGH (Configuración alta del puerto ADCx) ......... 236 
ADxPCFGL (Configuración baja del puerto ADCx).... 236 
CiBUFPNT1 (Puntero de búfer del filtro ECAN 0-3)....... 204 
CiBUFPNT2 (Puntero de búfer del filtro ECAN 4-7)....... 205 
CiBUFPNT3 (filtro ECAN 8-11 Puntero de búfer)... 205 
CiBUFPNT4 (Puntero de búfer del filtro ECAN 12-15)....... 206 
CiCFG1 (Configuración de velocidad de baudios ECAN 1) ................ 202 
CiCFG2 (Configuración de velocidad de baudios ECAN 2) ................ 203 
CiCTRL1 (ECAN Control 1) ...................................... 194 
CiCTRL2 (ECAN Control 2) ...................................... 195 
CiEC (recuento de errores de transmisión/recepción de ECAN).... 201 
CiFCTRL (Control ECAN FIFO)................................. 197 
CiFEN1 (Habilitación del filtro de aceptación ECAN)....204 
CiFIFO (Estado ECAN FIFO)................................. 198 
CiFMSKSEL1 (Selección de máscara del filtro ECAN 7-0).... 208, 
209 
CiINTE (Habilitación de interrupción ECAN) ................................. 200 
CiINTF (indicador de interrupción ECAN)................................. 199 
CiRXFnEID (Filtro de aceptación ECAN n Identificación extendida 
hierro)................................................................. 207 
CiRXFnSID (filtro de aceptación ECAN n identificación estándar) 
hierro)................................................................. 207 
CiRXFUL1 (Búfer de recepción ECAN lleno 1)................. 211 
CiRXFUL2 (Búfer de recepción ECAN lleno 2)................. 211 
CiRXMnEID (Máscara de filtro de aceptación ECAN n Extendida 
Identificador)................................................................. 210 
CiRXMnSID (máscara de filtro de aceptación ECAN n estándar 
Identificador)................................................................. 210 
CiRXOVF1 (Desbordamiento del búfer de recepción ECAN 1)....... 212 
CiRXOVF2 (Desbordamiento del búfer de recepción ECAN 2)....... 212 
CiTRBnDLC (búfer ECAN y control de longitud de datos).. 215 
CiTRBnDm (Búfer ECAN n campo de datos Byte m) ...... 215 
CiTRBnEID (búfer ECAN n identificador extendido) ..... 214 
CiTRBnSID (búfer ECAN n identificador estándar)... 214 
CiTRBnSTAT (Estado del búfer de recepción ECAN)... 216 
CiTRmnCON (Control del búfer m ECAN TX/RX)... 213 
CiVEC (Código de interrupción ECAN)................................. 196 
CLKDIV (Divisor de reloj) ........................................ 142 
CORCON (Control central)................................. 26, 86 
DCICON1 (Control DCI 1) ........................................ 219 
DCICON2 (Control DCI 2) ........................................ 220 
DCICON3 (Control DCI 3) ........................................ 221 
DCISTAT (Estado DCI) ................................. 222 
DMACS0 (Estado del controlador DMA 0) ........................ 133 
DMACS1 (Estado del controlador DMA 1) ......... 135 
DMAxCNT (Canal DMA x Recuento de transferencias)....... 132 
DMAxCON (Control DMA Canal x)................. 129 
DMaxPAD (canal DMA x dirección periférica) .... 132 
DMAxREQ (Canal DMA x Selección IRQ)................. 130 
DMaxSTA (canal DMA x dirección de inicio de RAM A). 131 
DMaxSTB (canal DMA x dirección de inicio B de RAM). 131 
DSADR (Dirección RAM DMA más reciente) ......... 136 
I2CxCON (Control I2Cx)................................................. 179 
I2CxMSK (Máscara de dirección del modo esclavo I2Cx).... 183 
I2CxSTAT (Estado I2Cx)................................................. 181 
ICxCON (Captura de entrada x control).................... 166 
IEC0 (Control de habilitación de interrupción 0).................... 98 
IEC1 (Control de habilitación de interrupción 1).................... 100 
IEC2 (Control de habilitación de interrupción 2).................... 102 
IEC3 (Control de habilitación de interrupción 3).................... 104 
IEC4 (Control de habilitación de interrupción 4).................... 105 
IFS0 (Estado de indicador de interrupción 0)................................. 90 
IFS1 (Estado del indicador de interrupción 1)................................. 92 
IFS2 (Estado del indicador de interrupción 2)................................. 94 
IFS3 (Estado de indicador de interrupción 3)................................. 96 
IFS4 (Estado de indicador de interrupción 4)................................. 97 
INTCON1 (Control de interrupción 1) ................................... 87 
INTCON2 (Control de interrupción 2) ................................... 89 
INTTREG Registro de estado y control de interrupciones... 124 
IPC0 (Control de prioridad de interrupción 0).................... 106 
IPC1 (Control de prioridad de interrupción 1).................... 107 
IPC10 (Control de prioridad de interrupción 10).................... 116 
IPC11 (Control de prioridad de interrupción 11).................... 117 
IPC12 (Control de prioridad de interrupción 12).................... 118 
IPC13 (Control de prioridad de interrupción 13).................... 119 
IPC14 (Control de prioridad de interrupción 14).................... 120 
IPC15 (Control de prioridad de interrupción 15).................... 121 
IPC16 (Control de prioridad de interrupción 16).................... 122 
IPC17 (Control de prioridad de interrupción 17).................... 123 
IPC2 (Control de prioridad de interrupción 2).................... 108 
IPC3 (Control de prioridad de interrupción 3).................... 109 
IPC4 (Control de prioridad de interrupción 4).................... 110 
IPC5 (Control de prioridad de interrupción 5).................... 111 
IPC6 (Control de prioridad de interrupción 6).................... 112 
IPC7 (Control de prioridad de interrupción 7).................... 113 
IPC8 (Control de prioridad de interrupción 8).................... 114 
IPC9 (Control de prioridad de interrupción 9).................... 115 
NVMCOM (Control de memoria flash) ......... 73, 74 
OCxCON (Comparación de salida x control).................... 169 
OSCCON (Control del oscilador)................................. 140 
OSCTUN (Sintonización del oscilador FRC).................... 144 
PLLFBD (Divisor de retroalimentación PLL) ........................ 143 
PMD1 (Registro de control de desactivación de módulo periférico 1). 
149 
PMD2 (Registro de control de desactivación de módulo periférico 2). 
151 
PMD3 (Registro de control de desactivación de módulo periférico 3). 
153 
RCON (control de reinicio)................................................. 78 
RSCON (Control de ranura de recepción DCI) ......... 223 
SPIxCON1 (Control SPIx 1) ................................... 173 
SPIxCON2 (Control SPIx 2) ................................... 175 

dsPIC33FJXXXGPX06/X08/X10 
DS70286C-página 316 
© 2009 Microchip Technology Inc. 
SPIxSTAT (Estado y control de SPIx) ........................ 172 
SR (estado de la CPU)................................................. 24, 86 
T1CON (Control del temporizador 1)................................. 158 
TSCON (Control de ranura de transmisión DCI) ......... 223 
TxCON (Control T2CON, T4CON, T6CON o T8CON) .. 
162 
TyCON (Control T3CON, T5CON, T7CON o T9CON) .. 
163 
UxMODE (modo UARTx)................................................. 186 
UxSTA (Estado y control de UARTx).................... 188 
Reiniciar 
Selección de fuente de reloj................................................ 79 
Estados de restablecimiento del registro de funciones especiales ................ 80 
Horarios ................................................................................ 79 
Secuencia de reinicio................................................................ 81 
Restablecimientos................................................................................ 77 
S 
Interfaz periférica serie (SPI) ........................................ 171 
Simulador de software (MPLAB SIM)................................. 254 
Puntero de pila de software, puntero de marco 
Marco de pila CALLL................................................ 61 
Características especiales de la CPU................................................ 237 
Módulo SPI 
Mapa de registro SPI1................................................ 48 
Mapa de registro SPI2................................................ 48 
Símbolos utilizados en las descripciones de códigos de operación.................... 246 
Control del sistema 
Mapa de registro................................................................ 60 
t 
Especificaciones de temperatura y voltaje 
CA ................................................................................ 266 
Temporizador1................................................................ 157 
Temporizador 2/3, Temporizador 4/5, Temporizador 6/7 y Temporizador 8/9 ................. 159 
Características de sincronización 
CLKO y E/S ................................................................ 269 
Diagramas de tiempo 
Conversión A/D de 10 bits (CHPS = 01, SIMSAM = 0, ASAM 
= 0, SSRC = 000)................................................. 294 
Conversión A/D de 10 bits (CHPS = 01, SIMSAM = 
0, ÁCIDO = 1, SSRC = 111, SAMC = 
00001)................................................................. 295 
Conversión A/D de 12 bits (ASAM = 0, SSRC = 000) ..... 292 
PUEDE E/S................................................................... 288 
Modo DCI AC-Link ................................................ 287 
DCI multicanal, modos I2S................................ 285 
Reloj externo................................................................ 267 
Datos del bus I2Cx (modo maestro) ................................. 281 
Datos del bus I2Cx (modo esclavo) ................................... 283 
Bits de inicio/parada del bus I2Cx (modo maestro) ................ 281 
Bits de inicio/parada del bus I2Cx (modo esclavo) ................. 283 
Captura de entrada (CAPx) ................................................ 274 
OC/PWM................................................................ 275 
Comparación de salida (OCx)................................................. 274 
Reinicio, temporizador de vigilancia, temporizador de inicio del oscilador y 
Temporizador de encendido................................................ 270 
Modo maestro SPIx (CKE = 0) ................................ 276 
Modo maestro SPIx (CKE = 1) ................................ 277 
Modo esclavo SPIx (CKE = 0) ................................... 278 
Modo esclavo SPIx (CKE = 1) ................................... 279 
Temporizador1, 2, 3, 4, 5, 6, 7, 8, 9 Reloj externo ................ 272 
Requisitos de tiempo 
CLKO y E/S ................................................................ 269 
Modo DCI AC-Link................................................ 287, 289 
DCI multicanal, modos I2S................................ 286, 289 
Reloj externo................................................................ 267 
Captura de entrada................................................... 274 
Especificaciones de sincronización 
Requisitos de conversión A/D de 10 bits ......... 296 
Requisitos de conversión A/D de 12 bits ......... 293 
Requisitos de E/S de CAN................................ 288 
Requisitos de datos del bus I2Cx (modo maestro) ......... 282 
Requisitos de datos del bus I2Cx (modo esclavo).... 284 
Requisitos de comparación de resultados................................ 274 
Reloj PLL ................................................................ 268 
Reinicio, temporizador de vigilancia, temporizador de inicio del oscilador, encendido 
Requisitos de reinicio del temporizador de encendido y de apagón... 
271 
Requisitos simples del modo OC/PWM ................. 275 
Requisitos del modo maestro SPIx (CKE = 0) ................ 276 
Requisitos del modo maestro SPIx (CKE = 1) ................ 277 
Requisitos del modo esclavo SPIx (CKE = 0) ................ 278 
Requisitos del modo esclavo SPIx (CKE = 1) ................ 280 
Requisitos del reloj externo del Timer1.................... 272 
Timer2, Timer4, Timer6 y Timer8 Reloj externo Re- 
Requisitos................................................................ 273 
Timer3, Timer5, Timer7 y Timer9 Reloj externo Re- 
Requisitos................................................................ 273 
Ud. 
Módulo UART 
Mapa de registro UART1................................................ 48 
Mapa de registro UART2................................................ 48 
V 
Regulador de voltaje (en chip) ......................................... 241 
W. 
Temporizador de vigilancia (WDT)................................................. 237, 242 
Consideraciones de programación ................................ 242 
Dirección WWW ................................................................ 317 
WWW, soporte en línea ................................................ 12 

© 2009 Microchip Technology Inc.
DS70286C-página 317
dsPIC33FJXXXGPX06/X08/X10
EL SITIO WEB DEL MICROCHIP
Microchip proporciona soporte en línea a través de nuestro sitio WWW en
www.microchip.com. Este sitio web se utiliza como medio
para que los archivos y la información estén fácilmente disponibles para
clientes. Accesible mediante el uso de su Internet favorito
navegador, el sitio web contiene la siguiente información:
ción:
• Soporte de producto: hojas de datos y erratas, aplicaciones.
notas de catión y programas de muestra, diseño 
recursos, guías del usuario y soporte de hardware 
documentos, últimas versiones de software y archivados 
software
• Soporte técnico general: preguntas frecuentes 
Preguntas (FAQ), solicitudes de soporte técnico, 
grupos de discusión en línea, consultor de Microchip 
listado de miembros del programa
• Negocio de Microchip – Selector de productos y 
guías de pedidos, últimos comunicados de prensa de Microchip, 
listado de seminarios y eventos, listados de Micro-
oficinas de venta de chips, distribuidores y representantes de fábrica.
sentativos
NOTIFICACIÓN DE CAMBIO DE CLIENTE 
SERVICIO
El servicio de notificación al cliente de Microchip ayuda a mantener
clientes al día con los productos Microchip. Suscriptores
Recibirá una notificación por correo electrónico cada vez que haya
cambios, actualizaciones, revisiones o erratas relacionadas con una espec-
familia de productos ificada o herramienta de desarrollo de interés.
Para registrarse, acceda al sitio web de Microchip en
www.microchip.com, haga clic en Notificación de cambio de cliente.
catión y siga las instrucciones de registro.
ATENCIÓN AL CLIENTE
Los usuarios de productos Microchip pueden recibir asistencia
a través de varios canales:
• Distribuidor o Representante
• Oficina de ventas local
• Ingeniero de Aplicaciones de Campo (FAE)
• Soporte técnico
Los clientes deben ponerse en contacto con su distribuidor, representante
técnico o ingeniero de aplicaciones de campo (FAE) para obtener soporte.
Las oficinas de ventas locales también están disponibles para ayudar a los clientes personalizados.
ers. Se incluye una lista de oficinas y ubicaciones de ventas en
el reverso de este documento.
El soporte técnico está disponible a través del sitio web.
en: http://support.microchip.com

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 318
© 2009 Microchip Technology Inc.
RESPUESTA DEL LECTOR
Nuestra intención es proporcionarle la mejor documentación posible para garantizar el uso exitoso de su producto Microchip.
producto.  Si desea proporcionar sus comentarios sobre la organización, la claridad, el tema y las formas en que nuestra documentación
Para servirle mejor, envíe sus comentarios por FAX al Gerente de Publicaciones Técnicas al (480) 792-4150.
Enumere la siguiente información y utilice este esquema para brindarnos sus comentarios sobre este documento.
Para:
Gerente de Publicaciones Técnicas
RE:
Respuesta del lector
Total de páginas enviadas ________
De:
Nombre
Empresa
Dirección
Ciudad / Estado / Código Postal / País
Teléfono: (_______) _________ - _________
Solicitud (opcional):
¿Quieres una respuesta?       Sí No
Dispositivo: 
                                 Número de literatura: 
Preguntas:
FAX: (______) _________ - _________
DS70286C
dsPIC33FJXXXGPX06/X08/X10
1.
¿Cuáles son las mejores características de este documento?
2.
¿Cómo satisface este documento sus necesidades de desarrollo de hardware y software?
3.
¿Le resulta fácil seguir la organización de este documento? Si no, ¿por qué?
4.
¿Qué adiciones al documento cree que mejorarían la estructura y el tema?
5.
¿Qué eliminaciones del documento podrían realizarse sin afectar la utilidad general?
6.
¿Hay alguna información incorrecta o engañosa (qué y dónde)?
7.
¿Cómo mejorarías este documento?

© 2009 Microchip Technology Inc.
DS70286C-página 319
dsPIC33FJXXXGPX06/X08/X10
SISTEMA DE IDENTIFICACIÓN DE PRODUCTOS
Para realizar pedidos u obtener información, por ejemplo, sobre precios o entrega, consulte a la fábrica o a la oficina de ventas indicada.
   
Arquitectura:
33
=
Controlador de señal digital de 16 bits
Familia de memorias flash:
FJ
=
Memoria de programa flash, 3,3 V
Grupo de productos:
GP2
=
familia de uso general
GP3
=
familia de uso general
GP5
=
familia de uso general
GP7
=
familia de uso general
Número de pines:
06
=
64 pines
08
=
80 pines
10
=
100 pines
Rango de temperatura:
yo
= -40°C a
+85°C
(industriales)
Paquete:
PT
=
TQFP (paquete plano cuádruple delgado) de 10x10 o 12x12 mm
FP
=
TQFP de 14x14 mm (paquete plano cuádruple delgado)
Patrón
QTP, SQTP, Código o Requisitos Especiales de tres dígitos 
(en blanco en caso contrario)
ES
=
Muestra de ingeniería
Ejemplos:
a)
dsPIC33FJ256GP710I/PT:
Programa dsPIC33 de uso general, 64 KB 
memoria, 100 pines, temperatura industrial,
Paquete TQFP.
Marca registrada de microchip
Arquitectura
Familia de memorias flash
Tamaño de memoria del programa (KB)
Grupo de productos
Número de pines
Rango de temperatura
Paquete
Patrón
dsPIC 33 FJ 256 GP7 10 T I / PT - XXX
Bandera de cinta y carrete (si corresponde)

DS70286C-página 320
© 2009 Microchip Technology Inc.
AMÉRICAS
Oficina Corporativa
2355 bulevar oeste de Chandler.
Chandler, AZ 85224-6199
Teléfono: 480-792-7200 
Fax: 480-792-7277
Soporte técnico: 
http://support.microchip.com
Dirección web: 
www.microchip.com
Atlanta
Duluth, Georgia, EE.UU. 
Teléfono: 678-957-9614 
Fax: 678-957-1455
Boston
Westborough, Massachusetts, EE.UU. 
Teléfono: 774-760-0087 
Fax: 774-760-0088
chicago
Itasca, Illinois, EE.UU. 
Teléfono: 630-285-0071 
Fax: 630-285-0075
cleveland
Independencia, Ohio 
Teléfono: 216-447-0464 
Fax: 216-447-0643
dallas
Addison, Texas, EE.UU. 
Teléfono: 972-818-7423 
Fax: 972-818-2924
Detroit
Farmington Hills, Michigan, EE.UU. 
Teléfono: 248-538-2250
Fax: 248-538-2260
kokomo
Kokomo, Indiana 
Teléfono: 765-864-8360
Fax: 765-864-8387
Los Ángeles
Mission Viejo, California, EE.UU. 
Teléfono: 949-462-9523 
Fax: 949-462-9608
santaclara
Santa Clara, California, EE.UU. 
Teléfono: 408-961-6444
Fax: 408-961-6445
toronto
Mississauga, Ontario, 
Canadá
Teléfono: 905-673-0699 
Fax: 905-673-6509
ASIA/PACÍFICO
Oficina de Asia Pacífico
Suites 3707-14, Piso 37
Torre 6, La Puerta de Entrada
Ciudad portuaria, Kowloon
hong kong
Teléfono: 852-2401-1200
Fax: 852-2401-3431
Australia - Sídney
Teléfono: 61-2-9868-6733
Fax: 61-2-9868-6755
China - Pekín
Teléfono: 86-10-8528-2100 
Fax: 86-10-8528-2104
China - Chengdú
Teléfono: 86-28-8665-5511
Fax: 86-28-8665-7889
China - RAE de Hong Kong
Teléfono: 852-2401-1200 
Fax: 852-2401-3431
China - Nankín
Teléfono: 86-25-8473-2460
Fax: 86-25-8473-2470
China - Qingdao
Teléfono: 86-532-8502-7355
Fax: 86-532-8502-7205
China - Shangai
Teléfono: 86-21-5407-5533 
Fax: 86-21-5407-5066
China - Shenyang
Teléfono: 86-24-2334-2829
Fax: 86-24-2334-2393
China - Shénzhen
Teléfono: 86-755-8203-2660 
Fax: 86-755-8203-1760
China-Wuhan
Teléfono: 86-27-5980-5300
Fax: 86-27-5980-5118
China - Xiamén
Teléfono: 86-592-2388138 
Fax: 86-592-2388130
China - Xian
Teléfono: 86-29-8833-7252
Fax: 86-29-8833-7256
China - Zhuhai
Teléfono: 86-756-3210040 
Fax: 86-756-3210049
ASIA/PACÍFICO
India - Bangalore
Teléfono: 91-80-3090-4444 
Fax: 91-80-3090-4080
India - Nueva Delhi
Teléfono: 91-11-4160-8631
Fax: 91-11-4160-8632
India - Pune
Teléfono: 91-20-2566-1512
Fax: 91-20-2566-1513
Japón - Yokohama
Teléfono: 81-45-471-6166 
Fax: 81-45-471-6122
Corea - Daegu
Teléfono: 82-53-744-4301
Fax: 82-53-744-4302
Corea - Seúl
Teléfono: 82-2-554-7200
Fax: 82-2-558-5932 o 
82-2-558-5934
Malasia - Kuala Lumpur
Teléfono: 60-3-6201-9857
Fax: 60-3-6201-9859
Malasia - Penang
Teléfono: 60-4-227-8870
Fax: 60-4-227-4068
Filipinas - Manila
Teléfono: 63-2-634-9065
Fax: 63-2-634-9069
Singapur
Teléfono: 65-6334-8870
Fax: 65-6334-8850
Taiwán - Hsin Chu
Teléfono: 886-3-572-9526
Fax: 886-3-572-6459
Taiwán - Kaohsiung
Teléfono: 886-7-536-4818
Fax: 886-7-536-4803
Taiwán - Taipéi
Teléfono: 886-2-2500-6610 
Fax: 886-2-2508-0102
Tailandia - Bangkok
Teléfono: 66-2-694-1351
Fax: 66-2-694-1350
EUROPA
Austria - Gales
Teléfono: 43-7242-2244-39
Fax: 43-7242-2244-393
Dinamarca - Copenhague
Teléfono: 45-4450-2828 
Fax: 45-4485-2829
Francia - París
Teléfono: 33-1-69-53-63-20 
Fax: 33-1-69-30-90-79
Alemania - Múnich
Teléfono: 49-89-627-144-0 
Fax: 49-89-627-144-44
Italia - Milán 
Teléfono: 39-0331-742611 
Fax: 39-0331-466781
Países Bajos - Drunen
Teléfono: 31-416-690399 
Fax: 31-416-690340
España - Madrid
Teléfono: 34-91-708-08-90
Fax: 34-91-708-08-91
Reino Unido - Wokingham
Teléfono: 44-118-921-5869
Fax: 44-118-921-5820
Ventas y servicio a nivel mundial
04/02/09
