"""
HERRAMIENTA 2: Extracción Rápida (fast_extract.py)
-------------------------------------------------------------------------
Descripción:
Este script se utiliza para los PDFs que YA ESTÁN en español.
Su propósito es abrir el PDF, extraer el texto usando el método de bloques
ordenados por posición (más legible que la extracción lineal), y guardarlo
como .md en la carpeta correspondiente.
Es increíblemente rápido comparado con el traductor (milisegundos).

Método de extracción:
Usa get_text("blocks") y ordena los bloques por posición vertical (y) y luego
horizontal (x) para respetar el orden de lectura natural del documento,
evitando mezclas de columnas o pies de página intercalados.

Nota sobre rutas:
- Para PDFs en CLASES TEORICAS: los .md se guardan en la carpeta CLASES TEORICAS/
  (NO en Originales_PDF/), siguiendo la convención establecida en el repositorio.
- Para el resto de PDFs: el .md se guarda junto al PDF original.

Nota sobre codificación:
Los PDFs de diapositivas de PowerPoint pueden contener viñetas en la PUA de
Unicode (U+F0xx, fuentes Symbol/Wingdings). Son artefactos visuales de bullets
que se suprimen automáticamente. Los acentos y tildes se preservan correctamente
en UTF-8. Si detectás caracteres rotos, usá diagnostico_pdf.py para analizarlos.

Para agregar nuevos PDFs:
Añadí una tupla (pdf_path, md_path) a la lista CLASES_TEORICAS_PDFS,
o un path directo a OTROS_PDFS según corresponda.
"""

import fitz  # PyMuPDF
import os
import re

DIR_ACTUAL  = os.path.dirname(os.path.abspath(__file__))
DIR_RAIZ    = os.path.dirname(DIR_ACTUAL)
DIR_CLASES  = os.path.join(DIR_RAIZ, "CLASES TEORICAS")
DIR_ORIG    = os.path.join(DIR_CLASES, "Originales_PDF")

# ---------------------------------------------------------------------------
# CLASES TEORICAS: (nombre_pdf_en_Originales_PDF, nombre_md_en_CLASES_TEORICAS)
# Agregar nuevas clases aquí.
# ---------------------------------------------------------------------------
CLASES_TEORICAS_PDFS = [
    ("01. Presentación.pdf",                  "01. Presentación_es.md"),
    ("02. Unidad 1 - Introducción.pdf",       "02. Unidad 1 - Introducción_es.md"),
    ("03. Unidad 8 - Microcontroladores.pdf", "03. Unidad 8 - Microcontroladores_es.md"),
    ("04. Unidad 7 - Entrada-Salida.pdf",     "04. Unidad 7 - Entrada-Salida_es.md"),
    ("05. Unidad 2A - Técnicas Digitales.pdf","05. Unidad 2A - Técnicas Digitales_es.md"),
    ("06. Unidad 2B - Técnicas Digitales.pdf","06. Unidad 2B - Técnicas Digitales_es.md"),
]

# ---------------------------------------------------------------------------
# PROGRAMACION C: (nombre_pdf_en Originales/, nombre_md_en Programacion_C/)
# ---------------------------------------------------------------------------
PROGRAMACION_C_PDFS = [
    ("Apunte_C.pdf", "Apunte_C_es.md"),
    ("Apunte_C_Arqui.pdf", "Apunte_C_Arqui_es.md"),
    ("aprenda_lenguaje_ansi_c_como_si_estuviera_en_primero.pdf", "aprenda_ansi_c_es.md"),
]

# ---------------------------------------------------------------------------
# OTROS PDFs: el .md se guarda junto al PDF (mismo directorio).
# ---------------------------------------------------------------------------
OTROS_PDFS = [
    os.path.join(DIR_RAIZ, "Documentacion", "AC - Anexo1.pdf"),
    os.path.join(DIR_RAIZ, "PRACTICA 1", "AC - TP1 - 2026.pdf"),
    os.path.join(DIR_RAIZ, "PRACTICA 2", "AC - TP2 - 2026.pdf"),
    os.path.join(DIR_RAIZ, "PRACTICA 3", "ENUNCIADO", "AC - TP3 - 2026.pdf"),
    os.path.join(DIR_RAIZ, "PRACTICA 3", "MANUALES", "Conversor Analógico_Digital.pdf"),
]


# ---------------------------------------------------------------------------
# Funciones de extracción
# ---------------------------------------------------------------------------

def extract_blocks(page):
    """
    Extrae texto de una página usando bloques ordenados por posición (y, x).
    Esto produce un orden de lectura más natural que la extracción lineal,
    especialmente en diapositivas con múltiples columnas o overlays.
    """
    blocks = page.get_text("blocks")
    blocks.sort(key=lambda b: (round(b[1], 1), b[0]))  # ordena por y luego x
    lines = []
    for b in blocks:
        if b[6] == 0:  # tipo 0 = texto (no imagen)
            text = b[4].strip()
            if text:
                lines.append(text)
    return "\n".join(lines)

def suprimir_pua(text: str) -> str:
    """
    Suprime caracteres de la Private Use Area (U+E000–U+F8FF) que corresponden
    a viñetas/símbolos de fuentes Symbol/Wingdings incrustadas en PDFs de
    PowerPoint. No afecta letras, acentos ni tildes (U+00xx).
    """
    return re.sub(r'[\uE000-\uF8FF]', '', text)

def extraer_pdf(pdf_path: str, md_path: str):
    """Extrae el texto de un PDF y lo guarda como Markdown en md_path."""
    if not os.path.exists(pdf_path):
        print(f"  [NO ENCONTRADO] {pdf_path}")
        return

    nombre = os.path.basename(pdf_path)
    titulo = os.path.splitext(nombre)[0]
    print(f"Extrayendo: {nombre} ...")

    try:
        doc = fitz.open(pdf_path)
        with open(md_path, 'w', encoding='utf-8') as f:
            f.write(f"# {titulo}\n\n")
            for i, page in enumerate(doc):
                raw = extract_blocks(page)
                # Fallback a extracción simple si el bloque devuelve poco texto
                if len(raw.strip()) < 20:
                    raw = page.get_text()
                text = suprimir_pua(raw)
                if text.strip():
                    f.write(f"\n## Página {i+1}\n\n")
                    f.write(text)
                    f.write("\n\n")
        print(f"   -> Guardado: {md_path}")
    except Exception as e:
        print(f"  [ERROR] {nombre}: {e}")

# ---------------------------------------------------------------------------
# Procesamiento
# ---------------------------------------------------------------------------

print("=== CLASES TEÓRICAS ===")
for nombre_pdf, nombre_md in CLASES_TEORICAS_PDFS:
    pdf_path = os.path.join(DIR_ORIG, nombre_pdf)
    md_path  = os.path.join(DIR_CLASES, nombre_md)
    extraer_pdf(pdf_path, md_path)

print("\n=== PROGRAMACIÓN C ===")
DIR_PROG_C = os.path.join(DIR_RAIZ, "Documentacion", "Manuales", "Programacion_C")
DIR_PROG_C_ORIG = os.path.join(DIR_PROG_C, "Originales")
for nombre_pdf, nombre_md in PROGRAMACION_C_PDFS:
    pdf_path = os.path.join(DIR_PROG_C_ORIG, nombre_pdf)
    md_path  = os.path.join(DIR_PROG_C, nombre_md)
    extraer_pdf(pdf_path, md_path)

print("\n=== OTROS PDFs ===")
for pdf_path in OTROS_PDFS:
    md_path = os.path.splitext(pdf_path)[0] + "_es.md"
    extraer_pdf(pdf_path, md_path)

print("\n¡Extracción masiva completada exitosamente!")

