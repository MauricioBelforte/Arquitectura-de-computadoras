/* 
 * ARQUITECTURA DE COMPUTADORAS - UNPSJB
 * PROYECTO: TP2-2REVISADO
 * kernel.h - Definiciones del Multitarea por Copia de Stack
 */

#ifndef KERNEL_H
#define	KERNEL_H

#ifdef	__cplusplus
extern "C" {
#endif

// --- CONFIGURACIN ---
// TOPE_ARREGLOS debe ser lo suficientemente grande para copiar todo el frame.
#define TOPE_ARREGLOS 35    

// DESPLAZAMIENTO es CRTICO: Es la distancia exacta desde el W15 dentro del 
// planificador hasta donde est el PC guardado por la interrupcin.
// Si el original era 18, al agregar GUARDAR_REGISTROS (15 palabras), 
// el nuevo es aprox 33. Ajustar este valor probando en el simulador si el PC falla.
#define DESPLAZAMIENTO 33   

#define QUANTUM 2           // Cada 2 interrupciones cambia de proceso
#define VALOR_PR1 6000      // 150us @ 40MHz

// --- PROTOTIPOS ---
void boot(void);
void init(void);
void confReloj(void);
void planificador(void);

#ifdef	__cplusplus
}
#endif

#endif	/* KERNEL_H */
