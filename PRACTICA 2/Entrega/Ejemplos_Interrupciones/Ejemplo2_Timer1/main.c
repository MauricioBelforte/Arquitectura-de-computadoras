#include "xc.h"

// ==============================================================================
// EJEMPLO 2: Interrupción por Temporizador (Timer 1)
// Este código demuestra cómo configurar el Timer 1 para que genere 
// una interrupción periódica. Es la base de cualquier RTOS o Multitarea.
// ==============================================================================

void init_Timer1(void) {
    // 1. Apagar el Timer mientras se configura
    T1CONbits.TON = 0;
    
    // 2. Configurar el Pre-escalador (Prescaler) a un valor conocido
    // Asumiendo un reloj estándar. Preescalador 1:256
    T1CONbits.TCKPS = 0b11; 
    
    // 3. Fuente de reloj interno
    T1CONbits.TCS = 0; 
    
    // 4. Limpiar el contador actual
    TMR1 = 0;
    
    // 5. Establecer el valor de período maestro (Registro PR1)
    // Cuando TMR1 coincide con PR1, se dispara la interrupción
    PR1 = 39062; // Valor calculado según el tiempo y FOSC deseados!
    
    // 6. ---- CONFIGURAR LA INTERRUPCIÓN ----
    IPC0bits.T1IP = 5; // Nivel de Prioridad 5
    IFS0bits.T1IF = 0; // Limpiar la bandera pendiente
    IEC0bits.T1IE = 1; // Habilitar la interrupción de Timer 1
    
    // 7. Encender el Timer
    T1CONbits.TON = 1;
}

int main(void) {
    // Inicializar un pin de salida para verlo en el Stimulus
    TRISBbits.TRISB1 = 0; 
    LATBbits.LATB1 = 0;
    
    init_Timer1(); 
    
    while(1) {
        // Ejecución normal. CPU trabajando.
        // La interrupción detendrá este bucle cíclicamente.
    }
    return 0;
}

// ==============================================================================
// Rutina de Servicio de Interrupción (ISR) para Timer 1
// ==============================================================================
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void) {
    // En cada disparo del temporizador (overflow de PR1), se invierte el LED
    LATBbits.LATB1 = ~LATBbits.LATB1;

    // Limpiar siempre la bandera de finalización de interrupción de T1
    IFS0bits.T1IF = 0;
}
