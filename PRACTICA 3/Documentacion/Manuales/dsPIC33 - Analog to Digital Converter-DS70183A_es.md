# Traducción de dsPIC33 - Analog to Digital Converter-DS70183A.pdf

© 2006 Microchip Technology Inc.
DS70183A-página 16-1
CAD
16
Sección 16. Convertidor analógico a digital (ADC)
DESTACADOS
Esta sección del manual contiene los siguientes temas principales:
16.1
Introducción ................................................................................................................16-2
16.2
Registros de control ................................................................................................16-4
16.3
Terminología A/D y secuencia de conversión ........................................................ 16-14
16.4
Configuración del módulo ADC ........................................................................................ 16-16
16.5
Selección de la fuente de referencia de voltaje ......................................................... 16-16
16.6
Selección del reloj de conversión A/D................................................................ 16-17
16.7
Selección de entradas analógicas para muestreo ................................................................ 16-18
16.8
Habilitación del módulo ................................................................................................ 16-20
16.9
Especificación del control de muestra/conversión ......................................................... 16-20
16.10 Cómo iniciar el muestreo ................................................................................................ 16-21
16.11 Cómo detener el muestreo e iniciar las conversiones ................................................. 16-22
16.12 Control de la operación de muestra/conversión................................................ 16-32
16.13 Especificación del almacenamiento en búfer de resultados de conversión................................................. 16-33
16.14 Ejemplos de secuencia de conversión...................................................................16-37
16.15 Requisitos de muestreo A/D................................................................................ 16-49
16.16 Lectura del búfer de resultados del ADC ........................................................................ 16-50
16.17 Función de transferencia (modo de 10 bits).................................................................... 16-52
16.18 Función de transferencia (modo de 12 bits).................................................................... 16-53
16.19 Precisión/Error del ADC................................................................................................ 16-54
16.20 Consideraciones de conexión................................................................................. 16-54
16.21 Ejemplos de código................................................................................................... 16-54
16.22 Funcionamiento durante los modos de suspensión e inactivo...................................................16-61
16.23 Efectos de un reinicio................................................................................................... 16-62
16.24 Registros de funciones especiales asociados con el ADC................................................ 16-62
16.25 Consejos de diseño ................................................................................................ 16-64
16.26 Notas de aplicación relacionadas................................................................................16-65
16.27 Historial de revisiones................................................................................................ 16-66

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-2
© 2006 Microchip Technology Inc.
16.1
 INTRODUCCIÓN   
Los dispositivos de la familia dsPIC33F tienen hasta 32 canales de entrada A/D. Estos dispositivos también tienen hasta
dos módulos ADC (ADCx, donde x = 1 o 2), cada uno con su propio conjunto de registros de funciones especiales
(SFR).
El bit de modo de operación (AD12B) de 10 o 12 bits en el registro ADCx Control 1 (ADxCON1)
permite que cada uno de los módulos ADC sea configurado por la aplicación de usuario como 10 bits, 4
ADC de muestra/retención (S/H) (configuración predeterminada) o un ADC de 12 bits y 1 muestra/retención. 
La configuración ADC de 10 bits (AD12B = 0) tiene las siguientes características clave:
• Conversión de aproximación sucesiva (SAR)
• Velocidades de conversión de hasta 1,1 Msps
• Hasta 32 pines de entrada analógica
• Pines de entrada de referencia de voltaje externo
• Muestreo simultáneo de hasta cuatro pines de entrada analógica
• Modo de búsqueda automática de canales
• Fuente de activación de conversión seleccionable
• Modos de llenado de búfer seleccionables
• Compatibilidad con DMA, incluido el direccionamiento indirecto de periféricos
• Cuatro opciones de alineación de resultados (con/sin signo, fraccionario/entero)
• Operación durante los modos de suspensión e inactividad de la CPU
Dependiendo de la distribución de pines del dispositivo particular, el ADC puede tener hasta 32 pines de entrada analógica, diseñados
denominados AN0 a AN31. Además, hay dos pines de entrada analógica para referencia de voltaje externo.
conexiones de potencia. Estas entradas de referencia de voltaje se pueden compartir con otros pines de entrada analógica.
El número real de pines de entrada analógica y la configuración de entrada de referencia de voltaje externo
Depende del dispositivo específico. Consulte la hoja de datos del dispositivo para obtener más detalles. 
Las entradas analógicas están multiplexadas en cuatro amplificadores Sample/Hold, denominados CH0-CH3.   uno,
Se pueden habilitar dos o cuatro de los amplificadores Sample/Hold para adquirir datos de entrada. el analogo
Los multiplexores de entrada se pueden cambiar entre dos conjuntos de entradas analógicas durante las conversiones. Uni-
Las conversiones diferenciales polares son posibles en todos los canales usando ciertos pines de entrada (ver
Figura 16-1).
Se puede habilitar un modo de exploración de entrada analógica para el amplificador CH0 Sample/Hold. Un control 
El registro especifica qué canales de entrada analógica se incluyen en la secuencia de escaneo.  
El ADC está conectado a un búfer de resultados de una sola palabra. Sin embargo, múltiples resultados de conversión pueden
almacenarse en un búfer DMA RAM sin sobrecarga de CPU. Cada resultado de la conversión se convierte a
uno de los cuatro formatos de salida de 16 bits cuando se lee desde el búfer.
La configuración ADC de 12 bits (AD12B = 1) admite todas las funciones anteriores, excepto:
• En la configuración de 12 bits, se admiten velocidades de conversión de hasta 500 ksps
• Sólo hay un amplificador Sample/Hold en la configuración de 12 bits, por lo que 
No se admite el muestreo de múltiples canales.
Nota:
El módulo ADC debe desactivarse antes de modificar el bit AD12B.

© 2006 Microchip Technology Inc.
DS70183A-página 16-3
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
Figura 16-1:
Diagrama de bloques del ADC   
S/H
+
-
Conversión
Lógica de conversión
VEF+(1)
AVSS
AVDD
CAD
Formato de datos
16 bits
Resultado del CAD
Interfaz de autobús
00000
00101
00111
01001
11110
11111
00001
00010
00011
00100
00110
01000
01010
01011
AN30
AN31
AN8
AN9
AN10
AN11
AN2
AN4
AN7
AN0
AN3
AN1
AN5
CH1(2)
CH2(2)
CH3(2)
CH0
AN5
AN2
AN11
AN8
VREF-
AN4
AN1
AN10
AN7
VREF-
AN3
AN0
AN9
AN6
VREF-
AN1
VREF-
VREF-(1)
Muestra/Secuencia
controlar
muestra
CH0,CH1,
CH2,CH3
Entrada MUX
controlar
Entrada
interruptores
S/H
+
-
S/H
+
-
S/H
+
-
AN6
búfer
Resultado
Nota 1: Las entradas VREF+, VREF- se pueden multiplexar con otras entradas analógicas. Consulte la hoja de datos del dispositivo para obtener más detalles.
2: Los canales 1, 2 y 3 no son aplicables para el modo de operación de 12 bits.
3: El módulo ADC1 puede usar los 32 pines de entrada analógica (AN0-AN31), mientras que ADC2 puede usar solo 16 
pines de entrada analógica (AN0-AN15).
Pines de entrada analógica(3)

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-4
© 2006 Microchip Technology Inc.
16.2
 REGISTROS DE CONTROL
El módulo ADC tiene diez registros de control y estado. Estos registros son:
• ADxCON1: Registro de control ADCx 1(1)
• ADxCON2: Registro de control ADCx 2(1)
• ADxCON3: Registro de control ADCx 3(1)
• ADxCON4: Registro de control ADCx 4(1)
• ADxCHS123: Canal de entrada ADCx 1, 2, 3 Seleccionar registro (1)
• ADxCHS0: Registro de selección del canal 0 de entrada ADCx
• AD1CSSH: Registro alto de selección de escaneo de entrada ADC1
• ADxCSSL: Registro bajo de selección de escaneo de entrada ADCx
• AD1PCFGH: Registro de configuración del puerto ADC1 alto
• ADxPCFGL: Registro de configuración del puerto ADCx bajo
Los registros ADxCON1, ADxCON2 y ADxCON3 controlan el funcionamiento del módulo ADC.
El registro ADxCON4 configura el número de resultados de conversión almacenados en un búfer DMA para cada
entrada analógica en el modo Scatter/Gather. Los registros ADxCHS123 y ADxCHS0 seleccionan el
pines de entrada que se conectarán a los amplificadores Sample/Hold. Los registros ADxPCFGH/L configuran
los pines de entrada analógica como entradas analógicas o como E/S digitales. Los registros ADCSSH/L seleccionan entradas para
ser escaneados secuencialmente.

© 2006 Microchip Technology Inc.
DS70183A-página 16-5
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
    Registro 16-1:
ADxCON1: Registro de control ADCx 1(1)
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
1 =
El módulo ADC está funcionando
0 =
El ADC está apagado
poco 14
No implementado: leído como "0"
poco 13
ADSIDL: bit de parada en modo inactivo
1 = Interrumpir la operación del módulo cuando el dispositivo ingresa al modo inactivo
0 =
Continuar la operación del módulo en modo inactivo
poco 12
ADDMABM: bit de modo de construcción de búfer DMA
1 =
Los buffers DMA se escriben en el orden de conversión. El módulo proporciona una dirección al DMA.
canal que es la misma que la dirección utilizada para el búfer independiente no DMA.
0 =
Los buffers DMA se escriben en modo Scatter/Gather. El módulo proporciona una dirección de dispersión/reunión.
al canal DMA, según el índice de la entrada analógica y el tamaño del búfer DMA.
poco 11
No implementado: leído como "0"
poco 10
AD12B: bit de modo de operación de 10 o 12 bits
1 = operación ADC de 1 canal y 12 bits
0 =
Operación ADC de 10 bits y 4 canales
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
001 = La transición activa en el pin INTx finaliza el muestreo y comienza la conversión
000 = Borrar el bit de muestra finaliza el muestreo y comienza la conversión
poco 4
No implementado: leído como "0"
Nota 1: La 'x' en ADxCON1 y ADCx se refiere a ADC 1 o ADC 2.

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-6
© 2006 Microchip Technology Inc.
poco 3
SIMSAM: Bit de selección de muestra simultánea (solo aplicable cuando CHPS<1:0> = 01 o 1x)
Cuando AD12B = 1, SIMSAM es: U-0, no implementado, leído como '0'
1 =
Muestras CH0, CH1, CH2, CH3 simultáneamente (cuando CHPS<1:0> = 1x); o
Muestras CH0 y CH1 simultáneamente (cuando CHPS<1:0> = 01)
0 =
Muestra múltiples canales individualmente en secuencia
poco 2
ASAM: bit de inicio automático de muestra de ADC
1 = El muestreo comienza inmediatamente después de la última conversión. El bit SAMP se configura automáticamente.
0 =
El muestreo comienza cuando se establece el bit SAMP
poco 1
SAMP: bit de habilitación de muestra ADC
1 =
Los amplificadores ADC Sample/Hold están muestreando
0 =
Los amplificadores ADC Sample/Hold están en espera
Si ASAM = 0, el software puede escribir '1' para comenzar el muestreo. Configurado automáticamente por hardware si ASAM = 1.
Si SSRC = 000, el software puede escribir '0' para finalizar el muestreo e iniciar la conversión. Si SSRC ≠ 000, 
borrado automáticamente por el hardware para finalizar el muestreo e iniciar la conversión.
poco 0
HECHO: bit de estado de conversión de ADC 
1 =
Se completa el ciclo de conversión del ADC.
0 =
La conversión de ADC no se inició o está en curso
Configurado automáticamente por hardware cuando se completa la conversión A/D. El software puede escribir "0" para borrar HECHO
estado (el software no puede escribir '1'). Borrar este bit NO afecta ninguna operación en
progreso. El hardware lo borra automáticamente al inicio de una nueva conversión.
Registro 16-1:
ADxCON1: Registro de control ADCx 1(1) (Continuación)
Nota 1: La 'x' en ADxCON1 y ADCx se refiere a ADC 1 o ADC 2.

© 2006 Microchip Technology Inc.
DS70183A-página 16-7
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
     Registro 16-2:
ADxCON2: Registro de control ADCx 2(1)
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
CSCNA: bit de selección de escaneo de entrada
1 =
Escanee entradas para CH0+ durante el bit de muestra A
0 =
No escanear entradas
bits 9-8
CHPS<1:0>: bits de selección de canal
Cuando AD12B = 1, CHPS<1:0> es: U-0, no implementado, leído como '0' 
1x = Convierte CH0, CH1, CH2 y CH3
01 = Convierte CH0 y CH1
00 = Convierte CH0
poco 7
BUFS: Bit de estado de llenado del búfer (solo válido cuando BUFM = 1)
1 =
Actualmente, ADC está llenando la segunda mitad del buffer. La aplicación de usuario debe acceder a los datos en
la primera mitad del buffer
0 =
Actualmente, ADC está llenando la primera mitad del buffer. La aplicación de usuario debe acceder a los datos en el
segunda mitad del buffer.
poco 6
No implementado: leído como "0"
bit 5-2
SMPI<3:0>: Tasa de incremento para bits de direcciones DMA 
1111 = Incrementa la dirección DMA o genera una interrupción después de completar cada 16 
operación de muestra/conversión
1110 = Incrementa la dirección DMA o genera una interrupción después de completar cada 15 
operación de muestra/conversión
• • •
0001 = Incrementa la dirección DMA o genera una interrupción después de completar cada segundo 
operación de muestra/conversión
0000 = Incrementa la dirección DMA o genera una interrupción después de completar cada 
operación de muestra/conversión
poco 1
BUFM: Bit de selección del modo de llenado del búfer
1 =
Inicia el búfer llenando la primera mitad del búfer en la primera interrupción y la segunda mitad del búfer
en la próxima interrupción
0 =
Siempre comienza a llenar el búfer desde la dirección inicial.
poco 0
ALTS: bit de selección de modo de muestra de entrada alternativa
1 =
Utiliza selecciones de entrada de canal para la muestra A en la primera muestra y la muestra B en la siguiente muestra.
0 =
Siempre utiliza selecciones de entrada de canal para la muestra A
Nota 1: La 'x' en ADxCON2 y ADCx se refiere a ADC 1 o ADC 2.
VREFH
VREFL
000
AVDD
Avss
001
VREF+ externo
Avss
010
AVDD
VREF externo-
011
VREF+ externo
VREF externo-
1x
AVDD
Avss

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-8
© 2006 Microchip Technology Inc.
     Registro 16-3:
ADxCON3: Registro de control ADCx 3(1)
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
SAMC<4:0>
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
ADCS<7:0>
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
1 = Reloj RC interno ADC
0 = Reloj derivado del reloj del sistema
bits 14-13
No implementado: leído como "0"
bits 12-8
SAMC<4:0>: bits de tiempo de muestreo automático
11111 = 31 TAD
• • •
00001 = 1 TAD
00000 = 0 TAD
poco 7-0
ADCS<7:0>: Bits de selección de reloj de conversión ADC
11111111 = TCY · (ADCS<7:0> + 1) = 256 · TCY = TAD
• • •
00000010 = TCY · (ADCS<7:0> + 1) = 3 · TCY = TAD 
00000001 = TCY · (ADCS<7:0> + 1) = 2 · TCY = TAD
00000000 = TCY · (ADCS<7:0> + 1) = 1 · TCY = TAD
Nota 1: La 'x' en ADxCON3 y ADCx se refiere a ADC 1 o ADC 2.

© 2006 Microchip Technology Inc.
DS70183A-página 16-9
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
     Registro 16-4:
ADxCON4: Registro de control ADCx 4(1)
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
111 =Asigna 128 palabras de buffer a cada entrada analógica
110 =Asigna 64 palabras de buffer a cada entrada analógica
101 =Asigna 32 palabras de buffer a cada entrada analógica
100 =Asigna 16 palabras de buffer a cada entrada analógica
011 =Asigna 8 palabras de buffer a cada entrada analógica
010 =Asigna 4 palabras de buffer a cada entrada analógica
001 =Asigna 2 palabras de buffer a cada entrada analógica
000 =Asigna 1 palabra de buffer a cada entrada analógica
Nota 1: La 'x' en ADxCON4 y ADCx se refiere a ADC 1 o ADC 2.

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-10
© 2006 Microchip Technology Inc.
     Registro 16-5:
ADxCHS123: Canal de entrada ADCx 1, 2, 3 Seleccionar registro (1)
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
0x = CH1, CH2, CH3 la entrada negativa es VREFL
poco 8
CH123SB: Selección de entrada positiva del canal 1, 2, 3 para el bit de muestra B
Cuando AD12B = 1, CHxSA es: U-0, no implementado, leído como '0'
1 = La entrada positiva CH1 es AN3, la entrada positiva CH2 es AN4, la entrada positiva CH3 es AN5
0 = La entrada positiva de CH1 es AN0, la entrada positiva de CH2 es AN1, la entrada positiva de CH3 es AN2
bit 7-3
No implementado: leído como "0"
poco 2-1
CH123NA<1:0>: Selección de entrada negativa del canal 1, 2, 3 para bits de muestra A
Cuando AD12B = 1, CHxNA es: U-0, no implementado, leído como '0'
11 = La entrada negativa de CH1 es AN9, la entrada negativa de CH2 es AN10, la entrada negativa de CH3 es AN11
10 = La entrada negativa de CH1 es AN6, la entrada negativa de CH2 es AN7, la entrada negativa de CH3 es AN8
0x = CH1, CH2, CH3 la entrada negativa es VREFL
poco 0
CH123SA: Canal 1, 2, 3 Selección de entrada positiva para muestra A bit
Cuando AD12B = 1, CHxSA es: U-0, no implementado, leído como '0'
1 = La entrada positiva CH1 es AN3, la entrada positiva CH2 es AN4, la entrada positiva CH3 es AN5
0 = La entrada positiva de CH1 es AN0, la entrada positiva de CH2 es AN1, la entrada positiva de CH3 es AN2
Nota 1: La 'x' en ADxCHS123 y ADCx se refiere a ADC 1 o ADC 2.

© 2006 Microchip Technology Inc.
DS70183A-página 16-11
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
     Registro 16-6:
ADxCHS0: Canal de entrada ADCx 0 Seleccionar registro
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
CH0SB<4:0>: Selección de entrada positiva del canal 0 para bits de muestra B (1, 2)
Misma definición que bit<4:0>.
poco 7
CH0NA: Selección de entrada negativa del canal 0 para el bit de muestra A
1 = La entrada negativa del canal 0 es AN1
0 = La entrada negativa del canal 0 es VREFL
bits 6-5
No implementado: leído como "0"
poco 4-0
CH0SA<4:0>: Selección de entrada positiva del canal 0 para bits de muestra A (1, 2)
11111 = La entrada positiva del canal 0 es AN31
11110 = La entrada positiva del canal 0 es AN30
• • •
00010 = La entrada positiva del canal 0 es AN2
00001 = La entrada positiva del canal 0 es AN1
00000 = La entrada positiva del canal 0 es AN0
Nota 1: Los pines AN16 – AN31 no están disponibles para ADC 2.
2: La 'x' en ADxCHS0 y ADCx se refiere a ADC 1 o ADC 2

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-12
© 2006 Microchip Technology Inc.
     
     
Registro 16-7:
AD1CSSH: Registro alto de selección de escaneo de entrada ADC1
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
CSS<31:16>: bits de selección de escaneo de entrada de ADC (1, 2)
1 = Seleccione ANx para escaneo de entrada
0 = Saltar ANx para escaneo de entrada
Nota 1: En dispositivos con menos de 32 entradas analógicas, el usuario puede seleccionar todos los bits ADxCSSL. Sin embargo, las entradas 
seleccionado para escanear sin una entrada correspondiente en el dispositivo convertir VREF-.
2: ADC 2 solo admite entradas analógicas AN0-AN15; por lo tanto, no existe ningún registro de selección de exploración de entrada ADC 2.
Registro 16-8:
ADxCSSL: Registro de selección de escaneo de entrada ADCx bajo
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
CSS<15:0>: bits de selección de escaneo de entrada ADC (1, 2)
1 = Seleccione ANx para escaneo de entrada
0 = Saltar ANx para escaneo de entrada
Nota 1: En dispositivos con menos de 16 entradas analógicas, el usuario puede seleccionar todos los bits ADxCSSL. Sin embargo, las entradas 
seleccionado para escanear sin una entrada correspondiente en el dispositivo convertir VREF-.
2: La 'x' en ADxCSSL y ADCx se refiere a ADC 1 o ADC 2.

© 2006 Microchip Technology Inc.
DS70183A-página 16-13
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
     
     
Registro 16-9:
AD1PCFGH: Registro de configuración del puerto ADC1 alto
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
PCFG<31:16>: Bits de control de configuración del puerto ADC (1, 2)
1 = Pin de puerto en modo digital, entrada de lectura de puerto habilitada, multiplexor de entrada ADC conectado a AVSS
0 = Pin de puerto en modo analógico, entrada de lectura de puerto deshabilitada, ADC muestra el voltaje del pin
Nota 1: En dispositivos con menos de 32 entradas analógicas, todos los bits PCFG son R/W por el usuario. Sin embargo, los bits PCFG se ignoran. 
en puertos sin una entrada correspondiente en el dispositivo.
2: ADC2 solo admite entradas analógicas AN0-AN15; por lo tanto, no existe ningún registro de configuración del puerto ADC2.
Registro 16-10:
ADxPCFGL: Registro de configuración del puerto ADCx bajo
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
PCFG<15:0>: Bits de control de configuración del puerto ADC (1, 2, 3)
1 = Pin de puerto en modo digital, entrada de lectura de puerto habilitada, multiplexor de entrada ADC conectado a AVSS
0 = Pin de puerto en modo analógico, entrada de lectura de puerto deshabilitada, ADC muestra el voltaje del pin
Nota 1: En dispositivos con menos de 16 entradas analógicas, todos los bits PCFG son R/W por el usuario. Sin embargo, los bits PCFG se ignoran. 
en puertos sin una entrada correspondiente en el dispositivo.
2: En dispositivos con dos módulos analógicos a digitales, tanto AD1PCFGL como AD2PCFGL afectan la configuración de 
Pines de puerto multiplexados con AN0-AN15.
3: La 'x' en ADxPCFGL y ADx se refiere a ADC 1 o ADC 2

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-14
© 2006 Microchip Technology Inc.
16.3
 TERMINOLOGÍA A/D Y SECUENCIA DE CONVERSIÓN
La Figura 16-2 muestra una secuencia de conversión básica y los términos que se utilizan. Una muestra de la
El voltaje del pin de entrada analógica se realiza mediante amplificadores Sample/Hold (también llamados canales Sample/Hold).
nels). La configuración ADC de 10 bits puede utilizar hasta cuatro canales de muestreo/retención, designados
CH0-CH3, mientras que la configuración ADC de 12 bits puede usar solo un canal de muestreo/retención, CH0.
Los canales Sample/Hold están conectados a los pines de entrada analógica a través de la entrada analógica.
multiplexor. El multiplexor de entrada analógica está controlado por los registros ADxCHS123 y ADxCHS0.
ters. Hay dos conjuntos de bits de control del multiplexor en los registros de selección de canal del ADC que funcionan
ción de manera idéntica. Estos dos conjuntos de bits de control permiten dos multiplexores de entrada analógica diferentes.
configuraciones a programar (llamadas MUX A y MUX B). El ADC puede opcionalmente cambiar
entre las configuraciones MUX A y MUX B entre conversiones. El ADC también puede optar por:
escanear aliado a través de una serie de entradas analógicas.
El tiempo de muestreo es el tiempo que el amplificador de muestreo/retención del módulo ADC está conectado al analógico.
pin de entrada. El tiempo de muestreo se puede iniciar manualmente configurando ADC Sample Enable (SAMP)
bit en el registro de control ADCx 1 (ADxCON1<1>) o iniciado automáticamente por el hardware ADC.
El tiempo de muestreo finaliza manualmente borrando el bit de control SAMP en el software del usuario o automáticamente.
automáticamente por una fuente de activación de conversión.
El tiempo de conversión es el tiempo necesario para que el ADC convierta el voltaje retenido por el Sample/Hold
Amplificador. El ADC se desconecta del pin de entrada analógica al final del tiempo de muestreo. el
ADC requiere un ciclo de reloj A/D (TAD) para convertir cada bit del resultado más dos ciclos de reloj adicionales.
ciclos. Se requieren un total de 12 ciclos TAD para realizar la conversión completa en modo de 10 bits.
Se requieren un total de 14 ciclos TAD para realizar la conversión completa en modo de 12 bits. cuando
Cuando se completa el tiempo de conversión, el resultado se carga en el registro ADCxBUF0, el Sam-
ple/Hold El amplificador se puede volver a conectar al pin de entrada y se puede generar una interrupción de la CPU. 
La suma del tiempo de muestra y el tiempo de conversión A/D proporciona el tiempo total de conversión.
Hay un tiempo mínimo de muestreo para garantizar que el amplificador de muestreo/retención proporcione el nivel deseado.
precisión para la conversión A/D (consulte 16.15 “Requisitos de muestreo A/D”). Además,
Hay múltiples opciones de reloj de entrada para el ADC. Debe seleccionar una opción de reloj de entrada que no
no violar la especificación TAD mínima.
Figura 16-2:
Secuencia de muestra/conversión de ADC       
El ADC permite muchas opciones para especificar la secuencia de muestra/conversión. La muestra/conversión
La secuencia puede ser muy sencilla, utilizando sólo un amplificador Sample/Hold. Una muestra más elaborada
La secuencia ple/convert realiza múltiples conversiones utilizando más de un amplificador Sample/Hold.
La configuración ADC de 10 bits puede utilizar dos amplificadores Sample/Hold para realizar dos conversiones en
una secuencia de muestra/conversión o cuatro amplificadores de muestra/retención con cuatro conversiones.
Tiempo de muestra
Tiempo de conversión de ADC
Tiempo total de conversión de ADC
El amplificador Sample/Hold está conectado al pin de entrada analógica para muestreo.
El amplificador de muestreo/retención está desconectado de la entrada y mantiene el nivel de la señal.
La conversión A/D la inicia la fuente de activación de la conversión.
Conversión A/D completa, 
El resultado se carga en el búfer de resultados. 
Opcionalmente generar interrupción.

© 2006 Microchip Technology Inc.
DS70183A-página 16-15
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
El número de amplificadores de muestra/retención, o canales por muestra, utilizados en la muestra/conversión.
La secuencia está determinada por los bits de control de selección de canal (CHPS<1:0>) en el registro de control ADCx.
hermano 2 (ADxCON2<9:8>). 
Una secuencia de muestra/conversión que utiliza múltiples canales de muestra/retención se puede reproducir simultáneamente.
muestreado o muestreado secuencialmente, según lo controlado por la selección de muestra simultánea (SIMSAM)
bit (ADxCON1<3>). El muestreo simultáneo de múltiples señales garantiza que la instantánea de la
entradas analógicas se produce exactamente al mismo tiempo para todas las entradas. El muestreo secuencial toma un instante.
Toma de cada entrada analógica justo antes de que comience la conversión en esa entrada. El muestreo de múltiples
las entradas no están correlacionadas.
Figura 16-3:
Muestreo simultáneo y secuencial
La hora de inicio del muestreo se puede controlar en el software configurando ADC Sample Enable
(SAMP) bit de control (ADxCON1<1>). El inicio del tiempo de muestreo también se puede controlar automáticamente.
automáticamente por el hardware. Cuando el módulo ADC funciona en el modo Auto-Sample, el módulo Sam-
Los amplificadores ple/Hold se vuelven a conectar al pin de entrada analógica al final de la conversión en el
secuencia de muestra/conversión. La función de muestreo automático está controlada por el inicio automático de muestreo del ADC.
(ASAM) bit de control (ADxCON1<2>).
La fuente de activación de conversión finaliza el tiempo de muestreo y comienza una conversión A/D o una
secuencia de muestra/conversión. La fuente del activador de conversión se selecciona mediante el reloj de muestra.
Bits de control de selección de fuente (SSRC<2:0>) (ADxCON1<7:5>. El activador de conversión se puede tomar
desde una variedad de fuentes de hardware, o se puede controlar manualmente en el software borrando el
Bit de control SAMP. Una de las fuentes desencadenantes de conversión es la conversión automática. El tiempo entre
Las conversiones automáticas se establecen mediante un contador y el reloj ADC. El modo Auto-Sample y el auto-con-
El activador de versión se puede utilizar en conjunto para proporcionar infinitas conversiones automáticas sin software.
intervención.
Se puede generar una interrupción al final de cada secuencia de muestra/conversión o después de múltiples
secuencias de muestra/conversión, según lo determinado por el valor de Muestras por interrupción
(SMPI<3:0>) bits de control (ADxCON2<5:2>). El número de secuencias de muestra/conversión entre
las interrupciones pueden variar entre 1 y 16. El número total de resultados de conversión entre interrupciones
es el producto de los canales por muestra y el valor SMPI<3:0>. Sin embargo, dado que sólo uno
El resultado de la conversión se almacena en ADCxBUF0, cada ejecución de la rutina del servicio de interrupción se puede
se utiliza para leer solo un resultado de conversión.
Si es necesario almacenar en el búfer varios resultados de conversión, se debe utilizar un búfer DMA para almacenar los resultados.
resultados de la versión. En este caso, los bits SMPI<3:0> se utilizan para seleccionar la frecuencia con la que se actualiza la RAM DMA.
El puntero del búfer se incrementa. La frecuencia de incremento del puntero del buffer DMA RAM debe
no exceda la longitud del búfer DMA RAM.
Nota:
La configuración ADC de 12 bits solo puede realizar una conversión en una sola muestra.
secuencia de ejemplo/conversión. Los bits CHPS son irrelevantes en este caso.
AN0
AN1
AN2
AN3
simultáneo
Muestreo
secuencial
Muestreo

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-16
© 2006 Microchip Technology Inc.
16.4
 CONFIGURACIÓN DEL MÓDULO ADC
Se deben seguir los siguientes pasos para realizar una conversión A/D:
1.
Seleccione el modo de 10 o 12 bits (ADxCON1<10>)
2.
Seleccione la fuente de referencia de voltaje para que coincida con el rango esperado en las entradas analógicas
(ADxCON2<15:13>)
3.
Seleccione el reloj de conversión analógica para que coincida la velocidad de datos deseada con el reloj del procesador.
(ADxCON3<7:0>)
4.
Seleccione los pines del puerto como entradas analógicas (ADxPCFGH<15:0> y ADxPCFGL<15:0>)
5.
Determine cómo se asignarán las entradas a los canales Sample/Hold (ADxCHS0<15:0> y
ADxCHS123<15:0>)
6.
Determine cuántos canales de muestreo/retención se utilizarán (ADxCON2<9:8>, ADx-
PCFGH<15:0> y ADxPCFGL<15:0>)
7.
Determine cómo se producirá el muestreo (ADxCON1<3>, ADxCSSH<15:0> y ADxC-
SSL<15:0>)
8.
Seleccione muestreo manual o automático
9.
Seleccione el activador de conversión y el tiempo de muestreo.
10. Seleccione cómo se almacenan los resultados de la conversión en el búfer (ADxCON1<9:8>)
11. Seleccione la tasa de interrupción o la tasa de incremento del puntero del búfer DMA (ADxCON2<9:5>)
12. Seleccione el número de muestras en el búfer DMA para cada entrada del módulo ADC
(ADxCON4<2:0>)
13. Seleccione el formato de datos.
14. Configure la interrupción ADC (si es necesario)
• Borrar bit ADxIF 
• Seleccionar prioridad de interrupción (ADxIP<2:0)
• Establecer el bit ADxIE
15. Configure el canal DMA (si es necesario)
16. Encienda el módulo ADC (ADxCON1<15>)
Las opciones para estos pasos de configuración se describen en las secciones siguientes.
16.5
 SELECCIÓN DE LA FUENTE DE REFERENCIA DE TENSIÓN
Las referencias de voltaje para conversiones A/D se seleccionan usando los bits de control VCFG<2:0>.
(ADxCON2<15:13>). La referencia de voltaje superior (VREFH) y la referencia de voltaje inferior
(VREFL) pueden ser los rieles de voltaje internos AVDD y AVSS o los pines de entrada VREF+ y VREF-.
Los pines de referencia de voltaje externo se pueden compartir con las entradas AN0 y AN1 en un número bajo de pines.
dispositivos. El módulo ADC aún puede realizar conversiones en estos pines cuando se comparten con
los pines de entrada Vref+ y Vref-.
Los voltajes aplicados a los pines de referencia externos deben cumplir ciertas especificaciones. Consulte el
Sección "Especificaciones eléctricas" de la hoja de datos del dispositivo para obtener más detalles

© 2006 Microchip Technology Inc.
DS70183A-página 16-17
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.6
 SELECCIÓN DEL RELOJ DE CONVERSIÓN A/D
El módulo ADC tiene una tasa máxima a la que se pueden completar las conversiones. un analogo
El reloj del módulo, TAD, controla el tiempo de conversión. La conversión A/D requiere 12 períodos de reloj
(12 TAD) en el modo de 10 bits y 14 períodos de reloj (14 TAD) en el modo de 12 bits. La conversión A/D
El reloj se deriva del reloj de instrucciones del dispositivo o de una fuente de reloj RC interna. 
El período del reloj de conversión A/D se selecciona por software utilizando un contador de 6 bits. Hay 256
posibles opciones para TAD, especificadas por los bits de selección de reloj de conversión de ADC (ADCS<7:0>)
(ADxCON3<7:0>). La ecuación 16-1 proporciona el valor TAD en función de los bits de control ADCS y
el período del reloj del ciclo de instrucción del dispositivo, TCY.
Ecuación 16-1:
Período de reloj de conversión A/D
Para conversiones A/D correctas, se debe seleccionar el reloj de conversión A/D (TAD) para garantizar una
tiempo TAD mínimo de 75 ns.
El módulo ADC tiene una fuente de reloj RC interna dedicada que se puede utilizar para realizar
conversiones. La fuente de reloj RC interna debe usarse cuando se realizan conversiones A/D
mientras el dispositivo está en modo de suspensión. El oscilador RC interno se selecciona configurando el conector ADC.
versión del bit de fuente de reloj (ADRC) (ADxCON3<15>). Cuando el bit ADRC está establecido, el ADCS<7:0>
Los bits no tienen ningún efecto en la operación A/D.
Figura 16-4:
Diagrama de bloques del período de reloj de conversión A/D
TAD = TCY(ADCS + 1)
ADCS =
TAD
TCY
– 1
0
1
CAD interno 
Reloj RC 
Multiplicador de reloj
1, 2, 3, 4, 5,..., 256
ADxCON3<15>
TCY
TAD
8
ADxCON3<7:0>
Conversión A/D

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-18
© 2006 Microchip Technology Inc.
16.7
 SELECCIÓN DE ENTRADAS ANALÓGICAS PARA MUESTREO
Todos los amplificadores de muestreo/retención tienen multiplexores analógicos (consulte la Figura 16-1) tanto en sus
Ingresar e invertir entradas para seleccionar qué entradas analógicas se muestrean. Una vez que la muestra/conversión
Se especifica la secuencia, los registros ADxCHS0 y ADxCHS123 determinan qué entradas analógicas
Se seleccionan para cada muestra. 
Además, las entradas seleccionadas pueden variar según una muestra alterna o de forma repetida.
secuencia de muestras.
La misma entrada analógica se puede conectar a dos o más canales Sample/Hold para mejorar la conexión.
tarifas de versión.
16.7.1
Configuración de pines de puertos analógicos
Los registros ADPCFGH y ADPCFGL especifican la condición de entrada de los pines del dispositivo utilizados como análisis.
entradas de registro. Junto con el registro Dirección de datos (TRISx) en el módulo Puerto de E/S paralelo, estos
Los registros controlan el funcionamiento de los pines del ADC.
Un pin se configura como entrada analógica cuando el bit PCFGn correspondiente (ADPCFGH<n> o
ADPCFGL<n>) es claro. Los registros ADPCFGH y ADPCFGL están limpios en el reinicio, lo que provoca que
Los pines de entrada ADC se configurarán para entrada analógica de forma predeterminada en el reinicio.
Cuando se configura para entrada analógica, el búfer de entrada digital de E/S del puerto asociado está deshabilitado, por lo que no
no consume corriente.
Los pines del puerto que se desean como entradas analógicas deben tener su correspondiente bit TRIS configurado, especifi-
entrada del puerto de identificación. Si el pin de E/S asociado con una entrada A/D está configurado como salida, el TRIS
El bit se borra y el nivel de salida digital del puerto (VOH o VOL) se convierte. Después de un reinicio del dispositivo,
todos los bits TRIS están configurados.
Un pin se configura como E/S digital cuando se establece el bit PCFGn correspondiente. En esta configuración,
la entrada al multiplexor analógico está conectada a AVss. 
16.7.2
Selección de entrada del canal 0
El canal 0 es el más flexible de los cuatro canales Sample/Hold en términos de selección de canales analógicos.
entradas. Le permite seleccionar cualquiera de las hasta 16 entradas analógicas como entrada a la entrada positiva.
del canal. La selección de entrada positiva del canal 0 para bits de muestra A (CH0SA<4:0>)
(ADxCHS0<4:0>) normalmente selecciona la entrada analógica para la entrada positiva del canal 0.
Puede seleccionar VREF- o AN1 como entrada negativa del canal. El bit CH0NA
(ADxCHS0<7>) normalmente selecciona la entrada analógica para la entrada negativa del canal 0.
16.7.2.1
ESPECIFICAR SELECCIONES DE ENTRADA ALTERNADAS DEL CANAL 0
El bit de selección de modo de muestra de entrada alternativa (ALTS) (ADxCON2<0>) hace que el módulo ADC
alternar entre dos conjuntos de entradas que se seleccionan durante muestras sucesivas.
Las entradas especificadas por CH0SA<4:0> (ADxCHS0<4:0>), CH0NA (ADxCHS0<7>), CH123SA
(ADxCHS123<0>) y CH123NA<1:0> (ADxCHS123<2:1>) se denominan colectivamente MUX A
entradas. Las entradas especificadas por CH0SB<4:0> (ADxCHS0<12:8>), CH0NB (ADxCHS0<15>),
CH123SB (ADxCHS0<8>) y CH123NB<1:0> (ADxCHS0<10:9>) se denominan colectivamente
Entradas MUX B. Cuando el bit ALTS es '1', el módulo ADC alterna entre las entradas MUX A
en un grupo de muestras y las entradas MUX B en el grupo de muestras siguiente.
Nota:
Diferentes dispositivos tendrán diferentes números de entradas analógicas. Verificar el análogo
disponibilidad de entrada con la hoja de datos del dispositivo.
Nota 1: Cuando se lee el registro del puerto ADC, cualquier pin configurado como entrada analógica lee
como un '0'.
2: Niveles analógicos en cualquier pin que esté definido como entrada digital (incluido el AN15:AN0
pines) puede hacer que el búfer de entrada consuma corriente que está fuera del alcance del dispositivo.
especificación.

© 2006 Microchip Technology Inc.
DS70183A-página 16-19
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
Para el canal 0, si el bit ALTS es '0', solo las entradas especificadas por CH0SA<4:0> y CH0NA son
seleccionados para el muestreo. 
Si el bit ALTS es '1', en la primera secuencia de muestra/conversión para el canal 0, las entradas especificadas por
Se seleccionan CH0SA<4:0> y CH0NA para el muestreo. En la siguiente secuencia de conversión de muestra para
canal 0, las entradas especificadas por CH0SB<4:0> y CH0NB se seleccionan para el muestreo. esto
repeticiones de patrones para secuencias de conversión de muestras posteriores.
Tenga en cuenta que si se utilizan varios canales (CHPS = 01 o 1x) y muestreo simultáneo (SIMSAM = 1),
especificado, las entradas alternas cambian cada muestra porque todos los canales se muestrean en cada
tiempo de muestra. Si se utilizan múltiples canales (CHPS = 01 o 1x) y muestreo secuencial (SIMSAM = 0)
especificadas, las entradas alternas cambian sólo en cada muestra de un canal en particular.
16.7.2.2
ESCANEO A TRAVÉS DE VARIAS ENTRADAS CON CANAL 0
El canal 0 puede escanear a través de un vector seleccionado de entradas. El bit CSCNA (ADxCON2<10>)
permite escanear las entradas del canal CH0 en un número seleccionado de entradas analógicas. cuando
CSCNA está configurado, los bits CH0SA<4:0> se ignoran. 
Registro alto de selección de escaneo de entrada ADCx (ADxCSSH) y registro de selección de escaneo de entrada ADCx
Los registros bajos (ADxCSSL) especifican las entradas que se escanearán. Cada bit en estos registros
Corresponde a una entrada analógica. El bit 0 corresponde a AN0, el bit 1 corresponde a AN1 y así sucesivamente.
Si un bit en particular es '1', la entrada correspondiente es parte de la secuencia de escaneo. Las entradas son
siempre se escanea de entradas numeradas más bajas a más altas, comenzando en el primer canal seleccionado después
se produce cada interrupción.
Los bits ADxCSSH y ADxCSSL solo especifican la entrada de la entrada positiva del canal. el
El bit CH0NA todavía selecciona la entrada negativa del canal durante el escaneo.
Si el bit ALTS es '1', el escaneo solo se aplica a la selección de entrada MUX A. La entrada MUX B
La selección, especificada por CH0SB<4:0>, aún selecciona la entrada del canal 0 alterno. cuando el
Las selecciones de entrada se programan de esta manera, la entrada del canal 0 alterna entre un conjunto de
entradas de escaneo especificadas por el registro ADxCSSL y una entrada fija especificada por el CH0SB
bits.
16.7.3
Selección de entrada de los canales 1, 2 y 3
Los canales 1, 2 y 3 pueden muestrear un subconjunto de los pines de entrada analógica. Los canales 1, 2 y 3 pueden seleccionar
uno de dos grupos de tres entradas.
El bit CH123SA (ADxCHS123<0>) selecciona la fuente para las entradas positivas de los canales 1, 2 y
3. Al borrar CH123SA se selecciona AN0, AN1 y AN2 como fuente analógica para las entradas positivas de
canal 1, 2 y 3, respectivamente. La configuración de CH123SA selecciona AN3, AN4 y AN5 como analógico
fuente.
Los bits CH123NA<1:0> (ADxCHS<2:1>) seleccionan la fuente para las entradas negativas del canal 1,
2 y 3. Programando CH123NA = 0x selecciona VREF- como fuente analógica para las entradas negativas
de los canales 1, 2 y 3. La programación CH123NA = 10 selecciona AN6, AN7 y AN8 como analógico
fuente a las entradas negativas de los canales 1, 2 y 3 respectivamente. Programación CH123NA = 11
selecciona AN9, AN10 y AN11 como fuente analógica.
Nota:
Si el número de entradas escaneadas seleccionadas es mayor que el número de muestras
tomadas por interrupción, las entradas con números más altos no serán muestreadas.

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-20
© 2006 Microchip Technology Inc.
16.7.3.1
SELECCIÓN DE MÚLTIPLES CANALES PARA UNA ÚNICA ENTRADA ANALÓGICA
El multiplexor de entrada analógica se puede configurar para que el mismo pin de entrada esté conectado a dos o
más canales de muestreo/retención. El ADC convierte el valor retenido en un canal Sample/Hold,
mientras que el segundo canal Sample/Hold adquiere una nueva muestra de entrada.
16.7.3.2
ESPECIFICAR LA ENTRADA ALTERNA DE CANAL 1, 2 Y 3 
SELECCIONES
Al igual que con las entradas del canal 0, el bit ALTS (ADxCON2<0>) hace que el módulo ADC alterne
entre dos conjuntos de entradas que se seleccionan durante muestras sucesivas para los canales 1, 2 y 3.
Las entradas MUX A especificadas por CH123SA y CH123NA<1:0> siempre seleccionan la entrada cuando
ALT = 0.
Las entradas MUX A se alternan con las entradas MUX B especificadas por CH123SB y CH123NB<1:0>
cuando ALTS = 1.
16.8
 ACTIVACIÓN DEL MÓDULO
Cuando el bit del modo de funcionamiento del ADC (ADON) (ADxCON1<15>) es '1', el módulo ADC está en activo
modo y está completamente alimentado y funcional. 
Cuando ADON es '0', el módulo ADC está deshabilitado. Las partes digital y analógica del circuito son
desactivado para obtener el máximo ahorro actual.
Para volver al modo Activo desde el modo Apagado, el usuario debe esperar a que las etapas analógicas
para estabilizar. Para el tiempo de estabilización, consulte la sección Características Eléctricas del dispositivo.
hoja de datos.
16.9
 ESPECIFICAR EL CONTROL DE MUESTRA/CONVERSIÓN
El módulo ADC utiliza cuatro amplificadores Sample/Hold y un convertidor A/D en modo de 10 bits.
El módulo puede realizar 1, 2 o 4 muestras de entrada y conversiones A/D por muestra/conversión.
secuencia.
16.9.1
Número de canales de muestra/retención
Los bits de control CHPS<1:0> (ADxCON2<9:8>) se utilizan para seleccionar cuántas amplificaciones Sample/Hold
El módulo ADC utiliza los fiadores durante las secuencias de muestra/conversión. Los siguientes tres
Se pueden seleccionar opciones:
• Sólo CH0
• CH0 y CH1
• CH0, CH1, CH2, CH3
Los bits de control CHPS funcionan junto con el bit de control SIMSAM (muestra simultánea)
(ADxCON1<3>). Los bits CHPS y SIMSAM no son relevantes en el modo de 12 bits ya que sólo hay
un amplificador de muestra/retención.
16.9.2
Habilitación de muestreo simultáneo
Algunas aplicaciones pueden requerir que se muestreen varias señales simultáneamente. El SIMSAM
El bit de control (ADxCON1<3>) funciona junto con los bits de control CHPS y controla el mismo
Secuencia de plegado/conversión para múltiples canales como se muestra en la Tabla 16-1. El bit de control SIMSAM tiene
ningún efecto en el funcionamiento del módulo ADC si CHPS<1:0> = 00. Si hay más de un amplificador Sample/Hold
activado por los bits de control CHPS y el bit SIMSAM es '0', los dos o cuatro canales seleccionados
Los canales se muestrean y convierten secuencialmente con dos o cuatro períodos de muestreo. Si el SIMSAM
bit es '1', dos o cuatro canales seleccionados se muestrean simultáneamente con un período de muestreo.
Luego, los canales se convierten secuencialmente. El bit SIMSAM no es relevante en el modo de 12 bits ya que
solo hay un S/H.
Nota:
Los bits SSRC<2:0>, SIMSAM, ASAM, CHPS<1:0>, SMPI<3:0>, BUFM y ALTS,
así como los registros ADxCON3, ADxCSSH y ADxCSSL, no deben escribirse
a while ADON = 1. Esto conduciría a resultados indeterminados.

© 2006 Microchip Technology Inc.
DS70183A-página 16-21
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
Tabla 16-1:
Opciones de control de muestra/conversión
16.10
 CÓMO EMPEZAR A MUESTREAR
16.10.1
manuales
Configurar el bit SAMP (ADxCON1<1>) hace que el ADC comience a muestrear. Una de varias opciones
se puede utilizar para finalizar el muestreo y completar las conversiones. El muestreo no se reanuda hasta que
El bit SAMP vuelve a estar establecido. Para ver un ejemplo, consulte la Figura 16-5.
16.10.2
Automático
Configurar el bit ASAM (ADxCON1<2>) hace que el ADC comience a muestrear automáticamente un canal
siempre que una conversión no esté activa en ese canal. Se puede utilizar una de varias opciones para finalizar
muestreo y completar las conversiones. Si el bit SIMSAM especifica muestreo secuencial,
El muestreo en un canal se reanuda después de que se completa la conversión de ese canal. Si el SIMSAM
El bit especifica el muestreo simultáneo; el muestreo en un canal se reanuda después de la conversión de todos
canales completos. Para ver un ejemplo, consulte la Figura 16-6.
CHPS<1:0> SIMSAM
Secuencia de muestra/conversión
# de muestra/
Convertir ciclos
para completar
Ejemplo
00
x
Muestra CH0, convierte CH0
1
Figura 16-5,
Figura 16-6,
Figura 16-7,
Figura 16-8,
Figura 16-11,
Figura 16-12,
Figura 16-17,
Figura 16-18
01
0
Muestra CH0, convierte CH0
Muestra CH1, convierte CH1
2
1x
0
Muestra CH0, convierte CH0
Muestra CH1, convierte CH1
Muestra CH2, convierte CH2
Muestra CH3, convierte CH3
4
Figura 16-10,
Figura 16-14,
Figura 16-22
01
1
Muestra CH0, CH1 simultáneamente
Convertir CH0
Convertir CH1
1
Figura 16-20
1x
1
Muestra CH0, CH1, CH2, CH3
simultáneamente
Convertir CH0
Convertir CH1
Convertir CH2
Convertir CH3
1
Figura 16-9,
Figura 16-13,
Figura 16-19,
Figura 16-21

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-22
© 2006 Microchip Technology Inc.
16.11
 CÓMO DETENER EL MUESTREO E INICIAR CONVERSIONES
La fuente de activación de conversión finaliza el muestreo e inicia una secuencia seleccionada de
conversiones. Los bits de selección de fuente de reloj de muestra (SSRC<2:0>) (ADxCON1<7:5>) seleccionan el
fuente del activador de conversión.   
16.11.1
 manuales
Cuando SSRC<2:0> = 000, el activador de conversión está bajo control del software. Borrar el SAMP
El bit (ADxCON1<1>) inicia la secuencia de conversión. 
La Figura 16-5 es un ejemplo donde al configurar el bit SAMP se inicia el muestreo y se borra el bit SAMP.
El bit finaliza el muestreo y comienza la conversión. El software del usuario debe cronometrar la configuración y
borrado del bit SAMP para garantizar un tiempo de muestreo adecuado de la señal de entrada. Ver ejemplo 16-1
por ejemplo de código. 
Figura 16-5:
Conversión de 1 canal, inicio de muestra manual, inicio de conversión manual    
Nota:
Las fuentes de activación de conversión disponibles pueden variar según la variante del dispositivo.
Consulte la hoja de datos del dispositivo específico para conocer el activador de conversión disponible.
fuentes.
Nota:
Los bits de selección SSRC<2:0> no deben cambiarse cuando el módulo ADC está
habilitado.    Si cambia la fuente del activador de conversión, asegúrese de que el módulo ADC esté
deshabilitado primero borrando el bit ADON (ADxCON1<15>).
Reloj ADC
MUESTRA
ADC1BUF0
TSAMP
TCONV
BCLR AD1CON1,MUESTRA
BSET AD1CON1,MUESTRA
Ejecución de instrucciones
HECHO

© 2006 Microchip Technology Inc.
DS70183A-página 16-23
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
Ejemplo 16-1:
Conversión de 1 canal, inicio de muestra manual,
Código de inicio de conversión manual
La Figura 16-6 es un ejemplo donde la configuración del bit ASAM inicia el muestreo y la limpieza automáticos.
el bit SAMP finaliza el muestreo y comienza la conversión. Una vez completada la conversión, el
El módulo ADC vuelve automáticamente a un estado de muestreo. El bit SAMP se establece automáticamente en el
inicio del intervalo de muestreo. El software del usuario debe cronometrar el borrado del bit SAMP para garantizar
tiempo de muestreo adecuado de la señal de entrada, entendiendo que el tiempo entre el borrado de la señal de entrada
El bit SAMP incluye el tiempo de conversión y el tiempo de muestreo. Consulte el ejemplo 16-2 para ver el código.
ejemplo. 
Figura 16-6:
Conversión de 1 canal, inicio automático de muestra, inicio de conversión manual   
 AD1PCFGL = 0xFFFB;
// todos los PORTB = Digital; RB2 = analógico
 AD1CON1 = 0x0000;
// bit SAMP = 0 finaliza el muestreo...
// y comienza a convertir
 AD1CHS0 = 0x0002;
// Conecte RB2/AN2 como entrada CH0.
// en este ejemplo RB2/AN2 es la entrada
 AD1CSSL = 0;
 AD1CON3 = 0x0002;
// Muestra manual, Tad = 2 Tcy internos
 AD1CON2 = 0;
 AD1CON1bits.ADON = 1;
// enciende el ADC
 while(1)
// repetir continuamente
{
 
AD1CON1bits.SAMP = 1;
// empezar a muestrear...
 
RetardoNmSec(100);
// durante 100 ms
 
AD1CON1bits.SAMP = 0;
//comenzar a convertir
while (!AD1CON1bits.DONE);// ¿conversión realizada?
 
ValorADC = ADC1BUF0;
// sí, entonces obtenemos el valor ADC
}
// repetir
Reloj ADC
MUESTRA
ADC1BUF0
TSAMP
TCONV
BCLR AD1CON1,MUESTRA
Ejecución de instrucciones
TCONV
BSET AD1CON1,ASAM BCLR AD1CON1,MUESTRA
TSAMP
TAD0
TAD0
HECHO

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-24
© 2006 Microchip Technology Inc.
Ejemplo 16-2:
Conversión de 1 canal, inicio automático de muestra,
Código de inicio de conversión manual
16.11.2
Activador de conversión sincronizada
Cuando SSRC<2:0> = 111, el activador de conversión está bajo control de reloj A/D. El tiempo de muestreo automático
(SAMC<4:0>) bits (AD1CON3<12:8>) seleccionan el número de ciclos de reloj TAD entre el inicio de la muestra
inicio y el inicio de la conversión. Esta opción de activación proporciona las tasas de conversión más rápidas en múltiples
canales. Después del inicio del muestreo, el módulo ADC cuenta una cantidad de relojes TAD especificados por el
Brocas SAMC.
Ecuación 16-2:
Tiempo de activación de conversión sincronizado 
Cuando se utiliza solo un canal de muestreo/retención o muestreo simultáneo, SAMC siempre debe estar
programado para al menos un ciclo de reloj. Cuando se utilizan múltiples canales Sample/Hold con secuencial
muestreo, programar SAMC para ciclos de reloj cero da como resultado la tasa de conversión más rápida posible.
Consulte el Ejemplo 16-3 para ver un ejemplo de código.
Figura 16-7:
Conversión de 1 canal, inicio de muestra manual, inicio de conversión basada en TAD   
 AD1PCFGL = 0xFF7F;
// todos PORTB = Digital pero RB7 = analógico 
 AD1CON1 = 0x0004;
// bit ASAM = 1 implica muestreo..
// comienza inmediatamente después del último 
// la conversión está hecha
 AD1CHS0= 0x0007;
// Conecte RB7/AN7 como entrada CH0.
// en este ejemplo RB7/AN7 es la entrada
 AD1CSSL = 0;
 AD1CON3 = 0x0002;
// Manual de tiempo de muestra, Tad = interno 2 Tcy
 AD1CON2 = 0;
 
 AD1CON1bits.ADON = 1;
// enciende el ADC
 while(1)
// repetir continuamente
{
 
RetardoNmSec(100);
// muestra durante 100 mS 
 
AD1CON1bits.SAMP = 0;
//comenzar a convertir
while (!AD1CON1bits.DONE);// ¿conversión realizada?
 
ValorADC = ADC1BUF0;
// sí, entonces obtenemos el valor ADC
}
// repetir
TSMP = SAMC<4:0>*TAD
Reloj ADC
MUESTRA
ADC1BUF0
TSAMP
TCONV
BSET AD1CON1,MUESTRA
Ejecución de instrucciones
HECHO
= 16 TAD

© 2006 Microchip Technology Inc.
DS70183A-página 16-25
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
Ejemplo 16-3:
Conversión de un canal, inicio manual de muestras,
Código de inicio de conversión basado en TAD
16.11.2.1 SECUENCIA DE CONVERSIÓN DE MUESTRA DE EJECUCIÓN LIBRE
Como se muestra en la Figura 16-8, utilizando el modo Activador de conversión de conversión automática (SSRC = 111) en
combinación con el modo de inicio de muestra automática (ASAM = 1), permite que el módulo ADC programe
secuencias de muestra/conversión sin intervención del usuario u otros recursos del dispositivo. esto
El modo "cronometrado" permite la recopilación continua de datos después de la inicialización del módulo. 
Figura 16-8:
Conversión de un canal, inicio de muestreo automático, inicio de conversión basada en TAD   
Nota:
Esta configuración A/D debe estar habilitada para una tasa de conversión de 750 ksps.
 AD1PCFGL = 0xEFFF;
// todos los PORTB = Digital; RB12 = analógico
 AD1CON1 = 0x00E0;
// bit SSRC = 111 implica interno
// el contador finaliza el muestreo y comienza
// convirtiendo.
 AD1CHS0= 0x000C;
// Conecte RB12/AN12 como entrada CH0.
// en este ejemplo RB12/AN12 es la entrada
 AD1CSSL = 0;
 AD1CON3 = 0x1F02;
// Tiempo de muestreo = 31Tad, Tad = interno 2 Tcy
 AD1CON2 = 0;
 
 AD1CON1bits.ADON = 1;
// enciende el ADC
 while(1)
// repetir continuamente
{ 
 
AD1CON1bits.SAMP = 1;
//comenzar a muestrear entonces...
// después del 31Tad vamos a la conversión
while (!AD1CON1bits.DONE);// ¿conversión realizada?
 
ValorADC = ADC1BUF0;
// sí, entonces obtenemos el valor ADC
}
// repetir
Reloj ADC
MUESTRA
Búfer[1]
TSAMP
TCONV
HECHO
= 16 TAD
TSAMP
TCONV
= 16 TAD
Búfer[0]
BSET AD1CON1,ASAM
Ejecución de instrucciones

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-26
© 2006 Microchip Technology Inc.
16.11.2.2 MÚLTIPLES CANALES CON MUESTREO SIMULTÁNEO
Como se muestra en la Figura 16-9, cuando se utiliza muestreo simultáneo, el valor SAMC especifica la muestra
tiempo de inmersión. En el ejemplo, SAMC especifica un tiempo de muestreo de 3 TAD. Porque la muestra automática
El inicio está activo, el muestreo comienza en todos los canales después de que finaliza la última conversión y continúa durante
Tres relojes A/D. 
Figura 16-9:
Conversión de cuatro canales, inicio de muestreo automático, inicio de conversión TAD, muestreo simultáneo 
16.11.2.3 MÚLTIPLES CANALES CON MUESTREO SECUENCIAL
Como se muestra en la Figura 16-10, cuando se utiliza muestreo secuencial, el tiempo de muestreo precede a cada
tiempo de conversión. En el ejemplo, se agregan 3 relojes TAD para el tiempo de muestreo de cada canal. 
Figura 16-10:
Conversión de cuatro canales, inicio de muestreo automático, inicio de conversión TAD, muestreo secuencial 
TCONV
TCONV
TCONV
TCONV
ADCLK
ch1_samp
ch2_samp
ch3_samp
ch0_samp
Búfer[0]
Búfer[1]
Búfer[2]
Búfer[3]
TCONV
TCONV
HECHO
MUESTRA
TSAMP
TCONV
ADCLK
ch1_samp
ch2_samp
ch3_samp
ch0_samp
Búfer[0]
Búfer[1]
Búfer[2]
Búfer[3]
TCONV
TCONV
TCONV
TCONV
MUESTRA
TSAMP
TSAMP
HECHO
= 0

© 2006 Microchip Technology Inc.
DS70183A-página 16-27
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.11.2.4 CONSIDERACIONES DE TIEMPO DE MUESTRA UTILIZANDO LA CONVERSIÓN RELOJADA 
DISPARADOR Y MUESTREO AUTOMÁTICO
Diferentes secuencias de muestreo/conversión proporcionan diferentes tiempos de muestreo disponibles para el Sam-
Plegar/Mantener canal para adquirir la señal analógica. El usuario debe asegurarse de que el tiempo de muestreo exceda
los requisitos de muestreo, como se describe en la Sección 16.15 “Requisitos de muestreo A/D”.
Suponiendo que el módulo ADC está configurado para muestreo automático y utiliza una conversión sincronizada
disparador, el intervalo de muestreo está determinado por el intervalo de muestreo especificado por los bits SAMC.
Si el bit SIMSAM especifica muestreo simultáneo o solo un canal está activo, el muestreo
El tiempo es el período especificado por el bit SAMC.
Ecuación 16-3:
Tiempo de muestreo disponible, muestreo simultáneo
Si el bit SIMSAM especifica muestreo secuencial, el intervalo total utilizado para convertir todos los canales es
el número de canales multiplicado por el tiempo de muestreo y el tiempo de conversión. El tiempo de muestreo para un
canal individual es el intervalo total menos el tiempo de conversión para ese canal.
Ecuación 16-4:
Tiempo de muestreo disponible, muestreo simultáneo  
16.11.3
Inicio de conversión del activador de evento
A menudo es deseable sincronizar el final del muestreo y el inicio de la conversión con algunos
otro evento temporal. El módulo ADC puede utilizar una de tres fuentes como activador de conversión:
• Disparador INT externo
• Activador de comparación del temporizador GP
• Disparador PWM de control del motor
16.11.3.1 DISPARADOR INT EXTERNO
Cuando SSRC<2:0> = 001, la conversión A/D se activa mediante una transición activa en el pin INT0.
El pin INT0 se puede programar para una entrada de flanco ascendente o de flanco descendente.
16.11.3.2 DISPARADOR DE COMPARACIÓN DEL TEMPORIZADOR GP
El ADC se configura en este modo de disparo estableciendo SSRC<2:0> = 010. Cuando ocurre una coincidencia
entre el temporizador de 32 bits TMR3/TMR2 y el registro de período combinado PR3/PR2 de 32 bits,
Timer3 genera una señal especial de evento de activación de ADC. Esta característica no existe para el
Par de temporizadores TMR5/TMR4. Consulte la Sección 11. “Temporizadores” para obtener más detalles. Comprueba lo más
documentación reciente en el sitio web de Microchip en www.microchip.com.
16.11.3.3 DISPARADOR PWM DEL CONTROL DEL MOTOR
El módulo PWM tiene un activador de eventos que permite sincronizar las conversiones A/D con el
Base de tiempo PWM. Cuando SSRC<2:0> = 011, los tiempos de muestreo y conversión A/D ocurren en cualquier
punto programable por el usuario dentro del período PWM. El activador de evento especial permite al usuario
Minimizar el retraso entre el momento en que se adquieren los resultados de la conversión A/D y el momento en que se obtienen los resultados de la conversión A/D.
cuando se actualiza el valor del ciclo de trabajo. Consulte la Sección 14. “Control del motor PWM” para obtener más información.
detalles. Consulte la documentación más reciente en el sitio web de Microchip en 
www.microchip.com.
EET
=
Canales por muestra (CH/S) * 
((SAMC<4:0> * TAD) + Tiempo de conversión (TCONV))
TSMP
=
(TSEQ-TCONV) 
Nota 1: CH/S especificado por bits CHPS<1:0>.
2: TSEQ es el tiempo total para la secuencia de muestra/conversión.
TSMP = SAMC<4:0> * TAD

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-28
© 2006 Microchip Technology Inc.
16.11.3.4 SINCRONIZACIÓN DE OPERACIONES A/D CON INTERNO O EXTERNO 
EVENTOS
Modos en los que un pulso de activación de evento externo finaliza el muestreo e inicia la conversión (SSRC<2:0>
= 001, 10, 011) se puede utilizar en combinación con el muestreo automático (ASAM = 1) para provocar que el ADC
Módulo para sincronizar los eventos de conversión de muestra con la fuente de pulso de disparo. Por ejemplo,
En la Figura 16-12, donde SSRC<2:0> = 010 y ASAM = 1, el módulo ADC siempre termina de la misma manera.
realiza e inicia las conversiones de forma sincrónica con el evento desencadenante de comparación del temporizador. La ADC tiene
una tasa de conversión de muestra que corresponde a la tasa de eventos de comparación del temporizador. 
Figura 16-11:
Conversión de un canal, inicio de muestra manual, inicio de conversión basado en activador de conversión   
Figura 16-12:
Conversión de un canal, inicio de muestreo automático, inicio de conversión basado en activador de conversión   
Conversión
ADCLK
MUESTRA
ADC1BUF0
TSAMP
TCONV
BSET AD1CON1,MUESTRA
Ejecución de instrucciones
gatillo
ADCLK
MUESTRA
Búfer[0]
TSAMP
TCONV
BSET AD1CON1,ASAM
Ejecución de instrucciones
TCONV
TSAMP
Búfer[1]
HECHO
Conversión
gatillo

© 2006 Microchip Technology Inc.
DS70183A-página 16-29
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.11.3.5 MÚLTIPLES CANALES CON MUESTREO SIMULTÁNEO
Como se muestra en la Figura 16-13, cuando se utiliza el muestreo simultáneo, el muestreo comienza en todos los canales.
después de establecer el bit ASAM o cuando finaliza la última conversión. El muestreo se detiene y las conversiones comienzan
cuando se produce el desencadenante de conversión.
Figura 16-13:
Conversión de cuatro canales, inicio de muestreo automático, inicio de conversión de disparador, simultáneo 
Muestreo   
TCONV
TCONV
TCONV
TCONV
ADCLK
ch1_samp
ch2_samp
ch3_samp
ch0_samp
Búfer[0]
Búfer[1]
Búfer[2]
Búfer[3]
HECHO
TSAMP
MUESTRA
TSAMP
EET
Conversión
gatillo
Borrado
en software

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-30
© 2006 Microchip Technology Inc.
16.11.3.6 MÚLTIPLES CANALES CON MUESTREO SECUENCIAL
Como se muestra en la Figura 16-14, cuando se utiliza el muestreo secuencial, el muestreo para un canal en particular
se detiene justo antes de convertir ese canal y se reanuda después de que se detiene la conversión.
Figura 16-14:
Conversión de cuatro canales, inicio de muestreo automático, inicio de conversión de disparador, muestreo secuencial   
TCONV
TCONV
TCONV
TCONV
ADCLK
ch1_samp
ch2_samp
ch3_samp
ch0_samp
Búfer[0]
Búfer[1]
Búfer[2]
Búfer[3]
HECHO
TSAMP
TSAMP
TSAMP
TSAMP
MUESTRA
TSAMP
EET
Conversión
gatillo
Borrado
en software

© 2006 Microchip Technology Inc.
DS70183A-página 16-31
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.11.3.7 CONSIDERACIONES DE TIEMPO DE MUESTRA PARA AUTOMÁTICO 
SECUENCIAS DE MUESTREO/CONVERSIÓN
Diferentes secuencias de muestreo/conversión proporcionan diferentes tiempos de muestreo disponibles para el Sam-
Plegar/Mantener canal para adquirir la señal analógica. Debe asegurarse de que el tiempo de muestreo exceda
los requisitos de muestreo, como se describe en la Sección 16.15 “Requisitos de muestreo A/D”.
Suponiendo que el módulo ADC está configurado para muestreo automático y se recibe un pulso de disparo externo
Utilizado como disparador de conversión, el intervalo de muestreo es una parte del intervalo del pulso de disparo.
Si el bit SIMSAM especifica muestreo simultáneo, el tiempo de muestreo es el período del pulso de activación.
menos el tiempo necesario para completar las conversiones especificadas.
Ecuación 16-5:
Tiempo de muestreo disponible, muestreo simultáneo
Si el bit SIMSAM especifica muestreo secuencial, el tiempo de muestreo es el período del pulso de disparo menos
el tiempo necesario para completar una sola conversión.
Ecuación 16-6:
Tiempo de muestreo disponible, muestreo secuencial
TSMP = Intervalo de pulso de activación (TSEQ) - Canales por muestra (CH/S) * Tiempo de conversión (TCONV)
TSMP = TSEQ - (CH/S * TCONV)
Nota 1: CH/S se especifica mediante bits CHPS<1:0>
2: TSEQ es el intervalo de tiempo del pulso de activación
TSMP = Intervalo de pulso de activación (TSEQ) - Tiempo de conversión (TCONV)
TSMP = TSEQ - TCONV
Nota:
TSEQ es el tiempo del intervalo del pulso de activación.

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-32
© 2006 Microchip Technology Inc.
16.12
 CONTROL DE LA OPERACIÓN DE MUESTRA/CONVERSIÓN
El software de la aplicación puede sondear los bits SAMP (AD1CON1<1>) y DONE (AD1CON1<0>) para
realizar un seguimiento de las operaciones A/D o el módulo ADC puede interrumpir la CPU cuando se realizan conversiones.
completo. El software de la aplicación también puede cancelar las operaciones A/D, si es necesario.
16.12.1
Monitoreo del estado de la muestra/conversión
Los bits SAMP y DONE indican el estado de muestreo y el estado de conversión del ADC,
respectivamente. Generalmente, cuando el bit SAMP se borra, indicando el final del muestreo, el bit DONE se desactiva.
se configura automáticamente, indicando el final de la conversión. Si tanto SAMP como DONE son '0', el ADC está en
un estado inactivo. En algunos modos operativos, el bit SAMP también puede invocar y terminar sam-
pling.
16.12.2
Generando una interrupción ADC
Los bits SMPI<3:0> (ADxCON2<5:2>) controlan la generación de interrupciones. La interrupción ocurre
cierto número de secuencias de muestra/conversión después de iniciar el muestreo y vuelve a ocurrir en cada
número equivalente de muestras. Tenga en cuenta que las interrupciones se especifican en términos de muestras y no
en términos de conversiones o muestras de datos en la memoria intermedia. 
Si las transferencias DMA no están habilitadas, tener un valor SMPI<3:0> distinto de cero da como resultado que se sobrescriba el
datos en el registro ADCxBUF0. Por ejemplo, si SMPI<3:0> = 0011, entonces cada cuarta conversión
El resultado se puede leer en la Rutina de servicio de interrupción del ADC. Sin embargo, si la búsqueda de canales es
habilitado, los bits SMPI<3:0> deben configurarse en uno menos que el número de canales a escanear.
De manera similar, si el muestreo alternativo está habilitado, los bits SMPI<3:0> deben configurarse en '0001'.
Si las transferencias DMA están habilitadas, el bit SMPI<3:0> debe borrarse, excepto cuando se realiza la exploración de canales.
o se utiliza un muestreo alternativo. Consulte la Sección 16.13 “Especificación de los resultados de la conversión
Almacenamiento en búfer” para obtener más detalles sobre los requisitos de configuración de SMPI<3:0>.
Cuando el bit SIMSAM (ADxCON1<3>) especifica muestreo secuencial, independientemente del número
de canales especificados por los bits CHPS<1:0> (ADxCON2<9:8>), el módulo ADC muestrea una vez
para cada conversión y muestra de datos en el búfer. El valor especificado por el registro DMAxCNT.
para el canal DMA que se utiliza corresponde al número de muestras de datos en el búfer.
Cuando el bit SIMSAM especifica muestreo simultáneo, el número de muestras de datos en el búfer
está relacionado con los bits CHPS<1:0>. Algorítmicamente, los canales por muestra (CH/S) multiplicados por el número
El número de muestras da como resultado el número de entradas de muestras de datos en el búfer. Para evitar la pérdida de datos en
el buffer debido a desbordamientos, el registro DMAxCNT debe configurarse al tamaño de buffer deseado.
La desactivación de la interrupción del ADC no se realiza con los bits SMPI<3:0>. Para desactivar la interrupción, borre
el bit de habilitación de interrupción del módulo analógico ADxIE.
16.12.3
Abortar el muestreo
Borrar el bit SAMP mientras se está en el modo de muestreo manual finaliza el muestreo pero también puede iniciar un
conversión si SSRC<2:0> = 000.
Borrar el bit ASAM mientras se está en el modo de muestreo automático no finaliza una operación en curso.
secuencia de muestreo/conversión, sin embargo, el muestreo no se reanuda automáticamente después de
conversiones.
16.12.4
Cancelar una conversión
Al borrar el bit ADON (ADxCON1<15>) durante una conversión, se cancela la conversión actual. el
El par de registros de resultados de ADC NO se actualiza con la muestra de conversión A/D parcialmente completada.
Es decir, la ubicación del buffer ADC1BUF0 correspondiente continúa conteniendo el valor del último
conversión completada (o el último valor escrito en el búfer).

© 2006 Microchip Technology Inc. 
DS70183A-página 16-33 
Sección 16. Convertidor analógico a digital (ADC) 
CAD 
16 
16.13 
ESPECIFICAR EL BÚFER DE LOS RESULTADOS DE LA CONVERSIÓN 
El módulo ADC contiene un registro de puerto dual, de solo lectura y de una sola palabra (ADCxBUF0), que 
almacena el resultado de la conversión A/D. Si es necesario almacenar en el búfer más de un resultado de conversión antes 
Al desencadenar una interrupción, se pueden utilizar transferencias de datos DMA. Ambos canales ADC (ADC1 y ADC2) 
puede desencadenar una transferencia de datos DMA. Dependiendo del canal ADC seleccionado como DMA IRQ 
fuente, se produce una transferencia DMA cuando el estado del indicador de interrupción completa de conversión ADC (AD1IF 
o AD2IF) en el registro de estado de indicador de interrupción (IFS0 o IFS1, respectivamente) en el registro de estado de interrupción. 
El módulo se configura como resultado de una secuencia de conversión de muestra. 
El resultado de cada conversión A/D se almacena en el registro ADCxBUF0. Si un canal DMA no es 
habilitado para el módulo ADC, la aplicación del usuario debe leer cada resultado antes de obtenerlo. 
sobrescrito por el siguiente resultado de conversión. Sin embargo, si DMA está habilitado, la conversión múltiple 
Los resultados se pueden transferir automáticamente desde ADCxBUF0 a un búfer definido por el usuario en el DMA. 
Área de RAM. Por lo tanto, la aplicación puede procesar varios resultados de conversión con un software mínimo. 
arriba. 
El bit del modo de creación de búfer DMA (ADDMABM) en el registro de control 1 de ADCx (ADxCON1<12>) determina 
Explora cómo se completan los resultados de la conversión en el área del búfer DMA RAM que se utiliza para el ADC. 
Si este bit está establecido (ADDMABM = 1), los buffers DMA se escriben en el orden de conversión. El CAD 
El módulo proporciona una dirección al canal DMA que es la misma que la dirección utilizada para el 
Búfer independiente no DMA. Si se borra el bit ADDMABM, los buffers DMA se escriben en 
Modo dispersión/reunión. El módulo ADC proporciona una dirección de dispersión/reunión al canal DMA, 
basado en el índice de la entrada analógica y el tamaño del búfer DMA. 
16.13.1 
USO DE DMA EN EL MODO DISPERSIÓN/REUNIÓN 
Cuando el bit ADDMABM es '0', el modo Dispersión/Reunión está habilitado. En este modo, el canal DMA 
nel debe configurarse para direccionamiento indirecto periférico. El buffer DMA se divide en con- 
bloques de memoria consecutivos correspondientes a todas las entradas analógicas disponibles (de AN0 - AN31). Cada 
El resultado de la conversión para una entrada analógica particular es transferido automáticamente por el módulo ADC a 
el bloque correspondiente dentro del área de buffer DMA definida por el usuario. muestras sucesivas para el 
misma entrada analógica se almacenan en secuencia dentro del bloque asignado a esa entrada. 
El número de muestras que deben almacenarse en el búfer DMA para cada entrada analógica se especifica 
especificado por los bits DMABL<2:0> (ADxCON4<2:0>). 
El módulo ADC accede a las ubicaciones del búfer dentro de cada bloque mediante un puntero interno, 
que se inicializa a '0' cuando el módulo ADC está habilitado. Cuando este puntero interno llega 
el valor definido por los bits DMABL<2:0>, se restablece a '0'. Esto asegura que la conversión 
Los resultados de una entrada analógica no corrompen los resultados de la conversión de otras entradas analógicas. la tasa 
Se especifica el valor en el que se incrementa este puntero interno cuando los datos se escriben en el búfer DMA. 
por los bits SMPI<3:0>. 
Cuando no se requiere escaneo de canales ni muestreo alternativo, se debe borrar SMPI <3:0>, 
lo que implica que el puntero se incrementará en cada muestra. Por lo tanto, es teóricamente posible utilizar 
cada ubicación en el búfer DMA para los bloques asignados a las entradas analógicas que se están muestreando. 
En el ejemplo ilustrado en la Figura 16-15, se puede observar que los resultados de conversión para el 
Las entradas AN0, AN1 y AN2 se almacenan en secuencia, sin dejar ubicaciones no utilizadas en sus respectivos 
bloques de memoria correspondientes. Sin embargo, para las cuatro entradas analógicas (AN4, AN5, AN6 y AN7) que están 
escaneado por CH0, la primera ubicación en el bloque AN5, las dos primeras ubicaciones en el bloque AN6 y 
Las primeras tres ubicaciones en el bloque AN7 no se utilizan, lo que resulta en una organización relativamente ineficiente. 
ment de datos en el buffer DMA. 
Nota: 
Para obtener información sobre cómo configurar un canal DMA para transferir datos desde el 
Búfer ADC y definir un área de búfer DMA correspondiente desde donde los datos pueden 
ser accedido por la aplicación, consulte la Sección 22. “Memoria directa 
Acceso (DMA)". Para obtener información específica sobre los registros de interrupción, consulte 
a la Sección 6. “Interrupciones”. 

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-34
© 2006 Microchip Technology Inc.
Cuando se utiliza el escaneo y no se realiza ningún muestreo simultáneo (SIMSAM = 0), SMPI<3:0>
debe establecerse en uno menos que el número de entradas que se escanean. Por ejemplo, si CHPS<1:0>
= 00 (solo se usa un canal de muestra/retención) y AD1CSSL = 0xFFFF, lo que indica que
AN0-AN15 se están escaneando, luego configure SMPI<3:0> = 1111 para que el puntero interno aumente.
solo después de cada 16.ª secuencia de muestra/conversión. Esto evita ubicaciones no utilizadas en el
bloques correspondientes a las entradas analógicas que se están escaneando.
De manera similar, si ALTS=1, lo que indica que se utilizan selecciones de entrada analógica alternas, entonces SMPI<3:0>
se establece en '0001', incrementando así el puntero interno después de cada segunda muestra.
Nota:
El módulo no realiza comprobaciones de límites en las direcciones del búfer generadas. Para
Por ejemplo, debe asegurarse de que los bits LS del registro DMAxSTA o DMAxSTB
utilizados son efectivamente '0'. Además, el número de entradas analógicas potenciales multiplicado por el
El tamaño del buffer especificado por DMABL<2:0> no debe exceder la longitud total del DMA.
búfer.

© 2006 Microchip Technology Inc.
DS70183A-página 16-35
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
Figura 16-15:
Búfer DMA en modo dispersión/reunión 
DMAxSTA
AN0 – MUESTRA 1
AN0 – MUESTRA 2
AN0 – MUESTRA 3
AN0 – MUESTRA 4
AN0 – MUESTRA 5
AN0 – MUESTRA 6
AN0 – MUESTRA 7
AN0 – MUESTRA 8
AN1 – MUESTRA 1
AN1 – MUESTRA 2
AN1 – MUESTRA 3
AN1 – MUESTRA 4
AN1 – MUESTRA 5
AN1 – MUESTRA 6
AN1 – MUESTRA 7
AN1 – MUESTRA 8
AN2 – MUESTRA 1
AN2 – MUESTRA 2
AN2 – MUESTRA 3
AN2 – MUESTRA 4
AN2 – MUESTRA 5
AN2 – MUESTRA 6
AN2 – MUESTRA 7
AN2 – MUESTRA 8
—
—
—
—
—
—
—
—
AN4 – MUESTRA 1
—
—
—
AN4 – MUESTRA 5
—
—
—
—
AN5 – MUESTRA 2
—
—
—
AN5 – MUESTRA 6
—
—
—
—
AN6 – MUESTRA 3
—
—
—
AN6 – MUESTRA 7
—
—
—
—
AN7 – MUESTRA 4
—
—
—
AN7 – MUESTRA 8
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
BLOQUE AN0
BLOQUE AN1
BLOQUE AN2
BLOQUE AN3
BLOQUE AN4
BLOQUE AN5
BLOQUE AN6
BLOQUE AN7
BLOQUE AN31
|
|
|
{
{
{
{
{
{
{
Ubicaciones de búfer no utilizadas
Ubicaciones de búfer no utilizadas
Ubicaciones de búfer no utilizadas
Ubicaciones de búfer no utilizadas
Ubicaciones de búfer no utilizadas
Ubicaciones de búfer no utilizadas
Ubicaciones de búfer no utilizadas
{
{
{
{
{
{
{
{
{

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-36
© 2006 Microchip Technology Inc.
16.13.2
USO DE DMA EN EL MODO DE ORDEN DE CONVERSIÓN
Cuando el bit AADMABM (ADCON1<12>) = 1, el modo de orden de conversión está habilitado. en esto
modo, el canal DMA se puede configurar para registro indirecto o dirección indirecta periférica.
ing. Todos los resultados de la conversión se almacenan en el área de búfer DMA especificada por el usuario en el mismo orden en
donde las conversiones son realizadas por el módulo ADC. En este modo, el buffer no se divide
en bloques asignados a diferentes entradas analógicas. Más bien, la conversión resulta de diferentes entradas.
se intercalan de acuerdo con los modos de llenado de búfer específicos que se utilizan. 
En esta configuración, el puntero del búfer siempre se incrementa en una palabra. En este caso, el
Los bits SMPI<3:0> (ADxCON2<5:2>) deben borrarse y los bits DMABL<2:0> (ADxCON4<2:0>)
son ignorados.
La Figura 16-16 ilustra un ejemplo idéntico a la configuración de la Figura 16-15, pero usando el
Modo de orden de conversión. En este ejemplo, el registro DMAxCNT se ha configurado para generar
Comió la interrupción DMA después de obtener 16 resultados de conversión. 
Figura 16-16:
Búfer DMA en modo de orden de conversión   
AN4 – MUESTRA 1
DMAxSTA
AN0 – MUESTRA 1
AN1 – MUESTRA 1
AN2 – MUESTRA 1
AN5 – MUESTRA 2
AN0 – MUESTRA 2
AN1 – MUESTRA 2
AN2 – MUESTRA 2
AN6 – MUESTRA 3
AN0 – MUESTRA 3
AN1 – MUESTRA 3
AN2 – MUESTRA 3
AN7 – MUESTRA 4
AN0 – MUESTRA 4
AN1 – MUESTRA 4
AN2 – MUESTRA 4

© 2006 Microchip Technology Inc.
DS70183A-página 16-37
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.14
 EJEMPLOS DE SECUENCIA DE CONVERSIÓN
Los siguientes ejemplos de configuración muestran la operación A/D en diferentes muestreos y almacenamiento en búfer.
configuraciones. En cada ejemplo, al configurar el bit ASAM se inicia el muestreo automático. una conversión
El disparador finaliza el muestreo y comienza la conversión.
16.14.1
Muestreo y conversión de un solo canal varias veces
La Figura 16-17 y la Tabla 16-2 ilustran una configuración básica del ADC. En este caso, un ADC
La entrada, AN0, se muestrea mediante un canal de muestreo/retención, CH0, y se convierte. Los resultados se almacenan
en el búfer DMA configurado por el usuario, ilustrado como Buffer(0) a Buffer(15). este proceso
se repite 16 veces hasta que el búfer está lleno y luego el módulo ADC genera una interrupción. el
Luego se repite todo el proceso.
Los bits CHPS especifican que sólo está activo Sample/Hold CH0. Con ALTS limpio, sólo el MUX A
las entradas están activas. Los bits CH0SA y CH0NA se especifican (AN0-VREF-) como entrada al
Canal de muestra/retención. Todos los demás bits de selección de entrada no se utilizan.
Figura 16-17:
Conversión de un canal 16 veces/interrupción    
Reloj ADC
MUESTRA
Búfer[0]
TSAMP
TCONV
BSET AD1CON1,ASAM
Ejecución de instrucciones
Búfer[1]
HECHO
Búfer[2]
Búfer[15]
Entrada a CH0
AN0
TSAMP
TCONV
AN0
TSAMP
TCONV
AN0
TSAMP
TCONV
AN0
AD1IF
ASAM
Conversión
gatillo

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-38
© 2006 Microchip Technology Inc.
Tabla 16-2:
Conversión de un canal 16 veces por interrupción DMA       
BROCAS DE CONTROL
SECUENCIA DE OPERACIÓN
Seleccionar secuencia
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
SMPI<3:0> = 0000, AMODO = 00, DMAxCNT = 15
Interrupción DMA en la conversión 16
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere solicitud DMA
CHPS<1:0> = 00
Canal de muestra CH0
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
SIMSAM = n/a
escriba ADC1BUF0 y genere una solicitud DMA
No aplicable para muestra de un solo canal
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
BUFM = 0
Búfer de resultados único de 16 palabras
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
ALT = 0
Utilice siempre la selección de entrada MUX A
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
Selección de entrada MUX A
CH0SA<4:0> = 00000
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
Seleccione AN0 para entrada CH0+
CH0NA = 0
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
Seleccione VREF- para entrada CH0-
CSCNA = 0
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
Sin escaneo de entrada
CSSL<15:0> = n/a
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
Seleccionar entrada de escaneo sin usar
CH123SA = n/a
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
Canal CH1, CH2, CH3 + entrada no utilizada
escriba ADC1BUF0 y genere una solicitud DMA
CH123NA<1:0> = n/a
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0,
 escriba ADC1BUF0 y genere una solicitud DMA
Canal CH1, CH2, CH3 – entrada no utilizada
Selección de entrada MUX B
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
CH0SB<4:0> = n/a
Entrada del canal CH0+ no utilizada
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
CH0NB = n/a
Canal CH0- entrada no utilizada
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0,
 escriba ADC1BUF0 y genere una solicitud DMA
CH123SB = no disponible
Canal CH1, CH2, CH3 + entrada no utilizada
Entradas MUX A de muestra: AN0 -> CH0, Convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
CH123NB<1:0> = n/a
Canal CH1, CH2, CH3 – entrada no utilizada
Interrupción DMA
repetir
Búfer DMA @
Primera interrupción DMA
Búfer DMA @
Segunda interrupción DMA
AN0 Muestra 1
AN0 Muestra 17
AN0 Muestra 2
AN0 Muestra 18
AN0 Muestra 3
AN0 Muestra 19
AN0 Muestra 4
AN0 Muestra 20
AN0 Muestra 5
AN0 Muestra 21
AN0 Muestra 6
AN0 Muestra 22
AN0 Muestra 7
AN0 Muestra 23
AN0 Muestra 8
AN0 Muestra 24
AN0 Muestra 9
AN0 Muestra 25
AN0 Muestra 10
AN0 Muestra 26
AN0 Muestra 11
AN0 Muestra 27
AN0 Muestra 12
AN0 Muestra 28
AN0 Muestra 13
AN0 Muestra 29
AN0 Muestra 14
AN0 Muestra 30
AN0 Muestra 15
AN0 Muestra 31
AN0 Muestra 16
AN0 Muestra 32

© 2006 Microchip Technology Inc.
DS70183A-página 16-39
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.14.2
Conversiones A/D mientras se escanean todas las entradas analógicas
La Figura 16-18 y la Tabla 16-3 ilustran una configuración típica donde todos los canales de entrada analógica disponibles
son muestreados por un canal Sample/Hold, CH0, y convertidos. La selección de entrada de escaneo establecida
El bit (CSCNA) (ADxCON2<10>) especifica el escaneo de las entradas ADC a la entrada positiva CH0.
Otras condiciones son similares a las descritas en la Sección 16.14.1 “Muestreo y conversión
un solo canal varias veces”.
Inicialmente, la entrada AN0 es muestreada por CH0 y convertida. El resultado se almacena en la configuración de usuario.
búfer DMA almacenado. Luego se muestrea y convierte la entrada AN1. Este proceso de escanear el
inputs se repite 16 veces hasta que el buffer esté lleno. Entonces el módulo ADC genera una interrupción. el
Luego se repite todo el proceso.
Figura 16-18:
Escaneo a través de 16 entradas/interrupción    
Reloj ADC
MUESTRA
Búfer[0]
TSAMP
TCONV
BSET AD1CON1,#ASAM
Ejecución de instrucciones
Búfer[1]
HECHO
Búfer[2]
Búfer[15]
Entrada a CH0
AN0
TSAMP
TCONV
AN1
TSAMP
TCONV
AN14
TSAMP
TCONV
AN15
AD1IF
ASAM
Conversión
gatillo

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-40
© 2006 Microchip Technology Inc.
Tabla 16-3:
Escaneo a través de 16 entradas por interrupción DMA       
BROCAS DE CONTROL
SECUENCIA DE OPERACIÓN
Seleccionar secuencia
Entradas MUX A de muestra: AN0 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
SMPI<3:0> = 1111, AMODO = 00, DMAxCNT = 15
Interrupción DMA en la conversión 16
Entradas MUX A de muestra: AN1 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
CHPS<1:0> = 00
Entradas MUX A de muestra: AN2 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
Canal de muestra CH0
SIMSAM = n/a
Entradas MUX A de muestra: AN3 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
No aplicable para muestra de un solo canal
BUFM = 0
Entradas MUX A de muestra: AN4 -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
Búfer de resultados único de 16 palabras
ALT = 0
Entradas MUX A de muestra: AN5 -> CH0, convertir CH0,
escriba ADC1BUF0 y genere una solicitud DMA
Utilice siempre la selección de entrada MUX A
Selección de entrada MUX A
Entradas MUX A de muestra: AN6 -> CH0, convertir CH0,
escriba ADC1BUF0 y genere una solicitud DMA
CH0SA<4:0> = n/a
Anulación por CSCNA
Entradas MUX A de muestra: AN7 -> CH0, convertir CH0,
escriba ADC1BUF0 y genere una solicitud DMA
CH0NA = 0
Seleccione VREF- para entrada CH0-
Entradas MUX A de muestra: AN8 -> CH0, convertir CH0,
escriba ADC1BUF0 y genere una solicitud DMA
CSCNA = 1
Explorar entradas CH0+
Entradas MUX A de muestra: AN9 -> CH0, convertir CH0,
escriba ADC1BUF0 y genere una solicitud DMA
CSSL<15:0> = 1111 1111 1111 1111
16 entradas escaneadas
Entradas MUX A de muestra: AN10 -> CH0, convertir CH0,
escriba ADC1BUF0 y genere una solicitud DMA
CH123SA = n/a
Canal CH1, CH2, CH3 + entrada no utilizada
Entradas MUX A de muestra: AN11 -> CH0, convertir CH0,
escriba ADC1BUF0 y genere una solicitud DMA
CH123NA<1:0> = n/a
Canal CH1, CH2, CH3 – entrada no utilizada
Entradas MUX A de muestra: AN12 -> CH0, convertir CH0,
escriba ADC1BUF0 y genere una solicitud DMA
Selección de entrada MUX B
CH0SB<3:0> = n/a
Entradas MUX A de muestra: AN13 -> CH0, convertir CH0,
escriba ADC1BUF0 y genere una solicitud DMA
Entrada del canal CH0+ no utilizada
CH0NB = n/a
Entradas MUX A de muestra: AN14 -> CH0, convertir CH0,
escriba ADC1BUF0 y genere una solicitud DMA
Canal CH0- entrada no utilizada
CH123SB = no disponible
Entradas MUX A de muestra: AN15 -> CH0, convertir CH0,
escriba ADC1BUF0 y genere una solicitud DMA
Canal CH1, CH2, CH3 + entrada no utilizada
CH123NB<1:0> = n/a
interrumpir
Canal CH1, CH2, CH3 – entrada no utilizada
repetir
Búfer DMA @
Primera interrupción DMA
Búfer DMA @
Segunda interrupción DMA
AN0 Muestra 1
AN0 Muestra 17
AN1 Muestra 2
AN1 Muestra 18
AN2 Muestra 3
AN2 Muestra 19
AN3 Muestra 4
AN3 Muestra 20
AN4 Muestra 5
AN4 Muestra 21
AN5 Muestra 6
AN5 Muestra 22
AN6 Muestra 7
AN6 Muestra 23
AN7 Muestra 8
AN7 Muestra 24
AN8 Muestra 9
AN8 Muestra 25
AN9 Muestra 10
AN9 Muestra 26
AN10 Muestra 11
AN10 Muestra 27
AN11 Muestra 12
AN11 Muestra 28
AN12 Muestra 13
AN12 Muestra 29
AN13 Muestra 14
AN13 Muestra 30
AN14 Muestra 15
AN14 Muestra 31
AN15 Muestra 16
AN15 Muestra 32

© 2006 Microchip Technology Inc.
DS70183A-página 16-41
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.14.3
Muestreo frecuente de tres entradas mientras se escanean otras cuatro 
Entradas
La Figura 16-19 y la Tabla 16-4 muestran cómo se puede configurar el módulo ADC para muestrear tres
entradas que utilizan frecuentemente los canales Sample/Hold CH1, CH2 y CH3; mientras que otras cuatro entradas son
muestreados con menos frecuencia escaneándolos usando el canal Sample/Hold CH0. En este caso, sólo
Se utilizan entradas MUX A y los cuatro canales se muestrean simultáneamente. Cuatro entradas diferentes
(AN4, AN5, AN6, AN7) se escanean en CH0, mientras que AN0, AN1 y AN2 son las entradas fijas para
CH1, CH2 y CH3, respectivamente. Por lo tanto, en cada conjunto de 16 muestras, AN0, AN1 y AN2 son muestras.
se muestrearon cuatro veces, mientras que AN4, AN5, AN6 y AN7 se muestrearon sólo una vez cada uno.
Figura 16-19:
Conversión de tres entradas, cuatro veces y cuatro entradas, una vez/interrupción   
Reloj ADC
MUESTRA
HECHO
Entrada a CH0
AN4
TSAMP
AD1IF
TCONVTCONVTCONV
TCONV
AN0
AN1
AN2
Entrada a CH1
Entrada a CH2
Entrada a CH3
Búfer[13]
Búfer[14]
Búfer[15]
AN5
TSAMP
AN0
AN1
AN2
AN7
TSAMP
AN0
AN1
AN2
ASAM
AN4
AN0
AN1
AN2
Búfer[0]
Búfer[1]
Búfer[2]
Búfer[3]
Búfer[12]
AN6
AN0
AN1
AN2
Conversión
gatillo
TCONVTCONVTCONV
TCONV
TCONVTCONVTCONV
TCONV

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-42
© 2006 Microchip Technology Inc.
Tabla 16-4:
Conversión de tres entradas, cuatro veces y cuatro entradas, una vez por interrupción DMA       
BROCAS DE CONTROL
SECUENCIA DE OPERACIÓN
Seleccionar secuencia
Entradas MUX A de muestra:
SMPI<3:0> = 0011, AMODO = 00, DMAxCNT = 15
AN4 -> CH0, AN0 -> CH1, AN1 -> CH2, AN2 -> CH3
Escanee 4 entradas, interrumpa en la 16.ª conversión
Convierta CH0, escriba ADC1BUF0 y genere una solicitud DMA
CHPS<1:0> = 1x
Convierta CH1, escriba ADC1BUF0 y genere una solicitud DMA
Canales de muestra CH0, CH1, CH2, CH3
Convierta CH2, escriba ADC1BUF0 y genere una solicitud DMA
SIMSAM = 1
Convierta CH3, escriba ADC1BUF0 y genere una solicitud DMA
Muestra todos los canales simultáneamente
Entradas MUX A de muestra: 
BUFM = 0
AN5 -> CH0, AN0 -> CH1, AN1 -> CH2, AN2 -> CH3
Búfer de resultados único de 16 palabras
Convierta CH0, escriba ADC1BUF0 y genere una solicitud DMA
ALT = 0
Convierta CH1, escriba ADC1BUF0 y genere una solicitud DMA
Utilice siempre la selección de entrada MUX A
Convierta CH2, escriba ADC1BUF0 y genere una solicitud DMA
Selección de entrada MUX A
Convierta CH3, escriba ADC1BUF0 y genere una solicitud DMA
CH0SA<3:0> = n/a
Entradas MUX A de muestra: 
Anulación por CSCNA
AN6 -> CH0, AN0 -> CH1, AN1 -> CH2, AN2 -> CH3
CH0NA = 0
Convierta CH0, escriba ADC1BUF0 y genere una solicitud DMA
Seleccione VREF- para entrada CH0-
Convierta CH1, escriba ADC1BUF0 y genere una solicitud DMA
CSCNA = 1
Convierta CH2, escriba ADC1BUF0 y genere una solicitud DMA
Explorar entradas CH0+
Convierta CH3, escriba ADC1BUF0 y genere una solicitud DMA
CSSL<15:0> = 0000 0000 1111 0000
Entradas MUX A de muestra: 
Escanear AN4, AN5, AN6, AN7
AN7 -> CH0, AN0 -> CH1, AN1 -> CH2, AN2 -> CH3
CH123SA = 0
Convierta CH0, escriba ADC1BUF0 y genere una solicitud DMA
CH1+ = AN0, CH2+ = AN1, CH3+ = AN2
Convierta CH1, escriba ADC1BUF0 y genere una solicitud DMA
CH123NA<1:0> = 0x
Convierta CH2, escriba ADC1BUF0 y genere una solicitud DMA
CH1-, CH2-, CH3- = VREF-
Convierta CH3, escriba ADC1BUF0 y genere una solicitud DMA
Selección de entrada MUX B
interrumpir
CH0SB<3:0> = n/a
repetir
Entrada del canal CH0+ no utilizada
CH0NB = n/a
Canal CH0- entrada no utilizada
CH123SB = no disponible
Canal CH1, CH2, CH3 + entrada no utilizada
CH123NB<1:0> = n/a
Canal CH1, CH2, CH3 – entrada no utilizada
Búfer DMA @
Primera interrupción DMA
Búfer DMA @
Segunda interrupción DMA
AN4 Muestra 1
AN4 Muestra 2
AN0 Muestra 1
AN0 Muestra 5
AN1 Muestra 1
AN1 Muestra 5
AN2 Muestra 1
AN2 Muestra 5
AN5 Muestra 1
AN5 Muestra 2
AN0 Muestra 2
AN0 Muestra 6
AN1 Muestra 2
AN1 Muestra 6
AN2 Muestra 2
AN2 Muestra 6
AN6 Muestra 1
AN6 Muestra 2
AN0 Muestra 3
AN0 Muestra 7
AN1 Muestra 3
AN1 Muestra 7
AN2 Muestra 3
AN2 Muestra 7
AN7 Muestra 1
AN7 Muestra 2
AN0 Muestra 4
AN0 Muestra 8
AN1 Muestra 4
AN1 Muestra 8
AN2 Muestra 4
AN2 Muestra 8

© 2006 Microchip Technology Inc.
DS70183A-página 16-43
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.14.4
Uso de selecciones de entrada MUX A y MUX B alternas
La Figura 16-20 y la Tabla 16-5 demuestran un muestreo alternativo de las entradas asignadas al MUX A.
y MUX B. En este ejemplo, dos canales están habilitados para muestrear simultáneamente. Configurando el
El bit ALTS (ADCxCON2<0>) permite alternar selecciones de entrada. La primera muestra utiliza el MUX.
Entradas A especificadas por los bits CH0SA, CH0NA, CH123SA y CH123NA. La siguiente muestra utiliza
las entradas MUX B especificadas por los bits CH0SB, CH0NB, CH123SB y CH123NB. En este examen-
Por ejemplo, una de las especificaciones de entrada MUX B utiliza dos entradas analógicas como fuente diferencial para el
Muestra/Retención, muestreo (AN3-AN9).
Tenga en cuenta que el uso de cuatro canales Sample/Hold sin alternar selecciones de entrada da como resultado el
mismo número de conversiones que en este ejemplo, utilizando dos canales con selección de entrada alterna.
ciones. Sin embargo, debido a que los canales CH1, CH2 y CH3 tienen una selectividad más limitada
las entradas analógicas, este método de ejemplo proporciona más flexibilidad de selección de entrada que usar cuatro
canales.
Figura 16-20:
Conversión de dos conjuntos de dos entradas mediante selecciones de entrada alternas    
Reloj ADC
MUESTRA
Búfer[0]
Búfer[1]
HECHO
Búfer[2]
Búfer[3]
Entrada a 
AN1
TSAMP
ADxIF
TCONV
TCONV
AN0
Entrada a 
Búfer[4]
Búfer[5]
Búfer[6]
Búfer[7]
AN15
TSAMP
TCONV
TCONV
AN3-AN9
ASAM
BUFS
AN1
TSAMP
TCONV
TCONV
AN0
AN15
TSAMP
TCONV
TCONV
AN3-AN9
Búfer[8]
TCONV
TCONV
TSAMP
AN15
AN3-AN9
Borrado por software
CH0
CH1
Conversión
gatillo
Borrado
en software

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-44
© 2006 Microchip Technology Inc.
Tabla 16-5:
Conversión de dos conjuntos de dos entradas mediante selecciones de entrada alternas  
BROCAS DE CONTROL
SECUENCIA DE OPERACIÓN
Seleccionar secuencia
Entradas MUX A de muestra: AN1 -> CH0, AN0 -> CH1
SMPI<3:0> = 0001, AMODO = 00, DMAxCNT = 7
Convierta CH0, escriba ADC1BUF0 y genere una solicitud DMA
Alt. Muestreo, interrupción DMA en la octava conversión
Convierta CH1, escriba ADC1BUF0 y genere una solicitud DMA
CHPS<1:0> = 01
Entradas MUX B de muestra: AN15 -> CH0, (AN3-AN9) -> CH1
Canales de muestra CH0, CH1
Convierta CH0, escriba ADC1BUF0 y genere una solicitud DMA
SIMSAM = 1
Convierta CH1, escriba ADC1BUF0 y genere una solicitud DMA
Muestra todos los canales simultáneamente
Entradas MUX A de muestra: AN1 -> CH0, AN0 -> CH1
BUFM = 1
Convierta CH0, escriba ADC1BUF0 y genere una solicitud DMA
Búfers de resultados duales de 8 palabras
Convierta CH1, escriba ADC1BUF0 y genere una solicitud DMA
ALT = 1
Entradas MUX B de muestra: AN15 -> CH0, (AN3-AN9) -> CH1
Selección de entrada MUX A/B alternativa
Convierta CH0, escriba ADC1BUF0 y genere una solicitud DMA
Selección de entrada MUX A
Convierta CH1, escriba ADC1BUF0 y genere una solicitud DMA
CH0SA<3:0> = 0001
interrumpir
Seleccione AN1 para entrada CH0+
repetir
CH0NA = 0
Seleccione VREF- para entrada CH0-
CSCNA = 0
Sin escaneo de entrada
CSSL<15:0> = n/a
Seleccionar entrada de escaneo sin usar
CH123SA = 0
CH1+ = AN0, CH2+ = AN1, CH3+ = AN2
CH123NA<1:0> = 0x
CH1-, CH2-, CH3- = VREF-
Selección de entrada MUX B
CH0SB<3:0> = 1111
Seleccione AN15 para entrada CH0+
CH0NB = 0
Seleccione VREF- para entrada CH0-
CH123SB = 1
CH1+ = AN3, CH2+ = AN4, CH3+ = AN5
CH123NB<1:0> = 11
CH1- = AN9, CH2- = AN10, CH3- = AN11
Búfer DMA @
Primera interrupción DMA
Búfer DMA @
Segunda interrupción DMA
AN1 Muestra 1
AN1 Muestra 3
AN0 Muestra 1
AN0 Muestra 3
AN15 Muestra 1
AN15 Muestra 3
(AN3-AN9) Muestra 1
(AN3-AN9) Muestra 3
AN1 Muestra 2
AN1 Muestra 4
AN0 Muestra 2
AN0 Muestra 4
AN15 Muestra 2
AN15 Muestra 4
(AN3-AN9) Muestra 2
(AN3-AN9) Muestra 4

© 2006 Microchip Technology Inc.
DS70183A-página 16-45
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.14.5
Muestreo de ocho entradas mediante muestreo simultáneo
Este y el siguiente ejemplo demuestran configuraciones idénticas con la excepción de que este ejemplo
utiliza muestreo simultáneo (SIMSAM = 1), y el siguiente ejemplo utiliza muestreo secuencial
pling (SIMSAM = 0). Ambos ejemplos utilizan entradas alternas y especifican entradas diferenciales para el
Muestra/Retención.
La Figura 16-21 y la Tabla 16-6 demuestran el muestreo simultáneo. Al convertir más de
un canal y seleccionando muestreo simultáneo, el módulo ADC muestrea todos los canales, luego
realiza las conversiones requeridas en secuencia. En este ejemplo, con ASAM configurado, el muestreo comienza
después de que se completen las conversiones.
Figura 16-21:
Muestreo de ocho entradas mediante muestreo simultáneo    
Reloj ADC
MUESTRA
HECHO
Entrada a CH0
AN13-AN1
TSAMP
AD1IF
AN0
AN1
AN2
Entrada a CH1
Entrada a CH2
Entrada a CH3
Búfer[13]
Búfer[14]
Búfer[15]
AN14
TSAMP
AN3-AN6
AN4-AN7
AN5-AN8
AN14
TSAMP
AN3-AN6
AN4-AN7
AN5-AN8
ASAM
AN13-AN1
AN0
AN1
AN2
Búfer[0]
Búfer[1]
Búfer[2]
Búfer[3]
Búfer[12]
Conversión
gatillo
TCONVTCONVTCONV
TCONV
TCONVTCONVTCONV
TCONV
TCONVTCONVTCONV
TCONV

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-46
© 2006 Microchip Technology Inc.
Tabla 16-6:
Muestreo de ocho entradas mediante muestreo simultáneo       
BROCAS DE CONTROL
SECUENCIA DE OPERACIÓN
Seleccionar secuencia
Entradas MUX A de muestra: 
SMPI<3:0> = 0001, AMODO = 00, DMAxCNT = 15
(AN13-AN1) -> CH0, AN0 -> CH1, AN1 -> CH2, AN2 -> CH3
Alt. muestreo, interrupción DMA en la conversión 16
Convierta CH0, escriba ADC1BUF0 y genere una solicitud DMA
CHPS<1:0> = 1x
Convierta CH1, escriba ADC1BUF0 y genere una solicitud DMA
Canales de muestra CH0, CH1, CH2, CH3
Convierta CH2, escriba ADC1BUF0 y genere una solicitud DMA
SIMSAM = 1
Convierta CH3, escriba ADC1BUF0 y genere una solicitud DMA
Muestra todos los canales simultáneamente
Entradas MUX B de muestra: 
BUFM = 0
AN14 -> CH0, 
Búfer de resultados único de 16 palabras
(AN3-AN6) -> CH1, (AN4-AN7) -> CH2, (AN5-AN8) -> CH3
ALT = 1
Convierta CH0, escriba ADC1BUF0 y genere una solicitud DMA
Selección de entrada alternativa MUX A/MUX B
Convierta CH1, escriba ADC1BUF0 y genere una solicitud DMA
Selección de entrada MUX A
Convierta CH2, escriba ADC1BUF0 y genere una solicitud DMA
CH0SA<3:0> = 1101
Convierta CH3, escriba ADC1BUF0 y genere una solicitud DMA
Seleccione AN13 para entrada CH0+
Entradas MUX A de muestra: 
CH0NA = 1
(AN13-AN1) -> CH0, AN0 -> CH1, AN1 -> CH2, AN2 -> CH3
Seleccione AN1 para entrada CH0
Convierta CH0, escriba ADC1BUF0 y genere una solicitud DMA
CSCNA = 0
Convierta CH1, escriba ADC1BUF0 y genere una solicitud DMA
Sin escaneo de entrada
Convierta CH2, escriba ADC1BUF0 y genere una solicitud DMA
CSSL<15:0> = n/a
Convierta CH3, escriba ADC1BUF0 y genere una solicitud DMA
Seleccionar entrada de escaneo sin usar
Entradas MUX B de muestra: 
CH123SA = 0
AN14 -> CH0, 
CH1+ = AN0, CH2+ = AN1, CH3+ = AN2
(AN3-AN6) -> CH1, (AN4-AN7) -> CH2, (AN5-AN8) -> CH3
CH123NA<1:0> = 0x
Convierta CH0, escriba ADC1BUF0 y genere una solicitud DMA
CH1-, CH2-, CH3- = VREF-
Convierta CH1, escriba ADC1BUF0 y genere una solicitud DMA
Selección de entrada MUX B
Convierta CH2, escriba ADC1BUF0 y genere una solicitud DMA
CH0SB<3:0> = 1110
Convierta CH3, escriba ADC1BUF0 y genere una solicitud DMA
Seleccione AN14 para entrada CH0+
interrumpir
CH0NB = 0
repetir
Seleccione VREF- para entrada CH0-
CH123SB = 1
CH1+ = AN3, CH2+ = AN4, CH3+ = AN5
CH123NB<1:0> = 10
CH1- = AN6, CH2- = AN7, CH3- = AN8
Búfer DMA @
Primera interrupción DMA
Búfer DMA @
Segunda interrupción DMA
(AN13-AN1) Muestra 1
(AN13-AN1) Muestra 3
AN0 Muestra 1
AN0 Muestra 3
AN1 Muestra 1
AN1 Muestra 3
AN2 Muestra 1
AN2 Muestra 3
AN14 Muestra 1
AN14 Muestra 3
(AN3-AN6) Muestra 1
(AN3-AN6) Muestra 3
(AN4-AN7) Muestra 1
(AN4-AN7) Muestra 3
(AN5-AN8) Muestra 1
(AN5-AN8) Muestra 3
(AN13-AN1) Muestra 1
(AN13-AN1) Muestra 4
AN0 Muestra 2
AN0 Muestra 4
AN1 Muestra 2
AN1 Muestra 4
AN2 Muestra 2
AN2 Muestra 4
AN14 Muestra 2
AN14 Muestra 4
(AN3-AN6) Muestra 2
(AN3-AN6) Muestra 4
(AN4-AN7) Muestra 2
(AN4-AN7) Muestra 4
(AN5-AN8) Muestra 2
(AN5-AN8) Muestra 4

© 2006 Microchip Technology Inc.
DS70183A-página 16-47
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.14.6
Muestreo de ocho entradas mediante muestreo secuencial
La Figura 16-22 y la Tabla 16-7 demuestran el muestreo secuencial. Al convertir más de uno
canal y seleccionando el muestreo secuencial, el módulo ADC comienza a muestrear un canal en el
lo antes posible y luego realiza las conversiones requeridas en secuencia. En este ejemplo, con
Conjunto ASAM, el muestreo de un canal comienza después de que se completa la conversión de ese canal. 
Cuando ASAM está claro, el muestreo no se reanuda después de completar la conversión, sino que ocurre cuando
el bit SAMP está establecido.
Cuando se utiliza más de un canal, el muestreo secuencial proporciona más tiempo de muestreo ya que
Se puede muestrear un canal mientras se produce la conversión en otro.
Figura 16-22:
Muestreo de ocho entradas mediante muestreo secuencial    
Reloj ADC
MUESTRA
HECHO
Entrada a CH0
AN13-AN1
TSAMP
AD1IF
AN0
AN1
AN2
Entrada a CH1
Entrada a CH2
Entrada a CH3
Búfer[13]
Búfer[14]
Búfer[15]
AN14
TSAMP
AN4-AN7
AN5-AN8
AN14
TSAMP
AN3-AN6
AN4-AN7
AN5-AN8
ASAM
AN1
AN2
Búfer[0]
Búfer[1]
Búfer[2]
Búfer[3]
Búfer[12]
AN13-AN1
AN0
AN2
Conversión
gatillo
TCONVTCONVTCONV
TCONV
TCONVTCONVTCONV
TCONV
TCONVTCONVTCONV
TCONV
AN3-AN6
AN1
AN13-AN1
AN0

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-48
© 2006 Microchip Technology Inc.
Tabla 16-7:
Muestreo de ocho entradas mediante muestreo secuencial       
BROCAS DE CONTROL
SECUENCIA DE OPERACIÓN
Seleccionar secuencia
Muestra: (AN13-AN1) -> CH0, convertir CH0, 
escriba ADC1BUF0 y genere una solicitud DMA
SMPI<3:0> = 0001, AMODO = 00, DMAxCNT = 15
Alt. muestreo, interrupción DMA en la muestra 16
 Muestra: AN0 -> CH1, convertir CH0,
CHPS<1:0> = 1x
escriba ADC1BUF0 y genere una solicitud DMA
Canales de muestra CH0, CH1, CH2, CH3
 Muestra: AN1 -> CH2, convertir CH0,
SIMSAM = 0
 escriba ADC1BUF0 y genere una solicitud DMA
Muestreo de todos los canales secuencialmente
Muestra: AN2 -> CH3, convertir CH0,
BUFM = 0
 escriba ADC1BUF0 y genere una solicitud DMA
Búfer de resultados único de 16 palabras
Muestra: AN14 -> CH0, convertir CH0,
ALT = 1
 escriba ADC1BUF0 y genere una solicitud DMA
Selección de entrada MUX A/B alternativa
Muestra: (AN3-AN6) -> CH1, convertir CH0,
Selección de entrada MUX A
escriba ADC1BUF0 y genere una solicitud DMA
CH0SA<3:0> = 0110
Muestra: (AN4-AN7) -> CH2, convertir CH0,
Seleccione AN6 para entrada CH0+
escriba ADC1BUF0 y genere una solicitud DMA
CH0NA = 0
Muestra: (AN5-AN8) -> CH3, convertir CH0,
Seleccione VREF- para entrada CH0-
escriba ADC1BUF0 y genere una solicitud DMA
CSCNA = 0
Muestra: (AN13-AN1) -> CH0, convertir CH0,
Sin escaneo de entrada
escriba ADC1BUF0 y genere una solicitud DMA
CSSL<15:0> = n/a
Muestra: AN0 -> CH1, convertir CH0,
Seleccionar entrada de escaneo sin usar
 escriba ADC1BUF0 y genere una solicitud DMA
CH123SA = 0
Muestra: AN1 -> CH2, convertir CH0,
CH1+ = AN0, CH2+ = AN1, CH3+ = AN2
escriba ADC1BUF0 y genere una solicitud DMA
CH123NA<1:0> = 0x
Muestra: AN2 -> CH3, convertir CH0,
CH1-, CH2-, CH3- = VREF-
escriba ADC1BUF0 y genere una solicitud DMA
Selección de entrada MUX B
Muestra: AN14 -> CH0, convertir CH0,
CH0SB<3:0> = 0111
escriba ADC1BUF0 y genere una solicitud DMA
Seleccione AN7 para entrada CH0+
Muestra: (AN3-AN6) -> CH1, convertir CH0,
CH0NB = 0
escriba ADC1BUF0 y genere una solicitud DMA
Seleccione VREF- para entrada CH0-
Muestra: (AN4-AN7) -> CH2, convertir CH0,
CH123SB = 1
escriba ADC1BUF0 y genere una solicitud DMA
CH1+ = AN3, CH2+ = AN4, CH3+ = AN5
Muestra: (AN5-AN8) -> CH3, convertir CH0,
CH123NB<1:0> = 0x
escriba ADC1BUF0 y genere una solicitud DMA
CH1-, CH2-, CH3- = VREF-
interrumpir
repetir
Búfer DMA @
Primera interrupción DMA
Búfer DMA @
Segunda interrupción DMA
(AN13-AN1) Muestra 1
(AN13-AN1) Muestra 3
AN0 Muestra 1
AN0 Muestra 3
AN1 Muestra 1
AN1 Muestra 3
AN2 Muestra 1
AN2 Muestra 3
AN14 Muestra 1
AN14 Muestra 3
(AN3-AN6) Muestra 1
(AN3-AN6) Muestra 3
(AN4-AN7) Muestra 1
(AN4-AN7) Muestra 3
(AN5-AN8) Muestra 1
(AN5-AN8) Muestra 3
(AN13-AN1) Muestra 2
(AN13-AN1) Muestra 4
AN0 Muestra 2
AN0 Muestra 4
AN1 Muestra 2
AN1 Muestra 4
AN2 Muestra 2
AN2 Muestra 28
AN14 Muestra 2
AN14 Muestra 4
(AN3-AN6) Muestra 2
(AN3-AN6) Muestra 4
(AN4-AN7) Muestra 2
(AN4-AN7) Muestra 4
(AN5-AN8) Muestra 2
(AN5-AN8) Muestra 4

© 2006 Microchip Technology Inc.
DS70183A-página 16-49
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.15
 REQUISITOS DE MUESTREO A/D
El modelo de entrada analógica de los modos ADC de 10 y 12 bits se muestra en la Figura 16-23 y
Figura 16-24. El tiempo total de muestreo para la conversión A/D es función del amplificador interno.
tiempo de estabilización y el tiempo de carga del condensador de retención.
Para que el módulo ADC cumpla con su precisión especificada, el capacitor de retención de carga (CHOLD) debe
se le permitirá cargar completamente al nivel de voltaje en el pin de entrada analógica. La fuente de salida analógica
impedancia (RS), la impedancia de interconexión (RIC) y el interruptor de muestreo interno (RSS)
La impedancia se combina para afectar directamente el tiempo necesario para cargar el condensador CHOLD. La com-
Por lo tanto, la impedancia combinada debe ser lo suficientemente pequeña como para cargar completamente el capacitor de retención dentro de
el tiempo de muestra elegido. Para minimizar los efectos de las corrientes de fuga de las clavijas en la precisión del
Módulo ADC, la impedancia de fuente máxima recomendada, RS, es 200Ω. Después del analógico
Cuando se selecciona el canal de entrada, esta función de muestreo debe completarse antes de iniciar la conversión.
sión. El condensador de retención interno estará descargado antes de cada operación de muestra.
Se debe permitir un período de tiempo mínimo entre conversiones para el tiempo de muestra. Para más
Para obtener más información sobre el tiempo mínimo de muestreo de un dispositivo, consulte las especificaciones eléctricas del dispositivo.
Figura 16-23:
Modelo de entrada analógica (modo de 10 bits)
Figura 16-24:
Modelo de entrada analógica (modo de 12 bits)
PIN
VA
Rs
ANx
TV = 0,6 V
TV = 0,6 V
me fuga
RIC ≤ 250Ω
Muestreo
Cambiar
RSS
CHOLD
= capacitancia DAC
VSS
VDD
= 4,4 pF
± 500 nA
Leyenda: CPIN
TV
me fuga
RIC
RSS
CHOLD
= capacitancia de entrada
= tensión umbral
= corriente de fuga en el pin debido a
= resistencia de interconexión
= resistencia del interruptor de muestreo
= Capacitancia de muestra/retención (de DAC)
varios cruces
Nota: El valor del CPIN depende del paquete del dispositivo y no se prueba. El efecto del CPIN es insignificante si Rs ≤ 500 Ω.
RSS ≤ 3kΩ
PIN
VA
Rs
ANx
TV = 0,6 V
TV = 0,6 V
me fuga
RIC ≤ 250Ω
Muestreo
Cambiar
RSS
CHOLD
= capacitancia DAC
VSS
VDD
= 18 pF
± 500 nA
Leyenda: CPIN
TV
me fuga
RIC
RSS
CHOLD
= capacitancia de entrada
= tensión umbral
= corriente de fuga en el pin debido a
= resistencia de interconexión
= resistencia del interruptor de muestreo
= Capacitancia de muestra/retención (de DAC)
varios cruces
Nota: El valor del CPIN depende del paquete del dispositivo y no se prueba. El efecto del CPIN es insignificante si Rs ≤ 5 kΩ.
RSS ≤ 3kΩ

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-50
© 2006 Microchip Technology Inc.
16.16
 LECTURA DEL BUFFER DE RESULTADOS DEL ADC
La RAM tiene 10 o 12 bits de ancho, pero los datos se formatean automáticamente en uno de los cuatro seleccionados.
formatos compatibles cuando se lee el buffer. Los bits FORM<1:0> (ADCON1<9:8>) seleccionan el formato.
El hardware de formateo proporciona un resultado de 16 bits en el bus de datos para todos los formatos de datos.
La Figura 16-25 y la Figura 16-26 muestran los formatos de salida de datos que se pueden seleccionar usando el
FORMATO<1:0> bits de control. 
Figura 16-25:
Formatos de datos de salida A/D (modo de 10 bits)
Figura 16-26:
Formatos de datos de salida A/D (modo de 12 bits)
Contenido de RAM:
d09 d08 d07 d06 d05 d04 d03 d02 d01 d00
Leer al autobús:
Entero
0
0
0
0
0
0
d09 d08 d07 d06 d05 d04 d03 d02 d01 d00
Entero con signo
d09 d09 d09 d09 d09 d09 d09 d08 d07 d06 d05 d04 d03 d02 d01 d00
Fraccionado (1.15)
d09 d08 d07 d06 d05 d04 d03 d02 d01 d00
0
0
0
0
0
0
Fraccionado firmado (1.15)
d09 d08 d07 d06 d05 d04 d03 d02 d01 d00
0
0
0
0
0
0
Contenido de RAM:
d11 d10 d09 d08 d07 d06 d05 d04 d03 d02 d01 d00
Leer al autobús:
Entero
0
0
0
0
d11 d10 d09 d08 d07 d06 d05 d04 d03 d02 d01 d00
Entero con signo
d11 d11 d11 d11 d11 d10 d09 d08 d07 d06 d05 d04 d03 d02 d01 d00
fraccionario
d11 d10 d09 d08 d07 d06 d05 d04 d03 d02 d01 d00
0
0
0
0
Fraccionado firmado (1.15)
d11 d10 d09 d08 d07 d04 d03 d02 d01 d00 d01 d00
0
0
0
0

© 2006 Microchip Technology Inc.
DS70183A-página 16-51
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
Tabla 16-8:
Equivalentes numéricos de varios códigos de resultados (modo de 10 bits)
Tabla 16-9:
Equivalentes numéricos de varios códigos de resultados (modo de 12 bits)
VIN/VREF
10 bits
Código de salida
Formato entero de 16 bits
16 bits firmado
Formato entero
Formato fraccionario de 16 bits
16 bits firmado
Formato fraccionario
1023/1024
11 1111 
1111
0000 0011 1111 
1111
= 1023
0000 0001 1111 
1111
= 511
1111 1111 1100 
0000
= 0,999
0111 1111 1100 
0000
= 0,499
1022/1024
11 1111 
1110
0000 0011 1111 
1110
= 1022
0000 0001 1111 
1110
= 5 10
1111 1111 1000 
0000
= 0,998
0111 1111 1000 
0000
= 0,498
• • •
513/1024
10 0000 
0001
0000 0010 0000 
0001
= 513
0000 0000 0000 
0001
= 1
1000 0000 0100 
0000
= 0,501
0 000 0000 0100 
0000
= 0,001
512/1024
10 0000 
0000
0000 0010 0000 
0000
= 512
0000 0000 0000 
0000
= 0 
1000 0000 0000 
0000
= 0,500
0000 0000 0000 
0000
= 0,000
511/1024
01 1111 
1111
0000 0001 1111 
1111
= 511
1111 1111 1111 
1111
= -1
0111 1111 1100 
0000
= .499
1111 1111 1100 
0000
= -0,001
• • •
1/1024
00 0000 
0001
0000 0000 0000 
0001
= 1
1111 1110 0000 
0001
= -511
0000 0000 0100 
0000
= 0,001
1000 0000 0100 
0000
= -0,499
0/1024
00 0000 
0000
0000 0000 0000 
0000
= 0
1111 1110 0000 
0000
= -512
0000 0000 0000 
0000
= 0,000
1000 0000 0000 
0000
= -0,500
VIN/VREF
12 bits
Código de salida
16 bits sin firmar
Formato entero
16 bits firmado
Formato entero
16 bits sin firmar
Formato fraccionario
16 bits firmado
Formato fraccionario
4095/4096
1111 1111 
1111
0000 1111 1111 
1111
= 4095
0000 0111 1111 
1111
= 2047
1111 1111 1111 
0000
= 0,9998
0111 1111 1111 
0000
= 0,9995
4094/4096
1111 1111 
1110
0000 1111 1111 
1110
= 4094
0000 0111 1111 
1110
= 2046
1111 1111 1110 
0000
= 0,9995
0111 1111 1110 
0000
= 0,9990
• • •
2049/4096
1000 0000 
0001
0000 1000 0000 
0001
= 2049
0000 0000 0000 
0001
= 1
1000 0000 0001 
0000
= 0,5002
0000 0000 0001 
0000
= 0,0005
2048/4096
1000 0000 
0000
0000 1000 0000 
0000
= 2048
0000 0000 0000 
0000
= 0
1000 0000 0000 
0000
= 0,500
0000 0000 0000 
0000
= 0,000
2047/4096
0111 1111 
1111
0000 0111 1111 
1111
= 2047
1111 1111 1111 
1111
= -1
0111 1111 1111 
0000
= 0,4998
1111 1111 1111 
0000
= -0,0005
• • •
1/4096
0000 0000 
0001
0000 0000 0000 
0001
= 1
1111 1000 0000 
0001
= -2047
0000 0000 0001 
0000
= 0,0002
1000 0000 0001 
0000
= -0,9995
0/4096
0000 0000 
0000
0000 0000 0000 
0000
= 0
1111 1000 0000 
0000
= -2048
0000 0000 0000 
0000
= 0,000
1000 0000 0000 
0000
= -1.000

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-52
© 2006 Microchip Technology Inc.
16.17
 FUNCIÓN DE TRANSFERENCIA (MODO DE 10 BITS)
La función de transferencia ideal del módulo ADC se muestra en la Figura 16-27. La diferencia de la
Los voltajes de entrada, (VINH – VINL), se comparan con la referencia, (VREFH – VREFL).
• La primera transición de código (A) ocurre cuando el voltaje de entrada es (VREFH – VREFL/2048) o 0,5 
LSB. 
• El código 00 0000 0001 está centrado en (VREFH – VREFL/1024) o 1,0 LSb (B). 
• El código 10 0000 0000 está centrado en (512*(VREFH – VREFL)/1024) (C).
• Un voltaje de entrada inferior a (1*(VREFH – VREFL)/2048) se convierte como 00 0000 0000 (D).
• Una entrada mayor que (2045*(VREFH – VREFL)/2048) se convierte como 11 1111 1111 (E).
Figura 16-27:
Función de transferencia del módulo ADC (modo de 10 bits) 
10 0000 0010 (= 514)
10 0000 0011 (= 515)
01 1111 1101 (= 509)
01 1111 1110 (= 510)
01 1111 1111 (= 511)
11 1111 1110 (= 1022)
11 1111 1111 (= 1023)
00 0000 0000 (= 0)
00 0000 0001 (= 1)
Salida 
Código
10 0000 0000 (= 512)
(VINH-VINL)
VREFL
VREFH – VREFL
1024
VREFH
VREFL +
10 0000 0001 (= 513)
512*(VREFH – VREFL)
1024
VREFL +
1023*(VREFH – VREFL)
1024
VREFL +
(A)
(B)
(C)
(D)
(mi)

© 2006 Microchip Technology Inc.
DS70183A-página 16-53
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.18
 FUNCIÓN DE TRANSFERENCIA (MODO DE 12 BITS)
La función de transferencia ideal del ADC se muestra en la Figura 16-27. La diferencia del voltaje de entrada
Se comparan las edades (VINH – VINL) con la referencia (VREFH – VREFL).
• La primera transición de código (A) ocurre cuando el voltaje de entrada es (VREFH – VREFL/8192) o 0,5 
LSB. 
• El código 00 0000 0001 está centrado en (VREFH – VREFL/4096) o 1,0 LSb (B). 
• El código 10 0000 0000 está centrado en (2048*(VREFH – VREFL)/4096) (C).
• Un voltaje de entrada inferior a (1*(VREFH – VREFL)/8192) se convierte como 00 0000 0000 (D).
• Una entrada mayor que (8192*(VREFH – VREFL)/8192) se convierte como 11 1111 1111 (E).
Figura 16-28:
Función de transferencia A/D (modo de 12 bits) 
1000 0000 0001 (= 2049)
1000 0000 0010 (= 2050)
1000 0000 0011 (= 2051)
0111 1111 1101 (= 2045)
0111 1111 1110 (= 2046)
0111 1111 1111 (= 2047)
1111 1111 1110 (= 4094)
1111 1111 1111 (= 4095)
0000 0000 0000 (= 0)
0000 0000 0001 (= 1)
Salida 
Código
1000 0000 0000 (= 2048)
(VINH-VINL)
VREFL
VREFH – VREFL
4096
2048*(VREFH – VREFL)
4096
VREFH
VREFL +
VREFL +
(A)
(B)
(C)
(D)
(mi)

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-54
© 2006 Microchip Technology Inc.
16.19
 PRECISIÓN/ERROR DEL ADC
Consulte la Sección 16.26 “Notas de aplicación relacionadas” para obtener una lista de documentos que analizan ADC
precisión.
16.20
 CONSIDERACIONES DE CONEXIÓN   
Dado que las entradas analógicas emplean protección ESD, tienen diodos para VDD y VSS. Como resultado,
la entrada analógica debe estar entre VDD y VSS. Si el voltaje de entrada excede este rango por mayor
superior a 0,3 V (en cualquier dirección), uno de los diodos se polariza directamente y puede dañar el
dispositivo si se excede la especificación de corriente de entrada.
A veces se agrega un filtro RC externo para suavizar la señal de entrada. El componente R
deben seleccionarse para garantizar que se cumplan los requisitos de tiempo de muestreo. Cualquier externo
componentes conectados (a través de alta impedancia) a un pin de entrada analógica (condensador, diodo zener, etc.)
debe tener muy poca corriente de fuga en el pin.
16.21
 EJEMPLOS DE CÓDIGO
Aquí se describen dos ejemplos de código que demuestran escenarios típicos de uso de ADC:
16.21.1
Escaneo de canales usando DMA
El ejemplo 16-4 configura un canal DMA para almacenar 32 resultados ADC en el modo Scatter/Gather.
El ADC está configurado para escanear cuatro entradas analógicas (AN0, AN1, AN2, AN3), proporcionando así ocho
muestras de cada entrada en el buffer DMA.
16.21.2
Muestreo alternativo usando DMA
El ejemplo 16-5 realiza un muestreo alternativo de dos entradas analógicas (AN4, AN5) y almacena el
da como resultado un buffer DMA de 32 palabras usando el modo Scatter/Gather.

© 2006 Microchip Technology Inc.
DS70183A-página 16-55
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
Ejemplo 16-4:
Código para escaneo de canales usando DMA
/************************************************************************
* © 2005 Microchip Technology Inc.
*
* Nombre de archivo: adcDrv1.c
* Dependencias: archivos de encabezado (.h) si corresponde, consulte a continuación
* Procesador: dsPIC33Fxxxx
* Compilador: MPLAB® C30 v2.01.00 o superior
*
* CONTRATO DE LICENCIA DE SOFTWARE:
* Microchip Technology Inc. (“Microchip”) le concede la licencia de este software únicamente para su uso con
* Productos de controlador de señal digital Microchip dsPIC®. El software es propiedad de Microchip.
* y está protegido por las leyes de derechos de autor aplicables.  Reservados todos los derechos.
*
* EL SOFTWARE SE PROPORCIONA "TAL CUAL".  MICROCHIP RENUNCIA EXPRESAMENTE A CUALQUIER GARANTÍA DE CUALQUIER TIPO, 
* YA SEA EXPRESA O IMPLÍCITA, INCLUYENDO PERO NO LIMITADO A, LAS GARANTÍAS IMPLÍCITAS DE
* COMERCIABILIDAD, IDONEIDAD PARA UN FIN PARTICULAR O NO INFRACCIÓN. EN NINGÚN CASO
* MICROCHIP SERÁ RESPONSABLE DE CUALQUIER DAÑO INCIDENTAL, ESPECIAL, INDIRECTO O CONSECUENTE, PÉRDIDA
* GANANCIAS O PÉRDIDA DE DATOS, DAÑOS A SU EQUIPO, COSTO DE ADQUISICIÓN DE BIENES SUSTITUTOS, 
* TECNOLOGÍA O SERVICIOS, CUALQUIER RECLAMACIÓN DE TERCEROS (INCLUYENDO PERO NO LIMITADO A CUALQUIER 
* DEFENSA DEL MISMO), CUALQUIER RECLAMACIÓN DE INDEMNIZACIÓN O CONTRIBUCIÓN, U OTROS COSTOS SIMILARES.
*
********************************************************************************************/
#si está definido(__dsPIC33F__)
#include "p33fxxxx.h"
#elif definido(__PIC24H__)
#include "p24hxxxx.h"
#endif
void ProcessADCSamples(unsigned int * AdcBuffer);
/*=============================================================================================
Inicialización de ADC para escaneo de canales 
==============================================================================================*/
vacío initAdc1 (void)
{
AD1CON1bits.FORM = 3;
// Formato de salida de datos: fracción firmada (formato Q15)
AD1CON1bits.SSRC = 2;
// Fuente de reloj de muestra: GP Timer inicia la conversión
AD1CON1bits.ASAM = 1;
// Control de muestra ADC: el muestreo comienza inmediatamente después de la conversión
AD1CON1bits.AD12B = 0;
// operación ADC de 10 bits
AD1CON1bits.SIMSAM = 0; 
// Muestra múltiples canales individualmente en secuencia
AD1CON2bits.BUFM = 0;
AD1CON2bits.CSCNA = 1;
// Explorar selecciones de entrada para CH0+ durante el bit de muestra A
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
// MUXA -ve selección de entrada (Vref-) para CH0

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-56
© 2006 Microchip Technology Inc.
Ejemplo 16-4:
Código para escaneo de canales usando DMA (continuación)
//AD1CHS123: Registro de selección de entrada A/D
AD1CHS123bits.CH123SA = 0;
// Selección de entrada MUXA +ve (AIN0) para CH1
AD1CHS123bits.CH123NA = 0;
// MUXA -ve selección de entrada (Vref-) para CH1
//AD1CSSH/AD1CSSL: Registro de selección de escaneo de entrada A/D
AD1CSSH = 0x0000;
AD1CSSL = 0x000F;
// Escanear entradas AIN0, AIN1, AIN2, AIN3
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
}
/*=========================================================================================== 
El temporizador 3 está configurado para que se agote cada 125 microsegundos (velocidad de 8 Khz). Como resultado, el módulo 
detendrá el muestreo y activará una conversión en cada tiempo de espera del Timer3, es decir, Ts=125us. 
=================================================================================================*/
anular initTmr3() 
{
TMR3 = 0x0000;
PR3 = 4999;
// Activa ADC1 cada 125 usos
IFS0bits.T3IF = 0;
// Borrar interrupción del temporizador 3
IEC0bits.T3IE = 0;
// Deshabilitar la interrupción del temporizador 3
T3CONbits.TON = 1;
//Iniciar temporizador 3
}
// El vinculador asignará estos buffers desde la parte inferior de la RAM DMA.
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
} BufferB __attribute__((espacio(dma)));;
// configuración DMA0
// Dirección: leer desde la dirección periférica 0-x300 (ADC1BUF0) y escribir en DMA RAM 
// AMODE: Modo de direccionamiento indirecto periférico
// MODO: Continuo, Modo Ping-Pong
// IRQ: Interrupción ADC

© 2006 Microchip Technology Inc.
DS70183A-página 16-57
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
Ejemplo 16-4:
Código para escaneo de canales usando DMA (continuación)
vacío initDma0 (void)
{
DMA0CONbits.AMODE = 2;
// Configurar DMA para modo indirecto periférico
DMA0CONbits.MODO = 2;
// Configurar DMA para el modo Ping-Pong continuo
DMA0PAD = 0x0300;
// Apunta DMA a ADC1BUF0
DMA0CNT = 31;
// 32 solicitudes DMA (4 buffers, cada uno con 8 palabras)
DMA0REQ = 13;
// Seleccione ADC1 como fuente de solicitud DMA
DMA0STA = __builtin_dmaoffset(&BufferA);
DMA0STB = __builtin_dmaoffset(&BufferB);
IFS0bits.DMA0IF = 0;
//Borra el bit de bandera de interrupción DMA
    IEC0bits.DMA0IE = 1;
//Establece el bit de habilitación de interrupción DMA
DMA0CONbits.CHEN=1;
// Habilitar DMA
}
/*============================================================================================
_DMA0Interrupt(): el nombre ISR se elige del script del vinculador de dispositivos.
=====================================================================================================*/
int sin firmar DmaBuffer = 0;
void __attribute__((__interrupt__)) _DMA0Interrupt(void)
{
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
IFS0bits.DMA0IF = 0;
//Borrar el indicador de interrupción DMA0
}
void ProcessADCSamples(int sin firmar * AdcBuffer)
{
/* Hacer algo con muestras ADC */
}

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-58
© 2006 Microchip Technology Inc.
Ejemplo 16-5:
Código para muestreo alternativo usando DMA
/*********************************************************************************************
* © 2005 Microchip Technology Inc.
*
* Nombre de archivo: adcDrv1.c
* Dependencias: archivos de encabezado (.h) si corresponde, consulte a continuación
* Procesador: dsPIC33Fxxxx
* Compilador: MPLAB® C30 v2.01.00 o superior
*
* CONTRATO DE LICENCIA DE SOFTWARE:
* Microchip Technology Inc. (“Microchip”) le concede la licencia de este software únicamente para su uso con 
* Productos de controlador de señal digital Microchip dsPIC®. El software es propiedad de Microchip. 
* y está protegido por las leyes de derechos de autor aplicables.  Reservados todos los derechos.
* *
* EL SOFTWARE SE PROPORCIONA "TAL CUAL".  MICROCHIP RENUNCIA EXPRESAMENTE A CUALQUIER GARANTÍA DE CUALQUIER TIPO, 
* YA SEA EXPRESA O IMPLÍCITA, INCLUYENDO PERO NO LIMITADO A, LAS GARANTÍAS IMPLÍCITAS DE 
* COMERCIABILIDAD, IDONEIDAD PARA UN FIN PARTICULAR O NO INFRACCIÓN. EN NINGÚN CASO 
* MICROCHIP SERÁ RESPONSABLE DE CUALQUIER DAÑO INCIDENTAL, ESPECIAL, INDIRECTO O CONSECUENTE, 
* PÉRDIDA DE GANANCIAS O PÉRDIDA DE DATOS, DAÑO A SU EQUIPO, COSTO DE ADQUISICIÓN DE BIENES SUSTITUTOS, 
* TECNOLOGÍA O SERVICIOS, CUALQUIER RECLAMACIÓN DE TERCEROS (INCLUYENDO PERO NO LIMITADO A 
* CUALQUIER DEFENSA DEL MISMO), CUALQUIER RECLAMACIÓN DE INDEMNIZACIÓN O CONTRIBUCIÓN, U OTROS COSTOS SIMILARES.
*
********************************************************************************************/
#si está definido(__dsPIC33F__)
#include "p33fxxxx.h"
#elif definido(__PIC24H__)
#include "p24hxxxx.h"
#endif
#include "adcDrv1.h"
#include "tglPin.h"
// Definir la longitud del búfer de mensajes para ECAN1/ECAN2
#definir MAX_CHNUM 5
// Número de entrada analógica más alto habilitado para muestreo alternativo
#definir SAMP_BUFF_SIZE 16
// Tamaño del buffer de entrada por entrada analógica
// Número de ubicaciones para el búfer ADC = 2 (AN4 y AN5) x 16 = 32 palabras
// Alinea el búfer a 32 palabras o 64 bytes. Esto es necesario para el modo indirecto periférico.
int BufferA[MAX_CHNUM+1][SAMP_BUFF_SIZE] __attribute__((espacio(dma),alineado(64)));
int BufferB[MAX_CHNUM+1][SAMP_BUFF_SIZE] __attribute__((espacio(dma),alineado(64)));
void ProcessADCSamples(int * AdcBuffer);
/*================================================================================
Inicialización de ADC para escaneo de canales 
===============================================================================*/
vacío initAdc1 (void)
{
AD1CON1bits.FORM = 3;
// Formato de salida de datos: fracción firmada (formato Q15)
AD1CON1bits.SSRC = 2;
// Fuente de reloj de muestra: GP Timer inicia la conversión
AD1CON1bits.ASAM = 1;
// Control de muestra ADC: el muestreo comienza inmediatamente después de la conversión
AD1CON1bits.AD12B = 0;
// operación ADC de 10 bits
AD1CON2bits.ALTS=1;
// Bit de selección de modo de muestra de entrada alternativa
AD1CON2bits.CHPS = 0;
// Convierte CH0

© 2006 Microchip Technology Inc.
DS70183A-página 16-59
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
Ejemplo 16-5:
Código para muestreo alternativo usando DMA (continuación)
AD1CON3bits.ADRC = 0;
// El reloj ADC se deriva del reloj de sistemas
AD1CON3bits.ADCS = 63;
// Reloj de conversión ADC Tad=Tcy*(ADCS+1)=(1/40M)*64 = 1.6us(625Khz)
// Tiempo de conversión de ADC para 10 bits Tc=12*Tab = 19,2us
AD1CON1bits.ADDMABM = 0; // Los buffers DMA están construidos en modo dispersión/reunión
AD1CON2bits.SMPI = 1;
// SMPI debe programarse en 1 para este caso
AD1CON4bits.DMABL = 4;
// Cada buffer contiene 16 palabras
//AD1CHS0: Registro de selección de entrada A/D
AD1CHS0bits.CH0SA=4;
// Selección de entrada MUXA +ve (AIN4) para CH0
AD1CHS0bits.CH0NA=0;
// MUXA -ve selección de entrada (Vref-) para CH0
AD1CHS0bits.CH0SB=5;
// selección de entrada MUXB +ve (AIN5) para CH0
AD1CHS0bits.CH0NB=0;
// MUXB -ve selección de entrada (Vref-) para CH0
//AD1PCFGH/AD1PCFGL: Registro de configuración de puerto
AD1PCFGL=0xFFFF;
AD1PCFGH=0xFFFF;
AD1PCFGLbits.PCFG4 = 0;
// AN4 como entrada analógica
AD1PCFGLbits.PCFG5 = 0;
// AN5 como entrada analógica
        
IFS0bits.AD1IF = 0;
// Borra el bit de bandera de interrupción A/D
IEC0bits.AD1IE = 0;
// No habilitar la interrupción A/D 
AD1CON1bits.ADON = 1;
//Enciende el convertidor A/D
tglPinInit();
}
/*============================================================================================ 
El temporizador 3 está configurado para que se agote cada 125 microsegundos (velocidad de 8 Khz). Como resultado, el módulo 
detendrá el muestreo y activará una conversión en cada tiempo de espera del Timer3, es decir, Ts=125us. 
========================================================================================================*/
anular initTmr3() 
{
TMR3 = 0x0000;
PR3 = 4999;
IFS0bits.T3IF = 0;
IEC0bits.T3IE = 0;
//Iniciar temporizador 3
T3CONbits.TON = 1;
}
// configuración DMA0
// Dirección: leer desde la dirección periférica 0-x300 (ADC1BUF0) y escribir en DMA RAM 
// AMODE: Modo de direccionamiento indirecto periférico
// MODO: Continuo, Modo Ping-Pong
// IRQ: Interrupción ADC
// ADC almacena los resultados almacenados alternativamente entre DMA_BASE[0]/DMA_BASE[16] en cada 16ª solicitud de DMA 
vacío initDma0 (void)
{
DMA0CONbits.AMODE = 2;
// Configurar DMA para modo indirecto periférico
DMA0CONbits.MODO = 2;
// Configurar DMA para el modo Ping-Pong continuo
DMA0PAD=(int)&ADC1BUF0;
DMA0CNT = (SAMP_BUFF_SIZE*2)-1;

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-60
© 2006 Microchip Technology Inc.
Ejemplo 16-5:
Código para muestreo alternativo usando DMA (continuación)
DMA0REQ=13;
DMA0STA = __builtin_dmaoffset(&BufferA[0][0]);
DMA0STB = __builtin_dmaoffset(&BufferB[0][0]);
IFS0bits.DMA0IF = 0;
//Borra el bit de bandera de interrupción DMA
    IEC0bits.DMA0IE = 1;
//Establece el bit de habilitación de interrupción DMA
DMA0CONbits.CHEN=1;
}
/*============================================================================================
_DMA0Interrupt(): el nombre ISR se elige del script del vinculador de dispositivos.
=================================================================================================*/
int sin firmar DmaBuffer = 0;
void __attribute__((__interrupt__)) _DMA0Interrupt(void)
{
   
si(DmaBuffer==0) {
ProcessADCSamples(&BufferA[4][0]);
ProcessADCSamples(&BufferA[5][0]);
} más {
ProcessADCSamples(&BufferB[4][0]);
ProcessADCSamples(&BufferB[5][0]);
}
DmaBuffer ^= 1;
tglPin();
// Alternar PORTA, BIT0
        IFS0bits.DMA0IF = 0;//Borrar el indicador de interrupción DMA0
}
void ProcessADCSamples(int * AdcBuffer)
{
/* Hacer algo con muestras ADC */
}

© 2006 Microchip Technology Inc.
DS70183A-página 16-61
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.22
 FUNCIONAMIENTO DURANTE LOS MODOS DE SUSPENSIÓN E INACTIVO 
Los modos de suspensión e inactividad son útiles para minimizar el ruido de conversión porque la actividad digital de
Se minimiza la CPU, buses y otros periféricos.
16.22.1
Modo de suspensión de CPU sin reloj RC A/D
Cuando el dispositivo ingresa al modo de suspensión, todas las fuentes de reloj del módulo ADC se apagan y
permanezca en el '0' lógico.
Si la suspensión ocurre en medio de una conversión, la conversión se cancela a menos que el ADC esté
sincronizado desde su generador de reloj RC interno. El convertidor no reanuda un funcionamiento parcialmente
La conversión se completó al salir del modo de suspensión.
El contenido del registro no se ve afectado por el hecho de que el dispositivo entre o salga del modo de suspensión.
16.22.2
Modo de suspensión de CPU con reloj RC A/D
El módulo ADC puede funcionar durante el modo de suspensión si la fuente de reloj A/D está configurada en el modo A/D interno.
Oscilador RC (ADRC = 1). Esto elimina el ruido de conmutación digital de la conversión. cuando el
se completa la conversión, se establece el bit DONE y el resultado se carga en el búfer de resultados del ADC,
ADCBUF. 
Si la interrupción del ADC está habilitada (ADxIE = 1), el dispositivo se reactiva del modo de suspensión cuando el ADC
se produce la interrupción. La ejecución del programa se reanuda en la Rutina de Servicio de Interrupción del ADC si el ADC
La interrupción es mayor que la prioridad actual de la CPU. De lo contrario, la ejecución continúa desde el
instrucción después de la instrucción PWRSAV que colocó el dispositivo en modo de suspensión. 
Si la interrupción ADC no está habilitada, el módulo ADC se apaga, aunque el bit ADON permanece
conjunto.
Para minimizar los efectos del ruido digital en el funcionamiento del módulo ADC, el usuario debe seleccionar un
fuente de activación de conversión que garantiza que la conversión A/D se realizará en modo de suspensión. el
La opción de activación de conversión automática se puede utilizar para muestreo y conversión en suspensión.
(SSRC<2:0> = 111). Para utilizar la opción de conversión automática, el bit ADON debe configurarse en el
instrucción antes de la instrucción PWRSAV.
16.22.3
Operación de ADC durante el modo inactivo de la CPU
Para la conversión A/D, el bit ADSIDL (ADxCON1<13>) selecciona si el módulo ADC se detiene o continúa.
continúa en inactivo. Si ADSIDL = 0, el módulo ADC continúa funcionando normalmente cuando el dispositivo
ingresa al modo inactivo. Si la interrupción ADC está habilitada (ADxIE = 1), el dispositivo se reactiva desde Inactivo
modo cuando se produce la interrupción del ADC. La ejecución del programa se reanuda en el servicio de interrupción del ADC
Rutina si la interrupción del ADC es mayor que la prioridad actual de la CPU. De lo contrario, la ejecución continúa.
continúa desde la instrucción posterior a la instrucción PWRSAV que colocó el dispositivo en modo inactivo.
Si ADSIDL = 1, el módulo ADC se detiene en inactivo. Si el dispositivo entra en modo inactivo en medio de una
conversión, la conversión se cancela. El convertidor no reanuda un proceso parcialmente completado.
conversión al salir del modo inactivo.
Nota:
Para que el módulo ADC funcione en suspensión, la fuente de reloj ADC debe estar configurada en RC
(ADRC = 1).

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-62
© 2006 Microchip Technology Inc.
16.23
 EFECTOS DE UN RESET
Un reinicio del dispositivo fuerza a todos los registros a su estado de reinicio. Esto obliga a girar el módulo ADC.
apagado y cualquier conversión en curso será abortada. Todos los pines que están multiplexados con entradas analógicas.
están configurados como entradas analógicas. Se activan los bits TRIS correspondientes.
El valor en el registro ADCxBUF0 no se inicializa durante un reinicio de encendido y contiene
datos desconocidos.
16.24
 REGISTROS DE FUNCIONES ESPECIALES ASOCIADOS AL ADC
La siguiente tabla enumera los registros de funciones especiales del ADC dsPIC33F, incluidas sus direcciones y
formatos. Todos los registros y/o bits no implementados dentro de un registro se leen como ceros.

© 2006 Microchip Technology Inc.
DS70183A-página 16-63
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
Tabla 16-10:
Mapa de registro ADC
Nombre de archivo
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
Reiniciar 
Estados
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
ADC1BUF0
0300
Búfer de datos ADC1
uuuuu
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
—
—
ADCS<5:0>
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
AD1PCFGH
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
AD1CSSH
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
ADC2BUF0
0340
Búfer de datos ADC2
uuuuu
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
—
—
ADCS<5:0>
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
tu = desconocido
Nota:
Es posible que no todas las fuentes de interrupción y sus bits de control asociados estén disponibles en un dispositivo en particular. Consulte la hoja de datos del dispositivo para obtener más detalles.

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-64
© 2006 Microchip Technology Inc.
16.25
 CONSEJOS DE DISEÑO
Pregunta 1:
¿Cómo puedo optimizar el rendimiento del sistema del módulo ADC? 
Respuesta:
1.
Asegúrese de cumplir con todas las especificaciones de sincronización. Si está activando el modo ADC
La regla se enciende y se apaga, hay un retraso mínimo que debe esperar antes de tomar una muestra. si lo eres
Al cambiar los canales de entrada, hay un retraso mínimo, por lo que también debes esperar. Finalmente,
está el TAD, que es el tiempo seleccionado para cada conversión de bits. TAD está seleccionado en ADCON3
y debe estar dentro del rango especificado en las Características Eléctricas. Si TAD es demasiado
En resumen, es posible que el resultado no se convierta completamente antes de que finalice la conversión. Si TAD es
demasiado tiempo, el voltaje en el capacitor de muestreo puede disminuir antes de que se complete la conversión.
completo. Estas especificaciones de sincronización se proporcionan en la sección "Especificaciones eléctricas" de
las hojas de datos del dispositivo. 
2.
A menudo, la impedancia de la fuente de la señal analógica es alta (superior a 10 kΩ), por lo que la
La corriente extraída de la fuente para cargar el condensador de muestra puede afectar la precisión. si el
Para que la señal de entrada no cambie demasiado rápido, intente colocar un condensador de 0,1 μF en la entrada analógica.
Este condensador se carga al voltaje analógico que se está muestreando y suministra el
corriente instantánea necesaria para cargar el condensador de retención interno de 4,4 pF. 
3.
Coloque el dispositivo en modo de suspensión antes de iniciar la conversión A/D. El reloj RC
Se requiere selección de fuente para conversiones en modo de suspensión. Esta técnica aumenta
precisión porque se minimiza el ruido digital de la CPU y otros periféricos.
Pregunta 2:
¿Conoce una buena referencia sobre los ADC?
Respuesta: Una buena referencia para comprender las conversiones A/D es el “Conversor analógico-digital”.
Handbook”, tercera edición, publicada por Prentice Hall (ISBN 0-13-03-2848-0).
Pregunta 3:
Mi combinación de canales/muestra y muestras/interrupción es mayor que
el tamaño del búfer. ¿Qué pasará con el búfer?
Respuesta: No se recomienda esta configuración. El búfer contendrá resultados desconocidos.

© 2006 Microchip Technology Inc.
DS70183A-página 16-65
Sección 16. Convertidor analógico a digital (ADC)
CAD
16
16.26
 NOTAS DE APLICACIÓN RELACIONADAS
Esta sección enumera las notas de aplicación relacionadas con esta sección del manual. Estos
Es posible que las notas de aplicación no estén escritas específicamente para la familia de productos dsPIC33F, pero el
Los conceptos son pertinentes y podrían usarse con modificaciones y posibles limitaciones. la corriente
Las notas de aplicación relacionadas con el módulo ADC son:
Título 
Nota de aplicación #
Uso del convertidor analógico a digital (A/D)
AN546
Voltímetro digital de cuatro canales con pantalla y teclado 
AN557
Comprensión de las especificaciones de rendimiento del convertidor A/D 
AN693
Uso del dsPIC30F para control BLDC sin sensores 
AN901
Uso del dsPIC30F para el control vectorial de un ACIM
AN908
Control de motor BLDC con sensor utilizando el dsPIC30F2010
AN957
Introducción al control de motores de inducción de CA mediante el MCU dsPIC30F
AN984
Nota:
Visite el sitio web de Microchip (www.microchip.com) para obtener información adicional sobre aplicaciones.
Notas y ejemplos de código para la familia de dispositivos dsPIC33F.

Manual de referencia de la familia dsPIC33F
DS70183A-página 16-66
© 2006 Microchip Technology Inc.
16.27
 HISTORIAL DE REVISIONES
Revisión A (diciembre de 2006)
Esta es la publicación inicial de este documento.
