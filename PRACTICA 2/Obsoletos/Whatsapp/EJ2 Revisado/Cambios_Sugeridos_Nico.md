# 📝 Cambios sugeridos para la versión de Nico (Multitask)

Hola Nico, estuve revisando el código del Ejercicio 2. La lógica del `switch-case` y el uso del puntero para el intercambio de memoria está perfecta, es tal cual lo pidió el profe en la pizarra. 

Para que el programa no tire errores en el simulador y sea 100% robusto, implementé estos ajustes técnicos:

### 1. Resguardo de Registros (W0 - W14)
*   **Cambio:** Agregué dos macros (`GUARDAR_REGISTROS` y `RESTAURAR_REGISTROS`) en la interrupción del Timer.
*   **Por qué:** El compilador de C usa los mismos registros para todos los procesos. Si no los guardamos en el stack justo antes del cambio, el Proceso B podría pisar los resultados del Proceso A. Con esto nos aseguramos de que cada uno mantenga sus variables intactas.

### 2. Ajuste de Tamaño del Buffer (TOPE_ARREGLOS)
*   **Cambio:** Subí el tamaño de los arreglos de 13 a **38**.
*   **Por qué:** Para guardar todo el estado (PC, SR y los 15 registros W) necesitamos al menos 18 posiciones. Usar 13 nos causaba un "desbordamiento" (el proceso A pisaba la memoria del B). Con 38 tenemos espacio de sobra y es mucho más seguro para el simulador.

### 3. Aritmética de Punteros
*   **Cambio:** Refiné el cálculo del puntero en el planificador: `puntero = (unsigned int*)WREG15; puntero -= DESPLAZAMIENTO;`.
*   **Por qué:** Al decirle al compilador que es un puntero de enteros, él ya sabe que cada salto es de 2 bytes, evitando cualquier confusión de memoria.

### 4. Variables Globales de Dirección
*   **Cambio:** Moví las variables `dirA, dirB, dirC` fuera del `main` para que el Kernel las vea correctamente al linkear.

---
**Conclusión:** Mantuvimos tu estructura de "Copia de Stack" (que es la más difícil y la que quiere el profe), pero le pusimos un motor más fuerte para que no falle. ¡Ya está listo para probar en MPLAB!
