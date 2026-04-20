"""
HERRAMIENTA 4: Reparador de Código CTraducido (fix_code_md.py)
-------------------------------------------------------------------------
Descripción: 
Cuando Google Translate procesa hojas de datos (Datasheets), a menudo
traduce palabras clave de C de manera literal ("void" -> "nulo"). 
Este script escanea todos los .md y usa Regex para restaurar la sintaxis 
de C en los ejemplos de código (ej. "nulo __atributo__" a "void __attribute__").
"""

import os
import re
import glob

DIR_ACTUAL = os.path.dirname(os.path.abspath(__file__))
DIR_RAIZ = os.path.dirname(DIR_ACTUAL)

def restore_c_code_in_md(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()

    original_content = content
    
    # 1. Atributos de interrupción
    content = re.sub(r'\bnulo\s+__atributo__\b', 'void __attribute__', content, flags=re.IGNORECASE)
    content = re.sub(r'\bvacío\s+__atributo__\b', 'void __attribute__', content, flags=re.IGNORECASE)
    content = re.sub(r'__atributo__', '__attribute__', content)
    
    # 2. Argumentos void en funciones
    content = re.sub(r'\(\s*nulo\s*\)', '(void)', content, flags=re.IGNORECASE)
    content = re.sub(r'\(\s*vacío\s*\)', '(void)', content, flags=re.IGNORECASE)
    
    # 3. Palabras reservadas seguidas de punto y coma
    content = re.sub(r'\bdevolver\s*;', 'return;', content, flags=re.IGNORECASE)
    content = re.sub(r'\bdevolver\s+', 'return ', content, flags=re.IGNORECASE)
    content = re.sub(r'\bromper\s*;', 'break;', content, flags=re.IGNORECASE)
    content = re.sub(r'\bcontinuar\s*;', 'continue;', content, flags=re.IGNORECASE)
    
    # 4. Cabeceras y funciones específicas mal traducidas
    content = re.sub(r'#incluir', '#include', content, flags=re.IGNORECASE)
    content = re.sub(r'habilitar interrupciones nulas \(anular\)', 'void enable_interrupts(void)', content)
    content = re.sub(r'anular desactivar interrupciones \(anular\)', 'void disable_interrupts(void)', content)
    
    # 5. Estructuras de control
    content = re.sub(r'\bmientras\s*\(\s*1\s*\)', 'while(1)', content, flags=re.IGNORECASE)
    content = re.sub(r'\} demás \{', '} else {', content, flags=re.IGNORECASE)
    
    if content != original_content:
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(content)
        print(f"Corregido bloque de código C en: {os.path.basename(file_path)}")

# Encontrar todos los archivos _es.md dinámicamente desde la raíz
patron = os.path.join(DIR_RAIZ, "**", "*_es.md")
md_files = glob.glob(patron, recursive=True)

for md_file in md_files:
    restore_c_code_in_md(md_file)

print("¡Revisión de sintaxis C terminada!")
