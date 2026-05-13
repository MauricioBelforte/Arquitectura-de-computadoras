# EDI-Anexo-1

ANEXO 1
ELEMENTOS
DE  
INFORMÁTICA
APUNTES DE CÁTEDRA
Docentes: 
​
Profesor:​
 ​ Mg. Sebastián Wahler 
​
Jefe de Trabajos Prácticos: ​
Lic. Gustavo Fantín 
​
Ayudante de Primera:​
 ​ Dr. Iván Gareis 
​
Ayudante de Segunda:​
 ​ APU. Kiara Kruse​
​

ELEMENTOS DE INFORMÁTICA
ÍNDICE 
Capítulo 1​
7 
SISTEMAS DE INFORMACIÓN​
8 
Introducción​
8 
Computadora​
8 
Hardware y Software​
8 
RESUMEN HISTÓRICO DE LA COMPUTACIÓN​
9 
Computadoras mecánicas (1642-1945)​
9 
La primera generación (1945-1955)​
9 
La segunda generación (1955-1965)​
10 
La tercera generación (1965-1980)​
10 
La cuarta generación (1980- ...)​
10 
CORRIENTE ELÉCTRICA Y DIFERENCIA DE POTENCIAL​
11 
Utilidad del Potencial Eléctrico​
12 
FENÓMENOS ANALÓGICOS Y DIGITALES​
13 
ELABORACIÓN DE SISTEMAS​
14 
Etapas en el Desarrollo de un Sistema  (DDDT)​
14 
Relevamiento​
14 
Análisis​
14 
Diseño​
15 
Desarrollo​
15 
Implementación​
15 
Capítulo 2​
15 
SISTEMAS DE NUMERACIÓN​
16 
Representación polinómica o canónica de un número entero​
17 
Conversión por divisiones sucesivas​
18 
Representación polinómica o canónica de un número fraccionario​
19 
Conversión por multiplicaciones sucesivas​
20 
Conversión directa entre bases​
21 
Operaciones aritméticas en base 2​
21 
Suma​
22 
Resta​
22 
Multiplicación​
22 
División​
23 
Operaciones lógicas base 2​
23 
Multiplicación lógica (and)​
23 
Suma lógica (or)​
24 
Inversión o complementación (not)​
24 
Exclusión lógica (Xor)​
25 
Capítulo 3​
25
__________________________________________   2   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
LOS NÚMEROS BINARIOS EN LAS COMPUTADORAS​
26 
Sin signo​
26 
Signo y módulo​
26 
Complemento a uno​
27 
Complemento a dos​
28 
Cambio de formato​
30 
Conclusiones​
31 
Banderas de estado​
32 
Bandera N​
32 
Bandera Z​
32 
Bandera P​
32 
Bandera C​
32 
Bandera DC​
32 
Bandera OV​
33 
Comparación​
34 
Conclusiones acerca de la utilidad de las banderas C, OV, N y Z.​
35 
Capítulo 4​
35 
SISTEMAS DE CODIFICACIÓN​
36 
Notación Exponencial​
36 
Estándar IEEE de punto flotante​
36 
Signo S​
37 
Exponente E​
37 
Mantisa M​
37 
Formatos No normalizados​
38 
Infinito​
38 
Exponente en cero​
38 
Rango representable​
38 
Unidades de medida​
39 
Codificación​
39 
Código ASCII​
39 
Tipos de datos​
41 
BCD​
41 
Bandera Digit Carry​
42 
Códigos auto-complementarios​
43 
Capítulo 5​
43 
COMPUTADORA ELECTRÓNICA DIGITAL​
44 
Microprocesadores​
44 
Buses​
44 
Memoria Principal​
44 
Mapa de Entrada y Salida​
44 
__________________________________________   3   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
CPU​
46 
Ciclos​
47 
Clock Cycle (Ciclo de reloj)​
47 
MPU Cycle o Memory Cycle​
47 
Instruction Cycle​
47 
Registros del microprocesador​
48 
Funcionamiento paso a paso de la CPU (microinstrucciones)​
48 
Capítulo 6​
50 
ORGANIZACIÓN DE LA COMPUTADORA​
51 
Formatos de Instrucciones​
51 
Modos de Direccionamiento​
51 
Seudo-Operandos​
52 
Utilización de las etiquetas​
52 
Seudo-Operando .EQU​
52 
Seudo-Operandos .word, .byte y .Space​
53 
Conclusiones​
53 
Capítulo 7​
54 
FUNCIONALIDAD DE MICROPROCESADORES​
55 
Microcontroladores PIC24 y dsPIC33​
55 
Características​
55 
Arquitectura von Neumann​
55 
Arquitectura Harvard​
56 
Procesador tipo RISC y Segmentado​
56 
Puertos​
56 
Otros pines​
56 
Organización de la memoria​
57 
Memoria de Programa​
58 
SP (Stack Pointer)​
59 
Memoria de Datos​
60 
Registro STATUS​
60 
Manejo de Puertos​
61 
Interrupciones​
61 
Fuentes de Interrupción​
62 
Fases de una interrupción​
63 
Capítulo 8​
63 
SET DE INSTRUCCIONES REDUCIDO​
64 
Análisis detallado de las Instrucciones más relevantes​
65 
INSTRUCCIONES DE TRANSFERENCIA​
66 
Instrucción MOV​
66 
Capítulo 9​
67 
__________________________________________   4   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
INSTRUCCIONES ARITMÉTICO LÓGICAS​
67 
Instrucción ADD​
67 
Instrucción SUB​
67 
Instrucción INC y DEC​
68 
Instrucción INC2 y DEC2​
68 
Instrucción COM,  NEG y CLR​
68 
Instrucciones RLC,  RRC, RLNC y RRNC​
69 
Instrucciones lógicas de dos operandos​
70 
Capítulo 10​
70 
INSTRUCCIONES DE CONTROL​
71 
Instrucciones de Control del programa​
71 
Instrucciones de Salto Incondicional​
71 
Instrucciones BRA y GOTO​
71 
Microprograma de una instrucción de salto​
72 
Instrucciones de Salto Condicional​
72 
Instrucciones de Testeo de bits​
73 
Instrucciones para manejo de Subrutinas​
73 
Pila (Stack Pointer)​
74 
Instrucciones​
75 
Instrucciones especiales​
75 
Comparativa de Tipos de instrucciones de Control de Programa y Sistema​
76 
Capítulo 11​
76 
LENGUAJE ENSAMBLADOR​
77 
Introducción​
77 
Etiquetas​
77 
Instrucciones o directivas​
77 
Datos u operandos​
77 
Comentarios​
78 
El primer programa: EJEMPLO1.S​
78 
Secuencia a seguir para el grabado del microcontrolador​
79 
Capítulo 12​
79 
ENTORNO DE DESARROLLO MPLAB X​
80 
Introducción​
80 
Descarga​
80 
Instalación y Uso dentro del marco de la Asignatura​
80 
Instalación del compilador​
85 
Inicio de un Proyecto​
91 
Configuración del Simulador​
96 
Simulación​
98 
Menú Window​
99 
__________________________________________   5   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Menú View​
99 
Capítulo 13​
100 
LENGUAJE C  ELEMENTAL​
100 
Programa ejemplo​
100 
Capítulo 14​
101 
LENGUAJE C​
102 
Introducción​
102 
Programa​
102 
Función​
102 
La función main( )​
103 
Tokens​
103 
Identificadores​
103 
Palabras clave​
104 
Constantes​
104 
Operadores​
105 
Separadores​
105 
Comentarios​
105 
Lenguaje C​
106 
Preprocesador​
106 
Comando #include​
106 
Comando #define​
106 
Librería estándar​
108 
Tipos de datos fundamentales. Variables​
108 
Caracteres (tipo char)​
108 
Números enteros (tipo int)​
109 
Números enteros (tipo long)​
109 
Números reales (tipo float)​
110 
Números reales (tipo double)​
110 
Operadores, expresiones y sentencias​
110 
Operadores​
110 
Operadores aritméticos​
111 
Operadores de asignación​
111 
Operadores relacionales​
111 
Operadores lógicos​
112 
Reglas de precedencia y asociatividad​
113 
Sentencias​
113 
Sentencias simples​
114 
Sentencia vacía ó nula​
114 
Sentencias compuestas o bloques​
114 
Control del flujo de ejecución​
114 
__________________________________________   6   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Bifurcaciones​
114 
Sentencia if​
114 
Sentencia if …. else​
114 
Bucles​
115 
Sentencia while​
115 
Tipos de datos derivados​
115 
Vectores, matrices y cadenas de caracteres​
115 
Inicialización de vectores y matrices​
116 
Funciones de entrada/salida​
117 
Función printf()​
117 
Capítulo 15​
118 
SISTEMAS OPERATIVOS​
119 
LINUX​
119 
Características principales de Linux​
119 
Jerarquía de directorios en Linux​
120 
Descripción de Comandos Básicos de Linux​
120 
La consola o intérprete de comandos.​
120 
Prompt​
120 
Comandos Linux de manipulación de archivos y directorios​
120 
Nombres de archivos en Linux​
121 
Directorios o Carpetas​
121 
Comandos sobre Directorios​
122 
Comando sobre Disco​
122 
Comandos para Archivos​
123 
WINDOWS​
124 
Manejo de la Consola del Sistema​
124 
Descripción de Comandos Básicos​
124 
Archivos​
125 
Format​
125 
Renombre de archivos​
128 
Eliminación de archivos​
129 
Comodines (WildCards)​
129 
Editor de texto​
129 
Ayuda​
130
__________________________________________   7   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Capítulo 1
SISTEMAS DE INFORMACIÓN
​
 
​Introducción
Las cada vez más crecientes necesidades de las organizaciones, ya sean comercios, empresas o industrias, públicas 
o privadas, de contar con información fidedigna en el momento adecuado, es decir cuando deben tomarse 
decisiones gerenciales, han hecho que los SISTEMAS DE INFORMACIÓN, sean estudiados y mejorados 
permanentemente.
Típicamente se define como sistema a todo conjunto de partes, cada una con un fin determinado, que interactúan 
para conseguir un objetivo en común; en el caso de los sistemas de información, interactúan personas, 
procedimientos, programas y computadoras, con el fin de brindar información confiable a quien o quienes deban 
tomar decisiones. La computadora entonces, es parte del sistema. 
Lo que almacenan las computadoras son DATOS, no información, ésta última está constituida por los datos 
procesados y elaborados de forma conveniente, a fin de que tengan algún significado.
Por ejemplo, en un sistema de control de gestión comercial, las cantidades vendidas en cada facturación y la fecha 
de la misma, son datos que hasta que no sean asociados de forma tal que se muestren en forma de gráfico 
estadístico las ventas realizadas en los meses de un determinado período, carecen de significación para quien tiene 
que decidir políticas de publicidad.
​Computadora
Una computadora digital es una máquina que puede resolver problemas ejecutando unas instrucciones dadas. Se 
llama programa a una secuencia de instrucciones que describe cómo ejecutar cierta tarea. Los circuitos 
electrónicos de cada computadora pueden reconocer y ejecutar directamente un conjunto limitado de instrucciones 
simples. Todos los programas que se deseen ejecutar en una computadora deben convertirse previamente en una 
secuencia de estas instrucciones simples. Estas instrucciones básicas pocas veces rebasan la complejidad de:
- Sumar dos números. 
- Comprobar si un número es cero. 
- Mover datos de una parte de la memoria a otra. 
  
El conjunto de las instrucciones primitivas de una computadora forma el lenguaje con el cual podemos 
comunicarnos con ella. Dicho lenguaje se llama lenguaje máquina.
​Hardware y Software
Los programas escritos en lenguaje de máquina (nivel 1), pueden ejecutarlos directamente los circuitos 
electrónicos de la computadora (nivel 0). Estos circuitos electrónicos, junto con la memoria y los dispositivos de 
entrada y salida, forman el hardware de la computadora (parte física, parte dura, inmodificable). El hardware 
consta de objetos tangibles, como circuitos integrados, placas de circuito impreso, cables, fuentes de alimentación, 
memorias, impresoras, etc.
El Software por el contrario, consta de algoritmos (parte blanda, modificable. Instrucciones detalladas que dicen 
como hacer algo) y sus representaciones en la computadora, es decir, los programas. Los programas pueden 
representarse en cintas magnéticas, discos para lectura por láser u otros medios, pero la esencia del software es el 
conjunto de instrucciones que forman los programas, no los medios físicos en los que se registran (hardware).
__________________________________________   8   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
RESUMEN HISTÓRICO DE LA COMPUTACIÓN
​
 
​Computadoras mecánicas (1642-1945)
En 1642 un científico francés de 19 años, Blaise Pascal inventó, para ayuda de su padre, un cobrador de impuestos, 
una máquina de calcular mecánica. La misma consistía de engranajes que, accionados por una manivela permitían 
hacer sumas y restas y mostraba el resultado en una ventanilla. Unos años más tarde el Barón von Leibniz, 
construyó una máquina mecánica capaz de multiplicar y dividir además de sumar y restar.
Alrededor de 1830, 150 años después de la máquina de Leibniz, Charles Babbage inventó su "máquina analítica", 
destinada a ser utilizada en navegación naval, realizando cálculos sobre tablas de funciones como logaritmos, 
trigonometría, etc. El gran avance que presentaba esta máquina, era que estaba dividida en dos grandes partes, una 
que ordenaba y otra que ejecutaba las operaciones necesarias para cumplir con esas órdenes. Por la forma que se 
administraba el trabajo, una sección de entrada, un área de almacenamiento, una unidad de cómputo y una sección 
de salida, se considera esta máquina como la antecesora de las computadoras contemporáneas, a pesar de que aún 
funcionaba con ruedas y engranajes.
​La primera generación (1945-1955)
Debido a que el gobierno inglés necesitaba durante la segunda guerra mundial, descifrar mensajes codificados por 
los alemanes, se desarrolla la primera computadora electrónica, llamada COLOSSUS, la cual estuvo lista para 
operar en 1943.
En Estados Unidos, a causa también de la guerra, se hacían necesarios cálculos de tablas numéricas para la 
artillería, con bajo nivel de error. Esto impulsó al Departamento de Defensa a propiciar el desarrollo por parte de 
John Mauchley y Presper Eckert, de una computadora electrónica digital llamada ENIAC. La misma una vez 
terminada en 1946, a la vez de ya no servir para lo que fue construida, dado que la guerra había terminado, 
consistía de 18.000 tubos de vacío, 1.500 relays y consumía 140 Kw de energía eléctrica, necesitando por el calor 
producido un sistema de refrigeración industrial. Para su programación se debían accionar 6.000 switch’s y 
conectar gran cantidad de cables puentes.
A partir de este primer intento en la generación de computadoras digitales, aparecen en el mundo otras tales como 
la EDSAC (Universidad de Cambridge), la JOHNIAC (Corporación Rand), la ILLIAC (Universidad de Illinois), la 
MANIAC (Laboratorio Los Alamos) y la WEIZAC (Instituto Weizmann en Israel).
Los mismos Eckert y Mauchley comenzaron a trabajar en un sucesor de la ENIAC, la EDVAC (Electronic Discrete 
Variable Automatic Computer), en cuyo proyecto participó John von Neumann.
Este último desarrolló una idea que ha hecho que se lo considere el padre de las computadoras modernas. Dicha 
idea consistía en que en la memoria coexistan los programas con los datos. Se toma real conciencia de la 
importancia de este principio cuando se piensa en que hasta ese momento los programas estaban "alambrados", es 
decir se programaba la computadora moviendo switch’s y cambiando cables de conexión. El hecho de tener los 
programas en la memoria de la máquina, permite entonces hacer una programación SOFT. Esta idea ha sido 
llamada el MODELO DE VON NEUMANN, cuyo principio está graficado en la Figura 1.
​MÁQUINA DE VON NEUMANN
Figura 1: Estructura de la máquina concebida por Von Neumann
__________________________________________   9   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
En este comienzo de la computación aún se desconocían en gran parte los alcances de la misma, dado en buena 
medida a que su programación en lenguaje de máquina era lenta y costosa, así también como eran muy costosas 
las mismas computadoras.
La primera computadora comercial fue la UNIVAC, la cual podía leer cintas magnéticas y fue usada para el censo 
de los Estados Unidos en 1950.
Una pequeña compañía llamada IBM incursionó al mercado con un modelo llamado el 701, en el año 1953, siendo 
la primera de una serie (702, 704 y 709) que dominaron una década el mercado de las computadoras. 
​La segunda generación (1955-1965)
Los transistores fueron inventados en 1948, en el Laboratorio Bell, con la aplicación de los mismos a las 
computadoras, las que estaban construidas con tubos de vacío se convirtieron rápidamente en obsoletas.
Estas nuevas computadoras se caracterizaban por ser de un tamaño y costo mucho menor a las anteriores y por 
comenzar a darle importancia a que pudieran ser programadas en lenguajes de alto nivel.
La primera computadora comercializable fue construida por DEC y llamada PDP-1; aparecida en 1961 tenía la 
mitad de la performance de la 7090 de IBM, pero costaba $ 120.000 contra millones que costaba esta última. Una 
de las innovaciones de la PDP-1 fue un display de vídeo de 512 x 512 puntos en pantalla.
Unos años después DEC lanzó al mercado la PDP-8 cuyo costo descendió a $ 16.000, convirtiéndose en el líder 
del mercado de las computadoras de negocios, vendiendo 50.000 unidades.
En el año 1964 la compañía CDC lanzó la 6600, una máquina que superaba ampliamente a sus competidoras en 
velocidad de procesamiento. Esto lo lograba teniendo computadoras dedicadas para sumas, multiplicaciones y 
divisiones con la posibilidad de trabajar en paralelo.  
​La tercera generación (1965-1980)
El advenimiento de los circuitos integrados, posibilita colocar docenas de transistores en un solo chip. Este 
agrupamiento permitió crear computadoras más pequeñas, más rápidas y más baratas que sus antecesoras. Durante 
ésta generación vale la pena destacar la serie 360 de IBM; la misma dio fama a ésta compañía debido a que 
capturó el mercado a través de varios puntos:
- Uso simple de cintas magnéticas y paquetes de discos magnéticos. 
- Compatibilidad entre máquinas de la serie 360, pero con distintas capacidades de prestaciones y costo. 
- MULTIPROGRAMACIÓN, (será vista más en detalle) - Emulación de modelos anteriores a fin de no 
perder a clientes de la compañía.
Otra computadora que fue altamente difundida fue la PDP-11, la cual entra entre las llamadas minicomputadoras, a 
fin de diferenciarlas de los Main-frames (gran sistema). 
​La cuarta generación (1980- ...)
Durante la década de los ochenta, el avance tecnológico permitió la integración de circuitos a gran escala (VLSI en 
inglés). La misma posibilitó colocar en un solo chip, desde decenas de miles a millones de transistores, con la 
consiguiente disminución en el tamaño y costo de las computadoras, a la vez que se incrementaba ampliamente su 
velocidad.
Ya no solo se había dejado atrás la época en que debía presupuestarse la adquisición de una computadora para toda 
la empresa, sino que ya se podía pensar en tener una computadora para cada persona, es decir, computadoras 
personales (PC).
En éste punto ya no es posible definir claramente un límite entre "historia" y presente, por ejemplo, al momento de 
escribir estas líneas se cuenta con un microprocesador de Intel llamado PENTIUM III (y otros de otros 
constructores con similares prestaciones), con altas prestaciones de velocidad de procesamiento gracias a las 
innovaciones en su arquitectura, diluyendo la frontera que separaba las computadoras personales con 
minicomputadoras y súper- minicomputadoras.
__________________________________________   10   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
CORRIENTE ELÉCTRICA Y DIFERENCIA DE
POTENCIAL
​
 
En Informática se utiliza un soporte (Hardware) que funciona con circuitos electrónicos, donde los transistores y 
las resistencias son los componentes más habituales. Estos últimos dispositivos están diseñados para que circule 
una corriente eléctrica (I) por ellos, provocando un potencial eléctrico (V) en puntos que son de interés.
En la Figura 3, vemos a la izquierda un circuito eléctrico que contiene una fuente que eleva el potencial (medido 
en volts) y puede proveer una corriente convencional de cargas positivas.
Figura 3: Circuito eléctrico y su analogía física con una instalación de agua.
Para que pueda circular corriente eléctrica debe haber un circuito cerrado, realizado con materiales conductores. 
La corriente que sale del terminal positivo de la fuente, vuelve a ingresar a ella por el terminal negativo.
La cantidad de corriente eléctrica (medida en Ampere o un submúltiplo: MiliAmpere) que circula por el circuito, 
está determinada por la resistencia eléctrica (R) que posee este. La resistencia eléctrica se mide en Ohm o un 
múltiplo: KiloOhm.
El potencial eléctrico es una medida de la capacidad de la fuente de producir trabajo. Esta cantidad se mide en 
Volt.
El potencial eléctrico, la corriente eléctrica y la resistencia eléctrica en un circuito están relacionados entre si por la 
Ley de Ohm, donde:
I = V / R
Observamos que la corriente eléctrica que circula en un circuito depende directamente del potencial que posee la 
fuente. Asimismo, observamos que si el circuito posee alta resistencia eléctrica, la corriente es menor.
Como ejercicio de cálculo se debe tener en cuenta que en el circuito simple de la figura, las resistencias parciales 
se suman para dar la resistencia total, estos es:
R total = R1 + R2 = 2 KOhm + 3 KOhm = 5 Kohm
Luego para determinar la corriente circulante se aplica la ley de Ohm:
I = 5 Volt  / 5 KOhm = 0,001 Ampere = 1 MiliAmpere
__________________________________________   11   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
A efectos de su mayor comprensión, en la figura 3 a la derecha se efectúa una analogía con la presión de agua 
existente en una cañería y el agua circulante.
La presión mecánica que posee el tanque, que es la fuente del sistema debido a su altura, es equivalente al 
potencial eléctrico que posee la fuente eléctrica.
La resistencia que ofrece la cañería al flujo de agua, es equivalente a la resistencia eléctrica del circuito. Las 
estrangulaciones de la cañería que se observan en la figura, provocan pérdida de presión al circular el agua.
Por último, el flujo de agua que se mide en litros sobre segundo (Lt/seg), está determinado por la presión y la 
resistencia de la cañería en una forma equivalente a la Ley de Ohm.
​Utilidad del Potencial Eléctrico
Si observamos con más detenimiento la figura de la izquierda, veremos que el interruptor (L) situado en la 
posición superior del circuito, está en una posición tal (1) que el circuito eléctrico está cerrado, permitiendo la 
circulación de la corriente eléctrica. Si se lleva al interruptor a la posición 2 (en gris), el circuito está abierto y no 
circula corriente eléctrica por él.
Si analizamos el circuito cuando el interruptor está en 1, observamos que el potencial eléctrico del punto P es de 3 
volts (deducible por aplicación de la ley de Ohm). En cambio, si se lleva el interruptor a la posición 2, al no 
circular corriente el potencial del punto P se va a 0 volts.
Para esta deducción debe tenerse en cuenta una ley (de Kirchhoff) que determina que la suma de los potenciales en 
un circuito cerrado es igual a cero. O sea, que el potencial de 5 volts que eleva la fuente, va cayendo al pasar la 
corriente por las resistencias. En este caso, hay dos caídas de potencial en las dos resistencias: de 2 volts y 3 volts 
respectivamente, llegando a potencial cero en la parte inferior del circuito. Esto equivale a decir que: Partiendo del 
polo negativo de la fuente (que se lo supone a potencial 0), la fuente eleva el potencial en 5 volts. Luego, la 
primera resistencia lo hace caer a 3 volts y la segunda resistencia lo hace caer a 0 volts. Como vemos, el potencial 
total resulta cero cuando hemos recorrido todo el circuito.
Por otro lado, vemos que podemos hacer que el potencial de un punto cambie por apertura y cierre de un 
interruptor. El Punto P cambia de 0 volts (con el interruptor abierto) a 3 volts (con el interruptor cerrado). En 
Electrónica, los interruptores se pueden conformar con transistores, que tiene la posibilidad de cambiar de abierto 
a cerrado y viceversa varios millones, de millones, de veces por segundo.
Si a su vez se asocia la existencia de un valor cualquiera de potencial, en el caso de la figura de 3 volts con el 
número binario 1 y la ausencia de potencial ( 0 volts), con el número binario 0, tenemos capacidad de representar 
número binarios con un circuito eléctrico, construyendo un circuito por cada bit a representar y esa es la esencia 
básica de la Computadora Electrónica Digital.
Como veremos oportunamente, el secuenciador de una Unidad Central de Proceso (CPU), es quien abre y cierra 
los interruptores hechos a base de transistores, para efectuar la representación y operaciones con números binarios 
a una gran velocidad. Para ello se debe tener en cuenta la ventaja que tienen la lógica binaria que es representable 
con bits de dos estados posibles ( 1 y 0). Estos bits pueden ser representados mediante la utilización de circuitos 
eléctricos en condición abierto o cerrado.
Por otro lado, debe tenerse presente que la propagación de una señal eléctrica dentro de un circuito, se hace a una 
velocidad cercana a la de la luz (300.000 Km. / seg). Ello permite que puedan efectuarse operaciones en un tiempo 
por debajo del nanosegundo (10 -9 seg).
__________________________________________   12   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
FENÓMENOS ANALÓGICOS Y DIGITALES
En la naturaleza las variaciones, sean cuales fueren, se producen en forma continua, es decir no presentan grandes 
diferencias sin haber pasado por valores intermedios muy próximos. Es suficiente tomar como ejemplos la 
temperatura, la velocidad del viento, etc. Estos tipos de fenómenos que presentan puntos intermedios próximos 
entre los valores máximos y mínimos que pueden alcanzar, son llamados ANALÓGICOS.
En contraposición a los fenómenos analógicos, el ser humano ha creado fenómenos DIGITALES, éstos últimos 
tienen la característica de tomar sus valores extremos, sin necesidad de pasar por los puntos intermedios.
Las computadoras trabajan en forma digital, utilizando para sus señales internas la ausencia o presencia de 
electricidad; esto es así debido a que una interferencia externa, por ejemplo un campo electromagnético intenso, 
podría afectar la tensión de un cableado. Si se utilizaran valores analógicos, por ejemplo 1, 2, y 3 volts para indicar 
con cada voltaje, un estado en particular, la interferencia podría hacer que una señal de 1 volt, se convirtiera en 2 o 
3 cambiando el significado de la señal.
Combinando entonces, las señales digitales, encendido y apagado, pueden representarse letras, números y 
símbolos. El estado de "encendido" y "apagado" se representa mediante un BIT (abreviatura de binary digit).  
Existe un sistema de numeración BINARIO, el cual es útil en las computadoras pero poco comprensible para el ser 
humano, el cual se siente más cómodo con el sistema numérico decimal, lo cual implica una traducción entre 
ambos.
__________________________________________   13   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
ELABORACIÓN DE SISTEMAS
Una vez detectada la necesidad de contar con un sistema de información, comienzan a realizarse las etapas 
esquematizadas en la Fig.2, relevamiento, análisis, diseño e implementación.
Dependiendo de la complejidad y volumen de trabajo que implique el desarrollo del sistema propuesto, las fases 
de la elaboración del mismo podrán ser realizadas por una o más personas.
Dependerá también de la cantidad de personas intervinientes en dicha elaboración, que las fronteras entre las 
etapas estén bien delimitadas o sean difusas, dado que, como se verá, una persona que esté realizando un análisis 
de un sistema difícilmente podrá abstraerse de internamente estar evaluando un diseño.
Estas etapas serán subdivididas y estudiadas con mayor profundidad en el futuro, pero a modo de introducción se 
verá brevemente en qué consisten y cuál es el producido de cada una de ellas.
​Etapas en el Desarrollo de un Sistema  (DDDT)
​
​
​
    Requerimientos                                                                             DEFINE 
 
 
​
​
​
​
Diagnóstico                                                                          
​
 
 
​
​
​
​
​
 Especificaciones                                                   DESIGN 
 
 
​
​
​
​
​
​
   Programas                                      DEVELOPMENT 
 
​
​
​
 
​
​
​
​
​
​
​
​
     Sistema                     TEST​
​
​
Figura 2: Vinculación de los nombres de etapas con las acciones principales que se desarrollan
Relevamiento 
Esta es la etapa en la cual se recaban los datos necesarios para delimitar las necesidades del sistema, a través de 
distintas técnicas de recopilación de información, entrevistas personales, encuestas, cuestionarios, etc.
Mediante las técnicas enumeradas se recopilan formularios ya existentes, se estudian manuales, reportes, se 
determinan procesos, entradas y salidas de información.
A partir de los datos obtenidos se generan informes (para lo cual también existen diversas metodologías), que 
permitan estudiar los REQUERIMIENTOS y alcances del sistema a quienes tengan como función efectuar la etapa 
siguiente, el análisis.
Análisis 
En ésta fase se evalúan los requerimientos obtenidos mediante el relevamiento, estudiando los procesos de control, 
funciones de las distintas áreas componentes de la empresa, tiempos de respuesta, niveles de producción y todo 
aquello que tenga que ver con la concreción de los objetivos del sistema actual.
Es menester detectar los problemas y los aciertos a fin de corregir los primeros y mantener los segundos; como así 
también determinar que áreas son factibles de computarizar y cuáles no. El análisis no debe sólo detenerse en el 
estado actual de las cosas, sino proyectar a futuro la evolución que es de esperarse de la empresa que se está 
analizando.
__________________________________________   14   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
De todo este estudio se obtiene como resultado un DIAGNÓSTICO de lo encontrado y una serie de propuestas 
alternativas de solución, las cuales tendrán que ser evaluadas por el dueño o encargado de tomar la decisión de 
cual será llevada a la práctica.
Diseño
En función a la alternativa seleccionada, se hará un diseño que cumpla con las necesidades actuales y futuras, 
determinadas en la etapa de análisis.
Será responsabilidad de los diseñadores identificar los informes y otras salidas que el sistema producirá, dando su 
exacto formato; describir los datos, la estructura y el soporte (magnético o incluso en papel) donde los mismos 
serán almacenados.
Las ESPECIFICACIONES antes mencionadas como así también las funciones que tengan algún tipo de 
peculiaridad, serán entregadas a los programadores que serán los encargados de realizar el desarrollo del sistema.
Desarrollo
Dentro de la solución elegida puede necesitarse desarrollar software "a medida", y/o utilizar software ya existente, 
planillas de cálculo, sistemas estadísticos, etc.
La opción seleccionada dependerá no solo del costo de cada alternativa, sino también de la necesidad impuesta por 
el tiempo, dado que los programas hechos específicamente para una empresa suelen ser más costosos y de mayor 
tiempo de implementación que los ya existentes.
En ésta etapa también se realiza la documentación de los sistemas desarrollados.
No siempre la mejor solución pasa por computarizar todas las funciones, a veces algunas de estas serán más 
eficientes si son realizadas manualmente; para estas últimas se crearán en esta etapa, manuales de operación, 
delimitación de misiones y funciones, etc.
Implementación
Una vez desarrollados los programas y/o funciones manuales, los mismos deberán ser probados y ajustados, hasta 
tanto se cumplan con las necesidades impuestas por el proyecto presentado en el análisis.
También en esta fase se entrenará al personal que deberá utilizar el sistema, a fin de que pueda operarlo 
eficientemente.
Se considera parte de la implementación, el seguimiento y mantenimiento de los programas, a fin de que se 
adapten a las variaciones que pueda presentar la empresa que los use.
​
R.López 1997-2008 
S.Wahler 2019-2025
__________________________________________   15   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 2
SISTEMAS DE NUMERACIÓN
A fin de poder representar cantidades, se han ensayado a lo largo de la historia, gran cantidad de sistemas 
numéricos. Los más difundidos, por su facilidad son los POSICIONALES.
Los sistemas numéricos  posicionales, toman su nombre debido a que un mismo símbolo tiene distinto significado 
o peso según su posición; por ejemplo en el sistema numérico decimal, el símbolo 1 colocado en la posición 
extrema derecha tiene el valor de una unidad, dos posiciones más a la izquierda, tiene el valor de centena:​
​
                 n1                     unidad
​
​
   1nn                   ciento ...
Otra de las características de los sistemas numéricos posicionales es que tienen una BASE o RAÍZ, la cual está 
determinada por la cantidad de símbolos con que se cuenta para representar números. De esta forma el 
sistema decimal tiene BASE = 10 (del 0 al 9). Posteriormente se verán los sistemas binario (base = 2), octal (base 
8) y hexadecimal (base 16).
El sistema binario tiene solo dos símbolos para representar cantidades: 0 y 1. La generación de números una vez 
que se han agotado los símbolos, es la misma en cualquier sistema numérico, por lo que representando en una recta 
numérica:
binario 
0​
1​
10​
11​
100​
101​
110​
111​
1000​
1001​
1010​
1011 
 
0​
1​
 2​
3​
4​
5​
6​
7​
8​
9​
10​
11...... 
decimal 
 
Binario 
0 
1 
10 
11 
100 
101 
110 
111 
1000 
1001 
1010 
1011 
Decimal 
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
10 
11 
 
El sistema hexadecimal tiene 16 símbolos para representar números, dado que utiliza los primeros 10 iguales al 
decimal, para completar los 6 restantes se han utilizado las letras desde la A a la F. 
 
hexadecimal 
0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F     10    11    12... 
 
0    1    2    3    4    5    6    7    8    9   10    11  12   13   14   15   16    17    18... 
decimal  
 
Hexadecimal 
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
A 
B 
C 
D 
E 
F 
10 
11 
Decimal 
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
10 
11 
12 
13 
14 
15 
16 
17 
 
 
Adoptaremos como convención que se colocará una línea a la derecha de los números con los que se trabaje, 
indicando como subíndice la base a la que se refiere. A su vez, para evitar confusión, el subíndice se 
expresará siempre en decimal (Si se expresara el subíndice en la base de cada sistema siempre sería el mismo: 
10). En otros casos, se pondrá una letra b si la cantidad se expresa en binario o una h si la cantidad es 
Hexadecimal. Si es decimal (por defecto) no se pondrá indicador. 
 
Ejemplo:​
​
              10¦ 10 = 1010¦ 2
También:​
​
​
0Ch = 12
__________________________________________   16   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Dada la necesidad de traslación de números en una base a otra, se hace menester conocer los métodos de 
conversión entre bases, para poder hacer pasajes de una a otra cuando sea requerido. 
 
Representación polinómica o canónica de un número entero
Un número entero en cualquier base se puede representar por una expresión polinómica como la que sigue:
V =  r n-1 b n-1 + r n-2 b n-2 +.......+  r 1  b1  + r 0  b0   
 
Donde cada uno de los términos del polinomio tiene el siguiente formato:
r n . b n​​
(donde n varía entre 0 y n-1) 
 
n: Cantidad de cifras que posee el número 
r n : Es la cifra que ocupa la posición n (comenzando desde cero por la parte derecha del número) 
b: Es la base de la representación 
 
Ejemplo1:
724 =  r n-1 b n-1 + r n-2 b n-2 + r 0  b0  = 7.102 + 2.101 + 4.100
Obsérvese que el número posee tres cifras en las posiciones 0, 1 y 2 comenzando a contar desde la derecha.
Ejemplo 3:
​
​
         208  = 2 x 100 + 0 x 10 + 8 x 1 
​
​
                 = 2 x 10 2 + 0 x 10 1 + 8 x 10 0 
 
Es decir descomponiendo el número en la sumatoria de: cada uno de los símbolos que lo componen, multiplicados 
por la base de origen, elevada al exponente correspondiente con la posición que ocupe el símbolo, contando a 
partir de cero, de derecha a izquierda (ver arriba en negrita).
El pasaje entre bases se puede realizar convirtiendo cada uno de los términos del polinomio de la base original, a 
su equivalente en la base de destino y haciendo las operaciones en esta última.
​
208¦10     = 2 x 10 2  + 0 x 10 1  + 8 x 10 0   
​
             = 10 x 1010 10   + 0 x 1010 1  + 1000 x 1010 0 
                          = 10 x 1100100  + 0 + 1000 = 11010000¦2
Éste es un buen método para efectuar pasaje de base desde binario a decimal porque las potencias sucesivas de 2 
se van duplicando. Veamos el ejemplo anterior a la inversa:
11010000¦2  = 16 + 64 + 128 = 208
Esto se deduce porque yendo de derecha a izquierda le vamos dando “peso numérico” a cada una de las cifras que 
encontramos empezando por 1 y duplicando (2, 4, 8, 16…). Si en la cifra nos encontramos un cero, esa cifra no 
contribuye al valor del resultado. Si en cambio, nos encontramos un 1 ese peso numérico se suma al total.
Observemos que en el ejemplo dado nos encontramos un 1 en la posición 4, 6 y 7. Esas posiciones tienen peso 
numérico 24 = 16, 26 = 64  y  27 = 128
O sea que el número resultante está compuesto de las cifras anteriormente mencionadas.
La desventaja visible de este método es que debemos calcular las potencias sucesivas de la base de destino, 
multiplicadas por sus coeficientes posicionales. Este método ortodoxo, si bien es claro, presenta una alta labor de 
cálculo cuando la base no es la binaria.
__________________________________________   17   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​Conversión por divisiones sucesivas
Si retomamos el concepto dado de representar un mismo número N en dos bases distintas v y b, tenemos:
N   = Q n v n + Q n-1 v n-1 + ...... +Q 2 v 2 + Q 1 v 1 + Q 0 v 0         para la base v con símbolos Q.
N   = r n b n + r n-1 b n-1 + ...... +r 2 b 2 + r 1 b 1 + r 0 b 0                para la base b con símbolos r. 
  
En el primer caso, cada uno de los coeficientes Q son el propio valor numérico del símbolo posicional 
correspondiente, puesto que es la representación polinómica del número, en su propia base. 
En el segundo caso los coeficientes deben ser obtenidos por alguna metodología. El método ortodoxo ya visto, es 
un camino, veamos otro.  
En general podemos asegurar que un número (N) es igual al cociente (N1) por el divisor (b) más un resto (r); es 
decir: 
​
​
                 N = N1 x  b + r
Si deseamos convertir el número N dado en base v a base b podremos escribir, sacando factor común b:
N =  (r n b n-1 + r n-1 b n-2 +.......+  r 2  b1  + r 1 )  b1 + r 0
Si la cantidad entre paréntesis la denominamos N1
resulta:​ ​
N = N1 x  b1 + r0
con:​
​
N1 =  r n b n-1 + r n-1 b n-2 +.......+ r 3  b2 + r 2  b1  + r 1
o:​
​
N1=  (r n b n-2 + r n-1 b n-3 +.......+ r 3  b1 + r 2  b0  )  b1 + r 1
Si la cantidad entre paréntesis la denominamos N2
resulta:​ ​
N1 = N2 x  b + r 1
y en forma análoga:
N2 = N3 x  b + r 2
​
​
.   .    .    .     .    .    .
​
​
.   .    .    .     .    .    .
​
​
Nm = 0 x  b + r m
Con lo cual se observa que cada uno de los coeficientes r 0 .... r n , necesarios para la representación en la nueva base 
b, pueden obtenerse de los restos de las divisiones sucesivas del número N, por la base de destino, teniendo en 
cuenta que el primer coeficiente que se obtiene es el correspondiente a la posición menos significativa (b0 ). 
 
El primer resto,                  r0=N – N1 x  b1      
 
Y así sucesivamente dividiendo ahora a N1
En resumen, el método de las Divisiones Sucesivas consiste en dividir un número en cualquier base, por la 
base de destino, dividiendo sucesivamente los cocientes que van quedando y conservando cada uno de los 
restos hasta llegar a 1. El número en la base de destino, son las cifras de cada uno de los restos ordenados de 
izquierda a derecha en el orden que se los fue obteniendo. 
 
 
Ejemplo 1: para convertir el número decimal 147 a binario:
__________________________________________   18   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
147   2 
​
​
 73 ¦1         menos significativo 
​
​
 36 ¦1 
​
​
 18 ¦0 
​
​
   9 ¦0    ​ Restos  => Por lo tanto: 
​
​
   4 ¦1 
​
​
   2 ¦0                               147¦10 = 10010011¦2 
​
​
   1 ¦0 
 
Ejemplo 2: para convertir el número decimal 147 a hexadecimal
147  16 
​
​
   3 ¦9 
      => Por lo tanto: 
 
                          147 ¦10 = 93 ¦16 
 
El método por divisiones sucesivas obtenido, llega a la solución mediante un algoritmo de cálculo más sencillo y 
eficiente.
​Representación polinómica o canónica de un número fraccionario
Si extendemos el polinomio de la representación canónica a las potencias negativas de la base, conservando sólo la 
primera cifra de la representación entera tenemos lo siguiente:
N =  r 0 b 0 + r -1 b -1 +  r -2  b-2  +.......+ r -n  b-n   
 
Donde cada uno de los términos del polinomio tiene el siguiente formato:
r -n . b -n
n: Cantidad de cifras fraccionarias que posee el número 
r -n: Cifra que ocupa la posición -n (comenzando desde cero, con índice negativo hacia la derecha del número) 
b: Es la base de la representación. 
 
En la representación, como las potencias negativas de un número implica extraer la inversa del número elevado a 
la potencia cambiada de signo, resulta que cada cifra es una fracción de la unidad. Luego a la parte fraccionaria 
se la separa con una coma (,) de la parte entera.
Ejemplo en decimal:
2,724 =  r 0  b0  + r -1 b -1 + r -2 b -2 + r -n b -n  = 2.100 + 7.10-1 + 2.10-2 + 4.10-3
Obsérvese que el número posee tres cifras fraccionarias, luego n es la cantidad de éstas que posee el número. Las 
posiciones tienen índices 0, -1 , -2 y -3 comenzando a contar desde la unidad (posición cero) en sentido negativo, 
hacia la derecha. Es obvio que la sumatoria de los términos con potencia negativa dan un resultado menor que la 
unidad (precisamente por eso son parte fraccionaria).
En la numeración binaria, los pesos numéricos que poseen las potencias negativas sucesivas de dos son:
2-1 = 0,5​​
2-2 = 0,25​
2-3 = 0,125​
2-4 = 0,0625
Esto sugiere que el método canónico sigue siendo útil para el pasaje de binario a decimal en números 
fraccionarios. Ejemplo:
0, 101b = 0 + 0,5 + 0 + 0,125 = 0,625
__________________________________________   19   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​Conversión por multiplicaciones sucesivas
En el caso de que se deba convertir una parte fraccionaria, se procederá con multiplicaciones sucesivas, cuya 
justificación teórica es la siguiente:
Dado un número con parte fraccionaria N=0,......... expresado en base v, se desea pasarlo a la base b.
En la nueva base, la parte fraccionaria del mismo puede ser expresada:
​
N = r -1 b -1 + r -2  b  -2 + ... + r -n  b -n
Sacando factor común b -1:
​
    N = b -1(r -1  + r -2  b  -1 + ... + r -n  b -(n-1) )
La cantidad entre paréntesis la denominamos N1, con lo cual es igual a:
​
     N x b = r -1  + r -2  b  -1 + ... + r -n  b -(n-1)  = N1
es decir, N1 es un número entero: (r-1),  con una parte fraccionaria:  r -2  b  -1 + ... + r -n  b -(n-1)
Análogamente:
N1 = b -1 (r -2 + r -3  b  -1 + ... + r -n  b -(n-2) ) = b -1 N2
La cantidad entre paréntesis la denominamos N2
y así siguiendo, con lo cual se demuestra que: al multiplicar la parte fraccionaria del número de origen por la base 
de destino, se obtiene una parte entera (que formará parte del número convertido) y una nueva parte fraccionaria 
que debe seguirse multiplicando.
Las partes enteras que se van obteniendo de las sucesivas multiplicaciones, son los coeficientes del número N en la 
nueva base, comenzando inmediatamente después de la coma.
Las nuevas partes fraccionarias obtenidas, deben seguir siendo multiplicadas sucesivamente hasta obtener la 
cantidad de coeficientes o cifras deseadas después de la coma. Cuantas más cifras se obtengan, el número toma 
mayor precisión.
Ejemplo: Para convertir el número decimal 0,345  a binario, con 5 dígitos fraccionarios de precisión:
0,345 x 2 = 0,69  ¦0 
0,69  x 2 = 1,38   ¦1 
0,38  x 2 = 0,76   ¦0 
0,76  x 2 = 1,52   ¦1 
0,52  x 2 = 1,04   ¦1
Por lo tanto: 0,345 = 0,01011b
Observemos que el número en la nueva base, es una aceptable aproximación (con cinco dígitos de precisión) al 
número original. Para que el número obtenido en la nueva base fuera exactamente igual al original, deberíamos 
detener la multiplicación sucesiva cuando la nueva parte fraccionaria obtenida fuera cero, cosa que NO ha ocurrido 
en el caso presentado.
Conjugando los dos métodos estudiados, para el pasaje de base decimal a binaria se convierte la parte entera 
mediante divisiones sucesivas y la parte fraccionaria mediante multiplicaciones sucesivas.
Ejemplo.
110,27  =  r 2 b 2 + r -1 b -1 + r 0  b0  + r -1 b -1 + r -2 b -2  = 1.102 + 1.10-1 + 0.100 + 2.10-1 + 7.10-2 =
En la expresión polinómica de la parte entera llegamos hasta la potencia 2 porque hay 3 cifras enteras. Por el lado 
fraccionario llegamos a la potencia -2 porque hay 2 cifras fraccionarias.
__________________________________________   20   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Luego:
110 ¦        0,27  x 2 = 0,54   ¦0 
   55 ¦0      0,54  x 2 = 1,08   ¦1 
   27 ¦1      0,08  x 2 = 0,16   ¦0 
   13 ¦1      0,16  x 2 = 0,32   ¦0       
     6 ¦1      0,32  x 2 = 0,64   ¦0       
     3 ¦0      0,64  x 2 = 1,28   ¦1       (llegamos a 6 cifras fraccionarias) 
     1 ¦1 
Por lo tanto: 110,25 = 1101110,010001 ¦ 2
En el pasaje de binario a decimal, la conversión se puede efectuar con la fórmula polinómica tanto para la parte 
entera como fraccionaria del número. Veamos cómo sería el pasaje completo de binario a decimal.
Supongamos el número binario 101,011b que como se ve, posee tres cifras enteras y tres cifras fraccionarias:
101,011b = r 2 b 2 + r 1 b -1 + r 0  b0  + r -1 b -1 + r -2 b -2 + r -3 b -3 =
4 + 0 + 1 + 0 + 0,25 + 0,125 = 5,375
​Conversión directa entre bases
La conversión de números expresados en base hexadecimal y octal, a binario, es sumamente sencilla, dado que 
representando con cuatro dígitos binarios cada dígito hexadecimal y con tres en el caso del octal, se obtiene el 
número expresado en base 2.
Ejemplo 1: Para pasar el número C01 ¦16   a binario:
​
            C        0       1
1100      0000    0001​
Por lo tanto:
​
 C01 ¦16   = 110000000001 ¦2
Ejemplo 2: Para pasar el número 720 ¦8   a binario:
​
        7      2      0
111  010  000​
Por lo tanto:
720 ¦8   = 111010000 ¦2
De la misma forma para pasar del sistema binario al hexadecimal, es suficiente con  agrupar de derecha a izquierda 
cuatro dígitos binarios y escribir su equivalente en base 16 y para el caso de sistema octal es el mismo proceso, 
solo que agrupando tres dígitos binarios y escribiendo su equivalente en base 8.
La justificación es a simple vista sencilla; en el caso del pasaje de hexadecimal a binario se agrupa de a cuatro 
dígitos, dado que con esa cantidad se pueden representar todos los símbolos del sistema hexadecimal (24 =16). 
Algo similar ocurre con el sistema octal, donde todos sus símbolos se pueden representar con tres dígitos binarios 
(23 =8).
​Operaciones aritméticas en base 2
Para operar en la suma y en la resta, se deben recordar las enseñanzas de indicar cuando se produce un arrastre y 
cuando se "pide prestado" una "base" en el caso de la resta.
__________________________________________   21   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Suma
La suma de dos cantidades consiste en sumar cada par de bits correspondientes en posición, empezando desde el 
de menor peso (derecha). Si esta suma individual supera la cifra más alta (1) debe incrementarse en uno la 
posición inmediata superior, dejando el excedente en la inferior.
Función:   Y = A + B
Responde a la siguiente tabla de verdad:
A 
B 
Y 
0 
0 
0 
0 
1 
1 
1 
0 
1 
1 
1 
0 (*) 
 
(*) NOTA: Se indicará entre paréntesis (), el arrastre producido por una operación de suma.
Ejemplo: Sumar 101110 + 101011 
 
​
​
          (1)     (1) (1) (1) 
 ​
​
                1   0    1   1   1   0 
​
​
            +  1   0    1   0   1   1 
​
​
            1  0   1    1   0   0   1
Resta
La resta de dos cantidades consiste en restar cada par de bits correspondientes en posición, empezando desde el de 
menor peso (derecha). Cuando el sustraendo es mayor al minuendo se debe pedir prestado una base al dígito de la 
izquierda. En este caso debe decrementarse en uno la posición inmediata superior, dejando la resta en la inferior. 
Si esta suma individual supera la cifra más alta (1)
Función:   Y = A - B
Responde a la siguiente tabla de verdad:
A 
B 
Y 
0 
0 
0 
0 
1 
1 (*) 
1 
0 
1 
1 
1 
0  
 
(*) NOTA: Se indicará entre paréntesis () el "prestado" en una operación de resta.
Ejemplo: Restar 101110 - 101011 
​
​
                              (0) (10) (10) 
​
​
              1    0     1    1    1    0 
​
​
            - 1    0    1     0    1    1 
​
​
              0    0    0     0    1    1
Multiplicación
La multiplicación es simple debido a que se repite el multiplicando tan desplazado a la izquierda, como sea la 
posición que ocupen los unos del multiplicador. Luego se procede a hacer la suma total, sumando parcialmente las 
cantidades individuales que se obtuvieron de la multiplicación. 
 
Función:   Y = A * B
__________________________________________   22   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Ejemplo: Multiplicar 11011 * 1101 
 
​
​
                    11011 
​
​
                  *  1101 
​
​
                    11011 
​
​
                11011- - 
​
​
              11011- - - 
​                          101011111        (a) 
 
Nota: En el valor final (a), las cantidades demarcadas en negrita, produjeron arrastre a la cifra superior y estos 
arrastres fueron sumados a la cifra siguiente en posición.
División
Se realiza por el método de buscar el sustraendo multiplicando por 1 al divisor si es menor o igual al resto parcial 
que se está considerando, o por 0 si mayor. Este algoritmo es el que se enseña en general en la enseñanza primaria. 
 
Función:   Y = A  / B
Ejemplo: Dividir        110111 / 101 
 
​
​
           11011   101 
​
​
        - 101        101       cociente 
​
​
         00011 
​
​
          - 000 
​
​
              111 
​
​
            - 101 
​
​
              010          resto 
 
 
Nota: Este método algorítmicamente es más eficiente que el de restas sucesivas que consiste en restar el divisor al 
dividendo tantas veces como sea posible y contar la cantidad de veces que es posible efectuar la resta. Esta cuenta 
es el cociente y el resto que queda (menor que el divisor) es el resto de la división. 
 
Operaciones lógicas base 2
Las operaciones lógicas entre dos números se efectúan entre pares de bits correspondientes en posición.
Multiplicación lógica (and)
La multiplicación lógica se basa en el concepto que una condición de salida es verdadera, si lo son todas aquellas 
de las cuales depende. 
 
Función:   Y = A & B  
 
Se puede concluir genéricamente que Y es verdadero (en 1) si las entradas de las que depende (A y B) son 
verdaderas, esto es, están en 1. Cualquier otra condición de A y B, conduce a un estado falso (en cero) de Y.
Responde a la siguiente tabla de verdad:
A 
B 
Y 
0 
0 
0 
0 
1 
0 
1 
0 
0 
1 
1 
1
__________________________________________   23   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Ejemplo: Multiplicar lógicamente 101110  &  110011 
 ​
​
                1   0    1   1   1   0 
​
​
            & 1   0    1   0   1   1 
​
​
                1   0    1   0   1   0
Suma lógica (or)
La suma lógica se basa en el concepto que una condición de salida es verdadera, si lo es cualquiera de las cuales 
depende. 
 
Función:   Y = A | B  
 
Se puede concluir genéricamente que Y es verdadero (en 1) si alguna de las entradas de la que depende (A y B) es 
verdadera, esto es, está en 1. 
 
Responde a la siguiente tabla de verdad:
A 
B 
Y 
0 
0 
0 
0 
1 
1 
1 
0 
1 
1 
1 
1 
 
Ejemplo: Sumar lógicamente 101110  U  110011 
 
 ​
​
                1   0    1   1   1   0 
​
​
            |   1   0    1   0   1   1 
​
​
                1   0    1   1   1   1
Inversión o complementación (not)
La complementación lógica se basa en el concepto que una condición de salida es verdadera, si es falsa la 
condición de la cual depende y viceversa. 
                       __ 
Función:   Y = A  = !A 
 
Nota: La negación de una variable se representa con un trazo horizontal sobre su nombre. C utiliza el símbolo ! 
(cierre de admiración). 
 
Responde a la siguiente tabla de verdad
A 
Y 
0 
1 
1 
0 
 
Ejemplo: Complementar lógicamente 101110 
 
 ​
          N =              1   0    1   1   1   0 
​
NOT  N =             0    1   0   0   0    1
__________________________________________   24   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Exclusión lógica (Xor)
La Exclusión lógica se basa en el concepto que una condición de salida es verdadera, si las entradas de las que 
depende son exclusivas (distintas). 
 
Función:   Y = A ^ B  
 
Se puede concluir genéricamente que Y es verdadero (en 1) si las entradas de la que depende (A y B) son distintas. 
 
Responde a la siguiente tabla de verdad:
A 
B 
Y 
0 
0 
0 
0 
1 
1 
1 
0 
1 
1 
1 
0 
 
Ejemplo: Excluir lógicamente 101110  ^  110011 
 
 ​
​
                1   0    1   1   1   0 
​
​
            ^  1   0    1   0   1   1 
​
​
                0   0    0   1   0   1
​
R.López 1997-2009 
S.Wahler 2019-2025
__________________________________________   25   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 3
LOS NÚMEROS BINARIOS EN LAS
COMPUTADORAS
​
 
Las palabras utilizadas para representar datos de cualquier tipo en los sistemas de microcómputo, entre los que se 
incluyen los datos numéricos, son codificaciones binarias de n bits fijos.
En particular, los números pueden ser interpretados como valores sin signo, en los cuales sólo interesa el valor 
absoluto, o bien, como números con signo, con valores positivos o negativos. Una u otra interpretación depende de 
las intenciones del programador. La unidad aritmético – lógica dará en general, solución para ambas 
interpretaciones.
En el caso de los números con signo o signados, no habiendo más que dos estados posibles en los circuitos de 
cómputo, no existe posibilidad de signos especiales para el signo, por lo cual es necesario reservar un bit para 
representarlo. Por convención, se trata del dígito más significativo, el cual conserva siempre idéntica posición si 
se conserva un formato preestablecido, esto es, la representación numérica siempre se produce con la misma 
cantidad de dígitos. Formatos de 4, 8, 16, 32 y 64 son standard en la industria.
En la representación del signo, si el dígito más significativo es cero el número es positivo, si es uno el número es 
negativo.
Adoptado este criterio, existen al menos cuatro distintos modos de representación:
 ​
Sin signo 
 ​
Signo y módulo  
 ​
Complemento a 1 (o a la base disminuida) 
 ​
Complemento a 2 (o a la base) 
 
Sin signo
Una configuración ordenada de n bits ri ordenada como: rn-1   rn-2   ....   r2   r1  r0 , representa al número N, sin signo 
dado por: 
​
​
​
i=n-1 
​
​
N   =​
∑     2 i  . r i     
​
​
​
i=0 
 
Evidentemente el valor más bajo representable es cero, donde todos los r i son cero, y el más alto corresponde al 
número con todos los r i en uno. 
Puede demostrarse que el alcance para la representación no signada de N es: 
 
​
0  ≤   N  ≤   2 n  - 1                en caso de n=8  es,  0  ≤   N  ≤   255 
 
Signo y módulo
Es una configuración ordenada de n bits, donde el más significativo de ellos representa el signo y reserva los n-1 
bits restantes para el valor absoluto. Por ejemplo, los valores decimales +13 y – 13 serían expresados en formato 
de ocho bits, de la siguiente manera: 
 
​
​
+ 13 |10  =  0000  1101 |2    
-  13 |10  =  1000  1101 |2
__________________________________________   26   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Esto implicaría dos representaciones para el cero.!!, que sólo difieren en el dígito de signo, con los demás dígitos 
en cero: 0000  0000  y  1000 0000. 
Por otra parte, como se trata solo de agregar un 1 a la izquierda del número positivo para convertirlo en negativo, 
al sumarlos se produce un error; para ejemplificarlo hágase la suma en formato n = 4, de los números: 6 = 0110  y  
-6 = 1110, la cual debería dar 0. 
 
​
​
                    0110 
​
​
                 + 1110 
​
​
                  10100 
 
Observemos que el resultado, como es notorio, es incorrecto pues no da cero.  Este es un inconveniente de la 
representación con este sistema. 
El rango de representación para el número signado Ns sería:
​i=n-2 
​
​
| Ns |   =​ ∑     2 i  . r i     
​
​
​
i=0 
 
Decreciendo aproximadamente a la mitad respecto a la representación no signada, puesto que un dígito se emplea 
ahora para el signo, esto es: 
 
​
- (2 n-1  - 1)   ≤  Ns  ≤   2 n-1  - 1                en caso de n=8  es,  -127  ≤  Ns  ≤   + 127 
 
Con dos representaciones del cero. 
 
Complemento a uno
En esta forma de representación, los números positivos son de idéntica forma que en el caso de signo y módulo. 
Pero lo negativos, son codificados como complemento a la base 2 disminuida.
En general, si la base de un sistema numérico es b y la representación se hace en n dígitos, el complemento Nc a la 
base disminuida del número N, se expresa como:
​
​
Nc = b n - 1 - N 
 
Para el caso de la base 2 se tiene:    Nc =  2 n - 1 - N 
Donde 2 n   se expresa con n ceros a partir de la posición menos significativa y un 1 en la posición n+1. 
Por ejemplo, si n = 8: 
​
​
​
​
2 8  =   1 0000 0000 
 
Si a esta potencia de dos se la “disminuye” restando uno, nos queda un número de n bits íntegramente formado por 
unos. 
​
​
​
​
2 8  =   1 0000 0000 
​
​
​
​
         -                   1 
​
​
​
​
               1111 1111 
 
Entonces, cualquier número binario restado a la base disminuida (2 n – 1) será como resultado otro Nc, que tiene 
todos los dígitos correspondientes a N, pero invertidos, pues 1-1=0  y 1-0 = 1. 
Es decir, suponiendo el 13 decimal, su complemento a 1 (es decir el – 13), será hallado como sigue: 
 
 2 8 – 1   =        1111  1111 
​
​
​
       13    =    -  0000  1101 
​
​
      2 8 -  1 -  13​ =        1111  0010     (complemento a uno de 13) 
 
Con lo cual observamos que para obtener el complemento a uno de un número, basta invertir todos sus bits.
__________________________________________   27   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
En conclusión en este sistema, el complemento a uno, representa el número negativo Nc cuyo valor absoluto es N. 
Es obvio entonces que al igual que en el sistema de signo y módulo, tendremos dos representaciones para el cero. 
En 8 dígitos: 
​
​
​
+ 0  =    0000 0000​
 
​
​
​
-  0  =    1111 1111 
 
En cualquier sistema numérico, si a un número se le suma su negativo, se debe obtener cero, veamos: 
 
            13    =        0000 1101 
​
​
​
+     (-  13)   =    -   1111 0010 
​
​
                         -  0    =        1111  1111    (Que es el cero negativo..!!). 
 
Este sistema presenta esta ventaja respecto al de signo y módulo. 
El alcance de la representación es el mismo que en el caso de signo y módulo: 
​
​
 
​
- (2 n-1  - 1)   ≤  Nc  ≤   2 n-1  - 1                en caso de n=8  es,  -127  ≤  Nc  ≤   + 127 
 
Con dos representaciones del cero.
Complemento a dos
También en este caso, la representación de números positivos es la misma que para las dos anteriores 
representaciones. Los negativos, en cambio, son codificados como complemento a la base. En general el 
complemento Nc* a la base b de un número N, representado en n dígitos es: 
 
​
​
​
Nc* =  b n -  N 
 
En base dos será:​​
Nc* =  2 n  -  N 
 
Comparando con el complemento a uno:  Nc =  b n  - 1 - N 
 
Y sustituyendo, obtenemos:  Nc*  =  Nc  + 1 
Es decir que el complemento a dos puede obtenerse sumando un 1 al complemento a uno. 
 
Por ejemplo, el complemento a dos del número decimal 13 en ocho bits, de acuerdo a la definición se halla como 
sigue: 
      2 8    =    1  0000  0000 
​
​
​
 -     13    =    -  0000  1101 
​
​
            2 8 -  13​
=         1111  0011     (complemento a dos de 13) 
 
O bien, partiendo del complemento a uno, sumarle 1 como se ha dicho: 
 
       13    =        0000  1101 
​
        complemento a uno    =       1111  0010    (todos los bits invertidos) 
​
​
​
​
        +               1 
​
​
            ​  ​
  =      1111  0011     (complemento a dos de 13) 
 
Esta representación tiene entre otras, la ventaja de una única representación del cero. Sea el cero positivo en ocho 
bits: 
        0    =        0000  0000 
​
        complemento a uno    =       1111  1111    (todos los bits invertidos) 
​
​
​
​
        +               1 
​
​
            ​            1   ⇐    0000  0000     (complemento a dos de 0) 
 
Queda el mismo cero en ocho bits, ya que el transporte sobre el bit de signo vuelve a salir de este y se pierde por 
exceder el formato. No hay cero negativo.
__________________________________________   28   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Por otra parte, si a un número se le suma su negativo, se debe obtener cero, veamos: 
 
            13    =        0000 1101 
​
​
​
+     (-  13)   =    -   1111 0011 
​
​
                        -  0     = 1⇐ 0000 0000   (El transporte se pierde y no significa nada). 
 
Este sistema presenta esta ventaja respecto al de signo y módulo y al de complemento a uno. 
El alcance de la representación es ligeramente mayor que en los casos anteriores, ya que no existe el cero negativo: 
 
​
      - (2 n-1 )   ≤  Nc*  ≤   2 n-1  - 1                en caso de n=8  es,  -128  ≤  Nc*  ≤   + 127 
 
Con una única representación del cero. 
 
Una manera simple de obtener el complemento a la base consiste en recorrer el número de derecha a izquierda, 
dejar el primer 1 que se encuentre, y a partir de allí cambiar unos por ceros y ceros por unos, hasta completar 
el número. 
 
Ejemplo: hallar el complemento a la base del número 10011010 ¦ 2  
​
​
               1 0 0 1 1 0 1 0 
​
​
​
                  | 
  ​
​
​
      invertir   retener 
  Complemento  a dos        0 1 1 0 0 1  1 0 
 
El método del complemento a la base, es excelente fundado en el hecho que las computadoras trabajan con 
números con formato prefijado. Esto también puede explicarse con un ejemplo en sistema decimal, si se desea 
hacer una resta, 8 - 3, contando con un formato de n = 1, es decir solo un dígito, la misma podrá hacerse buscando 
el complemento a la base del sustraendo y posteriormente sumar dicho complemento al minuendo: 
 
El complemento a la base, es decir,  cuánto "le falta" para llegar a la base del sistema numérico decimal, del 
número 3 es 7, entonces: 
​
​
                    8 
​
​
                +  7 
​
​
              1    5 
 
donde el 1 acarreado, producto de la suma, es ignorado porque excede el formato (n = 1), por lo que se obtiene el 
resultado de 8 - 3 = 5. 
 
De la misma forma puede operarse en otras bases y con formatos mayores de n. 
 
Ejemplo: en base 10 hacer la resta por complemento a la base de 678 - 345, con formato n = 4. 
 
El complemento a la base de 0345 (el cero a la izquierda es para completar el formato n = 4), es 9655 (lo que le 
falta a 0345 para llegar a 10000, que es 10 n ) por lo tanto: 
 
​
​
                     0678 
​
​
                 +  9655 
​
​
               1    0333 
​
​
          
          
A los fines prácticos en el sistema decimal puede parecer poco idóneo el método de resta por complemento a la 
base, dado que posiblemente se tenga que restar a 10 n, el número a complementar, pero en el sistema binario 
hay un método sencillo de obtener el complemento a la base, ya visto, luego debe realizarse una suma. 
​
NOTA: debe tenerse mucho cuidado de antes de  proceder a hacer el complemento a la base de un número, haber   
completado con ceros a la izquierda  el formato en el que se indique se debe trabajar.
__________________________________________   29   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
En el caso en que el minuendo es menor al sustraendo, el resultado de la resta por complemento será negativo, lo 
cual quedará indicado en el bit de signo. El número obtenido, si trata de interpretarse tal como se obtuvo, no tendrá 
significado válido para el humano, para que así sea, debe tenerse en cuenta que es un número negativo y proceder 
a complementarlo. 
 
 
Ejemplo: hacer la resta por complemento, con formato n = 8, de 36 = 100100 menos 45 = 101101. 
 
a) Se llevan ambos números al formato especificado, agregando ceros a la izquierda: 
​
​
                00100100 = 36 
​
​
                00101101 = 45 
 
b) Se complementa el sustraendo: 
​
​
                11010011  (Complemento de 45) 
 
c) Se realiza la suma: 
​
​
                0 ¦ 010 0100 
​
​
             + 1 ¦ 101 0011 
​
​
                1 ¦ 111 0111   
​
    bit de signo 
 
d) Dado que el bit de signo es 1 (negativo) para interpretar el resultado se debe complementar: 
 
​
​
          11110111 = -00001001 = -9 
 
Todo lo visto sugiere que con una unidad complementadora y otra sumadora en la computadora, es posible realizar 
las operaciones de suma y resta, esta última mediante el complemento a la base.
Cambio de formato
Cuando se cambia de formato un número, por ejemplo para llevarlo de un formateen 8 bits a un formato en 16 bits, 
se procede a la “extensión del signo”. El concepto puede comprenderse mediante el siguiente ejemplo:
Supongamos el binario:  01101  (Si se lo considera en formato n=5, se trata del número 13 decimal)
Si queremos llevarlo a formato n=8  se convierte en:    0000 1101
Este número “negado” se convierte en el:  1111 0011     (Que es el -13 decimal)
Si ahora deseamos cambiarle el formato al número negativo llevándolo a n=16, debemos extender el signo, esto es:
1111 1111 1111 0011   (Que sigue siendo el -13 decimal en formato n=16)
La tarea ha consistido en completar los bits necesarios para llegar al formato deseado, copiando en la parte 
alta el signo que posee el número en el anterior formato. (En este caso ha sido necesario incorporar “unos”).
Como verificación final, complementamos el nuevo número para obtener su correspondiente positivo y 
obtenemos:
0000 0000 0000 1101  (Que es el 13 decimal en formato n=16)
Como veremos más adelante en el tratamiento de instrucciones del procesador, existen instrucciones específicas 
para el cambio de formato.
__________________________________________   30   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Conclusiones
Para fijar ideas, consignaremos una tabla de los números representables en cuatro bits (para mayor simplicidad) en 
cada uno de los tres sistemas signados.
​
Nº 
decimal
Signo y Módulo 
Complemento a 1 
Complemento a 2
+ 7 
0111 
0111 
0111 
+ 6 
0110 
0110 
0110 
+ 5 
0101 
0101 
0101 
+ 4 
0100 
0100 
0100 
+ 3 
0011 
0011 
0011 
+ 2 
0010 
0010 
0010 
+ 1 
0001 
0001 
0001 
+ 0 
0000 
0000 
0000 
-  0 
1000 
1111 
----
-  1 
1001 
1110 
1111 
-  2 
1010 
1101 
1110 
-  3 
1011 
1100 
1101 
-  4 
1100 
1011 
1100 
-  5 
1101 
1010 
1011 
-  6 
1110 
1001 
1010 
-  7 
1111 
1000 
1001 
-  8 
---- 
---- 
1000 
 
 
Se destaca que: 
 
 ​
Los números positivos se representan de la misma manera en los tres casos. 
 ​
El bit más significativo representa el signo: positivo si es cero, negativo si es uno. 
 ​
En los dos primeros sistemas, el cero tiene doble representación. En complemento a dos, es única. 
 ​
En complemento a dos existe mayor alcance negativo de representación. 
 ​
En complemento a uno y dos, la resta se resuelve por suma de complemento, con resultados coherentes. 
 ​
En signo y módulo el bit de signo sólo significa eso. En complemento a dos, el bit de signo tiene “peso 
numérico” igual a  - (2 n-1 ). 
 
Esta última consideración permite sugerir un método simple para el pasaje a decimal de un número binario 
negativo. Bastará con calcular el valor positivo representado por todos los bits menos el de signo y sumar 
algebraicamente ese valor al representado por el bit de signo: - (2 n-1 ). 
 
Por ejemplo hallar el equivalente decimal de:  1001 0111 
 
El bit de signo es uno en este caso, luego su peso en ocho bits es: - (2 8-1 ) = 128 
Si exceptuamos el bit de signo y calculamos el número representado por el resto de los bits: 
 
​
​
001 0111 = 23 
 
Luego,​ ​
 N =  -128  + 23 =  -105 
 
Que es el valor decimal representado, obtenido mediante la conversión directa sugerida.
__________________________________________   31   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Banderas de estado
En los métodos anteriores hemos observado la ventaja del complemento a dos respecto al resto de los métodos:
a)​ Representación única del cero. 
b)​ Mayor alcance negativo de la representación. 
c)​ Simple mecanización de la resta, por suma de complemento. 
 
En los microprocesadores actuales, una operación aritmética genera seis bits que indican su estado en función del 
resultado que se obtiene. Esos bits son llamados banderas (flags) y se los conoce por sus nombres ingleses: 
 
​
N  = NEGATIVE  (signo) 
​
Z = ZERO  (resultado cero) 
​
P = PARITY (Paridad) 
C = CARRY (acarreo) 
​
DC = DECIMAL CARRY (Carry Auxiliar)   
OV = OVERFLOW (desborde de formato)
Bandera N
N será igual a 1 si el bit de signo en el resultado es negativo, es decir = 1; caso contrario, en que el resultado sea 
positivo, N = 0. 
Como se observa, la bandera N, es una copia del bit de signo del resultado de una operación de suma (o resta por 
complemento).
Bandera Z
Solamente se enciende, (Z = 1) si el resultado de la operación es cero, dentro del formato especificado. Es decir 
aunque se hubiera producido un acarreo en la operación, si en el formato quedaron todos ceros, la bandera  Z se 
hace igual a 1.
Bandera P
Esta bandera se coloca en 1 cuando existe una cantidad par de unos en un formato especificado (normalmente 8). 
Ejemplos con P=1, son:
11001100 
10000100 
Esta bandera es utilizada generalmente en comunicaciones para detectar errores. Representa la paridad en los 
registros de 8 bits y la paridad de la parte baja en los registros de 16 bits. Algunos procesadores no traen esta 
bandera.
Bandera C
Esta bandera se coloca en 1 cuando se produce un acarreo en la operación realizada con formato igual a n. Por 
acarreo se entiende cuando se obtiene un 1 en la posición n + 1, es decir excediendo el formato que se haya 
especificado. En caso de que esto no ocurra, la bandera C es igual a cero.
Bandera DC
Esta bandera se coloca en 1 cuando hay un arrastre del 4to al 5to bits en el caso de una operación aritmética en 8 
bits. Sirve para corregir el arrastre cuando se efectúan operaciones en decimal con codificación binaria (BCD), 
según se verá más adelante.
__________________________________________   32   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Bandera OV
Dado que en un formato especificado sólo es posible representar un número positivo máximo y uno negativo 
mínimo, puede ocurrir que como consecuencia de una operación aritmética se superen esos extremos. 
Por ejemplo en formato n = 8 solo se puede representar hasta el número 127 positivo y 128 negativo, si se hiciera 
la suma de los números 38 y 120, aunque los mismos pueden ser representados en el formato, no puede serlo su 
resultado, el cual es mayor a 127. Esto produce un desbordamiento (overflow). 
 
La bandera OV es la que indica si se ha producido o no un desbordamiento. Se colocará en 1, en caso de overflow 
y en 0 de no haber ocurrido.
 ​
Puede producirse overflow en caso de suma de dos números positivos o dos negativos. (En ambos casos 
el valor absoluto del número aumenta). 
 ​
También en la resta de números de distinto signo, ya que al complementar el sustraendo se cae en el caso 
anterior.  
 
Hay dos reglas prácticas para determinar el valor de la bandera OV: 
 
1.​ Siempre que se sumen dos números de signo contrario el valor de OV será cero. Ello es debido a que el valor
absoluto del resultado será menor que el del operando mayor. 
2.​ Siempre que se sumen dos números de igual signo y el resultado sea de signo contrario a los operandos, la
bandera OV será igual a 1. 
 
Resulta importante distinguir bien las funciones de las banderas de carry ( C ) y overflow ( OV ). 
La siguiente tabla da ejemplos en los cuales se aprecian cuatro situaciones posibles:
Decimal 
Binario 
Transporte desde
Signos 
diferentes
Bandera
Bandera
Resultado
el bit de signo.?
OV
C
1 
0000 0001 
 
 
 
 
 
+2   
0000 0010 
NO 
NO 
0 
0 
correcto 
 3 
0000 0011 
 
 
 
 
 
  64 
0100 0000 
 
 
 
 
 
+72 
0100 1000 
NO 
NO 
1 
0 
incorrecto 
136 
1000 1000 
 
 
 
 
 
    -2 
1111 1110 
 
 
 
 
 
+127 
0111 1111 
SI 
SI 
0 
1 
correcto 
  125 
1⇦0111 1101 
 
 
 
 
 
-128 
1000 0000 
 
 
 
 
 
   - 1 
1111 1111 
SI 
NO 
1 
1 
incorrecto 
-129 
1⇦0111 1111 
 
 
 
 
 
 
La bandera overflow tiene sentido si se consideran los operandos como números signados. En números NO 
signados esta bandera no tiene utilidad. La misión del indicador de overflow es poner de manifiesto un resultado 
incorrecto (Si bien los operandos actuantes cabían en el formato especificado, su resultado no). 
 
En cambio el indicador de transporte no parece tener una función claramente definida. 
Sin embargo, la función de este indicador se hace evidente cuando se considera la aritmética entera de mayor 
precisión que el tamaño máximo de los registros del procesador, donde los datos, para ser representados, deberán 
utilizar más de un registro. Por ejemplo, si se utilizaran dos palabras de 16 bits para representar un dato en 32 bits, 
se debería utilizar el siguiente procedimiento:
1.​
Se suman las dos palabras de 16 bits menos significativas (considerándolas como números NO signados), 
utilizando la instrucción ADD. 
2.​
Se suman después las dos palabras más significativas (considerándolas como números signados), más el 
valor del indicador de transporte, para ello se utilizará la instrucción ADC, que es una suma de tres 
integrantes: Los dos operandos identificados en los campos fuente y destino y el carry.
__________________________________________   33   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
3.​
El signo e indicador de overflow luego de esta operación, son los válidos para la operación completa en 
32 bits y resultan del registro que conforma la parte alta del resultado. 
 
El carry también actúa adecuadamente cuando se quiere efectuar una resta en la aritmética entera de mayor 
precisión que el tamaño máximo de los registros del procesador. En este caso, al realizar la resta en dos pasos 
(Equivalente al caso de la suma) el carry automáticamente establece si existe un “pedido” a la parte alta. Por 
ejemplo, si se utilizaran dos palabras de 16 bits para representar un dato en 32 bits, se debería utilizar el siguiente 
procedimiento:
1.​
Se restan las dos palabras de 16 bits menos significativas (considerándolas como números NO signados), 
utilizando la instrucción SUB. 
2.​
Se restan después las dos palabras más significativas (considerándolas como números signados), menos 
el valor del indicador de transporte, para ello se utilizará la instrucción SBB, que es una resta de tres 
integrantes: +Operando fuente – Operando destino – carry. 
3.​
El signo e indicador de overflow luego de esta operación, son los válidos para la operación completa en 
32 bits y resultan del registro que conforma la parte alta del resultado. 
 
Comparación
Otra utilidad de la bandera de Carry se hace evidente en la comparación de números NO Signados. 
Por ejemplo, consideremos comparar el número 7 con el número 20. Sabemos que el primero es menor. Veamos 
entonces cómo procede el microprocesador para instrumentar una función de comparación (CP). 
El procesador instrumenta la comparación por intermedio de una resta, sin verificar el resultado, sólo verificando 
la bandera C, veamos. 
 
1er caso: 
Para ello, el procesador deberá efectuar la siguiente instrucción:  CP  7 , 20 
Y prácticamente, restará de la siguiente forma:  7 – 20 
Para restar efectúa el complemento del segundo término y lo suma al primero: 
 
20  =  0010 0000, con lo que  - 20 =  1110  0000. 
Luego al sumar:
7  =     0000  0111 
​
​
          - 20 =      1110  0000 
​
​
​
       0  1110  0111​ 
 
Observamos que el carry resultante es CERO, cuando el operando de la izquierda (destino) es menor. 
 
2do caso: 
CP  15, 4 
Empleamos el mismo procedimiento: 
4 = 0000 0100   , o sea  - 4 = 1111 1100. Luego:
15  =    0000  1111 
​
​
            -  4  =     1111  1100 
​
​
​
         1 0000  1011 
​
 
Puesto que el arrastre que a su vez genera el carry, se pierde, se puede concluir que el carry se hace UNO, si el 
número a comparar (15) es mayor . 
 
3er. caso: 
Queda por último determinar qué sucede cuando ambos números son iguales. Comparemos: CP 7, 7 
 
7 =  0000 0111   , o sea  - 7 = 1111 1001. Luego:
7   =​
0000  0111 
​
​
            - 7   = ​
1111  1001 
​
​
​
          1​ 0000  0000 
__________________________________________   34   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Vemos que el carry se hace UNO, si el número a comparar es igual. 
 
Con lo que finalmente concluimos que, para comparar un operando destino (izquierda de la coma), con otro 
operando (fuente), bastará observar la bandera de carry. Si esta se pone en CERO, determinará que el número 
comparado (destino) es menor. En UNO, determinará que es mayor o igual. Si se quiere conocer si los números 
son iguales deberá utilizarse la bandera Z. 
 
La pregunta que aquí cabe es:
No sería igual si se utiliza la bandera N.?. 
La respuesta es: La bandera N no debe ser utilizada para la comparación de número NO Signados, debido 
precisamente a que esta asume el bit más significativo como signo y un número NO Signado no posee signo. 
Como una simple prueba veremos que la bandera S no otorga siempre un resultado correcto en la comparación de 
números NO signados. Veamos el siguiente ejemplo en 8 bits: 
 
4to. caso: 
CP 3, 133 
 
133= 1000 0101   , al complementar se transforma en  0111 1011. Luego:
=    0000  0011 
​
​
                  =      0111  1011 
​
​
​
        0  0111  1110 
 
Observemos que el carry es CERO indicando que el operando de la izquierda es menor, lo cual es correcto 
conforme a la regla establecida. Y la bandera de signo en este caso es 0, opuesta al resultado que otorgó cuando se 
comparó 7 con 20 (En el primer caso) . 
 
En la comparación de números signados se utilizará la bandera N, pero debido a que el resultado puede dar 
overflow en ciertos casos, deberá también considerarse la bandera OV. Los procesadores tienen instrucciones 
específicas que se valen de la comparación como números signados y que son distintas de las de números NO 
signados. Estas instrucciones se verán luego cuando veamos el comportamiento del microprocesador en estos 
casos. 
 
Conclusiones acerca de la utilidad de las banderas C, OV, N y Z.
a)​ El carry tiene utilidad para las operaciones de suma y resta signadas o no signadas que exceden el
formato máximo de los registros ya que determina si existe acarreo o pedido para ser incorporado en la 
siguiente etapa de la operación de las palabras de mayor peso numérico. 
b)​ El carry es el único que determina correctamente si un valor es mayor o menor que otro en la
comparación NO signada. 
c)​ La igualdad la determina la bandera Z. 
d)​ El overflow determina si una operación de suma o resta SIGNADA es incorrecta por haberse excedido
el tamaño del registro contenedor del resultado. 
e)​ La bandera de signo complementada con la de overflow son las únicas que determinan correctamente si
un valor es mayor o menor que otro en la comparación SIGNADA. La igualdad la determina la bandera 
Z.
​
R.López 1997-2011 
S.Wahler 2019-2025
__________________________________________   35   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 4
SISTEMAS DE CODIFICACIÓN
Notación Exponencial
En algunas ocasiones resulta inapropiada la forma de escribir los números mediante un sistema meramente 
posicional. En el caso de la masa de un electrón (9 x 10-28 gramos) o la masa del sol (2 x 10 33  gramos), deberían 
ser escritos respectivamente, como: 
​
0,0000000000000000000000000009       (28 ceros a la izquierda de la primera cifra significativa) 
​
2000000000000000000000000000000000  (33 ceros a la derecha de la primera cifra significativa) 
 
Como se verá, es mucho más práctico y legible representar esas cantidades en notación exponencial, la cual está 
constituida por un número real llamado MANTISA y otro entero positivo o negativo llamado EXPONENTE. 
Nótese que el rango está determinado por el número de dígitos del exponente, mientras que la precisión está 
determinada por el número de dígitos de la mantisa. 
 
El exponente negativo implica que para llevar el número a notación NO exponencial, se deberá mover la coma 
fraccionaria, tantos lugares a la izquierda como lo indique el exponente. El exponente positivo implica que para 
llevar el número a notación NO exponencial, se deberá mover la coma fraccionaria, tantos lugares a la derecha 
como lo indique el exponente. 
 
Ejemplo 1: 
15 = 0,15 x 10 2  = 1,5 x 10 1  = 0,0000015 x 10 7  = 1500,0 x 10-2  
 Ejemplo 2: en sistema binario 
1010 = 0,1010 x 10 100  = 1,010 x 10 11  = 101000,0 x 10 -10 
 
Debe notarse que en el Ejemplo 2, la mantisa, la base y el exponente están expresados en base 2. 
 
Como se ha visto en ambos ejemplos, el punto o coma fraccionaria puede "flotar" cambiando tan solo el exponente 
convenientemente. 
 
Debido a que como un mismo número puede ser expresado en infinitas formas utilizando la NOTACIÓN DE 
PUNTO FLOTANTE, ya sea en sistema decimal, sistema binario o cualquier otro sistema numérico, es deseable 
indicar una convención para escribir los números. La que se usa comúnmente es la de poner la coma 
inmediatamente a la derecha de la PRIMERA cifra significativa del número. Esto lo veremos en las codificaciones 
de punto flotante que siguen a continuación. 
 
Estándar IEEE de punto flotante
El IEEE Computer Society, haciéndose eco de la necesidad de poder brindar portabilidad en programas de 
aplicación numérica, desarrolló un estándar (Standard 754) para aritmética de punto flotante en sistema binario.
Este estándar está ampliamente difundido. Microprocesadores tales como Intel, Motorola, MIPS y SPARC tienen 
un co-procesador matemático que responde al estándar de IEEE.
Se cubre el formato para números de simple precisión (32 bits), los de doble precisión (64 bits) y precisión 
extendida (80 bits).
En simple precisión se ha dotado a la mantisa de 23 bits, al exponente de 8 bits y 1 bit para el signo global del 
número. Es equivalente a una representación con signo y módulo.
1 bit​
8 bits​
​
​
23 bits​ ​
​
​
​
total 32 bits= 4 bytes
__________________________________________   36   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Signo S 
El bit más significativo de la representación es el bit de signo: 1 (negativo) ó 0 (positivo).  Este es el signo del 
número (el que en rigor queda asociado a la mantisa).
Exponente E
Como el rango de representatividad para números no signados en 8 bits va de 0 a 255, el exponente codificado 
será siempre positivo porque se representa en “exceso 127”, es decir que al exponente real, se le debe sumar el 
número 127 para obtener el exponente codificado, en el Formato Normalizado, esto es: 
 
​
Expo. Codificado = Expo. Real + 127 
 
  
Con lo que resulta que el rango posible del exponente es: 
 
​
    127  ≥  Exponente Real   ≥   -126 
 
Los exponentes 255 y 0, representativos de + 128 y –127 reales, se dejan excluidos expresamente para la 
representación del infinito y el cero en lo que da en llamarse formato NO Normalizado. 
Es decir que para el Standard, los formatos normalizados tienen el alcance de exponente dado (+127, -126) con 
cualquier mantisa.
Mantisa M
En el caso de la mantisa, la misma tiene un 1 implícito. Esto es, la normalización indica que el punto fraccionario 
debe colocarse a la derecha del primer bit significativo, luego se poda la parte entera (que siempre será 1) y lo que 
se vuelca en la mantisa M codificada es la parte fraccionaria. 
Ejemplo: 
Mantisa= 0,0011101              Mantisa normalizada=1,1101              Volcado al campo del standard= 1101 
 
En función de lo expuesto, la expresión de decodificación para el número N(decimal) en función de los campos 
binarios del standard es:
Ejemplo 
Veamos el significado de la cantidad de 32 bits:  9C 82 E2 20 h= 1001 1100 1000 0010 1110 0010 0010 0000 b 
Volcado en la matriz del Estándar de Simple precisión resulta: 
 
 
 
​
 
Que está representando el número: 
-  1,00000101110001000100000 x 10 -01000110   ≅  1.0195 x 2 –70  (decimal)   
   
En el formato de doble precisión el estándar indica que deberá tener un bit de signo, un exponente de 11 bits y una 
mantisa de 52 bits. En este caso el exponente se representa en exceso 1023, con lo cual: 
 
​
​
   1023  ≥  Exponente real   ≥  - 1022 
 
 
              1 bit          11 bits                                                52 bits                                        total 64 bits= 8 bytes 
 
En este caso, los exponentes +1024 y –1023 se excluyen para la representación de infinito y cero, similarmente a 
lo dicho para simple precisión. Luego su expresión es:
__________________________________________   37   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
La representación para precisión extendida tiene un bit para el signo, 15 para el exponente y  64 para la mantisa, 
con similares consideraciones que para los casos anteriores. En este caso NO hay 1 implícito. Luego su expresión 
es:
Formatos No normalizados
Los formatos NO normalizados de representación para infinito y cero tienen las siguientes consideraciones:
Infinito
Con la representación de infinito, en los tres casos del standard se ponen todos unos en el exponente (sin importar 
la mantisa).
Exponente en cero 
Cuando el exponente está en cero la mantisa es válida tal cual está PERO en ese caso el que está implícito es un 
CERO (no uno implícito como en normalizada). Esto se cumple para la representación SIMPLE Y DOBLE.​
​
En el caso de la representación extendida no hay distingos en normalizada y NO normalizada porque NO EXISTE 
el uno o cero implícito. lo que se representa en el campo mantisa es el numero completo (obvio, sin exponente) 
donde el punto se entiende que está a la derecha de la primera cifra, con lo cual esa primera cifra (ahora 
explicita) es la parte entera del número que bien puede ser cero o uno. En este caso la representación del CERO es 
bien factible sin recurrir a un esquema NO NORMALIZADO como debe recurrirse en los casos simple y doble 
precisión.
Rango representable
-1.111...1 x 2 127                    -1.0000...000 x 2 -126      1.0000...000 x 2 -126                           1.111...1 x 2 127    
    A                    B                          C               D      E      F                G                        H                           I 
 
      -∞                                                                                                                                                          +∞ 
                                             -1                                  0                                 1    
 
La recta de arriba muestra una figura comprimida de la recta representativa de los números reales, que se extiende 
desde -∞ por la izquierda, pasando por el cero en el centro, hasta +∞ por la derecha. 
En la recta, se han determinado segmentos que se ubican entre una marca y otra y se los ha denominado con letras 
desde la A a la I. 
En la recta podemos distinguir siete zonas perfectamente diferenciadas. Si tomamos la representación de simple 
precisión como ejemplo, tenemos: 
 
La primera es la zona A, representa el desbordamiento negativo. En esta zona se encuentran todos los números 
negativos, cuyo valor absoluto supera el rango máximo alcanzable por la representación del standard que es 
-1.111...1 x 2 127 hasta -∞. 
  
La segunda zona es la de los números negativos representables por el standard (zonas B y C) para los números con 
valor absoluto mayor que 1 hasta el máximo representable (B) y los números de valor absoluto menor que 1 hasta 
el mínimo representable por el standard  -1.0000...000 x 2 -126 . 
 
Nótese que en la zona B y C la representación no puede ser continua, ya que la mantisa de solo 23 cifras más el 1 
implícito, no permitirá representar los números que posean más de 24 cifras significativas. Por ello, la precisión de 
un número está dada por la cantidad de cifras de su mantisa. Entre los dos números representables más próximos 
del standard, siempre habrá infinitos números que no podrán representarse dado que no se posee mayor 
discriminación. Para que todos los números fueran representables se deberían tener infinitas cifras significativas en 
la mantisa.
__________________________________________   38   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
La tercera zona es la zona D, representa el subdesbordamiento negativo. En esta zona se encuentran todos los 
números negativos, cuyo valor absoluto está comprendido entre el cero absoluto y el menor valor absoluto 
representable en el standard que es -1.0000...000 x 2 –126. 
 
La cuarta zona es realmente un punto, representado por E, el cero. 
 
La quinta zona es la zona F, representa el subdesbordamiento positivo. En esta zona se encuentran todos los 
números positivos, cuyo valor está comprendido entre el cero absoluto y el menor valor representable en el 
standard que es 1.0000...000 x 2 –126. 
 
La sexta zona es la de los números positivos representables por el standard (zonas G y H) para los números con 
valor comprendido entre el mínimo y el máximo representable por el standard (pasando por 1). 
 
La séptima es la zona I, representa el desbordamiento positivo. En esta zona se encuentran todos los números 
positivos, cuyo valor supera el rango máximo alcanzable por la representación del standard que es: 
1.111...1 x 2 127 hasta ∞.  
 
Unidades de medida
Luego de haber visto con relativa profundidad el sistema numérico binario, operaciones y estandarizaciones sobre 
el mismo, es importante dar nombre a las unidades de medida utilizadas habitualmente en computación. 
Teniendo en cuenta que a la agrupación de 8 bits se la llama BYTE, se puede generar la siguiente tabla de unidades 
de medida:
​Cantidad 
​Nombre 
​Bytes 
​Potencia de 2 
8 bits 
Byte 
1 
0 
1024 bytes 
Kilobyte 
1,024 
10 
1024 kb 
Megabyte 
1,048,576 
20 
1024 Mb 
Gigabyte 
1,073,741,824 
30 
1024 Gb 
TeraByte 
 
40 
1024 Tb 
PetaByte 
 
50 
1024 Pb 
ExaByte 
 
60
Codificación
Con un byte puede representarse en una computadora hasta 255 símbolos, incluyendo dentro de los mismos, 
señales de control para la computadora, letras mayúsculas y minúsculas, números, signos de puntuación y 
caracteres gráficos varios (líneas, ángulos, sombreados, etc.), estas representaciones son llamadas CÓDIGOS. Este 
tipo de variable es definida como char (carácter).
Código ASCII
El más difundido de los códigos actualmente, es el ASCII (American Standard Code for Information Interchange), 
el cual cuenta con 7 bits, permitiéndole representar hasta 128 (de 0 a 127), señales internas, letras minúsculas y 
mayúsculas, puntuaciones, números, etc.; por ejemplo: de 0 a 31 se representan señales internas. Con 8 bits se 
cuenta con un código ASCII “extendido” de 256 caracteres ( de 0 a 255). Los caracteres desde 128 en adelante, 
son de utilización variada por los distintos fabricantes por ende cada carácter no tiene un significado único.
__________________________________________   39   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
CÓDIGO ASCII  EXTENDIDO 
  Dec  
Hex 
Char     Dec  
Hex  
Char  
Dec  
Hex  
Char  
Dec  
Hex  
Char 
    0  
00h 
NUL   
  64  
40h  
@    
128  
80h  
Ç    
192  
C0h  
+ 
    1  
01h 
SOH   
  65  
41h  
A    
129  
81h  
ü    
193  
C1h  
- 
    2  
02h 
STX   
  66  
42h  
B    
130  
82h  
é    
194  
C2h  
- 
    3  
03h 
ETX   
  67  
43h  
C    
131  
83h  
â    
195  
C3h  
+ 
    4  
04h 
EOT   
  68  
44h  
D    
132  
84h  
ä    
196  
C4h  
- 
    5  
05h 
ENQ   
  69  
45h  
E    
133  
85h  
à    
197  
C5h  
+ 
    6  
06h 
ACK   
  70  
46h  
F    
134  
86h  
å    
198  
C6h  
ã 
    7  
07h 
BEL   
  71  
47h  
G    
135  
87h  
ç    
199  
C7h  
Ã 
    8  
08h 
BS    
  72  
48h  
H    
136  
88h  
ê    
200  
C8h  
+ 
    9  
09h 
HT    
  73  
49h  
I    
137  
89h  
ë    
201  
C9h  
+ 
   10  
0Ah 
LF    
  74  
4Ah  
J    
138  
8Ah  
è    
202  
CAh  
- 
   11  
0Bh 
VT    
  75  
4Bh  
K    
139  
8Bh  
ï    
203  
CBh  
- 
   12  
0Ch 
FF    
  76  
4Ch  
L    
140  
8Ch  
î    
204  
CCh  
¦ 
   13  
0Dh 
CR    
  77  
4Dh  
M    
141  
8Dh  
ì    
205  
CDh  
- 
   14  
0Eh 
SO    
  78  
4Eh  
N    
142  
8Eh  
Ä    
206  
CEh  
+ 
   15  
0Fh 
SI    
  79  
4Fh  
O    
143  
8Fh  
Å    
207  
CFh  
¤ 
   16  
10h 
DLE   
  80  
50h  
P    
144  
90h  
É    
208  
D0h  
ð 
   17  
11h 
DC1   
  81  
51h  
Q    
145  
91h  
æ    
209  
D1h  
Ð 
   18  
12h 
DC2   
  82  
52h  
R    
146  
92h  
Æ    
210  
D2h  
Ê 
   19  
13h 
DC3   
  83  
53h  
S    
147  
93h  
ô    
211  
D3h  
Ë 
   20  
14h 
DC4   
  84  
54h  
T    
148  
94h  
ö    
212  
D4h  
È 
   21  
15h 
NAK   
  85  
55h  
U    
149  
95h  
ò    
213  
D5h  
i 
   22  
16h 
SYN   
  86  
56h  
V    
150  
96h  
û    
214  
D6h  
Í 
   23  
17h 
ETB   
  87  
57h  
W    
151  
97h  
ù    
215  
D7h  
Î 
   24  
18h 
CAN   
  88  
58h  
X    
152  
98h  
ÿ    
216  
D8h  
Ï 
   25  
19h 
        
  89  
59h  
Y    
153  
99h  
Ö    
217  
D9h  
+ 
   26  
1Ah 
SUB   
  90  
5Ah  
Z    
154  
9Ah  
Ü    
218  
DAh  
+ 
   27  
1Bh 
ESC   
  91  
5Bh  
[    
155  
9Bh  
ø    
219  
DBh  
¦ 
   28  
1Ch 
FS    
  92  
5Ch  
\    
156  
9Ch  
£    
220  
DCh  
_ 
   29  
1Dh 
GS    
  93  
5Dh  
]    
157  
9Dh  
Ø    
221  
DDh  
¦ 
   30  
1Eh 
RS    
  94  
5Eh  
^    
158  
9Eh  
×    
222  
DEh  
Ì 
   31  
1Fh 
US    
  95  
5Fh  
_    
159  
9Fh  
ƒ    
223  
DFh  
¯ 
   32  
20h 
space   
  96  
60h  
`    
160  
A0h  
á    
224  
E0h  
Ó 
   33  
21h 
 !       
  97  
61h  
a    
161  
A1h  
í    
225  
E1h  
ß 
   34  
22h 
 "      
  98  
62h  
b    
162  
A2h  
ó    
226  
E2h  
Ô 
   35  
23h 
 #      
  99  
63h  
c    
163  
A3h  
ú    
227  
E3h  
Ò 
   36  
24h 
 $        100 
64h  
d    
164  
A4h  
ñ    
228  
E4h  
õ 
   37  
25h 
 %        101 
65h  
e    
165  
A5h  
Ñ    
229  
E5h  
Õ 
   38  
26h 
 &        102 
66h  
f    
166  
A6h  
ª    
230  
E6h  
µ 
   39  
27h 
 '         103 
67h  
g    
167  
A7h  
º    
231  
E7h  
þ 
   40  
28h 
 (         104 
68h  
h    
168  
A8h  
¿    
232  
E8h  
Þ 
   41  
29h 
 )         105 
69h  
i    
169  
A9h  
®    
233  
E9h  
Ú 
   42  
2Ah 
 *        106 
6Ah  
j    
170  
AAh  
¬    
234  
EAh  
Û 
   43  
2Bh 
 +        107 
6Bh  
k    
171  
ABh  
½    
235  
EBh  
Ù 
   44  
2Ch 
  
  108 
6Ch  
l    
172  
ACh  
¼    
236  
ECh  
 
   45  
2Dh 
 -         109 
6Dh  
m    
173  
ADh  
¡    
237  
EDh  
Ý 
   46  
2Eh 
 .         110 
6Eh  
n    
174  
AEh  
«    
238  
EEh  
¯ 
   47  
2Fh 
 /         111 
6Fh  
o    
175  
AFh  
»    
239  
EFh  
´ 
   48  
30h 
 0        112 
70h  
p    
176  
B0h  
¦    
240  
F0h  
 
   49  
31h 
 1        113 
71h  
q    
177  
B1h  
¦    
241  
F1h  
± 
   50  
32h 
 2        114 
72h  
r    
178  
B2h  
¦    
242  
F2h  
=
__________________________________________   40   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
51  
33h 
 3        115 
73h  
s    
179  
B3h  
¦    
243  
F3h  
¾ 
   52  
34h 
 4        116 
74h  
t    
180  
B4h  
¦    
244  
F4h  
  
   53  
35h 
 5        117 
75h  
u    
181  
B5h  
Á    
245  
F5h  
§ 
   54  
36h 
 6        118 
76h  
v    
182  
B6h  
Â    
246  
F6h  
÷ 
   55  
37h 
 7        119 
77h  
w    
183  
B7h  
À    
247  
F7h  
¸ 
   56  
38h 
 8        120 
78h  
x    
184  
B8h  
©    
248  
F8h  
° 
   57  
39h 
 9        121 
79h  
y    
185  
B9h  
¦    
249  
F9h  
¨ 
   58  
3Ah 
 :         122 
7Ah  
z    
186  
BAh  
¦    
250  
FAh  
· 
   59  
3Bh 
 ;         123 
7Bh  
{    
187  
BBh  
+    
251  
FBh  
¹ 
   60  
3Ch 
 <        124 
7Ch  
|    
188  
BCh  
+    
252  
FCh  
³ 
   61  
3Dh 
 =        125 
7Dh  
}    
189  
BDh  
¢    
253  
FDh  
² 
   62  
3Eh 
 >        126 
7Eh  
~    
190  
BEh  
¥    
254  
FEh  
¦ 
   63  
3Fh 
 ?        127 
7Fh  
    
191  
BFh  
+    
255  
FFh  
 
​
 
Tipos de datos
Los datos numéricos deben ser definidos previo a su uso por la computadora. Esto es así debido a que una 
agrupación de n bytes puede tener distinto significado conforme a la codificación que se haya adoptado. 
Estas agrupaciones y su codificación implícita tiene determinadas denominaciones conforme al lenguaje de 
computación que se adopte. No obstante daremos aquí una denominación general. La siguiente tabla ilustra sobre 
algunas de las distintas variables existentes.
TIPO 
Variable 
Tamaño
​
Rango 
​
Observaciones
(bytes)
Unsigned 
byte/char 
1 
0 – 255 
Interpretado como número no signado. 
/ Signed 
Word 
2 
0 - 65535 
Interpretado como número no signado. 
 
ShortInt 
1 
-128 a +127 
Representado en complemento a dos (Rep. Exacta) 
Enteros 
Integer 
2 
- 32768  a 32767 
Representado en complemento a dos (Rep. Exacta) 
(Signed) 
Long integer 
4 
-2147483648 a 2147483647 
Representado en complemento a dos (Rep. Exacta). 
 
float/single 
4 
10 -38 a  10 38 
Standard IEEE simple precisión (6 dígitos decimales).  
Reales 
Double 
8 
10 -308 a  10 308 
Standard IEEE doble precisión (16 dígitos decimales). 
 
Long Double 
10 
10 -4932 a  10 4932 
Standard IEEE de precisión ext (20 dígitos decimales). 
 
 
 
 
Longitud variable. Interpretado como una agrupación 
Cadena 
 
n 
No numérico 
de CHAR. Algunos lenguajes finalizan la cadena con  
 
 
 
 
el CHAR (0). 
 
 
Ejemplos de declaraciones:
signed char Toto; 
unsigned int Alfa; 
float Beta; 
 
 
BCD
El más difundido de los códigos ponderados para operaciones aritméticas, es el BCD (decimal codificado en 
binario). El código BCD es también llamado 8421, dado que esos son los valores con los cuales se pondera el 
número representado. 
 
Como se notará, con 4 dígitos binarios sería posible representar hasta el número 16, pero solo se codifica hasta el 
número 9, implicando esto que una operación aritmética que produzca un valor superior a 9 quedaría fuera de 
código; a continuación se verá cómo corregir esta situación.
__________________________________________   41   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
La siguiente tabla muestra el código BCD:
Decimal 
Código 
0 
0000 
1 
0001 
2 
0010 
3 
0011 
4 
0100 
5 
0101 
6 
0110 
7 
0111 
8 
1000 
9 
1001 
 
La forma de codificar un número es sumamente sencilla, dado que solo se debe reemplazar cada dígito decimal, 
por su equivalente en binario; por ejemplo: 
 
​
​
               309,15​ ​
​
equivale a:​
3​
0​
9,​
1​
5 
​
​
​
​
​
​
​
           0011        0000     1001,     0001      0101 
Si deseáramos hacer la suma 8 + 6 : 
 
​
​
   8 =   1000 
                          +  6 =    0110 
​
​
           1110 
El resultado a simple vista excede al código, a pesar de que se puede interpretar como 14, expresado en binario, 
pero no debe olvidarse que, quien está haciendo la operación es una máquina que debe entender el resultado en 
términos de un código, con lo cual este resultado aún no es el correcto. 
 
Cuando se produce un exceso de código de este tipo, debe sumarse al resultado obtenido el número 6 (0110), el 
nuevo resultado se encontrará dentro del código. 
 
En el ejemplo dado: 
​
​
                1110 
​
​
             + 0110 
​
​
       0001 0100 
​
​
             1      4  = 14 codificado 
 
Ejemplo: Sumar 128 + 173 = 301 
 
​
​
       128 =   0001 0010 1000 
​
​
  +   173 =   0001 0111 0011 
​
     ​
                    0010 1001 1011           fuera de código  (sumar: + 0110) 
​
​
​
  +                   0110   ​
​
     
   ​
​
​
              1010 0001            
​
​
       ​
​
​
               fuera de código  (sumar: + 0110) 
​
​
​
   +         0110                      
​
​
​
    0011  0000 0001            
                      en decimal:          3​
    0       1
Bandera Digit Carry
Otro ejemplo: 
​
28​
                0010 1000 
          + 49​
             + 0100 1001 
​
77​
                0111  0001         (incorrecto) 
__________________________________________   42   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
En el ejemplo dado: 
​
28​
                0010 1000 
          + 49​
             + 0100 1001             DC=1 
​
77​
                0111  0001         (incorrecto) 
​
​
                          0110 
​
​
                0111  0111 
​
​
                   7       7  = 77 codificado 
 
La regla entonces se reescribe así: 
Cuando se produce un exceso de código o la bandera de Digit Carry se pone a 1, debe sumarse al resultado 
obtenido el número 6 (0110), el nuevo resultado se encontrará dentro del código. 
 
Códigos auto-complementarios
A fin de simplificar la construcción de circuitos que realicen operaciones de suma y resta, se han creado códigos 
que al tener que restar, solo cambiando los 1 por 0 y los 0 por 1, se obtiene el complemento a la base - 1, luego 
operando se obtiene el resultado en binario ya sin codificar. Uno de los códigos más difundidos de este tipo es el 
EXCESO TRES , el cual consta de codificar los dígitos del 0 al 9, sumándole 3. La siguiente tabla lo muestra:
Decimal 
Código 
Decimal 
Código 
0 
0011 
5 
1000 
1 
0100 
6 
1001 
2 
0101 
7 
1010 
3 
0110 
8 
1011 
4 
0111 
9 
1100 
 
Por ejemplo, la resta 9 - 7 = 2, se haría:
​
7 = 1010 => Complemento a la base - 1 = 0101
​
​
         9   =  1100 
​
​
   + (-7)  =  0101 
​
 acarreo            1   ¦  0001 
​
​
                  +    1 
​
​
​
     0010  = 2 (en binario sin codificar) 
Dado que para la resta, se utilizó la suma del complemento a la base - 1, se le debe sumar al resultado obtenido, el 
acarreo, dando así el resultado final.
R.López 1996-2011 
S.Wahler 2019-2025
__________________________________________   43   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 5
COMPUTADORA ELECTRÓNICA DIGITAL
Microprocesadores
En la figura 1, puede observarse un esquema de la estructura interna de un microprocesador. En la figura se 
destaca:
 ​
3 buses (Address, Data y Control) 
 ​
3 bloques (CPU, Memoria Principal y Mapa de Entrada/Salida ) 
Buses
▪​
El bus de Address es de 16 bits. Son líneas exclusivamente salientes. 
▪​
El bus de datos es de 8 bits. Son líneas entrantes o salientes según el flujo de los datos. 
▪​
El bus de Control posee múltiples líneas, algunas entrantes y otras salientes. Son típicas salientes 
RD (read) / WR (write), que indican la lectura o escritura, respectivamente en la zona de memoria o 
en el mapa de IO. La línea M/IO es la que indica ante un direccionamiento, si se efectúa hacía la 
Memoria Principal o al Mapa de Entrada/Salida. La línea INTA, que indica el reconocimiento de una 
interrupción externa desde el Mapa de Entrada/Salida.
Son típicas líneas entrantes: La línea RESET que provoca la inicialización del microprocesador a partir algún
punto de inicio en memoria (POST). Las líneas NMI e INTR, de interrupción, que obligan al procesador a 
ejecutar en otra zona de la memoria de programa determinadas por los vectores de Interrupción.
Memoria Principal
La memoria principal puede interpretarse como celdas consecutivas que poseen la capacidad de albergar un 
Contenido con un formato prefijado. Ese formato típico es de 8 bits (1 byte o carácter).
Cada celda posee una Dirección que la identifica. Se adopta la siguiente convención para identificar las 
direcciones de memoria, por ejemplo: F540h, en hexadecimal (16 bits). Un número con ese formato se refiere a 
una dirección de memoria. Cuando queremos referirnos al contenido de esa dirección, lo indicamos como 
[F540], entre corchetes. La cantidad F540h, hace referencia al Desplazamiento u OFFSET dentro de la memoria.
De esta forma, la expresión:
​
[F540] = 3F              Indica que 3Fh es el contenido de la dirección F540​
En un microprocesador, el espacio direccionable máximo depende del tamaño de sus registros de direcciones. 
Cómo se ve en la figura 1, IP posee 16 bits, por lo cual el espacio direccionable es de 64 Kbyte = 2 16 = 65536 
bytes.
Comúnmente, la memoria principal está subdividida en  Memoria de Programa y Memoria de Datos.
Mapa de Entrada y Salida
Similarmente a la memoria principal son celdas consecutivas que poseen la capacidad de albergar un Contenido 
con un formato prefijado. Ese formato es normalmente de 8 bits (1 byte o carácter). Cada celda posee una 
Dirección identificatoria, a esa dirección se la llama PORT (puerta) ya que es por donde se accede desde la 
periferia al sistema interno del microprocesador. En la figura, también el espacio direccionable máximo depende 
del tamaño de sus registros de direcciones (16 bits), por lo que el espacio direccionable de 64 kbytes = 2 16 = 
65536 bytes.
__________________________________________   44   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Figura 1: Estructura de un microprocesador Genérico
__________________________________________   45   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
CPU
Es la Central Processing Unit (Unidad Central de Proceso) que posee los siguientes bloques básicos:
▪​
Circuitos de tiempo y sincronismo (Clock y Secuenciador). 
▪​
El decodificador de Instrucciones 
▪​
La ALU (Aritmethic – Logic Unit) 
▪​
Registros 
▪​
Registros buffer (Adaptadores electrónicos del Bus) 
 
Los Registros son similares a celdas de memoria pero, dentro del microprocesador, permiten el almacenamiento 
temporal de un contenido. Es posible la transferencia de contenidos entre un par de registros cualesquiera, para 
ello, uno de los registros actúa como fuente y el otro actúa como destino. El contenido del registro fuente se copia 
en el destino, el anterior contenido del destino se destruye pero el contenido del registro fuente permanece 
inalterable.
Los circuitos de tiempo y sincronismo, son aquellos que llevan la cadencia de las instrucciones. El secuenciador 
controlado por un clock de alta frecuencia (100 MHZ o más), efectúa todas las microoperaciones entre registros y 
entre estos y la ALU, para ello, se encarga en todo momento de controlar el flujo de datos abriendo y cerrando las 
compuertas de entrada y salida a los registros, de forma tal que puedan transferirse su contenido a través del Bus 
Interno.
Figura 2: Esquema de detalle de registros 
 
En la figura 2, apreciamos cómo se produce la copia del registro MAR (fuente), sobre el registro AX (destino). 
Para ello, el secuenciador controlado por el reloj, y poniendo las líneas de control correspondientes en 1, abre la 
compuerta de salida de datos del registro MAR y simultáneamente abre la compuerta de entrada de datos del 
registro AX, de forma tal que a través del Bus Interno puedan fluir los datos. Es obvio que mientras ocurre esta 
transferencia, las compuertas de salida y de entrada de los restantes registros conectados al Bus Interno están 
cerradas (líneas de control respectivas en 0).
Sólo es posible efectuar transferencias entre registros de igual tamaño o formato de bits. Esta acción se simboliza 
como:  MAR  →  AX
Todos los registros y la ALU poseen compuertas de entrada y salida de los datos para que pueda ser controlado el 
flujo de estos últimos por el Secuenciador. 
 
El secuenciador está controlado por un reloj con cristal de cuarzo, dicho reloj, emite señales como la que se 
aprecia en la Figura 3. Esta señal posee una frecuencia característica
__________________________________________   46   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Figura 3: Forma de Onda del Clock.
Ciclos
Clock Cycle (Ciclo de reloj)
Es el período T que media entre dos puntos homólogos de pasaje de la Onda. Segmento A en la figura 3. 
El período se define como la inversa de la frecuencia, o sea:  f = 1 / T  
Para una frecuencia de 100 MHZ (100 ciclos por segundo), el periodo es: 
 
​
​
T = 1 / 100,000,000 HZ = 1 / 100,000,000 S –1 = 10 nS = 10 nanosegundos 
 
Como puede observarse en un período existen dos flancos (dos cambios de 0 a 1 o viceversa). Luego, dentro del 
microprocesador puede hacerse que una acción tenga lugar cada vez que ocurre un flanco a efectos que los 
distintos órganos del micro funcionen coordinadamente. En el círculo ampliado de la figura 3, puede observarse 
que en el flanco ascendente se abren las compuertas de los registros de la figura 2 y en el flanco descendente las 
compuertas se cierran, insumiendo un tiempo total de transferencia de 5 nS. En el mismo flanco de bajada, se 
puede efectuar la apertura de compuertas de otro par de registros.
MPU Cycle o Memory Cycle
La memoria es un dispositivo electrónico con una cantidad muy grande de compuertas, necesarias para 
discriminar el elevado número de celdas que contiene (32 Mbytes es normal), cada una con su dirección. La 
operación de estas compuertas - si bien cada una insume un tiempo muy pequeño – tiene un tiempo total que no es 
despreciable si tenemos en cuenta la gran cantidad que deben abrirse y cerrarse para encontrar una celda de 
memoria específica. Se define como Tiempo de Acceso a Memoria (TA), al que media entre el instante en que se 
le suministra una dirección efectiva (EA) a la memoria en el Address Bus, hasta el instante en que el contenido de 
la locación especificada se encuentra en el Data Bus. Este tiempo TA  se mide en nanosegundos, y lo especifica el 
fabricante de la memoria, como el tiempo máximo (de caso peor) en el cual se asegura que la memoria ha de ser 
leída o escrita, en cualquier dirección especificada.
Como en el sistema de microproceso, el tiempo de acceso a memoria es el más importante (la velocidad del 
sistema todo depende de él, ya que las velocidades dentro del microprocesador son mucho mayores), normalmente 
se asocia el ciclo de máquina como el ciclo de memoria o tiempo de acceso.
En nuestro caso, el ciclo de máquina es de 4 ciclos de clock, esto es 40 nS. Luego, para que exista seguridad que 
la memoria sea leída o escrita, se debe utilizar una memoria que posea un TA < 40 nS.
Instruction Cycle
El ciclo de instrucción generalmente está determinado por la cantidad de accesos a memoria que posee la 
instrucción en cuestión. Si tomamos como ejemplo la instrucción: MOV  AX, BX, la misma tiene como código:
__________________________________________   47   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
8B C7 (2 bytes de código).  Luego para leer el código deben efectuarse dos accesos a memoria de programa, 
mientras que la ejecución propiamente dicha de la instrucción insumirá un tiempo despreciable ya que se trata de 
una transferencia entre registros internos de la CPU. En este caso, que es el que se presenta en la Figura 3, el Ciclo 
de Instrucción, comprenderá 2 ciclos de máquina o lo que es lo mismo 8 ciclos de clock.
Un Ciclo de instrucción puede comprender uno o muchos ciclos de máquina. 
Independientemente de ello, el ciclo de instrucción posee siempre dos estados fundamentales en los cuales se 
encuentra el μP, búsqueda o ejecución. Esto es, el μP en todo momento o está buscando una operación para 
ejecutar (FETCH) o la está ejecutando (EXECUTE).
Registros del microprocesador
En la Figura 1 puede observarse que un μP 8088 posee registros denominados visibles. Se llaman registros 
visibles aquellos que pueden ser explícitamente utilizados por el programador a través del Set de instrucciones 
(MOV AX, BX - ADD AX, 3Ah, etc.). También existen un número importante de registros denominados 
invisibles. Se llaman registros invisibles a aquellos que actúan implícitamente en casi todas las instrucciones que 
se cursan en el μP (Cada vez que se busca un contenido en memoria, los registros MAR, MDR, Y y T, deben 
operar).
En nuestro microprocesador hipotético de la Figura 1 se encuentran los registros:
IP: Registro Puntero de Instrucción (en algunos procesadores se denomina PC: Program Counter) que en
todo momento se encuentra apuntando a la siguiente posición de memoria de la que se está 
ejecutando, indicando el derrotero normal del programa. 
SP: Registro puntero que apunta al último byte depositado en la PILA. 
BX: Registro puntero que se utiliza como base en los direccionamientos indirectos de datos 
AX: Registro de propósito general, comúnmente utilizado en las operaciones aritmético – lógicas. 
Flags: registro de FLAGS o STATUS del procesador. Realmente sus celdas de bit funcionan en forma
individual, como banderas indicativas de cierto estado de la CPU, dependiendo del resultado de una 
operación aritmético – lógica. (Cero, Carry, Signo, etc.) 
 
Los registros invisibles que se destacan son:
MAR: Registro interfase con el Address Bus, mantiene efectivamente una dirección en tanto se está
accediendo a memoria. 
MDR: Registro interfase con el Data Bus, mantiene efectivamente un dato en tanto se está accediendo a
memoria para escritura o recibe el dato cuando se trata de una acción de lectura. 
IR: Registro de instrucciones. Es el que retiene el código de operación que se está ejecutando para accionar
el decodificador. 
Y y T: temporarios de entrada y salida de la ALU. Retienen uno de los operandos y el resultado de la
operación, el otro operando entra directamente a través del Bus interno mediante el registro visible 
involucrado en la operación. 
 
Funcionamiento paso a paso de la CPU (microinstrucciones)
Supongamos que se quiere ejecutar el siguiente programa, que tiene como objetivo, sumar dos números de 8 bits, 
devolviendo luego el resultado a memoria. El programa cuenta con las siguientes tres instrucciones. Su código 
Hexadecimal es el que figura en la tabla como contenidos de las direcciones a partir de 0100h. En el ejemplo 
usaremos sentencias de un microprocesador comercial del fabricante INTEL, pero el ejemplo es genérico y con 
suficiente aproximación al comportamiento que tiene un procesador de cualquier fabricante. 
 
#​
Assembler​
​
Simbólico​
​
Código​  
 
1.​
MOV​
AL, 18h​​
; AL  ⇦   18h​
​
B0  18 
2.​
ADD​
AL, BL​​
; AL  ⇦   AL + BL​
02  C3 
3.​
MOV​
[021Dh], AL​
; OpMemo ⇦   AL​
A2 1D  02
__________________________________________   48   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​Dirección 
Cont. 
0100 
B0 
0101 
18 
0102 
02 
0103 
C3 
0104 
A2 
0105 
1D 
0106 
02 
0107 
.. 
0108 
.. 
... 
.. 
... 
.. 
021A 
.. 
021B 
.. 
021C 
.. 
021D 
.. 
021E 
.. 
021F 
.. 
 
 
Si suponemos que IP arranca con un valor 0100h, los micropasos que deberá cumplir el procesador para lograr el 
objetivo, son: 
(Los valores están en hexadecimal. Los micropasos en sombreado corresponden a la etapa de búsqueda 
(FETCH) de cada instrucción, lo NO sombreado corresponde al etapa de ejecución (EXECUTE).
# 1. 
1)​ IP=0100 ⇨ MAR ⇨ Address Bus ⇨MemoProg 
2)​ IP + 1 ⇨ IP  
3)​ retardo 
4)​ [0100] = B0 ⇨ Data Bus ⇨ MDR 
5)​ MDR ⇨ IR  ⇨ Decodificador =  MOV AL, inmed 
6)​ IP=0101 ⇨ MAR 
7)​ IP + 1 ⇨ IP  
8)​ MAR = 0101 ⇨ Address Bus ⇨MemoProg. 
9)​ [0101] = 18 ⇨ Data Bus ⇨ MDR 
10)​ MDR ⇨ AL
# 2. 
1)​ IP=0102 ⇨ MAR ⇨ Address Bus ⇨MemoProg 
2)​ IP + 1 ⇨ IP  
3)​ retardo 
4)​ [0102] = 02 ⇨ Data Bus ⇨ MDR 
5)​ MDR ⇨ IR  ⇨ Decodificador = ADD reg, r/m 
6)​ IP=0103 ⇨ MAR⇨ Address Bus ⇨MemoProg 
7)​ IP + 1 ⇨ IP  
8)​ retardo 
9)​ [0103] = C3 ⇨ Data Bus ⇨ MDR 
10)​ MDR ⇨ EA  ⇨ Decodificador = ADD AL, BL 
11)​ AL ⇨ Y 
12)​ BL ⇨ ALU (ADD) ⇨ T (FLAGS) 
13)​ T ⇨ AL
__________________________________________   49   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
# 3. 
1)​ IP=0104 ⇨ MAR⇨ Address Bus ⇨MemoProg 
2)​ IP + 1 ⇨ IP  
3)​ retardo 
4)​ [0104] = A2 ⇨ Data Bus ⇨ MDR 
5)​ MDR ⇨ IR  ⇨ Decodificador = MOV [nnnn], AL 
6)​ IP=0105 ⇨ ddress Bus ⇨MemoProg  
7)​ IP + 1 ⇨ IP  
8)​ retardo 
9)​  [0105] = 1D ⇨ Data Bus ⇨ MDR ⇨ YL 
10)​ IP=0106 ⇨ ddress Bus ⇨MemoProg  
11)​ IP + 1 ⇨ IP  
12)​ retardo 
13)​ [0106] = 02 ⇨ Data Bus ⇨ MDR ⇨ MARH 
14)​ YL ⇨ MARL 
15)​ MAR=021D  ⇨ Address Bus ⇨MemoData. 
16)​ AL = 18 ⇨ MDR ⇨ Data Bus ⇨ [021D] 
17)​ retardo 
 
FIN del programa. 
  
Observaciones:
 ​
Dentro de una instrucción, la última utilización del decodificador indica la finalización del FETCH y 
comienzo del EXECUTE. La finalización de la instrucción define el comienzo del FETCH de la nueva 
instrucción.
 ​
El registro temporario Y se utiliza a conveniencia (en su parte alta o su parte baja).
R.López 1996-2010 
S.Wahler 2019-2025
__________________________________________   50   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 6
ORGANIZACIÓN DE LA COMPUTADORA
Formatos de Instrucciones
Las instrucciones siempre indican una acción mediante el código de operación (Cop) al que se le asocian: a)
Ninguno, b) uno o c) dos o d) tres operandos explícitos según el caso, respondiendo al formato general 
siguiente: 
 
 
​
​
​
​
|  a) ​
Cop​
(sin operando)                                 ej:  RETURN 
​
​
​
​
| 
INSTRUCCIONES​
|  b) ​
Cop​
op2​
                                           ej:  NEG  Alfa 
​
​
​
​
| 
​
​
​
​
|  c)​
Cop​
op1 , op2                                          ej:   MOV  Alfa, W0 
​
​
​
​
| 
​
​
​
​
|  d)​
Cop​
op1, op2, op3                                    ej:   ADD   W0, W1,W2
Tabla 1: formato general de instrucciones
Op1:​ Operando fuente  (source), permanece invariable con la operación.
Op2:​ Operando destino (destination), donde siempre queda el resultado de la operación y por ende se
modifica respecto a su valor inicial.
Op3:​ Operando destino, sólo cuando hay operando 2 que actúa como fuente (siempre hay un solo operando
destino).
Nota: Cuando los operandos son dos o tres, se los separa con una coma. La posición de los operandos es variable
según el fabricante. Por ejemplo Intel coloca el operando destino a la izquierda de la coma. Otro fabricante 
como Microchip, coloca el operando destino a la derecha. En el recuadro se han utilizado ejemplos del 
fabricante Microchip y como se observa, el operando destino está a la derecha. 
 
Modos de Direccionamiento
Para la obtención de los operandos (op1, op2, op3) los microprocesadores en general utilizan alguno de cuatro 
posibles modos de direccionamiento de operandos, a saber:
IMPLÍCITO  (imp): ​
El Operando no existe o se encuentra en un registro predeterminado (default) de la 
CPU,  no indicado explícitamente en la instrucción.
INMEDIATO (imd): ​ También denominado: literal. Operando incluido en la propia instrucción y que en
consecuencia reside en la memoria de programa (siguiente al Cop). Por quedar fijo 
en el programa, este operando es una constante y siempre va precedida del signo #.
DIRECTO    (dir):     ​ También denominado: file, pues se otorga la dirección de un registro o archivo
(file) de memoria. La dirección efectiva (Efective Address: EA) del operando está 
explícita en la instrucción, siguiente al código de operación. Obsérvese, que lo que 
ahora está fijo en el programa es la dirección del operando, pero el contenido de 
ésta es variable.
INDIRECTO  (ind):​
La dirección efectiva del operando en memoria, se encuentra en un registro 
puntero o se obtiene como suma del contenido de dos  registros punteros o un 
registro puntero y un desplazamiento u offset (los cuales se introducen entre 
corchetes). Por ej.: MOV [W0+#06], W7.
__________________________________________   51   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Obsérvese que un operando tienen en general, tres posibilidades de ubicación dentro de nuestro esquema:
1.​
Está en un registro de la CPU. Por ejemplo en el PC. Esta situación comúnmente está relacionada con el 
direccionamiento implícito y otras veces con el directo. 
2.​
Está en la memoria de programa. Esta situación está relacionada con el direccionamiento inmediato. 
3.​
Está en la memoria de datos. Esta situación está relacionada con un direccionamiento que siempre debe 
aportar una dirección efectiva (EA), ya sea en modo directo o indirecto.
Por otro lado, para la obtención de direcciones de destino en un salto (sólo en instrucciones de Control de 
programa), algunos procesadores utilizan el siguiente modo de direccionamiento de saltos:
RELATIVO    (rel):  ​
La dirección de destino de salto se obtiene adicionando un desplazamiento al PC 
actual. Este desplazamiento u  offset,  puede estar dado en la propia instrucción 
(adoptar un valor entero cualquiera positivo o negativo, en complemento a 2) o 
estar predeterminado con valor 2, donde el PC salta dos posiciones (skip), 
pudiendo dejar una instrucción sin ejecutar. La denominación de relativo proviene 
del hecho que la posición obtenida para el salto es dependiente (relativa) a la 
posición del PC.
Seudo-Operandos
Los seudo-Operandos no son instrucciones del Assembler. No obstante, se escriben en los programas pero se 
encargan de otorgarle instrucciones al propio Ensamblador, para que efectúe acciones conforme a lo que desea el 
programador.
Utilización de las etiquetas
Las etiquetas tienen una amplia utilización en la escritura de programas en distintos lenguajes. En Assembler las 
etiquetas siempre pueden asociarse a cantidades numéricas.
Seudo-Operando .EQU
El uso más corriente de una etiqueta es asociar un valor numérico a una cadena de caracteres. El valor numérico 
puede interpretarse tanto como una Dirección o como un Dato (Contenido de una dirección o Registro), esto se 
hace con el Seudo-Operando EQU (Equate=Igualar) de la siguiente forma:
​
​
.EQU ​ DirOperando,​
0x10F4
​
​
.EQU ​ SaldoCaja,​
62
Este Operando efectúa una asignación. Esto es, asigna a la Etiqueta: DirOperando el valor: 0x10F3.
Como puede apreciarse, una etiqueta puede conformarse mediante cualquier agrupación de caracteres (cadena) 
excepto espacios y algunos caracteres especiales: /, =,&. (Conviene generalmente emplear letras del abecedario, 
mayúsculas o minúsculas).
En este caso, cuando en el texto Assembler aparezca la cadena: DirOperando el Ensamblador la sustituirá por su 
equivalente: 0x10F3 (Efectúa una sustitución de los caracteres). Ejemplo:
​
MOV​
#SaldoCaja, W1
​
MOV​
DirOperando, W3        (La única condición es que la dirección sea par)
Nótese el carácter de constante que otorga el comando EQU al valor que se asigna. La ventaja consiste en que si 
se utiliza dentro del programa el SaldoCaja, cuando se quiera cambiar su valor, sólo habrá que hacerlo en la 
asignación (Con EQU) , y automáticamente la nueva asignación efectuará el cambio en el resto del programa. El 
compilador al hacer al análisis línea por línea reemplazará por el nuevo valor asignado.
__________________________________________   52   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Seudo-Operandos .word, .byte y .Space
La utilización de estos operandos es un poco más compleja. Estos operandos sólo definen direcciones, asociándole 
a cada una, una cadena de caracteres que la identifica. El Seudo-Operando .word  se utiliza de la siguiente forma:
​
Resultado:​
.word ​ 0x0B6A        (1)
Beta:​
.byte ‘C’, ‘D’            (2)
​
Beta:​
.space 4​ (3)
En el primer ejemplo (1)  se efectúan tres acciones implícitas:
a)​ Se reserva una dirección de memoria de tamaño de 2 bytes (1 word).
b)​ Resultado asume el valor de la dirección de la locación base. Resultado es puntero a la mencionada
dirección.
c)​ Se carga la locación definida con el valor 0x0B6A.
Si ahora se efectúa la siguiente instrucción:
​
MOV​
Resultado, W3
Se cargará en W3 el contenido de la dirección de memoria a la que apunta Resultado. Si Resultado hubiera sido 
definida con un EQU (y además la precediéramos con #), en W3 se cargaría el valor constante asignado por 
EQU.
En el segundo ejemplo (2) sucede algo equivalente al primero:
a)​ Se reservan dos posiciones consecutivas de memoria cada una de tamaño 1 byte.
b)​ Beta asume el valor de la dirección de la Primera locación. Beta es puntero a la mencionada dirección.
c)​ Se carga cada locación con los códigos ASCII de cada uno de los caracteres entre comillas, separados por
comas. (contenido de la 1º dirección: ‘C’, contenido de la 2º dirección: ‘D’)
Por último, en el tercer ejemplo (3) se reserva una cantidad de bytes en memoria equivalentes al número a 
continuación del seudo-operando .SPACE. Sucede algo equivalente al primer ejemplo sólo que en lugar de cargar 
las posiciones de memoria con un carácter definido, la carga con el valor: 0 (cero).
Nota: Muchos de los direccionamientos que se pueden usar con etiquetas en la instrucción MOV, en general 
no funcionan en aritmético lógicas como ADD, SUB, AND, etc. En lo que sigue se otorgan algunos ejemplos 
de sintaxis de instrucciones que no son válidas. 
. Ejemplo: 
 
.equ delta, 0x000C 
alfa:      .WORD   0,0 
​
 mov    W0,    alfa​
;correcto 
 ;mov        W0, [delta]      ESTO NO SE PUEDE 
 ;mov        W0, [#alfa]      ESTO NO SE PUEDE 
 ;add        W0, alfa, W2      ESTO NO SE PUEDE
Conclusiones
Podrían definirse tres momentos o Tiempos que son trascendentes en la vida de un programa:
Tiempo de Edición: Cuando el programador está escribiendo el Programa Fuente.
Tiempo de Ensamblado o Compilación: Cuando se crea el Programa Objeto.
Tiempo de Ejecución: Cuando el código del programa reside en RAM y es ejecutado por la CPU, situación en el 
cual ya es un Proceso. Se llama Proceso al programa que está siendo ejecutado por la CPU, para lo cual 
obviamente debe residir en la Main Memory.
Para aclarar la diferencia existente entre un .EQU y el resto de las definiciones vistas, debe tenerse en cuenta lo 
siguiente: El EQU lo define el programador cuando edita, el valor o la dirección de memoria que se asigna a la
__________________________________________   53   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
etiqueta queda constante y no depende del resultado del Ensamblado ni tampoco de la ejecución. Este valor quedó 
definido en tiempo de EDICIÓN del programa.
Con .byte, .word o .Space el programador define el Nombre de la ETIQUETA en la edición, pero la DIRECCIÓN 
a la que ésta siempre queda asociada, va a quedar definida como consecuencia del ensamblado de un programa. 
Esa dirección va a ser Variable cuando el Programador edita el programa, pero va a quedar como una Constante 
cuando el programa sea ensamblado.
Obviamente, el contenido de la dirección a la que apunta cualquier etiqueta tiene un carácter variable tanto en 
tiempo de Edición como de ensamblado. Su valor se fija en tiempo de ejecución.
La siguiente tabla ilustra sobre la comparativa efectuada:
Estado del Valor definido 
Forma de la definición de Etiqueta 
En edición 
En Compilación 
En Ejecución
Dato o Dirección definido con EQU 
Fijado 
Fijado 
Fijado
Dirección definida con .byte,.word .Space 
Variable 
Fijado 
Fijado 
Dirección definida en el Código 
Variable 
Fijado 
Fijado 
Contenido de una Dirección Definida con las 
anteriores 
Variable 
Variable 
Fijado
R.López 1996-2013 
S.Wahler 2019-2025
__________________________________________   54   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 7
FUNCIONALIDAD DE MICROPROCESADORES
​
 
Microcontroladores PIC24 y dsPIC33
Los PIC (Peripheral Interface Controller) de estas familias son microcontroladores CMOS FLASH de 16 bits de 
arquitectura RISC (Reduced Instruction Set Computer - Computadora con un Conjunto Reducido de Instrucciones) 
diferenciándose así de los CISC (Complex Instruction Set Computing utilizados por toda la familia Intel x86). Esta 
definición no es tan rigurosa dado que el set RISC recibe permanentemente ampliaciones. No obstante, tal 
denominación se sigue utilizando dado que las instrucciones a pesar de ser muy variadas, se siguen ejecutando en 
general en un ciclo de clock.
Características
​
La familia tiene importantes características como:
- Procesador tipo RISC (Procesador con un Conjunto Reducido de Instrucciones). 
- Procesador segmentado. 
- Arquitectura HARVARD. 
- Arquitectura orientada al uso de Lenguaje C. 
- Memoria de programa lineal hasta 88K instrucciones. 
- Memoria de datos hasta 32Kbytes. 
- Instrucciones de 24 bits y datos de 16 bits. 
- Niveles de prioridad para las interrupciones. 
- Capacidad de proceso de 40MIPS (aunque esto está en continuo aumento) 
- Las instrucciones se ejecutan en un sólo ciclo de máquina excepto los saltos (bra, goto y 
call), que requieren 2 ciclos. Aquí hay que especificar que un ciclo de máquina en general 
lleva 4 ciclos de reloj, si se utiliza el reloj interno de 4MHz, los ciclos de máquina se 
realizarán con una frecuencia de 1MHz, es decir que cada instrucción se ejecutará en 1uS 
(microsegundo). 
- Temporizadores. 
- Manejo de Stack (pila).​
 
- Módulos de comunicación serie, comparadores, PWM. 
 
Debido a la necesidad de conseguir elevados rendimientos en el proceso, se ha desembocado en el empleo 
generalizado de procesadores de arquitectura Harvard frente a los tradicionales que seguían la arquitectura de von 
Neumann.
Arquitectura von Neumann
Su característica principal es que la CPU se conecta con una memoria única, donde coexisten datos e 
instrucciones, a través de un sistema de buses.
Figura 1: Arquitectura von Neumann
__________________________________________   55   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Arquitectura Harvard
En la arquitectura Harvard son independientes la memoria de instrucciones y la memoria de datos y cada una 
dispone de su propio sistema de buses para el acceso. Esta dualidad, además de propiciar el paralelismo, permite la 
adecuación del tamaño de las palabras y los buses a los requerimientos específicos de las instrucciones y de los 
datos.
Figura 2: Arquitectura Harvard 
La separación de los dos tipos de memoria son los pilares de la arquitectura Harvard, esto permite acceder en 
forma simultánea e independiente a la memoria de datos y a la de instrucciones de programa. El tener memorias 
separadas permite que cada una tenga el ancho y tamaño más adecuado. En estas familias el ancho del bus de datos 
es de 16 bits, mientras que el bus de instrucciones es de 24 bits. Los buses de direcciones son de 16 bits para la 
memoria de datos y 23 bits para la memoria de programa.
Procesador tipo RISC y Segmentado
El procesador de los modernos microcontroladores responde a la arquitectura RISC (Computadores de Juego de 
Instrucciones Reducido), que se identifica por poseer un repertorio de instrucciones máquina pequeño y simple, de 
forma que la mayor parte de las instrucciones se ejecutan en un ciclo de instrucción.
Otro aporte que aumenta el rendimiento del computador es el fomento del paralelismo implícito, que consiste en la 
segmentación del procesador (pipe-line), descomponiéndolo en etapas para poder procesar una instrucción 
diferente en cada una de ellas y trabajar con varias a la vez. Con la estructura segmentada se pueden realizar 
simultáneamente las dos fases en que se descompone cada instrucción, ejecución de la instrucción y búsqueda de 
la siguiente.
Otra característica de los PIC es el manejo de los bancos de registros. En línea general, los registros se clasifican 
como de uso general (GPR) y de uso específico o de funciones especiales (SFR).
Los registros de uso general (es la zona R/W del programador) pueden ser usados directamente por el usuario, sin 
existir restricciones. Pueden servir para almacenar resultados que se reciben desde los registros de trabajo W (hay 
16 de ellos, de W0 a W15), datos que provienen de las puertas de entradas, etc.
Los registros de uso específicos no pueden ser usados directamente por el usuario. Estos registros controlan 
prácticamente todo el funcionamiento del microcontrolador, pues toda la configuración necesaria para 
funcionamiento del microcontrolador es hecho a través de algún tipo de SFR. 
Puertos
El microcontrolador posee puertos paralelos, en general de 16 bits, que se compatibilizan (multiplexión) con 
terminales de entrada y salida de otros dispositivos embebidos. Las siguientes son condiciones generales que 
cumplen alguno o todos los terminales de los puertos:
-​
Los pines de los puertos son bidireccionales y manejan señales de 0 a 5V. 
-​
Algunos pines del PORTA PORTB, también pueden ser utilizados como entradas analógicas. 
-​
Los pines RB0-RB15 se puede utilizar también como entrada de pulsos para provocar una interrupción 
externa.
Otros pines
-​
VDD: Pin de alimentación positiva. De 2 a 5,5 Vcc. 
-​
VSS: Pin de alimentación negativa. Se conecta a tierra o a 0 Vcc. 
-​
MCLR: Master Clear (Reset). Si el nivel lógico de este terminal es bajo (0 Vcc), el microcontrolador 
permanece inactivo. Este Reset se controla mediante la palabra de configuración del PIC.
-​
OSC1/OSC2: Entrada de oscilador externo.
__________________________________________   56   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Figura 4. Organización interna.
__________________________________________   57   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​Organización de la memoria
La familia PIC24, dsPIC30 y dsPIC33 tiene 2 bloques de memoria:
- Memoria de Programa Flash/Rom. 
- Memoria de Datos RAM. 
 
Las memorias de datos y de programa tienen buses separados, lo que permite accesos a ambas zonas en un mismo 
ciclo de máquina.
Memoria de Programa
La familia posee un contador de programa (PC) de 23 bits, lo que permite direccionar hasta 4MWords de memoria 
de programa (4 MInstrucciones), aunque los distintos integrantes de la familia tienen siempre instalada una 
cantidad bastante menor. El bit menos significativo del PC siempre es CERO (solo direcciona posiciones pares).
El vector de Reset se encuentra en la dirección 0x0002, mientras que los vectores de Interrupción se encuentran 
entre las direcciones 0x0004 y la 0x01FF.
Figura 5. Organización de la Memoria de Programa de un componente de la familia de 16 bits.
Como puede apreciarse en la figura 5, cada instrucción se inicia en una dirección par. Como el tamaño de cada 
celda de la memoria de programa es de 16 bits, cada instrucción ocupa dos palabras de 16 bits, esto es 32 bits. No
__________________________________________   58   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
obstante, como de estos sólo son necesarios 24 bits, los 8 bits de mayor peso de la dirección impar no se utilizan y 
siempre están en CERO (Se lo denomina byte fantasma). Además, para asegurarse que siempre se comienza la 
lectura por una posición par, el bit menos significativo del bus de direcciones de programa siempre está en CERO.
Figura 6. Organización de la Memoria de Programa.
SP (Stack Pointer)
Es el registro puntero de la Pila del microcontrolador (implícitamente es el registro de trabajo W15). Su utilización 
es automática, ya que el PC se introduce en la pila durante la ejecución de una instrucción CALL o de una 
interrupción, y se extrae de la pila durante la ejecución del retorno correspondiente
Figura 7. Mapa de los registros de funciones especiales más importantes.
__________________________________________   59   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
La pila habitualmente se la ubica en la zona de los GPR, luego de la zona de variables definidas por el programa. 
La pila crece hacia las direcciones ascendentes. El programador puede fijar el punto de inicio del Stack Pointer.
Memoria de Datos
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
Registro STATUS
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
Nota: Para  borrow, la polaridad es invertida. Una sustracción es ejecutada sumando el complemento a 2 del
segundo operando. Para las instrucciones de rotación (RRF, RLF), este bit es cargado con 
cualquiera de los bits 3 o 4 del registro fuente. 
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
__________________________________________   60   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Manejo de Puertos
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
Interrupciones
Una interrupción es un evento que hace que el microcontrolador deje de ejecutar la tarea que está realizando para 
atender dicho acontecimiento y luego regrese y continúe la tarea que estaba realizando antes de que se presentare 
la interrupción.
Las familias de 16 bits tienen múltiples fuentes de interrupción tanto internas como externas, y proporcionan 
prioridad de interrupciones que permite a las fuentes de interrupción ser asignadas a un nivel de prioridad alto o a 
un nivel bajo (prioridad 0 a 7). Cada fuente de interrupción tiene un vector de interrupción. Ese vector se encuentra 
entre las direcciones 0x0004 y 0x00FE y su tamaño es de 2 words. En dicho vector se guarda en el momento de 
compilación la dirección de inicio de la rutina de servicio que trata la interrupción. Esta rutina de servicio es 
similar a una subrutina convencional, pero su función es la de contener el programa que se ejecutará cuando la
__________________________________________   61   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
interrupción ocurra. Los eventos de interrupción de alta prioridad interrumpirán cualquier interrupción de baja 
prioridad que se encuentre en progreso.
En general las fuentes de interrupción tienen tres grupos de bits para controlar su operación. El Bit de Habilitación 
que permite habilitar una interrupción específica. Los bits de Prioridad para seleccionar el nivel de prioridad bajo 
(CERO) o bajo (7). El Bit de Flag para identificar cuál es la interrupción que ha ocurrido.
La dirección de retorno es colocada automáticamente en la Pila (stack) y el PC es cargado con la dirección 
contenida en el vector de interrupciones correspondiente a la INT en cuestión. Una vez en la Rutina de Servicio de 
la Interrupción, el Flag de interrupción correspondiente debe ser puesto a 0, antes de volver al programa principal 
ya que si no se lo hace se causarán interrupciones recursivas.
Figura 9. Esquema general de Interrupciones en un PIC típico.
Fuentes de Interrupción
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
__________________________________________   62   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Fases de una interrupción
Se expone ordenadamente la secuencia de acciones que se llevan a cabo cuando se atiende a una interrupción.
1.​
Si la interrupción está habilitada con su bit en 1 en el IEC correspondiente y si la prioridad está 
establecida en un valor SUPERIOR a la prioridad del procesador, se puede activar la interrupción.
2.​
 El flag de STATUS de dicha causa se pone en alto.
3.​
El valor actual del PC se guarda en la Pila. Juntamente con él se guardan los flags DC, OV, C, N y Z del 
SR. Estos datos ocupan DOS Words en la pila (O sea que el SP queda apuntando a cuatro posiciones más 
delante de la que se encontraba antes del llamado).
4.​
El PC se carga con el valor existente en el  vector de interrupción correspondiente.
5.​
Se entra en la rutina de servicio de la interrupción en cuestión.
6.​
Se debe borrar la bandera por software, antes de realizar el retorno.
7.​
Cuando se llega a la última instrucción de la rutina de interrupción, que es normalmente RETFIE 
(retorno de interrupción), se carga en el PC el valor que inicialmente se guardó en la Pila.
R.López 2008-2011 
S.Wahler 2008-2025
__________________________________________   63   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 8
SET DE INSTRUCCIONES REDUCIDO
Mnemónico 
Operandos 
Descripción 
Ciclos 
Estados Afectados 
ADD 
f 
f + WREG = f 
1 
C, DC, Z, OV, N 
ADD 
Wb,Ws,Wd 
Wb + Ws = Wd 
1 
C, DC, Z, OV, N 
ADD 
#lit10,Wn 
#lit10 + Wd = Wd 
1 
C, DC, Z, OV, N 
AND 
Wb,Ws,Wd 
Wb And Ws = Wd 
1 
Z, N 
BCLR 
f, #bit4 
Borrado de Bit de f 
1 
Ninguno 
BSET 
f, #bit4 
Seteado de Bit de f 
1 
Ninguno 
BTSC 
f, #bit4 
Testea Bit en f, Salta si Borrado 
1 (2 o 3) 
Ninguno 
BTSS 
f, #bit4 
Testeo Bit en f, Salta si Seteado 
1 (2 o 3) 
Ninguno
BRA 
C, etiq 
Salto si Carry 
1 (2) 
Ninguno
BRA 
N, etiq 
Salto si Negativo 
1 (2) 
Ninguno
BRA 
NC, etiq 
Salto si No Carry 
1 (2) 
Ninguno
BRA 
NN, etiq 
Salto si No Negativo 
1 (2) 
Ninguno
BRA 
NOV, etiq 
Salto si No Overflow 
1 (2) 
Ninguno
BRA 
NZ, etiq 
Salto si No Zero 
1 (2) 
Ninguno
BRA 
OV, etiq 
Salto si Overflow 
1 (2) 
Ninguno
BRA 
etiq 
Salto Incondicional 
2 
Ninguno
BRA 
Z, etiq 
Salto si Zero 
1 (2) 
Ninguno 
CLR 
f 
Borra f 
1 
Ninguno 
CLR 
Ws 
Borra Ws 
1 
Ninguno 
COM 
f 
Complementa f 
1 
Z, N 
COM 
Ws,Wd 
Complementa Ws.Se guarda en Wd 
1 
Z, N  
CP 
Wb,Ws 
Compara Wb con Ws (Wb–Ws) 
1 
C, DC, Z, OV, N 
CP0 
Ws 
Compara Ws con 0 
1 
C, DC, Z, OV, N 
DEC 
f 
Decrementa f en uno 
1 
C, DC, Z, OV, N 
DEC 
Ws,Wd 
Ws – 1 = Wd 
1 
C, DC, Z, OV, N 
DEC2 
f 
Decrementa f en 2 
1 
C, DC, Z, OV, N 
DEC2 
Ws,Wd 
Ws – 2 = Wd 
1 
C, DC, Z, OV, N 
GOTO 
n 
Ir a: Dirección               (2 palabras) 
2 
Ninguno 
INC 
f 
Incrementa f en uno 
1 
C, DC, Z, OV, N 
INC 
Ws,Wd 
Ws+1 = Wd 
1 
C, DC, Z, OV, N 
INC2 
f 
Incrementa f en 2 
1 
C, DC, Z, OV, N 
INC2 
Ws,Wd 
Ws+2 = Wd 
1 
C, DC, Z, OV, N 
IOR 
Wb,Ws,Wd 
Wb IOR  Ws = Wd 
1 
Z, N 
MOV 
#lit16,Wn 
Mueve 16 bits a Wn 
1 
Ninguno 
MOV 
Ws, Wd 
Movimiento entre registros 
1 
Ninguno 
MOV 
f, W0 
Movimiento de file a registro W0 
1 
Z, N 
MOV 
f, Wn 
Movimiento de file a registro 
1 
Ninguno 
MOV 
Wn, f 
Movimiento de registro a file 
1 
Ninguno 
MUL 
f 
W3:W2 = f * W0 
1 
Ninguno 
NEG 
f 
Negación de f (comp 2) 
1 
C, DC, Z, OV, N 
NEG 
Ws, Wd 
Niega Ws(comp 2)Se guarda en Wd 1 
C, DC, Z, OV, N 
NOP 
— 
No Operación 
1 
Ninguno
RCALL 
etiq 
Llamada a Subrutina   
2 
Ninguno 
RLC 
Ws, Wd 
Rota a Izquierda a través del Carry 
1 
C, Z, N 
RRC 
Ws, Wd 
Rota a Derecha a través del Carry 
1 
C, Z, N 
RETFIE 
— 
Retorno de Interrupción 
2 
Ninguno 
RETURN 
— 
Retorno de Subrutina 
2 
Ninguno 
SUB 
f, Wn 
Substrae. Wn = f - Wn 
1 
C, DC, Z, OV, N 
SUB 
Wb,Ws,Wd 
Wb - Ws = Wd 
1 
C, DC, Z, OV, N
SWAP             Wn 
Wn = intercambia bytes de  Wn           1 
Ninguno 
XOR 
Wb,Ws,Wd 
Wb XOR Ws = Wd 
1 
Z, N
__________________________________________   64   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Análisis detallado de las Instrucciones más relevantes
Notación: 
f: file. Alude a una dirección de 16 bits de la memoria RAM del procesador. Ej: 0x089F. 
#: Indica que los caracteres que siguen deben tomarse como un dato inmediato. Tales caracteres pueden ser un 
número o una etiqueta. Ej: #0x2F, #33, #alfa. 
Ws: Es el registro que actúa como fuente en la operación. 
Wb: Cuando existen dos registros fuente Wb también actúa como fuente. 
Wd: Es el registro destino de la operación. 
Wn: Es cualquiera (Wb, Ws, Wb) de los registros anteriores, registros W0 a W15.  
[ ]: Indica que lo que se encuentra entre corchetes debe ser interpretado como una dirección de 16 bits de la 
memoria RAM. Ej: [W0], [W5+W7], [W2+#34]
__________________________________________   65   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
INSTRUCCIONES DE TRANSFERENCIA
Las instrucciones de transferencia poseen dos operandos. Efectúan la copia del contenido del operando fuente 
(izquierda), al operando destino (derecha), sin alterar al primero. 
 
Instrucción MOV
Mueve el contenido de la fuente al destino. El registro STATUS no se altera en general.
MOV: Cargar literal en W 
Sintaxis:     MOV #k, Wn 
Operandos: 0 ≤ k  ≤ 0xFFFF 
Operación:      k ⇒  Wn 
Flags afectados: Ninguno 
 
Descripción: El literal k pasa al registro W. 
 
Ejemplo:  MOV  #0x5A27, W3 
 
Antes: W3 = 0x33FF​
​
​
​
     ​
Después:  W 3= 0x5A27
MOV:  Mover W a f
Sintaxis:     MOV Wn,  f 
Operandos: 0 ≤ f  ≤ 0xFFFF 
Operación:      Wn ⇒ f 
Flags afectados: Ninguno 
 
Descripción: El contenido del registro Wn pasa el registro f. 
 
Ejemplo:   MOV W5, 0x326F 
 
 Antes: W5 = 0x33FF - [0x326F] = 0x124F​ ​
​
 Después: W5 = 0x33FF - [0x326F] = 0x33FF
MOV.B:  Mover literal al byte bajo de Wn
Sintaxis:    MOV.B  #k, Wn 
Operandos: 0 ≤ k  ≤ 0xFF 
Operación:      k ⇒ Wn 
Flags afectados: Ninguno 
 
Descripción: El literal k se mueve al byte bajo registro f.  
 
Ejemplo:       MOV.B  #5, W7 
Antes: W7 = 0x0233​
​
​
 ​
Después: W7 = 0x0205
R.LOPEZ – 2008/2018 
S.WAHLER – 2008/2020
​
__________________________________________   66   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 9
INSTRUCCIONES ARITMÉTICO LÓGICAS
Son instrucciones que básicamente modifican los contenidos de registros o posiciones de memoria de destino, de 
acuerdo a la operación que se trate. En general también modifican el registro STATUS. 
 
Instrucción ADD
Suma el contenido de la fuente al destino y el resultado se transfiere al destino. El registro STATUS se actualiza 
acorde al resultado en el destino.
ADD: Suma  literal (10 bits no signado) a W
Sintaxis:     ADD  #k, Wn 
Operandos: 0 ≤ k ≤ 1023 
Operación: :    Wn + k ⇒ Wn 
Flags afectados: N, OV, C, DC, Z 
 
Descripción: Suma el contenido del registro W y k, guardando el resultado en W. 
 
Ejemplo:           ADD #0x0115, W8 
    
Antes: W8 = 0x0010​
​
   ​
​
Después: W8 = 0x0125
ADD: Suma Wb a Ws
Sintaxis:   ADD​ Wb, Ws, Wd 
Operandos:  0 ≤ Wn  ≤ 0xFFFF 
Operación:    Wb + Ws ⇒ Wd 
Flags afectados: N, OV, C, DC, Z 
 
Descripción: Suma el contenido del registro Wb y el registro Ws. El resultado se almacena en Wd. 
 
Ejemplo:           ADD  W0, W1, W2 
 
 Antes: W0 =  0x0017 -  W1 = 0x00C2 – W2 = 0x2233​
   Después: W2 = 0x00D9
Instrucción SUB
Resta el contenido de la fuente al destino y el resultado se transfiere al destino. El registro STATUS se actualiza 
acorde al resultado en el destino.
SUB:  Resta literal (10 bits no signado) a W
Sintaxis:     SUB  #k, Wn 
Operandos: 0 ≤ k ≤ 1023 
Operación:      Wn - k ⇒ Wn 
Flags afectados: N, OV, Z, C, DC 
 
Descripción: Mediante el método del complemento a dos el literal es restado a W. El resultado se almacena en W.
__________________________________________   67   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Ejemplos:                SUB​  0x0002, W3  
Antes:W3 = 0x0003,C=?.​  ​
​
Después: W= 0x0001, C=1 
Antes:W3 = 0x0002,C=?. ​​
​
Después: W= 0, C=1 
Antes:W3 = 0x0001,C=?.​ ​
​
Después:W= 0xFFFF, C=0 ​
  (El resultado es negativo)
SUB: Resta Ws aWb
Sintaxis:     SUB  Wb, Ws, Wd 
Operandos:  0 ≤ Wn  ≤ 0xFFFF 
Operación:     Wb - Ws ⇒ Wd 
Flags afectados: N, OV, Z, C, DC 
 
Descripción: Mediante el método del complemento a dos el contenido de Ws es restado al de Wb. El resultado se 
almacena en Wd. 
 
Ejemplos:                SUB  W1, W2, W3 
 
Antes: W1 = 03h, W2 = 02h, C = ?​​
Después:  W3=01h, C=1 
Antes: W1 = 02h, W2 = 02h, C = ?​​
Después: W3=00h  C= 1 
 
 
Instrucción INC y DEC
Adiciona / Resta 1 al contenido del destino y el resultado se transfiere al destino. El registro STATUS se actualiza 
acorde al resultado en el destino.  
 
Instrucción INC2 y DEC2
Adiciona / Resta 2 al contenido del destino y el resultado se transfiere al destino. El registro STATUS se actualiza 
acorde al resultado en el destino.
INC: Incremento de Ws
Sintaxis:  INC Ws, Wd 
Operandos: 0 ≤ Ws  ≤ 0xFFFF 
Operación: :    Ws + 1 ⇒ Wd 
Flags afectados:   C, DC, N, OV, Z 
 
Descripción: Incrementa en 1 el contenido de Ws. El resultado se almacena en Wd. 
 
Ejemplo: :           INC  W2,W2 
 
   Antes: W2 = 0xFFFF, Z = 0​
   Después: W2 = 0, Z = 1 
Instrucción COM,  NEG y CLR
Com complementa a 1 (cambia ceros por unos y unos por ceros) el contenido del registro destino. Neg 
complementa a 2 el contenido del registro destino. Clr pone a cero el contenido del registro destino. El registro 
STATUS se actualiza acorde al resultado en el destino.
__________________________________________   68   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
COM: Complemento a 1 de Ws
Sintaxis:  COM Ws, Wd 
Operandos: 0 ≤ Ws  ≤ 0xFFFF 
Operación: :    Ws ⇒ Wd 
Flags afectados:   N, Z 
 
Descripción: Complementa a 1 el contenido de Ws. El resultado se almacena en Wd. 
 
Ejemplo: :           COM  W2,W5 
 
   Antes: W2 = 0xFF00, N = 1​
   Después: W5 0x00FF, N = 0, Z = 0
NEG: Complemento a 2 de Ws
Sintaxis:  NEG Ws, Wd 
Operandos: 0 ≤ Ws  ≤ 0xFFFF 
Operación: :    C2 Ws ⇒ Wd 
Flags afectados:   C, DC, N, OV, Z 
 
Descripción: Complementa a 2 el contenido de Ws. El resultado se almacena en Wd. 
 
Ejemplo: :           NEG  W3,W7 
 
   Antes: W3 = 0xFF00​
   Después: W7 0x0100
CLR: Limpieza de registros Ws, f
Sintaxis:  CLR Ws 
Operandos: 0 ≤ Ws  ≤ 0xFFFF 
Operación: :    0 ⇒ Wd 
Flags afectados:   Ninguno 
 
Descripción: Pone a cero el contenido Ws o de un file. 
 
Ejemplo: :           CLR  0x234A 
 
   Antes: (0x234A) = 0xFF00​
   Después: (0x234A) = 0x0000 
 
Instrucciones RLC,  RRC, RLNC y RRNC
Rotan a izquierda o derecha (respectivamente) el contenido del registro destino, incluyendo o excluyendo al carry 
en la rotación. El registro STATUS se actualiza acorde al resultado en el destino.
RLC: Rotación a la izquierda de Ws (con carry)
Sintaxis:  RLC Ws, Wd 
Operandos: 0 ≤ Ws  ≤ 0xFFFF 
Operación: :    Rot Ws ⇒ Wd 
Flags afectados:   C, N y Z 
 
Descripción: Rota el contenido Ws incluyendo al carry. El resultado se acumula en Wd y el carry.
__________________________________________   69   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Ejemplo: :           RLC W2, W5 
 
   Antes: W2 = 0x0F00, C=1 ​
   Después: W5 = 0x1E01, C=0
RRNC: Rotación a la derecha de Ws (sin carry)
Sintaxis:  RRNC Ws, Wd 
Operandos: 0 ≤ Ws  ≤ 0xFFFF 
Operación: :    Rot Ws ⇒ Wd 
Flags afectados:   C, N y Z 
 
Descripción: Rota el contenido Ws, NO incluyendo al carry. El resultado se acumula en Wd y el carry. 
 
Ejemplo: :           RRNC W2, W5 
 
   Antes: W2 = 0x0F00, C=1 ​
   Después: W5 = 0x0780, C=1 
​
 
Instrucciones lógicas de dos operandos
Las instrucciones lógicas de dos operandos son AND, IOR y XOR. Las mismas responden a la tabla de verdad ya 
conocida entre pares de bits. Se otorga el ejemplo de la operación AND entre un par de registros. Las otras 
operaciones tienen un comportamiento equivalente.
AND: Función Y entre Wb y Ws
Sintaxis:   AND​ Wb, Ws, Wd 
Operandos:  0 ≤ Wn  ≤ 0xFFFF 
Operación:    Wb & Ws ⇒ Wd 
Flags afectados: N y  Z 
 
Descripción: Efectúa Y lógico del registro Wb y el registro Ws. El resultado se almacena en Wd. 
 
Ejemplo:           AND  W0, W1, W2 
 
 Antes: W0 =  0x0017 -  W1 = 0x00C2 – W2 = 0x2233​
   Después: W2 = 0x0002
R.López 2008-2018 
S.Wahler 2008-2020
__________________________________________   70   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 10
INSTRUCCIONES DE CONTROL
​
 
Instrucciones de Control del programa
Son instrucciones cuyo objetivo básico siempre es modificar el contenido del PC, a efectos de cambiar el curso 
del programa. No modifican los Flags del registro STATUS.
Instrucciones de Salto Incondicional
Instrucciones BRA y GOTO
El formato general es:  BRA  etiqueta y GOTO etiqueta 
La instrucción BRA (GOTO) tiene como objetivo efectuar un salto incondicional a otro punto del programa 
principal, cuya posición está indicada por una etiqueta. La etiqueta tiene un valor equivalente a la nueva dirección 
por donde continúa la secuencia. En general, cualquier nombre es admitido para las etiquetas.  
La dirección de destino se obtiene sumando al PC actual, un valor de desplazamiento que se calcula a partir de un 
valor que figura en el código de la operación. 
La instrucción BRA utiliza modo de direccionamiento RELATIVO. El desplazamiento puede ser positivo o 
negativo y se calcula de la siguiente forma:
PC = PC + 2 + (2 * n) 
Donde n indica la cantidad de instrucciones que se saltean a partir de la siguiente.
BRA: Salto incondicional RELATIVO 
 
 
Sintaxis:  BRA  n 
Operandos:  -32768 ≤  n  ≤ 32767 
Operación:   PC+2+2 n ⇒ PC 
Flags afectados: Ninguno 
 
Descripción: Se trata de un salto incondicional. Ocupa 2 ciclos de reloj. La posición de destino depende de la 
actual posición que tiene el PC.  
 
Ejemplo: ORIGEN BRA DESTINO 
 
   Antes: PC = ORIGEN+2​
​
   Después: PC = DESTINO
GOTO:​Salto incondicional DIRECTO 
 
Sintaxis:  GOTO  k 
Operandos:  0 ≤  k  ≤ 1048575 
Operación:    k ⇒ PC <22:0> 
Flags afectados: Ninguno 
 
Descripción: Se trata de un salto incondicional. Ocupa 2 ciclos de reloj. La posición de destino se otorga 
directamente por el valor k que se carga en el PC. Esta instrucción posee un tamaño de 4 Words en memoria de 
programa.
__________________________________________   71   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
La instrucción GOTO utiliza modo de direccionamiento DIRECTO. La dirección efectiva de destino está 
directamente incorporada en el código de operación en 23 bits que son los que se cargan directamente en el PC en 
la ejecución. 
 
Ejemplo: ORIGEN GOTO DESTINO 
 
   Antes: PC = ORIGEN+2​
   Después: PC = DESTINO
Microprograma de una instrucción de salto
Analicemos con detalle el comportamiento del microprograma de una instrucción de salto.   
​
 
1)​ PC=000102 ⇨ MARp ⇨ Address Bus ⇨MemoProg 
2)​ PC + 2 ⇨ PC                             
3)​ retardo. 
4)​ [000102] = E601 ⇨ Data Bus ⇨ MDRp 
5)​ MDRp ⇨ IR  ⇨ Decodificador =  BRA 01 
6)​ Test de Flag N 
7)​          Si es 1: IRL =   01h ⇨ ALU = 2 * 01 ⇨ T⇨ X 
8)​          Si es 1: PCL =   04h ⇨ ALU = PC + X ⇨ T 
9)​          Si es 1: T ⇨ PC 
​
Instrucciones de Salto Condicional
El formato general es:  BRA ​
x, etiqueta​
​
donde x: es una condición. 
Estas instrucciones tienen como objetivo, efectuar un salto condicional a otro punto del programa principal cuya 
posición está indicada por una etiqueta. La condición siempre está referida a uno o más flags, que son verificados 
previamente a la ejecución de la operación de salto.
- Si la condición se cumple, la dirección de destino se obtiene sumando al PC actual, un valor de 
desplazamiento de 16 bits, que se calcula a partir del valor que figura en el código de operación (byte siguiente 
al COP). El único modo de direccionamiento que admite esta instrucción es el RELATIVO y el desplazamiento 
siempre es signado. Esto determina una distancia máxima de salto de 32767  instrucciones hacia adelante o 
32768  instrucciones hacia atrás, contadas a partir de la instrucción siguiente al salto.
- Si la condición NO se cumple, el programa sigue en secuencia normal en la instrucción siguiente a la de salto.
Este tipo de instrucciones de salto condicional normalmente están situadas inmediatamente después de una 
instrucción aritmética o lógica, que es la que determina el movimiento de banderas. La instrucción CP (compare) o 
DEC (decremento) son las más comúnmente utilizadas como instrucción previa. 
Como la instrucción CP (u otra aritmético - lógica) mueve las banderas (flags) del registro STATUS, el salto 
condicional ocurre acorde al resultado en las banderas. 
Debido a ello es que puede pensarse que: la instrucción aritmético – lógica que mueve las banderas y la 
consiguiente de salto condicional, conforman una Estructura de Decisión. 
En el siguiente ejemplo se utiliza este tipo de estructura:
​
DEC​
contador​
​
;se decrementa la variable contador y se mueven banderas. 
​
BRA​
Z, beta​ ​
​
;si llegó a cero se salta a beta, sino se sigue en secuencia
La condición es Z (zero, igual a cero) . La condición de salto se dará si el  operando destino (contador) llegó a 
cero. 
Para efectuar el salto, el procesador analiza previamente la bandera de CERO, si Z=1 significa que  contador = 0, 
o sea, se producirá el salto. El movimiento de Z se efectuó con la instrucción DEC. 
Las instrucciones de salto condicional NO hacen variar los FLAGS, se valen de ellos.  
En lo que sigue, se otorga un listado clasificado de las más importantes instrucciones de salto.
BRA​
C, etiqueta 
BRA​
NC, etiqueta 
BRA​
N, etiqueta 
__________________________________________   72   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
BRA​
NN, etiqueta 
BRA​
OV, etiqueta 
BRA​
NOV, etiqueta 
BRA​
Z, etiqueta 
BRA​
NZ, etiqueta
Instrucciones de Testeo de bits
Estas instrucciones efectúan el testeo de algún bit de un File, ambos especificados en el campo de operandos de la 
instrucción y el salto se produce condicionalmente al estado del bit. La diferencia esencial con las instrucciones 
BRANCH es que el valor del salto cuando el resultado del test es verdadero, se limita a omitir una instrucción. 
Esto es, si el resultado del test es falso, se sigue en secuencia, ejecutando la instrucción que sigue a la 
instrucción de salto como en el caso de las instrucciones BRANCH. Si el resultado del test es verdadero se salta 
sólo la instrucción que sigue a la instrucción de salto.  
​
BTSS:    Test de bit y salto 
 
Sintaxis: BTSS   f, #bit4 
Operandos:  0 ≤ f  ≤ 0xFFFF, 0 ≤ #bit4  ≤ 15 
Operación:    Salto si  f<#bit4 > = 1 
Flags afectados: Ninguno 
 
Descripción: Si el bit b del registro f es 1, se salta una instrucción y se continúa con la ejecución. En caso de salto, 
ocupará dos ciclos de reloj. 
 
Ejemplo:                 ​
BTSS   W0, 6 
                                 ​
GOTO  SI_ES_0 
         ​
​
​
NO_ES_0:  Instrucción 
         ​
​
​
SI_ES_0:    Instrucción
BTSC:   Test de bit y salto 
 
Sintaxis: BTSC   f, #bit4 
Operandos:  0 ≤ f  ≤ 0xFFFF, 0 ≤ #bit4  ≤ 15 
Operación:    Salto si  f<#bit4  > = 0 
Flags afectados: Ninguno 
 
Descripción: Si el bit b del registro f es 0, se salta una instrucción y se continúa con la ejecución. En caso de salto, 
ocupará dos ciclos de reloj. 
 
Ejemplo:                 ​
BTSC   W0, 6 
                                 ​
GOTO   NO_ES_0 
           ​ ​
​
SI_ES_0:    Instrucción 
         ​
​
​
NO_ES_0:  Instrucción 
 
Instrucciones para manejo de Subrutinas
El formato general es:  CALL  etiqueta 
La instrucción CALL tiene como objetivo efectuar un salto incondicional a una subrutina, cuya posición de inicio 
en el programa está indicada por una etiqueta. La etiqueta tiene un valor equivalente a la dirección de la primera 
instrucción de la subrutina.  
Previo a la carga en el PC de la dirección de destino, la dirección actual que este contiene se mueve a la PILA en 
forma automática. Dicha dirección es la que se restaura luego para retornar al programa principal cuando finaliza 
la subrutina con una instrucción RETURN. 
 
La instrucción RETURN tiene como objetivo retornar al programa principal desde una subrutina. Para que ello 
ocurra, la instrucción RETURN debe ser la última instrucción de la subrutina. RETURN restituye en el PC el
__________________________________________   73   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
valor que fuera introducido en la pila por la última instrucción CALL. Como puede observarse, el modo de 
direccionamiento que posee la instrucción RETURN es el IMPLÍCITO. Call y Return conforman una estructura 
que es utilizada en las subrutinas. 
Pila (Stack Pointer)
La pila es una zona de memoria de datos apuntada por un puntero (Stack Pointer). 
En la línea PIC 24 o PIC 33 ese puntero es el registro W15. 
La pila se utiliza en un modo secuencial (no aleatorio). Cada valor introducido en la pila es en secuencia con el 
anterior. 
Cuando se introduce un dato en la Pila, dicho dato se introduce a partir de la dirección base a la que apunta el 
Stack Pointer. Luego, el Stack pointer se incrementa en una cantidad igual a la cantidad de bytes de datos 
introducidos y queda apuntando a la siguiente posición libre. Lo dicho se indica en la Figura 10.1. 
Cuando se extrae un dato desde la pila, primeramente el Stack Pointer se decrementa una cantidad de bytes igual a 
la cantidad de bytes de formato del registro destino. Luego, el valor residente en la nueva dirección base a la que 
apunta el Stack Pointer, es movido al registro destino. Lo expuesto se indica en la Figura 10.2. 
 
                   Antes de la operación                                                   Después de la operación 
 
Valor del PC:  ​ 0x 000023DE​
​
​
​
​
0x 000023DE 
Valor del W15: ​ 0x0802​ ​
​
​
​
​
0x0806
Contenido 
​Dirección 
​ 
 
Contenido 
​Dirección
B0 
0800 
 
 
B0 
0800 
 
18 
0801 
 
 
18 
0801 
 
02 
0802 
🡨 Stack P. 
 
DE 
0802 
 
C3 
0803 
 
 
23 
0803 
 
A2 
0804 
 
 
00 
0804 
 
1D 
0805 
 
 
00 
0805 
 
02 
0806 
 
 
02 
0806 
🡨 Stack P. 
1A 
0807 
 
 
1A 
0807 
 
3D 
0808 
 
 
3D 
0808
Figura 10.1: Secuencia del Stack ante una introducción de un valor en la pila.
Antes de la operación                                                   Después de la operación 
 
Valor del PC:  ​ 0x 000023DE​
​
​
​
​
0x 00010A02 
Valor del W15: ​ 0x0806​ ​
​
​
​
​
0x0802
Contenido 
​Dirección 
​
 
 
Contenido 
​Dirección 
 
B0 
0800 
 
 
B0 
0800 
 
18 
0801 
 
 
18 
0801 
 
02 
0802 
 
 
02 
0802 
🡨 Stack P. 
0A 
0803 
 
 
0A 
0803 
 
01 
0804 
 
 
01 
0804 
 
00 
0805 
 
 
00 
0805 
 
FF 
0806 
🡨 Stack P. 
 
FF 
0806 
 
1A 
0807 
 
 
1A 
0807 
 
3D 
0808 
 
 
3D 
0808
Figura 10.2: Secuencia del Stack ante una extracción de un valor de la pila.
__________________________________________   74   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Instrucciones
CALL:​ Salto a subrutina 
Sintaxis:  CALL k 
Operandos:  0 ≤  k  ≤ 1048575 
Operación:    PC + 4  ⇒ TOS;  k ⇒ PC <22:0> 
Flags afectados: Ninguno 
Descripción: Se trata de un salto incondicional. Ocupa 2 ciclos de reloj. El valor actual del PC se carga en el tope 
de la pila. Luego, la posición de destino se otorga directamente por el valor k que se carga en el PC. Esta 
instrucción posee un tamaño de 4 Words en memoria de programa. 
La instrucción CALL utiliza modo de direccionamiento DIRECTO. La dirección efectiva de destino está 
directamente incorporada en el código de operación en 23 bits que son los que se cargan directamente en el PC en 
la ejecución. 
 
Ejemplo:    ORIGEN CALL DESTINO 
 
   Antes:  PC = ORIGEN​ ​
   Después: PC = DESTINO
RETURN: Retorno de rutina  
Sintaxis:    RETURN  
Operandos: Ninguno 
Operación: :   TOS ⇒ PC 
Flags afectados:   Ninguno 
Descripción: El PC se carga con el contenido de la cima de la pila (TOS): dirección de retorno. Consume 2 ciclos.  
 
Ejemplo:             RETURN 
 
  Después: PC = dirección de retorno
Instrucciones especiales
En este grupo se concentra ciertas operaciones que poseen un fin específico. Ejemplos de ellas son: 
 
NOP​
Esta instrucción tiene como objetivo efectuar relleno de zonas vacías de memoria dentro de un 
programa.
NOP  No operar 
Sintaxis:   NOP 
Operandos: Ninguno 
Operación: No operar 
Flags afectados:    Ninguno 
Descripción: No realiza operación alguna. En realidad consume un ciclo de instrucción sin hacer nada. 
 
Ejemplo:            NOP 
 
RETFIE​
Instrucción de retorno de una interrupción que habilita interrupciones.
RETFIE Retorno de  interrupción 
Sintaxis:     RETFIE 
Operandos:  Ninguno 
Operación: :   IPL = 4;  TOS⇒PC 
Flags afectados:   Ninguno 
Descripción: El PC se carga con el contenido de la cima de la pila (TOS): dirección de retorno. Consume 2 ciclos. 
 
Ejemplo:        RETFIE
Después: PC = dirección de retorno
__________________________________________   75   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Comparativa de Tipos de instrucciones de Control de Programa y 
Sistema
Saltos 
Subrutinas 
Interrupciones
Permite reutilización de 
código. Favorece 
encapsulamiento.
Permite ejecución de 
programas distintos en forma 
concurrente.
Objeto 
Permite optar por dos 
alternativas de ejecución.
Etiqueta 
Se invoca en el origen del salto e Indica el punto de 
continuación (destino) de la ejecución.
No existe. La sustituye el 
vector, indicando el destino.
Incondicionales:
bra etiqueta 
Condicionales:
Tipos
Sólo incondicionales
bra   condición, etiqueta
Si está Habilitada, ocurre en 
cualquier punto de ejecución 
de main.
Llamada 
Explicita en el programa 
(BRA)
Explicita en el programa 
(CALL)
Guarda la dirección de retorno 
y FLAGS (parte baja) 
Retorno 
No retorna 
Con: RETURN 
Con: RETFIE
Pila 
No opera 
Guarda la dirección de 
retorno automáticamente.
Condicionales: Relativo. 
Incondicionales: Directo e 
indirecto.
Direcciona-
Relativo (RCALL) 
Directo e indirecto (CALL) 
Directo con Vector  Implícito
mientos
Condicionales: 16 bits 
signado. 
Incondicionales: 32 bits no 
signado.
OFFSET 
(tamaño)
16 bits signado y 32 bits no 
signado 
32 bits no signado
W15. Apunta siempre a la primera posición libre, 
incrementándose luego de introducir el valor. Se decrementa 
antes de extraer el valor.
Puntero a
PILA 
No es necesario
R.López 1999-2013 
S.Wahler 2008-2020
__________________________________________   76   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 11
LENGUAJE ENSAMBLADOR
​
 
Introducción
El ensamblador que utilizaremos para programar los PIC es el ASM30/XC16 Assembler. Los elementos básicos 
del lenguaje ensamblador son:
- Etiquetas. 
- Instrucciones / Directivas. 
- Operandos. 
- Comentarios. 
 
Para la programación se utiliza una cierta tabulación que se debe respetar, además utilizar una tabulación adecuada 
hace los programas más claros y legibles. Las etiquetas se escriben en la primera columna de cualquier línea, las 
instrucciones y directivas en la segunda columna y por último, en la tercer columna, los operandos. Los 
comentarios se pueden escribir en cualquier parte del programa.
Etiquetas
Las etiquetas son nombres de subrutinas o secciones de código fuente. Dando nombres a partes del programa, se 
usan para posibilitar el salto desde cualquier posición del programa hacia la etiqueta sin necesidad de recordar las 
direcciones físicas donde están ubicadas.
El ensamblador ASM30/XC16 permite etiquetas de hasta 32 caracteres. Es importante que las etiquetas empiecen 
con una letra o con un guión bajo “_”. Una etiqueta debe ir seguida de dos puntos (:). La longitud de una etiqueta 
puede ser de hasta 32 caracteres y como ya se dijo se deben escribir en la primer columna y será parte del campo 
de etiquetas.
Instrucciones o directivas
La segunda columna corresponde al campo de instrucciones. Son las operaciones que realiza el microcontrolador, 
así que estas ya están definidas para cada familia de PIC.
También puede ser una instrucción para el ensamblador llamada directiva. Las directivas son similares a las 
instrucciones, pero a diferencia de estas, las directivas son propias del lenguaje ensamblador e independientes del 
microcontrolador que se utilice. Las directivas representan algunas  características del lenguaje ensamblador, se 
utilizan para especificar el procesador empleado así como la configuración de este, también para asignar 
locaciones de memoria, entre otras cosas.
Datos u operandos
La tercera columna se trata del campo de datos u operandos para las instrucciones. En los PICs, los datos pueden 
ser un registro, un bit de un registro, una etiqueta o un número constante (llamado literal). Algunas instrucciones 
no llevan datos. Si una instrucción necesita múltiples datos, deben separarse por comas (,).
La especificación de la base en la que se expresan los datos u operandos es opcional: 65, 0b01000001’,0x0041, 
son el mismo dato. El no prefijo se emplea para expresar un valor en decimal. El prefijo 0b o 0B expresa un valor 
en binario. Para expresar un valor en hexadecimal se emplea el prefijo 0x ó 0X.
Un número en base octal se representa mediante el prefijo o ó O. Finalmente, un valor se puede expresar mediante 
un caracter ASCII si se encierra entre comillas simples como ‘A’.
__________________________________________   77   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Comentarios
La última columna es el campo de comentarios, siempre que haya un punto y coma (;) como primer carácter. 
Puede colocarse en cualquier lugar del código fuente.
Los comentarios en ensamblador son muy importantes. Los comentarios deben describir las tareas que realizan las 
instrucciones y/o subrutinas. Sin comentarios, es muy difícil descifrar, algunos días después, el código fuente que 
uno mismo ha creado.
El primer programa: EJEMPLO1.S
A continuación se muestra como debe quedar un programa con buen estilo de programación:
Vamos a ir examinando las distintas partes del programa EJEMPLO1.S y explicando cada una de ellas.
- La primera línea es un comentario. Los comentarios van precedidos siempre por el signo “;” (punto y coma). 
Tras este signo se pueden escribir los comentarios que se quiera hasta el final de la línea, y que puedan 
ayudar a identificar el programa y a comprender mejor cuál es la lógica del mismo.
- La siguiente línea se corresponde con una directiva. Una directiva no es una instrucción propia del PIC, sino 
una instrucción para el compilador para que identifique que la etiqueta _main de inicio del programa se 
encuentra en este archivo fuente.
- La directiva .text indica que a continuación se va a escribir la parte del programa correspondiente al código 
principal. El programa podría incluir datos, y para que el compilador distinga si lo que viene a continuación 
son datos u otro tipo de información, se usa la directiva .text.
- La etiqueta _main es la de inicio de programa, la siguiente instrucción será la primera que ejecute el 
microcontrolador tras atender una rutina interna de Reset.
- La instrucción mov #0x0001,W0 mueve el literal #0x0001 al registro W0. Para indicar que se trata de una 
constante, se coloca el símbolo numeral # delante del número a escribir. 0x significa que el número está 
representado en hexadecimal. La instrucción MOV mueve el primer operando (fuente) al segundo (destino).
- suma2: es otra etiqueta, las que se usan para darle claridad o legibilidad al programa o porque el programa 
salta a ella frecuentemente (con instrucciones de salto por ejemplo). Una etiqueta debe siempre terminar con 
el signo de puntuación dos puntos (:) y no debe coincidir con ninguna palabra reservada del compilador.
- A continuación el programa mueve un 2 al registro general W1, y luego suma los registros W0 y W1 y deja 
el resultado en W0. La instrucción ADD admite varios formatos.
- Por último, la directiva .end indica el final del programa fuente.
__________________________________________   78   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Secuencia a seguir para el grabado del microcontrolador
S.Wahler 2009-2020
__________________________________________   79   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 12
ENTORNO DE DESARROLLO MPLAB X
Introducción
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
subsiguientes es la 6.05.
Descarga
Para descargar el programa se debe ingresar al link mencionado anteriormente, al bajar en la página se podrá 
encontrar la sección de descargas donde se puede elegir para qué sistema operativo se desea descargar la 
plataforma (MAC, Linux o Windows) como muestra la siguiente imagen.
Una vez seleccionada la versión (señaladas por las flechas) se comienza la descarga del instalador del IDE 
MPLAB X. 
 
Instalación y Uso dentro del marco de la Asignatura
Lo primero es instalar el programa, es una tarea sencilla, para hacerse se debe cliquear el archivo recién 
descargado, al hacerlo se tendrá la siguiente ventana emergente.
__________________________________________   80   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Se debe cliquear el botón “Next” que resalta la imagen anterior, luego se tendrá la siguiente ventana.
Aquí se debe cliquear en el botón para aceptar los términos y condiciones, luego presionar el botón “Next” 
resaltado en la imagen anterior, una vez hecho esto se verá la siguiente ventana:
__________________________________________   81   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
En este momento se debe seleccionar la opción “Use System Proxy Settings” y cliquear el botón “Next”. Ambos 
señalados en la imagen anterior. Una vez realizadas estas acciones se tendrá la siguiente ventana.
En esta ventana se pueden elegir las aplicaciones a instalar, recomendamos que todas sean instaladas y elegir los 
dispositivos que pueden ser usados en el entorno, también estos deben ser todos seleccionados. Se debe cliquear el 
botón “Next” señalado en la imagen. Luego se tendrá la siguiente ventana.
__________________________________________   82   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Aquí se debe cliquear solamente el botón “Next”. Una vez hecho esto se verá una ventana con una barra de carga 
mostrando el nivel de instalación. Se debe esperar hasta que termine la instalación. Una vez que la instalación fue 
completada se verá la siguiente imagen:
Utilizamos la opción de “siempre confiar en software de microchip” para no tener que confirmar todas las 
instalaciones requeridas, puede no utilizarla y tomar la decisión de instalar o no cada complemento, 
recomendamos que si lo instale como muestran las siguientes imágenes.
__________________________________________   83   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Por último se tendrá la siguiente ventana.
__________________________________________   84   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Aquí se debe quitar las tildes de las tres opciones, aunque si se desea puede instalar los complementos. Por último, 
se debe cliquear el botón “Finish” y se finaliza la instalación.
En este momento, el IDE MPLABX debería estar instalado correctamente y se observará en el escritorio de la 
computadora los siguientes accesos directos.
Instalación del compilador
En este punto de la instalación es necesario instalar el compilador XC16 para poder ejecutar código en C. Para 
hacerlo, primero debe descargarse el compilador de la web oficial del entorno la cual es la siguiente 
https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers . Al ingresar a la web mencionada 
se tiene que descargar el compilador XC16 clickeando en el lugar que se indica en la siguiente imagen.
__________________________________________   85   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Al hacer click en el botón señalado se redirecciona la navegación al sitio de descarga y se debe descargar el 
compilador válido para su PC de los presentados en la siguiente imagen.
Una vez descargado el compilador y ejecutado su instalador se tendrá la siguiente ventana emergente.
__________________________________________   86   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Debe darse click al botón “Next” para continuar con la instalación del compilador.
En este punto se deben aceptar los términos y condiciones para poder continuar con la instalación apretando el 
botón “Next”.
__________________________________________   87   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Al haber sido la descarga gratuita “Free” será el único modo de compilador a instalar, basta con darle clic al botón 
“Next” para continuar con la instalación.
En esta ventana de instalación se permite seleccionar el sitio donde se instalará el compilador, se recomienda dejar 
la ruta seleccionada automáticamente, luego debe darse click al botón “Next”.
__________________________________________   88   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
En este punto debe darse click al botón “Next” para continuar con la instalación con los valores por defecto 
asignados por el instalador.
La ventana anterior indica que todo está configurado y listo para instalar el compilador, debe darse click al botón 
“Next”.
__________________________________________   89   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Una vez finalizada la instalación se solicita un identificador del host, al cual ya el instalador propone uno por 
defecto. Con apretar el botón “Next” se realiza la última configuración del instalador.
Como se indica en la imagen anterior la instalación se terminó y basta con clickear el botón “Finish” para finalizar 
el proceso de instalación del compilador XC 16.
NOTA IMPORTANTE: Es necesario primero instalar el entorno de programación y en segundo lugar el 
compilador.
__________________________________________   90   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Inicio de un Proyecto
Al instalar el programa se puede proceder con todas las opciones que vengan por defecto, también se puede hacer 
una instalación personalizada, la cual se sugiere para usuarios con mayor experiencia. Al finalizar la instalación y 
ejecutar el programa se obtendrá una pantalla como la siguiente:
De manera sencilla un nuevo proyecto se puede crear cliqueando en el botón “File”, ubicado en el sector superior
izquierdo del IDE MPLAB X. Luego, debe cliquear en “New Project” al hacerlo aparecerá la siguiente pantalla.
En este primer paso de la creación de un nuevo proyecto, elegimos la opción “Standalone Project” y cliqueamos en 
el botón “Next” indicado en la imagen. Una vez realizadas estas acciones tendrá la siguiente pantalla, en la cual 
debemos seleccionar el PIC a utilizar. El PIC que debe elegir es el “dsPIC33FJ256GP710”, el cual figura en la lista
__________________________________________   91   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
de la familia de PIC’s “16-bit DSC(dsPIC33)” como se muestra en la siguiente imagen (puede encontrarse también 
buscando en todas las familias de PIC’s.
Una vez que seleccione la familia de PIC’s mencionada y el PIC a utilizar, también mencionado anteriormente, 
tendrá que elegir la herramienta que se usará para debugging, debe seleccionar la opción “Simulator” como se 
indica en la siguiente imagen.
Una vez que haya presionado el botón “Next” resaltado en la imagen anterior, tendrá una ventana nueva en la que 
debe seleccionar el compilador a utilizar, aquí puede elegir entre distintos compiladores para distintos lenguajes 
(Por ej. XC 16 para un programa en C, o ASM30 para un programa en Assembler). Según el PIC que se utilizará 
dependerá de qué compilador puede usar, en nuestro caso, para el ya mencionado PIC a utilizar, usaremos el 
compilador XC 16. Debe seleccionarlo de la lista de compiladores como se muestra en la siguiente imagen.
__________________________________________   92   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Cabe aclarar en este punto que si no aparece en el listado el compilador XC16 es porque la instalación que debió 
realizarse previamente no fue exitosa por algún motivo y debe rehacerse.
En la ventana siguiente se le debe dar un nombre al proyecto y escoger el directorio en el que se guardará el 
mismo. Es recomendable que la ruta de la carpeta donde se guarde el proyecto no sea excesivamente larga, ya que 
el compilador posee una restricción máxima de 62 caracteres, pudiendo arrojar en caso contrario, un error al 
compilar.
Para ello, se recomienda crear una carpeta en el disco “C:\” o en cualquiera que se use, lo más cerca del directorio 
raíz del disco. En este caso la ruta escogida es C:\MPLAB\Proyecto1.
La opción de “Set as main project” puede ser deshabilitada sin problemas.
Una vez dado el nombre al proyecto, al hacer click en “Finish”, se le creará el proyecto, lo cual implica una serie 
de carpetas relacionadas que debería verlas en la ventana “Projects”, la cual si no la puede ver en la parte superior 
izquierda de la pantalla también puede clickear en el botón “Window” → “Projects”. Dicha ventana debería verse 
del siguiente modo con su proyecto recién creado.
__________________________________________   93   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
En este punto se puede escribir el código del programa a ejecutar. Para ello se crea un nuevo archivo y se lo guarda 
con extensión .c en la carpeta donde se tiene el proyecto. Para crear un archivo haga segundo click en Source Files 
→  New → mainXC16.c, como se indica en la siguiente imagen.
El siguiente paso es agregar el archivo al proyecto y posteriormente escribir el código de programa. En la ventana 
del proyecto hacer click derecho en Source Files y después seleccionar Add Files.
Una vez realizadas las acciones recién mencionadas se abrirá una ventana en la que debe darle nombre al archivo a 
crear (recomendamos por simplicidad que para el primer trabajo utilicen el nombre “main” como se hace en la 
siguiente imagen), también deben seleccionar la extensión del programa, en nuestro caso utilizaremos el lenguaje 
de programación C y por lo tanto crearemos un archivo con extensión “.c”. Todo esto lo vemos en la siguiente 
imagen.
__________________________________________   94   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Cuando haya cliqueado en el botón “Finish” resaltado en la imagen anterior tendrá un archivo que podrá colocar el 
código a ejecutar, en principio el contenido del archivo es llenado por el IDE con el siguiente contenido.
Todos los cambios que se efectúen en él se verán reflejados en el proyecto. Se escribió como ejemplo un código 
sencillo. Un programa que realice una suma de dos valores, guardando el resultado en una variable y restando un 
valor constante definido previamente:
__________________________________________   95   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Este ejemplo se escribió usando MPLABX, se puede ver que la aplicación reconoce la sintaxis del lenguaje C y 
utiliza diferentes colores para los diferentes elementos del código. Las instrucciones y tipos de datos se muestran 
en azul, los comentarios son mostrados en gris, las variables son escritas en color negro sin resaltar y los nombres 
de las funciones, en sus cabeceras son escritos en negrita, en verde los includes y defines y por último en celeste 
las constantes.
Una vez escrito el código se puede compilar el programa, con esto se genera el archivo .o con el que se graba el 
PIC. Para compilar el programa se puede utilizar el menú Production → Build Main Project o usar la combinación 
Ctrl + F11. El archivo O generado se encuentra en el mismo directorio que el proyecto y lleva el mismo nombre 
que el archivo con el código. Con ello se concluye la creación de un proyecto, la realización de un programa en 
MPLAB X con su correspondiente escritura en código C y la compilación del mismo.
Cuando la compilación resulta exitosa puede verse el resultado en la terminal de salida, informa con color verde 
que se terminó la compilación correctamente y con mensajes de color rojo cuando no lo hace, dando información 
asociada a los errores encontrados.
Configuración del Simulador
Una manera de saber si el programa que se ha realizado funciona como se desea, es simulando su proceso en la 
computadora. Por esto Microchip facilitó algunos utilitarios como el MPLAB SIM que nos permitirá observar el 
comportamiento del programa.
Con la configuración previamente mostrada ya se encuentra en posibilidad de realizar el debugging del programa, 
aunque puede configurarse también habilitando la opción del simulador seleccionando dando segundo click en el 
proyecto y seleccionando “propiedades”, allí se abrirá una pantalla como la siguiente.
__________________________________________   96   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
En esta ventana debe seleccionar la herramienta de hardware “Simulator”, luego aplicar el cambio y guardar, 
presionando el botón “OK”.
Con esta configuración ya se puede empezar a trabajar en el programa que se quiere implementar. La figura 
muestra la zona en donde se deben escribir los comandos del programa. Una vez finalizado, se debe ejecutar el 
programa para verificar que no haya errores, esto se hace teniendo configurado el compilador en “Real ICE” 
presionando el botón de “Play” verde, ubicado en la parte superior central del IDE, dicho botón tiene el siguiente 
aspecto (en algunos casos puede no reconocer la opción de Real ICE que figura al clickear en “Show All y basta 
con seleccionar “Simulator” para realizar pruebas).
Para correrlo en modo debug debe utilizarse la opción “Simulator” en la herramienta hardware usada como se 
mencionó previamente y deberá apretar el botón para correr en modo debug, este es el siguiente.
Luego de correr el programa en el primer modo explicado, aparecerá una lista con los errores y la línea donde se 
produjo cada uno. Si se hace doble click en la línea donde indica el tipo de error, el programa saltará 
automáticamente a la línea que debe ser corregida. Corregir los errores y volver a presionar el botón de play para 
verificar que el código sea correcto.
Cuando no se generen errores, aparecerá al final de todas las líneas BUILD SUCCESSFUL, esto indica que no se 
encontraron errores de compilación y uno puede empezar a simular.
__________________________________________   97   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Simulación
En el menú de MPLAB X se encuentra Debug, esta lista de opciones para el simulador permite realizar lo 
siguiente:
- Continue (F5): Al activarse esta opción el programa se ejecuta a toda velocidad en "modo tiempo real", 
aunque no hay que olvidar que se trata de una simulación por computadora. La ejecución comienza en la 
dirección actual del contador de programa (PC), que se muestra en la barra de estado y en la ventana 
Program Memory. Mientras el programa está en ejecución Step y Run están deshabilitados y se detiene si 
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
__________________________________________   98   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Para realizar la simulación podemos colocar las ventanas tal y como aparece en la figura, pulsar sobre  (Step Into) 
y observar cómo se ejecuta el programa paso a paso y se modifican los registros:
Tal y como están dispuestas las ventanas puede observarse todo lo necesario para la simulación. La flecha verde en 
la ventana donde está el C indica que instrucción es la que se va a ejecutar.
Con la ventana listing.disasm se pueden observar los cambios en los registros específicos. Con la ventana variables 
se pueden ver las variables empleadas en el código, su valor actual y su posición en memoria. Hay otras ventanas 
también de interés, como Output que nos brinda información sobre la compilación, la ejecución general del 
proyecto y los mensajes obtenidos en la simulación.
Menú Window
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
Menú View
- Toolbars: Permite seleccionar que barras de herramientas aparecerán en MPLAB X.
M.Ducid - 2020 
S.Wahler - 2025
__________________________________________   99   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 13
LENGUAJE C  ELEMENTAL
​
 
Programa ejemplo
Comenzaremos una breve explicación del lenguaje C sobre la base de un ejemplo elemental.
#include <stdio.h>
char mayor;
char personas[10] = {‘A’,‘B’,‘C’,‘D’,‘E’,‘F’,‘G’,‘H’,‘I’,‘J’};
int edad[10] = {15, 13, 16, 14, 16, 15, 17, 13, 14, 15};
main() 
{ 
​
int i, j = 0; 
​
int aux = edad[0]; 
​
while (i < 10) 
​
{
​​
if edad[i] > aux 
​​
{ 
​​
​
aux = edad[i]; 
​​
​
j = i; 
​​
} 
​​
i = i + 1; 
} 
 
​
mayor = personas[j]; 
​
printf(“La persona de mayor edad es %s\n”, mayor); 
} 
 
Un programa en C es un texto que contiene directivas, declaraciones y sentencias. Es usual emplear una línea de 
texto para cada una.
La primera línea hace referencia a una directiva del pre-procesador que incluye el encabezado de archivo estándar 
de C, en este caso la librería denominada stdio.h donde se describen todas las operaciones de entrada/salida 
estándar del lenguaje. Con esta directiva #include se pueden incluir otros textos que contienen declaraciones y 
sentencias.
En la segunda línea se realiza una declaración de una variable denominada mayor que será del tipo carácter y que 
esta sin valor inicial. Tanto las declaraciones como las sentencias terminan en punto y coma.
En la tercera línea se realiza una declaración de una variable denominada personas que será un vector (tabla) de 
10 posiciones de tipo caracter. Esta declaración es seguida de una inicialización de cada una de las posiciones de 
la tabla con los valores que aparecen dentro de las llaves. Representan a un grupo de 10 personas.
En la cuarta línea se realiza una declaración de una variable denominada edad que será un vector (tabla) de 10 
posiciones de tipo entero. Esta declaración, al igual que en la tercera línea, es seguida de una inicialización de 
cada una de las posiciones de la tabla con los valores que aparecen dentro de las llaves y representan las 10 edades 
de las personas anteriormente declaradas.
En la quinta línea comienza la declaración de la función principal y programa denominada main().
En la sexta línea comienza la definición del cuerpo principal del programa con el carácter {.
En la séptima línea se realiza una declaración local de dos variables denominadas i y j que serán de tipo entero y 
son seguidas de una inicialización con valor cero.
__________________________________________   100   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
En la octava línea se realiza una declaración local de una variable denominadas aux que será de tipo entero y es 
seguida de una inicialización cuyo valor es tomado de la primera posición del vector llamado edad. Recordar que 
la primera posición de un vector es la cero, en este caso el vector edad contiene 10 elementos ubicados desde la 
posición 0 a la 9. La idea de la variable aux es ir manteniendo el mayor valor de edad encontrada.
En la novena línea aparece la instrucción while que nos permite realizar un ciclo o lazo de búsqueda y 
comparación para recorrer las 10 posiciones de la tabla. Esta instrucción tiene asociada una condición expresada 
por i<10 de tal manera que mientras que el valor de la variable entera i este por debajo 10 se recorrerá la tabla 
buscando la mayor edad y se saldrá cuando esa variable i alcanza el valor 10.
En la décima línea aparece nuevamente el carácter { pero esta vez representa el inicio de un bloque de 
instrucciones que se hallan inmersas dentro de la estructura de repetición while y que se repetirán hasta alcanzar la 
condición de salida detallada en el párrafo anterior.
En la décimo primera línea hay una instrucción if encargada de verificar si se cumple la condición que la 
componente i-ésima de la tabla sea mayor que el valor contenido por la variable auxiliar aux.
En la décimo segunda línea aparece nuevamente el carácter {, por segunda vez aparece aquí para mostrar el inicio 
de un bloque de instrucciones que se deben realizar si se cumple la condición de la instrucción if.
En la décimo tercera línea si se cumple la condición del if entonces se copia en la variable auxiliar aux  la edad 
mayor contenida en la tabla de edades hasta ese momento.
En la décimo cuarta línea si se cumple la condición del if entonces también se resguarda en la variable j la 
posición de la edad de mayor valor hasta ese momento apuntada por la variable i.
En la décimo quinta línea aparece el carácter } que indica la finalización del bloque de instrucciones comenzado 
en la línea doce.
En la décimo sexta línea se incrementa el contador expresado por la variable i que permite apuntar a otra posición 
en la tabla de edades.
En la décimo séptima línea aparece nuevamente el carácter } que indica la finalización del bloque de instrucciones 
comenzado en la línea diez.
En la décimo octava línea ya hemos salido del ciclo de la instrucción while habiendo recorrido todo la tabla de 
edades. Por lo tanto ya tendremos la posición donde reside la edad mayor. Con esa misma posición pero 
accediendo a la tabla personas encontramos el nombre de la persona y lo copiamos a la variable mayor.
En la décimo novena línea mostramos por pantalla mediante la instrucción printf() un mensaje indicando quién es 
la persona de mayor edad de aquellas que figuraban en la tabla. Por lo tanto se comienza dentro de los paréntesis 
con las comillas, luego va el texto del mensaje y cuando queremos colocar el valor de una variable utilizamos el 
carácter de control % seguido de un carácter de conversión, en nuestro caso s que simboliza un carácter a 
imprimir. Luego se finaliza con el carácter \n y las comillas de cierre. Separado por una coma aparece la variable 
que se quiere mostrar, en nuestro caso la variable mayor y se cierra el paréntesis terminando es función.
En la vigésima línea aparece nuevamente el carácter } que indica la finalización del bloque principal de 
instrucciones o programa.
G.Ingravallo  - 2011
__________________________________________   101   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 14
LENGUAJE C
​
 
Introducción
Basándonos en los conceptos teóricos vistos en la materia abordaremos de manera introductoria los conceptos 
básicos de un lenguaje de programación llamado C. Iremos viendo como elementos conocidos en lenguaje 
assembler son implementados por este lenguaje de alto nivel.
Comencemos por definir este último término, decimos del assembler que es un lenguaje de bajo nivel porque es el 
más cercano a la máquina sin ser aún el que está expresado en valores binarios o hexadecimales equivalentes. En 
contraposición un lenguaje de alto nivel se lo denomina así porque es muy cercano a los programadores que lo 
utilizan en cuanto a que sus comandos o instrucciones son fácilmente entendibles por los mismos.
No obstante esa diferencia entre ambos, existe un punto en común que es que cada instrucción en lenguaje C se 
puede transformar en hasta 7 instrucciones de lenguaje assembler.
Programa 
Un programa está formado por un conjunto de instrucciones que se ejecutan secuencialmente. Este concepto se 
aplica tanto a los programas escritos en lenguaje C como a los que hemos escrito en assembler y a aquellos que en 
el futuro puedan escribir en otros lenguajes.
Cada lenguaje utiliza una sintaxis o conjunto de reglas que indican de qué manera se quiere realizar las 
operaciones. Esta tarea la cumple un programa especial llamado compilador, que traduce el programa a lenguaje 
de máquina. Es una tarea que suele descomponerse en dos etapas, que se pueden realizar juntas o por separado.
Cualquier programa se suele almacenar en uno o más archivos llamados archivos fuente, cuyo nombre finaliza de 
una manera particular llamada extensión. En particular, todos los programas escritos en C deben terminar en “.c”.
Por ejemplo:
analisis.c,
compras.c
El primer paso del compilador es realizar una traducción del programa a lenguaje assembler, produciendo un 
archivo objeto con el mismo nombre que el archivo original, pero con la extensión “.obj”. Luego se realiza el 
proceso de linkedición (linkage) del programa, donde se genera un programa ejecutable.
El lenguaje C, fué desarrollado por D. Ritchie en los laboratorios Bell de la AT&T, luego fue estandarizado por un 
comité del ANSI  (American National Standard Institute). Esta estandarización consistió en garantizar que 
cualquier programa se pudiese ejecutar en cualquier computadora; este concepto se lo conoce con el nombre de 
portabilidad. Se originó así el lenguaje ANSI C, que es la variante que se utiliza actualmente mayoritariamente.
Función 
Con el transcurso del tiempo los programas se van modificando para incluir nuevas tareas y por lo tanto crecen de 
tamaño, llegado un punto serán inmanejables. Para evitar este problema surgió el concepto de modularización, que 
es el proceso consistente en dividir un programa muy grande en una serie de módulos mucho más pequeños y 
manejables.
A estos módulos se los ha llamado: subprogramas, subrutinas, procedimientos, funciones, etc. dependiendo del 
lenguaje. En C se usa el concepto de función (function).
De allí que un programa grande se particiona en un conjunto de funciones más pequeñas que son llamadas por el 
programa principal. Y también las funciones pueden llamar a otras funciones más específicas y así sucesivamente.
__________________________________________   102   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
La función main( ) 
Todos los programas escritos en C, tienen un programa principal que es donde comienza la ejecución.. Ese 
programa es una función, con mayor prioridad que las demás y tiene un nombre especial: main() y su estructura es 
(la palabra void es opcional en este caso):
void main(void) 
{
sentencia_1 
sentencia_2 
... 
} 
Con las llaves {...} se especifica en C la forma de agrupar varias sentencias que se comportan como una única 
sentencia llamada sentencia compuesta o bloque. Todo el cuerpo de la función debe ir comprendido entre las llaves 
de apertura y cierre.
Tokens 
En el vocabulario del lenguaje C hay elementos que son llamados componentes sintácticos o tokens  y que son 
utilizados por el compilador para desarmar el texto fuente de un programa y a partir de allí generar el código 
objeto correspondiente. 
Los tokens usados por el C son: palabras clave, identificadores, constantes, cadenas de caracteres, operadores y 
separadores. 
Estos último (separadores) pueden ser espacios en blanco (uno o varios), tabuladores, caracteres de nueva línea, y 
también los comentarios escritos por el programador se usan para separar los otros tokens enumerados 
anteriormente. Todos los demás son ignorados por el compilador.  
 
Identificadores
Uno de los elementos que todo lenguaje de alto nivel posee es la manera de acceder a una posición de memoria de 
manera sencilla.
Como sabemos cada posición de memoria de un procesador puede identificarse mediante un número llamado 
dirección. Pero esa manera no es una forma práctica de hacerlo ya que no se establece ninguna relación entre la 
dirección de memoria usada y el dato almacenado en la misma. Además que la dirección física de un dato varía de 
una ejecución a otra del mismo programa.
Por esa razón para hablar de un dato sin nombrar su dirección en memoria, se realiza el uso de identificadores.
Un identificador es un nombre simbólico que hace referencia a un dato determinado.
De esta manera se vuelve fácil elegir identificadores ya que se elegirán nombres que se originan en la semántica o 
significado que los datos tienen en el mundo real.
Por ejemplo, el identificador llamado edad permite representar la cantidad de años transcurridos desde el 
nacimiento de una persona. Así el programador no necesita nunca preocuparse de direcciones físicas de memoria 
sino que el sistema se encarga por él utilizando una tabla, donde se relaciona cada identificador con el tipo de dato 
que representa y la posición de memoria en la que está almacenado.
identificador 
Tipo de dato 
Dirección de Memoria 
edad 
integer 
1A50 
 
 
Todos los lenguajes de programación, incluido el C, tienen reglas particulares para crear los identificadores. La 
elección de que nombres asignar, tanto a variables como a funciones y programas es trabajo del los usuarios. El 
único recaudo que deben tener en cuenta es el de respetar las reglas del lenguaje y de no utilizar un conjunto de 
palabras reservadas (keywords), que son definidas por el propio lenguaje.
__________________________________________   103   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
En ANSI C las reglas son:
- Un identificador se forma con una secuencia de letras (minúsculas de la a a la z; mayúsculas de la A a la 
Z; y dígitos del 0 al 9).
- El carácter subrayado o underscore (_) se considera como una letra más.
- Un identificador no puede contener espacios en blanco, ni otros caracteres distintos de los citados, como 
por ejemplo (* , ; . : - +, etc.).
- El primer carácter de un identificador debe ser siempre una letra o un (_), es decir, no puede ser un dígito.
- Se hace distinción entre letras mayúsculas y minúsculas.
o​ Por ejemplo: Mundo, mundo y MUNDO son tres identificadores distintos.
- ANSI C permite definir identificadores de hasta 31 caracteres de longitud.
o​ Ejemplos válidos son: universo, distancia1, paso_1, PI, velocidad_del_viento.
o​ Ejemplos inválidos son:1_juego, tiempo-total, pesos$, %compras.
De los identificadores hay que decir que todos aquellos que se utilicen han de ser declarados por el usuario. Esto 
quiere decir que hay que indicar explícitamente qué nombres se van a utilizar en el programa, y qué tipo de dato va 
a representar cada uno de ellos.
Es recomendable elegir los identificadores (nombres de las funciones y/o las variables) de manera tal que se note 
cual es su uso sin importar cuantos caracteres sean necesarios para nombrarlos. Esto facilita la programación y la 
posterior corrección y/o mantenimiento de los programas.
Palabras clave
En C existen una serie de palabras clave (keywords) que el usuario no puede utilizar como identificadores 
(nombres de variables y/o de funciones). Estas palabras son utilizadas  para indicar a la computadora que realice 
diferentes tareas, desde evaluar una comparación hasta definir el tipo de una variable y tienen un significado 
especial para el compilador. El C es un lenguaje que tiene muchas menos palabras clave que otros lenguajes.
Las siguientes son las 32 palabras clave del ANSI C, otros compiladores anexan otras palabras clave. Recordar que 
no se pueden utilizar como identificadores.
auto 
double 
int 
struct 
break 
else 
long 
switch 
case 
enum 
register 
typedef 
char 
extern 
return 
union 
const 
float 
short 
unsigned 
continue 
for 
signed 
void 
default 
goto 
sizeof 
volatile 
do 
if 
static 
while 
​
Constantes
Son usadas en los programas para fijar valores que se mantendrán sin cambio y que pueden ser mencionados en el 
fuente más de una vez. Un ejemplo común es el número π, que vale 3.141592654.  En C existen distintos tipos de 
constantes:
- Constantes numéricas. Son valores numéricos, enteros o de punto flotante. Se permiten también 
constantes octales (números enteros en base 8) y hexadecimales (base 16). 
- Constantes carácter. Cualquier carácter individual encerrado entre apóstrofos (tal como 'a', 'Y', ')', '+', 
etc.) es considerado por C como una constante carácter, o en realidad como un número entero pequeño 
(entre 0 y 255, o entre -128 y 127, según los sistemas). Ese código surge del código ASCII, que establece 
una equivalencia entre cada carácter y un valor numérico correspondiente.
__________________________________________   104   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
- Cadenas de caracteres. Un conjunto de caracteres alfanuméricos encerrados entre comillas es también un 
tipo de constante del lenguaje C, como por ejemplo: "espacio", "Esto es una cadena de caracteres", etc. 
- Constantes simbólicas. Las constantes simbólicas tienen un nombre (identificador) y en esto se parecen a 
las variables. Sin embargo, no pueden cambiar de valor a lo largo de la ejecución del programa. En C se 
pueden definir mediante el preprocesador o por medio de la palabra clave const.
Operadores
Son signos especiales formados por uno u dos caracteres que son interpretados por el compilador como distintas 
operaciones a realizar con las variables y/o constantes escritas en el programa.
El lenguaje C tiene varios y distintos tipos de operadores:
- Aritméticos (+, -, *, /, %) 
- de asignación (=, +=, -=, *=, /=) 
- relacionales (==, <, >, <=, >=, !=) 
- lógicos (&&, ||, !) 
- otros.  
 
Por ejemplo la clásica formula de física utilizada para calcular el espacio recorrido por un móvil se puede expresar 
como sigue utilizando variables y operadores:
espacio = espacio_inicial + 0.5 * aceleracion * tiempo * tiempo.
Separadores
Como ya se dijo anteriormente, los separadores están formados por uno o varios espacios en blanco, tabuladores, y 
caracteres de nueva línea. Su papel es ayudar al compilador a desarmar el programa fuente en cada uno de sus 
tokens.
Se recomienda utilizar espacios en blanco aunque no sean necesarios porque aportan a la legibilidad de los 
programas.
Comentarios
Los comentarios en lenguaje C son usados por el programador para anexar textos en los archivos fuente que 
contienen el código del programa. Se los utiliza para explicar o aclarar cómo está hecho el programa. Sobre todo 
para que pueda ser entendido por otra persona o aún el mismo programador a posteriori cuando tenga que 
modificar el programa. El compilador no toma en cuenta los comentarios.
Se utiliza:
- carácter (/*) para comenzar un comentario. 
- carácter (*/) para finalizar un comentario. 
- No se puede introducir un comentario dentro de otro. 
Por ejemplo:
variable_1 = variable_2; /* En esta línea se asigna a variable_1 el valor
contenido en variable_2 */
El lenguaje ANSI C permite también otro tipo de comentarios, que va en cualquier línea del código detrás de la 
doble barra (//) y hasta el final de la línea. Para comentarios cortos, esta forma es más cómoda que la anterior, pues 
no hay que preocuparse de cerrar el comentario (el fin de línea actúa como cierre). Como contrapartida, si un 
comentario ocupa varias líneas hay que repetir la doble barra (//) en cada una de las líneas.
El mismo ejemplo anterior con este segundo procedimiento quedaría:
variable_1 = variable_2; // En esta línea se asigna a 
// variable_1 el valor 
// contenido en variable_2
__________________________________________   105   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Lenguaje C
En las páginas anteriores ya han ido apareciendo algunas características importantes del lenguaje C. En realidad, el 
lenguaje C está constituido por tres elementos: el compilador, el preprocesador y la librería estándar.
Preprocesador
Es característico de C, no existe en otros lenguajes. Trabaja sobre el programa fuente, antes de que empiece la 
compilación propiamente dicha. Entre otras, permite sustituir macros (sustitución en el programa de constantes 
simbólicas o texto, con o sin parámetros), realizar compilaciones condicionales e incluir archivos.
Por ejemplo, la operación de sustitución de constantes simbólicas tiene relevancia cuando un programa hace uso 
repetidas veces de un determinado valor. Un caso sería el valor 3.141592654, correspondiente al número π. Se 
podría definir una constante simbólica llamada PI cuyo valor es 3.141592654 al comienzo del programa y que se 
escribirá en el código cada vez que haga falta. El preprocesador controla todo el programa al inicio de la 
compilación y reemplaza el texto PI por el texto 3.141592654 en cada parte que aparezca.
Los comandos más utilizados del preprocesador son: #include, #define.
Comando #include
Este comando le indica al preprocesador que cuando lo encuentre reemplace esa línea por el contenido del archivo 
al cual hace mención el #include.
La sintaxis de este comando es:
#include "nombre_del_archivo" 
#include <nombre_del_archivo> 
La diferencia de la sintaxis anterior radica en el directorio de búsqueda de los archivos.
- La primera forma busca el archivo en el directorio actual y posteriormente en el directorio estándar 
de librerías.
- En la segunda forma se busca directamente en el directorio estándar de librerías.
En la práctica, los archivos del sistema (stdio.h, math.h, etc.) se incluyen con la segunda forma, mientras que los 
archivos hechos por el propio programador se incluyen con la primera.
#include <stdio.h> donde stdio proviene de standard-input-output.
Este comando se utiliza para incluir archivos con los prototipos (declaraciones) de las funciones de librería, o con 
módulos de programación y prototipos de las funciones del propio usuario. Estos archivos suelen tener la 
extensión *.h, aunque puede incluirse cualquier tipo de archivo de texto.
Comando #define
El comando #define genera una macro en el código fuente. Las dos maneras de realizar esa definición:
#define NOMBRE texto_a_introducir
#define NOMBRE(parámetros) texto_a_introducir_con_parámetros
Previo a la compilación, el preprocesador analiza el programa y cada vez que encuentra el identificador NOMBRE 
lo reemplaza por el texto que se especifica a continuación en el comando #define. Por ejemplo, si se tienen el 
siguiente código fuente:
#define E 2.718281828459 
 
void main(void) 
{ 
double a;
__________________________________________   106   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
a= (1.+1./E)*(1.-2./E); 
... 
} 
 
Después que trabaje el procesador, quedará reemplazado E por el valor asociado y el código quedará de la 
siguiente manera:
void main(void) 
{ 
double a; 
a= (1.+1./2.718281828459)*(1.-2./2.718281828459); 
... 
} 
 
Otros usos del comando #define es la definición de constantes simbólicas o valores numéricos (ej.: PI, SIZE, etc.) 
que permiten modificarlos fácilmente, y el programa se torna más legible. También  se pueden definir macros con 
parámetros: Por ejemplo, la siguiente macro calcula el cuadrado de cualquier variable o expresión, 
 
#define CUAD(x) ((x)*(x)) 
void main() 
{ 
double a, b; 
... 
a = 7./CUAD(b+1.); 
... 
}
Al reemplazar el preprocesador la línea correspondiente quedará:
a = 7./((b+1.)*(b+1.));
Obsérvese que los paréntesis son necesarios para que el resultado sea el deseado, y que en el comando #define no 
hay que poner el carácter (;).
En la definición de una macro pueden utilizarse macros definidas anteriormente. En muchas ocasiones, las macros 
son más eficientes que las funciones, pues realizan una sustitución directa del código deseado, sin perder tiempo 
en copiar y pasar los valores de los argumentos.
Hay que tener presente que el comando #define:
–​
No define variables.
–​
Sus parámetros no son variables.
–​
En el preprocesamiento no se realiza una revisión de tipos, ni de sintaxis.
–​
Sólo se realizan sustituciones de código.
Por convención, los nombres de las macros se escriben con mayúsculas. Además existen también muchas macros 
predefinidas a algunas variables internas del sistema. Algunos de los ejemplos son:
__DATE__ Fecha de compilación
__FILE__ Nombre del archivo
__LINE__ Número de línea
__TIME__ Hora de compilación
Se puede definir una macro sin texto_a_sustituir para utilizarla como señal a lo largo del programa. Por ejemplo:
#define COMP_HOLA
__________________________________________   107   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Librería estándar
A diferencia de otros lenguajes el lenguajes C por ejemplo no posee por ejemplo, sentencias para entrada y salida 
de datos. Obviamente esas sentencias no pueden faltar, por lo que el mecanismo que se utiliza es el de funciones 
preprogramadas que se entregan junto con el compilador. Estas funciones se presentan en un conjunto de librerías 
de código objeto, que constituyen la llamada librería estándar del lenguaje. La llamada a dichas funciones se hace 
como a otras funciones cualesquiera, y deben ser declaradas antes de ser llamadas por el programa. 
Tipos de datos fundamentales. Variables
El lenguaje C puede trabajar con datos de distinta tipo: texto formado por caracteres alfanuméricos, números 
enteros, números reales con parte entera y parte fraccionaria, etc. Además, algunos de ellos admiten distintos 
números de cifras (rango y/o precisión), posibilidad de ser sólo positivos o de ser positivos y negativos, etc.
char 
signed
unsigned
char
char
Datos 
Enteros
signed int 
unsigned int
Datos 
Reales 
float 
double
- La palabra char  identifica a caracteres (una letra mayúscula o minúscula, un dígito, un carácter 
especial,).
- La palabra int identifica a un número entero.
- float se refiere a un número real (también llamado de punto o coma flotante).
- Los números enteros pueden ser positivos o negativos (signed), o bien esencialmente no negativos 
(unsigned).
- los caracteres tienen un tratamiento muy similar a los enteros y admiten los mismos calificadores.
- las palabras double se refieren al número de cifras o rango de los números reales.
- las palabras signed e int son las opciones por defecto para los números enteros y pueden omitirse.
En C como en otros lenguajes es necesario declarar todas las variables que se vayan a utilizar, sino se lo hiciese se 
produce un mensaje de error en la compilación. La declaración de una variable implica la reserva de memoria de 
acuerdo al tipo especificado en la declaración.
Es posible inicializar (dar un valor inicial) las variables en el momento de la declaración; aunque en determinadas 
circunstancias el compilador da un valor inicial por defecto, mientras que en otros casos no se realiza esta 
inicialización y la memoria asociada con la variable correspondiente contiene lo que se conoce como basura 
(combinaciones sin sentido de unos y ceros, resultado de operaciones anteriores con esa zona de la memoria, para 
otros fines).
Caracteres (tipo char)
Las variables carácter (tipo char) contienen un único carácter y se almacenan en un byte de memoria (8 bits). Con 
8 bits se podrán almacenar 256 valores diferentes (normalmente entre 0 y 255; con ciertos compiladores entre -128 
y 127).
La declaración de variables tipo carácter puede tener la forma:
char nombre;
char nombre1, nombre2, nombre3;
Se puede declarar más de una variable de un tipo determinado en una sola sentencia. Se puede también inicializar 
la variable en la declaración. Por ejemplo, para definir la variable carácter letra y asignarle el valor a, se puede 
escribir:
__________________________________________   108   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
char letra = ’a’;
De aquí en adelante queda definida la variable letra con el valor de la letra a. Recuérdese que el valor ’a’ utilizado 
para inicializar la variable letra es una constante carácter. En realidad, letra se guarda en un solo byte como un 
número entero, el correspondiente a la letra a en el código ASCII, (existe un código ASCII extendido que utiliza 
los 256 valores y que contiene caracteres especiales y caracteres específicos de los alfabetos de diversos países, 
como por ejemplo las vocales acentuadas y la letra ñ para el castellano).
letra = ’z’;
caracter = letra; // Ahora caracter es igual a ’z’
Como una variable tipo char es un número entero pequeño (entre 0 y 255), se puede utilizar el contenido de una 
variable char de la misma forma que se utiliza un entero, por lo que están permitidas operaciones como:
letra = letra + 1;
letra_minúscula = letra_mayúscula + (’a’ - ’A’);
En el primer ejemplo, si el contenido de letra era una a, al incrementarse en una unidad pasa a contener una b. El 
segundo ejemplo es interesante: puesto que la diferencia numérica entre las letras minúsculas y mayúsculas es 
siempre la misma (según el código ASCII), la segunda sentencia pasa una letra mayúscula a la correspondiente 
letra minúscula sumándole dicha diferencia numérica.
Números enteros (tipo int)
Comúnmente una variable tipo int se almacena en 2 bytes (16 bits), aunque algunos compiladores utilizan 4 bytes 
(32 bits). El ANSI C no tiene esto completamente normalizado y existen diferencias entre unos compiladores y 
otros. Los compiladores de Microsoft para PCs utilizan 2 bytes.
Con 16 bits se pueden almacenar 216 = 65536 números enteros diferentes: de 0 al 65535 para variables sin signo, y 
de -32768 al 32767 para variables con signo (que pueden ser positivas y negativas), que es la opción por defecto. 
Este es el rango de las variables tipo int.
Una variable entera (tipo int) se declara, o se declara y se inicializa en la forma:
unsigned int número;
int nota = 10;
En este caso la variable numero podrá estar entre 0 y 65535, mientras que nota deberá estar comprendida entre 
-32768 al 32767. Cuando a una variable int se le asigna en tiempo de ejecución un valor que queda fuera del rango 
permitido (situación de overflow o valor excesivo), se produce un error imprevisible en el resultado, el programa 
no avisa al usuario de dicha circunstancia.
Números enteros (tipo long)
Existe la posibilidad de utilizar enteros con un rango mayor si se especifica como tipo long en su declaración:
long int numero_grande;
como la palabra clave int puede omitirse en este caso,
long numero_grande;
El rango de un entero long puede variar según el computador o el compilador que se utilice, pero lo común es 
utilizar 4 bytes (32 bits) para almacenarlos, por lo que se pueden representar 232 = 4.294.967.296 números enteros 
diferentes. Si se utilizan números con signo, podrán representarse números entre -2.147.483.648 y 2.147.483.647. 
También se pueden declarar enteros long que sean siempre positivos con la palabra unsigned:
unsigned long numero_positivo_muy_grande;
En algunos computadores una variable int ocupa 2 bytes (coincidiendo con short) y en otros 4 bytes (coincidiendo 
con long). Lo que garantiza el ANSI C es que el rango de int no es nunca menor que el de short ni mayor que el de 
long.
__________________________________________   109   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Números reales (tipo float)
En muchas aplicaciones hacen falta variables reales, capaces de representar magnitudes que contengan una parte 
entera y una parte fraccionaria o decimal. Estas variables se llaman también de punto flotante. Si lo 
consideramos, en base 10 y con notación científica, estas variables se representan por medio de la mantisa, que es 
un número mayor o igual que 0.1 y menor que 1.0, y un exponente que representa la potencia de 10 por la que hay 
que multiplicar la mantisa para obtener el número considerado. Por ejemplo, π se representa como 0.3141592654 · 
101.
Tanto la mantisa como el exponente pueden ser positivos y negativos.
Los computadores trabajan en base 2. Por eso un número de tipo float se almacena en 4 bytes (32 bits), utilizando 
24 bits para la mantisa (1 para el signo y 23 para el valor) y 8 bits para el exponente (1 para el signo y 7 para el 
valor). Es interesante ver qué clase de números de punto flotante pueden representarse de esta forma. En este caso 
hay que distinguir el rango de la precisión. La precisión hace referencia al número de cifras con las que se 
representa la mantisa: con 23 bits el número más grande que se puede representar es,
223 = 8.388.608
lo cual quiere decir que se pueden representar todos los números decimales de 6 cifras y la mayor parte –aunque 
no todos– de los de 7 cifras (por ejemplo, el número 9.213.456 no se puede representar con 23 bits). Por eso se 
dice que las variables tipo float tienen entre 6 y 7 cifras decimales equivalentes de precisión.
Respecto al exponente de dos por el que hay que multiplicar la mantisa en base 2, con 7 bits el número más grande 
que se puede representar es 127. El rango vendrá definido por la potencia,
2127 = 1.7014 · 1038
lo cual indica el número más grande representable de esta forma. El número más pequeño en valor absoluto será 
del orden de
2-128 = 2.9385 · 10-39
Las variables tipo float se declaran de la forma:
float numero_real;
Las variables tipo float pueden ser inicializadas en el momento de la declaración, de forma análoga a las variables 
tipo int.
Números reales (tipo double)
Las variables tipo float tienen un rango y  una precisión muy limitada, insuficiente para la mayor parte de los 
cálculos técnicos y científicos. Este problema se soluciona con el tipo double, que utiliza 8 bytes (64 bits) para 
almacenar una variable. Se utilizan 53 bits para la mantisa (1 para el signo y 52 para el valor) y 11 para el 
exponente (1 para el signo y 10 para el valor). La precisión es en este caso,
252 = 4.503.599.627.370.496
lo cual representa entre 15 y 16 cifras decimales equivalentes. Con respecto al rango, con un exponente de 10 bits 
el número más grande que se puede representar será del orden de 2 elevado a 2 elevado a 10 (que es 1024):
21024 = 1.7977 · 10308
Las variables tipo double se declaran de forma análoga a las anteriores:
double real_grande; 
Operadores, expresiones y sentencias
Operadores
Como se mencionó anteriormente, un operador es un carácter o grupo de caracteres que actúa sobre una, dos o 
más variables para realizar una determinada operación con un determinado resultado.
__________________________________________   110   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
De acuerdo a que ellos operen sobre uno, dos o tres operandos los operadores se los clasifica en unarios, binarios y 
ternarios, respectivamente.
Uno de los aspectos más fuerte del lenguaje C es que existen muchos operadores de diversos tipos.
Operadores aritméticos
Ellos son los más sencillos y todos son operadores binarios. En el lenguaje C algunos de estos operadores son:
- Suma: + 
- Resta: - 
- Multiplicación: * 
- División: / 
 
Los operadores aritméticos participan de expresiones como el siguiente polinomio de grado 2 en la variable x:
5.0 + 3.0*x - x*x/2.0
Una expresión es un conjunto de variables y constantes relacionadas mediante distintos operadores que pueden 
contener paréntesis (...) que agrupan a algunos de sus términos.
A su vez puede haber paréntesis contenidos dentro de otros paréntesis. El significado de los paréntesis coincide 
con el habitual en las expresiones matemáticas. En ocasiones, la introducción de espacios en blanco mejora la 
legibilidad de las expresiones.
Operadores de asignación
Los operadores de asignación mueven a la zona de memoria donde está definida la variable el resultado de una 
expresión o el valor de otra variable. El operador de asignación por excelencia es el operador de igualdad (=), que 
no debe ser confundido con la igualdad matemática.
nombre_de_variable = expresion;
Su funcionamiento es:
- se evalúa expresión. 
- el resultado se copia en nombre_de_variable, reemplazado al valor que hubiera en esa posición de 
memoria. 
Ejemplo:
variable = variable + 1;
Función:
Incrementar el valor de variable en una unidad.
Resolución:
- se toma el valor de variable contenido en la memoria, 
- se le suma una unidad, 
- el valor resultante se coloca en memoria sustituyendo al valor que había 
anteriormente. 
Del ejemplo anterior podemos deducir que una variable puede aparecer a la izquierda y a la derecha del operador 
(=) pero a la izquierda del operador de asignación (=) no puede haber nunca una expresión. Es incorrecto escribir:
a + b = c; // incorrecto
Operadores relacionales
Los operadores relacionales permiten verificar si se cumplen o no ciertas condiciones  produciendo un resultado u 
otro según se cumplan o no algunas de esas condiciones.
Algunas de las palabras o formas de indicar si se cumple o no una determinada condición (en inglés) son:
- Yes/no,
- On/off,
__________________________________________   111   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
- True/false.
Esta última forma es la que más se utiliza en informática. Por lo tanto, si una condición se cumple, el resultado es 
true; en caso contrario, el resultado es false.
En C un 0 representa la condición de false, y cualquier número distinto de 0 equivale a la condición true. Cuando 
el resultado de una expresión es true y hay que asignar un valor concreto distinto de cero, por defecto se toma un 
valor unidad.
Los operadores relacionales de C son:
- Igual que: ==
- Menor que: <
- Mayor que: >
- Menor o igual que: <=
- Mayor o igual que: >=
- Distinto que: !=
Todos los operadores relacionales son operadores binarios (tienen dos operandos). Su forma general es:
expresion1 op expresion2
donde op es uno de los operadores (==, <, >, <=, >=, !=).
Funcionamiento:
- se evalúan expresion1 y expresion2,
- se comparan los valores resultantes. Si la condición representada por el operador relacional se 
cumple, el resultado es 1; si la condición no se cumple, el resultado es 0.
Ejemplos:
- (2==1) // resultado=0 porque la condición no se cumple 
- (3<=3) // resultado=1 porque la condición se cumple 
- (3<3) // resultado=0 porque la condición no se cumple 
- (1!=1) // resultado=0 porque la condición no se cumple
Operadores lógicos
Los operadores lógicos son operadores binarios que permiten combinar los resultados de los operadores 
relacionales, comprobando que se cumplen simultáneamente varias condiciones, que se cumple una u otra, etc.
El lenguaje C tiene dos operadores lógicos:
- el operador Y (&&)
- el operador O (||)
En inglés son los operadores and y or. Su forma general es:
expresion1 || expresion2
expresion1 && expresion2
Funcionamiento:
- el operador && devuelve un 1 si tanto expresion1 como expresion2 son verdaderas (o distintas de 0), 
y 0 en caso contrario, es decir si una de las dos expresiones o las dos son falsas (iguales a 0);
- el operador || devuelve 1 si al menos una de las expresiones es cierta.
Los operadores && y || se pueden combinar entre sí quizás agrupados entre paréntesis.
Ejemplos:
- (2==1) || (-1==-1) // el resultado es 1
__________________________________________   112   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
- (2==2) && (3==-1) // el resultado es 0 
- ((2==2) && (3==3)) || (4==0) // el resultado es 1 
- ((6==6) || (8==0)) && ((5==5) && (3==2)) // el resultado es 0
Reglas de precedencia y asociatividad
El resultado de una expresión depende del orden en que se ejecutan las operaciones. Considérese la expresión:
3 + 4 * 2
- si se realiza primero la suma (3+4) y después el producto (7*2), el resultado es 14;
- si se realiza primero el producto (4*2) y luego la suma (3+8), el resultado es 11.
Para evitar esta ambigüedad en el resultado de cada expresión, es necesario definir las reglas que especifican el 
orden con el que se ejecutan las expresiones de C.
Existe dos tipos de reglas para determinar este orden de evaluación y se denominan reglas de precedencia y de 
asociatividad:
- el orden de evaluación puede modificarse por medio de paréntesis,
- siempre se realizan primero las operaciones encerradas en los paréntesis más interiores.
- los distintos operadores de C se ordenan según su distinta precedencia o prioridad,
- para operadores de la misma precedencia o prioridad,
- en algunos el orden de ejecución es de izquierda a derecha, y otros de derecha a izquierda. A 
este orden se le llama asociatividad.
Tabla Precedencia Asociatividad 
() [] 
izquierda a derecha 
+(unario) -(unario) 
derecha a izquierda 
* / % 
izquierda a derecha 
+ - 
izquierda a derecha 
< <= > >= 
izquierda a derecha 
== != 
izquierda a derecha 
&& 
izquierda a derecha 
|| 
izquierda a derecha 
= 
derecha a izquierda 
 
Aplicando la Tabla anterior al ejemplo podemos observar  que el operador (*) tiene precedencia sobre el operador 
(+), por lo que ante la ausencia de paréntesis, el resultado de la expresión 3+4*2 es 11 y no 14.
Los operadores binarios (+) y (-) tienen igual precedencia, y asociatividad de izquierda a derecha. Por ejemplo, en 
la siguiente expresión:
a-b+d*5.0+u/2.0 // (((a-b)+(d*5.0))+(u/2.0))
El orden de evaluación es el indicado por los paréntesis en la parte derecha de la línea (Las últimas operaciones en 
ejecutarse son las de los paréntesis más exteriores).
Sentencias
Las sentencias son unidades completas, ejecutables en sí mismas que incorporan expresiones como componentes 
elementales. Estas y otros tipos de sentencias incorporan expresiones aritméticas, lógicas o generales como 
componentes de las mismas.
__________________________________________   113   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Sentencias simples
Una sentencia simple es una expresión de algún tipo terminada con un carácter (;). Un caso típico son las 
declaraciones o las sentencias aritméticas. Por ejemplo:
float real; 
espacio = espacio_inicial + velocidad * tiempo;
Sentencia vacía ó nula
A veces se requiere en un programa escribir una sentencia que ocupe un lugar, pero que no realice ninguna tarea. 
A esta sentencia se le denomina sentencia vacía y está formada por un simple carácter (;). Por ejemplo:
;
Sentencias compuestas o bloques
Otras veces se necesita escribir varias sentencias juntas en el programa donde debería haber una sola. Esto se 
realiza por medio de sentencias compuestas. Una sentencia compuesta es un conjunto de declaraciones y de 
sentencias agrupadas dentro de llaves {...}. También se conocen con el nombre de bloques. Una sentencia 
compuesta puede incluir otras sentencias, simples y compuestas. Un ejemplo de sentencia compuesta es el 
siguiente:
{ 
int i = 1, j = 3, k; 
double masa; 
masa = 3.0; 
k = y + j; 
} 
Control del flujo de ejecución
Se podría decir que inicialmente, las sentencias de un programa en C se ejecutan secuencialmente, o sea, una 
detrás de la otra empezando por la primera y acabando por la última. El lenguaje C dispone de varias sentencias 
para modificar este flujo secuencial de la ejecución.
Las más utilizadas se agrupan en:
- las bifurcaciones, que permiten elegir entre dos o más opciones según ciertas condiciones,  
- los bucles, que permiten ejecutar repetidamente un conjunto de instrucciones tantas veces como se 
desee, cambiando o actualizando ciertos valores.
Bifurcaciones
Sentencia if 
Esta sentencia de control permite ejecutar o no una sentencia simple o compuesta según se cumpla o no una 
determinada condición. Tiene la siguiente forma general:
if (expresion) 
sentencia; 
Funcionamiento:
- se evalúa expresion. 
- si el resultado es true (#0), se ejecuta sentencia; 
- si el resultado es false (=0), se salta sentencia y se prosigue en la línea siguiente.
Hay que recordar que sentencia puede ser una sentencia simple o compuesta (bloque { ... }).
Sentencia if …. else 
Esta sentencia permite realizar una bifurcación, ejecutando una parte u otra del programa según se cumpla o no 
una cierta condición. Su forma general es:
__________________________________________   114   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
if (expresion) 
sentencia_1; 
else 
sentencia_2; 
Funcionamiento:
- se evalúa expresion. 
- si el resultado es true (#0), se ejecuta sentencia_1 y se prosigue en la línea siguiente a 
sentencia_2; 
- si el resultado es false (=0), se salta sentencia_1, se ejecuta sentencia_2 y se prosigue 
en la línea siguiente.
Hay que indicar aquí también que sentencia_1 y sentencia_2 pueden ser sentencias simples o compuestas (bloques 
{ ... }).
Bucles
En el lenguaje C existen varias sentencias que permiten repetir una serie de veces la ejecución de unas líneas de 
código. Esta repetición se realiza, bien un número determinado de veces, bien hasta que se cumpla una 
determinada condición de tipo lógico o aritmético. De modo genérico, a estas sentencias se les denomina bucles.
Sentencia while 
Esta sentencia permite ejecutar repetidamente una sentencia o bloque de sentencias mientras se cumpla una 
determinada condición,. Su formato es:
while (expresion_de_control) 
sentencia; 
 
Funcionamiento:
- se evalúa expresion_de_control  
- si el resultado es false se salta sentencia y se prosigue la ejecución. 
- si el resultado es true se ejecuta sentencia y se vuelve a evaluar expresion_de_control 
(donde debe haber alguna variable de las que intervienen en expresion_de_control que 
habrá sido modificada para que el  bucle no se repita indefinidamente). La ejecución de 
sentencia prosigue hasta que expresion_de_control se hace false, en cuyo caso la 
ejecución continúa en la línea siguiente a sentencia.
En otras palabras, sentencia se ejecuta repetidamente mientras expresion_de_control sea true, y se deja de ejecutar 
cuando expresion_de_control se hace false.
Obsérvese que en este caso el control para decidir si se sale o no del bucle está antes de sentencia, por lo que es 
posible que sentencia no se llegue a ejecutar ni una sola vez.
Tipos de datos derivados
Vectores, matrices y cadenas de caracteres
Un array es una estructura capaz de manejar una gran cantidad de datos del mismo tipo bajo un mismo nombre o 
identificador. Es conocido como arreglo, vector o matriz.
Declaración de un vector:
- tipo nombre[numero_elementos];.
Ejemplo:
- int notas[10];
Funcionamiento:
- se reserva espacio para 10 variables de tipo int.
__________________________________________   115   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
- las 10 variables se llaman notas
- se accede a cada una mediante un subíndice, que es una expresión entera escrita a 
continuación del nombre entre corchetes [...].
- los elementos se numeran desde 0 hasta (numero_elementos-1).
El tamaño de un vector puede definirse con cualquier expresión constante entera. En C no se puede operar con 
todo un vector o toda una matriz como una única entidad, sino que hay que tratar sus elementos uno a uno por 
medio de un bucle, en nuestro caso podría ser un while. Los elementos de un vector se utilizan en las expresiones 
de C como cualquier otra variable.
Otros ejemplos:
- notas[5] = 8; //se asigna el valor 8 al sexto elemento del 
vector 
- notas[9] = 30. * notas[5];// 
- notas[0] = 3. * notas[9] - notas[5]/notas[9]; 
- notas[3] = (notas[0] + notas[9])/notas[3]; 
 
Una cadena de caracteres es un vector de tipo char, Las cadenas suelen contener texto (nombres, frases, etc.), y 
éste se almacena en la parte inicial de la cadena (a partir de la posición cero del vector). Para separar la parte que 
contiene texto de la parte no utilizada, se utiliza un carácter fin de texto que es el carácter nulo ('\0') según el 
código ASCII. Este carácter se introduce automáticamente al leer o inicializar las cadenas de caracteres.
Ejemplo:
char ciudad[20] = "Trelew";
Funcionamiento:
- donde a los 6 caracteres del nombre de la ciudad se añade un séptimo: el '\0'.
- el resto del espacio reservado –hasta la posición ciudad[19]– no se utiliza.
- de modo análogo, una cadena constante tal como "mar" ocupa 4 bytes (para las 3 letras y el '\0').
Las matrices se declaran de forma análoga, con corchetes independientes para cada subíndice.
Declaración:
tipo nombre[numero_filas][numero_columnas];
Funcionamiento:
- donde tanto las filas como las columnas se numeran también a partir de 0.
- la forma de acceder a los elementos de la matriz es utilizando su nombre, seguido de las expresiones 
enteras correspondientes a los dos subíndices, entre corchetes.
En C pueden definirse arrays con tantos subíndices como se desee.
Ejemplo:
double a[3][5][7];
declara una hipermatriz con tres subíndices, que podría verse como un conjunto de 3 matrices de dimensión (5x7).
Inicialización de vectores y matrices
La inicialización de un array se puede hacer de varias maneras:
- Declarando el array como tal e inicializándolo luego mediante lectura o asignación por medio de un bucle.
- Inicializándolo en la misma declaración, en la forma:
double v[6] = {1., 2., 3., 3., 2., 1.}; 
float d[] = {1.2, 3.4, 5.1}; // d[3] está implícito 
int f[100] = {0}; // todo se inicializa a 0
__________________________________________   116   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
int h[10] = {1, 2, 3}; // restantes elementos a 0 
int mat[3][2] = {{1, 2}, {3, 4}, {5, 6}};
donde es necesario poner un punto decimal tras cada cifra, para que ésta sea reconocida como un valor de tipo
float o double.
Funciones de entrada/salida
A diferencia de otros lenguajes, C no dispone de sentencias de entrada/salida. En su lugar se utilizan funciones 
contenidas en la librería estándar y que forman parte integrante del lenguaje.
Las funciones de entrada/salida (Input/Output) son un conjunto de funciones, incluidas con el compilador, que 
permiten a un programa recibir y enviar datos al exterior. Para su utilización es necesario incluir, al comienzo del 
programa, el archivo stdio.h en el que están definidos sus prototipos:
#include <stdio.h>
donde stdio proviene de standard-input-output.
Función printf()
La función printf() imprime en la unidad de salida (el monitor, por defecto), el texto, las constantes y variables 
que se indiquen. La forma general de esta función se puede estudiar viendo su prototipo:
Ejemplo:
int printf("cadena_de_control", tipo arg1, tipo arg2, ...)
Funcionamiento:
- la función printf() imprime el texto contenido en cadena_de_control junto con el valor de los otros 
argumentos, de acuerdo con los formatos incluidos en cadena_de_control.
- los puntos suspensivos (...) indican que puede haber un número variable de argumentos.
- cada formato comienza con el carácter (%) y termina con un carácter de conversión.
Ejemplo:
int legajo; 
float nota; 
printf("El alumno con legajo nº: %d obtuvo la nota %f\n", legajo, nota);
Funcionamiento:
- se imprimen 2 variables (legajo y nota) con los formatos (%d y %f), correspondientes a los tipos (int, y 
float), respectivamente.
- la cadena de control se imprime con el valor de cada variable intercalado en el lugar del formato 
correspondiente.
Caracteres de conversión para la función printf().
Carácter 
Tipo de argumento 
Carácter 
Tipo de argumento 
d, i 
int decimal 
o 
octal unsigned 
U 
int unsigned 
x, X 
hex. unsigned 
C 
Char 
s 
cadena de char 
F 
Float notación decimal 
e, g 
float not. científ. o breve 
 
 
 
 
 
Lo importante es considerar que debe haber correspondencia uno a uno (el 1º con el 1º, el 2º con el 2º, etc.) entre 
los formatos que aparecen en la cadena_de_control y los otros argumentos (constantes, variables o expresiones).
__________________________________________   117   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Entre el carácter % y el carácter de conversión puede haber, por el siguiente orden, uno o varios de los elementos 
que a continuación se indican:
- Un número entero positivo, que indica el ancho mínimo del campo en caracteres.
- Un signo (-), que indica alineamiento por la izquierda (el defecto es por la derecha).
- Un punto (.), que separa el ancho de la precisión.
- Un número entero positivo, la precisión, que es el nº máximo de caracteres a imprimir en un string, el 
nº de decimales de un float o double, o las cifras mínimas de un int.
- Un cualificador: una (l) double
Algunos ejemplos de uso de la función printf().
Ejemplo:
printf("Con cien cañones por banda,\nviento en popa a toda vela,\n");
El resultado serán dos líneas con las dos primeras estrofas de la famosa poesía. No es posible partir 
cadena_de_control en varias líneas con caracteres intro, por lo que en este ejemplo podría haber problemas para 
añadir más estrofas.
Otra manera sería:
printf("%s\n%s\n%s\n%s\n",
"Con cien cañones por banda,",
"viento en popa a toda vela,",
"no cruza el mar sino vuela,",
"un velero bergantín.");
Aquí se escriben 4 cadenas constantes de caracteres que se introducen como argumentos, con formato %s y con los 
correspondientes saltos de línea. Un ejemplo que contiene una constante y una variable como argumentos es el 
siguiente:
printf("En el año %s ganó %f pesos.\n", "1993", beneficios);
donde el texto 1993 se imprime como cadena de caracteres (%s), mientras que beneficios se imprime con formato 
de variable float (%f). Es importante hacer corresponder bien los formatos con el tipo de los argumentos, pues si 
no los resultados pueden ser muy diferentes de lo esperado.
La función printf() tiene un valor de retorno de tipo int, que representa el número de caracteres escritos en esa 
llamada.
G. Ingravallo  - 2010
__________________________________________   118   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
​ Capítulo 15
SISTEMAS OPERATIVOS
En este capítulo veremos dos Sistemas Operativos distintos: Linux y Windows con sus características 
particulares:
LINUX
Linux es un sistema operativo, compatible Unix. Dos características muy peculiares lo 
diferencian del resto de sistemas que podemos encontrar en el mercado, la primera, es que 
es libre, esto significa que no tenemos que pagar ningún tipo de licencia a ninguna casa 
desarrolladora de software por el uso del mismo, la segunda, es que el sistema viene 
acompañado del código fuente.  
Tux es la mascota oficial de LINUX.
Una versión muy usada de la familia de Linux es Ubuntu:  una 
distribución GNU/Linux basada en Debian GNU/Linux que proporciona un 
sistema operativo actualizado y estable para el usuario medio, con un fuerte enfoque en la 
facilidad de uso e instalación del sistema. .(Wikipedia, acceso: 14/2/2011) 
 
 
El sistema lo forman el núcleo del sistema (kernel) más un gran número de programas/bibliotecas que hacen 
posible su utilización. 
​
Características principales de Linux
- Multitarea: La palabra multitarea describe la habilidad de ejecutar varios programas al mismo tiempo. 
LINUX utiliza la llamada multitarea preventiva, la  cual asegura que todos los programas que se están 
utilizando en un momento dado serán ejecutados, siendo el sistema operativo el encargado de ceder 
tiempo de microprocesador a cada programa. 
- Multiusuario: Muchos usuarios usando la misma máquina al mismo tiempo. 
- Multiplataforma: Las plataformas en las que en un principio se puede utilizar Linux son 386-, 486-. 
Pentium, Pentium Pro, Pentium II,Amiga y Atari, también existen versiones para su utilización en otras 
plataformas, como Alpha, ARM, MIPS, PowerPC y SPARC. 
- Multiprocesador: Soporte para sistemas con más de un procesador está disponible para Intel y SPARC.
__________________________________________   119   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Jerarquía de directorios en Linux
En Linux existe un sistema de archivos que carga y contiene todos los directorios, redes, programas, particiones, 
dispositivos, etc. que el sistema sabe reconocer o identificar. Este sistema de ficheros y directorios, tiene como 
base al carácter (/); ese mismo carácter sirve también para demarcar los directorios, como por ejemplo: 
"/home/usuario/imagen.jpg". El directorio especificado por una ruta consistente sólo por este carácter contiene 
toda la jerarquía de los directorios que constituyen todo el sistema. A este directorio suele llamársele directorio 
raíz. En Linux, a los discos no se les asigna una letra como en Windows (p.e. "C:"), sino que se les asigna un 
directorio de la jerarquía del directorio raíz (/), como por ejemplo: "/media/floppy".
Descripción de Comandos Básicos de Linux
Los comandos Linux son necesarios para tener un dominio del sistema operativo. La línea de comandos es la 
manera más directa de enviar órdenes a su máquina. Los comandos del Sistema Operativo (S.O.), son palabras 
simples, provenientes del inglés que hacen que la computadora ejecute acciones relacionadas con las unidades de 
disco que haya instaladas en el sistema. 
La consola o intérprete de comandos.
Un intérprete de comandos, intérprete de órdenes, terminal, consola, shell o su acrónimo en inglés CLI (por 
Command Line Interface) es un programa informático que actúa como interfaz de usuario para comunicarlo con 
S.O. mediante una ventana que espera órdenes escritas por el usuario en el teclado, las interpreta y las entrega al 
S.O. para su ejecución. La respuesta del S.O. se muestra al usuario en la misma ventana. A continuación, el 
programa shell queda esperando más instrucciones. Se interactúa con la información de la manera más sencilla 
posible, sin gráficas, sólo el texto crudo.(Wikipedia, acceso: 14/8/2010)
Prompt
Se llama prompt al carácter o conjunto de caracteres que se muestran en una línea de comandos para indicar que 
está a la espera de órdenes. Éste puede variar dependiendo del intérprete de comandos y suele ser configurable. 
.(Wikipedia, acceso: 14/2/2011)
En la siguiente imagen correspondiente a una consola, el prompt está representado por  “ /home/Emilio – >”  a 
continuación se encuentra la orden correspondiente (la primera que se ve es: df) y luego la respuesta a la orden 
hasta ver nuevamente el prompt.
​
A continuación para nuestros ejemplos tomaremos como prompt a “#”
Comandos Linux de manipulación de archivos y directorios
Las unidades de disco son unidades de almacenamiento de información, las únicas entidades que pueden ser 
almacenadas en un disco, desde el punto de vista del S.O., son los archivos.  
Los nombres de archivos (o ficheros) en Linux distinguen mayúsculas de minúsculas, esto es, son "case sensitive". 
Los archivos README, readme, REadme y rEadme por ejemplo son archivos distintos y por lo tanto al ser 
nombres distintos pueden estar en el mismo directorio.
__________________________________________   120   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Nombres de archivos en Linux
En Linux los ficheros no tienen porqué tener una extensión. La suelen tener a modo orientativo, pero no es en 
absoluto necesario. Linux sabe qué contiene cada archivo independientemente de cuál sea su extensión. Por 
comodidad, podremos llamar a todos nuestros archivos de texto con la extensión .texto, o a todos nuestros 
documentos con la extensión .documento, de esta manera, podremos luego agruparlos más fácilmente.  
Los ficheros y directorios ocultos en Linux comienzan su nombre por un punto (.)  
Los nombres de archivos o directorios pueden ser muy largos, de más de 200 caracteres, lo cual nos da bastante 
flexibilidad para asociar el nombre de un archivo a lo que contiene. No obstante, hay ciertos caracteres que nunca 
se deberían utilizar a la hora de nombrar un archivo. Uno de ellos es el espacio, nunca llamaremos a un fichero con 
un nombre que contenga un espacio. Tampoco son recomendados otros caracteres raros como signos de 
puntuación (a excepción del punto), acentos o la ñ. En algunos casos Linux ni siquiera nos permitirá usarlos. Los 
recomendables son las letras A-Z, a-z, los números (0-9), el punto, el guión (-) y el guión bajo (_) para nombrar un 
archivo. Los acentos y la ñ tampoco se recomiendan.
Directorios o Carpetas
Se ha dicho que en un disco los únicos elementos que pueden ser depositados (figurativamente) son los archivos. 
Cada archivo posee un nombre. El S.O. no permite que existan dos ficheros con un mismo nombre. 
En los discos es posible configurar una estructura u organización del tipo “caja dentro de caja” de acuerdo al 
siguiente gráfico, suponiendo que nos encontramos en el disco C:
Organización de un disco
Estos elementos de organización dentro de un disco, reciben el nombre de directorios. Cada uno de ellos puede 
contener archivos u otros directorios. 
Debe entonces recordarse que:
 ​ El archivo es el elemento que puede almacenarse en un disco. 
 ​ El Directorio es una entidad de organización en el disco. 
 
En un disco al que se le ha dado formato, existe desde el inicio un primer directorio llamado RAIZ o ROOT. 
En este primer directorio pueden almacenarse archivos o crear nuevos directorios que dependen del raíz (como en 
la figura). Estos nuevos directorios a su vez, pueden contener archivos y/o directorios. 
Tal organización da lugar a un esquema o estructura en árbol como la siguiente:
RAIZ
INTRO                                         ARQUI 
           
                                NOTAS
__________________________________________   121   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Obsérvese que del directorio raíz, dependen dos directorios: INTRO y ARQUI. A su vez, de INTRO depende un 
directorio denominado NOTAS. Los nombres de los directorios en estos esquemas, se los ha consignado en 
MAYÚSCULAS para distinguirlos de los nombres de los archivos que se han consignado en minúsculas. 
Los nombres para los directorios, poseen las mismas reglas que los nombres de archivos.
Comandos sobre Directorios
- Para crear un directorio  
Se debe escribir: 
 
# mkdir nombre 
 
Donde mkdir (Make Dir) es el comando de creación de un directorio y nombre es aquel que se le quiere otorgar. 
 
- Para eliminar un directorio  
Se debe escribir: 
 
 #  rmdir  – r nombre 
 
Donde rmdir (Remove dir) es el comando de eliminación de un directorio y nombre es el que se quiere eliminar,
si utilizamos la opción  – r entonces borra todos los subdirectorios que contenga el directorio nombre. 
Dentro de cada directorio se pueden colocar archivos. Estos archivos pueden ser creados o copiados desde otros
directorios. 
- Para cambiar de uno a otro directorio  
Se debe escribir: 
 
 # cd nombre 
 
Donde cd (Change Dir) es el comando de cambio de directorio y nombre es el del directorio al que se desea
mudar. Con este formato del comando, solo se puede avanzar en la estructura en árbol. Por ejemplo: 
# cd  /INTRO 
 
 
Para ir a un directorio específico se lo puede hacer escribiendo toda la Ruta absoluta, esto es, la cadena de
dependencia en la estructura en árbol. En nuestro ejemplo para ir al directorio ARQUI (estando ubicados en 
INTRO) se debe escribir: 
 
# cd /ARQUI 
 
Para volver desde cualquier directorio al Raíz se debe escribir: 
 
# cd / 
 
El prompt en condiciones normales, indica el directorio en el que se está situado con su ruta absoluta. Este
directorio es el que se toma  por defecto y lo llama directorio actual. 
Si se ejecutara un comando ls se obtendría exclusivamente el listado de los archivos del directorio actual: 
 
# ls 
. 
.. 
fecha     dbf 
 
(en este ejemplo, fecha.dbf  es el único archivo que existe en el directorio en cuestión.)
Comando sobre Disco
- Para cambiar de disco
__________________________________________   122   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Debe invocárselo por su nombre. Por ejemplo: 
 
#   <ENTER>    No olvidarse de pulsar Enter, en lo sucesivo no se indica. 
 
Luego de solicitar el cambio de directorio (cd change dir) al disco D: la línea de comando luce así: 
 
D:/>_          (indicando el disco “activo” o por defecto.) 
 
Atención: Para que se pueda invocar una unidad externa (discos extraíbles o unidad de CD), debe existir un
elemento del tipo requerido y con formato, insertado en el compartimento, caso contrario será indicado un error 
y deberá volverse al disco C:
Comandos para Archivos
- Para poder  ver qué archivos contiene un disco  
 
Se debe ejecutar el comando: 
 
# ls  <ENTER>    (luego de escribir cada comando debe pulsarse la tecla Enter) 
 
Este comando lista todos los archivos que contiene el disco.  Si se le agrega: –l (lista detalles) –a (lista el directorio
padre y el actual). 
 
- Para copiar archivos de un directorio a otro, se emplea el siguiente comando: 
 
#  cp /INTRO/NOTAS/nombre.txt  /ARQUI 
 
El comando cp copia un archivo desde una fuente hacia un destino. Obsérvese que en general, se debe indicar la
ruta completa del directorio donde reside el archivo fuente, el propio archivo fuente y  la ruta del directorio de 
destino. No es necesario indicar el nombre del archivo de destino (a no ser que se le quiera cambiar el nombre). 
Existen otras excepciones a la regla general: 
Si el archivo a copiar, reside en el directorio actual, se puede obviar la ruta del archivo fuente. En este caso el S.O.
tomará la ruta por defecto que es la del directorio actual. En nuestro caso ejemplo, estando en INTRO: 
 
# cp notas.txt  /INTRO/NOTAS​ ​
copia notas.txt  al directorio /INTRO/NOTAS 
 
- Para renombrar un archivo 
 
Si en el directorio actual ejecutamos: 
# rn  notas.txt  notas.bak                       y luego: 
# ls 
. 
.. 
parcial1.doc 
notas.bak 
 
En el nuevo listado solicitado mediante ls, observamos que notas.txt cambio de nombre a notas.bak 
El comando rn (rename), renombra archivos sin modificar su posición en el disco ni su contenido. 
Se puede renombrar archivos mientras se copian en una acción escribiendo completas la ruta y el nombre del
destino. Por ejemplo: 
 
# cp parcial1.doc /parcial.txt​
Se copia con nombre parcial.txt en el directorio RAIZ de C:. 
 
En general todos los comandos de LINUX que efectúan acciones sobre archivos, pueden utilizar la ruta adecuada
para ejercer acciones sobre otros directorios distintos al actual. Ejemplos: 
 
# cp /Parcial.txt  /INTRO/NOTAS/Parcial.doc
__________________________________________   123   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Este comando copia desde el RAIZ el archivo parcial.txt hacia el directorio INTRO/NOTAS cambiándole el
nombre en una sola acción. Obsérvese que se ha hecho una acción que involucra dos directorios que no son el 
actual, por defecto. Otro ejemplo: 
 
# ls  C:/INTRO/NOTAS            Desde INTRO, se lista el contenido de INTRO/NOTAS 
 
- Para eliminar un archivo 
 
El comando rm  (remove) elimina un archivo de un directorio. Ejemplo: 
 
# rm  /INTRO/NOTAS/fecha.dbf            Desde INTRO, se elimina el archivo fecha.dbf 
 
Este comando puede prescindir de la ruta si la acción se desea sobre el directorio actual. 
​
WINDOWS
Anunciado en 1983, Microsoft comercializó por primera vez el entorno operativo 
denominado Windows en noviembre de 1985 como complemento para MS-DOS, en 
respuesta al creciente interés del mercado en una interfaz gráfica de usuario (GUI). 
Microsoft Windows llegó a dominar el mercado de ordenadores personales del mundo, 
superando a Mac OS, el cual había sido introducido previamente a Windows. En 
octubre de 2009, Windows tenía aproximadamente el 91% de la cuota de mercado de 
sistemas operativos en equipos cliente que acceden a Internet (Wikipedia, acceso: 14/8/2010).
Manejo de la Consola del Sistema
La siguiente es una guía básica acerca de los fundamentos de operación del S.O. desde la línea de comandos.
Descripción de Comandos Básicos
Cuando se enciende la computadora, en condiciones normales un programa comienza a correr automáticamente 
prácticamente desde el inicio. Este programa es el Sistema Operativo de disco en alguna de sus versiones. Luego 
de la inicialización y verificación de determinados elementos en la máquina, la pantalla presenta en la última línea 
escrita, lo siguiente: 
 
C:\>_ 
 
La línea de subrayado, último caracter escrito, se presenta intermitente. Esta es la presentación del inductor que 
indica al usuario que la computadora está lista para aceptar comandos. 
Los comandos del S.O., son palabras simples, provenientes del inglés que hacen que la computadora ejecute 
acciones relacionadas con las unidades de disco que haya instaladas en el sistema. 
Las unidades de disco son denominadas con las letras del abecedario comenzando por A. Las letras A y B, se 
reservan para las unidades de discos removibles (Floppy disks) aun cuando actualmente ya no se usa esta 
tecnología y las PC ya no traen normalmente unidad de Floppy. Las letras siguientes a partir de C, se reservan para 
los discos fijos o duros (Hard disks) o para las memorias Flash o Pendrive. 
En nuestro caso, las PC’s del laboratorio de Sistemas están dispuestas para que en general, el S.O. sea tomado (o 
cargado) desde un Hard disk que posee cada máquina, que recibe el nombre C: , por ser la primer unidad hard 
disk. 
La línea presentada por el DOS, siempre indica el disco “activo” o tomado por defecto. Tal situación significa que 
todos los comandos que no indiquen expresamente otra unidad de disco, tomarán la unidad activa para efectuar 
las acciones correspondientes. En el arranque, el disco presentado como activo es aquel desde el cual se ha cargado 
el S.O.
__________________________________________   124   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Archivos
Las unidades de disco son unidades de almacenamiento de información. las únicas entidades que pueden ser 
almacenadas en un disco, desde el punto de vista del S.O., son los archivos.  
Un archivo es un conjunto de bytes, que recibe un nombre. Para almacenar, copiar o eliminar tal conjunto de 
bytes, se debe hacer referencia al nombre del archivo que los contiene. 
Los nombres de los archivos pueden ser confeccionados con los caracteres de la escritura, en general las letras A a 
Z y los números de 1 a 9. Otros caracteres son admisibles. 
Cada nombre de archivo debe tener al menos un carácter hasta un máximo de 8. Luego de los caracteres del 
nombre, puede agregarse hasta tres caracteres más, separados del nombre por un punto. A esta trama de hasta tres 
caracteres se la denomina: extensión. Dentro del nombre y la extensión no puede haber espacios ni tampoco los 
caracteres: * (asterisco)  , (coma)  ; (punto y coma)  : (dos puntos)  ? (pregunta o admiración).  
 
Ejemplos de nombres de archivos: 
 
Válidos​
No válidos 
maria​
exclamacion.txt​
(nombre con más de 8 caracteres) 
enlace.txt​
versos.docu​
(extensión con más de cuatro caracteres) 
2​
lecciones​ ​
(nombre con más de 8 caracteres) 
111.21​
lea esto.bak​
(nombre con espacios intermedio) 
 
Para poder  ver qué archivos contiene un disco se debe ejecutar el comando: 
 
C:\> DIR  <ENTER>    (luego de escribir cada comando debe pulsarse la tecla Enter) 
 
Este comando lista todos los archivos que contiene el disco. Para cambiar de disco debe invocárselo por su 
nombre. Por ejemplo: 
 
C:\> A:   <ENTER>    No olvidarse de pulsar Enter, en lo sucesivo no se indica. 
 
Luego de invocar el disco A: la línea de comando luce así: 
 
A:\>_          (indicando el disco “activo” o por defecto.) 
 
Atención: Para que se pueda invocar un floppy disk, debe existir un diskette con formato, insertado en el 
compartimento, caso contrario será indicado un error y deberá volverse al disco C:
Format
Los diskettes o floppy disk cuando son adquiridos en el comercio, vienen en general, como unidades vírgenes que 
previamente deben ser puestas en condiciones para su uso. Se les debe dar un formato.  Para ello, si se está en el 
disco A: Invocar el disco C: 
 
A:\> C: 
 
La acción de dar formato a un diskette es llevada a cabo por el comando: 
 
C:\> FORMAT  A:        (Para dar formato a un disco en el driver A:) 
 
El S.O. solicita que se inserte una unidad en el compartimento y que se pulse Enter cuando se esté listo. A partir de 
allí indica en la pantalla el porcentaje de avance de la acción de formato. 
Cuando el “formateo ( de la jerga) ” es concluido, solicita dar un nombre de etiqueta al disco, acción que puede ser 
ignorada dando Enter. A partir de este momento el diskette está en condiciones de uso y podrán almacenarse 
archivos en el mismo. 
Para verificar el disco desde la línea de comando, escribir:
__________________________________________   125   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
C:\> DIR  A: 
 
Tal comando otorgará el listado de archivos en A: indicando que no existe ningún archivo almacenado. En caso de 
efectuar este comando sobre un diskette al que NO se le ha dado formato, la máquina indicará un ERROR. 
 
​
Directorios o Carpetas
Se ha dicho que en un disco los únicos elementos que pueden ser depositados (figurativamente) son los archivos. 
Cada archivo posee un nombre. El S.O. no permite que existan dos archivos con un mismo nombre. 
En los discos es posible configurar una estructura u organización del tipo “caja dentro de caja” de acuerdo al 
siguiente gráfico:
Organización de un disco
Estos elementos de organización dentro de un disco, reciben el nombre de directorios. Dentro de ellos se puede 
contener archivos u otros directorios. 
Debe entonces recordarse que:
 ​ El archivo es el elemento que puede almacenarse en un disco. 
 ​ El Directorio es una entidad de organización en el disco. 
 
En un disco al que se le ha dado formato, existe desde el inicio un primer directorio llamado RAIZ o ROOT. 
En este primer directorio pueden almacenarse archivos o crear nuevos directorios que dependen del raíz (como en 
la figura). Estos nuevos directorios a su vez, pueden contener archivos y/o directorios. 
Tal organización da lugar a un esquema o estructura en árbol como la siguiente:
RAIZ
INTRO                                         ARQUI 
           
                                NOTAS 
 
Obsérvese que del directorio raíz, dependen dos directorios: INTRO y ARQUI. A su vez, de INTRO depende un 
directorio denominado NOTAS. Los nombres de los directorios en estos esquemas, se los ha consignado en 
MAYUSCULAS para distinguirlos de los nombres de los archivos que se han consignado en minúsculas. 
Los nombres para los directorios, poseen las mismas reglas que los nombres de archivos. 
 
Comandos para manejo de Directorios: 
 
Situémonos en el disco A: 
 
C:\> A:
__________________________________________   126   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Para crear un directorio se debe escribir: 
 
A:\> MD  nombre 
 
Donde MD (Make Dir) es el comando de creación de un directorio y nombre es aquel que se le quiere otorgar. 
 
Para eliminar un directorio que ya ha sido creado, se debe escribir 
 
A:\>  RD nombre 
 
Donde RD (Remove Dir) es el comando de eliminación de un directorio y nombre es el que se quiere eliminar. 
Dentro de cada directorio se pueden colocar archivos. Estos archivos pueden ser creados o copiados desde otros 
directorios. 
Para cambiar de uno a otro directorio se debe escribir: 
 
A:\> CD nombre 
 
Donde CD (Change Dir) es el comando de cambio de directorio y nombre es el del directorio al que se desea 
mudar. Con este formato del comando, solo se puede avanzar en la estructura en árbol. 
Si se desea retroceder hacia el directorio RAIZ, debe escribirse: 
 
A:\> CD ..  (dos puntos separados de CD) 
 
Para ir a un directorio específico se puede hacerlo escribiendo toda la Ruta absoluta, esto es, la cadena de 
dependencia en la estructura en árbol. En nuestro ejemplo para ir al directorio NOTAS (dependiente de INTRO) se 
debe escribir: 
 
A:\> CD \INTRO\NOTAS 
 
Para volver desde cualquier directorio al Raíz se debe escribir: 
 
A:\>  CD\ 
 
Luego de efectuar el cambio de directorio la línea de comando luce un PROMPT (significa: incitar, presto) como 
el siguiente: 
 
A:\INTRO\NOTAS> 
 
El prompt en condiciones normales, indica el directorio en el que se está situado con su ruta absoluta. Este 
directorio es el que se toma  por defecto y lo llama directorio actual. 
Si se ejecutara un comando dir se obtendría exclusivamente el listado de los archivos del directorio actual: 
 
A:\INTRO\NOTAS> DIR 
. 
.. 
fecha     dbf 
 
(en este ejemplo, fecha.dbf  es el único archivo que existe en el directorio en cuestión.) 
 
PRACTICA: Hasta aquí, pruebe hacer en el diskette A: o B: la serie de comandos que se han indicado para la 
creación, remoción y movimiento dentro de directorios. 
 
​
Creación y Copia de archivos
La creación de archivos la producen programas específicos como editores de texto, planillas electrónicas, 
compiladores, etc. El S.O. puede crear un archivo de texto desde la línea de comando con la siguiente escritura:
__________________________________________   127   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
A:\> COPY  CON  primer.txt 
pepe 
pablo 
^Z  <ENTER> 
 
Con el primer comando se crea un archivo “copiándolo” (COPY) desde el teclado o consola (CON) y se le otorga 
el nombre,  en este caso: primer.txt 
En la segunda y tercera línea, se escriben palabras que serán contenidas en el archivo de texto. 
En la última línea se escribe un comando de finalización de archivo: ^Z  (significa mantener pulsada la tecla Ctrl 
y pulsar Z). Al final se concluye con Enter. 
Si ahora se ejecuta dir se observará la existencia en el disco, en el directorio actual el archivo: primer.txt 
si se quiere visualizar lo que contiene primer.txt se debe escribir: 
 
A:\> TYPE  primer.txt 
 
El comando TYPE envía a pantalla (o impresora) el contenido de un archivo en consecuencia aparecerá en la 
pantalla bajo la línea de comando: 
 
pepe 
pablo 
 
Para copiar archivos de un directorio a otro, se emplea el siguiente comando: 
 
A:\> COPY A:\INTRO\NOTAS\nombre.txt  A:\ARQUI 
 
El comando COPY copia un archivo desde una fuente hacia un destino. Obsérvese que en general, se debe 
indicar la ruta completa del directorio donde reside el archivo fuente, el propio archivo fuente y  la ruta del 
directorio de destino. No es necesario indicar el nombre del archivo de destino (a no ser que se le quiera cambiar el 
nombre). 
Existen otras excepciones a la regla general: 
Si el archivo a copiar, reside en el directorio actual, se puede obviar la ruta del archivo fuente. En este caso el S.O. 
tomará la ruta por defecto que es la del directorio actual. En nuestro caso ejemplo, estando en INTRO: 
 
A:\INTRO> COPY notas.txt  C:\INTRO\NOTAS​ ​
Permite copiar notas.txt residente en INTRO al di- 
​
​
​
​
​
​
​
rectorio INTRO\NOTAS
Renombre de archivos
Si en el directorio actual ejecutamos: 
A:\INTRO> REN  notas.txt  notas.bak                       y luego: 
A:\INTRO> DIR 
. 
.. 
parcial1.doc 
notas.bak 
 
En el nuevo listado solicitado mediante dir, observamos que notas.txt cambio de nombre a notas.bak 
El comando REN, renombra archivos sin modificar su posición en el disco ni su contenido. 
Se puede renombrar archivos mientras se copian en una acción escribiendo completas la ruta y el nombre del 
destino. Por ejemplo: 
 
A:\INTRO\> COPY parcial1.doc A:\parcial.txt​
Se copia con nombre parcial.txt en el directorio RAIZ de A:. 
 
En general todos los comandos del DOS que efectúan acciones sobre archivos, pueden utilizar la ruta adecuada 
para ejercer acciones sobre otros directorios distintos al actual. Ejemplos:
__________________________________________   128   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
A:\INTRO> COPY A:\Parcial.txt  A:\INTRO\NOTAS\Parcial.doc 
 
Estando en INTRO, este comando copia desde el RAIZ el archivo parcial.txt hacia el directorio INTRO\NOTAS 
cambiándole el nombre en una sola acción. Obsérvese que se ha hecho una acción que involucra dos directorios 
que no son el actual, por defecto. Otro ejemplo: 
 
A:\INTRO> DIR  A:\INTRO\NOTAS            Desde INTRO, se lista el contenido de INTRO\NOTAS
Eliminación de archivos
El comando DEL  (Delete) elimina un archivo de un directorio. Ejemplo: 
 
A:\INTRO> DEL  A:\INTRO\NOTAS\fecha.dbf            Desde INTRO, se elimina el archivo fecha.dbf 
 
Este comando puede prescindir de la ruta si la acción se desea sobre el directorio actual. 
Para poder eliminar un directorio completo, en primer lugar deben eliminarse todos los archivos contenidos en él. 
Luego se elimina el directorio con el comando RD. Recuérdese: DEL elimina archivos. RD elimina directorios. 
En las versiones últimas del DOS (6.0 y posteriores), existe el comando DELTREE (borra arbol). Se utiliza así: 
 
A:\> DELTREE  INTRO  ​
(elimina el directorio incluidos los archivos y directorios que dependen de él) 
 
Este comando debe utilizarse con mucho cuidado !!.
Comodines (WildCards)  
 
El caracter: * (Asterísco), se utiliza para representar todos los caracteres que existen en un nombre de archivo a 
partir de la posición en que es insertado el  *. Ejemplo: 
 
par*.* ​ ​
Representa cualquiera de estos archivos: parcial.txt, parcial1.txt, parcial.bak, parcial1.doc 
 
De la misma forma, el caracter: ? (pregunta), se utiliza para representar un solo caracter en la posición que ocupa. 
Así: 
 
parcial?.doc​
Representa cualquiera de los archivos: parcial1.doc, parcial2.doc 
 
En función de ello, se pueden utilizar los comodines para efectuar acciones sobre un grupo de archivos de un 
mismo directorio. 
 
A:\INTRO> COPY *.*  A:\ARQUI​
Copia todos los archivos de INTRO en ARQUI 
A:\INTRO> DEL A:\ARQUI\*.DOC​
Elimina todos los archivos con extensión .DOC en ARQUI.
Editor de texto
El DOS cuenta con un EDITOR DE TEXTO que puede ser usado para crear archivos que contengan texto. 
Se invoca con el comando EDIT , si estamos en el disco A: , escribir: 
 
A:\> C:\EDIT​
​
Se indica la ruta para hallar edit, si es necesario. 
 
El editor presenta una pantalla donde se puede escribir línea por línea un texto. Con la tecla Alt, se accede a un 
menú que se presenta en la zona superior de la pantalla, que contiene múltiples comandos de edición. En particular 
bajo el título ARCHIVO, se encuentra un comando que permite guardar un archivo en el disco y otro comando 
que permite salir. Este editor puede ser utilizado para el desarrollo de la práctica.
__________________________________________   129   /  130  ____________________________________
EDI-Anexo1-2026

ELEMENTOS DE INFORMÁTICA
Ayuda
Hasta aquí se han descripto los comandos básicos del S.O. para una descripción más extensa, puede utilizarse el 
comando HELP. Este comando al ser invocado presenta un texto que trae consigo ordenados por orden alfabético 
del resto de los comandos. También se lo puede utilizar añadiendo un comando específico sobre el que se quiere 
ayuda. Ejemplo. 
 
A:\INTRO> HELP COPY​
Otorga ayuda sobre el comando copy. 
 
Se sale del HELP con Alt, entrando al menú ARCHIVO y luego: SALIR. 
Nota: Si HELP no funciona invocándolo desde el disco A:, cambiar a C:.  
 
Otra forma de ayuda se obtiene escribiendo un comando seguido de /?. 
Otra ayuda se puede obtener del manual de usuario del S.O., disponible en biblioteca o en el laboratorio de 
computadoras.
A.B. Paur 2007 - 2011
R. López 2007 - 2011
__________________________________________   130   /  130  ____________________________________
EDI-Anexo1-2026
