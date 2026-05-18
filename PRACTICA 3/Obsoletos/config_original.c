#include "xc.h"

void initPORTS(void) {
    TRISD = 0xFFFF; // RD6 y RD7 de entrada
    TRISE = 0x0000; // Todo PORTE tiene LEDS de salida
    

}


void configSignado(){
    AD1CON1bits.AD12B=1;    // 12 bits, 1 canal de ADC
    AD1CON1bits.FORM=1;     // Entero signado
    AD1CON3bits.SAMC=14;    // TADs asignados a duracion de sampleo (CantBits+2)
    AD1CHS0=2;              // Conecta AN2 como input para canal 0
}

void configSinSigno(){
    AD1CON1bits.AD12B=0;    // 10 bits, 4 canales de ADC
    AD1CON1bits.FORM=0;     // Entero sin signo
    AD1CON3bits.SAMC=12;    // TADs asignados a duracion de sampleo (CantBits+2)
    AD1CHS0=5;              // Conecta AN5 como input para canal 0
}

void initADC(void) {
    // Descomentar y completar
    AD1CON1bits.SSRC=7;     // Duracion automatica de sampleo
    AD1CON1bits.ASAM=0;     // Reinicio manual de sampleo
    AD1CON3bits.ADCS=2;     // TAD dura 75ns, suficiente para trabajar con 40Mhz
    configSignado();
    /*
    AD1CON2bits.CSCNA = ;
    AD1CSSL = ;
    AD1CSSH = ;
    */
    AD1CON1bits.ADON = 1;
}

void config(void) {
    initPORTS();
    initADC();
    configSignado();
}
