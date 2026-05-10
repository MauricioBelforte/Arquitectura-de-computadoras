#define TOPE_ARREGLOS 13    // "Lo que salta W15 al guardar los datos de A"
#define QUANTUM 2           // Por consigna
#define DESPLAZAMIENTO 18   // "Lo que salta W15 desde A->INT_TMR1->Planificador"
#define VALOR_PR1 6000      // 150us con prescaler 1:1

#ifndef KERNEL_H
#define	KERNEL_H
#ifdef	__cplusplus
extern "C" {
#endif

    void boot(void);



#ifdef	__cplusplus
}
#endif

#endif	/* KERNEL_H */

