# Guía de Estructura del Repositorio
Este documento define la organización oficial del repositorio para mantener la coherencia entre diferentes máquinas y sesiones de trabajo.

---

## 📂 Jerarquía de Carpetas

### 1. Nivel Raíz (Gestión y Memoria)
*   `AGENTS.md`: Directivas de trabajo, diccionario de siglas y protocolos de automatización. **Lectura obligatoria para cualquier IA.**
*   `CRONOGRAMA_RESUMEN.md`: Seguimiento de fechas críticas de parciales y entregas.
*   `ESTRUCTURA_REPOSITORIO.md`: (Este archivo) Mapa de ubicación de archivos.
*   `Documentacion/`:
    *   `Diccionario.md`: Glosario técnico unificado de la materia.

### 2. Estructura por Práctica (`PRACTICA X/`)
Todas las carpetas de práctica (`PRACTICA 1`, `PRACTICA 2`, `PRACTICA 3`) deben seguir este esquema:

*   `ENUNCIADO/`:
    *   PDF original de la cátedra.
    *   Versión `.md` traducida/transcrita.
*   `Documentacion/`:
    *   `Diapositivas/`: PDFs de presentaciones de clase y sus transcripciones `.md`.
    *   `Manuales/`: Datasheets de periféricos específicos (ADC, DMA, etc.) y versiones `_es.md`.
*   `GUIA DE ESTUDIO GEMINI/`:
    *   `Guia_Teorica_... .md`: Resumen consolidado de conceptos.
    *   `Guia_Paso_a_Paso_... .md`: Tutorial iterativo para resolver los ejercicios.
    *   `Guia_Examen_... .md`: Preparación técnica para la defensa ante el docente.
*   `Entrega/`: Proyectos `.X` de MPLAB finales, limpios y compilables.
*   `Originales/`: Archivos fuente, plantillas o `.zip` provistos por la cátedra.
*   `Obsoletos/`: Versiones descartadas, capturas de pantalla de ayuda y borradores.

### 3. Carpetas Globales de Soporte
*   **`MANUALES/`**: Repositorio central de documentación técnica pesada.
    *   `Audios/`: Grabaciones y notas de voz técnicas.
    *   `PDFs/`: Datasheets originales de Microchip en inglés.
    *   `Programacion_C/`: Guías de sintaxis de C para XC16.
    *   `Traducidos_Referencia/`: Manuales de referencia de Microchip traducidos al español.
*   **`CLASES TEORICAS/`**: Material y apuntes de las clases presenciales/virtuales.
    *   `Originales_PDF/`: Diapositivas y material virgen de la cátedra.
*   **`Cuestionarios/`**: Material de estudio para los exámenes teóricos cortos.
    *   `Cuestionario X/`: Preguntas y respuestas específicas de cada test.
*   **`Herramientas_Python/`**: Scripts de automatización (`translate_pdf.py`, `fix_code_md.py`, etc.).
*   **`scratch/`**: Carpeta de trabajo temporal para la IA (scripts rápidos de prueba).

---

## ✅ Protocolo de Sincronización
Si al abrir el repositorio en una nueva máquina detectas archivos fuera de lugar:
1. **Mover** los manuales técnicos de periféricos a `PRACTICA X/Documentacion/Manuales/`.
2. **Mover** las diapositivas de clase a `PRACTICA X/Documentacion/Diapositivas/`.
3. **Eliminar** copias duplicadas de archivos `.md` en la raíz de las carpetas de práctica.
4. **Respetar las subcarpetas** de `MANUALES/` para evitar mezclar PDFs con Audios.
5. **Ejecutar `git pull`** para asegurar que las guías generadas por la IA estén actualizadas.
