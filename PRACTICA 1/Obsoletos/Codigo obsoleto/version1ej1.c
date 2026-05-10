/* TRABAJO PRÁCTICO Nº 1 
Temas: RISC Microchip. Manejo de instrucciones y memoria. Polling. 
Objetivos: 
● Programación en lenguaje C, y debugging en MPLAB.X 
● Técnica de programación por polling. Manejo de puertos de I/O. 
Material de soporte: 
● Para resolver el práctico se propone consultar el “Material para clases prácticas”, como así 
también la sección correspondiente a este práctico, disponible en el Aula Virtual. 
● Utilizar el proyecto base proyectobase1.X también disponible en el Aula Virtual. 
Ejercicio 1: Sistema de habilitación de máquina 
Se desea implementar el control básico de habilitación de una máquina. La máquina sólo puede 
ponerse en funcionamiento si: 
● Se acciona un pulsador de ENCENDIDO PS_ON (RD6). 
● Se mantiene activa una condición de SEGURIDAD PS_SEG (RD13). 
Además, existe un pulsador de APAGADO PS_OFF (RD7) que fuerza la detención inmediata del 
sistema. 
El sistema posee dos LEDs indicadores: 
● LED_VERDE (RA0) → Máquina en funcionamiento 
● LED_ROJO (RA1) → Máquina detenida 
La máquina deberá iniciar detenida, LED_ROJO encendido y. LED_VERDE apagado. 
NOTA:  
El programa deberá estar controlando el estado de las entradas continuamente (polling) y actuar 
dependiendo las condiciones presentadas. */


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

/* Este codigo tiene 2 problemas. Uno es que si el PS_SEG(RD13) esta en 0 , no apagamos el led verde ni encendemos el rojo
Segundo inconveniente seria mejor primero chequear si el pulsador PS_OFF(RD7) esta apagado, 
porque si estan todos los pulsadores encendidos el PS_ON el PS_OFF y el PS_SEG no deberia actualizar como encendido.
*/

// Configuracion PORTD
typedef union {
    struct{
        unsigned int :6;
        unsigned int PS_ON:1;
        unsigned int PS_OFF:1;
        unsigned int :5;
        unsigned int PS_SEG:1;
        unsigned int :2;   
    }bits;
    unsigned int completo;
} ENTRADAS_t;


// Configuracion PORTA
typedef union {
    struct{
        unsigned int LED_VERDE:1;
        unsigned int LED_ROJO:1;
        unsigned int :14;
    }bits;
    unsigned int valor;
}SALIDAS_t;


ENTRADAS_t sensores;
SALIDAS_t leds;




int main(void) {
    
    AD1PCFGH = 0xFFFF;
    AD1PCFGL = 0xFFFF;
    AD2PCFGL = 0xFFFF;
  //  TRISAbits
    
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
    
    leds.bits.LED_ROJO = 1;
    leds.bits.LED_VERDE = 0;

    while(1){
        // --- BLOQUE 1: LECTURA (Polling) ---
        // Sincronizamos el estado de los pines físicos a la memoria RAM
        sensores.completo = PORTD; 
        
        // --- BLOQUE 2: LÓGICA ---
        // Se evalúan las condiciones usando solo las variables de memoria
        
        // Condición de encendido: Presionar PS_ON Y que PS_SEG esté activo
        if(leds.bits.LED_VERDE == 0 && leds.bits.LED_ROJO == 1)
            if (sensores.bits.PS_ON == 1 && sensores.bits.PS_SEG == 1) {
                leds.bits.LED_VERDE = 1;
                leds.bits.LED_ROJO = 0;
            }
            
           /* else{
                salidas.bits.LED_VERDE = 0;
                salidas.bits.LED_ROJO = 1;
            }
           */
        // Condición de apagado: Presionar PS_OFF O que PS_SEG se desactive 
        
        if (leds.bits.LED_VERDE == 1 && leds.bits.LED_ROJO == 0){
            if (sensores.bits.PS_OFF == 1) {
                leds.bits.LED_VERDE = 0;
                leds.bits.LED_ROJO = 1;
            }
        }
        // --- BLOQUE 3: SALIDA ---
        // Vuelca el resultado de la lógica al registro de salida físico
        PORTA = leds.valor; 
    }
    
}

