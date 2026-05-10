# Contenido extraído de Conversor Analógico_Digital.pdf

Conversor Analógico/Digital
Arquitectura de Computadoras
Departamento de Informática
Facultad de Ingeniería
UNPSJB - Trelew

Temario
- Conceptos generales de conversión analógico a digital
- El conversor ADC incluido en los microcontroladores 
dsPIC33F

Conceptos generales
V
t
2,35V
481
5V
1023
t1
0

Conceptos generales
En el gráfico anterior:
- Existe un valor analógico que se mide en un pin de entrada analógica
- El valor analógico se mide en Volts, y tiene un rango posible, supongamos de 
0 a 5V
- Los dispositivos ofrecen uno o más voltajes de referencia. Por ejemplo de 0 a 
5V.
- La escala se divide en saltos enteros, dependiendo de la cantidad de bits del 
resultado digitalizado. Por ejemplo, con 10 bits el rango se divide en 1024 
saltos discretos.
- El tope de escala es 5V = 1023 (ó 3FF, suponiendo entero sin signo de 
10bits)

Conceptos generales
En el gráfico:
- En el tiempo t1 el valor analógico de entrada es 2,35V. En consecuencia el 
ADC entregará el valor 481 (entero).
- Nosotros recibimos 481. Cómo hacemos la traducción?:
  - 481 x (5V/1023) = 2,35V
  - Si bien en C conviene hacer esta cuenta así: (481 x 5V) /1023 = 2,35V
- Suponiendo que medimos un tope de escala, 5V. Entonces el ADC nos 
entregará un 1023, si hacemos la cuenta:
  - (1023 x 5V) / 1023 = 5V (que es el tope de escala)
- Importante: Si un valor analógico está entre dos escalones, el conversor 
aproxima a uno. Siempre nos entrega un valor entero.

Conceptos generales
- En general el valor de voltaje eléctrico que ingresa al pin del conversor 
proviene de un transductor.
- Un transductor es un dispositivo que transforma un valor de alguna magnitud 
física en otra.
- Dado que los conversores esperan sólo un valor de voltaje eléctrico, en 
general se usan transductores que transforman otras magnitudes físicas 
(humedad, presión, distancia, temperatura, etc) en un voltaje eléctrico en un 
rango determinado (por ejemplo de 0 a 5V)

Conceptos generales
- Esto implica que hay otra traducción a tener en cuenta. En general estará 
explicado en el enunciado.
- Ejemplo: Si decimos que tenemos un sensor de humedad de 0 a 100%, 
entonces seguramente el 100% de humedad será igual a 5V, igual a 1023 
(con 10 bits)
  - 100% (humedad) = 5V = 1023

Conceptos generales
El tiempo t1 del gráfico en realidad se divide en dos tiempos muy breves:
- Tiempo de muestreo (en inglés sampling)
  - En este tiempo se toma muestra de la entrada analógica
- Tiempo de conversión (en inglés decimos tiempo de holding porque el valor 
es “mantenido” estable durante la conversión)
  - En este tiempo se desconecta la entrada y se convierte la muestra obtenida.
Por eso se habla de Sampling/Holding (durante el Holding se da la conversión 
propiamente dicha)

ADC en el dsPIC33F
Se detallan algunas características del módulo ADC disponible en el 
microcontrolador utilizado en nuestras prácticas.
- En nuestro caso tenemos dos ADC disponibles ADC1 y ADC2.
- Además 32 pines pueden ser entradas analógicas (AN0 a AN31)
- Los ADC tienen canales de conversión. Por lo tanto debemos conectar una 
entrada analógica (ANx) a un canal (en general CH0) antes de poder 
convertir esa entrada.
- El voltaje de referencia podría entrar por 2 pines del exterior.
- También permite que el voltaje de referencia sea el voltaje de alimentación 
del microcontrolador (vamos a usar esta opción en general).

ADC en el dsPIC33F
Se detallan algunas características del módulo ADC disponible en el 
microcontrolador utilizado en nuestras prácticas.
- Permite usar 10 bits o 12 bits para conversión. Tener en cuenta las 
diferencias.
  - Con 10 bits el rango total se divide en 1024 saltos discretos
  - Con 12 bits el mismo rango se divide en 4096 saltos discretos (por lo tanto tenemos mayor 
resolución)
- Veamos la diferencia en la resolución, suponiendo rango de 0V a 5V
  - Con 10 bits cada escalón equivale a: 5V/1024 = 4,88 mV
  - Con 12 bits cada escalón equivale a: 5V/4096 = 1,22 mV

ADC en el dsPIC33F
Sobre tiempos de sampling/holding, tomado del manual de referencia disponible 
en el Aula Virtual

ADC en el dsPIC33F
Se detallan algunas características del módulo ADC disponible en el 
microcontrolador utilizado en nuestras prácticas.
- Hay diferentes opciones para provocar los siguientes eventos:
  - Inicio de muestreo
  - Fin de muestreo y comienzo de conversión
- El final de la conversión se puede determinar por polling.
- El final de la conversión se puede determinar por interrupciones. Es más 
natural usar un ADC por interrupciones que por polling.
- El ADC se puede complementar con DMA (como muchos otros dispositivos). 
Esto se justifica para grandes cantidades de conversiones.
