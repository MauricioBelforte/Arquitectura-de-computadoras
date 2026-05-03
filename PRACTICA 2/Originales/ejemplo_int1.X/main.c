/*
 * Arquitectura de Computadoras
 * Facultad de Ingeniería
 * UNPSJB - Trelew
 *
 * Modificado por: IA Assistant
 * Descripción: Ejemplo de interrupciones utilizando Change Notification (CN).
 * 
 * ¿QUÉ ES EL CHANGE NOTIFICATION (CN)?
 * Es un tipo especial de interrupción. A diferencia de INT0 que busca un flanco 
 * específico (subida o bajada), el módulo CN detecta CUALQUIER CAMBIO de estado 
 * en un pin. Es decir, salta a la interrupción tanto cuando apretás el botón 
 * (0V a Nivel Alto) como cuando lo soltás (Nivel Alto a 0V).
 * 
 * ¿QUÉ HACE ESTE PROGRAMA EN PARTICULAR?
 * Actúa como un "Espejo Físico". El pin RC14 (conectado internamente al módulo 
 * CN0) funciona como entrada (ej. un botón). El pin RD12 funciona como salida 
 * (ej. un LED). Cada vez que el botón cambia de estado físico, la interrupción 
 * se dispara, lee el voltaje del botón, y manda ese mismo voltaje al LED.
 */
#include "xc.h"

/*
 * Rutina de Atención de la Interrupción de Change Notification (CN)
 * Función: Se dispara automáticamente cada vez que el pin RC14 cambia su estado
 * físico de 0 a 1, o de 1 a 0.
 */
void __attribute__((interrupt, auto_psv)) _CNInterrupt (void)
{
    // EXTREMADAMENTE OBLIGATORIO: Apagar la bandera de interrupción.
    // Si no la bajamos por software, el procesador se cuelga infinitamente acá.
    IFS1bits.CNIF = 0;
  
    // Leemos el estado físico actual del pin RC14 (nuestro botón)
    if (PORTCbits.RC14 == 1)
    {
        // Si el botón tiene voltaje alto (1), encendemos el LED en RD12
        PORTDbits.RD12 = 1;
    }
    else
    {
        // Si el botón no tiene voltaje (0), apagamos el LED en RD12
        PORTDbits.RD12 = 0;
    }
}

/*
 * Función de Inicialización (Setup del Hardware)
 * Configura los pines de entrada/salida y enciende el módulo de interrupción CN.
 */
void ini (void)
{
    // 1. Configuración de la Interrupción Change Notification
    CNEN1bits.CN0IE = 1; // Habilita la detección de cambio específicamente para el canal CN0 (que está multiplexado en el pin RC14).
    IEC1bits.CNIE = 1;   // Gira la llave maestra para habilitar todas las interrupciones CN globalmente en la CPU.

    // 2. Configuración de Entradas y Salidas (Registros TRIS)
    // TRISC en 0xFFFF (1111 1111 1111 1111 en binario) configura TODO el Puerto C como ENTRADA.
    // Nos interesa especialmente que el bit 14 (RC14) sea entrada para poder leer el botón.
    TRISC = 0xFFFF;		
  
    // TRISD en 0xEFFF (1110 1111 1111 1111 en binario) configura el Puerto D.
    // El dígito 'E' en Hexadecimal es 1110. ¡Ese '0' en la posición 12 configura a RD12 como SALIDA!
    // Por esa salida mandaremos el voltaje al LED.
    TRISD = 0xEFFF;		
}

/*
 * Programa Principal
 */
int main (void)
{
    // 1. Configuramos el hardware
    ini ();
  
    // 2. Bucle infinito (Super Loop).
    // El procesador principal se queda atrapado acá sin ejecutar nada más, 
    // delegando todo el control a la interrupción asíncrona _CNInterrupt 
    // que se despertará por hardware solo cuando toquemos el botón.
    while (1);
}
