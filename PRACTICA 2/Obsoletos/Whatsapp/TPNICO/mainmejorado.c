/* 
 * ARQUITECTURA DE COMPUTADORAS - TP2 EJERCICIO 2 (MEJORADO)
 * Basado en la idea de Nico pero optimizado para rendimiento real.
 */

#include <p33FJ256GP710.h>
#include <stdio.h>
#include <stdlib.h>

// --- CONFIGURACIN ---
#define QUANTUM 2
#define STACK_SIZE 64    // Tamao de pila para cada proceso
#define VALOR_PR1 6000   // 150us aprox @ 40MHz (ajustar segn clock)

// --- ESTRUCTURAS ---
typedef struct {
    unsigned int sp;     // Guardaremos el Stack Pointer (W15) aqu
} PCB;

// --- VARIABLES GLOBALES DEL KERNEL ---
PCB tablaProcesos[3];
int procesoActual = 0;
int cuentaTicks = 0;

// Pilas independientes (Mucho ms rpido que copiar memoria)
unsigned int stackA[STACK_SIZE];
unsigned int stackB[STACK_SIZE];
unsigned int stackC[STACK_SIZE];

// --- PROCESOS (No se modifican) ---
void procesoA(void) {
    int x=2, y=4, z;
    while(1) { z = x + y; x += 2; y = z; }
}

void procesoB(void) {
    int a=1, b=3, c;
    while(1) { c = a * b; a += 2; }
}

void procesoC(void) {
    int r=1, s=1, t;
    while(1) { t = r + s; t >>= 1; r++; s += 4; }
}

// --- LOGICA DEL KERNEL ---

void inicializarProceso(int id, void* funcion, unsigned int* stackPtr) {
    /* 
     * Simulamos que el proceso fue interrumpido justo antes de empezar.
     * El hardware espera: [PC Low] [PC High + SR] en el stack al hacer RETFIE.
     */
    stackPtr[0] = (unsigned int)funcion; // PC Low
    stackPtr[1] = 0x0000;                // PC High y SR (Status Register)
    
    /* 
     * Resguardamos el contexto inicial (W0-W14). 
     * Son 15 registros que el planificador intentar sacar (POP) del stack.
     * Dejamos espacio para ellos (15 posiciones).
     */
    tablaProcesos[id].sp = (unsigned int)&stackPtr[17]; 
}

void boot(void) {
    // Proceso 0 (A) no necesita inicializar pila porque arranca en el main
    // Pero los procesos 1 (B) y 2 (C) s, para que el planificador pueda "saltar" a ellos.
    inicializarProceso(1, procesoB, stackB);
    inicializarProceso(2, procesoC, stackC);
    
    // Configurar Timer 1
    T1CON = 0;
    T1CONbits.TCKPS = 0; // 1:1
    PR1 = VALOR_PR1;
    IPC0bits.T1IP = 4;
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    T1CONbits.TON = 1;
}

// Macro para guardar y restaurar registros de trabajo (W0-W14)
#define GUARDAR_REGISTROS() asm volatile("push.d w0 \n push.d w2 \n push.d w4 \n push.d w6 \n push.d w8 \n push.d w10 \n push.d w12 \n push w14")
#define RESTAURAR_REGISTROS() asm volatile("pop w14 \n pop.d w12 \n pop.d w10 \n pop.d w8 \n pop.d w6 \n pop.d w4 \n pop.d w2 \n pop.d w0")

void __attribute__((interrupt, auto_psv)) _T1Interrupt(void) {
    IFS0bits.T1IF = 0;
    
    if (++cuentaTicks >= QUANTUM) {
        cuentaTicks = 0;
        
        // 1. Guardar contexto del proceso actual
        GUARDAR_REGISTROS();
        tablaProcesos[procesoActual].sp = WREG15; // Guardamos donde qued el stack pointer
        
        // 2. Planificador (Round Robin simple)
        procesoActual = (procesoActual + 1) % 3;
        
        // 3. Recuperar contexto del nuevo proceso
        WREG15 = tablaProcesos[procesoActual].sp; // Inyectamos el nuevo stack pointer
        RESTAURAR_REGISTROS();
        
        // Al salir de la ISR, el RETFIE buscar el PC en el NUEVO stack. Magia!
    }
}

int main(void) {
    boot();
    procesoA(); // Iniciamos con el proceso A
    return 0;
}
