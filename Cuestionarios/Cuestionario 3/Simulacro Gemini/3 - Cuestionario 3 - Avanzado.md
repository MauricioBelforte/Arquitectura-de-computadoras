# ARQUITECTURA DE COMPUTADORAS
**DIT - UNPSJB - Facultad de Ingeniería**  
**SIMULACRO CUESTIONARIO N° 3 — NIVEL: AVANZADO**  

**Alumno/a:** ________________________  
**Fecha:** ____/____/2026  
**Tema:** Módulo DMA (Acceso Directo a Memoria) y su Acoplamiento con el ADC en el dsPIC33F.  

---

## PARTE 1: Preguntas para Completar (Vacías)

### 1. Ventaja fundamental de la arquitectura DMA (Seleccione la/s correcta/s):
El controlador DMA (Direct Memory Access) del dsPIC33F representa una gran mejora arquitectónica sobre el esquema tradicional de interrupciones o polling. ¿Cuál es su principal ventaja física?
* **[ ] A)** Permite al CPU ejecutar código a una frecuencia de reloj superior a 40 MHz.
* **[ ] B)** Permite la transferencia directa de datos entre los periféricos (como el ADC o UART) y la memoria RAM sin intervención de la CPU, liberando a esta para procesar cálculos matemáticos en paralelo.
* **[ ] C)** Elimina la necesidad de utilizar pines físicos de alimentación ($V_{dd}$ y $V_{ss}$) en el integrado.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 2. Configuración de dirección en un canal DMA — DIR (Seleccione la/s correcta/s):
El bit `DIR` del registro de control de canal `DMAxCON` define el sentido de la transferencia. Si configuramos un canal de DMA para operar de forma conjunta con el **ADC1**:
* **[ ] A)** Debemos configurar `DIR = 1` para que el DMA lea desde la RAM y escriba en el conversor.
* **[ ] B)** Debemos configurar `DIR = 0` para que el DMA lea desde el registro buffer del periférico (`ADC1BUF0`) y escriba los datos en la memoria RAM.
* **[ ] C)** El bit `DIR` se ignora por completo ya que el ADC1 es un módulo de solo escritura.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 3. Asociación de un periférico a un canal DMA — IRQSEL (Seleccione la/s correcta/s):
El registro `DMAxREQ` (DMA Channel x Request Register) asocia el canal de DMA a un periférico específico mediante el campo `IRQSEL<6:0>`. Para asociar el canal al fin de conversión del **ADC1**, ¿qué configuración de hardware es requerida?
* **[ ] A)** Cargar `IRQSEL = 13` (valor binario `0b0001101`), que corresponde al vector de interrupción de fin de conversión del ADC1.
* **[ ] B)** Cargar `IRQSEL = 0` para indicar que el DMA debe operar de forma manual e independiente del hardware.
* **[ ] C)** Configurar `IRQSEL = 8` para asociarlo con la interrupción externa INT0 del pulsador físico.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 4. El registro puente periférico — DMAxPAD (Seleccione la/s correcta/s):
El registro `DMAxPAD` define el "buzón" o dirección física del registro de datos del periférico asociado al canal. Si configuramos el canal para leer desde el **ADC1**, ¿cuál es la configuración correcta del registro?
* **[ ] A)** `DMAxPAD = (int)&ADC1BUF0;` (o la dirección hexadecimal `0x0300`).
* **[ ] B)** `DMAxPAD = 0x0800;` para apuntar al primer registro de trabajo de la CPU (WREG0).
* **[ ] C)** Cargar en `DMAxPAD` la dirección física de la variable global de nuestro programa en memoria de programa Flash.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 5. Declaración de buffers en memoria DMA mediante compilador C (Seleccione la/s correcta/s):
El dsPIC33F posee una arquitectura de RAM de doble puerto (Dual-Port RAM). Para que el controlador DMA pueda acceder físicamente a las variables de buffer que definimos en nuestro programa de C (XC16), ¿cómo deben ser declaradas?
* **[ ] A)** `int BufferADC[16] __attribute__((space(auto_psv)));`
* **[ ] B)** `int BufferADC[16] __attribute__((space(dma)));`
* **[ ] C)** `static volatile int BufferADC[16];` sin atributos especiales de compilación.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 6. Configuración de direcciones de inicio en RAM — DMAxSTA/STB (Seleccione la/s correcta/s):
Para indicarle al canal de DMA dónde comienza físicamente nuestro buffer en la RAM, cargamos la dirección en el registro `DMAxSTA` (y opcionalmente `DMAxSTB` si usamos Ping-Pong). ¿Cuál es la sintaxis correcta en C (XC16) para realizar esto de forma segura?
* **[ ] A)** `DMAxSTA = BufferADC;` directamente cargando el puntero en C.
* **[ ] B)** `DMAxSTA = __builtin_dmaoffset(BufferADC);` utilizando una función intrínseca del compilador para obtener el desplazamiento físico dentro del espacio DMA.
* **[ ] C)** `DMAxSTA = (int)&BufferADC[15];` apuntando al último elemento del arreglo en RAM.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 7. Cantidad de transferencias — DMAxCNT (Seleccione la/s correcta/s):
El registro de control de conteo de transferencias `DMAxCNT` define el tamaño del bloque de datos que el DMA moverá antes de generar una interrupción de CPU. Si queremos recolectar un bloque completo de exactamente **6 muestras** consecutivas del ADC:
* **[ ] A)** Debemos cargar `DMAxCNT = 6;` en el registro.
* **[ ] B)** Debemos cargar `DMAxCNT = 5;` (el número de transferencias deseadas menos 1).
* **[ ] C)** Debemos cargar `DMAxCNT = 0;` para que la transferencia se repita infinitamente.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 8. Modos de direccionamiento DMA (Seleccione la/s correcta/s):
El bit `AMODE<1:0>` del registro `DMAxCON` define el modo de direccionamiento que usa el DMA sobre la memoria RAM de datos. Si configuramos `AMODE = 0b00` (Direccionamiento Indirecto por Registro con Post-Incremento):
* **[ ] A)** El DMA escribirá cada nuevo dato del conversor en la misma dirección de RAM física de forma fija, sobreescribiendo el valor previo.
* **[ ] B)** El DMA escribirá el primer dato en la dirección apuntada por `DMAxSTA` y, de forma automática por hardware, incrementará el puntero interno en 2 bytes para escribir la siguiente muestra en la dirección de memoria contigua.
* **[ ] C)** El DMA requerirá que el software incremente manualmente un puntero de la CPU en cada fin de ciclo de muestreo.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 9. Colisiones de bus y arbitraje de hardware (Seleccione la/s correcta/s):
Dado que el DMA y la CPU comparten el bus de datos interno para acceder a la memoria de datos (RAM), ¿qué ocurre por hardware cuando la CPU y el DMA intentan leer o escribir en la misma dirección de RAM física de forma simultánea (colisión de bus)?
* **[ ] A)** El microcontrolador entra en falla física ("Address Error Trap") y se reinicia por hardware.
* **[ ] B)** El hardware del bus arbitra dando prioridad absoluta al DMA; la CPU se detiene momentáneamente durante un único ciclo de instrucción ($1\ T_{cy}$), permitiendo al DMA transferir su palabra sin pérdida de datos.
* **[ ] C)** El bus se bloquea permanentemente hasta que un desborde del temporizador Watchdog (WDT) reinicie el integrado.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 10. Bandera e interrupción de fin de transferencia DMA (Seleccione la/s correcta/s):
La bandera de interrupción de un canal de DMA (por ejemplo, `DMA0IF` para el canal 0) es un recurso clave en la programación. ¿Cuándo se activa esta bandera por hardware?
* **[ ] A)** Cada vez que se realiza una única transferencia individual de palabra del ADC a la RAM.
* **[ ] B)** Cuando el canal de DMA completa la transferencia de todo el bloque de datos especificado en `DMAxCNT` (es decir, el contador interno llega a cero).
* **[ ] C)** Solo cuando la memoria RAM se daña o se desconecta de la CPU.
* **[ ] D)** Ninguna de las anteriores es correcta.

---
---

## PARTE 2: Clave de Respuestas y Explicaciones Detalladas

A continuación se presentan las respuestas correctas y el desglose de su justificación teórica y de hardware.

### 1. Respuesta Correcta: B
* **Explicación:** La gran revolución de la arquitectura con controlador DMA en microcontroladores es la **independencia de bus**. 
  * En sistemas sin DMA, la CPU debe detener sus cálculos matemáticos principales, saltar a una ISR de interrupción, gastar ciclos de instrucción salvando el contexto, leer el registro de datos `ADC1BUF0` y escribirlo en una variable de RAM.
  * El DMA se encarga de realizar este traslado de datos de forma **totalmente automatizada por hardware**, utilizando canales dedicados y compartiendo el bus de datos en paralelo a la CPU. La CPU solo es interrumpida cuando el buffer de memoria RAM está completamente lleno y listo para procesar.

### 2. Respuesta Correcta: B
* **Explicación:** El registro `DMAxCON` configura la dirección física del flujo de datos en el bit `DIR` (Direction):
  * `DIR = 0` configura el canal para **lectura desde el periférico** y escritura en la memoria de datos RAM. Este es el modo obligatorio para módulos de entrada como el ADC o el receptor UART (Rx).
  * `DIR = 1` configura el canal para lectura de RAM y **escritura en el periférico**. Se utiliza para módulos de salida como el transmisor UART (Tx), el comparador de salida (OC/PWM) o un DAC.

### 3. Respuesta Correcta: A
* **Explicación:** Para que el DMA actúe de forma síncrona con el periférico, debe responder a su solicitud física de transferencia. Cada periférico tiene asignado un número de canal de interrupción interna (IRQ). En el dsPIC33F, la solicitud del fin de conversión del **ADC1** se asocia de forma fija al código de solicitud **13** (`IRQSEL = 13` o `0x0D`). Al configurarlo, el DMA transferirá un dato desde `ADC1BUF0` a la RAM cada vez que el ADC encienda el bit `DONE`.

### 4. Respuesta Correcta: A
* **Explicación:** El registro `DMAxPAD` (DMA Channel x Peripheral Address Register) le indica al canal de DMA la dirección física de la celda de memoria SFR asignada a ese periférico.
  * Para el ADC1, el registro donde el hardware del conversor almacena la muestra convertida es `ADC1BUF0`.
  * La dirección de memoria SFR física de `ADC1BUF0` en el mapa de registros del dsPIC33F es la dirección **`0x0300`**.
  * En C (compilador XC16), es altamente recomendable escribirlo usando la sintaxis `DMAxPAD = (int)&ADC1BUF0;` para que el compilador resuelva automáticamente la dirección física del registro.

### 5. Respuesta Correcta: B
* **Explicación:** Arquitectónicamente, el controlador DMA del dsPIC33F solo puede acceder a una región dedicada de la RAM llamada **Dual-Port RAM** (RAM de doble puerto), la cual posee dos interfaces de bus independientes (una para la CPU y otra para el DMA). Para obligar al enlazador (linker) del compilador a ubicar nuestro arreglo de variables en este rango físico específico de la RAM, debemos indicarle la directiva de atributo de sección especial: `__attribute__((space(dma)))`. De lo contrario, se guardará en la RAM convencional y el DMA no podrá acceder a ella, provocando fallas o lecturas vacías.

### 6. Respuesta Correcta: B
* **Explicación:** Dado que la memoria RAM está dividida internamente, el controlador DMA no requiere la dirección física absoluta de 16 bits de la CPU para apuntar al buffer. Requiere el **desplazamiento de memoria o desplazamiento (offset)** relativo al inicio de la memoria del espacio DMA. Para obtener este valor de forma segura y portable ante cambios de compilación, el compilador XC16 provee la función intrínseca de ensamblador: `__builtin_dmaoffset(NombreBuffer);`. Escribir la dirección directa (opción **A**) generaría un puntero inválido para el hardware del DMA.

### 7. Respuesta Correcta: B
* **Explicación:** El registro de conteo de transferencias `DMAxCNT` (DMA Channel x Transfer Count Register) opera bajo la regla de hardware de **N - 1**.
  * El conversor realiza transferencias desde `0` hasta el valor cargado en `DMAxCNT`.
  * Por consiguiente, si queremos realizar exactamente $6$ transferencias de datos analógicos, debemos programar el registro con el valor **`5`** ($6 - 1 = 5$).
  * Si pusiéramos `6` (opción **A**), el DMA realizaría $7$ transferencias antes de interrumpir a la CPU, lo que desbordaría un arreglo declarado con tamaño 6.

### 8. Respuesta Correcta: B
* **Explicación:** El modo de direccionamiento indirecto con post-incremento (`AMODE = 0b00`) es el más común para buffers analógicos continuos.
  * El primer dato se guarda en la dirección base configurada en `DMAxSTA`.
  * Inmediatamente después, el hardware de control de direccionamiento del DMA suma 2 bytes al puntero de dirección (2 bytes porque cada muestra del ADC es una palabra de 16 bits).
  * La siguiente conversión se escribirá de forma automática en la dirección contigua de memoria RAM. Esto se repite secuencialmente hasta completar el bloque de transferencia sin gastar una sola línea de código de software.

### 9. Respuesta Correcta: B
* **Explicación:** El dsPIC33F implementa un mecanismo físico de arbitraje de bus llamado **ciclo de robo de reloj ("Cycle Stealing")**.
  * Si el DMA y la CPU entran en colisión sobre la misma celda de memoria RAM, el bus del sistema da prioridad absoluta al canal de DMA por hardware.
  * Esto se realiza insertando un **ciclo de wait** en la CPU: la CPU se congela físicamente por exactamente un ciclo de instrucción ($1\ T_{cy}$ o $25\text{ ns}$ a 40 MIPS), permitiendo al DMA transferir la muestra.
  * Este robo de ciclo es transparente al software y asegura que jamás se pierda una muestra crítica del periférico en tiempo real.

### 10. Respuesta Correcta: B
* **Explicación:** La bandera de interrupción de canal del DMA (`DMAxIF`) no se activa con cada muestra transferida de forma individual (opción **A**). Se activa exclusivamente cuando el contador de hardware interno del canal (inicializado con `DMAxCNT`) llega a cero, indicando al sistema que **se ha completado con éxito la transferencia de todo el bloque de datos** en la RAM. En ese momento, la CPU salta a la ISR de interrupción del canal de DMA correspondiente para procesar la información acumulada en el buffer.
