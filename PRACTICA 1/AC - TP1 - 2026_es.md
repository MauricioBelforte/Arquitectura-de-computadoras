# Contenido extraído de AC - TP1 - 2026.pdf

 
ARQUITECTURA DE COMPUTADORAS 
 
​
TRABAJO PRÁCTICO Nº 1 
 
Temas: RISC Microchip. Manejo de instrucciones y memoria. Polling. 
 
Objetivos: 
- Programación en lenguaje C, y debugging en MPLAB.X 
- Técnica de programación por polling. Manejo de puertos de I/O. 
 
Material de soporte: 
- Para resolver el práctico se propone consultar el “Material para clases prácticas”, como así 
también la sección correspondiente a este práctico, disponible en el Aula Virtual. 
- Utilizar el proyecto base proyectobase1.X también disponible en el Aula Virtual. 
 
### Ejercicio 1: Sistema de habilitación de máquina 
 
Se desea implementar el control básico de habilitación de una máquina. La máquina sólo puede 
ponerse en funcionamiento si: 
 
- Se acciona un pulsador de ENCENDIDO PS_ON (RD6). 
- Se mantiene activa una condición de SEGURIDAD PS_SEG (RD13). 
 
Además, existe un pulsador de APAGADO PS_OFF (RD7) que fuerza la detención inmediata del 
sistema. 
 
El sistema posee dos LEDs indicadores: 
 
- LED_VERDE (RA0) → Máquina en funcionamiento 
- LED_ROJO (RA1) → Máquina detenida 
 
La máquina deberá iniciar detenida, LED_ROJO encendido y. LED_VERDE apagado. 
 
NOTA:  
El programa deberá estar controlando el estado de las entradas continuamente (polling) y actuar 
dependiendo las condiciones presentadas. 
 
### Ejercicio 2: Automatismo 
 
Un sistema de calefacción de una fábrica posee un termostato variable y cinco sensores de 
detección de apertura de accesos (portones y puertas al exterior de la fábrica). El sistema de control 
debe encender un motor que impulsa aire caliente y abrir la válvula de salida de gas, si se cumplen a 
la vez las siguientes condiciones: 
 
- El termostato variable desciende por debajo de 24°C, detectable por un sensor que entrega 
valores en 16 bits por un puerto. El sensor trabaja en un rango de -20°C a 80°C.  
- Por lo menos 3 de los accesos se encuentran cerrados, detectable cada acceso por un 
sensor del tipo ON/OFF, habiendo un bit por cada acceso (cuando el sensor detecta que la 
puerta/portón está cerrado, estará en ON). 
- Hay presión de gas suficiente por encima del umbral mínimo, detectable por un sensor de 
nivel del tipo ON/OFF. 
 
Año 2026 
UNPSJB – Facultad de Ingeniería 
Página 1 de 2 
 

 
ARQUITECTURA DE COMPUTADORAS 
 
- Hay energía eléctrica, detectable por un sensor de presencia de tensión del tipo ON/OFF. 
 
NOTA:  
La lectura de entradas debe hacerse por polling. Otorgar en lo posible al programa una estructura en 
bloques tal que: 
1.​ En el primer bloque se tomen las variables de entrada y se las deposite en memoria. 
2.​ En el segundo bloque se instrumente la lógica consignada, utilizando las variables de 
memoria. 
3.​ En el tercer bloque se actualicen las salidas y sólo se escriba una salida cuando exista un 
cambio respecto a su estado inmediato anterior (no escribir permanentemente). 
 
 
Año 2026 
UNPSJB – Facultad de Ingeniería 
Página 2 de 2
