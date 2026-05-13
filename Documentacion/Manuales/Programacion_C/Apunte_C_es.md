# Apunte_C

APUNTE: LENGUAJE ANSI C
Fuente (Aprenda Lenguaje ANSI C como si estuviera en rimero)
INTRODUCCIÓN
En estos apuntes se describe de forma abreviada la sintaxis del lenguaje C. No se trata de 
aprender a programar en C, sino más bien de presentar los recursos o las posibilidades que 
el C pone a disposición de los programadores.
Conocer  un vocabulario y una gramática no equivale a saber un idioma. Conocer un idioma 
implica además el hábito de combinar sus elementos de   forma   semiautomática   para 
producir frases que expresen lo que uno quiere decir. Conocer las palabras, las sentencias y la 
sintaxis  del  C  no  equivalen a saber programar, pero son condición necesaria para estar en 
condiciones de empezar a hacerlo, o de entender cómo  funcionan  programas  ya  hechos. 
El proporcionar la base necesaria para aprender a programar en C es el objetivo de estas 
páginas.
CONCEPTO DE "FUNCIÓN"
Las aplicaciones informáticas que habitualmente se utilizan, incluso a nivel de informática 
personal, suelen contener decenas y aún cientos de miles de líneas de código fuente. A medida 
que los programas se van desarrollando y aumentan de tamaño, se convertirían rápidamente en 
sistemas poco manejables si no fuera por la modularización, que es el proceso consistente en 
dividir un programa muy grande en una serie de módulos mucho más pequeños y manejables. 
A estos módulos se les ha solido denominar de distintas formas (subprogramas, subrutinas, 
procedimientos,  funciones, etc.) según los distintos lenguajes. El lenguaje C  hace  uso  del 
concepto de función (function). Sea cual sea la nomenclatura, la idea es sin embargo siempre 
la misma: dividir un programa grande en un conjunto de subprogramas o funciones  más 
pequeñas que son llamadas por el programa principal; éstas a su vez llaman a otras funciones 
más específicas y así sucesivamente.
NOMBRE, VALOR DE RETORNO Y ARGUMENTOS DE UNA FUNCIÓN
Una función de C es una porción de código o programa que realiza una determinada tarea. 
Una función está asociada con un identificador o nombre, que se utiliza para referirse a ella 
desde el resto del programa. En toda función utilizada en C hay  que  distinguir  entre  su 
definición, su declaración y su llamada. Para explicar estos conceptos hay que introducir los 
conceptos de valor de retorno y de argumentos.
Quizás  lo  mejor  sea  empezar  por  el  concepto  más  próximo  al  usuario,  que  es  el 
concepto de llamada. Las  funciones en C se llaman incluyendo su  nombre, seguido de los 
argumentos, en una sentencia del programa principal o de otra función de rango superior. Los 
argumentos   son   datos   que  se  envían  a  la  función  incluyéndolos  entre  paréntesis  a 
continuación del nombre, separados por comas. Por ejemplo, supóngase una función llamada 
power que calcula x elevado a y. Una forma de llamar a esta función es escribir la siguiente 
sentencia (las sentencias de C terminan con punto y coma):

power(x,y);
EL PREPROCESADOR
El  preprocesador del lenguaje C permite sustituir  macros (sustitución en el programa de 
constantes simbólicas o texto, con o sin parámetros), realizar compilaciones condicionales e 
incluir  archivos,  todo  ello  antes  de  que  empiece  la  compilación  propiamente  dicha.  El 
preprocesador de C reconoce los siguientes comandos:
#define, #undef
#if, #ifdef, #ifndef, #endif, #else, #elif
#include
#pragma
#error
Los comandos más utilizados son: #include, #define.
Comando #include
Cuando en un archivo .c se encuentra una línea con un #include seguido de un nombre de 
archivo, el preprocesador la sustituye por el contenido de ese archivo.
La sintaxis de este comando es la siguiente:
#include "nombre_del_archivo"
#include <nombre_del_archivo>
La   diferencia   entre   la primera forma (con comillas "...") y la segunda forma (con los 
símbolos  <...>)  estriba  en  el  directorio  de búsqueda de dichos archivos. En la forma con 
comillas se busca el archivo en el directorio actual y posteriormente en el directorio estándar 
de  librerías  (definido  normalmente  con  una  variable  de  entorno  del  MS-DOS  llamada 
INCLUDE, en el caso de los compiladores de Microsoft). En la forma que utiliza los símbolos
<...> se busca directamente en el directorio estándar de librerías. En la práctica, los archivos 
del sistema (stdio.h, math.h, etc.) se incluyen con la segunda forma, mientras que los archivos 
hechos por el propio programador se incluyen con la primera.
Este   comando del preprocesador se utiliza normalmente para incluir archivos con los 
prototipos  (declaraciones) de las funciones de librería, o con módulos de programación y 
prototipos de las funciones del propio usuario. Estos archivos suelen tener la extensión  *.h, 
aunque puede incluirse cualquier tipo de archivo de texto.
Comando #define
El comando #define establece una macro en el código fuente. Existen dos posibilidades de 
definición:
#define NOMBRE texto_a_introducir

#define NOMBRE(parámetros) texto_a_introducir_con_parámetros
Antes de comenzar la compilación, el preprocesador analiza el programa y  cada vez que 
encuentra el identificador NOMBRE lo sustituye por el texto que se especifica a continuación 
en el comando #define. Por ejemplo, si se tienen las siguientes líneas en el código fuente:
#define E 2.718281828459
...
void main(void) {
double a;
a= (1.+1./E)*(1.-2./E);
...
}
al  terminar  de  actuar  el  preprocesador, se habrá realizado la sustitución de  E por el 
valor indicado y el código habrá quedado de la siguiente forma:
void main(void) {
double a;
a= (1.+1./2.718281828459)*(1.-2./2.718281828459);
...
}
Este   mecanismo   de   sustitución  permite  definir  constantes  simbólicas  o  valores 
numéricos (tales como  E,  PI,  SIZE, etc.) y poder cambiarlas fácilmente, a la vez que el 
programa se mantiene más legible.
LA FUNCIÓN MAIN( )
Todo programa C, desde el más pequeño hasta el más complejo, tiene un programa principal 
que es con el que se comienza la ejecución del programa. Este programa principal es también 
una función, pero una función que está por encima de todas las demás. Esta función se llama 
main() y tiene la forma siguiente (la palabra void es opcional en este caso):
void main(void)
{
sentencia_1;
sentencia_2;
...
}
Las   llaves   {...}   constituyen   el modo utilizado por el lenguaje C para agrupar varias 
sentencias de modo que se comporten como una sentencia única (sentencia compuesta o 
bloque).  Todo  el  cuerpo  de  la  función debe ir comprendido entre las llaves de apertura y 
cierre.
PALABRAS CLAVE DEL C

En C, como en cualquier otro lenguaje, existen una serie de palabras clave (keywords) que el 
usuario no puede utilizar como identificadores (nombres de variables y/o de funciones). Estas 
palabras sirven para indicar al computador que realice  una  tarea  muy  determinada  (desde 
evaluar una comparación, hasta definir el tipo de una variable) y tienen un especial significado 
para el compilador. El C es un lenguaje muy conciso, con muchas menos palabras clave que 
otros lenguajes. A continuación se presenta la lista de las 32 palabras clave del ANSI C, para 
las  que   más  adelante  se dará detalle de su significado (algunos compiladores añaden 
otras palabras clave, propias de cada uno de ellos. Es importante evitarlas como identificadores):
Auto double int struct break else long switch case enum register typedef char extern 
return union const float short unsigned continue for signed void default goto sizeof 
volatile do if static while
IDENTIFICADORES
Ya se ha explicado lo que es un identificador: un nombre con el que se hace referencia a una 
función o al contenido de una zona de la memoria (variable). Cada lenguaje tiene sus propias 
reglas respecto a las posibilidades de elección de nombres para las funciones y variables. En 
ANSI C estas reglas son las siguientes:
1. Un  identificador se forma con una secuencia de  letras (minúsculas de la  a a la
z;
2.
mayúsculas de la A a la Z; y dígitos del 0 al 9).
3. El carácter subrayado o underscore (_) se considera como una letra más.
4. Un identificador no puede contener espacios en blanco, ni otros caracteres distintos de
los citados, como por ejemplo (* ; : - + / $ %).
5. El primer carácter de un identificador debe ser siempre una letra o un (_), es decir, no
puede ser un dígito.
6. Se hace distinción entre letras mayúsculas y minúsculas. Así,  Masa es considerado
como un identificador distinto de masa y de MASA.
7. ANSI C permite definir identificadores de hasta 31 caracteres de longitud. Ejemplos de
identificadores válidos son los siguientes:
tiempo, distancia1, caso_A, PI, velocidad_de_la_luz
Por el contrario, los siguientes nombres no son válidos (¿Por qué?)
1_valor, tiempo-total, dolares$, %final
En general es muy aconsejable elegir los nombres de las funciones y las variables de 
forma  que  permitan  conocer  a  simple  vista  qué  tipo  de  variable  o  función  representan, 
utilizando para ello tantos caracteres como sean necesarios. Esto simplifica enormemente la

tarea de programación y –sobre todo– de corrección y mantenimiento de los programas.  Es 
cierto que los nombres largos son más laboriosos de teclear, pero en general resulta rentable 
tomarse esa pequeña molestia.
OPERADORES
Los   operadores son signos especiales –a veces, conjuntos de   dos   caracteres–   que 
indican determinadas operaciones a realizar con las variables y/o constantes sobre las que 
actúan en el programa. El lenguaje C es particularmente rico en distintos tipos de operadores:
Aritméticos (+, -, *, /, %) , de asignación (=, +=, -=, *=, /=), relacionales (==, <, >,
<=, >=, !=), lógicos (&&, ||, !)
Por ejemplo, en la sentencia:
espacio = espacio_inicial + 0.5 * aceleracion * tiempo * tiempo;
aparece un operador de asignación (=) y dos operadores  aritméticos  (+ y  *). También los
operadores serán vistos con mucho más detalle en apartados posteriores.
COMENTARIOS
El lenguaje C permite que el programador introduzca comentarios en los ficheros fuente que 
contienen el código de su programa. La misión de los comentarios es servir de explicación o 
aclaración sobre cómo está hecho el programa, de forma que pueda ser entendido por  una 
persona diferente (o por el propio programador algún tiempo después). Los comentarios son 
también particularmente útiles (y peligrosos...) cuando el programa forma parte de un examen 
que el profesor debe corregir. El compilador ignora por completo los comentarios.
Los caracteres (/*) se emplean para iniciar un comentario introducido entre el código del 
programa;  el  comentario  termina  con  los  caracteres  (*/).  No  se  puede  introducir  un 
comentario dentro de otro. Todo texto introducido entre los símbolos de comienzo (/*) y final
(*/) de comentario son siempre ignorados por el compilador. Por ejemplo:
variable_1 = variable_2;    /*se asigna a variable_1 el valor contenido en variable_2 */
El lenguaje ANSI C permite también otro tipo de comentarios, tomado del C++. Todo lo que va 
en cualquier línea del código detrás de la doble barra (//) y hasta el final de la línea, se 
considera como un comentario y es ignorado por el compilador. Para comentarios cortos, esta 
forma es más cómoda que la anterior, pues no hay que preocuparse de cerrar el comentario (el 
fin de línea actúa como cierre). Como contrapartida, si un comentario ocupa varias líneas hay 
que repetir la doble barra (//) en cada una de las líneas. Con este segundo procedimiento de 
introducir comentarios, el último ejemplo podría ponerse en la forma:
variable_1 = variable_2;
// En esta línea se asigna a
                                                                   //   variable_1 el valor
//   contenido en variable_2

TIPOS DE DATOS FUNDAMENTALES. VARIABLES
El C, como cualquier otro lenguaje de programación, tiene posibilidad de trabajar con datos de 
distinta naturaleza: texto formado por caracteres alfanuméricos, números enteros, números 
reales con parte entera y parte fraccionaria, etc. Además, algunos de estos  tipos  de  datos 
admiten distintos números de cifras (rango y/o precisión), posibilidad de ser sólo positivos o 
de ser positivos y negativos, etc. En este apartado se verán los tipos fundamentales de datos 
admitidos  por  el  C.  Más  adelante se verá que hay otros tipos de datos,  derivados de 
los fundamentales. Los tipos de datos fundamentales del C se indican en la Tabla 2.1.
Tabla 2.1. Tipos de datos fundamentales (notación completa)
Datos enteros
char
signed char
unsigned char
signed short int
signed int
signed long int
unsigned short int
unsigned int
unsigned long int
Datos reales
float
double
long double
La palabra  char  hace  referencia a que se trata de un carácter (una letra mayúscula o 
minúscula, un dígito, un carácter especial, ...). La palabra int indica que se trata de un número 
entero, mientras que  float  se  refiere  a un número real (también llamado de punto o coma 
flotante).   Los   números   enteros   pueden   ser   positivos   o   negativos   (signed),   o bien 
esencialmente no negativos (unsigned); los caracteres tienen un tratamiento muy similar a los 
enteros y admiten estos mismos cualificadores. En los datos enteros, las palabras short y 
long  hacen referencia al número de cifras o rango de dichos números. En los datos 
reales  las palabras  double  y  long  apuntan  en  esta  misma  dirección,  aunque  con  un 
significado ligeramente diferente, como más adelante se verá.
Esta nomenclatura puede simplificarse: las palabras signed e int son las opciones por 
defecto  para  los  números  enteros  y pueden omitirse, resultando la Tabla 2.2, que indica la 
nomenclatura más habitual para los tipos fundamentales del C.
Tabla 2.2. Tipos de datos fundamentales (notación abreviada).
Datos enteros:   
char    ( signed char     unsigned char)
int
Datos reales:  float
double
long double
A continuación se va a explicar cómo puede ser y cómo se almacena en C un dato de cada 
tipo fundamental.

Recuérdese que en C es necesario declarar todas las variables que se vayan a utilizar. Una 
variable no declarada produce un mensaje de error en la compilación. Cuando una 
variable es declarada se le reserva memoria de acuerdo con el tipo incluido en la declaración. 
Es posible inicializar –dar un valor inicial– las variables en el momento de la declaración; ya 
se verá que en ciertas ocasiones el compilador da un valor inicial por defecto, mientras que en 
otros   casos   no   se   realiza  esta  inicialización  y  la  memoria  asociada  con  la  variable 
correspondiente contiene  basura informática (combinaciones sin sentido de unos y ceros, 
resultado de operaciones anteriores con esa zona de la memoria, para otros fines).
Caracteres (tipo char)
Las variables carácter (tipo char) contienen un único carácter y se almacenan en un byte
de  memoria (8 bits). Con 8 bits se podrán  almacenar 28  = 256 valores diferentes 
(normalmente entre 0 y 255; con ciertos compiladores entre -128 y 127).
La declaración de variables tipo carácter puede tener la forma:
char nombre;
char nombre1, nombre2, nombre3;
Se puede declarar más de una variable de un tipo determinado en una sola sentencia. Se 
puede también inicializar la variable en la declaración. Por ejemplo, para definir la variable 
carácter letra y asignarle el valor a, se puede escribir:         char letra = ’z’;
También puede utilizarse una variable char para dar valor a otra variable de tipo char:
caracter = letra;
// Ahora caracter es igual a ’z’
Como una variable tipo char es un número entero pequeño (entre 0 y 255), se   puede 
utilizar el contenido de una variable char de la misma forma que se utiliza un entero, por lo 
que están permitidas operaciones como:
letra = letra + 1;
letra_minuscula = letra_mayuscula + (’a’ - ’A’);
En el primer ejemplo, si el contenido de letra era una a, al incrementarse en una unidad pasa a 
contener una b. El segundo ejemplo es interesante: puesto que la diferencia numérica entre 
las letras minúsculas y mayúsculas es siempre la misma (según el código ASCII),   la 
segunda sentencia pasa una letra mayúscula a la correspondiente letra minúscula sumándole 
dicha diferencia numérica. Recuérdese para concluir que las variables tipo char son y se 
almacenan como números enteros pequeños. Ya se verá más adelante que se pueden 
escribir  como  caracteres  o  como números según que formato de conversión se utilice en la 
llamada a la función de escritura.

Números enteros (tipo int)
De  ordinario  una  variable  tipo  int  se  almacena  en  2  bytes  (16  bits),  aunque  algunos 
compiladores utilizan 4 bytes (32 bits). El ANSI C no tiene esto completamente normalizado y 
existen diferencias entre unos compiladores y otros. Los compiladores de Microsoft   para 
PCs utilizan 2 bytes.
Con 16 bits se pueden almacenar 216 = 65536 números enteros diferentes: de 0 al 65535 para 
variables   sin signo, y de -32768 al 32767 para variables con signo (que pueden ser 
positivas y negativas), que es la opción por defecto. Este es el rango de las variables tipo int. 
Una variable entera (tipo int) se declara, o se declara y se inicializa en la forma:
unsigned int numero;
int nota = 10;
En este caso la variable numero podrá estar entre 0 y 65535, mientras que nota deberá estar 
comprendida entre -32768 al 32767. Cuando a una variable int se le asigna en tiempo de 
ejecución  un  valor  que  queda  fuera  del  rango  permitido  (situación  de  overflow  o  valor 
excesivo), se produce un error en el resultado de consecuencias  tanto  más  imprevisibles 
cuanto que de ordinario el programa no avisa al usuario de dicha circunstancia.
Números reales (tipo float)
En muchas aplicaciones hacen falta variables reales, capaces de representar magnitudes 
que contengan  una parte entera y una parte fraccionaria o  decimal. Estas variables se 
llaman también de punto flotante. Las variables tipo float se declaran de la forma:
float numero_real;
Las variables tipo  float pueden ser inicializadas en el momento de la declaración, de forma 
análoga a las variables tipo int.
Números reales (tipo double)
Las  variables  tipo  float  tienen  un  rango  y  –sobre  todo–  una  precisión  muy  limitada, 
insuficiente  para  la mayor parte de los cálculos técnicos y científicos. Este problema se 
soluciona con el tipo  double, que utiliza 8 bytes (64 bits) para almacenar  una  variable.  Se 
utilizan 53 bits para la mantisa (1 para el signo y 52 para el valor) y 11 para el exponente (1 
para el signo y 10 para el valor). Las variables tipo double se declaran de forma análoga a las 
anteriores:
double real_grande;
Cadenas de caracteres
Una cadena de caracteres es una secuencia de caracteres delimitada por comillas ("), como

por  ejemplo: "Esto es una cadena de caracteres". Dentro de la cadena, pueden aparecer 
caracteres en blanco y se pueden emplear las mismas secuencias de escape válidas para 
las constantes carácter. Por ejemplo, las comillas (") deben estar precedidas por (\), para no ser 
interpretadas como fin de la cadena; también la propia barra invertida (\). Es muy importante 
señalar que el compilador sitúa siempre un byte nulo (\0) adicional al final de cada cadena de 
caracteres para señalar  el  final  de  la  misma.  Así,  la  cadena  "mesa"  no  ocupa  4  bytes, 
sino  5  bytes.  A continuación se muestran algunos ejemplos de cadenas de caracteres:
"Informática I"
"'A'"
"        cadena con espacios en blanco         "
"Esto es una \"cadena de caracteres\".\n"
OPERADORES, EXPRESIONES Y SENTENCIAS
Operadores
Un operador es un carácter o grupo de caracteres que actúa sobre una, dos o más variables 
para realizar una determinada operación con un determinado resultado. Ejemplos típicos de 
operadores son la suma (+), la diferencia (-), el producto (*), etc. Los operadores pueden ser 
unarios, binarios y ternarios, según actúen sobre uno, dos o tres operandos, 
respectivamente. En  C  existen  muchos  operadores de diversos tipos (éste es uno de los 
puntos fuertes del lenguaje), que se verán a continuación.
OPERADORES ARITMÉTICOS
Los operadores aritméticos son los más sencillos de entender y de utilizar. Todos ellos 
son operadores binarios. En C se utilizan los cinco operadores siguientes:
–   Suma:
+
–   Resta:
-
–   Multiplicación:
*
–   División:
/
–   Resto:
%
Todos   estos   operadores se pueden aplicar a constantes, variables y expresiones. El 
resultado es el que se obtiene de aplicar la operación correspondiente entre los dos operandos. 
El único operador que requiere una explicación adicional es el operador   resto %. En 
realidad su nombre completo es resto de la división entera. Este operador se aplica 
solamente a constantes, variables o expresiones de tipo  int. Aclarado esto, su significado es 
evidente:
23%4 es 3
puesto que el resto de dividir 23 por 4 es 3. Si a%b es cero, a es múltiplo de b. Como se verá 
más adelante, una expresión es un conjunto de variables y constantes –y
también de otras expresiones más sencillas– relacionadas mediante distintos operadores. Un 
ejemplo de expresión en la que intervienen operadores aritméticos es el siguiente polinomio

de grado 2 en la variable x:
5.0 + 3.0*x - x*x/2.0
Las expresiones pueden contener paréntesis (...) que agrupan a algunos de sus términos. 
Puede haber paréntesis contenidos dentro de otros paréntesis. El significado de los paréntesis 
coincide  con  el  habitual  en  las  expresiones  matemáticas,  con  algunas   características 
importantes que se verán más adelante. En ocasiones, la introducción de espacios en blanco 
mejora la legibilidad de las expresiones.
4.1.2  OPERADORES DE ASIGNACIÓN
Los  operadores de asignación atribuyen a una variable –es decir, depositan en la zona 
de memoria correspondiente a dicha variable– el resultado de una expresión o el valor de 
otra variable (en realidad, una variable es un caso particular de una expresión).
El operador de asignación más utilizado es el  operador de igualdad (=), que no debe ser 
confundido con la igualdad matemática. Su forma general es:
nombre_de_variable = expresion;
cuyo  funcionamiento  es  como  sigue:  se  evalúa  expresion  y  el  resultado  se  deposita  en 
nombre_de_variable,  sustituyendo  cualquier  otro  valor  que  hubiera  en  esa  posición  de 
memoria anteriormente. Una posible utilización de este operador es como sigue:
variable = variable + 1;
Desde el punto de vista matemático este ejemplo no tiene sentido (¡Equivale a 0 = 1!), pero sí 
lo tiene considerando que en realidad el operador de asignación (=) representa una 
sustitución; en efecto, se toma el valor de variable contenido en la memoria, se le suma una 
unidad y el valor resultante vuelve a depositarse en  memoria  en  la  zona  correspondiente 
al identificador  variable,  sustituyendo al valor que había anteriormente. El resultado ha sido 
incrementar el valor de variable en una unidad.
Así pues, una variable puede aparecer a la izquierda y a la derecha del operador (=). Sin 
embargo, a la izquierda del operador de asignación (=) no puede haber nunca una expresión:
tiene que ser necesariamente el nombre de una variable5. Es incorrecto, por tanto, escribir algo 
así como:
a + b = c;     // incorrecto
Existen otros cuatro operadores de asignación (+=, -=, *= y /=) formados por los
4 operadores aritméticos seguidos por el carácter de igualdad. Estos operadores simplifican 
algunas operaciones recurrentes sobre una misma variable. Su forma general es:
variable op= expresion;

donde   op representa cualquiera de los operadores (+ - * /). La expresión anterior es 
equivalente a:
variable = variable op expresion;
A continuación se presentan algunos ejemplos con estos operadores de asignación: distancia += 
1;
equivale a:
distancia  =  distancia  +  1;  rango  /=  2.0
equivale a:
rango = rango /2.0
x *= 3.0 * y - 1.0
equivale a:
x = x * (3.0 * y - 1.0)
CONTROL DEL FLUJO DE EJECUCIÓN
En principio, las sentencias de un programa en C se ejecutan secuencialmente, esto es, cada 
una a continuación de la anterior empezando por la primera y acabando por la  última.  El 
lenguaje C dispone de varias sentencias para modificar este flujo secuencial de la ejecución. 
Las más utilizadas se agrupan en dos familias: las   bifurcaciones, que permiten elegir 
entre dos  o  más  opciones  según  ciertas  condiciones,  y  los   bucles,  que  permiten 
ejecutar  repetidamente  un  conjunto  de  instrucciones  tantas  veces  como  se  desee, 
cambiando  o actualizando ciertos valores.
Bifurcaciones
SENTENCIA IF
Esta sentencia de control permite ejecutar o no una sentencia simple o compuesta según 
se cumpla o no una determinada condición. Esta sentencia tiene la siguiente forma general:
if (expresion)
sentencia;
Explicación:  Se evalúa  expresion. Si el resultado es  true (#0), se ejecuta  sentencia; si 
el  resultado es false (=0), se salta sentencia y se prosigue en la línea siguiente. Hay que 
recordar que sentencia puede ser una sentencia simple o compuesta (bloque { ... }).
SENTENCIA IF ... ELSE
Esta sentencia permite realizar una  bifurcación,  ejecutando  una  parte u otra del programa
según se cumpla o no una cierta condición. La forma general es la siguiente:
if (expresion)
sentencia_1;
else
sentencia_2;

Explicación:  Se evalúa expresion. Si el resultado es true (#0), se ejecuta sentencia_1 y 
se  prosigue en la línea siguiente a sentencia_2; si el resultado es false (=0), se salta 
sentencia_1, se ejecuta sentencia_2 y se prosigue en la línea siguiente. Hay que indicar aquí 
también que  sentencia_1 y sentencia_2 pueden ser sentencias simples o compuestas 
(bloques { ... }).
Bucles
Además de bifurcaciones, en el lenguaje C existen también varias sentencias que 
permiten repetir una serie de veces la ejecución de unas líneas de código. Esta repetición se 
realiza, bien un número determinado de veces, bien hasta que se cumpla una determinada 
condición de tipo lógico o aritmético. De modo genérico, a estas sentencias se les denomina 
bucles. Las tres construcciones del lenguaje C para realizar bucles son el while, el for y el 
do...while.
SENTENCIA WHILE
Esta  sentencia  permite  ejecutar   repetidamente,   mientras  se  cumpla  una  determinada
condición, una sentencia o bloque de sentencias. La forma general es como sigue:
while (expresion_de_control)
sentencia;
Explicación:  Se evalúa expresion_de_control y si el resultado es false se salta sentencia 
y se prosigue la ejecución. Si el resultado es  true se ejecuta  sentencia  y se vuelve a 
evaluar expresion_de_control   (evidentemente   alguna   variable   de   las
que
intervienen
en 
expresion_de_control  habrá  tenido  que  ser  modificada,  pues  si  no  el  bucle  continuaría 
indefinidamente). La ejecución de  sentencia  prosigue hasta que  expresion_de_control se 
hace  false, en cuyo caso la ejecución continúa en la línea siguiente a  sentencia.  En 
otras palabras,   sentencia se ejecuta repetidamente mientras   expresion_de_control sea 
true, y se deja de ejecutar cuando expresion_de_control se hace false. Obsérvese que en 
este caso el control para decidir si se sale o no del bucle está antes de sentencia, por lo que 
es posible que sentencia no se llegue a ejecutar ni una sola vez.
SENTENCIA FOR
For es quizás el tipo de bucle mas versátil y utilizado del lenguaje C. Su forma general es la 
siguiente:
for (inicializacion; expresion_de_control; actualizacion)
sentencia;
Explicación:  Posiblemente la forma más sencilla de explicar la sentencia for sea utilizando 
la construcción while que sería equivalente. Dicha construcción es la siguiente:

inicializacion;
while (expresion_de_control) {
sentencia;
actualizacion;
}
donde sentencia puede ser una única sentencia terminada con (;), otra sentencia de control 
ocupando varias líneas (if, while, for, ...), o una sentencia compuesta o un bloque encerrado 
entre llaves {...}. Antes de iniciarse  el  bucle  se  ejecuta  inicializacion, que es una o más 
sentencias que asignan valores iniciales a ciertas variables o contadores.  A  continuación  se 
evalúa  expresion_de_control  y  si  es  false  se  prosigue  en  la  sentencia  siguiente  a 
la construcción  for; si es  true se ejecutan  sentencia y  actualizacion, y se vuelve a 
evaluar expresion_de_control. El proceso prosigue hasta  que  expresion_de_control sea 
false. La parte de actualizacion sirve para actualizar variables o incrementar contadores. Un 
ejemplo típico puede ser el producto escalar de dos vectores a y b de dimensión n:
for (pe =0.0, i=1; i<=n; i++){
pe += a[i]*b[i];
}
Primeramente se inicializa la variable pe a cero y la variable i a 1; el ciclo se repetirá 
mientras que i sea menor o igual que n, y al final de cada ciclo el valor de i se incrementará en 
una unidad. En total, el bucle se repetirá n veces. La ventaja de la construcción for sobre la 
construcción while equivalente está en que en la cabecera de la construcción for se tiene toda 
la información sobre como se inicializan, controlan  y  actualizan  las  variables  del  bucle. 
Obsérvese que la inicializacion consta de dos sentencias separadas por el operador (,).
Función printf()
La función printf() imprime en la unidad de salida (el monitor, por defecto), el texto, y las 
constantes y variables que se indiquen. La forma general de esta función se puede estudiar 
viendo su prototipo:
int printf("cadena_de_control", tipo arg1, tipo arg2, ...)
Explicación: La función  printf()  imprime el texto contenido en  cadena_de_control junto 
con   el   valor   de   los   otros   argumentos,   de   acuerdo   con   los formatos   incluidos   en 
cadena_de_control. Los puntos suspensivos (...) indican que puede haber un número variable 
de  argumentos.  Cada  formato comienza con el carácter (%) y termina con un  carácter de 
conversión.
Considérese el ejemplo siguiente,
int    i; double tiempo; float  masa;
printf("Resultado nº: %d. En el instante %lf la masa vale %f\n", i, tiempo, masa);

en el que se imprimen 3 variables  (i,  tiempo y masa) con los formatos (%d,  %lf y %f), 
correspondientes a los tipos (int,  double y float), respectivamente. La cadena de control se 
imprime con el valor de cada variable intercalado en el lugar del formato correspondiente.
