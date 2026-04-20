#include "xc.h"

// ==============================================================================
// EJEMPLO 1: Interrupción Externa 0 (INT0)
// Este código demuestra cómo configurar un pin externo para lanzar una
// interrupción. Ideal para probar con Stimulus o un pulsador físico.
// ==============================================================================

// FOSC = 40MHz (Configuraciones de los fuses deben coincidir)
// Este es un esqueleto básico. 

void init_INT0(void) {
    // 1. Configurar el pin asociado a INT0 como entrada
    // En los dsPIC33F, INT0 siempre está mapeado a un pin específico, por ejemplo RA11 (Revisar datasheet específico)
    TRISAbits.TRISA11 = 1; 

    // 2. Configurar el flanco de disparo
    INTCON2bits.INT0EP = 0; // 0 = Flanco ascendente (positivo), 1 = Flanco descendente (negativo)
    
    // 3. Asignar la Prioridad de la interrupción (Por defecto es 4)
    IPC0bits.INT0IP = 4; // Nivel 4 de prioridad
    
    // 4. Limpiar la bandera de la interrupción por si había disparos previos
    IFS0bits.INT0IF = 0;
    
    // 5. Habilitar la interrupción externa 0
    IEC0bits.INT0IE = 1;
}

int main(void) {
    // Configuración Inicial
    TRISBbits.TRISB0 = 0; // Pin RB0 como salida (Para un LED)
    LATBbits.LATB0 = 0;   // Iniciar apagado
    
    init_INT0(); // Inicializar INT0
    
    while(1) {
        // El bucle principal no hace nada. 
        // El microcontrolador está "esperando" a la interrupción.
    }
    return 0;
}

// ==============================================================================
// Rutina de Servicio de Interrupción (ISR) para INT0
// ==============================================================================
void __attribute__((__interrupt__, no_auto_psv)) _INT0Interrupt(void) {
    // 1. Acciones de la interrupción: Invertir estado del LED
    LATBbits.LATB0 = ~LATBbits.LATB0;

    // 2. IMPORTANTE: Limpiar siempre la bandera de interrupción al final
    IFS0bits.INT0IF = 0;
}
