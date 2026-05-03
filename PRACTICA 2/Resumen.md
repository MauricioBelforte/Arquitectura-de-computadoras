Para resolver el **Trabajo Práctico Nº 2 (TP2)**, que se enfoca en el uso de **Timers** y el manejo de **Interrupciones** en el dsPIC33F, aquí tienes un resumen integral del material clave y las referencias exactas para profundizar.

### 1. Resumen: Temporizadores (Timers)
Los timers son módulos de hardware que cuentan pulsos de reloj para medir tiempo o contar eventos externos.

*   **Clasificación:** Existen tres tipos en el dsPIC33:
    *   **Tipo A (Timer1):** Es un timer de 16 bits único, útil para relojes de tiempo real.
    *   **Tipo B (Timers 2, 4, 6, 8):** Pueden funcionar de forma independiente o como la palabra menos significativa en un par de 32 bits.
    *   **Tipo C (Timers 3, 5, 7, 9):** Funcionan como timers de 16 bits o como la palabra más significativa en un par de 32 bits.
*   **Registros Clave:**
    *   **`TMRn`:** Es el registro contador que incrementa en cada pulso.
    *   **`PRn` (Period Register):** Contiene el valor de comparación. Cuando `TMRn` alcanza a `PRn`, ocurre un "match", se genera una interrupción y el contador vuelve a cero.
    *   **`TnCON`:** Registro de control para encender el timer (`TON`), elegir la fuente de reloj (`TCS`) y configurar el divisor de frecuencia o **Prescaler** (`TCKPS`).

### 2. Resumen: Gestión de Interrupciones
Una interrupción es un evento que obliga a la CPU a pausar su programa principal para ejecutar una **Rutina de Servicio de Interrupción (ISR)**.

*   **Jerarquía y Prioridad:** Cada fuente (como el Timer1 o la entrada INT1) tiene un nivel de prioridad configurable del **1 (mínima) al 7 (máxima)**. El nivel **0** deshabilita la interrupción.
*   **Controladores de Interrupción (Registros):**
    *   **`IFSx` (Interrupt Flag Status):** Contiene los "flags" o banderas. El hardware pone el bit en **1** cuando ocurre el evento. **Es obligatorio ponerlo en 0 por software dentro de la ISR**.
    *   **`IECx` (Interrupt Enable Control):** Bit que habilita o deshabilita cada interrupción específica.
    *   **`IPCx` (Interrupt Priority Control):** Donde se asigna el nivel de prioridad (1-7) a cada periférico.
*   **La ISR en C:** Se define con el atributo `__attribute__((interrupt, no_auto_psv))` seguido del nombre del vector (ej. `_T1Interrupt`).

### 3. Aplicación al TP2
*   **Ejercicio 1 (Productor-Consumidor):** Debes usar la interrupción externa **INT1** para detectar el ingreso de datos (Productor) y un **Timer** para disparar la tarea de consumo con tiempos variables (150us a 900us).
*   **Ejercicio 2 (Multitask):** El **Timer** actúa como "reloj del sistema". Cada 2 interrupciones (quantum), se debe invocar al planificador para cambiar de proceso.

---

### ¿Dónde ampliar el tema en tus fuentes?

Si necesitas profundizar en detalles técnicos o ver ejemplos de código, consulta estas secciones:

1.  **Configuración Detallada de Timers:**
    *   **`manual_referencia_dsPIC33F_11_timers.pdf`**: Lee la **Sección 11.4** (Modos de operación) y la **Sección 11.6** si necesitas configurar timers de 32 bits.
    *   **`dsPic33FJ256GP710-70286C.pdf`**: Consulta la **Sección 12.0** (Timer1) y **13.0** (Timers 2 al 9) para ver los diagramas de bloques y registros específicos.

2.  **Lógica y Registro de Interrupciones:**
    *   **`DsPIC33 - Interrupts -DS70184b.pdf`**: Es la fuente definitiva. La **Sección 6.4** describe cada bit de los registros `IFS`, `IEC` e `IPC`.
    *   **`AC - Anexo1.pdf`**: En las **páginas 10 y 11**, encontrarás una explicación simplificada en español sobre las fases de una interrupción y cómo se comporta la pila (stack).

3.  **Prioridades de la CPU:**
    *   **`MCU_and_DSC_prog_Reference_Manual.pdf`**: Revisa la **Sección 2.5.11.4** para entender cómo los bits `IPL` en el registro `SR` determinan qué interrupciones puede aceptar la CPU en un momento dado.