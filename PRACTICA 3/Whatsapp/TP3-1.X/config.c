#include "xc.h"

void initPORTS(void) {
    TRISD = 0xFFFF; // RD6 y RD7 configurados como entradas digitales (Pulsadores)
    TRISE = 0x0000; // Todo PORTE configurado como salida digital (LEDS de visualización)
    LATE = 0x0000;  // Apaga todos los leds inicialmente
}

void configSignado(void){
    AD1CON1bits.AD12B = 1;    // Habilita modo ADC de 12 bits, 1 canal de muestreo (S/H)
    AD1CON1bits.FORM = 1;     // Formato de datos de salida: Entero con signo (Signed Integer)
    AD1CON3bits.SAMC = 14;    // Tiempo de auto-muestreo = 14 TAD (mayor al mínimo de 12 TAD en 12 bits)
    AD1CHS0bits.CH0SA = 2;    // Conecta el pin físico AN2 como entrada positiva al Canal 0 S/H
    AD1CHS0bits.CH0NA = 0;    // Conecta la entrada negativa al pin de referencia negativo (VREF- / AVSS)
}

void configSinSigno(void){
    AD1CON1bits.AD12B = 0;    // Habilita modo ADC de 10 bits, hasta 4 canales de muestreo
    AD1CON1bits.FORM = 0;     // Formato de datos de salida: Entero sin signo (Unsigned Integer)
    AD1CON3bits.SAMC = 12;    // Tiempo de auto-muestreo = 12 TAD (mayor al mínimo de 10 TAD en 10 bits)
    AD1CHS0bits.CH0SA = 5;    // Conecta el pin físico AN5 como entrada positiva al Canal 0 S/H
    AD1CHS0bits.CH0NA = 0;    // Conecta la entrada negativa al pin de referencia negativo (VREF- / AVSS)
}

void initADC(void) {
    AD1CON1bits.SSRC = 7;     // Trigger de conversión: Modo automático (el reloj interno dispara la conversión al terminar el tiempo de muestreo)
    AD1CON1bits.ASAM = 0;     // Muestreo manual: Inicia cuando el software pone SAMP = 1, y se detiene automáticamente por SAMC
    AD1CON3bits.ADCS = 2;     // Reloj del ADC: ADCS = 2 para generar TAD = 75ns a 40 MHz (Fcy = 40Mips), cumpliendo TAD > 75ns
    
    // Antes de encender el ADC por primera vez, aplicamos la configuración inicial
    configSignado();
    
    AD1CON1bits.ADON = 1;     // Enciende el módulo ADC
}

void config(void) {
    initPORTS();
    initADC();
}
