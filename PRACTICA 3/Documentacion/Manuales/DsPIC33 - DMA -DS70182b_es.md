# Traducción de DsPIC33 - DMA -DS70182b.pdf

© 2008 Microchip Technology Inc.
DS70182B-página 22-1
DMA
22
Sección 22. Acceso directo a memoria (DMA)
DESTACADOS
Esta sección del manual contiene los siguientes temas:
22.1
Introducción ................................................................................................................22-2
22.2
Registros DMA................................................................................................................22-3
22.3
Diagrama de bloques DMA................................................................................................ 22-12
22.4
Transferencia de datos DMA ................................................................................................ 22-13
22,5
Configuración de DMA................................................................................................................. 22-15
22.6
Modos de funcionamiento DMA ................................................................................................ 22-21
22.7
Iniciar la transferencia DMA................................................................................................22-46
22.8
Arbitraje y sobrecostos del canal DMA .................................................................22-48
22.9
Soporte de depuración................................................................................................ 22-49
22.10 Colisiones de escritura de datos................................................................................................ 22-50
22.11 Funcionamiento en modos de ahorro de energía ................................................................ 22-51
22.12 Consejos de diseño ................................................................................................ 22-52
22.13 Registrar mapas................................................................................................................ 22-54
22.14 Notas de aplicación relacionadas................................................................................22-57
22.15 Historial de revisiones................................................................................................ 22-58

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-2
© 2008 Microchip Technology Inc.
22.1
 INTRODUCCIÓN
El controlador de acceso directo a memoria (DMA) es un subsistema importante en el sistema de Microchip.
familias de controladores de señal digital (DSC) de 16 bits de alto rendimiento. Este subsistema facilita la
transferencia de datos entre la CPU y su periférico sin asistencia de la CPU. El dsPIC33F
El controlador DMA está optimizado para aplicaciones integradas de alto rendimiento y en tiempo real donde
el determinismo y la latencia del sistema son prioridades.
El controlador DMA transfiere datos entre registros de datos periféricos y el espacio de datos SRAM. el
El subsistema DMA dsPIC33F utiliza memoria SRAM de doble puerto (DPSRAM) y estructuras de registro
que permiten que el DMA opere a través de sus propios buses de datos y direcciones independientes sin
impacto en el funcionamiento de la CPU. Esta arquitectura elimina la necesidad de robar ciclos, lo que detiene
la CPU cuando se solicita una transferencia DMA de mayor prioridad. Tanto la CPU como el controlador DMA pueden
escribir y leer hacia/desde direcciones dentro del espacio de datos sin interferencias, como paradas de CPU,
lo que da como resultado un rendimiento maximizado en tiempo real. Alternativamente, operación DMA y transferencia de datos.
hacia/desde la memoria y los periféricos no se ven afectados por el procesamiento de la CPU. Por ejemplo, cuando un
Se realiza la operación de autoprogramación en tiempo de ejecución (RTSP), la CPU no ejecuta ningún
instrucciones hasta que finalice RTSP. Esta condición, sin embargo, no afecta la transferencia de datos hacia/desde
La memoria y los periféricos.
Figura 22-1:
Controlador DMA 
El controlador DMA admite ocho canales independientes. Cada canal se puede configurar para
transferencias hacia o desde periféricos seleccionados. Los periféricos admitidos por el controlador DMA incluyen:
• Tecnología ECAN™
• Interfaz de convertidor de datos (DCI)
• Convertidor analógico a digital (ADC) de 10/12 bits
• Interfaz periférica serie (SPI)
• UART
• Captura de entrada
• Comparación de salida
Además, las transferencias DMA pueden ser activadas por temporizadores así como por interrupciones externas. Cada DMA
El canal es unidireccional. Se deben asignar dos canales DMA para leer y escribir en un periférico.
En caso de que más de un canal reciba una solicitud de transferencia de datos, se aplicará un sencillo esquema de prioridad fija,
basado en el número de canal, dicta qué canal completa la transferencia y qué canal, o
canales, quedan pendientes. Cada canal DMA mueve un bloque de hasta 1024 elementos de datos, después
que genera una interrupción a la CPU para indicar que el bloque está disponible para su procesamiento.
DMA
CPU
DPSRAM
PERIFÉRICO

© 2008 Microchip Technology Inc.
DS70182B-página 22-3
Sección 22. Acceso directo a memoria (DMA)
DMA
22
El controlador DMA proporciona estas capacidades funcionales:
• Ocho canales DMA
• Registro indirecto con modo de direccionamiento post-incremento
• Registrar modo indirecto sin direccionamiento post-incremento
• Modo de direccionamiento indirecto de periféricos (el periférico genera la dirección de destino)
• Interrupción de la CPU después de completar la transferencia de medio bloque o bloque completo
• Transferencias de bytes o palabras
• Arbitraje de canal de prioridad fija
• Inicio de transferencia manual (software) o automática (solicitudes DMA periféricas)
• Modos de transferencia en bloque One-Shot o Auto-Repeat
• Modo Ping-Pong (cambio automático entre dos direcciones de inicio DPSRAM después de cada bloque 
transferencia completa)
• La solicitud DMA para cada canal se puede seleccionar desde cualquier fuente de interrupción admitida
• Funciones de soporte de depuración
22.2
 REGISTROS DMA
Cada canal DMA tiene un conjunto de seis registros de estado y control.
• DMaxCON: Canal DMA x Registro de control 
Este registro configura el canal DMA correspondiente habilitando/deshabilitando el canal,
especificando el tamaño de la transferencia de datos, la dirección y el método de interrupción del bloque, y seleccionando el canal DMA
Modo de direccionamiento, modo de operación y modo de escritura de datos nulos.
• DMAxREQ: Canal DMA x IRQ Seleccionar Registrar
Este registro asocia el canal DMA con un periférico compatible con DMA específico asignando
la IRQ periférica al canal DMA.
• DMaxSTA: Canal DMA x Registro de compensación de dirección de inicio DPSRAM A
Este registro especifica el desplazamiento de la dirección de inicio primaria desde la dirección base DMA DPSRAM.
del bloque de datos a transferir por el canal DMA x hacia o desde la DPSRAM. lecturas de esto
El registro devuelve el valor del último desplazamiento de dirección de transferencia DPSRAM. Escribe en este registro.
mientras el canal x está habilitado (es decir, activo) puede resultar en un comportamiento impredecible y debe ser
evitado.
• DMaxSTB: Canal DMA x Registro de compensación de dirección de inicio DPSRAM B
Este registro especifica el desplazamiento de la dirección de inicio secundaria desde la base DMA DPSRAM.
dirección del bloque de datos que se transferirá por el canal DMA x hacia o desde la DPSRAM. Lee
de este registro devuelve el valor del último desplazamiento de dirección de transferencia DPSRAM. escribe a esto
registrarse mientras el canal x está habilitado (es decir, activo) puede resultar en un comportamiento impredecible y
debe evitarse.
• DMaxPAD: Canal DMA x Registro de dirección periférica
Este registro de lectura/escritura contiene la dirección estática del registro de datos periférico. escribe a esto
registrarse mientras el canal DMA correspondiente está habilitado (es decir, activo) puede resultar en
comportamiento adecuado y debe evitarse.
• DMAxCNT: Canal DMA x Registro de recuento de transferencias
Este registro contiene el recuento de transferencias. DMAxCNT + 1 representa el número de DMA
solicita que el canal debe prestar servicio antes de que la transferencia del bloque de datos se considere completa. eso
es decir, un valor DMAxCNT de '0' transferirá un elemento. El valor del registro DMAxCNT es
independiente del tamaño de los datos de transferencia (bit TAMAÑO en el registro DMaxCON). Escribe a este registro.
ter mientras el canal DMA correspondiente está habilitado (es decir, activo) puede resultar en
comportamiento y debe evitarse.

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-4
© 2008 Microchip Technology Inc.
Además de los registros de canales DMA individuales, el controlador DMA tiene tres estados DMA
registros.
• DSADR: Registro de direcciones DMA DPSRAM más reciente
Este registro de estado de sólo lectura de 16 bits es común a todos los canales DMA. Capta la dirección
del acceso DPSRAM más reciente (lectura o escritura). Se borra al reiniciar y, por lo tanto,
contiene el valor '0x0000' si se lee antes de cualquier actividad DMA. Este registro es accesible en cualquier
tiempo, pero está pensado principalmente como ayuda para la depuración. 
• DMACS0: Registro de estado del controlador DMA 0
Este registro de estado de sólo lectura de 16 bits contiene la DPSRAM y la colisión de escritura periférica.
banderas, XWCOLx y PWCOLx, respectivamente. Consulte 22.10 “Colisiones de escritura de datos” para obtener más información.
información detallada. 
• DMACS1: Registro de estado del controlador DMA 1
Este registro de estado de solo lectura de 16 bits indica qué canal DMA estuvo activo más recientemente
y proporciona el estado del modo Ping-Pong de cada canal DMA indicando qué DPSRAM
Se selecciona el registro de compensación de dirección de inicio (DMaxSTA o DMaxSTB).

© 2008 Microchip Technology Inc.
DS70182B-página 22-5
Sección 22. Acceso directo a memoria (DMA)
DMA
22
             Registro 22-1:
DMAXCON: Registro de control del canal X DMA
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
1 =
Canal habilitado
0 =
Canal desactivado
poco 14
TAMAÑO: Bit de tamaño de transferencia de datos
1 =
byte
0 =
palabra
poco 13
DIR: Bit de dirección de transferencia (selección de bus de origen/destino)
1 =
Leer desde la dirección DPSRAM, escribir en la dirección del periférico
0 =
Leer desde la dirección periférica, escribir en la dirección DPSRAM
poco 12
MITAD: Bit de selección de interrupción de transferencia en bloque
1 =
Iniciar interrupción cuando se haya movido la mitad de los datos.
0 =
Iniciar interrupción cuando todos los datos se hayan movido
poco 11
NULLW: bit de selección de modo de escritura periférica de datos nulos
1 =
Escritura de datos nulos en el periférico además de la escritura DPSRAM (el bit DIR también debe estar limpio)
0 =
funcionamiento normal
bit 10-6
No implementado: leído como "0"
bit 5-4
AMODE<1:0>: Bits de selección del modo de direccionamiento del canal DMA
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

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-6
© 2008 Microchip Technology Inc.
 Registro 22-2:
DMAXREQ: DMA Canal X IRQ Seleccionar Registrar
R/S-0
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
IRQSEL<6:0>
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
1 =
Forzar una única transferencia DMA (modo manual)
0 =
Iniciación automática de transferencia DMA mediante solicitud DMA
bit 14-7
No implementado: leído como "0"
poco 6-0
IRQSEL<6:0>: Bits de selección de número IRQ periférico DMA
0000000 =
INT0 – Interrupción externa 0
0000001 =
IC1 – Captura de entrada 1
0000010 =
OC1 – Comparación de salida 1
0000101 =
IC2 – Captura de entrada 2
0000110 =
OC2 – Comparación de salida 2
0000111 =
TMR2 – Temporizador2
0001000 =
TMR3 – Temporizador3
0001010 =
SPI1 – Transferencia realizada
0001011 =
UART1RX – Receptor UART1
0001100 =
UART1TX – Transmisor UART1
0001101 =
ADC1 – Conversión ADC1 realizada
0010101 =
ADC2 – Conversión ADC2 realizada
0011110 =
UART2RX – Receptor UART2
0011111 =
UART2TX – Transmisor UART2
0100001 =
Transferencia SPI2 realizada
0100010 =
ECAN1 – Datos RX listos
0110111 =
ECAN2 – Datos RX listos
0111100 =
DCI – Transferencia de CODEC realizada
1000110 =
ECAN1 – Solicitud de datos TX
1000111 =
ECAN2 – Solicitud de datos TX
Nota 1: El usuario no puede borrar el bit FORCE. El hardware borra el bit FORCE cuando se activa el bit FORCE.
La transferencia DMA está completa.

© 2008 Microchip Technology Inc.
DS70182B-página 22-7
Sección 22. Acceso directo a memoria (DMA)
DMA
22
 
 
 
Registro 22-3:
DMAXSTA: DMA Canal X DPSRAM Dirección de inicio Registro de compensación A
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
STA<15:0>: Bits de desplazamiento de dirección de inicio de DPSRAM primaria (origen o destino) 
Registro 22-4:
DMAXSTB: DMA Canal X DPSRAM Dirección de inicio Registro de compensación B
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
STB<15:0>: Bits de desplazamiento de dirección de inicio de DPSRAM secundaria (origen o destino) 
Regístrate 22-5:
DMAXPAD: Registro de direcciones periféricas del canal X de DMA
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

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-8
© 2008 Microchip Technology Inc.
 
 
Registro 22-6:
DMAXCNT: Registro de recuento de transferencias del canal X de DMA
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
R/W-0
—
—
—
—
—
—
CNT<9:8>
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
CNT<7:0>
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
Reservado
poco 9-0
CNT<9:0>: bits de registro de recuento de transferencia DMA
Regístrese 22-7:
DSADR: Registro de direcciones DMA DPSRAM más reciente
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
DSADR<15:0>: Dirección DMA DPSRAM más reciente a la que acceden los bits DMA

© 2008 Microchip Technology Inc.
DS70182B-página 22-9
Sección 22. Acceso directo a memoria (DMA)
DMA
22
             Registro 22-8:
DMACS0: Registro de estado del controlador DMA 0
R-0
R-0
R-0
R-0
R-0
R-0
R-0
R-0
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
R-0
R-0
R-0
R-0
R-0
R-0
R-0
R-0
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
XWCOL7: Bit de indicador de colisión de escritura DPSRAM del canal 7
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 6
XWCOL6: Bit de indicador de colisión de escritura DPSRAM del canal 6
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 5
XWCOL5: Bit de indicador de colisión de escritura DPSRAM del canal 5
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 4
XWCOL4: Bit de indicador de colisión de escritura DPSRAM del canal 4
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 3
XWCOL3: Bit de indicador de colisión de escritura DPSRAM del canal 3
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-10
© 2008 Microchip Technology Inc.
poco 2
XWCOL2: Bit de indicador de colisión de escritura DPSRAM del canal 2
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 1
XWCOL1: Bit de indicador de colisión de escritura DPSRAM del canal 1
1 = Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
poco 0
XWCOL0: Bit de indicador de colisión de escritura DPSRAM del canal 0
1 =
Colisión de escritura detectada
0 = No se detectó ninguna colisión de escritura
Registro 22-8:
DMACS0: Registro de estado del controlador DMA 0 (continuación)

© 2008 Microchip Technology Inc.
DS70182B-página 22-11
Sección 22. Acceso directo a memoria (DMA)
DMA
22
 Regístrate 22-9:
DMACS1: Registro de estado del controlador DMA 1
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
LSTCH<3:0>: Últimos bits activos del canal DMAC
1111 = No se ha producido ninguna transferencia DMA desde el reinicio del sistema
1110-1000 = Reservado
0111 = La última transferencia de datos fue por el Canal 7
0110 = La última transferencia de datos fue por el Canal 6
0101 = La última transferencia de datos fue por el Canal 5
0100 = La última transferencia de datos fue por el Canal 4
0011 = La última transferencia de datos fue por el Canal 3
0010 = La última transferencia de datos fue por el Canal 2
0001 = La última transferencia de datos fue por el Canal 1
0000 = La última transferencia de datos fue por el Canal 0
Establezca en '1111' al restablecer. Se puede acceder a este campo en cualquier momento, pero su objetivo principal es servir de ayuda para la depuración.
poco 7
PPST7: Indicador de estado del modo "Ping-Pong" del canal 7
1 = registro DMA7STB seleccionado
0 = registro DMA7STA seleccionado
poco 6
PPST6: Indicador de estado del modo "Ping-Pong" del canal 6
1 = registro DMA6STB seleccionado
0 = registro DMA6STA seleccionado
poco 5
PPST5: Indicador de estado del modo "Ping-Pong" del canal 5
1 = registro DMA5STB seleccionado
0 = registro DMA5STA seleccionado
poco 4
PPST4: Indicador de estado del modo "Ping-Pong" del canal 4
1 = registro DMA4STB seleccionado
0 = registro DMA4STA seleccionado
poco 3
PPST3: Indicador de estado del modo "Ping-Pong" del canal 3
1 = registro DMA3STB seleccionado
0 = registro DMA3STA seleccionado
poco 2
PPST2: Indicador de estado del modo "Ping-Pong" del canal 2
1 = registro DMA2STB seleccionado
0 = registro DMA2STA seleccionado
poco 1
PPST1: Indicador de estado del modo "Ping-Pong" del canal 1
1 = registro DMA1STB seleccionado
0 = registro DMA1STA seleccionado
poco 0
PPST0: Indicador de estado del modo 'Ping-Pong' del canal 0
1 = registro DMA0STB seleccionado
0 = registro DMA0STA seleccionado
Nota:
Este registro es de sólo lectura.

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-12
© 2008 Microchip Technology Inc.
22.3
 DIAGRAMA DE BLOQUES DMA
La Figura 22-2 es un diagrama de bloques que muestra cómo se integra el DMA en el sistema interno dsPIC33F.
arquitectura. La CPU se comunica con la SRAM convencional a través del bus X. También
se comunica con el puerto 1 del bloque SRAM de puerto dual (DPSRAM) a través del mismo bus X. el
La CPU se comunica con los periféricos a través de un bus periférico X independiente, que también reside
dentro del espacio de datos X.
Los canales DMA se comunican con el Puerto 2 de la DPSRAM y el puerto DMA de cada uno de los
Periféricos preparados para DMA a través de un bus DMA dedicado. 
Figura 22-2:
Diagrama de bloques del controlador DMA
A diferencia de otras arquitecturas, la CPU dsPIC33F es capaz de acceder a lectura y escritura dentro de
cada ciclo del bus de la CPU. De manera similar, el DMA puede completar la transferencia de un byte o palabra en cada bus.
recorrer en bicicleta su autobús exclusivo. Esto también garantiza que todas las transferencias DMA no se interrumpan. eso
es decir, una vez iniciada la transferencia, se completará dentro del mismo ciclo, independientemente de otros cambios.
actividad del personal.
La aplicación de usuario puede designar cualquier interrupción periférica lista para DMA para que sea una solicitud de DMA, la
Término dado a una IRQ cuando se dirige al DMA. Por supuesto, se supone que cuando un DMA
El canal está configurado para responder a una interrupción particular como una solicitud DMA, el correspondiente
La interrupción de la CPU está deshabilitada; de lo contrario, también se solicitará una interrupción de la CPU.
Cada canal DMA también se puede activar manualmente mediante software. Configurar el bit FORCE en
el registro DMaxCON inicia una solicitud DMA manual que está sujeta al mismo arbitraje que
todas las solicitudes DMA basadas en interrupciones (consulte 22.8 “Arbitraje y excesos del canal DMA”).
CPU
SRAM
DPSRAM
Periférico 1
DMA
periférico
Sin DMA
PUERTO 2
PUERTO 1
Periférico 2
DMA
Listo
Periférico 3
DMA
Listo
Listo
DMA X-Bus
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
CPU periférico X-Bus
IRQ a DMA 
e interrumpir 
Controlador 
Módulos
SRAM X-Bus
IRQ a DMA 
e interrumpir 
Controlador 
Módulos
IRQ a DMA 
e interrumpir 
Controlador 
Módulos
0
1
2
3
4
5
6
7

© 2008 Microchip Technology Inc.
DS70182B-página 22-13
Sección 22. Acceso directo a memoria (DMA)
DMA
22
22.4
 TRANSFERENCIA DE DATOS DMA
La Figura 22-3 ilustra una transferencia de datos entre un periférico y una SRAM de doble puerto. 
A.
En este ejemplo, el canal DMA 5 está configurado para funcionar con el periférico 1 listo para DMA.
b.
Cuando los datos están listos para ser transferidos desde el periférico, el dispositivo emite una solicitud DMA.
periférico. La solicitud de DMA se arbitra con cualquier otra solicitud coincidente. si esto
canal tiene la prioridad más alta, la transferencia se completa durante el siguiente ciclo.
De lo contrario, la solicitud de DMA permanece pendiente hasta que se convierta en la máxima prioridad.
c.
El canal DMA ejecuta una lectura de datos desde la dirección periférica designada, que
es la aplicación de usuario definida dentro del canal activo. 
D.
El canal DMA escribe los datos en la dirección DPSRAM designada. 
Este ejemplo representa el modo de registro indirecto, donde se designa la dirección DPSRAM.
dentro del canal DMA a través de los registros de estado DMA (DMAxSTA o DMAxSTB). En periférico
Modo indirecto, la dirección DPSRAM se deriva del periférico, no del canal activo. Más
La información sobre este tema se presenta en 22.6.6 “Modo de direccionamiento indirecto de periféricos”.
Toda la operación de transferencia de lectura y escritura de DMA se realiza de forma ininterrumpida en un solo
ciclo de instrucción. Durante todo este proceso, la solicitud DMA permanece bloqueada en el canal DMA.
hasta que se complete la transferencia de datos.
El canal DMA monitorea simultáneamente el registro del contador de transferencias (DMA5CNT). cuando el
el recuento de transferencias alcanza un límite especificado por la aplicación del usuario, la transferencia de datos se considera completa
y se activa una interrupción de la CPU para alertar a la CPU para que procese los datos recién recibidos.
Durante el ciclo de transferencia de datos, el controlador DMA también continúa arbitrando pendientes o
solicitudes DMA posteriores para maximizar el rendimiento.

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-14
© 2008 Microchip Technology Inc.
Figura 22-3:
Ejemplo de transferencia de datos DMA
CPU
SRAM
DPSRAM
Periférico 1
DMA
PUERTO 2
PUERTO 1
Listo
Bus espacial de datos DMA
DMA de la CPU
DMA
controlar
Controlador DMA
Bus de espacio de datos periféricos de CPU
SRAM X-Bus
DMA Capítulo 5
CPU
SRAM
DPSRAM
Periférico 1
DMA
PUERTO 2
PUERTO 1
Listo
DMA de la CPU
DMA
controlar
Controlador DMA
SRAM X-Bus
CPU
SRAM
DPSRAM
Periférico 1
DMA
PUERTO 2
PUERTO 1
Listo
DMA de la CPU
DMA
controlar
Controlador DMA
SRAM X-Bus
DMA Capítulo 5
CPU
SRAM
DPSRAM
Periférico 1
DMA
PUERTO 2
PUERTO 1
Listo
DMA de la CPU
DMA
controlar
Controlador DMA
SRAM X-Bus
DMA Capítulo 5
Periférico 1 configurado para DMA Canal 5
b
un
c
re
El periférico tiene datos para transferir al canal 5 de DMA
DMA Canal 5 lee datos del Periférico 1
DMA Canal 5 escribe datos en DPSRAM
DATOS
DATOS
DATOS
Solicitud de DMA
DMA Capítulo 5
Dirección periférica
Lectura de datos
Escritura de datos (bus DMA DS)
Dirección DPSRAM

© 2008 Microchip Technology Inc.
DS70182B-página 22-15
Sección 22. Acceso directo a memoria (DMA)
DMA
22
22,5
 CONFIGURACIÓN DE DMA
Para que la transferencia de datos DMA funcione correctamente, los canales y periféricos DMA deben estar
configurado apropiadamente: 
• Los canales DMA deben estar asociados con periféricos (consulte 22.5.1 “Canal DMA a 
Configuración de asociación de periféricos”)
• Los periféricos deben estar configurados correctamente (consulte 22.5.2 “Configuración de periféricos”)
• Las direcciones de inicio de datos DPSRAM deben inicializarse (consulte 22.5.3 “Dirección de memoria 
Inicialización”)
• Se debe inicializar el recuento de transferencias DMA (consulte 22.5.4 “Configuración del recuento de transferencias DMA”). 
Arriba”)
• Se deben seleccionar los modos de funcionamiento y direccionamiento adecuados (consulte 22.6 “Operación DMA”). 
Modos”)
22.5.1
Configuración de asociación de canal DMA a periférico
El canal DMA necesita saber desde qué dirección de destino periférica leer o escribir, y
cuando hacerlo. Esta información se configura en el registro de direcciones periféricas del canal DMA x
(DMAxPAD) y Registro de selección de canal DMA x IRQ (DMAxREQ), respectivamente.
La Tabla 22-1 muestra qué valores deben escribirse en estos registros para asociar un determinado
periférico con un canal DMA determinado.
Si dos canales DMA seleccionan el mismo periférico como fuente de su solicitud DMA, ambos
Los canales reciben la solicitud DMA simultáneamente. Sin embargo, el canal de mayor prioridad
ejecuta su transferencia primero, dejando pendiente el otro canal. Esta situación es común cuando un
Se utiliza una sola solicitud DMA para mover datos desde y hacia un periférico (por ejemplo, SPI). dos
Se utilizan canales DMA. Uno está asignado para lecturas periféricas y el otro está asignado para
Escritura de datos periféricos. Ambos utilizan la misma solicitud DMA.
Tabla 22-1:
Canal DMA a Asociaciones Periféricas
Periférico a la Asociación DMA
Registro DMaxREQ
IRQSEL<6:0> Bits
Registro DMaxPAD 
Valores para leer 
periférico
Registro DMaxPAD 
Valores para escribir 
periférico
INT0 – Interrupción externa 0
0000000
—
—
IC1 – Captura de entrada 1
0000001
0x0140 (IC1BUF)
—
IC2 – Captura de entrada 2
0000101
0x0144 (IC2BUF)
—
OC1 – Comparación de salida 1 datos
0000010
—
0x0182 (OC1R)
OC1 – Comparación de salida 1 datos secundarios
0000010
—
0x0180 (OC1RS)
OC2 – Comparación de salida 2 datos
0000110
—
0x0188 (OC2R)
OC2 – Comparación de salida 2 datos secundarios
0000110
—
0x0186 (OC2RS)
TMR2 – Temporizador2
0000111
—
—
TMR3 – Temporizador3
0001000
—
—
SPI1 – Transferencia realizada
0001010
0x0248 (SPI1BUF)
0x0248 (SPI1BUF)
SPI2 – Transferencia realizada
0100001
0x0268 (SPI2BUF)
0x0268 (SPI2BUF)
UART1RX – Receptor UART1
0001011
0x0226 (U1RXREG)
—
UART1TX – Transmisor UART1
0001100
—
0x0224 (U1TXREG)
UART2RX – Receptor UART2
0011110
0x0236 (U2RXREG)
—
UART2TX – Transmisor UART2
0011111
—
0x0234 (U2TXREG)
ECAN1 – Datos RX listos
0100010
0x0440 (C1RXD)
—
ECAN1 – Solicitud de datos TX
1000110
—
0x0442 (C1TXD)
ECAN2 – Datos RX listos
0110111
0x0540 (C2RXD)
—
ECAN2 – Solicitud de datos TX
1000111
—
0x0542 (C2TXD)
DCI – Transferencia de CODEC realizada
0111100
0x0290 (RXBUF0)
0x0298 (TXBUF0)
ADC1 – Conversión ADC1 realizada
0001101
0x0300 (ADC1BUF0)
—
ADC2 – Conversión ADC2 realizada
0010101
0x0340 (ADC2BUF0)
—

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-16
© 2008 Microchip Technology Inc.
Si el registro DMaxPAD se inicializa a un valor que no figura en la Tabla 22-1, el canal DMA escribe
a esta dirección periférica se ignorarán. Las lecturas del canal DMA desde esta dirección darán como resultado un
lectura de '0'.
22.5.2
Configuración de configuración de periféricos
El segundo paso en el proceso de configuración de DMA es configurar correctamente los periféricos listos para DMA para
Operación DMA. La Tabla 22-2 describe los requisitos de configuración para periféricos listos para DMA.
Tabla 22-2:
Consideraciones de configuración para periféricos listos para DMA
 Periférico listo para DMA
Consideraciones de configuración
ECAN 
Los buffers ECAN se asignan en la RAM DMA. El tamaño total de la CAN. 
El área de búfer y FIFO en la RAM DMA lo especifica el usuario y debe ser 
definido a través de los bits de tamaño del búfer DMA DMABS<2:0> en el ECAN FIFO 
Registro de control (C1FCTRL). El código de muestra se muestra en el Ejemplo 22-9.
Interfaz de convertidor de datos (DCI)
El DCI debe configurarse para generar una interrupción por cada dato almacenado en el buffer.
palabra configurando los bits de control de longitud del búfer (BLEN<1:0>) en '00' en el DCI
Registro de control 2 (DCICON2). Se debe utilizar la misma interrupción DCI como
Solicitud de dos canales DMA para admitir transferencias de datos RX y TX. si el
El módulo DCI está funcionando como Maestro y solo recibe datos, el segundo
Se debe utilizar el canal DMA para enviar datos de transmisión ficticios. El código de muestra es
se muestra en el ejemplo 22-11.
Analógico a digital de 10 bits/12 bits 
Convertidor (ADC)
Cuando el ADC se utiliza con el DMA en modo periférico indirecto, el 
Tasa de incremento para los bits de direcciones DMA (SMPI<3:0>) en el ADCx 
Registro de control 2 (ADCxCON2) y número de ubicaciones de búfer DMA 
por bits de entrada analógica (DMABL<2:0>) en el ADCx Control 4 (ADCxCON4) 
El registro debe estar configurado correctamente. Además, el bit del modo DMA Buffer Build 
(ADDMABM) en el registro ADCx Control 1 (ADxCON1) debe estar correctamente 
configurado para la generación de direcciones ADC. Consulte 22.6.6.1 “Soporte ADC para DMA 
Generación de direcciones” para obtener información detallada. El código de muestra se muestra en 
Ejemplo 22-5 y Ejemplo 22-7. 
Interfaz periférica serie (SPI) 
Si el módulo SPI está funcionando como maestro y solo recibe datos, el 
Se debe asignar un segundo canal DMA y utilizarlo para enviar transmisiones ficticias. 
datos. Alternativamente, se puede utilizar un único canal DMA en escritura de datos nulos. 
modo. Consulte 22.6.11 “Modo de escritura de datos nulos” para obtener información detallada. 
El código de muestra se muestra en el Ejemplo 22-12.
UART
La UART debe configurarse para generar interrupciones para cada carácter. 
recibido o transmitido. Para que el receptor UART genere una interrupción RX 
por cada carácter recibido, recibir bits de selección del modo de interrupción 
(URXISEL<1:0>) debe configurarse en '00' o '01' en Estado y Control 
registro (UxSTA). 
Para que el transmisor UART genere una interrupción de TX para cada carácter 
transmitido, bits de selección del modo de interrupción de transmisión UTXISEL0 y 
UTXISEL1 debe establecerse en '0' en el registro de Estado y Control (UxSTA). 
El código de muestra se muestra en el Ejemplo 22-10.
Captura de entrada
El módulo de captura de entrada debe configurarse para generar una interrupción para 
cada evento de captura configurando el número de capturas por bits de interrupción 
(ICI<1:0>) a '00' en el registro de Control de captura de entrada (ICxCON). Código de muestra 
se muestra en el ejemplo 22-4.
Comparación de salida
El módulo Output Compare no requiere ninguna configuración especial para funcionar 
DMA. Sin embargo, normalmente el temporizador se utiliza para proporcionar la solicitud DMA, 
y debe configurarse correctamente. El código de muestra se muestra en 
Ejemplo 22-3.

© 2008 Microchip Technology Inc.
DS70182B-página 22-17
Sección 22. Acceso directo a memoria (DMA)
DMA
22
Una condición de error dentro de un periférico habilitado para DMA generalmente establece un indicador de estado y genera
una interrupción (si las interrupciones están habilitadas por la aplicación del usuario). Cuando un periférico recibe servicio de
la CPU, se requiere que el manejador de interrupciones de datos verifique si hay indicadores de error y, si es necesario, tome
acción apropiada. Sin embargo, cuando un periférico recibe servicio del canal DMA, el DMA puede
solo responde a solicitudes de transferencia de datos y no tiene conocimiento de ninguna condición de error posterior. Todos
condiciones de error en periféricos compatibles con DMA, deben tener una interrupción asociada habilitada y
ser atendido por la Rutina de Servicio de Interrupción (ISR) definida por el usuario, si dicha interrupción está presente en
el periférico.
22.5.3
Inicialización de la dirección de memoria
El tercer requisito de configuración de DMA es asignar buffers de memoria dentro de un área de memoria específica para
Acceso DMA. La ubicación y el tamaño de esta área de memoria dependen del dispositivo dsPIC33F (consulte
(consulte la hoja de datos del dispositivo para obtener información específica). La Figura 22-4 muestra un área de memoria DMA de
2 Kbytes para dispositivos dsPIC33F con 30 Kbytes de RAM.
Interrupción externa y temporizadores 
Sólo se pueden seleccionar la interrupción externa 0 y los temporizadores 2 y 3 para DMA 
solicitud. Aunque estos periféricos no admiten la transferencia DMA 
ellos mismos, se pueden utilizar para activar transferencias DMA para otros DMA 
periféricos compatibles. Por ejemplo, Timer2 puede activar transacciones DMA 
para el periférico de comparación de salida en modo PWM. Se muestra el código de muestra. 
en el ejemplo 22-3.
Tabla 22-2:
Consideraciones de configuración para periféricos listos para DMA (continuación)
 Periférico listo para DMA
Consideraciones de configuración

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-18
© 2008 Microchip Technology Inc.
Figura 22-4:
Mapa de memoria de datos para dispositivos de la familia dsPIC33F con 30 Kbytes de RAM 
Para funcionar correctamente, el DMA necesita conocer la dirección DPSRAM para leer o escribir como
un desplazamiento desde el comienzo de la memoria DMA. Esta información se configura en el DMA.
Canal x DPSRAM Dirección de inicio Registro de desplazamiento A (DMAxSTA) y DMA Canal x DPSRAM
Registro de compensación de dirección de inicio B (DMaxSTB).
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

© 2008 Microchip Technology Inc.
DS70182B-página 22-19
Sección 22. Acceso directo a memoria (DMA)
DMA
22
La Figura 22-5 es un ejemplo que muestra cómo los canales 4 DMA primario y secundario almacenan en buffer
están configurados en el dispositivo dsPIC33FJ256GP710 en la dirección 0x7800 y 0x7810, respectivamente.
Figura 22-5:
Asignación de búfer primario y secundario en la memoria DMA
En este ejemplo, debe estar familiarizado con el diseño de la memoria del dispositivo para poder codificar
esta información en la aplicación. Además, debe utilizar la aritmética de punteros para acceder a estos búferes.
después de que se complete la transferencia DMA. Como resultado, esta implementación es difícil de trasladar desde un
procesador a otro.
El compilador MPLAB® C30 simplifica la inicialización y el acceso al búfer DMA al proporcionar C integrado
primitivos del lenguaje para ese propósito. Por ejemplo, el código de la Figura 22-6 asigna dos buffers
en la memoria DMA e inicializa el canal DMA para que apunte a ellos.
Figura 22-6:
Asignación de búfer DMA primario y secundario con MPLAB® IDE
Primaria
búfer
Secundaria
búfer
0x7800
0x7810
RAM DMA
&_DMA_BASE (definido en p33FJ256GP710.gld)
&_DMA_BASE+DMA4STA (0x7800 + 0x0000 = 0x7800)
&_DMA_BASE+DMA4STA (0x7800 + 0x0010 = 0x7810)
Ejemplo de código:
DMA4STA = 0x0000;
DMA4STB = 0x0010;
Búfer B
(secundario)
Tampón A
(Primario)
0x7FE0
0x8000
RAM DMA
0x7Tarifa
0x7FF0
0x7FFE
&_DMA_BASE
Ejemplo de código:
unsigned int BufferA[8] __attribute__((espacio(dma)));
unsigned int BufferB[8] __attribute__((espacio(dma)));
DMA0STA = __builtin_dmaoffset(BufferA);
DMA0STB = __builtin_dmaoffset(BufferB);
Nota:
El enlazador MPLAB LINK30 asigna los buffers primario y secundario en orden inverso
comenzando en la parte inferior del espacio de memoria DMA.

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-20
© 2008 Microchip Technology Inc.
Si el registro DMAxSTA (y/o DMAxSTB) se inicializa a un valor que dará como resultado el DMA
El canal lee o escribe direcciones RAM fuera del espacio RAM DMA, el canal DMA escribe en
esta dirección de memoria se ignoran. Las lecturas del canal DMA desde esta dirección de memoria dan como resultado una lectura
de '0'.
22.5.4
Configuración del recuento de transferencias DMA
En el cuarto paso del proceso de configuración de DMA, cada canal DMA debe programarse para dar servicio
N + 1 número de solicitudes antes de que la transferencia del bloque de datos se considere completa. El valor 'N' es
especificado mediante la programación del registro DMA Channel x Transfer Count (DMAxCNT). Es decir, un
El valor DMAxCNT de '0' transferirá un elemento. 
El valor del registro DMAxCNT es independiente del tamaño de los datos de transferencia (byte o palabra), que
se especifica en el bit TAMAÑO del registro DMaxCON.
Si el registro DMAxCNT se inicializa a un valor que dará como resultado la lectura del canal DMA o
Al escribir direcciones de RAM fuera del espacio de RAM de DMA, el canal DMA escribe en esta dirección de memoria.
son ignorados. Las lecturas del canal DMA desde esta dirección de memoria dan como resultado una lectura de "0".
22.5.5
Configuración del modo de funcionamiento
El quinto y último paso de configuración de DMA es especificar el modo de operación para cada canal DMA mediante
configurar el registro DMA Channel x Control (DMAxCON). Consulte 22.6 “Funcionamiento DMA
Modos” para obtener información de configuración específica.

© 2008 Microchip Technology Inc.
DS70182B-página 22-21
Sección 22. Acceso directo a memoria (DMA)
DMA
22
22.6
 MODOS DE FUNCIONAMIENTO DMA
El canal DMA admite estos modos de operación:
• Transferencia de datos de palabras o bytes
• Dirección de transferencia (periférico a DPSRAM o DPSRAM a periférico)
• Interrupciones de transferencia total o media a la CPU
• Direccionamiento DPSRAM estático o post-incremento
• Direccionamiento indirecto periférico
• Transferencias en bloque continuas o de una sola vez
• Cambio automático entre dos compensaciones de direcciones de inicio (DMAxSTA o DMAxSTB) después de cada 
transferencia completa (modo Ping-Pong)
• Modo de escritura de datos nulos
Además, DMA admite un modo manual, que fuerza una única transferencia DMA. 
22.6.1
Transferencia de datos de palabras o bytes
Cada canal DMA se puede configurar para transferir datos por palabra o byte. Los datos de palabras sólo pueden ser
movido hacia y desde direcciones alineadas (pares). Los datos de bytes, por otro lado, se pueden mover hacia o
desde cualquier dirección (legal).
Si el bit TAMAÑO (DMAxCON<14>) está limpio, se transfieren datos del tamaño de una palabra. Si se registra indirectamente con
El modo de direccionamiento post-incremento está habilitado, la dirección se incrementa posteriormente en 2 después de cada
transferencia de palabras (consulte 22.6.5 “Registro indirecto sin modo de direccionamiento post-incremento”).
Si se establece el bit TAMAÑO, se transfieren datos del tamaño de un byte. Si se registra indirectamente con post-incremento
El modo de direccionamiento está habilitado, la dirección se incrementa en 1 después de cada transferencia de bytes.
22.6.2
Dirección de transferencia
Cada canal DMA se puede configurar para transferir datos desde un periférico a la DPSRAM o desde
la DPSRAM a un periférico.
Si el bit de dirección de transferencia (DIR) en DMaxCON está limpio, los datos se leen desde el periférico (usando
la dirección periférica proporcionada por DMaxPAD) y la escritura de destino se dirige al
Desplazamiento de la dirección de memoria DPSRAM DMA (usando DMAxSTA o DMAxSTB).
Si el bit DIR está configurado, los datos se leen desde el desplazamiento de la dirección de memoria DPSRAM DMA (usando
DMaxSTA o DMaxSTB) y la escritura de destino se dirige al periférico (usando el
dirección periférica, proporcionada por DMaxPAD).
Una vez configurado, cada canal es un conducto de datos unidireccional. Es decir, si un periférico
requieren lectura y escritura de datos usando el módulo DMA, se deben asignar dos canales: uno para
lectura y otra para escritura.
22.6.3
Interrupciones de transferencia de bloque completo o medio bloque
Cada canal DMA proporciona una interrupción al controlador de interrupciones cuando se realiza la transferencia de datos en bloque.
completo o medio completo. Este modo se designa borrando o configurando el bit HALF en el
Registro DMA Canal x Control (DMAxCON): 
HALF = 0 (inicia la interrupción cuando se han movido todos los datos)
HALF = 1 (inicia la interrupción cuando se ha movido la mitad de los datos)
Cuando se utiliza el modo DMA continuo, la CPU debe poder procesar las señales entrantes o salientes.
datos al menos tan rápido como el DMA los mueve. La interrupción de media transferencia ayuda a mitigar esto
problema al generar una interrupción cuando solo se ha transferido la mitad de los datos. Por ejemplo,
Si el controlador DMA lee continuamente un ADC, la interrupción de media transferencia permite que
CPU para procesar el búfer antes de que se llene por completo. Siempre que nunca se adelante al
DMA escribe que este esquema se puede utilizar para relajar los requisitos de tiempo de respuesta de la CPU. Figura 22-7
ilustra este proceso.

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-22
© 2008 Microchip Technology Inc.
Figura 22-7:
Modo de transferencia de medio bloque
En todos los modos, cuando se establece el bit HALF, el DMA emite una interrupción sólo cuando la primera mitad del buffer
Se transfiere A y/o B. No se emite ninguna interrupción cuando el buffer A y/o B se transfieren por completo.
En otras palabras, las interrupciones solo se emiten cuando DMA completa (DMAxCNT + 1)/2 transferencias. si
(DMAxCNT + 1) es igual a un número impar, las interrupciones se emiten después de (DMAxCNT + 2)/2 transferencias.
Por ejemplo, si DMA3 está configurado para One-Shot, buffers de Ping-Pong (MODE<1:0> = 11), y
DMA3CNT = 7, se emiten dos interrupciones DMA3, una después de transferir cuatro elementos del búfer
A, y uno después de transferir cuatro elementos del Buffer B. (Para obtener más información, consulte 22.6.7
“Modo One-Shot” y 22.6.9 “Modo Ping-Pong”.)
Aunque el canal DMA emite una interrupción en transferencias de medio bloque o de bloque completo, el usuario
La aplicación puede "engañar" al canal DMA para que emita una interrupción en transferencias de medio bloque y bloque completo.
alternando el valor del bit HALF durante cada interrupción DMA. Por ejemplo, si el canal DMA
está configurado con el bit HALF establecido en '1', se emite una interrupción después de cada transferencia de medio bloque. si el
La aplicación de usuario restablece el bit HALF a '0' mientras se atiende la interrupción, el DMA emite
otra interrupción cuando se complete la transferencia de bloque completo.
Para habilitar estas interrupciones, el bit de habilitación de interrupción DMA correspondiente (DMAxIE) debe configurarse en
el registro de control de habilitación de interrupciones (IECx) en el módulo del controlador de interrupciones, como se muestra en
Tabla 22-3.
El ejemplo 22-1 muestra cómo se habilita la interrupción del canal 0 de DMA:
Ejemplo 22-1:
Código para habilitar la interrupción del canal 0 de DMA
&_DMA_BASE
Transferencia #1
Transferencia #2
Transferencia #3
Transferencia #n
CONTAR++
CONTAR = DMAxCNT+1
2
&_DMA_BASE + DMAxSTA
IRQ de media transferencia 
a la CPU
CONTAR = 0
Tabla 22-3:
Configuración del controlador de interrupciones para habilitar/deshabilitar interrupciones DMA
DMA 
canal
Registro del controlador de interrupción 
Nombre y número de bit
Bit de registro correspondiente 
Nombre
Código de acceso a la estructura C
0
CEI0<4>
DMA0IE
IEC0bits.DMA0IE 
1
IEC0<14>
DMA1IE
IEC1bits.DMA1IE 
2
IEC1<8>
DMA2IE
IEC1bits.DMA2IE 
3
IEC2<4>
DMA3IE
IEC2bits.DMA3IE 
4
IEC2<14>
DMA4IE
IEC2bits.DMA4IE 
5
IEC3<13>
DMA5IE
IEC3bits.DMA5IE 
6
IEC4<4>
DMA6IE
IEC4bits.DMA6IE 
7
IEC4<5>
DAM7IE
IEC4bits.DMA7IE
IEC0bits.DMA0IE = 1;

© 2008 Microchip Technology Inc.
DS70182B-página 22-23
Sección 22. Acceso directo a memoria (DMA)
DMA
22
Cada interrupción de transferencia de canal DMA establece un indicador de estado correspondiente en el controlador de interrupciones,
lo que desencadena la Rutina de Interrupción del Servicio (ISR). La aplicación de usuario debe entonces aclarar que
indicador de estado para evitar que se vuelva a ejecutar el ISR de transferencia completa. 
La Tabla 22-4 muestra el registro de estado de indicador de interrupción (IFSx) y el nombre de bit correspondiente (DMAxIF).
en el módulo controlador de interrupciones. También muestra el código de acceso a la estructura C que borra la bandera.
Como ejemplo, supongamos que la interrupción del canal 0 DMA está habilitada, la transferencia del canal 0 DMA ha
terminado y la interrupción asociada se ha emitido al controlador de interrupciones. lo siguiente
El código debe estar presente en el canal DMA 0 ISR para borrar el indicador de estado y evitar una pendiente.
interrumpir.
Ejemplo 22-2:
Código para borrar la interrupción del canal 0 de DMA
Tabla 22-4:
Configuración del controlador de interrupción para borrar indicadores de estado de interrupción DMA
DMA 
canal
Registro del controlador de interrupción 
Nombre y número de bit
Bit de registro correspondiente 
Nombre
Código de acceso a la estructura C
0
IFS0<4>
DMA0IF
IFS0bits.DMA0IE 
1
IFS0<14>
DMA1IF
IFS0bits.DMA1IE 
2
IFS1<8>
DMA2IF
IFS1bits.DMA2IE 
3
IFS2<4>
DMA3IF
IFS2bits.DMA3IE 
4
IFS2<14>
DMA4IF
IFS2bits.DMA4IE 
5
IFS3<13>
DMA5IF
IFS3bits.DMA5IE 
6
IFS4<4>
DMA6IF
IFS4bits.DMA6IE 
7
IFS4<5>
DMA7IF
IFS4bits.DMA7IE 
void __attribute__((__interrupt__)) _DMA0Interrupt(void)
{
. . . 
IFS0bits.DMA0IF = 0;
}

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-24
© 2008 Microchip Technology Inc.
22.6.4
Registro indirecto con modo de direccionamiento post-incremento
El registro indirecto con direccionamiento post-incremento se utiliza para mover bloques de datos incrementando
la dirección DPSRAM después de cada transferencia.
El canal DMA pasa por defecto a este modo después de restablecer el controlador DMA. Este modo está seleccionado
programando los bits de selección del modo de direccionamiento (AMODE<1:0>) en '00' en el canal DMA
Registro de control (DMAxCON). En este modo, el desplazamiento de dirección de inicio de DPSRAM (DMAxSTA o
DMaxSTB) proporciona la dirección inicial del búfer DPSRAM. 
La aplicación de usuario determina la última dirección de transferencia DPSRAM compensada leyendo el
Registro de compensación de dirección de inicio de DPSRAM. Sin embargo, el contenido de este registro no se modifica.
por el controlador DMA. 
La Figura 22-8 ilustra la transferencia de datos en este modo. 
Figura 22-8:
Transferencia de datos con registro indirecto con direccionamiento post-incremento
&_DMA_BASE
&_DMA_BASE + DMA3STA + 0
&_DMA_BASE + DMA3STA + 1
&_DMA_BASE + DMA3STA + 2
Datos 1
Datos 2
Datos 3
periférico 
1
DMA
Canal 3
DMA Canal 3, Primera Transferencia
un
&_DMA_BASE
&_DMA_BASE + DMA3STA + 0
&_DMA_BASE + DMA3STA + 1
&_DMA_BASE + DMA3STA + 2
Datos 1
Datos 2
Datos 3
periférico 
1
DMA
Canal 3
&_DMA_BASE
&_DMA_BASE + DMA3STA + 0
&_DMA_BASE + DMA3STA + 1
&_DMA_BASE + DMA3STA + 4
Datos 1
Datos 2
Datos 3
periférico 
1
DMA
Canal 3
DMA Canal 3, Segunda Transferencia
b
DMA Canal 3, Tercera Transferencia
c
Transferencia 1
Transferencia 2
Transferencia 3

© 2008 Microchip Technology Inc.
DS70182B-página 22-25
Sección 22. Acceso directo a memoria (DMA)
DMA
22
Ejemplo 22-3:
Código para comparación de salida y DMA con registro indirecto 
Modo post-incremento
22.6.5
Registro indirecto sin modo de direccionamiento post-incremento
El registro indirecto sin direccionamiento post-incremento se utiliza para mover bloques de datos sin
incrementando la dirección inicial del buffer de datos después de cada transferencia. En este modo, el
El registro DPSRAM Start Address Offset (DMAxSTA o DMAxSTB) proporciona un desplazamiento al inicio
dirección del buffer DPSRAM. Cuando se realiza la transferencia de datos DMA, la dirección DPSRAM
no aumenta a la siguiente ubicación. Entonces, la siguiente transferencia de datos DMA se inicia al mismo
Dirección DPSRAM.
Este modo se selecciona programando los bits de selección del modo de direccionamiento (AMODE<1:0>) en '01'.
en el registro de control de canal DMA (DMAxCON). 
Si el modo de direccionamiento se cambia a Registrar indirecto sin direccionamiento post-incremento mientras
el canal DMA está activo (es decir, después de que se hayan producido algunas transferencias DMA), la DMA DPSRAM
La dirección apuntará a la ubicación actual del buffer DPSRAM (es decir, no al contenido del DMAxSTA).
o DMAxSTB, que para entonces podría diferir de la ubicación actual del buffer DPSRAM). Figura 22-9
ilustra la transferencia de datos desde el periférico a la DMA DPSRAM, contrastando el uso con y
sin direccionamiento post-incremento.
Configure el módulo Output Compare 1 para el modo PWM:
OC1CON = 0;
//Restablecer el módulo OC
OC1R = 0x60;
// Inicializa el ciclo de trabajo PWM
OC1RS = 0x60;
// Inicializa el búfer de ciclo de trabajo PWM
OC1CONbits.OCM = 6;
// Configurar OC para el modo PWM
Configure el canal DMA 3 en el modo Post Incremento con la fuente de solicitud Timer2:
unsigned int BufferA[32] __attribute__((espacio(dma)));
/* Inserte el código aquí para inicializar el BufferA con los valores de ciclo de trabajo deseados */
DMA3CONbits.AMODE = 0;
// Configurar DMA para el modo indirecto de registro 
// con post-incremento
DMA3CONbits.MODO = 0;
// Configurar DMA para modo continuo
DMA3CONbits.DIR = 1;
// Transferencias de datos de RAM a periférico
DMA3PAD = (int volátil sin signo)&OC1RS; // Apunta DMA a OC1RS
DMA3CNT = 31;
// 32 solicitud DMA
DMA3REQ = 7;
// Seleccione Timer2 como fuente de solicitud DMA
DMA3STA = __builtin_dmaoffset(BufferA);
IFS2bits.DMA3IF = 0;
// Borra el bit de bandera de interrupción DMA
IEC2bits.DMA3IE = 1;
// Establece el bit de habilitación de interrupción DMA
DMA3CONbits.CHEN = 1;
// Habilitar DMA
Configure Timer2 para el modo PWM de comparación de salida:
PR2 = 0xBF;
// Inicializa el periodo PWM
T2CONbits.TON = 1;
// Iniciar temporizador2
Configure el controlador de interrupciones del canal 3 de DMA:
void __attribute__((__interrupt__)) _DMA3Interrupt(void)
{
/* Actualice BufferA con nuevos valores de ciclo de trabajo si lo desea aquí*/
IFS2bits.DMA3IF = 0;
//Borrar el indicador de interrupción DMA3
}

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-26
© 2008 Microchip Technology Inc.
Figura 22-9:
Contraste de transferencia de datos con y sin direccionamiento post-incremento
&_DMA_BASE
&_DMA_BASE + DMA3STA + 0
&_DMA_BASE + DMA3STA + 1
&_DMA_BASE + DMA3STA + 2
Datos 0
periférico 
1
DMA
Canal 0
Canal DMA 0, primera transferencia (con direccionamiento post-incremento)
un
&_DMA_BASE
&_DMA_BASE + DMA3STA + 0
&_DMA_BASE + DMA3STA + 1
&_DMA_BASE + DMA3STA + 2
Datos 0
Datos 1
Datos 2
periférico 
1
DMA
Canal 0
&_DMA_BASE
&_DMA_BASE + DMA3STA + 0
&_DMA_BASE + DMA3STA + 1
&_DMA_BASE + DMA3STA + 2
Datos 0
Datos 1
periférico 
1
DMA
Canal 0
Canal DMA 0, segunda transferencia (con direccionamiento post-incremento)
b
DMA Canal 0, Tercera Transferencia (modo cambiado a Direccionamiento “Sin Post-Incremento”)
c
&_DMA_BASE
&_DMA_BASE + DMA3STA + 0
&_DMA_BASE + DMA3STA + 1
&_DMA_BASE + DMA3STA + 2
Datos 0
Datos 1
Datos 3
periférico 
1
DMA
Canal 0
DMA Canal 0, Cuarta Transferencia (sin direccionamiento post-incremento)
c
&_DMA_BASE + DMA3STA + 3
&_DMA_BASE + DMA3STA + 3
&_DMA_BASE + DMA3STA + 3
&_DMA_BASE + DMA3STA + 3
Transferencia 1
Transferencia 2
Transferencia 3
Transferencia 4

© 2008 Microchip Technology Inc.
DS70182B-página 22-27
Sección 22. Acceso directo a memoria (DMA)
DMA
22
Ejemplo 22-4:
Código para captura de entrada y DMA con registro indirecto sin 
Direccionamiento posterior al incremento
22.6.6
Modo de direccionamiento indirecto periférico
El modo de direccionamiento indirecto de periféricos es un modo de direccionamiento especial en el que el periférico, no el
Canal DMA, proporciona la parte variable de la dirección DPSRAM. Es decir, el periférico.
genera los bits menos significativos (LSb) de la dirección DPSRAM mientras que el canal DMA
proporciona la dirección base del búfer fijo. Sin embargo, el canal DMA continúa coordinando la
transferencia de datos real, realizar un seguimiento del recuento de transferencias y generar la CPU correspondiente
interrumpe. 
El modo de direccionamiento indirecto de periféricos puede funcionar bidireccionalmente, dependiendo del periférico. 
necesita, por lo que el canal DMA aún debe configurarse adecuadamente para admitir el periférico de destino. 
leer o escribir. 
El modo de direccionamiento indirecto periférico se selecciona programando la selección de modo de direccionamiento.
bits (AMODE<1:0>) a '1x' en el registro de control de canal DMA (DMAxCON). 
La capacidad DMA en el modo de direccionamiento indirecto periférico se puede adaptar específicamente para cumplir
las necesidades de cada periférico que lo soporta. El periférico define la secuencia de direcciones para
acceder a los datos dentro de la DPSRAM, lo que le permite, por ejemplo, clasificar los datos ADC entrantes en
múltiples buffers, liberando a la CPU de la tarea.
Si el modo de direccionamiento indirecto periférico es compatible con un periférico, se producirá una interrupción de solicitud DMA.
desde ese periférico va acompañado de una dirección que se presenta al canal DMA. si el
El canal DMA que responde a la solicitud también está habilitado para Direccionamiento Indirecto Periférico,
lógicamente O la dirección base del buffer con el periférico indirecto entrante extendido cero
Dirección para crear la dirección de compensación DPSRAM real, como se muestra en la Figura 22-10.
Configure el módulo Input Capture 1 para la operación DMA:
IC1CON = 0;
//Restablecer el módulo IC
IC1CONbits.ICTMR = 1;
//Selecciona el contenido de Timer2 para capturar
IC1CONbits.ICM = 2;
// Captura cada borde descendente
IC1CONbits.ICI = 0;
// Generar solicitud DMA en cada evento de captura
Configure Timer2 para que lo utilice el módulo de captura de entrada:
PR2 = 0xBF;
// Inicializa el valor del conteo
T2CONbits.TON = 1;
// Iniciar cronómetro
Configure el canal DMA 0 para el modo sin incremento posterior:
unsigned int CaptureValue __attribute__((espacio(dma)));
DMA0CONbits.AMODE = 1;
// Configurar DMA para registro indirecto 
// sin incremento posterior
DMA0CONbits.MODO = 0;
// Configurar DMA para modo continuo
DMA0PAD = (int volátil sin signo)&IC1BUF; // Apunta DMA a IC1BUF
DMA0CNT = 0;
// Interrumpir después de cada transferencia
DMA0REQ = 1;
// Seleccione el módulo de captura de entrada como fuente de solicitud DMA
DMA3STA = __builtin_dmaoffset(&CaptureValue);
IFS0bits.DMA0IF = 0;
// Borra el bit de bandera de interrupción DMA
IEC0bits.DMA0IE = 1;
// Establece el bit de habilitación de interrupción DMA
DMA0CONbits.CHEN = 1;
// Habilitar DMA
Configure el controlador de interrupciones del canal 0 de DMA:
void __attribute__((__interrupt__)) _DMA3Interrupt(void)
{
/* Procesa la variable CaptureValue aquí*/
IFS0bits.DMA0IF = 0;
//Borrar el indicador de interrupción DMA3
}

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-28
© 2008 Microchip Technology Inc.
Figura 22-10:
Generación de compensación de dirección en modo de direccionamiento indirecto periférico
El periférico determina cuántos bits de dirección menos significativa controlará. la aplicacion
El programa debe seleccionar una dirección base para el búfer en DPSRAM y asegurarse de que el
El número correspondiente de bits menos significativos de ese desplazamiento de dirección es cero. Como con otros
modos, cuando se lee el registro de compensación de dirección de inicio DPSRAM, devuelve un valor de la última
Desplazamiento de la dirección de transferencia DPSRAM, que incluye el cálculo del desplazamiento de dirección descrito anteriormente.
Si el canal DMA no está configurado para direccionamiento indirecto periférico, la dirección entrante es
ignorado y la transferencia de datos ocurre normalmente.
El modo de direccionamiento indirecto periférico es compatible con todos los demás modos operativos y actualmente está
Soportado por los módulos ADC y ECAN.
22.6.6.1
SOPORTE ADC PARA GENERACIÓN DE DIRECCIONES DMA
En el modo de direccionamiento indirecto de periféricos, el periférico define la secuencia de direccionamiento, que
está más adaptado a la funcionalidad periférica. Por ejemplo, si el ADC está configurado para funcionar continuamente
convierte las entradas 0 a 3 en secuencia (por ejemplo, 0, 1, 2, 3, 0, 1, etc.) y es
asociado con un canal DMA que está configurado para registrar direccionamiento indirecto con
Después del incremento, la transferencia DMA mueve estos datos a un búfer secuencial como se muestra en la Figura 22-11.
El ejemplo 22-5 ilustra el código para esta configuración.
Figura 22-11:
Transferencia de datos desde ADC con direccionamiento indirecto de registro
Dirección de compensación
(de DMAxSTA o DMAxSTB)
Dirección indirecta periférica
(de periférico)
Dirección PIA
0. . . . 0
0. . . . 0
Dirección de compensación
Desplazamiento de dirección DPSRAM
Responsabilidad de la aplicación:
Establecer en '0'
Extensión cero
&_DMA_BASE
&_DMA_BASE+DMA5STA+PIA (para Transferencia 1)
CAD
DMA
canal
5
UN 0
UN 1
UN 2
UN 3
Datos
DMA
Solicitar
AN0 Muestra 1
AN1 Muestra 1
AN2 Muestra 1
AN0 Muestra 2
AN0 Muestra 3
AN2 Muestra 2
AN1 Muestra 2
AN1 Muestra 3
AN2 Muestra 3
AN3 Muestra 1
AN3 Muestra 2
AN3 Muestra 3
Transferencia 1
Transferencia 2
Transferencia 12
Transferencia 3

© 2008 Microchip Technology Inc.
DS70182B-página 22-29
Sección 22. Acceso directo a memoria (DMA)
DMA
22
Ejemplo 22-5:
Código para transferencia de datos desde ADC con direccionamiento indirecto de registro
Configure ADC1 para el muestreo del canal 0-3:
AD1CON1bits.FORM = 3;
// Formato de salida de datos: fracción firmada (formato Q15)
AD1CON1bits.SSRC = 2;
// Fuente de reloj de muestra: GP Timer inicia la conversión
AD1CON1bits.ASAM = 1;
// El muestreo comienza inmediatamente después de la conversión.
AD1CON1bits.AD12B = 0;
// operación ADC de 10 bits
AD1CON1bits.SIMSAM = 0; 
// Muestra canales individuales secuencialmente
AD1CON2bits.BUFM = 0;
AD1CON2bits.CSCNA = 1;
// Escanear selecciones de entrada CH0+ durante el bit de muestra A
AD1CON2bits.CHPS = 0;
// Convierte CH0
AD1CON3bits.ADRC = 0;
// El reloj ADC se deriva del reloj de sistemas
AD1CON3bits.ADCS = 63;
// Reloj de conversión ADC
//AD1CHS0: Registro de selección de entrada A/D
AD1CHS0bits.CH0SA = 0;
// selección de entrada MUXA +ve (AIN0) para CH0
AD1CHS0bits.CH0NA = 0;
// selección de entrada MUXA -ve (VREF-) para CH0
//AD1CHS123: Registro de selección de entrada A/D
AD1CHS123bits.CH123SA = 0;
// Selección de entrada MUXA +ve (AIN0) para CH1
AD1CHS123bits.CH123NA = 0;
// selección de entrada MUXA -ve (VREF-) para CH1
//AD1CSSH/AD1CSSL: Registro de selección de escaneo de entrada A/D
AD1CSSH = 0x0000;
AD1CSSL = 0x000F;
// Escanear entradas AIN0, AIN1, AIN2, AIN3
Configure Timer3 para activar conversiones ADC1:
TMR3 = 0x0000;
PR3 = 4999;
// Activa ADC1 cada 125 μs a 40 MIPS
IFS0bits.T3IF = 0;
// Borrar interrupción del Timer3
IEC0bits.T3IE = 0;
// Deshabilitar la interrupción del Timer3
T3CONbits.TON = 1;
//Iniciar temporizador3
Configure el canal 5 de DMA para el registro indirecto con direccionamiento post-incremento:
unsigned int BufferA[32] __attribute__((espacio(dma)));
unsigned int BufferB[32] __attribute__((espacio(dma)));
DMA5CONbits.AMODE = 0;
// Configurar DMA para el modo indirecto de registro 
// con post-incremento
DMA5CONbits.MODO = 2;
// Configurar DMA para el modo Ping-Pong continuo
DMA5PAD = (int volátil sin signo)&ADC1BUF0; // Apunta DMA a ADC1BUF0
DMA5CNT = 31;
// 32 solicitud DMA
DMA5REQ = 13;
// Seleccione ADC1 como fuente de solicitud DMA
DMA5STA = __builtin_dmaoffset(BufferA);
DMA5STB = __builtin_dmaoffset(BufferB);
IFS3bits.DMA5IF = 0;
//Borra el bit de bandera de interrupción DMA
IEC3bits.DMA5IE = 1;
//Establece el bit de habilitación de interrupción DMA
DMA5CONbits.CHEN=1;
// Habilitar DMA

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-30
© 2008 Microchip Technology Inc.
Ejemplo 22-5:
Código para transferencia de datos desde ADC con direccionamiento indirecto de registro 
(Continuación)
Un algoritmo típico funcionaría por canal de datos ADC, requiriendo que ordene
datos transferidos o indexarlos saltando datos no deseados. Cualquiera de estos métodos requiere más
código y consume más tiempo de ejecución. El modo de direccionamiento indirecto periférico ADC define un
Técnica de direccionamiento especial donde los datos de cada canal ADC se colocan en su propio búfer. Para
En el ejemplo anterior, si el canal DMA está configurado para el modo de direccionamiento indirecto periférico,
La transferencia DMA mueve los datos del ADC a búferes separados, como se muestra en la Figura 22-12.
Figura 22-12:
Transferencia de datos desde ADC con direccionamiento indirecto periférico
Configure el controlador de interrupciones del canal 5 de DMA:
int sin firmar DmaBuffer = 0;
void __attribute__((__interrupt__)) _DMA5Interrupt(void)
{
// Cambiar entre buffers de ping-pong primarios y secundarios
si (DmaBuffer == 0)
{
ProcessADCSamples(BufferA);
}
otra cosa
{
ProcessADCSamples(BufferB);
}
DmaBuffer ^= 1;
IFS3bits.DMA5IF = 0;
//Borrar el indicador de interrupción DMA5
}
Configure ADC1 para la operación DMA:
AD1CON1bits.ADDMABM = 0; 
// No importa: la generación de direcciones ADC es
// Ignorado por DMA
AD1CON2bits.SMPI = 3;
// No me importa
AD1CON4bits.DMABL = 3;
// No me importa
        
IFS0bits.AD1IF = 0;
// Borra el bit de bandera de interrupción A/D
IEC0bits.AD1IE = 0;
// No habilitar la interrupción A/D 
AD1CON1bits.ADON = 1;
//Enciende el convertidor A/D
&_DMA_BASE
&_DMA_BASE+DMA5STA+PIA (para Transferencia 1)
CAD
DMA
canal
5
UN 0
UN 1
UN 2
UN 3
Datos
DMA
Solicitar
AN0 Muestra 1
AN0 Muestra 2
AN0 Muestra 3
AN1 Muestra 1
AN2 Muestra 1
AN1 Muestra 3
AN1 Muestra 2
AN2 Muestra 2
AN2 Muestra 3
AN3 Muestra 1
AN3 Muestra 2
AN3 Muestra 3
:
:
:
:
&_DMA_BASE+DMA5STA+PIA (para Transferencia 2)
&_DMA_BASE+DMA5STA+PIA (para Transferencia 12)
:
:
:
:
:
:
:
:
:
:
:
:
:
:
:
Transferencia 1
Transferencia 5
Transferencia 2
Transferencia 3
Transferencia 4
Transferencia 12
Dirección indirecta periférica (PIA)

© 2008 Microchip Technology Inc.
DS70182B-página 22-31
Sección 22. Acceso directo a memoria (DMA)
DMA
22
Para habilitar este tipo de direccionamiento ADC, el bit DMA Buffer Build Mode (ADDMABM) en el ADCx
Se debe borrar el registro de control 1 (ADxCON1). Si este bit está establecido, el ADC genera direcciones en
el orden de conversión (igual que el direccionamiento indirecto del registro DMA con modo post-incremento).
Como se mencionó anteriormente, debe prestar especial atención al número de bits menos significativos que
están reservados para el periférico cuando los registros de compensación de dirección de inicio DPSRAM (DMAxSTA y
DMaxSTB) son inicializados por la aplicación de usuario. Para el ADC, el número de bits dependerá de
el tamaño y el número de buffers del ADC.
El número de buffers ADC se inicializa con la tasa de incremento para los bits de direcciones DMA SMPI<3:0>
en el registro ADCx Control 2 (ADxCON2). El tamaño de cada búfer ADC se inicializa con
Número de ubicaciones de búfer DMA por bits de entrada analógica DMABL<2:0> en el control ADCx 4
(ADCxCON4) registro. Por ejemplo, si SMPI<3:0> se inicializa en 3 y DMABL<2:0> es
inicializado a 3, habrá cuatro buffers ADC (SMPI<3:0> + 1), cada uno con ocho palabras
(2 DMABL<2:0>), para un total de 32 palabras (64 bytes). Esto significa que el desplazamiento de dirección que es
escrito en DMAxSTA y DMAxSTB debe tener 6 (26 bits = 64 bytes) bits menos significativos
puesto a cero.
Si se utiliza el compilador MPLAB® C30 para inicializar los registros DMAxSTA y DMAxSTAB,
La alineación adecuada de los datos debe especificarse mediante atributos de datos. Para las condiciones anteriores, el código
mostrado en el Ejemplo 22-6 inicializará correctamente los registros DMaxSTA y DMaxSTB.
Ejemplo 22-6:
Alineación del buffer DMA con MPLAB® C30
El ejemplo 22-7 ilustra el código para esta configuración.
int BufferA[4][8] __attribute__((espacio(dma),alineado(64)));
int BufferB[4][8] __attribute__((espacio(dma),alineado(64)));
DMA0STA = __builtin_dmaoffset(BufferA);
DMA0STB = __builtin_dmaoffset(BufferB);

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-32
© 2008 Microchip Technology Inc.
Ejemplo 22-7:
Código para ADC y DMA con direccionamiento indirecto periférico
Configure ADC1 para el muestreo del canal 0-3:
AD1CON1bits.FORM = 3;
// Formato de salida de datos: fracción firmada (formato Q15)
AD1CON1bits.SSRC = 2;
// Fuente de reloj de muestra: GP Timer inicia la conversión
AD1CON1bits.ASAM = 1;
// El muestreo comienza inmediatamente después de la conversión.
AD1CON1bits.AD12B = 0;
// operación ADC de 10 bits
AD1CON1bits.SIMSAM = 0; 
// Muestras de múltiples canales secuencialmente
AD1CON2bits.BUFM = 0;
AD1CON2bits.CSCNA = 1;
// Escanear selecciones de entrada CH0+ durante el bit de muestra A
AD1CON2bits.CHPS = 0;
// Convierte CH0
AD1CON3bits.ADRC = 0;
// El reloj ADC se deriva del reloj de sistemas
AD1CON3bits.ADCS = 63;
// Reloj de conversión ADC
//AD1CHS0: Registro de selección de entrada A/D
AD1CHS0bits.CH0SA = 0;
// selección de entrada MUXA +ve (AIN0) para CH0
AD1CHS0bits.CH0NA = 0;
// selección de entrada MUXA -ve (VREF-) para CH0
//AD1CHS123: Registro de selección de entrada A/D
AD1CHS123bits.CH123SA = 0;
// Selección de entrada MUXA +ve (AIN0) para CH1
AD1CHS123bits.CH123NA = 0;
// selección de entrada MUXA -ve (VREF-) para CH1
//AD1CSSH/AD1CSSL: Registro de selección de escaneo de entrada A/D
AD1CSSH = 0x0000;
AD1CSSL = 0x000F;
// Escanear entradas AIN0, AIN1, AIN2, AIN3
Configure Timer3 para activar conversiones ADC1:
TMR3 = 0x0000;
PR3 = 4999; // Activa ADC1 cada 125 usos
IFS0bits.T3IF = 0;
// Borrar interrupción del Timer3
IEC0bits.T3IE = 0;
// Deshabilitar la interrupción del Timer3
T3CONbits.TON = 1;
//Iniciar temporizador3
Configure el canal 5 de DMA para direccionamiento indirecto de periféricos:
estructura
{
sin firmar int Adc1Ch0[8];
sin firmar int Adc1Ch1[8];
sin firmar int Adc1Ch2[8];
sin firmar int Adc1Ch3[8];
} BufferA __attribute__((espacio(dma)));
estructura
{
sin firmar int Adc1Ch0[8];
sin firmar int Adc1Ch1[8];
sin firmar int Adc1Ch2[8];
sin firmar int Adc1Ch3[8];
} BufferB __attribute__((espacio(dma)));
int BufferA[4][8] __attribute__((espacio(dma), alineado(64)));
BufferB[4][8] __attribute__((espacio(dma), alineado(64)));
DMA5CONbits.AMODE = 2;
// Configurar DMA para modo indirecto periférico
DMA5CONbits.MODO = 2; 
// Configurar DMA para el modo Ping-Pong continuo
DMA5PAD = (int volátil sin signo)&ADC1BUF0; // Apunta DMA a ADC1BUF0
DMA5CNT = 31; 
// 32 solicitudes DMA (4 buffers, cada uno con 8 palabras)
DMA5REQ = 13;
// Seleccione ADC1 como fuente de solicitud DMA
DMA5STA = __builtin_dmaoffset(BufferA);
DMA5STB = __builtin_dmaoffset(BufferB);
IFS3bits.DMA5IF = 0;
//Borra el bit de bandera de interrupción DMA
IEC3bits.DMA5IE = 1;
//Establece el bit de habilitación de interrupción DMA
DMA5CONbits.CHEN=1;
// Habilitar DMA

© 2008 Microchip Technology Inc.
DS70182B-página 22-33
Sección 22. Acceso directo a memoria (DMA)
DMA
22
Ejemplo 22-7:
Código para ADC y DMA con direccionamiento indirecto de periféricos (continuación)
22.6.6.2
SOPORTE ECAN PARA LA GENERACIÓN DE DIRECCIONES DMA
El direccionamiento indirecto periférico también se puede utilizar con el módulo ECAN para permitir que ECAN defina más
funcionalidad de direccionamiento específica. Cuando el dispositivo dsPIC33F filtra y recibe mensajes a través de
el bus CAN, los mensajes se pueden clasificar en dos grupos:
• Mensajes recibidos que deben ser procesados
• Mensajes recibidos que deben reenviarse a otros nodos CAN sin procesar
En el primer caso, los mensajes recibidos deben reconstruirse en buffers de ocho palabras cada uno.
antes de que puedan ser procesados por la aplicación del usuario. Con múltiples buffers ECAN ubicados en el
DMA RAM, sería más fácil dejar que el periférico ECAN genere direcciones RAM para entradas
(o salientes), como se muestra en la Figura 22-13. En este ejemplo, el buffer 2 se recibe primero, seguido
por el Buffer 0. El módulo ECAN genera direcciones de destino para colocar correctamente los datos en el
DMA RAM (Direccionamiento indirecto de periféricos).
Configure el controlador de interrupciones del canal 5 de DMA:
int sin firmar DmaBuffer = 0;
void __attribute__((__interrupt__)) _DMA5Interrupt(void)
{
// Cambiar entre buffers de ping-pong primarios y secundarios
si (DmaBuffer == 0)
{
ProcessADCSamples(BufferA.Adc1Ch0);
ProcessADCSamples(BufferA.Adc1Ch1);
ProcessADCSamples(BufferA.Adc1Ch2);
ProcessADCSamples(BufferA.Adc1Ch3);
}
otra cosa
{
ProcessADCSamples(BufferB.Adc1Ch0);
ProcessADCSamples(BufferB.Adc1Ch1);
ProcessADCSamples(BufferB.Adc1Ch2);
ProcessADCSamples(BufferB.Adc1Ch3);
}
DmaBuffer ^= 1;
IFS3bits.DMA5IF = 0;
//Borrar el indicador de interrupción DMA5
}
Configure ADC1 para la operación DMA:
AD1CON1bits.ADDMABM = 0; 
// Los buffers DMA están construidos en modo dispersión/reunión
AD1CON2bits.SMPI = 3;
// 4 buffers ADC
AD1CON4bits.DMABL = 3;
// Cada buffer contiene 8 palabras
        
IFS0bits.AD1IF = 0;
// Borra el bit de bandera de interrupción A/D
IEC0bits.AD1IE = 0;
// No habilitar la interrupción A/D 
AD1CON1bits.ADON = 1;
//Enciende el convertidor A/D

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-34
© 2008 Microchip Technology Inc.
Figura 22-13:
Transferencia de datos desde ECAN con direccionamiento indirecto periférico
Como se mencionó anteriormente, debe prestar especial atención al número de bits menos significativos que
están reservados para el periférico cuando los registros de compensación de dirección de inicio DPSRAM (DMAxSTA y
DMaxSTB) son inicializados por la aplicación de usuario y el DMA está funcionando en modo periférico indirecto.
Modo de direccionamiento. Para el ECAN, el número de bits depende del número de buffers del ECAN.
definido por los bits de tamaño del búfer DMA (DMABS<2:0>) en el registro de control ECAN FIFO
(CiFCTRL). 
Por ejemplo, si el módulo ECAN reserva 12 buffers configurando los bits DMABS<2:0> en '3', no
Habrá 12 buffers con ocho palabras cada uno, para un total de 96 palabras (192 bytes). Esto significa que el
El desplazamiento de dirección que se escribe en los registros DMAxSTA y DMAxSTB debe tener 8 (28 bits =
256 bytes) Bits menos significativos establecidos en '0'. Si se utiliza el compilador MPLAB C30 para inicializar el
Registro DMaxSTA, se debe especificar la alineación adecuada de los datos mediante atributos de datos. Por lo anterior
Por ejemplo, el código del Ejemplo 22-8 inicializa correctamente el registro DMaxSTA.
Ejemplo 22-8:
Alineación del búfer DMA con MPLAB® C30
El ejemplo 22-9 ilustra el código para esta configuración.
Sin embargo, es posible que el procesamiento de mensajes entrantes no siempre sea un requisito. Por ejemplo, en
En algunas aplicaciones automotrices, los mensajes recibidos pueden simplemente reenviarse a otro nodo.
en lugar de ser procesado por la CPU. En este caso, no es necesario ordenar los buffers recibidos.
en la memoria y se pueden reenviar a medida que estén disponibles. 
Este modo de transferencia de datos se puede lograr con el DMA en Registro de direccionamiento indirecto con
Post-incremento. La figura 22-14 ilustra este escenario.
Búfer 0: SID
Búfer 0: EID
:
:
:
:
:
:
Búfer 2: SID
Memoria intermedia 2: EID
:
:
:
;
:
:
&_DMA_BASE
ECAN
DMA
canal
0
RX
Datos
DMA
Solicitar
Transferir 9
Transferencia 1
Transferencia 8
Dirección indirecta periférica
Transferencia 16
Búfer 0
Búfer 1
Tampón 2
int BufferA[12][8] __attribute__((espacio(dma),alineado(256)));
DMA0STA = __builtin_dmaoffset(&BufferA[0][0]);

© 2008 Microchip Technology Inc.
DS70182B-página 22-35
Sección 22. Acceso directo a memoria (DMA)
DMA
22
Ejemplo 22-9:
Código para ECAN y DMA con direccionamiento indirecto de periféricos
Configure ECAN1 con dos filtros:
/* Inicializa primero el reloj ECAN. Consulte la sección ECAN para ver el código de ejemplo */
C1CTRL1bits.WIN = 1;
// Habilitar ventana de filtro
C1FEN1bits.FLTEN0 = 1;
// El filtro 0 está habilitado
C1FEN1bits.FLTEN1 = 1;
// El filtro 1 está habilitado
C1BUFPNT1bits.F0BP = 0;
// Filtrar 0 puntos a Buffer0
C1BUFPNT1bits.F1BP = 2;
// Filtrar 1 puntos al Buffer2
C1RXF0SID = 0xFFEA;
// Configuración del filtro 0
C1RXF0EID = 0xFFFF; 
C1RXF1SID = 0xFFEB;
// Configuración del filtro 1
C1RXF1EID = 0xFFFF;
C1FMSKSEL1bits.F0MSK = 0;
// Máscara 0 utilizada para ambos filtros
C1FMSKSEL1bits.F1MSK = 0;
// Máscara 0 utilizada para ambos filtros
C1RXM0SID = 0xFFEB;
C1RXM0EID = 0xFFFF;
C1FCTRLbits.DMABS = 3;
// 12 buffers en DMA RAM
C1FCTRLbits.FSA = 3;
// FIFO comienza desde el búfer TX/RX 3
C1CTRL1bits.WIN = 0;
C1TR01CONbits.TXEN0 = 0;
// El búfer 0 es un búfer de recepción
C1TR23CONbits.TXEN2 = 0;
// El búfer 2 es un búfer de recepción
C1TR01CONbits.TX0PRI = 0b11;
//alta prioridad
C1TR01CONbits.TX1PRI = 0b10;
// Prioridad intermedia alta
C1CTRL1bits.REQOP = 0;// Habilitar el modo de operación normal
Configure el canal 0 de DMA para direccionamiento indirecto de periféricos:
unsigned int Ecan1Rx[12][8] __attribute__((space(dma)));// 12 buffers, 8 
palabras cada una
DMA0CONbits.AMODE = 2;
// Modo continuo, buffer único
DMA0CONbits.MODO = 0;
// Direccionamiento indirecto periférico
DMA0PAD = (int volátil sin signo) &C1RXD;
// Apunta al registro ECAN1 RX
DMA0STA = __builtin_dmaoffset(Ecan1Rx);
// Apunta DMA a los buffers ECAN1
DMA0CNT = 7;
// 8 solicitudes DMA (1 búfer, cada uno con 8 palabras)
DMA0REQ = 0x22;
// Seleccione ECAN1 RX como fuente de solicitud DMA
IEC0bits.DMA0IE = 1;
// Habilitar la interrupción del canal 0 de DMA
DMA0CONbits.CHEN = 1;
// Habilitar canal DMA 0
Configurar el controlador de interrupciones DMA:
void __attribute__((__interrupt__)) _DMA0Interrupt(void)
{
   ProcessData(Ecan1Rx[C1VECbits.ICODE]);
// Procesar el buffer recibido;
   
   IFS0bits.DMA0IF = 0;
// Borrar el indicador de interrupción DMA0;
}

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-36
© 2008 Microchip Technology Inc.
Figura 22-14:
Transferencia de datos desde ECAN con registro de direccionamiento indirecto
ECAN 1
Búfer 2: SID
Memoria intermedia 2: EID
:
:
:
:
:
:
&_DMA_BASE
ECAN 1
DMA
canal
0
RX
Datos
DMA
Solicitar
Transferencia 1
Transferencia 8
Tampón 2
Búfer 2: SID
Memoria intermedia 2: EID
:
:
:
:
:
:
Búfer 0: SID
Búfer 0: EID
:
:
:
:
:
:
ECAN 1
DMA
canal
0
RX
Datos
DMA
Solicitar
Transferir 9
Transferencia 16
Búfer 0
Búfer 2: SID
Memoria intermedia 2: EID
:
:
:
:
:
:
Búfer 0: SID
Búfer 0: EID
:
:
:
:
:
:
&_DMA_BASE
Transferir 9
Transferencia 16
DMA
canal
1
ECAN 1
Texas
Datos
DMA
Solicitar
Transferencia 1
Transferencia 8
DMA
canal
1
Texas
Datos
DMA
Solicitar
Recibir búfer 2
un
Recibir el búfer 0 y transmitir el búfer 2
b
Búfer de transmisión 0
c

© 2008 Microchip Technology Inc.
DS70182B-página 22-37
Sección 22. Acceso directo a memoria (DMA)
DMA
22
22.6.7
Modo de una sola vez
El programa de aplicación utiliza el modo One-Shot cuando no se requiere una transferencia de datos repetitiva.
El modo One-Shot se selecciona programando los bits de selección del modo operativo (MODE<1:0>) para
'x1' en el registro de control de canal DMA (DMAxCON). En este modo, cuando todo el bloque de datos
se mueve (longitud del bloque definida por DMAxCNT), se detecta el final del bloque de datos y el canal
se desactiva automáticamente (es decir, el bit CHEN en el registro de control de canal DMA (DMAxCON) se desactiva automáticamente.
borrado por el hardware). La Figura 22-15 ilustra el modo One-Shot.
Figura 22-15:
Transferencia de bloques de datos con modo One-Shot
Si el bit HALF está configurado en el registro DMA Channel Control (DMAxCON), el bit DMAxIF está configurado
(y se genera la interrupción DMA, si está habilitada por el programa de aplicación) cuando la mitad de los datos
La transferencia en bloque se completa y el canal permanece habilitado. Cuando la transferencia de bloque completo es
completa, no se establece ningún indicador de interrupción y el canal se desactiva automáticamente. Consulte 22.6.3 “Lleno o
Interrupciones de transferencia de medio bloque” para obtener información sobre cómo configurar el canal DMA para interrumpir
tanto en transferencias de medio bloque como de bloque completo.
Si el canal se vuelve a habilitar configurando CHEN en DMAxCON en '1', se lleva a cabo la transferencia en bloque.
desde la dirección de inicio, según lo proporcionado por el desplazamiento de dirección de inicio de DPSRAM (DMAxSTA y DMAxSTB)
registros. El ejemplo 22-10 ilustra el código para la operación One-Shot.
Ejemplo 22-10: Código para UART y DMA con modo One-Shot
&_DMA_BASE
TRANSFERENCIA #1
TRANSFERENCIA #2
TRANSFERENCIA #3
TRANSFERENCIA #n
CONTAR++
CONTAR = DMAxCNT+1
&_DMA_BASE+DMAxSTA
CPU
Transferencia en bloque 
completo
IRQ
Configure UART para RX y TX:
#definir FCY 40000000
#definir BAUDRATE 9600                
#definir BRGVAL ((FCY/BAUDRATE)/16)-1
U2MODEbits.STSEL = 0;
// bit de 1 parada
U2MODEbits.PDSEL = 0;
// Sin paridad, 8 bits de datos
U2MODEbits.ABAUD = 0;
// Autobaud deshabilitado
U2BRG = BRGVAL;// Configuración de velocidad en BAUDIOS para 9600
U2STAbits.UTXISEL0 = 0;
// Interrumpir después de transmitir un carácter TX
U2STAbits.UTXISEL1 = 0;                            
U2STAbits.URXISEL = 0;
// Interrumpir después de recibir un carácter RX
U2MODEbits.UARTEN = 1;
// Habilitar UART
U2STAbits.UTXEN = 1;
// Habilitar UART TX

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-38
© 2008 Microchip Technology Inc.
Ejemplo 22-10: Código para UART y DMA con modo One-Shot (continuación)
Configure el canal DMA 0 para transmitir en modo One-Shot, Single-Buffer:
unsigned int BufferA[8] __attribute__((espacio(dma)));
unsigned int BufferB[8] __attribute__((espacio(dma)));
DMA0CON = 0x2001;
// One-Shot, Post-Incremento, RAM a Periférico
DMA0CNT = 7;
// 8 solicitudes DMA
DMA0REQ = 0x001F;
//Seleccione el transmisor UART2
DMA0PAD = (int volátil sin signo) &U2TXREG;
DMA0STA = __builtin_dmaoffset(BufferA);
IFS0bits.DMA0IF = 0;
// Borrar indicador de interrupción DMA
IEC0bits.DMA0IE = 1;
// Habilitar interrupción DMA
Configure el canal DMA 1 para recibir en modo Ping-Pong continuo:
DMA1CON = 0x0002;
// Continuo, Ping-Pong, Post-Inc., Periph-RAM
DMA1CNT = 7;
// 8 solicitudes DMA
DMA1REQ = 0x001E;
//Seleccione el receptor UART2
DMA1PAD = (int volátil sin signo) &U2RXREG;
DMA1STA = __builtin_dmaoffset(BufferA);
DMA1STB = __builtin_dmaoffset(BufferB);
IFS0bits.DMA1IF = 0;
// Borrar interrupción DMA
IEC0bits.DMA1IE = 1;
// Habilitar interrupción DMA
DMA1CONbits.CHEN = 1;
// Habilitar canal DMA
Configurar el controlador de interrupciones DMA:
void __attribute__((__interrupt__)) _DMA0Interrupt(void)
{
   IFS0bits.DMA0IF = 0;
// Borrar el indicador de interrupción DMA0;
}
void __attribute__((__interrupt__)) _DMA1Interrupt(void)
{
   estático sin signo int BufferCount = 0; 
// Mantener registro de qué buffer
// contiene datos RX
   si(BufferCount == 0)
   {
DMA0STA = __builtin_dmaoffset(BufferA);
// Apunta DMA 0 a los datos 
// a transmitir
   }
   otra cosa
 {
DMA0STA = __builtin_dmaoffset(BufferB); // Apunta DMA 0 a los datos 
// a transmitir
   }
   DMA0CONbits.CHEN = 1;
// Habilitar canal DMA0
   DMA0REQbits.FORCE = 1;
// Modo manual: inicia la primera transferencia
   Conteo de búfer ^= 1;
   IFS0bits.DMA1IF = 0;
// Borrar el indicador de interrupción DMA1
}

© 2008 Microchip Technology Inc.
DS70182B-página 22-39
Sección 22. Acceso directo a memoria (DMA)
DMA
22
22.6.8
Modo continuo
El programa de aplicación utiliza el modo continuo cuando se requiere una transferencia de datos repetitiva
durante toda la vida del programa. 
Este modo se selecciona programando los bits de selección del modo de funcionamiento (MODO<1:0>) en 'x0' en
el registro de control de canal DMA (DMAxCON). En este modo, cuando todo el bloque de datos está
movido (longitud del bloque definida por DMAxCNT), se detecta el final del bloque de datos y el canal
permanece habilitado. Durante la última transferencia de datos, la dirección DMA DPSRAM se restablece a (primaria)
Registro de desplazamiento de dirección de inicio DPSRAM A (DMaxSTA). La Figura 22-16 ilustra el modo Continuo.
Figura 22-16:
Transferencia de bloques de datos repetitivos con modo continuo
Si el bit HALF está configurado en el registro DMA Channel Control (DMAxCON), DMAxIF está configurado (y
La interrupción DMA se genera, si está habilitada) cuando se completa la mitad de la transferencia del bloque de datos. el
El canal permanece habilitado. Cuando se completa la transferencia de bloque completo, no se establece ningún indicador de interrupción y
el canal permanece habilitado. Consulte 22.6.3 “Interrupciones de transferencia de bloque completo o medio bloque”, para
información sobre cómo configurar el canal DMA para interrumpir la transferencia de medio bloque y de bloque completo.
22.6.9
Modo ping pong
El modo Ping-Pong permite a la CPU procesar un búfer mientras un segundo búfer opera con el
Canal DMA. El resultado neto es que la CPU tiene todo el tiempo de transferencia de bloques DMA para
procesar el búfer que actualmente no está siendo utilizado por el canal DMA. Por supuesto, este modo de transferencia
duplica la cantidad de DPSRAM necesaria para un tamaño determinado de búfer.
En todos los modos de funcionamiento DMA, cuando el canal DMA está habilitado, el canal DMA (primario) x
El registro DPSRAM Start Address Offset A (DMaxSTA) se selecciona de forma predeterminada para generar la dirección inicial.
Dirección efectiva de DPSRAM. A medida que se completa cada transferencia en bloque y el canal DMA es
reiniciado, la dirección de inicio del búfer proviene del mismo registro DMaxSTA.
En el modo Ping-Pong, la dirección de inicio del búfer se deriva de dos registros:
• Primario: Registro de desplazamiento A de dirección de inicio de canal DMA x DPSRAM (DMAxSTA)
• Secundario: Registro de desplazamiento B de dirección de inicio de canal DMA x DPSRAM (DMAxSTB)
El DMA utiliza un búfer secundario para transferencias en bloques alternativas. A medida que se completa cada transferencia en bloque
y el canal DMA se reinicia, la dirección de inicio del búfer se deriva del canal alternativo
registrarse.
El modo Ping-Pong se selecciona mediante programación Modo de funcionamiento Seleccionar bits (MODO<1:0>) a '1x'
en el registro de control de canal DMA (DMAxCON).
&_DMA_BASE
Transferencia #1
Transferencia #2
Transferencia #3
Transferencia #n
CONTAR++
&_DMA_BASE+DMAxSTA
CONTAR=0
Conteo = DMAxCNT+1
CPU
Transferencia en bloque 
completo
IRQ

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-40
© 2008 Microchip Technology Inc.
Si se selecciona el modo Continuo mientras el DMA está funcionando en modo Ping-Pong, el DMA
responde reiniciando para apuntar al búfer secundario después de transferir el búfer primario, y
luego transfiere el buffer secundario. Las transferencias en bloque posteriores alternan entre primaria y
amortiguadores secundarios. Las interrupciones se generan (si el programa de aplicación las habilita) después de cada
se transfiere el buffer. La Figura 22-17 ilustra el modo Ping-Pong con funcionamiento continuo.
El ejemplo 22-11 ilustra el código utilizado para la operación Ping-Pong utilizando el módulo DCI como
ejemplo.
Figura 22-17:
Transferencia de datos repetitiva en modo ping-pong
&_DMA_BASE
Transferencia #1
Transferencia #2
Transferencia #3
Transferencia #n
CONTAR++
&_DMA_BASE+DMAxSTA
CONTAR = 0
CONTAR = DMAxCNT+1
Transferencia en bloque de CPU
IRQ completa
Transferencia #1
Transferencia #2
Transferencia #3
Transferencia #n
CONTAR++
&_DMA_BASE+DMAxSTB
CONTAR = DMAxCNT+1
Transferencia en bloque de CPU
IRQ completa
Tampón A (primario)
Búfer B (Secundario)

© 2008 Microchip Technology Inc.
DS70182B-página 22-41
Sección 22. Acceso directo a memoria (DMA)
DMA
22
Ejemplo 22-11: Código para DCI y DMA con operación ping-pong continua
Configure DCI para RX y TX:
#definir FCY
40000000
#definir FS
48000
#definir FCSCK
64*FS
#definir BCGVAL (FCY/(2*FS))-1
DCICON1bits.CSCKD = 0; // Se emite el reloj de bits serie (pin CSCK)
DCICON1bits.CSCKE = 0; // Datos muestreados en el flanco descendente de CSCK
DCICON1bits.COFSD = 0; // Se emite la señal de sincronización de cuadros
DCICON1bits.UNFM = 0;
// Transmite '0's en un desbordamiento de transmisión
DCICON1bits.CSDOM = 0; // El pin CSDO genera '0's durante los intervalos de tiempo de TX deshabilitados
DCICON1bits.DJST = 0;
// TX/RX inicia 1 ciclo de reloj en serie después del pulso de sincronización de cuadro
DCICON1bits.COFSM = 1; // Señal de sincronización de cuadros configurada para el modo I2S
DCICON2bits.BLEN = 0;
// Se almacenará una palabra de datos entre interrupciones
DCICON2bits.COFSG = 1; // El marco de datos tiene 2 palabras: muestras IZQUIERDA y DERECHA
DCICON2bits.WS = 15;
// El tamaño de la palabra de datos es de 16 bits
DCICON3 = BCG_VAL;// Configurar la frecuencia del reloj de bits CSCK
TSCONbits.TSE0 = 1;    // Transmitir en el intervalo de tiempo 0
TSCONbits.TSE1 = 1;    // Transmitir en el intervalo de tiempo 1
RSCONbits.RSE0 = 1;    // Recibir en el intervalo de tiempo 0
RSCONbits.RSE1 = 1;    // Recibir en el intervalo de tiempo 1
Configure el canal 0 de DMA para transmitir en modo Ping-Pong continuo:
unsigned int TxBufferA[16] __attribute__((espacio(dma)));
unsigned int TxBufferB[16] __attribute__((espacio(dma)));
DMA0CON = 0x2002;
// Ping-Pong, Continuo, Post-Incremento, RAM a Periférico
DMA0CNT = 15;
// 15 solicitudes DMA
DMA0REQ = 0x003C;
//Selecciona DCI como fuente de solicitud DMA
DMA0PAD = (int volátil sin signo) &TXBUF0;
DMA0STA = __builtin_dmaoffset(TxBufferA);
DMA0STB = __builtin_dmaoffset(TxBufferB);
IFS0bits.DMA0IF = 0;
// Borrar indicador de interrupción DMA
IEC0bits.DMA0IE = 1;
// Habilitar interrupción DMA
DMA0CONbits.CHEN = 1;
// Habilitar canal DMA
Configure el canal DMA 1 para recibir en modo Ping-Pong continuo:
unsigned int RxBufferA[16] __attribute__((espacio(dma)));
unsigned int RxBufferB[16] __attribute__((espacio(dma)));
DMA1CON = 0x0002;
// Continuo, Ping-Pong, Post-Inc., Periph-RAM
DMA1CNT = 15;
// 16 solicitudes DMA
DMA1REQ = 0x003C;
//Selecciona DCI como fuente de solicitud DMA
DMA1PAD = (int volátil sin signo) &RXBUF0;
DMA1STA = __builtin_dmaoffset(RxBufferA);
DMA1STB = __builtin_dmaoffset(RxBufferB);
IFS0bits.DMA1IF = 0;// Borrar interrupción DMA
IEC0bits.DMA1IE = 1;// Habilitar interrupción DMA
DMA1CONbits.CHEN = 1;// Habilitar canal DMA

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-42
© 2008 Microchip Technology Inc.
Ejemplo 22-11: Código para DCI y DMA con operación ping-pong continua 
(Continuación)
Si se selecciona el modo One-Shot mientras el DMA está funcionando en modo Ping-Pong, el DMA responde
reiniciando para apuntar al búfer secundario después de transferir el búfer primario y luego transfiere
el buffer secundario. Sin embargo, no se producirán transferencias en bloque posteriores porque la DMA
El canal se desactiva solo. La Figura 22-18 ilustra la transferencia de datos One-Shot en modo Ping-Pong.
Configurar el controlador de interrupciones DMA:
void __attribute__((__interrupt__)) _DMA0Interrupt(void)
{
   static unsigned int TxBufferCount = 0;// Mantener registro de qué buffer 
// tiene datos RX
   si(BufferCount == 0)
   {
/* Notifica a la aplicación que se ha transmitido TxBufferA */
   }
   otra cosa
   {
/* Notifica a la aplicación que se ha transmitido TxBufferB */
   }
   Conteo de búfer ^= 1;
   IFS0bits.DMA0IF = 0;
// Borrar el indicador de interrupción DMA0;
}
void __attribute__((__interrupt__)) _DMA1Interrupt(void)
{
   estático sin signo int RxBufferCount = 0; // Mantener registro de qué buffer 
// tiene datos RX
   si(BufferCount == 0)
   {
/* Notificar a la aplicación que se ha recibido RxBufferA */
   }
   otra cosa
   {
/* Notificar a la aplicación que se ha recibido RxBufferB */ }
   Conteo de búfer ^= 1;
   IFS0bits.DMA1IF = 0;
// Borrar el indicador de interrupción DMA1
}
Habilitar DCI:
/* Forzar las primeras dos palabras para completar el búfer de TX/desplazar el registro */
DMA0REQbits.FORCE = 1;
mientras(DMA0REQbits.FORCE == 1);
    
DMA0REQbits.FORCE = 1;
mientras(DMA0REQbits.FORCE == 1);
DCICON1bits.DCIEN = 1;
// Habilitar DCI

© 2008 Microchip Technology Inc.
DS70182B-página 22-43
Sección 22. Acceso directo a memoria (DMA)
DMA
22
Figura 22-18:
Transferencia de datos de un solo bloque en modo ping-pong
22.6.10
Modo de transferencia manual
Para los periféricos que envían datos a la DPSRAM utilizando el controlador DMA, los datos DMA
La transferencia comienza automáticamente después de que se inicializan el canal DMA y el periférico. cuando el
El periférico está listo para mover datos a la DPSRAM, emite una solicitud DMA. Si los datos también necesitan
enviarse al periférico en este momento, la misma solicitud DMA se puede utilizar para activar otro
canal para leer datos de DPSRAM y escribirlos en el periférico.
Por otro lado, si la aplicación sólo necesita enviar datos a un periférico (desde una DPSRAM
buffer) puede ser necesaria una carga de datos inicial (manual) en el periférico para iniciar el proceso (consulte
22.7 “Inicio de la transferencia DMA”). Este proceso podría iniciarse con software convencional.
Sin embargo, un enfoque más conveniente es simplemente imitar la solicitud DMA del canal estableciendo un
bit dentro del canal DMA seleccionado. El canal DMA procesa la solicitud forzada como lo haría
cualquier otra solicitud y transfiere el primer elemento de datos para iniciar la secuencia. Cuando el periférico
está listo para el siguiente dato, envía una solicitud DMA normal y el DMA envía el siguiente
elemento de datos. Este proceso se ilustra en la Figura 22-19.
Se puede crear una solicitud DMA manual configurando el bit FORCE en el canal DMA x IRQ
Seleccione el registro (DMAxREQ). Una vez establecido, la aplicación del usuario no puede borrar el bit FORCE.
Debe borrarse mediante hardware cuando se complete la transferencia DMA forzada. Dependiendo de cuando
Cuando el bit FORCE está activado, se aplican estas condiciones especiales:
• Establecer el bit FORCE mientras la transferencia DMA está en curso no tiene ningún efecto y se ignora.
• Configurar el bit FORCE mientras se configura el canal x (es decir, configurar el bit FORCE 
durante la misma escritura que configura el canal DMA) puede resultar en un comportamiento impredecible 
y debe evitarse.
• Un intento de establecer el bit FORCE mientras está pendiente una solicitud de interrupción periférica (para este 
canal) se descarta a favor de la solicitud basada en interrupciones. Sin embargo, se produce una condición de error. 
generado configurando tanto el bit de bandera de colisión de escritura DMA RAM (XWCOLx) como el 
Bit de bandera de colisión de escritura periférica (PWCOLx) en el estado 0 del controlador DMA (DMACS0) 
registrarse. Consulte 22.10 “Colisiones de escritura de datos” para obtener más detalles.
&_DMA_BASE
Transferencia #1
Transferencia #2
Transferencia #3
Transferencia #n
CONTAR++
&_DMA_BASE+DMAxSTA
CONTAR=0
CONTAR = DMAxCNT+1
Transferencia en bloque de CPU
IRQ completa
Transferencia #1
Transferencia #2
Transferencia #3
Transferencia #n
CONTAR++
&_DMA_BASE+DMAxSTB
CONTAR = DMAxCNT+1
Transferencia en bloque de CPU IRQ completa
Deshabilitar el canal DMA
Tampón A (primario)
Búfer B (Secundario)

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-44
© 2008 Microchip Technology Inc.
Figura 22-19:
Transferencia de datos iniciada en modo manual
22.6.11
Modo de escritura de datos nulos
El modo de escritura de datos nulos es el más útil en aplicaciones en las que la recepción secuencial de datos es
requerido sin ninguna transmisión de datos como SPI.
El SPI es esencialmente un registro de desplazamiento simple, que registra la entrada y salida de un bit de datos para cada período de reloj.
Sin embargo, surge una situación inusual cuando el SPI está configurado en modo Maestro (es decir, cuando el
SPI será la fuente del reloj), pero sólo los datos recibidos son de interés. En este caso, algo
debe escribirse en el registro de datos SPI para iniciar el reloj de datos SPI y recibir el
datos externos.
Sería posible asignar dos canales DMA, uno para recepción de datos y otro para simplemente
introduzca datos nulos o cero en el SPI. Sin embargo, una solución más eficiente es utilizar un DMA Null Data
Modo de escritura que escribe automáticamente un valor nulo en el registro de datos SPI después de cada elemento de datos
ha sido recibido y transferido por el canal DMA configurado para lecturas de datos periféricos.
Si el bit de selección de modo de escritura periférica de datos nulos (NULLW) está configurado en el control DMA Channel x
(DMAxCON), y el canal DMA está configurado para leer desde el periférico, entonces el
El canal DMA también ejecuta una escritura nula (todo ceros) en la dirección del periférico en el mismo ciclo.
como se leen los datos periféricos. Esta escritura se produce a través del bus periférico al mismo tiempo que la
(datos) escribir en la DPSRAM (a través del bus DPSRAM). La Figura 22-20 ilustra este modo.
Durante el funcionamiento normal en este modo, la escritura de datos nulos sólo puede ocurrir en respuesta a una
Solicitud de DMA periférica (es decir, después de que los datos se hayan recibido y estén disponibles para su transferencia). una inicial
Se requiere la escritura de la CPU en el periférico para iniciar la recepción de la primera palabra, después de lo cual el DMA
se encarga de todas las escrituras de datos periféricos (nulos) posteriores. Es decir, la escritura nula de la CPU inicia el
SPI (maestro) enviando/recibiendo datos que a su vez eventualmente genera una solicitud DMA para mover
los datos recién recibidos.
Alternativamente, se podría utilizar una transferencia DMA forzada para "iniciar" el proceso. Sin embargo, esto será
También incluye una lectura periférica redundante (datos no válidos) y un puntero DPSRAM asociado.
ajuste, que debe tenerse en cuenta.
&_DMA_BASE
&_DMA_BASE + DMA3STA 
&_DMA_BASE + DMA3STA + 1
&_DMA_BASE + DMA3STA + 2
Datos 0
periférico 
1
DMA
canal 6
Primera transferencia forzada
un
&_DMA_BASE
&_DMA_BASE + DMA3STA 
&_DMA_BASE + DMA3STA + 1
&_DMA_BASE + DMA3STA + 2
Datos 0
Datos 1
periférico 
1
DMA
canal 6
Transferencias posteriores solicitadas por periférico
b
CPU escribir en
FUERZA poco
Datos 1
Datos 2
Datos 2
Transferencia 1
Transferencia 2
Transferencia 3
Solicitud de DMA

© 2008 Microchip Technology Inc.
DS70182B-página 22-45
Sección 22. Acceso directo a memoria (DMA)
DMA
22
Figura 22-20:
Transferencia de datos con modo de escritura de datos nulos
Ejemplo 22-12: SPI y DMA con modo de escritura de datos nulos
&_DMA_BASE
&_DMA_BASE + DMA3STA 
&_DMA_BASE + DMA3STA + 1
&_DMA_BASE + DMA3STA + 2
Datos 0
Datos 1
SPI 
DMA
Canal 1
Datos 2
Transferencia 2
Transferencia 3
Transferencia 1
Texas
RX
Escrituras de datos nulos 
generado por DMA
Transferencia de datos
Configure SPI para el modo Maestro:
SPI1CON1bits.MODE16 = 1;
// La comunicación es a nivel de palabra (16 bits)
SPI1CON1bits.MSTEN = 1;
// Modo maestro habilitado
SPI1STATbits.SPIEN = 1;
// Habilitar módulo SPI
Configure el canal DMA 1 para el modo de escritura de datos nulos:
unsigned int BufferA[16] __attribute__((espacio(dma)));
unsigned int BufferB[16] __attribute__((espacio(dma)));
DMA1CON = 0x0802;
// Escritura nula, continua, ping-pong,
// Post-Incremento, Periférico a RAM
DMA1CNT = 15;
// Transfiere 16 palabras a la vez
DMA1REQ = 0x000A;
//Selecciona SPI1 como fuente de solicitud DMA
DMA1STA = __builtin_dmaoffset(BufferA);
DMA1STB = __builtin_dmaoffset(BufferB);
DMA1PAD = (int volátil sin signo) &SPI1BUF;
IFS0bits.DMA1IF = 0;
IEC0bits.DMA1IE = 1;
// Habilitar interrupción DMA
DMA1CONbits.CHEN = 1;
// Habilitar canal DMA
DMA1REQbits.FORCE = 1;
// Forzar la primera palabra después de habilitar SPI
Configurar el controlador de interrupciones DMA:
void __attribute__((__interrupt__)) _DMA1Interrupt(void)
{
   estático sin signo int BufferCount = 0;
// Mantener registro de qué buffer 
// contiene datos RX
   si(BufferCount == 0)
   {
ProcessRxData(BufferA); 
// Procesar los datos SPI recibidos en 
// DMA RAM Búfer primario
   }
   otra cosa
   {
ProcessRxData(BufferB); 
// Procesar los datos SPI recibidos en 
// DMA RAM Búfer secundario
   }
   Conteo de búfer ^= 1;
   IFS0bits.DMA1IF = 0; 
// Borrar el indicador de interrupción DMA1
}

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-46
© 2008 Microchip Technology Inc.
22.7
 INICIANDO LA TRANSFERENCIA DMA
Antes de que puedan comenzar las transferencias DMA, el canal DMA debe habilitarse configurando el bit CHEN en
'1' en el registro DMAxCON. Cuando el canal DMA está activo, se puede reinicializar deshabilitando
este canal (CHEN = 0), seguido de volver a habilitarlo (CHEN = 1). Este proceso restablece el DMA
transfiere el recuento a cero y establece el búfer DMA activo en el búfer primario.
Cuando el canal DMA y el periférico se inicializan correctamente, la transferencia DMA comienza tan pronto como
ya que el periférico está listo para mover datos y emite una solicitud DMA. Sin embargo, algunos periféricos
puede no emitir una solicitud de DMA (y por lo tanto no iniciará la transferencia de DMA) hasta que se cumplan ciertos
existen condiciones. En estos casos, una combinación de diferentes modos y procedimientos DMA puede
Se debe aplicar para iniciar la transferencia DMA:
22.7.1
Inicio de DMA con la interfaz periférica serie (SPI)
El inicio de la transferencia DMA hacia/desde el periférico SPI depende de la dirección de datos SPI y del esclavo.
o modo Maestro:
• TX solo en modo Maestro: en esta configuración, no se emite ninguna solicitud DMA hasta la primera 
Se envía un bloque de datos SPI. Para iniciar transferencias DMA, la aplicación del usuario primero debe enviar datos 
usando el modo de transferencia manual DMA, o primero debe escribir datos en el búfer SPI 
(SPIxBUF) independientemente de la DMA.
• RX solo en modo Maestro: en esta configuración, no se emite ninguna solicitud DMA hasta la primera 
Se recibe un bloque de datos SPI. Sin embargo, en modo Maestro, no se reciben datos hasta que SPI 
transmite primero. Para iniciar transferencias DMA, la aplicación de usuario debe utilizar DMA Null Data Write 
e inicie el modo de transferencia manual DMA.
• RX y TX en modo maestro: en esta configuración, no se emite ninguna solicitud DMA hasta la primera 
Se recibe un bloque de datos SPI. Sin embargo, en el modo Maestro, no se reciben datos hasta que el SPI 
lo transmite. Para iniciar transferencias DMA, la aplicación de usuario primero debe enviar datos utilizando el 
Modo de transferencia manual DMA, o primero debe escribir datos en el búfer SPI (SPIxBUF) 
independientemente de la DMA.
• TX solo en modo esclavo: en esta configuración, no se emite ninguna solicitud DMA hasta la primera 
Se recibe un bloque de datos SPI. Para iniciar transferencias DMA, la aplicación del usuario primero debe enviar 
datos usando el modo de transferencia manual DMA, o primero debe escribir datos en el búfer SPI 
(SPIxBUF) independientemente de la DMA.
• RX solo en modo esclavo: esta configuración genera una solicitud DMA tan pronto como se activa la primera 
Los datos SPI han llegado, por lo que el usuario no necesita realizar pasos especiales para iniciar DMA 
transferencia.
• RX y TX en modo esclavo: en esta configuración, no se emite ninguna solicitud DMA hasta el primer 
Se recibe el bloque de datos SPI. Para iniciar transferencias DMA, la aplicación del usuario primero debe enviar 
datos utilizando el modo de transferencia manual DMA, o primero debe escribir datos en el búfer SPI 
(SPIxBUF) independientemente de la DMA.
22.7.2
Inicio de DMA con la interfaz del convertidor de datos (DCI)
A diferencia de otros periféricos seriales, el DCI comienza a transmitir tan pronto como se habilita (asumiendo que
es el Maestro). Alimenta constantemente cuadros de datos sincrónicos al códec externo al que está conectado.
conectado. Antes de habilitar la DCI debes:
• Configure el DCI como se describe en 22.5.2 “Configuración de configuración de periféricos”
• Si está conectado a un códec estéreo, use el modo de transferencia manual DMA para iniciar los dos primeros datos 
transferencias. 
- Configure el bit FORCE en el registro DMaxREQ para transferir la muestra del canal izquierdo DCI.
- Configure el bit FORCE por segunda vez para transferir la muestra del canal derecho DCI.
Una vez completados estos pasos, habilite el periférico DCI (consulte el Ejemplo 22-11).

© 2008 Microchip Technology Inc.
DS70182B-página 22-47
Sección 22. Acceso directo a memoria (DMA)
DMA
22
22.7.3
Iniciando DMA con la UART
El receptor UART emite una solicitud DMA tan pronto como se reciben los datos. No es necesario realizar pasos especiales
La aplicación del usuario debe tomar los pasos necesarios para iniciar la transferencia DMA. El transmisor UART emite un DMA
Solicite tan pronto como la UART y el transmisor estén habilitados. Esto significa que el canal DMA
y los buffers deben inicializarse y habilitarse antes que el UART y el transmisor.
Asegúrese de que la UART esté configurada como se describe en 22.5.2 "Configuración de configuración de periféricos"
(Tabla 22-2).
Alternativamente, el UART y el transmisor UART se pueden habilitar antes de que se active el canal DMA.
habilitado. En este caso, la solicitud DMA del transmisor UART se perderá y la aplicación del usuario
debe emitir una solicitud DMA para iniciar transferencias DMA configurando el bit FORCE en DMAxREQ 
registrarse.

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-48
© 2008 Microchip Technology Inc.
22.8
 ARBITRAJE Y SOBRECOSTOS DEL CANAL DMA
Cada canal DMA tiene una prioridad fija. El canal 0 es el más alto y el canal 7 es el más bajo.
Cuando la fuente solicita una transferencia DMA, la solicitud es bloqueada por el DMA asociado.
canal. El responsable del tratamiento de la DMA actúa como árbitro. Si no hay ninguna otra transferencia en curso o pendiente,
el controlador otorga recursos de bus al canal DMA solicitante. El controlador DMA garantiza
que a ningún otro canal DMA se le concede ningún recurso hasta que el canal DMA actual se complete
su funcionamiento.
Si llegan o están pendientes varias solicitudes de DMA, la lógica de prioridad dentro del controlador DMA otorga
recursos al canal DMA de mayor prioridad para completar su operación. Todos los demás DMA
Las solicitudes permanecen pendientes hasta que se complete la transferencia DMA seleccionada. Si otra solicitud de DMA
llega mientras la transferencia de DMA actual está en curso, también tiene prioridad con cualquier DMA pendiente
solicitudes, asegurando que la solicitud de mayor prioridad siempre sea atendida después del DMA actual
la transferencia se ha completado.
Como los canales DMA tienen prioridad, es posible que una solicitud DMA no se reciba inmediatamente.
revisado y quedará pendiente. La solicitud permanecerá pendiente hasta que todos los de mayor prioridad
Los canales han sido atendidos. Se produce un desbordamiento de datos, si llega otra interrupción antes del DMA
El controlador ha borrado la solicitud DMA original y la interrupción es del mismo tipo que la pendiente.
interrumpir.
Un desbordamiento de datos se define como la condición en la que han llegado nuevos datos a un búfer de datos periférico.
antes de que la DMA pudiera mover los datos anteriores. Algunos periféricos preparados para DMA pueden detectar datos
se desborda y emite una interrupción de la CPU (si la interrupción de error periférico correspondiente está habilitada),
como se muestra en la Tabla 22-5.
Tabla 22-5:
Manejo de saturación por periféricos listos para DMA
Periférico listo para DMA
Manejo de exceso de datos
Interfaz periférica serie (SPI)
Los datos en espera de ser movidos por el canal DMA no se 
sobrescrito por datos entrantes adicionales. posterior 
Los datos entrantes se pierden y el desbordamiento de recepción SPI 
El bit (SPIROV) se establece en el registro Estado SPI (SPIXSTAT).
ter. También se genera la interrupción de fallo SPIx si el SPI 
El bit de habilitación de interrupción de error (SPIxEIE) está establecido en el
rupt Enable Control (IECx) registro en la interrupción 
controlador. 
UART
Los datos en espera de ser movidos por el canal DMA no se 
sobrescrito por datos entrantes adicionales. posterior 
Los datos entrantes se pierden y el bit de error de desbordamiento (OERR) 
se establece en el registro de estado UART (UxSTA). Además, el 
La interrupción de error UARTx se genera si el error UART 
El bit de habilitación de interrupción (UxEIE) está establecido en la configuración de interrupción. 
Habilite el registro de control (IECx) en el controlador de interrupciones.
Interfaz de convertidor de datos (DCI)
Los datos en espera de ser movidos por el canal DMA están sobrepasados.
escrito por datos entrantes adicionales y el Recibir 
El bit de desbordamiento (ROV) está configurado en el estado DCI (DCISTAT) 
registrarse. También se genera la interrupción por fallo DCI si el 
El bit de habilitación de interrupción de error DCI (DCIEIE) está establecido en el 
Registro de control de habilitación de interrupción (IEC0) en la interrupción 
controlador.
Analógico a digital de 10 bits/12 bits 
Convertidor (ADC)
Los datos en espera de ser movidos por el canal DMA están sobrepasados.
escrito por datos entrantes adicionales. la invasión 
El ADC no detecta la condición.
Otros periféricos listos para DMA
No puede producirse un exceso de datos.

© 2008 Microchip Technology Inc.
DS70182B-página 22-49
Sección 22. Acceso directo a memoria (DMA)
DMA
22
Los excesos de datos solo son detectables en el hardware cuando el DMA mueve datos desde un periférico
a DPSRAM. Transferencias de datos DMA desde DPSRAM a un periférico (basado en, por ejemplo, un buffer
interrupción vacía) siempre se ejecutará. Cualquier exceso de datos DPSRAM resultante debe ser
detectado mediante software. La solicitud DMA duplicada se ignora y la solicitud pendiente permanece
pendiente. Como de costumbre, el canal DMA borra la solicitud DMA cuando finalmente se realiza la transferencia.
completado. Si la CPU no interviene mientras tanto, los datos transferidos serán los últimos
(sobrepasados) y los datos anteriores se perderán.
La aplicación de usuario puede manejar un error de desbordamiento de diferentes maneras, dependiendo de la naturaleza del
la fuente de datos. La recuperación de datos y la resincronización del DMAC con su fuente/sumidero de datos es una
tarea que depende en gran medida de la aplicación. Para la transmisión de datos, como los de un CODEC (a través de
periférico DCI), la aplicación puede ignorar los datos perdidos. Después de solucionar el origen del problema.
(si es posible), el controlador de interrupciones DMA debe intentar resincronizar el DMAC y el DCI para que
esos datos se vuelven a almacenar correctamente en el buffer. La aplicación de usuario debe reaccionar lo suficientemente rápido para evitar cualquier
se produzcan más sobrecostos. 
En el momento en que se ingresa la interrupción de desbordamiento periférico, la solicitud DMA pendiente habrá
ya movió el valor de datos desbordados a la dirección donde deberían haber ido los datos perdidos. eso
Los datos se pueden mover a su dirección correcta y se puede insertar un valor de datos nulo en los datos faltantes.
ranura. La dirección DPSRAM del canal se puede ajustar en consecuencia. DMA posterior
Las solicitudes al canal con falla luego inician las transferencias normalmente a la DPSRAM corregida.
dirección. Para aplicaciones donde los datos no se pueden perder, la interrupción de desbordamiento periférico necesitará
para cancelar la transferencia en bloque actual, reinicialice el canal DMA y solicite un reenvío de datos antes
está perdido.
22.9
 SOPORTE DE DEPURACIÓN
Para mejorar la visibilidad del usuario sobre el funcionamiento de DMA durante la depuración, el controlador DMA incluye
varios registros de estado que pueden proporcionar información sobre qué canal DMA se ejecutó por última vez
(bits LSTCH<3:0> en el registro DMACS1), a qué dirección DPSRAM se estaba accediendo
(DSADR<15:0> bits en el registro DSADR) y desde qué búfer (bits PPSTx en el registro DMACS1
registrarse).

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-50
© 2008 Microchip Technology Inc.
22.10
 COLISIONES DE ESCRITURA DE DATOS
La CPU y el canal DMA pueden leer o leer/escribir simultáneamente en cualquier DPSRAM o
Registro de datos periféricos listo para DMA. La única restricción es que la CPU y el canal DMA deben
no escribir simultáneamente a la misma dirección. En circunstancias normales, esta situación debería
nunca surja. Sin embargo, si por alguna razón lo hace, será detectado y marcado, y un DMA
Se iniciará la captura de fallas. También se permitirá que la escritura de la CPU tenga prioridad, aunque eso es principalmente
para proporcionar un comportamiento predecible y, por lo demás, tiene pocas consecuencias prácticas.
También está permitido que el canal DMA escriba en una ubicación durante el mismo ciclo de bus que
la CPU lo lee y viceversa. Sin embargo, cabe señalar que las lecturas resultantes son de
los datos antiguos, no los datos escritos durante ese ciclo de bus. También tenga en cuenta que esta situación se considera
funcionamiento normal y no requiere la adopción de ninguna medida especial. 
En caso de una escritura simultánea en la misma dirección DPSRAM por parte de la CPU y DMA
canal, el bit XWCOLx se establece en el registro Estado 0 del controlador DMA (DMACS0). en el caso
de una escritura simultánea en la misma dirección periférica por la CPU y el canal DMA, el
El bit PWCOLx se establece en el registro de estado 0 del controlador DMA (DMACS0). Todos los indicadores de estado de colisión
se combinan lógicamente con OR para generar una trampa de falla DMAC común. El XWCOLx y
Los indicadores PWCOLx se borran automáticamente cuando la aplicación del usuario borra el estado de error DMAC
bit (DMACERR) en el registro del controlador de interrupciones (INTCON1).
Las solicitudes DMA posteriores a un canal que tiene un error de colisión de escritura se ignoran mientras el
XWCOLx o PWCOLx permanecen configurados.
En condiciones de colisión de escritura, se podrían configurar XWCOLx o PWCOLx debido a una colisión de escritura.
pero no ambos. La configuración de ambas banderas se utiliza como un medio único para marcar un evento de activación manual poco común
error sin agregar más bits de estado (consulte 22.6.10 “Modo de transferencia manual”).
El ejemplo 22-13 ilustra el manejo de capturas del controlador DMA con el canal 0 de DMA transfiriendo datos.
desde la DPSRAM al periférico (UART), y el canal DMA 1 transfiriendo datos desde el
periférico (ADC) a la DPSRAM.
Ejemplo 22-13: Manejo de trampas del controlador DMA:
void __attribute__((__interrupt__)) _DMACError(void)
{
estático sin firmar int ErrorLocation;
// Ubicación del error de colisión de escritura periférica
si (DMACS0 y 0x0100)
{
    
UbicaciónError = DMA0STA;
}
// Ubicación del error de colisión de escritura de DMA RAM
si (DMACS0 y 0x0002)
{
UbicaciónError = DMA1STA;
}
DMACS0 = 0;
//Borrar indicador de colisión de escritura
INTCON1bits.DMACERR = 0;
//Borrar bandera de trampa
}

© 2008 Microchip Technology Inc.
DS70182B-página 22-51
Sección 22. Acceso directo a memoria (DMA)
DMA
22
22.11
 FUNCIONAMIENTO EN MODOS DE AHORRO DE ENERGÍA
22.11.1
Modo de suspensión
El DMA está desactivado durante el modo de ahorro de energía en suspensión. Antes de ingresar al modo de suspensión, es
Se recomienda (aunque no es esencial) que se permita a todos los canales DMA completar el
transferencia en bloque que está actualmente en curso, o ser deshabilitada.
22.11.2
Modo inactivo
El DMA es un segundo bus maestro dentro del sistema y, por lo tanto, puede continuar transfiriendo datos.
cuando la CPU ha entrado en el modo de ahorro de energía inactivo. Siempre que el periférico esté siendo reparado
por el canal DMA está configurado para funcionar durante el modo inactivo, los datos pueden transferirse y
del periférico y DPSRAM. Cuando se completa la transferencia en bloque, el canal DMA emite
una interrupción (si está habilitada) y despierta la CPU. Luego, la CPU ejecuta el controlador del servicio de interrupción.
Cada periférico incluye un bit de control de parada en reposo. Cuando se establece, este bit de control desactiva el
periférico mientras la CPU está en modo inactivo. Si el DMAC se utiliza para transferir datos dentro y/o fuera
del periférico, activar la función Detener en inactivo dentro del periférico, de hecho, también desactivará
el canal DMA asociado con el periférico.

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-52
© 2008 Microchip Technology Inc.
22.12
 CONSEJOS DE DISEÑO
22.12.1
Interfaz de DMA con DCI
Cuando el DCI tiene múltiples canales de audio por cuadro (por ejemplo, canales izquierdo y derecho de
un códec estéreo), todas las muestras se entrelazan secuencialmente y se transfieren por el canal DMA como
se muestra en la Figura 22-21.
Sin embargo, normalmente la aplicación de usuario prefiere los datos por canal, lo que significa
que el programa debe proporcionar un algoritmo adicional para ordenar los datos transferidos o indexar
saltando datos no deseados. Cualquiera de los dos enfoques requiere código adicional y da como resultado más
tiempo de ejecución.
El DCI no admite direccionamiento indirecto de periféricos. Sin embargo, todavía es posible ensamblar
los datos por canal de audio con una configuración DCI especial combinada con dos canales DMA.
Cuando los bits de control de longitud del búfer (BLEN<1:0>) en el registro DCI Control 2 (DCICON2) están
configurado en '01' (en lugar de '00'), y se utilizan dos canales DMA para transferir los datos recibidos desde el
DCI a DPSRAM, los datos de audio recibidos se ordenan por canal. En este caso, cuando el DCI
genera una solicitud DMA y va a ambos canales DMA cada vez que se almacenan en el búfer dos palabras (una
muestra derecha y una muestra izquierda). Cuando se produce la solicitud de DMA, un canal DMA transfiere
datos del registro DCI RX Buffer 0 (RXBUF0), mientras que el otro canal DMA transfiere datos
del registro DCI RX Buffer 1 (RXBUF1). De hecho, los datos transferidos se clasifican por audio.
canal, como se muestra en la Figura 22-22.
Para que este ejemplo funcione, el canal DMA 1 inicializa el registro DMA1PAD en RXBUF1.
dirección (en lugar de la dirección RXBUF0 como se indica en 22.5.1 “Canal DMA a periférico
Configuración de la asociación”).
Figura 22-21:
Transferencia de datos típica para DCI
DMA Canal 0
Transferencia 1
Transferencia 6
DCI
DMA 
Canal izquierdo 
Muestra 0
Canal derecho 
Muestra 0
Canal izquierdo 
Muestra1
Canal derecho 
Muestra 1
Canal izquierdo 
Muestra 2
Canal derecho 
Muestra 2
&_DMA_BASE
Solicitar
Datos

© 2008 Microchip Technology Inc.
DS70182B-página 22-53
Sección 22. Acceso directo a memoria (DMA)
DMA
22
Figura 22-22:
Clasificación de datos de canales DCI con dos canales DMA
DMA Canal 0
Datos
Muestra 0
Muestra 1
Muestra 2
:
Muestra 0
:
:
Muestra 1
Muestra 2
:
:
:
:
:
:
:
Transferencia 1
Transferencia 5
Transferencia 2
Transferencia 3
Transferencia 4
Transferencia 8
Canal de audio derecho
Canal de audio izquierdo
DMA Canal 1
DCI
RxBUF0
RxBUF1
Solicitud de DMA
Datos
DMA0PAD = &RxBUF0
DMA1PAD = &RxBUF1

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-54
© 2008 Microchip Technology Inc.
22.13
 REGISTRAR MAPAS
Tabla 22-6:
Mapa de Registro DMA
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
Leyenda:
— = no implementado, leído como '0'. Los valores de reinicio se muestran en hexadecimal.

© 2008 Microchip Technology Inc.
DS70182B-página 22-55
Sección 22. Acceso directo a memoria (DMA)
DMA
22
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
INTCON1
0080
NSTDIS
—
—
—
—
—
—
—
—
—
DMACERR
—
—
—
—
—
0000
IFS0
0084
—
DMA1IF
—
—
—
—
—
—
—
—
—
DMA0IF
—
—
—
—
0000
IFS1
0086
—
—
—
—
—
—
—
DMA2IF
—
—
—
—
—
—
—
—
0000
IFS2
0088
—
DMA4IF
—
—
—
—
—
—
—
—
—
DMA3IF
—
—
—
—
0000
IFS3
008A
—
—
DMA5IF
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
—
—
DMA7IF
DMA6IF
—
—
—
—
0000
IEC0
0094
—
DMA1IE
—
—
—
—
—
—
—
—
—
DMA0IE
—
—
—
—
0000
IEC1
0096
—
—
—
—
—
—
—
DMA2IE
—
—
—
—
—
—
—
—
0000
IEC2
0098
—
DMA4IE
—
—
—
—
—
—
—
—
—
DMA3IE
—
—
—
—
0000
IEC3
009A
—
—
DMA5IE
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
—
—
DMA7IE
DMA6IE
—
—
—
—
0000
IPC1
00A6
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
DMA0IP<2:0>
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
—
—
—
—
—
—
—
4444
IPC6
00B0
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
DMA2IP<2:0>
4444
IPC9
00B6
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
DMA3IP<2:0>
4444
Tabla 22-6:
Mapa de registro DMA (continuación)
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

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-56
© 2008 Microchip Technology Inc.
CIP11
00BA
—
—
—
—
—
DMA4IP<2:0>
—
—
—
—
—
—
—
—
4444
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
—
—
—
4444
CIP17
00C6
—
—
—
—
—
—
—
—
—
DMA7IP<2:0>
—
DMA6IP<2:0>
4444
Tabla 22-6:
Mapa de registro DMA (continuación)
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

© 2008 Microchip Technology Inc.
DS70182B-página 22-57
Sección 22. Acceso directo a memoria (DMA)
DMA
22
22.14
 NOTAS DE APLICACIÓN RELACIONADAS
Esta sección enumera notas de aplicación relacionadas con el uso de Direct Memory Access. Estos
Es posible que las notas de aplicación no estén escritas específicamente para la familia de productos dsPIC33F, pero el
Los conceptos son pertinentes y podrían usarse con modificaciones y posibles limitaciones. la corriente
Las notas de aplicación relacionadas con el módulo DMA incluyen:
Título
Nota de aplicación #
No hay notas de aplicación relacionadas en este momento.
Nota:
Visite el sitio web de Microchip (www.microchip.com) para obtener información adicional.
Notas de aplicación y ejemplos de código para la familia de dispositivos dsPIC33F.

Manual de referencia de la familia dsPIC33F
DS70182B-página 22-58
© 2008 Microchip Technology Inc.
22.15
 HISTORIAL DE REVISIONES
Revisión A (diciembre de 2006)
Esta es la publicación inicial de este documento.
Revisión B (julio de 2008)
Esta revisión incorpora las siguientes actualizaciones de contenido:
• Cifras:
- Transferencia de datos desde ADC con direccionamiento indirecto de registro (ver Figura 22-11).
- Transferencia de datos desde ADC con direccionamiento indirecto de periféricos (consulte la Figura 22-12).
• Se incorporan correcciones menores adicionales, como actualizaciones de idioma y formato. 
todo el documento.
