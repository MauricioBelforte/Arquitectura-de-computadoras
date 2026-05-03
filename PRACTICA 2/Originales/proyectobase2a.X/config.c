/**********************************************************************
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author            Date      Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Sebastián Wahler  23/03/2016  Primer release - Interrupciones
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ¿QUÉ ES UN ARCHIVO .C (Código Fuente) Y EN QUÉ SE DIFERENCIA DEL .H?
* ---------------------------------------------------------------------
* El archivo .c contiene el DESARROLLO REAL o el "músculo" del programa.
* A diferencia del .h (que solo actúa como un índice para decir qué cosas
* existen), en el archivo .c es donde escribimos matemáticamente las 
* instrucciones paso a paso de cada función. 
* El microcontrolador lee y ejecuta lo que está desarrollado aquí.
*
**********************************************************************/
#include "p33FJ256GP710.h"
#include "config.h"

// Valor para el registro PR1 (Period Register) del Timer1
// PR1 = 62500 (0xF424). Junto con el prescaler, esto define cuánto tarda el timer en desbordarse y generar interrupción.
#define ValPR1 62500 

// Variables globales externas definidas en main.c
extern int counterINT0;
extern int counterTimer;

/*
 * Rutina de Atención de la interrupción externa INT0
 * Función: Se ejecuta automáticamente cada vez que hay un evento físico en el pin INT0 (por ej. pulsar un botón).
 */
void __attribute__((interrupt, auto_psv)) _INT0Interrupt( void )
{
	/* Restablecer bandera de interrupción (reset INT0 interrupt flag) */
	/* Es obligatorio limpiar la bandera en software para que la interrupción no se dispare de nuevo infinitamente sola. */
 	IFS0bits.INT0IF = 0;
    
    // Incrementamos el contador de pulsos externos
    counterINT0++;
}

/*
 * Rutina de Atención de la interrupción del Timer1
 * Función: Se ejecuta automáticamente cuando el contador del Timer1 alcanza el valor establecido en PR1.
 */
void __attribute__((interrupt, auto_psv)) _T1Interrupt( void )
{
	/* Restablecer bandera de interrupción del Timer 1 (reset Timer 1 interrupt flag) */
 	IFS0bits.T1IF = 0;

	// Si se deseara que el timer se apague tras la primera vez, se usaría:
	// T1CONbits.TON = 0; 	
    
    // Incrementamos el contador de desbordamientos del Timer1
	counterTimer++;
}

/*---------------------------------------------------------------------
  Function Name: Init_Timer1
  Description:   Inicialización de Timer1
-----------------------------------------------------------------------*/
void Init_Timer1( void )
{
	/* Asegurarse de que el Timer 1 esté apagado y en estado de reset */
	T1CON = 0;
    
    /* Configurar Prescaler: TCKPS = 2 significa un divisor de reloj de 1:256 */
	T1CONbits.TCKPS = 2; 

	/* Limpiar la bandera de interrupción del Timer 1 por precaución antes de arrancar */
 	IFS0bits.T1IF = 0;

 	/* Configurar la prioridad de la interrupción del Timer (nivel 1 al 7) */
	IPC0bits.T1IP = 5;

	/* Habilitar la interrupción del Timer 1 */
 	IEC0bits.T1IE = 1;

	/* Configurar el registro de período del Timer (hasta qué valor cuenta el timer antes de interrumpir) */
	PR1 = ValPR1;
    
    /* Encender / Habilitar el Timer 1 */
	T1CONbits.TON = 1; 	

}

/*---------------------------------------------------------------------
  Function Name: Init_INT0
  Description:   Inicialización de Interrupción Externa 0 (INT0)
-----------------------------------------------------------------------*/
void Init_INT0( void )
{
    /* Limpiar la bandera de interrupción INT0 por precaución */
    IFS0bits.INT0IF = 0;

    /* Configurar la prioridad de la interrupción INT0 (nivel 1 al 7) */
    IPC0bits.INT0IP = 5;

    /* Habilitar la interrupción externa INT0 */
    IEC0bits.INT0IE = 1;
}

/*---------------------------------------------------------------------
  Function Name: config
  Description:   Función general para configurar todo el microcontrolador
-----------------------------------------------------------------------*/
void config( void )
{
	// Inicialización de Puertos de Entrada/Salida (I/O)
	/* Configurar los pines correspondientes a los LEDs (RA0-RA7) como salidas.
       Los bits en 0 en el registro TRIS significan "Salida" (Output).
       En este caso, 0xFF00 (1111 1111 0000 0000 en binario) deja RA8 a RA15 como entradas y RA0 a RA7 como salidas. */
	TRISA = 0xFF00;
    
    /* Apagar todos los LEDs escribiendo un 0 en el registro LATCH de salida */
	LATA  = 0xFF00;  

    /* Inicializar Interrupción Externa INT0 */
    Init_INT0();

	/* Inicializar Timer1 */
	Init_Timer1();

}
