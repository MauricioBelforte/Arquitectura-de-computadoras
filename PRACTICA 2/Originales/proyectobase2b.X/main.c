/* 
 * Arquitectura de Computadoras
 * Facultad de Ingeniería - UNPSJB
 *
 * Proyecto Base 2B: Kernel Multitarea (Multitasking)
 * Modificado por: IA Assistant
 * 
 * ¿QUÉ ES ESTE PROYECTO?
 * Este es el esqueleto básico para construir un Sistema Operativo de Tiempo Real (RTOS) 
 * extremadamente simple. El objetivo es lograr que 3 funciones ("Procesos") que 
 * tienen bucles infinitos (while(1)) parezcan ejecutarse exactamente al mismo tiempo 
 * en un microcontrolador de 1 solo núcleo.
 *
 * ¿CÓMO SE LOGRA LA ILUSIÓN DE MULTITAREA?
 * Usando la interrupción de un Timer. Cada vez que el Timer desborda (ej. cada 1 ms), 
 * el hardware frena al proceso actual bruscamente, llama al "planificador" (scheduler) 
 * para que guarde dónde se quedó anotando todo, y le da el control al siguiente proceso. 
 * A esto se le llama "Cambio de Contexto".
 */

#include "xc.h"
#include <stdio.h>
#include <stdlib.h>
#include "kernel.h"

/*
 * =========================================================================
 * LOS 3 PROCESOS DEL USUARIO
 * =========================================================================
 * Cada proceso representa un "programa" independiente. Notarás que TODOS tienen
 * un `while(1)`. En la programación secuencial normal, si un programa entra 
 * a un `while(1)`, se queda atrapado ahí para siempre y el resto del código muere.
 * 
 * ¡Acá es donde brillará la magia del Timer y nuestro Kernel! El planificador 
 * se encargará de ir saltando de un while(1) a otro (conmutación) sin que 
 * los procesos se den cuenta de que fueron pausados.
 */

// --- PROCESO A ---
void procesoA(void)
{
    int x, y, z;
    x = 2;
    y = 4;
    
    while(1) {
        z = x + y;
        x = x + 2;
        y = z;
        // La ejecución se congela mágicamente en alguna de estas líneas
        // cuando el Timer interrumpe, y luego de un rato se reanuda acá mismo.
    }
}

// --- PROCESO B ---
void procesoB(void)
{
    int a, b, c;
    a = 1;
    b = 3;
    
    while(1) {
        c = a * b;
        a = a + 2;
    }
}

// --- PROCESO C ---
void procesoC(void)
{
    int r, s, t;
    r = 1;
    s = r;
    
    while(1) {
        t = r + s;
        t >>= 1;   // Operador de bitshift (Divide por 2 moviendo los bits a la derecha)
        r = r + 1;
        s = s + 4;
    }
}

/*
 * =========================================================================
 * PROGRAMA PRINCIPAL (PUNTO DE ENTRADA)
 * =========================================================================
 */
int main(int argc, char** argv) {
    
    // 1. Fase de Arranque del "Sistema Operativo"
    // Llama a las funciones del kernel (en kernel.c) para configurar los relojes,
    // los punteros de pila (Stack Pointers) para cada uno de los procesos, 
    // y dejar todo listo para la multitarea.
    // (Actual spoiler: ¡Si mirás kernel.c vas a ver que está totalmente vacío por ahora!).
    boot();
    
    // 2. Ejecución del Primer Proceso
    // Llamamos manualmente al Proceso A para arrancar la rueda del sistema.
    // Una vez que entremos acá, el micro quedará atrapado en su while(1).
    // Solo podrá salir cuando el Timer dispare la interrupción, el cual invocará 
    // al kernel para forzar el salto hacia el Proceso B, luego al C, y vuelta al A.
    procesoA();
    
    // El programa jamás debería llegar a esta línea de EXIT_SUCCESS 
    // porque el procesoA() es un bucle infinito del cual no se puede retornar.
    return (EXIT_SUCCESS);
}
