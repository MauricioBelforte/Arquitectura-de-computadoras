# Traducción de DsPIC33 - Interrupts -DS70184b.pdf

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-1
Interrumpe
6
Sección 6. Interrupciones
DESTACADOS
Esta sección del manual contiene los siguientes temas:
6.1
Introducción ................................................................................................................................6-2
6.2
Trampas no enmascarables................................................................................................6-7
6.3
Temporización del procesamiento de interrupciones .........................................................................6-13
6.4
Registros de estado y control de interrupciones................................................................6-16
6.5
Procedimientos de configuración de interrupción................................................................6-59
6.6
Consejos de diseño ................................................................................................................6-64
6.7
Notas de aplicación relacionadas................................................................................6-65
6.8
Historial de revisiones...................................................................................................6-66

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-2
preliminar
© 2008 Microchip Technology Inc.
6.1
 INTRODUCCIÓN
El módulo controlador de interrupciones dsPIC33F reduce las numerosas solicitudes de interrupción periférica
señales a una única señal de solicitud de interrupción a la CPU dsPIC33F. Este módulo consta de la
siguientes características:
• Hasta ocho excepciones de procesador y trampas de software
• Siete niveles de prioridad seleccionables por el usuario
• Tabla de vectores de interrupción (IVT) con hasta 126 vectores
• Un vector único para cada fuente de interrupción o excepción
• Prioridad fija dentro de un nivel de prioridad de usuario específico
• Tabla de vectores de interrupción alternativa (AIVT) para soporte de depuración
• Se corrigieron las latencias de entrada y retorno de interrupciones.
6.1.1
Tabla de vectores de interrupción
La tabla de vectores de interrupción (IVT), como se muestra en la Figura 6-1, reside en la memoria del programa a partir de
ubicación 0x000004. El IVT contiene 126 vectores que constan de ocho vectores trampa no enmascarables.
y hasta 118 fuentes de interrupción. En general, cada fuente de interrupción tiene su propio vector. cada uno
El vector de interrupción contiene una dirección de 24 bits de ancho. El valor programado en cada vector de interrupción.
La ubicación es la dirección inicial de la Rutina de Servicio de Interrupción (ISR) asociada.
6.1.2
Tabla de vectores de interrupción alternativos
La Tabla de vectores de interrupción alternativa (AIVT) está ubicada después de la IVT, como se muestra en la Figura 6-1.
El acceso al AIVT lo proporciona el control Habilitar tabla de vectores de interrupción alternativa (ALTIVT)
bit en el registro de control de interrupción 2 (INTCON2<15>). Si el bit ALTIVT está activado, todas las interrupciones y
El proceso de excepción utiliza vectores alternativos en lugar de los vectores predeterminados. Los vectores alternativos
están organizados de la misma manera que los vectores predeterminados. 
El AIVT admite la emulación y la depuración al proporcionar un medio para cambiar entre
una aplicación y un entorno de soporte sin reprogramar los vectores de interrupción. esto
La característica también permite cambiar entre aplicaciones para la evaluación de diferentes software.
algoritmos en tiempo de ejecución. Si el AIVT no es necesario, el AIVT debe programarse con el mismo
direcciones utilizadas en el IVT.
6.1.3
Restablecer secuencia
El reinicio de un dispositivo no es una verdadera excepción porque el controlador de interrupciones no participa en el reinicio.
proceso. El dispositivo dsPIC33F borra sus registros durante el reinicio, lo que fuerza al programa
Contador (PC) a cero. Luego, el procesador comienza la ejecución del programa en la ubicación 0x000000. el
El usuario programa una instrucción GOTO en la dirección Reset, que redirige la ejecución del programa a la dirección Reset.
rutina de arranque adecuada.
Nota:
Cualquier ubicación de vector no implementada o no utilizada en IVT y AIVT debe ser
programado con la dirección de una rutina de manejo de interrupciones predeterminada que contiene un
Instrucción RESET.

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-3
Sección 6. Interrupciones
Interrumpe
6
Figura 6-1:
Tabla de vectores de interrupción
Ver Tabla 6-1
Detalles vectoriales
para interrumpir
TIV
AIVT
Prioridad decreciente del orden natural
Restablecer – Instrucción GOTO
0x000000
Restablecer – IR A Dirección
0x000002
Reservado
0x000004
Vector de trampa de falla del oscilador
0x000006
Vector de trampa de error de dirección
0x000008
Vector de trampa de error de pila
0x00000A
Vector de trampa de error matemático
0x00000C
Vector de trampa de error DMAC
0x00000E
Reservado
0x000010
Reservado
0x000012
Vector de interrupción 0
0x000014
Vector de interrupción 1
0x000016
:
:
:
:
:
:
Vector de interrupción 52
0x00007C
Vector de interrupción 53
0x00007E
Vector de interrupción 54
0x000080
:
:
:
:
:
:
Vector de interrupción 116
0x0000FC
Vector de interrupción 117
0x0000FE
Reservado
0x000100
Reservado
0x000102
Reservado
0x000104
Vector de trampa de falla del oscilador
0x000106
Vector de trampa de error de dirección
0x000108
Vector de trampa de error de pila
0x00010A
Vector de trampa de error matemático
0x00010C
Vector de trampa de error DMAC
0x00010E
Reservado
0x000110
Reservado
0x000112
Vector de interrupción 0
0x000114
Vector de interrupción 1
0x000116
:
:
:
:
:
:
Vector de interrupción 52
0x00017C
Vector de interrupción 53
0x00017E
Vector de interrupción 54
0x000180
:
:
:
:
:
:
Vector de interrupción 116
0x0001FC
Vector de interrupción 117
0x0001FE
INICIO DEL CÓDIGO
0x000200

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-4
preliminar
© 2008 Microchip Technology Inc.
Tabla 6-1:
Detalles del vector de interrupción
número de IRQ
Dirección IVT
Dirección AIVT
Fuente de interrupción
Prioridad de orden natural más alta
0
0x000004
0x000084
Reservado
1
0x000006
0x000086
Fallo del oscilador
2
0x000008
0x000088
Error de dirección
3
0x00000A
0x00008A
Error de pila
4
0x00000C
0x00008C
Error matemático
5
0x00000E
0x00008E
Error DMAC
6
0x000010
0x000091
Reservado
7
0x000012
0x000092
Reservado
8
0x000014
0x000114
INT0 – Interrupción externa 0
9
0x000016
0x000116
IC1 – Comparación de entrada 1
10
0x000018
0x000118
OC1 – Comparación de salida 1
11
0x00001A
0x00011A
T1 – Temporizador1
12
0x00001C
0x00011C
DMA0 – DMA Canal 0
13
0x00001E
0x00011E
IC2 – Captura de entrada 2
14
0x000020
0x000120
OC2 – Comparación de salida 2
15
0x000022
0x000122
T2 – Temporizador2
16
0x000024
0x000124
T3 – Temporizador3
17
0x000026
0x000126
SPI1E – Fallo SPI1
18
0x000028
0x000128
SPI1 – Transferencia SPI1 realizada
19
0x00002A
0x00012A
U1RX – Receptor UART1
20
0x00002C
0x00012C
U1TX – Transmisor UART1
21
0x00002E
0x00012E
AD1 – Conversión ADC1 realizada
22
0x000030
0x000130
DMA1 – DMA Canal 1
23
0x000032
0x000132
Reservado
24
0x000034
0x000134
SI2C1 – Evento esclavo I2C1
25
0x000036
0x000136
MI2C1 – Evento Maestro I2C1
26
0x000038
0x000138
Reservado
27
0x00003A
0x00013A
CN – Interrupción de cambio de entrada
28
0x00003C
0x00013C
INT1 – Interrupción externa 1
29
0x00003E
0x00013E
AD2 – Conversión ADC2 realizada
30
0x000040
0x000140
IC7 – Captura de entrada 7
31
0x000042
0x000142
IC8 – Captura de entrada 8
32
0x000044
0x000144
DMA2 – DMA Canal 2
33
0x000046
0x000146
OC3 – Comparación de salida 3
34
0x000048
0x000148
OC4 – Comparación de salida 4
35
0x00004A
0x00014A
T4 – Temporizador4
36
0x00004C
0x00014C
T5 – Temporizador5
37
0x00004E
0x00014E
INT2 – Interrupción externa 2
38
0x000050
0x000150
U2RX – Receptor UART2
39
0x000052
0x000152
U2TX – Transmisor UART2
40
0x000054
0x000154
SPI2E – Fallo SPI2
41
0x000056
0x000156
SPI2 – Transferencia SPI2 realizada
42
0x000058
0x000158
C1RX – Datos CAN1 RX listos
43
0x00005A
0x00015A
C1 – Evento CAN1
44
0x00005C
0x00015C
DMA3 – DMA Canal 3
45
0x00005E
0x00015E
IC3 – Captura de entrada 3
46
0x000060
0x000160
IC4 – Captura de entrada 4
47
0x000062
0x000162
IC5 – Captura de entrada 5
48
0x000064
0x000164
IC6 – Captura de entrada 6
49
0x000066
0x000166
OC5 – Comparación de salida 5
50
0x000068
0x000168
OC6 – Comparación de salida 6
51
0x00006A
0x00016A
OC7 – Comparación de salida 7

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-5
Sección 6. Interrupciones
Interrumpe
6
52
0x00006C
0x00016C
OC8 – Comparación de salida 8
53
0x00006E
0x00016E
Reservado
54
0x000070
0x000170
DMA4 – DMA Canal 4
55
0x000072
0x000172
T6 – Temporizador6
56
0x000074
0x000174
T7 – Temporizador7
57
0x000076
0x000176
I2C2S – Evento esclavo I2C2
58
0x000078
0x000178
I2C2M – Evento Maestro I2C2
59
0x00007A
0x00017A
T8 – Temporizador8
60
0x00007C
0x00017C
T9 – Temporizador9
61
0x00007E
0x00017E
INT3 – Interrupción externa 3
62
0x000080
0x000180
INT4 – Interrupción externa 4
63
0x000082
0x000182
C2RX – Datos CAN2 RX listos
64
0x000084
0x000184
C2 – Evento CAN2
65
0x000086
0x000186
PWM – Coincidencia de período PWM
66
0x000088
0x000188
QEI – Comparación del contador de posiciones QEI
67
0x00008A
0x00018A
DCIE – Interrupción de falla DCI
68
0x00008C
0x00018C
DCI – Transferencia DCI realizada
69
0x00008E
0x00018E
DMA5 – DMA Canal 5
70
0x000090
0x000190
Reservado
71
0x000092
0x000192
FLTA – Falla MPWM A
72
0x000094
0x000194
FLTB – Fallo MPWM B
73
0x000096
0x000196
U1E – Interrupción de error UART1
74
0x000098
0x000198
U2E – Interrupción de error UART2
75
0x00009A
0x00019A
Reservado
76
0x00009C
0x00019C
DMA6 – DMA Canal 6
77
0x00009E
0x00019E
DMA7 – DMA Canal 7
78
0x0000A0
0x0001A0
C1TX – Solicitud de datos CAN1 TX
79
0x0000A2
0x0001A2
C2TX – Solicitud de datos CAN2 TX
80
0x0000A4
0x0001A4
 Reservado
81
0x0000A6
0x0001A6
 Reservado
82
0x0000A8
0x0001A8
 Reservado
83-124
0x0000AA-0x0000FC
0x0001AA-0x0001FC
 Reservado
125
0x0000FE
0x0001FE
 Reservado
Prioridad de orden natural más baja
Tabla 6-1:
Detalles del vector de interrupción (continuación)
número de IRQ
Dirección IVT
Dirección AIVT
Fuente de interrupción

Manual de referencia de la familia dsPIC33F 
DS70184B-página 6-6 
Preliminar 
© 2008 Microchip Technology Inc. 
6.1.4 
Estado de prioridad de la CPU 
La CPU puede funcionar en uno de los 16 niveles de prioridad que van del 0 al 15. Una fuente de interrupción o trampa 
debe tener un nivel de prioridad mayor que la prioridad actual de la CPU para iniciar un proceso de excepción. 
Puede programar fuentes de interrupción periféricas y externas para los niveles 0-7. Niveles de prioridad de CPU 8-15 
están reservados para fuentes de trampa. 
Una trampa es una fuente de interrupción no enmascarable destinada a detectar problemas de hardware y software. 
(ver 6.2 “Trampas no enmascarables”). El nivel de prioridad para cada fuente de captura es fijo. Sólo una trampa 
se asigna a un nivel de prioridad. Una fuente de interrupción programada con el nivel de prioridad 0 es efectivamente 
deshabilitado, ya que nunca puede ser mayor que la prioridad de la CPU. 
El nivel de prioridad actual de la CPU se indica mediante los siguientes bits de estado: 
• Bits de estado del nivel de prioridad de interrupción de la CPU (IPL<2:0>) en el registro de estado de la CPU (SR<7:5>) 
• Bit de estado de nivel 3 de prioridad de interrupción de CPU (IPL3) en el registro de control central (CORCON<3>) 
Los bits de estado de IPL<2:0> se pueden leer y escribir, por lo que la aplicación del usuario puede modificar estos bits. 
para desactivar todas las fuentes de interrupciones por debajo de un nivel de prioridad determinado. Por ejemplo, si IPL<2:0> = 3, el 
La CPU no sería interrumpida por ninguna fuente con un nivel de prioridad programado de 0, 1, 2 o 3. 
Los eventos de captura tienen mayor prioridad que cualquier fuente de interrupción del usuario. Cuando se establece el bit IPL3, se genera una trampa. 
el evento está en progreso. La aplicación de usuario puede borrar el bit IPL3, pero no establecerlo. en algunos 
aplicaciones, es posible que necesite borrar el bit IPL3 cuando se haya producido una trampa y pasar a una 
instrucción distinta a la siguiente a la que originalmente causó que ocurriera la trampa. 
Todas las fuentes de interrupción del usuario se pueden desactivar configurando IPL<2:0> = 111. 
6.1.5 
Prioridad de interrupción 
Cada fuente de interrupción periférica se puede asignar a uno de los siete niveles de prioridad. el usuario 
Los bits de control de prioridad de interrupción asignables para cada interrupción individual se encuentran en el mínimo 
3 bits significativos de cada nibble dentro de los registros IPCx. El bit 3 de cada nibble no se utiliza y se 
leer como un '0'. Estos bits definen el nivel de prioridad asignado a una interrupción particular. lo utilizable 
Los niveles de prioridad son del 1 (prioridad más baja) al 7 (prioridad más alta). Si los bits IPC asociados con un 
Todas las fuentes de interrupción se borran, la fuente de interrupción se desactiva efectivamente. 
Se puede asignar más de una fuente de solicitud de interrupción a un nivel de prioridad específico. para resolver 
conflictos de prioridad dentro de un determinado nivel asignado a la aplicación de usuario, cada fuente de interrupción tiene un 
Prioridad de orden natural en función de su ubicación en el IVT. La Tabla 6-1 muestra la ubicación de cada 
fuente de interrupción en el IVT. Los vectores de interrupción con números más bajos tienen una prioridad natural más alta, 
mientras que los vectores con números más altos tienen una prioridad natural más baja. El nivel de prioridad general para cualquier 
La fuente pendiente de interrupción se determina primero por la prioridad asignada por el usuario de esa fuente en el 
registro IPCx, luego por el orden de prioridad natural dentro del IVT. 
La prioridad del orden natural se utiliza solo para resolver conflictos entre interrupciones pendientes simultáneas. 
con el mismo nivel de prioridad asignado al usuario. Una vez resuelto el conflicto de prioridad y la excepción 
Cuando comienza el proceso, la CPU sólo puede ser interrumpida por una fuente con mayor prioridad asignada por el usuario. 
Interrupciones con la misma prioridad asignada por el usuario, pero con una prioridad de orden natural más alta que se convierte en 
pendiente durante el proceso de excepción, permanece pendiente hasta el proceso de excepción actual 
completa. 
Asignar cada fuente de interrupción a uno de los siete niveles de prioridad permite que la aplicación del usuario 
dar una interrupción con una prioridad de orden natural baja y un nivel de prioridad general muy alto. Para 
Por ejemplo, a la interrupción UART1 Rx se le puede dar una prioridad de 7 y a la interrupción externa 0 (INT0) 
se puede asignar al nivel de prioridad 1, dándole así una prioridad efectiva muy baja. 
Nota: 
Los bits de IPL<2:0> se convierten en bits de solo lectura cuando se deshabilita el anidamiento de interrupciones. Ver 
6.2.4.2 “Anidamiento de interrupción”, para más información. 
Nota: 
El programa de aplicación debe deshabilitar las interrupciones mientras reconfigura la interrupción. 
niveles de prioridad sobre la marcha. No desactivar las interrupciones puede producir cambios inesperados. 
resultados. 
Nota: 
Los periféricos y fuentes de interrupción disponibles en el IVT varían dependiendo del 
dispositivo dsPIC33F específico. Las fuentes de interrupción que se muestran en este documento. 
representan una lista completa de todas las fuentes de interrupción que se encuentran en dsPIC33F 
dispositivos. Consulte la hoja de datos específica del dispositivo para obtener más detalles. 

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-7
Sección 6. Interrupciones
Interrumpe
6
6.2
 TRAMPAS NO ENMASCARABLES
Las trampas son interrupciones anidables y no enmascarables que se adhieren a una estructura de prioridad fija. Trampas
Proporcionar un medio para corregir el funcionamiento erróneo durante la depuración y el funcionamiento del
aplicación. Si la aplicación del usuario no tiene la intención de corregir una condición de error de captura, estos vectores
debe cargarse con la dirección de una rutina de software para restablecer el dispositivo. De lo contrario, el usuario
La aplicación programa el vector de trampa con la dirección de una rutina de servicio que corrige la trampa.
condición.
El dsPIC33F consta de las siguientes fuentes implementadas de trampas no enmascarables:
• Trampa de falla del oscilador
• Trampa de error de pila
• Trampa de error de dirección
• Trampa de errores matemáticos
• Trampa de errores DMAC
Para muchas de las condiciones de trampa, se permite que la instrucción que causó la trampa se complete antes
comienza el procesamiento de excepciones. Por lo tanto, es posible que la aplicación de usuario tenga que corregir la acción de
la instrucción que causó la trampa. 
Cada fuente de trampa tiene una prioridad fija definida por su posición en el IVT. Una trampa de falla del oscilador
tiene la prioridad más alta, mientras que una captura de error del controlador DMA (DMAC) tiene la prioridad más baja (consulte
Figura 6-1). Además, las fuentes de trampas se clasifican en dos categorías distintas: trampas blandas y trampas blandas.
trampas duras.
6.2.1
Trampas blandas
La trampa de errores DMAC (nivel de prioridad 10), la trampa de errores matemáticos (nivel de prioridad 11) y la trampa de errores de pila
(nivel de prioridad 12) se clasifican como fuentes de trampas blandas. Las trampas blandas pueden tratarse como
Fuentes de interrupción no enmascarables que respetan la prioridad asignada por su posición en el IVT.
Las trampas suaves se procesan como interrupciones y requieren dos ciclos para ser muestreadas y reconocidas.
antes del procesamiento de excepción. Por lo tanto, se pueden ejecutar instrucciones adicionales antes de que se ejecute un software.
Se reconoce la trampa.
6.2.1.1
TRAMPA DE ERROR DE APILACIÓN (TRAMPA SUAVE, NIVEL 12)
La pila se inicializa a 0x0800 durante un reinicio. Se genera una trampa de error de pila, si la pila
La dirección del puntero es inferior a 0x0800.
Un registro de límite de pila (SPLIM) asociado con el puntero de pila no se inicializa en el reinicio. el
La verificación de desbordamiento de pila no se habilita hasta que se escribe una palabra en el registro SPLIM.
Todas las direcciones efectivas (EA) generadas utilizando W15 como puntero de origen o destino son
comparado con el valor en el registro SPLIM. Si el EA es mayor que el contenido del
Registro SPLIM, se genera una trampa de error de pila. Además, se genera una trampa de error de pila si el
El cálculo de EA finaliza hasta el final del espacio de datos (0xFFFF). 
Se puede detectar un error de pila en el software sondeando el bit de estado de la trampa de errores de pila (STKERR).
(INTCON1<2>). Para evitar volver a ingresar a la rutina de servicio de captura, el indicador de estado STKERR debe estar
borrado (en software) antes de que el programa regrese de la trampa (con una instrucción RETFIE).

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-8
preliminar
© 2008 Microchip Technology Inc.
6.2.1.2
TRAMPA DE ERRORES MATEMÁTICOS (TRAMPA SUAVE, NIVEL 11)
Cualquiera de los siguientes eventos genera una trampa de error matemático: 
• Desbordamiento del acumulador A 
• Desbordamiento del acumulador B
• Desbordamiento catastrófico del acumulador
• Dividir por cero
• Operación del acumulador de desplazamiento (SFTAC) que excede ±16 bits
Tres bits en el registro INTCON1 habilitan tres tipos de trampas de desbordamiento del acumulador. 
• El bit de control del indicador de trampa de desbordamiento del acumulador A (OVATE) (INTCON1<10>) habilita las trampas. 
para un evento de desbordamiento del Acumulador A. 
• El bit de control del indicador de trampa de desbordamiento del acumulador B (OVBTE) (INTCON1<9>) habilita las trampas. 
para un evento de desbordamiento del Acumulador B. 
• El bit de control de activación de trampa de desbordamiento catastrófico (COVTE) (INTCON1<8>) habilita las trampas. 
por un desbordamiento catastrófico de cualquiera de los acumuladores. Cuando se detecta esta trampa, estos 
Los bits de ERROR correspondientes se establecen en el registro INTCON1:
- Bandera de trampa de desbordamiento del acumulador A (OVAERR)
- Bandera de trampa de desbordamiento del acumulador B (OVBERR)
- Habilitación de trampa de desbordamiento catastrófico del acumulador A (COVAERR)
- Habilitación de trampa de desbordamiento catastrófico del acumulador B (COVBERR)
Un evento de desbordamiento del Acumulador A o del Acumulador B se define como una ejecución del bit 31.
El desbordamiento del acumulador no puede ocurrir si el modo de saturación de 31 bits está habilitado para el acumulador.
Un desbordamiento catastrófico del acumulador se define como una transferencia del bit 39 de cualquiera de los acumuladores.
El desbordamiento catastrófico no puede ocurrir si la saturación del acumulador (31 bits o 39 bits) está habilitada.
Las trampas de división por cero no se pueden desactivar. La verificación de división por cero se realiza durante la primera
iteración del bucle REPEAT que ejecuta la instrucción de división. El estado del error matemático
El bit (DIV0ERR) (INTCON1<6>) se establece cuando se detecta esta trampa.
Las trampas de cambio del acumulador no se pueden desactivar. La instrucción SFTAC se puede utilizar para cambiar el
acumulador por un valor literal o un valor en uno de los registros W. Si el valor del cambio excede
±16 bits, se genera una trampa aritmética y el bit de estado de error del acumulador de desplazamiento (SFTACERR)
(INTCON1<7>) está configurado. La instrucción SFTAC se ejecuta, pero los resultados del cambio no se escriben
al acumulador de destino.
Se puede detectar una trampa de error matemático en el software sondeando el bit de estado de error matemático (MATHERR)
(INTCON1<4>). Para evitar volver a ingresar a la rutina del servicio de captura, el indicador de estado MATHERR debe
borrarse (en software) antes de que el programa regrese de la trampa (con una instrucción RETFIE).
Antes de que se pueda borrar el bit de estado MATHERR, se deben borrar todas las condiciones que causaron la captura.
también ser aclarado. Si la trampa se debió a un desbordamiento del acumulador, el Desbordamiento del acumulador (OA
y OB) se deben borrar los bits de estado (SR<15:14>). Los bits de estado OA y OB son de sólo lectura, por lo que
El software del usuario debe realizar una operación ficticia en el acumulador desbordado (como
agregando '0'), lo que hará que el hardware borre el bit de estado OA u OB.
6.2.1.3
TRAMPA DE ERROR DMAC (TRAMPA SUAVE, NIVEL 10)
Se produce una trampa de error DMAC con estas condiciones:
• Colisión de escritura en RAM
• Colisión de escritura en RAM periférica lista para DMA
Los errores de colisión de escritura son una amenaza lo suficientemente grave para la integridad del sistema como para justificar una solución no enmascarable.
Evento de trampa de CPU. Si tanto la CPU como un canal DMA intentan escribir en una dirección de destino, el
Se da prioridad a la CPU y se ignora la escritura DMA. En este caso, se genera una trampa de error DMAC.
y se establece el bit de estado de error DMAC (DMACERR) (INTCON1<5>).

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-9
Sección 6. Interrupciones
Interrumpe
6
6.2.2
Trampas duras
Las trampas difíciles incluyen excepciones del nivel de prioridad 13 al 15, inclusive. El error de dirección
(nivel 13) y las trampas de error del oscilador (nivel 14) entran en esta categoría.
Al igual que las trampas suaves, las trampas duras son fuentes de interrupción que no se pueden enmascarar. La diferencia entre duro
trampas y trampas suaves es que las trampas duras obligan a la CPU a detener la ejecución del código después de la instrucción.
provocando que la trampa se haya completado. El flujo normal de ejecución del programa no se reanuda hasta que se elimina la trampa.
ha sido reconocido y procesado.
6.2.2.1
PRIORIDAD DE TRAMPA Y CONFLICTOS DE TRAMPA DIFÍCIL
Si se produce una captura de mayor prioridad mientras hay alguna trampa de menor prioridad en progreso, el procesamiento de la
Se suspende la trampa de menor prioridad. La captura de mayor prioridad se reconoce y procesa. el
La captura de menor prioridad permanece pendiente hasta que se completa el procesamiento de la captura de mayor prioridad.
Cada trampa difícil que se produzca debe reconocerse antes de que pueda ejecutarse código de cualquier tipo.
continuar. Si se produce una trampa dura de menor prioridad mientras hay pendiente una trampa de mayor prioridad, se reconoce
o se está procesando, se produce un conflicto de trampa dura porque la trampa de menor prioridad no puede
se reconoce hasta que se completa el procesamiento de la captura de mayor prioridad.
El dispositivo se reinicia automáticamente en una condición de conflicto de trampa dura. La bandera de reinicio de trampa (TRAPR)
El bit de estado en el registro de control de reinicio (RCON<15> en el módulo de reinicio) se establece cuando el reinicio
ocurre para que la condición pueda ser detectada en el software.
6.2.2.2
TRAMPA DE FALLA DEL OSCILADOR (TRAMPA DURA, NIVEL 14)
Se genera un evento de trampa de falla del oscilador por cualquiera de estos motivos:
• El monitor de reloj a prueba de fallos (FSCM) está habilitado y ha detectado una pérdida del sistema. 
fuente del reloj.
• Se ha detectado una pérdida del bloqueo de PLL durante el funcionamiento normal utilizando el PLL.
• El FSCM está habilitado y el PLL no logra bloquearse en un reinicio de encendido (POR).
Se puede detectar un evento de trampa de falla del oscilador en el software sondeando la trampa de falla del oscilador.
(OSCFAIL) bit de estado (INTCON1<1>) o el bit de estado Clock Fail (CF) (OSCCON<3> en el
Módulo oscilador). Para evitar volver a ingresar a la rutina del servicio de captura, el indicador de estado OSCFAIL debe
borrarse (en software) antes de que el programa regrese de la trampa (con una instrucción RETFIE).
Consulte la Sección 7 "Oscilador" (DS70186) y la Sección 25 "Configuración del dispositivo"
(DS70194), para obtener más información sobre el monitor de reloj a prueba de fallos. Consulta la web de Microchip
Visite el sitio www.microchip.com para obtener la documentación más reciente.
6.2.2.3
TRAMPA DE ERROR DE DIRECCIÓN (TRAMPA DURA, NIVEL 13)
Las condiciones operativas que pueden generar una trampa de error de dirección incluyen:
• Se intenta recuperar una palabra de datos desalineada. Esta condición ocurre cuando una instrucción 
realiza un acceso a palabra con el bit menos significativo (LSb) de la dirección efectiva establecido en 
'1'. La CPU dsPIC33F requiere que todos los accesos a palabras estén alineados con una dirección par 
límite.
• Una instrucción de manipulación de bits utiliza el modo de direccionamiento indirecto con el LSb del 
dirección efectiva establecida en '1'.
• Se intenta recuperar datos desde un espacio de direcciones de datos no implementado.
• Ejecución de una instrucción #literal BRA o una instrucción #literal GOTO, donde 
literal es una dirección de memoria de programa no implementada.
• Ejecución de instrucciones después de que el contador de programa se haya modificado para que apunte a 
direcciones de memoria de programas no implementadas. El contador de programa se puede modificar mediante 
cargar un valor en la pila y ejecutar una instrucción RETURN.
Cuando se produce una trampa de error de dirección, las escrituras en el espacio de datos se inhiben para que los datos no se destruyan.

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-10
preliminar
© 2008 Microchip Technology Inc.
Se puede detectar un error de dirección en el software sondeando el bit de estado ADDRERR (INTCON1<3>).
Para evitar volver a ingresar a la rutina de servicio de captura (TSR), se debe borrar el indicador de estado ADDRERR
(en software) antes de que el programa regrese de la trampa (con una instrucción RETFIE).
6.2.3
Desactivar instrucción de interrupciones
La instrucción DISI (Desactivar interrupciones) puede desactivar interrupciones hasta por 16384 ciclos de instrucción.
Esta instrucción es útil para ejecutar segmentos de código en los que el tiempo es crítico.
La instrucción DISI solo desactiva las interrupciones con niveles de prioridad 1-6. El nivel de prioridad 7 interrumpe y
Todos los eventos de captura aún pueden interrumpir la CPU cuando la instrucción DISI está activa. 
La instrucción DISI funciona junto con el registro Disable Interrupts Count (DISICNT).
en la CPU. Cuando el registro DISICNT es distinto de cero, las interrupciones de nivel de prioridad 1-6 están deshabilitadas. el
El registro DISICNT disminuye en cada ciclo de instrucción posterior. Cuando el DISICTO
el registro cuenta atrás hasta cero, las interrupciones de nivel de prioridad 1-6 se vuelven a habilitar. El valor especificado en
la instrucción DISI incluye todos los ciclos debidos a accesos de PSV, paradas de instrucción, etc.
El registro DISICNT se puede leer y escribir. La aplicación del usuario puede cancelar el efecto.
de una instrucción DISI anterior antes de tiempo borrando el registro DISICNT. El tiempo que las interrupciones son
deshabilitado también se puede aumentar escribiendo o agregando al registro DISICNT. 
Si el registro DISICNT es cero, las interrupciones no se pueden desactivar simplemente escribiendo un valor distinto de cero
al registro. Primero se deben desactivar las interrupciones mediante la instrucción DISI. Una vez que la DISI
instrucción se ha ejecutado y DISICNT tiene un valor distinto de cero, la aplicación puede extender el
interrumpir el tiempo de desactivación modificando el contenido de DISICNT.
El bit de estado de la instrucción DISI (DISI) (INTCON2<14>) se establece siempre que las interrupciones están deshabilitadas como
como resultado de la instrucción DISI.
6.2.4
Operación de interrupción
Todos los indicadores de eventos de interrupción se muestrean durante cada ciclo de instrucción. Una solicitud de interrupción pendiente
(IRQ) se indica mediante el bit de bandera = 1 en un registro IFSx. El IRQ causa una interrupción, si el
Se establece el bit correspondiente en los registros de habilitación de interrupción (IECx). Para el resto de la instrucción.
ciclo en el que se muestrea la IRQ, se evalúan las prioridades de todas las solicitudes de interrupción pendientes. 
Ninguna instrucción se cancela cuando la CPU responde a la IRQ. La instrucción en curso cuando
La muestra de la IRQ se completa antes de que se ejecute la rutina de interrupción del servicio (ISR).
Si hay una IRQ pendiente con un nivel de prioridad asignado por el usuario mayor que el procesador actual
nivel de prioridad, indicado por los bits de estado IPL<2:0> (SR<7:5>), se presenta una interrupción al 
procesador. Luego, el procesador guarda la siguiente información en la pila de software:
• Valor de PC actual
• Byte bajo del registro de estado del procesador (SRL)
• Bit de estado IPL3 (CORCON<3>)
Estos tres valores permiten return el valor de la dirección del contador de programa, los bits de estado de la MCU y la corriente.
El nivel de prioridad del procesador se guardará automáticamente. 
Después de guardar esta información en la pila, la CPU escribe el nivel de prioridad de las tareas pendientes.
interrumpir en las ubicaciones de bits IPL<2:0>. Esta acción desactiva todas las interrupciones de menor o igual
prioridad hasta que el ISR finalice utilizando la instrucción RETFIE. 
Nota:
En la clase de instrucciones MAC, el espacio de datos se divide en espacios X e Y. En estos
instrucciones, el espacio X no implementado incluye todo el espacio Y, y el espacio Y no implementado
el espacio incluye todo el espacio X.
Nota:
La instrucción DISI se puede utilizar para desactivar rápidamente todas las fuentes de interrupción del usuario, si no
La fuente está asignada al nivel de prioridad de CPU 7.

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-11
Sección 6. Interrupciones
Interrumpe
6
Figura 6-2:
Operación de pila para evento de interrupción
6.2.4.1
REGRESO DE INTERRUPCIÓN
La instrucción RETFIE (Retorno de interrupción) desapila la dirección de retorno de la PC, bit de estado IPL3
y registro SRL para return el procesador al estado y nivel de prioridad que existía antes de la
secuencia de interrupción. 
6.2.4.2
ANIDADO DE INTERRUPCIONES
Las interrupciones son anidables de forma predeterminada. Cualquier ISR en curso puede ser interrumpido por otra fuente de
interrumpir con un nivel de prioridad más alto asignado por el usuario. El anidamiento de interrupciones se puede desactivar configurando
el bit de control Interrupt Nesting Disable (NSTDIS) (INTCON1<15>). Cuando el control NSTDIS
Cuando se establece el bit, todas las interrupciones en curso fuerzan la prioridad de la CPU al nivel 7 configurando IPL<2:0> = 111.
Esta acción enmascara efectivamente todas las demás fuentes de interrupción hasta que se ejecuta una instrucción RETFIE.
Cuando el anidamiento de interrupciones está deshabilitado, los niveles de prioridad de interrupción asignados por el usuario no tienen ningún efecto.
excepto para resolver conflictos entre interrupciones pendientes simultáneas.
Los bits IPL<2:0> (SR<7:5>) pasan a ser de solo lectura cuando se deshabilita el anidamiento de interrupciones. Esto evita
impedir que el software del usuario establezca IPL<2:0> en un valor más bajo, lo que volvería a habilitar
interrumpir el anidamiento.
6.2.5
Despertar desde el modo de suspensión e inactividad
Cualquier fuente de interrupción que se habilite individualmente, utilizando su correspondiente bit de control en el IECx
registros, puede reactivar el procesador desde el modo de suspensión o inactivo. Cuando el indicador de estado de interrupción para
Se establece una fuente y la fuente de interrupción se habilita mediante el bit correspondiente en el control IEC.
registra, se envía una señal de activación a la CPU dsPIC33F. Cuando el dispositivo sale del modo de suspensión o
Modo inactivo, ocurre una de dos acciones:
• Si el nivel de prioridad de interrupción para esa fuente es mayor que el nivel de prioridad actual de la CPU, el 
El procesador procesará la interrupción y se bifurcará al ISR para la fuente de interrupción.
• Si el nivel de prioridad de interrupción asignado por el usuario para la fuente es menor o igual al 
nivel de prioridad actual de la CPU, el procesador continuará la ejecución, comenzando con la instrucción 
inmediatamente después de la instrucción PWRSAV que previamente puso la CPU en suspensión o inactiva 
modo.
Nota:
Las fuentes de interrupción del usuario que están asignadas al nivel de prioridad 0 de la CPU no pueden reactivar el sistema.
CPU desde el modo de suspensión o inactivo, porque la fuente de interrupción está efectivamente desactivada.
Para utilizar una interrupción como fuente de activación, el programa debe asignar la prioridad de la CPU
nivel para la interrupción al nivel 1 o superior.
<Palabra libre>
ordenador<15:0>
PC<22:16>
0
15
W15 (antes de la IRQ)
W15 (después de IRQ)
La pila crece hacia
dirección superior
SR<7:0>
Esta pila almacena
el estado de IPL3
bit (CORCON<3>)

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-12
preliminar
© 2008 Microchip Technology Inc.
6.2.6
Conversión externa del convertidor analógico a digital (ADC) 
Solicitar
El pin de solicitud de interrupción externa INT0 se comparte con el ADC como una solicitud de conversión externa
señal. La fuente de interrupción INT0 tiene polaridad de borde programable, que también está disponible para el
Función de solicitud de conversión externa de ADC. 
6.2.7
Soporte de interrupción externa
El dsPIC33F admite hasta cinco fuentes de pines de interrupción externas (INT0-INT4). Cada externo
El pin de interrupción tiene un circuito de detección de bordes para detectar el evento de interrupción. El registro INTCON2 tiene
Cinco bits de control (INT0EP-INT4EP) que seleccionan la polaridad del circuito de detección de bordes. cada uno
El pin de interrupción externo se puede programar para interrumpir la CPU en un flanco ascendente o descendente.
evento. Consulte el Registro 6-4 para obtener más detalles.

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-13
Sección 6. Interrupciones
Interrumpe
6
6.3
 TIEMPO DE PROCESAMIENTO DE INTERRUPCIONES
6.3.1
Latencia de interrupción para instrucciones de un ciclo
La Figura 6-3 muestra la secuencia de eventos cuando se afirma una interrupción periférica durante un
instrucción de un ciclo. El proceso de interrupción requiere cuatro ciclos de instrucción. Cada ciclo está numerado.
(en la figura) como referencia.
El bit de estado del indicador de interrupción se establece durante el ciclo de instrucción después de que ocurre la interrupción periférica.
La instrucción actual se completa durante este ciclo de instrucción. En la segunda instrucción
ciclo después del evento de interrupción, el contenido de la PC y los registros de estado de byte inferior (SRL) se
guardado en un registro de búfer temporal. El segundo ciclo del proceso de interrupción se ejecuta como
un NOP para mantener la coherencia con la secuencia tomada durante una instrucción de dos ciclos (ver
6.3.2 “Latencia de interrupción para instrucciones de dos ciclos”). En el tercer ciclo, la PC se carga con
Se recupera la dirección de la tabla de vectores para la fuente de interrupción y la dirección inicial del ISR.
En el cuarto ciclo, la PC se carga con la dirección ISR. El cuarto ciclo se ejecuta como NOP
mientras que se recupera la primera instrucción en el ISR.
Figura 6-3:
Interrupción del tiempo durante una instrucción de un ciclo 
4
6
6
6
4
4
INST(PC-2)
INST(PC)
FNOP
FNOP
ISR
INST
ejecutado
Bandera de interrupción
PUSH Baja 16 bits de PC
PUSH SRL y Alta 8 bits de PC
6
4
ISS + 2
ISR+4
Prioridad de CPU
buscar 
2000 (ISR)
2002
2004
2006
ordenador personal
PC+2
ordenador personal
Vector
Guardar PC en 
Bit de estado
Vector#
Evento de interrupción periférica
ocurre en o antes del punto medio
TCY
1
2
3
4
temporal
buffer
de este ciclo
(desde el búfer temporal)
(desde el búfer temporal)

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-14
preliminar
© 2008 Microchip Technology Inc.
6.3.2
Latencia de interrupción para instrucciones de dos ciclos
La latencia de interrupción durante una instrucción de dos ciclos es la misma que durante una instrucción de un ciclo.
El primer y segundo ciclo del proceso de interrupción permiten que se complete la instrucción de dos ciclos.
ejecución. El diagrama de tiempos en la Figura 6-4 muestra el evento de interrupción periférica que ocurre en el
ciclo de instrucción antes de la ejecución de la instrucción de dos ciclos.
La Figura 6-5 muestra el momento en que una interrupción periférica coincide con el primer ciclo de una
instrucción de dos ciclos. En este caso, el proceso de interrupción se completa como para una instrucción de un ciclo.
(consulte 6.3.1 “Latencia de interrupción para instrucciones de un ciclo”).
Figura 6-4:
 Interrupción del tiempo durante una instrucción de dos ciclos
Figura 6-5:
Temporización de interrupción, la interrupción se produce durante el primer ciclo de una instrucción de dos ciclos 
4
6
6
6
4
4
INST(PC-2)
INST(PC)
INST(PC)
FNOP
ISR
INST
ejecutado
Bandera de interrupción
PUSH Baja 16 bits de PC
PUSH SRL y Alta 8 bits de PC
6
4
ISS + 2
ISR+4
Prioridad de CPU
buscar 
2000 (ISR)
2002
2004
2006
ordenador personal
PC+2
ordenador personal
Vector
Guardar PC en
Bit de estado
Vector#
Evento de interrupción periférica
ocurre en o antes
TCY
1
2
3
4
2do ciclo
1er ciclo
temporal
buffer
punto medio de este ciclo
(desde el búfer temporal)
(desde el búfer temporal)
4
6
6
6
4
4
INST(PC)
INST(PC)
FNOP
ISR
INST
ejecutado
Bandera de interrupción
PUSH Baja 16 bits de PC
PUSH SRL y Alta 8 bits de PC
6
4
ISS + 2
ISR+4
Prioridad de CPU
buscar 
2000 (ISR)
2002
2004
2006
ordenador personal
PC + 2
ordenador personal
Vector
Guardar PC en
Bit de estado
Vector#
Evento de interrupción periférica
ocurre en o antes
TCY
1
2
3
4
2do ciclo
1er ciclo
temporal
buffer
FNOP
punto medio de este ciclo
(desde el búfer temporal)
(desde el búfer temporal)

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-15
Sección 6. Interrupciones
Interrumpe
6
6.3.3
Regresando de la interrupción
Para regresar de una interrupción, el programa debe llamar a la instrucción RETFIE.
Durante los primeros dos ciclos de una instrucción RETFIE, el contenido de la PC y el registro SRL
se extraen de la pila. El tercer ciclo de instrucción se utiliza para recuperar la instrucción direccionada.
por el contador de programa actualizado. Este ciclo se ejecuta como una instrucción NOP. En el cuarto ciclo,
La ejecución del programa se reanuda en el punto donde ocurrió la interrupción.
Figura 6-6:
Regreso de la sincronización de interrupción 
6.3.4
Condiciones especiales para la latencia de interrupción
El dsPIC33F permite que la instrucción actual se complete cuando una fuente de interrupción periférica
queda pendiente. La latencia de interrupción es la misma para instrucciones de uno y dos ciclos.
Sin embargo, ciertas condiciones pueden aumentar la latencia de interrupción en un ciclo, dependiendo de cuándo
se produce la interrupción. Si una latencia fija es crítica para la aplicación, se deben cumplir las siguientes condiciones.
evitado: 
• La ejecución de una instrucción MOV.D utiliza PSV para acceder a un valor en el espacio de memoria del programa.
• Agregar un ciclo de parada de instrucción a cualquier instrucción de dos ciclos
• Agregar un ciclo de pérdida de instrucción a cualquier instrucción de un ciclo que realice una PSV 
acceso
• Una prueba de bits y una instrucción de omisión (BTSC, BTSS) que utiliza PSV para acceder a un valor en el programa. 
espacio de memoria
4
4
4
4
6
6
CPU
Prioridad
REFIE
REFIE
ordenador personal
INST
ejecutado
FNOP
ISR último
6
PC + 2
PC + 4
ordenador personal
PC + 2
PC + 4
PC + 6
ISR
ISS + 2
ordenador personal
2do ciclo
TCY
instrucción
1
2
3
4

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-16
preliminar
© 2008 Microchip Technology Inc.
6.4
 CONTROL DE INTERRUPCIONES Y REGISTROS DE ESTADO
Estos están asociados con el controlador de interrupciones:
• Registros INTCON1, INTCON2
Estos registros controlan las funciones de interrupción global:
- INTCON1 contiene el bit Interrupt Nesting Disable (NSTDIS), así como el bit de control 
e indicadores de estado para las fuentes de captura del procesador. 
- INTCON2 controla el comportamiento de la señal de solicitud de interrupción externa y el uso de la alternativa 
tabla de vectores.
• IFSx: Registros de estado de indicador de interrupción
Todos los indicadores de solicitud de interrupción se mantienen en los registros IFSx, donde 'x' indica el       
número de registro. Cada fuente de interrupción tiene un bit de estado, que es establecido por el respectivo 
periféricos o señal externa y se borra mediante software.
• IECx: Registros de control de habilitación de interrupciones
Todos los bits de control de habilitación de interrupción se mantienen en los registros IECx, donde 'x' indica el 
número de registro. Estos bits de control se utilizan para habilitar individualmente las interrupciones del 
periféricos o señales externas.
• IPCx: Registros de control de prioridad de interrupción
Cada fuente de interrupción de usuario se puede asignar a uno de los ocho niveles de prioridad. El IPC se registra 
establezca el nivel de prioridad de interrupción para cada fuente de interrupción. 
• SR: Registro de estado de la CPU 
El SR no es específicamente parte del hardware del controlador de interrupciones, pero contiene el 
Bits de estado IPL<2:0> (SR<7:5>) que indican el nivel de prioridad de la CPU actual. el usuario 
La aplicación puede cambiar el nivel de prioridad actual de la CPU escribiendo en los bits de IPL.
• CORCON: Registro de Control Central 
El registro CORCON no es específicamente parte del hardware del controlador de interrupciones, pero 
Contiene el bit de estado IPL3, que indica el nivel de prioridad actual de la CPU. IPL3 es un 
bit de solo lectura para que el software del usuario no pueda enmascarar los eventos de captura.
Cada registro se describe en detalle en las siguientes secciones.
6.4.1
Asignación de Interrupciones a Registros de Control
Las fuentes de interrupción se asignan a los registros IFSx, IECx e IPCx en la misma secuencia
que se enumeran en la Tabla 6-1. Por ejemplo, la fuente INT0 (Interrupción externa 0) tiene vector
número y prioridad de orden natural 0. Por lo tanto, el bit de estado de indicador de interrupción externa 0 (INT0IF)
existe en IFS0<0>. La interrupción INT0 utiliza el bit 0 del registro IEC0 como bit de habilitación. el
Los bits IPC0<2:0> asignan el nivel de prioridad de interrupción para la interrupción INT0.
Nota:
El número total y el tipo de fuentes de interrupción dependen de la variante del dispositivo. Referir
Consulte la hoja de datos del dispositivo específico para obtener más detalles.

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-17
Sección 6. Interrupciones
Interrumpe
6
 
Registro 6-1:
SR: Registro de estado (en CPU)
R-0
R-0
R/C-0
R/C-0
R-0
R/C-0
R-0
R-0
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
R/W-0
R/W-0
R/W-0
R-0
R/W-0
R/W-0
R/W-0
R/W-0
IPL<2:0>
RA
norte
VO
z
c
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
No utilizado por el controlador de interrupciones
(Consulte el “Manual de referencia del programador dsPIC30F/33F” (DS70157) para obtener descripciones de los bits SR)
bits 7-5
IPL<2:0>: Bits de estado del nivel de prioridad de interrupción de la CPU (1,2)
111 = el nivel de prioridad de interrupción de la CPU es 7 (15). Interrupciones de usuario deshabilitadas
110 = el nivel de prioridad de interrupción de la CPU es 6 (14)
101 = el nivel de prioridad de interrupción de la CPU es 5 (13)
100 = el nivel de prioridad de interrupción de la CPU es 4 (12)
011 = el nivel de prioridad de interrupción de la CPU es 3 (11)
010 = el nivel de prioridad de interrupción de la CPU es 2 (10)
001 = el nivel de prioridad de interrupción de la CPU es 1 (9)
000 = el nivel de prioridad de interrupción de la CPU es 0 (8)
poco 4-0
No utilizado por el controlador de interrupciones
(Consulte el “Manual de referencia del programador dsPIC30F/33F” (DS70157) para obtener descripciones de los bits SR)
Nota 1:
Los bits IPL<2:0> se concatenan con el bit IPL<3> (CORCON<3>) para formar la prioridad de interrupción de la CPU. 
nivel. El valor entre paréntesis indica la IPL si IPL<3> = 1.
2:
Los bits de estado de IPL<2:0> son de sólo lectura cuando NSTDIS = 1 (INTCON1<15>).

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-18
preliminar
© 2008 Microchip Technology Inc.
 
Registro 6-2:
CORCON: Registro de Control Central 
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
DL<1:0>
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
IPL3
PSV
RND
SI
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
bit 15-4
No utilizado por el controlador de interrupciones
(Consulte el “Manual de referencia del programador dsPIC30F/33F” (DS70157) para obtener descripciones de los bits CORCON)
poco 3
IPL3: Bit de estado 3(1) del nivel de prioridad de interrupción de la CPU
1 = el nivel de prioridad de interrupción de la CPU es mayor que 7
0 = el nivel de prioridad de interrupción de la CPU es 7 o menos
poco 2-0
No utilizado por el controlador de interrupciones
(Consulte el “Manual de referencia del programador dsPIC30F/33F” (DS70157) para obtener descripciones de los bits CORCON)
Nota 1:
El bit IPL3 se concatena con los bits IPL<2:0> (SR<7:5>) para formar el nivel de prioridad de interrupción de la CPU.

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-19
Sección 6. Interrupciones
Interrumpe
6
 
Registro 6-3:
INTCON1: Registro de control de interrupción 1
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
DIV0ERR: Bit de estado de error de división por cero
1 = La trampa de error de división por cero fue causada por una división por cero
0 = La trampa de error de división por cero no fue causada por una división por cero
poco 5
DMACERR: bit de estado de error DMAC
1 = Se ha producido una trampa DMAC
0 = No se ha producido la trampa DMAC
poco 4
MATHERR: Bit de estado de error matemático
1 = Se ha producido una trampa de error matemático
0 = No se ha producido la trampa de error matemático
poco 3
ADDRERR: Bit de estado de captura de error de dirección
1 = Se ha producido una trampa de error de dirección
0 = No se ha producido la captura de error de dirección

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-20
preliminar
© 2008 Microchip Technology Inc.
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
Registro 6-3:
INTCON1: Registro de control de interrupción 1 (continuación)

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-21
Sección 6. Interrupciones
Interrumpe
6
 
Registro 6-4:
INTCON2: Registro de control de interrupción 2 
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-22
preliminar
© 2008 Microchip Technology Inc.
    
Registro 6-5:
IFS0: Registro de estado de indicador de interrupción 0
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
DMA0IF
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
DMA0IF: Transferencia de datos del canal 0 de DMA completa Bit de estado del indicador de interrupción
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 3
T1IF: Bit de estado del indicador de interrupción del temporizador 1
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-23
Sección 6. Interrupciones
Interrumpe
6
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
Registro 6-5:
IFS0: Registro de estado de indicador de interrupción 0 (continuación)

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-24
preliminar
© 2008 Microchip Technology Inc.
 
Registro 6-6:
IFS1: Registro de estado de indicador de interrupción 1
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
DMA2IF
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
DMA2IF: Transferencia de datos del canal 2 de DMA completa Bit de estado del indicador de interrupción
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

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-25
Sección 6. Interrupciones
Interrumpe
6
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
Registro 6-6:
IFS1: Registro de estado de indicador de interrupción 1 (continuación)

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-26
preliminar
© 2008 Microchip Technology Inc.
 
Registro 6-7:
IFS2: Registro de estado de indicador de interrupción 2
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

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-27
Sección 6. Interrupciones
Interrumpe
6
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
Registro 6-7:
IFS2: Registro de estado de indicador de interrupción 2 (continuación)

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-28
preliminar
© 2008 Microchip Technology Inc.
Registro 6-8:
IFS3: Registro de estado de indicador de interrupción 3
R/W-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
FLTAIF
—
DMA5IF
DCIIF
DCIEIF
QEIIF
PWMIF
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
poco 15
FLTAIF: Fallo de PWM A Bit de estado del indicador de interrupción
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 14
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
poco 10
QEIIF: Bit de estado del indicador de interrupción de evento QEI
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
poco 9
PWMIF: Bit de estado del indicador de interrupción de error de PWM
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido
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

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-29
Sección 6. Interrupciones
Interrumpe
6
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
Registro 6-8:
IFS3: Registro de estado de indicador de interrupción 3 (continuación)

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-30
preliminar
© 2008 Microchip Technology Inc.
    
Registro 6-9:
IFS4: Registro de estado de indicador de interrupción 4
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
R/W-0
C2TXIF
C1TXIF
DMA7IF
DMA6IF
—
U2EIF
U1EIF
FLTBIF
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
FLTBIF: Bit de estado del indicador de interrupción de fallo B de PWM
1 = Se ha producido una solicitud de interrupción
0 = La solicitud de interrupción no se ha producido

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-31
Sección 6. Interrupciones
Interrumpe
6
    
Registro 6-10:
IEC0: Registro de control de habilitación de interrupción 0
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-32
preliminar
© 2008 Microchip Technology Inc.
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
Registro 6-10:
IEC0: Registro de control de habilitación de interrupción 0 (continuación)

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-33
Sección 6. Interrupciones
Interrumpe
6
 
Registro 6-11:
IEC1: Registro de control de habilitación de interrupción 1
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-C
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-34
preliminar
© 2008 Microchip Technology Inc.
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
Registro 6-11:
IEC1: Registro de control de habilitación de interrupción 1 (continuación)

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-35
Sección 6. Interrupciones
Interrumpe
6
 
Registro 6-12:
IEC2: Registro de control de habilitación de interrupción 2
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-36
preliminar
© 2008 Microchip Technology Inc.
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
Registro 6-12:
IEC2: Registro de control de habilitación de interrupción 2 (continuación)

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-37
Sección 6. Interrupciones
Interrumpe
6
 
Registro 6-13:
IEC3: Registro de control de habilitación de interrupción 3
R/W-0
U-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
FLTAIE
—
DMA5IE
DCIIE
DCIEIE
QEIIE
PWMIE
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
poco 15
FLTAIE: Fallo de PWM Un bit de habilitación de interrupción
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 14
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
poco 10
QEIIE: Bit de habilitación de interrupción de evento QEI
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
poco 9
PWMIE: Bit de habilitación de interrupción de error de PWM
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-38
preliminar
© 2008 Microchip Technology Inc.
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
Registro 6-13:
IEC3: Registro de control de habilitación de interrupción 3 (continuación)

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-39
Sección 6. Interrupciones
Interrumpe
6
 
Registro 6-14:
IEC4: Registro de control de habilitación de interrupción 4
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
R/W-0
C2TXIE
C1TXIE
DMA7IE
DMA6IE
—
U2EIE
U1EIE
FLTBIE
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
FLTBIE: Bit de habilitación de interrupción de falla B de PWM
1 = Solicitud de interrupción habilitada
0 = Solicitud de interrupción no habilitada

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-40
preliminar
© 2008 Microchip Technology Inc.
 
Registro 6-15:
IPC0: Registro de control de prioridad de interrupción 0
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

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-41
Sección 6. Interrupciones
Interrumpe
6
    
Registro 6-16:
IPC1: Registro de control de prioridad de interrupción 1
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-42
preliminar
© 2008 Microchip Technology Inc.
    
Registro 6-17:
IPC2: Registro de control de prioridad de interrupción 2
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

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-43
Sección 6. Interrupciones
Interrumpe
6
Registro 6-18:
IPC3: Registro de control de prioridad de interrupción 3
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-44
preliminar
© 2008 Microchip Technology Inc.
Registro 6-19:
IPC4: Registro de control de prioridad de interrupción 4
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

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-45
Sección 6. Interrupciones
Interrumpe
6
Regístrate 6-20:
IPC5: Registro de control de prioridad de interrupción 5
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-46
preliminar
© 2008 Microchip Technology Inc.
Registro 6-21:
IPC6: Registro de control de prioridad de interrupción 6
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

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-47
Sección 6. Interrupciones
Interrumpe
6
Registro 6-22:
IPC7: Registro de control de prioridad de interrupción 7
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-48
preliminar
© 2008 Microchip Technology Inc.
Registro 6-23:
IPC8: Registro de control de prioridad de interrupción 8
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

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-49
Sección 6. Interrupciones
Interrumpe
6
Regístrate del 6 al 24:
IPC9: Registro de control de prioridad de interrupción 9
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-50
preliminar
© 2008 Microchip Technology Inc.
Regístrese del 6 al 25:
IPC10: Registro de control de prioridad de interrupción 10
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

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-51
Sección 6. Interrupciones
Interrumpe
6
    
Registro 6-26:
IPC11: Registro de control de prioridad de interrupción 11
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-52
preliminar
© 2008 Microchip Technology Inc.
    
Registro 6-27:
IPC12: Registro de control de prioridad de interrupción 12
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

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-53
Sección 6. Interrupciones
Interrumpe
6
    
Registro 6-28:
IPC13: Registro de control de prioridad de interrupción 13
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-54
preliminar
© 2008 Microchip Technology Inc.
Registro 6-29:
IPC14: Registro de control de prioridad de interrupción 14
U-0
R/W-1
R/W-0
R/W-0
U-0
R/W-1
R/W-0
R/W-0
—
DCIEIP<2:0>
—
QEIIP<2:0>
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
PWMIP<2:0>
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
poco 11
No implementado: leído como "0"
bits 10-8
QEIIP<2:0>: Bits de prioridad de interrupción QEI
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 7
No implementado: leído como "0"
bits 6-4
PWMIP<2:0>: Bits de prioridad de interrupción PWM
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
poco 3
No implementado: leído como "0"
poco 2-0
C2IP<2:0>: Bits de prioridad de interrupción de evento ECAN2
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-55
Sección 6. Interrupciones
Interrumpe
6
Regístrate del 6 al 30:
IPC15: Registro de control de prioridad de interrupción 15
U-0
R/W-1
R/W-0
R/W-0
U-0
U-0
U-0
U-0
—
FLTAIP<2:0>
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
poco 15
No implementado: leído como "0"
bits 14-12
FLTAIP<2:0>: Fallo PWM A Bits de prioridad de interrupción
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada
bit 11-7
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-56
preliminar
© 2008 Microchip Technology Inc.
Registro 6-31:
IPC16: Registro de control de prioridad de interrupción 16
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
R/W-1
R/W-0
R/W-0
—
U1EIP<2:0>
—
FLTBIP<2:0>
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
poco 3
No implementado: leído como "0"
poco 2-0
FLTBIP<2:0>: Bits de prioridad de interrupción de fallo B de PWM
111 = La interrupción tiene prioridad 7 (interrupción de mayor prioridad)
•
•
•
001 = La interrupción tiene prioridad 1
000 = La fuente de interrupción está deshabilitada

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-57
Sección 6. Interrupciones
Interrumpe
6
Registro 6-32:
IPC17: Registro de control de prioridad de interrupción 17
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-58
preliminar
© 2008 Microchip Technology Inc.
Registro 6-33:
INTTREG: Registro de estado y control de interrupciones
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
1111111 = El vector de interrupción pendiente es el número 135
•
•
•
0000001 = El vector de interrupción pendiente es el número 9
0000000 = El vector de interrupción pendiente es el número 8

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-59
Sección 6. Interrupciones
Interrumpe
6
6.5
 PROCEDIMIENTOS DE CONFIGURACIÓN DE INTERRUPCIONES
6.5.1
Inicialización
Para configurar una fuente de interrupción:
1.
Configure el bit de control NSTDIS (INTCON1<15>), si no planea utilizar interrupciones anidadas.
2.
Seleccione el nivel de prioridad asignado por el usuario para la fuente de interrupción escribiendo los bits de control en
el registro de control IPCx apropiado. El nivel de prioridad depende de la situación específica.
aplicación y tipo de fuente de interrupción. Si no planea utilizar múltiples niveles de prioridad,
Puede programar los bits de control del registro IPCx para todas las fuentes de interrupción habilitadas en el
mismo valor distinto de cero.
3.
Borre el bit de estado del indicador de interrupción asociado con el periférico en el IFSx asociado
Registro de estado.
4.
Habilite la fuente de interrupción configurando el bit de control de habilitación de interrupción asociado con el
fuente en el registro de control IECx apropiado.
6.5.2
Rutina de servicio de interrupción
El método utilizado para declarar un ISR e inicializar la tabla de vectores de interrupción (IVT) con el valor correcto.
La dirección del vector depende del lenguaje de programación (C o Assembler) y del lenguaje.
Conjunto de herramientas de desarrollo utilizado para desarrollar la aplicación. En general, la aplicación de usuario debe
borre el indicador de interrupción en el registro IFSx apropiado para la fuente de interrupción que el ISR
manijas. De lo contrario, la aplicación volverá a ingresar inmediatamente al ISR después de salir de la rutina. si
Si codifica el ISR en lenguaje ensamblador, debe terminarse usando una instrucción RETFIE para
desapila el valor de PC guardado, el valor SRL y el nivel de prioridad de CPU anterior.
6.5.3
Rutina de servicio de trampa
Una Rutina de Servicio de Trampas (TSR) está codificada como una ISR, excepto que el código debe borrar el
indicador de estado de captura apropiado en el registro INTCON1 para evitar el reingreso al TSR.
6.5.4
Interrumpir Desactivar
Para desactivar las interrupciones:
1.
Inserte el valor SR actual en la pila de software usando la instrucción PUSH.
2.
Fuerce la CPU al nivel de prioridad 7 aplicando una operación OR inclusiva al valor 0xE0 con SRL.
Para habilitar las interrupciones del usuario, puede utilizar la instrucción POP para restaurar el valor SR anterior.
La instrucción DISI desactiva las interrupciones de los niveles de prioridad 1-6 durante un período de tiempo fijo. Nivel 7
Las fuentes de interrupción no están desactivadas por la instrucción DISI.
Nota:
En un reinicio del dispositivo, los registros IPC se inicializan con todas las fuentes de interrupción del usuario.
asignado al nivel de prioridad 4.
Nota:
Sólo se pueden desactivar las interrupciones de usuario con un nivel de prioridad de 7 o menos. Fuentes de trampa
(nivel 8-nivel 15) no se puede desactivar.

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-60
preliminar
© 2008 Microchip Technology Inc.
6.5.5
Ejemplo de código
El ejemplo 6-1 ilustra el código que habilita interrupciones anidadas, configura Timer1, Timer2, Timer3,
Timer4 y cambie los periféricos de aviso a los niveles de prioridad 2, 5, 6, 3 y 4, respectivamente. También
ilustra cómo se pueden habilitar y deshabilitar las interrupciones usando el registro de estado. ISR de muestra 
ilustra la eliminación de interrupciones.
Ejemplo 6-1:
Ejemplo de código de configuración de interrupción
void enable_interrupts(void)
{
/* Establezca CPU IPL en 0, habilite las interrupciones de nivel 1-7 */
/* Aquí no se realiza ninguna restauración del estado anterior de IPL de la CPU */
SRbits.IPL = 0;
return;
}
void disable_interrupts(void)
{
/* Establezca la IPL de la CPU en 7, deshabilite las interrupciones de nivel 1-7 */
/* Aquí no se guarda la configuración actual de IPL de la CPU */
SRbits.IPL = 7;
return;
}
Interrupciones de inicio nulas (anulas)
{
/* Interrumpir el anidamiento habilitado aquí */
INTCON1bits.NSTDIS = 0;
/* Establece la prioridad de interrupción del Timer3 en 6 (el nivel 7 es el más alto) */
IPC2bits.T3IP = 6;
 
/* Establece la prioridad de interrupción del Timer2 en 5 */
IPC1bits.T2IP = 5;
/* Establece la prioridad de interrupción de aviso de cambio en 4 */
IPC4bits.CNIP = 4;
/* Establece la prioridad de interrupción del Timer4 en 3 */
IPC6bits.T4IP = 3; 
/* Establece la prioridad de interrupción del Temporizador1 en 2 */
IPC0bits.T1IP = 2; 
/* Restablecer el indicador de interrupción del temporizador 1 */
IFS0bits.T1IF = 0;
/* Restablecer el indicador de interrupción del Timer2 */
IFS0bits.T2IF = 0;
/* Restablecer el indicador de interrupción del Timer3 */
IFS0bits.T3IF = 0;
/* Restablecer el indicador de interrupción del Timer4 */
IFS1bits.T4IF = 0;
/* Habilitar interrupciones CN */
IEC1bits.CNIE = 1;

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-61
Sección 6. Interrupciones
Interrumpe
6
Ejemplo 6-1:
Ejemplo de código de configuración de interrupción (continuación)
/* Habilitar interrupción del Temporizador1 */
IEC0bits.T1IE = 1;
/* Habilitar la interrupción del Timer2 (base de tiempo PWM) */
IEC0bits.T2IE = 1;
/* Habilitar interrupción del Timer3 */
IEC0bits.T3IE = 1;
/* Habilitar la interrupción del Timer4 (reemplazo del Timer 2 */
IEC1bits.T4IE = 1;
/* Restablecer el indicador de interrupción de aviso de cambio */
IFS1bits.CNIF = 0;
regresar;
}
void __attribute__((__interrupt__)) _T1Interrupt(void)
{
/* Inserte el código ISR aquí*/
/* Borrar interrupción del Temporizador1 */
IFS0bits.T1IF = 0;
}
void __attribute__((__interrupt__)) _T2Interrupt(void)
{
/* Inserte el código ISR aquí*/
/* Borrar interrupción del Timer2 */
IFS0bits.T2IF = 0;
}
void __attribute__((__interrupt__)) _T3Interrupt(void)
{
/* Inserte el código ISR aquí*/
/* Borrar interrupción del Timer3 */
IFS0bits.T3IF = 0;
}
void __attribute__((__interrupt__)) _T4Interrupt(void)
{
/* Inserte el código ISR aquí*/
/* Borrar interrupción del Timer4 */
IFS1bits.T4IF = 0;
}
void __attribute__((__interrupt__)) _CNInterrupt(void)
{
/* Inserte el código ISR aquí*/
/* Borrar interrupción CN */
IFS1bits.CNIF = 0;
}

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-62
preliminar
© 2008 Microchip Technology Inc.
Tabla 6-2:
Mapa de registro del controlador de interrupciones
Archivo 
Nombre
ADR
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
OVBERR
COVAERR
COVBERR
OVADO
OVBTE
COVTE
SFTACERR
DIV0ERR
DMACERR
MATHERR
DIRECCIÓN
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
FLTAIF
—
DMA5IF
DCIIF
DCIEIF
QEIIF
PWMIF
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
FLTBIF
0000
IFS5
008E
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
IFS6
0090
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
IFS7
0092
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
FLTAIE
—
DMA5IE
DCIIE
DCIEIE
QEIIE
PWMIE
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
FLTBIE
0000
IEC5
009E
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
IEC6
00A0
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
IEC7
00A2
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
4444
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
4444
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
4444
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
Leyenda:
— = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-63
Sección 6. Interrupciones
Interrumpe
6
CIP14
00C0
—
DCIEIP<2:0>
—
QEIIP<2:0>
—
PWMIP<2:0>
—
C2IP<2:0>
4444
CIP15
00C2
—
FLTAIP<2:0>
—
—
—
—
—
DMA5IP<2:0>
—
DCIIP<2:0>
4444
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
FLTBIP<2:0>
4444
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
CIP18
00C8
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
4444
CIP19
00CA
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
4444
IPC20
00CC
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
4444
IPC21
00 CE
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
4444
IPC22
00D0
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
4444
IPC23
00D2
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
4444
IPC24
00D4
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
4444
IPC25
00D6
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
4444
IPC26
00D8
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
4444
IPC27
00DA
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
4444
CIP28
00DC
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
4444
IPC29
00DE
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
4444
Tabla 6-2:
Mapa de registro del controlador de interrupciones (continuación)
Archivo 
Nombre
ADR
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

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-64
preliminar
© 2008 Microchip Technology Inc.
6.6
 CONSEJOS DE DISEÑO
Pregunta 1:
¿Qué sucede cuando dos fuentes de interrupción quedan pendientes al mismo tiempo?
tiempo y tener el mismo nivel de prioridad asignado por el usuario? 
Respuesta:
Tendrá prioridad la fuente de interrupción con la mayor prioridad de orden natural.
La prioridad del orden natural está determinada por la tabla de vectores de interrupción (IVT)
dirección de esa fuente. Las fuentes de interrupción con una dirección IVT más baja tienen una mayor
Prioridad del orden natural.
Pregunta 2:
¿Se puede utilizar la instrucción DISI para desactivar todas las fuentes de interrupción y
trampas?
Respuesta:
La instrucción DISI no desactiva trampas ni fuentes de interrupción de nivel de prioridad 7.
Sin embargo, la instrucción DISI se puede utilizar como una forma conveniente de desactivar todos
fuentes de interrupción, si no hay fuentes de interrupción de nivel de prioridad 7 habilitadas en la cuenta del usuario.
aplicación.
Pregunta 3:
¿Qué sucede cuando se utiliza una interrupción periférica como solicitud de DMA?
Respuesta:
La aplicación de usuario puede designar cualquier interrupción periférica como una solicitud DMA.
Una solicitud de DMA es una IRQ que se dirige a la DMA. Cuando el canal DMA está
configurado para responder a una interrupción particular como una solicitud DMA, la aplicación
debería deshabilitar la interrupción de CPU correspondiente. De lo contrario, una interrupción de la CPU
También se solicitaría.

© 2008 Microchip Technology Inc.
preliminar
DS70184B-página 6-65
Sección 6. Interrupciones
Interrumpe
6
6.7
 NOTAS DE APLICACIÓN RELACIONADAS
Esta sección enumera las notas de aplicación relacionadas con esta sección del manual. Estos
Es posible que las notas de aplicación no estén escritas específicamente para la familia de productos dsPIC33F, pero el
Los conceptos son pertinentes y podrían usarse con modificaciones y posibles limitaciones. la corriente
Las notas de aplicación relacionadas con el módulo Interrupciones son:
Título
Nota de aplicación #
No hay notas de aplicación relacionadas en este momento.
Nota:
Visite el sitio web de Microchip (www.microchip.com) para obtener información adicional sobre aplicaciones.
Notas y ejemplos de código para la familia de dispositivos dsPIC33F.

Manual de referencia de la familia dsPIC33F
DS70184B-página 6-66
preliminar
© 2008 Microchip Technology Inc.
6.8
 HISTORIAL DE REVISIONES
Revisión A 
Esta es la publicación inicial de este documento. (Enero de 2007).
Revisión B (julio de 2008)
Esta revisión incorpora las siguientes actualizaciones:
• Ejemplos:
- El término “Detección de bajo voltaje programable (PLVD)” en el ejemplo, en 
6.1.5 "Prioridad de interrupción" se ha corregido como "Interrupción de recepción UART1".
• Registros:
- Las descripciones de bits para el bit 4, bit 6, bit 11 y bit 12 en (INTCON1): Control de interrupción 
El registro 1 ha sido corregido (ver Registro 6-3).
- Las descripciones de bits para el bit 5, bit 6, bit 7 y bit 8 en IEC1: Control de habilitación de interrupción. 
El registro 1 ha sido corregido (ver Registro 6-11).
- Las descripciones de bits para el bit 0, bit 2, bit 3, bit 4 y bit 14 en IEC2: Interrupt Enable 
Se ha corregido el registro de control 2 (consulte el registro 6-12).
- Las descripciones de bits para todos los bits en IEC3: Registro de control de habilitación de interrupción 3 
han sido corregidos (ver Registro 6-13).
- Las descripciones de bits para todos los bits en IEC4: Registro de control de habilitación de interrupción 4 
han sido corregidos (ver Registro 6-14).
- Se agregó un nuevo registro “INTTREG: Registro de estado y control de interrupciones” (ver 
Registro 6-33).
• Notas:
- Se agregó una nota después del primer párrafo en 6.1.5 “Prioridad de interrupción”, que proporciona 
información sobre cómo cambiar los niveles de prioridad de interrupción “sobre la marcha”.
• Mesas:
- Se actualizó la dirección IVT y la dirección AIVT para los números IRQ 83-124, en la Tabla 6-1.
• Se incorporan correcciones menores adicionales, como actualizaciones de idioma y formato. 
a lo largo del documento.
