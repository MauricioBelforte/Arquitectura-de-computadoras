Aquí tienes la transcripción del **Cuestionario Nº 2 (Recuperatorio)** de la materia **Arquitectura de Computadoras**, correspondiente al año **2024**, basada en las imágenes de tus fuentes.

---

### **ARQUITECTURA DE COMPUTADORAS**
**CUESTIONARIO Nº 2 (Recuperatorio)**  
**Fecha:** 25/04/2024  
**Temas:** Interrupciones y Timers  
**Alumno/a:** Pedro Revuelta Garcia

---

#### **1. Ejercicio de programación de ISR**
Se necesita contabilizar en una variable, la cantidad de ocurrencias de la interrupción **INT0**. Asuma que la interrupción ya está configurada y habilitada. A la octava (8) interrupción debe reiniciar la cuenta del **Timer1** y cambiar el **Prescaler a 256**. Complete el código de la rutina de atención que resuelva correctamente este problema.

**Código completado (según manuscrito):**
```c
int cont = 0;

void __attribute__((interrupt, auto_psv)) _INT0Interrupt(void)
{
    cont++;
    if (cont == 8)
    {
        TMR1 = 0;               // Reinicia la cuenta del Timer1
        T1CONbits.TCKPS = 0b11; // Cambia el Prescaler a 256 (valor 11 en binario)
        cont = 0;               // Reinicia el contador de interrupciones
    }
    IFS0bits.INT0IF = 0;        // Baja la bandera de interrupción (paso obligatorio)
}
```

---

#### **2. Cálculo de tiempos**
Considerando que la frecuencia de instrucción (**Fcy**) es de **40 MHz**, seleccione un valor adecuado para el **Prescaler** y un valor adecuado para **PR1**, de tal forma que se produzca una interrupción del Timer1 cada **25 ms**. Justifique la respuesta.

**Resolución (según manuscrito):**
*   **Datos:**
    *   $Fcy = 40\text{ MHz}$
    *   $Tcy = \frac{1}{Fcy} = 0,025\text{ $\mu$s}$
    *   $t = 25\text{ ms} = 25.000\text{ $\mu$s}$
*   **Fórmula utilizada:** $t = Tcy \cdot \text{Prescaler} \cdot PR1$
*   **Selección:**
    *   **Prescaler:** $1:64$
    *   **Cálculo de PR1:** $PR1 = \frac{t}{Tcy \cdot \text{Prescaler}} = \frac{25.000}{0,025 \cdot 64} = 15.625$
*   **Resultado:** Prescaler $= 64$ y $PR1 = 15.625$.

---

#### **3. Análisis de prioridades y registros**
Dados los siguientes valores de registros:  
`SR=0x0052`, `IEC0=0x2B89`, `IPC0=0x6037`, `IPC1=0x4037`, `IPC2=0x7004`.

**A. Suponga que se está atendiendo la interrupción de Timer1 (prioridad 7). Antes de finalizar, interrumpen simultáneamente el Timer2 y el Timer3. Una vez que concluya la interrupción actual, ¿Cuál de estas dos interrupciones será atendida primero? Justifique la respuesta.**
*   **Respuesta:** Será atendido primero el **Timer 2**.
*   **Justificación:** Según los registros de prioridad (`IPC1` e `IPC2`), ambos Timers tienen configurada la misma prioridad (Prioridad 4). Ante igualdad de prioridad, se define por la **prioridad natural** dada por su ubicación en la Tabla de Vectores (IVT); el Timer 2 tiene un número de vector menor que el Timer 3, por lo que tiene precedencia.

**B. Suponga ahora que se atendieron todas las interrupciones pendientes y se está ejecutando el programa principal. ¿Puede interrumpir el INT0? Justifique la respuesta.**
*   **Respuesta:** Sí, puede interrumpir.
*   **Justificación:** La prioridad configurada para **INT0** es **7** (según `IPC0bits.INT0IP`), mientras que el nivel de prioridad actual de la CPU (**IPL**) en el registro `SR` (bits 7-5) es **2** (ya que `SR=0x0052` implica bits 7-5 en `010`). Como la prioridad del dispositivo ($7$) es estrictamente mayor que la de la CPU ($2$), la interrupción es aceptada.


---


El parcial del año 2024 que se observa en las imágenes **está resuelto correctamente** en todos sus puntos. Los cálculos de tiempo son precisos, la lógica de la rutina de interrupción (ISR) sigue las reglas del compilador y el análisis de prioridades coincide con los registros y la tabla de vectores del dsPIC33F.

A continuación, realizo la resolución formal del examen paso a paso, citando las fuentes para que puedas verificar cada concepto:

### 1. Programación de la ISR (INT0)
El objetivo es contar 8 ocurrencias de **INT0**, y en la octava, reiniciar el **Timer1** y cambiar su **Prescaler a 256**.

*   **Lógica:** Se utiliza una variable global para contar los eventos. Al llegar a 8, se accede al registro de cuenta `TMR1` y al registro de control `T1CON` para modificar el divisor de frecuencia.
*   **Prescaler:** El valor para un divisor 1:256 en el Timer1 se logra poniendo los bits `TCKPS<1:0>` en `11` (binario).
*   **Bandera:** Es obligatorio limpiar el bit `INT0IF` en el registro `IFS0` antes de salir para evitar interrupciones recursivas.

**Código correcto:**
```c
int cont = 0; // Variable global

void __attribute__((interrupt, auto_psv)) _INT0Interrupt(void) {
    cont++;
    if (cont == 8) {
        TMR1 = 0;               // Reinicia el contador del Timer
        T1CONbits.TCKPS = 3;    // Prescaler 1:256 (3 en decimal es 11 binario)
        cont = 0;               // Reinicia el contador de eventos
    }
    IFS0bits.INT0IF = 0;        // Baja la bandera de interrupción
}
```

---

### 2. Cálculo de Tiempos
Se requiere una interrupción del **Timer1** cada **25 ms** con una **Fcy = 40 MHz**.

*   **Paso 1: Calcular el período de instrucción ($Tcy$).**
    $Tcy = 1 / Fcy = 1 / 40\text{ MHz} = 0,025\text{ $\mu$s}$.
*   **Paso 2: Utilizar la fórmula de tiempo.**
    $t = Tcy \cdot \text{Prescaler} \cdot PR1$.
*   **Paso 3: Seleccionar Prescaler y despejar $PR1$.**
    Si probamos con **Prescaler 1:64**:
    $25.000\text{ $\mu$s} = 0,025\text{ $\mu$s} \cdot 64 \cdot PR1$
    $PR1 = 25.000 / 1,6 = 15.625$
*   **Resultado:** Como $15.625$ es menor que $65.535$ (límite de 16 bits), los valores son válidos. **Prescaler = 64** y **PR1 = 15.625**.

---

### 3. Análisis de Prioridades
Dados: `SR=0x0052`, `IEC0=0x2B89`, `IPC0=0x6037`, `IPC1=0x4037`, `IPC2=0x7004`.

**A. ¿Quién se atiende primero entre Timer2 y Timer3?**
1.  **Prioridad de Timer2:** En `IPC1`, los bits 14-12 (`T2IP`) corresponden al primer dígito hexadecimal `4`. **Prioridad = 4**.
2.  **Prioridad de Timer3:** En `IPC2`, los bits 2-0 (`T3IP`) corresponden al último dígito hexadecimal `4`. **Prioridad = 4**.
3.  **Resolución de empate:** Al tener igual prioridad configurada, se recurre a la **prioridad natural**. Según la tabla de vectores, el **Timer2** (Vector 15) tiene un número de vector menor que el **Timer3** (Vector 16), por lo tanto, el **Timer2 se atiende primero**.

**B. ¿Puede interrumpir el INT0 al programa principal?**
1.  **Prioridad de INT0:** En `IPC0`, los bits 2-0 (`INT0IP`) corresponden al último dígito hexadecimal `7`. **Prioridad del dispositivo = 7**.
2.  **IPL de la CPU:** En el registro `SR=0x0052`, los bits 7-5 (`010` en binario) indican el nivel actual de la CPU. **IPL de la CPU = 2**.
3.  **Condición de interrupción:** La prioridad del dispositivo ($7$) es **estrictamente mayor** que la de la CPU ($2$).
*   **Respuesta:** **Sí, puede interrumpir**.


