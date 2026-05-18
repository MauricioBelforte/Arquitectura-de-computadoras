Aquí tienes la transcripción detallada de ambas páginas del primer cuestionario en formato Markdown, incluyendo el estado de las respuestas y el material de contexto.

---

# ARQUITECTURA DE COMPUTADORAS

**DIT - UNPSJB - Facultad de Ingeniería** **CUESTIONARIO N° 1** (31/03/2026)

**Alumno/a:** Belfiore Mauricio

**Estado:** Aprobado (95)

**Temas:** RISC Microchip. Manejo de instrucciones y memoria. Polling.

---

## PÁGINA 1

### 1. Sobre la asignación de memoria y registros (Seleccione la/s correcta/s):

* **[X] A) Una variable global inicializada `int contador = 5;` se almacena físicamente en la Memoria de Programa (MP) porque su valor no debe perderse.** *(Marcada por el alumno, corregida como incorrecta con una $\times$)*
* **[X] B) Si el Puntero de Pila (Stack Pointer - WREG15) apunta a `0x0850`, se encuentra operando en el rango de la Memoria de Datos (RAM).** *(Marcada como correcta con un visto $\checkmark$)*
* **[ ] C)** El registro `WREG7` tiene una dirección de memoria superior a la de `PORTA`.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 2. Configuración de Puertos y Polling (Seleccione la/s correcta/s):

Se desea leer un pulsador en **RB5** y, si está presionado (nivel alto), encender un LED en **RA2**.

* **[X] A) La configuración inicial correcta es `TRISB = 0x0020; TRISA = 0xFFFB;`.** *(Marcada como correcta con un visto $\checkmark$)*
* **[ ] B)** Para leer el estado del pulsador de forma segura en un sistema de polling, se debe consultar el registro `TRISBbits.TRISB5`.
* **[ ] C)** La sentencia `PORTA = PORTB;` configurará el LED de RA2 correctamente sin afectar otros pines de PORTA, siempre que RB5 sea la única entrada.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 3. Estructuras y Uniones para IPC1 (Seleccione la/s correcta/s):

Dado el siguiente código para configurar el registro **IPC1**:

```c
typedef struct {
    unsigned :4;        // Campo A
    unsigned IC2IP:3;   // Campo B
    unsigned :1;        // Campo C
    unsigned OC2IP:3;   // Campo D
} PRIORIDADES;

```

* **[X] A) El "Campo A" (offset de 4 bits) es correcto para alinear el inicio de `IC2IP` con el bit 4 del registro físico.** *(Marcada como correcta con un visto $\checkmark$)*
* **[X] B) El "Campo C" permite que el siguiente miembro (`OC2IP`) comience en el bit 8, saltando el bit no implementado (U-0).** *(Marcada como correcta con un visto $\checkmark$)*
* **[ ] C)** Si definimos una `union` con esta estructura y un `unsigned int Val`, al hacer `union.Val = 0xFFFF`, estamos poniendo todas las prioridades en nivel 0.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 4. Lógica de ejecución (Pregunta de razonamiento):

En un esquema de polling de 3 bloques (Lectura -> Lógica -> Escritura), si un sensor cambia de estado mientras el microcontrolador está ejecutando el bloque de "Escritura":

* **[ ] A)** El cambio se pierde definitivamente si no se usan interrupciones.
* **[X] B) El cambio será procesado en la siguiente iteración del bucle `while(1)`.** *(Marcada como correcta con un visto $\checkmark$)*

*(Continúa en la página 2)* *C1 - Año 2026 | Página 1 de 2*

---

## PÁGINA 2

* **[ ] C)** El sistema se bloquea porque el bloque de "Escritura" solo puede enviar datos, no recibir cambios.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

## MATERIAL DE CONTEXTO (Para uso durante el examen)

### REGISTER 7-16: IPC1: INTERRUPT PRIORITY CONTROL REGISTER 1

| U-0 | R/W-1 | R/W-0 | R/W-0 | U-0 | R/W-1 | R/W-0 | R/W-0 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| — |  | T2IP<2:0> |  | — |  | OC2IP<2:0> |  |
| **bit 15** |  |  |  |  |  |  | **bit 8** |

| U-0 | R/W-1 | R/W-0 | R/W-0 | U-0 | R/W-1 | R/W-0 | R/W-0 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| — |  | IC2IP<2:0> |  | — |  | DMA0IP<2:0> |  |
| **bit 7** |  |  |  |  |  |  | **bit 0** |

> **Legend:**
> * `R = Readable bit` | `W = Writable bit` | `U = Unimplemented bit, read as '0'`
> * `-n = Value at POR` | `'1' = Bit is set` | `'0' = Bit is cleared` | `x = Bit is unknown`
> 
> 

* **bit 15:** `Unimplemented: Read as '0'`
* **bit 14-12:** `T2IP<2:0>: Timer2 Interrupt Priority bits`
* `111 = Interrupt is priority 7 (highest priority interrupt)`
* `...`
* `001 = Interrupt is priority 1`
* `000 = Interrupt source is disabled`


* **bit 11:** `Unimplemented: Read as '0'`
* **bit 10-8:** `OC2IP<2:0>: Output Compare Channel 2 Interrupt Priority bits`
* `111 = Interrupt is priority 7 (highest priority interrupt)`
* `...`
* `001 = Interrupt is priority 1`
* `000 = Interrupt source is disabled`


* **bit 7:** `Unimplemented: Read as '0'`
* **bit 6-4:** `IC2IP<2:0>: Input Capture Channel 2 Interrupt Priority bits`
* `111 = Interrupt is priority 7 (highest priority interrupt)`
* `...`
* `001 = Interrupt is priority 1`
* `000 = Interrupt source is disabled`


* **bit 3:** `Unimplemented: Read as '0'`
* **bit 2-0:** `DMA0IP<2:0>: DMA Channel 0 Data Transfer Complete Interrupt Priority bits`
* `111 = Interrupt is priority 7 (highest priority interrupt)`
* `...`
* `001 = Interrupt is priority 1`
* `000 = Interrupt source is disabled`



---

### TABLE 4-1: CPU CORE REGISTERS MAP

| SFR Name | SFR Addr | Bits 15 - 0 | All Resets |
| --- | --- | --- | --- |
| WREG0 | 0000 | Working Register 0 | 0000 |
| WREG1 | 0002 | Working Register 1 | 0000 |
| WREG2 | 0004 | Working Register 2 | 0000 |
| WREG3 | 0006 | Working Register 3 | 0000 |
| WREG4 | 0008 | Working Register 4 | 0000 |
| WREG5 | 000A | Working Register 5 | 0000 |
| WREG6 | 000C | Working Register 6 | 0000 |
| WREG7 | 000E | Working Register 7 | 0000 |
| WREG8 | 0010 | Working Register 8 | 0000 |
| WREG9 | 0012 | Working Register 9 | 0000 |
| WREG10 | 0014 | Working Register 10 | 0000 |
| WREG11 | 0016 | Working Register 11 | 0000 |
| WREG12 | 0018 | Working Register 12 | 0000 |
| WREG13 | 001A | Working Register 13 | 0000 |
| WREG14 | 001C | Working Register 14 | 0000 |
| WREG15 | 001E | Working Register 15 | 0800 |

---

### TABLE 4-25: PORTA REGISTER MAP(1)

| File Name | Addr | Bit 15 | Bit 14 | Bit 13 | Bit 12 | Bit 11 | Bit 10 | Bit 9 | Bit 8 | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 | All Resets |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| TRISA | 02C0 | TRISA15 | TRISA14 | TRISA13 | TRISA12 | — | TRISA10 | TRISA9 | — | TRISA7 | TRISA6 | TRISA5 | TRISA4 | TRISA3 | TRISA2 | TRISA1 | TRISA0 | F6FF |
| PORTA | 02C2 | RA15 | RA14 | RA13 | RA12 | — | RA10 | RA9 | — | RA7 | RA6 | RA5 | RA4 | RA3 | RA2 | RA1 | RA0 | xxxx |
| LATA | 02C4 | LATA15 | LATA14 | LATA13 | LATA12 | — | LATA10 | LATA9 | — | LATA7 | LATA6 | LATA5 | LATA4 | LATA3 | LATA2 | LATA1 | LATA0 | xxxx |
| ODCA(2) | 02C6 | ODCA15 | ODCA14 | — | — | — | — | — | — | ODCA7 | ODCA6 | ODCA5 | ODCA4 | ODCA3 | ODCA2 | ODCA1 | ODCA0 | 0000 |

---

### TABLE 4-26: PORTB REGISTER MAP(1)

| File Name | Addr | Bit 15 | Bit 14 | Bit 13 | Bit 12 | Bit 11 | Bit 10 | Bit 9 | Bit 8 | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 | All Resets |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| TRISB | 02C8 | TRISB15 | TRISB14 | TRISB13 | TRISB12 | TRISB11 | TRISB10 | TRISB9 | TRISB8 | TRISB7 | TRISB6 | TRISB5 | TRISB4 | TRISB3 | TRISB2 | TRISB1 | TRISB0 | FFFF |
| PORTB | 02CA | RB15 | RB14 | RB13 | RB12 | RB11 | RB10 | RB9 | RB8 | RB7 | RB6 | RB5 | RB4 | RB3 | RB2 | RB1 | RB0 | xxxx |
| LATB | 02CC | LATB15 | LATB14 | LATB13 | LATB12 | LATB11 | LATB10 | LATB9 | LATB8 | LATB7 | LATB6 | LATB5 | LATB4 | LATB3 | LATB2 | LATB1 | LATB0 | xxxx |

---

*C1 - Año 2026 | UNPSJB - Facultad de Ingeniería | Página 2 de 2*