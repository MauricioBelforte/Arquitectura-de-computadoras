# Guía Teórica - Trabajo Práctico 1 (Entradas y Salidas Digitales)
Este resumen integra los conceptos fundamentales sobre el manejo de **pines digitales (GPIO)** en el microcontrolador dsPIC33F, abarcando desde la configuración del hardware hasta la estructuración de datos en C (uniones y campos de bits).

---

### 1. Sistema de Entradas/Salidas Digitales (GPIO)
Los puertos del dsPIC están agrupados por letras (PORTA, PORTB, PORTC, etc.). Cada puerto controla hasta 16 pines físicos simultáneamente.

*   **Registros de Control Clave:**

    > **💡 Resumen de Roles para los Pines Digitales:**
    > *   **`TRISx` (El Director de Tráfico):** Decide si un pin va a recibir información desde afuera (Entrada) o enviar información (Salida). Su nombre viene de "Tri-State".
    > *   **`PORTx` (La Ventana a la Realidad):** Es el registro físico conectado a las patitas del chip. Si lees de aquí, ves exactamente si hay 5V o 0V afuera.
    > *   **`LATx` (El Portapapeles Seguro):** Es un registro intermedio para escribir datos. Sirve para evitar errores cuando modificas un pin y lees otro del mismo puerto al mismo tiempo (el clásico problema de *Read-Modify-Write*).
    > *   **`AD1PCFGL` / `ADxPCFGH` (El Interruptor Analógico/Digital):** Por defecto, muchos pines vienen configurados como "Analógicos" de fábrica. Este registro obliga a los pines a comportarse como digitales puros (0 o 1).

### 1.1 Bits Clave de `TRISx` (Detalle y Sintaxis C)
*   **`TRISA0`** (bit 0 de `TRISA`): Dirección de Datos del Pin 0.
    *   `TRISAbits.TRISA0 = 1;` → Configura el pin físico `RA0` como Entrada (Input = 1).
    *   `TRISAbits.TRISA0 = 0;` → Configura el pin físico `RA0` como Salida (Output = 0).
*   **`TRISA1`** (bit 1 de `TRISA`): Dirección de Datos del Pin 1.
*   **`TRISA2`** (bit 2 de `TRISA`): Dirección de Datos del Pin 2.
*   **`TRISA3`** (bit 3 de `TRISA`): Dirección de Datos del Pin 3.
    ... (los bits del 4 al 14)
*   **`TRISA15`** (bit 15 de `TRISA`): Dirección de Datos del Pin 15.
    *   *Nota masiva:* `TRISD = 0xFFFF;` configura los 16 pines del Puerto D como entradas a la vez.

### 1.2 Bits Clave de `PORTx` (Detalle y Sintaxis C)
*   **`RA0`** (bit 0 de `PORTA`): Valor Físico del Pin 0.
    *   `variable = PORTAbits.RA0;` → **Lee** el voltaje real del pin (1 = 3.3V, 0 = 0V).
    *   `PORTAbits.RA0 = 1;` → **Escribe** un `1` lógico en el pin directamente.
*   **`RA1`** (bit 1 de `PORTA`): Valor Físico del Pin 1.
*   **`RA2`** (bit 2 de `PORTA`): Valor Físico del Pin 2.
*   **`RA3`** (bit 3 de `PORTA`): Valor Físico del Pin 3.
    ... (los bits del 4 al 14)
*   **`RA15`** (bit 15 de `PORTA`): Valor Físico del Pin 15.

### 1.3 Bits Clave de `LATx` (Detalle y Sintaxis C)
*   **`LATA0`** (bit 0 de `LATA`): Latch de Salida Segura del Pin 0.
    *   `LATAbits.LATA0 = 1;` → Escribe un `1` en el latch del pin, modificando la salida física de forma segura. *Para salidas, Microchip recomienda siempre usar LATx en lugar de PORTx.*
*   **`LATA1`** (bit 1 de `LATA`): Latch de Salida Segura del Pin 1.
*   **`LATA2`** (bit 2 de `LATA`): Latch de Salida Segura del Pin 2.
*   **`LATA3`** (bit 3 de `LATA`): Latch de Salida Segura del Pin 3.
    ... (los bits del 4 al 14)
*   **`LATA15`** (bit 15 de `LATA`): Latch de Salida Segura del Pin 15.

### 1.4 Bits Clave de `AD1PCFGL` (Detalle y Sintaxis C)
*   **`PCFG0`** (bit 0 de `AD1PCFGL`): Configuración de Pin Analógico/Digital.
    *   `AD1PCFGLbits.PCFG0 = 1;` → Configura el pin `AN0` como **Digital**.
    *   `AD1PCFGLbits.PCFG0 = 0;` → Configura el pin `AN0` como Analógico (ADC).
*   **`PCFG1`** (bit 1 de `AD1PCFGL`): Configuración de Pin Analógico/Digital (AN1).
*   **`PCFG2`** (bit 2 de `AD1PCFGL`): Configuración de Pin Analógico/Digital (AN2).
*   **`PCFG3`** (bit 3 de `AD1PCFGL`): Configuración de Pin Analógico/Digital (AN3).
    ... (los bits del 4 al 14)
*   **`PCFG15`** (bit 15 de `AD1PCFGL`): Configuración de Pin Analógico/Digital (AN15).
    *   *Nota masiva:* `AD1PCFGL = 0xFFFF;` vuelve a los 16 pines del registro 100% digitales. Es el primer paso obligatorio en tu `main.c`.

---

### 2. Estructuras de Datos Avanzadas en C (TP1-1 y TP1-2)
Para evitar escribir máscaras de bits matemáticas y confusas (ej. `(PORTD & 0x0020) >> 5`), en esta práctica aplicamos **Campos de Bits (Bitfields)** y **Uniones (Unions)**.

#### 2.1 Uso de "Unions" y "Structs"
Una `union` permite acceder a una misma dirección de memoria RAM de múltiples formas simultáneas.
El objetivo es poder leer un puerto completo de 16 bits de una sola vez, pero luego preguntar por "pedacitos" individuales con nombres legibles (ej. `entrada.sensores.SGAS`).

*Ejemplo de código utilizado en tu TP1:*
```c
typedef union {
    struct {
        unsigned int SA1:1;     // Bit 0: Puerta 1
        unsigned int SA2:1;     // Bit 1: Puerta 2
        unsigned int SA3:1;     // Bit 2: Puerta 3
        unsigned int SA4:1;     // Bit 3: Puerta 4
        unsigned int SA5:1;     // Bit 4: Puerta 5
        unsigned int SGAS:1;    // Bit 5: Sensor de Gas
        unsigned int SENE:1;    // Bit 6: Sensor de Energía
    } sensores;
    unsigned int completo;      // Acceso a los 16 bits completos
} t_entrada;

t_entrada entrada;
```

#### 2.2 La Ventaja Práctica del Polimorfismo de Datos
*   **Lectura masiva por Hardware:**
    `entrada.completo = PORTD;`
    Esto copia el estado de los 16 pines del chip de un solo golpe a tu variable. Es rapidísimo (solo gasta 1 ciclo de reloj del procesador).
*   **Análisis detallado por Software:**
    `if(entrada.sensores.SGAS == 1)`
    Ahora podemos analizar qué pasó con el sensor de gas, de forma amigable y sin matemáticas binarias.

---

### 3. Buenas Prácticas y Lógica (TP1-2)
Tu código de la Práctica 1 también implementa diseño modular y **banderas de estado (Flags)** por software para el control lógico.

*   **Variables de Estado vs Variables de Hardware:**
    En lugar de encender el motor directamente si la temperatura baja, la práctica usa una estructura llamada `t_banderas`. Primero se evalúa la lógica (`analizar_entradas()`) y luego otra función se encarga estrictamente de encender o apagar los pines (`escribir_salida()`).
*   **Estados Previos y Prevención de "Glitches":**
    El código evalúa el estado previo antes de actuar. 
    `if (CONDICIONES_ENCENDIDO) { if (APAGADO) { PRENDIDO=1; ... } }`
    *Lógica:* Si hay que encender la máquina, pero YA estaba encendida, el programa no hace nada. Esto evita reescribir constantemente el registro `PORTA` en un bucle infinito, ahorrando energía y previniendo "ruido" electromagnético en los pines físicos.
