#include <xc.h>

// ==============================================================================
// EJEMPLO 3: Código extraído del Manual de Microchip (Sección 6.5.5)
// ¡Corregido! El traductor de Google había traducido "void" como "nulo" y 
// "return" como "devolver". Aquí está el código C original y funcional.
// Muestra cómo habilitar múltiples timers y asignarles distintas prioridades.
// ==============================================================================

void enable_interrupts(void)
{
    /* Establezca CPU IPL en 0, habilite las interrupciones de nivel 1-7 */
    /* Aquí no se realiza ninguna restauración del estado anterior de IPL de la CPU */
    SRbits.IPL = 0;
    return;
}

void disable_interrupts(void)
{
    /* Establezca la IPL de la CPU en 7, deshabilite las interrupciones de nivel 1-7 */
    /* Aquí no se guarda la configuración actual de IPL de la CPU */
    SRbits.IPL = 7;
    return;
}

void init_interrupts(void)
{
    /* Habilitar anidamiento de interrupciones aquí */
    INTCON1bits.NSTDIS = 0;
    
    /* Establece la prioridad de interrupción del Timer3 en 6 (el nivel 7 es el más alto) */
    IPC2bits.T3IP = 6;
    
    /* Establece la prioridad de interrupción del Timer2 en 5 */
    IPC1bits.T2IP = 5;
    
    /* Establece la prioridad de interrupción de aviso de cambio (Change Notification) en 4 */
    IPC4bits.CNIP = 4;
    
    /* Establece la prioridad de interrupción del Timer4 en 3 */
    IPC6bits.T4IP = 3; 
    
    /* Establece la prioridad de interrupción del Temporizador1 en 2 */
    IPC0bits.T1IP = 2; 
    
    /* Restablecer el indicador (flag) de interrupción del temporizador 1 */
    IFS0bits.T1IF = 0;
    /* Restablecer el indicador de interrupción del Timer2 */
    IFS0bits.T2IF = 0;
    /* Restablecer el indicador de interrupción del Timer3 */
    IFS0bits.T3IF = 0;
    /* Restablecer el indicador de interrupción del Timer4 */
    IFS1bits.T4IF = 0;
    
    /* Habilitar interrupciones CN (Change Notification) */
    IEC1bits.CNIE = 1;

    /* Habilitar interrupción del Temporizador1 */
    IEC0bits.T1IE = 1;
    /* Habilitar la interrupción del Timer2 (base de tiempo PWM) */
    IEC0bits.T2IE = 1;
    /* Habilitar interrupción del Timer3 */
    IEC0bits.T3IE = 1;
    /* Habilitar la interrupción del Timer4 (reemplazo del Timer 2) */
    IEC1bits.T4IE = 1;
    /* Restablecer el indicador de interrupción de aviso de cambio */
    IFS1bits.CNIF = 0;
    
    return;
}

int main(void) {
    // Apago las interrupciones globalmente mientras configuro
    disable_interrupts();
    
    // Cargo la configuración del manual
    init_interrupts();
    
    // Vuelvo a encender el sistema de interrupciones
    enable_interrupts();
    
    while(1) {
        // Ejecución normal.
    }
    
    return 0;
}


// --- Rutinas de Servicio (ISR) del ejemplo del manual ---

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
    /* Inserte el código ISR aquí*/
    /* Borrar interrupción del Temporizador1 */
    IFS0bits.T1IF = 0;
}

void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void)
{
    /* Inserte el código ISR aquí*/
    /* Borrar interrupción del Timer2 */
    IFS0bits.T2IF = 0;
}

void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void)
{
    /* Inserte el código ISR aquí*/
    /* Borrar interrupción del Timer3 */
    IFS0bits.T3IF = 0;
}

void __attribute__((__interrupt__, no_auto_psv)) _T4Interrupt(void)
{
    /* Inserte el código ISR aquí*/
    /* Borrar interrupción del Timer4 */
    IFS1bits.T4IF = 0;
}

void __attribute__((__interrupt__, no_auto_psv)) _CNInterrupt(void)
{
    /* Inserte el código ISR aquí*/
    /* Borrar interrupción CN */
    IFS1bits.CNIF = 0;
}
