/* 
 * Arquitectura de Computadoras
 * Facultad de Ingeniería - UNPSJB
 *
 * =========================================================================
 * TRABAJO PRÁCTICO N° 2 - Ejercicio 2: Multitask 
 * =========================================================================
 * Escribir un programa que simule la ejecución de tres procesos independientes 
 * (procesoA, procesoB y procesoC) y concurrentes. El programa debe constar de 
 * los tres procesos, una rutina de atención para la interrupción de un reloj y 
 * un planificador que alterna el uso de la CPU entre los tres procesos. 
 *
 * Para resolver este ejercicio tomen como base el proyectobase2b.X. El código 
 * de los tres procesos ya está presente y se recomienda NO modificarlos. El 
 * código de la función boot() en kernel.c también está completo. Si ejecutan el 
 * proyecto tal cual está, sólo se ejecutará el procesoA. Lo que deben lograr es 
 * que se ejecuten en forma concurrente los tres procesos. Para esto deberán 
 * completar las funciones incompletas en kernel.c, además de crear las estructuras 
 * de datos necesarias. 
 *
 * A los procesos se les asignará idéntico quantum (tiempo de ejecución). Cuando 
 * la rutina del reloj detecta que expiró el quantum del proceso actual, invoca 
 * al planificador. El planificador debe resguardar los valores de los registros 
 * del proceso actual (estado del proceso), recuperar el estado del proceso 
 * siguiente (previamente resguardado) y restablecer el quantum. 
 *
 * El planificador debe constar de una estructura de datos apropiada para contener 
 * el estado de los procesos. Para implementar el reloj se utilizará un Timer. 
 * El quantum será igual a 2 (dos) interrupciones de reloj. 
 *
 * Nota: Para manipular la dirección de ingreso a una rutina se puede asignar 
 * directamente el nombre de una función a una variable. 
 * Ejemplo: int direccion; ... direccion = main;
 * =========================================================================
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
