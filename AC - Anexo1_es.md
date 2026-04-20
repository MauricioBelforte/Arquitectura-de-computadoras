# Contenido extraído de AC - Anexo1.pdf

 
ARQUITECTURA DE COMPUTADORAS 
 
ANEXO 1 
 
 
 
 
 
 
 
 
 
 
 
 
 
ARQUITECTURA 
DE  
COMPUTADORAS 
 
 
APUNTES DE CÁTEDRA 
 
 
Docentes: 
 
​
Profesor:​
Lic. Marcelo Gómez 
​
Jefe de Trabajos Prácticos:​
Mg. Sebastián Wahler 
​
Auxiliar de 1ra.:​
Lic. Rodrigo Huincalef 
 
 
 
 
 
 
​Versión 1 - 2026
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 1 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
INDICE 
 
Capítulo 1​
2 
Detalles de Funcionalidad de Microprocesadores​
2 
Microcontroladores PIC24, dsPIC33​
2 
Características​
2 
Arquitectura von Neumann​
4 
Arquitectura Harvard​
4 
Procesador tipo RISC y Segmentado​
4 
Puertos​
5 
Otros pines​
5 
​
5 
Organización de la memoria​
5 
Memoria de Programa​
5 
SP (Stack Pointer)​
7 
Memoria de Datos​
7 
Registro STATUS​
8 
Manejo de Puertos​
9 
Interrupciones​
10 
Fuentes de Interrupción​
10 
Fases de una interrupción​
11 
Capítulo 2​
11 
LENGUAJE ENSAMBLADOR​
11 
Introducción​
11 
Etiquetas​
11 
Instrucciones o directivas​
12 
Datos u operandos​
13 
Comentarios​
13 
El primer programa: EJEMPLO1.ASM​
13 
Directivas​
13 
Código del programa​
14 
Secuencia a seguir para el grabado del microcontrolador​
14 
Capítulo 3​
14 
LENGUAJE C​
14 
Introducción​
14 
Estructura de un programa​
14 
Operadores​
17 
Strings​
18 
Función printf​
19 
Casting​
19 
Ciclo for​
20 
Ciclo do-while​
20 
Definición de tipos propios (Typedef)​
21 
Estructuras de compos de bits en dsPIC33​
21 
Uniones​
22 
​
23 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 2 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
Capítulo 4​
23 
ENTORNO DE DESARROLLO MPLAB X​
23 
Introducción​
23 
Descarga​
24 
Instalación y Uso dentro del marco de la Asignatura​
25 
Inicio de un Proyecto​
26 
Configuración del Simulador​
34 
Simulación​
35 
Menú Window​
37 
Menú View​
38 
Capítulo 5​
38 
CONVERSOR ANALÓGICO-DIGITAL (ADC)​
38 
Introducción​
38 
Capítulo 6​
41 
RECEPTOR TRANSMISOR ASINCRONICO UNIVERSAL (UART)​
41 
Introducción​
41 
Transmisión  y Recepción de datos​
42 
Norma EIA 232 / RS-232​
44 
Aplicación de referencia​
44 
inicialización​
45 
 
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 3 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
​Capítulo 1 
​Detalles de Funcionalidad de Microprocesadores 
​Microcontroladores PIC24, dsPIC33 
Los PIC (Peripheral Interface Controller) de estas familias son un microcontroladores CMOS FLASH de 16 bits 
de arquitectura RISC  (Reduced Instruction Set Computer - Computadora con un Conjunto Reducido de 
Instrucciones) diferenciándose así de los CISC (Complex Instruction Set Computing utilizados por toda la familia 
Intel x86). Esta definición no es tan rigurosa dado que el set RISC recibe permanentemente ampliaciones. No 
obstante, tal denominación se sigue utilizando dado que las instrucciones a pesar de ser muy variadas, se siguen 
ejecutando en general en un ciclo de clock. 
​Características 
​
La familia tiene importantes características como: 
 
​
Procesador tipo RISC (Procesador con un Conjunto Reducido de Instrucciones). 
​
Procesador segmentado. 
​
Arquitectura HARVARD. 
​
Arquitectura orientada al uso de Lenguaje C. 
​
Memoria de programa lineal hasta 88K instrucciones. 
​
Memoria de datos hasta 32Kbytes. 
​
Instrucciones de 24 bits y datos de 16 bits. 
​
Niveles de prioridad para las interrupciones. 
​
Capacidad de proceso de 40MIPS (aunque esto está en continuo aumento) 
​
Las instrucciones se ejecutan en un sólo ciclo de máquina excepto los saltos (bra, goto y call), que 
requieren 2 ciclos. Aquí hay que especificar que un ciclo de máquina en general lleva 2 o 4 ciclos de 
reloj. Por ejemplo, si se utiliza el reloj interno de 4MHz, los ciclos de máquina se realizarán con una 
frecuencia de 1MHz, es decir que cada instrucción se ejecutará en 1uS (microsegundo). 
​
Temporizadores. 
​
Manejo de Stack (pila).​
 
​
Módulos de comunicación serie, comparadores, PWM. 
 
Debido a la necesidad de conseguir elevados rendimientos en el proceso, se ha desembocado en el empleo 
generalizado de procesadores de arquitectura Harvard frente a los tradicionales que seguían la arquitectura de von 
Neumann. 
​Arquitectura von Neumann 
Su característica principal es que la CPU se conecta con una memoria única, donde coexisten datos e 
instrucciones, a través de un sistema de buses. 
 
Figura 1: Arquitectura von Neumann 
​Arquitectura Harvard  
En la arquitectura Harvard son independientes la memoria de instrucciones y la memoria de datos y cada una 
dispone de su propio sistema de buses para el acceso. Esta dualidad, además de propiciar el paralelismo, permite la 
adecuación del tamaño de las palabras y los buses a los requerimientos específicos de las instrucciones y de los 
datos. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 4 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
Figura 2: Arquitectura Harvard 
 
La separación de los dos tipos de memoria son los pilares de la arquitectura Harvard, esto permite acceder en 
forma simultánea e independiente a la memoria de datos y a la de instrucciones de programa. El tener memorias 
separadas permite que cada una tenga el ancho y tamaño más adecuado. En estas familias el ancho del bus de datos 
es de 16 bits, mientras que el bus de instrucciones es de 24 bits. Los buses de direcciones son de 16 bits para la 
memoria de datos y 23 bits para la memoria de programa. 
​Procesador tipo RISC y Segmentado 
El procesador de los modernos microcontroladores responde a la arquitectura RISC (Computadores de Juego de 
Instrucciones Reducido), que se identifica por poseer un repertorio de instrucciones máquina pequeño y simple, de 
forma que la mayor parte de las instrucciones se ejecutan en un ciclo de instrucción.  
Otro aporte que aumenta el rendimiento del computador es el fomento del paralelismo implícito, que consiste en la 
segmentación del procesador (pipe-line), descomponiéndolo en etapas para poder procesar una instrucción 
diferente en cada una de ellas y trabajar con varias a la vez. Con la estructura segmentada se pueden realizar 
simultáneamente las dos fases en que se descompone cada instrucción, ejecución de la instrucción y búsqueda de 
la siguiente. Con estos recursos el PIC es capaz de ejecutar instrucciones solamente en un ciclo de instrucción.  
Otra característica de los PICs es el manejo de los bancos de registros. En línea general, los registros se clasifican 
como de uso general (GPR) y de uso específico o de funciones especiales (SFR). 
Los registros de uso general (es la zona R/W del programador) pueden ser usados directamente por el usuario, sin 
existir restricciones. Pueden servir para almacenar resultados que se reciben desde los registros de trabajo W (hay 
16 de ellos, de W0 a W15), datos que provienen de las puertas de entradas, etc. 
Los registros de uso específicos no pueden ser usados directamente por el usuario. Estos registros controlan 
prácticamente todo el funcionamiento del microcontrolador, pues toda la configuración necesaria para 
funcionamiento del microcontrolador es hecho a través de algún tipo de SFR. 
 
​Puertos 
El microcontrolador posee puertos paralelos, en general de 16 bits, que se compatibilizan (multiplexión) con 
terminales de entrada y salida de otros dispositivos embebidos. Las siguientes son condiciones generales que 
cumplen alguno o todos los terminales de los puertos: 
-​
Los pines de los puertos son bidireccionales y manejan señales de 0 a 5Vo 0 a 3,3v. 
-​
Algunos pines del PORTA PORTB, también pueden ser utilizados como entradas analógicas. 
-​
Los pines RB0-RB15 se puede utilizar también como entrada de pulsos para provocar una interrupción 
externa. 
 
​Otros pines 
 
-​
VDD: Pin de alimentación positiva. De 2 a 5,5 Vcc. 
-​
VSS: Pin de alimentación negativa. Se conecta a tierra o a 0 Vcc. 
-​
MCLR: Master Clear (Reset). Si el nivel lógico de este terminal es bajo (0 Vcc), el microcontrolador 
permanece inactivo. Este Reset se controla mediante la palabra de configuración del PIC. 
-​
OSC1/OSC2: Entrada de oscilador externo. 
​
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 5 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
Figura 4. Organización interna.
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 6 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
​Organización de la memoria 
La familia PIC24, dsPIC30 y dsPIC33 tiene 2 bloques de memoria: 
 
​Memoria de Programa Flash/Rom. 
​Memoria de Datos RAM. 
 
Las memorias de datos y de programa tienen buses separados, lo que permite accesos a ambas zonas en un mismo 
ciclo de máquina. 
​Memoria de Programa 
La familia posee un contador de programa (PC) de 23 bits, lo que permite direccionar hasta 4MWords de memoria 
de programa (4 MInstrucciones), aunque los distintos integrantes de la familia tienen siempre instalada una 
cantidad bastante menor. El bit menos significativo del PC siempre es CERO (solo direcciona posiciones pares). 
El vector de Reset se encuentra en la dirección 0x0002, mientras que los vectores de Interrupción se encuentran 
entre las direcciones 0x0004 y la 0x01FF. 
 
 
 
Figura 5. Organización de la Memoria de Programa de un componente de la familia de 16 bits. 
 
Como puede apreciarse en la figura 5, cada instrucción se inicia en una dirección par. Como el tamaño de cada 
celda de la memoria de programa es de 16 bits, cada instrucción ocupa dos palabras de 16 bits, esto es 32 bits. No 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 7 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
obstante, como de estos sólo son necesarios 24 bits, los 8 bits de mayor peso de la dirección impar no se utilizan y 
siempre están en CERO (Se lo denomina byte fantasma). Además, para asegurarse que siempre se comienza la 
lectura por una posición par, el bit menos significativo del bus de direcciones de programa siempre está en CERO. 
 
 
 
Figura 6. Organización de la Memoria de Programa. 
 
​SP (Stack Pointer) 
Es el registro puntero de la Pila del microcontrolador (implícitamente es el registro de trabajo W15). Su utilización 
es automática, ya que el PC se introduce en la pila durante la ejecución de una instrucción CALL o de una 
interrupción, y se extrae de la pila durante la ejecución del retorno correspondiente 
 
 
Figura 7. Mapa de los registros de funciones especiales más importantes. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 8 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
La pila habitualmente se la ubica en la zona de los GPR, luego de la zona de variables definidas por el programa. 
La pila crece hacia las direcciones ascendentes. El programador puede fijar el punto de inicio del Stack Pointer. 
​Memoria de Datos 
La RAM está compartida con los registros de función especial SFRs y los registros de propósito general (GPRs). 
Los SFRs comienzan su localización en la primera posición de memoria (0x0000) y finalizan en la posición 
0x07FF. Los GPRs están ubicados desde la posición 0x0800 en adelante, hasta el final de la memoria existente la 
cual es variable para cada miembro de la familia.  
Toda la RAM puede ser accedida en forma directa o indirecta. La arquitectura de esta familia permite el acceso a 
cualquiera de las posiciones de RAM (SFRs/GPRs) en una sola instrucción. 
 
En la zona izquierda de la figura 7 puede apreciarse los 16 registros de trabajo, cada uno de ellos puede utilizarse 
como acumulador de datos y efectuar operaciones con él. Asimismo pueden utilizarse indistintamente como 
registros punteros. En caso de utilizar pila el registro W15 asume la función de Stack Pointer. Los registros W0 a 
W3 poseen registros sombra permitiendo efectuar un guardado rápido de los mismos. El registro SPLIM fija el 
tope de la Pila.  
​Registro STATUS 
Junto con los registros de trabajo es uno de los registros más usados. Este registro contiene los estados aritméticos 
de la ALU. Al pie de la figura 7 se presenta cada una de las posiciones de bit de Status. Estas son: 
 
​
Bit 15-9​Funciones especiales (fuera del alcance de este tratado). 
 
​
Bit 8​
DC: Bit de Digital Carry / borrow. 
​
​
1 =  Se pone en 1 cuando se produce un acarreo en el cuarto bit. De interés en operaciones BCD. 
​
​
0 =  Se pone en 0 cuando no existe acarreo en el cuarto bit. 
Nota: Para  borrow, la polaridad es invertida. Una sustracción es ejecutada sumando el 
complemento a 2 del segundo operando. Para las instrucciones de rotación (RRF, RLF), este bit 
es cargado con cualquiera de los bits 3 o 4 del registro fuente. 
​
Bit 7-4​ Funciones especiales (fuera del alcance de este tratado). 
 
Bit 3​
N: Bit de Negación. 
Este bit es usado para la aritmética signada (complemento a 2). Indica cuando el resultado es 
negativo (ALU MSB = 1). 
​
​
1 = Resultado fue negativo. 
​
​
0 = Resultado fue positivo. 
 
​
Bit 2​
OV: Bit de Overflow. 
Este bit es usado para la aritmética signada (complemento a 2). Indica un overflow en el bit 7, lo 
que causa un cambio de estado en el bit de signo (bit 7 del resultado). 
​
​
1 = Overflow ocurrido por aritmética signada. 
​
​
0 = Sin ocurrencia de overflow. 
 
​
Bit 1​
Z: Bit de Cero (Zero). 
​
​
1 =  El resultado de una operación Aritmético-Lógica ha sido 0. 
​
​
0 =  El resultado de una operación Aritmético-Lógica no ha sido 0. 
 
Bit 0​
C: Bit de Carry / borrow . 
​
​
1 =  Se pone en 1 cuando se produce un acarreo en el bit de mayor peso. 
​
​
0 =  Se pone en 0 cuando no existe acarreo en el bit de mayor peso. 
Nota: Para  borrow, la polaridad es invertida. Una sustracción es ejecutada sumando el 
complemento a 2 del segundo operando. Para las instrucciones de rotación (RRF, RLF), este bit 
es cargado con cualquiera de los bits de mayor o menor orden del registro fuente. 
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 9 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
​Manejo de Puertos 
La familia cuenta con varios puertos de 16 bits PORTA, PORTB, PORTC, etc La cantidad de estos es variable 
según el miembro de la familia. Algunos pines de estos puertos de entrada/salida son multiplexados (compartidos) 
con una función alternativa de los módulos periféricos del dispositivo. Cuando un periférico es activado el pin no 
puede ser usado para propósitos generales de e/s. 
Cada puerto dispone de tres registros: 
1.​
PORTx: Registro correspondiente a los pines del puerto, que se conecta con los pines de salida. Se utiliza 
para leer el estado de las entradas. Por razones de compatibilidad, escribir en esta dirección equivale a 
hacerlo en la dirección LATx. 
2.​
LATx: Es el registro de salida del puerto. Es donde se almacenan los datos que pueden salir por los 
correspondientes pines de puerto. Se utiliza para escribir el estado que se desea poner en las salidas. Si se 
lee esta dirección, se leerá el valor que hay en los registros y no el estado de los pines. 
3.​
TRISx: Registros que se utiliza para configurar los pines del puerto, de forma individual y dinámica,. Un 
pin puede estar configurado como entrada o salida (no ambas a la vez). Cada bit del TRIS está 
relacionado con un pin del PORT correspondiente de modo que, colocando un 1 en un bit, queda definido 
que el pin correspondiente es de entrada. Colocando un 0, el pin correspondiente queda definido como 
salida. 
 
 
 
Figura 8. Esquema interno de un pin I/O de un PORT. 
 
​Interrupciones 
Una interrupción es un evento que hace que el microcontrolador deje de ejecutar la tarea que está realizando para 
atender dicho acontecimiento y luego regrese y continúe la tarea que estaba realizando antes de que se presentara 
la interrupción. 
Las familias de 16 bits tienen múltiples fuentes de interrupción tanto internas como externas, y proporcionan 
prioridad de interrupciones que permite a las fuentes de interrupción ser asignadas a un nivel de prioridad alto o a 
un nivel bajo (prioridad 0 a 7). Cada fuente de interrupción tiene un vector de interrupción. Ese vector se encuentra 
entre las direcciones 0x0004 y 0x00FE y su tamaño es de 2 words. En dicho vector se guarda en el momento de 
compilación la dirección de inicio de la rutina de servicio que trata la interrupción. Esta rutina de servicio es 
similar a una subrutina convencional, pero su función es la de contener el programa que se ejecutará cuando la 
interrupción ocurra. Los eventos de interrupción de alta prioridad interrumpirán cualquier interrupción de baja 
prioridad que se encuentre en progreso. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 10 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
En general las fuentes de interrupción tienen tres grupos de bits para controlar su operación. El Bit de Habilitación 
que permite habilitar una interrupción específica. Los bits de Prioridad para seleccionar el nivel de prioridad bajo 
(CERO) o bajo (7). El Bit de Flag para identificar cuál es la interrupción que ha ocurrido. 
La dirección de retorno es colocada automáticamente en la Pila (stack) y el PC es cargado con la dirección 
contenida en el vector de interrupciones correspondiente a la INT en cuestión. Una vez en la Rutina de Servicio de 
la Interrupción, el Flag de interrupción correspondiente debe ser puestos a 0, antes de volver al programa principal 
ya que si no se lo hace se causarán interrupciones recursivas. 
 
 
 
 Figura 9. Esquema general de Interrupciones en un PIC típico. 
 
​Fuentes de Interrupción 
Los PIC tienen fuentes de interrupción internas y fuentes de interrupción externas. Si las interrupciones están 
habilitadas, cada vez que uno de estos acontecimientos se presente el microcontrolador dejará de ejecutar el 
programa para ir a atender la interrupción y al término de la misma continuará ejecutando el programa donde lo 
había dejado.  
 
Una de las fuentes de interrupción Externas con las que se trabajará es la INT4 (interrupción externa 4) que tiene 
las siguientes características. 
- Su PIN externo se encuentra en el PBA15 (en general en toda la familia). 
- Esta interrupción posee su vector en la dirección 0x000080 de la memoria de programa. 
- Se habilita con el bit 6 del registro IEC3 (Interrupt Enable Control 3). 
- El flag de Status se encuentra en el bit  6 del IFS3 (Interrupt Falg Status 3). 
- La prioridad está fijada en 4 en los bits 8 a 10 del IPC13 (Interrupt Priority Control 3). 
 
​Fases de una interrupción 
Se expone ordenadamente la secuencia de acciones que se llevan a cabo cuando se atiende a una interrupción. 
1.​
Si la interrupción está habilitada con su bit en 1 en el IEC correspondiente y si la prioridad está 
establecida en un valor SUPERIOR a la prioridad del procesador, se puede activar la interrupción. 
2.​
 El flag de STATUS de dicha causa se pone en alto. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 11 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
3.​
El valor actual del PC se guarda en la Pila. Juntamente con él se guardan los flags DC,OV,C,N y Z del 
SR. Estos datos ocupan DOS Words en la pila (O sea que el SP queda apuntando a cuatro posiciones más 
delante de la que se encontraba antes del llamado). 
4.​
El PC se carga con el valor existente en el  vector de interrupción correspondiente. 
5.​
Se entra en la rutina de servicio de la interrupción en cuestión. 
6.​
Se debe borrar la bandera por software, antes de realizar el retorno. 
7.​
Cuando se llega a la ultima instrucción de la rutina de interrupción, que es normalmente RETFIE 
(retorno de interrupción), se carga en el PC el valor que inicialmente se guardo en la Pila. 
 
 
 
R.LOPEZ – 2008/2012 
S.WAHLER – 2008/2010 
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 12 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
​Capítulo 2 
​LENGUAJE ENSAMBLADOR 
​Introducción 
 
El ensamblador que utiliza MPLAB (Aplicación que se explicará en el capitulo siguiente) por defecto y el que 
utilizaremos para programar los PIC es MPASM. Los elementos básicos del lenguaje ensamblador son: 
​
Etiquetas. 
​
Instrucciones / Directivas. 
​
Operandos. 
​
Comentarios. 
 
Para la programación se utiliza una cierta tabulación que se debe respetar, además utilizar una tabulación adecuada 
hace los programas más claros y legibles. Las etiquetas se escriben en la primer columna de cualquier línea, las 
instrucciones y directivas en la segunda columna y por último, en la tercer columna, los operandos. Los 
comentarios se pueden escribir en cualquier parte del programa. 
 
​Etiquetas 
 
Las etiquetas son nombres de subrutinas o secciones de código fuente. Dando nombres a partes del programa, se 
usan para posibilitar el salto desde cualquier posición del programa hacia la etiqueta sin necesidad de recordar las 
direcciones físicas donde están ubicadas. 
El ensamblador MPASM permite etiquetas de hasta 32 caracteres. Es importante que las etiquetas empiecen con 
una letra o con un guión bajo “_”. Una etiqueta puede ir seguida de dos puntos (:), espacios, tabuladores o 
RETURN. La longitud de una etiqueta puede ser de hasta 32 caracteres y como ya se dijo se deben escribir en la 
primer columna y será parte del campo de etiquetas. 
 
​Instrucciones o directivas 
 
La segunda columna corresponde al campo de instrucciones. Son las operaciones que realiza el microcontrolador, 
así que estas ya están definidas para cada familia de PIC. El 16F628a así como todos los PICs de gama media 
utiliza un conjunto de 35 instrucciones que están definidas en la hoja de datos del PIC.  
También puede ser una instrucción para el ensamblador llamada directiva. Las directivas son similares a las 
instrucciones, pero a diferencia de estas, las directivas son propias del lenguaje ensamblador e independientes del 
microcontrolador que se utilice. Las directivas representan algunas  características del lenguaje ensamblador, se 
utilizan para especificar el procesador empleado así como la configuración de este, también para asignar 
locaciones de memoria, entre otras cosas. 
 
​Datos u operandos 
 
La tercer columna se trata del campo de datos u operandos para las instrucciones. En los PICs, los datos pueden 
ser un registro, un bit de un registro, una etiqueta o un número constante (llamado literal). Algunas instrucciones 
no llevan datos. Si una instrucción necesita múltiples datos, deben separarse por comas (,). 
La especificación de la base en la que se expresan los datos u operandos es opcional: d’65’, b’01000001’,0x41, 
son el mismo dato o’101’ y ‘A’ también son el mismo dato. El prefijo d o D se emplea para expresar un valor en 
decimal. El prefijo b o B expresa un valor en binario. Para expresar un valor en hexadecimal se emplea el prefijo 
0x ó 0X. 
Un número en base octal se representa mediante el prefijo o ó O. Finalmente, un valor se puede expresar mediante 
un caracter ASCII si se encierra entre comillas simples como ‘A’. 
 
 
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 13 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
​Comentarios 
 
La última columna es el campo de comentarios, siempre que haya un punto y coma (;) como primer carácter. 
Puede colocarse en cualquier lugar del código fuente. 
Los comentarios en ensamblador son muy importantes. Los comentarios deben describir las tareas que realizan las 
instrucciones y/o subrutinas. Sin comentarios, es muy difícil descifrar, algunos días después, el código fuente que 
uno mismo ha creado. 
A continuación se muestra como debe quedar un programa con buen estilo de programación: 
 
 
 
​El primer programa: EJEMPLO1.ASM 
 
Vamos a ir examinando las distintas partes del programa EJEMPLO1.ASM y explicando cada una de ellas. 
 
​Directivas 
 
Una directiva es un comando escrito en el código fuente para realizar un control directo o ahorrar tiempo a la hora 
de ensamblar. El resultado de incorporar directivas se puede ver en el fichero *.LST después de ensamblar el 
programa. 
En el programa EJEMPLO1.ASM aparecen las siguientes directivas: 
 
∙ LIST → permite elegir, entre otras cosas, el tipo de microcontrolador a utilizar (P), número de caracteres 
por línea (C), tamaño de los tabuladores (B), base de numeración por defecto (R), niveles de 
mensajes de salida (W), etc. 
∙ EQU → se utiliza para asignar valores a las etiquetas deseadas. Así, Resultado, tiene asignado el valor 
0x10, y puede referirse a un registro de la memoria de datos del PIC. 
∙ ORG → indica al ensamblador dónde debe comenzar a colocar las instrucciones en la memoria de 
programa. Es decir, es el ORiGen para todo el código que sigue. La dirección de comienzo 
(origen) es en la posición 0, debido a que la familia de microcontroladores PIC de gama media 
después del encendido o RESET siempre ejecutan la instrucción situada en la dirección0. Se 
denomina Vector de Reset. 
La dirección 4 es el Vector de Interrupción. Si se genera una interrupción el microcontrolador 
ejecuta la instrucción que se encuentre aquí. Es una buena práctica dejar libre la dirección 4 por 
si más adelante deseamos añadir capacidad de interrupción a nuestro programa. El programa 
salta por encima del Vector de interrupción y comienza en la dirección 5. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 14 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
∙ INCLUDE → permite añadir listados de programas al listado del programa actual. 
∙ END → indica al ensamblador el final del código fuente, donde ha de finalizar el proceso de 
ensamblado. 
 
​Código del programa 
 
Las tres instrucciones que siguen a la etiqueta Inicio realizan la suma de dos numeros literales, 7 y 6, y guardan el 
resultado de la suma en la posición de memoria 0x10 etiquetada como Resultado. 
Por último, nop es una instrucción que produce que el PIC no haga nada, significa no operación. 
 
​Secuencia a seguir para el grabado del microcontrolador 
 
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 15 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
S.WAHLER  -  18/02/09
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 16 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
​Capítulo 3 
​LENGUAJE C 
​Introducción 
 
El lenguaje de programación C es un lenguaje de alto nivel, pero muy cercano al bajo nivel. Por esto, es habitual 
que los microcontroladores puedan programarse en C. En la práctica se utilizará una versión libre del compilador 
C18 que permite programar los PICs de la familia 18. En este capítulo se verán algunos aspectos básicos del 
lenguaje C. Para una referencia completa se recomienda la lectura de “El lenguaje de Programación C” de Brian 
W. Kernighan y Dennis M. Ritchie, y “Aprenda C como en primero”. 
 
​Estructura de un programa 
Un programa en C es un conjunto de funciones donde una y solo una de ellas debe denominarse main. La función 
main es la función principal porque la ejecución del programa comienza por ahí. Además, la finalización de esta 
función implica la finalización de la ejecución del programa. Cabe aclarar que en el caso particular de los 
microcontroladores, la función main nunca finaliza, sino que permanece en un ciclo infinito. De esta forma el 
microcontrolador puede realizar en forma indefinida, la tarea para la cual fue programado. A continuación se 
muestra un programa básico en C, constituido únicamente por la función main: 
 
int main(void) { 
 
​
/* Esta línea es un comentario. */ 
​
 
while(1) { 
​printf(“Hola Mundo\n”); 
} 
} 
 
Si bien los distintos componentes de este programa de ejemplo se verán en secciones subsiguientes, pueden 
mencionarse aquí algunos rasgos del lenguaje, como una primera aproximación. Toda función debe indicar el tipo 
de valor de devuelve, (integer en este ejemplo), y el tipo de los argumentos que espera recibir. La palabra void 
como valor de retorno indica que la función no retornará un valor útil a quién la invoque. Si se utiliza esta palabra 
como argumento (como en el ejemplo), indica que la función no espera recibir parámetros en la invocación. Las 
llaves delimitan el comienzo y fin de funciones y de otras estructuras del lenguaje (while, if, etc.). El valor 
numérico 1 siempre se evalúa como verdadero en un contexto donde se espera un valor lógico. Por esto, nuestro 
primer programa de ejemplo imprimirá indefinidamente “Hola Mundo” en la salida estándar (el concepto de salida 
estándar se explica en la sección referida a la función printf, más adelante). 
 
​Operadores 
 
Entre los operadores más utilizados de C se encuentran los siguientes 
 
Operadores 
Significado 
+  -  *  / 
Aritméticos básicos 
++  --  % 
Otros operadores aritméticos 
[]  . 
Acceso a elementos de un arreglo o estructura 
<  <=  >  >= 
Comparación aritmética 
==  != 
Comparación por igualdad y desigualdad respectivamente 
& 
And a nivel de bit o dirección de una variable 
| 
Or a nivel de bit 
&&  || 
And y or lógicos 
?: 
Asignación condicional 
=  +=  -=  *=  /= 
Asignación simple y asignaciones compuestas 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 17 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
Dejando de lado los operadores aritméticos básicos y los operadores de comparación aritmética, a continuación de 
describe el resto de los operadores. 
Se dice que los operadores son unarios cuando se aplican y afectan a un solo operando. Un mismo operador puede 
tener diferente significado si se utiliza como unario o no. Un ejemplo de esto es el operador & que se describe más 
adelante. 
Los operadores unarios de incremento (++) y decremento (--) se utilizan para incrementar en una unidad o 
decrementar en una unidad una variable entera. Estos operadores se pueden utilizar como prefijo o como sufijo. Si 
se utilizan como prefijo (por ej. ++i), el valor de la variable se modifica y luego se usa el valor ya modificado en el 
contexto en que se encuentra. En cambio si se utilizan como sufijo, primero se utiliza la variable en su contexto y 
luego se incrementa. Por ejemplo, la sentencia 
 
val = vector[i++]; 
 
Asigna a la variable val, el valor de la posición i (sin modificar) del arreglo vector y luego de esta asignación se 
incrementa i, con lo cual queda apuntando al próximo elemento en el arreglo. 
El operador % representa el módulo de una división entera. Se aplica a dos operandos y devuelve el resto de la 
división entera del primer operando por el segundo. Por ejemplo, una forma de verificar si un número es impar o 
no, es 
 
if(n % 2) { 
​
/* El valor de n es impar */ 
​
… 
​
… 
​
… 
} 
 
Ya que en C el valor 0 (cero) se considera falso y cualquier valor numérico distinto de 0 se considera verdadero, y 
en este caso el módulo será igual a 0 o a 1. 
Para acceder a un elemento de un arreglo se utilizan los corchetes con el subíndice del elemento deseado, por 
ejemplo v[3] accede al cuarto elemento del arreglo v. Debe tenerse en cuenta que los elementos de un arreglo se 
numeran desde 0 (cero) en adelante, hasta el tamaño menos uno. 
Las estructuras tienen la forma 
 
struct mi_estructura { 
​
int val1; 
​
long val2; 
} miestruc; 
 
Para acceder a un elemento de una estructura se utiliza el operador punto (.). Por ejemplo, para acceder al campo 
de tipo long de la estructura de arriba, y asignarle un valor, se utiliza el operador de esta manera 
miestruc.val2 = 70000; 
La igualdad en C se comprueba con el operador ==, el cual no debe confundirse con el operador = que es el 
operador de asignación. Intercambiar inadvertidamente estos dos operadores es una de las confusiones más típicas 
en los programadores principiantes de C. Además, considerando que toda expresión tiene un valor numérico en C, 
y que todo valor numérico a su vez tiene un valor de verdad (cero para verdadero y distinto de cero para falso), un 
caso como 
 
if(n = 3) { 
​
/* Siempre se ejecutan estas sentencias */ 
​
… 
​
… 
​
… 
} 
 
No será interpretado como un error para el compilador. En este caso la condición del if siempre se evalúa como 
verdadero, ya que es una asignación de valor 3. El valor numérico de una expresión aritmética de asignación es el 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 18 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
valor asignado, y como el resultado es 3 y por lo tanto, distinto de cero, se considera como verdadero. Esto es muy 
diferente de 
 
if(n == 3) { 
​
/* Estas sentencias solo se ejecutan si n es igual a tres */ 
​
… 
​
… 
​
… 
} 
 
Además en este último caso el valor de n no se modifica como en el primero. 
El operador para comparar por distinto es !=. 
 
​Strings 
 
En C no existe el tipo de datos String como en otros lenguajes. Un string en C es un conjunto de caracteres 
almacenados consecutivamente en memoria. El último carácter del string debe ser siempre el carácter especial ‘\0’, 
cuyo valor numérico es cero. Esta es la forma de marcar el final del string. Por lo tanto la forma más común de 
utilizar strings en C es mediante arreglos de caracteres. Por ejemplo, si el arreglo de caracteres: 
char cadena[10]; 
 
Contiene estos valores: 
 
H 
o 
l 
a 
\n 
\0 
 
 
 
 
0 
1 
2 
3 
4 
5 
6 
7 
8 
9 
 
Se puede interpretar como el string “Hola\n” que es la palabra Hola seguida de un carácter nueva línea. Es 
importante que el arreglo tenga espacio suficiente para la cadena y para el carácter ‘\0’. Un string puede contener 
tanto caracteres imprimibles como no imprimibles. Para incluir un carácter especial en un string, se utiliza la 
secuencia de escape barra invertida, como en el caso del carácter nueva línea del ejemplo anterior. Si bien, como 
se mencionó anteriormente, C no contempla un tipo de datos básico para string, sí está permitido utilizar strings 
literales. Para demarcar los strings literales en el código C, se utilizan las comillas dobles. Por ejemplo, las 
siguientes líneas de código son válidas en lenguaje C: 
 
Char cadena[] = “String de inicialización”; 
miFuncion(“Esta es una cadena de caracteres”); 
 
​Función printf 
 
La función printf pertenece a la librería estándar de C y se utiliza para imprimir caracteres en la salida estándar. La 
salida estándar en una PC de escritorio es normalmente el monitor de la misma, mientras que en un 
microcontrolador, por lo general, la salida estándar es una puerta serie (UART). La forma más simple de utilizar 
printf es esta: 
 
printf(“Hola mundo!\n”); 
 
Que imprime en la salida estándar “Hola mundo!” seguido de un carácter nueva línea. Sin embargo la utilidad 
principal de printf es que esta función es capaz de imprimir con formato. Invocando a printf se pueden imprimir 
valores de variables, contantes o literales del programa aún cuando éstas sean de diferentes tipos. Printf realiza la 
conversión a caracteres apropiada para cada valor a imprimir siempre y cuando se utilicen las especificaciones de 
conversión necesarias. La declaración de printf es la siguiente: 
 
int printf( char * formato, arg1, arg2, …) 
 
Printf acepta una cantidad variable de argumentos (mínimo uno), y los tipos de estos argumentos no están 
previamente definidos, excepto el primero (que es char *). El primer argumento es el string de formato. Este string 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 19 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
contiene dos tipos de elementos, caracteres comunes y secuencias de caracteres que conforman especificadores de 
conversión. Los especificadores de conversión siempre comienzan con el carácter ‘%’. Printf se comporta de la 
siguiente manera. Recorre el string de formato de izquierda a derecha y cada vez que encuentra un carácter común 
lo imprime en la salida estándar. En cambio, cuando encuentra un especificador de conversión busca 
(posicionalmente) en los argumentos, el valor a convertir. En la siguiente tabla se muestran algunos de los 
especificadores de conversión más utilizados: 
 
Especificador de 
conversión 
Tipo de 
argumento 
Impreso como 
%d 
int 
Número decimal 
%x 
int 
Número hexadecimal 
%c 
int 
Carácter sencillo 
%u 
int 
Número decimal sin signo 
%f 
double 
[-]ddd.dddddd (la cantidad de dígitos antes y después del 
punto puede modificarse) 
%s 
char * 
Imprime caracteres de una cadena hasta un ‘\0’ 
%% 
- 
Se utiliza para imprimir el carácter ‘%’ 
 
Los siguientes son ejemplos válidos del uso de printf: 
 
int i, double d; 
i = 5; 
d = 3.14; 
printf(“Valor de i = %d, valor de d = %f\n”, i, d); 
printf(“Valores literales: Valor 1 = %d, Valor 2 = %f\n”, 5, 3.14); 
 
​Casting 
 
En C cuando un operador tiene operandos de diferentes tipos, ocurren conversiones de tipos de manera automática 
y siguiendo un conjunto de reglas bien definido. El compilador no considera errónea esta situación.  En general se 
convierten los tipos más chicos a los tipos más grandes, con el fin de no perder información. Por ejemplo, si i es 
una variable entera y d una variable de tipo double, entonces al evaluar la expresión 
 
i + d 
Primero se convierte i a double y luego se realiza la suma, siendo el resultado de la expresión un valor de tipo 
double. 
Cuando se desea forzar una conversión de tipo de manera explicita se puede utilizar el operador unario 
denominado cast. Este operador consiste en un nombre de tipo encerrado entre paréntesis, que se antepone a una 
variable o a una expresión. En la construcción 
 
(nombre-de-tipo) expresión 
 
La expresión es convertida al tipo nombrado. El siguiente es un ejemplo de un cast explicito 
 
unsigned long int n; 
unsigned int r; 
n = 1103515245 + 12345; 
r = (unsigned int) (n/65536) % 32768; 
 
​Ciclo for 
 
El ciclo for tiene la siguiente estructura 
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 20 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
for(expr1; expr2; expr3) 
​
proposición 
 
Y es equivalente a 
 
expr1; 
while(expr2) { 
​
proposición 
​
expr3; 
} 
 
En el ciclo for, la expresión expr1 se evalúa una sola vez al principio y se considera una inicialización del ciclo. 
Luego se evalúa por verdadero o falso la expresión expr2. Si ocurre que expr2 es verdadero (distinto de cero), 
entonces se ejecuta la proposición, que puede ser una sentencia simple o un conjunto de sentencias entre llaves. 
Luego de ejecutar la proposición se evalúa la expresión expr3. El ciclo se repite evaluando expr2, proposición, 
expr3 mientras expr2 sea verdadero. Ninguna de las expresiones es obligatoria. Si expr2 está ausente se considera 
verdadero, por lo tanto 
 
for(;;) { 
​
… 
} 
 
Es un ciclo infinito. Un ejemplo más habitual puede ser el siguiente 
 
for(i = 0; i < n; ++i) { 
​
… 
​
… 
​
… 
} 
 
Si la proposición es un conjunto de sentencias, se puede utilizar continue para forzar la evaluación inmediata de 
expr3, sin ejecutar las sentencias debajo de continue. Por otro lado se puede utilizar break para interrumpir la 
iteración y saltar a la sentencia siguiente al ciclo for. 
 
​Ciclo do-while 
 
La estructura del ciclo do-while es la siguiente 
 
do 
​
proposición 
while(expresión); 
 
A diferencia de los ciclos for y while, el ciclo do-while verifica la condición de término al final, después de 
realizar cada paso a través del cuerpo del ciclo. En el cuerpo del ciclo (proposición) se puede utilizar continue para 
forzar la evaluación inmediata de expresión, al igual que en el ciclo for. También se puede utilizar break para salir 
del ciclo do-while de forma inmediata. 
 
​Definición de tipos propios (Typedef) 
Se pueden definir tipos propios a partir de tipos ya existentes en el lenguaje. Un caso sencillo de uso de esta 
capacidad sería dar un nombre más significativo para un problema en particular a un tipo ya existente. Por 
ejemplo: 
 
typedef unsigned int t_edad;​
// Tendría sentido ya que las edades no son negativas 
typedef unsigned int T_PID; ​
​
// T_PID: Tipo Process ID (Identificador de 
proceso) 
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 21 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
A partir de estas definiciones de tipo se pueden crear variables de estos tipos, de la siguiente manera: 
 
t_edad edadPepe;​
​
// edadPepe es un entero sin signo 
T_PID pid1, pid2;​
​
// Dos variables de tipo T_PID 
 
Un caso más habitual es dar nombre a tipo que consiste en una estructura. Por ejemplo: 
 
typedef struct  { 
​
int x; 
​
int y; 
} t_punto; 
 
Este nuevo tipo nos permite definir, de manera mas cómoda y legible, variables que representen puntos en un 
plano (ya que tiene dos dimensiones, x e y). En base a este nuevo tipo podríamos definir variables de la siguiente 
manera: 
 
t_punto punto1, punto2; 
 
​Estructuras de compos de bits en dsPIC33 
 
Las estructuras de campos de bits no deberían confundirse con las estructuras tradicionales vistas más arriba. En 
este caso se utiliza una sintáxis similar a la de las estructuras, inclusive con la palabra clave struct, pero para dar 
nombre (y poder acceder en forma independiente) a diferentes bits de una posición de memoria. Esto es muy 
utilizado en el ámbito de los microcontroladores, donde es habitual trabajar con bits independientes, o conjuntos 
pequeños de bits, que no alcanzan a conformar siquiera un byte. 
Un ejemplo inspirado en el microcontrolador dsPIC33FJ256GP710, y combinado con un typedef es el siguiente 
que permite acceder a las benderas del registro de estados (SR – Status Register). 
 
En el Datasheet del microcontrolador podemos ver esta documentación: 
 
 
 
 
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 22 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
A partir de esto podemos definir un nuevo tipo utilizando una estructura de campos de bits, de la siguiente manera: 
 
typedef struct { 
        unsigned int C:1; 
        unsigned int Z:1; 
        unsigned int OV:1; 
        unsigned int N:1; 
        unsigned int RA:1; 
        unsigned int IPL:3; 
        unsigned int DC:1; 
        unsigned int DA:1; 
        unsigned int SAB:1; 
        unsigned int OAB:1; 
        unsigned int SB:1; 
        unsigned int SA:1; 
        unsigned int OB:1; 
        unsigned int OA:1; 
    } t_sr; 
 
Con este nuevo tipo se pueden crear variables de esta forma: 
 
t_sr reg_sr; 
 
Y luego acceder a diferentes campos como se muestra en los ejemplos a continuación. 
 
… 
int variable_temporal; 
… 
variable_temporal = reg_sr.C;   
// Asignación de la bandera de Carry a la variable 
temporal; 
variable_temporal = reg_sr.IPL; // Asignación del campo IPL a la variable temporal; 
 
​Uniones 
 
Por último vemos una posibilidad que brinda el lenguaje C, y que es útil para trabajar tanto en bajo como en alto 
nivel. Se trata de las uniones y sirven para utilizar una misma posición de memoria de diferentes maneras. Es 
decir, como si esa posición de memoria alojara valores de diferentes tipos de datos (no en simultáneo, sino en 
momentos diferentes de la ejecución del programa). En nuestro caso, y continuando con el ejemplo anterior, 
vamos a ver cómo podemos declarar un tipo, utilizando uniones, que nos permita acceder al valor de una variable 
(en nuestro caso, una copia del valor del SR) tanto por campos de bits como por su valor completo. 
La sintáxis de una union es idéntica a la de una estructura: 
 
union { 
​
int a; 
​
char b; 
} var1; 
 
La diferencia con las estructuras es que los diferentes campos declarados se ubican a partir de la misma dirección 
de memoria (elegida normalmente por el compilador). De esto se deriva que la memoria utilizada por una 
estructura es la suma del tamaño de sus campos, mientras que la memoria utilizada por una union es igual al 
tamaño del campo de mayor dimensión. 
 
A continuación vemos cómo utilizar typedef, uniones y estructuras para brindar la posibilidad de acceder a una 
variable tanto por su valor completo como por bits individuales (o campos de varios bits). 
 
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 23 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
typedef union { 
    struct { 
        unsigned int C:1; 
        unsigned int Z:1; 
        unsigned int OV:1; 
        unsigned int N:1; 
        unsigned int RA:1; 
        unsigned int IPL:3; 
        unsigned int DC:1; 
        unsigned int DA:1; 
        unsigned int SAB:1; 
        unsigned int OAB:1; 
        unsigned int SB:1; 
        unsigned int SA:1; 
        unsigned int OB:1; 
        unsigned int OA:1; 
    } bits; 
    unsigned int completo; 
} t_sr; 
 
Con este nuevo tipo podemos declarar una variable de la siguiente manera. 
 
t_sr status_register; 
 
Y luego en el código del programa podríamos ver asignaciones como las siguientes. 
 
    … 
    unsigned int var_temp; 
    … 
    status_register.completo = SR; 
    var_temp = status_register.bits.C; 
    var_temp = status_register.bits.IPL; 
 
 
 
 
 
 
​ 
 
 
 
M.GOMEZ  -  2010/2019
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 24 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
​
Capítulo 4 
​
ENTORNO DE DESARROLLO MPLAB X 
​
 
​Introducción 
El MPLAB X IDE es un programa que corre sobre una PC con el cual se pueden desarrollar aplicaciones para 
microcontroladores de la marca Microchip. Se dice que es un Entorno de Desarrollo Integrado, del inglés (IDE), 
debido a que provee un “entorno” integrado y sencillo para el desarrollo y depuración de código para 
microcontroladores embebidos. 
El MPLAB X permite escribir y desarrollar código en lenguaje ensamblador para los microcontroladores PIC de 
Microchip. Incorpora todas las herramientas necesarias para la realización de cualquier proyecto, ya que además 
de un editor de textos cuenta con un simulador MPLAB X SIM, en el que se puede ejecutar el código paso a paso 
para ver así su evolución y el estado en el que se encuentran sus registros en cada momento. 
El MPLAB X es un software gratuito que se encuentra disponible en la página de Microchip, 
https://www.microchip.com/mplab/mplab-x-ide , la versión que será utilizada en este capítulo y en los ejemplos 
subsiguientes es la 5.35. 
 
​Descarga 
Para descargar el programa se debe ingresar al link mencionado anteriormente, al bajar en la página se podrá 
encontrar la sección de descargas donde se puede elegir para qué sistema operativo se desea descargar la 
plataforma (MAC, Linux o Windows) como muestra la siguiente imagen. 
 
 
 
 
 
 
 
 
 
 
Una vez seleccionada la versión (señaladas por las flechas) se comienza la descarga del instalador del IDE 
MPLAB X. 
 
​Instalación y Uso dentro del marco de la Asignatura 
Lo primero es instalar el programa, es una tarea sencilla, para hacerse se debe cliquear el archivo recién 
descargado, al hacerlo se tendrá la siguiente ventana emergente. 
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 25 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
 
Se debe cliquear el botón “Next” que resalta la imagen anterior, luego se tendrá la siguiente ventana. 
 
 
Aquí se debe cliquear en el botón para aceptar los términos y condiciones, luego presionar el botón “Next” 
resaltado en la imagen anterior, una vez hecho esto se verá la siguiente ventana: 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 26 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
En este momento se debe seleccionar la opción “Use System Proxy Settings” y cliquear el botón “Next”. Ambos 
señalados en la imagen anterior. Una vez realizadas estas acciones se tendrá la siguiente ventana. 
 
En esta ventana se pueden elegir las aplicaciones a instalar, recomendamos que todas sean instaladas. Se debe 
cliquear el botón “Next” señalado en la imagen. Luego se tendrá la siguiente ventana. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 27 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
Aquí se debe cliquear solamente el botón “Next”. Una vez hecho esto se verá una ventana con una barra de carga 
mostrando el nivel de instalación. Se debe esperar hasta que termine la instalación. Una vez que la instalación fue 
completada se verá la siguiente imagen: 
 
Utilizamos la opción de “siempre confiar en software de microchip” para no tener que confirmar todas las 
instalaciones requeridas, puede no utilizarla y tomar la decisión de instalar o no cada complemento, 
recomendamos que si lo instale. Por último se tendrá la siguiente ventana. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 28 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
 
Aquí se debe quitar las tildes de las tres opciones, si se desea puede instalar los complementos. Por último, se debe 
cliquear el botón “Finish” y finaliza la instalación. 
En este momento, el IDE MPLABX debería estar instalado correctamente y se observará en el escritorio de la 
computadora los siguientes accesos directos. 
 
 
 
​Inicio de un Proyecto 
Al instalar el programa se puede proceder con todas las opciones que vengan por defecto, también se puede hacer 
una instalación personalizada, la cual se sugiere para usuarios con mayor experiencia. Al finalizar la instalación y 
ejecutar el programa se obtendrá una pantalla como la siguiente: 
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 29 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
De manera sencilla un nuevo proyecto se puede crear cliqueando en el botón “File”, ubicado en el sector superior 
izquierdo del IDE MPLAB X. Luego, debe cliquear en “New Project” al hacerlo aparecerá la siguiente pantalla.
 
En este primer paso de la creación de un nuevo proyecto, elegimos la opción “Standalone Project” y cliqueamos en 
el botón “Next” indicado en la imagen. Una vez realizadas estas acciones tendrá la siguiente pantalla, en la cual 
debemos seleccionar el PIC a utilizar. El PIC que debe elegir es el “dsPIC33FJ256GP710”, el cual figura en la lista 
de la familia de PIC’s “16-bit DSC(dsPIC33)” como se muestra en la siguiente imagen. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 30 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
Una vez que seleccione la familia de PIC’s mencionada y el PIC a utilizar, tambien mensionado anterior mente y 
luego presione el botón “Next” resaltado en la imagen previa, tendrá que elegir la herramienta que se usará para 
debuggin, debe seleccionar la opción “Real ICE” como se indica en la siguiente imagen. 
 
Una vez que haya presionado el botón “Next” resaltado en la imagen anterior, tendrá una ventana como la 
mostrada en la siguiente imagen, es un paso opcional que nos permite seleccionar un “tablero de pluggins”, no se 
le dará uso en la cátedra, por lo cual debe seleccionar la opción “None” como se muestra en la siguiente imagen. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 31 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
Al haber realizado la selección de tablero mencionada previamente y luego haber cliqueado el botón “Next” 
resaltado en la imagen anterior, tendra una ventana nueva en la que debe seleccionar el compilador a utilizar, aquí 
puede elegir entre distintos compiladores para distintos lenguajes ( Por ej. XC 16 para un programa en C, o 
ASM30 para un programa en Assembler). Según el PIC que se utilizará dependerá de qué programa puede usar 
para compilarlo, en nuestro caso, para el ya mencionado PIC a utilizar, usaremos el compilador XC 16. Debe 
seleccionarlo de la lista de compiladores como se muestra en la siguiente imagen. 
 
En la ventana siguiente se le debe dar un nombre al proyecto y escoger el directorio en el que se guardará el 
mismo. Es recomendable que la ruta de la carpeta donde se guarde el proyecto no sea excesivamente larga, ya que 
al compilador posee una restricción máxima de 62 caracteres, pudiendo arrojar en caso contrario, un error al 
compilar. ​
 
Para ello, se recomienda crear una carpeta en el disco “C:\” o en cualquiera que se use, lo más cerca del directorio 
raíz del disco. En este caso la ruta escogida es C:\MPLAB\Proyecto1. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 32 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
Una vez dado el nombre al proyecto, al hacer click en “Finish”, se le creará el proyecto, lo cual implica una serie 
de carpetas relacionadas que deberia verlas en la ventana “Projects”, la cual si no la puede ver puede clickear en el 
botón “Window” → “Projects”. Dicha ventana debería verse del siguiente modo con su proyecto recién creado. 
 
En este punto se puede escribir el código del programa a ejecutar. Para ello se crea un nuevo archivo y se lo guarda 
con extensión .c en la carpeta donde se tiene el proyecto. Para crear un archivo haga segundo click en Source Files 
→  New → mainXC16.c, como se indica en la siguiente imagen. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 33 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
Lo siguiente es agregar el archivo al proyecto y posteriormente escribir el código de programa. En la ventana del 
proyecto hacer click derecho en Source Files y después seleccionar Add Files. 
Una vez realizadas las acciones recién mencionadas se abrirá una ventana en la que debe darle nombre al archivo a 
crear (recomendamos por simplicidad que para el primer trabajo utilicen el nombre “main” como se hace en la 
siguiente imagen), también deben seleccionar la extensión del programa, en nuestro caso utilizaremos el lenguaje 
de programación C y por lo tanto crearemos un archivo con extensión “.c”. Todo esto lo vemos en la siguiente 
imagen. 
 
 
Cuando haya cliqueado en el botón “Finish” resaltado en la imagen anterior tendrá un archivo que podrá colocar el 
código a ejecutar, en principio el contenido del archivo es llenado por el IDE con el siguiente contenido. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 34 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
Todos los cambios que se efectúen en él se verán reflejados en el proyecto. Se escribió como ejemplo un código 
sencillo. Un programa que realice una suma de dos valores, guardando el resultado en una variable y restandole un 
valor constante definido previamente: 
 
Este ejemplo se escribió usando MPLABX, se puede ver que la aplicación reconoce la sintaxis del lenguaje C y 
utiliza diferentes colores para los diferentes elementos del código. Las instrucciones y tipos de datos se muestran 
en azul, los comentarios son mostrados en gris, las variables son escritas en color negro sin resaltar y los nombres 
de las funciones, en sus cabeceras son escritos en negrita, en verde los includes y defines, en celeste las constantes. 
Una vez escrito el código se puede compilar el programa, con esto se genera el archivo .o con el que se graba el 
PIC. Para compilar el programa se puede utilizar el menú Production → Build Main Project o usar la combinación 
Ctrl + F11. El archivo O generado se encuentra en el mismo directorio que el proyecto y lleva el mismo nombre 
que el archivo con el código. Con ello se concluye la creación de un proyecto, la realización de un programa en 
MPLAB X con su correspondiente escritura en código C y la compilación del mismo. 
 
​Configuración del Simulador 
Una manera de saber si el programa que se ha realizado funciona como se desea, es simulando su proceso en la 
computadora. Por esto Microchip facilitó algunos utilitarios como el MPLAB SIM que nos permitirá observar el 
comportamiento del programa. 
Hay que habilitar la opción del simulador seleccionando  dando segundo click en el proyecto y seleccionando 
“propiedades”, allí se abrirá una pantalla como la siguiente. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 35 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
En esta ventana debe seleccionar la herramienta de hardware “Simulator”, luego aplicar el cambio y guardar, 
presionando el boton “OK”. 
Con esta configuración ya se puede empezar a trabajar en el programa que se quiere implementar. La figura 
muestra la zona en donde se deben escribir los comandos del programa. Una vez finalizado, se debe ejecutar el 
programa para verificar que no haya errores, esto se hace teniendo configurado el compilador en “Real ICE” 
presionando el boton de “Play” verde, ubicado en la parte superior central del IDE, dicho botón tiene el siguiente 
aspecto. 
 
Para correrlo en modo debug debe utilizarse la opción “Simulator” en la herramienta hardware usada como se 
mencionó previamente y deberá apretar el botón para correr en modo debug, este es el siguiente. 
 
Luego de correr el programa en el primer modo explicado, aparecerá una lista con los errores y la línea donde se 
produjo cada uno. Si se hace doble click en la línea donde indica el tipo de error, el programa saltará 
automáticamente a la línea que debe ser corregida. Corregir los errores y volver a presionar el botón de play para 
verificar que el código sea correcto. 
Cuando no se generen errores, aparecerá al final de todas las líneas BUILD SUCCESSFUL, esto indica que no se 
encontraron errores de compilación y uno puede empezar a simular. 
 
​Simulación 
En el menú de MPLAB X se encuentra Debug, esta lista de opciones para el simulador permite realizar lo 
siguiente:  
- Continue (F5): Al activarse esta opción el programa se ejecuta a toda velocidad en "modo tiempo real", 
aunque no hay que olvidar que se trata de una simulación por computadora. La ejecución comienza en la 
dirección actual del contador de programa (PC), que se muestra en la barra de estado y en la ventana 
Program Memory. Mientras el programa está en ejecución Step y Run están deshabilitados y se detiene si 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 36 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
se activa Halt o si se encuentra un breakpoint (ver mas adelante).  Si se presiona durante la ejecución del 
programa es un “Halt” (pausa). 
- Step Into (F7): Esta acción ejecuta la instrucción cuya dirección de memoria coincida con el valor al que 
apunta el PC antes de activarla. Si algún registro se modifica se resalta en color rojo. Como puede 
apreciarse cuando se utiliza esta acción, podemos comprobar paso a paso como se ejecuta el programa, y 
de esta forma, ver si hay fallos y ver donde está el error para depurarlo. También es especialmente 
interesante cuando se comienza a estudiar el ensamblador y queremos comprobar el repertorio de 
instrucciones del mismo. En definitiva, ejecuta la instrucción actual y se detiene, actualizándose la 
información. Si se realiza un Step Into sobre una instrucción SLEEP, como en la realidad, el dispositivo 
pasa a modo sleep, siendo necesario despertarlo para continuar, por ejemplo mediante un reset. 
- Step Over (F8): Ejecuta la instrucción actual y se detiene, actualizándose la información. Aparentemente 
funciona como Step Into pero si la instrucción a ejecutar es CALL, ejecuta la subrutina llamada y se 
detiene en la instrucción siguiente a la llamada. Muy útil para ejecutar subrutinas ya comprobadas y 
seguir con la depuración del programa. 
- Step Out(Ctrl+F7): Si la localización actual está dentro de una subrutina, la termina y retorna al programa 
principal. 
- Reset: Esta opción inicializa el sistema. El Contador de Programa (PC), que es la dirección de memoria 
donde se encuentra la primera instrucción que ejecuta el microcontrolador cuando se realiza un reset en el 
sistema, se pone a 0. A esta dirección de memoria se le denomina vector de reset. 
- Breakpoint: Es una marca en un punto del programa de manera que en modo Run, cuando se llegue a ese 
punto el programa se detenga. Muy útil para establecer en que zona o zonas nos interesa ir paso a paso. 
Para trabajar con breakpoints y realizar otras acciones interesantes, como colocar el contador de programa 
en la localización actual (Set PC at Cursor), pulsamos el botón derecho del ratón sobre el programa en 
ensamblador. 
 
Para realizar la simulación podemos colocar las ventanas tal y como aparece en la figura, pulsar sobre  (Step Into) 
y observar como se ejecuta el programa paso a paso y se modifican los registros: 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 37 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
Tal y como están dispuestas las ventanas puede observarse todo lo necesario para la simulación. La flecha verde en 
la ventana donde está el C indica que instrucción es la que se va a ejecutar. 
Con la ventana listing.disasm se pueden observar los cambios en los registros específicos. Con la ventana variables 
se pueden ver las variables empleadas en el código, su valor actual y su posición en memoria. Hay otras ventanas 
también de interés, como Output que nos brinda información sobre la compilación, la ejecución general del 
proyecto y los mensajes obtenidos en la simulación. 
 
​Menú Window 
Uno podrá apreciar mejor el comportamiento del dispositivo con la lista de opciones del menú Window. 
- Project: Esta ventana presenta la lista de archivos que actualmente hay en un proyecto. Si el proyecto se 
ha ensamblado o compilado la ventana de proyecto muestra una lista de todos los archivos incluidos en el 
proyecto. Un doble click en cualquier archivo resaltado en la ventana, abrirá dicho archivo. 
- Output: Muestra la ventana Output, que ofrece información de salida del programa, como por ejemplo 
cuando se compila aquí va apareciendo la información sobre la compilación, indicando si hay errores. 
- Debbuging: Aquí podemos seleccionar mostrar varias ventanas que nos brindan información en el debug. 
  - Output → Dissasembly Listing File: Nos muestra el código realizado pero en Assempler. 
  - Variables: Muestra información de  las variables en el sistema, como por ejemplo el valor actual, 
dirección de memoria, nombre. 
  - Breakpoints: Muestra los breakpoints en el sistema. 
 
​Menú View 
- Toolbars: Permite seleccionar que barras de herramientas aparecerán en MPLAB X. 
 
 
M.Ducid - 2020 
S.Wahler - 2021
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 38 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
​Capítulo 5 
​CONVERSOR ANALÓGICO-DIGITAL (ADC) 
​Introducción 
En este apartado haremos referencias puntuales a la configuración de la aplicación y el lector podrá 
profundizar en otra documentación del fabricante (Conversor AD) para detalles.  
El Microcontrolador dispone de dos ADCs, ADC1 y ADC2 cada uno con su propio conjunto de 
registros de Status y Control. Hasta 32 pins pueden ser conectados a los ADCs (AN0 a AN31) aunque 
sólo 8 de ellos pueden usarse simultáneamente como máximo (cuatro conectados a los 4 canales 
Sample  & Hold del ADC1 y otros cuatro al ADC2). 
Una característica de cada uno de los conversores es que permite el muestreo simultáneo instantáneo 
de sus 4 canales. Los que después admiten en forma secuencial su cuantificación, esta es una 
propiedad muy interesante cuando se quieren lograr precisiones en la comparación de distintas 
muestras de entrada. Un ejemplo: Medición de Potencia trifásica en distintas componentes armónicas.  
El diagrama en bloque de cualquiera de los ADCs se muestra en la figura 5.1.  
El conversor analógico-digital funciona bajo el principo ya descrito oportunamente. Como se ha visto 
el ADC desarrolla dos procesos básicos: 
1.​ Efectúa un muestreo de la señal de entrada, mediante una red de muestro y retención (sample 
and hold), discretizándola en el tiempo. Para ello necesita un breve tiempo que ronda en 0,5 
us. 
2.​ Efectúa la conversión de la amplitud de la señal a un valor digital, discretizándola en amplitud. 
Para ello necesita un tiempo que ronda en 1us. 
Si este conversor estuviera en un proceso automático podría entregar una muestra cada 12us lo que 
permitiría una frecuencia máxima de muestreo fs = 1/12 us = 83,33 KHz. En algunos casos esta 
frecuencia es más elevada. Por ejemplo si se utiliza el conversor A/D de 10 bits que permite configurar 
este microcontrolador. 
En la aplicación ejemplo, en el archivo isr_ADC.C, función: Init_ADC() se efectúa la configuración 
del conversor, que por comodidad ampliamos aquí: 
​
AD1PCFGLbits.PCFG4 = 0; 
​
AD1PCFGLbits.PCFG5 = 0; 
Con esta sentencia configuramos las entradas AN4 y AN5 como analógicas, dejando el resto del 
puerto como digital. Por defecto todas los pines del puerto están como analógicas. 
 El registro AD1CON1 permite fijar varias condiciones de configuración. Inicialmente se le asigna un 
valor 0x00E4 que posee el siguiente significado: 
AD1CON1bits.ADON = 0;​
//Se desactiva el ADC 
AD1CON1bits.FORM = 0;​
//Los valores ADC deben interpretarse como enteros 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 39 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
Figura 5.1: Diagrama en bloques y conexiones del ADC
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 40 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
AD1CON1bits.AD12B = 1;​ //Se activa el conversor en Modo de 12 bits. 
AD1CON1bits.SSRC = 7; 
Este conjunto de tres bits permite indicar al ADC quien define el fin del muestreo e inicio de la 
conversión. Esto se puede hacer por soft cuando lo indique el programador pero en este caso tal 
función comienza automáticamente. 
AD1CON1bits.ASAM = 1;​
//El inicio del muestreo es automático al fin de la conversión. 
El Bit DONE es una bandera que anuncia el fin de la conversión a efectos se pueda disponer la 
muestra. En este caso esa acción la dispara el ADC mediante una interrupción que indica el fin de 
conversión (EOC) a efectos que se pueda tomar la muestra desde el Buffer ADC1BUF0 (ver la rutina 
de servicio de interrupción). 
El Registro AD1CON2 fija otras condiciones, aunque se han dejado por defecto. Ellas son: 
-​
Se deja que las referencias del conversor sean las tensiones de alimentación Vdd y Vss. 
-​
Se indica que solo convierte el Canal 0, de los cuatro canales disponibles para la conversión. 
-​
Se utiliza un solo buffer de salida y se fija que la interrupción del ADC ocurre en cada muestra 
convertida. 
-​
Se utiliza un sólo Mutiplexor MUXA de los dos que se dispone.  
El Registro AD1CON3 fija tiempos para el ADC. Se ha fijado que el reloj principal de tiene una 
FCY=40Mhz o see TCY = (1/40) us es quien hace de clock al conversor. 
Con el valor 0x032F cargado se fija: 
AD1CON3bits.ADCS = 47; //Se fija que TAD = TCY * 48. El tiempo de adquisición será de 1,2 us 
AD1CON3bits.SAMC = 3; //Se fija que Tiempo de muestreo = TAD * 3. O sea será de 3.6 us. 
El registro AD1CON4 fija el largo del buffer, que en este caso se fijo en una unidad y su largo es de 1 
WORD. 
El Registro AD1CHS0 configura el hardware fijando que el pin AN5 de entrada que sea conectado a 
la red de muestreo y retención. En este caso se fija que la tensión negativa de la placa se conecte al 
borne negativo de la señal de entrada y el positivo a AN5. El canal 4 no se usa en esta oportunidad. 
 
Luego se habilitan las interrupciones (AD1IF y AD1IE) y se habilita el ADC  
 
 
R.LÓPEZ  -  15/03/11 
 
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 41 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
​Capítulo 6 
​RECEPTOR TRANSMISOR ASINCRONICO UNIVERSAL (UART) 
​Introducción 
El circuito que estudiaremos es la UART (Universal Asynchronous Receiver Transmitter), que está 
embebido en casi todos los microcontroladores, difiriendo muy ligeramente en su conformación de un 
modelo a otro de cada línea. En tiempos pasados contábamos con el chip discreto 8250 de National, 
fabricado por Intel, aunque el mismo evolucionó luego al 16550 con leves diferencias. Esta última 
UART es más reciente y mucho más potente -aunque solo sea por unos pequeños detalles- y cada vez 
está más extendida, en particular en las actuales placas base. 
Esencialmente en todo chip UART tenemos una línea física de transmisión UTx y otra física de 
recepción URx. Como está pensado para una comunicación punto a punto entre dos hosts, la línea de 
transmisión del Host 1 se conecta a la de recepción del Host 2 y viceversa. La línea que transmite los 
datos en serie está inicialmente en estado alto (1 lógico). La transmisión serie está orientada a 
caracteres y dado que estos normalmente están codificados mediante un byte, aquella es un modo de 
comunicación que se orienta a la transmisión de bytes. A efectos de sincronismo se llama la atención 
del receptor mediante un bit de inicio, denominado Start Bit que se antepone a la emisión serie de un 
byte. Del mismo modo al terminar la emisión de un byte, se concluye la misma mediante la emisión de 
un bit de parada denominado Stop Bit. O sea que la transmisión de un byte se encuentra 
“empaquetada” entre dos bits: de start y de stop.   
En la figura 6.1, vemos un diagrama de tiempos. La gráfica perteneciente a Rx input, nos otorga como 
es el formato de la emisión de un byte, en este caso el valor 0x5A.  
Al comenzar la transferencia, se envía la línea a 0 ó bit de inicio. Tras él irán los 8 bits de datos a 
transmitir (en ocasiones estos pueden ser menos de un byte: 7, 6 ó 5). Estos bits están espaciados con 
un intervalo temporal fijo y preciso, ligado a la velocidad de transmisión que se esté empleando. 
Tras ellos podría venir o no un bit de paridad generado automáticamente por la UART. Al final, 
aparecerá un bit (a veces un bit y medio ó dos bits) que son los bits de parada o bits de stop que pone 
nuevamente la línea a 1, dejándola en reposo o, como se indica en la figura, recomenzar con un nuevo 
start para la transmisión de un nuevo byte. 
​Transmisión  y Recepción de datos 
En comunicaciones se utiliza el término baudio para hacer referencia a las velocidades. Un baudio 
equivale a un bit/s. Cada bit esta determinado por el estado de la línea (en alto o en bajo) y ese estado 
tiene una duración (para permitir el muestro por parte del receptor). La duración de ese estado 
justamente es la inversa de la velocidad. Por ejemplo a la velocidad comercial de 9600 baudios o bits 
por segundo (bps) corresponde un tiempo de bit de 1/9600 s = 0,104 ms. 
Esta velocidad - que debe ser la misma para el transmisor y el receptor -, es definida por el bit Clock, 
existente tanto en la unidad transmisora como en la receptora. Esta línea interna en la UART está 
derivada del cristal principal del procesador mediante la aplicación de un divisor de frecuencia que 
tiene un registro que contiene el número del divisor el cual es programable por software a efectos de 
lograr diferentes velocidades. Las velocidades comerciales son: 50, 100, 200, 600, 1200, 2400, 4800, 
9600, 19200, 28800, 38400, 57600 y 115200 bps. Aunque estos valores pueden tener cambios acorde a 
los fabricantes. 
La presencia de bits de inicio y parada permite sincronizar la estación emisora con la receptora, 
haciendo que a partir de la recepción del start, el receptor efectúe el muestreo de cada bit más o menos 
en el centro de su intervalo. Obsérvese en la figura que el instante del flanco ascendente del Bit Clock 
coincide con el centro del intervalo conferido a cada bit.  
Existe flexibilidad en los tiempos que median entre la finalización de la transmisión de un byte y el 
comienzo del que sigue. De ahí que este tipo de comunicaciones se consideren asíncronas. La 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 42 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
transmisión de los 8 bits de datos de un byte realmente es síncrona entre los caracteres de inicio y de 
stop, pero no lo es en el tiempo restante, por ello, este tipo de comunicaciones en serie son 
consideradas asíncronas. 
En la figura 6.1, se destaca que: 
1.​ Los bits se reciben empezando por el menos significativo y se muestrean en cada flanco 
ascendente del clock (bit clock). 
2.​ En el momento que un bit de datos se muestrea, el mismo es copiado en el RxShift Register, 
introduciéndolo en su posición correspondiente. 
 
Figura 6.1: Diagrama de tiempos para la recepción de datos 
3.​ Cuando se ha detectado el último bit de datos, el shift register contiene el resultado. 
4.​ Puede existir o no un bit de paridad. 
5.​ En el instante que se detecta el bit de stop se disparan varios eventos a saber: 
a.​ Se traslada el contenido del Rx Shift Register al Rx Buffer Register y queda a disposición 
de ser leído por el procesador. 
b.​ La bandera que indica que el registro de recepción está lleno (Rx Register full) denominada 
URXDA y esto se manifiesta poniéndola en 1, en el registro de Status de la UART. 
c.​ Se pueden detectar los errores de Parity, Overrun y Framing. Cada una tiene un flag 
dedicado en el registro de Status de la UART 
d.​ Se produce requerimiento de interrupción si la misma está habilitada. Independientemente 
de ello se pone en uno el flag U1RXIF (uart 1, en este ejemplo, Interrupt Flag de 
recepción). 
En la figura 6.2, se observa similar gráfico pero para la transmisión. Se destaca que: 
1.​ Se traslada el contenido del Tx Buffer Register al Tx Shift Register y comienza la emisión del 
Start, poniendo la línea de salida Tx Output en bajo. Cada cambio de estado de los bits a 
transmitir está determinado por el flanco ascendente del Bit Clock. 
2.​ Los bits se emiten empezando por el menos significativo. En el momento que un bit de datos se 
emite, el mismo es extraído del TxShift Register, desplazando a derecha el valor inicial a 
transmitir (0x5A). 
3.​ Cuando se ha emitido el último bit de datos, el shift register queda en cero. 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 43 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
 
 
Figura 6.2: Diagrama de tiempos para la transmisión de datos 
4.​ Puede emitirse o no un bit de paridad. 
5.​ En el instante que se emite el bit de stop se disparan varios eventos a saber: 
a.​ La bandera que indica que el registro de transmisión está vació (Tx Register empty) 
denominada TRMT se pone en 1, en el registro de Status de la UART. 
b.​ Se produce requerimiento de interrupción si la misma está habilitada. Independientemente 
de ello se pone en uno el flag U1TXIF (uart 1, en este ejemplo, Interrupt Flag de 
transmisión). 
Con este esquema se puede realizar un software que tiene las siguientes características: 
Desde el punto de vista del emisor, se escribirá un dato (un byte) en el registro interfase del 
programador para la UART1. Este registro es el buffer de transmisión y se lo denomina U1TXREG. A 
partir de esa escritura el programa puede efectuar un pooling de la bandera U1TXIF a efectos de 
determinar si el registro U1TXREG a quedado vacío para que se pueda escribir otro dato. En otro caso 
se puede habilitar la interrupción por transmisión mediante la bandera U1TXIE y de esta manera 
escribir el byte de datos dentro del cuerpo de la rutina de servicio de dicha interrupción. El suministro 
de bytes a ser trasmitidos normalmente proviene de un buffer de transmisión que contiene datos ya 
preparados. 
Desde el punto de vista del receptor, el mismo estará leyendo por pooling la bandera U1RXIF, para 
determinar si existe dato nuevo en el registro buffer de recepción U1RXREG. En otro caso se puede 
habilitar la interrupción por recepción mediante la bandera U1RXIE y de esta manera leer el byte de 
datos entrante dentro del cuerpo de la rutina de servicio de dicha interrupción. Los datos recibidos se 
pueden ir depositando en un buffer de recepción. 
Este criterio básico es el que puede seguirse para la elaboración de un software que efectúe la 
transmisión/recepción de datos en un Host permitiendo una comunicación punto a punto, igual a igual, 
de datos por la existencia de la habilidad tanto de emitir como de recibir datos. 
​Norma EIA 232 / RS-232 
La norma comúnmente denominada RS-232 describe muchos aspectos para la comunicación entre dos 
host. Su tratamiento completo excede el alcance de este tratado y por ello sólo nos limitaremos a lo 
que atañe a las líneas de transmisión y recepción de un Host. Como se ha descrito anteriormente la 
línea de transmisión se pone en alto (a uno) o bajo (a cero) en relación directa con los bits del byte a 
transmitir. También se pone en bajo en el caso de un start y se vuelve a poner en alto en el caso de un 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 44 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
bit de stop quedando en esa condición de reposo hasta la emisión de un nuevo start cuando otro byte se 
comienza a transmitir. 
Debido al hecho que una UART posee una electrónica de baja potencia en la línea del emisor y un bajo 
rechazo a ruido en la línea del receptor, se han desarrollado circuitos electrónicos que cambian esa 
situación del modo siguiente: 
1.​ El uno lógico se lo condice con un valor aproximado de -12 volts, respecto a una línea de 
referencia. 
2.​ El cero lógico se lo condice con un valor aproximado de +12 volts, respecto a la línea de 
referencia. 
3.​ Una ausencia de estos valores (0 o 1) respecto a la referencia, implica una avería en el circuito que 
puede ser detectada. Este umbral se lo sitúa comúnmente en +/- 3 volts. 
Este simple cambio de niveles de tensión y de impedancia en los circuitos emisor y receptor (respecto 
a los niveles normales de tensión entre 3,3 y 5 volts que mantienen los circuitos integrados de un 
procesador, respecto a su línea de referencia de 0 (cero) volts), los hace factibles para la emisión a una 
considerable distancia (10 metros por norma pero a veces hasta 100 metros) y altamente inmunes al 
ruido. 
No obstante con este cambio de niveles de tensión, potencia de salida del emisor e inmunidad al ruido 
del receptor la comunicación es punto a punto entre un par de Hosts    
​Aplicación de referencia 
La aplicación dsCom33x es la aplicación de referencia que se utilizará para las comunicaciones. En 
esta aplicación se definió una rutina isr_UART2.c que contiene la inicialización de la UART y la 
adquisición de caracteres por interrupción. La emisión es a demanda. 
En lo que sigue se transcribe el código de inicialización de la UART. A su vez en main() nos 
encontramos una rutina que emite por el puerto serie los valores de tensión adquiridos por el ADC. 
​inicialización 
Se transcriben las líneas que tienen que ver con la Inicialización de la UART.​
 
U2MODEbits.UARTEN = 0;// Bit15 TX, RX DISABLED 
​
U2MODEbits.RTSMD = 1;​
// Bit11 Simplex Mode 
Se deshabilita la UART y se configura en modo Simplex. 
​
U2BRG = BRGVAL;​ // 40Mhz osc, 9600 Baud 
Con esta línea se le otorga al divisor un valor que es función de la frecuencia de trabajo del procesador 
y de la velocidad en baudios deseada. Respondiendo a la formula: 
#define FCY 40000000 
#define BAUDRATE 9600 
#define BRGVAL ((FCY / BAUDRATE) / 16) -1 
Estas 3 líneas de código se colocan a la cabecera del archivo 
 
​
IPC7 = 0x4400;​
// Mid Range Interrupt Priority level, no urgent reason 
​
IFS1bits.U2TXIF = 0;​ // Clear the Transmit Interrupt Flag 
​
IEC1bits.U2TXIE = 0;​// Disable Transmit Interrupts 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 45 de 46 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
​
IFS1bits.U2RXIF = 0;​// Clear the Recieve Interrupt Flag 
​
IEC1bits.U2RXIE = 1;​// Enable Recieve Interrupts 
Se fija la prioridad de la UART tanto en transmisión como en recepción, Se limpian las banderas de 
interrupción y se habilita la interrupción por recepción. 
​
U2MODEbits.UARTEN = 1;​ // And turn the peripheral on 
​
U2STAbits.UTXEN = 1;​
// Habilito Tx.. 
Una vez configurada la UART se habilita la misma y la transmisión. 
 
 
R.LÓPEZ  -  15/03/11 
 
 
 
Año 2026 
AC- Anexo1 - UNPSJB – Facultad de Ingeniería 
Página 46 de 46
