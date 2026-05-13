# Guía de Herramientas de Automatización (Python)
**Ecosistema:** Arquitectura de Computadoras
**Ubicación:** `/Herramientas_Python/`

Este directorio contiene scripts diseñados para automatizar el procesamiento de la documentación técnica pesada (Datasheets y Manuales de Referencia). Están configurados con **rutas relativas dinámicas**, por lo que funcionan sin importar en qué carpeta local se haya clonado el repositorio.

---

## 🛠️ Índice de Herramientas

### 1. `fast_extract.py` (Extracción Rápida)
*   **Propósito:** Para PDFs que **ya están en español** (ej. Enunciados, diapositivas de clase).
*   **Funcionamiento:** Extrae el texto plano del PDF de forma instantánea sin pasar por traductores.
*   **Resultado:** Genera un archivo `.md` con el sufijo `_es.md` en la misma ubicación que el PDF original.
*   **Dependencias:** Requiere la librería `PyMuPDF` (`import fitz`).

### 2. `translate_pdf.py` (Traductor de Manuales)
*   **Propósito:** Traducir manuales originales en **inglés** al español.
*   **Funcionamiento:** Envía el texto por bloques a la API de Google Translate. Posee un sistema de pausas automáticas para evitar bloqueos por exceso de peticiones.
*   **Resultado:** Crea la versión traducida en formato Markdown (`_es.md`).
*   **Nota:** Debido a que los Datasheets tienen miles de páginas, este script puede demorar horas. Se recomienda usarlo solo para capítulos específicos o manuales medianos.

### 3. `format_md.py` (Limpiador Estético)
*   **Propósito:** Corregir el formato visual de los archivos Markdown generados.
*   **Funcionamiento:** 
    *   Elimina saltos de línea dobles innecesarios.
    *   Arregla viñetas y listas rotas por la extracción.
    *   Acomoda los niveles de títulos (`#`, `##`, `###`) para que el documento sea navegable.
    *   Elimina "basura" visual típica de los PDFs (pies de página repetitivos, números de página sueltos).

### 4. `fix_code_md.py` (Reparador de Sintaxis C)
*   **Propósito:** Restaurar el código fuente que fue "arruinado" por la traducción automática.
*   **Funcionamiento:** Busca patrones comunes de traducciones literales erróneas y los devuelve a su sintaxis original de C (XC16).
*   **Correcciones principales:**
    *   `nulo __atributo__` ➡️ `void __attribute__`
    *   `habilitar interrupciones nulas (anular)` ➡️ `void enable_interrupts(void)`
    *   `anular desactivar interrupciones (anular)` ➡️ `void disable_interrupts(void)`
    *   `mientras (1)` ➡️ `while(1)`
    *   `devolver;` ➡️ `return;`
    *   `#incluir` ➡️ `#include`
    *   `\} demás \{` ➡️ `} else {`

### 5. `leer_pdf_consola.py` (Lector Rápido)
*   **Propósito:** "Ojear" el contenido de un PDF directamente desde la consola sin generar archivos nuevos.
*   **Funcionamiento:** Extrae el texto y lo imprime usando codificación UTF-8 para evitar errores de caracteres especiales.
*   **Uso:** `python Herramientas_Python/leer_pdf_consola.py "ruta/archivo.pdf"`

### 6. `diagnostico_pdf.py` (Diagnóstico de Codificación)
*   **Propósito:** Analizar los codepoints Unicode de los caracteres especiales de un PDF para detectar problemas de codificación antes de extraerlo.
*   **Funcionamiento:** Escanea las primeras páginas del PDF e imprime una tabla con cada carácter especial encontrado, su frecuencia y su categoría:
    *   **Latin-1 (U+00C0–U+00FF):** Tildes y eñes. Correctos en UTF-8. Si se ven rotos, el problema es la terminal, no el archivo.
    *   **PUA (U+E000–U+F8FF):** Viñetas de fuentes Symbol/Wingdings. Se suprimen automáticamente con `fast_extract.py`.
*   **Uso:** Configurar `PDF_A_ANALIZAR` en el script y ejecutar:
    ```bash
    python Herramientas_Python/diagnostico_pdf.py
    ```

---

## 🚀 Cómo utilizarlas

1.  **Instalación de dependencias:**
    Asegúrate de tener Python instalado y ejecuta:
    ```bash
    pip install pymupdf googletrans==4.0.0-rc1
    ```

2.  **Ejecución:**
    Simplemente abre una terminal en la carpeta raíz del proyecto y ejecuta el script deseado:
    ```bash
    python Herramientas_Python/fast_extract.py
    ```

3.  **Flujo Recomendado:**
    *   Para **mirar rápido** un documento: Usar `leer_pdf_consola.py`.
    *   Para **integrar** un manual nuevo (inglés): `translate` -> `format` -> `fix_code`.
    *   Para **integrar** un manual nuevo (español): `fast_extract` -> `format`.
    *   Si el texto extraído tiene **caracteres rotos**: ejecutar `diagnostico_pdf.py` primero.

---
> [!IMPORTANT]
> **Agregar nuevos PDFs a `fast_extract.py`:** Para clases teóricas, añadir una tupla `("nombre.pdf", "nombre_es.md")` a la lista `CLASES_TEORICAS_PDFS`. Para otros PDFs (prácticas, manuales), añadir la ruta completa a `OTROS_PDFS`. Los scripts usan rutas dinámicas y funcionan en cualquier máquina donde esté clonado el repositorio.

