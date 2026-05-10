# Walkthrough: Trabajo Práctico 2 - Ejercicio 2 (Kernel Multitarea - Stack Swap)
**Materia:** Arquitectura de Computadoras
**Arquitectura:** dsPIC33F (Arquitectura Harvard)

Este documento detalla el funcionamiento exacto del Ejercicio 2 (entregado y aprobado). Se explican los mecanismos físicos de manipulación del Puntero de Pila (WREG15) para lograr un intercambio de contexto (Context Switching) mediante Round-Robin.

---

## 1. Concepto de Context Switching (Stack Swap)

A diferencia de un flujo normal donde los procesos corren hasta terminar (`return`), en este kernel ejecutamos 3 tareas de bucle infinito (`procesoA`, `procesoB`, `procesoC`).
La única forma de alternar entre ellos es engañar al hardware. Cuando ocurre la interrupción del `Timer1`:
1.  El microcontrolador guarda el estado de la tarea actual en la **Pila física (Stack)**.
2.  El Kernel **copia** toda la información de la pila a un "Arreglo de Resguardo" (ej. `arregloProcA`).
3.  El Kernel **sobrescribe** la pila física con la información guardada del siguiente proceso (ej. `arregloProcB`).
4.  Al forzar el retorno de interrupción (`RETFIE`), el hardware obedece a la nueva pila y salta directamente a la siguiente tarea.

---

## 2. Inicialización de Estructuras (`kernel.c -> init()`)

Antes de correr los procesos, se necesita "falsificar" los contextos iniciales:
```c
void init(void){
    // ... inicialización en 0 ...
    arregloProcA[0]=dirA; // PC inicial de A
    arregloProcB[0]=dirB; // PC inicial de B
    arregloProcC[0]=dirC; // PC inicial de C
}
```
En las direcciones `[0]` de los arreglos se guardan las direcciones base de las funciones en Memoria de Programa (`dirA`, `dirB`, `dirC`). Esto garantiza que la primera vez que se cargue la pila de un proceso, el hardware encuentre la dirección correcta para iniciar la ejecución.

---

## 3. El Planificador y la Aritmética de Punteros

El corazón del ejercicio es la función `planificador()`, la cual trasplanta los bloques de memoria.

### Puntero de Pila (WREG15) y Desplazamiento
```c
unsigned int* puntero=WREG15;   
puntero-=DESPLAZAMIENTO;        
```
Cuando entramos a la interrupción de Timer1 y luego a la función `planificador()`, el Puntero de Pila (`WREG15`) se encuentra en el "tope" de la pila, habiendo apilado registros adicionales para la llamada a la función.
Para copiar todo el **marco de interrupción**, es imperativo retroceder el puntero hasta la "base" de los datos del proceso interrumpido. `DESPLAZAMIENTO` representa la cantidad matemática exacta de saltos (words / 16 bits) que el puntero debe retroceder para apuntar al primer elemento empujado por el hardware: el **Program Counter (PC)**.

### El Intercambio en el Switch-Case
```c
switch(estadoProceso){
    case 0: //A hacia B
        for(i=0; i<TOPE_ARREGLOS ; i++){
            arregloProcA[i]=*puntero;   // Guarda pila de A
            *puntero=arregloProcB[i];   // Reemplaza por pila de B
            puntero++;
        }
        estadoProceso++;
        break;
// ... (Repite para B->C y C->A)
```
**Operación a bajo nivel:**
1.  **Lectura:** `*puntero` accede a la Pila física en RAM. Lee el valor (PC, SR o registros W) y lo resguarda a salvo en la variable global `arregloProcA[i]`.
2.  **Escritura:** Inmediatamente después, inserta en esa misma dirección de memoria física de la Pila el contenido guardado en `arregloProcB[i]`.
3.  **Avance:** `puntero++` avanza a la siguiente dirección del Stack (subiendo en la RAM).

Cuando termina el ciclo for, toda la "conciencia" del Proceso A está respaldada estáticamente en RAM, y la Pila física está completamente dominada por el contexto del Proceso B. 

---

## 4. El Ciclo de Interrupción (`_T1Interrupt`)

```c
void __attribute__((interrupt, auto_psv)) _T1Interrupt( void ){
    IFS0bits.T1IF = 0;
    if(++contT1==QUANTUM){  
        contT1=0;           
        planificador();     
    }
}
```
*   **QUANTUM:** Representa la porción de tiempo máxima otorgada a un proceso para utilizar la CPU. Como el `Timer1` se dispara en intervalos configurables, se requieren varios disparos (`contT1`) para alcanzar el `QUANTUM` completo.
*   **Alternancia Constante:** Cuando se llega al `QUANTUM`, se llama al planificador. Al salir del planificador, la función termina y ejecuta por hardware un `RETFIE`. Esa instrucción saca de la pila el PC (que ahora es el de Proceso B) y salta al código del proceso nuevo sin que este lo note.
