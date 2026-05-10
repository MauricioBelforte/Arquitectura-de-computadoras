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

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**********************************************************************/

#include <p33FJ256GP710.h>

#define TMPMINIMA 28835             //  (44*65535)/100 = 0x70A3 (24°C)
#define CONDICIONES_ENCENDIDO banderas.bits.temperatura && banderas.bits.puertas && banderas.bits.presion && banderas.bits.energia // Acorta
#define PRENDIDO banderas.bits.prendido
#define APAGADO !(banderas.bits.prendido)          // Solo para facilitar lectura
#define PUERTAS_CERRADAS (entrada.sensores.SA1 + entrada.sensores.SA2 + entrada.sensores.SA3 + entrada.sensores.SA4 + entrada.sensores.SA5)

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
        unsigned int puertas:1;
        unsigned int temperatura:1;
        unsigned int presion:1;
        unsigned int energia:1;
        unsigned int prendido:1;
    }bits;
    unsigned int completo;
}t_banderas;

typedef union{
    struct{
        unsigned int MOTOR:1;
        unsigned int VALVULA:1;
    }bits;
    unsigned int completo;
} t_salida;

t_entrada entrada;  // Variable estructura para sensores
t_salida salida;    // Variable estructura para salida
t_banderas banderas;// Variable estructura para banderas/condiciones

unsigned int TEMP;  // Variable para temperatura (-20°C a 80°C)

void configurar(){
    //Configura todos los pines como digitales
    AD1PCFGH = 0xFFFF;
    AD1PCFGL = 0xFFFF;
    AD2PCFGL = 0xFFFF;
    //Configuramos pines para entrada y salida (No usados en 1, mas seguro electronicamente)
    TRISA=0xFFFC; // 2 pines de salida (MOTOR y GAS)
    TRISB=0xFFFF; // Todos pines de entrada (Temperatura)
    TRISD=0XFFFF; // 7 pines de entrada (Sensores de puertas, energia y gas)
    
    TEMP = 0x0000;  // Inicializar temperatura en cero / Eliminar dato basura
}

void leer_entradas()
{
    entrada.completo=PORTD; // Leo estado de sensores del puerto
    TEMP = PORTB;           // Leo temperatura tomando el valor completo del puerto
}


void analizar_entradas(){
    banderas.bits.puertas = (PUERTAS_CERRADAS >= 3);    // Si hay AL MENOS 3 puertas cerradas -> 1
    banderas.bits.temperatura = (TEMP < TMPMINIMA);   // Temp DEBAJO de valor min -> 1
    banderas.bits.presion = entrada.sensores.SGAS;
    banderas.bits.energia = entrada.sensores.SENE;
}


void escribir_salida(){
    if(CONDICIONES_ENCENDIDO){  // Si se cumplen las 4 (Presion, temp, puertas, energia)
        if(APAGADO){    // ...y no estaba prendido
            PRENDIDO=1; // No se pise salida de nuevo a menos que haya cambio
            salida.bits.MOTOR=1;     // Escribo en variable de salida:
            salida.bits.VALVULA=1;   // Prendiendo motor y valvula
            PORTA=salida.completo;  // Escribe valores de salida (Puerto) con variable
        }
    } else {            // Si alguna no se cumple
        if(PRENDIDO){   // ...y no estaba apagado
            PRENDIDO= 0; // Aseguro que no se reescriba la salida prox iter
            salida.bits.MOTOR=0;     // Escribo en variable de salida:
            salida.bits.VALVULA=0;   // Apagando motor y valvula
            PORTA=salida.completo; // Escribo valores de variable en el puerto
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


