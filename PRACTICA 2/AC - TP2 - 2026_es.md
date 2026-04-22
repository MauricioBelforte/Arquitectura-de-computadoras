# Contenido extraído de AC - TP2 - 2026.pdf

 
ARQUITECTURA DE COMPUTADORAS 
 
​
TRABAJO PRÁCTICO Nº 2 
 
Temas: Interrupciones. Timers. 
 
Objetivos:  
- Técnica de programación por interrupciones. 
- Programación de un productor – consumidor (buffer limitado). 
- Programación de timers. 
 
Material de soporte: 
- Para resolver el práctico se propone consultar el “Material para clases prácticas”, como así 
también la sección correspondiente a este práctico, disponible en el Aula Virtual. 
- Para el primer ejercicio (Productor/Consumidor) utilizar el proyecto base proyectobase2a.X 
disponible en el Aula Virtual. 
- Para el segundo ejercicio (Multitask) utilizar el proyecto base proyectobase2b.X disponible 
en el Aula Virtual. 
 
 
### ### Ejercicio 1: Productor/Consumidor 
 
El objetivo es implementar una rutina de interrupción para gestionar un buffer circular que almacene 
datos recibidos por el Puerto B (PORTB). El sistema debe operar bajo el paradigma 
Productor/Consumidor con las siguientes especificaciones: 
 
- Productor (ISR): el cuerpo de la rutina de atención para la interrupción debe resolver el 
ingreso de caracteres en un arreglo. Este arreglo (buffer) se utilizará de manera circular (se 
volverá al inicio una vez que se lo termine de recorrer). El ingreso de un caracter se detecta 
por un flanco ascendente en la Interrupción Externa (INT1). El ingreso a caracteres al buffer 
debe realizarse selectivamente, sólo debe aceptar caracteres que pertenezcan al rango de 
operadores aritméticos y números (ASCII del '0' al '9', y los símbolos '+', '-', '*', '/'). 
Cualquier otro carácter debe ser descartado. 
 
- Consumidor (Main): Debe leer los caracteres pendientes del buffer circular y trasladarlos a 
una tabla de "Log de Operaciones" en la memoria de datos. Al consumir, si el carácter es una 
letra minúscula (en caso de que el filtro del productor fallara o se modificara), el consumidor 
debe convertirlo a mayúscula antes de guardarlo en la tabla final. 
El programa principal debe ejecutar, en paralelo al consumidor, una rutina de parpadeo de un 
LED. 
 
- Temporización Dinámica (Timer): El consumidor no es constante. Se debe configurar un 
Timer para disparar la tarea de consumo con la siguiente lógica de espera: 
  - Estado inicial: Tiempo de espera base de 150us. 
  - Si no hay datos: Ell tiempo de espera aumentará de forma lineal sumando 150us 
en cada intento fallido (150us -> 300us -> 450us...), hasta un tope máximo de 900us. 
  - Si hay datos: En el momento en que se detecte y consuma al menos un carácter, el 
temporizador debe resetearse inmediatamente a su valor base de 150us. 
 
 
 
 
 
Año 2026 
UNPSJB – Facultad de Ingeniería 
Página 1 de 2 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
### ### Ejercicio 2: Multitask 
 
Escribir un programa que simule la ejecución de tres procesos independientes (procesoA, procesoB y 
procesoC) y concurrentes. El programa debe constar de los tres procesos, una rutina de atención 
para la interrupción de un reloj y un planificador que alterna el uso de la CPU entre los tres procesos. 
 
Para resolver este ejercicio tomen como base el proyectobase2b.X entregado por la cátedra en el 
Aula Virtual. En este proyecto encontrarán un esqueleto de solución. El código de los tres procesos 
ya está presente y se recomienda NO modificarlos. El código de la función boot() en kernel.c también 
está completo. Si ejecutan el proyecto tal cual está, sólo se ejecutará el procesoA. Lo que deben 
lograr es que se ejecuten en forma concurrente los tres procesos. Para esto deberán completar las 
funciones incompletas en kernel.c, además de crear las estructuras de datos necesarias. 
 
A los procesos se les asignará idéntico quantum (tiempo de ejecución). Cuando la rutina del reloj 
detecta que expiró el quantum del proceso actual, invoca al planificador. El planificador debe 
resguardar los valores de los registros del proceso actual (estado del proceso), recuperar el estado 
del proceso siguiente (previamente resguardado) y restablecer el quantum. 
 
El planificador debe constar de una estructura de datos apropiada para contener el estado de los 
procesos. Para implementar el reloj se utilizará un Timer. Una vez que se configura el timer, este 
generará interrupciones en forma regular. A estas les denominamos “interrupciones de reloj en este 
ejercicio. El quantum será igual a 2 (dos) interrupciones de reloj. Esto quiere decir que cada dos 
interrupciones del timer, se considera que se acabó el quantum del proceso actual y por lo tanto hay 
que cambiar la ejecución al proceso siguiente. 
 
Nota: Para manipular la dirección de ingreso a una rutina se puede asignar directamente el nombre 
de una función a una variable. 
Ejemplo: 
int direccion; 
… 
direccion = main; 
​
​
 
​
 
 
Año 2026 
UNPSJB – Facultad de Ingeniería
