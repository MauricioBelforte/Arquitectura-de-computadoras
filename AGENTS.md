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
- **Rigor Técnico y Resumen de Roles:** Al abordar periféricos complejos (ADC, DMA, UART), se debe incluir un bloque de "Resumen de Roles" que asigne una función conceptual clara a cada registro para facilitar la comprensión de la jerarquía de control. Se prohíbe el uso de analogías coloquiales ajenas a la ingeniería; se deben usar roles funcionales (ej. "Selector de Canal", "Activador", "Buzón de Resultados").
- **Formato Estricto de Registros y Bits:** Al desglosar la configuración de un registro, se DEBE usar siempre un subtítulo específico con el formato `### X.Y Bits Clave de [NOMBRE_REGISTRO] (Detalle y Sintaxis C)`. **Queda terminantemente prohibido agrupar múltiples registros en un solo título** (ej. no agrupar `TRIS`, `PORT` y `LAT`). Cada registro debe tener su propia sección `###` independiente. Debajo de ese título, se debe construir una lista con viñetas donde cada ítem principal sea el nombre del bit o campo de bits, **indicando obligatoriamente su posición/número de bit entre paréntesis** (ej. `**ADON** (bit 15): Control de...`), y sus sub-ítems sean TODAS las combinaciones posibles escritas en código C explícito (ej: `AD1CON1bits.ADON = 1;`), explicando la acción física que disparan.
- **Representación de Registros de 16-bits (Patrones Repetitivos):** Cuando un registro controle 16 pines idénticos (ej. `TRISx`, `PORTx`, `AD1PCFGL`), **no se debe mostrar solo el bit 0 como ejemplo**. Se deben listar secuencialmente los primeros bits (0, 1, 2, 3), luego incluir puntos suspensivos verticales y una aclaración del rango omitido (ej. `... (los bits del 4 al 14)`), y finalmente el último bit (15) para mostrar la escala completa del registro visualmente.
- **Distinción Pin vs. Registro:** Se debe diferenciar explícitamente entre los componentes físicos (Pines externos como `ANx`, `INTx`) y los registros de control interno. Se debe aclarar que los registros *apuntan* o *configuran* a los pines, pero los pines no residen "dentro" de los registros.
- **Prioridad Incremental en Ejemplos:** Al añadir ejemplos de código, queda terminantemente prohibido recortar las opciones técnicas completas del manual (ej: mostrar solo una opción del bit `FORM`). Se deben integrar los ejemplos de código manteniendo la totalidad de los valores posibles para consulta técnica.
- **Precisión Arquitectónica y Desglose de Hardware:** Toda documentación debe diferenciar explícitamente entre acciones realizadas por el **Hardware** (automáticas de la CPU) y acciones por **Software** (nuestro código). Los ejemplos deben utilizar mapas de memoria realistas, respetando la Arquitectura Harvard y utilizando direcciones físicas hexadecimales coherentes con el mapa de memoria del dsPIC (ej. variables globales en direcciones bajas `0x0800`, Stack en direcciones altas).
- **Saneamiento de Codificación:** Si un archivo presenta caracteres rotos por codificación antigua, el Agente debe recrearlo en formato UTF-8 para garantizar la integridad visual del estudio.

## 7. Estándar de Estructura de Proyecto y Nomenclatura
- **Idioma Mandatorio:** Todo documento generado por el Agente (resúmenes, guías, explicaciones) debe escribirse en **español** y utilizar términos técnicos precisos. Queda prohibido el uso de nombres de archivos en inglés para material de estudio propio.
- **Estructura Raíz:** Ver archivo `ESTRUCTURA_REPOSITORIO.md` para el desglose detallado de carpetas globales (`MANUALES/`, `CLASES TEORICAS/`, `Cuestionarios/`, etc.).
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
1.  **Estructura del Proyecto:** Consultar siempre `ESTRUCTURA_REPOSITORIO.md` para ubicar archivos y respetar la jerarquía de subcarpetas.
2.  **Fechas y Plazos:** Consultar siempre `CRONOGRAMA_RESUMEN.md` en la raíz.
2.  **Teoría y Conceptos:** 
    - Diccionario técnico: `Documentacion/Diccionario.md`.
    - Clases: `CLASES TEORICAS/` (resúmenes) y `CLASES TEORICAS/Originales_PDF/`.
3.  **Desarrollo de Prácticas:**
    - Consigna: `PRACTICA X/ENUNCIADO/`.
    - Guías de estudio: `PRACTICA X/GUIA DE ESTUDIO GEMINI/`.
    - Código final: `PRACTICA X/Entrega/`.
4.  **Documentación Oficial:** `MANUALES/PDFs/` para datasheets y manuales de referencia.

## 9. Gestión de Cambios y Preservación de Contenido
- **Resguardo Ante Cambios Grandes:** Antes de realizar modificaciones estructurales, refactorizaciones masivas o procesos de "saneamiento" en documentos de estudio, el Agente **DEBE** guardar una copia exacta de la versión original en la carpeta `Obsoletos/` de la práctica correspondiente.
- **Prioridad Incremental:** Queda estrictamente prohibido realizar resúmenes o recortes de contenido técnico (tablas, diagramas, explicaciones de bajo nivel) a menos que el usuario lo solicite explícitamente. Ante la duda, el Agente debe **agregar contenido** (detallar más) en lugar de borrar o simplificar para "limpiar" el archivo.
- **Integridad de la "Memoria Técnica":** Los detalles de direcciones físicas, aritmética de punteros y mapas de memoria son activos críticos. No se deben resumir bajo ninguna circunstancia estética si eso implica perder precisión técnica.

---

## Índice de Herramientas de Python 🛠️
*Ubicación: `/Herramientas_Python/`*

Todos los scripts han sido configurados para ejecutarse sin importar en qué computadora se haya clonado el repositorio (rutas relativas automatizadas).

1. **`fast_extract.py`:** Convierte instantáneamente PDFs que YA están en español a archivos legibles Markdown (`.md`).
2. **`translate_pdf.py`:** Convierte manuales en INGLÉS al español usando Google Translate. *(Cuidado: demora horas en datasheets grandes por la espera entre párrafos para evitar baneos de Google).*
3. **`format_md.py`:** Limpiador estético de Markdown. Arregla viñetas, acomoda los títulos por niveles (`###`), y elimina basura visual del texto extraído.
4. **`fix_code_md.py`:** Escanea los documentos traducidos y re-ensambla la sintaxis rota del C (cambia *nulo __atributo__* por `void __attribute__` y arregla bucles *mientras* por `while`).
5. **`leer_pdf_consola.py`:** Lector rápido para visualizar contenido de PDFs directamente en la consola sin generar archivos.
