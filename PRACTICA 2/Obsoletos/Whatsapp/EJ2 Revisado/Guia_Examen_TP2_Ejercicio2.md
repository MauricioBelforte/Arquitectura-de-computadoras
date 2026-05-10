# 🎓 Guía de Examen: Multitarea por Copia de Stack (TP2-Eje2)
**Materia:** Arquitectura de Computadoras | **Micro:** dsPIC33F

## 1. El Concepto a Defender
Este kernel utiliza la técnica de **Stack Swapping** (Intercambio de Memoria). A diferencia de otros métodos, aquí solo hay una pila física y nosotros movemos los datos de los procesos de un lado a otro.

---

## 2. Configuración del Simulador (MPLAB X)

### A. Ventana de WATCHES (Vigilancia)
Para demostrar que el micro "salta" de un proceso a otro, agrega estas variables:
| Variable | Valor Esperado | Qué demuestra |
| :--- | :--- | :--- |
| **`estadoProceso`** | `0, 1, 2` | Muestra qué proceso está "dueño" de la CPU. |
| **`contT1`** | `0` a `1` | El contador de Quantum antes del cambio. |
| **`x` (del Proceso A)** | Aumenta de 2 en 2 | Demuestra que el Proceso A sigue vivo. |
| **`a` (del Proceso B)** | Aumenta de 2 en 2 | Demuestra que el Proceso B sigue vivo. |
| **`WREG15` (SP)** | Valor estable | Muestra que el Stack Pointer físico no cambia radicalmente, solo su contenido. |

### B. Uso del STOPWATCH
*   Pon un breakpoint en `planificador()`.
*   Cada vez que le des a **Continue (F5)**, el cronómetro debería marcar aproximadamente **300 µs** (2 interrupciones de 150µs cada una, ya que el Quantum es 2).

---

## 3. Puntos Clave de la Demostración

1.  **El "Cambiazo":** Muestra el bucle `for` dentro del `switch-case`. Explica que ahí es donde "fotocopiamos" la memoria del proceso que sale y "pegamos" la del proceso que entra.
2.  **Resguardo de Registros:** Si el profesor pregunta por qué usamos `asm volatile`, explica: *"C no tiene una instrucción para guardar los 15 registros de trabajo (W0-W14). Si no los guardamos nosotros en el stack antes de la copia, los procesos se pisarían los datos entre ellos"*.
3.  **Inicialización (`init`):** Explica que en `arregloProcX[0]` guardamos la dirección de la función para que, en el primer cambio de contexto, el `RETFIE` encuentre un lugar a donde saltar.

---

## 4. Preguntas "Trampa" de Examen

**Q: ¿Por qué este método es más lento que usar varios stacks independientes?**
*   **A:** Porque en cada cambio de contexto tenemos que mover físicamente 38 palabras de memoria (dos veces). Es costoso en tiempo de CPU, pero ahorra RAM si los procesos tienen pilas muy profundas.

**Q: ¿Qué pasaría si `TOPE_ARREGLOS` fuera muy chico (ej. 10)?**
*   **A:** Habría un desbordamiento de memoria. El proceso pisaría variables de otros procesos o el sistema tiraría un "Address Error Trap" porque no alcanzaríamos a guardar el PC y el SR correctamente.

**Q: ¿Por qué deshabilitamos las interrupciones en el planificador?**
*   **A:** En este caso no es necesario porque el planificador ya corre DENTRO de una interrupción (Timer 1), y el micro dsPIC no permite que otra interrupción de igual o menor prioridad lo interrumpa.

**Q: ¿De dónde sale el valor de `DESPLAZAMIENTO` (ej. 33) y por qué es tan crítico? (¡PREGUNTA ESTRELLA!)**
*   **A:** El desplazamiento no es un tamaño arbitrario, es la "distancia" en palabras desde donde está el Stack Pointer (`W15`) dentro de la función `planificador` hasta donde el hardware guardó el Program Counter (PC) al momento de la interrupción. Como nosotros guardamos 15 palabras extra (`W0-W14`), el W15 sube. Si calculamos mal el desplazamiento, al hacer la copia, la variable `dirB` (que pusimos en `arreglo[0]`) no quedará alineada con la posición donde `RETFIE` buscará el PC. El micro leerá basura y colapsará (Address Error Trap).
