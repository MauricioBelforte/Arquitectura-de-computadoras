# Directivas de Trabajo Conjunto (AI Agent)
**Materia:** Arquitectura de Computadoras (dsPIC33 / MPLAB X)

Este documento centraliza las reglas, flujos de trabajo acordados y el índice de automatización del proyecto. Sirve como "memoria" e instrucciones operativas para mantener el ecosistema de estudio perfectamente estructurado.

## 1. Directivas de Conocimiento y Diccionario
- **Expansión Proactiva:** Cada vez que analicemos un nuevo PDF, Cuestionario o Trabajo Práctico, el Agente debe identificar siglas, bits, o registros nuevos (ej. I2C, SPI, PLL) y **sugerir automáticamente agregarlos** a `Documentacion/Diccionario.md`.
- **Formato Estricto:** Al expandir el diccionario, se debe respetar la catalogación por temas (General, CPU, Timers, Interrupciones) y se deben añadir al final "Ejemplos de Sintaxis C (XC16)" garantizando que se entienda cómo escribirlo en MPLAB.

## 2. Gestión del Repositorio y `.gitignore`
- **Solo Texto y Código:** El repositorio debe mantenerse liviano. Archivos de código (C, H), proyectos comprimidos (`.zip`), scripts (`.py`) y Markdown (`.md`) se suben a Git.
- **Aislamiento de Binarios:** Si el usuario incluye/sube nuevos archivos pesados como **imágenes (`.jpg`, `.png`, `.gif`), audios (`.m4a`), o nuevos manuales crudos (`.pdf`, `.doc`)**, el Agente DEBE agregarlos de inmediato al archivo `.gitignore`.

## 3. Flujo de Lectura y Extracción
- **No leer PDFs grandes al vuelo:** Procesar PDFs directamente durante la conversación es lento y gasta contexto. El protocolo establece que todo PDF nuevo proporcionado por el usuario debe pasarse por nuestras herramientas de Python para crear un `_es.md` local, permanente y textualmente rápido de leer.
- **Legibilidad Garantizada:** Todo texto transcrito desde un PDF debe pasar por un formato estético. No deben quedar "basuras" como pies de página superpuestos, viñetas extrañas o saltos de línea dobles.

## 4. Estándar de Generación de Código C
- **Nunca teoría a medias:** Los manuales técnicos suelen tener fragmentos de código incompletos o mal traducidos por el traductor automático (ej. *nulo __atributo__*).
- **Proyectos Compilables:** Cuando se aborde un tema nuevo (ej. Interrupciones, Timers, UART), el Agente debe crear carpetas independientes con ejemplos `main.c` **funcionales y compilables** que el usuario pueda copiar, pegar y simular con *Stimulus* en MPLAB X, en lugar de darle sólo porciones de código aisladas.

---

## Índice de Herramientas de Python 🛠️
*Ubicación: `/Herramientas_Python/`*

Todos los scripts han sido configurados para ejecutarse sin importar en qué computadora se haya clonado el repositorio (rutas relativas automatizadas).

1. **`fast_extract.py`:** Convierte instantáneamente PDFs que YA están en español a archivos legibles Markdown (`.md`).
2. **`translate_pdf.py`:** Convierte manuales en INGLÉS al español usando Google Translate. *(Cuidado: demora horas en datasheets grandes por la espera entre párrafos para evitar baneos de Google).*
3. **`format_md.py`:** Limpiador estético de Markdown. Arregla viñetas, acomoda los títulos por niveles (`###`), y elimina basura visual del texto extraído.
4. **`fix_code_md.py`:** Escanea los documentos traducidos y re-ensambla la sintaxis rota del C (cambia *nulo __atributo__* por `void __attribute__` y arregla bucles *mientras* por `while`).
