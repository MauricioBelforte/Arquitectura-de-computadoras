"""
HERRAMIENTA 6: Diagnóstico de Codificación de PDF (diagnostico_pdf.py)
-------------------------------------------------------------------------
Descripción:
Analiza los codepoints Unicode de los caracteres especiales encontrados
en las primeras páginas de un PDF y los muestra de forma segura (ASCII).

Útil para diagnosticar PDFs con caracteres rotos al ser extraídos.
Los más comunes en diapositivas de PowerPoint son:
  - U+F06E, U+F0A7, etc. → Viñetas de fuentes Symbol/Wingdings (PUA)
    Solución: suprimir con re.sub(r'[\\uE000-\\uF8FF]', '', text)
  - U+00E1, U+00E9, etc. → á, é (Latin-1, correctos en UTF-8)
    Si se ven rotos, el problema es la codificación de la TERMINAL, no del archivo.

Uso:
  1. Modificar la variable PDF_A_ANALIZAR con la ruta del PDF a diagnosticar.
  2. Ejecutar: python Herramientas_Python/diagnostico_pdf.py
"""

import fitz
import os

DIR_ACTUAL = os.path.dirname(os.path.abspath(__file__))
DIR_RAIZ   = os.path.dirname(DIR_ACTUAL)

# ⚙️  CONFIGURAR: ruta del PDF a diagnosticar
PDF_A_ANALIZAR = os.path.join(
    DIR_RAIZ,
    "CLASES TEORICAS", "Originales_PDF",
    "05. Unidad 2A - Técnicas Digitales.pdf"
)

# Número de páginas a analizar (para no procesar todo el documento)
PAGINAS_A_REVISAR = 5

# ---------------------------------------------------------------------------

if not os.path.exists(PDF_A_ANALIZAR):
    print(f"[ERROR] No se encontró el PDF:\n  {PDF_A_ANALIZAR}")
    exit(1)

print(f"Analizando: {os.path.basename(PDF_A_ANALIZAR)}")
print(f"Primeras {PAGINAS_A_REVISAR} páginas\n")

doc = fitz.open(PDF_A_ANALIZAR)
chars_found = {}

for i in range(min(PAGINAS_A_REVISAR, len(doc))):
    page = doc[i]
    raw = page.get_text("rawdict")
    for blk in raw.get("blocks", []):
        if blk.get("type") == 0:
            for line in blk.get("lines", []):
                for span in line.get("spans", []):
                    for char in span.get("chars", []):
                        c = char.get("c", "")
                        if c and ord(c) > 127:
                            cp = ord(c)
                            chars_found[cp] = chars_found.get(cp, 0) + 1

doc.close()

if not chars_found:
    print("No se encontraron caracteres especiales (>U+007F). El PDF es ASCII puro.")
else:
    print(f"{'Codepoint':<12} {'Apariciones':<14} {'Categoría':<25} {'Descripción'}")
    print("-" * 70)
    for cp, count in sorted(chars_found.items()):
        if 0x00C0 <= cp <= 0x00FF:
            categoria = "Latin-1 (tildes/eñes)"
            desc = "Correcto en UTF-8"
        elif 0xE000 <= cp <= 0xF8FF:
            categoria = "PUA (Symbol/Wingdings)"
            desc = "Viñeta decorativa — suprimir"
        else:
            categoria = "Otro"
            desc = ""
        print(f"  U+{cp:04X}      {count:<14} {categoria:<25} {desc}")

print("\nDiagnóstico completado.")
print("Referencia: fast_extract.py ya aplica suprimir_pua() automáticamente.")
