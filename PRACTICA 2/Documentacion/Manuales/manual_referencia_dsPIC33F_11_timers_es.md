# Traducción de d:\Escritorio\INFORMATICA\ARQUITECTURA DE COMPUTADORAS\PRACTICA 2\manual_referencia_dsPIC33F_11_timers.pdf

© 2007-2011 Microchip Technology Inc.
DS70205D-página 11-1
Temporizadores
11
Sección 11. Temporizadores
DESTACADOS
Esta sección del manual contiene los siguientes temas principales:
11.1
Introducción ................................................................................................................ 11-2
11.2
Variantes del temporizador................................................................................................. 11-3
11.3
Registros de control ........................................................................................................ 11-6
11.4
Modos de operación ................................................................................................ 11-10
11.5
Interrupciones del temporizador................................................................................................ 11-15
11.6
Configuración del temporizador de 32 bits................................................................................ 11-15
11.7
Modos de funcionamiento del temporizador de 32 bits ................................................................. 11-18
11.8
Operación del temporizador en modos de ahorro de energía ................................................. 11-20
11.9
Periféricos que utilizan módulos temporizadores................................................................. 11-21
11.10 Mapa de registro................................................................................................................ 11-22
11.11 Notas de aplicación relacionadas................................................................................ 11-23
11.12 Historial de revisiones................................................................................................ 11-24

Manual de referencia de la familia dsPIC33F/PIC24H
DS70205D-página 11-2
© 2007-2011 Microchip Technology Inc.
11.1
 INTRODUCCIÓN
La familia de dispositivos dsPIC33F/PIC24H ofrece varios módulos de temporizador de 16 bits. con ciertos 
Con excepciones, todos los temporizadores de 16 bits tienen el mismo circuito funcional y se clasifican en tres tipos. 
según sus diferencias funcionales:
• Temporizador tipo A (Temporizador1)
• Temporizador tipo B (Timer2, Timer4, Timer6 y Timer8), al que se hace referencia como Timerx
• Temporizador tipo C (Timer3, Timer5, Timer7 y Timer9), al que se le denomina Timery
Los temporizadores tipo B y tipo C se pueden combinar para formar un temporizador de 32 bits. 
Cada módulo de temporizador es un temporizador/contador de 16 bits que consta de los siguientes elementos legibles/escribibles. 
registros:
• TMRn: registro de recuento de temporizador de 16 bits
• PRn: registro de período de temporizador de 16 bits asociado al temporizador
• TnCON: Registro de control del temporizador de 16 bits asociado al temporizador
Cada módulo temporizador también tiene estos bits asociados para el control de interrupciones: 
• Bit de control de habilitación de interrupción (TnIE)
• Bit de estado de indicador de interrupción (TnIF) 
• Bits de control de prioridad de interrupción (TnIP<2:0>)
Nota:
Esta sección del manual de referencia familiar está destinada a servir como complemento al dispositivo. 
hojas de datos. Dependiendo de la variante del dispositivo, es posible que esta sección del manual no se aplique a 
todos los dispositivos dsPIC33F/PIC24H.
Consulte la nota al comienzo del capítulo "Temporizadores" en la publicación actual. 
hoja de datos del dispositivo para comprobar si este documento es compatible con el dispositivo que está 
usando.
Las hojas de datos del dispositivo y las secciones del manual de referencia familiar están disponibles para 
descárguelo del sitio web de Microchip Worldwide en: http://www.microchip.com.
Nota 1: Cada variante de dispositivo dsPIC33F/PIC24H puede tener uno o más módulos de temporizador. Para 
Para más detalles, consulte las hojas de datos específicas del dispositivo.
2: Una 'n' utilizada en los nombres de pines, bits de control/estado y registros denota todos los temporizadores 
(n = 1 a 9).
3: Una 'x' utilizada en los nombres de pines, bits de control/estado y registros denota el 
número particular de temporizador Tipo B (x = 2, 4, 6 y 8).
4: Una 'y' utilizada en los nombres de pines, bits de control/estado y registros denota el 
número particular de temporizador Tipo C (y = 3, 5, 7 y 9).

© 2007-2011 Microchip Technology Inc.
DS70205D-página 11-3
Sección 11. Temporizadores
Temporizadores
11
11.2
 VARIANTES DEL TEMPORIZADOR
Esta sección describe los diferentes tipos de temporizadores disponibles en la familia de dispositivos dsPIC33F/PIC24H. 
dispositivos.
11.2.1
Escriba un temporizador
Timer1 es un temporizador de tipo A. Un temporizador tipo A tiene las siguientes características únicas sobre otros tipos de 
temporizadores:
• Puede operarse desde el oscilador de cristal de 32 kHz de baja potencia disponible en el dispositivo
• Puede funcionar en modo Contador asíncrono desde una fuente de reloj externa
• Opcionalmente, la entrada del reloj externo (T1CK) se puede sincronizar con el reloj interno del dispositivo. 
y la sincronización del reloj se realiza después de que el preescalador divide T1CK. el 
La ventaja de la sincronización del reloj después de la división por el preescalador se explica en 
11.4.3 “Modo contador síncrono”.
Las características únicas del temporizador tipo A permiten su uso para aplicaciones de reloj en tiempo real (RTC). 
La Figura 11-1 muestra el diagrama de bloques de un temporizador Tipo A.
Figura 11-1:
Diagrama de bloques del temporizador tipo A 
Nota
1:
FCY es el reloj del ciclo de instrucción.
2:
Consulte la Sección 7. “Oscilador” (DS70186), para obtener información sobre cómo habilitar el oscilador secundario.
TGATE
TCS
00
10
x1
TMR1
Comparador
PR1
TGATE
Establecer bandera T1IF
0
1
SINCRONIZACIÓN
1
0
Sincronizar
igual
Reiniciar
Preescalador
(/n)
TCKPS<1:0>
Puerta
Sincronizar
FCY
(1)
Borde descendente 
detectar
Preescalador
(/n)
TCKPS<1:0>
LPOSCEN(2)
pestillo
CLK
DATOS
SOSCO/
T1CK
SOSCI

Manual de referencia de la familia dsPIC33F/PIC24H
DS70205D-página 11-4
© 2007-2011 Microchip Technology Inc.
11.2.2
Temporizador tipo B
Timer2, Timer4, Timer6 y Timer8, si están presentes, son temporizadores de tipo B. Un temporizador tipo B consta de 
siguientes características específicas:
• Puede concatenarse con un temporizador tipo C para formar un temporizador de 32 bits
• La entrada del reloj externo (TxCK) siempre está sincronizada con el reloj interno del dispositivo y 
La sincronización del reloj se realiza después de que el preescalador divide TxCK. la ventaja 
La sincronización del reloj después de la división por el preescalador se explica en 
11.4.3 “Modo contador síncrono”.
La Figura 11-2 muestra un diagrama de bloques del temporizador Tipo B.
Figura 11-2:
Diagrama de bloques del temporizador tipo B 
Nota
1:
FCY es el reloj del ciclo de instrucción.
TGATE
TCS
00
x1
TMRx
Comparador
PRx
TGATE
Establecer bandera TxIF
0
1
Sincronizar
igual
Reiniciar
Preescalador
(/n)
TCKPS<1:0>
Puerta
Sincronizar
FCY
(1)
Borde descendente 
detectar
Preescalador
(/n)
TCKPS<1:0>
pestillo
CLK
DATOS
TXCK
10

© 2007-2011 Microchip Technology Inc.
DS70205D-página 11-5
Sección 11. Temporizadores
Temporizadores
11
11.2.3
Temporizador tipo C
Timer3, Timer5, Timer7 y Timer9, si están presentes, son temporizadores tipo C. Un temporizador tipo C tiene la 
siguientes características específicas:
• Puede concatenarse con un temporizador tipo B para formar un temporizador de 32 bits
• Al menos un temporizador tipo C tiene la capacidad de activar una conversión de analógico a digital
• La entrada del reloj externo (TyCK) siempre está sincronizada con el reloj interno del dispositivo. el 
La sincronización del reloj se realiza utilizando TyCK, después de lo cual este reloj sincronizado se 
dividido por el preescalador.
La Figura 11-3 muestra un diagrama de bloques del temporizador Tipo C. 
Figura 11-3:
Diagrama de bloques del temporizador tipo C 
TGATE
TCS
00
x1
TMRy
Comparador
PRy
TGATE
Establecer bandera TyIF
0
1
Sincronizar
igual
Reiniciar
Preescalador
(/n)
TCKPS<1:0>
Puerta
Sincronizar
FCY
(1)
Borde descendente 
detectar
Preescalador
(/n)
TCKPS<1:0>
pestillo
CLK
DATOS
TYCK
CAD Inicio de
Activador de conversión(2)
Nota
1:
FCY es el reloj del ciclo de instrucción.
2:
El disparador ADC solo está disponible en TMR3 y TMR5.
10

Manual de referencia de la familia dsPIC33F/PIC24H
DS70205D-página 11-6
© 2007-2011 Microchip Technology Inc.
11.3
 REGISTROS DE CONTROL
Esta sección describe las funciones de registros de control de temporizador específicos:
• T1CON: Registro de control del temporizador tipo A
Este registro controla la configuración de un temporizador tipo A.
• TxCON: Registro de control de temporizador tipo B (x = 2, 4, 6, 8)
Este registro controla la configuración de un temporizador tipo B.
• TyCON: Registro de control de temporizador tipo C (y = 3, 5, 7, 9)
Este registro controla la configuración de un temporizador tipo C.
Además de los registros anteriores, cada temporizador tiene asociados los siguientes registros de 16 bits:
• PRn: Registro de período del temporizador (n = 1 a 9)
Este es el registro del período del temporizador de 16 bits.
• TMRn: Registro de recuento del temporizador (n = 1 a 9)
Este es el registro de conteo del temporizador de 16 bits.

© 2007-2011 Microchip Technology Inc.
DS70205D-página 11-7
Sección 11. Temporizadores
Temporizadores
11
 
Registro 11-1:
T1CON: Registro de control del temporizador tipo A
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
TON: Temporizador encendido bit
1 = Inicia el temporizador
0 = Detiene el temporizador
poco 14
No implementado: leído como "0"
poco 13
TSIDL: bit de parada en modo inactivo
1 = Interrumpir la operación del temporizador cuando el dispositivo ingresa al modo inactivo
0 = Continuar la operación del temporizador en modo inactivo
bit 12-7
No implementado: leído como "0"
poco 6
TGATE: Bit de habilitación de acumulación de tiempo activado por temporizador
Cuando TCS = 1:
Este bit se ignora
Cuando TCS = 0:
1 = Acumulación de tiempo activada
0 = Acumulación de tiempo de puerta deshabilitada
bit 5-4
TCKPS<1:0>: Bits de selección de preescala de reloj de entrada de temporizador
11 = 1:256 valor de preescala
10 = valor preescala 1:64
01 = valor de preescala 1:8
00 = valor de preescala 1:1
poco 3
No implementado: leído como "0"
poco 2
TSYNC: bit de selección de sincronización de entrada de reloj externo del temporizador
Cuando TCS = 1: 
1 = Sincronizar entrada de reloj externo
0 = No sincronizar la entrada del reloj externo
Cuando TCS = 0: 
Este bit se ignora. Leer como '0'. Timerx usa el reloj interno cuando TCS = 0
poco 1
TCS: Bit de selección de fuente de reloj del temporizador
1 = Reloj externo del pin TxCK
0 = Reloj interno (FOSC/2)
poco 0
No implementado: leído como "0"

Manual de referencia de la familia dsPIC33F/PIC24H
DS70205D-página 11-8
© 2007-2011 Microchip Technology Inc.
 
Registro 11-2:
TxCON: Registro de control de temporizador tipo B (x = 2, 4, 6, 8)
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
TONELADA: Timerx activado bit
Cuando T32 = 1 (en modo Temporizador de 32 bits):
1 = Inicia el par de temporizadores TMRx:TMRy(1) de 32 bits
0 = Detiene el par de temporizadores TMRx:TMRy(1) de 32 bits
Cuando T32 = 0 (en modo Temporizador de 16 bits):
1 = Inicia el temporizador de 16 bits
0 = Detiene el temporizador de 16 bits
poco 14
No implementado: leído como "0"
poco 13
TSIDL: bit de parada en modo inactivo
1 = Interrumpir la operación del temporizador cuando el dispositivo ingresa al modo inactivo
0 = Continuar la operación del temporizador en modo inactivo
bit 12-7
No implementado: leído como "0"
poco 6
TGATE: bit de habilitación de acumulación de tiempo activado Timerx
Cuando TCS = 1:
Este bit se ignora
Cuando TCS = 0:
1 = Acumulación de tiempo activada
0 = Acumulación de tiempo de puerta deshabilitada
bit 5-4
TCKPS<1:0>: Bits de selección de preescala de reloj de entrada Timerx
11 = 1:256 valor de preescala
10 = valor preescala 1:64
01 = valor de preescala 1:8
00 = valor de preescala 1:1
poco 3
T32: bit de selección de modo Timerx de 32 bits
1 = TMRx y TMRy(1) forman un temporizador de 32 bits
0 = TMRx y TMRy(1) forman temporizadores de 16 bits separados
poco 2
No implementado: leído como "0"
poco 1
TCS: Bit de selección de fuente de reloj Timerx
1 = Reloj externo del pin TxCK
0 = Reloj interno (FOSC/2)
poco 0
No implementado: leído como "0" 
Nota 1:
TMRy es un temporizador tipo C (y = 3, 5, 7 y 9).

© 2007-2011 Microchip Technology Inc.
DS70205D-página 11-9
Sección 11. Temporizadores
Temporizadores
11
 
Registro 11-3:
TyCON: Registro de control de temporizador tipo C (y = 3, 5, 7, 9)
R/W-0
U-0
R/W-0
U-0
U-0
U-0
U-0
U-0
TONELADA(2)
 —
TSIDL(1)
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
 PUERTA TG(2)
TCKPS<1:0>(2)
—
—
TC(2)
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
TON: Temporizador activado bit(2)
1 = Inicia el temporizador de 16 bits
0 = Detiene el temporizador de 16 bits
poco 14
No implementado: leído como "0"
poco 13
TSIDL: Detener en modo inactivo bit(1)
1 = Interrumpir la operación del temporizador cuando el dispositivo ingresa al modo inactivo
0 = Continuar la operación del temporizador en modo inactivo
bit 12-7
No implementado: leído como "0"
poco 6
TGATE: Bit de habilitación de acumulación de tiempo activado por temporizador (2)
Cuando TCS = 1:
Este bit se ignora
Cuando TCS = 0:
1 = Acumulación de tiempo activada
0 = Acumulación de tiempo de puerta deshabilitada
bit 5-4
TCKPS<1:0>: Bits de selección de preescala de reloj de entrada de temporizador(2)
11 = 1:256 valor de preescala
10 = valor preescala 1:64
01 = valor de preescala 1:8
00 = valor de preescala 1:1
bit 3-2
No implementado: leído como "0"
poco 1
TCS: Bit de selección de fuente de reloj temporizador (2)
1 = Reloj externo del pin TyCK
0 = Reloj interno (FOSC/2)
poco 0
No implementado: leído como "0" 
Nota 1:
Cuando se habilita la operación del temporizador de 32 bits (T32 = 1) en el registro de control del temporizador tipo B (TxCON<3>), el 
El bit TSIDL debe borrarse para operar el temporizador de 32 bits en modo inactivo.
2:
Estos bits no tienen ningún efecto cuando la operación del temporizador de 32 bits está habilitada (T32 = 1) en el Control de temporizador tipo B 
registro (TxCON<3>).

Manual de referencia de la familia dsPIC33F/PIC24H
DS70205D-página 11-10
© 2007-2011 Microchip Technology Inc.
11.4
 MODOS DE OPERACIÓN
El módulo Temporizador puede funcionar en uno de los siguientes modos:
• Modo temporizador
• Modo de temporizador cerrado
• Modo contador síncrono
• Modo contador asíncrono (sólo temporizador tipo A)
En los modos Temporizador y Temporizador cerrado, el reloj de entrada se deriva del ciclo de instrucción interno. 
reloj (FCY). En los modos de contador síncrono y asíncrono, el reloj de entrada se deriva de 
la entrada del reloj externo en el pin TxCK.
Los modos del temporizador están determinados por los siguientes bits:
• TCS (TnCON<1>): Bit de control de fuente de reloj del temporizador
• TSYNC (T1CON<2>): bit de control de sincronización del temporizador (sólo temporizador tipo A)
• TGATE (TnCON<6>): Bit de control de puerta del temporizador
La configuración de los bits de control del temporizador para diferentes modos de funcionamiento se proporciona en la Tabla 11-1, a continuación:
El reloj de entrada (FCY o TnCK) para todos los temporizadores de 16 bits tiene opciones de preescala de 1:1, 1:8, 1:64 y 1:256. 
El preescalador del reloj se selecciona utilizando los bits del preescalador del reloj del temporizador (TCKPS) en el temporizador. 
Registro de control (TnCON<5:4>). El contador del preescalador se borra cuando cualquiera de las siguientes 
ocurre:
• Una escritura en el registro del temporizador (TMRn) o en el registro de control del temporizador (TnCON)
• Borrar el bit de habilitación del temporizador (TON) en el registro de control del temporizador (TnCON<15>)
• Restablecer cualquier dispositivo
El módulo Temporizador se habilita o deshabilita usando el bit TON (TnCON<15>).
11.4.1
Modo temporizador
En el modo Temporizador, el reloj de entrada al temporizador se deriva del reloj interno (FCY), dividido por un 
Preescalador programable. Cuando el temporizador está habilitado, aumenta en uno en cada flanco ascendente 
del reloj de entrada y genera una interrupción en un partido de período. La figura 11-4 ilustra el temporizador. 
operación.
Para configurar el modo Temporizador:
• Borre el bit de control TCS (TnCON<1>) para seleccionar la fuente del reloj interno
• Borre el bit de control TGATE (TnCON<6>) para deshabilitar el funcionamiento del modo Temporizador cerrado
Configurar el bit TSYNC (TnCON<2>) no tiene ningún efecto ya que el reloj interno siempre está sincronizado.
El ejemplo 11-1 ilustra la secuencia de código para configurar el Temporizador1 en el modo Temporizador de 16 bits. este codigo 
genera una interrupción cada 10 ciclos de instrucción. 
Tabla 11-1:
Configuración de modos de temporizador
Modo
Configuración de bits
TCS
PUERTA TG(2)
SINCRONIZACIÓN(1)
Temporizador 
0
0
x
Temporizador cerrado
0
1
x
Contador sincrónico
1
x
1
Contador asíncrono(3)
1
x
0
Nota 1:
El bit TSYNC está disponible sólo para el temporizador tipo A y se ignora para ambos temporizadores. 
modos.
2:
El bit TGATE se ignora para ambos modos de contador.
3:
El modo Contador asíncrono solo es compatible con el temporizador Tipo A.
Nota 1: El registro PRn reinicia un período de reloj del temporizador sólo después de que se establece el bit TnIF.
2: El bit TnIF se establece un ciclo de instrucción después de una coincidencia de período.

© 2007-2011 Microchip Technology Inc.
DS70205D-página 11-11
Sección 11. Temporizadores
Temporizadores
11
Ejemplo 11-1:
Código de inicialización para el modo de temporizador de 16 bits
Figura 11-4:
Interrumpir el tiempo para la coincidencia del período del temporizador
Nota:
El temporizador cuenta los tiempos PRn para el primer evento TnIF y (PRn + 1) tiempos para todos 
eventos TnIF posteriores. Para aplicaciones en las que la asimetría en el tiempo de interrupción 
no es aceptable, se recomienda ignorar el primer evento TnIF después de habilitar el 
temporizador.
T1CONbits.TON = 0;
// Deshabilitar el temporizador
T1CONbits.TCS = 0;
//Selecciona el reloj de ciclo de instrucción interno 
T1CONbits.TGATE = 0;
// Deshabilitar el modo de temporizador cerrado
T1CONbits.TCKPS = 0b00;
//Seleccione el preescalador 1:1
TMR1 = 0x00; 
// Borrar registro del temporizador
PR1 = 9; 
// Carga el valor del periodo
IPC0bits.T1IP = 0x01;
// Establecer el nivel de prioridad de interrupción del temporizador 1
IFS0bits.T1IF = 0;
// Borrar el indicador de interrupción del Timer1
IEC0bits.T1IE = 1;
//Habilitar interrupción del Temporizador1
T1CONbits.TON = 1;
// Iniciar temporizador
/* Código de ejemplo para Timer1 ISR */
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
/* El código de la rutina de servicio de interrupción va aquí */
IFS0bits.T1IF = 0; 
// Borrar el indicador de interrupción del Timer1
}
Temporizador
Reloj
Entrada
TNI
TMRn
1
2
3
4
0
1
2
3
4
5
6
7
0
1
2
3
0
PRn
9
Borrado por el software del usuario
Borrado por el software del usuario
 
 
8
9
5
6
7
8
9
~~
~~

Manual de referencia de la familia dsPIC33F/PIC24H
DS70205D-página 11-12
© 2007-2011 Microchip Technology Inc.
11.4.2
Modo de temporizador cerrado
Cuando el módulo Temporizador funciona con el reloj interno (TCS = 0), se puede activar el modo Temporizador cerrado. 
Se utiliza para medir la duración de una señal de puerta externa. En este modo, el temporizador aumenta en 
uno en cada flanco ascendente del reloj de entrada siempre que la señal de puerta externa en el pin TnCK esté 
alto. La interrupción del temporizador se genera en el flanco descendente del pin TnCK. La figura 11-5 ilustra 
Funcionamiento en modo temporizador cerrado. 
Para configurar el modo Temporizador cerrado:
• Configure el bit de control TGATE (TnCON<6>) para habilitar la operación del temporizador controlado.
• Borre el bit de control TCS (TnCON<1>) para seleccionar la fuente del reloj interno
Configurar el bit TSYNC (TnCON<2>) no tiene ningún efecto porque el reloj interno siempre está 
sincronizado.
El ejemplo 11-2 ilustra la secuencia de código para medir el ancho de pulso del temporizador 1 (T1CK) en modo cerrado. 
Modo temporizador.
Ejemplo 11-2:
Código de inicialización para el modo de temporizador cerrado de 16 bits 
Figura 11-5:
Operación del modo de temporizador cerrado   
T1CONbits.TON = 0;
// Deshabilitar el temporizador
T1CONbits.TCS = 0;
//Selecciona el reloj de ciclo de instrucción interno 
T1CONbits.TGATE = 1;
// Habilitar el modo de temporizador cerrado
T1CONbits.TCKPS = 0b00;
//Seleccione el preescalador 1:1
TMR1 = 0x00; 
// Borrar registro del temporizador
PR1 = 9; 
// Carga el valor del periodo
IPC0bits.T1IP = 0x01;
// Establecer el nivel de prioridad de interrupción del temporizador 1
IFS0bits.T1IF = 0;
// Borrar el indicador de interrupción del Timer1
IEC0bits.T1IE = 1;
//Habilitar interrupción del Temporizador1
T1CONbits.TON = 1;
// Iniciar temporizador
/* Código de ejemplo para Timer1 ISR */
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
/* El código de la rutina de servicio de interrupción va aquí */
IFS0bits.T1IF = 0; 
// Borrar el indicador de interrupción del Timer1
}
Reloj temporizador 
Entrada
(Interno)
TNI
TMRn
1
2
3
8
9
0
PRn
9
Borrado por el software del usuario
Borrado por el software del usuario
TnCK
(Entrada de puerta)
4
5
6
7
1
2
0

© 2007-2011 Microchip Technology Inc.
DS70205D-página 11-13
Sección 11. Temporizadores
Temporizadores
11
11.4.3
Modo contador síncrono
En el modo Contador síncrono, el reloj de entrada al temporizador se deriva de la entrada del reloj externo. 
dividido por un preescalador programable. En este modo, la entrada del reloj externo se sincroniza con 
el reloj interno del dispositivo. Cuando el temporizador está habilitado, aumenta en uno en cada flanco ascendente 
del reloj de entrada y genera una interrupción en una coincidencia de período. 
Para configurar el modo Contador síncrono:
• Establezca el bit de control TSYNC (T1CON<2>) para un temporizador tipo A para habilitar la sincronización del reloj. 
Para un temporizador Tipo B o Tipo C, la entrada del reloj externo siempre está sincronizada.
• Configure el bit de control TCS (TnCON<1>) para seleccionar la fuente de reloj externo.
Un temporizador que funciona desde una fuente de reloj externa sincronizada no funciona en modo de suspensión, 
porque el circuito de sincronización se apaga durante el modo de suspensión.
Para temporizadores tipo C cuando se configuran para modo externo, es necesario que el reloj externo 
período de entrada para cumplir con los tiempos mínimos de entrada de reloj alto y bajo para una sincronización adecuada. 
Consulte la hoja de datos del dispositivo específico para obtener información sobre la sincronización.
La sincronización del reloj para un temporizador Tipo A y Tipo B se realiza después del preescalador. 
y la salida del preescalador cambia en el flanco ascendente de la entrada. Por lo tanto, para un tipo A 
y temporizador tipo B, el período de entrada del reloj externo es una función de TCY y una entrada adicional 
retardo del búfer dividido por el valor del preescalador. Consulte la hoja de datos específica del dispositivo para conocer la sincronización. 
información. Además del período mínimo, el tiempo alto y bajo del reloj externo 
La entrada no debe violar los requisitos mínimos de ancho de pulso definidos en la hoja de datos.
El ejemplo 11-3 ilustra la secuencia de código para configurar el módulo Timer1 en Síncrono 
Modo contador. Este código genera una interrupción después de contar 1000 flancos ascendentes en el T1CK 
alfiler. 
Ejemplo 11-3:
Código de inicialización para el modo de contador síncrono de 16 bits 
Nota 1: Para conocer los requisitos de sincronización del reloj externo en el modo Contador síncrono, consulte 
el capítulo “Características eléctricas” de la ficha técnica específica del dispositivo.
2: Los temporizadores, cuando se configuran para el modo Contador externo (TCS = 1), funcionan como 
siguiente: Los temporizadores tipo A y tipo B comienzan a contar desde el segundo flanco ascendente, mientras 
Los temporizadores tipo C comienzan a contar desde el primer flanco ascendente.
3: El registro PRn se reinicia en el siguiente flanco ascendente de la entrada del reloj del temporizador.
4: El bit TnIF se establece un ciclo de instrucción después de una coincidencia de período.
Nota:
El temporizador cuenta los tiempos PRn para el primer evento TnIF y (PRn + 1) tiempos para todos 
eventos TnIF posteriores. Para aplicaciones en las que la asimetría en el tiempo de interrupción 
no es aceptable, se recomienda ignorar el primer evento TnIF después de habilitar el 
temporizador.
T1CONbits.TON = 0;
// Deshabilitar el temporizador
T1CONbits.TCS = 1;
//Selecciona la fuente del reloj externo
T1CONbits.TSYNC = 1;
// Habilitar sincronización
T1CONbits.TCKPS = 0b00;
//Seleccione el preescalador 1:1
TMR1 = 0x00; 
// Borrar registro del temporizador
PR1 = 999; 
// Carga el valor del periodo
IPC0bits.T1IP = 0x01;
// Establecer el nivel de prioridad de interrupción del temporizador 1
IFS0bits.T1IF = 0;
// Borrar el indicador de interrupción del Timer1
IEC0bits.T1IE = 1;
//Habilitar interrupción del Temporizador1
T1CONbits.TON = 1;
// Iniciar temporizador
/* Código de ejemplo para Timer1 ISR */
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
/* El código de la rutina de servicio de interrupción va aquí */
IFS0bits.T1IF = 0;
// Borrar el indicador de interrupción del Timer1
}

Manual de referencia de la familia dsPIC33F/PIC24H
DS70205D-página 11-14
© 2007-2011 Microchip Technology Inc.
11.4.4
Modo de contador asíncrono (solo temporizador tipo A)
Un temporizador tipo A puede funcionar en modo de conteo asíncrono. En el modo Contador asíncrono, 
El reloj de entrada al temporizador se deriva de la entrada del reloj externo (T1CK) dividida por un programa.
preescalador mable. En este modo, la entrada del reloj externo no está sincronizada con la entrada del reloj interno. 
reloj del dispositivo. Cuando está habilitado, el temporizador aumenta en uno en cada flanco ascendente del reloj de entrada. 
y genera una interrupción en un partido de período.
Para configurar el modo Contador asíncrono:
• Borre el bit de control TSYNC (T1CON<2>) para desactivar la sincronización del reloj.
• Configure el bit de control TCS (T1CON<1>) para seleccionar la fuente de reloj externo.
En modo Contador asíncrono:
• El temporizador se puede sincronizar desde el oscilador de cristal secundario de baja potencia de 32 kHz para RTC 
aplicaciones configurando el bit de habilitación del oscilador secundario (LPOSCEN) en el oscilador 
Registro de control (OSCCON<1>). Para obtener más información, consulte la Sección 7. "Oscilador" 
(DS70186).
• El temporizador puede funcionar durante el modo de suspensión, si la entrada del reloj externo está activa o el 
El oscilador secundario está habilitado. El temporizador puede generar una interrupción (si está habilitada) en un 
coincidencia de registro de período para reactivar el procesador del modo de suspensión.
• El tiempo alto y bajo de la entrada del reloj externo no debe violar el ancho de pulso mínimo 
requisito de 10 ns nominal (o frecuencia nominal de 50 MHz)
El ejemplo 11-4 ilustra la secuencia de código para configurar el módulo Timer1 en modo asincrónico. 
Modo contador. Este código genera una interrupción cada segundo cuando se ejecuta en un reloj de 32 kHz. 
entrada.
Ejemplo 11-4:
Código de inicialización para el modo de contador asíncrono de 16 bits
Nota 1: Para conocer los requisitos de sincronización del reloj externo en el modo Contador asíncrono, consulte 
el capítulo “Características eléctricas” de la ficha técnica específica del dispositivo.
2: El registro PR1 se reinicia en el siguiente flanco ascendente de la entrada del reloj del temporizador.
3: El bit T1IF se establece un ciclo de instrucción después de una coincidencia de período.
Nota:
El cronómetro cuenta los tiempos PR1 para el primer evento T1IF y (PR1 + 1) tiempos para todos 
eventos T1IF posteriores. Para aplicaciones en las que la asimetría en el tiempo de interrupción 
no es aceptable, se recomienda ignorar el primer evento T1IF después de habilitar el 
temporizador.
T1CONbits.TON = 0;
// Deshabilitar el temporizador
T1CONbits.TCS = 1;
//Selecciona reloj externo 
T1CONbits.TSYNC = 0;
// Deshabilitar la sincronización
T1CONbits.TCKPS = 0b00;
//Seleccione el preescalador 1:1
TMR1 = 0x00; 
// Borrar registro del temporizador
PR1 = 32767; 
// Carga el valor del periodo
IPC0bits.T1IP = 0x01;
// Establecer el nivel de prioridad de interrupción del temporizador 1
IFS0bits.T1IF = 0;
// Borrar el indicador de interrupción del Timer1
IEC0bits.T1IE = 1;
//Habilitar interrupción del Temporizador1
T1CONbits.TON = 1;
// Iniciar temporizador
/* Código de ejemplo para Timer1 ISR */
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
/* El código de la rutina de servicio de interrupción va aquí */
IFS0bits.T1IF = 0; 
// Borrar el indicador de interrupción del Timer1
}

© 2007-2011 Microchip Technology Inc.
DS70205D-página 11-15
Sección 11. Temporizadores
Temporizadores
11
11.5
 INTERRUPCIONES DEL TEMPORIZADOR
Se genera una interrupción del temporizador:
• En una coincidencia de período para el modo Temporizador o el modo Contador síncrono/asíncrono (consulte 
Figura 11-4)
• En el flanco descendente de la señal de “puerta” en el pin TnCK para el modo de temporizador activado (consulte 
Figura 11-5)
El bit del indicador de interrupción del temporizador (TnIF) se debe borrar en el software. 
Un temporizador se habilita como fuente de interrupción a través del respectivo bit de habilitación de interrupción del temporizador (TnIE). 
Los bits del nivel de prioridad de interrupción (TnIP<2:0>) deben escribirse con un valor distinto de cero para el temporizador. 
ser una fuente de interrupción. Para obtener más información, consulte la Sección 6. "Interrupciones" (DS70184).
11.6
 CONFIGURACIÓN DEL TEMPORIZADOR DE 32 BITS
Se puede formar un módulo de temporizador de 32 bits combinando temporizadores de 16 bits tipo B y tipo C. Para 32 bits 
operación del temporizador, se debe configurar el bit de control T32 en el registro de control del temporizador tipo B (TxCON<3>). 
El temporizador Tipo C contiene la palabra más significativa (msw) y el temporizador Tipo B contiene la menor 
palabra significativa (lsw) para operación de 32 bits. 
Cuando se configura para operación de 32 bits, solo se requieren los bits de registro de control del temporizador tipo B para 
configuración y control. Con la excepción del bit TSIDL, todos los bits del registro de control del temporizador tipo C son 
ignorado. Para obtener más información, consulte 11.8.2 “Funcionamiento del temporizador en modo inactivo”. 
Para el control de interrupciones, el temporizador combinado de 32 bits utiliza la habilitación de interrupciones, el indicador de interrupción y 
bits de control de prioridad de interrupción del temporizador tipo C. El control de interrupciones y los bits de estado del tipo B. 
El temporizador se ignora durante la operación del temporizador de 32 bits.
La Tabla 11-2 enumera los temporizadores de tipo B y tipo C que se pueden combinar para formar un temporizador de 32 bits. 
En la Figura 11-6 se muestra un diagrama de bloques del módulo Temporizador de 32 bits. los 32 bits 
El módulo temporizador puede funcionar en cualquiera de los siguientes modos:
• Temporizador
• Temporizador cerrado
• Contador síncrono
En los modos Temporizador y Temporizador cerrado, el reloj de entrada se deriva del ciclo de instrucción interno. 
reloj (FCY). En el modo Contador síncrono, el reloj de entrada se deriva del temporizador Tipo B 
Entrada de reloj externo en el pin TxCK.
Los modos de temporizador de 32 bits están determinados por los siguientes bits en el control de temporizador tipo B. 
registros:
• TCS (TxCON<1>): Bit de control de fuente de reloj del temporizador
• TGATE (TxCON<6>): Bit de control de puerta del temporizador
Nota:
Un caso especial ocurre cuando el registro de período, PRn, se carga con 0x0000 y el 
El temporizador está habilitado. No se generan interrupciones del temporizador para esta configuración.
Tabla 11-2:
Combinaciones de temporizador de 32 bits
Temporizador tipo B (lsw)
Temporizador tipo C (msw)
Temporizador2
Temporizador3
Temporizador4
Temporizador5
Temporizador6
Temporizador7
Temporizador8
Temporizador9

Manual de referencia de la familia dsPIC33F/PIC24H
DS70205D-página 11-16
© 2007-2011 Microchip Technology Inc.
La configuración de los bits de control del temporizador para diferentes modos de funcionamiento se proporciona en la Tabla 11-3.
El reloj de entrada (FCY o TxCK) para todos los temporizadores de 32 bits tiene opciones de preescala de 1:1, 1:8, 1:64 y 1:256. 
El preescalador de reloj se selecciona utilizando los bits del preescalador de reloj del temporizador (TCKPS<1:0>) en el tipo 
B Registro de control del temporizador (TxCON<5:4>). El contador del preescalador se borra cuando cualquiera de los 
ocurre lo siguiente:
• Una escritura en el registro del temporizador tipo B (TMRx) o en el registro de control del temporizador tipo B (TxCON)
• Borrar el bit de habilitación del temporizador (TON) en el registro de control del temporizador tipo B (TxCON<15>)
• Restablecer cualquier dispositivo
El módulo de temporizador de 32 bits se habilita o deshabilita usando el bit TON en el control de temporizador tipo B. 
registros (TxCON<15>).
Para que las operaciones de lectura/escritura de 32 bits se sincronicen entre lsw y msw del temporizador de 32 bits, 
Se utilizan lógica de control adicional y registros de retención (consulte la Figura 11-6). Cada temporizador tipo C 
tiene un registro llamado TMRyHLD, que se utiliza al leer o escribir el par de registros del temporizador. el 
Los registros TMRyHLD se utilizan sólo cuando los temporizadores respectivos están configurados para funcionamiento de 32 bits. 
Suponiendo que TMR3:TMR2 forme un par de temporizadores de 32 bits, la aplicación de usuario primero debe leer el lsw del 
valor del temporizador del registro TMR2. La lectura del lsw transfiere automáticamente el contenido de 
TMR3 en el registro TMR3HLD. La aplicación de usuario puede leer TMR3HLD para obtener el msw. 
del valor del temporizador. 
Para escribir un valor en el par de registros TMR3:TMR2, la aplicación de usuario primero debe escribir el msw en 
el registro TMR3HLD. Cuando el lsw del valor del temporizador se escribe en TMR2, el contenido de 
TMR3HLD se transfiere automáticamente al registro TMR3. 
El código para acceder al temporizador de 32 bits se muestra en el ejemplo 11-5.
Ejemplo 11-5:
Acceso con temporizador de 32 bits
Tabla 11-3:
Configuración del modo temporizador
Modo
Configuración de bits
TCS
TGATE
Temporizador 
0
0
Temporizador cerrado
0
1
Contador sincrónico
1
x
Nota 1: Los temporizadores tipo B y tipo C no admiten el modo de reloj externo asíncrono; 
por lo tanto, no se admite el modo Contador asíncrono de 32 bits.
2: El registro PRx se reinicia en el siguiente flanco ascendente de la entrada del reloj del temporizador.
3: El bit TxIF se establece un ciclo de instrucción después de una coincidencia de período.
// Leyendo desde un temporizador de 32 bits
lsw = TMR2;
// Lee lsw del registro del temporizador tipo B
msw = TMR3HLD;
// Leer msw del registro de retención del temporizador tipo C
// Escribiendo en un temporizador de 32 bits
TMR3HLD = msw;
// Escribe msw en el registro de retención del temporizador tipo C
TMR2 = lsw;
// Escribe lsw en el registro del temporizador tipo B

© 2007-2011 Microchip Technology Inc.
DS70205D-página 11-17
Sección 11. Temporizadores
Temporizadores
11
Figura 11-6:
Diagrama de bloques de pares de temporizadores tipo B/tipo C (temporizador de 32 bits)
pestillo
Preescalador
(/n)
TGATE
TCS
00
x1
TMRx
PRx
TGATE
Establecer bandera TyIF 
0
1
Sincronizar
TCKPS<1:0>
igual
Puerta
Sincronizar
FCY
Borde descendente 
detectar
Preescalador
(/n)
TCKPS<1:0>
TMRy
Comparador
PRy
Reiniciar
msw
lsw
TMryHLD
Bus de datos<15:0>
CAD 
DATOS
CLK
Nota 1:
El disparador ADC solo está disponible en temporizadores de 32 bits TMR3:TMR2 y TMR5:TMR4.
2:
Timerx es un temporizador de tipo B (x = 2, 4, 6 y 8).
3:
Timery es un temporizador tipo C (y = 3, 5, 7 y 9).
TXCK
10

Manual de referencia de la familia dsPIC33F/PIC24H
DS70205D-página 11-18
© 2007-2011 Microchip Technology Inc.
11.7
 MODOS DE FUNCIONAMIENTO DEL TEMPORIZADOR DE 32 BITS
11.7.1
Modo temporizador
El temporizador de 32 bits funciona de manera similar a un temporizador de 16 bits en modo Temporizador. El ejemplo 11-6 ilustra la 
Secuencia de código para configurar Timer2 y Timer3 en modo de temporizador de 32 bits.
Ejemplo 11-6:
Código de inicialización para el modo de temporizador de 32 bits
11.7.2
Modo de temporizador cerrado
El temporizador de 32 bits funciona de manera similar a un temporizador de 16 bits en el modo Temporizador cerrado. Ejemplo 11-7 
ilustra la secuencia de códigos para configurar Timer2 y Timer3 en modo de temporizador cerrado de 32 bits.
Ejemplo 11-7:
Código de inicialización para el modo de temporizador cerrado de 32 bits
T3CONbits.TON = 0;
// Detener cualquier operación Timer3 de 16 bits
T2CONbits.TON = 0;
// Detener cualquier operación Timer2 de 16/32 bits
T2CONbits.T32 = 1;
// Habilitar el modo Temporizador de 32 bits
T2CONbits.TCS = 0;
//Selecciona el reloj de ciclo de instrucción interno 
T2CONbits.TGATE = 0;
// Deshabilitar el modo de temporizador cerrado
T2CONbits.TCKPS = 0b00;
//Seleccione el preescalador 1:1
TMR3 = 0x00;
// Borrar temporizador de 32 bits (msw)
TMR2 = 0x00; 
// Borrar temporizador de 32 bits (lsw)
PR3 = 0x0002; 
// Carga el valor del período de 32 bits (msw)
PR2 = 0x0000; 
// Carga el valor del período de 32 bits (lsw)
IPC2bits.T3IP = 0x01;
// Establecer el nivel de prioridad de interrupción del Timer3
IFS0bits.T3IF = 0;
// Borrar el indicador de interrupción del Timer3
IEC0bits.T3IE = 1;
// Habilitar la interrupción del Timer3
T2CONbits.TON = 1;
// Iniciar temporizador de 32 bits
/* Código de ejemplo para Timer3 ISR */
void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void)
{
/* El código de la rutina de servicio de interrupción va aquí */
IFS0bits.T3IF = 0; 
// Borrar el indicador de interrupción del Timer3
}
T3CONbits.TON = 0;
// Detener cualquier operación Timer3 de 16 bits
T2CONbits.TON = 0;
// Detener cualquier operación Timer2 de 16/32 bits
T2CONbits.T32 = 1;
// Habilitar el modo Temporizador de 32 bits
T2CONbits.TCS = 0;
//Selecciona el reloj de ciclo de instrucción interno 
T2CONbits.TGATE = 1;
// Habilitar el modo de temporizador cerrado
T2CONbits.TCKPS = 0b00;
//Seleccione el preescalador 1:1
TMR3 = 0x00; 
// Borrar temporizador de 32 bits (msw)
TMR2 = 0x00; 
// Borrar temporizador de 32 bits (lsw)
PR3 = 0x0002; 
// Carga el valor del período de 32 bits (msw)
PR2 = 0x0000; 
// Carga el valor del período de 32 bits (lsw)
IPC2bits.T3IP = 0x01;
// Establecer el nivel de prioridad de interrupción del Timer3
IFS0bits.T3IF = 0;
// Borrar el indicador de interrupción del Timer3
IEC0bits.T3IE = 1;
// Habilitar la interrupción del Timer3
T2CONbits.TON = 1;
// Iniciar temporizador de 32 bits
/* Código de ejemplo para Timer3 ISR */
void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void)
{
/* El código de la rutina de servicio de interrupción va aquí */
IFS0bits.T3IF = 0; 
// Borrar el indicador de interrupción del Timer3
}

© 2007-2011 Microchip Technology Inc.
DS70205D-página 11-19
Sección 11. Temporizadores
Temporizadores
11
11.7.3
Modo contador síncrono
El temporizador de 32 bits funciona de manera similar a un temporizador de 16 bits en modo Contador síncrono. Ejemplo 11-8 
ilustra la secuencia de códigos para configurar Timer2 y Timer3 en modo contador síncrono de 32 bits.
Ejemplo 11-8:
Código de inicialización para el modo de contador síncrono de 32 bits 
T3CONbits.TON = 0;
// Detener cualquier operación Timer3 de 16 bits
T2CONbits.TON = 0;
// Detener cualquier operación Timer2 de 16/32 bits
T2CONbits.T32 = 1;
// Habilitar el modo Temporizador de 32 bits
T2CONbits.TCS = 1;
//Selecciona reloj externo 
T2CONbits.TCKPS = 0b00;
//Seleccione el preescalador 1:1
TMR3 = 0x00; 
// Borrar temporizador de 32 bits (msw)
TMR2 = 0x00; 
// Borrar temporizador de 32 bits (lsw)
PR3 = 0x0002; 
// Carga el valor del período de 32 bits (msw)
PR2 = 0x0000; 
// Carga el valor del período de 32 bits (lsw)
IPC2bits.T3IP = 0x01;
// Establecer el nivel de prioridad de interrupción del Timer3
IFS0bits.T3IF = 0;
// Borrar el indicador de interrupción del Timer3
IEC0bits.T3IE = 1;
// Habilitar la interrupción del Timer3
T2CONbits.TON = 1;
// Iniciar temporizador de 32 bits
/* Código de ejemplo para Timer3 ISR */
void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void)
{
/* El código de la rutina de servicio de interrupción va aquí */
IFS0bits.T3IF = 0; 
// Borrar el indicador de interrupción del Timer3
}

Manual de referencia de la familia dsPIC33F/PIC24H
DS70205D-página 11-20
© 2007-2011 Microchip Technology Inc.
11.8
 FUNCIONAMIENTO DEL TEMPORIZADOR EN MODOS DE AHORRO DE ENERGÍA
11.8.1
Operación del temporizador en modo de suspensión
Cuando el dispositivo ingresa al modo de suspensión, el reloj del sistema se desactiva. Si el módulo Temporizador se está ejecutando 
en la fuente de reloj interno (FCY), también está deshabilitado.
Un temporizador tipo A se diferencia de los demás temporizadores porque puede funcionar de forma asíncrona desde el 
fuente del reloj del sistema. Debido a esta distinción, el temporizador Tipo A puede continuar funcionando durante 
Modo de suspensión. Para operar en modo de suspensión, el temporizador tipo A debe configurarse de la siguiente manera:
• Borre el bit de control TSYNC (T1CON<2>) para desactivar la sincronización del reloj.
• Configure el bit de control TCS (T1CON<1>) para seleccionar la fuente de reloj externa.
• Habilitar el oscilador secundario, si la entrada de reloj externo (T1CK) no está activa
Cuando se cumplen todas estas condiciones, el cronómetro continúa contando y detectando coincidencias de períodos. 
mientras el dispositivo está en modo de suspensión. Cuando hay una coincidencia entre el cronómetro y el registro del período 
ocurre, el bit TnIF se establece. La interrupción del temporizador se genera, si la interrupción del temporizador está habilitada 
(TnIE = 1).
La interrupción del temporizador despierta el dispositivo del modo de suspensión y ocurren los siguientes eventos:
• Si el nivel de prioridad asignado para la interrupción es menor o igual a la prioridad actual de la CPU, 
el dispositivo se activa y continúa la ejecución del código a partir de la instrucción que sigue al 
Instrucción PWRSAV que inició el modo de suspensión
• Si el nivel de prioridad asignado para la fuente de interrupción es mayor que la prioridad actual de la CPU, 
el dispositivo se activa y comienza el proceso de excepción de la CPU. La ejecución del código continúa 
desde la primera instrucción del temporizador Rutina de Servicio de Interrupción (ISR)
Para obtener más información, consulte la Sección 9. "Temporizador de vigilancia y modos de ahorro de energía" 
(DS70196).
11.8.2
Operación del temporizador en modo inactivo
Cuando el dispositivo entra en modo inactivo, las fuentes de reloj del sistema siguen funcionando y la CPU 
deja de ejecutar el código. El bit de parada del temporizador en inactividad (TSIDL) en el registro de control del temporizador 
(TnCON<13>) determina si el módulo se detiene en modo inactivo o continúa funcionando en modo inactivo 
modo.
• Si TSIDL = 0, el temporizador continúa funcionando en modo inactivo y proporciona funcionalidad completa. Para 
Operación del temporizador de 32 bits, el bit TSIDL (TxCON<13> y TyCON<13>) debe borrarse en 
El control de temporizador tipo B y tipo C registra un temporizador para funcionar en modo inactivo.
• Si TSIDL  = 1, el temporizador realiza las mismas funciones cuando se detiene en modo inactivo que en suspensión 
modo (consulte 11.8.1 “Funcionamiento del temporizador en modo de suspensión”)
Nota:
El oscilador secundario se habilita configurando el bit de habilitación del oscilador secundario 
(LPOSCEN) en el registro de control del oscilador (OSCCON<1>). Para más información,
consulte la Sección 7. "Oscilador" (DS70186). El cristal del reloj de 32 kHz debe estar 
conectado a los pines del dispositivo SOSCO/SOSCI.

© 2007-2011 Microchip Technology Inc.
DS70205D-página 11-21
Sección 11. Temporizadores
Temporizadores
11
11.9
 PERIFÉRICOS QUE UTILIZAN MÓDULOS TEMPORIZADORES
11.9.1
Base de tiempo para captura de entrada y comparación de salida
Los periféricos de captura de entrada y comparación de salida pueden seleccionar Timer2 o Timer3 como base de tiempo. 
Para obtener más información, consulte la Sección 12. "Captura de entrada" (DS70198), Sección 13. "Captura de entrada" 
Comparar” (DS70209), y la hoja de datos específica del dispositivo.
11.9.2
Activador de eventos especiales de analógico a digital
En cada variante de dispositivo, un temporizador tipo C puede generar una señal especial de analógico a digital. 
señal de activación de conversión en una coincidencia de período, tanto en modo de 16 bits como de 32 bits. El cronómetro 
 El módulo proporciona una señal de inicio de conversión a la lógica de muestreo de analógico a digital.
• Si T32 = 0, cuando se produce una coincidencia entre el registro del temporizador de 16 bits (TMRx) y el 
respectivo registro de período de 16 bits (PRx), la señal de activación de evento especial analógico a digital se 
generado
• Si T32 = 1, cuando se produce una coincidencia entre el temporizador de 32 bits (TMRx:TMRy) y el temporizador de 32 bits 
respectivo registro de período combinado (PRx:PRy), el disparador de evento especial analógico a digital 
se genera la señal
La señal de activación de evento especial siempre la genera el temporizador. La fuente de activación debe 
seleccionarse en los registros de control del convertidor analógico a digital (ADC). Para más 
información, consulte la Sección 16. "Convertidor analógico a digital (ADC)" (DS70183) y el 
ficha técnica específica del dispositivo.
11.9.3
Temporizador como pin de interrupción externo
El pin de entrada del reloj externo para cada temporizador se puede utilizar como pin de interrupción adicional. para proporcionar 
la interrupción, el registro del período del temporizador, PRn, se escribe con un valor distinto de cero y el TMRn 
El registro se inicializa a un valor de uno menos que el valor escrito en el registro del período. el cronómetro 
debe configurarse para un preescalador de reloj 1:1. Se genera una interrupción cuando el siguiente flanco ascendente 
Se detecta la señal del reloj externo. 
11.9.4
Control de pines de E/S
Cuando un módulo temporizador está habilitado y configurado para el funcionamiento de un reloj externo o de una puerta, el usuario 
La aplicación debe garantizar que la dirección del pin de E/S esté configurada para una entrada. Habilitar el temporizador 
El módulo no configura la dirección del pin.

Manual de referencia de la familia dsPIC33F/PIC24H
DS70205D-página 11-22
© 2007-2011 Microchip Technology Inc.
11.10
 REGISTRAR MAPA
En la Tabla 11-4 se proporciona un resumen de los registros de funciones especiales (SFR) asociados con el módulo de temporizador dsPIC33F/PIC24H.
Tabla 11-4:
Mapa de registro del temporizador 
SFR 
Nombre
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
Temporizador1 Registrarse
xxxx
PR1
Registro de período 1
FFFFF
T1CON
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
TMRx
Registro Timerx
xxxx
TMryHLD
Registro de retención de temporizador (solo para operaciones de temporizador de 32 bits)
xxxx
TMRy
Registro de tiempo
xxxx
PRx
Periodo Registro x
FFFFF
PRy
Periodo Registro y
FFFFF
TxCON
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
TyCON
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
Nota
1:
Una 'n' utilizada en los nombres de pines, bits de control/estado y registros denota todos los temporizadores (n = 1 a 9).
2:
Una 'x' utilizada en los nombres de pines, bits de control/estado y registros denota el número particular del temporizador Tipo B (x = 2, 4, 6 y 8).
3:
Una 'y' utilizada en los nombres de pines, bits de control/estado y registros denota el número particular del temporizador Tipo C (y = 3, 5, 7 y 9).

© 2007-2011 Microchip Technology Inc.
DS70205D-página 11-23
Sección 11. Temporizadores
Temporizadores
11
11.11
 NOTAS DE APLICACIÓN RELACIONADAS
Esta sección enumera las notas de aplicación relacionadas con esta sección del manual. Estos 
Es posible que las notas de aplicación no estén escritas específicamente para la familia de dispositivos dsPIC33F/PIC24H, pero el 
Los conceptos son pertinentes y podrían usarse con modificaciones y posibles limitaciones. la corriente 
Las notas de aplicación relacionadas con el módulo Temporizadores son:
Título
Nota de aplicación #
Uso del Timer1 en modo de reloj asíncrono
AN580
Nota:
Para notas de aplicación adicionales y ejemplos de código para dsPIC33F/PIC24H 
familia de dispositivos, visite el sitio web de Microchip (www.microchip.com).

Manual de referencia de la familia dsPIC33F/PIC24H
DS70205D-página 11-24
© 2007-2011 Microchip Technology Inc.
11.12
 HISTORIAL DE REVISIONES
Revisión A (abril de 2007)
Esta es la revisión inicial publicada de este documento.
Revisión B (abril de 2008)
Esta revisión incorpora las siguientes actualizaciones:
• Notas: 
- Se agregó una nota en 11.4.3 "Modo contador síncrono", que proporciona información 
en funcionamiento del temporizador cuando se configura para el modo de contador externo (TCS = 1)
- Nota corregida 2 en la Figura 11-6. TMR5:TMR2 se cambió a TMR5:TMR4
• Se incorporaron correcciones menores adicionales, como actualizaciones de idioma y formato. 
a lo largo del documento
Revisión C (enero de 2010)
Esta revisión incorpora las siguientes actualizaciones:
• Todas las referencias a dsPIC33F en el documento se actualizaron a dsPIC33F/PIC24H.
• Se cambiaron todas las instancias de __shadow__ a no_auto_psv en los ejemplos de código.
• Se agregó un bloque de pestillo a la Figura 11-1, Figura 11-2, Figura 11-3 y Figura 11-6.
• Notas:
- Se agregó una nota sombreada al comienzo de la sección, que proporciona información sobre 
documentación complementaria
- Se agregó la siguiente nota en 11.4.1 "Modo temporizador":
• El registro PRx reinicia un período de reloj del temporizador sólo después de que se establece el bit TxIF
- Se agregó la siguiente nota en 11.4.3 “Modo contador síncrono” y 
11.4.4 “Modo de contador asíncrono (solo temporizador tipo A)”:
• El registro PRx se reinicia en el siguiente flanco ascendente de la entrada del reloj del temporizador.
- Se agregaron las siguientes notas en 11.4.1 “Modo temporizador”, 11.4.3 “Contador síncrono 
Mode” y 11.4.4 “Modo de contador asíncrono (solo temporizador tipo A)”:
• El bit TxIF se establece un ciclo de instrucción después de una coincidencia de período
• El temporizador cuenta los tiempos PRx para el primer evento TxIF y los tiempos (PRx + 1) para todos los subsecuentes.
eventos TxIF frecuentes. Para aplicaciones en las que la asimetría en el tiempo de interrupción no es 
aceptable, se recomienda ignorar el primer evento TxIF después de habilitar el temporizador.
• Se eliminó la Tabla 11-5: Mapa de registro de control de interrupciones.
• Se incorporaron correcciones menores adicionales, como actualizaciones de idioma y formato. 
a lo largo del documento
Revisión D (septiembre de 2011)
Esta revisión incluye las siguientes actualizaciones:
• Se realizaron actualizaciones globales en todo el documento para distinguir entre los tres temporizadores. 
tipos: A (TImer1), B (Timerx) y C (Timery). Además, el uso de la letra 'n' fue 
introducido para indicar pines, bits de control/estado y registros que son comunes a los tres 
tipos de temporizadores.
• Se actualizaron los diagramas de bloques del temporizador (consulte la Figura 11-1, la Figura 11-2 y la Figura 11-3).
• Se actualizaron los párrafos tercero y cuarto de 11.4.3 “Modo de contador síncrono”
• Se actualizó el código de inicialización para el temporizador de 32 bits, el temporizador activado de 32 bits y el temporizador de 32 bits. 
Modo de contador síncrono (consulte el Ejemplo 11-6, el Ejemplo 11-7 y el Ejemplo 11-8)
• Se actualizó el mapa de registro del temporizador (consulte la Tabla 11-4).
• Se eliminó el estado del documento preliminar.
• Se incorporaron correcciones menores al texto y al formato en todo el documento.

© 2007-2011 Microchip Technology Inc. 
DS70205D-página 11 -25 
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
El nombre y el logotipo de Microchip, el logotipo de Microchip, dsPIC, 
KEELOQ, logotipo de KEELOQ, MPLAB, PIC, PICmicro, PICSTART, 
El logotipo PIC32, rfPIC y UNI/O son marcas registradas de 
Microchip Technology Incorporated en los EE.UU. y otros 
países. 
FilterLab, Hampshire, HI-TECH C, termistor activo lineal, 
MXDEV, MXLAB, SEEVAL y el control integrado 
Solutions Company son marcas registradas de Microchip 
Tecnología incorporada en EE.UU. 
Analógico para la era digital, Application Maestro, chipKIT, 
Logotipo de chipKIT, CodeGuard, dsPICDEM, dsPICDEM.net, 
dsPICworks, dsSPEAK, ECAN, ECONOMONITOR, 
FanSense, HI-TIDE, programación en serie en circuito, ICSP, 
Mindi, MiWi, MPASM, logotipo certificado MPLAB, MPLIB, 
MPLINK, mTouch, generación de código omnisciente, PICC, 
PICC-18, PICDEM, PICDEM.net, PICkit, PICtail, REAL ICE, 
rfLAB, Modo de selección, Resistencia total, TSHARC, 
UniWinDriver, WiperLock y ZENA son marcas comerciales de 
Microchip Technology Incorporated en los EE.UU. y otros 
países. 
SQTP es una marca de servicio de Microchip Technology Incorporated 
en los EE.UU. 
Todas las demás marcas comerciales mencionadas en este documento son propiedad de sus 
respectivas empresas. 
© 2007-2011, Microchip Technology Incorporated, Impreso en 
EE.UU., Todos los derechos reservados. 
Impreso en papel reciclado. 
ISBN: 978-1-61341-624-2 
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
Microchip recibió la certificación ISO/TS-16949:2009 para su 
sede, instalaciones de diseño y fabricación de obleas en Chandler y 
Tempe, Arizona; Gresham, Oregon y centros de diseño en California 
e India. Los procesos y procedimientos del sistema de calidad de la Compañía. 
son para sus MCU PIC® y DSC dsPIC®, salto de código KEELOQ® 
dispositivos, EEPROM seriales, microperiféricos, memoria no volátil y 
productos analógicos. Además, el sistema de calidad de Microchip para el diseño 
y la fabricación de sistemas de desarrollo cuenta con la certificación ISO 9001:2000. 

DS70205D-página 11 -26
© 2007-2011 Microchip Technology Inc.
AMÉRICAS
Oficina Corporativa
2355 bulevar oeste de Chandler.
Chandler, AZ 85224-6199
Teléfono: 480-792-7200 
Fax: 480-792-7277
Soporte técnico: 
http://www.microchip.com/
apoyo
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
Tel: 630-285-0071 
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
Indianápolis
Noblesville, Indiana, EE.UU. 
Teléfono: 317-773-8323
Fax: 317-773-5453
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
Teléfono: 86-10-8569-7000 
Fax: 86-10-8528-2104
China - Chengdu
Teléfono: 86-28-8665-5511
Fax: 86-28-8665-7889
China - Chóngqing
Teléfono: 86-23-8980-9588
Fax: 86-23-8980-9500
China - Hangzhou
Teléfono: 86-571-2819-3187 
Fax: 86-571-2819-3189
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
China - Xian
Teléfono: 86-29-8833-7252
Fax: 86-29-8833-7256
China - Xiamén
Teléfono: 86-592-2388138 
Fax: 86-592-2388130
China - Zhuhai
Teléfono: 86-756-3210040 
Fax: 86-756-3210049
ASIA/PACÍFICO
India - Bangalore
Teléfono: 91-80-3090-4444 
Fax: 91-80-3090-4123
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
Teléfono: 886-3-5778-366
Fax: 886-3-5770-955
Taiwán - Kaohsiung
Teléfono: 886-7-536-4818
Fax: 886-7-330-9305
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
02/08/11
