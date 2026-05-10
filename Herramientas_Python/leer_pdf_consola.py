import fitz
import sys
import os

"""
HERRAMIENTA 5: Lector Rápido de PDF (leer_pdf_consola.py)
-------------------------------------------------------------------------
Descripción: 
Este script permite extraer el texto de un PDF y mostrarlo directamente 
en la consola con codificación UTF-8. Es ideal para "ojear" el contenido 
de un manual o cronograma sin generar archivos adicionales.

Uso: python Herramientas_Python/leer_pdf_consola.py "ruta/al/archivo.pdf"
"""

def leer_pdf(ruta_pdf):
    # Forzar salida en UTF-8 para evitar errores de charmap en Windows
    sys.stdout.reconfigure(encoding='utf-8')

    if not os.path.exists(ruta_pdf):
        print(f"Error: No se encuentra el archivo en {ruta_pdf}")
        return

    try:
        doc = fitz.open(ruta_pdf)
        print(f"\n--- LEYENDO: {os.path.basename(ruta_pdf)} ---\n")
        for page in doc:
            print(page.get_text())
        print("\n--- FIN DEL DOCUMENTO ---\n")
    except Exception as e:
        print(f"Error al leer el PDF: {e}")

if __name__ == "__main__":
    if len(sys.argv) > 1:
        leer_pdf(sys.argv[1])
    else:
        print("Uso: python leer_pdf_consola.py <ruta_del_pdf>")
