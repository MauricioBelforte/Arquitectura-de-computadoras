#include <p33FJ256GP710.h>
#include "kernel.h"

extern unsigned dirA;
extern unsigned dirB;
extern unsigned dirC;

unsigned int arregloProcA[TOPE_ARREGLOS];
unsigned int arregloProcB[TOPE_ARREGLOS];
unsigned int arregloProcC[TOPE_ARREGLOS];
int contT1=0;           // Cuenta quantums transcurridos
int estadoProceso=0;

void init(void){
    int i;
    for(i=0;i<TOPE_ARREGLOS;i++){   // Inicializar arreglos con 0
        arregloProcA[i]=0;
        arregloProcB[i]=0;
        arregloProcC[i]=0;
    }
    // Inicializar direcciones de retorno (Reemplaza lo que va al PC)
    arregloProcA[0]=dirA;
    arregloProcB[0]=dirB;
    arregloProcC[0]=dirC;
}

void confReloj(void){
    T1CON=0;            // Asegurar estado por defecto
    T1CONbits.TCS=0;    // Uso reloj interno
    T1CONbits.TCKPS=0;  // Prescaler 1:1
    PR1=VALOR_PR1;      // Asigno valor de PR1 para medir 150us

    IFS0bits.T1IF=0;    // Bajo flag de interrupcion
    IPC0bits.T1IP=5;    // Prioridad 5
    IEC0bits.T1IE=1;    // Activo interrupcion por TMR1

    T1CONbits.TON=1;    // Empieza a contar
}

void boot(void){
    init();
    confReloj();
    return;
}

void planificador(void){
    unsigned int* puntero=WREG15;   // Obtiene puntero a pila
    puntero-=DESPLAZAMIENTO;        // Apunta a "Datos de A en pila"
    int i;
    switch(estadoProceso){
        case 0: //A hacia B
            for(i=0; i<TOPE_ARREGLOS ; i++){
                arregloProcA[i]=*puntero;   // Guarda pila de A
                *puntero=arregloProcB[i];   // Reemplaza por pila de B
                puntero++;
            }
            estadoProceso++;
            break;
        case 1: //B hacia C
            for(i=0; i<TOPE_ARREGLOS ; i++){
                arregloProcB[i]=*puntero;   // Guarda pila de B
                *puntero=arregloProcC[i];   // Reemplaza por pila de C
                puntero++;
            }
            estadoProceso++;
            break;
        case 2: //C hacia A
            for(i=0; i<TOPE_ARREGLOS ; i++){
                arregloProcC[i]=*puntero;   // Guarda pila de C
                *puntero=arregloProcA[i];   // Reemplaza por pila de A
                puntero++;
            }
            estadoProceso=0;
            break;
    }

}

void __attribute__((interrupt, auto_psv)) _T1Interrupt( void ){
    IFS0bits.T1IF = 0;
    if(++contT1==QUANTUM){  // Si se cumplen los quantums necesarios
        contT1=0;           // Reinicia contador
        planificador();     // Cambia el proceso
    }
}
