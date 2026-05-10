# Directivas de Trabajo Conjunto (AI Agent)
**Materia:** Arquitectura de Computadoras (dsPIC33 / MPLAB X)

Este documento centraliza las reglas, flujos de trabajo acordados y el índice de automatización del proyecto. Sirve como "memoria" e instrucciones operativas para mantener el ecosistema de estudio perfectamente estructurado.

## 1. Directivas de Conocimiento y Diccionario
- **Expansión Proactiva:** Cada vez que analicemos un nuevo PDF, Cuestionario o Trabajo Práctico, el Agente debe identificar siglas, bits, o registros nuevos (ej. I2C, SPI, PLL) y **sugerir automáticamente agregarlos** a `Documentacion/Diccionario.md`.
- **Formato Estricto:** Al expandir el diccionario, se debe respetar la catalogación por temas (General, CPU, Timers, Interrupciones) y se deben añadir al final "Ejemplos de Sintaxis C (XC16)" garantizando que se entienda cómo escribirlo en MPLAB.

## 2. Gestión del Repositorio y `.gitignore`
- **Solo Texto y Código:** El repositorio debe mantenerse liviano. Archivos de código (C, H), proyectos comprimidos (`.zip`, `.rar`), scripts (`.py`) y Markdown (`.md`) se suben a Git.
- **Aislamiento de Binarios:** Si el usuario incluye/sube nuevos archivos pesados como **imágenes (`.jpg`, `.png`, `.gif`), audios (`.m4a`), o nuevos manuales crudos (`.pdf`, `.doc`)**, el Agente DEBE agregarlos de inmediato al archivo `.gitignore`.

## 3. Flujo de Lectura y Extracción
- **No leer PDFs grandes al vuelo:** Procesar PDFs directamente durante la conversación es lento y gasta contexto. El protocolo establece que todo PDF nuevo proporcionado por el usuario debe pasarse por nuestras herramientas de Python para crear un `_es.md` local, permanente y textualmente rápido de leer.
- **Legibilidad Garantizada:** Todo texto transcrito desde un PDF debe pasar por un formato estético. No deben quedar "basuras" como pies de página superpuestos, viñetas extrañas o saltos de línea dobles.

## 4. Estándar de Generación de Código C
- **Nunca teoría a medias:** Los manuales técnicos suelen tener fragmentos de código incompletos o mal traducidos por el traductor automático (ej. *nulo __atributo__*).
- **Proyectos Compilables:** Cuando se aborde un tema nuevo (ej. Interrupciones, Timers, UART), el Agente debe crear carpetas independientes con ejemplos `main.c` **funcionales y compilables** que el usuario pueda copiar, pegar y simular con *Stimulus* en MPLAB X, en lugar de darle sólo porciones de código aisladas.

## 5. Estándar de Commits en Git
- **Idioma y Tiempo Verbal:** Todos los mensajes de `commit` al realizar un `push` deben escribirse estrictamente en **español**, utilizando un tiempo verbal descriptivo en pasado (pasivo o impersonal). 
- **Ejemplos de formato:** *"Se actualizó la guía de estudio"*, *"Se agregaron comentarios explicativos en el proyectobase2"*, *"Se corrigió el cálculo matemático del Timer"*.

## 6. Metodología de Resolución y Documentación Pedagógica
- **Comentarios "Deep-Dive" en C:** Las soluciones de código deben incluir comentarios extensos en español que desglosen la lógica matemática (ej. frecuencias, prescalers) y el comportamiento físico de los registros (WREGs, IFS, etc.).
- **Generación de Guías Paso a Paso:** Ante ejercicios complejos, el Agente debe crear un documento `Guia_Paso_a_Paso_... .md` independiente que explique la construcción de la solución de forma iterativa y pedagógica.
- **Guías de Preparación para Examen:** Al finalizar un ejercicio práctico, el Agente debe generar un documento `Guia_Examen_... .md` enfocado en la demostración técnica ante el docente. Debe incluir:
    - Pasos de simulación en MPLAB X y configuración de *Stimulus* (pines y valores).
    - Variables críticas para la ventana de *Watches* con valores esperados (Hex/Decimal).
    - Uso del *Stopwatch* para validación de tiempos y frecuencias.
    - Sección de "Preguntas Trampa" con respuestas justificadas sobre hardware y lógica.
- **Rigor Técnico Obligatorio:** Queda prohibido el uso de analogías coloquiales (ej. oficinas, escritorios, pizzerías) en las Guías y Documentación. Se debe utilizar terminología estricta de hardware y arquitectura de computadoras: Puntero de Pila (SP / WREG15), Program Counter (PC), registros de trabajo (WREG0...WREG14), memoria RAM de datos, aritmética de punteros y marcos de interrupción. Siempre que se mencione un componente, se debe incluir su sigla o registro correspondiente entre paréntesis para mayor claridad técnica.
- **Precisión Arquitectónica y Desglose de Hardware:** Toda documentación debe diferenciar explícitamente entre acciones realizadas por el **Hardware** (automáticas de la CPU) y acciones por **Software** (nuestro código). Los ejemplos deben utilizar mapas de memoria realistas, respetando la Arquitectura Harvard y utilizando direcciones físicas hexadecimales coherentes con el mapa de memoria del dsPIC (ej. variables globales en direcciones bajas `0x0800`, Stack en direcciones altas).
- **Saneamiento de Codificación:** Si un archivo presenta caracteres rotos por codificación antigua, el Agente debe recrearlo en formato UTF-8 para garantizar la integridad visual del estudio.

## 7. Estándar de Estructura de Proyecto y Nomenclatura
- **Idioma Mandatorio:** Todo documento generado por el Agente (resúmenes, guías, explicaciones) debe escribirse en **español** y utilizar términos técnicos precisos. Queda prohibido el uso de nombres de archivos en inglés para material de estudio propio.
- **Estructura Raíz:**
    - `MANUALES/`: Carpeta central para documentación de referencia general (Datasheets, Manuales de Referencia de Microchip, Audios y archivos pesados).
- **Estructura por Práctica (`PRACTICA X/`):**
    - `ENUNCIADO/`: Contiene la consigna original (PDF) y su traducción.
    - `Documentacion/`:
        - `Manuales/`: Datasheets y Manuales de Referencia técnicos de Microchip.
        - `Diapositivas/`: Apuntes, presentaciones y material teórico de la cátedra.
    - `GUIA DE ESTUDIO GEMINI/`: Carpeta exclusiva para el material de estudio generado (Resumen, Guía Paso a Paso, Guía de Examen).
    - `Entrega/`: Versiones finales, aprobadas y compilables del código.
    - `Obsoletos/`: Borradores, capturas de WhatsApp y archivos descartados.
    - `Originales/`: Proyectos base (.zip) y archivos fuente originales de la cátedra.

## 8. Protocolo de Navegación y Búsqueda (Para el Agente)
Para garantizar la continuidad entre sesiones, el Agente debe seguir este orden de búsqueda:
1.  **Fechas y Plazos:** Consultar siempre `CRONOGRAMA_RESUMEN.md` en la raíz.
2.  **Teoría y Conceptos:** 
    - Diccionario técnico: `Documentacion/Diccionario.md`.
    - Clases: `CLASES TEORICAS/` (resúmenes) y `CLASES TEORICAS/Originales_PDF/`.
3.  **Desarrollo de Prácticas:**
    - Consigna: `PRACTICA X/ENUNCIADO/`.
    - Guías de estudio: `PRACTICA X/GUIA DE ESTUDIO GEMINI/`.
    - Código final: `PRACTICA X/Entrega/`.
4.  **Documentación Oficial:** `MANUALES/PDFs/` para datasheets y manuales de referencia.

---

## Índice de Herramientas de Python 🛠️
*Ubicación: `/Herramientas_Python/`*

Todos los scripts han sido configurados para ejecutarse sin importar en qué computadora se haya clonado el repositorio (rutas relativas automatizadas).

1. **`fast_extract.py`:** Convierte instantáneamente PDFs que YA están en español a archivos legibles Markdown (`.md`).
2. **`translate_pdf.py`:** Convierte manuales en INGLÉS al español usando Google Translate. *(Cuidado: demora horas en datasheets grandes por la espera entre párrafos para evitar baneos de Google).*
3. **`format_md.py`:** Limpiador estético de Markdown. Arregla viñetas, acomoda los títulos por niveles (`###`), y elimina basura visual del texto extraído.
4. **`fix_code_md.py`:** Escanea los documentos traducidos y re-ensambla la sintaxis rota del C (cambia *nulo __atributo__* por `void __attribute__` y arregla bucles *mientras* por `while`).
5. **`leer_pdf_consola.py`:** Lector rápido para visualizar contenido de PDFs directamente en la consola sin generar archivos.
