#include <p33FJ256GP710.h>
#include "kernel.h"


extern unsigned int dirA;
extern unsigned int dirB;
extern unsigned int dirC;

unsigned int arregloProcA[TOPE_ARREGLOS];
unsigned int arregloProcB[TOPE_ARREGLOS];
unsigned int arregloProcC[TOPE_ARREGLOS];
int contT1=0;
int estadoProceso=0;

void init(void){
    int i;
    for(i=0;i<TOPE_ARREGLOS;i++){
        arregloProcA[i]=0;
        arregloProcB[i]=0;
        arregloProcC[i]=0;
    }
    arregloProcA[0]=dirA;
    arregloProcB[0]=dirB;
    arregloProcC[0]=dirC;
}

void confReloj(void){
    T1CON=0;            // Asegurar estado por defecto
    T1CONbits.TCS=0;    // Uso reloj interno
    T1CONbits.TCKPS=0;  // Prescaler 1:1
    PR1=VALOR_PR1;           // Asigno valor de PR1 para medir 150us

    IFS0bits.T1IF=0;
    IPC0bits.T1IP=5;
    IEC0bits.T1IE=1;

    T1CONbits.TON=1;
}

void boot(void){
    init();
    confReloj();
    return;
}

void planificador(void){
    unsigned int* puntero=WREG15-DESPLAZAMIENTO;
    int i;
    switch(estadoProceso){
        case 0: //A hacia B
            for(i=0; i<TOPE_ARREGLOS ; i++){
                arregloProcA[i]=*puntero;
                *puntero=arregloProcB[i];
                puntero++;
            }
            estadoProceso++;
            break;
        case 1: //B hacia C
            for(i=0; i<TOPE_ARREGLOS ; i++){
                arregloProcB[i]=*puntero;
                *puntero=arregloProcC[i];
                puntero++;
            }
            estadoProceso++;
            break;
        case 2: //C hacia A
            for(i=0; i<TOPE_ARREGLOS ; i++){
                arregloProcC[i]=*puntero;
                *puntero=arregloProcA[i];
                puntero++;
            }
            estadoProceso=0;
            break;
    }

}

void __attribute__((interrupt, auto_psv)) _T1Interrupt( void ){
    IFS0bits.T1IF = 0;
    if(++contT1==QUANTUM){
        planificador();
    }
}
