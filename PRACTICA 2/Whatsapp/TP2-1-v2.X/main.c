/**********************************************************************
 FileName:        main.c
 Dependencies:    p33FJ256GP710.h
 Processor:       dsPIC33F
 Compiler:        MPLAB� C30 v2.01 or higher

 Ejemplo de funcionamiento de:
 	Timer1
        INT0
 	PORTS

 REVISION HISTORY:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Author            Date      Comments on this revision
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**********************************************************************/

#include "p33FJ256GP710.h"
#include "config.h"

#define LOG_ACTUAL logOperaciones[indLog++]
#define CAR_DE_BUFFER buffer[indConsum++]
#define FIN_DE_LOG indLog >= TAM_LOG

extern char buffer[];

int counterTimer, caracteresPendientes, cantFallas = 0;

char logOperaciones[TAM_LOG];   // Tabla de log de operaciones
int indLog = 0;                 // Indice para la tabla de log de operaciones
int indConsum=0;                // Indice para recorrer buffer ("Pensar como aguja de LECTURA")

void consumirDatos(int caracteresPendientes){
    int i;
    for (i = 0; i < caracteresPendientes; i++){   // Consumo el dato del buffer y lo guardo en la tabla de log de operaciones
        LOG_ACTUAL = CAR_DE_BUFFER; // ...lo guardo en la tabla de log de operaciones
        if (FIN_DE_LOG)
            indLog = 0;
        if (FIN_DE_BUFFER(indConsum))
            indConsum = 0;
    }
}

/*
 * Programa Principal
 */
int main(void) {
    config();
    while(TRUE){
        if (counterTimer > cantFallas ){
            if (cantFallas < MAX_FALLAS) // Puse como if suelto en vez de "else a lo de abajo" para no anidar tanto
                cantFallas++;           // REVISAR si se renombra cantFallas debido a esto
            if (caracteresPendientes > 0){       // Si se ingreso al menos 1 caracter en el buffer
                consumirDatos(caracteresPendientes);
                caracteresPendientes = 0;
                cantFallas = 0;         // Reinicia timer a 150us
            }
            LATA = !LATA; // Parpadeo del LED (Puerto A)
            counterTimer = 0;
        }
    }
}
