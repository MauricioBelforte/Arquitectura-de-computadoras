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
/*TRABAJO PRÁCTICO Nº 2 
Temas: Interrupciones. Timers. 
Objetivos:  
● Técnica de programación por interrupciones. 
● Programación de un productor – consumidor (buffer limitado). 
● Programación de timers. 
Material de soporte: 
● Para resolver el práctico se propone consultar el “Material para clases prácticas”, como así 
también la sección correspondiente a este práctico, disponible en el Aula Virtual. 
● Para el primer ejercicio (Productor/Consumidor) utilizar el proyecto base proyectobase2a.X 
disponible en el Aula Virtual. 
● Para el segundo ejercicio (Multitask) utilizar el proyecto base proyectobase2b.X disponible 
en el Aula Virtual. 
Ejercicio 1: Productor/Consumidor 
El objetivo es implementar una rutina de interrupción para gestionar un buffer circular que almacene 
datos recibidos por el Puerto B (PORTB). El sistema debe operar bajo el paradigma 
Productor/Consumidor con las siguientes especificaciones: 
● Productor (ISR): el cuerpo de la rutina de atención para la interrupción debe resolver el 
ingreso de caracteres en un arreglo. Este arreglo (buffer) se utilizará de manera circular (se 
volverá al inicio una vez que se lo termine de recorrer). El ingreso de un caracter se detecta 
por un flanco ascendente en la Interrupción Externa (INT1). El ingreso a caracteres al buffer 
debe realizarse selectivamente, sólo debe aceptar caracteres que pertenezcan al rango de 
operadores aritméticos y números (ASCII del '0' al '9', y los símbolos '+', '-', '*', '/'). 
Cualquier otro carácter debe ser descartado. 
● Consumidor (Main): Debe leer los caracteres pendientes del buffer circular y trasladarlos a 
una tabla de "Log de Operaciones" en la memoria de datos. Al consumir, si el carácter es una 
letra minúscula (en caso de que el filtro del productor fallara o se modificara), el consumidor 
debe convertirlo a mayúscula antes de guardarlo en la tabla final. 
El programa principal debe ejecutar, en paralelo al consumidor, una rutina de parpadeo de un 
LED. 
● Temporización Dinámica (Timer): El consumidor no es constante. Se debe configurar un 
Timer para disparar la tarea de consumo con la siguiente lógica de espera: 
○ Estado inicial: Tiempo de espera base de 150us. 
○ Si no hay datos: Ell tiempo de espera aumentará de forma lineal sumando 150us 
en cada intento fallido (150us -> 300us -> 450us...), hasta un tope máximo de 900us. 
○ Si hay datos: En el momento en que se detecte y consuma al menos un carácter, el 
temporizador debe resetearse inmediatamente a su valor base de 150us. 
 */


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

void consumirDatos(int cantidadAProcesar){
    int i;
    for (i = 0; i < cantidadAProcesar; i++){
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
                // Capturamos cuántos hay AHORA MISMO
                int procesados = caracteresPendientes;
                consumirDatos(procesados);
                
                // BUG DE CONCURRENCIA SOLUCIONADO: 
                // No ponemos `caracteresPendientes = 0;` porque si entró un pulso
                // en el medio del for de consumirDatos, lo borraríamos por error.
                // Apagamos la interrupción un microsegundo, restamos los leídos, y volvemos a prender.
                IEC1bits.INT1IE = 0;
                caracteresPendientes -= procesados;
                IEC1bits.INT1IE = 1;
                
                cantFallas = 0;         // Reinicia timer a 150us
            }
            LATA = !LATA; // Parpadeo del LED (Puerto A)
            counterTimer = 0;
        }
    }
}
