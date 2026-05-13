# Contenido extraído de AC - TP3 - 2026.pdf

 
ARQUITECTURA DE COMPUTADORAS 
 
​TRABAJO PRÁCTICO Nº 3 
​ 
Temas: ADCs. DMA. 
 
Objetivos: 
- Conocimiento en el uso de ADC. 
- Conocimiento en el uso de DMA. 
 
Material de soporte: 
- Para resolver el práctico se propone consultar el “Material para clases prácticas”, como así 
también la sección correspondiente a este práctico, disponible en el Aula Virtual. 
- Utilizar el proyecto base proyectobase3.X disponible en el Aula Virtual. 
 
 
### ### Ejercicio 1: Conversión ADC – Polling. 
 
Escribir un programa que realice un monitoreo continuo de 2 pulsadores conectados en los pines 
RD6 y RD7. Dependiendo del pulsador accionado se deberá realizar una lectura analógica en 
particular. 
Para RD6 la conversión AD deberá ser: AN2 - 12 bits – Entero signado. 
Para RD7 la conversión AD deberá ser: AN5 - 10 bits – Entero no signado. 
 
El programa deberá mantener dos arreglos (buffers) de 8 posiciones. Almacenar cada valor 
convertido en el buffer correspondiente, utilizando un índice circular. Cada vez que un valor 
convertido sea igual a 0 se deberá incrementar un contador global, y enviar dicho valor actualizado 
del contador por el PORTE, donde habrá LEDS conectados en los pines. 
 
 
### ### Ejercicio 2: Conversión ADC  – DMA. 
 
Escribir un programa que realice muestreos y mediciones de temperaturas en valores analógicos, 
relacionados a un brazo robot. Para ello, los valores analógicos de temperaturas serán ingresados 
por los pines AN0 y AN1, y el programa deberá convertir continuamente valores que ingresan por 
AN0 y AN1, en secuencia. Es decir, convierte AN0, luego AN1, luego AN0, y así sucesivamente. La 
transferencia deberá hacerse por DMA dado que el programa principal se encontrará abocado a 
procesar los comandos de posicionamiento enviados por un joystick conectado a un brazo robótico.  
​
Para la adquisición con DMA: 
-​
Configurar un arreglo (buffer) de 6 posiciones. 
-​
Considerar que hay 3 muestras de AN0 y 3 de AN1. 
-​
Completar el buffer automáticamente. 
 
En el programa principal se controlarán los comandos, que se reciben por los pines del PORTB, 
siendo el mapeo de estos de la siguiente manera: 
 
- UP pin RB0  
- DOWN pin RB1 
- HOLD pin RB3 
- RELEASE pin RB4 
 
Los comandos UP, DOWN son comandos de desplazamiento del brazo (TIPO 1), mientras que los 
comandos HOLD y RELEASE son comandos de acciones relacionados al brazo sobre la posición 
actual(TIPO 2). Estos comandos deben censarse continuamente y enviar el estado de los mismos por 
el PORTE organizando las lecturas por tipo de comando, anteponiendo en el nibble más significativo 
 
Año 2026 
UNPSJB – Facultad de Ingeniería 
Página 1 de 2 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
el tipo de comando y en el menos significativo el valor del comando. Así por ejemplo, si se presiona 
DOWN, el valor a enviar por el PORTE para informar sería el siguiente:  0001 0010 (0x12). 
 
Con respecto a valores de temperatura por AN0 y AN1, éstos tienen que ser almacenados en la 
memoria DMA, y serán considerados comandos TIPO 3, y cuando el buffer esté completo deberá ser 
enviado un valor indicando dicha situación por el PORTE 0011 0000 (0x30). 
 
 
Año 2026 
UNPSJB – Facultad de Ingeniería
