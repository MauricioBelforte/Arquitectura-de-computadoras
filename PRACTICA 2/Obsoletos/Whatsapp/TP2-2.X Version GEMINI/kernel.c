#include <p33FJ256GP710.h>
#include "kernel.h"

// =========================================================================
// ESTRUCTURAS DE DATOS DEL KERNEL
// =========================================================================

/* 
 * 1. Process Control Block (PCB): 
 * El enunciado nos pide una estructura de datos para guardar el "estado".
 * Lo más crítico para resguardar es el Stack Pointer (El puntero de pila, W15).
 * ¿Por qué? Porque en la pila de cada proceso están guardados todos sus 
 * registros (W0-W14) y la línea de código exacta (Program Counter) en la que 
 * fue interrumpido.
 */
typedef struct {
    unsigned int sp; // Puntero de Pila (Stack Pointer)
} PCB;

PCB procesos[3];         // Arreglo para nuestros 3 procesos (A, B y C)
int procesoActual = 0;   // Índice del proceso que está usando la CPU (0=A, 1=B, 2=C)
int quantum = 2;         // El enunciado pide que el quantum sea de 2 interrupciones de reloj

/* 
 * 2. Pilas Propias (Stacks)
 * En Multitasking, cada proceso necesita su propia porción de memoria. Si todos 
 * usaran la misma pila general, al saltar de uno a otro se pisarían las variables 
 * locales (las variables x, y, z de A chocarían con las a, b, c de B).
 */
unsigned int stackA[128];
unsigned int stackB[128];
unsigned int stackC[128];

// Le avisamos al compilador que estas funciones existen en otro archivo (main.c)
extern void procesoA(void);
extern void procesoB(void);
extern void procesoC(void);


// =========================================================================
// MACROS PARA CAMBIO DE CONTEXTO (Resguardo de Registros)
// =========================================================================
// El enunciado dice: "resguardar los valores de los registros del proceso actual".
// El hardware del dsPIC guarda automáticamente el PC y el SR cuando entra a una
// interrupción. A nosotros nos toca guardar a mano los 15 registros de trabajo (W0-W14).
#define GUARDAR_CONTEXTO() \
    asm volatile("push.d w0 \n push.d w2 \n push.d w4 \n push.d w6 \n push.d w8 \n push.d w10 \n push.d w12 \n push w14")

// Cuando queremos despertar al proceso, sacamos (pop) los registros de su pila en orden inverso.
#define RESTAURAR_CONTEXTO() \
    asm volatile("pop w14 \n pop.d w12 \n pop.d w10 \n pop.d w8 \n pop.d w6 \n pop.d w4 \n pop.d w2 \n pop.d w0")


// =========================================================================
// FUNCIONES DEL KERNEL
// =========================================================================

void init(void)
{
    /* 
     * INICIALIZACIÓN FANTASMA DE LAS PILAS
     * El Proceso A arranca naturalmente desde el main(), así que su pila se inicializa sola.
     * Pero los procesos B y C nunca fueron llamados... ¡Tenemos que falsificar sus pilas
     * para que el planificador crea que fueron interrumpidos antes y pueda "reanudarlos"!
     */
    
    // Inicialización del Proceso B
    // Acá aplicamos la "Nota" del enunciado: asignamos la dirección de la rutina.
    // Una interrupción en dsPIC deja en el fondo de la pila: PC (2 palabras) y SR (1 palabra).
    stackB[0] = (unsigned int)procesoB; // Metemos la dirección de la función en la pila (Para que salte ahí)
    stackB[1] = 0x0000;                 // Falsificamos un SR (Status Register) en cero
    
    // Luego simulamos que empujamos W0-W14 (son 15 registros = 15 lugares ocupados artificialmente en la pila)
    // Entonces, el puntero de pila (SP) quedaría apuntando 17 posiciones más arriba.
    procesos[1].sp = (unsigned int)&stackB[17]; 

    // Inicialización del Proceso C (Exactamente la misma lógica)
    stackC[0] = (unsigned int)procesoC;
    stackC[1] = 0x0000;
    procesos[2].sp = (unsigned int)&stackC[17];
}

void confReloj(void)
{
    // Configuramos el Timer1 como el "motor" inquebrantable de nuestro Sistema Operativo
    T1CONbits.TON = 0;      // Apagamos para configurar
    T1CONbits.TCS = 0;      // Reloj interno
    T1CONbits.TCKPS = 1;    // Prescaler 1:8
    TMR1 = 0;
    PR1 = 5000;             // Valor límite para interrumpir a intervalos regulares
    
    IPC0bits.T1IP = 1;      // Prioridad baja
    IFS0bits.T1IF = 0;      // Bajamos bandera por seguridad
    IEC0bits.T1IE = 1;      // Habilitamos interrupción
    
    T1CONbits.TON = 1;      // ¡Arranca el Reloj del SO!
}

void boot(void)
{
    // La fase de booteo configura los stacks falsos y prende el reloj del Kernel
    init();
    confReloj();
    return;
}

void planificador(void)
{
    // El planificador simplemente decide quién es el siguiente en usar la CPU.
    // Usamos el clásico algoritmo "Round-Robin" (Ronda circular): A -> B -> C -> A -> B...
    
    procesoActual++;
    if (procesoActual > 2) {
        procesoActual = 0; // Si llegamos al final, volvemos a empezar por el A
    }
    
    // El enunciado exige explícitamente: "restablecer el quantum"
    quantum = 2;
}

/*
 * =========================================================================
 * EL CORAZÓN DEL SISTEMA OPERATIVO (INTERRUPCIÓN DEL TIMER)
 * =========================================================================
 */
void __attribute__((interrupt, auto_psv)) _T1Interrupt( void )
{
    IFS0bits.T1IF = 0; // OBLIGATORIO: Bajar bandera de hardware
    
    quantum--; // Descontamos 1 de su "crédito" de tiempo (quantum)
    
    if (quantum == 0) {
        // ¡Se le acabó el tiempo al proceso actual! 
        // Empezamos la magia del CAMBIO DE CONTEXTO.
        
        // 1. RESGUARDAR LOS REGISTROS (Estado del proceso actual)
        // Guardamos los W0-W14 empujándolos a la pila del proceso que venía corriendo.
        GUARDAR_CONTEXTO();
        
        // 2. RESGUARDAR EL PUNTERO DE PILA (SP)
        // El registro de hardware WREG15 contiene el Stack Pointer actual. 
        // Lo guardamos en el PCB del proceso para saber dónde se quedó.
        procesos[procesoActual].sp = WREG15;
        
        // 3. INVOCAR AL PLANIFICADOR
        // Elegimos el próximo proceso y reseteamos el quantum a 2.
        planificador();
        
        // 4. RECUPERAR EL ESTADO DEL SIGUIENTE PROCESO
        // Le inyectamos bruscamente a la CPU el Stack Pointer del nuevo proceso.
        WREG15 = procesos[procesoActual].sp;
        
        // 5. RESTAURAR LOS REGISTROS
        // Al hacer pop, la CPU saca los registros viejos de la pila del nuevo proceso.
        RESTAURAR_CONTEXTO();
        
        // Al terminar esta función C, el compilador ejecuta la instrucción RETFIE.
        // Como le cambiamos la pila por debajo, el RETFIE va a leer el PC del NUEVO proceso
        // y saltará a ejecutarlo como si nada hubiera pasado. ¡Ilusión lograda!
    }
}
