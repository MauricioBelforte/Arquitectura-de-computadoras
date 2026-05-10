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

#define TMPMINIMA (44*65535)/100    // 28835 = 0x70A3

/* El sufijo UL evita el overflow en el calculo de 16 bits */
/* #define TMPMINIMA (44UL * 65535UL) / 100UL  */
#define CONDICIONES_ENCENDIDO temperatura && puertas && presion && energia // Acorta
#define APAGADO !prendido           // Solo para facilitar lectura

/* Comprobar si es mala practica el uso de var. globales */
// NOTA (Amir): Lo hice exclusivamente para tener codigo cercano a funcional para hoy
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
{
    // Configura todos los pines como digitales
    AD1PCFGH = 0xFFFF;
    AD1PCFGL = 0xFFFF;
    AD2PCFGL = 0xFFFF;
    
    TRISA=0xFFFF; // Puerto entradas temperatura 
    TRISB=0x0000; // Puerto salidas
    TRISD=0X00FF; // Puerto entradas sensores
    
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


