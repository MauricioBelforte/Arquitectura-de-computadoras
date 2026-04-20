"""
HERRAMIENTA 1: Traductor de PDF a Markdown (translate_pdf.py)
-------------------------------------------------------------------------
Descripción: 
Este script recibe una lista de archivos PDF en inglés, procesa su 
texto página por página, y utiliza la API gratuita de Google Translate 
(deep-translator) para convertir el texto al español. 
El resultado se guarda en archivos Markdown (_es.md).

Nota sobre rutas: 
El script obtiene automáticamente la ruta de la carpeta raíz de la materia
('ARQUITECTURA DE COMPUTADORAS') subiendo un nivel desde donde se ejecuta.
"""

import fitz  # PyMuPDF
from deep_translator import GoogleTranslator
import time
import sys
import os

# Determinar automáticamente el directorio raíz del proyecto (una carpeta arriba)
DIR_ACTUAL = os.path.dirname(os.path.abspath(__file__))
DIR_RAIZ = os.path.dirname(DIR_ACTUAL)

def translate_pdf_to_md(pdf_path, md_path):
    print(f"Abriendo {pdf_path}...")
    try:
        doc = fitz.open(pdf_path)
    except Exception as e:
        print(f"Error al abrir el PDF: {e}")
        return

    translator = GoogleTranslator(source='auto', target='es')
    
    with open(md_path, 'w', encoding='utf-8') as f:
        f.write(f"# Traducción de {os.path.basename(pdf_path)}\n\n")
        
        for i, page in enumerate(doc):
            print(f"Procesando página {i+1}/{len(doc)}...", end='\r')
            text = page.get_text()
            
            if not text.strip():
                continue
            
            f.write(f"\n## Página {i+1}\n\n")
            
            paragraphs = text.split('\n\n')
            for p in paragraphs:
                p = p.strip()
                if not p:
                    continue
                
                if len(p) > 4000:
                    lines = p.split('\n')
                    for line in lines:
                        if line.strip():
                            try:
                                translated = translator.translate(line.strip())
                                f.write(translated + " \n")
                                time.sleep(0.3) # Pausa para no saturar la API
                            except Exception as e:
                                f.write(f"\n> Error de traducción: {line}\n")
                    f.write("\n\n")
                else:
                    try:
                        translated = translator.translate(p)
                        f.write(translated + "\n\n")
                        time.sleep(0.3)
                    except Exception as e:
                        f.write(f"\n> Error de traducción: {p}\n\n")

    print(f"\n\n¡Traducción completa! Guardado en {md_path}")

if __name__ == '__main__':
    # Archivos a traducir usando rutas relativas automáticas
    pdfs_a_traducir = [
        os.path.join(DIR_RAIZ, "PRACTICA 2", "manual_referencia_dsPIC33F_11_timers.pdf"),
        os.path.join(DIR_RAIZ, "Set_de_Instrucciones_dsPic33 (Resumido).pdf"),
        os.path.join(DIR_RAIZ, "MCU_and_DSC_prog_Reference_Manual (Set de instrucciones completo).pdf"),
        os.path.join(DIR_RAIZ, "dsPic33FJ256GP710-70286C (Datasheet).pdf")
    ]
    
    for pdf_path in pdfs_a_traducir:
        if not os.path.exists(pdf_path):
            print(f"No se encontró el archivo: {pdf_path}")
            continue
            
        md_path = os.path.splitext(pdf_path)[0] + "_es.md"
        print(f"\n==========================================")
        print(f"Iniciando traducción de: {os.path.basename(pdf_path)}")
        translate_pdf_to_md(pdf_path, md_path)
