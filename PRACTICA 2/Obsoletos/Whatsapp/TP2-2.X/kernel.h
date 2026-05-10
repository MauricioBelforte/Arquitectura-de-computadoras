#define TOPE_ARREGLOS 13    // TEST DEBUG REVISAR: Ver que valor usar
#define QUANTUM 2           // Por consigna
#define DESPLAZAMIENTO 18   // Modificar a medida que se agregan o quitan variables
// WREG15 - 38 , 26 EN HEXA 
#define VALOR_PR1 6000       // 150us con prescaler 1:1

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

