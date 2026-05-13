# Traducción de d:\Escritorio\INFORMATICA\ARQUITECTURA DE COMPUTADORAS\Set_de_Instrucciones_dsPic33 (Resumido).pdf

¤ 2009 Microchip Technology Inc.
DS70286C-página 245
dsPIC33FJXXXGPX06/X08/X10
23.0
RESUMEN DEL JUEGO DE INSTRUCCIONES
El conjunto de instrucciones dsPIC33F es idéntico al del
dsPIC30F. 
La mayoría de las instrucciones son una sola palabra de memoria de programa.
(24 bits). Sólo tres instrucciones requieren dos programas
ubicaciones de memoria. 
Cada instrucción de una sola palabra es una palabra de 24 bits, dividida
en un código de operación de 8 bits, que especifica la instrucción
tipo y uno o más operandos, que especifican con más detalle
el funcionamiento de la instrucción. 
El conjunto de instrucciones es altamente ortogonal y está agrupado
en cinco categorías básicas:
• Operaciones orientadas a palabras o bytes
• Operaciones orientadas a bits
• Operaciones literales
• Operaciones DSP
• Control operations
La tabla 23-1 ilustra los símbolos generales utilizados en
describiendo las instrucciones. 
El resumen del conjunto de instrucciones dsPIC33F en la Tabla 23-2
proporciona todas las instrucciones, junto con las banderas de estado
afectados por cada instrucción. 
La mayoría de las instrucciones de registro W orientadas a palabras o bytes
(incluyendo 
barril 
turno 
instrucciones) 
tener 
tres
operandos: 
• El primer operando fuente, que normalmente es un 
registrar ‘Wb’ sin ningún modificador de dirección
• El segundo operando fuente, que normalmente es un 
registrar ‘Ws’ con o sin modificador de dirección
• El destino del resultado, que normalmente es un 
registrar ‘Wd’ con o sin un modificador de dirección 
Sin embargo, las instrucciones de registro de archivos orientadas a palabras o bytes
tener dos operandos:
• El registro de archivo especificado por el valor ‘f’
• El destino, que podría ser el archivo 
registro ‘f’ o el registro W0, que se denota como 
‘WREG’
la mayoría 
orientado a bits 
instrucciones 
(incluyendo 
sencillo
instrucciones de rotación/desplazamiento) tienen dos operandos:
• El registro W (con o sin dirección) 
modificador) o registro de archivo (especificado por el valor de 
‘Ws’ o ‘f’) 
• El bit en el registro W o registro de archivo 
(especificado por un valor literal o indirectamente por el 
contenido del registro ‘Wb’) 
Las instrucciones literales que impliquen movimiento de datos podrán
Utilice algunos de los siguientes operandos:
• Un valor literal que se cargará en un registro o archivo W 
registro (especificado por el valor de ‘k’) 
• El registro W o registro de archivo donde se encuentra el literal 
se va a cargar el valor (especificado por ‘Wb’ o ‘f’)
Sin embargo, las instrucciones literales que involucran aritmética o
Las operaciones lógicas utilizan algunos de los siguientes operandos:
• El primer operando fuente que es un registro ‘Wb’ 
without any address modifier
• El segundo operando fuente que es un literal 
valor
• El destino del resultado (solo si no es el mismo 
como primer operando fuente) que normalmente es un 
registrar ‘Wd’ con o sin un modificador de dirección
La clase MAC de instrucciones DSP puede utilizar algunas de las
siguientes operandos:
• El acumulador (A o B) a utilizar (requerido 
operando)
• Los registros W que se utilizarán como dos operandos
• Las operaciones de captación previa del espacio de direcciones X e Y
• Los destinos de captación previa del espacio de direcciones X e Y
• El destino de reescritura del acumulador
Las otras instrucciones DSP no implican ningún
multiplicación y puede incluir:
• El acumulador a utilizar (obligatorio)
• El operando de origen o destino (designado como 
Wso o Wdo, respectivamente) con o sin 
modificador de dirección 
• La cantidad de desplazamiento especificada por un registro W ‘Wn’ 
o un valor literal
Las instrucciones de control pueden utilizar algunos de los siguientes
operandos:
• Una dirección de memoria de programa 
• El modo de lectura y escritura de la tabla. 
instrucciones 
Nota:
Esta hoja de datos resume las características
del dsPIC33FJXXXGPX06/X08/X10
family of devices. Sin embargo, no es
pretende ser una referencia completa
fuente. Para complementar la información en
esta hoja de datos, consulte la sección relacionada
en la referencia de la familia “dsPIC33F
Manual”, que está disponible en la
Sitio web de Microchip (www.microchip.com).

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 246
¤ 2009 Microchip Technology Inc.
Todas las instrucciones son una sola palabra, excepto ciertas
doble palabra 
instrucciones, 
cual 
fueron 
hecho
instrucciones de dos palabras para que todos los requeridos
La información está disponible en estos 48 bits. en el segundo
En otras palabras, los 8 MSbs son ‘0. Si esta segunda palabra es
ejecutado como una instrucción (por sí mismo), se ejecutará como
un NOP. 
Most single-word instructions are executed in a single
ciclo de instrucción, a menos que una prueba condicional sea verdadera, o la
El contador del programa cambia como resultado de la
instrucción. En estos casos, la ejecución tarda dos
ciclos de instrucción con el ciclo(s) de instrucción adicional
ejecutado como NOP. Las excepciones notables son el BRA
(rama incondicional/calculada), CALL/GOTO indirecto,
todas las tablas leen y escriben y RETURN/RETFIE
instrucciones, que son instrucciones de una sola palabra pero que toman
dos o tres ciclos. Ciertas instrucciones que implican saltarse
ping sobre la instrucción posterior requiere dos
o tres ciclos si se realiza el salto, dependiendo de
si la instrucción que se omite es una sola palabra o
instrucción de dos palabras. Además, los movimientos de dos palabras
requieren dos ciclos. Las instrucciones de dos palabras.
ejecutar en dos ciclos de instrucción. 
  
Nota:
Para obtener más detalles sobre el conjunto de instrucciones,
consulte el manual del "Programador dsPIC30F/33F".
Manual de referencia” (DS70157).
TABLA 23-1:
SÍMBOLOS UTILIZADOS EN LAS DESCRIPCIONES DE CÓDIGOS DE OPCIÓN
campo
Descripción
#texto
Significa literal definido por “texto”
(texto)
Significa “contenido del texto”
[texto]
Significa “la ubicación a la que se dirige el texto”
{ }
Campo u operación opcional
<n:m>
Campo de bits de registro
.b
Selección del modo de bytes
.d
Selección del modo de doble palabra
.S
Shadow register select
.w
Selección de modo de palabra (predeterminado)
Acc
Uno de los dos acumuladores {A, B}
AWB
Registro de dirección de destino de reescritura del acumulador ∈ {W13, [W13]+ = 2}
bit4
Campo de selección de bits de 4 bits (utilizado en instrucciones con dirección de palabra) ∈ {0...15}
C, CC, N, OV, Z
Bits de estado de MCU: acarreo, acarreo de dígitos, negativo, desbordamiento, cero fijo
Expr.
Dirección, etiqueta o expresión absoluta (resuelta por el vinculador)
f
Dirección de registro de archivo ∈ {0x0000...0x1FFF}
lit1
Literal sin signo de 1 bit ∈ {0,1}
lit4
Literal sin signo de 4 bits ∈ {0...15}
lit5
Literal sin signo de 5 bits ∈ {0...31}
lit8
Literal sin signo de 8 bits ∈ {0...255}
iluminado10
Literal sin signo de 10 bits ∈ {0...255} para el modo Byte, {0:1023} para el modo Word
iluminado14
Literal sin signo de 14 bits ∈ {0...16384}
iluminado16
Literal sin signo de 16 bits ∈ {0...65535}
lit23
Literal sin signo de 23 bits ∈ {0...8388608}; LSb debe ser ‘0’
Ninguno
El campo no requiere entrada, puede estar en blanco
OA, OB, SA, SB
Bits de estado DSP: AccA Overflow, AccB Overflow, AccA Saturate, AccB Saturate
ordenador personal
Contador de programas
hendidura10
Literal con signo de 10 bits ∈ {-512...511}
hendidura16
Literal con signo de 16 bits ∈ {-32768...32767}
rendija6
Literal con signo de 6 bits ∈ {-16...16}
Wb
Registro base W ∈ {W0..W15}
Wd
Registro W de destino ∈ { Wd, [Wd], [Wd++], [Wd--], [++Wd], [--Wd] }
wdo
Destination W register ∈ 
{ Viento, [Viento], [Viento++], [Viento--], [++Viento], [--Viento], [Viento+Wb] } 
Wm,Wn
Dividendo, par de registros de trabajo del divisor (direccionamiento directo)

¤ 2009 Microchip Technology Inc.
DS70286C-página 247
dsPIC33FJXXXGPX06/X08/X10
Wm*Wm
Par de registros de trabajo multiplicando y multiplicador para instrucciones Square ∈ 
{W4 * W4,W5 * W5,W6 * W6,W7 * W7} 
Wm*Wn
Par de registros de trabajo multiplicando y multiplicador para instrucciones DSP ∈
{W4 * W5,W4 * W6,W4 * W7,W5 * W6,W5 * W7,W6 * W7}
Wn
Uno de los 16 registros de trabajo ∈ {W0..W15}
viento
Uno de los 16 registros de trabajo de destino ∈ {W0...W15}
Wns
Uno de los 16 registros de trabajo fuente ∈ {W0...W15}
WREG
W0 (registro de trabajo utilizado en las instrucciones de registro de archivos)
Ws
Registro fuente W ∈ { Ws, [Ws], [Ws++], [Ws--], [++Ws], [--Ws] }
Wso
Registro fuente W ∈ 
{ Wns, [Wns], [Wns++], [Wns--], [++Wns], [--Wns], [Wns+Wb] } 
Wx
Registro de dirección de captación previa del espacio de datos X para instrucciones DSP 
∈{[W8]+ = 6, [W8]+ = 4, [W8]+ = 2, [W8], [W8]- = 6, [W8]- = 4, [W8]- = 2,
     [W9]+ = 6, [W9]+ = 4, [W9]+ = 2, [W9], [W9]- = 6, [W9]- = 4, [W9]- = 2,
     [S9 + W12], ninguno}
Wxd
Registro de destino de captación previa del espacio de datos X para instrucciones DSP ∈ {W4...W7}
Wy
Registro de direcciones de captación previa del espacio de datos Y para instrucciones DSP 
∈{[W10]+ = 6, [W10]+ = 4, [W10]+ = 2, [W10], [W10]- = 6, [W10]- = 4, [W10]- = 2,
     [W11]+ = 6, [W11]+ = 4, [W11]+ = 2, [W11], [W11]- = 6, [W11]- = 4, [W11]- = 2,
     [W11 + W12], ninguno}
Wyd
Registro de destino de captación previa del espacio de datos Y para instrucciones DSP ∈ {W4...W7}
TABLA 23-1:
SÍMBOLOS UTILIZADOS EN LAS DESCRIPCIONES DE CÓDIGOS DE OPCIÓN (CONTINUACIÓN)
campo
Descripción

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 248
¤ 2009 Microchip Technology Inc.
TABLA 23-2:
RESUMEN DEL JUEGO DE INSTRUCCIONES    
bases
instrucción
#
Asamblea
mnemotécnico
Sintaxis de ensamblaje
Descripción
# de 
palabras
# de 
Ciclos
Banderas de estado 
Afectados
1
AÑADIR
AÑADIR
Acc
Agregar acumuladores
1
1
OA, OB, SA, SB
AÑADIR
f
f = f + WREG
1
1
C,CC,N,OV,Z
AÑADIR
f,WREG
WREG = f + WREG
1
1
C,CC,N,OV,Z
AÑADIR
#lit10,Wn
Wd = lit10 + Wd
1
1
C,CC,N,OV,Z
AÑADIR
Wb,Ws,Wd
Wd = Wb + Ws
1
1
C,CC,N,OV,Z
AÑADIR
Wb,#lit5,Wd
Wd = Wb + lit5
1
1
C,CC,N,OV,Z
AÑADIR
Wso,#Slit4,Acc
Agregar al acumulador firmado de 16 bits
1
1
OA, OB, SA, SB
2
ADDC
ADDC
f
f = f + WREG + (C)
1
1
C,CC,N,OV,Z
ADDC
f,WREG
WREG = f + WREG + (C)
1
1
C,CC,N,OV,Z
ADDC
#lit10,Wn
Wd = lit10 + Wd + (C)
1
1
C,CC,N,OV,Z
ADDC
Wb,Ws,Wd
Wd = Wb + Ws + (C)
1
1
C,CC,N,OV,Z
ADDC
Wb,#lit5,Wd
Wd = Wb + lit5 + (C)
1
1
C,CC,N,OV,Z
3
Y
Y
f
f = f .Y. WREG
1
1
N,Z
Y
f,WREG
WREG = f .Y. WREG
1
1
N,Z
Y
#lit10,Wn
Wd = lit10 .Y. Wd
1
1
N,Z
Y
Wb,Ws,Wd
Wd = Wb .Y. Ws
1
1
N,Z
Y
Wb,#lit5,Wd
Wd = Wb .Y. lit5
1
1
N,Z
4
ASR
ASR
f
f = Desplazamiento aritmético a la derecha f
1
1
C,N,OV,Z
ASR
f,WREG
WREG = Desplazamiento aritmético a la derecha f
1
1
C,N,OV,Z
ASR
Ws,Wd
Wd = Desplazamiento aritmético a la derecha Ws
1
1
C,N,OV,Z
ASR
Wb,Wns,Wnd
Wnd = Desplazamiento aritmético a la derecha Wb por Wns
1
1
N,Z
ASR
Wb,#lit5,Wnd
Wnd = Desplazamiento aritmético a la derecha Wb por lit5
1
1
N,Z
5
BCLR
BCLR
f,#bit4
Borrar bits f
1
1
Ninguno
BCLR
Ws,#bit4
Borrar bits Ws
1
1
Ninguno
6
sujetador
BRA
C,expr.
Rama si lleva
1
1 (2)
Ninguno
sujetador
GE,expr.
Rama si es mayor o igual
1
1 (2)
Ninguno
sujetador
GEU,expr.
Rama si no está firmada mayor o igual
1
1 (2)
Ninguno
sujetador
GT,Exp.
Rama si es mayor que
1
1 (2)
Ninguno
sujetador
GTU,expr.
Rama si no está firmada mayor que
1
1 (2)
Ninguno
sujetador
LE, Expr.
Rama si es menor o igual
1
1 (2)
Ninguno
sujetador
LEU,expr.
Rama si no está firmada menor o igual
1
1 (2)
Ninguno
sujetador
LT,expr.
Sucursal si es menor que
1
1 (2)
Ninguno
sujetador
LTU,expr.
Rama si no está firmada menos de
1
1 (2)
Ninguno
sujetador
N,expr.
Rama si es negativo
1
1 (2)
Ninguno
sujetador
NC, Expr.
Rama si no se lleva
1
1 (2)
Ninguno
sujetador
NN, Expr
Rama si no es negativo
1
1 (2)
Ninguno
BRA
NOV, exp.
Rama si no se desborda
1
1 (2)
Ninguno
sujetador
Nueva Zelanda, Expr.
Rama si no es cero
1
1 (2)
Ninguno
sujetador
OA,expr.
Rama si el acumulador A se desborda
1
1 (2)
Ninguno
sujetador
OB,expr.
Rama si el acumulador B se desborda
1
1 (2)
Ninguno
sujetador
OV,expr.
Rama si se desborda
1
1 (2)
Ninguno
sujetador
SA,expr.
Rama si el acumulador A está saturado
1
1 (2)
Ninguno
sujetador
SB,expr.
Ramifica si el acumulador B está saturado
1
1 (2)
Ninguno
sujetador
Expr.
Ramificar incondicionalmente 
1
2
Ninguno
sujetador
Z, Expr
Rama si cero
1
1 (2)
Ninguno
sujetador
Wn
Rama Computada
1
2
Ninguno
7
BSET
BSET
f,#bit4
Juego de bits f
1
1
Ninguno
BSET
Ws,#bit4
Juego de puntas Ws
1
1
Ninguno
8
BSW
BSW.C
Ws,Wb
Escribe el bit C en Ws<Wb>
1
1
Ninguno
BSW.Z
Ws,Wb
Escribe el bit Z en Ws<Wb>
1
1
Ninguno
9
BTG
BTG
f,#bit4
Cambio de bits f
1
1
Ninguno
BTG
Ws,#bit4
Cambio de bits Ws
1
1
Ninguno

¤ 2009 Microchip Technology Inc.
DS70286C-página 249
dsPIC33FJXXXGPX06/X08/X10
10
BTSC
BTSC
f,#bit4
Prueba de bits f, omitir si está claro
1
1 
(2 o 3)
Ninguno
BTSC
Ws,#bit4
Prueba de bits Ws, omitir si está claro
1
1 
(2 o 3)
Ninguno
11
BTSS
BTSS
f,#bit4
Prueba de bits f, omitir si está configurado
1
1 
(2 o 3)
Ninguno
BTSS
Ws,#bit4
Prueba de bits Ws, omitir si está configurado
1
1 
(2 o 3)
Ninguno
12
BTST
BTST
f,#bit4
Prueba de bits f
1
1
z
BTST.C
Ws,#bit4
Prueba de bits Ws a C
1
1
c
BTST.Z
Ws,#bit4
Prueba de bits Ws a Z
1
1
z
BTST.C
Ws,Wb
Prueba de bits Ws<Wb> a C 
1
1
c
BTST.Z
Ws,Wb
Prueba de bits Ws<Wb> a Z
1
1
z
13
BTSTS
BTSTS
f,#bit4
Prueba de bits y luego configure f
1
1
z
BTSTS.C
Ws,#bit4
Prueba de bits Ws a C, luego configurar
1
1
c
BTSTS.Z
Ws,#bit4
Prueba de bits Ws a Z, luego establece
1
1
z
14
LLAMADA
LLAMADA
lit23
Llamar a subrutina
2
2
Ninguno
LLAMADA
Wn
Llamar a subrutina indirecta
1
2
Ninguno
15
CLR
CLR
f
f = 0x0000
1
1
Ninguno
CLR
WREG
WREG = 0x0000
1
1
Ninguno
CLR
Ws
Ws = 0x0000
1
1
Ninguno
CLR
Acc,Wx,Wxd,Wy,Wyd,AWB
Limpiar acumulador
1
1
OA, OB, SA, SB
16
CLRWDT
CLRWDT
Borrar temporizador de vigilancia
1
1
WDTO, dormir
17
COM
COM
f
f = f
1
1
N,Z
COM
f,WREG
WREG = f
1
1
N,Z
COM
Ws,Wd
Wd = Ws
1
1
N,Z
18
CP
CP
f
Comparar f con WREG
1
1
C,CC,N,OV,Z
CP
Wb,#encendido5
Comparar Wb con lit5
1
1
C,CC,N,OV,Z
CP
Wb,Ws
Compare Wb con Ws (Wb – Ws)
1
1
C,CC,N,OV,Z
19
CP0
CP0
f
Comparar f con 0x0000
1
1
C,CC,N,OV,Z
CP0
Ws
Comparar Ws con 0x0000
1
1
C,CC,N,OV,Z
20
CPB
CPB
f
Comparar f con WREG, con Borrow
1
1
C,CC,N,OV,Z
CPB
Wb,#encendido5
Comparar Wb con lit5, con Borrow
1
1
C,CC,N,OV,Z
CPB
Wb,Ws
Compare Wb con Ws, con Préstamo
 (Wb – Ws – C)
1
1
C,CC,N,OV,Z
21
CPSEQ
CPSEQ
Wb, Wn
Compare Wb con Wn, omita si =
1
1 
(2 o 3)
Ninguno
22
CPSGT
CPSGT
Wb, Wn
Compare Wb con Wn, omita si >
1
1 
(2 o 3)
Ninguno
23
CPSLT
CPSLT
Wb, Wn
Compare Wb con Wn, omita si <
1
1 
(2 or 3)
Ninguno
24
CPSNE
CPSNE
Wb, Wn
Compare Wb con Wn, omita si ≠
1
1 
(2 o 3)
Ninguno
25
DAW
DAW
Wn
Wn = ajuste decimal Wn
1
1
c
26
DIC
DIC
f
f = f – 1
1
1
C,CC,N,OV,Z
DIC
f,WREG
WREG = f – 1
1
1
C,CC,N,OV,Z
DIC
Ws,Wd
Wd = Ws – 1
1
1
C,CC,N,OV,Z
27
DIC2
DIC2
f
f = f – 2
1
1
C,CC,N,OV,Z
DIC2
f,WREG
WREG = f – 2
1
1
C,CC,N,OV,Z
DIC2
Ws,Wd
Wd = Ws – 2
1
1
C,CC,N,OV,Z
28
DISI
DISI
#lit14
Deshabilitar interrupciones para k ciclos de instrucción
1
1
Ninguno
TABLA 23-2:
RESUMEN DEL CONJUNTO DE INSTRUCCIONES (CONTINUACIÓN)   
bases
instrucción
#
Asamblea
mnemotécnico
Sintaxis de ensamblaje
Descripción
# de 
palabras
# de 
Ciclos
Banderas de estado 
Afectados

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 250
¤ 2009 Microchip Technology Inc.
29
DIV
DIV.S 
Wm,Wn
División entera de 16/16 bits con signo
1
18
N, Z, C, OV
DIV.SD
Wm,Wn
División entera de 32/16 bits con signo
1
18
N, Z, C, OV
DIV.U
Wm,Wn
División entera de 16/16 bits sin signo
1
18
N, Z, C, OV
DIV.UD
Wm,Wn
División entera de 32/16 bits sin signo
1
18
N, Z, C, OV
30
DIVF
DIVF Wm,Wn
División fraccionaria firmada de 16/16 bits
1
18
N, Z, C, OV
31
HACER
HACER
#lit14,expr.
Hacer código a PC + Expr, lit14 + 1 veces
2
2
Ninguno
HACER
Wn, Expr
Hacer código a PC + Expr, (Wn) + 1 veces
2
2
Ninguno
32
DE
DE
Wm*Wm,Acc,Wx,Wy,Wxd
Distancia euclidiana (sin acumulación)
1
1
OA,OB,OAB,
SA,SB,SAB
33
EDAC
EDAC
Wm*Wm,Acc,Wx,Wy,Wxd
Distancia euclidiana 
1
1
OA,OB,OAB,
SA,SB,SAB
34
EXCH
EXCH
Wns,Wnd
Intercambiar Wns con Wnd 
1
1
Ninguno
35
FBCL
FBCL
Ws, viento
Buscar cambio de bits desde el lado izquierdo (MSb) 
1
1
c
36
FF1L
FF1L
Ws, viento
Encuentre el primero desde el lado izquierdo (MSb) 
1
1
c
37
FF1R
FF1R
Ws, viento
Encuentre el primero desde el lado derecho (LSb) 
1
1
c
38
IR A
IR A
Expr.
Ir a la dirección
2
2
Ninguno
IR A
Wn
Ir a indirecto
1
2
Ninguno
39
INC
INC
f
f = f + 1
1
1
C,CC,N,OV,Z
INC
f,WREG
WREG = f + 1
1
1
C,CC,N,OV,Z
INC
Ws,Wd
Wd = Ws + 1
1
1
C,CC,N,OV,Z
40
INC2
INC2
f
f = f + 2
1
1
C,CC,N,OV,Z
INC2
f,WREG
WREG = f + 2
1
1
C,CC,N,OV,Z
INC2
Ws,Wd
Wd = Ws + 2
1
1
C,CC,N,OV,Z
41
IOR
IOR
f
f = f .IOR. WREG
1
1
N,Z
IOR
f,WREG
WREG = f .IOR. WREG
1
1
N,Z
IOR
#lit10,Wn
Wd = lit10 .IOR. Wd
1
1
N,Z
IOR
Wb,Ws,Wd
Wd = Wb .IOR. Ws
1
1
N,Z
IOR
Wb,#lit5,Wd
Wd = Wb .IOR. lit5
1
1
N,Z
42
ALC
ALC
Wso,#Slit4,Acc
Acumulador de carga
1
1
OA,OB,OAB,
SA,SB,SAB
43
LNK
LNK
#lit14
Puntero de marco de enlace
1
1
Ninguno
44
LSR
LSR
f
f = Desplazamiento lógico a la derecha f
1
1
C,N,OV,Z
LSR
f,WREG
WREG = Desplazamiento lógico a la derecha f
1
1
C,N,OV,Z
LSR
Ws,Wd
Wd = Desplazamiento lógico a la derecha Ws
1
1
C,N,OV,Z
LSR
Wb,Wns,Wnd
Wnd = Desplazamiento lógico a la derecha Wb por Wns
1
1
N,Z
LSR
Wb,#lit5,Wnd
Wnd = Desplazamiento lógico a la derecha Wb por lit5
1
1
N,Z
45
MAC
MAC
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd
,
AWB
Multiplicar y acumular
1
1
OA,OB,OAB,
SA,SB,SAB
MAC
Wm*Wm,Acc,Wx,Wxd,Wy,Wyd
Cuadrar y acumular
1
1
OA,OB,OAB,
SA,SB,SAB
46
MOVIMIENTO
MOVIMIENTO
f,Wn
Mover f a Wn
1
1
Ninguno
MOVIMIENTO
f
Mover f a f
1
1
N,Z
MOVIMIENTO
f,WREG
Mover f a WREG
1
1
N,Z
MOVIMIENTO
#lit16,Wn
Mover literal de 16 bits a Wn
1
1
Ninguno
MOV.b
#lit8,Wn
Mover literal de 8 bits a Wn
1
1
Ninguno
MOVIMIENTO
Wn,f
Mover Wn a f
1
1
Ninguno
MOVIMIENTO
Wso,Wdo
Mover Ws a Wd
1
1
Ninguno
MOVIMIENTO
WREG,f
Mover WREG a f
1
1
N,Z
MOV.D Wns,Wd
Mover el doble de W(ns):W(ns + 1) a Wd
1
2
Ninguno
MOV.D Ws,Wnd
Mover el doble de Ws a W(nd + 1):W(nd) 
1
2
Ninguno
47
MOVSAC
MOVSAC
Acc,Wx,Wxd,Wy,Wyd,AWB
Precargar y almacenar acumulador
1
1
Ninguno
TABLA 23-2:
RESUMEN DEL CONJUNTO DE INSTRUCCIONES (CONTINUACIÓN)   
bases
instrucción
#
Asamblea
mnemotécnico
Sintaxis de ensamblaje
Descripción
# de 
palabras
# de 
Ciclos
Banderas de estado 
Afectados

¤ 2009 Microchip Technology Inc.
DS70286C-página 251
dsPIC33FJXXXGPX06/X08/X10
48
MPY
MPY            
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd
Multiplique Wm por Wn al acumulador
1
1
OA,OB,OAB,
SA,SB,SAB
MPY            
Wm*Wm,Acc,Wx,Wxd,Wy,Wyd
Wm cuadrado a acumulador
1
1
OA,OB,OAB,
SA,SB,SAB
49
MPY.N
MPY.N         
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd
-(Multiplicar Wm por Wn) al acumulador
1
1
Ninguno
50
MSC
MSC
Wm*Wm,Acc,Wx,Wxd,Wy,Wyd
,
AWB
Multiplicar y restar del acumulador
1
1
OA,OB,OAB,
SA,SB,SAB
51
MUL
MUL.SS
Wb,Ws,Wnd
{Wnd + 1, Wnd} = firmado(Wb) * firmado(Ws)
1
1
Ninguno
MUL.SU
Wb,Ws,Wnd
{Wnd + 1, Wnd} = con signo (Wb) * sin signo (Ws)
1
1
Ninguno
MUL.US
Wb,Ws,Wnd
{Wnd + 1, Wnd} = sin firmar (Wb) * con signo (Ws)
1
1
Ninguno
MUL.UU
Wb,Ws,Wnd
{Wnd + 1, Wnd} = unsigned(Wb) * 
sin firmar(Ws)
1
1
Ninguno
MUL.SU
Wb,#lit5,Wnd
{Wnd + 1, Wnd} = firmado(Wb) * sin firmar(lit5)
1
1
Ninguno
MUL.UU
Wb,#lit5,Wnd
{Wnd + 1, Wnd} = sin firmar (Wb) * 
sin firmar (lit5)
1
1
Ninguno
MUL
f
W3:W2 = f * WREG 
1
1
Ninguno
52
NEG
NEG
Acc
Negar acumulador
1
1
OA,OB,OAB,
SA,SB,SAB
NEG
f
f = f + 1
1
1
C,CC,N,OV,Z
NEG
f,WREG
WREG = f + 1
1
1
C,CC,N,OV,Z
NEG
Ws,Wd
Wd = Ws + 1
1
1
C,CC,N,OV,Z
53
NOP
NOP
Sin operación
1
1
Ninguno
NOPR
Sin operación
1
1
Ninguno
54
POP
POP
f
Pop f desde la parte superior de la pila (TOS)
1
1
Ninguno
POP
wdo
Pop del Top-of-Stack (TOS) a Wdo
1
1
Ninguno
POP.D
viento
Pop desde Top-of-Stack (TOS) a 
W(nd):W(nd + 1)
1
2
Ninguno
POP.S
Registros de sombras pop
1
1
Todos
55
EMPUJAR
EMPUJAR
f
Empuje f a la parte superior de la pila (TOS)
1
1
Ninguno
EMPUJAR
Wso
Empuje Wso a la parte superior de la pila (TOS)
1
1
Ninguno
EMPUJAR.D
Wns
Empuje W(ns):W(ns + 1) a la parte superior de la pila (TOS)
1
2
Ninguno
EMPUJAR.S
Empujar registros de sombra
1
1
Ninguno
56
PWRSAV
PWRSAV #lit1
Entra en modo de suspensión o inactivo
1
1
WDTO, dormir
57
LLAMADA
LLAMADA
Expr.
Llamada relativa
1
2
Ninguno
LLAMADA
Wn
Computed Call
1
2
Ninguno
58
REPETIR
REPETIR
#lit14
Repita la siguiente instrucción lit14 + 1 veces
1
1
Ninguno
REPETIR
Wn
Repita la siguiente instrucción (Wn) + 1 veces
1
1 
Ninguno
59
REINICIAR
REINICIAR
Restablecer dispositivo de software
1
1 
Ninguno
60
REFIE
REFIE
Regreso de la interrupción 
1
3 (2)
Ninguno
61
RETLW
RETLW
#lit10,Wn
Regresar con literal en Wn
1
3 (2)
Ninguno
62
VOLVER
VOLVER
Regresar de la subrutina
1
3 (2)
Ninguno
63
RLC
RLC
f
f = Girar hacia la izquierda hasta Llevar f
1
1
C,N,Z
RLC
f,WREG
WREG = Girar a la izquierda hasta Llevar f
1
1
C,N,Z
RLC
Ws,Wd
Wd = Girar a la izquierda a través de Llevar Ws
1
1
C,N,Z
64
RLNC
RLNC
f
f = Girar a la izquierda (sin transporte) f
1
1
N,Z
RLNC
f,WREG
WREG = Girar a la izquierda (sin transporte) f
1
1
N,Z
RLNC
Ws,Wd
Wd = Girar a la izquierda (sin transporte) Ws
1
1
N,Z
65
RRC
RRC
f
f = Girar a la derecha hasta Llevar f
1
1
C,N,Z
RRC
f,WREG
WREG = Girar a la derecha hasta Llevar f
1
1
C,N,Z
RRC
Ws,Wd
Wd = Girar a la derecha a través de Llevar Ws
1
1
C,N,Z
TABLA 23-2:
RESUMEN DEL CONJUNTO DE INSTRUCCIONES (CONTINUACIÓN)   
bases
instrucción
#
Asamblea
mnemotécnico
Sintaxis de ensamblaje
Descripción
# de 
palabras
# de 
Ciclos
Banderas de estado 
Afectados

dsPIC33FJXXXGPX06/X08/X10
DS70286C-página 252
¤ 2009 Microchip Technology Inc.
66
RRNC
RRNC
f
f = Girar a la derecha (sin transporte) f
1
1
N,Z
RRNC
f,WREG
WREG = Girar a la derecha (sin transporte) f
1
1
N,Z
RRNC
Ws,Wd
Wd = Girar a la derecha (sin transporte) Ws
1
1
N,Z
67
SACO
SACO
Acc,#Slit4,Wdo
Acumulador de tienda
1
1
Ninguno
SAC.R
Acc,#Slit4,Wdo
Almacenar acumulador redondeado
1
1
Ninguno
68
SE
SE
Ws, viento
Wnd = Ws con signo extendido
1
1
C,N,Z
69
SETM
SETM
f
f = 0xFFFF
1
1
Ninguno
SETM
WREG
WREG = 0xFFFF
1
1
Ninguno
SETM
Ws
Ws = 0xFFFF
1
1
Ninguno
70
SFTAC
SFTAC
Acc, Wn
Acumulador de desplazamiento aritmético por (Wn)
1
1
OA,OB,OAB,
SA,SB,SAB
SFTAC
Acc,#Rendija6
Arithmetic Shift Accumulator by Slit6 
1
1
OA,OB,OAB,
SA,SB,SAB
71
SL
SL
f
f = Desplazamiento a la izquierda f
1
1
C,N,OV,Z
SL
f,WREG
WREG = Desplazamiento a la izquierda f
1
1
C,N,OV,Z
SL
Ws,Wd
Wd = Desplazamiento a la izquierda Ws
1
1
C,N,OV,Z
SL
Wb,Wns,Wnd
Wnd = Desplazamiento a la izquierda Wb por Wns
1
1
N,Z
SL
Wb,#lit5,Wnd
Wnd = Desplazamiento a la izquierda Wb por lit5
1
1
N,Z
72
SUB
SUB
Acc
Restar acumuladores
1
1
OA,OB,OAB,
SA,SB,SAB
SUB
f
f = f – WREG
1
1
C,CC,N,OV,Z
SUB
f,WREG
WREG = f – WREG
1
1
C,CC,N,OV,Z
SUB
#lit10,Wn
Wn = Wn – lit10
1
1
C,CC,N,OV,Z
SUB
Wb,Ws,Wd
Wd = Wb – Ws
1
1
C,CC,N,OV,Z
SUB
Wb,#lit5,Wd
Wd = Wb – lit5
1
1
C,CC,N,OV,Z
73
SUBB
SUBB
f
f = f – WREG – (C)
1
1
C,CC,N,OV,Z
SUBB
f,WREG
WREG = f – WREG – (C)
1
1
C,CC,N,OV,Z
SUBB
#lit10,Wn
Wn = Wn – lit10 – (C)
1
1
C,CC,N,OV,Z
SUBB
Wb,Ws,Wd
Wd = Wb – Ws – (C)
1
1
C,CC,N,OV,Z
SUBB
Wb,#lit5,Wd
Wd = Wb – lit5 – (C)
1
1
C,CC,N,OV,Z
74
SUBR
SUBR
f
f = WREG–f
1
1
C,CC,N,OV,Z
SUBR
f,WREG
WREG = WREG – f
1
1
C,CC,N,OV,Z
SUBR
Wb,Ws,Wd
Wd = Ws – Wb
1
1
C,CC,N,OV,Z
SUBR
Wb,#lit5,Wd
Wd = lit5  –  Wb
1
1
C,CC,N,OV,Z
75
SUBBR
SUBBR
f
f = WREG – f – (C)
1
1
C,CC,N,OV,Z
SUBBR
f,WREG
WREG = WREG – f – (C)
1
1
C,CC,N,OV,Z
SUBBR
Wb,Ws,Wd
Wd = Ws – Wb – (C)
1
1
C,CC,N,OV,Z
SUBBR
Wb,#lit5,Wd
Wd = lit5 – Wb – (C)
1
1
C,CC,N,OV,Z
76
INTERCAMBIAR
INTERCAMBIO.b
Wn
Wn = intercambio de mordiscos Wn
1
1
Ninguno
INTERCAMBIAR
Wn
Wn = intercambio de bytes Wn
1
1
Ninguno
77
TBLRDH
TBLRDH
Ws,Wd
Leer Prog<23:16> a Wd<7:0>
1
2
Ninguno
78
TBLRDL
TBLRDL
Ws,Wd
Leer Prog<15:0> a Wd
1
2
Ninguno
79
TBLWTH
TBLWTH
Ws,Wd
Escriba Ws<7:0> en Prog<23:16>
1
2
Ninguno
80
TBLWTL
TBLWTL
Ws,Wd
Escribir Ws en Prog<15:0>
1
2
Ninguno
81
ULNK
ULNK
Puntero de marco de desvinculación
1
1
Ninguno
82
XOR
XOR
f
f = f .XOR. WREG
1
1
N,Z
XOR
f,WREG
WREG = f .XOR. WREG
1
1
N,Z
XOR
#lit10,Wn
Wd = lit10 .XOR. Wd
1
1
N,Z
XOR
Wb,Ws,Wd
Wd = Wb .XOR. Ws
1
1
N,Z
XOR
Wb,#lit5,Wd
Wd = Wb .XOR. lit5
1
1
N,Z
83
ZE
ZE
Ws, viento
Wnd = Ws de extensión cero
1
1
C,Z,N
TABLA 23-2:
RESUMEN DEL CONJUNTO DE INSTRUCCIONES (CONTINUACIÓN)   
bases
instrucción
#
Asamblea
mnemotécnico
Sintaxis de ensamblaje
Descripción
# de 
palabras
# de 
Ciclos
Banderas de estado 
Afectados
