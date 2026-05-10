/* Ejercicio 2: Automatismo 
Un sistema de calefacción de una fábrica posee un termostato variable y cinco sensores de 
detección de apertura de accesos (portones y puertas al exterior de la fábrica). El sistema de control 
debe encender un motor que impulsa aire caliente y abrir la válvula de salida de gas, si se cumplen a 
la vez las siguientes condiciones: 
● El termostato variable desciende por debajo de 24°C, detectable por un sensor que entrega 
valores en 16 bits por un puerto. El sensor trabaja en un rango de -20°C a 80°C.  
● Por lo menos 3 de los accesos se encuentran cerrados, detectable cada acceso por un 
sensor del tipo ON/OFF, habiendo un bit por cada acceso (cuando el sensor detecta que la 
puerta/portón está cerrado, estará en ON). 
● Hay presión de gas suficiente por encima del umbral mínimo, detectable por un sensor de 
nivel del tipo ON/OFF.  
● Hay energía eléctrica, detectable por un sensor de presencia de tensión del tipo ON/OFF. 
NOTA:  
La lectura de entradas debe hacerse por polling. Otorgar en lo posible al programa una estructura en 
bloques tal que: 
1. En el primer bloque se tomen las variables de entrada y se las deposite en memoria. 
2. En el segundo bloque se instrumente la lógica consignada, utilizando las variables de 
memoria. 
3. En el tercer bloque se actualicen las salidas y sólo se escriba una salida cuando exista un 
cambio respecto a su estado inmediato anterior (no escribir permanentemente). */


/**********************************************************************
 FileName:        main.c
 Dependencies:    p33FJ256GP710.h
 Processor:       dsPIC33F
 Compiler:        MPLAB® C30 v2.01 or higher

 Proyecto en Lenguaje C.

 REVISION HISTORY:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Author            Date         Comments on this revision
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Ortega jorge   xx-04-2026      Polling 1.0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**********************************************************************/

#include <p33FJ256GP710.h>

/* Rango -20 a 80 = 100 grados de span. 24 grados es el 44% del rango (24 - (-20) = 44).
   Calculo: (44 * 65535) / 100 = 28835. 
   Usamos el valor directo para evitar desbordamientos en tiempo de compilacion. */
#define TMPMINIMA 28835


typedef union {
    struct {
        unsigned int SA1:1;
        unsigned int SA2:1;
        unsigned int SA3:1;
        unsigned int SA4:1;
        unsigned int SA5:1;
        unsigned int SGAS:1;
        unsigned int SENE:1;
        unsigned int BMOTOR:1;
        unsigned int BPUERTAS:1;
        unsigned int PRENDER:1;
        unsigned int APAGAR:1;               
    } bits;
    unsigned int completo;
} t_var;

unsigned int TEMP;              //variable para temperatura

t_var var;                      //variable estructura para sensores


void configurar()
{
    // Configura todos los pines como digitales
    AD1PCFGH = 0xFFFF;
    AD1PCFGL = 0xFFFF;
    AD2PCFGL = 0xFFFF;

    TRISA=0xFFFF;
    TRISD=0X00FF;
    
    var.completo = 0;               // Inicializa todos los campos de bits a cero en un solo paso
    TEMP = 0;                       // Temperatura inicializada
}

void leer_entradas()
{
    var.bits.SA1 = PORTDbits.RD0;           //leo sensores
    var.bits.SA2 = PORTDbits.RD1;
    var.bits.SA3 = PORTDbits.RD2;
    var.bits.SA4 = PORTDbits.RD3;
    var.bits.SA5 = PORTDbits.RD4;
    
    var.bits.SGAS = PORTDbits.RD5;          //leo gas y energia electrica
    var.bits.SENE = PORTDbits.RD6;
    
    TEMP = PORTA;                       //leo temperatura
}


void analizar_entradas()
{
    int contador=0;
    
    if (TEMP< TMPMINIMA)       //temperatura x debajo del minimo
        var.bits.BMOTOR = 1;
    else
        var.bits.BMOTOR = 0;
    
    
    contador+= var.bits.SA1;        //cuento las puertas cerradas
    contador+= var.bits.SA2;
    contador+= var.bits.SA3;
    contador+= var.bits.SA4;
    contador+= var.bits.SA5;
            
    if (contador>=3)
        var.bits.BPUERTAS = 1;
    else
        var.bits.BPUERTAS = 0;
}

void escribir_salida()
{
    if(var.bits.BMOTOR==1 && var.bits.BPUERTAS==1 && var.bits.SGAS==1 && var.bits.SENE==1){
        if(var.bits.PRENDER==0){        //si no estaba prendido
            PORTDbits.RD12 = 1;
            PORTDbits.RD13 = 1;         //prendo motor y valvula
            var.bits.PRENDER = 1;   
        } else
            var.bits.APAGAR = 0;
    } else {
        if(var.bits.APAGAR==0){         //si no estaba apagado
            PORTDbits.RD12 = 0;
            PORTDbits.RD13 = 0;         //apago motor y valvula
            var.bits.APAGAR = 1;   
        } else
            var.bits.PRENDER = 0;
    }
}


int main(void) {

    configurar();
    
    while(1)
    {
        leer_entradas();
        analizar_entradas();
        escribir_salida();
    }
}
