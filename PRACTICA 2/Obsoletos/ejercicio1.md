Para resolver el **Ejercicio 1 del TP2**, vamos a implementar un sistema de **Productor/Consumidor** utilizando un **buffer circular** y gestión de interrupciones en el dsPIC33F.

Este ejercicio requiere que el procesador realice tareas en paralelo: mientras una interrupción externa (Productor) llena un buffer con datos filtrados, el programa principal (Consumidor) procesa esos datos con una frecuencia variable controlada por un Timer.

### Estructura del Código Paso a Paso

#### 1. Definiciones Globales y Buffer Circular
Primero, definimos las estructuras de datos en la memoria RAM (GPR). Un buffer circular necesita un índice de escritura (`cabecera`) y uno de lectura (`cola`).

```c
#include <xc.h>

#define TAM_BUFFER 16
#define TIEMPO_BASE 6000  // Valor para 150us si FCY = 40MHz (150u / 25ns)
#define TIEMPO_MAX 36000  // Valor para 900us

char buffer[TAM_BUFFER];
char log_operaciones; // Tabla de log solicitada
int cabecera = 0; // Índice para el Productor
int cola = 0;     // Índice para el Consumidor
int log_idx = 0;
int tiempo_actual = TIEMPO_BASE;
```
> **Nota técnica:** El uso de un buffer circular permite que el productor no sobreescriba datos que el consumidor aún no ha leído.

#### 2. Configuración Inicial (Setup)
En la función `main`, debemos configurar los puertos y las interrupciones siguiendo el manual.

*   **Puertos:** PORTB como entrada (datos) y PORTA para el LED.
*   **INT1:** Interrupción externa por flanco ascendente.
*   **Timer1:** Para controlar la tarea del consumidor.

```c
void setup(void) {
    TRISB = 0xFFFF; // Puerto B como entrada
    TRISA = 0xFFFE; // RA0 como salida para el LED
    
    // Configuración INT1 (Productor)
    INTCON2bits.INT1EP = 0; // Flanco ascendente
    IPC5bits.INT1IP = 4;    // Prioridad nivel 4
    IFS1bits.INT1IF = 0;    // Bajamos bandera
    IEC1bits.INT1IE = 1;    // Habilitamos interrupción
    
    // Configuración Timer1 (Consumidor)
    T1CONbits.TON = 0;      // Detener timer para configurar
    T1CONbits.TCKPS = 0;    // Prescaler 1:1
    PR1 = TIEMPO_BASE;      // Carga inicial 150us
    IFS0bits.T1IF = 0;      // Limpiar bandera
    IEC0bits.T1IE = 1;      // Habilitar interrupción de Timer
    T1CONbits.TON = 1;      // Arrancar Timer
}
```

#### 3. El Productor (Rutina de Interrupción ISR)
El productor se dispara cada vez que hay un flanco en INT1. Debe leer PORTB, filtrar el carácter y guardarlo si es válido ('0'-'9' o '+', '-', '*', '/').

```c
void __attribute__((interrupt, no_auto_psv)) _INT1Interrupt(void) {
    char dato = (char)PORTB; // Leemos el dato del puerto

    // Filtro selectivo: números y operadores
    if ((dato >= '0' && dato <= '9') || dato == '+' || dato == '-' || dato == '*' || dato == '/') {
        buffer[cabecera] = dato;
        cabecera = (cabecera + 1) % TAM_BUFFER; // Avance circular
    }
    
    IFS1bits.INT1IF = 0; // OBLIGATORIO: Bajar bandera para no repetir
}
```
> **Para ampliar:** Lee las **pestañas 10 y 11 del Anexo 1** sobre las "Fases de una interrupción" para entender por qué es crítico borrar la bandera `IFS` por software.

#### 4. El Consumidor (Lógica del Timer y Main)
El consumidor se ejecuta cuando el Timer expira. Debe verificar si hay datos (si `cabecera != cola`), procesarlos y ajustar el tiempo dinámicamente.

```c
void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void) {
    if (cabecera != cola) { // ¿Hay datos pendientes?
        char c = buffer[cola];
        
        // Conversión minúscula a mayúscula (seguridad adicional)
        if (c >= 'a' && c <= 'z') c -= 32; 
        
        log_operaciones[log_idx++] = c; // Guardar en tabla final
        cola = (cola + 1) % TAM_BUFFER;
        
        // REGLA: Si hay datos, resetear a 150us
        PR1 = TIEMPO_BASE;
    } else {
        // REGLA: Si no hay datos, aumentar linealmente +150us
        if (PR1 < TIEMPO_MAX) {
            PR1 += TIEMPO_BASE;
        }
    }
    IFS0bits.T1IF = 0; // Bajar bandera del Timer
}

int main(void) {
    setup();
    while(1) {
        // Parpadeo de LED en paralelo
        LATAbits.LATA0 = !LATAbits.LATA0;
        // Se puede usar una pequeña demora aquí (delay)
    }
}
```

### Resumen de funcionamiento para el examen:
1.  **Entrada Selectiva:** El Productor usa el registro `PORTB` y realiza un filtrado ASCII antes de tocar la memoria.
2.  **Buffer Circular:** Evita el uso de memoria excesiva y permite una comunicación fluida entre el hardware (ISR) y el software (Main/Timer).
3.  **Temporización Dinámica:** Es una técnica de ahorro de recursos. Si el sistema está inactivo, el consumidor "descansa" más tiempo (hasta 900us), pero reacciona instantáneamente (150us) en cuanto llega un dato.

**¿Dónde leer más?**
*   Para configurar el Timer, consulta la **Sección 11.4.1** del `manual_referencia_dsPIC33F_11_timers.pdf`.
*   Para el manejo de vectores de interrupción, revisa la **Tabla 7-1** del `dsPic33FJ256GP710-70286C.pdf`.