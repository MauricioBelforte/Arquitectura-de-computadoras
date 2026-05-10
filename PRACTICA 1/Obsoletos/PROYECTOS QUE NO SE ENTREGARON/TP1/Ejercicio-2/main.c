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

#define TMPMINIMA (44*65535)/100    // 28835 = 0x70A3
#define CONDICIONES_ENCENDIDO temperatura && puertas && presion && energia // Acorta
#define APAGADO !prendido           // Solo para facilitar lectura

/* Comprobar si es mala practica el uso de var. globales */

// Variables de tipo flag/booleano, para condiciones de encendido
static int puertas=0;
static int temperatura=0;
static int presion=0;
static int energia=0;
// Usado para evitar pisar la salida constantemente
static int prendido=0;

typedef union {
    struct{
        unsigned int SA1:1;
        unsigned int SA2:1;
        unsigned int SA3:1;
        unsigned int SA4:1;
        unsigned int SA5:1;     // 5 bits que corresponden a puertas
        unsigned int SGAS:1;    // Sensor de presion de gas
        unsigned int SENE:1;    // Sensor de energia electrica
    }sensores;
    unsigned int completo;
} t_entrada;

typedef union{
    struct{
        unsigned int MOTOR:1;
        unsigned int VALVULA:1;
    };
    unsigned int completo;
} t_salida;

t_entrada entrada;  // Variable estructura para sensores
t_salida salida;    // Variable estructura para salida
unsigned int TEMP;  // Variable para temperatura

void configurar()
{   // Configura todos los pines como digitales
    AD1PCFGH = 0xFFFF;
    AD1PCFGL = 0xFFFF;
    AD2PCFGL = 0xFFFF;
    
    TRISA=0xFFFF;
    TRISB=0x0000;
    TRISD=0X00FF;
    
    TEMP = 0x0000;  // Inicializar temperatura en cero / Eliminar dato basura
}

void leer_entradas()
{
    entrada.completo=PORTD; // Leo estado de sensores del puerto
    TEMP = PORTA;           // Leo temperatura tomando el valor completo del puerto
}


void analizar_entradas(){
    int contador=0;
    contador+= entrada.sensores.SA1;    // Cuento las puertas cerradas
    contador+= entrada.sensores.SA2;
    contador+= entrada.sensores.SA3;
    contador+= entrada.sensores.SA4;
    contador+= entrada.sensores.SA5;
    // SIN TESTEAR Reemplazo los ifs por una asignacion simple en ambos
    puertas = (contador >= 3);          // Si hay AL MENOS 3 puertas cerradas -> 1
    temperatura = (TEMP < TMPMINIMA);   // Temp DEBAJO de valor min -> 1

    presion = entrada.sensores.SGAS;
    energia = entrada.sensores.SENE;
}


void escribir_salida(){
    if(CONDICIONES_ENCENDIDO){  // Si se cumplen las 4 (Presion, temp, puertas, energia)
        if(APAGADO){    // ...y no estaba prendido
            prendido=1; // No se pise salida de nuevo a menos que haya cambio
            salida.MOTOR=1;     // Escribo en variable de salida:
            salida.VALVULA=1;   // Prendiendo motor y valvula
            PORTB=salida.completo;  // Escribe valores de salida (Puerto) con variable
        }
    } else {            // Si alguna no se cumple
        if(prendido){   // ...y no estaba apagado
            prendido = 0; // Aseguro que no se reescriba la salida prox iter
            salida.MOTOR=0;     // Escribo en variable de salida:
            salida.VALVULA=0;   // Apagando motor y valvula
            PORTB=salida.completo; // Escribo valores de variable en el puerto
        }
    }
}

int main(void) {
    configurar();
    while(1){
        leer_entradas();
        analizar_entradas();
        escribir_salida();
    }
}


