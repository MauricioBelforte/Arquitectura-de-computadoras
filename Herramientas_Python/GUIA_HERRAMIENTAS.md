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

---
> [!IMPORTANT]
> **Configuración de Archivos:** Para añadir nuevos PDFs a la cola de procesamiento, edita la lista `pdfs_a_extraer` dentro de cada script. Los scripts escanearán automáticamente las subcarpetas del proyecto.
