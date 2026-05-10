/* 
 * ARQUITECTURA DE COMPUTADORAS - UNPSJB
 * PROYECTO: TP2-2REVISADO
 * kernel.c - Implementacin del Planificador por Copia de Stack
 */

#include <p33FJ256GP710.h>
#include "kernel.h"

// Direcciones de los procesos (definidas en main.c)
extern unsigned int dirA, dirB, dirC;

// Arreglos de resguardo para cada proceso
unsigned int arregloProcA[TOPE_ARREGLOS];
unsigned int arregloProcB[TOPE_ARREGLOS];
unsigned int arregloProcC[TOPE_ARREGLOS];

int contT1 = 0;          // Contador para el Quantum
int estadoProceso = 0;   // Planificador: 0=A, 1=B, 2=C

// Macros de bajo nivel para resguardar el contexto de la CPU (W0-W14)
#define GUARDAR_REGISTROS() asm volatile("push.d w0 \n push.d w2 \n push.d w4 \n push.d w6 \n push.d w8 \n push.d w10 \n push.d w12 \n push w14")
#define RESTAURAR_REGISTROS() asm volatile("pop w14 \n pop.d w12 \n pop.d w10 \n pop.d w8 \n pop.d w6 \n pop.d w4 \n pop.d w2 \n pop.d w0")

void init(void) {
    int i;
    for(i=0; i<TOPE_ARREGLOS; i++) {
        arregloProcA[i] = 0; arregloProcB[i] = 0; arregloProcC[i] = 0;
    }
    
    // Inicializamos el PC de cada proceso en la base de su arreglo
    // El RETFIE buscar el PC al final de la zona de stack restaurada
    arregloProcA[0] = dirA;
    arregloProcB[0] = dirB;
    arregloProcC[0] = dirC;
}

void confReloj(void) {
    T1CON = 0;
    T1CONbits.TCKPS = 0; // 1:1
    TMR1 = 0;
    PR1 = VALOR_PR1;     // 150us
    IPC0bits.T1IP = 5;
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    T1CONbits.TON = 1;
}

void boot(void) {
    init();
    confReloj();
}

/* 
 * PLANIFICADOR: Mtodo de Copia de Stack (Pizarra)
 * Intercambia la memoria del Stack fsico con los arreglos en RAM.
 */
void planificador(void) {
    // Calculamos la base de la zona de stack a intercambiar
    unsigned int* puntero = (unsigned int*)WREG15; 
    puntero -= DESPLAZAMIENTO; 
    int i;

    switch(estadoProceso) {
        case 0: // De Proceso A hacia Proceso B
            for(i=0; i<TOPE_ARREGLOS; i++) {
                arregloProcA[i] = *puntero;    // Guardamos A
                *puntero = arregloProcB[i];    // Cargamos B
                puntero++;
            }
            estadoProceso = 1;
            break;
            
        case 1: // De Proceso B hacia Proceso C
            for(i=0; i<TOPE_ARREGLOS; i++) {
                arregloProcB[i] = *puntero;    // Guardamos B
                *puntero = arregloProcC[i];    // Cargamos C
                puntero++;
            }
            estadoProceso = 2;
            break;
            
        case 2: // De Proceso C hacia Proceso A
            for(i=0; i<TOPE_ARREGLOS; i++) {
                arregloProcC[i] = *puntero;    // Guardamos C
                *puntero = arregloProcA[i];    // Cargamos A
                puntero++;
            }
            estadoProceso = 0;
            break;
    }
}

void __attribute__((interrupt, auto_psv)) _T1Interrupt(void) {
    IFS0bits.T1IF = 0;
    
    if (++contT1 >= QUANTUM) {
        contT1 = 0; 
        
        // RESGUARDO COMPLETO: Antes de mover el stack, metemos los Ws en l.
        GUARDAR_REGISTROS();
        planificador();
        RESTAURAR_REGISTROS();
    }
}
