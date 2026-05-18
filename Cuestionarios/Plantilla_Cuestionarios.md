# PLANTILLA PARA GENERACIÓN DE CUESTIONARIOS SIMULACROS (A.I. AGENT)
**Estructura y Reglas Estrechas de Formato Pedagógico**

Este documento codifica las especificaciones de diseño y estructura de los cuestionarios simulacro desarrollados por el Agente para la materia de **Arquitectura de Computadoras**. Debe utilizarse de guía exacta para estructurar futuros simulacros (como el Cuestionario N° 4).

---

## 1. Reglas de Organización y Niveles
Cada módulo de estudio o cuestionario debe dividirse en **4 niveles de dificultad incremental**, guardados en archivos Markdown independientes dentro de la subcarpeta `Simulacro Gemini/` del cuestionario correspondiente:

1. **`Cuestionario X - Facil.md`:** Conceptos básicos, catalogación de registros del módulo y distinciones fundamentales pin-registro.
2. **`Cuestionario X - Medio.md`:** Bits de control específicos, fórmulas de temporización matemáticas simples e interrupciones básicas.
3. **`Cuestionario X - Avanzado.md`:** Interacción compleja con otros módulos (ej. DMA con ADC), mapas de memoria de bajo nivel y arquitectura de buses.
4. **`Cuestionario X - Super.md`:** Casos especiales de hardware (modos Sleep, fallas), análisis de ancho de banda, depuración real en simulador, y condiciones de carrera de software.

---

## 2. Formato Estricto de los Archivos Markdown
Cada archivo de nivel debe contener exactamente **10 preguntas** y estructurarse bajo el siguiente patrón de diseño:

### 2.1 Encabezado del Documento
```markdown
# ARQUITECTURA DE COMPUTADORAS
**DIT - UNPSJB - Facultad de Ingeniería**  
**SIMULACRO CUESTIONARIO N° [NÚMERO] — NIVEL: [DIFICULTAD]**  

**Alumno/a:** ________________________  
**Fecha:** ____/____/2026  
**Tema:** [Desglose de los temas específicos del cuestionario]  

---

## PARTE 1: Preguntas para Completar (Vacías)
```

### 2.2 Estructura de las Preguntas Vacías
Para permitir al alumno resolver y practicar, **ninguna opción en la Parte 1 debe estar marcada**. Todas deben usar corchetes vacíos `* [ ]`. Cada pregunta debe ir numerada mediante un título de nivel 3 (`### X.`) y utilizar la escala de opciones hasta la opción `D`.

```markdown
### 1. [Título Breve y Descriptivo] (Seleccione la/s correcta/s):
[Consigna o contexto técnico de la pregunta]
* **[ ] A)** [Opción A]
* **[ ] B)** [Opción B]
* **[ ] C)** [Opción C]
* **[ ] D)** Ninguna de las anteriores es correcta.

---
```
*(Nota: Incluir siempre el separador horizontal `---` después de cada pregunta).*

### 2.3 Estructura de la Clave de Respuestas (Parte 2)
Al final de las 10 preguntas vacías, debe incluirse un separador de doble nivel (`---` seguido de otro `---`) y la sección de respuestas con su desglose técnico y justificación de hardware detallada.

```markdown
---
---

## PARTE 2: Clave de Respuestas y Explicaciones Detalladas

A continuación se presentan las respuestas correctas y el desglose de su justificación teórica y de hardware.

### 1. Respuesta Correcta: [LETRA]
* **Explicación:** [Desglose pedagógico riguroso de por qué es la correcta. Debe citar conceptos físicos de hardware, bits de registros SFR involucrados, fórmulas matemáticas de temporización asociadas si corresponde, y justificar por qué las demás opciones son incorrectas].
```

---

## 3. Pautas Pedagógicas del Contenido (AI Agent)
* **Precisión Arquitectónica:** No utilizar analogías informales. Se debe hablar en términos de ingeniería de hardware (ej: buffers SFR en RAM, multiplexores analógicos, amplificadores de muestreo S/H, decodificadores de bus, dual-port RAM, ciclo de wait de CPU, etc.).
* **Alineación con Hojas de Datos:** Las preguntas deben validar el conocimiento de los registros reales del microcontrolador dsPIC33F (ej: `AD1CON1`, `AD1CON2`, `DMAxCON`, `DMACS1`, etc.) y sus bits específicos.
* **Compatibilidad de Simulación vs Físico:** Incluir preguntas orientadas a la depuración real en MPLAB X, detallando las discrepancias de comportamiento entre simulación por *Register Injection* y el hardware real, lo que le dará al alumno una ventaja clave para el examen teórico-práctico ante el docente.
