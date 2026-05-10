/* 
 * ARQUITECTURA DE COMPUTADORAS - UNPSJB
 * KERNEL POR COPIA DE STACK (Mtodo Pizarra) - kernel.h
 */

#ifndef KERNEL_H
#define	KERNEL_H

#ifdef	__cplusplus
extern "C" {
#endif

// --- CONSTANTES ---
#define TOPE_ARREGLOS 38    // Tamaño del depósito para el stack de cada proceso
#define DESPLAZAMIENTO 38   // Cuántas posiciones retroceder en el stack real
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
