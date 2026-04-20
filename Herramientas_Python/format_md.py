"""
HERRAMIENTA 3: Formateador de Markdown (format_md.py)
-------------------------------------------------------------------------
Descripción: 
Este script busca todos los archivos _es.md en el repositorio y aplica 
expresiones regulares para corregir problemas estéticos:
- Restaura viñetas rotas (● y ○) a guiones normales (-).
- Elimina cabeceras y pies de páginas ("Página x de y", "Año 2026").
- Formatea los títulos de "Ejercicio X:" como cabeceras reales (###).
- Limpia los saltos de línea basura.
"""

import os
import re
import glob

DIR_ACTUAL = os.path.dirname(os.path.abspath(__file__))
DIR_RAIZ = os.path.dirname(DIR_ACTUAL)

def clean_markdown_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()

    # Eliminar pies de página repetitivos
    content = re.sub(r'Año 2026\n', '', content)
    content = re.sub(r'UNPSJB – Facultad de Ingeniería\n', '', content)
    content = re.sub(r'Página \d+ de \d+\n', '', content)
    content = re.sub(r'## Página \d+\n', '', content)
    
    # Arreglar viñetas raras del PDF (● y ○ con espacios/basura invisible)
    content = re.sub(r'●[\s\u200b]*', '- ', content)
    content = re.sub(r'○[\s\u200b]*', '  - ', content)
    
    # Formatear Ejercicios como subtítulos
    content = re.sub(r'(Ejercicio \d+:.*)', r'### \1', content)
    
    # Limpiar saltos de línea excesivos
    content = re.sub(r'\n{3,}', '\n\n', content)
    
    # Guardar sobreescribiendo el original
    with open(file_path, 'w', encoding='utf-8') as f:
        f.write(content.strip() + "\n")
    print(f"Formateado: {os.path.basename(file_path)}")

# Encontrar todos los archivos _es.md dinámicamente desde la raíz
patron = os.path.join(DIR_RAIZ, "**", "*_es.md")
md_files = glob.glob(patron, recursive=True)

for md_file in md_files:
    clean_markdown_file(md_file)

print("¡Todos los archivos Markdown han sido limpiados y formateados!")
