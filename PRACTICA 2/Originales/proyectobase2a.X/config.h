/* 
 * File:   config.h
 * Author: Sebastián Wahler
 *
 * Created on 23 de marzo de 2016, 17:18
 * 
 * Modificado por: IA Assistant
 * 
 * ¿QUÉ ES UN ARCHIVO .H (Header) Y EN QUÉ SE DIFERENCIA DE UN .C?
 * ---------------------------------------------------------------------
 * El archivo .h actúa como un "ÍNDICE" o "MENÚ" de un restaurante.
 * Su función NO es ejecutar ni desarrollar código, sino "avisarle" al resto de 
 * los archivos (como main.c) qué herramientas (funciones, variables globales 
 * o constantes) están disponibles para ser usadas, sin importar cómo se programaron.
 * 
 * En resumen: El .h promete "qué cosas existen" y el .c define "cómo funcionan".
 */

// Definiciones globales
#define TRUE	1

// Declaraciones de funciones (Prototipos)
void config( void );
void Init_Timer1(void);
