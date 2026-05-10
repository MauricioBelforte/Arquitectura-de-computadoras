/* 
 * ARQUITECTURA DE COMPUTADORAS - UNPSJB
 * KERNEL POR COPIA DE STACK (Mtodo Pizarra) - main.c
 */

#include <p33FJ256GP710.h>
#include <stdio.h>
#include <stdlib.h>
#include "kernel.h"

// Direcciones globales para que el Kernel las vea
unsigned int dirA, dirB, dirC;

void procesoA(void) {
    int x = 2, y = 4, z;
    while(1) { z = x + y; x += 2; y = z; }
}

void procesoB(void) {
    int a = 1, b = 3, c;
    while(1) { c = a * b; a += 2; }
}

void procesoC(void) {
    int r = 1, s = 1, t;
    while(1) { t = r + s; t >>= 1; r++; s += 4; }
}

int main(int argc, char** argv) {
    dirA = (unsigned int)procesoA;
    dirB = (unsigned int)procesoB;
    dirC = (unsigned int)procesoC;
    
    boot();
    procesoA();
    
    return (EXIT_SUCCESS);
}
