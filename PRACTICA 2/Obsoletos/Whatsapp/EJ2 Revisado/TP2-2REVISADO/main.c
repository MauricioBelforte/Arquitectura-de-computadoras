/* 
 * ARQUITECTURA DE COMPUTADORAS - UNPSJB
 * PROYECTO: TP2-2REVISADO
 * main.c - Procesos del sistema multitarea
 */

#include <p33FJ256GP710.h>
#include <stdio.h>
#include <stdlib.h>
#include "kernel.h"

// Direcciones globales para el Kernel
unsigned int dirA, dirB, dirC;

void procesoA(void) {
    int x = 2, y = 4, z;
    while(1) {
        z = x + y;
        x = x + 2;
        y = z;
    }
}

void procesoB(void) {
    int a = 1, b = 3, c;
    while(1) {
        c = a * b;
        a = a + 2;
    }
}

void procesoC(void) {
    int r = 1, s = 1, t;
    while(1) {
        t = r + s;
        t >>= 1;
        r = r + 1;
        s = s + 4;
    }
}

int main(int argc, char** argv) {
    // Capturamos las direcciones de inicio de cada proceso
    dirA = (unsigned int)procesoA;
    dirB = (unsigned int)procesoB;
    dirC = (unsigned int)procesoC;
    
    boot();      // Inicializa el sistema y el Timer
    procesoA();  // Arranca el primer proceso
    
    return (EXIT_SUCCESS);
}
