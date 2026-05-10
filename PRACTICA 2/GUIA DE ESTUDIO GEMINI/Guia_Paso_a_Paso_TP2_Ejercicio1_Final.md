# Walkthrough: Trabajo Práctico 2 - Ejercicio 1 (Productor / Consumidor)
**Materia:** Arquitectura de Computadoras
**Arquitectura:** dsPIC33F (Arquitectura Harvard)

Este documento detalla el funcionamiento exacto del Ejercicio 1 que fue aprobado y entregado. Combina el análisis narrativo del flujo de datos con un desglose técnico de bajo nivel (mapa de memoria).

---

## 1. Topología del Sistema

El sistema implementa el clásico patrón **Productor-Consumidor** mediante el uso de interrupciones asíncronas de hardware y un despachador síncrono. Consta de tres actores principales que operan sobre la memoria RAM (GPR):

1. **El Productor (`INT1`):** Reacciona asíncronamente ante eventos físicos externos (flanco ascendente). Filtra datos válidos y los introduce en un buffer circular en RAM.
2. **El Temporizador (`Timer1`):** Opera independientemente en segundo plano, sumando "ticks" de tiempo a un contador global (`counterTimer`) a intervalos matemáticamente precisos de 150 µs.
3. **El Consumidor (`main.c`):** Utiliza la CPU en un bucle infinito (`while(1)`) para decidir estratégicamente cuándo procesar la información del buffer, implementando temporización dinámica.

---

## 2. Mapa de Memoria RAM (Data Space)

En la Arquitectura Harvard del dsPIC33F, la memoria RAM de datos (Data Space) está físicamente separada de la Memoria de Programa (Flash). El sistema organiza las estructuras de datos de la siguiente manera:

```text
DIRECCIÓN DE RAM (Hex)      CONTENIDO FÍSICO
================================================================================================
0x0000 - 0x07FF       SFR (Special Function Registers)
                      ► Registros de control del hardware (IFS0, IFS1, T1CON, PR1, PORTB).
                      ► Manipulados para configurar interrupciones y temporizadores.
------------------------------------------------------------------------------------------------
0x0800 - ...          GPR (General Purpose Registers - Globales)
                      ► `buffer[TAM_BUFFER]`: Almacenamiento circular transitorio.
                      ► `logOperaciones[TAM_LOG]`: Destino final en memoria.
                      ► Punteros lógicos: `indBuffer` (Escritura), `indConsum` (Lectura), `indLog`.
                      ► Flags: `caracteresPendientes`, `counterTimer`, `cantFallas`.
------------------------------------------------------------------------------------------------
... - Final RAM       PILA (Stack / WREG15)
                      ► Crece hacia direcciones ascendentes.
                      ► Guarda el Program Counter (PC) y Status Register (SR) cuando
                        se dispara _INT1Interrupt o _T1Interrupt.
================================================================================================
```

---

## 3. Análisis del Código: Paso a Paso

### A. Configuración Base (`config.c`)
El sistema inicia configurando los periféricos.
*   **Timer1:** Se configura con el reloj interno (`TCS = 0`) y Prescaler 1:1 (`TCKPS = 0`). Para lograr una interrupción cada 150 µs (con `Fosc = 40MHz`), el registro `PR1` se carga con el valor `6000` (150 µs / 0.025 µs).
*   **INT1:** Se configura para dispararse con el flanco ascendente en `PORTB` (`INT1EP = 0`). Las prioridades (`IP`) están en nivel 5 para ambos módulos.

### B. El Productor (`_INT1Interrupt`)
Cuando ocurre un flanco en el pin INT1, el hardware salva el PC y el SR en la Pila y ejecuta la ISR.
1.  Baja la bandera de hardware: `IFS1bits.INT1IF = 0;`.
2.  Captura el valor físico en el `PORTB`.
3.  Pasa el valor por una macro de validación `ES_CARACTER_VALIDO(c)`. Si es un número o un símbolo matemático, lo ingresa en el arreglo `buffer` usando el índice `indBuffer`.
4.  Aumenta la variable `caracteresPendientes`.
5.  Avanza y envuelve el índice `indBuffer` a 0 si llega al final (`FIN_DE_BUFFER`).

### C. El Reloj Base (`_T1Interrupt`)
Cada 150 µs el Timer 1 genera una interrupción.
1.  Baja la bandera `IFS0bits.T1IF = 0;`.
2.  Aumenta la variable global `counterTimer++`.

### D. El Cerebro Síncrono (`main.c`)
El bucle principal actúa como despachador.
*   **Temporización Dinámica:** Verifica si `counterTimer > cantFallas`. Si el consumidor ha fallado repetidas veces al buscar datos en el buffer (es decir, el buffer estaba vacío), `cantFallas` incrementa hasta un límite de `MAX_FALLAS`. Esto hace que el despachador espere progresivamente más tiempo antes de volver a revisar (ahorrando tiempo de CPU).
*   **Consumo y Vaciado:** 
    ```c
    if (caracteresPendientes > 0){       
        consumirDatos(caracteresPendientes);
        caracteresPendientes = 0;
        cantFallas = 0;         
    }
    ```
    Si hay al menos un caracter pendiente, llama a `consumirDatos()`, pasándole la cantidad. Luego *resetéa* `caracteresPendientes = 0` y vuelve a establecer el ritmo rápido del despachador (`cantFallas = 0`).
*   **Macro `consumirDatos()`:** Recorre el `buffer` secuencialmente usando `indConsum` y traslada la información a `logOperaciones` usando `indLog`. Una vez ejecutado, la información queda asentada permanentemente.

> [!WARNING]
> **Condición de Carrera en la Entrega Aprobada:** En la línea `caracteresPendientes = 0;` en `main.c`, existe una pequeña ventana de tiempo (unos pocos ciclos de máquina) donde una interrupción de `INT1` podría agregar un nuevo caracter *después* de haber leído la variable, pero *antes* de volverla a cero. Si esto ocurre, se pierde la cuenta de un elemento ingresado. Como esta implementación fue la **aprobada**, se respeta exactamente el código entregado, pero debes tener presente esta justificación arquitectónica por si el docente hace una pregunta trampa (ver Guía de Examen).
