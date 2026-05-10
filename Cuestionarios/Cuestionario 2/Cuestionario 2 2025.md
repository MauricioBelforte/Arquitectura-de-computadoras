Aquí tienes la transcripción y la resolución correcta del **Cuestionario Nº 2** correspondiente al año **2025**, basado en las imágenes de tus fuentes.

---

### **ARQUITECTURA DE COMPUTADORAS**
**CUESTIONARIO Nº 2**  
**Fecha:** 15/04/2025  
**Temas:** Interrupciones y Timers  

---

#### **1. Ejercicio de Programación y Cálculo: Semáforo Intermitente**
**Enunciado:** Se requiere comandar la luz amarilla de un semáforo intermitente. La lámpara está conectada al **bit 8 del PORTB** y se enciende con 1. Debe estar encendida por **3 segundos** y apagada por **2 segundos**. Este ciclo se repite continuamente hasta que llegue una interrupción por **INT0**. En ese momento se debe apagar completamente la intermitencia (no se debe volver a encender).  
**Dato:** $Fcy = 1\text{ MHz}$.

#### **Cálculos para el Timer1:**
Para calcular los valores de los registros, usamos la fórmula de tiempo: $t = Tcy \cdot \text{Prescaler} \cdot PR$.

1.  **Período de instrucción ($Tcy$):**  
    $Tcy = 1 / Fcy = 1 / 1.000.000 = 1\text{ $\mu$s}$.
2.  **Cálculo de `PR_SEGUNDO` (valor para 1 segundo):**  
    El código ya establece un **Prescaler de 1:64** (`TCKPS = 2`).  
    $1.000.000\text{ $\mu$s} = 1\text{ $\mu$s} \cdot 64 \cdot PR$  
    $PR = 1.000.000 / 64 = \mathbf{15.625}$.

---

#### **Código Completado:**

```c
int estadoLampara; // 1 = Encendida, 0 = Apagada

#define PR_SEGUNDO 15625                                     // (1)
#define TIEMPO_ENCENDIDO (PR_SEGUNDO * 3)
#define TIEMPO_APAGADO (PR_SEGUNDO * 2)                       // (2)

int main(int argc, char** argv)
{
    IFS0bits.INT0IF = 0;    // Limpiar bandera INT0
    IEC0bits.INT0IE = 1;    // Habilitar interrupción INT0
    TRISBbits.TRISB8 = 0;   // Configurar RB8 como salida
    
    // Configuración T1
    T1CONbits.TON = 0;      
    T1CONbits.TCS = 0;      // Reloj interno Fcy
    T1CONbits.TCKPS = 2;    // Prescaler 1:64
    TMR1 = 0;
    T1CONbits.TON = 1;      // Iniciar Timer
    
    PR1 = TIEMPO_ENCENDIDO; // Establece PR para luz encendida inicial
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;      // Habilitar interrupción de Timer1
    
    LATBbits.LATB8 = 1;     // (3) ENCENDER LUZ INICIALMENTE
    estadoLampara = 1;      // Estado ENCENDIDO
    
    while(1); // El resto de la lógica de parpadeo se asume en la ISR del Timer
}

// Rutina de interrupción externa para detener el semáforo
void __attribute__((interrupt, auto_psv)) _INT0Interrupt(void)
{
    IFS0bits.INT0IF = 0;    // (4) Bajar bandera de INT0
    TMR1 = 0;               // (5) Reiniciar cuenta
    T1CONbits.TON = 0;      // (6) APAGAR EL TIMER (Detiene la intermitencia)
    LATBbits.LATB8 = 0;     // APAGAR LA LÁMPARA DEFINITIVAMENTE
}
```

---

### **Explicación de los puntos clave:**
*   **Punto (1) y (2):** Se define la base de tiempo. Como $Fcy$ es 1 MHz y el prescaler es 64, el timer incrementa cada $64\text{ $\mu$s}$. Por lo tanto, para llegar a 1 segundo ($1.000.000\text{ $\mu$s}$) necesitamos $15.625$ pulsos.
*   **Punto (3):** Para encender la lámpara conectada al bit 8, se debe escribir un '1' en el registro **LATB** (`LATBbits.LATB8 = 1`).
*   **Punto (4):** Dentro de cualquier ISR, es obligatorio poner a '0' el **Flag** (`xIF`) para que el microcontrolador no se quede atrapado reingresando a la interrupción infinitamente.
*   **Punto (6):** Al poner `TON = 0`, el módulo Timer1 deja de contar. Esto detiene el ciclo de parpadeo (intermitencia) que depende de las interrupciones del timer para alternar el estado.