/*
 * File:   main.c
 * Author: Luciano Serruya Aloisi
 *
 * Created on May 14, 2019, 6:27 PM
 */


#include "xc.h"
#include "config.h"

#define PULSADOR_SIGNADO (PORTDbits.RD6)
#define PULSADOR_SIN_SIGNO (PORTDbits.RD7)
#define PULSADO (PULSADOR_SIGNADO || PULSADOR_SIN_SIGNO)
#define SIGNADO 0
#define SIN_SIGNO 1
#define TAM_BUFFER 8
#define FIN_BUFFER(i) (i==TAM_BUFFER)
int bufferRD6[TAM_BUFFER];
unsigned int bufferRD7[TAM_BUFFER];
int indiceEscrituraRD6=0,indiceEscrituraRD7=0;
int *punteroBuffer;
int indice;
int contadorDeCeros=0;
int modo=0;     // Por defecto es signado, init lo refleja
unsigned valorADC;

void __attribute__((interrupt, auto_psv)) _DMA0Interrupt(void) {
    /* Rutina de atencin para la interrupcin del DMA */
    IFS0bits.DMA0IF = 0;
}


int main(void) {
    config();
    while(1) {
        if(PULSADO){
            if(PULSADOR_SIGNADO){
                if(modo!=SIGNADO){
                    configSignado();
                    modo=0;
                }
                punteroBuffer=&bufferRD6[indiceEscrituraRD6++];
                if (FIN_BUFFER(indiceEscrituraRD6))
                    indiceEscrituraRD6=0;
            }
            if(PULSADOR_SIN_SIGNO){
                if (modo!=SIN_SIGNO){
                    configSinSigno();
                    modo=1;
                }
                punteroBuffer=&bufferRD7[indiceEscrituraRD7++];
                if(FIN_BUFFER(indiceEscrituraRD7))
                    indiceEscrituraRD7=0;
            }
            AD1CON1bits.SAMP=1;         // Inicia sampleo (Y luego conversion)
            while(!AD1CON1bits.DONE);   // Espera a que termine la conversion
            valorADC=ADC1BUF0;
            *punteroBuffer=valorADC;
            if (valorADC==0x0800){
                LATE=++contadorDeCeros;
            }
        }
    }
    return 0;
}
