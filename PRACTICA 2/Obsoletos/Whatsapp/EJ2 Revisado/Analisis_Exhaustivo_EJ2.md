# 📑 Informe de Análisis Exhaustivo: Ejercicio 2 (Multitask)
**Proyecto analizado:** `TP2-2.X` (Versión Nico) vs `TPNICOMEJORADO` (Versión Ayer)

## 1. Evaluación de la Propuesta de Nico (`TP2-2.X`)

Nico ha implementado correctamente la **estructura lógica** que el profesor solicitó en la pizarra (uso de `switch-case` y puntero para el intercambio de memoria). Sin embargo, la implementación tiene errores de "bajo nivel" que impedirían su funcionamiento real.

### 🔴 Errores Críticos Detectados:

1.  **Omisión del Resguardo de Registros (Contexto):**
    *   **Problema:** La interrupción del Timer (`_T1Interrupt`) solo llama al planificador. No guarda los registros de trabajo (`W0` al `W14`).
    *   **Consecuencia:** Al cambiar de proceso, los valores temporales de las cuentas (como la variable `x` o `y`) se pierden o se corrompen. El programa daría resultados matemáticos basura.

2.  **Inconsistencia de Memoria (Buffer Overflow):**
    *   **Problema:** Nico definió `TOPE_ARREGLOS 13` pero `DESPLAZAMIENTO 18`.
    *   **Consecuencia:** El bucle `for` intenta copiar 18 palabras en un espacio de 13. Esto causa un **desbordamiento de memoria**, lo que significa que el proceso A pisaría los datos del proceso B o incluso variables críticas del sistema, causando un "Address Trap" (reinicio del micro).

3.  **Cálculo de Espacio Insuficiente:**
    *   El contexto mínimo para que el `RETFIE` funcione es de 18 palabras (PC + SR + 15 registros W). Definir 13 posiciones es físicamente imposible para guardar un proceso.

---

## 2. Comparativa Técnica

| Característica | Versión Nico (`TP2-2.X`) | Versión Mejorada (`TPNICOMEJORADO`) | Impacto |
| :--- | :--- | :--- | :--- |
| **Lógica de Cambio** | `switch-case` (Pizarra) | `switch-case` (Pizarra) | Ambas cumplen la consigna. |
| **Resguardo W0-W14** | No tiene | **Sí (mediante `asm volatile`)** | **Crítico** para estabilidad. |
| **Tamaño Arreglos** | 13 (Insuficiente/Peligroso) | **38 (Seguro)** | Evita colisiones de RAM. |
| **Reset de Quantum** | Sí | Sí | Correcto en ambas. |

---

## 3. Propuesta de Unificación (TP2-2REVISADO)

Para que el trabajo sea perfecto, vamos a mantener la **estética de Nico** (que es la que quiere el profesor) pero le inyectaremos el **motor técnico** de ayer.

### Mejoras a implementar:
1.  **Unificar constantes:** Usar `TOPE_ARREGLOS 38` y `DESPLAZAMIENTO 38` para máxima compatibilidad y seguridad.
2.  **Inyectar Macros de Resguardo:** Añadir `GUARDAR_REGISTROS()` y `RESTAURAR_REGISTROS()` en la interrupción.
3.  **Limpiar la Inicialización:** Asegurar que `arregloProc[0]` contenga la dirección de inicio para el primer salto.

---
**Conclusión:** La idea de Nico es buena y está alineada con la clase, pero le faltaban los "cimientos" para que el edificio no se caiga. La versión revisada será la definitiva para entregar.
