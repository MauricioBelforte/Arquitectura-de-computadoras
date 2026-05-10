/**********************************************************************
 FileName:        main.c
 Dependencies:    p33FJ256GP710.h
 Processor:       dsPIC33F
 Compiler:        MPLAB® C30 v2.01 or higher

 Proyecto base en Lenguaje C.

 REVISION HISTORY:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Author            Date      Comments on this revision
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Sebastián Wahler  09/03/16  Initial Release
 Marcelo Gómez     10/03/19  Actualización (Se incorporó campo de bits)
 Sebastián Wahler  22/03/22  Entradas/Salidas Digitales
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**********************************************************************/

#include <p33FJ256GP710.h>

// Configuracion PORTD
typedef union {
    struct{
        unsigned :6;
        unsigned PS_ON:1;
        unsigned PS_OFF:1;
        unsigned :5;
        unsigned PS_SEG:1;
        unsigned :2;   
    }bits;
    unsigned valor;
} ENTRADAS_t;


// Configuracion PORTA
typedef union {
    struct{
        unsigned LED_VERDE:1;
        unsigned LED_ROJO:1;
        unsigned :14;
    }bits;
    unsigned valor;
}SALIDAS_t;


ENTRADAS_t entradas;
SALIDAS_t salidas;




int main(void) {
    // Configuramos todoe el resto en 1 como entrada (TRISA = 0XFFFC), porque el fabricante lo recomienda
    // para evitar cortocircuitos y no dañar a otros si hay algo conectado.
    TRISA = 0XFFFC;//  (Esto pone en '0' los bits 0 y 1 del Puerto A para que sean salidas).
    // F = 1111
    // F = 1111
    // F = 1111
    // C = 1100
    
    
    // Basándonos en la recomendación de seguridad del fabricante, sería mejor usar un valor que mantenga el resto en 1.
    // Si queremos que RD6, RD7 y RD13 sean entradas (1) y el resto también sean entradas (1), el valor sería 0xFFFF.
    TRISD = 0XFFFF;
    
    

    while(1) {
        // --- BLOQUE 1: LECTURA (Polling) ---
        // Sincronizamos el estado de los pines físicos a la memoria RAM [1]
        entradas.valor = PORTD; 

        // --- BLOQUE 2: LÓGICA ---
        // Se evalúan las condiciones usando solo las variables de memoria [1]
        
        // Condición de encendido: Presionar PS_ON Y que PS_SEG esté activo [5]
        if (entradas.bits.PS_ON == 1 && entradas.bits.PS_SEG == 1) {
            salidas.bits.LED_VERDE = 1;
            salidas.bits.LED_ROJO = 0;
        }

        // Condición de apagado: Presionar PS_OFF O que PS_SEG se desactive [5]
        if (entradas.bits.PS_OFF == 1 || entradas.bits.PS_SEG == 0) {
            salidas.bits.LED_VERDE = 0;
            salidas.bits.LED_ROJO = 1;
        }

        // --- BLOQUE 3: SALIDA ---
        // Vuelca el resultado de la lógica al registro de salida físico [1, 4]
        LATA = salidas.valor; 
    }
    return 0;
}

