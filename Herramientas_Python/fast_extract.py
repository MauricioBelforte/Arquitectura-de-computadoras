"""
HERRAMIENTA 2: Extracción Rápida (fast_extract.py)
-------------------------------------------------------------------------
Descripción: 
Este script se utiliza para los PDFs que YA ESTÁN en español. 
Su único propósito es abrir el archivo PDF, extraer el texto plano sin 
necesidad de pasarlo por la API de traducción, y guardarlo como .md.
Es increíblemente rápido comparado con el traductor (milisegundos).

Nota sobre rutas: 
El script obtiene automáticamente la ruta de la carpeta raíz de la materia
y procesa los archivos locales usando rutas dinámicas.
"""

import fitz  # PyMuPDF
import os

DIR_ACTUAL = os.path.dirname(os.path.abspath(__file__))
DIR_RAIZ = os.path.dirname(DIR_ACTUAL)

pdfs_a_extraer = [
    os.path.join(DIR_RAIZ, "AC - Anexo1.pdf"),
    os.path.join(DIR_RAIZ, "CLASES TEORICAS", "01. Presentación.pdf"),
    os.path.join(DIR_RAIZ, "CLASES TEORICAS", "02. Unidad 1 - Introducción.pdf"),
    os.path.join(DIR_RAIZ, "CLASES TEORICAS", "03. Unidad 8 - Microcontroladores.pdf"),
    os.path.join(DIR_RAIZ, "CLASES TEORICAS", "04. Unidad 7 - Entrada-Salida.pdf"),
    os.path.join(DIR_RAIZ, "PRACTICA 1", "AC - TP1 - 2026.pdf"),
    os.path.join(DIR_RAIZ, "PRACTICA 2", "AC - TP2 - 2026.pdf")
]

for pdf_path in pdfs_a_extraer:
    if not os.path.exists(pdf_path):
        # Limpieza simple de tildes por si hay inconsistencias de nombres
        pdf_path = pdf_path.replace("ó", "").replace("ó", "")
        if not os.path.exists(pdf_path):
            print(f"No se encontró: {pdf_path}")
            continue

    md_path = os.path.splitext(pdf_path)[0] + "_es.md"
    print(f"Extrayendo texto de: {os.path.basename(pdf_path)}...")
    
    try:
        doc = fitz.open(pdf_path)
        with open(md_path, 'w', encoding='utf-8') as f:
            f.write(f"# Contenido extraído de {os.path.basename(pdf_path)}\n\n")
            for i, page in enumerate(doc):
                text = page.get_text()
                if text.strip():
                    f.write(f"\n## Página {i+1}\n\n")
                    f.write(text)
                    f.write("\n\n")
        print(f"   -> Guardado en {md_path}")
    except Exception as e:
        print(f"Error procesando {pdf_path}: {e}")

print("¡Extracción masiva completada exitosamente!")
