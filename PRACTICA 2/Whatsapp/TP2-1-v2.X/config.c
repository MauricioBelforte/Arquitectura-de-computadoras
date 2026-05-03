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

#define ValPR1  6000 // 150us con prescaler 1 y Fosc 40MHz
#define ES_CARACTER_VALIDO(c) ( (c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' )

extern int caracteresPendientes;
extern int counterTimer;

char buffer[TAM_BUFFER];    // Buffer circular para almacenar los caracteres recibidos
int indBuffer = 0;          // Indice para recorrer buffer ("Pensar como aguja de ESCRITURA")

/*
 * Rutina de atencion de la interrupcin externa INT1
 */
void __attribute__((interrupt, auto_psv)) _INT1Interrupt( void ){
    IFS1bits.INT1IF = 0;	// Reinicio bandera de INT1
    char c = PORTB;			// Leo el caracter recibido por el Puerto B
    if (ES_CARACTER_VALIDO(c)){	// Si es digito o simbolo de operacion...
        caracteresPendientes++;              // Cuenta cantidad de caracteres validos recibidos
        CAR_GUARDADO = c;           // Guardo el caracter recibido en el buffer
        if (FIN_DE_BUFFER(indBuffer))
            indBuffer = 0;      // Funcionamiento circular del buffer
    }
}

/*
 * Rutina de Atencion de la interrupcion del Timer1
 */
void __attribute__((interrupt, auto_psv)) _T1Interrupt( void ){
    IFS0bits.T1IF = 0; 	// Reinicio bandera de T1
    counterTimer ++;
}

void Init_Timer1( void ){
    T1CON = 0;				// Asegurar que Timer1 se encuentre en estado por defecto
    T1CONbits.TCS = 0; 		// Uso reloj interno
    T1CONbits.TCKPS = 0; 	// Prescaler 1:1

    IFS0bits.T1IF = 0;		// Reinicio bandera de Timer1
    IPC0bits.T1IP = 5;		// Prioridad 5
    IEC0bits.T1IE = 1;		// Habilito interrupcion de Timer1

    PR1 = ValPR1;			// Asigno valor de PR1 para medir 150ms
    T1CONbits.TON = 1; 		// Habilito Timer
}

void Init_INT1( void ){
    IFS1bits.INT1IF = 0;	// Reinicio bandera de INT1
    IPC5bits.INT1IP = 5; 	// Prioridad 5
    INTCON2bits.INT1EP = 0; // Setteo flanco ascendente / positivo como fuente de interrupcion
    IEC1bits.INT1IE = 1; 	// Habilito interrupcion de INT1
}

/* Inicializacion de Puertos E/S, INT1 y Timer1 */
void config( void ){	
    TRISA = 0xFF00;		// Settear pines RA0-RA7 como salida
    LATA  = 0xFF00;  	// Apago todos los LEDs
    TRISB = 0xFFFF; 	// Puerto B como entrada
    //Configura todos los pines como digitales
    AD1PCFGH = 0xFFFF;
    AD1PCFGL = 0xFFFF;
    AD2PCFGL = 0xFFFF;
    
    Init_INT1();		// Inicializo INT1
    Init_Timer1();		// Inicializo Timer1
}

