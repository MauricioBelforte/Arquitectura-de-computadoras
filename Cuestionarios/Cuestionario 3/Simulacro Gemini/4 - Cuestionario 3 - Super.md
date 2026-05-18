# ARQUITECTURA DE COMPUTADORAS
**DIT - UNPSJB - Facultad de Ingeniería**  
**SIMULACRO CUESTIONARIO N° 3 — NIVEL: SÚPER**  

**Alumno/a:** ________________________  
**Fecha:** ____/____/2026  
**Tema:** Modos Especiales de ADC y DMA, Depuración, y Optimización de Bus en el dsPIC33F.  

---

## PARTE 1: Preguntas para Completar (Vacías)

### 1. Sincronización del Modo Ping-Pong — DMACS1 (Seleccione la/s correcta/s):
Cuando configuramos el DMA en modo Ping-Pong (`MODE = 0b10` o `0b11`), el hardware alterna de forma automática entre el Buffer A (`DMAxSTA`) y el Buffer B (`DMAxSTB`). Si la CPU está procesando los datos de la interrupción y necesita saber con certeza absoluta cuál de los dos buffers está siendo modificado físicamente por el DMA en ese instante:
* **[ ] A)** Se debe leer el bit `PPSTx` (Ping-Pong Status) del registro de control de estado del DMA **`DMACS1`**.
* **[ ] B)** Se debe consultar el registro `AD1CON1` buscando el bit `SAMP`.
* **[ ] C)** Se debe detener el módulo DMA apagando `CHEN = 0` para poder leer los registros de dirección con seguridad.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 2. Muestreo Simultáneo Multicanal y bit ALTS (Seleccione la/s correcta/s):
En modo de 10 bits, el módulo ADC1 puede muestrear de forma simultánea múltiples entradas utilizando sus 4 canales S/H. Si queremos alternar las fuentes físicas analógicas de entrada entre dos conjuntos de sensores en cada conversión secuencial (ejemplo: en una iteración AN2/AN3/AN4/AN5, y en la siguiente AN10/AN11/AN12/AN13):
* **[ ] A)** Debemos utilizar el bit **`ALTS`** del registro `AD1CON2` en `1` para obligar al ADC a alternar la selección de multiplexores analógicos MUX A y MUX B.
* **[ ] B)** Debemos configurar el DMA para que reescriba el registro `AD1CHS0` a través de un canal secundario de salida en tiempo real.
* **[ ] C)** Debemos conectar físicamente cables externos para cortocircuitar los pines en la placa.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 3. Modo de direccionamiento indirecto por periférico (Seleccione la/s correcta/s):
El bit `AMODE<1:0>` de `DMAxCON` permite seleccionar el Direccionamiento Indirecto por Periférico (`AMODE = 0b10`). En este modo de hardware:
* **[ ] A)** El DMA escribe los datos de conversión en direcciones aleatorias de la RAM.
* **[ ] B)** El periférico (como el ADC) proporciona directamente los bits inferiores de la dirección de destino a la RAM, permitiendo al hardware ordenar automáticamente las muestras según el canal de hardware que las generó (modo scatter/gather).
* **[ ] C)** La CPU debe actualizar el registro `DMAxSTA` en cada ciclo de conversión de forma obligatoria por software.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 4. Operación del DMA en modo de bajo consumo (Sleep) (Seleccione la/s correcta/s):
La administración de energía y de consumo es crítica en microcontroladores. Si el dsPIC33F entra en modo **Sleep** mientras el canal de DMA del ADC está activo:
* **[ ] A)** El DMA continuará operando y despertando a la CPU de forma normal porque utiliza un reloj independiente de la CPU.
* **[ ] B)** Si el reloj del sistema de la CPU se detiene en modo Sleep, todas las operaciones de transferencia del DMA se detendrán físicamente debido a la ausencia de reloj del bus, a menos que el periférico solicitante (como el ADC) opere con un oscilador de hardware RC activo e independiente.
* **[ ] C)** El DMA se dañará físicamente por sobrecalentamiento debido al apagado repentino del bus de datos.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 5. Prioridades de arbitraje entre canales DMA (Seleccione la/s correcta/s):
El dsPIC33F posee hasta 8 canales independientes de DMA. Si dos o más canales solicitan simultáneamente una transferencia de bus de datos (por ejemplo, el ADC en canal 0 y la UART en canal 1):
* **[ ] A)** El sistema entra en estado de excepción permanente ("Math Error Trap").
* **[ ] B)** El DMA los procesará de forma secuencial según el modo de arbitraje configurado en `DMACON`: por defecto opera en **prioridad fija** (donde el canal 0 tiene la prioridad más alta y el canal 7 la más baja).
* **[ ] C)** El sistema realiza un sorteo aleatorio por hardware en cada ciclo de colisión de bus.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 6. Rendimiento y límites de ancho de banda del bus de datos (Seleccione la/s correcta/s):
En una aplicación de alta velocidad de adquisición, si configuramos el conversor ADC1 para operar a su velocidad máxima física de 1.1 MSPS (millón de muestras por segundo) a 10 bits con DMA activo:
* **[ ] A)** El bus de datos de la RAM se saturará por completo, bloqueando la ejecución del código de la CPU de forma indefinida.
* **[ ] B)** El DMA requerirá una transferencia cada $\approx 909\text{ ns}$. Si cada ciclo de bus DMA dura $1\ T_{cy} = 25\text{ ns}$ (a 40 MIPS), el DMA solo consumirá aproximadamente un **$2.75\%$** del ancho de banda total del bus de la RAM de datos, permitiendo a la CPU ejecutar su código principal al $97.25\%$ de su velocidad nominal.
* **[ ] C)** El conversor analógico-digital requiere un reloj de $100\text{ GHz}$ para poder sostener esta velocidad de transferencia.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 7. Alineación de memoria para buffers DMA (Seleccione la/s correcta/s):
Debido a las limitaciones físicas de la decodificación de direcciones de hardware del controlador DMA del dsPIC33F, ¿cuál es el requisito de alineación en RAM para los buffers declarados en el espacio DMA?
* **[ ] A)** Los buffers del DMA deben alinearse obligatoriamente en direcciones de memoria impares.
* **[ ] B)** El tamaño del buffer en bytes define el límite de alineación física: un buffer de $N$ palabras ($2N$ bytes) debe comenzar en una dirección física de RAM que sea múltiplo exacto de la potencia de dos inmediatamente superior al tamaño del buffer (alineación de borde de bloque).
* **[ ] C)** No existe ningún tipo de restricción física de alineación; el compilador y el hardware resuelven cualquier dirección sin penalizaciones ni fallas.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 8. Depuración de simuladores mediante Register Injection (Seleccione la/s correcta/s):
Al validar nuestro código en el simulador de MPLAB X utilizando inyección de registros (*Register Injection*) desde un archivo de texto como `ADC1_Values.txt`:
* **[ ] A)** El simulador emula físicamente la tensión eléctrica en los pines analógicos y ejecuta el cálculo de los ciclos TAD de forma exacta.
* **[ ] B)** El simulador escribe de forma directa el valor hexadecimal del archivo de texto en el registro SFR `ADC1BUF0` cada vez que se produce una solicitud de conversión, lo que significa que el dato en el buffer no pasa por el hardware de conversión analógica ni por la codificación de formato del bit `FORM`.
* **[ ] C)** El simulador requiere que conectemos físicamente un potenciómetro al monitor de la computadora para emular el voltaje de entrada.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 9. Lógica de software para evitar condiciones de carrera (Seleccione la/s correcta/s):
En una arquitectura que utiliza DMA en modo continuo (con o sin Ping-Pong) para actualizar un buffer en RAM que la CPU lee de forma periódica en su bucle principal `while(1)`. ¿Cuál es la mejor práctica de programación para garantizar la integridad de los datos?
* **[ ] A)** Utilizar semáforos por software o banderas de sincronización para que la CPU lea únicamente el buffer que está completamente cerrado y libre de escrituras físicas por parte del hardware del DMA.
* **[ ] B)** Realizar lecturas aleatorias del buffer sin importar el estado del DMA, ya que la memoria RAM de doble puerto resuelve colisiones de datos de forma automática devolviendo siempre el promedio matemático de la celda.
* **[ ] C)** Deshabilitar por completo las interrupciones del microcontrolador durante todo el tiempo de ejecución del programa.
* **[ ] D)** Ninguna de las anteriores es correcta.

---

### 10. Configuración scatter/gather con DMA en modo indirecto de periférico (Seleccione la/s correcta/s):
En el dsPIC33F, cuando configuramos el ADC1 en modo de conversión multicanal secuencial con DMA, ¿cómo organiza el hardware los datos resultantes dentro de nuestro arreglo en la memoria RAM?
* **[ ] A)** El hardware escribe todas las muestras mezcladas en una única posición de la RAM de forma aleatoria.
* **[ ] B)** Si se utiliza el modo de direccionamiento indirecto por periférico, el hardware ordenará de forma física las muestras agrupándolas por su número de canal analógico (ej: todas las muestras de AN0 juntas, luego las de AN1 juntas) de forma automática por hardware, en lugar de mezclarlas por orden temporal de conversión.
* **[ ] C)** El conversor analógico-digital requiere el uso de punteros triples de C para poder ubicar las muestras en la RAM de doble puerto.
* **[ ] D)** Ninguna de las anteriores es correcta.

---
---

## PARTE 2: Clave de Respuestas y Explicaciones Detalladas

A continuación se presentan las respuestas correctas y el desglose de su justificación teórica y de hardware.

### 1. Respuesta Correcta: A
* **Explicación:** El registro de estado de canal del DMA **`DMACS1`** contiene bits de estado controlados exclusivamente por hardware:
  * El bit **`PPSTx`** (Ping-Pong Status) de cada canal $x$ indica exactamente cuál es la mitad activa en ese instante: si `PPSTx = 0`, el canal de DMA está direccionando activamente el **Buffer A** (apuntado por `DMAxSTA`). Si `PPSTx = 1`, está escribiendo en el **Buffer B** (`DMAxSTB`).
  * Esta lectura es de solo lectura y permite a la CPU sincronizarse perfectamente para leer los datos del buffer inactivo sin detener el flujo de datos (evitando colisiones o corrupción por sobreescritura de hardware).

### 2. Respuesta Correcta: A
* **Explicación:** El bit **`ALTS`** (Alternate Input Sample Mode Select) del registro `AD1CON2` habilita una red multiplexora analógica doble.
  * Si `ALTS = 0`, el conversor utiliza de forma fija la configuración de pines cargada en el multiplexor principal **MUX A**.
  * Si `ALTS = 1`, el conversor alternará su multiplexación de hardware en cada muestra consecutiva: para una conversión usará la configuración de **MUX A** y para la siguiente usará la de **MUX B** (configurado por `AD1CHS123` y `AD1CHS0` secundarios). Esto permite recolectar muestras de sensores totalmente diferentes en cada fase del timer analógico sin alterar registros por software en tiempo real.

### 3. Respuesta Correcta: B
* **Explicación:** En el modo de direccionamiento indirecto por periférico (`AMODE = 0b10`), se elimina la linealidad de la RAM:
  * El registro `DMAxSTA` define la dirección base del bloque de RAM.
  * El periférico solicitante (como el ADC1) añade directamente un desplazamiento físico (offset) binario al bus de direcciones del DMA basado en el número de canal que acaba de terminar su conversión.
  * Esto permite que las muestras del canal analógico AN2 se depositen físicamente en la celda de memoria `Buffer[2]`, las de AN5 en `Buffer[5]`, etc., sin importar el orden temporal en que hayan sido digitalizadas. El hardware implementa un demultiplexado de memoria instantáneo.

### 4. Respuesta Correcta: B
* **Explicación:** El DMA es un periférico síncrono que depende del reloj principal del bus del microcontrolador ($F_{cy}$):
  * Al ingresar a modo Sleep, la CPU apaga el oscilador principal para ahorrar corriente, lo que congela el bus de datos y detiene el controlador DMA.
  * Sin embargo, si el ADC1 se configura para operar utilizando su propio oscilador RC interno (`ADRC = 1` en `AD1CON3`), el conversor analógico-digital continuará operando y digitalizando voltajes en modo Sleep de forma física.
  * No obstante, la transferencia de datos a la RAM a través del DMA se detendrá temporalmente hasta que se despierte al microcontrolador. Las muestras adicionales se perderán por overrun si no se gestiona el despertar físico mediante interrupciones analógicas directas.

### 5. Respuesta Correcta: B
* **Explicación:** El arbitraje del bus de datos entre múltiples canales de DMA se define por registros:
  * Por defecto, el controlador opera en modo de **prioridad fija**, asignando un peso estricto al número de canal físico. El canal 0 posee prioridad suprema, y el canal 7 la más baja.
  * Si el ADC1 (canal 0) y la UART1 (canal 1) solicitan el bus exactamente en el mismo ciclo, el hardware dará el bus al canal 0, y el canal 1 esperará el ciclo siguiente.
  * Este esquema puede alterarse en el registro de configuración general `DMACON` para operar en modo Round-Robin (prioridad circular rotativa) si se requiere evitar la inanición de periféricos de menor velocidad.

### 6. Respuesta Correcta: B
* **Explicación:** Analicemos la aritmética de bus de datos y tiempos en hardware:
  * A 1.1 MSPS, el ADC1 genera una conversión terminada cada $T_{convert} = \frac{1}{1.1\times 10^6} \approx 909\text{ ns}$.
  * Cada ciclo de bus de datos de la RAM de doble puerto para una palabra de 16 bits del DMA consume exactamente $1\ T_{cy} = 25\text{ ns}$ (a 40 MIPS).
  * Por lo tanto, el porcentaje de tiempo que el bus de la RAM estará ocupado por transferencias de DMA es:
    $$\%\text{ ocupación del bus} = \frac{25\text{ ns}}{909\text{ ns}} \times 100 \approx 2.75\%$$
  * Esto demuestra la altísima eficiencia de la arquitectura DMA: a velocidad máxima, el impacto sobre la velocidad de ejecución de la CPU es prácticamente imperceptible ($<3\%$), mientras que realizar este proceso por software mediante interrupciones saturaría la CPU al $100\%$ bloqueando el sistema.

### 7. Respuesta Correcta: B
* **Explicación:** El controlador DMA del dsPIC33F utiliza decodificadores de dirección simplificados para ahorrar silicio y lograr la máxima velocidad:
  * Por consiguiente, los bloques de memoria asignados al DMA requieren alinearse físicamente en bordes de dirección de memoria múltiplo de su tamaño en bytes (redondeado a la potencia de dos superior).
  * Por ejemplo, un buffer de 16 palabras de 16 bits consume $32\text{ bytes}$. La potencia de dos inmediatamente superior o igual a 32 es $32$ ($2^5$). Así, el compilador alineará la dirección de inicio del buffer en una celda de memoria de RAM física cuyo valor hexadecimal termine en múltiplos de `0x0020` (ej: `0x0800`, `0x0820`, `0x0840`).

### 8. Respuesta Correcta: B
* **Explicación:** Esta es la clave de la discrepancia de simulación:
  * En la inyección de registros en MPLAB X, el simulador no corre el modelo de hardware analógico de aproximación sucesiva. Simplemente toma el dato hexadecimal del archivo de texto (ej. `0x0800`) y lo deposita directamente sobre la celda SFR `ADC1BUF0` mediante una inyección de memoria de simulación.
  * Por ende, si inyectas `0x0800` y configuras el formato en entero signado (`FORM = 0b01`), el simulador NO calculará la conversión con signo; colocará el valor crudo `0x0800` en `ADC1BUF0`, y tu software leerá exactamente `0x0800` en lugar del valor físico corregido que ocurriría en el integrado físico. Esto obliga al programador a escribir condiciones híbridas de compatibilidad para simulación.

### 9. Respuesta Correcta: A
* **Explicación:** Aunque el hardware de doble puerto de la RAM evita la destrucción de datos físicos o cortocircuitos eléctricos en las celdas, no puede evitar la **corrupción lógica o inconsistencia de datos**.
  * Si la CPU lee un arreglo de 6 elementos en el bucle principal mientras el DMA está escribiendo activamente sobre el tercer elemento, la CPU puede leer 2 muestras nuevas y 4 muestras viejas mezcladas.
  * Para evitar esta condición de carrera lógica, se deben implementar mecanismos de exclusión por software (como consultar `PPSTx` en modo Ping-Pong, o deshabilitar temporalmente el canal de DMA durante la copia rápida de datos a un buffer de trabajo del main).

### 10. Respuesta Correcta: B
* **Explicación:** Cuando operamos el canal de DMA en **Modo Indirecto de Periférico** (`AMODE = 0b10`):
  * El conversor analógico-digital ADC1 interactúa con el DMA suministrando el índice de canal físico de hardware en cada muestra convertida.
  * Esto permite que las muestras digitalizadas se ordenen y agrupen automáticamente de forma interna en la RAM por canales físicos (`BufferAN0[x]`, `BufferAN1[x]`, etc.) en lugar de guardarse de manera lineal mezcladas cronológicamente por orden de adquisición temporal. Esto facilita drásticamente la tarea de programación para filtros digitales u operaciones matemáticas específicas de sensores individuales.
