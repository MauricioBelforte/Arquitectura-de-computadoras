/* 
 * ARQUITECTURA DE COMPUTADORAS - UNPSJB
 * KERNEL POR COPIA DE STACK (Mtodo Pizarra) - kernel.c
 */

#include <p33FJ256GP710.h>
#include "kernel.h"

// Direcciones de los procesos (vienen de main.c)
extern unsigned int dirA, dirB, dirC;

// Arreglos que actan como "depsitos" de memoria para cada proceso
unsigned int arregloProcA[TOPE_ARREGLOS];
unsigned int arregloProcB[TOPE_ARREGLOS];
unsigned int arregloProcC[TOPE_ARREGLOS];

int contT1 = 0;          // Contador para el Quantum
int estadoProceso = 0;   // 0=A, 1=B, 2=C

// Macros para resguardar los registros de trabajo (W0-W14)
#define GUARDAR_REGISTROS() asm volatile("push.d w0 \n push.d w2 \n push.d w4 \n push.d w6 \n push.d w8 \n push.d w10 \n push.d w12 \n push w14")
#define RESTAURAR_REGISTROS() asm volatile("pop w14 \n pop.d w12 \n pop.d w10 \n pop.d w8 \n pop.d w6 \n pop.d w4 \n pop.d w2 \n pop.d w0")

void init(void) {
    int i;
    for(i=0; i<TOPE_ARREGLOS; i++) {
        arregloProcA[i] = 0; arregloProcB[i] = 0; arregloProcC[i] = 0;
    }
    
    /* 
     * INICIALIZACIN DE DEP"SITOS
     * Colocamos la direccin de inicio en la base del arreglo.
     * El RETFIE buscar el PC en el fondo de la zona copiada.
     */
    arregloProcA[0] = dirA;
    arregloProcB[0] = dirB;
    arregloProcC[0] = dirC;
}

void confReloj(void) {
    T1CON = 0;
    T1CONbits.TCKPS = 0; // 1:1
    TMR1 = 0;
    PR1 = VALOR_PR1;
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
 * PLANIFICADOR (Mtodo del Profesor)
 * Intercambia el contenido del stack fsico con los arreglos de RAM.
 */
void planificador(void) {
    // Retrocedemos el puntero de pila para capturar todo el contexto (PC, SR y Ws)
    unsigned int* puntero = (unsigned int*)WREG15; 
    puntero -= DESPLAZAMIENTO; // El compilador resta (DESPLAZAMIENTO * 2) bytes automáticamente
    int i;

    switch(estadoProceso) {
        case 0: // Saliendo A -> Entrando B
            for(i=0; i<TOPE_ARREGLOS; i++) {
                arregloProcA[i] = *puntero;    // Guardamos stack de A en su arreglo
                *puntero = arregloProcB[i];    // Cargamos arreglo de B en el stack
                puntero++;
            }
            estadoProceso = 1;
            break;
            
        case 1: // Saliendo B -> Entrando C
            for(i=0; i<TOPE_ARREGLOS; i++) {
                arregloProcB[i] = *puntero;
                *puntero = arregloProcC[i];
                puntero++;
            }
            estadoProceso = 2;
            break;
            
        case 2: // Saliendo C -> Entrando A
            for(i=0; i<TOPE_ARREGLOS; i++) {
                arregloProcC[i] = *puntero;
                *puntero = arregloProcA[i];
                puntero++;
            }
            estadoProceso = 0;
            break;
    }
}

void __attribute__((interrupt, auto_psv)) _T1Interrupt(void) {
    IFS0bits.T1IF = 0;
    
    // CORRECCIN: Resetear el contador de quantum (contT1)
    if (++contT1 >= QUANTUM) {
        contT1 = 0; 
        
        /* 
         * PASOS CR?TICOS PARA QUE EL M"TODO FUNCIONE:
         * 1. Meter registros W0-W14 al stack para que entren en la copia.
         * 2. Swappear la memoria.
         * 3. Sacar los registros del nuevo proceso del stack.
         */
        GUARDAR_REGISTROS();
        planificador();
        RESTAURAR_REGISTROS();
    }
}
