Aquí tienes la transcripción detallada de ambas páginas del cuestionario en formato Markdown. Se han incluido todas las anotaciones manuscritas, fórmulas y marcas de respuestas correctas.

---

# ARQUITECTURA DE COMPUTADORAS

**DIT - UNPSJB - Facultad de Ingeniería** **CUESTIONARIO N° 2** (23/04/2026)

**Alumno/a:** Mauricio Belfiore

**Estado:** Aprobado (100)

---

## PÁGINA 1

### 1. Configuración de Tiempos (Seleccione la/s correcta/s):

Se desea configurar el **Timer1** para que desborde exactamente cada **20 ms**. Dato: $F_{cy} = 40\text{ MHz}$

*Anotaciones manuscritas al margen:*

* $t = t_{cy} \cdot \text{Prescaler} \cdot PRx$
* $t_{cy} = \frac{1}{F_{cy}}$
* $t_{cy} = 0,025\ \mu\text{s}$
* $t = 20\text{ ms}$
* $t = 20000\ \mu\text{s}$
* **[X] A) Utilizando un Prescaler de 1:64, el valor de PR1 debe ser 12500.** *(Marcada como correcta)*
* **[ ] B)** Si se utiliza un Prescaler de 1:8, el valor de **PR1** no excedería los 16 bits del registro.
* **[X] C) Con un Prescaler de 1:256, el valor de PR1 sería 3125.** *(Marcada como correcta)*
* **[ ] D)** Ninguna es correcta.

---

### 2. Jerarquía y Anidamiento (Seleccione la/s correcta/s):

El sistema tiene los siguientes valores: $\text{SR} = \text{0x0060}$, $\text{IPC0} = \text{0x4004}$ (Prioridad $\text{INT0} = 4$ y Prioridad $\text{T1} = 4$).

* **[ ] A)** Si ocurre una interrupción de **Timer1**, el CPU ignora de inmediato porque la prioridad del periférico (4) es igual a la del CPU.
* **[X] B) Si ocurren simultáneamente INT0 y T1, el hardware desempatará a favor de INT0 por tener un vector de interrupción de menor dirección.** *(Marcada como correcta)*
* **[ ] C)** El CPU actualmente ignora cualquier interrupción con prioridad mayor a 3.
* **[ ] D)** Ninguna es correcta.

---

### 3. Lógica dentro de la ISR (Analice el fragmento y seleccione):

```c
void __attribute__((interrupt, auto_psv)) _T1Interrupt(void) {
    PORTBbits.RB0 = !PORTBbits.RB0;
    // Faltan líneas de código aquí
}

```

* **[X] A) Si falta `IFS0bits.T1IF = 0;`, el programa entrará en un bucle infinito re-ejecutando la ISR.** *(Marcada como correcta)*
* **[ ] B)** Es necesario agregar `TMR1 = 0;` manualmente al final de la ISR para que la interrupción por Timer 1 se vuelva a habilitar.
* **[X] C) Si se agrega `IEC0bits.T1IE = 0;` al final, el pin RB0 solo cambiará de estado una única vez.** *(Marcada como correcta)*
* **[ ] D)** Ninguna es correcta.

*Anotaciones manuscritas al pie de página:*


$$PR1 = \frac{t}{t_{cy} \cdot \text{Prescaler}}$$

$$PR1 = \frac{20000}{0,025 \cdot \text{Prescaler}}$$

*(Continúa al dorso!)* *C2 - Año 2026 | Página 1 de 2*

---

## PÁGINA 2

### MATERIAL DE CONTEXTO (Para uso durante el examen)

**Fórmula de Timer:**


$$PR = \frac{\text{Tiempo de espera}}{T_{cy} \cdot \text{Prescaler}} \quad \text{donde } T_{cy} = \frac{1}{F_{cy}}$$

---

### Register 6-15: IPC0: Interrupt Priority Control Register 0

| U-0 | R/W-1 | R/W-0 | R/W-0 | U-0 | R/W-1 | R/W-0 | R/W-0 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| — |  | T1IP<2:0> |  | — |  | OC1IP<2:0> |  |
| **bit 15** | **bit 14** | **bit 13** | **bit 12** |  |  |  | **bit 8** |

| U-0 | R/W-1 | R/W-0 | R/W-0 | U-0 | R/W-1 | R/W-0 | R/W-0 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| — |  | IC1IP<2:0> |  | — |  | INT0IP<2:0> |  |
| **bit 7** |  |  |  |  |  |  | **bit 0** |

> **Legend:**
> * `R = Readable bit` | `W = Writable bit` | `U = Unimplemented bit, read as '0'`
> * `-n = Value at POR` | `'1' = Bit is set` | `'0' = Bit is cleared` | `x = Bit is unknown`
> 
> 

---

### Register 6-1: SR: Status Register (In CPU)

| R-0 | R-0 | R/C-0 | R/C-0 | R-0 | R/C-0 | R-0 | R-0 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| OA | OB | SA | SB | OAB | SAB | DA | DC |
| **bit 15** |  |  |  |  |  |  | **bit 8** |

| R/W-0 | R/W-0 | R/W-0 | R-0 | R/W-0 | R/W-0 | R/W-0 | R/W-0 |
| --- | --- | --- | --- | --- | --- | --- | --- |
|  | IPL<2:0> |  | RA | N | OV | Z | C |
| **bit 7** |  |  |  |  |  |  | **bit 0** |

---

### Table 6-1: Interrupt Vector Details

| IRQ # | IV Address | AIV Address | Interrupt Source |
| --- | --- | --- | --- |
| 0 | 0x000004 | 0x000084 | Reserved |
| 1 | 0x000006 | 0x000086 | Oscillator Failure |
| 2 | 0x000008 | 0x000088 | Address Error |
| 3 | 0x00000A | 0x00008A | Stack Error |
| 4 | 0x00000C | 0x00008C | Math Error |
| 5 | 0x00000E | 0x00008E | DMAC Error |
| 6 | 0x000010 | 0x000091 | Reserved |
| 7 | 0x000012 | 0x000092 | Reserved |
| 8 | 0x000014 | 0x000114 | INT0 – External Interrupt 0 |
| 9 | 0x000016 | 0x000116 | IC1 – Input Compare 1 |
| 10 | 0x000018 | 0x000118 | OC1 – Output Compare 1 |
| 11 | 0x00001A | 0x00011A | T1 – Timer1 |
| 12 | 0x00001C | 0x00011C | DMA0 – DMA Channel 0 |
| 13 | 0x00001E | 0x00011E | IC2 – Input Capture 2 |
| 14 | 0x000020 | 0x000120 | OC2 – Output Compare 2 |
| 15 | 0x000022 | 0x000122 | T2 – Timer2 |
| 16 | 0x000024 | 0x000124 | T3 – Timer3 |
| 17 | 0x000026 | 0x000126 | SPI1E – SPI1 Fault |
| 18 | 0x000028 | 0x000128 | SPI1 – SPI1 Transfer Done |
| 19 | 0x00002A | 0x00012A | U1RX – UART1 Receiver |
| 20 | 0x00002C | 0x00012C | U1TX – UART1 Transmitter |
| 21 | *[Recortado]* | *[Recortado]* | AD1 – ADC1 Convert Done *(Parcialmente visible)* |

---

*C2 - Año 2026 | Página 2 de 2*