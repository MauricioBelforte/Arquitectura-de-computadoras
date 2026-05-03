/**********************************************************************
 FileName:        main.c
 Dependencies:    p33FJ256GP710.h
 Processor:       dsPIC33F
 Compiler:        MPLAB C30 v2.01 or higher

 Ejemplo de funcionamiento de:
 	Timer1
        INT0
 	PORTS

 REVISION HISTORY:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Author            Date      Comments on this revision
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Sebastián Wahler  23/03/16  Proyecto base - Interrupciones
 Modificado        Hoy       Traducción y explicación de código.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**********************************************************************/

#include "p33FJ256GP710.h"
#include "config.h"

// Variables globales declaradas para contar las interrupciones.
// Se inicializan en 0 al arrancar el programa.
int counterTimer = 0;
int counterINT0 = 0;

/*
 * Programa Principal
 * Descripción: Este programa utiliza Timer1 para medir un intervalo de tiempo.
 * Mientras pasa el tiempo, cualquier evento en el pin de interrupción externa (INT0)
 * suma al contador `counterINT0`.
 * Cada vez que el Timer1 cuenta 10 ciclos (counterTimer > 9), el programa refleja
 * la cantidad de pulsos registrados por INT0 en los LEDs del Puerto A (LATA).
 * 
 * MATEMÁTICA DEL TIMER (A 40 MHz):
 * Si el micro opera a 40MHz, cada latido (Tcy) dura 0,025 us. 
 * Al configurar el prescaler en 1:256, el TMR1 (registro interno que lleva la cuenta) suma "1" cada 6,4 us (0,025 us * 256).
 * Al cargar un límite de PR1 = 62500, el TMR1 lo iguala y desborda tras 400.000 us (6,4 us * 62500).
 * Es decir, genera UNA interrupción exactamente cada 400 milisegundos (0,4 segundos).
 * Como el bucle principal espera 10 interrupciones (counterTimer > 9), 
 * los LEDs se actualizan cada 4 segundos exactos (0,4s * 10).
 */
int main(void) {

    // Llama a la función config() que inicializa puertos, Timer1 e interrupciones.
    config();

    // Bucle infinito (Super Loop)
    while(TRUE)
    {
        // Se ejecuta si el Timer1 generó la interrupción 10 veces
        if (counterTimer > 9 )
        {
            // Muestra en los LEDs conectados al PORTA la cantidad de veces 
            // que se activó la interrupción externa INT0 durante este período.
            LATA = counterINT0;
            
            // Reinicia los contadores para el próximo ciclo
            counterTimer = 0;
            counterINT0 = 0;
        }
    }

}
