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

#define TMPMINIMA (24*65535)/100    //15428= 0x3D70


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
    TRISA=0xFFFF;
    TRISD=0X00FF;
    
    var.bits.BMOTOR = 0;            //apagado
    var.bits.BPUERTAS = 0;          //apagado
    var.bits.APAGAR = 0;            
    var.bits.PRENDER = 0;
    
    TEMP = 0x0000;              //temperatura en cero    
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


