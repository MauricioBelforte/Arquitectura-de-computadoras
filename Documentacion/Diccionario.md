Aquí tienes un diccionario técnico organizado por temas, basado en el material de tu materia, para ayudarte a identificar y comprender rápidamente cada sigla y concepto.

### 1. Conceptos Generales de Computadoras (PC)
Estos términos se refieren a la estructura básica de cualquier sistema de cómputo, como el modelo de Von Neumann.

*   **CPU (Central Processing Unit):** Unidad Central de Proceso. Es el "corazón" del ordenador, encargado de realizar operaciones aritmético-lógicas y coordinar el funcionamiento de todos los componentes.
*   **ALU (Arithmetic and Logic Unit):** Unidad Aritmético-Lógica. Es el bloque interno de la CPU que realiza físicamente los cálculos matemáticos y las operaciones de lógica booleana.
*   **RAM (Random Access Memory):** Memoria de acceso aleatorio. Memoria volátil donde se guardan los datos y programas que la CPU está utilizando en el momento; su contenido se borra al apagar el equipo.
*   **ROM (Read Only Memory):** Memoria de solo lectura. No volátil, utilizada generalmente para almacenar el código de arranque o configuraciones fijas.
*   **I/O (Input/Output):** Entrada/Salida (E/S). Se refiere a los módulos y dispositivos que permiten la comunicación entre la computadora y el mundo exterior.
*   **HW (Hardware):** Conjunto de componentes físicos y tangibles de un sistema (procesador, pines, circuitos). En los dsPIC, el HW puede realizar tareas (como contar tiempo o detectar flancos) de forma autónoma.
*   **Bus:** Sistema de interconexión (cables o pistas) por donde fluye la información (datos, direcciones o control) entre los distintos bloques del sistema.


### 2. Arquitectura y Tecnologías de Procesadores
Conceptos que definen cómo está construido y cómo trabaja el procesador.

*   **RISC (Reduced Instruction Set Computer):** Computador de Juego de Instrucciones Reducido. Arquitectura que utiliza instrucciones simples y de tamaño fijo que suelen ejecutarse en un solo ciclo de reloj.
*   **CISC (Complex Instruction Set Computer):** Computador de Juego de Instrucciones Complejo. Arquitectura (como los Intel x86) que utiliza instrucciones más potentes pero que pueden tomar varios ciclos de reloj para completarse.
*   **Harvard:** Arquitectura que utiliza memorias y buses independientes para las instrucciones y para los datos, lo que permite accesos simultáneos y mayor velocidad.
*   **Von Neumann:** Arquitectura donde datos e instrucciones comparten la misma memoria y el mismo bus, lo que impide acceder a ambos al mismo tiempo.
*   **Pipeline (Segmentación):** Técnica que divide la ejecución de las instrucciones en etapas independientes para poder procesar varias instrucciones a la vez en paralelo.

### 3. Microcontroladores (Conceptos de Programador)
Siglas que encontrarás frecuentemente al definir variables o analizar el flujo del programa.

*   **W / WREG (Working Register):** Registro de trabajo o acumulador. En el dsPIC33 hay 16 (W0 a W15). El W0 se usa típicamente para almacenar resultados inmediatos de la ALU.
*   **PC (Program Counter):** Contador de Programa. Registro que contiene la dirección de memoria de la próxima instrucción que debe ejecutarse.
*   **SP (Stack Pointer):** Puntero de Pila. Indica la dirección actual en la "pila" (stack), una zona de memoria usada para guardar estados temporales y direcciones de retorno.
*   **SR (Status Register):** Registro de Estado de la CPU. Contiene los bits **IPL<2:0>** que definen la prioridad actual de procesamiento y las banderas de acarreo (C), cero (Z), etc.
*   **FCY (Instruction Cycle Frequency):** Frecuencia de Ciclo de Instrucción. Velocidad real de ejecución de instrucciones (usualmente FOSC/2). Clave para cálculos de tiempo.
*   **GPR (General Purpose Registers):** Registros de Propósito General. Zona de la memoria RAM destinada a las variables que define el programador.

*   **SFR (Special Function Registers):** Registros de Funciones Especiales. Registros destinados al control y configuración de los periféricos del microcontrolador.
*   **CORCON (Core Control Register):** Registro de control de 16 bits utilizado para configurar los parámetros fundamentales del núcleo (core) del CPU. Permite configurar la visibilidad de memoria (PSV), modos de saturación DSP y gestionar niveles de prioridad de excepciones (IPL3).


### 4. Registros Específicos del dsPIC33 (Puertos e Interrupciones)
Estas son las siglas que usarás directamente en tu código C en MPLAB X.

**Puertos de E/S:**
*   **TRISx:** Registro de dirección de puerto (ej. `TRISB`). Define si un pin es entrada (si el bit es 1) o salida (si es 0).
*   **PORTx:** Registro de lectura (ej. `PORTB`). Se utiliza para leer el estado físico actual de los pines configurados como entrada.
*   **LATx:** Registro de salida (ej. `LATB`). Es el "cerrojo" donde se escribe el dato que se quiere enviar hacia los pines físicos.

**Gestión de Interrupciones:**
*   **ISR (Interrupt Service Routine):** Rutina de Servicio de Interrupción. Es la función que se ejecuta automáticamente cuando ocurre un evento.
*   **IVT (Interrupt Vector Table):** Tabla de Vectores de Interrupción. Mapa de memoria que contiene las direcciones de inicio de todas las ISR.
*   **IFS (Interrupt Flag Status):** Registro de banderas. Indica mediante un '1' si se ha producido una solicitud de interrupción específica.
*   **IEC (Interrupt Enable Control):** Registro de habilitación. Permite activar o desactivar cada interrupción de forma individual.
*   **IPC (Interrupt Priority Control):** Registro de prioridad. Permite asignar a cada interrupción un nivel de importancia del 1 al 7.
*   **RETFIE (Return From Interrupt):** Instrucción de retorno de interrupción. Restaura el contexto y devuelve el control al programa principal.
*   **DMA (Direct Memory Access):** Acceso Directo a Memoria. Módulo que mueve datos entre periféricos y RAM sin intervención de la CPU para no quitarle tiempo de procesamiento.
*   **INTx (External Interrupts 0-4):** Fuentes de **interrupción externa** disparadas por pines físicos. El dsPIC33F soporta hasta cinco de estas entradas (INT0 a INT4).
*   **INT1 (External Interrupt 1):** Interrupción externa específica usada frecuentemente para detectar ingresos de datos (ej. en el TP2) mediante un flanco ascendente o descendente configurable.
*   **IPL3 (Interrupt Priority Level 3):** Bit de estado (en CORCON) que indica si una **trampa (trap)** o excepción crítica del procesador está siendo atendida.
*   **INTCON1 / INTCON2:** Registros de control de interrupciones. Configuran el comportamiento global del sistema de excepciones.
*   **NSTDIS (Interrupt Nesting Disable):** Bit en INTCON1. Si es '1', prohíbe que una interrupción sea interrumpida por otra de mayor prioridad (desactiva el anidamiento).
*   **ALTIVT (Alternate Interrupt Vector Table):** Bit en INTCON2. Permite habilitar el uso de una tabla de vectores alternativa para depuración.



### 5. Temporizadores (Timers)
Términos relacionados con los módulos que miden tiempo en el microcontrolador.

*   **TMRn:** Registro contador del Timer (ej. `TMR1`). Se incrementa en cada pulso de reloj hasta alcanzar el valor de periodo.
*   **PRn (Period Register):** Registro de periodo (ej. `PR1`). Es el valor límite que fijas; cuando el TMRn lo iguala, ocurre el evento de interrupción.
*   **TnCON:** Registro de configuración del Timer. Aquí se enciende el módulo (`TON`) y se elige la fuente de reloj.
*   **TON (Timer On):** Bit dentro de `TnCON`. Al ponerlo en '1' el temporizador comienza a contar; en '0' se detiene.
*   **TCS (Timer Clock Source):** Bit en `TnCON`. Selecciona si el reloj es el ciclo interno (0) o un pulso externo (1).
*   **TGATE (Timer Gated Accumulation):** Modo que permite al timer contar solo mientras un pin externo se mantenga en nivel alto.
*   **TCKPS (Timer Clock Prescale Select):** Bits dentro de `TnCON` que definen el **Prescaler** (divisor de frecuencia) para que el timer cuente más lento.

*   **Prescaler:** Circuito que divide la frecuencia del reloj principal (FCY) por un factor (1, 8, 64 o 256) antes de que llegue al contador del timer.



### 6. Sintaxis de Manejo de Registros en C (XC16)
Ejemplos de cómo escribir el código en MPLAB X para interactuar con el hardware.

**Acceso a Bits Individuales:**
*   `INTCON2bits.INT1EP = 0;` → Configura el flanco de la interrupción externa 1 como positivo (subida).
*   `AD1CON1bits.ADON = 1;` → Enciende el módulo de conversión Analógico-Digital (ADC).
*   `IEC0bits.T1IE = 1;` → Habilita (Enciende) la interrupción del Timer 1.
*   `IFS0bits.T1IF = 0;` → Limpia la bandera de interrupción del Timer 1 (indica que ya se atendió).

**Acceso al Registro Completo (16 bits):**
*   `TRISB = 0x0000;` → Configura todo el Puerto B como salida (pone los 16 bits en 0).
*   `LATB = 0xFFFF;` → Pone en alto (5V/3.3V) todos los pines del Puerto B al mismo tiempo.
*   `PR1 = 39062;` → Carga el valor de periodo directamente en el registro del Timer 1.

**Sintaxis de Interrupciones (ISR):**
*   `void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)` → Firma obligatoria para que el micro sepa que esta función es la que debe ejecutar cuando el Timer 1 llega a su fin.