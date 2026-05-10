/**********************************************************************
 FileName:        main.c
 Dependencies:    p33FJ256GP710.h
 Processor:       dsPIC33F
 Compiler:        MPLAB® C30 v2.01 or higher

 Proyecto base en Lenguaje C.

 REVISION HISTORY:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Author            Date      Comments on this revision
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Sebastián Wahler  09/03/16  Initial Release
 Marcelo Gómez     10/03/19  Actualización (Se incorporó campo de bits)
 Sebastián Wahler  22/03/22  Entradas/Salidas Digitales
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

    TRISD=0xFFFF;
    TRISA=0xFFFC;

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

