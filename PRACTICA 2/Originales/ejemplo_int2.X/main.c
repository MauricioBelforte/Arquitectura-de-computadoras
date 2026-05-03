/*
 * Arquitectura de Computadoras
 * Facultad de Ingeniería
 * UNPSJB - Trelew
 *
 * Modificado por: IA Assistant
 * Descripción: Ejemplo puramente dedicado a la interrupción de un Timer.
 * 
 * ¿QUÉ HACE ESTE PROGRAMA?
 * A diferencia del Proyecto Base 2, este código es la expresión más minimalista
 * posible de un Timer. Su único propósito es despertar al microcontrolador 
 * de manera asíncrona exactamente cada 100 milisegundos (0,1 segundos) y no 
 * hacer nada en el bucle principal mientras espera.
 *
 * MATEMÁTICA DEL TIMER (A 40 MHz):
 * - Frecuencia (Fcy): 40 MHz -> Cada latido (Tcy) dura 0,025 us.
 * - Prescaler: Configurado en 1:64. El TMR1 suma "1" cada 1,6 us (0,025 * 64).
 * - PR1 (Límite): 62500. 
 * - Desborde (El Disparo): El TMR1 choca contra el PR1 y se desborda tras 100.000 us (1,6 us * 62500).
 *   ¡Este "desborde" (reiniciarse a cero) es el evento exacto que genera la interrupción!
 * - 100.000 us equivalen exactamente a 100 milisegundos (0,1 segundos).
 */
#include "xc.h"

/*
 * Rutina de Atención de la interrupción del Timer1
 * Función: Se ejecuta automáticamente cada 100 milisegundos.
 */
void __attribute__((interrupt, auto_psv)) _T1Interrupt( void ) {
    
    // Aquí iría el código útil (ej. prender un LED, leer un sensor, etc)
    // que necesitamos ejecutar en este intervalo de tiempo estricto.
    
    // EXTREMADAMENTE OBLIGATORIO: Bajar la bandera
    // Le avisamos al hardware que ya "atendimos" el evento del Timer para que 
    // nos deje salir de esta función y no vuelva a entrar infinitamente sola.
    IFS0bits.T1IF = 0;
}

/*
 * Función de Inicialización del Timer1
 */
void config(void) {
    // 1. Configuración Básica del Timer
    T1CONbits.TON = 0;      // Apagamos el motor del Timer mientras lo configuramos.
    T1CONbits.TCS = 0;      // Usar reloj interno (Fcy) como fuente, no un pin externo.
    T1CONbits.TCKPS = 2;    // Ajustar la caja de cambios (Prescaler). El 2 binario (10) equivale a 1:64.
    
    // 2. Variables matemáticas del Timer
    TMR1 = 0;               // Reiniciamos a cero el contador vivo por las dudas.
    PR1 = 62500;            // Seteamos la "alarma" al valor calculado para que suene a los 100ms.
    
    // 3. Configuración de la Interrupción (El aviso a la CPU)
    IPC0bits.T1IP = 1;      // Le asignamos Prioridad 1 (la más baja). Así, si hay otra interrupción más grave, la dejará pasar primero.
    IFS0bits.T1IF = 0;      // Bajamos cualquier bandera vieja o ruido que haya quedado levantado por error en la memoria.
    IEC0bits.T1IE = 1;      // Giramos la llave de la "puerta" general para que este Timer1 específico pueda interrumpir a la CPU.
    
    // 4. Encendido
    T1CONbits.TON = 1;      // ¡Start! El cronómetro empieza a avanzar invisiblemente en paralelo al resto del programa.
}

/*
 * Programa Principal
 */
int main(void) {
    // 1. Configuramos y arrancamos el Timer1
    config();
    
    // 2. Bucle infinito (Super Loop)
    while(1) {
        // Nop() es una instrucción pura en lenguaje Ensamblador (No Operation).
        // Literalmente le dice al procesador físico "perdé el tiempo durante 1 latido/ciclo de reloj".
        // Como el micro está "aburrido" dando vueltas sin nada útil que hacer acá adentro,
        // cuando pasan los 100ms exactos, el hardware del Timer interrumpe la ejecución sin piedad.
        Nop();
        Nop();
        Nop();
    }
}
