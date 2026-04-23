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

*   **W / WREG (Working Register):** Registro de trabajo o acumulador. En el dsPIC33 hay 16 (W0 a W15). El W0 se usa típicamente para almacenar resultados inmediatos de la ALU. *(Son registros del núcleo CPU, pero arquitectónicamente **SÍ están mapeados en la Memoria de Datos** ocupando los primeros espacios desde `0x0000` hasta `0x001E`).*
*   **PC (Program Counter):** Contador de Programa. Registro de 23 bits que contiene la dirección de memoria de la próxima instrucción que debe ejecutarse. *(Registro interno del núcleo CPU, opera sobre la Memoria de Programa de 24 bits.)*
*   **SP / W15 (Stack Pointer):** Puntero de Pila. Es el registro W15, dedicado permanentemente a indicar la dirección actual en la cima de la "pila" (stack), una zona de la Memoria de Datos (RAM) usada para guardar estados temporales y direcciones de retorno. *(Registro interno del núcleo CPU. La Pila a la que apunta reside en la Memoria de Datos, típicamente desde `0x0800` en adelante.)*
*   **SPLIM (Stack Pointer Limit):** Registro que establece el límite superior de la pila. Si W15 supera este valor, se genera una trampa (Stack Error Trap) para evitar corrupción de memoria. *(Memoria de Datos - SFR: `0x0020`)*
*   **SR (Status Register):** Registro de Estado de la CPU. Contiene los bits **IPL<2:0>** que definen la prioridad actual de procesamiento y las banderas de acarreo (C), cero (Z), negativo (N), desbordamiento (OV), etc. *(Memoria de Datos - SFR: `0x0042`)*
*   **FCY (Instruction Cycle Frequency):** Frecuencia de Ciclo de Instrucción. Velocidad real de ejecución de instrucciones ($Fcy = Fosc/2$). Clave para cálculos de tiempo. *(No es un registro, es un valor derivado del oscilador.)*
*   **Tcy (Instruction Cycle Time):** Tiempo de Ciclo de Instrucción. Es la duración de una sola instrucción ($Tcy = 1/Fcy$). Es el valor que usas para multiplicar en las fórmulas de los Timers. Ej: Si Fcy es 40MHz, Tcy es 25 nanosegundos. *(No es un registro, es el inverso de FCY.)*
*   **GPR (General Purpose Registers):** Registros de Propósito General. Zona de la Memoria de Datos (RAM) destinada a las variables que define el programador. *(Memoria de Datos: desde `0x0800` hasta el final de la RAM disponible, compartido con la Pila.)*
*   **SFR (Special Function Registers):** Registros de Funciones Especiales. Registros destinados al control y configuración de los periféricos del microcontrolador. *(Memoria de Datos: ocupan el rango `0x0000` a `0x07FF`, los primeros 2 KB.)*
*   **CORCON (Core Control Register):** Registro de control de 16 bits utilizado para configurar los parámetros fundamentales del núcleo (core) del CPU. Permite configurar la visibilidad de memoria (PSV), modos de saturación DSP y gestionar niveles de prioridad de excepciones (IPL3). *(Memoria de Datos - SFR: `0x0044`)*


### 4. Registros Específicos del dsPIC33 (Puertos e Interrupciones)
Estas son las siglas que usarás directamente en tu código C en MPLAB X.

**Puertos de E/S:**
*   **TRISx:** Registro de dirección de puerto (ej. `TRISB`). Define si un pin es entrada (si el bit es 1) o salida (si es 0). *(Memoria de Datos - SFR: TRISA=`0x02C0`, TRISB=`0x02C6`, TRISD=`0x02D2`)*
*   **PORTx:** Registro de lectura (ej. `PORTB`). Se utiliza para leer el estado físico actual de los pines configurados como entrada. *(Memoria de Datos - SFR: PORTA=`0x02C2`, PORTB=`0x02C8`, PORTD=`0x02D4`)*
*   **LATx:** Registro de salida (ej. `LATB`). Es el "cerrojo" donde se escribe el dato que se quiere enviar hacia los pines físicos. *(Memoria de Datos - SFR: LATA=`0x02C4`, LATB=`0x02CA`, LATD=`0x02D6`)*

**Gestión de Interrupciones:**
*   **ISR (Interrupt Service Routine):** Rutina de Servicio de Interrupción. Es la función en C que se ejecuta automáticamente cuando ocurre un evento de hardware. *(No es un registro; es código que reside en la Memoria de Programa / Flash.)*
*   **IVT (Interrupt Vector Table):** Tabla de Vectores de Interrupción. Mapa de memoria que contiene las direcciones de inicio de todas las ISR. *(Memoria de Programa / Flash: `0x000004` a `0x0000FF`)*
*   **AIVT (Alternate Interrupt Vector Table):** Tabla alternativa de vectores, usada para depuración o protección. *(Memoria de Programa / Flash: `0x000100` a `0x0001FF`)*
*   **IFS (Interrupt Flag Status):** Registro de banderas. Indica mediante un '1' si se ha producido una solicitud de interrupción específica. *(Memoria de Datos - SFR: IFS0=`0x0084`, IFS1=`0x0086`)*
*   **IEC (Interrupt Enable Control):** Registro de habilitación. Permite activar o desactivar cada interrupción de forma individual. *(Memoria de Datos - SFR: IEC0=`0x0094`, IEC1=`0x0096`)*
*   **IPC (Interrupt Priority Control):** Registro de prioridad. Permite asignar a cada interrupción un nivel de importancia del 1 al 7 (3 bits por fuente). *(Memoria de Datos - SFR: IPC0=`0x00A4`, IPC1=`0x00A6`, IPC2=`0x00A8`, IPC3=`0x00AA`)*
*   **INTCON1 / INTCON2:** Registros de control global de interrupciones. Configuran el comportamiento del sistema de excepciones (anidamiento, flancos, uso de AIVT). *(Memoria de Datos - SFR: INTCON1=`0x0080`, INTCON2=`0x0082`)*
*   **RETFIE (Return From Interrupt):** Instrucción en ensamblador de retorno de interrupción. Desapila el PC y el SR desde la Pila (Memoria de Datos) y devuelve el control al programa principal. *(No es un registro; es una instrucción codificada en la Memoria de Programa.)*
*   **DMA (Direct Memory Access):** Acceso Directo a Memoria. Módulo de hardware que mueve datos entre periféricos y RAM sin intervención de la CPU para no quitarle tiempo de procesamiento. *(Los registros de control DMA residen en la Memoria de Datos - SFR.)*
*   **INTx (External Interrupts 0-4):** Fuentes de **interrupción externa** disparadas por pines físicos. El dsPIC33F soporta hasta cinco de estas entradas (INT0 a INT4). *(Los pines físicos se identifican en el Pinout Diagram del Datasheet, páginas 4 a 10.)*
*   **INT1 (External Interrupt 1):** Interrupción externa específica usada frecuentemente para detectar ingresos de datos (ej. en el TP2) mediante un flanco ascendente o descendente configurable.
*   **IPL<3:0> (Interrupt Priority Level):** Campo de 4 bits que define la prioridad actual de la CPU. Los bits **IPL<2:0>** están en el registro **SR** (`0x0042`), y el bit **IPL<3>** está en el registro **CORCON** (`0x0044`). IPL<3> NO es accesible al programador; el hardware lo setea solo ante un TRAP.
*   **NSTDIS (Interrupt Nesting Disable):** Bit en INTCON1 (`0x0080`). Si es '1', prohíbe que una interrupción sea interrumpida por otra de mayor prioridad (desactiva el anidamiento).
*   **ALTIVT (Alternate Interrupt Vector Table):** Bit en INTCON2 (`0x0082`). Permite habilitar el uso de la tabla de vectores alternativa (AIVT) para depuración.



### 5. Temporizadores (Timers)
Términos relacionados con los módulos que miden tiempo en el microcontrolador.

*   **TMRn:** Registro contador del Timer (ej. `TMR1`). Se incrementa en cada pulso de reloj hasta alcanzar el valor de periodo. *(Memoria de Datos - SFR: TMR1=`0x0100`, TMR2=`0x0106`, TMR3=`0x010A`)*
*   **PRn (Period Register):** Registro de periodo (ej. `PR1`). Es el valor límite que fijas; cuando el TMRn lo iguala, ocurre el evento de interrupción. *(Memoria de Datos - SFR: PR1=`0x0102`, PR2=`0x0108`, PR3=`0x010C`)*
*   **TnCON:** Registro de configuración del Timer. Aquí se enciende el módulo (`TON`) y se elige la fuente de reloj. *(Memoria de Datos - SFR: T1CON=`0x0104`, T2CON=`0x0110`, T3CON=`0x0112`)*
*   **TON (Timer On):** Bit 15 dentro de `TnCON`. Al ponerlo en '1' el temporizador comienza a contar; en '0' se detiene.
*   **TCS (Timer Clock Source):** Bit 1 en `TnCON`. Selecciona si el reloj es el ciclo interno FCY (0) o un pulso externo por pin TxCK (1).
*   **TGATE (Timer Gated Accumulation):** Modo que permite al timer contar solo mientras un pin externo se mantenga en nivel alto.
*   **TCKPS (Timer Clock Prescale Select):** Bits 5:4 dentro de `TnCON` que definen el **Prescaler** (divisor de frecuencia) para que el timer cuente más lento. Valores: `00`=1:1, `01`=1:8, `10`=1:64, `11`=1:256.
*   **Prescaler:** Circuito de hardware que divide la frecuencia del reloj principal (FCY) por un factor (1, 8, 64 o 256) antes de que llegue al contador del timer.

**Otros registros periféricos referenciados:**
*   **AD1CON1:** Registro de control del módulo Conversor Analógico-Digital (ADC). *(Memoria de Datos - SFR: `0x0320`)*


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


### 7. Tabla Resumen: Mapa de Registros y Direcciones de Memoria (dsPIC33FJ256GP710)

| Registro | Dirección (Hex) | Tipo de Memoria |
|:---|:---|:---|
| **W0 - W15 (Working Registers)** | `0x0000` a `0x001E` | Memoria de Datos (SFR) |
| **PC (Program Counter)** | — | Registro interno del CPU (24 bits) |
| **SPLIM** | `0x0020` | Memoria de Datos (SFR) |
| **SR (Status Register)** | `0x0042` | Memoria de Datos (SFR) |
| **CORCON** | `0x0044` | Memoria de Datos (SFR) |
| **INTCON1** | `0x0080` | Memoria de Datos (SFR) |
| **INTCON2** | `0x0082` | Memoria de Datos (SFR) |
| **IFS0** | `0x0084` | Memoria de Datos (SFR) |
| **IFS1** | `0x0086` | Memoria de Datos (SFR) |
| **IEC0** | `0x0094` | Memoria de Datos (SFR) |
| **IEC1** | `0x0096` | Memoria de Datos (SFR) |
| **IPC0** | `0x00A4` | Memoria de Datos (SFR) |
| **IPC1** | `0x00A6` | Memoria de Datos (SFR) |
| **IPC2** | `0x00A8` | Memoria de Datos (SFR) |
| **IPC3** | `0x00AA` | Memoria de Datos (SFR) |
| **TMR1** | `0x0100` | Memoria de Datos (SFR) |
| **PR1** | `0x0102` | Memoria de Datos (SFR) |
| **T1CON** | `0x0104` | Memoria de Datos (SFR) |
| **TMR2** | `0x0106` | Memoria de Datos (SFR) |
| **PR2** | `0x0108` | Memoria de Datos (SFR) |
| **TMR3** | `0x010A` | Memoria de Datos (SFR) |
| **PR3** | `0x010C` | Memoria de Datos (SFR) |
| **T2CON** | `0x0110` | Memoria de Datos (SFR) |
| **T3CON** | `0x0112` | Memoria de Datos (SFR) |
| **TRISA** | `0x02C0` | Memoria de Datos (SFR) |
| **PORTA** | `0x02C2` | Memoria de Datos (SFR) |
| **LATA** | `0x02C4` | Memoria de Datos (SFR) |
| **TRISB** | `0x02C6` | Memoria de Datos (SFR) |
| **PORTB** | `0x02C8` | Memoria de Datos (SFR) |
| **LATB** | `0x02CA` | Memoria de Datos (SFR) |
| **TRISD** | `0x02D2` | Memoria de Datos (SFR) |
| **PORTD** | `0x02D4` | Memoria de Datos (SFR) |
| **LATD** | `0x02D6` | Memoria de Datos (SFR) |
| **AD1CON1** | `0x0320` | Memoria de Datos (SFR) |
| **IVT** | `0x000004` a `0x0000FF` | Memoria de Programa (Flash) |
| **AIVT** | `0x000100` a `0x0001FF` | Memoria de Programa (Flash) |
| **Pila (Stack)** | Desde ~`0x0800` | Memoria de Datos (RAM) |
| **GPR (Variables)** | Desde ~`0x0800` | Memoria de Datos (RAM) |

---

### 8. Representación Visual: Mapa de Memoria de Datos (RAM)
Este esquema simula el orden físico de los registros en la memoria RAM (bus de 16 bits). La memoria se divide estrictamente en dos mundos: la zona de Hardware (SFR) y la zona de tu Software (GPR).

| Dirección (Hex) | Contenido / Registro |
| :--- | :--- |
| **--- ZONA SFR ---** | **(Special Function Registers: `0x0000` a `0x07FF`)** - *Controlan el HW* |
| `0x0000` a `0x001E` | **W0 a W15** (Working Registers del núcleo, mapeados como SFR) |
| `0x0020` | **SPLIM** (Límite de la pila) |
| `...` | *Otros registros del núcleo...* |
| `0x0042` | **SR** (Status Register) |
| `0x0044` | **CORCON** (Core Control Register) |
| `...` | *Hueco de memoria...* |
| `0x0080` | **INTCON1** |
| `0x0082` | **INTCON2** |
| `0x0084` | **IFS0** |
| `0x0086` | **IFS1** |
| `...` | *Hueco de memoria...* |
| `0x0094` | **IEC0** |
| `0x0096` | **IEC1** |
| `...` | *Hueco de memoria...* |
| `0x00A4` | **IPC0** |
| `0x00A6` | **IPC1** |
| `0x00A8` | **IPC2** |
| `0x00AA` | **IPC3** |
| `...` | *Hueco de memoria...* |
| `0x0100` | **TMR1** |
| `0x0102` | **PR1** |
| `0x0104` | **T1CON** |
| `0x0106` | **TMR2** |
| `0x0108` | **PR2** |
| `0x010A` | **TMR3** |
| `0x010C` | **PR3** |
| `...` | *Hueco de memoria...* |
| `0x0110` | **T2CON** |
| `0x0112` | **T3CON** |
| `...` | *Hueco de memoria...* |
| `0x02C0` | **TRISA** |
| `0x02C2` | **PORTA** |
| `0x02C4` | **LATA** |
| `0x02C6` | **TRISB** |
| `0x02C8` | **PORTB** |
| `0x02CA` | **LATB** |
| `...` | *Hueco de memoria...* |
| `0x02D2` | **TRISD** |
| `0x02D4` | **PORTD** |
| `0x02D6` | **LATD** |
| `...` | *Hueco de memoria...* |
| `0x0320` | **AD1CON1** |
| `...` | *Resto de los SFRs...* |
| `0x07FF` | *Límite final del bloque SFR de hardware* |
| **--- ZONA GPR ---** | **(General Purpose Registers: `0x0800` en adelante)** - *Memoria libre para tu código* |
| `0x0800` | **Espacio de Usuario** (Ej: Aquí el compilador C guarda `int contador;`) |
| `0x0802` | **Espacio de Usuario** (Ej: Aquí el compilador C guarda `float temperatura;`) |
| `...` | *Más variables C y arreglos/arrays en RAM...* |
| `Dinámico` | **La Pila (Stack)** (Crece hacia arriba según indique la dirección del W15/SP) |
| `Límite RAM` | *Fin de la memoria RAM instalada en tu dsPIC33* |

---

### 9. Representación Visual: Mapa de Memoria de Programa (Flash)
Este esquema simula la memoria Flash no volátil, donde el bus de direcciones usa palabras de 24 bits. Aquí es donde se "quema" permanentemente la lógica de tu código C compilado.

| Dirección (Hex) | Contenido en Flash |
| :--- | :--- |
| **--- VECTORES ---** | **(Gestión de Inicio e Interrupciones)** |
| `0x000000` | **Reset Vector** (La CPU arranca aquí. Ejecuta un `GOTO` hacia tu `main`) |
| `0x000004` a `0x0000FF` | **IVT** (Tabla de Vectores de Interrupción Principal) |
| `0x000100` a `0x0001FF` | **AIVT** (Tabla de Vectores de Interrupción Alternativa) |
| **--- CÓDIGO ---** | **(Espacio de Memoria de Instrucciones)** |
| `0x000200` | **Inicio del Código C** (Aquí empieza a alojarse tu bloque `main()`) |
| `...` | *Líneas de tu código C traducidas a instrucciones Ensamblador...* |
| `Dinámico` | **Funciones ISR** (Ej: Aquí se aloja la función `_T1Interrupt()`) |
| `Dinámico` | **Constantes** (Si defines `const int x = 5`, se guarda aquí, no en la RAM) |
| `Límite Flash` | *Fin de la memoria de programa (Flash) instalada* |