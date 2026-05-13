# Guía Teórica - Trabajo Práctico 2 (Interrupciones y Timers)
Este resumen integra los conceptos fundamentales sobre **interrupciones** y **timers** para el microcontrolador dsPIC33F, combinando la teoría con su aplicación práctica.

---

### 1. Sistema de Interrupciones
Una interrupción es un evento que obliga a la CPU a pausar su programa principal para ejecutar una **Rutina de Servicio de Interrupción (ISR)** y luego regresar al punto exacto donde se detuvo.

*   **Fuentes y Vectores:** El sistema admite hasta **8 trampas (traps)** no enmascarables (errores críticos) y hasta **118 fuentes** de interrupción periférica. Cada fuente tiene asignada una dirección fija en la **Tabla de Vectores de Interrupción (IVT)**.
*   **Prioridad y Jerarquía:** La CPU tiene su propio nivel de prioridad (**IPL**) en el registro **STATUS**. Cada fuente tiene un nivel configurable del **1 (mínima) al 7 (máxima)**. El nivel **0** deshabilita la interrupción. Solo interrupciones con prioridad mayor a la del procesador pueden interrumpirlo.
*   **Registros de Control Clave:**
    *   **`IFSx` (Interrupt Flag Status):** Contiene los "flags" o banderas. El hardware pone el bit en **1** cuando ocurre el evento. **Debe borrarse por software obligatoriamente** dentro de la ISR para evitar llamadas recursivas infinitas.
    *   **`IECx` (Interrupt Enable Control):** Bit que habilita o deshabilita cada interrupción específica.
    *   **`IPCx` (Interrupt Priority Control):** Define el nivel de prioridad de cada periférico.
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
    *   **`TMRn`:** Es el registro contador que incrementa en cada pulso.
    *   **`PRn` (Period Register):** Contiene el valor de comparación. Cuando `TMRn` iguala a `PRn`, ocurre un "match", se genera una interrupción y el contador vuelve a cero.
    *   **`TnCON`:** Registro de configuración que incluye:
        *   **`TON`**: Encender/apagar el módulo.
        *   **`TCS`**: Fuente de reloj (interno FCY o externo).
        *   **`TCKPS`**: **Prescaler** para dividir la frecuencia de entrada y contar más lento.

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
