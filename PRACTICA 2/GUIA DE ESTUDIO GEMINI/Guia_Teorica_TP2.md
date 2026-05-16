# Guía Teórica - Trabajo Práctico 2 (Interrupciones y Timers)
Este resumen integra los conceptos fundamentales sobre **interrupciones** y **timers** para el microcontrolador dsPIC33F, combinando la teoría con su aplicación práctica.

---

### 1. Sistema de Interrupciones
Una interrupción es un evento que obliga a la CPU a pausar su programa principal para ejecutar una **Rutina de Servicio de Interrupción (ISR)** y luego regresar al punto exacto donde se detuvo.

*   **Fuentes y Vectores:** El sistema admite hasta **8 trampas (traps)** no enmascarables (errores críticos) y hasta **118 fuentes** de interrupción periférica. Cada fuente tiene asignada una dirección fija en la **Tabla de Vectores de Interrupción (IVT)**.
*   **Prioridad y Jerarquía:** La CPU tiene su propio nivel de prioridad (**IPL**) en el registro **STATUS**. Cada fuente tiene un nivel configurable del **1 (mínima) al 7 (máxima)**. El nivel **0** deshabilita la interrupción. Solo interrupciones con prioridad mayor a la del procesador pueden interrumpirlo.
*   **Registros de Control Clave:**
    
    > **💡 Resumen de Roles para Interrupciones:**
    > *   **`IECx` (El Portero):** Decide si una interrupción tiene permiso o no para ejecutarse.
    > *   **`IPCx` (El Supervisor de VIPs):** Le asigna un nivel de importancia a la interrupción (1 a 7) para saber quién pasa primero en caso de concurrencia.
    > *   **`IFSx` (El Timbre):** Es la bandera que el **Hardware** levanta (suena) cuando ocurrió el evento. Tú (el **Software**) tienes que "apagar el timbre" bajando la bandera.
    > *   **`INTx` (Pines Físicos):** Ojo, estos son los pines externos (como `INT1`). No son registros, sino el hardware físico donde conectas botones o señales.
    
### 1.1 Bits Clave de `IECx` (Detalle y Sintaxis C)
*   **`T1IE`** (bit 3 de `IEC0`): Control de Habilitación.
    *   `IEC0bits.T1IE = 1;` → Habilita la interrupción (ej: del Timer 1).
    *   `IEC0bits.T1IE = 0;` → Deshabilita la interrupción.

### 1.2 Bits Clave de `IPCx` (Detalle y Sintaxis C)
*   **`T1IP<2:0>`** (bits 14-12 de `IPC0`): Nivel de Prioridad.
    *   `IPC0bits.T1IP = 4;` → Asigna prioridad nivel 4 a la interrupción (ej: del Timer 1).

### 1.3 Bits Clave de `IFSx` (Detalle y Sintaxis C)
*   **`T1IF`** (bit 3 de `IFS0`): Bandera de Estado.
    *   `if(IFS0bits.T1IF == 1)` → Permite consultar si el evento ya ocurrió (técnica de Polling). El hardware lo pone en 1.
    *   `IFS0bits.T1IF = 0;` → **Apaga la bandera.** Es *obligatorio* hacerlo por software al final de tu rutina ISR para evitar un bucle infinito.
*   **Proceso de Atención:**
    1.  Se detecta el evento (Flag en '1').
    2.  Se guarda el contexto actual (Contador de programa **PC** y registros de estado) en la **Pila (Stack)**.
    3.  El PC se carga con la dirección de la **ISR**. Se define en C con: `void __attribute__((interrupt, no_auto_psv)) _NombreInterrupt(void)`
    4.  Se ejecuta la ISR y se limpia la bandera.
    5.  La instrucción ensambladora **`RETFIE`** finaliza la rutina, restaurando el contexto desde la Pila.

---

### 2. Temporizadores (Timers)
Son módulos de hardware (16 bits por defecto) que cuentan pulsos de reloj (interno o externo) para medir tiempo o contar eventos.

*   **Clasificación:** Existen tres tipos en el dsPIC33:
    *   **Tipo A (Timer1):** Es un timer único. Puede funcionar con un cristal externo de 32.768 kHz para aplicaciones de **Reloj en Tiempo Real (RTC)** y operar en modo asíncrono durante el modo Sleep.
    *   **Tipo B (Timers 2, 4, 6, 8):** Pueden concatenarse con un timer de Tipo C para formar un **Timer de 32 bits**.
    *   **Tipo C (Timers 3, 5, 7, 9):** Pueden actuar como disparadores (trigger) para el inicio de conversión del **ADC**.
*   **Registros Clave:**
    
    > **💡 Resumen de Roles para Timers:**
    > *   **`TMRn` (El Cronómetro):** Es el registro físico que va contando hacia arriba (0, 1, 2, 3...).
    > *   **`PRn` (La Alarma):** Es el límite fijo que tú le pones. Cuando el cronómetro iguala a la alarma, "suena" (reinicia el contador y dispara una interrupción).
    > *   **`TnCON` (El Panel de Control):** Enciende el cronómetro, elige qué reloj usar y configura el engranaje reductor (prescaler).
    > *   **`TxCK` (Pin Físico):** Es el pin externo (hardware) por si quieres que el timer cuente pulsos externos en vez del reloj interno.
    
### 2.1 Bits Clave de `TMRn` (Detalle y Sintaxis C)
*   **`TMR1`** (Registro completo de 16 bits): El Contador.
    *   `TMR1 = 0;` → Borra el contador (lo reinicia a cero manualmente).

### 2.2 Bits Clave de `PRn` (Detalle y Sintaxis C)
*   **`PR1`** (Registro completo de 16 bits): Periodo Máximo.
    *   `PR1 = 39062;` → Fija el tope de cuenta. Cuando `TMR1` llegue a 39062, dispara el evento (si la interrupción está habilitada).

### 2.3 Bits Clave de `TnCON` (Detalle y Sintaxis C)
*   **`TON`** (bit 15): Encendido del módulo.
    *   `T1CONbits.TON = 1;` → Arranca a contar el Timer.
    *   `T1CONbits.TON = 0;` → Detiene el Timer.
*   **`TCS`** (bit 1): Selección de reloj.
    *   `T1CONbits.TCS = 0;` → Usa el reloj interno de la CPU (`FCY`).
    *   `T1CONbits.TCS = 1;` → Usa pulsos externos provenientes del pin físico `T1CK`.
*   **`TCKPS<1:0>`** (bits 5-4): Prescaler (divisor de frecuencia).
    *   `T1CONbits.TCKPS = 0;` // `00` = Divisor 1:1.
    *   `T1CONbits.TCKPS = 1;` // `01` = Divisor 1:8.
    *   `T1CONbits.TCKPS = 2;` // `10` = Divisor 1:64.
    *   `T1CONbits.TCKPS = 3;` // `11` = Divisor 1:256.

---

### 3. Aplicación Práctica (Trabajo Práctico 2)
El conocimiento de estos temas fue vital para implementar:
*   **Paradigma Productor-Consumidor (Ej 1):** Usando una interrupción externa (**INT1**) para recibir datos (Productor) y un **Timer** con temporización dinámica (150us a 900us) para procesarlos (Consumidor).
*   **Multitarea (Multitask - Ej 2):** Donde un Timer actúa como reloj del sistema para generar un **quantum** de tiempo y permitir que un planificador (Scheduler) alterne los punteros de pila de procesos concurrentes.

---

### 📚 ¿Dónde ampliar el tema en tus fuentes oficiales?

1.  **Configuración Detallada de Timers:**
    *   **`manual_referencia_dsPIC33F_11_timers.pdf`**: Lee la **Sección 11.4** (Modos de operación) y la **Sección 11.6** si necesitas configurar timers de 32 bits.
    *   **`dsPic33FJ256GP710-70286C.pdf`**: Consulta la **Sección 12.0** (Timer1) y **13.0** (Timers 2 al 9) para ver los diagramas de bloques y registros específicos.
2.  **Lógica y Registro de Interrupciones:**
    *   **`DsPIC33 - Interrupts -DS70184b.pdf`**: Es la fuente definitiva. La **Sección 6.4** describe cada bit de los registros `IFS`, `IEC` e `IPC`.
    *   **`AC - Anexo1.pdf`**: En las **páginas 10 y 11**, encontrarás una explicación simplificada en español sobre las fases de una interrupción y cómo se comporta la pila (stack).
3.  **Prioridades de la CPU:**
    *   **`MCU_and_DSC_prog_Reference_Manual.pdf`**: Revisa la **Sección 2.5.11.4** para entender cómo los bits `IPL` en el registro `SR` determinan qué interrupciones puede aceptar la CPU en un momento dado.
