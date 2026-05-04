/**********************************************************************
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author            Date      Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Sebasti�n Wahler  23/03/2016  Primer release - Interrupciones
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES: 
*
**********************************************************************/
#include "p33FJ256GP710.h"
#include "config.h"

// VALOR DEL PERIODO (PR1):
// Calculado para 150 microsegundos con Fosc = 40MHz (Fcy = 20MHz).
// Tcy = 0.05us. Si Prescaler = 1:1, entonces 150us / 0.025us = 6000 pulsos.
// Nota: A 40MHz reales (Fcy = 20MHz), el ciclo de instrucción es 50ns (0.05us).
// Si el Timer suma cada 1:1 Tcy, entonces 150 / 0.05 = 3000.
// Si tu chip corre a 80MHz (Fcy=40MHz), entonces Tcy=0.025us y el valor es 6000.
#define ValPR1  6000 

// FILTRO INTELIGENTE: Solo acepta números (ASCII 48-57) y los 4 signos aritméticos.
#define ES_CARACTER_VALIDO(c) ( (c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' )

// Declaramos que estas variables existen en otro archivo (probablemente main.c)
extern int caracteresPendientes;
extern int counterTimer;

// EL MOSTRADOR (Buffer Circular): Aquí es donde el cocinero (ISR) deja los datos.
char buffer[TAM_BUFFER];    
int indBuffer = 0;          // Índice de escritura (¿Dónde dejo la próxima pizza?)

/*
 * =========================================================================
 * RUTINA DE ATENCIÓN DE INTERRUPCIÓN: INT1 (El Productor)
 * Se activa cada vez que detecta un flanco ascendente en el pin físico.
 * =========================================================================
 */
void __attribute__((interrupt, auto_psv)) _INT1Interrupt( void ){
    IFS1bits.INT1IF = 0;	// 1. LIMPIAR BANDERA: Si no la bajamos, la ISR se repite infinitamente.
    
    char c = PORTB;			// 2. CAPTURA FÍSICA: Leemos el estado de los pines del Puerto B.
    
    if (ES_CARACTER_VALIDO(c)){	// 3. FILTRADO: ¿Es algo que nos sirve?
        caracteresPendientes++;  // Avisamos al sistema que hay un dato nuevo sin leer.
        
        // 4. GUARDADO CIRCULAR:
        // Usamos la macro que guarda el dato e incrementa el índice en un solo paso.
        CAR_GUARDADO = c;           
        
        // 5. EFECTO CIRCULAR: Si el índice llegó al final, lo mandamos de vuelta al inicio (0).
        // Así nunca nos salimos de la memoria del arreglo.
        if (FIN_DE_BUFFER(indBuffer))
            indBuffer = 0;      
    }
}

/*
 * =========================================================================
 * RUTINA DE ATENCIÓN DE INTERRUPCIÓN: TIMER 1 (El Reloj)
 * Se activa exactamente cada 150 microsegundos.
 * =========================================================================
 */
void __attribute__((interrupt, auto_psv)) _T1Interrupt( void ){
    IFS0bits.T1IF = 0; 	// Bajamos la bandera del Timer para permitir futuras interrupciones.
    counterTimer ++;    // Sumamos un "tic" al contador global de tiempo.
}

/*
 * =========================================================================
 * INICIALIZACIÓN DEL TIMER 1
 * =========================================================================
 */
void Init_Timer1( void ){
    T1CON = 0;				// Limpiamos configuración previa.
    T1CONbits.TCS = 0; 		// Seleccionamos reloj interno (Fcy).
    T1CONbits.TCKPS = 0; 	// Prescaler 1:1 (Máxima velocidad, el timer suma en cada ciclo).

    IFS0bits.T1IF = 0;		// Nos aseguramos que la bandera arranque en cero.
    IPC0bits.T1IP = 5;		// Prioridad 5 (Nivel medio-alto).
    IEC0bits.T1IE = 1;		// Habilitamos la interrupción (damos permiso de interrumpir al main).

    PR1 = ValPR1;			// Cargamos el "límite" del contador (6000).
    T1CONbits.TON = 1; 		// ¡ENCENDEMOS EL RELOJ!
}

/*
 * =========================================================================
 * INICIALIZACIÓN DE LA INTERRUPCIÓN EXTERNA 1 (INT1)
 * =========================================================================
 */
void Init_INT1( void ){
    IFS1bits.INT1IF = 0;	// Limpiamos bandera inicial.
    IPC5bits.INT1IP = 5; 	// Seteamos prioridad 5.
    INTCON2bits.INT1EP = 0; // 0 = Flanco Ascendente (Positivo). 1 = Flanco Descendente.
    IEC1bits.INT1IE = 1; 	// Habilitamos la interrupción externa.
}

/*
 * =========================================================================
 * CONFIGURACIÓN GLOBAL DE PUERTOS Y PERIFÉRICOS
 * =========================================================================
 */
void config( void ){	
    // TRIS: 0 = Output (Salida), 1 = Input (Entrada).
    TRISA = 0xFF00;		// RA0 a RA7 como salidas (para los LEDs).
    LATA  = 0xFF00;  	// Inicialmente todos los LEDs apagados.
    TRISB = 0xFFFF; 	// Todo el Puerto B como entrada (para recibir caracteres).
    
    // IMPORTANTE: Los pines suelen arrancar como ANALÓGICOS.
    // Debemos pasarlos a DIGITALES para que funcionen como entradas simples.
    AD1PCFGH = 0xFFFF;
    AD1PCFGL = 0xFFFF;
    AD2PCFGL = 0xFFFF;
    
    Init_INT1();		// Configuramos el botón/pulso externo.
    Init_Timer1();		// Configuramos el reloj de 150us.
}

