/* Ejercicio 2: Automatismo 
Un sistema de calefacción de una fábrica posee un termostato variable y cinco sensores de 
detección de apertura de accesos (portones y puertas al exterior de la fábrica). El sistema de control 
debe encender un motor que impulsa aire caliente y abrir la válvula de salida de gas, si se cumplen a 
la vez las siguientes condiciones: 
● El termostato variable desciende por debajo de 24°C, detectable por un sensor que entrega 
valores en 16 bits por un puerto. El sensor trabaja en un rango de -20°C a 80°C.  
● Por lo menos 3 de los accesos se encuentran cerrados, detectable cada acceso por un 
sensor del tipo ON/OFF, habiendo un bit por cada acceso (cuando el sensor detecta que la 
puerta/portón está cerrado, estará en ON). 
● Hay presión de gas suficiente por encima del umbral mínimo, detectable por un sensor de 
nivel del tipo ON/OFF.  
● Hay energía eléctrica, detectable por un sensor de presencia de tensión del tipo ON/OFF. 
NOTA:  
La lectura de entradas debe hacerse por polling. Otorgar en lo posible al programa una estructura en 
bloques tal que: 
1. En el primer bloque se tomen las variables de entrada y se las deposite en memoria. 
2. En el segundo bloque se instrumente la lógica consignada, utilizando las variables de 
memoria. 
3. En el tercer bloque se actualicen las salidas y sólo se escriba una salida cuando exista un 
cambio respecto a su estado inmediato anterior (no escribir permanentemente). */



/**********************************************************************
 FileName:        main.c
 Dependencies:    p33FJ256GP710.h
 Processor:       dsPIC33F
 Compiler:        MPLAB� C30 v2.01 or higher

 Proyecto base en Lenguaje C.

 REVISION HISTORY:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Author            Date      Comments on this revision
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Sebasti�n Wahler  09/03/16  Initial Release
 Marcelo G�mez     10/03/19  Actualizaci�n (Se incorpor� campo de bits)
 Sebasti�n Wahler  22/03/22  Entradas/Salidas Digitales
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**********************************************************************/

#include <p33FJ256GP710.h>

typedef union{
    struct{
        unsigned int:6;
        unsigned int PS_ON:1;
        unsigned int PS_OFF:1;
        unsigned int:5;
        unsigned int PS_SEG:1;
    }pulsadores;
    unsigned int completo;
}t_sensores;

typedef union{
    struct{
        unsigned int LUZ_VERDE:1;
        unsigned int LUZ_ROJA:1;
    };
    unsigned int completo;
}t_leds;

#define APAGADO ((leds.LUZ_ROJA) && !(leds.LUZ_VERDE))
#define ENCENDIDO ((leds.LUZ_VERDE) && !(leds.LUZ_ROJA))
int main(void) {

    AD1PCFGH = 0xFFFF;
    AD1PCFGL = 0xFFFF;
    AD2PCFGL = 0xFFFF;

    TRISD=0x20C0;
    TRISA=0x0000;

    t_sensores sensores;
    t_leds leds;

    leds.LUZ_ROJA=1;
    leds.LUZ_VERDE=0;
    PORTA=leds.completo;

    while(1){
        while (APAGADO){
            sensores.completo=PORTD;
            if (sensores.pulsadores.PS_ON && sensores.pulsadores.PS_SEG){
                leds.LUZ_ROJA=0;
                leds.LUZ_VERDE=1;
                PORTA=leds.completo;
            }
        }
        while (ENCENDIDO){
            sensores.completo=PORTD;
            if ((sensores.pulsadores.PS_OFF) || !(sensores.pulsadores.PS_SEG)){
                leds.LUZ_ROJA=1;
                leds.LUZ_VERDE=0;
                PORTA=leds.completo;
            }
        }
    }
}

