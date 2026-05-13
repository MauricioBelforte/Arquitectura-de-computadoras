# Apunte_C_Arqui

Operadores
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
Comparación por igualdad y desigualdad 
respectivamente
&
And a nivel de bit o dirección de una variable
|
Or a nivel de bit
&&  ||
And y or lógicos
?:
Asignación condicional
=  +=  -=
*=  /=
Asignación simple y asignaciones compuestas
Dejando de lado los operadores aritméticos básicos y los operadores de 
comparación  aritmética,  a  continuación  de  describe  el  resto  de  los 
operadores.
Se dice que los operadores son unarios cuando se aplican y afectan a un 
solo operando. Un mismo operador puede tener diferente significado si se 
utiliza como  unario o no. Un ejemplo de esto es el operador  & que se 
describe más adelante.
Los operadores unarios de incremento (++) y decremento (--) se utilizan 
para incrementar en una unidad o decrementar en una unidad una variable 
entera. Estos operadores se pueden utilizar como prefijo o como sufijo. Si se 
utilizan como prefijo (por ej. ++i), el valor de la variable se modifica y luego 
se  usa  el  valor  ya  modificado  en el contexto  en  que se  encuentra.  En 
cambio  si  se  utilizan  como  sufijo,  primero  se  utiliza  la  variable  en  su 
contexto y luego se incrementa. Por ejemplo, la sentencia
val = vector[i++];
Asigna a la variable val, el valor de la posición i (sin modificar) del arreglo 
vector  y  luego  de  esta  asignación  se  incrementa  i,  con  lo  cual  queda 
apuntando al próximo elemento en el arreglo.
El operador % representa el módulo de una división entera. Se aplica a dos 
operandos y devuelve el resto de la división entera del primer operando por 
el segundo. Por ejemplo, una forma de verificar si un número es impar o no, 
es
if(n % 2) {

/* El valor de n es impar */
…
…
…
}
Ya que en C el valor 0 (cero) se considera falso y cualquier valor numérico 
distinto de 0 se considera verdadero, y en este caso el módulo será igual a 0 
o a 1.
Para acceder a un elemento de un arreglo se utilizan los corchetes con el 
subíndice  del  elemento  deseado,  por  ejemplo  v[3]  accede  al  cuarto 
elemento del arreglo v. Debe tenerse en cuenta que los elementos de un 
arreglo se numeran desde 0 (cero) en adelante, hasta el tamaño menos 
uno. Las estructuras tienen la forma
struct mi_estructura {
int val1;
long val2;
} miestruc;
Para acceder a un elemento de una estructura se utiliza el operador punto 
(.). Por ejemplo, para acceder al campo de tipo long de la estructura de 
arriba, y asignarle un valor, se utiliza el operador de esta manera
miestruc.val2 = 70000;
La  igualdad  en  C  se  comprueba  con  el  operador  ==,  el  cual  no  debe 
confundirse  con  el  operador  =  que  es  el  operador  de  asignación. 
Intercambiar  inadvertidamente  estos  dos  operadores  es  una  de  las 
confusiones más típicas en los programadores principiantes de C. Además, 
considerando que toda expresión tiene un valor numérico en C, y que todo 
valor numérico a su vez tiene un valor de verdad (cero para verdadero y 
distinto de cero para falso), un caso como
if(n = 3) {
/* Siempre se ejecutan estas sentencias */
…
…
…
}

No será interpretado como un error para el compilador. En este caso la 
condición  del  if  siempre  se  evalúa  como  verdadero,  ya  que  es  una 
asignación de valor 3. El valor numérico de una expresión aritmética de 
asignación es el valor asignado, y como el resultado es 3 y por lo tanto, 
distinto de cero, se considera como verdadero. Esto es muy diferente de
if(n == 3) {
/* Estas sentencias solo se ejecutan si n es igual a tres */
…
…
…
}
Además  en  este  último  caso  el  valor  de  n  no  se  modifica  como  en  el 
primero.
El operador para comparar por distinto es !=.
Strings
En C no existe el tipo de datos String como en otros lenguajes. Un string en 
C  es  un  conjunto  de  caracteres  almacenados  consecutivamente  en 
memoria. El último carácter del string debe ser siempre el carácter especial 
‘\0’, cuyo valor numérico es cero. Esta es la forma de marcar el final del 
string. Por lo tanto la forma más común de utilizar strings en C es mediante 
arreglos de caracteres. Por ejemplo, si el arreglo de caracteres:
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
Se puede interpretar como el string “Hola\n” que es la palabra Hola seguida 
de un carácter nueva línea. Es importante que el arreglo tenga espacio 
suficiente para la cadena y para el carácter ‘\0’. Un string puede contener 
tanto caracteres imprimibles como no imprimibles. Para incluir un carácter 
especial en un string, se utiliza la secuencia de escape barra invertida, 
como en el caso del carácter nueva línea del ejemplo anterior. Si bien, como

se mencionó anteriormente, C no contempla un tipo de datos básico para 
string, sí está permitido utilizar strings literales. Para demarcar los strings 
literales en el código C, se utilizan las comillas dobles. Por ejemplo, las 
siguientes líneas de código son válidas en lenguaje C:
Char cadena[] = “String de inicialización”;
miFuncion(“Esta es una cadena de caracteres”);
Función printf
La función printf pertenece a la librería estándar de C y se utiliza para 
imprimir caracteres en la salida estándar. La salida estándar en una PC de 
escritorio  es normalmente el monitor  de la misma,  mientras  que en un 
microcontrolador,  por lo general, la salida estándar es una puerta serie 
(UART). La forma más simple de utilizar printf es esta:
printf(“Hola mundo!\n”);
Que imprime en la salida estándar “Hola mundo!” seguido de un carácter 
nueva línea. Sin embargo la utilidad principal de printf es que esta función 
es capaz de imprimir con formato. Invocando a printf se pueden imprimir 
valores de variables, contantes o literales del programa aún cuando éstas 
sean de diferentes tipos. Printf realiza la conversión a caracteres apropiada 
para cada valor a imprimir siempre y cuando se utilicen las especificaciones 
de conversión necesarias. La declaración de printf es la siguiente:
int printf( char * formato, arg1, arg2, …)
Printf acepta una cantidad variable de argumentos (mínimo uno), y los tipos 
de estos argumentos no están previamente definidos, excepto el primero 
(que es char *). El primer argumento es el string de formato. Este string 
contiene  dos  tipos  de  elementos,  caracteres  comunes  y  secuencias  de 
caracteres  que  conforman  especificadores  de  conversión.  Los 
especificadores de conversión siempre comienzan con el carácter ‘%’. Printf 
se  comporta  de  la  siguiente  manera.  Recorre  el  string  de  formato  de 
izquierda  a  derecha  y  cada  vez  que  encuentra  un  carácter  común  lo 
imprime  en  la  salida  estándar.  En  cambio,  cuando  encuentra  un 
especificador de conversión busca (posicionalmente) en los argumentos, el 
valor  a  convertir.  En  la  siguiente  tabla  se  muestran  algunos  de  los 
especificadores de conversión más utilizados:
Especificador 
de conversión
Tipo de 
argument
Impreso como

o
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
[-]ddd.dddddd (la cantidad de dígitos antes 
y después del punto puede modificarse)
%s
char *
Imprime caracteres de una cadena hasta un 
‘\0’
%%
-
Se utiliza para imprimir el carácter ‘%’
Los siguientes son ejemplos válidos del uso de printf:
int i, double d;
i = 5;
d = 3.14;
printf(“Valor de i = %d, valor de d = %f\n”, i, d);
printf(“Valores literales: Valor 1 = %d, Valor 2 = %f\n”, 5, 3.14);
Casting
En  C  cuando  un  operador  tiene  operandos  de  diferentes  tipos,  ocurren 
conversiones de tipos de manera automática y siguiendo un conjunto de 
reglas bien definido. El compilador no considera errónea esta situación.  En 
general se convierten los tipos más chicos a los tipos más grandes, con el 
fin de no perder información. Por ejemplo, si i es una variable entera y d una 
variable de tipo double, entonces al evaluar la expresión
i + d
Primero  se  convierte  i  a  double  y  luego  se  realiza  la  suma,  siendo  el 
resultado de la expresión un valor de tipo double.
Cuando se desea forzar una  conversión  de tipo de manera explicita se 
puede utilizar el operador unario denominado cast. Este operador consiste 
en un nombre de tipo encerrado entre paréntesis, que se antepone a una 
variable o a una expresión. En la construcción
(nombre-de-tipo) expresión
La expresión es convertida al tipo nombrado. El siguiente es un ejemplo de 
un cast explicito
unsigned long int n;

unsigned int r;
n = 1103515245 + 12345;
r = (unsigned int) (n/65536) % 32768;
Ciclo for
El ciclo for tiene la siguiente estructura
for(expr1; expr2; expr3)
proposición
Y es equivalente a
expr1;
while(expr2) {
proposición
expr3;
}
En el ciclo for, la expresión expr1 se evalúa una sola vez al principio y se 
considera una inicialización del ciclo. Luego se evalúa por verdadero o falso 
la expresión expr2. Si ocurre que expr2 es verdadero (distinto de cero), 
entonces se ejecuta la proposición, que puede ser una sentencia simple o 
un conjunto de sentencias entre llaves. Luego de ejecutar la proposición se 
evalúa la expresión expr3. El ciclo se repite evaluando expr2, proposición, 
expr3  mientras  expr2  sea  verdadero.  Ninguna  de  las  expresiones  es 
obligatoria. Si expr2 está ausente se considera verdadero, por lo tanto
for(;;) {
…
}
Es un ciclo infinito. Un ejemplo más habitual puede ser el siguiente
for(i = 0; i < n; ++i) {
…

…
…
}
Si la proposición es un conjunto de sentencias, se puede utilizar  continue 
para forzar la evaluación inmediata de expr3, sin ejecutar las sentencias 
debajo de continue. Por otro lado se puede utilizar break para interrumpir la 
iteración y saltar a la sentencia siguiente al ciclo for.
Ciclo do-while
La estructura del ciclo do-while es la siguiente
do
proposición
while(expresión);
A diferencia de los ciclos for y while, el ciclo do-while verifica la condición de 
término al final, después de realizar cada paso a través del cuerpo del ciclo. 
En el cuerpo del ciclo (proposición) se puede utilizar continue para forzar la 
evaluación inmediata de expresión, al igual que en el ciclo for. También se 
puede utilizar break para salir del ciclo do-while de forma inmediata.
