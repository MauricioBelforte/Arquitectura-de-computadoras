# Traducción de d:\Escritorio\INFORMATICA\ARQUITECTURA DE COMPUTADORAS\MCU_and_DSC_prog_Reference_Manual (Set de instrucciones completo).pdf

¤ 2009 Microchip Technology Inc.
 
DS70157D
Programa MCU y DSC de 16 bits
Manual de referencia de Mer
Microcontroladores de alto rendimiento (MCU)
y controladores de señal digital (DSC)

DS70157D-página 2 
¤ 2009 Microchip Technology Inc. 
Información contenida en esta publicación sobre el dispositivo. 
aplicaciones y similares se proporcionan sólo para su conveniencia 
y puede ser reemplazado por actualizaciones. Es tu responsabilidad 
asegúrese de que su aplicación cumpla con sus especificaciones. 
PASTILLA 
MARCAS 
NO 
REPRESENTACIONES 
O 
GARANTÍAS DE NINGÚN TIPO YA SEA EXPRESA O 
IMPLÍCITO, 
ESCRITO 
O 
ORAL, 
ESTATUTARIO 
O 
DE LO CONTRARIO, 
RELACIONADO 
A 
EL 
INFORMACIÓN, 
INCLUYENDO PERO NO LIMITADO A SU CONDICIÓN, 
CALIDAD, 
ACTUACIÓN, 
COMERCIABILIDAD 
O 
IDONEIDAD PARA EL PROPÓSITO. Microchip se exime de toda responsabilidad 
que surjan de esta información y su uso. Uso de microchip 
dispositivos en aplicaciones de soporte vital y/o seguridad está completamente en 
riesgo del comprador, y el comprador se compromete a defender, indemnizar y 
eximir de responsabilidad a Microchip de todos y cada uno de los daños, reclamaciones, 
demandas o gastos resultantes de dicho uso. No hay licencias 
transmitido, implícitamente o de otro modo, bajo cualquier Microchip 
derechos de propiedad intelectual. 
Marcas registradas 
El nombre y el logotipo de Microchip, el logotipo de Microchip, dsPIC, 
KEELOQ, logotipo de KEELOQ, MPLAB, PIC, PICmicro, PICSTART, 
rfPIC y UNI/O son marcas registradas de Microchip 
Tecnología incorporada en EE.UU. y otros países. 
FilterLab, Hampshire, HI-TECH C, termistor activo lineal, 
MXDEV, MXLAB, SEEVAL y el control integrado 
Solutions Company son marcas registradas de Microchip 
Tecnología incorporada en EE.UU. 
Analógico para la era digital, Application Maestro, CodeGuard, 
dsPICDEM, dsPICDEM.net, dsPICworks, dsSPEAK, ECAN, 
ECONOMONITOR, FanSense, HI-TIDE, Serie en circuito 
Programación, ICSP, Mindi, MiWi, MPASM, certificación MPLAB 
logotipo, MPLIB, MPLINK, mTouch, Octopus, Código Omnisciente 
Generación, PICC, PICC-18, PICDEM, PICDEM.net, PICkit, 
PICtail, logotipo PIC32, REAL ICE, rfLAB, Modo de selección, Total 
Resistencia, TSHARC, UniWinDriver, WiperLock y ZENA 
son marcas comerciales de Microchip Technology Incorporated en el 
Estados Unidos y otros países. 
SQTP es una marca de servicio de Microchip Technology Incorporated 
en los EE.UU. 
Todas las demás marcas comerciales mencionadas en este documento son propiedad de sus 
respectivas empresas. 
© 2009, Microchip Technology Incorporated, Impreso en el 
EE.UU., todos los derechos reservados. 
Impreso en papel reciclado. 
Tenga en cuenta los siguientes detalles de la función de protección de código en dispositivos Microchip: 
• 
Los productos Microchip cumplen con las especificaciones contenidas en su particular Hoja de Datos de Microchip. 
• 
Microchip cree que su familia de productos es una de las más seguras de su tipo en el mercado hoy en día, cuando se utiliza en el 
forma prevista y en condiciones normales. 
• 
Se utilizan métodos deshonestos y posiblemente ilegales para violar la función de protección del código. Todos estos métodos, a nuestra 
conocimiento, requieren el uso de los productos Microchip de una manera fuera de las especificaciones operativas contenidas en los Datos de Microchip 
Hojas. Lo más probable es que la persona que lo haga se dedique al robo de propiedad intelectual. 
• 
Microchip está dispuesto a trabajar con el cliente que está preocupado por la integridad de su código. 
• 
Ni Microchip ni ningún otro fabricante de semiconductores pueden garantizar la seguridad de su código. La protección del código no 
significa que estamos garantizando que el producto es “irrompible”. 
La protección del código está en constante evolución. En Microchip estamos comprometidos a mejorar continuamente las funciones de protección de código de nuestro 
productos. Los intentos de violar la función de protección del código de Microchip pueden constituir una violación de la Ley de derechos de autor del milenio digital. Si tales actos 
permite el acceso no autorizado a su software u otro trabajo protegido por derechos de autor, es posible que tenga derecho a demandar para obtener reparación en virtud de esa Ley. 
Microchip recibió la certificación ISO/TS-16949:2002 para su 
sede, instalaciones de diseño y fabricación de obleas en Chandler y 
Tempe, Arizona; Gresham, Oregon y centros de diseño en California 
e India. The Company’s quality system processes and procedures 
son para sus MCU PIC® y DSC dsPIC®, salto de código KEELOQ® 
dispositivos, EEPROM seriales, microperiféricos, memoria no volátil y 
productos analógicos. Además, el sistema de calidad de Microchip para el diseño 
y la fabricación de sistemas de desarrollo cuenta con la certificación ISO 9001:2000. 

¤ 2009 Microchip Technology Inc. 
DS70157D-página 3 
PÁGINA 
SECCIÓN 1. INTRODUCCIÓN 
5 
Introducción ........................................................................................................................................................ 6 
Objetivo manual ................................................................................................................................................ 6 
Apoyo al desarrollo ........................................................................................................................................ 6 
Convenciones de estilo y símbolos ................................................................................................................................ 7 
Símbolos del conjunto de instrucciones ................................................................................................................................ 8 
Documentos relacionados ................................................................................................................................................ 9 
SECCIÓN 2. MODELO DEL PROGRAMADOR 
11 
Descripción general de la arquitectura central DSC y MCU de 16 bits ................................................................................ 12 
Modelo del programador ......................................................................................................................................... 14 
Matriz de registros de trabajo ................................................................................................................................ 17 
Registro de trabajo predeterminado (WREG) ................................................................................................................ 17 
Puntero del marco de pila de software ................................................................................................................ 18 
SECCIÓN 3. DESCRIPCIÓN GENERAL DEL JUEGO DE INSTRUCCIONES 
29 
Introducción................................................................................................................................................................ 30 
Descripción general del conjunto de instrucciones ................................................................................................................ 30 
Tablas de resumen del conjunto de instrucciones ......................................................................................................... 32 
SECCIÓN 4. DETALLES DEL JUEGO DE INSTRUCCIONES 
41 
Modos de direccionamiento de datos ................................................................................................................................ 42 
Modos de direccionamiento del programa ................................................................................................................ 51 
Puestos de instrucción ................................................................................................................................................ 52 
Operaciones de bytes ................................................................................................................................................ 54 
Operaciones de movimiento de palabras ................................................................................................................................ 56 
Uso de operandos literales de 10 bits ................................................................................................................ 59 
Puntero de pila de software y puntero de marco ................................................................................................. 60 
Instrucciones de sucursal condicional ................................................................................................................ 65 
Bit de estado Z ........................................................................................................................................................ 66 
Uso del registro de trabajo asignado ................................................................................................................ 67 
Formatos de datos DSP (dispositivos dsPIC30F y dsPIC33F) ................................................................................ 70 
Uso del acumulador (dispositivos dsPIC30F y dsPIC33F) ................................................................................. 72 
Acceso al acumulador (dispositivos dsPIC30F y dsPIC33F) ................................................................................. 73 
Instrucciones DSP MAC (dispositivos dsPIC30F y dsPIC33F) ................................................................................ 74 
Instrucciones del acumulador DSP (dispositivos dsPIC30F y dsPIC33F) ................................................................ 78 
Escalado de datos con la instrucción FBCL (dispositivos dsPIC30F y dsPIC33F) ................................................ 79 
Normalización del acumulador con la instrucción FBCL (dispositivos dsPIC30F y dsPIC33F) ................. 81 
SECCIÓN 5. DESCRIPCIONES DE LAS INSTRUCCIONES 
83 
Símbolos de instrucción ................................................................................................................................................ 84 
Introducción a los descriptores de campos de codificación de instrucciones ................................................................. 84 
Ejemplo de descripción de instrucción ........................................................................................................................ 88 
Descripciones de instrucciones ................................................................................................................................ 89 
SECCIÓN 6. REFERENCIA 
357 
Mapa de bits de instrucción ................................................................................................................................ 358 
Tabla de resumen del conjunto de instrucciones ........................................................................................................ 360 
Historial de revisiones ................................................................................................................................................ 367 
Tabla de contenido 

DS70157D-página 4
 2009 Microchip Technology Inc.
Manual de referencia del programador MCU y DSC de 16 bits
SECCIÓN 7. ÍNDICE
 369
SECCIÓN 8. VENTAS Y SERVICIO MUNDIAL
 374

© 2009 Microchip Technology Inc.
DS70157D-página 5
Introducción
1
Sección 1. Introducción
DESTACADOS
Esta sección del manual contiene los siguientes temas:
1.1
Introducción ................................................................................................................................ 6
1.2
Objetivo manual................................................................................................................ 6
1.3
Apoyo al desarrollo ................................................................................................................ 6
1.4
Convenciones de estilo y símbolos ......................................................................................... 7
1.5
Símbolos del conjunto de instrucciones ........................................................................................ 8
1.6
Documentos relacionados ................................................................................................................ 9

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 6
© 2009 Microchip Technology Inc.
1.1
 INTRODUCCIÓN
El enfoque de Microchip Technology está en productos que satisfacen las necesidades del control integrado.
mercado. Somos un proveedor líder de:
• Microcontroladores de uso general de 8 bits (PIC® MCU)
• Controladores de señal digital de 16 bits (DSC dsPIC®)
• Microcontroladores (MCU) de 16 y 32 bits
• Dispositivos de memoria no volátil estándar y especiales
• Dispositivos de seguridad (KEELOQ® Security IC)
• Productos estándar para aplicaciones específicas
Solicite una Guía de selección de productos de Microchip para obtener una lista de todos los productos interesantes que
tenemos para ofrecer. Esta documentación se puede obtener en su oficina de ventas local o descargar desde
el sitio web de Microchip (www.microchip.com).
1.2
 OBJETIVO MANUAL
Este manual es una referencia para desarrolladores de software para las familias de dispositivos MCU y DSC de 16 bits.
Este manual describe el conjunto de instrucciones en detalle y también proporciona información general para ayudar
al usuario en el desarrollo de software para las familias MCU y DSC de 16 bits.
Este manual no incluye información detallada sobre el núcleo, los periféricos y la integración del sistema.
o información específica del dispositivo. El usuario debe consultar la referencia de la familia de dispositivos específica.
manual para obtener información sobre el núcleo, los periféricos y la integración del sistema. Para dispositivos específicos
información, el usuario debe consultar las hojas de datos individuales. La información que se puede encontrar
en las hojas de datos incluye:
• Mapa de memoria del dispositivo
• Detalles de empaquetado y configuración de pines del dispositivo
• Especificaciones eléctricas del dispositivo
• Lista de periféricos incluidos en el dispositivo
A lo largo de este manual se proporcionan ejemplos de código. Estos ejemplos son válidos para cualquier dispositivo en
las familias MCU y DSC de 16 bits.
1.3
 APOYO AL DESARROLLO
Microchip ofrece una amplia gama de herramientas de desarrollo que permiten a los usuarios desarrollar y
depurar el código de la aplicación. Las herramientas de desarrollo de Microchip se pueden dividir en cuatro categorías:
• Generación de código
• Depuración de hardware/software
• Programador de dispositivos
• Tableros de evaluación de productos
Puede obtener información sobre las últimas herramientas, resúmenes de productos y guías de usuario en
Sitio web de Microchip (www.microchip.com) o en su oficina de ventas local de Microchip.
Microchip ofrece otras herramientas de referencia para acelerar el ciclo de desarrollo. Estos incluyen:
• Notas de aplicación 
• Diseños de referencia 
• Sitio web sobre microchips 
• Oficinas de ventas locales con soporte para aplicaciones de campo 
• Línea de Soporte Corporativa 
El sitio web de Microchip también enumera otros sitios que pueden ser referencias útiles.

© 2009 Microchip Technology Inc.
DS70157D-página 7
Sección 1. Introducción
Introducción
1
1.4
 CONVENCIONES DE ESTILO Y SÍMBOLO
A lo largo de este documento, se utilizan ciertas convenciones de estilo y formato de fuente. La mayoría del formato
Las convenciones implican que se debe hacer una distinción para el texto resaltado. La industria del MCU
tiene muchos símbolos y definiciones/abreviaturas de palabras no convencionales. La Tabla 1-1 proporciona una
descripción de las convenciones utilizadas en este documento.
Tabla 1-1:
Convenciones de documentos  
Símbolo o término
Descripción
conjunto
Para forzar un bit/registro a un valor lógico ‘1’.
claro
Para forzar un bit/registro a un valor lógico ‘0’.
Reiniciar
1.
Para forzar un registro/bit a su estado predeterminado. 
2.
Una condición en la que el dispositivo se coloca después de un reinicio del dispositivo.
ocurre. Algunos bits serán forzados a ‘0’ (como los bits de habilitación de interrupción),
mientras que otros se verán obligados a ‘1’ (como los bits de dirección de datos de E/S).
0xnnnn
Designa el número ‘nnnn’ en el sistema numérico hexadecimal. Estos 
Se utilizan convenciones en los ejemplos de código. Por ejemplo, 0x013F o 
0xA800.
: (dos puntos)
Se utiliza para especificar un rango o la concatenación de registros/bits/pins. 
Un ejemplo es ACCAU:ACCAH:ACCAL, que es la concatenación de 
tres registros para formar el acumulador de 40 bits.
El orden de concatenación (izquierda-derecha) generalmente especifica una relación posicional. 
(MSb a LSb, de mayor a menor).
< >
Especifica ubicaciones de bits en un registro particular. 
Un ejemplo es SR<7:5> (o IPL<2:0>), que especifica el registro y 
bits asociados o posiciones de bits.
LSb, MSb 
Indica el bit menos significativo o el más significativo de un campo.
LSB, MSB
Indica el byte menos/más significativo en un campo de bits.
lsw, msw
Indica la palabra más/menos significativa en un campo de bits.
Fuente de mensajería
Se utiliza para ejemplos de código, números binarios y mnemotécnicos de instrucciones. 
en el texto.
tiempos nuevos 
Fuente romana, cursiva
Se utiliza para ecuaciones y variables.
tiempos nuevos 
fuente romana, 
Negrita cursiva
Se utiliza en texto explicativo para elementos llamados de una figura, ecuación o 
ejemplo. 
Nota:
Una Nota presenta información que queremos volver a enfatizar, ya sea para ayudar 
evitar un error común o informarle sobre las diferencias operativas 
entre algunos miembros de la familia de dispositivos. En la mayoría de los casos, se utiliza una nota. 
en un cuadro sombreado (como se ilustra a continuación); sin embargo, cuando se hace referencia en un 
tabla, aparecerá una nota en la parte inferior de la tabla asociada (consulte 
Tabla 1-2).
Nota:
Esta es una nota en un cuadro de notas sombreado.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 8
© 2009 Microchip Technology Inc.
1.5
 SÍMBOLOS DEL CONJUNTO DE INSTRUCCIONES
Las tablas de resumen en la Sección 3.2 “Descripción general del conjunto de instrucciones” y la Sección 6.2 “Instrucción
Establecer tabla de resumen”, y las descripciones de instrucciones en la Sección 5.4 “Instrucción
Descripciones” utilizan los símbolos que se muestran en la Tabla 1-2. 
Tabla 1-2:
     Símbolos utilizados en descripciones y tablas de resumen de instrucciones
Símbolo(1)
Descripción
{ }
Campo u operación opcional
[texto]
La ubicación a la que se dirige el mensaje de texto.
(texto)
El contenido del texto.
#texto
El literal definido por el texto.
a ∈[b, c, d] “a” debe estar en el conjunto de [b, c, d]
<n:m>
Campo de bits de registro
{etiqueta:}
Nombre de etiqueta opcional
Acc
Acumulador A o Acumulador B
AWB
Reescritura del acumulador
bit4
Posición de bits de 4 bits de ancho (0:7 en modo Byte, 0:15 en modo Word)
Expr.
Dirección, etiqueta o expresión absoluta (resuelta por el vinculador)
f
Dirección de registro de archivos
lit1
Literal de 1 bit (0:1)
lit4
Literal de 4 bits (0:15)
lit5
Literal de 5 bits (0:31)
lit8
Literal de 8 bits (0:255)
iluminado10
Literal de 10 bits (0:255 en modo Byte, 0:1023 en modo Word)
iluminado14
Literal de 14 bits (0:16383)
iluminado16
Literal de 16 bits (0:65535)
lit23
Literal de 23 bits (0:8388607)
hendidura4
Literal de 4 bits firmado (-8:7)
rendija6
Literal de 6 bits con signo (-32:31) (el rango está limitado a -16:16)
hendidura10
Literal de 10 bits firmado (-512:511)
hendidura16
Literal de 16 bits firmado (-32768:32767)
Términos de servicio
Parte superior de la pila
Wb
registro base de trabajo 
Wd
Registro de trabajo de destino (direccionamiento directo e indirecto)
Wm, Wn
Par de división de registro de trabajo (dividendo, divisor)
Wm * Wm
Par multiplicador de registros de trabajo (mismo registro fuente)
Wm * Wn
Par multiplicador de registros de trabajo (diferentes registros de origen)
Wn
Registro de trabajo tanto de origen como de destino (direccionamiento directo)
viento
Registro de trabajo de destino (direccionamiento directo)
Wns
Registro de trabajo fuente (direccionamiento directo)
WREG
Registro de trabajo predeterminado (asignado a W0)
Ws
Registro de trabajo fuente (direccionamiento directo e indirecto)
Wx
Modo de direccionamiento de origen y registro de trabajo para la captación previa del bus de datos X
Wxd
Registro de trabajo de destino para la captación previa del bus de datos X 
Wy
Modo de direccionamiento de origen y registro de trabajo para la captación previa del bus de datos Y
Wyd
Registro de trabajo de destino para la captación previa del bus de datos Y
Nota 1:
El rango de cada símbolo depende de la instrucción. Consulte la sección 
5. “Descripciones de instrucciones” para el rango de instrucciones específico.

© 2009 Microchip Technology Inc.
DS70157D-página 9
Sección 1. Introducción
Introducción
1
1.6
 DOCUMENTOS RELACIONADOS
Microchip, así como otras fuentes, ofrecen documentación adicional que puede ayudarle en su
Desarrollo con MCU y DSC de 16 bits. Estas listas contienen la documentación más común,
pero también pueden estar disponibles otros documentos. Por favor consulte el sitio web de Microchip.
(www.microchip.com) para obtener la documentación técnica publicada más reciente.
1.6.1
Documentación de terceros
Hay varios documentos disponibles de fuentes de terceros en todo el mundo. Microchip
no revisa estos documentos para verificar su precisión técnica. Sin embargo, pueden ser una fuente útil.
para comprender el funcionamiento de dispositivos MCU y DSC de Microchip de 16 bits. Por favor consulte el
Sitio web de Microchip (www.microchip.com) para obtener documentación de terceros relacionada con la MCU de 16 bits
y familias DSC.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 10
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70157D-página 11
Programador 
modelo
2
Sección 2. Modelo del programador
DESTACADOS
Esta sección del manual contiene los siguientes temas:
2.1
Descripción general de la arquitectura central de MCU y DSC de 16 bits ........................................ 12
2.2
Modelo del programador................................................................................................... 14
2.3
Matriz de registros de trabajo................................................................................................ 17
2.4
Registro de trabajo predeterminado (WREG) ................................................................................. 17
2.5
Puntero del marco de pila de software ......................................................................... 18

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 12
© 2009 Microchip Technology Inc.
2.1
 DESCRIPCIÓN GENERAL DE LA ARQUITECTURA CENTRAL DE DSC Y MCU DE 16 BITS
Esta sección proporciona una descripción general de las características y capacidades de la arquitectura de 16 bits para
siguientes familias de dispositivos:
• Microcontroladores (MCU) de 16 bits:
- PIC24F
- PIC24H
• Controladores de señal digital (DSC) de 16 bits:
- dsPIC30F
- dsPIC33F
2.1.1
Características específicas de MCU de 16 bits y núcleo DSC
El núcleo de los dispositivos MCU y DSC de 16 bits es una arquitectura Harvard modificada de 16 bits (datos) con
un conjunto de instrucciones mejorado. El núcleo tiene una palabra de instrucción de 24 bits, con un campo de código de operación de 8 bits.
El contador de programa (PC) tiene 23 bits de ancho y direcciona hasta 4 M x 24 bits de programa de usuario.
espacio de memoria. Se utiliza un mecanismo de captación previa de instrucciones para ayudar a mantener el rendimiento y
Proporciona una ejecución predecible. La mayoría de las instrucciones se ejecutan en un solo ciclo.
2.1.1.1
REGISTROS
Los dispositivos MCU y DSC de 16 bits tienen dieciséis registros de trabajo de 16 bits. Cada uno de los trabajadores
Los registros pueden actuar como registros de datos, direcciones o compensaciones. Funciona el 16º registro de trabajo (W15)
como software Stack Pointer para interrupciones y llamadas.
2.1.1.2
JUEGO DE INSTRUCCIONES
El conjunto de instrucciones es casi idéntico para las arquitecturas MCU y DSC de 16 bits. la instrucción
El conjunto incluye muchos modos de direccionamiento y fue diseñado para una eficiencia óptima del compilador de C. 
2.1.1.3
DIRECCIONAMIENTO DEL ESPACIO DE DATOS
El espacio de datos se puede direccionar como 32 K palabras o 64 Kbytes. Los 32 Kbytes superiores de los datos.
El mapa de memoria espacial se puede asignar opcionalmente al espacio del programa en cualquier palabra de programa de 16 K
límite, una característica conocida como Visibilidad del Espacio del Programa (PSV). El programa al espacio de datos.
La función de mapeo permite que cualquier instrucción acceda al espacio del programa como si fuera el espacio de datos, que es
útil para almacenar coeficientes de datos.
2.1.1.4
MODOS DE DIRECCIONAMIENTO
El núcleo admite inherente (sin operando), relativo, literal, memoria directa, registro directo,
Registre los modos de direccionamiento indirecto y de registro compensado. Cada instrucción está asociada a una
grupo de modos de direccionamiento predefinido, dependiendo de sus requisitos funcionales. Hasta 7
Se admiten modos de direccionamiento para cada instrucción.
Para la mayoría de las instrucciones, la CPU es capaz de ejecutar una lectura de memoria de datos (o datos de programa), una
lectura de registro de trabajo (datos), escritura de memoria de datos y lectura de memoria de programa (instrucciones) por
ciclo de instrucción. Como resultado, se pueden admitir instrucciones de 3 operandos, lo que permite A + B = C
operaciones a ejecutar en un solo ciclo.
2.1.1.5
UNIDAD ARITMÉTICA Y LÓGICA
Se incluye un multiplicador de alta velocidad de 17 bits por 17 bits para mejorar significativamente la aritmética central.
capacidad y rendimiento. El multiplicador admite los modos firmado, no firmado y mixto, de 16 bits por
Multiplicación de enteros de 16 bits u 8 bits por 8 bits. Todas las instrucciones de multiplicación se ejecutan en un solo ciclo.
La unidad lógica aritmética (ALU) de 16 bits está mejorada con hardware de asistencia de división de enteros que
admite un algoritmo de división iterativo sin restauración. Opera en conjunto con el REPEAT
mecanismo de bucle de instrucciones y una selección de instrucciones de división iterativas para admitir 32 bits
(o 16 bits) dividido por una división entera de 16 bits con y sin signo. Todas las operaciones de división requieren 19
ciclos para completar, pero son interrumpibles en cualquier límite del ciclo.

© 2009 Microchip Technology Inc.
DS70157D-página 13
Sección 2. Modelo del programador
Programador 
modelo
2
2.1.1.6
TRÁMITE DE EXCEPCIÓN
Los dispositivos MCU y DSC de 16 bits tienen un esquema de excepción vectorial compatible con hasta 8
fuentes de trampas no enmascarables y hasta 118 fuentes de interrupción. En ambas familias, cada interrupción
La fuente se puede asignar a uno de los siete niveles de prioridad.
2.1.2
Funciones dsPIC30F y dsPIC33F
Además de la información proporcionada en 2.1.1 “Características específicas de MCU y DSC de 16 bits
Core”, esta sección describe las mejoras de DSP que están disponibles en el dsPIC30F y
Familias de dispositivos dsPIC33F.
2.1.2.1
CONSTRUCCIONES DE BUCLE DE PROGRAMACIÓN
Las construcciones de bucle de programa gratuitas se admiten mediante la instrucción DO, que es
interrumpible.
2.1.2.2
CLASE DE INSTRUCCIÓN DSP
La clase de instrucciones DSP se integra perfectamente en la arquitectura y se ejecuta desde
una única unidad de ejecución.
2.1.2.3
DIRECCIONAMIENTO DEL ESPACIO DE DATOS
El espacio de datos se divide en dos bloques, denominados memoria de datos X e Y. Cada bloque de memoria
tiene su propia Unidad de Generación de Direcciones (AGU) independiente. La clase de instrucciones MCU opera
únicamente a través de la memoria X AGU, que accede a todo el mapa de memoria como un dato lineal
espacio. La clase de instrucciones de fuente dual DSP opera a través de las AGU X e Y, que
divide el espacio de direcciones de datos en dos partes. El límite del espacio de datos X e Y es arbitrario y
específico del dispositivo.
2.1.2.4
DIRECCIONAMIENTO DE MÓDULO Y DE BIT INVERTIDO
Se admiten buffers circulares libres (direccionamiento de módulo) en direcciones X e Y
espacios. El direccionamiento de módulo elimina la sobrecarga de verificación de límites del software para DSP
algoritmos. Además, el direccionamiento circular X AGU se puede utilizar con cualquiera de las clases de MCU.
de instrucciones. La X AGU también admite direccionamiento de bit inverso, para simplificar enormemente la entrada o
Reordenación de datos de salida para algoritmos FFT radix-2.
2.1.2.5
MOTOR DSP
El motor DSP presenta un multiplicador de alta velocidad de 17 bits por 17 bits, una ALU de 40 bits, dos
acumuladores de saturación y una palanca de cambios de barril bidireccional de 40 bits. La palanca de cambios de barril es capaz de
desplazar un valor de 40 bits, hasta 16 bits a la derecha o hasta 16 bits a la izquierda, en un solo ciclo. El DSP
Las instrucciones funcionan perfectamente con todas las demás instrucciones y han sido diseñadas para una óptima
rendimiento en tiempo real. La instrucción MAC y otras instrucciones asociadas pueden simultáneamente
recupera dos operandos de datos de la memoria mientras multiplica dos registros de trabajo. Esto requiere que
el espacio de datos se dividirá para estas instrucciones y será lineal para todas las demás. Esto se logra en un
manera transparente y flexible mediante la dedicación de determinados registros de trabajo a cada dirección
espacio.
2.1.2.6
TRÁMITE DE EXCEPCIÓN
Los dispositivos dsPIC30F tienen un esquema de excepción vectorial con soporte para hasta 8 fuentes de
trampas no enmascarables y hasta 54 fuentes de interrupción. Los dispositivos dsPIC33F tienen un similar
esquema de excepción, pero admite hasta 118 fuentes de interrupción. En ambas familias, cada interrupción
La fuente se puede asignar a uno de los siete niveles de prioridad.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 14
© 2009 Microchip Technology Inc.
2.2
 MODELO DEL PROGRAMADOR
La Figura 2-1 a la Figura 2-2 muestra los diagramas del modelo del programador para la MCU de 16 bits y
Familias de dispositivos DSC.
Figura 2-1:
Diagrama del modelo del programador PIC24F y PIC24H
TABPAG
22
0
7
0
0
15
Contador de programas
Dirección de la página de la tabla de datos
Registro de estado
Registros de trabajo
W1
W2
W3
W4
W5
W6
W7
W8
W9
W10
W11
W12
W13
W14/Puntero de marco
W15/Puntero de pila
PSVPAG
7
0
Dirección de la página de visibilidad del espacio del programa
z
—
—
—
—
RCONTAR
15
 0
REPETIR contador de bucles
IPL2 IPL1
SPLIM
Registro de límite de puntero de pila
srl
PUSH.S Sombra
—
—
15
0
 Registro de control del núcleo de la CPU 
Leyenda
CORCÓN
—
CC
RA
norte
c
TBLPAG
PSVPAG
IPL0
VO
W0/WREG
SSR 
DIV y MUL
Registros de resultados

© 2009 Microchip Technology Inc.
DS70157D-página 15
Sección 2. Modelo del programador
Programador 
modelo
2
Figura 2-2:
Diagrama del modelo del programador dsPIC30F y dsPIC33F
TABPAG
22
0
7
0
0
15
Contador de programas
Dirección de la página de la tabla de datos
Registro de estado
Registros de trabajo
Operando MAC
Registros
W1
W2
W3
W4
W5
W6
W7
W8
W9
W10
W11
Compensación W12/MAC
W13/MAC Reescritura
W14/Puntero de marco
W15/Puntero de pila
Dirección MAC
Registros
39
0
31
DSP
Acumuladores
ACCA
ACCB
PSVPAG
7
0
Dirección de la página de visibilidad del espacio del programa
z
OA
OB
SA
SB
RCONTAR
15
0
REPETIR contador de bucles
DCUENTO
15
0
Contador de bucle DO
DOSTART
22
0
Dirección de inicio del bucle DO
IPL2 IPL1
SPLIM
Registro de límite de puntero de pila
15
srl
PUSH.S Sombra
HACER sombra
OAB SAB
15
0
 Registro de control del núcleo de la CPU 
Leyenda
CORCÓN
DA
CC
RA
norte
c
TBLPAG
PSVPAG
IPL0
VO
W0/WREG
SSR 
Dirección final del bucle DO
FINALIZAR
22
0
DIV y MUL
Registros de resultados

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 16
© 2009 Microchip Technology Inc.
Todos los registros en el modelo del programador están mapeados en memoria y pueden manipularse directamente mediante
el conjunto de instrucciones. En la Tabla 2-1 se proporciona una descripción de cada registro.
Nota:
A menos que se especifique lo contrario, las Descripciones de Registro del Modelo del Programador en
La Tabla 2-1 se aplica a todas las familias de dispositivos MCU y DSC.
Tabla 2-1:
Descripciones de registros de modelos del programador
Registrarse
Descripción
CORCÓN
Registro de configuración del núcleo de la CPU
ordenador personal
Contador de programa de 23 bits
PSVPAG
Programa Espacio Visibilidad Página Registro de direcciones
RCONTAR
Repetir registro de conteo de bucles
SPLIM
Registro de valor límite de puntero de pila
SR
Registro de ESTADO del motor ALU y DSP
TBLPAG
Registro de dirección de página de memoria de tabla
W0-W15
Matriz de registros de trabajo
ACCA, ACCB(1)
Acumuladores DSP de 40 bits
DCUENTA(1)
Registro de recuento de bucles DO
FINALIZAR(1)
Registro de dirección final del bucle DO
DOINICIO(1)
Registro de dirección de inicio del bucle DO
Nota 1:
Este registro solo está disponible en dispositivos dsPIC30F y dsPIC33F.

© 2009 Microchip Technology Inc.
DS70157D-página 17
Sección 2. Modelo del programador
Programador 
modelo
2
2.3
 MATRIZ DE REGISTRO DE TRABAJO
Los 16 registros de trabajo (W) pueden funcionar como registros de datos, direcciones o compensaciones. La función de un
El registro W está determinado por la instrucción que accede a él.
Las instrucciones de bytes, que apuntan a la matriz de registros de trabajo, solo afectan el byte menos significativo
(LSB) del registro de destino. Dado que los registros de trabajo están mapeados en memoria, el mínimo y el mayor
Los bytes significativos (MSB) se pueden manipular mediante accesos al espacio de memoria de datos de todo el byte.
2.4
 REGISTRO DE TRABAJO PREDETERMINADO (WREG)
El conjunto de instrucciones se puede dividir en dos tipos de instrucciones: instrucciones de registro de trabajo y instrucciones de archivo.
instrucciones de registro. Las instrucciones del registro de trabajo utilizan la matriz de registros de trabajo como datos. 
valores, o como direcciones que apuntan a una ubicación de memoria. Por el contrario, las instrucciones de registro de archivos
operar en una dirección de memoria específica contenida en el código de operación de la instrucción.
Las instrucciones de registro de archivos que también utilizan un registro de trabajo no especifican el registro de trabajo que
se utilizará para la instrucción. En su lugar, se utiliza un registro de trabajo predeterminado (WREG) para estos archivos.
instrucciones de registro. El registro de trabajo, W0, se asigna como WREG. La tarea WREG
no es programable.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 18
© 2009 Microchip Technology Inc.
2.5
 PUNTERO DEL MARCO DE PILA DE SOFTWARE
Un marco es una sección de memoria definida por el usuario en la pila, utilizada por una función para asignar memoria.
para variables locales. W14 ha sido asignado para su uso como puntero de marco de pila con el enlace (LNK)
y desvincular instrucciones (ULNK). Sin embargo, si un puntero de marco de pila y el LNK y ULNK
No se utilizan instrucciones, W14 puede ser utilizado por cualquier instrucción de la misma manera que todas las demás.
Registros W. Consulte 4.7.2 “Puntero del marco de pila de software” para obtener información detallada sobre el
Puntero de marco.
2.5.1
Puntero de pila de software
W15 sirve como un puntero de pila de software dedicado y se modificará automáticamente según la función.
llamadas, procesamiento de excepciones y devoluciones. Sin embargo, se puede hacer referencia a W15 mediante cualquier instrucción en
de la misma manera que todos los demás registros W. Esto simplifica la lectura, escritura y manipulación del
Puntero de pila. Consulte 4.7.1 “Puntero de pila de software” para obtener información detallada sobre la pila.
Puntero.
2.5.2
Registro de límite de puntero de pila (SPLIM)
SPLIM es un registro de 16 bits asociado con el puntero de pila. Se utiliza para prevenir la pila.
El puntero se desborda y accede a la memoria más allá de la región de la pila asignada por el usuario
memoria. Consulte 4.7.3 “Desbordamiento del puntero de pila” para obtener información detallada sobre SPLIM.
2.5.3
Acumulador A, Acumulador B (dsPIC30F y dsPIC33F 
Dispositivos)
El acumulador A (ACCA) y el acumulador B (ACCB) son registros de 40 bits de ancho, utilizados por DSP
instrucciones para realizar operaciones matemáticas y de desplazamiento. Cada acumulador se compone de
3 registros mapeados en memoria:
• AccxU (bits 39-32)
• AccxH (bits 31-16)
• AccxL (bits 15-0)
Consulte 4.12 “Uso del acumulador (dispositivos dsPIC30F y dsPIC33F)” para obtener detalles sobre el uso.
ACCA y ACCB. 
2.5.4
Contador de programas
El contador de programa (PC) tiene 23 bits de ancho. Las instrucciones se abordan en el formato de usuario de 4M x 24 bits.
espacio de memoria del programa por PC<22:1>, donde PC<0> siempre se establece en ‘0’ para mantener la instrucción
alineación de palabras y proporciona compatibilidad con el direccionamiento del espacio de datos. Esto significa que durante
ejecución normal de instrucciones, el PC incrementa en 2.
La memoria del programa ubicada en 0x800000 y superior se utiliza para los datos de configuración del dispositivo, ID de unidad
e ID del dispositivo. Esta región no está disponible para la ejecución del código de usuario y la PC no puede acceder
esta área. Sin embargo, se puede acceder a esta región de la memoria utilizando instrucciones de la tabla. Para más detalles
Para acceder a los datos de configuración, ID de unidad y ID de dispositivo, consulte la familia de dispositivos específica.
manual de referencia.
2.5.5
Registro TBLPAG
El registro TBLPAG se utiliza para contener los 8 bits superiores de una dirección de memoria de programa durante la tabla.
operaciones de lectura y escritura. Las instrucciones de tabla se utilizan para transferir datos entre la memoria del programa.
Espacio y espacio de memoria de datos. Para obtener detalles sobre cómo acceder a la memoria del programa con la tabla
Para obtener instrucciones, consulte el manual de referencia de la familia de dispositivos específica.
2.5.6
Registro PSVPAG (PIC24F, PIC24H, dsPIC30F y dsPIC33F)
La visibilidad del espacio del programa permite al usuario asignar una sección de 32 Kbytes del espacio de memoria del programa.
en los 32 Kbytes superiores del espacio de direcciones de datos. Esta característica permite el acceso transparente de
datos constantes a través de instrucciones que operan en la memoria de datos. El registro PSVPAG selecciona
la región de 32 Kbytes del espacio de memoria del programa que está asignada al espacio de direcciones de datos. Para
Para obtener más información sobre la visibilidad del espacio del programa, consulte el manual de referencia de la familia de dispositivos específica.

© 2009 Microchip Technology Inc.
DS70157D-página 19
Sección 2. Modelo del programador
Programador 
modelo
2
2.5.7
Registro RCOUNT
El registro RCOUNT de 14 bits contiene el contador de bucle para la instrucción REPEAT. cuando un
Se ejecuta la instrucción REPEAT, se carga RCOUNT con el recuento de repeticiones de la instrucción,
ya sea “lit14” para la instrucción “REPEAT #lit14”, o el contenido de Wn para la instrucción “REPEAT Wn”
instrucción. El bucle REPEAT se ejecutará RCOUNT + 1 vez.
2.5.8
Registro DCOUNT (dispositivos dsPIC30F y dsPIC33F)
El registro DCOUNT de 14 bits contiene el contador de bucles para bucles DO de hardware. Cuando una DO
Cuando se ejecuta la instrucción, DCOUNT se carga con el recuento de bucles de la instrucción, ya sea “lit14” para
la instrucción “DO #lit14,Expr”, o los 14 bits menos significativos de W para la instrucción “DO Ws,Expr”
instrucción. El bucle DO se ejecutará DCOUNT + 1 vez.
2.5.9
Registro DOSTART (dispositivos dsPIC30F y dsPIC33F)
El registro DOSTART contiene la dirección inicial de un bucle DO de hardware. Cuando una DO
Cuando se ejecuta la instrucción, DOSTART se carga con la dirección de la instrucción que sigue al comando DO.
instrucción. Esta ubicación en la memoria es el inicio del ciclo DO. Cuando el bucle está activado,
La ejecución del programa continúa con la instrucción almacenada en la dirección DOSTART después de la última
Se ejecuta la instrucción en el bucle DO. Este mecanismo permite un bucle de sobrecarga cero.
2.5.10
Registro DOEND (dispositivos dsPIC30F y dsPIC33F)
El registro DOEND contiene la dirección final de un bucle DO de hardware. Cuando una instrucción DO
se ejecuta, DOEND se carga con la dirección especificada por la expresión en la instrucción DO.
Esta ubicación en la memoria especifica la última instrucción en el bucle DO. Cuando el bucle está activado
y se ejecuta la instrucción almacenada en la dirección DOEND, la ejecución del programa continuará
desde la dirección de inicio del bucle DO (almacenada en el registro DOSTART).
2.5.11
ESTADO Registrarse
El registro STATUS de 16 bits mantiene información de estado para las instrucciones que tienen más
recientemente ejecutado. Los bits de estado de operación existen para operaciones de MCU, operaciones de bucle y
Operaciones DSP. Además, el registro STATUS contiene los bits del nivel de prioridad de interrupción de la CPU,
IPL<2:0>, que se utilizan para el procesamiento de interrupciones.
Dependiendo de la familia MCU y DSC, se proporcionan las siguientes descripciones de registros:
• Registre 2-1 para dispositivos PIC24F y PIC24H
• Registro 2-2 para dispositivos dsPIC30F y dsPIC33F
2.5.11.1
BITS DE ESTADO MCU ALU
Los bits de estado de operación de la MCU se ven afectados o utilizados por la mayoría de las instrucciones en el
conjunto de instrucciones. La mayoría de las instrucciones lógicas, matemáticas, de rotación/desplazamiento y de bits modifican los bits de estado de la MCU.
después de la ejecución, y las instrucciones de rama condicionales utilizan el estado de los bits de estado individuales para
determinar el flujo de ejecución del programa. Todas las instrucciones de rama condicional se enumeran en 
4.8 “Instrucciones de Rama Condicional”.
Los bits de acarreo, cero, desbordamiento, negativo y acarreo de dígitos (C, Z, OV, N y DC) se utilizan para mostrar
el estado inmediato de la MCU ALU. Indican cuando una operación ha resultado en un Carry,
Cero, Desbordamiento, Resultado negativo y Acarreo de dígitos, respectivamente. Cuando una operación de resta es
realiza, la bandera C se utiliza como bandera de préstamo.
Nota 1: Si se está ejecutando un bucle REPEAT y se interrumpe, RCOUNT puede borrarse mediante
la Rutina de Interrupción del Servicio para salir del bucle REPETIR cuando el primer plano
se vuelve a introducir el código. 
2: Consulte el manual de referencia de la familia de dispositivos específica para obtener detalles completos sobre
REPETIR bucles.

Manual de referencia del programador MCU y DSC de 16 bits 
DS70157D-página 20 
© 2009 Microchip Technology Inc. 
El bit de estado Z es un bit de estado cero especial que resulta útil para la aritmética de precisión extendida. La Z 
El bit funciona como un indicador Z normal para todas las instrucciones, excepto aquellas que utilizan una entrada de acarreo o préstamo. 
(ADDC, CPB, SUBB y SUBBR). Consulte 4.9 “Bit de estado Z” para conocer el uso del bit de estado Z. 
2.5.11.2 
BITS DE ESTADO DEL BUCLE 
El bit REPEAT Active (RA) se utiliza para indicar cuándo el bucle está activo. La bandera RA indica que 
Se está ejecutando una instrucción REPEAT y solo se ve afectada por las instrucciones REPEAT. El 
El indicador RA se establece en ‘1’ cuando la instrucción que se repite comienza a ejecutarse y se borra cuando 
la instrucción que se repite completa la ejecución por última vez. 
Dado que el indicador RA también es de solo lectura, es posible que no se borre directamente. Sin embargo, si una REPETICIÓN o su 
se interrumpe la instrucción objetivo, la Rutina de Servicio de Interrupción puede borrar la bandera RA del SRL, 
que reside en la pila. Esta acción deshabilitará el bucle una vez que la ejecución del programa regrese de 
la Rutina de Interrupción del Servicio, porque el RA restaurado será ‘0’. 
2.5.11.2.1 Bit DO activo (DA) (dispositivos dsPIC30F y dsPIC33F) 
El bit DO activo (DA) se utiliza para indicar cuándo el bucle está activo. Las instrucciones DO afectan la 
Bandera DA, que indica que un bucle DO está activo. El indicador DA se establece en ‘1’ cuando se ejecuta la primera instrucción. 
del bucle DO se ejecuta y se borra cuando la última instrucción del bucle completa la operación final. 
ejecución. 
La bandera DA es de solo lectura. Esto significa que el bucle no puede iniciarse escribiendo un ‘1’ en DA, ni tampoco 
El bucle se puede terminar escribiendo un ‘0’ en DA. Si un bucle DO debe terminarse prematuramente, 
se debe utilizar el bit EDT, CORCON<11>. 
2.5.11.3 
BITS DE ESTADO DSP ALU (DISPOSITIVOS dsPIC30F Y dsPIC33F) 
El byte alto del registro STATUS (SRH) lo utiliza la clase de instrucciones DSP y es 
modificado cuando los datos pasan a través de uno de los sumadores. La SRH proporciona información sobre el estado 
sobre desbordamiento y saturación para ambos acumuladores. Saturado A, Saturado B, Desbordamiento A y 
Los bits de desbordamiento B (SA, SB, OA, OB) proporcionan el estado del acumulador individual, mientras que los bits de saturación AB 
y los bits Overflow AB (SAB, OAB) proporcionan el estado combinado del acumulador. Los bits SAB y OAB 
Proporcionar al desarrollador de software eficiencia en la comprobación del registro en busca de saturación o desbordamiento. 
Los bits OA y OB se utilizan para indicar cuando una operación ha generado un desbordamiento en el 
bits de protección (bits 32 a 39) del acumulador respectivo. Esta condición sólo puede ocurrir cuando 
el procesador está en modo Super Saturación, o si la saturación está desactivada. Indica que el 
La operación ha generado un número que no se puede representar con los 31 bits inferiores del 
acumulador. 
Los bits SA y SB se utilizan para indicar cuando una operación ha generado un desbordamiento del 
Bit más significativo del respectivo acumulador. Los bits SA y SB están activos, independientemente de 
el modo de Saturación (Desactivado, Normal o Súper) y puede considerarse “pegajoso”. Es decir, una vez 
Si el SA o SB está configurado en ‘1’, solo se puede borrar manualmente mediante software, independientemente de los cambios posteriores. 
Operaciones DSP. Cuando sea necesario, se recomienda borrar los bits con el BCLR 
instrucción. 
Por conveniencia, los bits OA y OB se combinan lógicamente con el operador O para formar el indicador OAB, y el 
Los bits SA y SB se colocan lógicamente en posición OR para formar el indicador SAB. Estos bits de estado acumulativos proporcionan 
Comprobación eficiente de desbordamiento y saturación cuando se implementa un algoritmo, que utiliza tanto 
acumuladores. En lugar de interrogar los bits OA y OB de forma independiente para realizar operaciones aritméticas 
se desborda, se puede realizar una única verificación de OAB. Del mismo modo, al comprobar la saturación, 
Se puede examinar SAB en lugar de verificar los bits SA y SB. Tenga en cuenta que borrar el SAB 
El indicador borrará los bits SA y SB. 
Nota 1: Todos los bits de MCU quedan sombreados durante la ejecución de la instrucción PUSH.S y son 
restaurado al ejecutar la instrucción POP.S. 
2: Todos los bits de MCU, excepto el indicador DC (que no está en el SRL), se apilan durante 
procesamiento de excepciones (ver 4.7.1 “Puntero de pila de software”). 

© 2009 Microchip Technology Inc.
DS70157D-página 21
Sección 2. Modelo del programador
Programador 
modelo
2
2.5.11.4
BITS DE ESTADO DEL NIVEL DE PRIORIDAD DE INTERRUPCIÓN
Los tres bits de nivel de prioridad de interrupción (IPL) de SRL, SR<7:5>, y el bit IPL3, CORCON<3>,
configure la IPL de la CPU que se utiliza para el procesamiento de excepciones. Las excepciones consisten en interrupciones y
trampas de hardware. Las interrupciones tienen un nivel de prioridad definido por el usuario entre 0 y 7, mientras que las trampas tienen un nivel de prioridad definido por el usuario entre 0 y 7.
nivel de prioridad fijo entre 8 y 15. El cuarto bit de nivel de prioridad de interrupción, IPL3, es una IPL especial
bit que sólo puede ser leído o borrado por el usuario. Este bit sólo se establece cuando hay una trampa de hardware.
se activa y se borra después de dar servicio a la trampa.
La IPL de la CPU identifica la excepción de nivel más bajo que puede interrumpir el procesador. el
El nivel de interrupción de una excepción pendiente siempre debe ser mayor que la IPL de la CPU para que la CPU pueda
procesar la excepción. Esto significa que si la IPL es 0, todas las excepciones en el nivel de prioridad 1 y superior
puede interrumpir el procesador. Si la IPL es 7, sólo las capturas de hardware pueden interrumpir el procesador.
Cuando se atiende una excepción, la IPL se establece automáticamente en el nivel de prioridad de la excepción.
siendo reparado, lo que deshabilitará todas las excepciones de igual o menor prioridad. Sin embargo, desde el
El campo IPL es de lectura/escritura, se pueden modificar los tres bits inferiores de la IPL en un servicio de interrupción.
Rutina para controlar qué excepciones pueden adelantarse al procesamiento de excepciones. Dado que la SRL es
apilada durante el procesamiento de excepciones, la IPL original siempre se restaura después de que se resuelve la excepción.
atendido. Si es necesario, también se puede evitar que se anidan excepciones configurando el bit NSTDIS,
INTCON1<15>.
2.5.12
Registro de control central 
Para todos los dispositivos MCU y DSC, el registro CPU Core Control (CORCON) de 16 bits se utiliza para configurar
la configuración de la CPU. Este registro proporciona la capacidad de mapear el espacio del programa en datos.
espacio.
Además de configurar los modos de la CPU, el registro CORCON contiene información de estado sobre el
Bit de estado IPL<3>, que indica si se está procesando una excepción de captura.
Dependiendo de la familia MCU y DSC, las siguientes descripciones de registros CORCON son
proporcionado:
• Registre 2-3 para dispositivos PIC24F y PIC24H
• Registro 2-4 para dispositivos dsPIC30F y dsPIC33F
2.5.12.1
BITS ESPECÍFICOS dsPIC30F Y dsPIC33F
Además de configurar los modos de CPU, las siguientes funciones están disponibles a través de CORCON
registrarse:
• Establecer la habilitación de saturación ACCA y ACCB
• Establecer el modo de saturación de escritura del espacio de datos
• Establecer los modos de Saturación y Redondeo del Acumulador
• Configure el modo Multiplicador para operaciones DSP
• Terminar los bucles DO prematuramente
• Proporciona información de estado sobre el nivel de anidamiento del bucle DO (DL<2:0>)
Nota:
Consulte el manual de referencia de la familia de dispositivos específica para obtener detalles completos sobre
procesamiento de excepciones.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 22
© 2009 Microchip Technology Inc.
2.5.13
Registros en la sombra
Un registro sombra se utiliza como un registro de tenencia temporal y puede transferir su contenido hacia o desde
el registro de host asociado ante algún evento. Algunos de los registros en el modelo del programador.
tener un registro sombra, que se utiliza durante la ejecución de un DO, POP.S o PUSH.S
instrucción. El uso del registro de sombra se muestra en la Tabla 2-2. 
Para dispositivos dsPIC30F y dsPIC33F, dado que los registros DCOUNT, DOSTART y DOEND son
sombreado, se proporciona la capacidad de anidar bucles DO sin gastos generales adicionales. Desde toda sombra
Los registros tienen un registro de profundidad, es posible hasta un nivel de anidamiento de bucles DO. Anidamiento adicional de
Los bucles DO son posibles en el software, con soporte proporcionado por los bits de estado del nivel de anidamiento del bucle DO.
(CORCON<10:8>) en el registro CORCON.
Nota:
La instrucción DO solo está disponible en dispositivos dsPIC30F y dsPIC33F.
Tabla 2-2:
Uso automático del registro de sombra
Ubicación
HACER(1)
POP.S/PUSH.S
DCUENTA(1)
si
—
DOINICIO(1)
si
—
FINALIZAR(1)
si
—
ESTADO Registro – Bits DC, N, OV, Z y C
—
si
W0-W3
—
si
Nota 1:
Los registros de sombra DO solo están disponibles en dispositivos dsPIC30F y dsPIC33F.
Nota:
Todos los registros ocultos tienen un registro de profundidad y no son accesibles directamente.
Se puede realizar un sombreado adicional en el software utilizando la pila de software.

© 2009 Microchip Technology Inc.
DS70157D-página 23
Sección 2. Modelo del programador
Programador 
modelo
2
             
Regístrate 2-1:
SR: Registro de estado de la CPU (dispositivos PIC24H y PIC24F)
U-0
U-0
U-0
U-0
U-0
U-0
U-0
R/W-0
—
—
—
—
—
—
—
CC
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R-0
R/W-0
R/W-0
R/W-0
R/W-0
IPL<2:0>(1,2)
RA
norte
VO
z
c
poco 7
poco 0
Leyenda:
U = Bit no implementado, leído como ‘0’
R = bit legible
W = bit grabable
C = bit borrable
-n = Valor en POR
‘1’ = El bit está configurado
‘0’ = El bit se borra
x = El bit es desconocido
bit 15-9
No implementado: leído como ‘0’
poco 8
DC: MCU ALU Medio acarreo/bit de préstamo
1 = Una transferencia desde el cuarto bit de orden inferior (para datos de tamaño de byte) o el octavo bit de orden inferior (para datos de tamaño de palabra)
del resultado ocurrido
0 = Sin transferencia desde el cuarto bit de orden inferior (para datos de tamaño de byte) o el octavo bit de orden inferior (para datos de tamaño de palabra)
del resultado ocurrido
bits 7-5
IPL<2:0>: Bits de estado del nivel de prioridad de interrupción de la CPU (1,2)
111 = El nivel de prioridad de interrupción de la CPU es 7 (15). Interrupciones de usuario deshabilitadas 
110 = El nivel de prioridad de interrupción de la CPU es 6 (14)
101 = El nivel de prioridad de interrupción de la CPU es 5 (13)
100 = El nivel de prioridad de interrupción de la CPU es 4 (12)
011 = El nivel de prioridad de interrupción de la CPU es 3 (11)
010 = El nivel de prioridad de interrupción de la CPU es 2 (10)
001 = El nivel de prioridad de interrupción de la CPU es 1 (9)
000 = El nivel de prioridad de interrupción de la CPU es 0 (8)
poco 4
RA: REPETIR bit activo del bucle
1 = REPETIR bucle en curso
0 = bucle REPETIR no en curso
poco 3
N: bit negativo MCU ALU
1 = El resultado fue negativo
0 = El resultado no fue negativo (cero o positivo)
poco 2
OV: Bit de desbordamiento MCU ALU
Este bit se utiliza para aritmética con signos (complemento a 2). Indica un desbordamiento de la magnitud que
hace que el bit de signo cambie de estado. 
1 = Se produjo un desbordamiento para la aritmética con signo (en esta operación aritmética)
0 = No se produjo ningún desbordamiento
poco 1
Z: MCU ALU bit cero
1 = Una operación que afecta el bit Z lo ha configurado en algún momento en el pasado
0 = La operación más reciente que afecta el bit Z lo ha borrado (es decir, un resultado distinto de cero)
poco 0
C: Bit de transporte/préstamo MCU ALU
1 = Se produjo una transferencia del bit más significativo del resultado
0 = No se realizó ninguna transferencia del bit más significativo del resultado
Nota 1: Los bits IPL<2:0> se concatenan con el bit IPL<3> (CORCON<3>) para formar la prioridad de interrupción de la CPU.
Nivel. El valor entre paréntesis indica la IPL, si IPL<3> = 1. Las interrupciones del usuario se desactivan cuando
IPL<3> = 1.
2: Los bits de estado de IPL<2:0> se leen solo cuando NSTDIS = 1 (INTCON1<15>).

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 24
© 2009 Microchip Technology Inc.
Registro 2-2:
SR: Registro de ESTADO de CPU (dispositivos dsPIC30F y dsPIC33F)
R-0
R-0
R/C-0
R/C-0
R-0
R/C-0
R-0
R/W-0
OA
OB
SA(1,2)
SB(1,2)
VH
SAB(1,2,3)
DA(4)
CC
poco 15
poco 8
R/W-0
R/W-0
R/W-0
R-0
R/W-0
R/W-0
R/W-0
R/W-0
IPL<2:0>(5)
RA
norte
VO
Z(6)
c
poco 7
poco 0
Leyenda:
R = bit legible
W = bit grabable
C = bit borrable
-n = Valor en POR
‘1’ = El bit está configurado
‘0’ = El bit se borra
x = El bit es desconocido
poco 15
OA: Bit de desbordamiento del acumulador A 
1 = Acumulador A desbordado
0 = El acumulador A no se ha desbordado
poco 14
OB: Bit de desbordamiento del acumulador B
1 = Acumulador B desbordado
0 = El acumulador B no se ha desbordado
poco 13
SA: Acumulador A Bit de saturación(1,2)
1 = El acumulador A está saturado o ha estado saturado en algún momento
0 = El acumulador A no está saturado
poco 12
SB: Bit de saturación del acumulador B (1,2)
1 = El acumulador B está saturado o ha estado saturado en algún momento
0 = Acumulador B no está saturado
poco 11
VHA: OA || Bit de desbordamiento del acumulador combinado OB
1 = Los acumuladores A o B se han desbordado
0 = Ni los acumuladores A ni B se han desbordado
poco 10
SAB: SA || Bit de acumulador combinado SB (1,2,3)
1 = Los acumuladores A o B están saturados o han estado saturados en algún momento del pasado
0 = Ni los acumuladores A ni B están saturados
poco 9
DA: bit activo del bucle DO (4)
1 = bucle DO en curso
0 = bucle DO no en progreso
poco 8
DC: MCU ALU Medio bit de transporte
1 = Se produjo una transferencia del bit más significativo del cuarteto inferior
0 = No se produjo ninguna transferencia del bit más significativo del cuarteto inferior
Nota 1: Este bit puede leerse o borrarse, pero no establecerse.
2: Una vez establecido este bit, el software debe borrarlo manualmente.
3: Al borrar este bit se borrarán SA y SB.
4: este bit es de sólo lectura.
5: Los bits IPL<2:0> se concatenan con el bit IPL<3> (CORCON<3>) para formar la prioridad de interrupción de la CPU.
Nivel. El valor entre paréntesis indica la IPL, si IPL<3> = 1.
6: Consulte 4.9 “Bit de estado Z” para conocer la operación con las instrucciones ADDC, CPB, SUBB y SUBBR.

© 2009 Microchip Technology Inc.
DS70157D-página 25
Sección 2. Modelo del programador
Programador 
modelo
2
bits 7-5
IPL<2:0>: bits de nivel de prioridad de interrupción(5)
111 = El nivel de prioridad de interrupción de la CPU es 7 (15). Interrupciones de usuario deshabilitadas
110 = El nivel de prioridad de interrupción de la CPU es 6 (14)
101 = El nivel de prioridad de interrupción de la CPU es 5 (13)
100 = El nivel de prioridad de interrupción de la CPU es 4 (12)
011 = El nivel de prioridad de interrupción de la CPU es 3 (11)
010 = El nivel de prioridad de interrupción de la CPU es 2 (10)
001 = El nivel de prioridad de interrupción de la CPU es 1 (9)
000 = El nivel de prioridad de interrupción de la CPU es 0 (8)
poco 4
RA: REPETIR bit activo del bucle
1 = REPETIR bucle en curso
0 = bucle REPETIR no en curso
poco 3
N: bit negativo MCU ALU
1 = El resultado de la operación fue negativo
0 = El resultado de la operación no fue negativo
poco 2
OV: Bit de desbordamiento MCU ALU
1 = Se produjo un desbordamiento
0 = No se produjo ningún desbordamiento
poco 1
Z: MCU ALU Bit cero(6)
1 = El resultado de la operación fue cero
0 = El resultado de la operación no fue cero
poco 0
C: Bit de transporte/préstamo MCU ALU
1 = Se produjo una transferencia del bit más significativo
0 = No se produjo ninguna transferencia del bit más significativo
Registro 2-2:
SR: Registro de ESTADO de CPU (dispositivos dsPIC30F y dsPIC33F) (continuación)
Nota 1: Este bit puede leerse o borrarse, pero no establecerse.
2: Una vez establecido este bit, el software debe borrarlo manualmente.
3: Al borrar este bit se borrarán SA y SB.
4: este bit es de sólo lectura.
5: Los bits IPL<2:0> se concatenan con el bit IPL<3> (CORCON<3>) para formar la prioridad de interrupción de la CPU.
Nivel. El valor entre paréntesis indica la IPL, si IPL<3> = 1.
6: Consulte 4.9 “Bit de estado Z” para conocer la operación con las instrucciones ADDC, CPB, SUBB y SUBBR.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 26
© 2009 Microchip Technology Inc.
Registro 2-3:
CORCON: Registro de control central (dispositivos PIC24F y PIC24H)
U-0
U-0
U-0
U-0
U-0
U-0
U-0
U-0
—
—
—
—
—
—
—
—
poco 15
poco 8
U-0
U-0
U-0
U-0
R/C-0
R/W-0
U-0
U-0
—
—
—
—
IPL3(1,2)
PSV
—
—
poco 7
poco 0
Leyenda:
C = bit borrable
R = bit legible
W = bit grabable
-n = Valor en POR
‘1’ = El bit está configurado
‘0’ = El bit se borra
x = El bit es desconocido
U = Bit no implementado, leído como ‘0’
bit 15-4
No implementado: leído como ‘0’
poco 3
IPL3: Bit de estado de nivel 3 de prioridad de interrupción (1,2)
1 = El nivel de prioridad de interrupción de la CPU es 8 o mayor (excepción de captura activada)
0 = El nivel de prioridad de interrupción de la CPU es 7 o menos (no se activa ninguna excepción de captura)
poco 2
PSV: Visibilidad del espacio del programa en el bit de habilitación del espacio de datos
1 = Espacio de programa visible en el espacio de datos
0 = Espacio de programa no visible en el espacio de datos
poco 1-0
No implementado: no usar
Nota 1: Este bit puede leerse o borrarse, pero no establecerse.
2: este bit se concatena con los bits IPL<2:0> (SR<7:5>) para formar el nivel de prioridad de interrupción de la CPU.

© 2009 Microchip Technology Inc.
DS70157D-página 27
Sección 2. Modelo del programador
Programador 
modelo
2
Registro 2-4:
CORCON: Registro de control central (dispositivos dsPIC30F y dsPIC33F)
Ud.
Ud.
Ud.
R/W-0
R(0)/W-0
R-0
R-0
R/W-0
—
—
—
Estados Unidos
hora del este(1)
DL<2:0>(2,3)
poco 15
poco 8
R/W-0
R/W-0
R/W-1
R/W-0
R/C-0
R/W-0
R/W-0
R/W-0
sata
SATB
SATDW
ACCESAT
IPL3(4,5)
PSV
RND
SI
poco 7
poco 0
Leyenda:
C = bit borrable
R = bit legible
W = bit grabable
-n = Valor en POR
‘1’ = El bit está configurado
‘0’ = El bit se borra
x = El bit es desconocido
U = Bit no implementado, leído como ‘0’
bits 15-13
No implementado: no usar
poco 12
EE. UU.: bit de selección de modo multiplicador sin signo o con signo
1 = Modo sin signo habilitado para operaciones de multiplicación DSP
0 = Modo firmado habilitado para operaciones de multiplicación DSP
poco 11
EDT: bit de control de terminación temprana del bucle DO (1)
1 = Terminar la ejecución del bucle DO al final de la iteración actual
0 = Sin efecto
bits 10-8
DL<2:0>: Bits de estado del nivel de anidamiento del bucle DO (2,3)
111 = El bucle DO está anidado en 7 niveles
110 = el bucle DO está anidado en 6 niveles
110 = el bucle DO está anidado en 5 niveles
110 = el bucle DO está anidado en 4 niveles
011 = El bucle DO está anidado en 3 niveles
010 = el bucle DO está anidado en 2 niveles
001 = El bucle DO está activo, pero no anidado (solo 1 nivel)
000 = el bucle DO no está activo
poco 7
SATA: bit de habilitación de saturación ACCA
1 = Saturación del acumulador A habilitada
0 = Saturación del acumulador A deshabilitada
poco 6
SATB: bit de habilitación de saturación ACCB
1 = Saturación del acumulador B habilitada
0 = Saturación del acumulador B deshabilitada
poco 5
SATDW: Escritura en espacio de datos desde el bit de habilitación de saturación del motor DSP
1 = Saturación de escritura del espacio de datos habilitada
0 = Saturación de escritura del espacio de datos deshabilitada
poco 4
ACCSAT: Bit de selección del modo de saturación del acumulador
1 = saturación 9,31 (súper saturación)
0 = 1,31 de saturación (Saturación normal)
poco 3
IPL3: Bit de estado de nivel 3 de prioridad de interrupción (4,5)
1 = El nivel de prioridad de interrupción de la CPU es 8 o mayor (excepción de captura activada)
0 = El nivel de prioridad de interrupción de la CPU es 7 o menos (no se activa ninguna excepción de captura)
Nota 1: Este bit siempre leerá ‘0’.
2: DL<2:1> son de solo lectura.
3: Los primeros dos niveles de anidamiento de bucles DO se manejan mediante hardware.
4: Este bit puede leerse o borrarse, pero no establecerse.
5: Este bit se concatena con los bits IPL<2:0> (SR<7:5>) para formar el nivel de prioridad de interrupción de la CPU.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 28
© 2009 Microchip Technology Inc.
poco 2
PSV: Visibilidad del espacio del programa en el bit de habilitación del espacio de datos
1 = Espacio de programa visible en el espacio de datos
0 = Espacio de programa no visible en el espacio de datos
poco 1
RND: bit de selección de modo de redondeo
1 = Redondeo sesgado (convencional) habilitado
0 = Redondeo imparcial (convergente) habilitado
poco 0
IF: Modo multiplicador entero o fraccionario Seleccionar bit
1 = Modo entero habilitado para operaciones de multiplicación DSP
0 = Modo fraccionario habilitado para operaciones de multiplicación DSP
Registro 2-4:
CORCON: Registro de control central (dispositivos dsPIC30F y dsPIC33F) (continuación)
Nota 1: Este bit siempre leerá ‘0’.
2: DL<2:1> son de solo lectura.
3: Los primeros dos niveles de anidamiento de bucles DO se manejan mediante hardware.
4: Este bit puede leerse o borrarse, pero no establecerse.
5: Este bit se concatena con los bits IPL<2:0> (SR<7:5>) para formar el nivel de prioridad de interrupción de la CPU.

© 2009 Microchip Technology Inc.
DS70157D-página 29
Conjunto de instrucciones 
Descripción general
3
Sección 3. Descripción general del conjunto de instrucciones
DESTACADOS
Esta sección del manual contiene los siguientes temas principales:
3.1
Introducción ................................................................................................................................ 30
3.2
Descripción general del conjunto de instrucciones................................................................ 30
3.3
Tablas de resumen del conjunto de instrucciones ......................................................................... 32

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 30
© 2009 Microchip Technology Inc.
3.1
 INTRODUCCIÓN 
El conjunto de instrucciones MCU y DSC de 16 bits proporciona un amplio conjunto de instrucciones que admiten
aplicaciones de microcontroladores tradicionales y una clase de instrucciones, que admite matemáticas intensivas
aplicaciones. Dado que casi toda la funcionalidad del conjunto de instrucciones PIC® MCU ha sido
mantenido, este conjunto de instrucciones híbrido permite una ruta de migración DSP amigable para los usuarios que ya
familiarizado con el microcontrolador PIC.
3.2
 RESUMEN DEL JUEGO DE INSTRUCCIONES
Dependiendo de la familia de dispositivos, el conjunto de instrucciones MCU y DSC de 16 bits contiene hasta 83
instrucciones, que se pueden agrupar en las categorías funcionales que se muestran en la Tabla 3-1. Tabla 1-2
define los símbolos utilizados en las tablas de resumen de instrucciones, de la Tabla 3-2 a la Tabla 3-11. Estos
Las tablas definen los requisitos de sintaxis, descripción, almacenamiento y ejecución de cada instrucción.
Los requisitos de almacenamiento se representan en palabras de instrucción de 24 bits y requisitos de ejecución.
se representan en ciclos de instrucción. 
Tabla 3-1:
Grupos de instrucción  
La mayoría de las instrucciones tienen varios modos de direccionamiento y flujos de ejecución diferentes, que requieren
diferentes variantes de instrucción. Por ejemplo, dependiendo de la familia de dispositivos, hay hasta seis
instrucciones ADD únicas y cada variante de instrucción tiene su propia codificación de instrucción. Instrucción
Las descripciones del formato y la operación de instrucciones específicas se proporcionan en la Sección 5. “Instrucción
Descripciones”. Además, se proporciona una tabla compuesta de instrucciones alfabéticas en
Sección 6. “Referencia”.
Grupo Funcional
Tabla resumen
Número de página
Instrucciones de movimiento
Tabla 3-2
3-32
Instrucciones de matemáticas
Table 3-3
3-32
Instrucciones lógicas
Tabla 3-4
3-34
Instrucciones de rotación/desplazamiento
Tabla 3-5
3-35
Instrucciones de bits
Tabla 3-6
3-36
Comparar/Omitir instrucciones
Tabla 3-7
3-37
Instrucciones de flujo del programa
Tabla 3-8
3-38
Instrucciones de sombra/pila
Tabla 3-9
3-39
Instrucciones de control
Tabla 3-10
3-39
Instrucciones DSP(1)
Tabla 3-11
3-39
Nota 1:
Las instrucciones DSP solo están disponibles en las familias de dispositivos dsPIC30F y dsPIC33F.

© 2009 Microchip Technology Inc.
DS70157D-página 31
Sección 3. Descripción general del conjunto de instrucciones
Conjunto de instrucciones 
Descripción general
3
3.2.1
Instrucciones de ciclos múltiples
Como muestran las tablas de resumen de instrucciones, la mayoría de las instrucciones se ejecutan en un solo ciclo, con el
siguientes excepciones:
• Instrucciones DO, MOV.D, POP.D, PUSH.D, TBLRDH, TBLRDL, TBLWTH y TBLWTL 
Requiere 2 ciclos para ejecutarse. 
• Las instrucciones DIV.S, DIV.U y DIVF son instrucciones de un solo ciclo, que deben ejecutarse
cortado 18 veces consecutivas como objetivo de una instrucción REPETIR.
• Las instrucciones que cambian el contador del programa también requieren 2 ciclos para ejecutarse, con el 
ciclo adicional ejecutado como NOP. Instrucción SKIP, que omite una instrucción de 2 palabras, 
requiere 3 ciclos de instrucción para ejecutarse, con 2 ciclos ejecutados como NOP. 
• Los RETFIE, RETLW y RETURN son un caso especial de instrucción que cambia el 
contador de programa. Estos se ejecutan en 3 ciclos, a menos que haya una excepción pendiente y luego 
ejecutar en 2 ciclos. 
3.2.2
Instrucciones de varias palabras
Como se define en la Tabla 3-2: “Instrucciones de movimiento”, casi todas las instrucciones consumen una instrucción
palabra (24 bits), con excepción de las instrucciones CALL, DO y GOTO, que son Programa
Instrucciones de flujo, enumeradas en la Tabla 3-8. Estas instrucciones requieren dos palabras de memoria porque
sus códigos de operación incorporan grandes operandos literales.
Nota:
Las instrucciones DO y DIVF solo están disponibles en dsPIC30F y dsPIC33F.
familias de dispositivos.
Nota:
Instrucciones que acceden a la memoria del programa como datos, usando Program Space Visibility
(PSV), incurrirá en un retraso de uno o dos ciclos para todos los dispositivos MCU y DSC de 16 bits. cuando
La instrucción de destino de un bucle REPEAT accede a la memoria del programa como datos, solo el
La primera ejecución de la instrucción objetivo está sujeta al retraso. Ver el dispositivo específico
manual de referencia familiar para más detalles.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 32
© 2009 Microchip Technology Inc.
3.3
 TABLAS RESUMEN DEL JUEGO DE INSTRUCCIONES
Tabla 3-2:
Instrucciones de movimiento
Sintaxis de ensamblaje
Descripción
palabras
Ciclos
Página 
Número
EXCH
Wns,Wnd
Intercambiar Wns y Wnd
1
1
5-203
MOVIMIENTO
f {,WREG}(1) 
Mover f al destino
1
1
5-233
MOVIMIENTO
WREG,f
Mover WREG a f
1
1
5-234
MOVIMIENTO
f, viento
Mover f a Wnd
1
1
5-235
MOVIMIENTO
Wns,f
Mover Wns a f
1
1
5-236
MOV.B
#lit8,viento
Mover literal de 8 bits a Wnd
1
1
5-237
MOVIMIENTO
#lit16,viento
Mover literal de 16 bits a Wnd
1
1
5-238
MOVIMIENTO
[Ws+Rendija10],Wnd
Mueva [Ws + desplazamiento de 10 bits con signo] a Wnd
1
1
5-239
MOVIMIENTO
Wns,[Wd+Rendija10]
Mueva Wns a [Wd + desplazamiento de 10 bits con signo]
1
1
5-240
MOVIMIENTO
Ws,Wd
Mover Ws a Wd
1
1
5-241
MOV.D
Ws, viento
Mover doble W a Wnd:Wnd + 1 
1
2
5-243
MOV.D
Wns,Wd
Mover doble Wns:Wns + 1 a Wd
1
2
5-243
INTERCAMBIAR
Wn
Wn = byte o intercambio de nibble Wn
1
1
5-340
TBLRDH
Ws,Wd
Leer palabra de programa alta en Wd
1
2
5-341
TBLRDL
Ws,Wd
Leer palabra de programa baja en Wd
1
2
5-343
TBLWTH
Ws,Wd
Escriba Ws en la palabra de programa alta
1
2
5-345
TBLWTL
Ws,Wd
Escribe Ws en una palabra de programa baja
1
2
5-347
Nota 1: Cuando se especifica el operando {,WREG} opcional, el destino de la instrucción es WREG. cuando
{,WREG} no se especifica, el destino de la instrucción es el registro de archivo f.
Tabla 3-3:
Instrucciones de matemáticas
Sintaxis de ensamblaje
Descripción
palabras
Ciclos
Página 
Número
AÑADIR
f {,WREG}(1)
Destino = f + WREG
1
1
5-89
AÑADIR
#lit10,Wn
Wn = lit10 + Wn
1
1
5-90
AÑADIR
Wb,#lit5,Wd
Wd = Wb + lit5
1
1
5-91
AÑADIR
Wb,Ws,Wd
Wd = Wb + Ws
1
1
5-93
ADDC
f {,WREG}(1)
Destino = f + WREG + (C)
1
1
5-98
ADDC
#lit10,Wn
Wn = lit10 + Wn + (C)
1
1
5-99
ADDC
Wb,#lit5,Wd
Wd = Wb + lit5 + (C)
1
1
5-100
ADDC
Wb,Ws,Wd
Wd = Wb + Ws + (C)
1
1
5-102
DAW.B
Wn
Wn = ajuste decimal Wn
1
1
5-183
DIC
f {,WREG}(1)
Destino = f – 1
1
1
5-184
DIC
Ws,Wd
Wd = Ws – 1
1
1
5-185
DIC2
f {,WREG}(1)
Destino = f – 2
1
1
5-186
DIC2
Ws,Wd
Wd = Ws – 2
1
1
5-187
DIV.S
Wm, Wn
División entera de 16/16 bits con signo
1
18(2)
5-189
DIV.SD
Wm, Wn
División entera de 32/16 bits con signo
1
18(2)
5-189
DIV.U
Wm, Wn
División entera de 16/16 bits sin signo
1
18(2)
5-191
Nota 1: Cuando se especifica el operando {,WREG} opcional, el destino de la instrucción es WREG. cuando
{,WREG} no se especifica, el destino de la instrucción es el registro de archivo f.
2: Las instrucciones de división deben ir precedidas de una instrucción “REPEAT #17”, de manera que se ejecuten
18 veces consecutivas.

© 2009 Microchip Technology Inc.
DS70157D-página 33
Sección 3. Descripción general del conjunto de instrucciones
Conjunto de instrucciones 
Descripción general
3
DIV.UD
Wm, Wn
División entera de 32/16 bits sin signo
1
18(2)
5-191
DIVF
Wm, Wn
División fraccionaria firmada de 16/16 bits
1
18(2)
5-193
INC
f {,WREG}(1)
Destino = f + 1
1
1
5-212
INC
Ws,Wd
Wd = Ws + 1
1
1
5-213
INC2
f {,WREG}(1)
Destino = f + 2
1
1
5-214
INC2
Ws,Wd
Wd = Ws + 2
1
1
5-215
MUL
f
W3:W2 = f * WREG 
1
1
5-255
MUL.SS
Wb,Ws,Wnd
{Wnd + 1,Wnd} = firmado(Wb) * firmado(Ws)
1
1
5-256
MUL.SU
Wb,#lit5,Wnd
{Wnd + 1,Wnd} = firmado(Wb) * sin firmar(lit5)
1
1
5-258
MUL.SU
Wb,Ws,Wnd
{Wnd + 1,Wnd} = con signo (Wb) * sin signo (Ws)
1
1
5-260
MUL.SU
Wb,#lit5,Wnd
{Wnd + 1, Wnd} = firmado(Wb) * sin firmar(lit5)
1
1
5-260
MUL.US
Wb,Ws,Wnd
{Wnd + 1,Wnd} = sin firmar (Wb) * firmado (Ws)
1
1
5-262
MUL.UU
Wb,Ws,Wnd
{Wnd + 1,Wnd} = sin firmar (Wb) * sin firmar (Ws)
1
1
5-265
MUL.UU
Wb,#lit5,Wnd
{Wnd + 1, Wnd} = sin firmar (Wb) * sin firmar (lit5)
1
1
5-264
SE
Ws, viento
Wnd = Ws extendido con signo
1
1
5-309
SUB
f {,WREG}(1)
Destino = f – WREG
1
1
5-319
SUB
#lit10,Wn
Wn = Wn – lit10
1
1
5-320
SUB
Wb,#lit5,Wd
Wd = Wb – lit5
1
1
5-321
SUB
Wb,Ws,Wd
Wd = Wb – Ws
1
1
5-322
SUBB
f {,WREG}(1)
Destino = f – WREG – (C)
1
1
5-325
SUBB
#lit10,Wn
Wn = Wn – lit10 – (C)
1
1
5-326
SUBB
Wb,Ws,Wd
Wd = Wb – Ws – (C)
1
1
5-329
SUBBR
f {,WREG}(1)
Destino = WREG – f – (C)
1
1
5-331
SUBBR
Wb,#lit5,Wd
Wd = lit5 – Wb – (C)
1
1
5-332
SUBBR
Wb,Ws,Wd
Wd = Ws – Wb – (C)
1
1
5-334
SUBR
f {,WREG}(1)
Destino = WREG – f
1
1
5-336
SUBR
Wb,#lit5,Wd
Wd = lit5 – Wb
1
1
5-337
SUBR
Wb,Ws,Wd
Wd = Ws – Wb
1
1
5-338
ZE
Ws, viento
Wnd = Ws extendido a cero
1
1
5-355
Tabla 3-3:
Instrucciones de matemáticas (continuación)
Sintaxis de ensamblaje
Descripción
palabras
Ciclos
Página 
Número
Nota 1: Cuando se especifica el operando {,WREG} opcional, el destino de la instrucción es WREG. cuando
{,WREG} no se especifica, el destino de la instrucción es el registro de archivo f.
2: Las instrucciones de división deben ir precedidas de una instrucción “REPEAT #17”, de manera que se ejecuten
18 veces consecutivas.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 34
© 2009 Microchip Technology Inc.
Tabla 3-4:
Instrucciones lógicas
Sintaxis de ensamblaje
Descripción
palabras
Ciclos
Página 
Número
Y
f {,WREG}(1)
Destino = f .Y. WREG
1
1
5-104
Y
#lit10,Wn
Wn = lit10 .Y. Wn
1
1
5-105
Y
Wb,#lit5,Wd
Wd = Wb .Y. lit5
1
1
5-106
Y
Wb,Ws,Wd
Wd = Wb .Y. Ws
1
1
5-107
CLR
f 
f = 0x0000
1
1
5-163
CLR
WREG
WREG = 0x0000
1
1
5-163
CLR
Wd
Wd = 0x0000
1
1
5-164
COM
f {,WREG}(1)
Destino = f
1
1
5-168
COM
Ws,Wd
Wd = Ws
1
1
5-169
IOR
f {,WREG}(1)
Destino = f .IOR. WREG
1
1
5-216
IOR
#lit10,Wn
Wn = lit10 .IOR. Wn
1
1
5-217
IOR
Wb,#lit5,Wd
Wd = Wb .IOR. lit5
1
1
5-218
IOR
Wb,Ws,Wd
Wd = Wb .IOR. Ws
1
1
5-219
NEG
f {,WREG}(1)
Destino = f + 1
1
1
5-267
NEG
Ws,Wd
Wd = Ws + 1
1
1
5-268
SETM
f
f = 0xFFFF
1
1
5-310
SETM
WREG
WREG = 0xFFFF
1
1
5-310
SETM
Wd
Wd = 0xFFFF
1
1
5-311
XOR
f {,WREG}(1)
Destino = f .XOR. WREG
1
1
5-350
XOR
#lit10,Wn
Wn = lit10 .XOR. Wn
1
1
5-351
XOR
Wb,#lit5,Wd
Wd = Wb .XOR. lit5
1
1
5-352
XOR
Wb,Ws,Wd
Wd = Wb .XOR. Ws
1
1
5-353
Nota 1: Cuando se especifica el operando {,WREG} opcional, el destino de la instrucción es WREG. cuando
{,WREG} no se especifica, el destino de la instrucción es el registro de archivo f.

© 2009 Microchip Technology Inc.
DS70157D-página 35
Sección 3. Descripción general del conjunto de instrucciones
Conjunto de instrucciones 
Descripción general
3
Tabla 3-5:
Instrucciones de rotación/desplazamiento
Sintaxis de ensamblaje
Descripción
palabras
Ciclos
Página #
ASR
f {,WREG}(1)
Destino = desplazamiento aritmético a la derecha f
1
1
5-109
ASR
Ws,Wd
Wd = desplazamiento aritmético a la derecha Ws
1
1
5-111
ASR
Wb,#lit4,Wnd
Wnd = desplazamiento aritmético a la derecha Wb por lit4
1
1
5-113
ASR
Wb,Wns,Wnd
Wnd = desplazamiento aritmético a la derecha Wb por Wns
1
1
5-114
LSR
f {,WREG}(1)
Destino = desplazamiento lógico a la derecha f
1
1
5-224
LSR
Ws,Wd
Wd = desplazamiento lógico a la derecha Ws
1
1
5-225
LSR
Wb,#lit4,Wnd
Wnd = desplazamiento lógico a la derecha Wb por lit4
1
1
5-227
LSR
Wb,Wns,Wnd
Wnd = desplazamiento lógico a la derecha Wb por Wns
1
1
5-228
RLC
f {,WREG}(1)
Destino = girar a la izquierda hasta Llevar f
1
1
5-293
RLC
Ws,Wd
Wd = rotar a la izquierda a través de Carry Ws
1
1
5-294
RLNC
f {,WREG}(1)
Destino = rotar a la izquierda (sin transporte) f
1
1
5-296
RLNC
Ws,Wd
Wd = girar a la izquierda (sin transporte) Ws
1
1
5-297
RRC
f {,WREG}(1)
Destino = girar a la derecha a través de Llevar f
1
1
5-299
RRC
Ws,Wd
Wd = rotar hacia la derecha a través de Carry Ws
1
1
5-300
RRNC
f {,WREG}(1)
Destino = rotar a la derecha (sin transporte) f
1
1
5-302
RRNC
Ws,Wd
Wd = girar a la derecha (sin transporte) Ws
1
1
5-303
SL
f {,WREG}(1)
Destino = desplazamiento a la izquierda f
1
1
5-314
SL
Ws,Wd
Wd = desplazamiento a la izquierda Ws
1
1
5-315
SL
Wb,#lit4,Wnd
Wnd = desplazamiento a la izquierda Wb por lit4
1
1
5-317
SL
Wb,Wns,Wnd
Wnd = desplazamiento a la izquierda Wb por Wns
1
1
5-318
Nota 1: Cuando se especifica el operando {,WREG} opcional, el destino de la instrucción es WREG. cuando
{,WREG} no se especifica, el destino de la instrucción es el registro de archivo f.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 36
© 2009 Microchip Technology Inc.
Tabla 3-6:
Instrucciones de bits
Sintaxis de ensamblaje
Descripción
palabras
Ciclos
Página 
Número
BCLR
f,#bit4
Poco claro f
1
1
5-115
BCLR
Ws,#bit4
Un poco claro Ws
1
1
5-116
BSET
f,#bit4
Juego de bits f
1
1
5-140
BSET
Ws,#bit4
Juego de puntas Ws
1
1
5-141
BSW.C
Ws,Wb
Escribe el bit C en Ws<Wb>
1
1
5-142
BSW.Z
Ws,Wb
Escribe el bit Z en Ws<Wb>
1
1
5-142
BTG
f,#bit4
Cambio de bits f
1
1
5-144
BTG
Ws,#bit4
Cambio de bits Ws
1
1
5-145
BTST
f,#bit4
prueba de bits f
1
1
5-153
BTST.C
Ws,#bit4
Prueba de bits Ws a C
1
1
5-154
BTST.Z
Ws,#bit4
Prueba de bits Ws a Z
1
1
5-154
BTST.C
Ws,Wb
Prueba de bits Ws<Wb> a C
1
1
5-155
BTST.Z
Ws,Wb
Prueba de bits Ws<Wb> a Z
1
1
5-155 
BTSTS
f,#bit4
Pruebe el bit f y luego configure f
1
1
5-157
BTSTS.C
Ws,#bit4
Pruebe el bit Ws en C y luego configure Ws
1
1
5-158
BTSTS.Z
Ws,#bit4
Pruebe los bits de Ws a Z y luego configure Ws
1
1
5-158
FBCL
Ws, viento
Encuentre el cambio de bits desde el lado izquierdo (MSb) 
1
1
5-204
FF1L
Ws, viento
Encuentra el primero desde el lado izquierdo (MSb) 
1
1
5-206
FF1R
Ws, viento
Encuentra el primero desde el lado derecho (LSb) 
1
1
5-208

© 2009 Microchip Technology Inc.
DS70157D-página 37
Sección 3. Descripción general del conjunto de instrucciones
Conjunto de instrucciones 
Descripción general
3
Tabla 3-7:
Comparar/Omitir instrucciones
Sintaxis de ensamblaje
Descripción
palabras
Ciclos(1)
Página 
Número
BTSC
f,#bit4
Prueba de bit f, omitir si está claro
1
1 (2 o 3)
5-146
BTSC
Ws,#bit4
Prueba de bits Ws, omítala si está clara
1
1 (2 o 3)
5-148
BTSS
f,#bit4
Prueba de bit f, omitir si está configurado
1
1 (2 o 3)
5-150
BTSS
Ws,#bit4
Prueba de bits Ws, omitir si está configurado
1
1 (2 o 3)
5-151
CP
f
Comparar (f – WREG)
1
1
5-170
CP
Wb,#encendido5
Comparar (Wb – lit5)
1
1
5-171
CP
Wb,Ws
Comparar (Wb – Ws)
1
1
5-172
CP0
f
Comparar (f – 0x0000)
1
1
5-173
CP0
Ws
Comparar (Ws – 0x0000)
1
1
5-174
CPB
f
Comparar con Préstamo (f – WREG – C)
1
1
5-175
CPB
Wb,#encendido5
Comparar con Préstamo (Wb – lit5 – C)
1
1
5-176
CPB
Wb,Ws
Comparar con Préstamo (Wb – Ws – C)
1
1
5-177
CPSEQ
Wb, Wn
Comparar (Wb – Wn), omitir si =
1
1 (2 o 3)
5-179
CPSGT
Wb, Wn
Comparar (Wb – Wn), omitir si >
1
1 (2 o 3)
5-180
CPSLT
Wb, Wn
Comparar (Wb – Wn), omitir si <
1
1 (2 o 3)
5-181
CPSNE
Wb, Wn
Comparar (Wb – Wn), omitir si ≠
1
1 (2 o 3)
5-182
Nota 1: Las instrucciones de salto condicional se ejecutan en 1 ciclo si no se realiza el salto, 2 ciclos si el salto se realiza durante un
instrucción de una palabra y 3 ciclos si el salto se realiza sobre una instrucción de dos palabras.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 38
© 2009 Microchip Technology Inc.
Tabla 3-8:
Instrucciones de flujo del programa
Sintaxis de ensamblaje
Descripción
palabras
Ciclos
Página 
Número
sujetador
Expr.
Rama incondicionalmente 
1
2
5-117
sujetador
Wn
rama computada
1
2
5-118
sujetador
C,expr.
Ramificar si se lleva (sin préstamo)
1
1 (2)(1)
5-119
sujetador
GE,expr.
Rama si es mayor o igual
1
1 (2)(1)
5-121
sujetador
GEU,expr.
Rama si no está firmada mayor o igual
1
1 (2)(1)
5-122
sujetador
GT,Exp.
Rama si es mayor que
1
1 (2)(1)
5-123
sujetador
GTU,expr.
Rama si no está firmada mayor que
1
1 (2)(1)
5-124
sujetador
LE, Expr.
Rama si es menor o igual
1
1 (2)(1)
5-125
sujetador
LEU,expr.
Rama si no está firmada menor o igual
1
1 (2)(1)
5-126
sujetador
LT,expr.
Sucursal si es menor que
1
1 (2)(1)
5-127
sujetador
LTU,expr.
Rama si no está firmada menos de
1
1 (2)(1)
5-128
sujetador
N,expr.
Rama si es negativo
1
1 (2)(1)
5-129
sujetador
NC, Expr.
Ramificar si no llevar (pedir prestado)
1
1 (2)(1)
5-130
sujetador
NN, Expr
Rama si no es Negativa
1
1 (2)(1)
5-131
sujetador
NOV, exp.
Rama si no se desborda
1
1 (2)(1)
5-132
sujetador
Nueva Zelanda, Expr.
Rama si no es cero
1
1 (2)(1)
5-133
sujetador
OA,expr.
Ramificación si el acumulador A se desborda
1
1 (2)(1)
5-134
sujetador
OB,expr.
Ramificación si el acumulador B se desborda
1
1 (2)(1)
5-135
sujetador
OV,expr.
Rama si se desborda
1
1 (2)(1)
5-136
sujetador
SA,expr.
Ramificar si el acumulador A está saturado
1
1 (2)(1)
5-137
sujetador
SB,expr.
Ramificar si el acumulador B está saturado
1
1 (2)(1)
5-138
sujetador
Z, Expr
Rama si cero
1
1 (2)(1)
5-139
LLAMADA
Expr.
Llamar a subrutina
2
2
5-159
LLAMADA
Wn
Llamar a subrutina indirecta
1
2
5-161
HACER
#lit14,Expr(3)
Codifique a través de PC + Expr, (lit14 + 1) veces
2
2
5-195
HACER
Wn, Expr(3)
Codifique a través de PC + Expr, (Wn + 1) veces
2
2
5-197
IR A
Expr.
Ir a la dirección 
2
2
5-210
IR A
Wn
Ir a la dirección indirecta
1
2
5-211
LLAMADA
Expr.
llamada relativa
1
2
5-281
LLAMADA
Wn
llamada calculada
1
2
5-283
REPETIR
#lit14
Repita la siguiente instrucción (lit14 + 1) veces
1
1
5-285
REPETIR
Wn
Repita la siguiente instrucción (Wn + 1) veces
1
1
5-286
REFIE
Retorno de habilitación de interrupción
1
3 (2)(2)
5-290
RETLW
#lit10,Wn
Regresar con lit10 en Wn
1
3 (2)(2)
5-291
VOLVER
Regreso de subrutina
1
3 (2)(2)
5-292
Nota 1: Las instrucciones de bifurcación condicional se ejecutan en 1 ciclo si no se toma la bifurcación, o en 2 ciclos si se toma la bifurcación.
tomado. 
2: Las instrucciones RETURN se ejecutan en 3 ciclos, pero si hay una excepción pendiente, se ejecutan en 2 ciclos.
3: Esta instrucción solo está disponible en dispositivos dsPIC30F y dsPIC33F.

© 2009 Microchip Technology Inc.
DS70157D-página 39
Sección 3. Descripción general del conjunto de instrucciones
Conjunto de instrucciones 
Descripción general
3
Tabla 3-9:
Instrucciones de sombra/pila
Tabla 3-10:
Instrucciones de control
Tabla 3-11:
Instrucciones DSP (dispositivos dsPIC30F y dsPIC33F)
Sintaxis de ensamblaje
Descripción
palabras
Ciclos
Página 
Número
LNK
#lit14
Puntero de marco de enlace
1
1
5-223
POP
f
POP TOS a f
1
1
5-272
POP
Wd
POP TOS a Wd
1
1
5-273
POP.D
viento
Doble POP de TOS a Wnd:Wnd + 1
1
2
5-274
POP.S
Registros ocultos POP
1
1
5-275
EMPUJAR
f
EMPUJE f a TOS
1
1
5-276
EMPUJAR
Ws
EMPUJE W a TOS
1
1
5-277
EMPUJAR.D
Wns
PUSH doble Wns:Wns + 1 a TOS
1
2
5-278
EMPUJAR.S
PUSH registros de sombra
1
1
5-279
ULNK
Puntero de marco de desvinculación
1
1
5-349
Sintaxis de ensamblaje
Descripción
palabras
Ciclos
Página 
Número
CLRWDT
Borrar temporizador de vigilancia
1
1
5-167
DISI
#lit14
Deshabilitar interrupciones para (lit14 + 1) ciclos de instrucción
1
1
5-188
NOP
Sin operación
1
1
5-270
NOPR
Sin operación
1
1
5-271
PWRSAV
#lit1
Ingrese al modo de ahorro de energía iluminado1
1
1
5-280
REINICIAR
Restablecer dispositivo de software
1
1
5-288
Sintaxis de ensamblaje
Descripción
palabras
Ciclos
Página 
Número
AÑADIR
Acc
Añadir acumuladores
1
1
5-95
AÑADIR
Ws,#Slit4,Acc
Agregar firmado de 16 bits a Acc
1
1
5-96
CLR
Acc,Wx,Wxd,Wy,Wyd,AWB
Borrar cuenta
1
1
5-165
DE
Wm*Wm,Acc,Wx,Wy,Wxd
distancia euclidiana 
(sin acumular)
1
1
5-199
EDAC
Wm*Wm,Acc,Wx,Wy,Wxd
distancia euclidiana
1
1
5-201
ALC
Ws,#Slit4,Acc
Cargar cuenta
1
1
5-221
MAC
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd,AWB Multiplica y acumula
1
1
5-229
MAC
Wm*Wm,Acc,Wx,Wxd,Wy,Wyd
Cuadrar y acumular
1
1
5-231
MOVSAC
Acc,Wx,Wxd,Wy,Wyd,AWB
Mover Wx a Wxd y Wy a Wyd
1
1
5-245
MPY
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd
Multiplique Wn por Wm para Acc
1
1
5-247
MPY
Wm*Wm,Acc,Wx,Wxd,Wy,Wyd
Cuadrado a Acc
1
1
5-249
MPY.N
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd
-(Multiplicar Wn por Wm) a Acc
1
1
5-251
MSC
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd,AWB Multiplica y resta de Acc
1
1
5-253
NEG
Acc
Negar cuenta
1
1
5-269
SACO
Acc,#Slit4,Wd
Cuenta de la tienda
1
1
5-305
SAC.R
Acc,#Slit4,Wd
Tienda Acc redondeada
1
1
5-307
SFTAC
Acc,#Rendija6
Desplazamiento aritmético Acc por Slit6
1
1
5-312
SFTAC
Acc, Wn
Desplazamiento aritmético Acc por (Wn) 
1
1
5-313
SUB
Acc
Restar acumuladores
1
1
5-324

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 40
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70157D-página 41
Conjunto de instrucciones 
Detalles
4
Sección 4. Detalles del conjunto de instrucciones
DESTACADOS
Esta sección del manual contiene los siguientes temas principales:
4.1
Modos de direccionamiento de datos................................................................................................. 42
4.2
Modos de direccionamiento del programa ................................................................................ 51
4.3
Puestos de instrucción................................................................................................ 52
4.4
Operaciones de bytes ................................................................................................................ 54
4.5
Operaciones de movimiento de palabras ................................................................................................ 56
4.6
Uso de operandos literales de 10 bits ......................................................................... 59
4.7
Puntero de pila de software y puntero de marco................................................................. 60
4.8
Instrucciones de sucursal condicional ................................................................................ 65
4.9
Bit de estado Z................................................................................................................ 66
4.10
Uso del registro de trabajo asignado ................................................................. 67
4.11
Formatos de datos DSP (dispositivos dsPIC30F y dsPIC33F).................................... 70
4.12
Uso del acumulador (dispositivos dsPIC30F y dsPIC33F) ........................................ 72
4.13
Acceso al acumulador (dispositivos dsPIC30F y dsPIC33F) ................................. 73
4.14
Instrucciones DSP MAC (dispositivos dsPIC30F y dsPIC33F).................................... 74
4.15
Instrucciones del acumulador DSP (dispositivos dsPIC30F y dsPIC33F).................... 78
4.16
Escalado de datos con la instrucción FBCL (dispositivos dsPIC30F y dsPIC33F) ................. 79
4.17
Normalización del acumulador con la instrucción FBCL (dsPIC30F y dsPIC33F 
Dispositivos)................................................................................................................ 81

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 42
© 2009 Microchip Technology Inc.
4.1
 MODOS DE DIRECCIONAMIENTO DE DATOS
Los dispositivos MCU y DSC de 16 bits admiten tres modos de direccionamiento nativos para acceder a los datos
memoria, junto con varias formas de direccionamiento inmediato. Se podrán realizar accesos a los datos
mediante registro de archivos, registro de direccionamiento directo o registro de direccionamiento indirecto y direccionamiento inmediato
permite que la instrucción utilice un valor fijo.
El direccionamiento de registros de archivos proporciona la capacidad de operar con datos almacenados en los 8K inferiores de datos.
memoria (Cerca de RAM) y también mover datos entre los registros de trabajo y los datos completos de 64K
espacio. El direccionamiento directo de registros se utiliza para acceder a los 16 registros de trabajo asignados en memoria,
W0:W15. El direccionamiento indirecto de registro se utiliza para operar eficientemente con los datos almacenados en todo el
Espacio de datos de 64K, utilizando como dirección efectiva el contenido de los registros de trabajo. Inmediato
El direccionamiento no accede a la memoria de datos, pero proporciona la capacidad de utilizar un valor constante como
operando de instrucción. El rango de direcciones de cada modo se resume en la Tabla 4-1.
Tabla 4-1:
Modos de direccionamiento MCU y DSC de 16 bits
4.1.1
Direccionamiento del registro de archivos
El direccionamiento de registros de archivos lo utilizan instrucciones que utilizan una dirección de datos predeterminada como
operando de la instrucción. La mayoría de las instrucciones que admiten el direccionamiento de registros de archivos
Proporciona acceso a los 8 Kbytes inferiores de memoria de datos, que se denomina Near RAM. Sin embargo,
la instrucción MOV proporciona acceso a los 64 Kbytes de memoria mediante el direccionamiento de registros de archivos.
Esto permite la carga de datos desde cualquier ubicación en la memoria de datos a cualquier registro de trabajo, y
almacenar el contenido de cualquier registro de trabajo en cualquier ubicación de la memoria de datos. Cabe señalar que
El direccionamiento de registros de archivos admite accesos de bytes y palabras a la memoria de datos, con la
excepción de la instrucción MOV, que accede a los 64K de memoria como palabras. Ejemplos de archivo
El direccionamiento de registros se muestra en el ejemplo 4-1.
La mayoría de las instrucciones que admiten el direccionamiento de registros de archivos realizan una operación en el
registro de archivo y el registro de trabajo predeterminado WREG (consulte 2.4 “Registro de trabajo predeterminado
(WREG)”). Si solo se proporciona un operando en la instrucción, WREG es un operando implícito y
Los resultados de la operación se almacenan en el registro de archivos. En estos casos, la instrucción es
efectivamente una instrucción de lectura-modificación-escritura. Sin embargo, cuando tanto el registro de archivos como WREG están
especificado en la instrucción, los resultados de la operación se almacenan en WREG y el contenido del archivo
registro no se modifican. Instrucciones de ejemplo que muestran la interacción entre el registro de archivos.
y WREG se muestran en el ejemplo 4-2.    
Modo de direccionamiento
Rango de direcciones
Registro de archivos
0x0000-0x1FFF (ver nota)
Regístrate Directo
0x0000-0x001F (matriz de registros de trabajo W0:W15)
Registrarse Indirecto
0x0000-0xFFFF
Inmediato
N/A (valor constante)
Nota:
El rango de direcciones para el registro de archivos MOV es 0x0000-0xFFFE.
Nota:
Las instrucciones que admiten el direccionamiento de registros de archivos utilizan ‘f’ como operando en el
tablas de resumen de instrucciones de la Sección 3. “Descripción general del conjunto de instrucciones”.

© 2009 Microchip Technology Inc.
DS70157D-página 43
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
Ejemplo 4-1:
Direccionamiento del registro de archivos 
Ejemplo 4-2:
Direccionamiento de registro de archivos y WREG
4.1.2
Registrar direccionamiento directo
El direccionamiento directo de registros se utiliza para acceder al contenido de los 16 registros de trabajo (W0:W15).
El modo de direccionamiento directo de registros es completamente ortogonal, lo que permite que cualquier registro de trabajo sea
especificado para cualquier instrucción que utilice direccionamiento directo de registro y admite bytes y
accesos de palabras. Las instrucciones que emplean direccionamiento directo de registro utilizan el contenido del
registro de trabajo especificado como datos para ejecutar la instrucción, por lo tanto, este modo de direccionamiento es
útil sólo cuando los datos ya residen en el núcleo del registro de trabajo. Instrucciones de muestra que
utilizar direccionamiento directo de registro se muestran en el Ejemplo 4-3.
Otra característica del direccionamiento directo de registros es que proporciona la capacidad de control de flujo dinámico.
Dado que las variantes de las instrucciones DO y REPEAT admiten el direccionamiento directo de registros,
Se pueden generar construcciones de bucle utilizando estas instrucciones.  
DIC
0x1000
; disminuir los datos almacenados en 0x1000
Antes de la instrucción:
Memoria de datos 0x1000 = 0x5555
Después de la instrucción:
Memoria de datos 0x1000 = 0x5554
MOVIMIENTO
0x27FE, W0
; mover datos almacenados en 0x27FE a W0
Antes de la instrucción:
W0 = 0x5555
Memoria de datos 0x27FE = 0x1234
Después de la instrucción:
W0 = 0x1234
Memoria de datos 0x27FE = 0x1234
Y
0x1000
; Y 0x1000 con WREG, almacenar en 0x1000
Antes de la instrucción:
W0 (WREG) = 0x332C
Memoria de datos 0x1000 = 0x5555
Después de la instrucción:
W0 (WREG) = 0x332C
Memoria de datos 0x1000 = 0x1104
Y
0x1000, WREG
; Y 0x1000 con WREG, almacenar en WREG
Antes de la instrucción:
W0 (WREG) = 0x332C
Memoria de datos 0x1000 = 0x5555
Después de la instrucción:
W0 (WREG) = 0x1104
Memoria de datos 0x1000 = 0x5555
Nota:
Las instrucciones que deben utilizar direccionamiento directo de registro, utilizan los símbolos Wb, Wn,
Wns y Wnd en las tablas de resumen de la Sección 3. “Descripción general del conjunto de instrucciones”.
Comúnmente, el direccionamiento directo de registros también se puede utilizar cuando se registran direcciones indirectas.
Se puede utilizar el direccionamiento. Instrucciones que utilizan registro de direccionamiento indirecto, uso
los símbolos Wd y Ws en las tablas de resumen de la Sección 3. “Conjunto de instrucciones
Descripción general”.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 44
© 2009 Microchip Technology Inc.
Ejemplo 4-3:
 Registrar direccionamiento directo
4.1.3
Registrar direccionamiento indirecto
El direccionamiento indirecto de registro se utiliza para acceder a cualquier ubicación en la memoria de datos tratando el
el contenido de un registro de trabajo como dirección efectiva (EA) a la memoria de datos. Esencialmente, el
El contenido del registro de trabajo se convierte en un puntero a la ubicación en la memoria de datos que debe ser
accedido por la instrucción.
Este modo de direccionamiento es poderoso, porque también permite modificar el contenido del
registro de trabajo, ya sea antes o después de que se realice el acceso a los datos, incrementando o disminuyendo
el EA. Modificando el EA en el mismo ciclo que se está realizando una operación, se registra
El direccionamiento indirecto permite el procesamiento eficiente de datos que se almacenan secuencialmente en
memoria. Los modos de direccionamiento indirecto admitidos por los dispositivos MCU y DSC de 16 bits son
se muestra en la Tabla 4-2.
Tabla 4-2:
Modos de direccionamiento indirecto
EXCH
W2, W3
; Intercambiar W2 y W3
Antes de la instrucción:
 
W2 = 0x3499
 
W3 = 0x003D
Después de la instrucción:
 
W2 = 0x003D
 
W3 = 0x3499
IOR
#0x44, W0
; Inclusivo-OR 0x44 y W0
Antes de la instrucción:
 
W0 = 0x9C2E
Después de la instrucción:
 
W0 = 0x9C6E
SL
W6, W7, W8
; Cambie a la izquierda W6 por W7 y almacene en W8
Antes de la instrucción:
 
W6 = 0x000C
 
W7 = 0x0008
W8 = 0x1234
Después de la instrucción:
 
W6 = 0x000C
 
W7 = 0x0008
 
W8 = 0x0C00
Modo indirecto
Sintaxis
Función
(Instrucción de bytes)
Función
(Instrucción de palabras)
Descripción
Sin modificación
[Wn]
EA = [Wn]
EA = [Wn]
El contenido de Wn forma el EA.
Pre-incremento
[++Wn]
EA = [Wn + = 1]
EA = [Wn + = 2]
Wn se incrementa previamente para formar el EA.
Pre-decremento
[--Wn]
EA = [Wn – = 1]
EA = [Wn – = 2]
Wn se reduce previamente para formar el EA.
Post-incremento
[Wn++]
EA = [Wn]+ = 1
EA = [Wn]+ = 2
El contenido de Wn forma el EA, entonces 
Wn se incrementa posteriormente.
Post-decremento
[Wn--]
EA = [Wn] – = 1
EA = [Wn] – = 2
El contenido de Wn forma el EA, entonces 
Wn está post-disminuido.
Registrar compensación
[Wn+Wb]
EA = [Wn + Wb]
EA = [Wn + Wb]
La suma de Wn y Wb forma el EA. 
Wn y Wb no se modifican.

© 2009 Microchip Technology Inc.
DS70157D-página 45
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
La Tabla 4-2 muestra que cuatro modos de direccionamiento modifican el EA utilizado en la instrucción, y esto
permite realizar las siguientes actualizaciones en el registro de trabajo: post-incremento, post-decremento,
preincremento y predecremento. Dado que todos los EA deben proporcionarse como direcciones de bytes, el soporte es
proporcionadas para las instrucciones en modo Word escalando la actualización de EA en 2. Es decir, en modo Word,
los decrementos previos y posteriores restan 2 del EA almacenado en el registro de trabajo, y
Los incrementos previos y posteriores suman 2 al EA. Esta característica garantiza que después de realizar una modificación del EA,
el EA señalará la siguiente palabra adyacente en la memoria. El ejemplo 4-4 muestra cuán indirecto
El direccionamiento se puede utilizar para actualizar el EA. 
La Tabla 4-2 también muestra que el modo de compensación de registro aborda datos que están compensados desde una base.
EA almacenado en un registro de trabajo. Este modo utiliza el contenido de un segundo registro de trabajo para formar
el EA añadiendo los dos registros de trabajo especificados. Este modo no se escala para el modo Word
instrucciones, pero ofrece el rango de desplazamiento completo de 64 Kbytes. Tenga en cuenta que ninguno de los trabajadores
Se modifican los registros utilizados para formar el EA. El ejemplo 4-5 muestra cómo la compensación de registros es indirecta.
El direccionamiento se puede utilizar para acceder a la memoria de datos.   
Ejemplo 4-4:
Direccionamiento indirecto con actualización de dirección efectiva
Nota:
El MOV con instrucciones de compensación (consulte las páginas 5-239 y 5-240) proporciona una
capacidad de compensación de direccionamiento para usarse con direccionamiento indirecto. En estas instrucciones,
El EA se forma añadiendo el contenido de un registro de trabajo a un archivo de 10 bits con signo.
literal. El ejemplo 4-6 muestra cómo se pueden utilizar estas instrucciones para mover datos hacia y
de la matriz de registros de trabajo.
MOV.B
[W0++], [W13--]
; movimiento de bytes [W0] a [W13]
; post-inc W0, post-disc W13
Antes de la instrucción:
W0 = 0x2300
W13 = 0x2708
Memoria de datos 0x2300 = 0x7783
Memoria de datos 0x2708 = 0x904E
Después de la instrucción:
W0 = 0x2301
W13 = 0x2707 
Memoria de datos 0x2300 = 0x7783
Memoria de datos 0x2708 = 0x9083
AÑADIR
W1, [--W5], [++W8]
; predisminución W5, preincremento W8
 
; agregue W1 a [W5], almacene en [W8]
Antes de la instrucción:
W1 = 0x0800
W5 = 0x2200
W8 = 0x2400
Memoria de datos 0x21FE = 0x7783
Memoria de datos 0x2402 = 0xAACC
Después de la instrucción:
W1 = 0x0800
W5 = 0x21FE
W8 = 0x2402
Memoria de datos 0x21FE = 0x7783
Memoria de datos 0x2402 = 0x7F83

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 46
© 2009 Microchip Technology Inc.
Ejemplo 4-5:
Direccionamiento indirecto con compensación de registro
Ejemplo 4-6:
Mover con instrucciones de compensación literal
MOV.B
[W0+W1], [W7++]
; movimiento de bytes [W0+W1] a W7, post-inc W7
Antes de la instrucción:
W0 = 0x2300
W1 = 0x01FE
W7 = 0x1000
Memoria de datos 0x24FE = 0x7783
Memoria de datos 0x1000 = 0x11DC
Después de la instrucción:
W0 = 0x2300
W1 = 0x01FE
W7 = 0x1001
Memoria de datos 0x24FE = 0x7783
Memoria de datos 0x1000 = 0x1183
ALC
[W0+W8], A
; cargar ACCA con [W0+W8]
; (firmar-extender y rellenar cero)
Antes de la instrucción:
W0 = 0x2344
W8 = 0x0008
ACCA = 0x00 7877 9321
Memoria de datos 0x234C = 0xE290
Después de la instrucción:
W0 = 0x2344
W8 = 0x0008
ACCA = 0xFF E290 0000
Memoria de datos 0x234C = 0xE290
MOVIMIENTO
[W0+0x20], W1
; mover [W0+0x20] a W1
Antes de la instrucción:
W0 = 0x1200
W1 = 0x01FE
Memoria de datos 0x1220 = 0xFD27
Después de la instrucción:
W0 = 0x1200
W1 = 0xFD27
Memoria de datos 0x1220 = 0xFD27
MOVIMIENTO
W4, [W8-0x300]
; mueva W4 a [W8-0x300]
Antes de la instrucción:
W4 = 0x3411
W8 = 0x2944
Memoria de datos 0x2644 = 0xCB98
Después de la instrucción:
W4 = 0x3411
W8 = 0x2944
Memoria de datos 0x2644 = 0x3411

© 2009 Microchip Technology Inc.
DS70157D-página 47
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
4.1.3.1
REGISTRAR EL DIRECCIONAMIENTO INDIRECTO Y EL SET DE INSTRUCCIONES
Los modos de direccionamiento presentados en la Tabla 4-2 demuestran el modo de direccionamiento indirecto.
Capacidad de los dispositivos MCU y DSC de 16 bits. Debido a la codificación de operación y funcional.
Consideraciones, no todas las instrucciones que soportan direccionamiento indirecto soportan todos los modos
se muestra en la Tabla 4-2. La mayoría de las instrucciones que utilizan direccionamiento indirecto admiten el No
Modificar, Direccionamiento Pre-Incremento, Pre-Decremento, Post-Incremento y Post-Decremento
modos. Las instrucciones MOV y varias instrucciones DSP basadas en acumuladores (dsPIC30F y
dispositivos dsPIC33F solamente), también son capaces de utilizar el modo de direccionamiento de compensación de registro. 
4.1.3.2
MODOS DE DIRECCIONAMIENTO INDIRECTO DSP MAC (dsPIC30F Y dsPIC33F 
DISPOSITIVOS)
Las instrucciones DSP MAC utilizan una clase especial de modos de direccionamiento indirecto. tal cual
se describe más adelante en 4.14 “Instrucciones DSP MAC (dispositivos dsPIC30F y dsPIC33F)”, el DSP
La clase de instrucciones MAC es capaz de realizar dos recuperaciones de la memoria usando
direccionamiento. Dado que los algoritmos DSP frecuentemente exigen una gama más amplia de actualizaciones de direcciones, el
Los modos de direccionamiento que ofrecen las instrucciones MAC del DSP proporcionan un mayor rango en el tamaño del
actualización efectiva de domicilio que pueda realizarse. La Tabla 4-3 muestra que tanto X como Y captan previamente
admite modos de direccionamiento post-incremento y post-decremento, con actualizaciones de 2, 4 y 6
bytes. Dado que las instrucciones DSP sólo se ejecutan en modo Word, no se toman disposiciones para archivos de tamaño impar.
Actualizaciones de EA.
Tabla 4-3:
Modos de direccionamiento indirecto DSP MAC
4.1.3.3
MODOS DE DIRECCIONAMIENTO DE MÓDULO Y DE BIT INVERTIDO (dsPIC30F Y 
DISPOSITIVOS dsPIC33F)
La arquitectura DSC de 16 bits proporciona soporte para dos direccionamientos indirectos de registro especiales.
modos, que se utilizan comúnmente para implementar algoritmos DSP. Direccionamiento módulo (o circular)
proporciona un medio automatizado para admitir buffers de datos circulares en la memoria X y/o Y. módulo
Los buffers eliminan la necesidad de que el software realice comprobaciones de límites de direcciones, lo que puede mejorar
el rendimiento de ciertos algoritmos. De manera similar, el direccionamiento de bits invertidos permite acceder
los elementos de un buffer de forma no lineal. Este modo de direccionamiento simplifica el reordenamiento de datos.
para algoritmos FFT radix-2 y proporciona una reducción significativa en el tiempo de procesamiento FFT. 
Ambos modos de direccionamiento son potentes funciones de dsPIC30F y dsPIC33F.
arquitecturas, que pueden ser explotadas por cualquier instrucción que utilice direccionamiento indirecto. Consulte
Consulte el manual de referencia de la familia de dispositivos específicos para obtener detalles sobre el uso de módulo y bit invertido.
direccionamiento.
Nota:
Las instrucciones que utilizan direccionamiento indirecto de registro utilizan los símbolos de operando Wd
y Ws en las tablas de resumen de la Sección 3. “Descripción general del conjunto de instrucciones”.
Modo de direccionamiento
Memoria X
Memoria Y
Indirecto sin modificación
EA = [Wx]
EA = [Wy]
Indirecto con post-incremento en 2
EA = [Wx] + = 2
EA = [Wy] + = 2
Indirecto con Post-Incremento en 4
EA = [Wx] + = 4
EA = [Wy] + = 4
Indirecto con Post-Incremento en 6
EA = [Wx] + = 6
EA = [Wy] + = 6
Indirecto con Post-Decremento en 2
EA = [Wx] – = 2
EA = [Wy] – = 2
Indirecto con Post-Decremento en 4
EA = [Wx] – = 4
EA = [Wy] – = 4
Indirecto con Post-Decremento en 6
EA = [Wx] – = 6
EA = [Wy] – = 6
Indirecto con compensación de registro
EA = [S9 + S12]
EA = [W11 + W12]
Nota:
Como se describe en 4.14 “Instrucciones MAC DSP (dsPIC30F y dsPIC33F
Dispositivos)”, solo se pueden usar W8 y W9 para acceder a la Memoria X, y solo W10 y
Se puede utilizar W11 para acceder a la memoria Y.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 48
© 2009 Microchip Technology Inc.
4.1.4
Direccionamiento Inmediato
En el direccionamiento inmediato, la codificación de la instrucción contiene un operando constante predefinido,
que es utilizado por la instrucción. Este modo de direccionamiento se puede utilizar de forma independiente, pero es más
frecuentemente combinado con los modos Registro de archivos, Direccionamiento directo e indirecto. el tamaño de
el operando inmediato que se puede utilizar varía según el tipo de instrucción. Constantes de tamaño
1 bit (#lit1), 4 bits (#bit4, #lit4 y #Slit4), 5 bits (#lit5), 6 bits (#Slit6), 8 bits (#lit8), 10 bits (#lit10
y #Slit10), se pueden utilizar 14 bits (#lit14) y 16 bits (#lit16). Las constantes pueden estar firmadas o
sin signo y los símbolos #Slit4, #Slit6 y #Slit10 designan una constante con signo. Todos los demás
las constantes inmediatas no están firmadas. La Tabla 4-4 muestra el uso de cada operando inmediato en el
conjunto de instrucciones.
Tabla 4-4:
Operandos inmediatos en el conjunto de instrucciones
La sintaxis para el direccionamiento inmediato requiere que el signo numérico (#) debe aparecer inmediatamente.
precede al valor del operando constante. El símbolo “#” indica al ensamblador que la cantidad
es una constante. Si se utiliza una constante fuera de rango con una instrucción, el ensamblador generará
un error. En el ejemplo 4-7 se muestran varios ejemplos de direccionamiento inmediato.
Nota:
El operando de 6 bits (#Slit6) solo está disponible en dispositivos dsPIC30F y dsPIC33F.
Operando
Uso de instrucciones
#lit1
PWRSAV
#bit4
BCLR, BSET, BTG, BTSC, BTSS, BTST, BTST.C, BTST.Z, BTSTS, 
BTSTS.C, BTSTS.Z
#lit4
ASR, LSR, SL
#rendija4
AGREGAR, LAC, SAC, SAC.R
#lit5
AGREGAR, ADDC, Y, CP, CPB, IOR, MUL.SU, MUL.UU, SUB, SUBB, 
SUBBR, SUBR, XOR
#Rendija6(1)
SFTAC
#lit8
MOV.B, CP, CPB
#lit10
AÑADIR, ADDC, Y, CP, CPB, IOR, RETLW, SUB, SUBB, XOR
#Rendija10
MOVIMIENTO
#lit14
DISI, HACER(1), LNK, REPETIR
#lit16
MOVIMIENTO
Nota 1:
Este operando o instrucción solo está disponible en dispositivos dsPIC30F y dsPIC33F.

© 2009 Microchip Technology Inc.
DS70157D-página 49
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
Ejemplo 4-7:
Direccionamiento Inmediato
4.1.5
Árbol de modo de direccionamiento de datos
Los modos de direccionamiento de datos de las familias PIC24F y PIC24H se resumen en la Figura 4-1.
Figura 4-1:
Árbol de modo de direccionamiento de datos (PIC24F y PIC24H)
Los modos de direccionamiento de datos de dsPIC30F y dsPIC33F se resumen en la Figura 4-2.
PWRSAV
#1
; Ingrese al modo inactivo
AGREGAR.B
#0x10, W0
; Agregue 0x10 a W0 (modo byte)
Antes de la instrucción:
W0 = 0x12A9
Después de la instrucción:
W0 = 0x12B9
XOR
W0, #1, [W1++]
; O exclusivo W0 y 0x1
; Guarde el resultado en [W1]
; W1 posterior al incremento
Antes de la instrucción:
W0 = 0xFFFF
W1 = 0x0890
Memoria de datos 0x0890 = 0x0032
Después de la instrucción:
W0 = 0xFFFF
W1 = 0x0892
Memoria de datos 0x0890 = 0xFFFE
Modos de direccionamiento de datos
Inmediato
Registro de archivos
Pre-incremento
Pre-decremento
Post-incremento
Post-decremento
Registrar compensación
Desplazamiento literal
Sin modificación
directo
indirecto

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 50
© 2009 Microchip Technology Inc.
Figura 4-2:
Árbol de modo de direccionamiento de datos (dsPIC30F y dsPIC33F)
Modos de direccionamiento de datos
Inmediato
Básico
Registro de archivos
Pre-incremento
Pre-decremento
Post-incremento
Post-decremento
Registrar compensación
Desplazamiento literal
Sin modificación
Sin modificación
Post-Decremento (2, 4 y 6)
Registrar compensación
Post-Incremento (2, 4 y 6)
MAC DSP
directo
indirecto
directo
indirecto

© 2009 Microchip Technology Inc.
DS70157D-página 51
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
4.2
 MODOS DE DIRECCIONAMIENTO DEL PROGRAMA
Los dispositivos MCU y DSC de 16 bits tienen un contador de programa (PC) de 23 bits. La PC aborda el
Memoria de programa de 24 bits de ancho para recuperar instrucciones para su ejecución y puede cargarse en varios
maneras. Para compatibilidad de bytes con las instrucciones de lectura y escritura de tabla, cada palabra de instrucción
Consume dos ubicaciones en la memoria del programa. Esto significa que durante la ejecución en serie, la PC está
cargado con PC + 2. 
Se pueden usar varios métodos para modificar la PC de manera no secuencial, y ambos métodos absolutos
y se pueden realizar cambios relativos en el PC. El cambio al PC puede ser de forma inmediata.
valor codificado en la instrucción, o un valor dinámico contenido en un registro de trabajo. En dsPIC30F
y dispositivos dsPIC33F, cuando el bucle DO está activo, la PC se carga con la dirección almacenada en
el registro DOSTART, después de que se ejecuta la instrucción en la dirección DOEND. Por excepción
manejo, la PC se carga con la dirección del controlador de excepciones, que se almacena en el
tabla de vectores de interrupción. Cuando es necesario, la pila de software se utiliza para return el alcance al primer plano.
proceso desde donde ocurrió el cambio en el flujo del programa. 
La Tabla 4-5 resume las instrucciones que modifican la PC. Al realizar llamadas a funciones, es
Se recomienda utilizar RCALL en lugar de CALL, ya que RCALL solo consume 1 palabra de 
memoria del programa.
Tabla 4-5:
Métodos para modificar el flujo del programa
Condición/Instrucción 
Modificación de PC
Uso de la pila de software
Ejecución secuencial
PC = PC + 2
Ninguno
Expr BRA(1)
(Rama incondicionalmente)
PC = PC + 2*Rendija16
Ninguno
Condición BRA, Expr(1)
(Rama condicional)
PC = PC + 2 (condición falsa)
PC = PC + 2 * Slit16 (condición verdadera)
Ninguno
LLAMADA Expr(1)
(Llamar a subrutina)
PC = iluminado23
PC + 4 es EMPUJADO en la pila(2) 
LLAMAR Wn
(Llamada a subrutina indirecta)
PC = Wn
PC + 2 es EMPUJADO en la pila(2) 
IR A Expr(1)
(Salto incondicional)
PC = iluminado23
Ninguno
IR A Wn
(Salto indirecto incondicional)
PC = Wn
Ninguno
RCALL Expr(1)
(Llamada relativa)
PC = PC + 2 * Rendija16
PC + 2 es EMPUJADO en la pila(2) 
RCALL Wn
(Llamada relativa calculada)
PC = PC + 2 * Wn
PC + 2 es EMPUJADO en la pila(2)
Manejo de excepciones
PC = dirección del controlador de excepciones
(leer de la tabla de vectores)
PC + 2 es EMPUJADO en la pila(3)
PC = Instrucción REPETIR objetivo
(REPETIR bucle)
PC no modificada (si REPEAT está activo)
Ninguno
PC = dirección DOEND(4)
(Hacer bucle)
PC = DOSTART (si DO activo)
Ninguno
Nota 1:
Para BRA, CALL y GOTO, Expr puede ser una etiqueta, dirección absoluta o expresión, que se resuelve mediante 
el enlazador a un valor de 16 o 23 bits (Slit16 o lit23). Consulte la Sección 5. “Descripciones de instrucciones” para obtener más detalles.
2:
Después de ejecutar CALL o RCALL, RETURN o RETLW volverá a colocar el Top-of-Stack (TOS) en la PC.
3:
Después de procesar una excepción, RETFIE volverá a colocar el Top-of-Stack (TOS) en la PC.
4:
Esta condición/instrucción solo está disponible en dispositivos dsPIC30F y dsPIC33F.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 52
© 2009 Microchip Technology Inc.
4.3
 PUESTOS DE INSTRUCCIÓN
Para maximizar el cálculo del EA en el espacio de datos y el tiempo de recuperación del operando, el espacio de datos X
Los accesos de lectura y escritura están parcialmente canalizados. Una consecuencia de esta canalización es que la dirección
Pueden surgir dependencias de datos de registro entre operaciones sucesivas de lectura y escritura utilizando
registros comunes.
Las dependencias ‘Read After Write’ (RAW) ocurren a través de los límites de las instrucciones y son detectadas por
el hardware. Un ejemplo de dependencia RAW sería una operación de escritura que modifica W5,
seguido de una operación de lectura que utiliza W5 como puntero de dirección. El contenido de W5 no será
válido para la operación de lectura hasta que se complete la escritura anterior. Este problema se resuelve deteniéndose
la ejecución de la instrucción durante un ciclo de instrucción, lo que permite que la escritura se complete antes de que
Se inicia la siguiente lectura.
4.3.1
Detección de dependencia RAW
Durante la predecodificación de la instrucción, el núcleo determina si existe alguna dependencia del registro de dirección.
inminente a través de un límite de instrucción. La lógica de detección de pérdida compara el registro W
(si corresponde) utilizado para el EA de destino de la instrucción que se está ejecutando actualmente con el registro W
para ser utilizado por el EA fuente (si lo hay) de la instrucción captada previamente. Cuando un partido entre los
Se identifican los registros de destino y origen, se aplica un conjunto de reglas para decidir si
para detener la instrucción por un ciclo. La Tabla 4-6 enumera varias condiciones RAW que causan una
parada en la ejecución de instrucciones.
Tabla 4-6:
Reglas de dependencia sin procesar (detección por hardware)
Destino
Modo de dirección usando Wn
Modo de dirección de origen
Usando Wn
Puesto 
¿Requerido?
Ejemplos(2)
(Wn = W2)
directo
directo
Sin puesto
AÑADIR.W W0, W1, W2
MOV.W W2, W3
indirecto
directo
Sin puesto
AÑADIR.W W0, W1, [W2]
MOV.W W2, W3
indirecto
indirecto 
Sin puesto
AÑADIR.W W0, W1, [W2]
MOV.W [W2], W3
indirecto
Indirecto con pre/post-modificación
Sin puesto
AÑADIR.W W0, W1, [W2]
MOV.W [W2++], W3
Indirecto con pre/post-modificación Directo
Sin puesto
AÑADIR.W W0, W1, [W2++]
MOV.W W2, W3
directo
indirecto 
Puesto(1)
AÑADIR.W W0, W1, W2
MOV.W [W2], W3
directo
Indirecto con pre/post-modificación 
Puesto(1)
AÑADIR.W W0, W1, W2
MOV.W [W2++], W3
indirecto
indirecto 
Puesto(1)
AÑADIR.W W0, W1, [W2](2)
MOV.W [W2], W3(2)
indirecto
Indirecto con pre/post-modificación 
Puesto(1)
AÑADIR.W W0, W1, [W2](2)    
MOV.W [W2++], W3(2) 
Indirecto con pre/post-modificación Indirecto 
Puesto(1)
AÑADIR.W W0, W1, [W2++]
MOV.W [W2], W3
Indirecto con pre/post-modificación Indirecto con pre/post-modificación 
Puesto(1)
AÑADIR.W W0, W1, [W2++]
MOV.W [W2++], W3
Nota 1:
Cuando se detectan paradas, se agrega un ciclo al tiempo de ejecución de la instrucción.
2:
Para estos ejemplos, el contenido de W2 = la dirección asignada de W2 (0x0004).

© 2009 Microchip Technology Inc.
DS70157D-página 53
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
4.3.2
Puestos de instrucción y excepciones
Para mantener una operación determinista, se permite que ocurran paradas de instrucción, incluso si
ocurrir inmediatamente antes del procesamiento de excepción.
4.3.3
La instrucción se detiene y las instrucciones que cambian el flujo del programa
CALL y RCALL escriben en la pila usando W15 y, por lo tanto, pueden estar sujetos a una instrucción
se detiene si la fuente leída de la instrucción posterior utiliza W15.
Las instrucciones GOTO, RETFIE y RETURN nunca están sujetas a un bloqueo de instrucción porque
no realice operaciones de escritura en los registros de trabajo.
4.3.4
Puestos de instrucción y bucles DO/REPEAT
Las instrucciones que operan en un bucle DO o REPEAT están sujetas a paradas de instrucción, al igual que cualquier otro
instrucción. Pueden ocurrir paradas en la entrada y salida del bucle y también durante el procesamiento del bucle.
4.3.5
Puestos de instrucción y PSV
Las instrucciones que operan en el espacio de direcciones PSV están sujetas a paradas de instrucción, como cualquier otra
instrucción. Si se detecta una dependencia de datos en la instrucción inmediatamente posterior a la
Acceso a datos PSV, el segundo ciclo de la instrucción iniciará una parada. ¿Debería un dato
La dependencia se detecta en la instrucción inmediatamente antes del acceso a datos PSV, la última
El ciclo de la instrucción anterior iniciará una pérdida.   
Nota:
Los bucles DO solo están disponibles en dispositivos dsPIC30F y dsPIC33F.
Nota:
Consulte el manual de referencia de la familia de dispositivos específica para obtener información más detallada.
sobre los puestos de instrucción RAW.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 54
© 2009 Microchip Technology Inc.
4.4
 OPERACIONES DE BYTES
Dado que la memoria de datos es direccionable por bytes, la mayoría de las instrucciones base pueden operar en cualquiera de los dos modos:
Modo byte o modo Word. Cuando estas instrucciones operan en modo Byte, las siguientes reglas
aplicar:
• Todas las referencias de registros de trabajo directos utilizan el byte menos significativo del registro de trabajo de 16 bits. 
registrarse y dejar el byte más significativo (MSB) sin cambios
• Todas las referencias de registros de trabajo indirectos utilizan el byte de datos especificado por la dirección de 16 bits. 
almacenado en el registro de trabajo
• Todas las referencias de registros de archivos utilizan el byte de datos especificado por la dirección del byte
• El Registro ESTADO se actualiza para reflejar el resultado de la operación del byte.
Cabe señalar que las direcciones de datos siempre se representan como direcciones de bytes. Además,
El formato de datos nativo es little-endian, lo que significa que las palabras se almacenan con el mínimo
Byte significativo en la dirección inferior y el byte más significativo en la dirección superior adyacente.
dirección (como se muestra en la Figura 4-3). El ejemplo 4-8 muestra operaciones de movimiento de bytes de muestra y
El ejemplo 4-9 muestra operaciones matemáticas de bytes de muestra.   
Ejemplo 4-8:
Operaciones de movimiento de bytes de muestra
Nota:
Las instrucciones que operan en modo Byte deben usar la instrucción “.b” o “.B”
extensión para especificar una instrucción de byte. Por ejemplo, las siguientes dos instrucciones
son formas válidas de una operación de borrado de bytes:
         CLR.b W0
         CLR.B W0
MOV.B
#0x30, W0
; mover el byte literal 0x30 a W0
Antes de la instrucción:
W0 = 0x5555
Después de la instrucción:
W0 = 0x5530
MOV.B
0x1000, W0
; mover el byte en 0x1000 a W0
Antes de la instrucción:
W0 = 0x5555
Memoria de datos 0x1000 = 0x1234
Después de la instrucción:
W0 = 0x5534
Memoria de datos 0x1000 = 0x1234
MOV.B
W0, 0x1001
; byte mueve W0 a la dirección 0x1001
Antes de la instrucción:
W0 = 0x1234
Memoria de datos 0x1000 = 0x5555
Después de la instrucción:
W0 = 0x1234
Memoria de datos 0x1000 = 0x3455
MOV.B
W0, [W1++]
; byte mueve W0 a [W1], luego post-inc W1
Antes de la instrucción:
W0 = 0x1234
W1 = 0x1001
Memoria de datos 0x1000 = 0x5555
Después de la instrucción:
W0 = 0x1234
W1 = 0x1002
Memoria de datos 0x1000 = 0x3455

© 2009 Microchip Technology Inc.
DS70157D-página 55
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
Ejemplo 4-9:
Operaciones matemáticas de bytes de muestra
CLR.B
[W6--]
; byte borrado [W6], luego post-dec W6
Antes de la instrucción:
W6 = 0x1001
Memoria de datos 0x1000 = 0x5555
Después de la instrucción:
W6 = 0x1000
Memoria de datos 0x1000 = 0x0055
SUB.B
W0, #0x10, W1
; byte resta el literal 0x10 de W0
; y almacenar en W1
Antes de la instrucción:
W0 = 0x1234
W1 = 0xFFFF
Después de la instrucción:
W0 = 0x1234
W1 = 0xFF24
AGREGAR.B
W0, W1, [W2++]
; byte agregue W0 y W1, almacene en [W2]
; y post-inc W2
Antes de la instrucción:
W0 = 0x1234
W1 = 0x5678
W2 = 0x1000
Memoria de datos 0x1000 = 0x5555
Después de la instrucción:
W0 = 0x1234
W1 = 0x5678
W2 = 0x1001
Memoria de datos 0x1000 = 0x55AC

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 56
© 2009 Microchip Technology Inc.
4.5
 OPERACIONES DE MOVIMIENTO DE PALABRA
Aunque el espacio de datos es direccionable por bytes, todas las operaciones de movimiento realizadas en modo Word deben
estar alineado con las palabras. Esto significa que para todos los operandos de origen y destino, el menos significativo
El bit de dirección debe ser ‘0’. Si se realiza un movimiento de palabra hacia o desde una dirección impar, se producirá un error de dirección.
Se genera una excepción. Asimismo, todas las palabras dobles deben estar alineadas entre palabras. La figura 4-3 muestra cómo
Los bytes y las palabras pueden alinearse en la memoria de datos. El ejemplo 4-10 contiene varias palabras legales.
operaciones de traslado.
Cuando se genera una excepción debido a un acceso desalineado, la excepción se toma después del
se ejecuta la instrucción. Si el acceso ilegal se produce a partir de una lectura de datos, se permitirá la operación.
para completar, pero el bit menos significativo de la dirección de origen se borrará para forzar la palabra
alineación. Si el acceso ilegal ocurre durante una escritura de datos, se inhibirá la escritura. Ejemplo 4-11
contiene varias operaciones ilegales de movimiento de palabras.
Figura 4-3:
Alineación de datos en la memoria
0x1001
b0
0x1000
0x1003
b1
0x1002
0x1005
b3
b2
0x1004
0x1007
b5
b4
0x1006
0x1009
b7
b6
0x1008
0x100B
b8
0x100A
Leyenda:
    b0 – byte almacenado en 0x1000
    b1 – byte almacenado en 0x1003
    b3:b2 – palabra almacenada en 0x1005:1004 (b2 es LSB)
    b7:b4 – palabra doble almacenada en 0x1009:0x1006 (b4 es LSB)
    b8 – byte almacenado en 0x100A
Nota:
Las instrucciones que funcionan en modo Word no necesitan utilizar una instrucción
extensión. Sin embargo, se pueden especificar con una extensión opcional “.w” o “.W”,
si lo desea. Por ejemplo, las siguientes instrucciones son formas válidas de una palabra clara
operación:
         BORRAR W0
         CLR.w W0 
         BORRAR.W W0

© 2009 Microchip Technology Inc.
DS70157D-página 57
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
Ejemplo 4-10:
Operaciones de movimiento de palabras legales
MOVIMIENTO
#0x30, W0
; mover la palabra literal 0x30 a W0
Antes de la instrucción:
W0 = 0x5555
Después de la instrucción:
W0 = 0x0030
MOVIMIENTO
0x1000, W0
; mover la palabra en 0x1000 a W0
Antes de la instrucción:
W0 = 0x5555
Memoria de datos 0x1000 = 0x1234
Después de la instrucción:
W0 = 0x1234
Memoria de datos 0x1000 = 0x1234
MOVIMIENTO
[W0], [W1++]
; movimiento de palabra [W0] a [W1],
; luego post-aum W1
Antes de la instrucción:
W0 = 0x1234
W1 = 0x1000
Memoria de datos 0x1000 = 0x5555
Memoria de datos 0x1234 = 0xAAAA
Después de la instrucción:
W0 = 0x1234
W1 = 0x1002
Memoria de datos 0x1000 = 0xAAAA
Memoria de datos 0x1234 = 0xAAAA

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 58
© 2009 Microchip Technology Inc.
Ejemplo 4-11:
Operaciones ilegales de movimiento de palabras
MOVIMIENTO
0x1001, W0
; mover la palabra en 0x1001 a W0
Antes de la instrucción:
W0 = 0x5555
Memoria de datos 0x1000 = 0x1234
Memoria de datos 0x1002 = 0x5678
Después de la instrucción:
W0 = 0x1234
Memoria de datos 0x1000 = 0x1234
Memoria de datos 0x1002 = 0x5678
TRAMPA DE ERROR DE DIRECCIÓN GENERADA
(la dirección de origen está desalineada, por lo que se realiza MOV)
MOVIMIENTO
W0, 0x1001
; mueva W0 a la palabra en 0x1001
Antes de la instrucción:
W0 = 0x1234
Memoria de datos 0x1000 = 0x5555
Memoria de datos 0x1002 = 0x6666
Después de la instrucción:
W0 = 0x1234
Memoria de datos 0x1000 = 0x5555
Memoria de datos 0x1002 = 0x6666
TRAMPA DE ERROR DE DIRECCIÓN GENERADA 
(la dirección de destino está desalineada, por lo que no se realiza MOV)
MOVIMIENTO
[W0], [W1++]
; movimiento de palabra [W0] a [W1], 
; luego post-aum W1
Antes de la instrucción:
W0 = 0x1235
W1 = 0x1000
Memoria de datos 0x1000 = 0x1234
Memoria de datos 0x1234 = 0xAAAA
Memoria de datos 0x1236 = 0xBBBB
Después de la instrucción:
W0 = 0x1235
W1 = 0x1002
Memoria de datos 0x1000 = 0xAAAA
Memoria de datos 0x1234 = 0xAAAA
Memoria de datos 0x1236 = 0xBBBB
TRAMPA DE ERROR DE DIRECCIÓN GENERADA
(la dirección de origen está desalineada, por lo que se realiza MOV)

© 2009 Microchip Technology Inc.
DS70157D-página 59
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
4.6
 USO DE OPERANDOS LITERALES DE 10 BITS
Varias instrucciones que admiten el modo Byte y Word tienen operandos de 10 bits. por byte
instrucciones, un literal de 10 bits es demasiado grande para usarlo. Entonces, cuando se usan literales de 10 bits en modo Byte, el
El rango del operando debe reducirse a 8 bits o el ensamblador generará un error. Tabla 4-7
muestra que el rango de un literal de 10 bits es 0:1023 en modo Word y 0:255 en modo Byte.
Las instrucciones que emplean literales de 10 bits en modo Byte y Word son: ADD, ADDC, AND, IOR,
RETLW, SUB, SUBB y XOR. El ejemplo 4-12 muestra cómo se utilizan los literales positivos y negativos en
Modo byte para la instrucción ADD.
Tabla 4-7:
Codificación literal de 10 bits     
Ejemplo 4-12:
Uso de literales de 10 bits para operandos de bytes
Valor literal
Modo de palabra
kk kkkk kkkk
Modo de bytes
kkkk kkkk
0
00 0000 0000
0000 0000
1
00 0000 0001
0000 0001
2
00 0000 0010
0000 0010
127
00 0111 1111
0111 1111
128
00 1000 0000
1000 0000
255
00 1111 1111
1111 1111
256
01 0000 0000
N/A
512
10 0000 0000
N/A
1023
11 1111 1111
N/A
AGREGAR.B
#0x80, W0
; agregue 128 (o -128) a W0
AGREGAR.B
#0x380, W0
; ERROR... Sintaxis ilegal para el modo byte 
AGREGAR.B
#0xFF, W0
; sumar 255 (o -1) a W0
AGREGAR.B
#0x3FF, W0
; ERROR... Sintaxis ilegal para el modo byte
AGREGAR.B
#0xF, W0
; suma 15 a W0
AGREGAR.B
#0x7F, W0
; sumar 127 a W0
AGREGAR.B
#0x100, W0
; ERROR... Sintaxis ilegal para el modo byte
Nota:
Usar un valor literal mayor que 127 en modo Byte es funcionalmente idéntico a usar
el valor equivalente en complemento a dos negativos, ya que el bit más significativo del
Se establece el byte. Cuando se opera en modo Byte, el ensamblador aceptará un valor positivo
o valor literal negativo (es decir, #-10).

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 60
© 2009 Microchip Technology Inc.
4.7
 PUNTERO DE PILA DE SOFTWARE Y PUNTERO DE MARCO
4.7.1
 Puntero de pila de software
Los dispositivos MCU y DSC de 16 bits cuentan con una pila de software que facilita las llamadas a funciones y
manejo de excepciones. W15 es el puntero de pila (SP) predeterminado y después de cualquier reinicio, se inicializa para
0x0800. Esto asegura que el SP apuntará a una RAM válida y permitirá la disponibilidad de la pila para
excepciones, que pueden ocurrir antes de que el software del usuario configure el SP. El usuario puede reprogramar
el SP durante la inicialización en cualquier ubicación dentro del espacio de datos.
El SP siempre apunta a la primera palabra libre disponible (Top-of-Stack) y llena la pila de software,
trabajando desde direcciones inferiores hacia direcciones superiores. Pre-decrementa para un POP de pila
(lectura) y post-incrementos para una pila PUSH (escritura).
La pila de software se manipula mediante las instrucciones PUSH y POP. El PUSH y el POP
Las instrucciones son el equivalente a una instrucción MOV, con W15 utilizado como puntero de destino. Para
Por ejemplo, el contenido de W0 se puede PUSH en el Top-of-Stack (TOS) mediante: 
EMPUJAR W0
Esta sintaxis es equivalente a:
MOVIMIENTO W0,[W15++]
El contenido de los TOS puede devolverse a W0 mediante: 
POP W0
Esta sintaxis es equivalente a:
MOVIMIENTO [--W15],W0
Durante cualquier instrucción CALL, la PC es EMPUJADA en la pila, de modo que cuando la subrutina
completa la ejecución, el flujo del programa puede reanudarse desde la ubicación correcta. Cuando la PC está
Empujado en la pila, PC<15:0> se EMPUJA en la primera palabra de pila disponible, luego
PC<22:16> está PUSH. Cuando se PUSHed PC<22:16>, los 7 bits más significativos de la PC son
extendido a cero antes de realizar el EMPUJE, como se muestra en la Figura 4-4. Durante el procesamiento de excepciones,
los 7 bits más significativos del PC se concatenan con el byte inferior del ESTADO
registro (SRL) e IPL<3>, CORCON<3>. Esto permite que el contenido del registro de ESTADO primario
y el nivel de prioridad de interrupción de la CPU se conservará automáticamente durante las interrupciones.
Figura 4-4:
Operación de pila para la instrucción CALL
Nota:
Para proteger contra accesos a la pila desalineados, W15<0> siempre está claro.
0
15
W15 (antes de LLAMADA)
W15 (después de LLAMADA)
La pila crece hacia
dirección superior
0x0000
ordenador<15:0>
 0x0
PC<22:16>
Parte superior de la pila
0xFFFE
Nota:
Para excepciones, los nueve bits superiores de la segunda palabra PUSHed contienen
el SRL y el IPL<3>.

© 2009 Microchip Technology Inc.
DS70157D-página 61
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
4.7.1.1
EJEMPLO DE PUNTERO DE PILA
La Figura 4-5 a la Figura 4-8 muestra cómo se modifica la pila de software para el fragmento de código.
se muestra en el ejemplo 4-13. La Figura 4-5 muestra la pila de software antes de que se ejecute el primer PUSH.
Tenga en cuenta que el SP tiene el valor inicializado de 0x0800. Además, el ejemplo carga 0x5A5A.
y 0x3636 a W0 y W1, respectivamente. La pila se EMPUJA por primera vez en la Figura 4-6 y
el valor contenido en W0 se copia a TOS. W15 se actualiza automáticamente para señalar el siguiente
ubicación de pila disponible y el nuevo TOS es 0x0802. En la Figura 4-7, el contenido de W1 es
Se EMPUJA en la pila y el nuevo TOS se convierte en 0x0804. En la Figura 4-8, la pila aparece como POP,
que copia el último valor PUSHed (W1) a W3. El SP disminuye durante el POP
operación, y al final del ejemplo, el TOS final es 0x0802. 
Ejemplo 4-13:
 Uso del puntero de pila
Figura 4-5:
Puntero de pila antes del primer PUSH
Figura 4-6:
Puntero de pila después de la instrucción “PUSH W0” 
MOVIMIENTO
#0x5A5A, W0
; Cargue W0 con 0x5A5A
MOVIMIENTO
#0x3636, W1
; Cargue W1 con 0x3636
EMPUJAR
W0
; Empuje W0 a TOS (consulte la Figura 4-5)
EMPUJAR
W1
; Empuje W1 a TOS (consulte la Figura 4-7)
POP
W3
; Pop TOS a W3 (ver Figura 4-8)
0x0000
0xFFFE
0x0800
W15 (SP)
W15 = 0x0800
W0 = 0x5A5A
W1 = 0x3636
<TOS>
0x0000
0xFFFE
0x0800
W15 (SP)
W15 = 0x0802
W0 = 0x5A5A
W1 = 0x3636
5A5A
<TOS>
0x0802

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 62
© 2009 Microchip Technology Inc.
Figura 4-7:
Puntero de pila después de la instrucción “PUSH W1” 
Figura 4-8:
Puntero de pila después de la instrucción “POP W3” 
4.7.2
Puntero de marco de pila de software
Un Stack Frame es una sección de memoria definida por el usuario que reside en la pila de software. Se utiliza para
asignar memoria para las variables temporales que utiliza una función, y se puede asignar un marco de pila
creado para cada función. W14 es el puntero de marco de pila (FP) predeterminado y se inicializa para
0x0000 en cualquier reinicio. Si no se utiliza el puntero del marco de pila, se puede utilizar W14 como cualquier otro
registro de trabajo. 
Las instrucciones de enlace (LNK) y desvinculación (ULNK) proporcionan la funcionalidad Stack Frame. El LNK
La instrucción se utiliza para crear un marco de pila. Se utiliza durante una secuencia de llamada para ajustar el SP,
de modo que la pila pueda usarse para almacenar variables temporales utilizadas por la función llamada. después
la función completa la ejecución, la instrucción ULNK se utiliza para eliminar el marco de pila
creado por la instrucción LNK. Las instrucciones LNK y ULNK siempre deben usarse juntas para
Evite el desbordamiento de la pila. 
0x0000
0xFFFE
0x0800
W15 (SP)
W15 = 0x0804
W0 = 0x5A5A
W1 = 0x3636
5A5A
<TOS>
0x0802
3636
0x0804
0x0000
0xFFFE
0x0800
W15 (SP)
W15 = 0x0802
W0 = 0x5A5A
W1 = 0x3636
5A5A
0x0802
<TOS>
0x0804
W3 = 0x3636
Nota: El contenido de 0x802, los nuevos TOS, permanece sin cambios (0x3636).

© 2009 Microchip Technology Inc.
DS70157D-página 63
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
4.7.2.1
EJEMPLO DE PUNTERO DE MARCO DE APILACIÓN
La Figura 4-9 a la Figura 4-11 muestra cómo se crea y elimina un marco de pila para el código.
fragmento que se muestra en el ejemplo 4-14. Este ejemplo demuestra cómo funciona un Stack Frame y
no es indicativo del código generado por el compilador. La Figura 4-9 muestra la condición de la pila en
al comienzo del ejemplo, antes de que los registros se EMPUJEN en la pila. Aquí, W15 puntos.
a la primera ubicación de pila libre (TOS) y W14 apunta a una parte de la memoria de pila asignada para
la rutina que se está ejecutando actualmente.
Antes de llamar a la función “COMPUTE”, se muestran los parámetros de la función (W0, W1 y W2).
EMPUJADO en la pila. Después de ejecutar la instrucción “CALL COMPUTE”, la PC cambia al modo
La dirección de “COMPUTE” y la dirección de retorno de la función “TASKA” se colocan en la pila.
(Figura 4-10). La función “COMPUTE” luego usa la instrucción “LNK #4” para EMPUJAR la llamada
valor del puntero de marco de la rutina en la pila y el nuevo puntero de marco se configurará para que apunte al
Puntero de pila actual. Luego, se agrega el literal 4 a la dirección del puntero de pila en W15, lo que
reserva memoria para dos palabras de datos temporales (Figura 4-11).
Dentro de la función “COMPUTE”, el FP se utiliza para acceder a los parámetros de la función y temporales
variables (locales). [W14 + n] accederá a las variables temporales utilizadas por la rutina y [W14 – n]
Se utiliza para acceder a los parámetros. Al final de la función, la instrucción ULNK se utiliza para copiar
la dirección del puntero de trama al puntero de pila y luego haga POP la trama de la subrutina que llama
Puntero al registro W14. La instrucción ULNK devuelve la pila al estado mostrado
en la Figura 4-10.
Una instrucción RETURN volverá al código que llamó a la subrutina. El código de llamada es
responsable de eliminar los parámetros de la pila. Las instrucciones RETURN y POP
restaure la pila al estado que se muestra en la Figura 4-9.
Ejemplo 4-14:
Uso del puntero de marco
Figura 4-9:
Pila al comienzo del ejemplo 4-14
TAREA: 
...   
EMPUJAR
W0
; Empujar parámetro 1
EMPUJAR
W1
; Empujar parámetro 2
EMPUJAR
W2
; Empujar parámetro 3
LLAMADA
COMPUTAR
; Llamar a la función COMPUTAR
POP
W2
; Parámetro pop 3
POP
W1
; Parámetro pop 2
POP
W0
; Parámetro pop 1
    ...
COMPUTAR:
LNK #4
; Apilar FP, asignar 4 bytes para variables locales
...
ULNK
; Liberar memoria asignada, restaurar FP original    
VOLVER
; Volver a TASKA
0x0000
0xFFFE
0x0800
W14 (PF)
<TOS>
W15 (SP)
TAREA
marco
de

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 64
© 2009 Microchip Technology Inc.
Figura 4-10:
Apilar después de que se ejecute “CALLCOMPUTE”
Figura 4-11:
Apilar después de que se ejecute “LNK #4”
4.7.3
Desbordamiento del puntero de pila 
Hay un registro de límite de pila (SPLIM) asociado con el puntero de pila que se restablece a 0x0000.
SPLIM es un registro de 16 bits, pero SPLIM<0> está fijado en ‘0’, porque todas las operaciones de pila deben ser
alineado con palabras.
La verificación de desbordamiento de pila no se habilitará hasta que se produzca una escritura de palabra en SPLIM, después de lo cual
solo se puede desactivar mediante un reinicio del dispositivo. Todas las direcciones efectivas generadas utilizando W15 como
El origen o el destino se comparan con el valor en SPLIM. ¿Debe ser la dirección efectiva
mayor que el contenido de SPLIM, se genera una trampa de error de pila.
Si se ha habilitado la verificación de desbordamiento de pila, también se producirá una trampa de error de pila si el W15 es efectivo.
El cálculo de la dirección se realiza al final del espacio de datos (0xFFFF).
Consulte el manual de referencia de la familia de dispositivos específica para obtener más información sobre la captura de errores de pila.
4.7.4
Desbordamiento insuficiente del puntero de pila
La pila se inicializa a 0x0800 durante el reinicio. Se iniciará una trampa de error de pila si la pila
La dirección del puntero alguna vez será menor que 0x0800.
Nota:
Las ubicaciones en el espacio de datos entre 0x0000 y 0x07FF están, en general, reservadas para
Registros de funciones especiales (SFR) centrales y periféricos.
0x0000
0xFFFE
0x0800
W14 (PF)
Parámetro 1
W15 (SP)
TAREA
marco
de
Parámetro 2
Parámetro 3
ordenador<15:0>
0:PC<22:16>
<TOS>
0x0000
0xFFFE
0x0800
W14 (PF)
Parámetro 1
W15 (SP)
TAREA
marco 
   de
Parámetro 2
Parámetro 3
ordenador<15:0>
0:PC<22:16>
<TOS>
FP de TASKA
Palabra temporal 1
Palabra temporal 2

© 2009 Microchip Technology Inc.
DS70157D-página 65
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
4.8
 Instrucciones de rama condicional
Las instrucciones de bifurcación condicional se utilizan para dirigir el flujo del programa, según el contenido del
Registro de ESTADO. Estas instrucciones se utilizan generalmente junto con una clase de comparación.
instrucción, pero pueden ser empleados efectivamente después de cualquier operación que modifique el ESTADO
registrarse. 
el 
comparar 
instrucciones 
CP, 
CP0 
y 
CPB, 
realizar 
un 
restar 
operación
(minuendo – sustraendo), pero en realidad no almacena el resultado de la resta. En lugar de eso, compare
Las instrucciones simplemente actualizan las banderas en el registro STATUS, de modo que una rama condicional subsiguiente
La instrucción puede cambiar el flujo del programa probando el contenido del registro STATUS actualizado. si
el resultado de la prueba del registro ESTADO es verdadero, se toma la sucursal. Si el resultado del ESTADO
la prueba de registro es falsa, la sucursal no se toma.
Las instrucciones de rama condicional admitidas por los dispositivos dsPIC30F y dsPIC33F son
se muestra en la Tabla 4-8. Esta tabla identifica la condición en el registro ESTADO que debe ser verdadera.
para que se tome la rama. En algunos casos, solo se prueba un bit (como en BRA C), mientras que en otros
En algunos casos, se realiza una operación lógica compleja (como en BRA GT). Para dsPIC30F y dsPIC33F
dispositivos, vale la pena señalar que se admiten pruebas condicionales firmadas y no firmadas, y que
Se proporciona soporte para algoritmos DSP con los mnemónicos de condición OA, OB, SA y SB.
Tabla 4-8:
Instrucciones de rama condicional 
Nota 1:
Las instrucciones tienen la forma: mnemónico BRA, Expr.
2:
GEU es idéntico a C y se ensamblará de manera inversa a BRA C, Expr.
3:
LTU es idéntica a NC y se ensamblará de manera inversa a BRA NC, Expr.
4:
Esta condición solo está disponible en dispositivos dsPIC30F y dsPIC33F.
Condición
Mnemónico(1)
Descripción
Prueba de estado
c
Llevar (no pedir prestado)
c
GE
Firmado mayor o igual
(N&&OV) || (N&&OV)
UEE(2)
Sin firmar mayor o igual
c
GT
Firmado mayor que
(Z&&N&&OV) || (Z&&N&&OV)
GTU
Sin firmar mayor que
C&&Z
LE
Firmado menor o igual
Z || (N&&OV) || (N&&OV)
UPE
Sin firmar menor o igual
C || z
LT
Firmado menos de
(N&&OV) || (N&&OV)
ULT(3)
Sin firmar menos de
c
norte
Negativo
norte
Carolina del Norte
No llevar (pedir prestado)
c
NN
No negativo
norte
NOVIEMBRE
No se desborda
VO
Nueva Zelanda
No cero
z
OA(4)
Acumulador A desbordamiento
OA
OB(4)
Desbordamiento del acumulador B
OB
VO
Desbordamiento
VO
SA(4)
Acumulador A saturado
SA
SB(4)
Acumulador B saturado
SB
z
Cero
z
Nota:
Las instrucciones “Comparar y omitir” (CPBEQ, CPBGT, CPBLT, CPBNE, CPSEQ,
CPSGT, CPSLT y CPSNE) no modifican el registro STATUS.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 66
© 2009 Microchip Technology Inc.
4.9
 BITS DE ESTADO Z
El bit de estado Z es un bit de estado cero especial que resulta útil para la aritmética de precisión extendida. el
El bit Z funciona como un indicador Z normal para todas las instrucciones, excepto aquellas que utilizan la entrada de acarreo/préstamo.
(ADDC, CPB, SUBB y SUBBR). Para las instrucciones ADDC, CPB, SUBB y SUBBR, el bit Z puede
sólo se borrará y nunca se configurará. Si el resultado de una de estas instrucciones es distinto de cero, el bit Z
será borrado y permanecerá borrado, independientemente del resultado de ADDC, CPB, SUBB o
Operaciones SUBBR. Esto permite utilizar el bit Z para realizar una verificación de cero simple en el
resultado de una serie de operaciones de precisión prolongadas.
Una secuencia de instrucciones que trabajan con datos de precisión múltiple (comenzando con una instrucción sin
llevar/tomar prestada entrada), automáticamente y lógicamente Y los resultados sucesivos de la prueba cero. Todos
Los resultados deben ser cero para que el indicador Z permanezca configurado al final de la secuencia de operaciones. si el
resultado de la instrucción ADDC, CPB, SUBB o SUBBR es distinto de cero, el bit Z se borrará y
permanecerá borrado para todas las instrucciones ADDC, CPB, SUBB o SUBBR posteriores. El ejemplo 4-15 muestra
cómo funciona el bit Z para una suma de 32 bits. Muestra cómo se ve afectado el bit Z en una adición de 32 bits.
implementado con una secuencia de instrucciones ADD/ADDC. El primer ejemplo genera un resultado cero.
solo para la palabra más significativa, y el segundo ejemplo genera un resultado cero tanto para la
palabra menos significativa y palabra más significativa.
Ejemplo 4-15:
Operación del bit de estado ‘Z’ para adición de 32 bits
; Suma dos dobles (G0:G1 y G2:G3)
; Guarde el resultado en W5:W4
AÑADIR
W0, W2, W4
; Agregue LSWord y guárdelo en W4
ADDC
W1, W3, W5
; Agregue MSWord y guárdelo en W5
Antes de la suma de 32 bits (resultado cero para la palabra más significativa):
W0 = 0x2342
W1 = 0xFFF0
W2 = 0x39AA
W3 = 0x0010
W4 = 0x0000
W5 = 0x0000
SR = 0x0000
Después de la adición de 32 bits:
W0 = 0x2342
W1 = 0xFFF0
W2 = 0x39AA
W3 = 0x0010
W4 = 0x5CEC
W5 = 0x0000
SR = 0x0201 (CC,C=1)
Antes de la suma de 32 bits (resultado cero para la palabra menos significativa y la palabra más significativa):
W0 = 0xB76E
W1 = 0xFB7B
W2 = 0x4892
W3 = 0x0484
W4 = 0x0000
W5 = 0x0000
SR = 0x0000
Después de la adición de 32 bits:
W0 = 0xB76E
W1 = 0xFB7B
W2 = 0x4892
W3 = 0x0485
W4 = 0x0000
W5 = 0x0000
SR = 0x0103 (CC,Z,C=1)

© 2009 Microchip Technology Inc.
DS70157D-página 67
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
4.10
 USO DEL REGISTRO DE TRABAJO ASIGNADO
Los 16 registros de trabajo de los dispositivos MCU y DSC de 16 bits proporcionan un gran conjunto de registros para
Generación eficiente de código e implementación de algoritmos. En un esfuerzo por mantener un conjunto de instrucciones
que proporciona capacidad avanzada, un entorno de ejecución estable y compatibilidad con versiones anteriores
Con núcleos de procesador Microchip anteriores, algunos registros de trabajo tienen un uso preasignado.
La Tabla 4-9 resume estas asignaciones de registros de trabajo. Para dsPIC30F y dsPIC33F,
Se proporcionan detalles adicionales en las subsecciones 4.10.1 “Operandos DSP implícitos (dsPIC30F y
Dispositivos dsPIC33F)” hasta 4.10.3 “Compatibilidad del microcontrolador PIC®”.
Tabla 4-9:
Asignaciones de Registro de Trabajo Especial  
4.10.1
Operandos DSP implícitos (dispositivos dsPIC30F y dsPIC33F)
Para ayudar a la codificación de instrucciones y mantener la uniformidad entre la clase de instrucciones DSP,
algunos registros de trabajo tienen funcionalidad preasignada. Para todas las instrucciones DSP que tienen
capacidad de captación previa, se deben cumplir las siguientes 10 asignaciones de registros:
• W4-W7 se utilizan para operandos aritméticos
• W8-W11 se utilizan para direcciones de captación previa (punteros)
• W12 se utiliza para el índice de compensación del registro de captación previa 
• W13 se utiliza para el destino de escritura posterior del acumulador.
Estas restricciones sólo se aplican a la clase de instrucciones DSP MAC, que utilizan
registros y tiene capacidad de captación previa (descrita en 4.15 “Instrucciones del acumulador DSP
(Dispositivos dsPIC30F y dsPIC33F)”). Las instrucciones afectadas son CLR, ED, EDAC, MAC,
MOVSAC, MPY, MPY.N y MSC. 
La clase de instrucciones del acumulador DSP (descritas en 4.15 “Instrucciones del acumulador DSP
(Dispositivos dsPIC30F y dsPIC33F)”) no están obligados a seguir las asignaciones de registros de trabajo
en la Tabla 4-9 y podrá utilizar libremente cualquier registro de trabajo cuando sea necesario. 
Registrarse
Asignación especial
W0
WREG predeterminado, cociente de división
W1
dividir el resto
W2
“MUL f” Producto palabra menos significativa
W3
“MUL f” Palabra más significativa del producto
W4
Operando MAC(1)
W5
Operando MAC(1)
W6
Operando MAC(1)
W7
Operando MAC(1)
W8
Dirección de captación previa MAC (memoria X)(1)
W9
Dirección de captación previa MAC (memoria X)(1)
W10
Dirección de captación previa MAC (memoria Y)(1)
W11
Dirección de captación previa MAC (memoria Y)(1)
W12
Compensación de captación previa de MAC(1)
W13
Destino de reescritura MAC(1)
W14
Puntero de marco
W15
Puntero de pila
Nota 1:
Esta asignación solo es aplicable en dispositivos dsPIC30F y dsPIC33F.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 68
© 2009 Microchip Technology Inc.
4.10.2
Marco implícito y puntero de pila
Para adaptarse al uso de la pila de software, W14 es el puntero de trama implícito (utilizado por LNK y
instrucciones ULNK) y W15 es el puntero de pila implícito (utilizado por CALL, LNK, POP, PUSH,
instrucciones RCALL, RETFIE, RETLW, RETURN, TRAP y ULNK). Aunque W14 y W15
tienen este uso implícito, aún se pueden usar como operandos genéricos en cualquier instrucción, con el
excepciones descritas en 4.10.1 “Operandos DSP implícitos (dispositivos dsPIC30F y dsPIC33F)”. si
W14 y W15 deben usarse para otros fines (se recomienda encarecidamente que permanezcan reservados
para Frame y Stack Pointer), se debe tener mucho cuidado para que el tiempo de ejecución
El entorno no está dañado.
4.10.3
Compatibilidad del microcontrolador PIC®
4.10.3.1
REGISTRO DE TRABAJO PREDETERMINADO WREG
Para facilitar el camino de migración para los usuarios de las familias de MCU PIC de 8 bits de Microchip, la MCU de 16 bits y
Los dispositivos DSC han coincidido lo más posible con la funcionalidad de los conjuntos de instrucciones PIC MCU.
posible. Una diferencia importante entre la MCU y DSC de 16 bits y la MCU PIC de 8 bits
procesadores es el número de registros de trabajo proporcionados. Las familias de MCU PIC de 8 bits solo proporcionan
un registro de trabajo de 8 bits, mientras que las familias MCU y DSC de 16 bits proporcionan dieciséis registros de trabajo de 16 bits.
registros. Para acomodar el único registro de trabajo de la MCU PIC de 8 bits, la MCU de 16 bits
y el conjunto de instrucciones del dispositivo DSC ha designado un registro de trabajo como el registro de trabajo predeterminado.
regístrese para recibir todas las instrucciones de registro de archivos heredados. El registro de trabajo predeterminado está configurado en W0 y es
utilizado por todas las instrucciones que utilizan el direccionamiento de registros de archivos.
Además, la sintaxis utilizada por el ensamblador de dispositivos MCU y DSC de 16 bits para especificar el valor predeterminado
El registro de trabajo es similar al utilizado por el ensamblador PIC MCU de 8 bits. Como se muestra en el detalle
descripciones de instrucciones en la Sección 5. “Descripciones de instrucciones”, “WREG” deben usarse para
especifique el registro de trabajo predeterminado. El ejemplo 4-16 muestra varias instrucciones que utilizan WREG.
Ejemplo 4-16:
 Uso del registro de trabajo predeterminado WREG
4.10.3.2
PRODH:PAR DE REGISTRO PRODL
Otra diferencia significativa entre el MCU PIC de 8 bits de Microchip y el MCU y DSC de 16 bits
las arquitecturas son el multiplicador. Algunas familias de MCU PIC admiten un multiplicador de 8 bits x 8 bits, que
coloca el producto multiplicado en el par de registros PRODH:PRODL. La MCU y DSC de 16 bits
Los dispositivos tienen un multiplicador de 17 bits x 17 bits, que puede colocar el resultado en dos
registros de trabajo (comenzando con un registro par) o un acumulador.
A pesar de esta diferencia arquitectónica, los dispositivos MCU y DSC de 16 bits aún admiten el archivo heredado
registre la instrucción de multiplicación (MULWF) con la instrucción “MUL{.B} f” (descrita en la página 5-255).
El soporte de la instrucción MULWF heredada se ha logrado mediante el mapeo de la
PRODH:PRODL se registra en el par de registros de trabajo W3:W2. Esto significa que cuando “MUL{.B}
f” se ejecuta en modo Word, la multiplicación genera un producto de 32 bits que se almacena en W3:W2,
donde W3 tiene la palabra más significativa del producto y W2 tiene la palabra menos significativa del
el producto. Cuando se ejecuta “MUL{.B} f” en modo Byte, el producto de 16 bits se almacena en W2,
y W3 no se ve afectado. En el Ejemplo 4-17 se muestran ejemplos de esta instrucción.
AÑADIR
RAM100
; agregue RAM100 y WREG, almacene en RAM100
ASR
RAM100, WREG
; cambie RAM100 a la derecha, guárdelo en WREG
CLR.B
WREG
; borre el byte WREG LS
DIC
RAM100, WREG
; disminuir RAM100, almacenar en WREG
MOVIMIENTO
WREG, RAM100
; mover WREG a RAM100
SETM
WREG
; establecer todos los bits en el WREG
XOR
RAM100
; XOR RAM100 y WREG, almacenar en RAM100

© 2009 Microchip Technology Inc.
DS70157D-página 69
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
Ejemplo 4-17:
 Multiplicación f y WREG sin signo (instrucción MULWF heredada)
4.10.3.3
MOVER DATOS CON WREG
La instrucción “MOV{.B} f {,WREG}” (descrita en la página 5-145) y “MOV{.B} WREG, f”
instrucción (descrita en la página 5-146) permite mover datos de bytes o palabras entre archivos
memoria de registros y el WREG (registro de trabajo W0). Estas instrucciones proporcionan equivalentes
funcionalidad a las instrucciones MOVF y MOVWF de Microchip PIC MCU heredadas.   
Las instrucciones “MOV{.B} f {,WREG}” y “MOV{.B} WREG, f” son las únicas instrucciones MOV
que admiten movimientos de datos de bytes hacia y desde la memoria de registro de archivos. El ejemplo 4-18 muestra varios
Ejemplos de instrucciones MOV utilizando WREG.
Ejemplo 4-18:
Moviendo datos con WREG
MUL.B
0x100
; (0x100)*WREG (modo byte), almacenar en W2
Antes de la instrucción:
W0 (WREG) = 0x7705
W2 = 0x1235
W3 = 0x1000
Memoria de datos 0x0100 = 0x1255
Después de la instrucción:
W0 (WREG) = 0x7705
W2 = 0x01A9
W3 = 0x1000
Memoria de datos 0x0100 = 0x1255
MUL
0x100
; (0x100)*WREG (modo palabra), almacenar en W3:W2
Antes de la instrucción:
W0 (WREG) = 0x7705
W2 = 0x1235
W3 = 0x1000
Memoria de datos 0x0100 = 0x1255
Después de la instrucción:
W0 (WREG) = 0x7705
W2 = 0xDEA9
W3 = 0x0885
Memoria de datos 0x0100 = 0x1255
Nota:
Al mover datos de palabras entre la memoria del registro de archivos y el registro de trabajo
matriz, las instrucciones “MOV Wns, f” y “MOV f, Wnd” permiten cualquier registro de trabajo
(W0:W15) para ser utilizado como registro de origen o destino, no solo WREG.
MOV.B
0x1001, WREG
; mueva el byte almacenado en la ubicación 0x1001 a W0
MOVIMIENTO
0x1000, WREG
; mover la palabra almacenada en la ubicación 0x1000 a W0
MOV.B
WREG, TBLPAG
; mover el byte almacenado en W0 al registro TBLPAG
MOVIMIENTO
WREG, 0x804
; mueva la palabra almacenada en W0 a la ubicación 0x804

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 70
© 2009 Microchip Technology Inc.
4.11
 FORMATOS DE DATOS DSP (DISPOSITIVOS dsPIC30F Y dsPIC33F)
4.11.1
Datos enteros y fraccionarios
Los dispositivos dsPIC30F y dsPIC33F admiten tipos de datos enteros y fraccionarios. Entero
Los datos se representan inherentemente como un valor en complemento a dos con signo, donde el valor más significativo
El bit se define como un bit de signo. En términos generales, el rango de un número entero en complemento a dos de N bits
es -2N-1 a 2N-1 – 1. Para un entero de 16 bits, el rango de datos es -32768 (0x8000) a 32767 (0x7FFF),
incluyendo ‘0’. Para un entero de 32 bits, el rango de datos es -2,147,483,648 (0x8000 0000) a
2.147.483.647 (0x7FFFFFFF).
Los datos fraccionarios se representan como un número en complemento a dos, donde el bit más significativo es
se define como un bit de signo, y se supone que el punto de base se encuentra justo después del bit de signo. Este formato es
comúnmente conocido como formato 1.15 (o Q15), donde 1 es el número de bits utilizados para representar
la parte entera del número, y 15 es el número de bits utilizados para representar la fracción
porción. El rango de una fracción en complemento a dos de N bits con este punto de base implícito es de -1,0 a
(1 – 21-N). Para una fracción de 16 bits, el rango de datos 1,15 es de -1,0 (0x8000) a 0,999969482 (0x7FFF),
incluyendo 0.0 y tiene una precisión de 3.05176x10-5. En el modo de saturación normal, los 32 bits
Los acumuladores utilizan un formato 1,31, que mejora la precisión a 4,6566x10-10.
El modo Super Saturación amplía el rango dinámico de los acumuladores utilizando los 8 bits de
el registro del acumulador superior (ACCxU) como bits de protección. Los bits de protección se utilizan si el valor almacenado
en el acumulador se desborda más allá del bit 32 y son útiles para implementar DSP
algoritmos. Este modo se habilita cuando el bit ACCSAT (CORCON<4>) está establecido en ‘1’ y
expande los acumuladores a 40 bits. Los acumuladores soportan entonces un rango entero de
-5.498x1011 (0x80 0000 0000) a 5.498x1011 (0x7F FFFF FFFF). En modo fraccionario, el guardia
Los bits del acumulador no modifican la ubicación del punto de base y los acumuladores de 40 bits.
Utilice un formato fraccionario 9,31. Tenga en cuenta que todos los resultados de las operaciones fraccionarias se almacenan en formato de 40 bits.
Acumulador, justificado con un punto de base de 1,31. Como en el modo entero, los bits de protección simplemente aumentan
el rango dinámico del acumulador. 9,31 fracciones tienen un rango de -256,0 (0x80 0000 0000)
a (256,0 – 4,65661x10-10) (0x7F FFFF FFFF). La Tabla 4-10 identifica el rango y la precisión de
números enteros y fracciones en los dispositivos dsPIC30F/33F para registros de 16, 32 y 40 bits. 
Cabe señalar que, con la excepción de los multiplicadores DSP, la ALU funciona de manera idéntica en
datos enteros y fraccionarios. Es decir, una suma de dos números enteros producirá el mismo resultado (binario
número) como la suma de dos números fraccionarios. La única diferencia es cómo es el resultado.
interpretado por el usuario. Sin embargo, las multiplicaciones realizadas por las operaciones DSP son diferentes. En estos
instrucciones, la selección del formato de datos se realiza mediante el bit IF, CORCON<0>, y debe establecerse
en consecuencia (‘0’ para el modo fraccionario, ‘1’ para el modo entero). Esto es necesario debido a lo implícito
Punto de base utilizado por números fraccionarios dsPIC30F/33F. En modo entero, multiplicar dos de 16 bits
enteros produce un resultado entero de 32 bits. Sin embargo, multiplicar dos valores de 1,15 genera un resultado de 2,30.
resultado. Dado que los dispositivos dsPIC30F y dsPIC33F utilizan un formato 1.31 para los acumuladores, un DSP
multiplicar en modo fraccionario también incluye un desplazamiento hacia la izquierda de un bit para mantener el punto de base correctamente
alineado. Esta característica reduce la resolución del multiplicador DSP a 2-30, pero no tiene ningún otro efecto.
en el cálculo (por ejemplo, 0,5 x 0,5 = 0,25). 
Tabla 4-10:
Rangos de datos dsPIC30F/33F
Tamaño del registro
Rango de números enteros
Rango de fracciones
Resolución de fracciones
16 bits
-32768 a 32767
-1,0 a (1,0 – 2-15)
3.052x10-5
32 bits
-2.147.483.648 a
 2.147.483.647
-1,0 a (1,0 – 2-31)
4,657x10-10
40 bits
-549.755.813.888 a
 549.755.813.887
-256,0 a (256,0 – 2-31)
4,657x10-10

© 2009 Microchip Technology Inc.
DS70157D-página 71
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
4.11.2
Representación de datos enteros y fraccionarios
Tener un conocimiento práctico de cómo se representan los datos enteros y fraccionarios en el dsPIC30F.
y dsPIC33F es fundamental para trabajar con el dispositivo. Tanto los datos enteros como los fraccionarios tratan
el bit más significativo como bit de signo y el exponente binario disminuye en uno como posición del bit
avanza hacia el bit menos significativo. El exponente binario para un entero de N bits comienza en (N-1)
para el bit más significativo y termina en ‘0’ para el bit menos significativo. Para una fracción de N bits, la
El exponente binario comienza en ‘0’ para el bit más significativo y termina en (1-N) para el menos significativo.
bit (como se muestra en la Figura 4-12 para un valor positivo y en la Figura 4-13 para un valor negativo).
La conversión entre representaciones enteras y fraccionarias se puede realizar usando simples
división y multiplicación. Para pasar de un entero de N bits a una fracción, divida el valor entero por
2N-1. Del mismo modo, para convertir una fracción de N bits en un número entero, multiplique el valor fraccionario por 2N-1.
Figura 4-12:
Diferentes representaciones de 0x4001
Figura 4-13:
Diferentes representaciones de 0xC002
Entero:
1.15 Fraccionario:
0x4001 = 214 + 20 = 16384 + 1 = 16385
0x4001 = 2-1 + 2-15 = 0,5 + .000030518 = 0,500030518
Punto de base implícito
0
1
0
0
0
0
0
0
0
0
0
0
0
0
0
1
1
0
0
0
0
0
0
0
0
0
0
0
0
0
0
1
 -215 214 213 212. . . . . . 
 20 
 2-15 
-20. 2-1 2-2 2-3. . . . . . 
Entero:
1.15 Fraccionario:
0xC002 = -215 + 214 + 21 = -32768 + 16384 + 2 = -16382
0xC002 = -20 + 2-1 + 2-14 = -1,0 + 0,5 + 0,000061035 = -0,499938965
Punto de base implícito
1
1
0
0
0
0
0
0
1
0
0
0
0
0
0
0
1
1
0
0
0
0
0
0
1
0
0
0
0
0
0
0
 -215 214 213 212. . . . . . 
 20 
 2-15 
-20. 2-1 2-2 2-3. . . . . . 
          
1
1
0
0
0
0
0
0
1
0
0
0
0
0
0
0

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 72
© 2009 Microchip Technology Inc.
4.12
 USO DEL ACUMULADOR (DISPOSITIVOS dsPIC30F Y dsPIC33F)
Los acumuladores A y B son utilizados por instrucciones DSP para realizar operaciones matemáticas y de cambio.
operaciones. Dado que los acumuladores tienen 40 bits de ancho y las rutas de datos X e Y son sólo de 16 bits,
Se debe entender el método para cargar y almacenar los acumuladores. 
El elemento A en la Figura 4-14 muestra que cada acumulador de 40 bits (ACCA y ACCB) consta de un acumulador de 8 bits.
Registro superior (ACCxU), un registro alto de 16 bits (ACCxH) y un registro bajo de 16 bits (ACCxL). a
abordar el requisito de alineación del autobús y proporcionar la capacidad de matemáticas 1.31, ACCxH se utiliza como
un registro de destino para cargar el acumulador (con la instrucción LAC), y también como origen
registro para almacenar el acumulador (con la instrucción SAC.R). Esto está representado por el artículo B,
Figura 4-14, donde las partes superior e inferior del acumulador están sombreadas. En realidad, durante
cargas del acumulador, ACCxL tiene relleno cero y ACCxU tiene signo extendido para representar el signo
del valor cargado en ACCxH.
Cuando la saturación normal (31 bits) está habilitada, las operaciones DSP (como ADD, MAC, MSC, etc.)
Utilice únicamente ACCxH:ACCxL (elemento C en la Figura 4-14) y ACCxU solo se utiliza para mantener el signo.
del valor almacenado en ACCxH:ACCxL. Por ejemplo, cuando se ejecuta una instrucción MPY, el
El resultado se almacena en ACCxH:ACCxL y el signo del resultado se extiende a través de ACCxU. 
Cuando la Súper Saturación está habilitada, se pueden usar todos los registros del acumulador (Ítem D en
Figura 4-14) y los resultados de las operaciones DSP se almacenan en ACCxU:ACCxH:ACCxL. el beneficio
de ACCxU es que aumenta el rango dinámico del acumulador, como se describe en
4.11.1 “Datos Enteros y Fraccionados”. Consulte la Tabla 4-10 para ver el rango de valores que pueden
se almacenará en el acumulador cuando esté en los modos Normal y Súper Saturación.
Figura 4-14:
Alineación y uso del acumulador
A)
D)
c)
B)
ACCxU
ACCxH
ACCxL
A) El acumulador de 40 bits consta de ACCxU:ACCxH:ACCxL
B) Operaciones de carga y almacenamiento
C) Operaciones en modo de Saturación Normal
D) Operaciones en modo Super Saturación
31.30
Punto Radix implícito (entre los bits 31 y 30)
0
15
16
32
39

© 2009 Microchip Technology Inc.
DS70157D-página 73
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
4.13
 ACCESO AL ACUMULADOR (DISPOSITIVOS dsPIC30F Y dsPIC33F)
Los seis registros del Acumulador A y del Acumulador B están mapeados en memoria como cualquier otro
Registro de funciones especiales. Esta característica permite acceder a ellos con registro de archivos o indirectos.
direccionamiento, utilizando cualquier instrucción que admita dicho direccionamiento. Sin embargo, se recomienda
que se utilicen las instrucciones DSP LAC, SAC y SAC.R para cargar y almacenar los acumuladores,
ya que proporcionan capacidades de extensión, desplazamiento y redondeo de señales. LAC, SAC y SAC.R
Los detalles de las instrucciones se proporcionan en la Sección 5. “Descripciones de las instrucciones”.    
Nota:
Para mayor comodidad, ACCAU y ACCBU tienen signos extendidos a 16 bits. Esto proporciona
la flexibilidad para acceder a estos registros usando el modo Byte o Word (cuando el archivo
se utiliza registro o direccionamiento indirecto).

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 74
© 2009 Microchip Technology Inc.
4.14
 INSTRUCCIONES DSP MAC (DISPOSITIVOS dsPIC30F Y dsPIC33F)
Las operaciones DSP Multiply and Accumulate (MAC) son un conjunto especial de instrucciones que
Proporciona el uso más eficiente de las arquitecturas dsPIC30F y dsPIC33F. El MAC DSP
Las instrucciones, que se muestran en la Tabla 4-11, utilizan las rutas de datos X e Y del núcleo de la CPU, que
permite que estas instrucciones realicen las siguientes operaciones en un solo ciclo:
• dos lecturas de la memoria de datos utilizando registros de trabajo de captación previa (MAC Prefetches)
• dos actualizaciones para la captación previa de registros de trabajo (Actualizaciones de registros de captación previa de MAC)
• una operación matemática con un acumulador (Operaciones MAC)
Además, cuatro de las diez instrucciones DSP MAC también son capaces de realizar una operación con
un acumulador, mientras almacena el contenido redondeado del acumulador alternativo. esto
La característica se llama escritura acumulada (WB) y proporciona flexibilidad para el software.
desarrollador. Por ejemplo, el acumulador WB se puede utilizar para ejecutar dos algoritmos simultáneamente, o
procesar eficientemente números complejos, entre otras cosas.
Tabla 4-11:
Instrucciones MAC DSP  
4.14.1
Precargas MAC
Las captaciones previas (o lecturas de datos) se realizan utilizando la dirección efectiva almacenada en el registro de trabajo.
Las dos captaciones previas de la memoria de datos deben especificarse utilizando las asignaciones de registros de trabajo.
se muestra en la Tabla 4-9. Debe realizarse una lectura desde el bus de datos X usando W8 o W9, y una lectura
debe ocurrir desde el bus de datos Y usando W10 o W11. El destino permitido se registra para ambos.
las captaciones previas son W4-W7.
Como se muestra en la Tabla 4-3, existe un modo de direccionamiento especial para la clase de instrucciones MAC. esto
El modo es el modo de direccionamiento de compensación de registro y utiliza W12. En este modo, la captación previa es
realizado utilizando la dirección efectiva del registro de trabajo especificado, más el valor con signo de 16 bits
almacenado en W12. El direccionamiento de compensación de registro sólo se puede utilizar en el espacio X con W9, y en el
Espacio Y con W11.
4.14.2
Actualizaciones del registro de captación previa de MAC
Después de realizar las captaciones previas de MAC, la dirección efectiva almacenada en cada registro de trabajo de captación previa
puede ser modificado. Esta característica permite un procesamiento eficiente de un solo ciclo para los datos almacenados
secuencialmente en la memoria X e Y. Dado que todas las instrucciones DSP se ejecutan en modo Word, sólo incluso
Se podrán realizar actualizaciones numeradas del domicilio efectivo consignado en el registro de trabajo.
Las modificaciones de dirección permitidas para cada registro de captación previa son -6, -4, -2, 0 (sin actualización), +2, +4 y
+6. Esto significa que las actualizaciones efectivas de direcciones se pueden realizar con hasta 3 palabras en cualquier dirección.
Cuando se utiliza el modo de direccionamiento de compensación de registro, no se realiza ninguna actualización en la captación previa base
registro (W9 o W11), o el registro de compensación (W12).
Instrucción
Descripción
¿Acumulador WB?
CLR
Limpiar acumulador
si
DE
Distancia euclidiana (sin acumulación)
No
EDAC
distancia euclidiana
No
MAC
Multiplica y acumula
si
MAC
Cuadrar y acumular
No
MOVSAC
Mover del autobús X e Y
si
MPY
Multiplicar al acumulador
No
MPY
Cuadrado al acumulador
No
MPY.N
Multiplicación negativa al acumulador.
No
MSC
multiplicar y restar
si

© 2009 Microchip Technology Inc.
DS70157D-página 75
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
4.14.3
Operaciones MAC
Las operaciones matemáticas realizadas por la clase MAC de instrucciones DSP se centran en
multiplicar el contenido de dos registros de trabajo y sumar o almacenar el resultado en cualquiera de los dos
Acumulador A o Acumulador B. Este es el funcionamiento del MAC, MPY, MPY.N y MSC
instrucciones. La Tabla 4-9 muestra que se debe utilizar W4-W7 para operandos de origen de datos en MAC
clase de instrucciones. W4-W7 se pueden combinar de cualquier forma y cuando los mismos
El registro se especifica para ambos operandos, un cuadrado o cuadrado y la operación de acumulación es
realizado.
Para las instrucciones ED y EDAC, el mismo operando multiplicando debe ser especificado por el
instrucción, porque esta es la definición de la operación Distancia Euclidiana. Otro único
La característica de esta instrucción es que los valores precargados de la memoria X e Y no son realmente
almacenado en W4-W7. En cambio, solo se almacena en W4-W7 la diferencia de las palabras de datos captadas previamente. 
Las dos instrucciones de clase MAC restantes, CLR y MOVSAC, son útiles para iniciar o completar
una serie de instrucciones MAC o EDAC y no utilice el multiplicador. CLR tiene la capacidad de borrar
Acumulador A o B, capta previamente dos valores de la memoria de datos y almacena el contenido del otro
acumulador. De manera similar, MOVSAC tiene la capacidad de buscar previamente dos valores de la memoria de datos y almacenarlos.
el contenido de cualquiera de los acumuladores.
4.14.4
Reescritura MAC
La capacidad de reescritura de la clase MAC de instrucciones DSP facilita el procesamiento eficiente de
algoritmos. Esta característica permite realizar una operación matemática con un solo
acumulador y el contenido redondeado del otro acumulador que se almacenará en el mismo ciclo.
Como se indica en la Tabla 4-9, el registro W13 está asignado para realizar la reescritura y dos
Se admiten modos de direccionamiento: Directo e Indirecto con Post-Incremento. 
Las instrucciones CLR, MOVSAC y MSC admiten la escritura acumulada, mientras que las instrucciones ED, EDAC,
Las instrucciones MPY y MPY.N no admiten la escritura regresiva del acumulador. La instrucción MAC, que
multiplica dos registros de trabajo que no son iguales, también admite escritura acumulada.
Sin embargo, las instrucciones MAC cuadradas y acumuladas no admiten la escritura repetida del acumulador.
(ver Tabla 4-11).
4.14.5
Sintaxis MAC
La sintaxis de la clase MAC de instrucciones puede tener varios formatos, que dependen del
tipo de instrucción y la operación que está realizando, con respecto a las captaciones previas y el acumulador
Escribe de nuevo. Con excepción de las instrucciones CLR y MOVSAC, todas las instrucciones de clase MAC
debe especificar un acumulador objetivo junto con dos multiplicandos, como se muestra en el ejemplo 4-19. 
Ejemplo 4-19:
Sintaxis MAC básica
Multiplique W7*W7, acumule a ACCB
; MAC sin captación previa
MAC W4*W5, A
; MAC sin captación previa
MAC W7*W7, B

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 76
© 2009 Microchip Technology Inc.
Si se utiliza una captación previa en la instrucción, el ensamblador es capaz de discriminar los datos X o Y.
captación previa basada en el registro utilizado para la dirección efectiva. [W8] o [W9] especifica la X
captación previa y [W10] o [W11] especifica la captación previa Y. Los soportes alrededor del registro de trabajo son
requerido en la sintaxis, y designan que el direccionamiento indirecto se utiliza para realizar la
captación previa. Cuando se utiliza la modificación de dirección, se debe especificar usando un signo menos igual o
más-es igual a una sintaxis similar a “C” (es decir, “[W8] – = 2” o “[W8] + = 6”). Cuando se registra el direccionamiento compensado
se utiliza para la captación previa, W12 se coloca dentro de los corchetes ([W9 + W12] para captaciones previas de X y [W11
+ W12] para capturas previas de Y). Cada operación de captación previa también debe especificar un destino de captación previa.
registro (W4-W7). En la sintaxis de la instrucción, el registro de destino aparece antes de la captación previa. 
registrarse. Las formas legales de captación previa se muestran en el ejemplo 4-20.
Ejemplo 4-20:
 Sintaxis de captación previa de MAC
Si se utiliza una escritura acumulada en la instrucción, se especifica al final. La respuesta de escritura debe
utilice el registro W13, y los formularios permitidos para la escritura posterior son “W13” para direccionamiento directo y
“[W13] + = 2” para direccionamiento indirecto con post-incremento. Por definición, el acumulador no se utiliza.
en la operación matemática se almacena, por lo que el acumulador de escritura no se especifica en el
instrucción. Las formas legales de escritura recíproca del acumulador (WB) se muestran en el ejemplo 4-21.
X([W8]+=2)→ W5
ACCA=ACCA+W5*W6
; MAC con captación previa solo X 
MAC W5*W6, A, [W8]+=2, W5
Y([W11+W12])→ W5
ACCB=ACCB+W5*W5
; MAC con Y solo captación previa
MAC W5*W5, B, [W11+W12], W5
X([W9])→ W6
ACCB=ACCB+W6*W7
Y([W10]+=4)→ W7
; MAC con captación previa X/Y
MAC W6*W7, B,
[W9], W6,
[W10]+=4, W7

© 2009 Microchip Technology Inc.
DS70157D-página 77
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
Ejemplo 4-21:
 Sintaxis WB del acumulador MAC
En conjunto, una instrucción MSC que realiza dos captaciones previas y una reescritura es
se muestra en el ejemplo 4-22.
Ejemplo 4-22:
Instrucción MSC con dos captaciones previas y escritura acumulada
ACCB → W13
0 → ACCA
; CLR con WB directo de ACCB
CLR A,
W13
ACCB → [W13]+=2
ACCA=ACCA+W4*W5
; MAC con WB indirecto de ACCB
MAC W4*W5, A [W13]+=2
Y([W10]+=2)→ W4
ACCB=ACCB+W4*W5
ACCA → W13
; MAC con captación previa Y, WB directo de ACCA
MAC W4*W5, B,
[W10]+=2, W4,
W13 
ACCB=ACCB-W6*W7
X([W8]+=2)→W6
Y([W10]-=6)→W7    
ACCA→[W13]+=2
; MSC con captación previa X/Y, WB indirecto de ACCA
MSC W6*W7, B, [W8]+=2, W6, [W10]-=6, W7 [W13]+=2

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 78
© 2009 Microchip Technology Inc.
4.15
 INSTRUCCIONES DEL ACUMULADOR DSP (dsPIC30F Y dsPIC33F 
DISPOSITIVOS)
Las instrucciones del acumulador DSP no tienen capacidad de captación previa o WB del acumulador, pero sí
Proporciona la capacidad de agregar, negar, desplazar, cargar y almacenar el contenido de cualquier acumulador de 40 bits.
Además, las instrucciones ADD y SUB permiten sumar o restar los dos acumuladores
unos de otros. Las instrucciones del acumulador DSP se muestran en la Tabla 4-12 y los detalles de las instrucciones.
se proporcionan en la Sección 5. “Descripciones de instrucciones”. 
Tabla 4-12:
 Instrucciones del acumulador DSP  
Instrucción
Descripción
¿Acumulador WB?
AÑADIR
Añadir acumuladores
No
AÑADIR
Agregar acumulador firmado de 16 bits
No
ALC
acumulador de carga
No
NEG
Negar acumulador
No
SACO
Acumulador de tienda
No
SAC.R
Almacenar acumulador redondeado
No
SFTAC 
Acumulador de desplazamiento aritmético por Literal
No
SFTAC
Acumulador de desplazamiento aritmético por (Wn)
No
SUB
Restar acumuladores
No

© 2009 Microchip Technology Inc.
DS70157D-página 79
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
4.16
 ESCALADO DE DATOS CON LA INSTRUCCIÓN FBCL (dsPIC30F Y dsPIC33F 
DISPOSITIVOS)
Para minimizar los errores de cuantificación asociados con el procesamiento de datos mediante instrucciones DSP,
es importante utilizar el resultado numérico completo de las operaciones. Esto puede requerir escalamiento
aumentar datos para evitar un desbordamiento insuficiente (es decir, al procesar datos desde un ADC de 12 bits) o reducir los datos
para evitar el desbordamiento (es decir, al enviar datos a un DAC de 10 bits). La escala, que debe ser
realizado para minimizar el error de cuantificación, depende del rango dinámico de los datos de entrada que
se opera y el rango dinámico requerido de los datos de salida. En ocasiones, estas condiciones
Se puede conocer de antemano y se puede emplear una escala fija. En otros casos, las condiciones de escala
Es posible que no sea fijo o conocido, y luego se debe utilizar el escalado dinámico para procesar los datos.
La instrucción FBCL (Buscar el primer cambio de bit a la izquierda) se puede utilizar eficientemente para realizar operaciones dinámicas.
escala, porque determina el exponente de un valor. Exponente de un punto fijo o valor entero
representa la cantidad que el valor puede desplazarse antes de desbordarse. Esta información es
valioso, porque puede usarse para llevar el valor de los datos a “escala completa”, lo que significa que su valor numérico
La representación utiliza todos los bits del registro en el que está almacenada.
La instrucción FBCL determina el exponente de una palabra detectando el primer cambio de bit que comienza
desde el bit de signo del valor y trabajando hacia el LSB. Desde el cañón del dispositivo dsPIC DSC
Shifter utiliza valores negativos para especificar un desplazamiento a la izquierda, la instrucción FBCL devuelve el valor negado.
exponente de un valor. Si el valor se está ampliando, esto permite que se realice el cambio siguiente.
inmediatamente con el valor devuelto por FBCL. Además, dado que la instrucción FBCL solo
opera en cantidades con signo, FBCL produce resultados en el rango de -15:0. Cuando la FBCL
La instrucción devuelve ‘0’, indica que el valor ya está en la escala completa. cuando la instrucción
devuelve -15, indica que el valor no se puede escalar (como es el caso de 0x0 y 0xFFFF).
La Tabla 4-13 muestra datos de palabras con varios rangos dinámicos, sus exponentes y el valor después
escalar cada dato para maximizar el rango dinámico. El ejemplo 4-23 muestra cómo el FBCL
La instrucción se puede utilizar para el procesamiento de bloques.
Tabla 4-13:
Ejemplos de escala 
Como ejemplo práctico, supongamos que el procesamiento de bloques se realiza en una secuencia de datos con
Rango dinámico muy bajo almacenado en formato fraccionario 1,15. Para minimizar los errores de cuantificación, los datos
puede ampliarse para evitar cualquier pérdida de cuantificación que pueda ocurrir mientras se procesa. La FBCL
La instrucción se puede ejecutar en la muestra con la magnitud más grande para determinar el valor óptimo.
valor de escala para procesar los datos. Tenga en cuenta que la ampliación de los datos se realiza desplazando hacia la izquierda
los datos. Esto se demuestra con el siguiente fragmento de código.
Valor de la palabra
exponente
Valor de escala completa
(Valor de palabra << Exponente)
0x0001
14
0x4000
0x0002
13
0x4000
0x0004
12
0x4000
0x0100
6
0x4000
0x01FF
6
0x7FC0
0x0806
3
0x4030
0x2007
1
0x400E
0x4800
0
0x4800
0x7000
0
0x7000
0x8000
0
0x8000
0x900A
0
0x900A
0xE001
2
0x8004
0xFF07
7
0x8380
Nota:
Para los valores de palabra 0x0000 y 0xFFFF, la instrucción FBCL devuelve -15.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 80
© 2009 Microchip Technology Inc.
Ejemplo 4-23:
 Escalando con FBCL
; supongamos que W0 contiene el valor absoluto más grande del bloque de datos
; supongamos que W4 apunta al comienzo del bloque de datos
; supongamos que el bloque de datos contiene BLOCK_SIZE palabras
; determinar el exponente a usar para escalar
FBCL
W0, W2
; almacenar exponente en W2
; escalar todo el bloque de datos antes de procesarlo
HACER
#(BLOCK_SIZE-1), ESCALA
ALC
[W4], un
; mover la siguiente muestra de datos a ACCA
SFTAC
A, W2
; cambiar ACCA en W2 bits
ESCALA: 
SACO
R, [W4++]
; almacenar entrada escalada (sobrescribir original)
; ahora procesa los datos
; (el bloque de procesamiento va aquí)

© 2009 Microchip Technology Inc.
DS70157D-página 81
Sección 4. Detalles del conjunto de instrucciones
Conjunto de instrucciones 
Detalles
4
4.17
 NORMALIZACIÓN DEL ACUMULADOR CON LA INSTRUCCIÓN FBCL 
(DISPOSITIVOS dsPIC30F Y dsPIC33F)
El proceso de escalar un valor cuantificado para su rango dinámico máximo se conoce como
normalización (los datos de la tercera columna de la Tabla 4-13 contienen datos normalizados). acumulador
La normalización es una técnica utilizada para garantizar que el acumulador esté correctamente alineado antes
almacena datos del acumulador, y la instrucción FBCL facilita esta función. 
Los dos acumuladores de 40 bits tienen cada uno 8 bits de guarda del registro ACCxU, lo que amplía la
rango dinámico de los acumuladores de 1,31 a 9,31, cuando se opera en modo Super Saturación
(ver 4.11.1 “Datos enteros y fraccionarios”). Sin embargo, incluso en el modo Súper Saturación, la Tienda
La instrucción Rounded Accumulator (SAC.R) solo almacena datos de 16 bits (en formato 1.15) de ACCxH,
como se describe en 4.12 “Uso del acumulador (dispositivos dsPIC30F y dsPIC33F)”. bajo ciertos
condiciones, esto puede suponer un problema. 
La alineación adecuada de los datos para almacenar el contenido del acumulador se puede lograr escalando
el acumulador hacia abajo si ACCxU está en uso, o aumentando el acumulador si todos los bits ACCxH
no se están utilizando. Para realizar dicho escalado, la instrucción FBCL debe operar en el ACCxU
byte y debe operar en la palabra ACCxH. Si se requiere un cambio, la palanca de cambios de 40 bits de la ALU es
empleado, utilizando la instrucción SFTAC para realizar el escalado. El ejemplo 4-24 contiene un código
fragmento para la normalización del acumulador.
Ejemplo 4-24:
 Normalizando con FBCL
; asumir que una operación en ACCA acaba de completarse (SR intacto)
; Supongamos que el procesador está en modo de supersaturación.
; supongamos que ACCAH está definido como la dirección de ACCAH (0x24)
MOVIMIENTO
#ACCAH, W5
; W5 apunta a ACCAH
sujetador
OA, FBCL_GUARD
; si se desborda, cambiamos a la derecha
FBCL_HI:
FBCL
[W5], W0
; extraer exponente para desplazamiento a la izquierda
sujetador
MAYÚS_ACC
; rama al turno
FBCL_GUARD:
FBCL
[++W5], W0
; extraer exponente para desplazamiento a la derecha
AGREGAR.B
W0, #15, W0
; ajustar la señal para el desplazamiento a la derecha
MAYÚS_ACC:
SFTAC
A, W0
; cambiar ACCA para normalizar

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 82
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70157D-página 83
Instrucción 
Descripciones
5
Sección 5. Descripciones de instrucciones
DESTACADOS
Esta sección del manual contiene los siguientes temas principales:
5.1
Símbolos de instrucción................................................................................................................ 84
5.2
Introducción a los descriptores de campos de codificación de instrucciones.................................... 84
5.3
Ejemplo de descripción de instrucción ................................................................................ 88
5.4
Descripciones de instrucciones................................................................................................ 89

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 84
© 2009 Microchip Technology Inc.
5.1
 Símbolos de instrucción
Todos los símbolos utilizados en la Sección 5.4 “Descripciones de instrucciones” se enumeran en la Tabla 1-2.
5.2
 Introducción a los descriptores de campos de codificación de instrucciones
Todos los descriptores de campos de codificación de instrucciones utilizados en la Sección 5.4 “Descripciones de instrucciones” son
se muestra en la Tabla 5-2 a la Tabla 5-12.
Tabla 5-1:
Descriptores de campos de codificación de instrucciones  
campo
Descripción
Un(1)
Bit de selección del acumulador: 0 = ACCA; 1 = CCB
aa(1)
Modo de escritura posterior del acumulador (consulte la Tabla 5-12)
b
Bit de selección del modo byte: 0 = operación de palabra; 1 = operación de bytes
bbbb
Selección de posición de bit de 4 bits: 0000 = LSB; 1111 = MSB
re
Bit de dirección de destino: 0 = resultado almacenado en WREG;
1 = resultado almacenado en el registro de archivos
dddd
Selección de registro de destino Wd: 0000 = W0; 1111 = W15
fffffffffffff
Dirección de archivo de registro de 13 bits (0x0000 a 0x1FFF)
ffff ffff ffff ffff
Dirección de palabra de archivo de registro de 15 bits (implícito 0 LSB)
(0x0000 a 0xFFFE)
ffff ffff ffff ffff
Dirección de bytes del archivo de registro de 16 bits (0x0000 a 0xFFFF)
ggg
Modo de direccionamiento de compensación de registro para el registro de origen Ws
(ver Tabla 5-4)
hhh
Modo de direccionamiento de compensación de registros para el registro de destino Wd
(ver Tabla 5-5)
iii(1)
Operación de captación previa X (consulte la Tabla 5-6)
jjjj(1)
Operación de captación previa en Y (consulte la Tabla 5-8)
k
Campo literal de 1 bit, datos o expresión constantes
kkkk
Campo literal de 4 bits, datos o expresión constantes
kk kkkk
Campo literal de 6 bits, datos o expresión constantes
kkkk kkkk
Campo literal de 8 bits, datos o expresión constantes
kk kkkk kkkk
Campo literal de 10 bits, datos o expresión constantes
kk kkkk kkkk kkkk
Campo literal de 14 bits, datos o expresión constantes
kkkk kkkk kkkk kkkk
Campo literal de 16 bits, datos o expresión constantes
milímetros
Selección de fuente multiplicadora con los mismos registros de trabajo
(ver Tabla 5-10)
mmm
Selección de fuente multiplicadora con diferentes registros de trabajo
(ver Tabla 5-11)
nnnn nnnn nnnn nnn0
           nnn nnnn
Dirección de programa de 23 bits para instrucciones CALL e GOTO
nnnn nnnn nnnn nnnn
Campo de compensación de programa de 16 bits para instrucciones relativas de rama/llamada
ppp
Modo de direccionamiento para el registro fuente Ws (consulte la Tabla 5-2)
qqq
Modo de direccionamiento para el registro de destino Wd (consulte la Tabla 5-3)
rrrr
Recuento de cambios de barril
sss
Selección de registro de origen Ws: 0000 = W0; 1111 = W15
tttt
Selección de dividendos, palabra más significativa
vvvv
Selección de dividendos, palabra menos significativa
W.
Bit de selección del modo de palabra doble: 0 = operación de palabra;
1 = operación de doble palabra
www
Selección de registro base Wb: 0000 = W0; 1111 = W15
x(1)
Destino X de captación previa (consulte la Tabla 5-7)
xxxx xxxx xxxx xxxxx
Campo no utilizado de 16 bits (no importa)
aa(1)
Destino Y de captación previa (consulte la Tabla 5-9)
z
Destino de la prueba de bits: 0 = bit de bandera C; 1 = bit de bandera Z 
Nota 1:
Este campo solo está disponible en dispositivos dsPIC30F y dsPIC33F.

© 2009 Microchip Technology Inc.
DS70157D-página 85
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
Tabla 5-2:
Modos de direccionamiento para el registro de origen Ws      
Tabla 5-3:
Modos de direccionamiento para el registro de destino Wd        
Tabla 5-4:
Modos de direccionamiento de compensación para el registro de origen Ws (con compensación de registro)
Tabla 5-5:
Modos de direccionamiento compensado para el registro de destino Wd
(con compensación de registro)
ppp
Modo de direccionamiento
Operando fuente
000
Regístrate Directo
Ws
001
indirecto
[Ws]
010
Indirecto con post-decremento
[Ws--]
011
Indirecto con post-incremento
[Ws++]
100
Indirecto con Pre-Decremento
[--Ws]
101
Indirecto con Pre-Incremento
[++Preguntas]
11x
Sin usar
qqq
Modo de direccionamiento
Operando de destino
000
Regístrate Directo
Wd
001
indirecto
[Wd]
010
Indirecto con post-decremento
[Wd--]
011
Indirecto con post-incremento
[Wd++]
100
Indirecto con Pre-Decremento
[--Wd]
101
Indirecto con Pre-Incremento
[++Wd]
11x
No utilizado (un intento de utilizar este modo de direccionamiento forzará una instrucción RESET)
ggg
Modo de direccionamiento
Operando fuente
000
Regístrate Directo
Ws
001
indirecto
[Ws]
010
Indirecto con post-decremento
[Ws--]
011
Indirecto con post-incremento
[Ws++]
100
Indirecto con Pre-Decremento
[--Ws]
101
Indirecto con Pre-Incremento
[++Preguntas]
11x
Indirecto con compensación de registro
[Ws+Wb]
hhh
Modo de direccionamiento
Operando fuente
000
Regístrate Directo
Wd
001
indirecto
[Wd]
010
Indirecto con post-decremento
[Wd--]
011
Indirecto con post-incremento
[Wd++]
100
Indirecto con Pre-Decremento
[--Wd]
101
Indirecto con Pre-Incremento
[++Wd]
11x
Indirecto con compensación de registro
[Wd+Wb]

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 86
© 2009 Microchip Technology Inc.
Tabla 5-6:
Operación de captación previa del espacio de datos X (dsPIC30F y dsPIC33F)    
Tabla 5-7:
 Destino de captación previa del espacio de datos X (dsPIC30F y dsPIC33F)    
Tabla 5-8:
Operación de captación previa del espacio de datos Y (dsPIC30F y dsPIC33F)     
iiii
Operación
0000
Anxd = [W8]
0001
Wxd = [W8], W8 = W8 + 2
0010
Wxd = [W8], W8 = W8 + 4
0011
Wxd = [W8], W8 = W8 + 6
0100
Sin captación previa para el espacio de datos X
0101
Wxd = [W8], W8 = W8 – 6
0110
Wxd = [W8], W8 = W8 – 4
0111
Wxd = [W8], W8 = W8 – 2
1000
Wxd = [W9]
1001
Wxd = [W9], W9 = W9 + 2
1010
Wxd = [W9], W9 = W9 + 4
1011
Wxd = [W9], W9 = W9 + 6
1100
Wxd = [W9 + W12]
1101
Wxd = [W9], W9 = W9 – 6
1110
Wxd = [W9], W9 = W9 – 4
1111
Wxd = [W9], W9 = W9 – 2
xx
Wxd
00
W4
01
W5
10
W6
11
W7
jjjj
Operación
0000
Wyd = [W10]
0001
Wyd = [W10], W10 = W10 + 2
0010
Wyd = [W10], W10 = W10 + 4
0011
Wyd = [W10], W10 = W10 + 6
0100
Sin captación previa para el espacio de datos Y
0101
Wyd = [W10], W10 = W10 – 6
0110
Wyd = [W10], W10 = W10 – 4
0111
Wyd = [W10], W10 = W10 – 2
1000
Wyd = [W11]
1001
Wyd = [W11], W11 = W11 + 2
1010
Wyd = [W11], W11 = W11 + 4
1011
Wyd = [W11], W11 = W11 + 6
1100
Wyd = [W11 + W12]
1101
Wyd = [W11], W11 = W11 – 6
1110
Wyd = [W11], W11 = W11 – 4
1111
Wyd = [W11], W11 = W11 – 2

© 2009 Microchip Technology Inc.
DS70157D-página 87
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
Tabla 5-9:
Destino de captación previa del espacio de datos Y (dsPIC30F y dsPIC33F)    
Tabla 5-10:
Operandos de origen MAC o MPY (mismo registro de trabajo) (dsPIC30F y 
dsPIC33F) 
Tabla 5-11:
Operandos de origen MAC o MPY (registro de trabajo diferente) (dsPIC30F y 
dsPIC33F)    
Tabla 5-12:
Selección de reescritura del acumulador MAC (dsPIC30F y dsPIC33F)    
yy
Wyd
00
W4
01
W5
10
W6
11
W7
milímetros
Multiplicandos
00
W4 * W4
01
W5 * W5
10
W6 * W6
11
W7 * W7
mmm
Multiplicandos
000
W4 * W5
001
W4 * W6
010
W4 * W7
011
Inválido
100
W5 * W6
101
W5 * W7
110
W6 * W7
111
Inválido
aa
Escribir selección
00
W13 = Otro acumulador (direccionamiento directo)
01
[W13] + = 2 = Otro acumulador (Direccionamiento indirecto con post-incremento)
10
Sin respuesta
11
Inválido

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 88
© 2009 Microchip Technology Inc.
5.3
 Ejemplo de descripción de instrucción
La descripción de ejemplo siguiente es para la instrucción ficticia FOO. El siguiente ejemplo
La instrucción se creó para demostrar cómo los campos de la tabla (sintaxis, operandos, operación, etc.)
se utilizan para describir las instrucciones presentadas en la Sección 5.4 “Descripciones de instrucciones”.
FOO
El campo Encabezado resume lo que hace la instrucción.
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Las celdas marcadas con una ‘X’ indican que la instrucción está implementada para ese 
familia de dispositivos.
Sintaxis:
El campo Sintaxis consta de una etiqueta opcional, el mnemotécnico de instrucción, cualquier 
extensiones opcionales que existen para la instrucción y los operandos para el 
instrucción. La mayoría de las instrucciones admiten más de una variante de operando para 
admite los distintos modos de direccionamiento dsPIC30F/dsPIC33F. En estos 
circunstancias, todos los operandos de instrucción posibles se enumeran debajo de cada 
otro (como en el caso de op2a, op2b y op2c anteriores). Los operandos opcionales son 
encerrado entre tirantes.
Operandos:
El campo Operandos describe el conjunto de valores que cada uno de los operandos 
puede tomar. Los operandos pueden ser registros acumuladores, registros de archivos, registros literales. 
constantes (con o sin firmar) o registros de trabajo.
Operación:
El campo Operación resume la operación realizada por la instrucción.
Estado afectado:
El campo Estado afectado describe qué bits del registro ESTADO son 
afectado por la instrucción. Los bits de estado se enumeran por posición de bit en 
orden descendente.
Codificación:
El campo Codificación muestra cómo se codifica la instrucción en bits. bit individual 
Los campos se explican en el campo Descripción y se completan los detalles de codificación. 
se proporcionan en la Tabla 5.2. 
Descripción:
El campo Descripción describe en detalle la operación realizada por el 
instrucción. También se proporciona una clave para los bits de codificación.
Palabras:
El campo Palabras contiene el número de palabras de programa que se utilizan para 
almacenar la instrucción en la memoria.
Ciclos:
El campo Ciclos contiene el número de ciclos de instrucción que se requieren 
para ejecutar la instrucción.
Ejemplos:
El campo Ejemplos contiene ejemplos que demuestran cómo la instrucción 
opera. Se proporcionan instantáneas de registro “Antes” y “Después”, que permiten 
que el usuario comprenda claramente qué operación realiza la instrucción.

© 2009 Microchip Technology Inc.
DS70157D-página 89
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
5.4
 Descripciones de instrucciones
AÑADIR
Añadir f a WREG
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
AÑADIR{.B}  
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
(f) + (WREG) → destino designado por D
Estado afectado:
CC, N, OV, Z, C
Codificación:
1011
0100
0BDF
ffff
ffff
ffff
Descripción:
Agregue el contenido del registro de trabajo predeterminado WREG al contenido de 
el registro del archivo y coloque el resultado en el registro de destino. el 
El operando WREG opcional determina el registro de destino. Si WREG es 
especificado, el resultado se almacena en WREG. Si no se especifica WREG, el 
El resultado se almacena en el registro de archivos.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0.
Palabras:
1
Ciclos:
1
Ejemplo 1:
AGREGAR.B
RAM100
; Agregue WREG a RAM100 (modo Byte)
antes 
Instrucción
después
Instrucción
WREG
CC80
WREG
CC80
 RAM100
FFC0
 RAM100
FF40
SR
0000
SR
0005
(OV, C = 1)
Ejemplo 2:
AÑADIR
RAM200, WREG
; Agregue RAM200 a WREG (modo Word)
antes 
Instrucción
después
Instrucción
WREG
CC80
WREG
CC40
 RAM200
FFC0
 RAM200
FFC0
SR
0000
SR
0001
(C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 90
© 2009 Microchip Technology Inc.
    
AÑADIR
Agregar literal a Wn
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
AÑADIR{.B}  
#lit10,
Wn
Operandos:
lit10 ∈ [0 ... 255] para operación de bytes
lit10 ∈ [0 ... 1023] para operación de palabra
Wn ∈ [W0 ... W15]
Operación:
lit10 + (Wn) → Wn
Estado afectado:
CC, N, OV, Z, C
Codificación:
1011
0000
0Bkk
kkkk
kkkk
dddd
Descripción:
Agregue el operando literal sin signo de 10 bits al contenido del trabajo 
registre Wn y coloque el resultado nuevamente en el registro de trabajo Wn. 
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits 'k' especifican el operando literal.
Los bits 'd' seleccionan la dirección del registro de trabajo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: para operaciones de bytes, el literal debe especificarse como sin firmar
valor [0:255]. Consulte la Sección 4.6 “Uso de operandos literales de 10 bits”
para obtener información sobre el uso de operandos literales de 10 bits en modo Byte.
Palabras:
1
Ciclos:
1
Ejemplo 1:
AGREGAR.B
#0xFF, W7
; Agregue -1 a W7 (modo Byte)
antes 
Instrucción
después
Instrucción
W7
12C0
W7
12BF
SR
0000
SR
0009
(norte, C = 1)
Ejemplo 2:
AÑADIR
#0xFF, W1
; Agregue 255 a W1 (modo Word)
antes 
Instrucción
después
Instrucción
W1
12C0
W1
13BF
SR
0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 91
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
 
AÑADIR
Agregar Wb al literal corto
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
AÑADIR{.B}  
Wb,
#lit5,
Wd
[Wd]
[Wd++]
[Wd--]
[++Wd]
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
iluminado5 ∈ [0 ... 31]
Wd ∈ [W0 ... W15]
Operación:
(Wb) + lit5 → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
0100
0www
wBqq
qdddd
d11k
kkkk
Descripción:
Agregue el contenido del registro base Wb al literal corto sin signo de 5 bits 
operando y coloque el resultado en el registro de destino Wd. Registrarse 
Se debe utilizar el direccionamiento directo para Wb. Ya sea registrarse directo o indirecto 
El direccionamiento se puede utilizar para Wd.
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘k’ proporcionan el operando literal, un número entero de cinco bits.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
AGREGAR.B
W0, #0x1F, W7
; Agregue W0 y 31 (modo Byte)
; Almacenar el resultado en W7
antes 
Instrucción
después
Instrucción
W0
2290
W0
2290
W7
12C0
W7
12AF
SR
0000
SR
0008
(norte = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 92
© 2009 Microchip Technology Inc.
Ejemplo 2:
AÑADIR
W3, #0x6, [--W4]
; Agregue W3 y 6 (modo Word)
; Guarde el resultado en [--W4]
antes 
Instrucción
después
Instrucción
W3
6006
W3
6006
W4
1000
W4
0FFE
Datos 0FFE
DDEE
Datos 0FFE
600C
Datos 1000
DDEE
Datos 1000
DDEE
SR
0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 93
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
AÑADIR
Añadir Wb a Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
AÑADIR{.B}  
Wb,
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Wb) + (Ws) → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
0100
0www
wBqq
qdddd
dppp
sss
Descripción:
Agregue el contenido del registro fuente Ws y el contenido de la base 
registre Wb y coloque el resultado en el registro de destino Wd. Registrarse 
Se debe utilizar el direccionamiento directo para Wb. Ya sea registrarse directo o indirecto 
El direccionamiento se puede utilizar para Ws y Wd.
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
AGREGAR.B
W5, W6, W7
; Agregue W5 a W6, almacene el resultado en W7
; (modo bytes)
antes 
Instrucción
después
Instrucción
W5
AB00
W5
AB00
W6
0030
W6
0030
W7
FFFFF
W7
FF30
SR
0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 94
© 2009 Microchip Technology Inc.
Ejemplo 2:
AÑADIR
W5, W6, W7
; Agregue W5 a W6, almacene el resultado en W7
; (modo palabra)
antes 
Instrucción
después
Instrucción
W5
AB00
W5
AB00
W6
0030
W6
0030
W7
FFFFF
W7
AB30
SR
0000
SR
0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 95
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
 
AÑADIR
Agregar acumuladores
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:}
AÑADIR  
Acc
Operandos:
Acc ∈ [A,B]
Operación:
Si (Cuenta = A): 
  (ACCA) + (ACCB) → ACCA
Más:
  (ACCA) + (ACCB) → ACCB
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1100
1011
A000
0000
0000
0000
Descripción:
Sume el contenido del Acumulador A al contenido del Acumulador B y 
coloca el resultado en el acumulador seleccionado. Esta instrucción realiza una 
Suma de 40 bits.
El bit ‘A’ especifica el acumulador de destino.
Palabras:
1
Ciclos:
1
Ejemplo 1:
AÑADIR
un
; Agregar ACCB a ACCA
antes 
Instrucción
después 
Instrucción
ACCA
00 0022 3300
ACCA
00 1855 7858
ACCB
00 1833 4558
ACCB
00 1833 4558
SR
0000
SR
        0000
Ejemplo 2:
AÑADIR
b
; Agregar ACCA a ACCB
; Suponga que el modo Súper Saturación está habilitado
; (ACCSAT = 1, SATA = 1, SATB = 1)
antes 
Instrucción
después
Instrucción
ACCA
00 E111 2222
ACCA
00 E111 2222
ACCB
00 7654 3210
ACCB
01 5765 5432
SR
 0000
SR
 4800 (OB, VHA = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 96
© 2009 Microchip Technology Inc.
AÑADIR
Agregar al acumulador firmado de 16 bits
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:}
AÑADIR  
Ws,
{#Rendija4,}
Acc
[Ws],
[Ws++],
[Ws--],
[--Ws],
[++Ws],
[Ws+Wb],
Operandos:
Ws ∈ [W0 ... W15]
Wb ∈ [W0 ... W15]
Rendija4 ∈ [-8 ... +7]
Acc ∈ [A,B]
Operación:
ShiftSlit4(Extender(Ws)) + (Acc) → Acc
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1100
1001
awww
wrrr
gggg
sss
Descripción:
Agregue un valor de 16 bits especificado por el registro de trabajo de origen al máximo 
palabra significativa del acumulador seleccionado. El operando fuente puede 
especificar el contenido directo de un registro de trabajo o de un domicilio efectivo. el 
El valor especificado se suma a la palabra más significativa del acumulador mediante 
extensión de signo y relleno cero del operando fuente antes de la operación. 
El valor añadido al acumulador también se puede desplazar mediante un signo de 4 bits. 
literal antes de realizar la adición.
El bit ‘A’ especifica el acumulador de destino.
Los bits ‘w’ especifican el registro de compensación Wb.
Los bits ‘r’ codifican el cambio opcional.
Los bits ‘g’ seleccionan el modo de dirección de origen.
Los bits ‘s’ especifican el registro fuente Ws.
Nota:
Los valores positivos del operando Slit4 representan un desplazamiento aritmético hacia la derecha.
y los valores negativos del operando Slit4 representan un desplazamiento aritmético
izquierda. El contenido del registro fuente no se ve afectado por Slit4.
Palabras:
1
Ciclos:
1
Ejemplo 1:
AÑADIR W0, #2, A
; Agregue W0 desplazado a la derecha en 2 a ACCA
antes 
Instrucción
después 
Instrucción
W0
 8000
W0
 8000
ACCA
00 7000 0000
ACCA
00 5000 0000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 97
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
Ejemplo 2:
AÑADIR [W5++], A
; Agregue el valor efectivo de W5 a ACCA
; W5 posterior al incremento
antes 
Instrucción
después 
Instrucción
W5
 2000
W5
   2002
ACCA
00 0067 2345
ACCA
00 5067 2345
Datos 2000
 5000
Datos 2000
 5000
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 98
© 2009 Microchip Technology Inc.
 
ADDC
Agregue f a WREG con Carry
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
ADDC{.B} f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
(f) + (WREG) + (C) → destino designado por D
Estado afectado:
CC, N, OV, Z, C
Codificación:
1011
0100
1HAB
ffff
ffff
ffff
Descripción:
Agregue el contenido del registro de trabajo predeterminado WREG, el contenido de 
el registro de archivo y el bit de acarreo y coloque el resultado en el destino 
registrarse. El operando WREG opcional determina el destino 
registrarse. Si se especifica WREG, el resultado se almacena en WREG. Si WREG es 
no especificado, el resultado se almacena en el registro de archivos.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0. 
3: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
ADDC.B
RAM100
; Agregue el bit WREG y C a RAM100
; (modo bytes)
antes 
Instrucción
después
Instrucción
WREG
CC60
WREG
CC60
 RAM100
8006
 RAM100
8067
SR
0001
(C=1) 
SR
0000
Ejemplo 2:
ADDC
RAM200, WREG
; Agregue RAM200 y bit C al WREG
; (modo palabra)
antes 
Instrucción
después
Instrucción
WREG
5600
WREG
8A01
 RAM200
3400
 RAM200
3400
SR
0001
(C=1)
SR
000C
(N, OV = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 99
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
ADDC
Agregar literal a Wn con Carry
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
ADDC{.B}  
#lit10,
Wn
Operandos:
lit10 ∈ [0 ... 255] para operación de bytes
lit10 ∈ [0 ... 1023] para operación de palabra
Wn ∈ [W0 ... W15]
Operación:
lit10 + (Wn) + (C) → Wn
Estado afectado:
CC, N, OV, Z, C
Codificación:
1011
0000
1 libro
kkkk
kkkk
dddd
Descripción:
Agregue el operando literal sin signo de 10 bits, el contenido del trabajo 
Registre Wn y el bit de acarreo y coloque el resultado nuevamente en el lugar de trabajo. 
registrar Wn. 
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits 'k' especifican el operando literal.
Los bits 'd' seleccionan la dirección del registro de trabajo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: Para operaciones de bytes, el literal debe especificarse como un
valor sin signo [0:255]. Consulte la Sección 4.6 “Uso de literal de 10 bits
Operandos” para obtener información sobre el uso de operandos literales de 10 bits en
Modo byte.
3: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
ADDC.B
#0xFF, W7
; Agregue -1 y bit C a W7 (modo Byte)
antes 
Instrucción
después
Instrucción
W7
12C0
W7
12BF
SR
0000
(C = 0)
SR
0009
(norte, C = 1)
Ejemplo 2:
ADDC
#0xFF, W1
; Agregue 255 y C bit a W1 (modo Word)
antes 
Instrucción
después
Instrucción
W1
12C0
W1
13C0
SR
0001
(C = 1)
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 100
© 2009 Microchip Technology Inc.
 
ADDC
Agregar Wb al literal corto con acarreo
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
ADDC{.B}  
Wb,
#lit5,
Wd
[Wd]
[Wd++]
[Wd--]
[++Wd]
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
iluminado5 ∈ [0 ... 31]
Wd ∈ [W0 ... W15]
Operación:
(Wb) + lit5 + (C) → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
0100
1www
wBqq
qdddd
d11k
kkkk
Descripción:
Agregue el contenido del registro base Wb, el literal corto sin signo de 5 bits 
operando y el bit de acarreo, y colocar el resultado en el registro de destino 
Wd. Se debe utilizar el direccionamiento directo de registro para Wb. Regístrate directo o 
Se puede utilizar direccionamiento indirecto para Wd.
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘k’ proporcionan el operando literal, un número entero de cinco bits.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
ADDC.B
W0, #0x1F, [W7]
; Agregue W0, 31 y C bit (modo Byte) 
; Guarde el resultado en [W7]
antes 
Instrucción
después
Instrucción
W0
CC80
W0
CC80
W7
12C0
W7
12C0
Datos 12C0
B000
Datos 12C0
B09F
SR
0000 (C = 0)
SR
0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 101
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
Ejemplo 2:
ADDC
W3, #0x6, [--W4]
; Agregue bits W3, 6 y C (modo Word)
; Guarde el resultado en [--W4]
antes 
Instrucción
después
Instrucción
W3
6006
W3
6006
W4
1000
W4
0FFE
Datos 0FFE
DDEE
Datos 0FFE
600D
Datos 1000
DDEE
Datos 1000
SR
DDEE
SR
0001
(C = 1)
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 102
© 2009 Microchip Technology Inc.
  
ADDC
Agregue Wb a Ws con Carry
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:}
ADDC{.B}  
Wb,
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Wb) + (Ws) + (C) → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
0100
1www
wBqq
qdddd
dppp
sss
Descripción:
Agregue el contenido del registro fuente Ws, el contenido de la base 
registre Wb y el bit de acarreo, y coloque el resultado en el destino 
registrar Wd. Se debe utilizar el direccionamiento directo de registro para Wb. Cualquiera 
Se puede utilizar el direccionamiento directo o indirecto del registro para Ws y Wd. 
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
ADDC.B
W0,[W1++],[W2++]
; Agregue W0, [W1] y C bit (modo Byte)
; Guarde el resultado en [W2]
; Post-incremento W1, W2
antes 
Instrucción
después
Instrucción
W0
CC20
W0
CC20
W1
0800
W1
0801
W2
1000
W2
1001
Datos 0800
AB25
Datos 0800
AB25
Datos 1000
FFFFF
Datos 1000
FF46
SR
0001 (C = 1)
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 103
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
Ejemplo 2:
ADDC
W3,[W2++],[W1++]
; Agregue W3, [W2] y C bit (modo Word)
; Guarde el resultado en [W1]
; Post-incremento W1, W2
antes 
Instrucción
después
Instrucción
W1
1000
W1
1002
W2
2000
W2
2002
W3
0180
W3
0180
Datos 1000
8000
Datos 1000
2681
Datos 2000
2500
Datos 2000
2500
SR
0001 (C = 1)
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 104
© 2009 Microchip Technology Inc.
  
Y
Y f y WREG
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
Y{.B}  
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
(f).AND.(WREG) → destino designado por D
Estado afectado:
norte, z
Codificación:
1011
0110
0BDF
ffff
ffff
ffff
Descripción:
Calcule la operación lógica AND del contenido del sistema de trabajo predeterminado. 
registrar WREG y el contenido del archivo de registro, y colocar el resultado en 
el registro de destino. El operando WREG opcional determina el 
registro de destino. Si se especifica WREG, el resultado se almacena en WREG.
Si no se especifica WREG, el resultado se almacena en el registro del archivo.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0. 
Palabras:
1
Ciclos:
1
Ejemplo 1:
Y.B RAM100
; Y WREG a RAM100 (modo Byte)
antes 
Instrucción
después
Instrucción
WREG
CC80
WREG
CC80
 RAM100
FFC0
 RAM100
FF80
SR
0000
SR
0008
(norte = 1)
Ejemplo 2:
Y RAM200, WREG
; Y RAM200 a WREG (modo Word)
antes 
Instrucción
después
Instrucción
WREG
CC80
WREG
0080
 RAM200
12C0
 RAM200
12C0
SR
0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 105
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
Y
 Y Literal y Wd
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
Y{.B}  
#lit10,
Wn
Operandos:
lit10 ∈ [0 ... 255] para operación de bytes
lit10 ∈ [0 ... 1023] para operación de palabra
Wn ∈ [W0 ... W15]
Operación:
lit10.Y.(Wn) → Wn 
Estado afectado:
norte, z
Codificación:
1011
0010
0Bkk
kkkk
kkkk
dddd
Descripción:
Calcule la operación lógica AND del operando literal de 10 bits y el 
contenido del registro de trabajo Wn y colocar el resultado nuevamente en el 
registro de trabajo Wn. Se debe utilizar el direccionamiento directo de registro para Wn.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits 'k' especifican el operando literal.
Los bits 'd' seleccionan la dirección del registro de trabajo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: para operaciones de bytes, el literal debe especificarse como sin firmar
valor [0:255]. Consulte la Sección 4.6 “Uso de operaciones literales de 10 bits.
ands” para obtener información sobre el uso de operandos literales de 10 bits en bytes
modo.
Palabras:
1
Ciclos:
1
Ejemplo 1:
Y.B #0x83, W7
; AND 0x83 a W7 (modo Byte)
antes 
Instrucción
después
Instrucción
W7
12C0
W7
1280
SR
0000
SR
0008
(norte = 1)
Ejemplo 2:
Y #0x333, W1
; Y 0x333 a W1 (modo Palabra)
antes 
Instrucción
después
Instrucción
W1
12D0
W1
0210
SR
0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 106
© 2009 Microchip Technology Inc.
  
Y
AND Wb y Literal Corto
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
Y{.B}  
Wb,
#lit5,
Wd
[Wd]
[Wd++]
[Wd--]
[++Wd]
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
iluminado5 ∈ [0 ... 31]
Wd ∈ [W0 ... W15]
Operación:
(Wb).AND.lit5 → Wd 
Estado afectado:
norte, z
Codificación:
0110
0www
wBqq
qdddd
d11k
kkkk
Descripción:
Calcular la operación lógica AND del contenido del registro base. 
Wb y el literal de 5 bits y coloque el resultado en el registro de destino Wd. 
Se debe utilizar el direccionamiento directo de registro para Wb. O registrarse directamente o 
Se puede utilizar direccionamiento indirecto para Wd.
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘k’ proporcionan el operando literal, un número entero de cinco bits.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
Y.B
  W0,#0x3,[W1++]
; AND W0 y 0x3 (modo Byte)
; Guardar en [W1]
; W1 posterior al incremento
antes 
Instrucción
después
Instrucción
W0
23A5
W0
23A5
W1
2211
W1
2212
 Datos 2210
9999
 Datos 2210
0199
SR
0000
SR
0000  
Ejemplo 2:
Y
W0,#0x1F,W1
; AND W0 y 0x1F (modo Palabra)
; Almacenar en W1
antes 
Instrucción
después
Instrucción
W0
6723
W0
6723
W1
7878
W1
0003
SR
0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 107
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
Y
Y Wb y Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
Y{.B}  
Wb,
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Wb).Y.(Ws) → Wd 
Estado afectado:
norte, z
Codificación:
0110
0www
wBqq
qdddd
dppp
sss
Descripción:
Calcular la operación lógica AND del contenido del registro fuente. 
Ws y el contenido del registro base Wb, y colocar el resultado en el 
registro de destino Wd. Se debe utilizar el direccionamiento directo de registro para Wb. 
Se puede utilizar el direccionamiento directo o indirecto de registro para Ws y Wd.
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
Y.B
W0, W1 [W2++]
; Y W0 y W1, y
; almacenar en [W2] (modo Byte)
; W2 posterior al incremento
antes 
Instrucción
después
Instrucción
W0
AA55
W0
AA55
W1
2211
W1
2211
W2
1001
W2
1002
 Datos 1000
FFFFF
 Datos 1000
11FF
SR
0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 108
© 2009 Microchip Technology Inc.
Ejemplo 2:
Y
W0, [W1++], W2
; Y W0 y [W1], y
; almacenar en W2 (modo Word)
; W1 posterior al incremento
antes 
Instrucción
después
Instrucción
W0
AA55
W0
AA55
W1
1000
W1
1002
W2
55AA
W2
2214
 Datos 1000
2634
 Datos 1000
2634
SR
0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 109
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
ASR
Desplazamiento aritmético a la derecha f
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
ASR{.B}  
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
Para operación de bytes:
    (f<7>) → Destino<7>
    (f<7>) → Destino<6>
    (f<6:1>) → Destino<5:0>
    (f<0>) → C
Para operación de palabras:
    (f<15>) → Destino<15>
    (f<15>) → Destino<14>
    (f<14:1>) → Destino<13:0>
    (f<0>) → C
Estado afectado:
norte, z, c
Codificación:
1101
0101
1HAB
ffff
ffff
ffff
Descripción:
Mueva el contenido del registro del archivo un bit a la derecha y coloque el resultado 
en el registro de destino. El bit menos significativo del registro de archivo es 
desplazado al bit de acarreo del registro STATUS. Después de realizar el turno
formado, el resultado es de signo extendido. El operando WREG opcional determina
extrae el registro de destino. Si se especifica WREG, el resultado se almacena en 
WREG. Si no se especifica WREG, el resultado se almacena en el registro del archivo.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ’1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0. 
Palabras:
1
Ciclos:
1
c
Ejemplo 1:
ASR.B RAM400, WREG
; ASR RAM400 y almacenar en WREG 
; (modo bytes)
antes 
Instrucción
después
Instrucción
WREG
0600
WREG
0611
RAM400
0823
RAM400
0823
SR
0000
SR
0001 (C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 110
© 2009 Microchip Technology Inc.
Ejemplo 2:
RAM200
; ASR RAM200 (modo Palabra)
antes 
Instrucción
después
Instrucción
RAM200
8009
RAM200
C004
SR
0000
SR
0009
(norte, C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 111
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
ASR
Desplazamiento aritmético a la derecha Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
ASR{.B}  
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
Para operación de bytes:
    (Ws<7>) → Wd<7>
    (Ws<7>) → Wd<6>
    (Ws<6:1>) → Wd<5:0>
    (Ws<0>) → C
Para operación de palabras:
    (Ws<15>) → Wd<15>
    (Ws<15>) → Wd<14>
    (Ws<14:1>) → Wd<13:0>
    (Ws<0>) → C
Estado afectado:
norte, z, c
Codificación:
1101
0001
1Bqq
qdddd
dppp
sss
Descripción:
Desplace el contenido del registro fuente Ws un bit hacia la derecha y coloque el 
resulta en el registro de destino Wd. La parte menos significativa de W es 
desplazado al bit de acarreo del registro STATUS. Una vez realizado el turno, 
el resultado es de signos extendidos. Cualquier registro de direccionamiento directo o indirecto podrá 
usarse para Ws y Wd.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
c

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 112
© 2009 Microchip Technology Inc.
Ejemplo 1:
ASR.B [W0++], [W1++]
; ASR [W0] y almacenar en [W1] 
(modo bytes)
; W0 y W1 posteriores al incremento
antes
Instrucción
después
Instrucción
W0
0600
W0
0601
W1
0801
W1
0802
Datos 600
2366
Datos 600
2366
 Datos 800
FFC0
Datos 800
33C0
SR
0000
SR
0000  
Ejemplo 2:
ASR W12, W13
; ASR W12 y almacenar en W13 
(modo palabra)
antes 
Instrucción
después
Instrucción
W12
AB01
W12
AB01
W13
0322
W13
D580
SR
0000
SR
0009
 (norte, C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 113
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
ASR
Desplazamiento aritmético a la derecha por literal corto
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:}
ASR
Wb, 
#lit4, 
viento
Operandos:
Wb ∈ [W0 ... W15]
iluminado4 ∈ [0...15]
Viento ∈ [W0 ... W15] 
Operación:
lit4<3:0> → Shift_Val
Wb<15> → Wnd<15:15-Shift_Val + 1>
Wb<15:Shift_Val> → Wnd<15-Shift_Val:0>
Estado afectado:
norte, z
Codificación:
1101
1110
1www
wdddd
d100
kkkk
Descripción:
Desplazamiento aritmético a la derecha del contenido del registro fuente Wb en 4 bits 
literal sin signo y almacene el resultado en el registro de destino Wnd. después 
Se realiza el cambio y el resultado se extiende con signos. El direccionamiento directo debe 
usarse para Wb y Wnd.
Los bits ‘w’ seleccionan la dirección del registro base.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘k’ proporcionan el operando literal.
Nota:
Esta instrucción funciona únicamente en modo Word.
Palabras:
1
Ciclos:
1
Ejemplo 1:
ASR W0, #0x4, W1
; ASR W0 por 4 y almacenar en W1
antes 
Instrucción
después
Instrucción
W0
060F
W0
060F
W1
1234
W1
0060
SR
0000
SR
0000  
Ejemplo 2:
ASR W0, #0x6, W1
; ASR W0 por 6 y almacenar en W1 
antes 
Instrucción
después
Instrucción
W0
80FF
W0
80FF
W1
0060
W1
FE03
SR
0000
SR
0008 (n = 1) 
Ejemplo 3:
ASR W0, #0xF, W1
; ASR W0 por 15 y almacenar en W1
antes 
Instrucción
después
Instrucción
W0
70FF
W0
70FF
W1
CC26
W1
0000
SR
0000
SR
0002 (Z = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 114
© 2009 Microchip Technology Inc.
  
ASR
Desplazamiento aritmético a la derecha por Wns
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:}
ASR
Wb, 
WNS, 
viento
Operandos:
Wb ∈ [W0 ... W15]
Wns ∈ [W0 ...W15]
Viento ∈ [W0 ... W15] 
Operación:
Wns<3:0> → Shift_Val
Wb<15> → Wnd<15:15-Shift_Val + 1>
Wb<15:Shift_Val> → Wnd<15-Shift_Val:0>
Estado afectado:
norte, z
Codificación:
1101
1110
1www
wdddd
d000
sss
Descripción:
Desplazamiento aritmético hacia la derecha el contenido del registro fuente Wb por el 4 Mínimo 
Bits significativos de Wns (hasta 15 posiciones) y almacenar el resultado en el 
registro de destino Wnd.  Después de realizar el turno, el resultado es 
signo extendido. Se debe utilizar direccionamiento directo para Wb, Wns y Wnd.
Los bits ‘w’ seleccionan la dirección del registro base.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: Esta instrucción funciona únicamente en modo Word.
2: Si Wns es mayor que 15, Wnd = 0x0 si Wb es positivo, y
Wnd = 0xFFFF si Wb es negativo.
Palabras:
1
Ciclos:
1
Ejemplo 1:
ASR W0, W5, W6
; ASR W0 por W5 y almacenar en W6 
antes 
Instrucción
después
Instrucción
W0
80FF
W0
80FF
W5
0004
W5
0004
W6
2633
W6
F80F
SR
0000
SR
0000  
Ejemplo 2:
ASR W0, W5, W6
; ASR W0 por W5 y almacenar en W6 
antes 
Instrucción
después
Instrucción
W0
6688
W0
6688
W5
000A
W5
000A
W6
FF00
W6
0019
SR
0000
SR
0000  
Ejemplo 3:
ASR W11, W12, W13
; ASR W11 por W12 y almacenar en W13 
antes 
Instrucción
después
Instrucción
W11
8765
W11
8765
W12
88E4
W12
88E4
W13
A5A5
W13
F876
SR
0000
SR
0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 115
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
    
BCLR
Borrar bits f
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BCLR{.B}
f,
#bit4
Operandos:
f ∈ [0 ... 8191] para operación de bytes
f ∈ [0 ... 8190] (solo pares) para operación de palabra
bit4 ∈ [0 ... 7] para operación de bytes
bit4 ∈ [0 ... 15] para operación de bytes
Operación:
 0 → f<bit4>
Estado afectado:
Ninguno
Codificación:
1010
1001
bbbf
ffff
ffff
fffb
Descripción:
Borre el bit en el registro de archivo f especificado por ‘bit4’. Comienza la numeración de bits 
con el bit menos significativo (bit 0) y avanza al más significativo 
bit (bit 7 para operaciones de bytes, bit 15 para operaciones de palabras).
Los bits ‘b’ seleccionan el valor bit4 de la posición del bit que se va a borrar.
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: Cuando esta instrucción opera en modo Word, el registro de archivo
la dirección debe estar alineada con las palabras.
3: Cuando esta instrucción opera en modo Byte, ‘bit4’ debe ser
entre 0 y 7.
Palabras:
1
Ciclos:
1
Ejemplo 1:
BCLR.B 0x800, #0x7
; Borrar bit 7 en 0x800
antes 
Instrucción
después
Instrucción
Datos 0800
66EF
Datos 0800
666F
SR
0000
SR
0000  
Ejemplo 2:
BCLR 0x400, #0x9
; Borrar bit 9 en 0x400
antes 
Instrucción
después
Instrucción
Datos 0400
AA55
Datos 0400
A855
SR
0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 116
© 2009 Microchip Technology Inc.
  
BCLR
Bit claro en Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BCLR{.B}
Ws,
#bit4
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
bit4 ∈ [0 ... 7] para operación de bytes
bit4 ∈ [0 ... 15] para operación de palabra
Operación:
 0 → Ws<bit4>
Estado afectado:
Ninguno
Codificación:
1010
0001
bbbb
0B00
0ppp
sss
Descripción:
Borre el bit en el registro Ws especificado por ‘bit4’. La numeración de bits comienza con 
el bit menos significativo (bit 0) y avanza al bit más significativo (bit 
7 para operaciones de bytes, bit 15 para operaciones de palabras). Registro directo o individual.
Se puede utilizar el direccionamiento correcto para Ws.
Los bits ‘b’ seleccionan el valor bit4 de la posición del bit que se va a borrar.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘s’ seleccionan el registro de origen/destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: Cuando esta instrucción opera en modo Word, la fuente
La dirección de registro debe estar alineada con palabras.
3: Cuando esta instrucción opera en modo Byte, ‘bit4’ debe ser
entre 0 y 7.
Palabras:
1
Ciclos:
1
Ejemplo 1:
BCLR.B
W2, #0x2
; Borrar bit 3 en W2 
antes 
Instrucción
después
Instrucción
W2
F234
W2
F230
SR
0000
SR
0000  
Ejemplo 2:
BCLR [W0++], #0x0
; Borrar bit 0 en [W0]
; W0 posterior al incremento 
antes 
Instrucción
después
Instrucción
W0
2300
W0
2302
Datos 2300
5607
 Datos 2300
5606  
SR
0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 117
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
 
sujetador 
Ramificar incondicionalmente
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde Slit16 ∈ [-32768 ... +32767].
Operación:
(PC + 2) + 2 * Rendija16 → PC
NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
0111
nnnn
nnnn
nnnn
nnnn
Descripción:
El programa se bifurcará incondicionalmente, en relación con la siguiente PC. la compensación 
de la rama es el número en complemento a dos ‘2 * Slit16’, que soporta 
ramifica hasta 32K instrucciones hacia adelante o hacia atrás. El valor de Slit16 es 
resuelto por el enlazador a partir de la etiqueta suministrada, dirección absoluta o 
expresión. Después de tomar la sucursal, la nueva dirección será (PC + 2) + 2 * 
Slit16, ya que la PC habrá incrementado para buscar la siguiente instrucción.
Los bits ‘n’ son un literal con signo que especifica el número de palabras del programa. 
compensado de (PC + 2).
Palabras:
1
Ciclos:
2
Ejemplo 1:
002000 AQUÍ: BRA ALLÁ
002002. . .
002004. . .
002006. . .
002008. . .
00200A ALLÍ: . . .
00200C. . .
; Sucursal a ALLÍ
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 200A
SR
  0000
SR
0000  
Ejemplo 2:
002000 AQUÍ: SUJETADOR ALLÍ+0x2
002002. . .
002004. . .
002006. . .
002008. . .
00200A ALLÍ: . . .
00200C. . .
; Ramificar a ALLÍ+0x2
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 200C
SR
  0000
SR
0000  
Ejemplo 3:
002000 AQUÍ: BRA 0x1366
002002. . .
002004. . .
; Ramificar a 0x1366
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 1366
SR
  0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 118
© 2009 Microchip Technology Inc.
  
sujetador
Rama Computada
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador 
Wn
Operandos:
Wn ∈ [W0 ... W15]
Operación:
(PC + 2) + (2 * Wn) → PC
NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0000
0001
0110
0000
0000
sss
Descripción:
El programa se ramifica incondicionalmente con respecto al siguiente PC. la compensación 
de la rama es el valor de 17 bits con signo extendido (2 * Wn), que admite 
ramifica hasta 32K instrucciones hacia adelante o hacia atrás. Después de esta instrucción 
se ejecuta, la nueva PC será (PC + 2) + 2 * Wn, ya que la PC tendrá 
incrementa para buscar la siguiente instrucción. 
Los bits ‘s’ seleccionan el registro fuente.
Palabras:
1
Ciclos:
2
Ejemplo 1:
002000 AQUÍ: BRA W7
002002
. . .
 ...
. . .
 ...
. . .
002108
. . .
00210A TABLA 7: . . .
00210C
. . .
; Rama hacia adelante (2+2*W7)
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 210A
W7
  0084
W7
0084  
SR
  0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 119
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
sujetador c
Rama si lleva
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
c, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde Slit16 ∈ [-32768 ... +32767].
Operación:
Condición = C
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
0001
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el bit del indicador de acarreo es ‘1’, entonces el programa se bifurcará en relación con la siguiente PC. 
El desplazamiento de la rama es el número en complemento a dos ‘2 * Slit16’, que 
Soporta ramas de hasta 32K instrucciones hacia adelante o hacia atrás. La hendidura16 
El valor lo resuelve el vinculador a partir de la etiqueta proporcionada, la dirección absoluta o 
expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que la 
La PC habrá incrementado para buscar la siguiente instrucción. La instrucción entonces 
se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo ciclo.
Los bits ‘n’ son un literal con signo de 16 bits que especifica el desplazamiento desde (PC + 2) en 
palabras de instrucción.
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA C, LLEVAR
002002NO_C: . . .
002004. . .
002006 IR AHÍ
002008 LLEVAR: . . .
00200A. . .
00200C ALLÍ: . . .
00200E. . .
; Si C está configurado, pase a CARRY
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2008
SR
  0001 (C = 1)
SR
 0001 (C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 120
© 2009 Microchip Technology Inc.
Ejemplo 2:
002000 AQUÍ: BRA C, LLEVAR
002002 NO_C: ...
002004...
002006 IR AHÍ
002008 LLEVAR: ...
00200A...
00200C ALLÍ: ...
00200E...
; Si C está configurado, pase a CARRY
; De lo contrario... continuar
antes
Instrucción
después
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
SR
  0000
SR
 0000
Ejemplo 3:
006230 AQUÍ: BRA C, LLEVAR
006232 NO_C: ...
006234 ...
006236 IR AHÍ
006238 LLEVAR: ...
00623A ...
00623C ALLÍ: ...
00623E ...
; Si C está configurado, pase a CARRY
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 6230
ordenador personal
00 6238
SR
  0001 (C = 1)
SR
 0001 (C = 1)
Ejemplo 4:
006230 INICIO: ...
006232 ...
006234 LLEVAR: ...
006236 ...
006238 ...
00623A ...
00623C AQUÍ: BRA C, LLEVAR
00623E ...
; Si C está configurado, pase a CARRY
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 623C
ordenador personal
00 6234
SR
  0001 (C = 1)
SR
 0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 121
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
BRA GE
Rama si se firma mayor o igual
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
GE, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = (N&&!OV)||(!N&&!OV)
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
1101
nnnn
nnnn
nnnn
nnnn
Descripción:
Si la expresión lógica (N&&OV)||(!N&&!OV) es verdadera, entonces el programa 
se bifurcará en relación con la siguiente PC. El desplazamiento de la rama es el de los dos. 
número de complemento ‘2 * Slit16’, que admite ramas de hasta 32K 
instrucciones hacia adelante o hacia atrás. El valor de Slit16 se resuelve mediante el 
enlazador de la etiqueta proporcionada, dirección absoluta o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits ‘n’ son un literal con signo de 16 bits que especifica el desplazamiento desde (PC + 2) 
en palabras de instrucción.
Nota:
El ensamblador convertirá la etiqueta especificada en el desplazamiento a
ser utilizado.
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
007600 BUCLE: . . .
007602. . .
007604. . .
007606. . .
007608 AQUÍ: BRA GE, BUCLE
00760A NO_GE: . . .
; Si es GE, pase a LOOP
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 7608
ordenador personal
00 7600
SR
  0000
SR
 0000  
Ejemplo 2:
007600 BUCLE: . . .
007602. . .
007604. . .
007606. . .
007608 AQUÍ: BRA GE, BUCLE
00760A NO_GE: . . .
; Si es GE, pase a LOOP
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 7608
ordenador personal
00 760A
SR
  0008 (n = 1)
SR
 0008 (n = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 122
© 2009 Microchip Technology Inc.
    
BRA GEU
Rama si no está firmada mayor o igual
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
UEE, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
El vinculador resuelve Expr en un desplazamiento Slit16 que admite un desplazamiento 
rango de palabras de programa [-32768 ... +32767].
Operación:
Condición = C
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
0001
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el indicador de acarreo es ‘1’, entonces el programa se bifurcará en relación con el siguiente 
ordenador personal. El desplazamiento de la rama es el número en complemento a dos ‘2 * 
Slit16’, que admite ramas de hasta 32 000 instrucciones hacia adelante o hacia atrás.
barrio. El valor de Slit16 lo resuelve el enlazador de la etiqueta suministrada, 
dirección o expresión absoluta.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, 
ya que la PC habrá incrementado para buscar la siguiente instrucción. el 
La instrucción luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado. 
en el segundo ciclo.
Los bits ‘n’ son un literal con signo de 16 bits que especifica el desplazamiento desde 
(PC + 2) en palabras de instrucción.
Nota:
Esta instrucción es idéntica a BRA C, Expr (Branch si
Carry) instrucción y tiene la misma codificación. se revertirá
ensamble como BRA C, Slit16.
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA GEU, BYPASS
002002 NO_GEU: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si C está configurado, bifurque
; para anular
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 200C
SR
  0001 (C = 1)
SR
 0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 123
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
BRA GT
Rama si se firma mayor que
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
GT, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = (!Z&&N&&OV)||(!Z&&!N&&!OV)
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
1100
nnnn
nnnn
nnnn
nnnn
Descripción:
Si la expresión lógica (!Z&&N&&OV)||(!Z&&!N&&!OV) es verdadera, entonces la 
El programa se bifurcará en relación con la siguiente PC. El desplazamiento de la rama es el 
número de complemento a dos ‘2 * Slit16’, que admite ramas de hasta 32K 
instrucciones hacia adelante o hacia atrás. El valor de Slit16 se resuelve mediante el 
enlazador de la etiqueta proporcionada, dirección absoluta o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits ‘n’ son un literal con signo de 16 bits que especifica el desplazamiento desde (PC + 2) 
en palabras de instrucción.
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA GT, BYPASS
002002 NO_GT: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si GT, pasar a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 200C
SR
  0001 (C = 1)
SR
 0001 (C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 124
© 2009 Microchip Technology Inc.
  
BRA GTU
Rama si no está firmada mayor que
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
GTU, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = (C&&!Z)
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
1110
nnnn
nnnn
nnnn
nnnn
Descripción:
Si la expresión lógica (C&&!Z) es verdadera, entonces el programa se bifurcará 
en relación con la siguiente PC. El desplazamiento de la rama es el complemento a dos. 
número ‘2 * Slit16’, que admite ramas de hasta 32K instrucciones 
hacia adelante o hacia atrás. El valor de Slit16 lo resuelve el enlazador del 
etiqueta suministrada, dirección absoluta o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits 'n' son un literal con signo que especifica el número de instrucciones fuera de
configurar desde (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA GTU, BYPASS
002002 NO_GTU: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si es GTU, pase a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 200C
SR
  0001 (C = 1)
SR
 0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 125
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
BRA LE
Rama si se firma menor o igual
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
LE, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = Z||(N&&!OV)||(!N&&OV)
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
0100
nnnn
nnnn
nnnn
nnnn
Descripción:
Si la expresión lógica (Z||(N&&!OV)||(!N&&OV)) es verdadera, entonces la 
El programa se bifurcará en relación con la siguiente PC. El desplazamiento de la rama es el 
número de complemento a dos ‘2 * Slit16’, que admite ramas de hasta 32K 
instrucciones hacia adelante o hacia atrás. El valor de Slit16 lo resuelve el enlazador. 
de la etiqueta suministrada, dirección absoluta o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits ‘n’ son un literal con signo que especifica el número de instrucciones 
compensado de (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA LE, BYPASS
002002 NO_LE: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si LE, bifurcar a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
SR
  0001 (C = 1)
SR
 0001 (C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 126
© 2009 Microchip Technology Inc.
  
BRA LEU
Rama si no está firmada menor o igual
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
UPE, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = !C||Z
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
0110
nnnn
nnnn
nnnn
nnnn
Descripción:
Si la expresión lógica (!C||Z) es verdadera, entonces el programa se bifurcará 
en relación con la siguiente PC. El desplazamiento de la rama es el complemento a dos. 
número ‘2 * Slit16’, que admite ramas de hasta 32K instrucciones para-
hacia atrás o hacia atrás. El valor de Slit16 lo resuelve el enlazador del 
etiqueta suministrada, dirección absoluta o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits 'n' son un literal con signo que especifica el número de instrucciones fuera de
configurar desde (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA LEU, BYPASS
002002 NO_LEU: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si es LEU, pase a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 200C
SR
  0001 (C = 1)
SR
 0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 127
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
sujetador lt
Rama si se firmó menos de
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
LT, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = (N&&!OV)||(!N&&!OV)
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
0101
nnnn
nnnn
nnnn
nnnn
Descripción:
Si la expresión lógica ( (N&&!OV)||(!N&&OV) ) es verdadera, entonces el programa 
se bifurcará en relación con la siguiente PC. El desplazamiento de la rama es el de los dos. 
número de complemento ‘2 * Slit16’, que admite ramas de hasta 32K 
instrucciones hacia adelante o hacia atrás. El valor de Slit16 se resuelve mediante el 
enlazador de la etiqueta proporcionada, dirección absoluta o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits 'n' son un literal con signo que especifica el número de instrucciones fuera de
configurar desde (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA LT, BYPASS
002002 NO_LT: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si LT, pase a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
SR
  0001 (C = 1)
SR
 0001 (C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 128
© 2009 Microchip Technology Inc.
BRA LTU
Rama si no está firmado Menos de
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
LTU, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = !C
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
1001
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el indicador de acarreo es ‘0’, entonces el programa se bifurcará en relación con la siguiente PC. 
El desplazamiento de la rama es el número en complemento a dos ‘2 * Slit16’, 
que admite ramas de hasta 32K instrucciones hacia adelante o hacia atrás. el 
El valor de Slit16 lo resuelve el enlazador de la etiqueta suministrada, absoluto 
dirección o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits ‘n’ son un literal con signo que especifica el número de instrucciones 
compensado de (PC + 2).
Nota:
Esta instrucción es idéntica a BRA NC, Expr (Branch si no
Carry) instrucción y tiene la misma codificación. se revertirá
ensamble como BRA NC, Slit16.
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA LTU, BYPASS
002002 NO_LTU: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si es LTU, pase a BYPASS
; De lo contrario... continuar
 
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
SR
  0001 (C = 1)
SR
 0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 129
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
 
BRA N
Rama si es negativo
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
norte, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = N
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones.
Estado afectado:
Ninguno
Codificación:
0011
0011
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el indicador Negativo es ‘1’, entonces el programa se bifurcará en relación con el siguiente 
ordenador personal. El desplazamiento de la rama es el número en complemento a dos ‘2 * Slit16’, 
que admite ramas de hasta 32K instrucciones hacia adelante o hacia atrás. el 
El valor de Slit16 lo resuelve el enlazador de la etiqueta suministrada, absoluto 
dirección o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits ‘n’ son un literal con signo que especifica el número de instrucciones 
compensado de (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA N, BYPASS
002002 NO_N: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si N, bifurque a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 200C
SR
  0008 (n = 1)
SR
 0008 (n = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 130
© 2009 Microchip Technology Inc.
  
BRA NC
Rama si no se lleva
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
Carolina del Norte, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = !C
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
1001
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el indicador de acarreo es ‘0’, entonces el programa se bifurcará en relación con la siguiente PC. 
El desplazamiento de la rama es el número en complemento a dos ‘2 * Slit16’, que 
Soporta ramas de hasta 32K instrucciones hacia adelante o hacia atrás. La hendidura16 
El valor lo resuelve el vinculador a partir de la etiqueta proporcionada, la dirección absoluta o 
expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits ‘n’ son un literal con signo que especifica el número de instrucciones 
compensado de (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA NC, BYPASS
002002 NO_NC: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si es NC, bifurque a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
SR
  0001 (C = 1)
SR
 0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 131
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
BRA NN
Rama si no es negativo
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
NN, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = !N
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
1011
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el indicador Negativo es ‘0’, entonces el programa se bifurcará en relación con el siguiente 
ordenador personal. El desplazamiento de la rama es el número en complemento a dos ‘2 * Slit16’, 
que admite ramas de hasta 32K instrucciones hacia adelante o hacia atrás. el 
El valor de Slit16 lo resuelve el enlazador de la etiqueta suministrada, absoluto 
dirección o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits 'n' son un literal con signo que especifica el número de instrucciones fuera de
configurar desde (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA NN, BYPASS
002002 NO_NN: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si es NN, pase a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 200C
SR
  0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 132
© 2009 Microchip Technology Inc.
    
SUJETADOR NOVIEMBRE
Rama si no se desborda
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
NOVIEMBRE, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = !OV
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
1000
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el indicador de desbordamiento es ‘0’, entonces el programa se bifurcará en relación con el siguiente 
ordenador personal. El desplazamiento de la rama es el número en complemento a dos ‘2 * Slit16’, 
que admite ramas de hasta 32K instrucciones hacia adelante o hacia atrás. el 
El valor de Slit16 lo resuelve el enlazador de la etiqueta suministrada, absoluto 
dirección o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits ‘n’ son un literal con signo que especifica el número de instrucciones 
compensado de (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA NOV, BYPASS
002002 NO_NOV: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si es NOV, pase a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 200C
SR
  0008 (n = 1)
SR
0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 133
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
BRA Nueva Zelanda
Rama si no es cero
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
Nueva Zelanda, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = !Z
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
1010
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el indicador Z es ‘0’, entonces el programa se bifurcará en relación con la siguiente PC. el 
El desplazamiento de la rama es el número en complemento a dos ‘2 * Slit16’, que 
Soporta ramas de hasta 32K instrucciones hacia adelante o hacia atrás. La hendidura16 
El valor lo resuelve el vinculador a partir de la etiqueta proporcionada, la dirección absoluta o 
expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits 'n' son un literal con signo que especifica el número de instrucciones fuera de
configurar desde (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA NZ, BYPASS
002002 NO_NZ: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si es Nueva Zelanda, pase a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
SR
  0002 (Z = 1)
SR
 0002 (Z = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 134
© 2009 Microchip Technology Inc.
  
BRA OA
Ramificación si se desborda el acumulador A
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:} 
sujetador
OA, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = OA
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0000
1100
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el indicador A del acumulador de desbordamiento es ‘1’, entonces el programa se bifurcará 
en relación con la siguiente PC. El desplazamiento de la rama es el complemento a dos. 
número ‘2 * Slit16’, que admite ramas de hasta 32K instrucciones 
hacia adelante o hacia atrás. El valor de Slit16 lo resuelve el enlazador del 
etiqueta suministrada, dirección absoluta o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits ‘n’ son un literal con signo que especifica el número de instrucciones 
compensado de (PC + 2).
Nota:
El ensamblador convertirá la etiqueta especificada en el desplazamiento a 
ser utilizado.
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA OA, BYPASS
002002 NO_OA: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si es OA, pase a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 200C
SR
  8800 (OA, OAB = 1) SR
 8800 (OA, OAB = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 135
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
SUJETADOR OB
Ramificación si se desborda el acumulador B
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:} 
sujetador
obstetricia, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = OB
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0000
1101
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el indicador del Acumulador de desbordamiento B es ‘1’, entonces el programa se bifurcará 
en relación con la siguiente PC. El desplazamiento de la rama es el complemento a dos. 
número ‘2 * Slit16’, que admite ramas de hasta 32K instrucciones 
hacia adelante o hacia atrás. El valor de Slit16 lo resuelve el enlazador del 
etiqueta suministrada, dirección absoluta o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits ‘n’ son un literal con signo que especifica el número de instrucciones 
compensado de (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA OB, BYPASS
002002 NO_OB: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si es OB, pase a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
SR
  8800 (OA, OAB = 1) SR
 8800 (OA, OAB = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 136
© 2009 Microchip Technology Inc.
    
SUJETADOR OV
Rama si se desborda
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
VO, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = OV
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
0000
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el indicador de desbordamiento es ‘1’, entonces el programa se bifurcará en relación con el siguiente 
ordenador personal. El desplazamiento de la rama es el número en complemento a dos ‘2 * Slit16’, 
que admite ramas de hasta 32K instrucciones hacia adelante o hacia atrás. el 
El valor de Slit16 lo resuelve el enlazador de la etiqueta suministrada, absoluto 
dirección o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits ‘n’ son un literal con signo que especifica el número de instrucciones 
compensado de (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA OV, BYPASS
002002 NO_OV . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si es OV, pase a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
SR
  0002 (Z = 1)
SR
 0002 (Z = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 137
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
BRA SA
Ramificación si saturación Acumulador A
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:} 
sujetador
SA, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = SA
Si (Condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0000
1110
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el indicador del acumulador de saturación A es ‘1’, entonces el programa se bifurcará 
en relación con la siguiente PC. El desplazamiento de la rama es el complemento a dos. 
número ‘2 * Slit16’, que admite ramas de hasta 32K instrucciones para-
hacia atrás o hacia atrás. El valor de Slit16 lo resuelve el enlazador del proveedor.
etiqueta aplicada, dirección absoluta o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits 'n' son un literal con signo que especifica el número de instrucciones fuera de
configurar desde (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA SA, BYPASS
002002 NO_SA: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si SA, derivar a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 200C
SR
  2400 (SA, SAB = 1)
SR
 2400 (SA, SAB = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 138
© 2009 Microchip Technology Inc.
  
SUJETADOR SB
Ramificación si saturación Acumulador B
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:} 
sujetador
SB, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = SB
si (condición)
    (PC + 2) + 2 * Rendija16→ PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0000
1111
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el indicador del Acumulador de Saturación B es ‘1’, entonces el programa se bifurcará 
en relación con la siguiente PC. El desplazamiento de la rama es el complemento a dos. 
número ‘2 * Slit16’, que admite ramas de hasta 32K instrucciones 
hacia adelante o hacia atrás. El valor de Slit16 lo resuelve el enlazador del 
etiqueta suministrada, dirección absoluta o expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits 'n' son un literal con signo que especifica el número de instrucciones fuera de
configurar desde (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA SB, BYPASS
002002 NO_SB: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si es SB, pase a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
SR
  0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 139
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
BRA Z
Rama si cero
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
sujetador
z, 
Expr.
Operandos:
Expr puede ser una etiqueta, una dirección absoluta o una expresión. 
Expr es resuelto por el enlazador a Slit16, donde 
Rendija16 ∈ [-32768 ... +32767].
Operación:
Condición = Z
si (condición)
    (PC + 2) + 2 * Rendija16 → PC
    NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0011
0010
nnnn
nnnn
nnnn
nnnn
Descripción:
Si el indicador Cero es ‘1’, entonces el programa se bifurcará en relación con la siguiente PC. 
El desplazamiento de la rama es el número en complemento a dos ‘2 * Slit16’, que 
Soporta ramas de hasta 32K instrucciones hacia adelante o hacia atrás. La hendidura16 
El valor lo resuelve el vinculador a partir de la etiqueta proporcionada, la dirección absoluta o 
expresión.
Si se toma la sucursal, la nueva dirección será (PC + 2) + 2 * Slit16, ya que 
la PC habrá incrementado para buscar la siguiente instrucción. la instrucción 
luego se convierte en una instrucción de dos ciclos, con un NOP ejecutado en el segundo 
ciclo.
Los bits ‘n’ son un literal con signo que especifica el número de instrucciones 
compensado de (PC + 2).
Palabras:
1
Ciclos:
1 (2 si se toma la rama)
Ejemplo 1:
002000 AQUÍ: BRA Z, BYPASS
002002 NO_Z: . . .
002004. . .
002006. . .
002008. . .
00200A IR AHÍ
00200C DERIVACIÓN: . . .
00200E. . .
; Si es Z, bifurque a BYPASS
; De lo contrario... continuar
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 200C
SR
  0002 (Z = 1)
SR
0002 (Z = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 140
© 2009 Microchip Technology Inc.
  
BSET
Juego de bits f 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BSET{.B}
f,
#bit4
Operandos:
f ∈ [0 ... 8191] para operación de bytes
f ∈ [0 ... 8190] (solo pares) para operación de palabra
bit4 ∈ [0 ... 7] para operación de bytes
bit4 ∈ [0 ... 15] para operación de palabra
Operación:
1 → f<bit4>
Estado afectado:
Ninguno
Codificación:
1010
1000
bbbf
ffff
ffff
fffb
Descripción:
Establezca el bit en el registro de archivo 'f' especificado por 'bit4'. Comienza la numeración de bits 
con el bit menos significativo (bit 0) y avanza al más significativo 
bit (bit 7 para operaciones de bytes, bit 15 para operaciones de palabras).
Los bits ‘b’ seleccionan el valor bit4 de la posición del bit que se va a configurar.
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: Cuando esta instrucción opera en modo Word, el registro de archivo
la dirección debe estar alineada con las palabras.
3: Cuando esta instrucción opera en modo Byte, ‘bit4’ debe ser
entre 0 y 7.
Palabras:
1
Ciclos:
1
Ejemplo 1:
BSET.B 0x601, #0x3
; Establecer el bit 3 en 0x601
antes 
Instrucción
después
Instrucción
Datos 0600
F234
Datos 0600
FA34
SR
0000
SR
0000  
Ejemplo 2:
BSET 0x444, #0xF
; Establecer el bit 15 en 0x444
antes 
Instrucción
después
Instrucción
Datos 0444
5604
Datos 0444
D604  
SR
0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 141
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
BSET
Conjunto de bits en Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BSET{.B}
Ws,
#bit4
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
bit4 ∈ [0 ... 7] para operación de bytes
bit4 ∈ [0 ... 15] para operación de palabra
Operación:
1 → Ws<bit4>
Estado afectado:
Ninguno
Codificación:
1010
0000
bbbb
0B00
0ppp
sss
Descripción:
Establezca el bit en el registro Ws especificado por ‘bit4’. La numeración de bits comienza con el 
Bit menos significativo (bit 0) y avanza al bit más significativo (bit 7 
para operaciones de bytes, bit 15 para operaciones de palabras). Registro directo o indirecto 
El direccionamiento se puede utilizar para Ws.
Los bits ‘b’ seleccionan el valor bit4 de la posición del bit que se va a borrar.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro de origen/destino.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: Cuando esta instrucción opera en modo Word, la fuente
La dirección de registro debe estar alineada con palabras.
3: Cuando esta instrucción opera en modo Byte, ‘bit4’ debe ser
entre 0 y 7.
Palabras:
1
Ciclos:
1
Ejemplo 1:
BSET.B
W3, #0x7
; Establecer el bit 7 en W3
antes 
Instrucción
después
Instrucción
W3
0026
W3
00A6
SR
0000
SR
0000
Ejemplo 2:
BSET [W4++], #0x0
; Establezca el bit 0 en [W4]
; W4 posterior al incremento 
antes 
Instrucción
después
Instrucción
W4
6700
W4
6702
Datos 6700
1734
 Datos 6700
1735  
SR
0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 142
© 2009 Microchip Technology Inc.
  
BSW
Escritura de bits en Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BSW.C
Ws,
Wb
BSW.Z
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
Wb ∈ [W0 ... W15]
Operación:
Para funcionamiento “.C”:
    C → Ws<(Wb)>
Para operación “.Z” (predeterminado):  
    Z → Ws<(Wb)>
Estado afectado:
Ninguno
Codificación:
1010
1101
Zwww
w000
0ppp
sss
Descripción:
El bit (Wb) en el registro Ws se escribe con el valor del indicador C o Z de 
el registro de ESTADO. La numeración de bits comienza con el bit menos significativo. 
(bit 0) y avanza al bit más significativo (bit 15) del código de trabajo. 
registrarse. Sólo se utilizan los cuatro bits menos significativos de Wb para determinar 
el número de bit de destino. Se debe utilizar el direccionamiento directo de registro para 
Wb, y se puede utilizar el direccionamiento directo o indirecto de registro para Ws.
El bit ‘Z’ selecciona el indicador C o Z como fuente.
Los bits ‘w’ seleccionan la dirección del registro de selección de bits.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
Esta instrucción sólo funciona en modo Word. Si no hay extensión 
siempre y cuando se suponga la operación “.Z”.
Palabras:
1
Ciclos:
1
Ejemplo 1:
BSW.C W2, W3
; Establezca el bit W3 en W2 al valor
; del bit C
antes 
Instrucción
después
Instrucción
W2
F234
W2
7234
W3
111F
W3
111F
SR
0002 (Z = 1, C = 0)
SR
0002 (Z = 1, C = 0)

© 2009 Microchip Technology Inc.
DS70157D-página 143
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
Ejemplo 2:
BSW.Z W2, W3
; Configure el bit W3 en W2 al complemento
; del bit Z
antes 
Instrucción
después
Instrucción
W2
E235
W2
E234
W3
0550
W3
0550
SR
0002 (Z = 1, C = 0) SR
0002 (Z = 1, C = 0)
Ejemplo 3:
BSW.C [++W0], W6
; Establezca el bit W6 en [W0++] al valor
; del bit C
antes 
Instrucción
después
Instrucción
W0
1000
W0
1002
W6
34A3
W6
34A3
Datos 1002
2380
Datos 1002
2388
SR
0001 (Z = 0, C = 1)
SR
0001 (Z = 0, C = 1)
Ejemplo 4:
BSW [W1--], W5
; Establezca el bit W5 en [W1] al
; complemento del bit Z
; Post-decremento W1
antes 
Instrucción
después
Instrucción
W1
1000
W1
0FFE
W5
888B
W5
888B
Datos 1000
C4DD
Datos 1000
CCDD
SR
0001 (C = 1)
SR
0001 (C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 144
© 2009 Microchip Technology Inc.
  
BTG
Cambio de bits f
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BTG{.B}
f,
#bit4
Operandos:
f ∈ [0 ... 8191] para operación de bytes
f ∈ [0 ... 8190] (solo pares) para operación de palabra
bit4 ∈ [0 ... 7] para operación de bytes
bit4 ∈ [0 ... 15] para operación de palabra
Operación:
(f)<bit4> → (f)<bit4>
Estado afectado:
Ninguno
Codificación:
1010
1010
bbbf
ffff
ffff
fffb
Descripción:
El bit ‘bit4’ en el registro de archivo ‘f’ se alterna (complementado). Para el bit4 
operando, la numeración de bits comienza con el bit menos significativo (bit 0) y 
avanza al bit más significativo (bit 7 para operación de byte, bit 15 para 
operación de palabra) del byte. 
Los bits ‘b’ seleccionan el valor bit4, la posición del bit a alternar.
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: Cuando esta instrucción opera en modo Word, el registro de archivo
la dirección debe estar alineada con las palabras.
3: Cuando esta instrucción opera en modo Byte, ‘bit4’ debe ser
entre 0 y 7.
Palabras:
1
Ciclos:
1
Ejemplo 1:
BTG.B 0x1001, #0x4
; Alternar bit 4 en 0x1001
antes 
Instrucción
después
Instrucción
Datos 1000
F234
Datos 1000
E234
SR
0000
SR
0000  
Ejemplo 2:
Por cierto 0x1660, #0x8
; Alternar bit 8 en RAM660
antes 
Instrucción
después
Instrucción
Datos 1660
5606
Datos 1660
5706  
SR
0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 145
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
BTG
Cambio de bits en Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BTG{.B}
Ws,
#bit4
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
bit4 ∈ [0 ... 7] para operación de bytes
bit4 ∈ [0 ... 15] para operación de palabra
Operación:
(Ws)<bit4> → Ws<bit4>
Estado afectado:
Ninguno
Codificación:
1010
0010
bbbb
0B00
0ppp
sss
Descripción:
El bit ‘bit4’ del registro Ws se alterna (complementado). Para el operando bit4, 
La numeración de bits comienza con el bit menos significativo (bit 0) y avanza hasta 
el bit más significativo (bit 7 para operaciones de bytes, bit 15 para operaciones de palabra 
operaciones). Se puede utilizar el direccionamiento directo o indirecto del registro para Ws.
Los bits ‘b’ seleccionan el valor bit4, la posición del bit a probar.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘s’ seleccionan el registro de origen/destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: Cuando esta instrucción opera en modo Word, la fuente
La dirección de registro debe estar alineada con palabras.
3: Cuando esta instrucción opera en modo Byte, ‘bit4’ debe ser
entre 0 y 7.
Palabras:
1
Ciclos:
1
Ejemplo 1:
BTG
W2, #0x0
; Alternar bit 0 en W2 
antes 
Instrucción
después
Instrucción
W2
F234
W2
F235
SR
0000
SR
0000  
Ejemplo 2:
BTG [W0++], #0x0
; Alternar bit 0 en [W0]
; W0 posterior al incremento 
antes 
Instrucción
después
Instrucción
W0
2300
W0
2302
Datos 2300
5606
 Datos 2300
5607  
SR
0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 146
© 2009 Microchip Technology Inc.
    
BTSC
Prueba de bits f, omitir si está claro
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BTSC{.B}
f,
#bit4
Operandos:
f ∈ [0 ... 8191] para operación de bytes
f ∈ [0 ... 8190] (solo pares) para operación de palabra
bit4 ∈ [0 ... 7] para operación de bytes
bit4 ∈ [0 ... 15] para operación de palabra
Operación:
Pruebe (f)<bit4>, omita si está claro
Estado afectado:
Ninguno
Codificación:
1010
1111
bbbf
ffff
ffff
fffb
Descripción:
Se prueba el bit ‘bit4’ en el registro de archivos. Si el bit probado es ‘0’, el siguiente 
La instrucción (obtenida durante la ejecución de la instrucción actual) se descarta. 
y en el siguiente ciclo, en su lugar se ejecuta un NOP. Si el bit probado es ‘1’, 
la siguiente instrucción se ejecuta normalmente. En cualquier caso, el contenido de 
el registro de archivos no se modifica. Para el operando bit4, numeración de bits 
comienza con el bit menos significativo (bit 0) y avanza hasta el más 
Bit significativo (bit 7 para operaciones de bytes, bit 15 para operaciones de palabras).
Los bits ‘b’ seleccionan el valor bit4, la posición del bit a probar.
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: Cuando esta instrucción opera en modo Word, el registro de archivo
la dirección debe estar alineada con las palabras.
3: Cuando esta instrucción opera en modo Byte, ‘bit4’ debe ser
entre 0 y 7.
Palabras:
1
Ciclos:
1 (2 o 3)
Ejemplo 1:
002000 AQUÍ: BTSC.B 0x1201, #2
002002 IR A ANULAR
002004. . .
002006. . .
002008 ANULACIÓN: . . .
00200A. . .
; Si el bit 2 de 0x1201 es 0,
; salta el IR A
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
Datos 1200
    264F
Datos 1200
 264F
SR
  0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 147
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
Ejemplo 2:
002000 AQUÍ: BTSC 0x804, #14
002002 IR A ANULAR
002004. . .
002006. . .
002008 ANULACIÓN: . . .
00200A. . .
; Si el bit 14 de 0x804 es 0,
; salta el IR A
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2004
Datos 0804
    2647
Datos 0804
 2647
SR
  0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 148
© 2009 Microchip Technology Inc.
      
BTSC
Prueba de bits Ws, omitir si está claro 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BTSC
Ws,
#bit4
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
bit4 ∈ [0 ... 15]
Operación:
Prueba (Ws)<bit4>, omítala si está clara
Estado afectado:
Ninguno
Codificación:
1010
0111
bbbb
0000
0ppp
sss
Descripción:
Se prueba el bit ‘bit4’ en Ws. Si el bit probado es ‘0’, la siguiente instrucción (buscada 
durante la ejecución de la instrucción actual) se descarta y en la siguiente 
ciclo, en su lugar se ejecuta un NOP. Si el bit probado es ‘1’, la siguiente instrucción 
se ejecuta normalmente. En cualquier caso, el contenido de Ws no cambia. 
Para el operando bit4, la numeración de bits comienza con el bit menos significativo 
(bit 0) y avanza al bit más significativo (bit 15) de la palabra. Cualquiera 
Se puede utilizar direccionamiento directo o indirecto para Ws.
Los bits ‘b’ seleccionan el valor bit4, la posición del bit a probar.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
Esta instrucción funciona únicamente en modo Word.
Palabras:
1
Ciclos:
1 (2 o 3 si se omite la siguiente instrucción)
Ejemplo 1:
002000 AQUÍ: BTSC W0, #0x0
002002 IR A ANULAR
002004. . .
002006. . .
002008 ANULACIÓN: . . .
00200A. . .
; Si el bit 0 de W0 es 0,
; salta el IR A
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
W0
    264F
W0
 264F
SR
  0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 149
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
Ejemplo 2:
002000 AQUÍ: BTSC W6, #0xF
002002 IR A ANULAR
002004. . .
002006. . .
002008 ANULACIÓN: . . .
00200A. . .
; Si el bit 15 de W6 es 0,
; salta el IR A
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2004
W6
    264F
W6
 264F
SR
  0000
SR
 0000
Ejemplo 3:
003400 AQUÍ: BTSC [W6++], #0xC
003402 IR A ANULAR
003404. . .
003406. . .
003408 ANULACIÓN: . . .
00340A. . .
; Si el bit 12 de [W6] es 0,
; salta el IR A
; W6 posterior al incremento
antes 
Instrucción
después 
Instrucción
ordenador personal
   00 3400
ordenador personal
  00 3402
W6
    1800
W6
 1802
Datos 1800
  1000
Datos 1800
 1000
SR
  0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 150
© 2009 Microchip Technology Inc.
  
BTSS
Prueba de bits f, omitir si está configurado
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BTSS{.B}
f,
#bit4
Operandos:
f ∈ [0 ... 8191] para operación de bytes
f ∈ [0 ... 8190] (solo pares) para operación de palabra
bit4 ∈ [0 ... 7] para operación de bytes
bit4 ∈ [0 ... 15] para operación de palabra
Operación:
Pruebe (f)<bit4>, omita si está configurado
Estado afectado:
Ninguno
Codificación:
1010
1110
bbbf
ffff
ffff
fffb
Descripción:
Se prueba el bit ‘bit4’ en el registro de archivo ‘f’. Si el bit probado es ‘1’, el siguiente 
La instrucción (obtenida durante la ejecución de la instrucción actual) se descarta. 
y en el siguiente ciclo, en su lugar se ejecuta un NOP. Si el bit probado es ‘0’, el 
La siguiente instrucción se ejecuta normalmente. En cualquier caso, el contenido del 
El registro de archivos no se modifica. Para el operando bit4, comienza la numeración de bits. 
con el bit menos significativo (bit 0) y avanza al más significativo 
bit (bit 7 para operación de byte, bit 15 para operación de palabra).
Los bits ‘b’ seleccionan el valor bit4, la posición del bit a probar.
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: Cuando esta instrucción opera en modo Word, el registro de archivo
la dirección debe estar alineada con las palabras.
3: Cuando esta instrucción opera en modo Byte, ‘bit4’ debe ser
entre 0 y 7.
Palabras:
1
Ciclos:
1 (2 o 3 si se omite la siguiente instrucción)
Ejemplo 1:
007100 AQUÍ: BTSS.B 0x1401, #0x1
007102 BORRAR BORRAR
007104. . .
; Si el bit 1 de 0x1401 es 1,
; no borre WREG
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 7100
ordenador personal
00 7104
Datos 1400
    0280
Datos 1400
 0280
SR
  0000
SR
 0000
Ejemplo 2:
007100 AQUÍ: BTSS 0x890, #0x9
007102 IR A ANULAR
007104. . .
007106 ANULACIÓN: . . .
; Si el bit 9 de 0x890 es 1,
; salta el IR A
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 7100
ordenador personal
00 7102
Datos 0890
    00FE
Datos 0890
00FE
SR
  0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 151
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
    
BTSS
Prueba de bits Ws, omitir si está configurado
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BTSS
Ws,
#bit4
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
bit4 ∈ [0 ... 15]
Operación:
Pruebe (Ws)<bit4>, omítalo si está configurado.
Estado afectado:
Ninguno
Codificación:
1010
0110
bbbb
0000
0ppp
sss
Descripción:
Se prueba el bit ‘bit4’ en Ws. Si el bit probado es ‘1’, la siguiente instrucción (buscada 
durante la ejecución de la instrucción actual) se descarta y en la siguiente 
ciclo, en su lugar se ejecuta un NOP. Si el bit probado es ‘0’, la siguiente instrucción 
se ejecuta normalmente. En cualquier caso, el contenido de Ws no cambia. 
Para el operando bit4, la numeración de bits comienza con el bit menos significativo 
(bit 0) y avanza al bit más significativo (bit 15) de la palabra. Cualquiera 
Se puede utilizar direccionamiento directo o indirecto para Ws.
Los bits ‘b’ seleccionan el valor bit4, la posición del bit a probar.
Los bits ‘s’ seleccionan el registro fuente.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Nota:
Esta instrucción funciona únicamente en modo Word.
Palabras:
1
Ciclos:
1 (2 o 3 si se omite la siguiente instrucción)
Ejemplo 1:
002000 AQUÍ: BTSS W0, #0x0
002002 IR A ANULAR
002004. . .
002006. . .
002008 ANULACIÓN: . . .
00200A. . .
; Si el bit 0 de W0 es 1,
; salta el IR A
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2004
W0
    264F
W0
 264F
SR
  0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 152
© 2009 Microchip Technology Inc.
Ejemplo 2:
002000 AQUÍ: BTSS W6, #0xF
002002 IR A ANULAR
002004. . .
002006. . .
002008 ANULACIÓN: . . .
00200A. . .
; Si el bit 15 de W6 es 1,
; salta el IR A
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
W6
    264F
W6
 264F
SR
  0000
SR
 0000
Ejemplo 3:
003400 AQUÍ: BTSS [W6++], 0xC
003402 IR A ANULAR
003404. . .
003406. . .
003408 ANULACIÓN: . . .
00340A. . .
; Si el bit 12 de [W6] es 1,
; salta el IR A
; W6 posterior al incremento
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 3400
ordenador personal
00 3404
W6
    1800
W6
1802
Datos 1800
  1000
Datos 1800
 1000
SR
  0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 153
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
BTST
Prueba de bits f
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BTST{.B}
f,
#bit4
Operandos:
f ∈ [0 ... 8191] para operación de bytes
f ∈ [0 ... 8190] (solo pares) para operación de palabra
bit4 ∈ [0 ... 7] para operación de bytes
bit4 ∈ [0 ... 15] para operación de palabra
Operación:
(f)<bit4> → Z
Estado afectado:
z
Codificación:
1010
1011
bbbf
ffff
ffff
fffb
Descripción:
El bit ‘bit4’ en el registro de archivo ‘f’ se prueba y el complemento del bit probado se 
almacenado en la bandera Z en el registro STATUS. El contenido del archivo. 
el registro no se modifica. Para el operando bit4, la numeración de bits comienza con 
el bit menos significativo (bit 0) y avanza al bit más significativo 
(bit 7 para operación de byte, bit 15 para operación de palabra).
Los bits ‘b’ seleccionan el valor bit4, la posición del bit que se va a probar.
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: Cuando esta instrucción opera en modo Word, el registro de archivo
la dirección debe estar alineada con las palabras.
3: Cuando esta instrucción opera en modo Byte, ‘bit4’ debe ser
entre 0 y 7.
Palabras:
1
Ciclos:
1
Ejemplo 1:
BTST.B 0x1201, #0x3
; Conjunto Z = complemento de 
; bit 3 en 0x1201
antes 
Instrucción
después
Instrucción
Datos 1200
F7FF
Datos 1200
F7FF
SR
0000
SR
0002 (Z = 1)
Ejemplo 2:
BTST 0x1302, #0x7
; Conjunto Z = complemento de
; bit 7 en 0x1302
antes 
Instrucción
después
Instrucción
Datos 1302
F7FF
Datos 1302
F7FF
SR
0002 (Z = 1) 
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 154
© 2009 Microchip Technology Inc.
  
BTST
Prueba de bits en Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BTST.C
Ws,
#bit4
BTST.Z
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
bit4 ∈ [0 ... 15]
Operación:
Para funcionamiento “.C”:  
    (Ws)<bit4> → C 
Para operación “.Z” (predeterminado):
    (Ws)<bit4> → Z
Estado afectado:
Z o C
Codificación:
1010
0011
bbbb
Z000
0ppp
sss
Descripción:
Se prueba el bit ‘bit4’ del registro Ws. Si la opción “.Z” de la instrucción es 
especificado, el complemento del bit probado se almacena en el indicador Cero en el 
Registro de ESTADO. Si se especifica la opción “.C” de la instrucción, el valor 
del bit probado se almacena en el indicador de acarreo en el registro STATUS. en cualquiera de los dos 
En este caso, el contenido de Ws no se modifica.
Para el operando bit4, la numeración de bits comienza con el bit menos significativo 
(bit 0) y avanza al bit más significativo (bit 15) de la palabra. Cualquiera 
Se puede utilizar direccionamiento directo o indirecto para Ws.
Los bits ‘b’ seleccionan el valor bit4, la posición del bit a probar.
El bit 'Z' selecciona la bandera C o Z como destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
Esta instrucción sólo funciona en modo Word. Si no hay extensión
siempre y cuando se suponga la operación “.Z”.
Palabras:
1
Ciclos:
1
Ejemplo 1:
BTST.C [W0++], #0x3
; Establezca C = bit 3 en [W0]
; W0 posterior al incremento
antes 
Instrucción
después
Instrucción
W0
1200
W0
1202
Datos 1200
FFF7
Datos 1200
FFF7
SR
0001 (C = 1)
SR
0000
Ejemplo 2:
BTST.Z W0, #0x7
; Establecer Z = complemento del bit 7 en W0
antes 
Instrucción
después
Instrucción
W0
F234
W0
F234
SR
0000
SR
0002 (Z = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 155
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
  
BTST
Prueba de bits en Ws 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BTST.C
Ws,
Wb
BTST.Z
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
Wb ∈ [W0 ... W15]
Operación:
Para funcionamiento “.C”:
    (Ws)<(Wb)> → C 
Para operación “.Z” (predeterminado):
    (Ws)<(Wb)> → Z 
Estado afectado:
Z o C
Codificación:
1010
0101
Zwww
w000
0ppp
sss
Descripción:
Se prueba el bit (Wb) en el registro Ws. Si la opción “.C” de la instrucción es 
especificado, el valor del bit probado se almacena en el indicador Carry en el 
Registro de ESTADO. Si se especifica la opción “.Z” de la instrucción, el 
El complemento del bit probado se almacena en el indicador Cero en el estado. 
registrarse. En cualquier caso, el contenido de Ws no cambia.
Sólo se utilizan los cuatro bits menos significativos de Wb para determinar el bit 
número. La numeración de bits comienza con el bit menos significativo (bit 0) y 
avanza al bit más significativo (bit 15) del registro de trabajo. 
Se puede utilizar el direccionamiento directo o indirecto del registro para Ws.
El bit 'Z' selecciona la bandera C o Z como destino.
Los bits ‘w’ seleccionan la dirección del registro de selección de bits.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
Esta instrucción sólo funciona en modo Word. Si no hay extensión
siempre y cuando se suponga la operación “.Z”.
Palabras:
1
Ciclos:
1
Ejemplo 1:
BTST.C W2, W3
; Establecer C = bit W3 de W2 
antes 
Instrucción
después
Instrucción
W2
F234
W2
F234
W3
2368
W3
2368
SR
0001 (C = 1)
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 156
© 2009 Microchip Technology Inc.
Ejemplo 2:
BTST.Z [W0++], W1
; Conjunto Z = complemento de 
; bit W1 en [W0], 
; W0 posterior al incremento
antes 
Instrucción
después
Instrucción
W0
1200
W0
1202
W1
CCC0
W1
CCC0
Datos 1200
6243
Datos 1200
6243
SR
0002 (Z = 1)
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 157
Sección 5. Descripciones de instrucciones
Instrucción 
Descripciones
5
    
BTSTS
Prueba de bits/Establecer f
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BTSTS{.B}
f,
#bit4
Operandos:
f ∈ [0 ... 8191] para operación de bytes
f ∈ [0 ... 8190] (solo pares) para operación de palabra
bit4 ∈ [0 ... 7] para operación de bytes
bit4 ∈ [0 ... 15] para operación de palabra
Operación:
(f)<bit4> → Z
1 → (f)<bit4>
Estado afectado:
z
Codificación:
1010
1100
bbbf
ffff
ffff
fffb
Descripción:
El bit ‘bit4’ en el registro de archivo ‘f’ se prueba y el complemento del bit probado se 
almacenado en el indicador Cero en el registro ESTADO. Luego se establece el bit probado 
a ‘1’ en el registro de archivos. Para el operando bit4, la numeración de bits comienza con 
el bit menos significativo (bit 0) y avanza al bit más significativo 
(bit 7 para operaciones de bytes, bit 15 para operaciones de palabras).
Los bits ‘b’ seleccionan el valor bit4, la posición del bit a probar/configurar.
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: Cuando esta instrucción opera en modo Word, el registro de archivo
la dirección debe estar alineada con las palabras.
3: Cuando esta instrucción opera en modo Byte, ‘bit4’ debe ser
entre 0 y 7.
4: El registro de archivo 'f' no debe ser el registro de estado de la CPU (SR).
Palabras:
1
Ciclos:
1
Ejemplo 1:
BTSTS.B 0x1201, #0x3
; Establezca Z = complemento del bit 3 en 0x1201, 
; luego configure el bit 3 de 0x1201 = 1
antes 
Instrucción
después
Instrucción
Datos 1200
F7FF
Datos 1200
FFFFF
SR
0000
SR
0002 (Z = 1)
Ejemplo 2:
BTSTS 0x808, #15
; Establezca Z = complemento del bit 15 en 0x808,
; luego configure el bit 15 de 0x808 = 1
antes 
Instrucción
después
Instrucción
RAM300
8050
RAM300
8050
SR
0002 (Z = 1) 
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 158
© 2009 Microchip Technology Inc.
  
BTSTS
Prueba de bits/establecido en Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
BTSTS.C
Ws,
#bit4
BTSTS.Z
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
bit4 ∈ [0 ... 15]
Operación:
Para funcionamiento “.C”:
    (Ws)<bit4> → C
    1 → Ws<bit4>
Para operación “.Z” (predeterminado):
    (Ws)<bit4> → Z
    1 → Ws<bit4>
Estado afectado:
Z o C
Codificación:
1010
0100
bbbb
Z000
0ppp
sss
Descripción:
Se prueba el bit ‘bit4’ del registro Ws. Si la opción “.Z” de la instrucción es 
especificado, el complemento del bit probado se almacena en el indicador Cero en el 
Registro de ESTADO. Si se especifica la opción “.C” de la instrucción, el valor 
del bit probado se almacena en el indicador de acarreo en el registro STATUS. en ambos 
En estos casos, el bit probado en Ws se establece en ‘1’.
Los bits ‘b’ seleccionan el valor bit4, la posición del bit a probar/configurar.
El bit 'Z' selecciona la bandera C o Z como destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: Esta instrucción solo funciona en modo Word. Si no hay extensión
siempre y cuando se suponga la operación “.Z”.
2: Si se utiliza Ws como puntero, no debe contener la dirección del
Registro de estado de la CPU (SR).
Palabras:
1
Ciclos:
1
Ejemplo 1:
BTSTS.C [W0++], #0x3
; Establezca C = bit 3 en [W0] 
; Configure el bit 3 en [W0] = 1
; W0 posterior al incremento
antes 
Instrucción
después
Instrucción
W0
1200
W0
1202
Datos 1200
FFF7
Datos 1200
FFFFF
SR
0001 (C = 1)
SR
0000
Ejemplo 2:
BTSTS.Z W0, #0x7
; Conjunto Z = complemento del bit 7 
; en W0 y establezca el bit 7 en W0 = 1
antes 
Instrucción
después
Instrucción
W0
F234
W0
F2BC
SR
0000
SR
0002 (Z = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 159
Instrucción 
Descripciones
5
  
LLAMADA
Llamar a subrutina
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
LLAMADA 
Expr.
Operandos:
Expr puede ser una etiqueta o expresión (pero no un literal).
Expr es resuelto por el enlazador a lit23, donde lit23 ∈ [0 ... 8388606].
Operación:
(PC) + 4 → PC
(PC<15:0>) → (TOS)
(W15) + 2 → W15
(PC<23:16>) → (TOS)
(W15) + 2 → W15
lit23 → ordenador personal 
NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
  1ra palabra
0000
0010
nnnn
nnnn
nnnn
nnn0
  2da palabra
0000
0000
0000
0000
0nnn
nnnn
Descripción:
Llamada directa a subrutina a través de todo el programa de instrucción de 4 Mbytes 
rango de memoria. Antes de realizar la LLAMADA, la dirección del remitente de 24 bits 
(PC + 4) se EMPUJA en la pila. Después de que la dirección del remitente sea 
apilados, el valor de 23 bits ‘lit23’ se carga en el PC.
Los bits ‘n’ forman la dirección de destino.
Nota:
El vinculador resolverá la expresión especificada en lit23 para
ser utilizado.
Palabras:
2
Ciclos:
2
Ejemplo 1:
026000 LLAMADA _FIR
026004 MOV W0, W1
   .           ...
   .           ...
026844 _FIR: MOV #0x400, W2
026846 ...       
; Llamar a la subrutina _FIR
; _Inicio de subrutina FIR
antes 
Instrucción
después 
Instrucción
ordenador personal
 02 6000
ordenador personal
02 6844
W15
    A268
W15
 A26C
Datos A268
 FFFFF
Datos A268
 6004
Datos A26A
 FFFFF
Datos A26A
 0002
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 160
© 2009 Microchip Technology Inc.
Ejemplo 2:
072000 LLAMADA _G66 ; rutina de llamada _G66
072004 MOV W0, W1
   .           ...
077A28 _G66: INC W6, [W7++]; inicio de rutina
077A2A ...
077A2C         
antes 
Instrucción
después 
Instrucción
ordenador personal
 07 2000
ordenador personal
07 7A28
W15
    9004
W15
9008
Datos 9004
 FFFFF
Datos 9004
 2004
Datos 9006
 FFFFF
Datos 9006
 0007
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 161
Instrucción 
Descripciones
5
 
LLAMADA
Llamar a subrutina indirecta 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
LLAMADA 
Wn
Operandos:
Wn ∈ [W0 ... W15]
Operación:
(PC) + 2 → PC
(PC<15:0>) → TOS
(W15) + 2 → W15
(PC<23:16>) → TOS
(W15) + 2 → W15
0 → PC<22:16>
(Wn<15:1>) → PC<15:1>
NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0000
0001
0000
0000
0000
sss
Descripción:
Llamada indirecta a subrutina sobre las primeras 32K instrucciones de la memoria del programa. 
Antes de realizar la LLAMADA, se PUSHed la dirección de retorno de 24 bits (PC + 2) 
en la pila. Después de apilar la dirección del remitente, se carga Wn<15:1> 
en PC<15:1> y PC<22:16> se borra. Dado que PC<0> es siempre ‘0’, 
Wn<0> se ignora.
Los bits ‘s’ seleccionan el registro fuente.
Palabras:
1
Ciclos:
2
Ejemplo 
1:
001002 LLAMADA W0
001004... 
   .           ...
001600 _ARRANQUE: MOV #0x400, W2
001602 MOV #0x300, W6
   .           ...
; Llamar a la subrutina BOOT indirectamente
; usando W0
; _BOOT comienza aquí
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 1002
ordenador personal
00 1600
W0
   1600
W0
1600
W15
    6F00
W15
6F04
Datos 6F00
 FFFFF
Datos 6F00
 1004
Datos 6F02
 FFFFF
Datos 6F02
 0000
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 162
© 2009 Microchip Technology Inc.
Ejemplo 2:
004200 LLAMADA W7
004202 ... 
   .           ...
005500 _PRUEBA: INC W1, W2
005502 DICIEMBRE W1, W3
   .           ...
; Llamar a la subrutina TEST indirectamente
; usando W7
; _La PRUEBA comienza aquí
;
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 4200
ordenador personal
00 5500
W7
    5500
W7
5500
W15
    6F00
W15
6F04
Datos 6F00
 FFFFF
Datos 6F00
 4202
Datos 6F02
 FFFFF
Datos 6F02
 0000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 163
Instrucción 
Descripciones
5
 
CLR
Borrar para WREG 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
ELIMINAR{.B} 
f
WREG
Operandos:
f ∈ [0 ... 8191] 
Operación:
0 → destino designado por D
Estado afectado:
Ninguno
Codificación:
1110
1111
0BDF
ffff
ffff
ffff
Descripción:
Borre el contenido de un registro de archivo o del registro de trabajo predeterminado WREG. 
Si se especifica WREG, se borra WREG. De lo contrario, el archivo especificado 
Se borra el registro ‘f’.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0. 
Palabras:
1
Ciclos:
1
Ejemplo 1:
CLR.B RAM200; Borrar RAM200 (modo Byte)
antes 
Instrucción
después
Instrucción
RAM200
8009
RAM200
8000
SR
0000
SR
0000
Ejemplo 2:
CLR WREG; Borrar WREG (modo Word)
antes 
Instrucción
después
Instrucción
WREG
0600
WREG
0000
SR
0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 164
© 2009 Microchip Technology Inc.
  
CLR
Borrar Wd
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
ELIMINAR{.B} 
Wd
[Wd]
[Wd++]
[Wd--]
[++Wd]
[--Wd]
Operandos:
Wd ∈ [W0 ... W15] 
Operación:
0 → Wd
Estado afectado:
Ninguno
Codificación:
1110
1011
0Bqq
qdddd
d000
0000
Descripción:
Borre el contenido del registro Wd. Ya sea registrarse directo o indirecto 
El direccionamiento se puede utilizar para Wd. 
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Nota:
La extensión .B en la instrucción denota una operación de byte. 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
CLR.B W2 ; Borrar W2 (modo Byte)
antes 
Instrucción
después
Instrucción
W2
3333
W2
3300
SR
0000
SR
0000
Ejemplo 2:
CLR [W0++]; Borrar [W0]
                  ; W0 posterior al incremento 
antes 
Instrucción
después
Instrucción
W0
2300
W0
2302
Datos 2300
5607
 Datos 2300
0000  
SR
0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 165
Instrucción 
Descripciones
5
  
CLR
Borrar acumulador, captación previa de operandos
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC30F
x
x
Sintaxis:            
{etiqueta:}
CLR
Acc
{,[Wx],Wxd}
{,[Wy],Wyd}
{,AWB}
{,[Wx] + = kx,Wxd} {,[Wy] + = ky,Wyd}
{,[Wx] – = kx,Wxd} {,[Wy] – = ky,Wyd}
{,[W9 + W12],Wxd} {,[W11 + W12],Wyd}
Operandos:
Acc ∈ [A,B]
Wx ∈ [W8, W9]; kx ∈ [-6, -4, -2, 2, 4, 6]; Wxd ∈ [W4 ... W7] 
Wy ∈ [W10, W11]; ky ∈ [-6, -4, -2, 2, 4, 6]; Wyd ∈ [W4 ... W7]
AWB ∈ [W13, [W13] + = 2]
Operación:
0 → Acc(A o B)
([Wx]) → Wxd; (Wx) +/– kx → Wx
([Wy]) → Wyd; (Wy) +/– ky → Wy
(Acc(B o A)) redondeado → AWB
Estado afectado:
OA, OB, SA, SB
Codificación:
1100
0011
A0xx
yyii
iijj
jjaa
Descripción:
Borrar los 40 bits del acumulador especificado, opcionalmente captar previamente 
operandos en preparación para una instrucción de tipo MAC y, opcionalmente, almacenar 
los resultados del acumulador no especificado. Esta instrucción borra las especificaciones
indicadores activos de desbordamiento y saturación (ya sea OA, SA u OB, SB).
Los operandos Wx, Wxd, Wy y Wyd especifican operaciones de captación previa opcionales. 
que admiten direccionamiento indirecto y de compensación de registro, como se describe en 
Sección 4.14.1 “Capturas previas de MAC”. El operando AWB especifica el opcional 
registrar el almacenamiento directo o indirecto del contenido redondeado convergentemente de 
el acumulador “otro”, como se describe en la Sección 4.14.4 “Escritura MAC 
Atrás”.
El bit ‘A’ selecciona el otro acumulador utilizado para la reescritura.
Los bits ‘x’ seleccionan el destino de captación previa Wxd.
Los bits ‘y’ seleccionan el destino Wyd de captación previa.
Los bits 'i' seleccionan la operación de captación previa de Wx.
Los bits 'j' seleccionan la operación de captación previa Wy.
Los bits ‘a’ seleccionan el destino de escritura posterior del acumulador.
Palabras:
1
Ciclos:
1

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 166
© 2009 Microchip Technology Inc.
Ejemplo 1:
BORRAR A, [W8]+=2, W4, W13
; Borrar ACCA
; Cargue W4 con [W8], post-inc W8
; Almacenar ACCB en W13
antes 
Instrucción
después 
Instrucción
W4
 F001
W4
   1221
W8
 2000
W8
   2002
W13
 C623
W13
   5420
ACCA
00 0067 2345
ACCA
00 0000 0000
ACCB
00 5420 3HAB
ACCB
00 5420 3HAB
Datos 2000
 1221
Datos 2000
 1221
SR
 0000
SR
 0000
Ejemplo 
2:
BORRAR B, [W8]+=2, W6, [W10]+=2, W7, [W13]+=2
; Borrar ACCB
; Cargue W6 con [W8]
; Cargue W7 con [W10]
; Guarde ACCA en [W13]
; Post-inc W8,W10,W13
antes 
Instrucción
después 
Instrucción
W6
 F001
W6
   1221
W7
 C783
W7
FF80
W8
 2000
W8
   2002
W10
 3000
W10
   3002
W13
 4000
W13
   4002
ACCA
00 0067 2345
ACCA
00 0067 2345
ACCB
00 5420 ABDD
ACCB
00 0000 0000
Datos 2000
 1221
Datos 2000
 1221
Datos 3000
 FF80
Datos 3000
 FF80
Datos 4000
FFC3
Datos 4000
 0067
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 167
Instrucción 
Descripciones
5
     
CLRWDT
Borrar temporizador de vigilancia
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CLRWDT
Operandos:
Ninguno
Operación:
0 → Registro de conteo WDT
0 → Conteo A del preescalador WDT
0 → Conteo B del preescalador WDT
Estado afectado:
Ninguno
Codificación:
1111
1110
0110
0000
0000
0000
Descripción:
Borre el contenido del registro de conteo del temporizador de vigilancia y el 
registros de conteo del preescalador. El Watchdog Prescaler A y Prescaler B 
Los ajustes, establecidos por los fusibles de configuración en el FWDT, no se modifican. 
Palabras:
1
Ciclos:
1
Ejemplo 1:
CLRWDT; Borrar temporizador de vigilancia
antes 
Instrucción
después
Instrucción
SR
0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 168
© 2009 Microchip Technology Inc.
  
 
COM
complemento f 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
COM{.B} 
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
f) → destino designado por D
Estado afectado:
norte, z
Codificación:
1110
1110
1HAB
ffff
ffff
ffff
Descripción:
Calcule el complemento a 1 del contenido del registro de archivos y coloque
el resultado en el registro de destino. El operando WREG opcional
determina el registro de destino. Si se especifica WREG, el resultado es
almacenado en WREG. Si no se especifica WREG, el resultado se almacena en el archivo
registrarse.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0. 
Palabras:
1
Ciclos:
1
Ejemplo 1:
COM.b RAM200; COM RAM200 (modo byte)
antes 
Instrucción
después
Instrucción
RAM200
80FF
RAM200
8000
SR
0000
SR
0002
(Z) 
Ejemplo 2:
COM RAM400, WREG; COM RAM400 y almacenar en WREG 
                        ; (modo palabra)
antes 
Instrucción
después
Instrucción
WREG
1211
WREG
F7DC
RAM400
0823
RAM400
0823
SR
0000
SR
0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 169
Instrucción 
Descripciones
5
  
COM
Complemento Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
COM{.B} 
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Ws) → Wd 
Estado afectado:
norte, z
Codificación:
1110
1010
1Bqq
qdddd
dppp
sss
Descripción:
Calcule el complemento a 1 del contenido del registro fuente Ws 
y coloque el resultado en el registro de destino Wd. O registrarse directamente o 
El direccionamiento indirecto se puede utilizar tanto para Ws como para Wd.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
COM.B [W0++], [W1++]
; COM [W0] y almacenar en [W1] (modo Byte)
; Post-incremento W0, W1
antes 
Instrucción
después
Instrucción
W0
2301
W0
2302
W1
2400
W1
2401
Datos 2300
5607
 Datos 2300
5607  
Datos 2400
ABCD
 Datos 2400
ABA9  
SR
0000
SR
0008 (n = 1)
Ejemplo 2:
COM W0, [W1++]
; COM W0 y almacenar en [W1] (modo Word)
; W1 posterior al incremento
antes 
Instrucción
después
Instrucción
W0
D004
W0
D004
W1
1000
W1
1002
Datos 1000
ABA9
 Datos 1000
2FFB  
SR
0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 170
© 2009 Microchip Technology Inc.
 
CP
Comparar f con WREG, establecer indicadores de estado 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CP{.B}  
f
Operandos:
f ∈ [0...8191]
Operación:
(f) – (WREG)
Estado afectado:
CC, N, OV, Z, C
Codificación: 
1110
0011
0B0f
ffff
ffff
ffff
Descripción:
Calcule (f) – (WREG) y actualice el registro STATUS. esta instrucción 
es equivalente a la instrucción SUBWF, pero el resultado de la resta es 
no almacenado. 
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0. 
Palabras:
1
Ciclos:
1
Ejemplo 1:
CP.B RAM400; Compare RAM400 con WREG (modo Byte)
antes 
Instrucción
después
Instrucción
WREG
8823
WREG
8823
RAM400
0823
RAM400
0823
SR
0000
SR
0002 (Z = 1)
Ejemplo 2:
CP 0x1200; Comparar (0x1200) con WREG (modo Word)
antes 
Instrucción
después
Instrucción
WREG
2377
WREG
2377
Datos 1200
2277
Datos 1200
2277
SR
0000
SR
0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 171
Instrucción 
Descripciones
5
 
CP
Comparar Wb con lit5, establecer indicadores de estado
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CP{.B} 
Wb,
#lit5
Operandos:
Wb ∈ [W0 ... W15]
iluminado5 ∈ [0 ... 31]
Operación:
(Wb) – lit5
Estado afectado:
CC, N, OV, Z, C
Codificación: 
1110
0001
0www
wB00
011k
kkkk
Descripción:
Calcule (Wb) – lit5 y actualice el registro ESTADO. Esta instrucción es 
equivalente a la instrucción SUB, pero el resultado de la resta no es 
almacenado. Se debe utilizar el direccionamiento directo de registro para Wb. 
Los bits ‘w’ seleccionan la dirección del registro base Wb.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘k’ proporcionan el operando literal, un número entero de cinco bits.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
CP.B W4, #0x12; Compare W4 con 0x12 (modo Byte)
                     
antes 
Instrucción
después
Instrucción
W4
7711
W4
7711
SR
0000
SR
0008 (n = 1)
Ejemplo 2:
CPW4, #0x12; Compare W4 con 0x12 (modo Word)
                     
antes 
Instrucción
después
Instrucción
W4
7713
W4
7713
SR
0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 172
© 2009 Microchip Technology Inc.
 
CP
Comparar Wb con Ws, establecer indicadores de estado
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CP{.B} 
Wb,
Ws
[Ws]
[Ws++]
[Ws--]
[++Preguntas]
[--Ws]
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15]
Operación:
(Wb) – (Ws)
Estado afectado:
CC, N, OV, Z, C
Codificación: 
1110
0001
0www
wB00
0ppp
sss
Descripción:
Calcule (Wb) – (Ws) y actualice el registro ESTADO. Esta instrucción es 
equivalente a la instrucción SUB, pero el resultado de la resta no es 
almacenado. Se debe utilizar el direccionamiento directo de registro para Wb. Regístrate directo o 
Se puede utilizar direccionamiento indirecto para Ws.
Los bits ‘w’ seleccionan la dirección del registro fuente Wb.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan la dirección del registro fuente Ws.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
CP.B W0, [W1++] ; Comparar [W1] con W0 (modo Byte)
                    ; W1 posterior al incremento
antes 
Instrucción
después
Instrucción
W0
ABA9
W0
ABA9
W1
2000
W1
2001
Datos 2000
D004
 Datos 2000
D004  
SR
0000
SR
0008 (n = 1)
Ejemplo 2:
CP W5, W6; Compara W6 con W5 (modo Word)
antes 
Instrucción
después
Instrucción
W5
2334
W5
2334
W6
8001
W6
8001
SR
0000
SR
000C (N, OV = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 173
Instrucción 
Descripciones
5
  
CP0
Compare f con 0x0, establezca indicadores de estado
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CP0{.B} 
f
Operandos:
f ∈ [0 ... 8191]
Operación:
(f) – 0x0
Estado afectado:
CC, N, OV, Z, C
Codificación: 
1110
0010
0B0f
ffff
ffff
ffff
Descripción:
Calcule (f) – 0x0 y actualice el registro ESTADO. El resultado de la 
la resta no se almacena. 
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte). 
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
CP0.B RAM100; Compare RAM100 con 0x0 (modo Byte)
antes 
Instrucción
después
Instrucción
RAM100
44C3
RAM100
44C3
SR
0000
SR
0008 (n = 1)
Ejemplo 2:
CP0 0x1FFE; Comparar (0x1FFE) con 0x0 (modo Word)
antes 
Instrucción
después
Instrucción
Datos 1FFE
0001
Datos 1FFE
0001
SR
0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 174
© 2009 Microchip Technology Inc.
  
CP0
Comparar Ws con 0x0, establecer indicadores de estado
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CP0{.B} 
Ws
[Ws]
[Ws++]
[Ws--]
[++Preguntas]
[--Ws]
Operandos:
Ws ∈ [W0 ... W15]
Operación:
(Ws) – 0x0000
Estado afectado:
CC, N, OV, Z, C
Codificación: 
1110
0000
0000
0B00
0ppp
sss
Descripción:
Calcule (Ws) – 0x0000 y actualice el registro ESTADO. El resultado de 
la resta no se almacena. Registrar direccionamiento directo o indirecto podrá ser 
utilizado para Ws.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan la dirección del registro fuente Ws.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
CP0.B [W4--]; Comparar [W4] con 0 (modo Byte)
                  ; W4 posterior a la disminución
antes 
Instrucción
después
Instrucción
W4
1001
W4
1000
Datos 1000
0034
Datos 1000
0034
SR
0000
SR
0002 (Z = 1)
Ejemplo 2:
CP0 [--W5] ; Comparar [--W5] con 0 (modo Word)
                      
antes 
Instrucción
después
Instrucción
W5
2400
W5
23FE
Datos 23FE
9000
Datos 23FE
9000
SR
0000
SR
0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 175
Instrucción 
Descripciones
5
  
CPB
Compare f con WREG usando Préstamo, Establecer indicadores de estado
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CPB{.B} 
f
Operandos:
f ∈ [0...8191]
Operación:
(f) – (WREG) – (C)
Estado afectado:
CC, N, OV, Z, C
Codificación: 
1110
0011
1B0f
ffff
ffff
ffff
Descripción:
Calcule (f) – (WREG) – (C) y actualice el registro STATUS. esto 
instrucción es equivalente a la instrucción SUBB, pero el resultado de la 
la resta no se almacena. 
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0. 
3: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
CPB.B RAM400; Compare RAM400 con WREG usando C (modo Byte)
antes 
Instrucción
después
Instrucción
WREG
8823
WREG
8823
RAM400
0823
RAM400
0823
SR
0000
SR
0008 (n = 1)
Ejemplo 2:
CPB 0x1200; Comparar (0x1200) con WREG usando C (modo Word)
antes 
Instrucción
después
Instrucción
WREG
2377
WREG
2377
Datos 1200
2377
Datos 1200
2377
SR
0001 (C = 1) 
SR
0001 (C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 176
© 2009 Microchip Technology Inc.
  
CPB
Compare Wb con lit5 usando Préstamo, Establezca indicadores de estado
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CPB{.B} 
Wb,
#lit5
Operandos:
Wb ∈ [W0 ... W15]
iluminado5 ∈ [0 ... 31]
Operación:
(Wb) – lit5 – (C)
Estado afectado:
CC, N, OV, Z, C
Codificación: 
1110
0001
1www
wB00
011k
kkkk
Descripción:
Calcule (Wb) – lit5 – (C) y actualice el registro ESTADO. esto 
instrucción es equivalente a la instrucción SUBB, pero el resultado de la 
la resta no se almacena. Se debe utilizar el direccionamiento directo de registro para Wb. 
Los bits ‘w’ seleccionan la dirección del registro fuente Wb.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘k’ proporcionan el operando literal, un número entero de cinco bits.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
CPB.B W4, #0x12; Compare W4 con 0x12 usando C (modo Byte)
                     
antes 
Instrucción
después
Instrucción
W4
7711
W4
7711
SR
0001 (C = 1) 
SR
0008 (n = 1)
Ejemplo 2:
CPB.B W4, #0x12; Compare W4 con 0x12 usando C (modo Byte)
                     
antes 
Instrucción
después
Instrucción
W4
7711
W4
7711
SR
0000
SR
0008 (n = 1)
Ejemplo 3:
CPB W12, #0x1F; Compare W12 con 0x1F usando C (modo Word)
                     
antes 
Instrucción
después
Instrucción
W12
0020
W12
0020
SR
0002 (Z = 1)
SR
0003 (Z,C=1)
Ejemplo 4:
CPB W12, #0x1F; Compare W12 con 0x1F usando C (modo Word)
                     
antes 
Instrucción
después
Instrucción
W12
0020
W12
0020
SR
0003 (Z,C=1)
SR
0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 177
Instrucción 
Descripciones
5
 
CPB
Compare Ws con Wb usando Préstamo, establezca indicadores de estado
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CPB{.B} 
Wb,
Ws
[Ws]
[Ws++]
[Ws--]
[++Preguntas]
[--Ws]
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15]
Operación:
(Wb) – (Ws) – (C)
Estado afectado:
CC, N, OV, Z, C
Codificación: 
1110
0001
1www
wB00
0ppp
sss
Descripción:
Calcule (Wb) – (Ws) – (C) y actualice el registro ESTADO. esto 
instrucción es equivalente a la instrucción SUBB, pero el resultado de la 
la resta no se almacena. Se debe utilizar el direccionamiento directo de registro para Wb. 
Se puede utilizar el direccionamiento directo o indirecto del registro para Ws.
Los bits ‘w’ seleccionan la dirección del registro fuente Wb.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan la dirección del registro fuente Ws.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
CPB.B W0, [W1++]
; Compare [W1] con W0 usando C (modo Byte)
; W1 posterior al incremento
antes 
Instrucción
después
Instrucción
W0
ABA9
W0
ABA9
W1
1000
W1
1001
Datos 1000
D0A9
 Datos 1000
D0A9  
SR
0002 (Z = 1) 
SR
0008 (n = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 178
© 2009 Microchip Technology Inc.
Ejemplo 2:
CPB.B W0, [W1++]
; Compare [W1] con W0 usando C (modo Byte)
; W1 posterior al incremento
antes 
Instrucción
después
Instrucción
W0
ABA9
W0
ABA9
W1
1000
W1
1001
Datos 1000
D0A9
 Datos 1000
D0A9  
SR
0001 (C = 1) 
SR
0001 (C = 1)
Ejemplo 3:
CPB W4, W5; Compare W5 con W4 usando C (modo Word)
                     
antes 
Instrucción
después
Instrucción
W4
4000
W4
4000
W5
3000
W5
3000
SR
0001 (C = 1) 
SR
0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 179
Instrucción 
Descripciones
5
 
CPSEQ 
Compare Wb con Wn, omita si es igual (Wb = Wn)
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CPSEQ{.B} Wb,
Wn
Operandos:
Wb ∈ [W0 ... W15]
Wn ∈ [W0 ... W15]
Operación:
(Wb) – (Wn)
Saltar si (Wb) = (Wn)
Estado afectado:
Ninguno
Codificación:
1110
0111
1www
wB00
0000
sss
Descripción:
Compare el contenido de Wb con el contenido de Wn realizando el 
resta (Wb) – (Wn), pero no almacena el resultado. Si (Wb) = (Wn), el 
La siguiente instrucción (obtenida durante la ejecución de la instrucción actual) es 
descartado y en el siguiente ciclo, en su lugar se ejecuta un NOP. si 
(Wb) ≠ (Wn), la siguiente instrucción se ejecuta normalmente.
Los bits ‘w’ seleccionan la dirección del registro fuente Wb.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘s’ seleccionan la dirección del registro fuente Ws.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1 (2 o 3 si se omite)
Ejemplo 1:
002000 AQUÍ:CPSEQ.BW0, W1; Si W0 = W1 (modo Byte),
002002GOTOBYPASS; salta el IR A
002004
. . .
002006
. . .
002008 ANULACIÓN: . . .
00200A
. . .
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
W0
1001
W0
1001
W1
    1000
W1
1000
SR
 0000
SR
 0000
Ejemplo 2:
018000 AQUÍ: CPSEQ W4, W8; Si W4 = W8 (modo Palabra),
018002 LLAMADA _FIR; saltar la llamada de subrutina
018006 ...
018008...
antes 
Instrucción
después 
Instrucción
ordenador personal
 01 8000
ordenador personal
01 8006
W4
3344
W4
3344
W8
3344
W8
3344
SR
 0002 (Z = 1)
SR
 0002 (Z = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 180
© 2009 Microchip Technology Inc.
  
CPSGT
Comparar con signo Wb con Wn, omitir si es mayor que (Wb > Wn)
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CPSGT{.B} 
Wb,
Wn
Operandos:
Wb ∈ [W0 ... W15]
Wn ∈ [W0 ... W15]
Operación:
(Wb) – (Wn)
Saltar si (Wb) > (Wn)
Estado afectado:
Ninguno
Codificación:
1110
0110
0www
wB00
0000
sss
Descripción:
Compare el contenido de Wb con el contenido de Wn realizando el 
resta (Wb) – (Wn), pero no almacena el resultado. Si (Wb) > (Wn), el 
La siguiente instrucción (obtenida durante la ejecución de la instrucción actual) es 
descartado y en el siguiente ciclo, en su lugar se ejecuta un NOP. De lo contrario, 
la siguiente instrucción se ejecuta normalmente.
Los bits ‘w’ seleccionan la dirección del registro fuente Wb.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘s’ seleccionan la dirección del registro fuente Ws.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1 (2 o 3 si se omite)
Ejemplo 1:
002000 AQUÍ: CPSGT.B W0, W1; Si W0 > W1 (modo Byte),
002002 IR A ANULAR; salta el IR A
002006. . .
002008. . .
00200A ANULACIÓN . . .
00200C. . .
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2006
W0
00FF
W0
00FF
W1
    26FE
W1
 26FE
SR
 0009 (N,C=1)
SR
 0009 (N,C=1)
Ejemplo 2:
018000 AQUÍ: CPSGT W4, W5; Si W4 > W5 (modo Word),
018002 LLAMADA _FIR; saltar la llamada de subrutina
018006 ...
018008...
antes 
Instrucción
después 
Instrucción
ordenador personal
 01 8000
ordenador personal
01 8002
W4
2600
W4
2600
W5
2600
W5
2600
SR
 0004 (OV = 1)
SR
 0004 (OV = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 181
Instrucción 
Descripciones
5
  
CPSLT
Comparar con signo Wb con Wn, omitir si es menor que (Wb < Wn)
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CPSLT{.B} 
Wb,
Wn
Operandos:
Wb ∈ [W0 ... W15]
Wn ∈ [W0 ... W15]
Operación:
(Wb) – (Wn)
Saltar si (Wb) < (Wn)
Estado afectado:
Ninguno
Codificación:
1110
0110
1www
wB00
0000
sss
Descripción:
Compare el contenido de Wb con el contenido de Wn realizando el 
resta (Wb) – (Wn), pero no almacena el resultado. Si (Wb) < (Wn), el 
La siguiente instrucción (obtenida durante la ejecución de la instrucción actual) es 
descartado y en el siguiente ciclo, en su lugar se ejecuta un NOP. De lo contrario, el 
La siguiente instrucción se ejecuta normalmente.
Los bits ‘w’ seleccionan la dirección del registro fuente Wb.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘s’ seleccionan la dirección del registro fuente Ws.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1 (2 o 3 si se omite)
Ejemplo 1:
002000 AQUÍ: CPSLT.B W8, W9; Si W8 < W9 (modo Byte),
002002 IR A ANULAR; salta el IR A
002006. . .
002008. . .
00200A ANULACIÓN: . . .
00200C. . .
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
W8
00FF
W8
00FF
W9
    26FE
W9
 26FE
SR
 0008 (n = 1)
SR
 0008 (n = 1)
Ejemplo 2:
018000 AQUÍ: CPSLT W3, W6; Si W3 < W6 (modo Palabra),
018002 LLAMADA _FIR; saltar la llamada de subrutina
018006. . .
018008. . .
antes 
Instrucción
después 
Instrucción
ordenador personal
 01 8000
ordenador personal
01 8006
W3
2600
W3
2600
W6
3000
W6
3000
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 182
© 2009 Microchip Technology Inc.
  
CPSNE
Con signo Comparar Wb con Wn, omitir si no es igual (Wb ≠ Wn)
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CPSNE{.B} Wb,
Wn
Operandos:
Wb ∈ [W0 ... W15]
Wn ∈ [W0 ... W15]
Operación:
(Wb) – (Wn)
Saltar si (Wb) ≠ (Wn)
Estado afectado:
Ninguno
Codificación:
1110
0111
0www
wB00
0000
sss
Descripción:
Compare el contenido de Wb con el contenido de Wn realizando el 
resta (Wb) – (Wn), pero no almacena el resultado. Si (Wb) ≠ (Wn), el siguiente 
La instrucción (obtenida durante la ejecución de la instrucción actual) se descarta. 
y en el siguiente ciclo, en su lugar se ejecuta un NOP. De lo contrario, la próxima 
La instrucción se ejecuta normalmente.
Los bits ‘w’ seleccionan la dirección del registro fuente Wb.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘s’ seleccionan la dirección del registro fuente Ws.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1 (2 o 3 si se omite)
Ejemplo 1:
002000 AQUÍ: CPSNE.B W2, W3; Si W2 != W3 (modo Byte),
002002 IR A ANULAR ; salta el IR A
002006. . .
002008. . .
00200A ANULACIÓN: . . .
00200C. . .
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2006
W2
00FF
W2
00FF
W3
    26FE
W3
 26FE
SR
 0001 (C = 1)
SR
 0001 (C = 1)
Ejemplo 2:
018000 AQUÍ: CPSNE W0, W8; Si W0 != W8 (modo Palabra),
018002 LLAMADA _FIR; saltar la llamada de subrutina
018006 ...
018008...
antes 
Instrucción
después 
Instrucción
ordenador personal
 01 8000
ordenador personal
01 8002
W0
3000
W0
3000
W8
3000
W8
3000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 183
Instrucción 
Descripciones
5
     
DAW.B
Ajuste decimal Wn
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
DAW.B
Wn
Operandos:
Wn ∈ [W0 ... W15]
Operación:
Si (Wn<3:0> > 9) o (DC = 1)
    (Wn<3:0>) + 6 → Wn<3:0>
más 
    (Wn<3:0>) → Wn<3:0>
Si (Wn<7:4> > 9) o (C = 1)
    (Wn<7:4>) + 6 → Wn<7:4>
más 
    (Wn<7:4>) → Wn<7:4> 
Estado afectado:
c
Codificación:
1111
1101
0100
0000
0000
sss
Descripción:
Ajuste el byte menos significativo en Wn para producir un decimal codificado en binario 
(BCD) resultado. El byte más significativo de Wn no se modifica y el 
La bandera de acarreo se utiliza para indicar cualquier rollover decimal. Regístrate directo 
El direccionamiento debe usarse para Wn.
Los bits ‘s’ seleccionan el registro de origen/destino.
Nota 1: Esta instrucción se utiliza para corregir el formato de datos después de dos
Se han agregado bytes BCD empaquetados.
2: Esta instrucción funciona solo en modo Byte y el .B
La extensión debe incluirse con el código de operación.
Palabras:
1
Ciclos:
1
Ejemplo 1:
DAW.B W0; Ajuste decimal W0
                     
antes 
Instrucción
después
Instrucción
W0
771A
W0
7720
SR
0002 (CC = 1)
SR
0002 (CC = 1)
Ejemplo 2:
DAW.BW3; Ajuste decimal W3
                     
antes 
Instrucción
después
Instrucción
W3
77AA
W3
7710
SR
0000
SR
0001 (C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 184
© 2009 Microchip Technology Inc.
  
 
DIC
decremento f 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
DIC{.B} 
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
f) – 1 → destino designado por D
Estado afectado:
CC, N, OV, Z, C
Codificación:
1110
1101
0BDF
ffff
ffff
ffff
Descripción:
Reste uno del contenido del registro del archivo y coloque el resultado en el
registro de destino. El operando WREG opcional determina el
registro de destino. Si se especifica WREG, el resultado se almacena en WREG. si
WREG no se especifica, el resultado se almacena en el registro del archivo.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0. 
Palabras:
1
Ciclos:
1
Ejemplo 1:
DIC.B 0x200 ; Decremento (0x200) (modo Byte)
antes 
Instrucción
después
Instrucción
Datos 200
80FF
Datos 200
80FE
SR
0000
SR
0009
(norte, C = 1) 
Ejemplo 2:
DEC RAM400, WREG
; Disminuir RAM400 y almacenar en WREG 
; (modo palabra)
antes 
Instrucción
después
Instrucción
WREG
1211
WREG
0822
RAM400
0823
RAM400
0823
SR
0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 185
Instrucción 
Descripciones
5
  
DIC
Decremento Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
DIC{.B} 
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Ws) – 1 → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
1110
1001
0Bqq
qdddd
dppp
sss
Descripción:
Reste uno del contenido del registro fuente Ws y coloque el 
resulta en el registro de destino Wd. Ya sea registrarse directo o indirecto 
El direccionamiento puede ser utilizado por Ws y Wd.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte. 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
DEC.B [S7++], [S8++] ; DEC [W7] y almacenar en [W8] (modo Byte)
                        ; Post-incremento W7, W8
antes 
Instrucción
después
Instrucción
W7
2301
W7
2302
W8
2400
W8
2401
Datos 2300
5607
 Datos 2300
5607  
Datos 2400
ABCD
 Datos 2400
AB55  
SR
0000
SR
0000
Ejemplo 2:
DIC W5, [W6++]; Disminuya W5 y almacene en [W6] (modo Palabra)
                  ; W6 posterior al incremento
antes 
Instrucción
después
Instrucción
W5
D004
W5
D004
W6
2000
W6
2002
Datos 2000
ABA9
 Datos 2000
D003  
SR
0000
SR
0009 (N,C=1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 186
© 2009 Microchip Technology Inc.
  
 
DIC2
Disminuir f en 2
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
DIC2{.B}
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
f) – 2 → destino designado por D 
Estado afectado:
CC, N, OV, Z, C
Codificación:
1110
1101
1HAB
ffff
ffff
ffff
Descripción:
Reste dos del contenido del registro del archivo y coloque el resultado en el
registro de destino. El operando WREG opcional determina el
registro de destino. Si se especifica WREG, el resultado se almacena en WREG. si
WREG no se especifica, el resultado se almacena en el registro del archivo.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota:
La extensión .B en la instrucción denota una operación de byte. 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
DEC2.B 0x200; Disminuir (0x200) en 2 (modo Byte)
antes 
Instrucción
después
Instrucción
Datos 200
80FF
Datos 200
80FD
SR
0000
SR
0009
(norte, C = 1) 
Ejemplo 2:
DEC2 RAM400, WREG; Disminuir RAM400 en 2 y
                       ; almacenar en WREG (modo Word)
antes 
Instrucción
después
Instrucción
WREG
1211
WREG
0821
RAM400
0823
RAM400
0823
SR
0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 187
Instrucción 
Descripciones
5
  
DIC2
Disminuir Ws en 2
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
DIC2{.B}
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Ws) – 2 → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
1110
1001
1Bqq
qdddd
dppp
sss
Descripción:
Reste dos del contenido del registro fuente Ws y coloque el 
resulta en el registro de destino Wd. Ya sea registrarse directo o indirecto 
El direccionamiento puede ser utilizado por Ws y Wd.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte. 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
DEC2.B [S7--], [S8--]; DEC [W7] por 2, almacenar en [W8] (modo Byte)
; Post-decremento W7, W8
antes 
Instrucción
después
Instrucción
W7
2301
W7
2300
W8
2400
W8
23FF
Datos 2300
0107
 Datos 2300
0107  
Datos 2400
ABCD
 Datos 2400
ABFF  
SR
0000
SR
0008 (n = 1)
Ejemplo 2:
DIC2 S5, [S6++]
; DEC W5 por 2, almacenar en [W6] (modo Word)
; W6 posterior al incremento
antes 
Instrucción
después
Instrucción
W5
D004
W5
D004
W6
1000
W6
1002
Datos 1000
ABA9
 Datos 1000
D002  
SR
0000
SR
0009 (N,C=1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 188
© 2009 Microchip Technology Inc.
  
 
DISI
Deshabilitar las interrupciones temporalmente
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
DISI
#lit14
Operandos:
iluminado14 ∈ [0 ... 16383]
Operación:
lit14 → DISICNT
1 → DISI 
Deshabilitar interrupciones para (lit14 + 1) ciclos
Estado afectado:
Ninguno
Codificación:
1111
1100
00kk
kkkk
kkkk
kkkk
Descripción:
Deshabilite las interrupciones de prioridad 0 a 6 para la instrucción (lit14 + 1) 
ciclos. Las interrupciones de prioridad 0 a 6 se desactivan a partir del 
ciclo que ejecuta DISI y permanecerá deshabilitado durante los siguientes (iluminado 14) ciclos. 
El valor lit14 se escribe en el registro DISICNT y el indicador DISI 
(INTCON2<14>) se establece en ‘1’. Esta instrucción se puede utilizar antes 
ejecutar código de tiempo crítico, para limitar los efectos de las interrupciones.
Nota:
Esta instrucción no evita interrupciones y trampas de prioridad 7.
de correr. Consulte el manual de referencia de la familia de dispositivos específica
para más detalles.
Palabras:
1
Ciclos:
1
Ejemplo 1:
002000 AQUÍ: DISI #100; Deshabilitar interrupciones durante 101 ciclos.
002002; próximos 100 ciclos protegidos por DISI
002004. . .
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2002
DISICTO
 0000
DISICTO
 0100
INTCON2
 0000
 INTCON2
 4000 (DISI = 1)
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 189
Instrucción 
Descripciones
5
  
DIV.S
División entera con signo
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
DIV.S{W}
Wm, Wn
DIV.SD
Wm, Wn
Operandos:
Wm ∈ [W0 ... W15] para operación de palabra
Wm ∈ [W0, W2, W4 ... W14] para funcionamiento doble
Wn ∈ [W2 ... W15]
Operación:
Para operación de palabra (predeterminado):
    Wm → W0
    Si (Wm<15> = 1):
        0xFFFF → W1
    Más:
        0x0 → W1
    W1:W0 / Wn → W0
    Resto → W1
Para operación doble (DIV.SD):
    Wm + 1:Wm → W1:W0
    W1:W0 / Wn → W0
    Resto → W1
Estado afectado:
N, OV, Z, C
Codificación:
1101
1000
0ttt
tvvv
vW00
sss
Descripción:
División entera iterativa con signo, donde el dividendo se almacena en Wm (para un 
división de 16 bits por 16 bits) o Wm + 1:Wm (para una división de 32 bits por 16 bits) y 
el divisor se almacena en Wn. En la operación de palabra predeterminada, Wm es primero 
copiado a W0 y firmado extendido a través de W1 para realizar la operación. en 
la operación doble, Wm + 1:Wm se copia primero a W1:W0. los 16 bits 
El cociente de la operación de división se almacena en W0 y el resto de 16 bits. 
se almacena en W1. 
Esta instrucción debe ejecutarse 18 veces usando la instrucción REPEAT. 
(con un recuento de iteraciones de 17) para generar el cociente correcto y 
resto. La bandera N se establecerá si el resto es negativo y se borra 
de lo contrario. El indicador OV se establecerá si la operación de división resultó en una 
desbordamiento y se borra en caso contrario. La bandera Z se establecerá si el resto es 
‘0’ y se borra en caso contrario. La bandera C se utiliza para implementar la división. 
El algoritmo y su valor final no deben usarse. 
Los bits ‘t’ seleccionan la palabra más significativa del dividendo para el doble 
operación. Estos bits son claros para la palabra operación.
Los bits ‘v’ seleccionan la palabra menos significativa del dividendo.
El bit ‘W’ selecciona el tamaño del dividendo (‘0’ para 16 bits, ‘1’ para 32 bits).
Los bits ‘s’ seleccionan el registro divisor.
Nota 1: La extensión .D en la instrucción denota una palabra doble
dividendo (32 bits) en lugar de una palabra dividendo. Puedes usar un
Extensión .W para indicar una operación de palabra, pero no es obligatoria.
2: Se producirán resultados inesperados si el cociente no se puede
representado en 16 bits. Cuando esto ocurre para el doble
operación (DIV.SD), el bit de estado OV se establecerá y el
No se deben utilizar el cociente y el resto. por la palabra
operación (DIV.S), sólo puede ocurrir un tipo de desbordamiento
(0x8000/0xFFFF = + 32768 o 0x00008000), lo que permite
Bit de estado OV para interpretar el resultado.
3: Dividir por cero iniciará una trampa de error aritmético durante el
primer ciclo de ejecución.
4: Esta instrucción es interrumpible en cada ciclo de instrucción.
límite.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 190
© 2009 Microchip Technology Inc.
Palabras:
1
Ciclos:
18 (más 1 para la ejecución de REPETIR)
Ejemplo 1:
REPITE #17; Ejecute DIV.S 18 veces
DIV.S W3, W4; Divida W3 por W4
                 ; Almacene el cociente en W0, el resto en W1
antes 
Instrucción
después
Instrucción
W0
5555
W0
013B
W1
1234
W1
0003
W3
3000
W3
3000  
W4
0027
W4
0027  
SR
0000
SR
0000  
Ejemplo 2:
REPITE #17; Ejecute DIV.SD 18 veces
DIV.SD W0, W12 ; Divida W1:W0 por W12
                 ; Almacene el cociente en W0, el resto en W1
antes 
Instrucción
después
Instrucción
W0
2500
W0
FA6B
W1
FF42
W1
EF00
W12
2200
W12
2200  
SR
0000
SR
0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 191
Instrucción 
Descripciones
5
  
DIV.U
División entera sin signo
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
DIV.U{W}
Wm, Wn
DIV.UD
Wm, Wn
Operandos:
Wm ∈ [W0 ... W15] para operación de palabra
Wm ∈ [W0, W2, W4 ... W14] para funcionamiento doble
Wn ∈ [W2 ... W15]
Operación:
Para operación de palabra (predeterminado):
    Wm → W0
    0x0 → W1
    W1:W0/Wn → W0
    Resto → W1
Para operación doble (DIV.UD):
    Wm + 1:Wm → W1:W0
    W1:W0/Wns → W0
    Resto → W1
Estado afectado:
N, OV, Z, C
Codificación:
1101
1000
1ttt
tvvv
vW00
sss
Descripción:
División entera iterativa y sin signo, donde el dividendo se almacena en Wm (por ejemplo 
una división de 16 bits por 16 bits), o Wm + 1:Wm (para una división de 32 bits por 16 bits) y 
el divisor se almacena en Wn. En la operación de palabras, Wm se copia primero a W0 
y W1 tiene autorización para realizar la división. En la doble operación, 
Wm + 1:Wm se copia primero en W1:W0. El cociente de la división de 16 bits 
La operación se almacena en W0 y el resto de 16 bits se almacena en W1.
Esta instrucción debe ejecutarse 18 veces usando la instrucción REPEAT. 
(con un recuento de iteraciones de 17) para generar el cociente correcto y 
resto. La bandera N siempre se borrará. La bandera OV se establecerá si el 
La operación de división resultó en un desbordamiento y se borró en caso contrario. La bandera Z 
se establecerá si el resto es ‘0’ y se borrará en caso contrario. Se utiliza la bandera C. 
para implementar el algoritmo de división y no se debe utilizar su valor final.
Los bits ‘t’ seleccionan la palabra más significativa del dividendo para el doble 
operación. Estos bits son claros para la palabra operación.
Los bits ‘v’ seleccionan la palabra menos significativa del dividendo.
El bit ‘W’ selecciona el tamaño del dividendo (‘0’ para 16 bits, ‘1’ para 32 bits).
Los bits ‘s’ seleccionan el registro divisor.
Nota 1: La extensión .D en la instrucción denota una palabra doble
dividendo (32 bits) en lugar de una palabra dividendo. Puedes usar un .W
extensión para denotar una operación de palabra, pero no es obligatoria.
2: Se producirán resultados inesperados si el cociente no se puede
representado en 16 bits. Esto sólo puede ocurrir para el doble
operación (DIV.UD). Cuando se produce un desbordamiento, el estado de OV
se establecerá el bit y el cociente y el resto no deben ser
usado. 
3: Dividir por cero iniciará una trampa de error aritmético durante el
primer ciclo de ejecución.
4: Esta instrucción es interrumpible en cada ciclo de instrucción.
límite.
Palabras:
1
Ciclos:
18 (más 1 para la ejecución de REPETIR)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 192
© 2009 Microchip Technology Inc.
Ejemplo 1:
REPITE #17; Ejecute DIV.U 18 veces
DIV.U W2, W4; Divida W2 por W4
                 ; Almacene el cociente en W0, el resto en W1
antes 
Instrucción
después
Instrucción
W0
5555
W0
0040
W1
1234
W1
0000
W2
8000
W2
8000  
W4
0200
W4
0200  
SR
0000
SR
0002 (Z = 1)
Ejemplo 2:
REPITE #17; Ejecute DIV.UD 18 veces
DIV.UD W10, W12; Divida W11:W10 por W12
                  ; Almacene el cociente en W0, el resto en W1
antes 
Instrucción
después
Instrucción
W0
5555
W0
01F2
W1
1234
W1
0100
W10
2500
W10
2500  
W11
0042
W11
0042  
W12
2200
W12
2200  
SR
0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 193
Instrucción 
Descripciones
5
  
DIVF
División fraccionaria
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:} 
DIVF
Wm, Wn
Operandos:
Wm ∈ [W0 ... W15]
Wn ∈ [W2 ... W15]
Operación:
0x0 → W0
Wm → W1
W1:W0/Wn → W0
Resto → W1
Estado afectado:
N, OV, Z, C
Codificación:
1101
1001
0ttt
t000
0000
sss
Descripción:
División iterativa, fraccionaria con signo de 16 bits por 16 bits, donde el dividendo es 
almacenado en Wm y el divisor se almacena en Wn. Para realizar la operación, 
Primero se borra W0 y se copia Wm a W1. El cociente de 16 bits de la 
La operación de división se almacena en W0 y el resto de 16 bits se almacena en W1. 
El signo del resto será el mismo que el signo del dividendo.
Esta instrucción debe ejecutarse 18 veces usando la instrucción REPEAT. 
(con un recuento de iteraciones de 17) para generar el cociente correcto y 
resto. La bandera N se establecerá si el resto es negativo y se borra 
de lo contrario. El indicador OV se establecerá si la operación de división resultó en una 
desbordamiento y se borra en caso contrario. La bandera Z se establecerá si el resto es 
‘0’ y se borra en caso contrario. La bandera C se utiliza para implementar la división. 
El algoritmo y su valor final no deben usarse. 
Los bits ‘t’ seleccionan el registro de dividendos.
Los bits ‘s’ seleccionan el registro divisor.
Nota 1: Para que la división fraccionaria sea efectiva, Wm debe ser menor que
Wn. Si Wm es mayor o igual que Wn, resultados inesperados
ocurrirá porque el resultado fraccionario será mayor o
igual a 1,0. Cuando esto ocurre, el bit de estado OV se establecerá y
no se debe utilizar el cociente y el resto.
2: Dividir por cero iniciará una trampa de error aritmético durante la
primer ciclo de ejecución.
3: Esta instrucción es interrumpible en cada ciclo de instrucción.
límite.
Palabras:
1
Ciclos:
18 (más 1 para la ejecución de REPETIR)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 194
© 2009 Microchip Technology Inc.
Ejemplo 1:
REPITE #17; Ejecute DIVF 18 veces
DIVF W8, W9; Divida W8 por W9
                  ; Almacene el cociente en W0, el resto en W1
antes 
Instrucción
después
Instrucción
W0
8000
W0
2000
W1
1234
W1
0000
W8
1000
W8
1000
W9
4000
W9
4000  
SR
0000
SR
0002 (Z = 1)
Ejemplo 2:
REPITE #17; Ejecute DIVF 18 veces
DIVF W8, W9; Divida W8 por W9
                 ; Almacene el cociente en W0, el resto en W1
antes 
Instrucción
después
Instrucción
W0
8000
W0
F000
W1
1234
W1
0000
W8
1000
W8
1000
W9
8000
W9
8000  
SR
0000
SR
0002 (Z = 1)
Ejemplo 3:
REPITE #17; Ejecute DIVF 18 veces
DIVF W0, W1; Divida W0 por W1
                 ; Almacene el cociente en W0, el resto en W1
antes 
Instrucción
después
Instrucción
W0
8002
W0
7FFE
W1
8001
W1
8002
SR
0000
SR
0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 195
Instrucción 
Descripciones
5
  
HACER
Inicializar literal de bucle de hardware
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:} 
HACER 
#lit14,
Expr.
Operandos:
iluminado14 ∈ [0 ... 16383]
Expr puede ser una dirección, etiqueta o expresión absoluta.
Expr es resuelto por el enlazador a Slit16, donde Slit16 ∈ [-32768 ... +32767].
Operación:
PUSH DO sombras (DCOUNT, DOEND, DOSTART)
(lit14) → DCONTAR
(PC) + 4 → PC
(PC) → INICIAR
(PC) + (2 * Rendija16) → DOEND
Incremento DL<2:0> (CORCON<10:8>)
Estado afectado:
DA
Codificación:
0000
1000
00kk
kkkk
kkkk
kkkk
0000
0000
nnnn
nnnn
nnnn
nnnn
Descripción:
Inicia un bucle DO de hardware sin gastos generales, que se ejecuta (lit14 + 1) 
veces. El bucle DO comienza en la dirección que sigue a la instrucción DO y 
termina en la dirección a 2 * Rendija16 palabras de instrucción de distancia. El conteo de 14 bits 
El valor (lit14) admite un valor máximo de recuento de bucles de 16384, y el valor de 16 bits 
El valor de compensación (Slit16) admite compensaciones de palabras de instrucción de 32 K en ambos 
direcciones.
Cuando se ejecuta esta instrucción, DCOUNT, DOSTART y DOEND son los primeros 
EMPUJADOS en sus respectivos registros de sombra y luego actualizados con el 
nuevos parámetros del bucle DO especificados por la instrucción. El recuento del nivel de OD, 
Luego se incrementa DL<2:0> (CORCON<8:10>). Después del ciclo DO 
completa la ejecución, PUSHed DCOUNT, DOSTART y DOEND 
Los registros se restauran y DL<2:0> disminuye.
Los bits 'k' especifican el recuento de bucles.
Los bits ‘n’ son un literal con signo que especifica el número de instrucciones 
desplazamiento desde la PC hasta la última instrucción ejecutada en el bucle.
Características especiales, restricciones:
Las siguientes características y restricciones se aplican a la instrucción DO.
1.
El uso de un recuento de bucle de ‘0’ dará como resultado que el bucle se ejecute un
tiempo.
2.
Usar un tamaño de bucle de -2, -1 o 0 no es válido. Los resultados inesperados pueden
ocurrirán si se utilizan estas compensaciones.
3.
Las dos últimas instrucciones del bucle DO NO pueden ser:
• una instrucción que cambia el flujo de control del programa
• una instrucción DO o REPEAT
Pueden producirse resultados inesperados si se utiliza cualquiera de estas instrucciones.
4.
Si ocurre una trampa difícil en la penúltima instrucción o en la antepenúltima
instrucción de un bucle DO, el bucle no funcionará correctamente. lo duro
trampa incluye excepciones del nivel de prioridad 13 al nivel 15,
inclusivo.
Nota 1: La instrucción DO es interrumpible y admite 1 nivel de
anidamiento de hardware. Es posible anidar hasta 5 niveles adicionales.
proporcionado en software por el usuario. Ver la familia de dispositivos específica
manual de referencia para más detalles.
2: El vinculador convertirá la expresión especificada en el desplazamiento a
ser utilizado.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 196
© 2009 Microchip Technology Inc.
Palabras:
2
Ciclos:
2
Ejemplo 1:
002000 BUCLE6: HACER #5, FIN6; Iniciar bucle DO (6 repeticiones)
002004 AÑADIR W1, W2, W3; Primera instrucción en bucle
002006. . .
002008. . .
00200A FIN6: SUB W2, W3, W4; Última instrucción en bucle
00200C. . .
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2004
DCUENTO
    0000
DCUENTO
0005
DOSTART
FFFFFF
DOSTART
00 2004
FINALIZAR
FFFFFF
FINALIZAR
00 200A
CORCÓN
 0000
CORCÓN
 0100 (DL = 1)
SR
 0001 (C = 1)
SR
 0201 (DA, C = 1)
Ejemplo 2:
01C000 BUCLE12: HACER
#0x160, FIN12; Iniciar bucle DO (353 repeticiones)
01C004 DIC W1, W2; Primera instrucción en bucle
01C006. . .
01C008. . .
01C00A. . .
01C00C. . .
01C00E. . .
01C010 LLAMADA _FIR88; Llame a la subrutina FIR88
01C014 FIN12: NO; Última instrucción en bucle 
; (Relleno NOP requerido)
antes 
Instrucción
después 
Instrucción
ordenador personal
 01 C000
ordenador personal
01 C004
DCUENTO
    0000
DCUENTO
0160
DOSTART
FFFFFF
DOSTART
01 C004
FINALIZAR
FFFFFF
FINALIZAR
01 C014
CORCÓN
 0000
CORCÓN
 0100 (DL = 1)
SR
 0008 (n = 1)
SR
 0208 (DA, N = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 197
Instrucción 
Descripciones
5
  
HACER
Inicializar bucle de hardware Wn
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:} 
HACER 
Wn, 
Expr.
Operandos:
Wn ∈ [W0 ... W15]
Expr puede ser una dirección, etiqueta o expresión absoluta.
Expr es resuelto por el enlazador a Slit16, donde Slit16 ∈ [-32768 ... +32767].
Operación:
EMPUJAR Sombras (DCOUNT, DOEND, DOSTART)
(Wn) → DCONTAR
(PC) + 4 → PC
(PC) → INICIAR 
(PC) + (2 * Rendija16) → DOEND
Incremento DL<2:0> (CORCON<10:8>)
Estado afectado:
DA
0000
1000
1000
0000
0000
sss
Codificación:
0000
0000
nnnn
nnnn
nnnn
nnnn
Descripción:
Inicie un bucle DO de hardware sin gastos generales, que se ejecuta (Wn + 1) veces. 
El bucle DO comienza en la dirección que sigue a la instrucción DO y termina en 
la dirección a 2 * Rendija16 palabras de instrucción de distancia. Los 14 bits inferiores de Wn 
admite un valor de recuento máximo de 16384 y el valor de compensación de 16 bits 
(Slit16) admite desplazamientos de palabras de instrucción de 32K en ambas direcciones.
Cuando se ejecuta esta instrucción, DCOUNT, DOSTART y DOEND son los primeros 
EMPUJADOS en sus respectivos registros de sombra y luego actualizados con el 
nuevos parámetros del bucle DO especificados por la instrucción. El recuento del nivel de OD, 
Luego se incrementa DL<2:0> (CORCON<8:10>). Después del ciclo DO 
completa la ejecución, PUSHed DCOUNT, DOSTART y DOEND 
Los registros se restauran y DL<2:0> disminuye.
Los bits ‘s’ especifican el registro Wn que contiene el recuento de bucles.
Los bits ‘n’ son un literal con signo que especifica el número de instrucciones 
desplazamiento de (PC + 4), que es la última instrucción ejecutada en el bucle.
Características especiales, restricciones:
Las siguientes características y restricciones se aplican a la instrucción DO. 
1.
El uso de un recuento de bucle de ‘0’ dará como resultado que el bucle se ejecute un
tiempo.
2.
Usar un desplazamiento de -2, -1 o 0 no es válido. Pueden ocurrir resultados inesperados
si se utilizan estas compensaciones.
3.
Las dos últimas instrucciones del bucle DO NO pueden ser:
• una instrucción que cambia el flujo de control del programa
• una instrucción DO o REPEAT
Pueden ocurrir resultados inesperados si se utilizan estas últimas instrucciones.
Nota 1: La instrucción DO es interrumpible y admite 1 nivel de anidamiento.
Se puede proporcionar anidamiento de hasta 5 niveles adicionales en el software.
por el usuario. Consulte el manual de referencia de la familia de dispositivos específica para
detalles.
2: El vinculador convertirá la expresión especificada en el desplazamiento a
ser utilizado. 
Palabras:
2
Ciclos:
2

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 198
© 2009 Microchip Technology Inc.
Ejemplo 1:
002000 BUCLE6: HACER W0, FIN6; Iniciar ciclo DO (W0 repeticiones)
002004 AÑADIR W1, W2, W3; Primera instrucción en bucle
002006. . .
002008. . .
00200A. . .
00200C REPETIR #6
00200E SUB W2, W3, W4 
002010 FIN6: NO ; Última instrucción en bucle
                                  ; (Relleno NOP requerido)
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2004
W0
0012
W0
0012  
DCUENTO
    0000
DCUENTO
0012
DOSTART
FFFFFF
DOSTART
00 2004
FINALIZAR
FFFFFF
FINALIZAR
00 2010
CORCÓN
 0000
CORCÓN
 0100 (DL = 1)
SR
0000
SR
 0080 (DA = 1)
Ejemplo 2:
002000 LOOPA: DO W7, ENDA; Iniciar ciclo DO (W7 repeticiones)
002004 INTERCAMBIAR W0 ; Primera instrucción en bucle
002006. . .
002008. . .
00200A. . .
002010 ENDA: MOV W1, [W2++] ; Última instrucción en bucle
                                  
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2000
ordenador personal
00 2004
W7
E00F
W7
E00F  
DCUENTO
    0000
DCUENTO
200F
DOSTART
FFFFFF
DOSTART
00 2004
FINALIZAR
FFFFFF
FINALIZAR
00 2010
CORCÓN
 0000
CORCÓN
 0100 (DL = 1)
SR
0000
SR
 0080 (DA = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 199
Instrucción 
Descripciones
5
  
DE
Distancia euclidiana (sin acumulación)
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis: {etiqueta:} ED
Wm * Wm, Acc,
[Wx],
[Wy],
Wxd
[Wx] + = kx, [Wy] + = ky,
[Wx] – = kx, [Wy] – = ky,
[W9 + 
W12],
[W11 + 
W12],
Operandos:
Acc ∈ [A,B]
Wm * Wm ∈ [W4 * W4, W5 * W5, W6 * W6, W7 * W7]
Wx ∈ [W8, W9]; kx ∈ [-6, -4, -2, 2, 4, 6]
Wy ∈ [W10, W11]; ky ∈ [-6, -4, -2, 2, 4, 6]
Wxd ∈ [W4 ... W7]
Operación:
(Wm) * (Wm) → Acc(A o B)
([Wx] – [Wy]) → Wxd
(Wx) + kx → Wx
(Wy) + ky → Wy
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1111
00mm
A1xx
00ii
iijj
jj11
Descripción:
Calcule el cuadrado de Wm y, opcionalmente, calcule la diferencia de los 
valores de captación previa especificados por [Wx] y [Wy]. Los resultados de Wm * Wm son 
signo extendido a 40 bits y almacenado en el acumulador especificado. el 
Los resultados de [Wx] – [Wy] se almacenan en Wxd, que puede ser el mismo que Wm.
Los operandos Wx, Wxd y Wyd especifican las operaciones de captación previa que 
Admite direccionamiento indirecto y de compensación de registro como se describe en 
Sección 4.14.1 “Capturas previas de MAC”.
Los bits ‘m’ seleccionan el registro de operando Wm para el cuadrado.
El bit ‘A’ selecciona el acumulador para el resultado.
Los bits ‘x’ seleccionan el destino Wxd de la diferencia de captación previa.
Los bits 'i' seleccionan la operación de captación previa de Wx.
Los bits 'j' seleccionan la operación de captación previa Wy.
Palabras:
1
Ciclos:
1
Ejemplo 1:
DE
W4*W4, A, [W8]+=2, [W10]-=2, W4
; Cuadrado W4 a ACCA
; [W8]-[W10] a W4
; W8 posterior al incremento 
; Post-decremento W10
                               
antes 
Instrucción
después 
Instrucción
W4
 009A
W4
   0057
W8
 1100
W8
   1102
W10
 2300
W10
   22FE
ACCA
00 3D0A 0000
ACCA
00 0000 5CA4
Datos 1100
 007F
Datos 1100
 007F
Datos 2300
 0028
Datos 2300
0028
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 200
© 2009 Microchip Technology Inc.
Ejemplo 2:
DE
W5*W5, B, [W9]+=2, [W11+W12], W5
; Cuadrado W5 a ACCB
; [W9]-[W11+W12] a W5
; W9 posterior al incremento 
                                                  
antes 
Instrucción
después 
Instrucción
W5
 43C2
W5
   3F3F
W9
 1200
W9
   1202
W11
 2500
W11
   2500
W12
 0008
W12
   0008
ACCB
00 28E3 F14C
ACCB
00 11EF 1F04
Datos 1200
 6A7C
Datos 1200
 6A7C
Datos 2508
 2B3D
Datos 2508
 2B3D
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 201
Instrucción 
Descripciones
5
  
EDAC
Distancia euclidiana
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis: {etiqueta:} EDAC
Wm * Wm, Acc,
[Wx],
[Wy],
Wxd
[Wx] + = 
kx,
[Wy] + = ky,
[Wx] – = kx, [Wy] – = ky,
[W9 + 
W12],
[W11 + 
W12],
Operandos:
Acc ∈ [A,B]
Wm * Wm ∈ [W4 * W4, W5 * W5, W6 * W6, W7 * W7]
Wx ∈ [W8, W9]; kx ∈ [-6, -4, -2, 2, 4, 6] 
Wy ∈ [W10, W11]; ky ∈ [-6, -4, -2, 2, 4, 6] 
Wxd ∈ [W4 ... W7]
Operación:
(Acc(A o B)) + (Wm) * (Wm) → Acc(A o B)
([Wx] – [Wy]) → Wxd
(Wx) + kx → Wx
(Wy) + ky → Wy
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1111
00mm
A1xx
00ii
iijj
jj10
Descripción:
Calcule el cuadrado de Wm y también la diferencia de la captación previa 
valores especificados por [Wx] y [Wy]. Los resultados de Wm * Wm son 
signo extendido a 40 bits y agregado al acumulador especificado. el 
Los resultados de [Wx] – [Wy] se almacenan en Wxd, que puede ser el mismo que Wm.
Los operandos Wx, Wxd y Wyd especifican las operaciones de captación previa que 
Admite direccionamiento indirecto y de compensación de registro como se describe en 
Sección 4.14.1 “Capturas previas de MAC”.
Los bits ‘m’ seleccionan el registro de operando Wm para el cuadrado.
El bit ‘A’ selecciona el acumulador para el resultado. 
Los bits ‘x’ seleccionan el destino Wxd de la diferencia de captación previa.
Los bits 'i' seleccionan la operación de captación previa de Wx.
Los bits 'j' seleccionan la operación de captación previa Wy.
Palabras:
1
Ciclos:
1
Ejemplo 1:
EDAC
W4*W4, A, [W8]+=2, [w10]-=2, W4
; Cuadrado W4 y
; agregar a ACCA
; [W8]-[W10] a W4
; W8 posterior al incremento 
; Post-decremento W10
                                                                   
antes 
Instrucción
después 
Instrucción
W4
 009A
W4
   0057
W8
 1100
W8
   1102
W10
 2300
W10
   22FE
ACCA
00 3D0A 3D0A
ACCA
00 3D0A 99AE
Datos 1100
 007F
Datos 1100
 007F
Datos 2300
 0028
Datos 2300
 0028
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 202
© 2009 Microchip Technology Inc.
Ejemplo 2:
EDAC W5*W5, B, [w9]+=2, [W11+W12], W5
; Cuadrado W5 y
; añadir a ACCB
; [W9]-[W11+W12] a W5
; W9 posterior al incremento          
antes 
Instrucción
después 
Instrucción
W5
 43C2
W5
   3F3F
W9
 1200
W9
   1202
W11
 2500
W11
   2500
W12
 0008
W12
   0008
ACCB
00 28E3 F14C
ACCB
00 3AD3 1050
Datos 1200
 6A7C
Datos 1200
 6A7C
Datos 2508
 2B3D
Datos 2508
 2B3D
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 203
Instrucción 
Descripciones
5
  
EXCH
Intercambiar Wns y Wnd
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
EXCH 
WNS,
viento
Operandos:
Wns ∈ [W0 ... W15]
Viento ∈ [W0 ... W15]
Operación:
(Wns) ↔ (Wnd) 
Estado afectado:
Ninguno
Codificación:
1111
1101
0000
0ddd
d000
sss
Descripción:
Intercambie el contenido de palabras de dos registros de trabajo. Regístrate directo 
El direccionamiento debe usarse para Wns y Wnd. 
Los bits 'd' seleccionan la dirección del primer registro.
Los bits ‘s’ seleccionan la dirección del segundo registro.
Nota:
Esta instrucción sólo se ejecuta en modo Word.
Palabras:
1
Ciclos:
1
Ejemplo 1:
EXCH
W1, W9; Intercambiar el contenido de W1 y W9.
                  
     
antes
Instrucción
      
después
Instrucción
W1
 55FF
W1
 A3A3
W9
 A3A3
W9
 55FF
SR
 0000
SR
 0000
Ejemplo 2:
EXCH
W4, W5; Intercambiar el contenido de W4 y W5.
                  
     
antes
Instrucción
      
después
Instrucción
W4
 ABCD
W4
 4321
W5
 4321
W5
ABCD
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 204
© 2009 Microchip Technology Inc.
  
FBCL
Encuentre el primer cambio de bit desde la izquierda
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
FBCL
Ws,
viento
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
Viento ∈ [W0 ... W15]
Operación:
Cambio_máx = 15
Signo = (Ws) y 0x8000
Temperatura = (Ws) << 1
Cambio = 0
Mientras ((Shift <Max_Shift) && ((Temp & 0x8000) == Signo))
    Temperatura = Temperatura << 1
    Mayús = Mayús + 1
-Mayús → (Wnd)
Estado afectado:
c
Codificación:
1101
1111
0000
0ddd
dppp
sss
Descripción:
Encuentre la primera aparición de uno (para un valor positivo) o cero (para un 
valor negativo), comenzando desde el bit más significativo después del bit de signo de 
Ws y trabajando hacia la parte menos significativa de la palabra operando. el 
El resultado del número de bits se extiende con signo a 16 bits y se coloca en Wnd.
Al siguiente bit más significativo después del bit de signo se le asigna el número de bit 0 y 
al bit menos significativo se le asigna el número de bit -14. Este poco ordenando 
permite el uso inmediato de Wd con la instrucción SFTAC para escalar 
valores hacia arriba. Si no se encuentra un cambio de bit, se devuelve un resultado de -15 y el código C 
La bandera está configurada. Cuando se encuentra un cambio de bit, se borra el indicador C.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
Esta instrucción funciona únicamente en modo Word.
Palabras:
1
Ciclos:
1
Ejemplo 1:
FBCL
W1, W9
; Encuentra el primer cambio de bit desde la izquierda en W1
; y almacenar el resultado en W9
antes 
Instrucción
después 
Instrucción
W1
 55FF
W1
 55FF
W9
 FFFFF
W9
 0000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 205
Instrucción 
Descripciones
5
Ejemplo 2:
FBCL
W1, W9
; Encuentra el primer cambio de bit desde la izquierda en W1
; y almacenar el resultado en W9
antes 
Instrucción
después 
Instrucción
W1
 FFFFF
W1
 FFFFF
W9
 BBBB
W9
 FFF1
SR
 0000
SR
 0001 (C = 1)
Ejemplo 3:
FBCL
[W1++], W9
; Encuentre el primer cambio de bit desde la izquierda en [W1] 
; y almacenar el resultado en W9
; W1 posterior al incremento 
antes 
Instrucción
después 
Instrucción
W1
 2000
W1
 2002
W9
 BBBB
W9
 FFF9
Datos 2000
 FF0A
Datos 2000 FF0A
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 206
© 2009 Microchip Technology Inc.
  
FF1L
Encuentra el primero desde la izquierda
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
FF1L
Ws,
viento
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
Viento ∈ [W0 ... W15]
Operación:
Cambio_máx = 17
Temperatura = (Ws)
Turno = 1
Mientras ((Shift <Max_Shift) &&! (Temperatura y 0x8000))
    Temperatura = Temperatura << 1
    Mayús = Mayús + 1
Si (Mayús == Max_Shift)
    0 → (viento)
más
    Mayús → (Wnd)
Estado afectado:
c
Codificación:
1100
1111
1000
0ddd
dppp
sss
Descripción:
Encuentra la primera aparición de un ‘1’ comenzando desde el bit más significativo de 
Ws y trabajando hacia la parte menos significativa de la palabra operando. 
El resultado del número de bits se extiende desde cero a 16 bits y se coloca en Wnd. 
La numeración de bits comienza con el bit más significativo (número asignado 1) 
y avanza al bit menos significativo (número asignado 16). un resultado 
de cero indica que no se encontró un ‘1’ y se establecerá la bandera C. Si un ‘1’ es 
encontrado, se borra la bandera C.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
Esta instrucción funciona únicamente en modo Word.
Palabras:
1
Ciclos:
1
Ejemplo 1:
FF1L
W2, W5; Encuentra el primero desde la izquierda en W2 
                 ; y almacenar el resultado en W5
                  
antes 
Instrucción
después 
Instrucción
W2
 000A
W2
 000A
W5
 BBBB
W5
 000D
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 207
Instrucción 
Descripciones
5
Ejemplo 2:
FF1L
[W2++], W5
; Encuentra el primero desde la izquierda en [W2] 
; y almacenar el resultado en W5
; W2 posterior al incremento
antes 
Instrucción
después 
Instrucción
W2
 2000
W2
 2002
W5
 BBBB
W5
 0000
Datos 2000
 0000
Datos 2000
 0000
SR
 0000
SR
 0001
(C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 208
© 2009 Microchip Technology Inc.
  
FF1R
Encuentra el primero desde la derecha
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
FF1R
Ws,
viento
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
Viento ∈ [W0 ... W15]
Operación:
Cambio_máx = 17
Temperatura = (Ws)
Turno = 1
Mientras ((Shift <Max_Shift) &&! (Temp & 0x1))
    Temperatura = Temperatura >> 1
    Mayús = Mayús + 1
Si (Mayús == Max_Shift)
    0 → (viento)
más
    Mayús → (Wnd)
Estado afectado:
c
Codificación:
1100
1111
0000
0ddd
dppp
sss
Descripción:
Encuentra la primera aparición de un ‘1’ comenzando desde el bit menos significativo de 
Ws y trabajando hacia la parte más significativa de la palabra operando. el 
El resultado del número de bits se extiende a cero a 16 bits y se coloca en Wnd. 
La numeración de bits comienza con el bit menos significativo (número asignado 1) 
y avanza al bit más significativo (número asignado 16). un resultado de 
cero indica que no se encontró un ‘1’ y se establecerá la bandera C. Si un ‘1’ es 
encontrado, se borra la bandera C.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
Esta instrucción funciona únicamente en modo Word.
Palabras:
1
Ciclos:
1
Ejemplo 1:
FF1R
W1, W9
; Encuentra el primero desde la derecha en W1 
; y almacenar el resultado en W9
                  
antes 
Instrucción
después 
Instrucción
W1
 000A
W1
 000A
W9
 BBBB
W9
 0002
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 209
Instrucción 
Descripciones
5
Ejemplo 2:
FF1R
[W1++], W9
; Encuentra el primero desde la derecha en [W1] 
; y almacenar el resultado en W9
; W1 posterior al incremento 
antes 
Instrucción
después 
Instrucción
W1
 2000
W1
 2002
W9
 BBBB
W9
 0010
Datos 2000
 8000
Datos 2000
 8000
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 210
© 2009 Microchip Technology Inc.
  
IR A
Salto incondicional
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
IR A 
Expr.
Operandos:
Expr puede ser una etiqueta o una expresión (pero no un literal).
Expr es resuelto por el enlazador a lit23, donde lit23 ∈ [0 ... 8388606].
Operación:
lit23 → ordenador personal
NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
    1ra palabra
0000
0100
nnnn
nnnn
nnnn
nnn0
    2da palabra
0000
0000
0000
0000
0nnn
nnnn
Descripción:
Salto incondicional a cualquier lugar dentro del programa de palabras de instrucción 4M 
rango de memoria. La PC está cargada con el literal de 23 bits especificado en el 
instrucción. Dado que la PC siempre debe residir en un límite de dirección par, 
lit23<0> se ignora. 
Los bits ‘n’ forman la dirección de destino.
Nota:
El vinculador resolverá la expresión especificada en lit23 para que sea
usado.
Palabras:
2
Ciclos:
2
Ejemplo 1:
026000 IR A _ ALLÍ
026004 MOV W0, W1
   .           ...
   .           ...
027844 _AQUÍ: MOV #0x400, W2
027846 ...       
; Saltar a _AQUÍ
; Ejecución de código
; se reanuda aquí
antes 
Instrucción
después 
Instrucción
ordenador personal
 02 6000
ordenador personal
02 7844
SR
 0000
SR
 0000
Ejemplo 2:
000100 _código:
...
   .           ...
026000 IR A _código+2
026004...    
; inicio del código
; Saltar a _code+2
antes 
Instrucción
después 
Instrucción
ordenador personal
 02 6000
ordenador personal
00 0102
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 211
Instrucción 
Descripciones
5
  
IR A
Salto indirecto incondicional
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
IR A 
Wn
Operandos:
Wn ∈ [W0 ... W15]
Operación:
0 → PC<22:16>
(Wn<15:1>) → PC<15:1>
0 → equipo<0>
NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0000
0001
0100
0000
0000
sss
Descripción:
Salto indirecto incondicional dentro de las primeras 32K palabras de la memoria del programa. 
Se carga cero en la PC<22:16> y se carga el valor especificado en (Wn) 
en PC<15:1>. Dado que la PC siempre debe residir en una dirección par 
límite, Wn<0> se ignora.
Los bits ‘s’ seleccionan el registro fuente.
Palabras:
1
Ciclos:
2
Ejemplo 1:
006000 IR A W4
006002 MOV W0, W1
   .           ...
   .           ...
007844 _AQUÍ: MOV #0x400, W2
007846 ...       
; Saltar incondicionalmente
; a valor de 16 bits en W4
; Ejecución de código
; se reanuda aquí
antes 
Instrucción
después 
Instrucción
W4
 7844
W4
 7844
ordenador personal
 00 6000
ordenador personal
00 7844
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 212
© 2009 Microchip Technology Inc.
  
INC
incremento f
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
INC{.B} 
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
(f) + 1 → destino designado por D
Estado afectado:
CC, N, OV, Z, C
Codificación:
1110
1100
0BDF
ffff
ffff
ffff
Descripción:
Agregue uno al contenido del registro de archivos y coloque el resultado en el
registro de destino. El operando WREG opcional determina el
registro de destino. Si se especifica WREG, el resultado se almacena en WREG. si
WREG no se especifica, el resultado se almacena en el registro del archivo.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0. 
Palabras:
1
Ciclos:
1
Ejemplo 1:
INC.B
0x1000; Incremento 0x1000 (modo Byte)
antes 
Instrucción
después 
Instrucción
Datos 1000
 8FFF
Datos 1000
 8F00
SR
 0000
SR
 0101
(CC, C = 1)
Ejemplo 2:
INC
0x1000, WREG; Incrementar 0x1000 y almacenar en WREG
                     ; (modo palabra)
antes 
Instrucción
después 
Instrucción
WREG
 ABCD
WREG
 9000
Datos 1000
 8FFF
Datos 1000
 8FFF
SR
 0000
SR
 0108
(CC, N = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 213
Instrucción 
Descripciones
5
  
INC
Incremento Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
INC{.B} 
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Ws) + 1 → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
1110
1000
0Bqq
qdddd
dppp
sss
Descripción:
Sume 1 al contenido del registro fuente Ws y coloque el resultado en el 
registro de destino Wd. Registrar direccionamiento directo o indirecto podrá ser 
utilizado para Ws y Wd.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
INC.B
W1, [++W2]; Preincremento W2
                         ; Incrementar W1 y almacenar en W2
                         ; (modo bytes)
antes 
Instrucción
después 
Instrucción
W1
 FF7F
W1
 FF7F
W2
 2000
W2
 2001
Datos 2000
 ABCD
Datos 2000
80CD
SR
 0000
SR
 010C
(CC, N, OV = 1)
Ejemplo 2:
INC
W1, W2; Incrementar W1 y almacenar en W2
                     ; (modo palabra)
antes 
Instrucción
después 
Instrucción
W1
 FF7F
W1
 FF7F
W2
 2000
W2
 FF80
SR
 0000
SR
 0108
(CC, N = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 214
© 2009 Microchip Technology Inc.
  
INC2
Incrementar f en 2
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
INC2{.B} 
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
(f) + 2 → destino designado por D 
Estado afectado:
CC, N, OV, Z, C
Codificación:
1110
1100
1HAB
ffff
ffff
ffff
Descripción:
Sume 2 al contenido del registro de archivos y coloque el resultado en el 
registro de destino. El operando WREG opcional determina el 
registro de destino. Si se especifica WREG, el resultado se almacena en WREG. si 
WREG no se especifica, el resultado se almacena en el registro del archivo.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
INC2.B
0x1000; Incrementar 0x1000 en 2
                 ; (modo bytes)
antes 
Instrucción
después 
Instrucción
Datos 1000
 8FFF
Datos 1000
 8F01
SR
 0000
SR
 0101
(CC, C = 1)
Ejemplo 2:
INC2
0x1000, WREG
; Incrementar 0x1000 en 2 y almacenar en WREG
                    ; (modo palabra)
antes 
Instrucción
después 
Instrucción
WREG
 ABCD
WREG
 9001
Datos 1000
 8FFF
Datos 1000
 8FFF
SR
 0000
SR
 0108
(CC, N = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 215
Instrucción 
Descripciones
5
  
INC2
Incrementar Ws en 2
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
INC2{.B} 
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Ws) + 2 → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
1110
1000
1Bqq
qdddd
dppp
sss
Descripción:
Sume 2 al contenido del registro fuente Ws y coloque el resultado en el 
registro de destino Wd. Se puede utilizar el direccionamiento directo o indirecto del registro. 
para Ws y Wd.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
INC2.B
W1, [++W2]; Preincremento W2
                     ; Incrementar en 2 y almacenar en W1
                     ; (modo bytes)
antes 
Instrucción
después 
Instrucción
W1
 FF7F
W1
 FF7F
W2
 2000
W2
 2001
Datos 2000
 ABCD
Datos 2000
81CD
SR
 0000
SR
 010C
(CC, N, OV = 1)
Ejemplo 2:
INC2
W1, W2; Incrementar W1 en 2 y almacenar en W2 
                 ; (modo palabra)
antes 
Instrucción
después 
Instrucción
W1
 FF7F
W1
 FF7F
W2
 2000
W2
 FF81
SR
 0000
SR
 0108
(CC, N = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 216
© 2009 Microchip Technology Inc.
  
IOR
OR inclusivo f y WREG
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
IOR{.B} 
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
(f).IOR.(WREG) → destino designado por D
Estado afectado:
norte, z
Codificación:
1011
0111
0BDF
ffff
ffff
ffff
Descripción:
Calcule la operación OR lógica inclusiva del contenido del trabajo 
registre WREG y el contenido del archivo registre y coloque el resultado en 
el registro de destino. El operando WREG opcional determina el 
registro de destino. Si se especifica WREG, el resultado se almacena en WREG. si 
WREG no se especifica, el resultado se almacena en el registro del archivo.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0. 
Palabras:
1
Ciclos:
1
Ejemplo 1:
IOR.B
0x1000; IOR WREG a (0x1000) (modo Byte)
                    ; (modo bytes)
antes 
Instrucción
después 
Instrucción
WREG
 1234
WREG
 1234
Datos 1000
 FF00
Datos 1000
 FF34
SR
 0000
SR
 0000
Ejemplo 2:
IOR
0x1000, WREG; IOR (0x1000) a WREG
                    ; (modo palabra)
antes 
Instrucción
después 
Instrucción
WREG
 1234
WREG
 1FBF
Datos 1000
 0FAB
Datos 1000
 0FAB
SR
 0008
(norte = 1)
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 217
Instrucción 
Descripciones
5
  
IOR
Inclusivo OR Literal y Wn
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
IOR{.B} 
#lit10,
Wn
Operandos:
lit10 ∈ [0 ... 255] para operación de bytes
lit10 ∈ [0 ... 1023] para operación de palabra
Wn ∈ [W0 ... W15]
Operación:
lit10.IOR.(Wn) → Wn 
Estado afectado:
norte, z
Codificación:
1011
0011
0Bkk
kkkk
kkkk
dddd
Descripción:
Calcule la operación OR lógica inclusiva del operando literal de 10 bits 
y el contenido del registro de trabajo Wn y colocar el resultado nuevamente en 
el registro de trabajo Wn. 
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits 'k' especifican el operando literal.
Los bits 'd' seleccionan la dirección del registro de trabajo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: para operaciones de bytes, el literal debe especificarse como sin firmar
valor [0:255]. Consulte la Sección 4.6 “Uso de operandos literales de 10 bits”
para obtener información sobre el uso de operandos literales de 10 bits en modo Byte.
Palabras:
1
Ciclos:
1
Ejemplo 1:
IOR.B #0xAA, W9; IOR 0xAA a W9 
                     ; (modo bytes)
                         
antes 
Instrucción
después 
Instrucción
W9
 1234
W9
 12 A.E.
SR
 0000
SR
 0008
(norte = 1)
Ejemplo 2:
IOR
#0x2AA, W4; IOR 0x2AA a W4
                     ; (modo palabra)
antes 
Instrucción
después 
Instrucción
W4
 A34D
W4
 A3EF
SR
 0000
SR
 0008
(norte = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 218
© 2009 Microchip Technology Inc.
  
IOR
Inclusivo OR Wb y Literal Corto 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
IOR{.B} 
Wb,
#lit5,
Wd
[Wd]
[Wd++]
[Wd--]
[++Wd]
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
iluminado5 ∈ [0 ... 31]
Wd ∈ [W0 ... W15]
Operación:
(Wb).IOR.lit5 → Wd 
Estado afectado:
norte, z
Codificación:
0111
0www
wBqq
qdddd
d11k
kkkk
Descripción:
Calcule la operación OR lógica inclusiva del contenido de la base 
registre Wb y el operando literal de 5 bits y coloque el resultado en el 
registro de destino Wd. Se debe utilizar el direccionamiento directo de registro para Wb. 
Para Wd se puede utilizar el direccionamiento directo o indirecto del registro.
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘k’ proporcionan el operando literal, un número entero de cinco bits.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
IOR.B
W1, #0x5, [W9++]
; IOR W1 y 0x5 (modo Byte)
                         ; Guardar en [W9]
                         ; W9 posterior al incremento
antes 
Instrucción
después 
Instrucción
W1
 AAAAA
W1
 AAAAA
W9
 2000
W9
 2001
Datos 2000
0000
Datos 2000
00AF
SR
 0000
SR
 0008
(norte = 1)
Ejemplo 2:
IOR
W1, #0x0, W9; IOR W1 con 0x0 (modo Palabra)
                     ; Guardar en W9
antes 
Instrucción
después 
Instrucción
W1
0000
W1
 0000
W9
 A34D
W9
 0000
SR
 0000
SR
 0002
(Z = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 219
Instrucción 
Descripciones
5
  
IOR
Inclusivo O Wb y Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
IOR{.B} 
Wb,
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Wb).IOR.(Ws) → Wd 
Estado afectado:
norte, z
Codificación:
0111
0www
wBqq
qdddd
dppp
sss
Descripción:
Calcule la operación OR lógica inclusiva del contenido de la fuente 
registrar Ws y el contenido del registro base Wb, y colocar el resultado en 
el registro de destino Wd. Se debe utilizar el direccionamiento directo de registro para Wb. 
Se puede utilizar el direccionamiento directo o indirecto de registro para Ws y Wd.
 Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
IOR.B
W1, [W5++], [W9++]
; IOR W1 y [W5] (modo Byte)
                           ; Guardar resultado en [W9]
                           ; W5 y W9 posteriores al incremento
antes 
Instrucción
después 
Instrucción
W1
 AAAAA
W1
 AAAAA
W5
 2000
W5
 2001
W9
 2400
W9
 2401
Datos 2000
1155
Datos 2000
1155
Datos 2400
0000
Datos 2400
00FF
SR
 0000
SR
 0008
(norte = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 220
© 2009 Microchip Technology Inc.
Ejemplo 2:
IOR
W1, W5, W9; IOR W1 y W5 (modo Palabra)
                       ; Guarde el resultado en W9
        
     antes 
    Instrucción
      después 
    Instrucción
W1
 AAAAA
W1
 AAAAA
W5
 5555
W5
 5555
W9
 A34D
W9
 FFFFF
SR
 0000
SR
 0008
(norte = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 221
Instrucción 
Descripciones
5
  
ALC
Acumulador de carga
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:} 
ALC 
Ws,
{#Rendija4,}
Acc
[Ws],
 
[Ws++],
 
[Ws--],
 
[--Ws],
 
[++Ws],
 
[Ws+Wb],
 
Operandos:
Ws ∈ [W0 ... W15]
Wb ∈ [W0 ... W15]
Rendija4 ∈ [-8 ... +7]
Acc ∈ [A,B]
Operación:
ShiftSlit4(Extender(Ws)) → Acc(A o B)
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1100
1010
awww
wrrr
gggg
sss
Descripción:
Leer el contenido del registro fuente, opcionalmente realizar un registro de 4 bits firmado 
cambie y almacene el resultado en el acumulador especificado. El rango de cambio es -8:7, 
donde un operando negativo indica un desplazamiento aritmético a la izquierda y un operando positivo 
El operando indica un desplazamiento aritmético a la derecha. Los datos almacenados en la fuente. 
Se supone que el registro es de 1,15 datos fraccionarios y se actualiza automáticamente. 
con signo extendido (hasta el bit 39) y con relleno de ceros (bits [15:0]), antes de 
cambiando.
El bit ‘A’ especifica el acumulador de destino.
Los bits ‘w’ especifican el registro de compensación Wb.
Los bits ‘r’ codifican el precambio del acumulador.
Los bits ‘g’ seleccionan el modo de dirección de origen.
Los bits ‘s’ especifican el registro fuente Ws. 
Nota:
Si la operación mueve más que datos de extensión de signo al
registro superior del Acumulador (AccxU), o provoca una saturación, el
Se establecerán los bits de desbordamiento y saturación apropiados.
Palabras:
1
Ciclos:
1
Ejemplo 1:
ALC
[W4++], #-3, B; Cargar ACCB con [W4] << 3
                       ; El contenido de [W4] no cambia 
                       ; Incremento posterior W4
                       ; Supongamos que la saturación está desactivada
                       ; (SATB = 0)
                                            
antes 
Instrucción
después 
Instrucción
W4
 2000
W4
   2002
ACCB
00 5125 ABCD
ACCB
FF 9108 0000
Datos 2000
 1221
Datos 2000
 1221
SR
 0000
SR
 4800 (OB, VHA = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 222
© 2009 Microchip Technology Inc.
Ejemplo 2:
ALC
[--W2], #7, A; Pre-decremento W2
                       ; Cargar ACCA con [W2] >> 7
                       ; El contenido de [W2] no cambia 
                       ; Supongamos que la saturación está desactivada
                       ; (SATA = 0)
                                                                   
antes 
Instrucción
después 
Instrucción
W2
 4002
W2
   4000
ACCA
00 5125 ABCD
ACCA
FF FF22 1000
Datos 4000
 9108
Datos 4000
 9108
Datos 4002
 1221
Datos 4002
 1221
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 223
Instrucción 
Descripciones
5
  
LNK
Asignar marco de pila
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
LNK
#lit14
Operandos:
iluminado14 ∈ [0 ... 16382]
Operación:
(W14) → (TOS)
(W15) + 2 → W15
(W15) → W14
(W15) + lit14 → W15
Estado afectado:
Ninguno
Codificación:
1111
1010
00kk
kkkk
kkkk
kkk0
Descripción:
Esta instrucción asigna un marco de pila de tamaño lit14 bytes para un 
secuencia de llamada de subrutina. El marco de pila se asigna PUSHing 
el contenido del puntero de marco (W14) en la pila, almacenando el 
Puntero de pila actualizado (W15) al puntero de marco y luego incrementando 
el puntero de pila por el operando literal de 14 bits sin signo. esta instrucción 
admite un marco de pila máximo de 16382 bytes.
Los bits 'k' especifican el tamaño del marco de pila.
Nota:
Dado que el puntero de pila solo puede residir en el límite de una palabra,
lit14 debe ser par. 
Palabras:
1
Ciclos:
1
Ejemplo 1:
LNK
#0xA0; Asigne un marco de pila de 160 bytes
antes 
Instrucción
después 
Instrucción
W14
 2000
W14
   2002
W15
 2000
W15
   20A2
Datos 2000
 0000
Datos 2000
 2000
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 224
© 2009 Microchip Technology Inc.
 
LSR
Desplazamiento lógico a la derecha f
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
LSR{.B} 
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
Para operación de bytes:
    0 → Destino<7>
    (f<7:1>) → Destino<6:0>
    (f<0>) → C
Para operación de palabras:
    0 → Destino<15>
    (f<15:1>) → Destino<14:0>
    (f<0>) → C
Estado afectado:
norte, z, c
Codificación:
1101
0101
0BDF
ffff
ffff
ffff
Descripción:
Mueva el contenido del registro del archivo un bit a la derecha y coloque el resultado 
en el registro de destino. El bit menos significativo del registro de archivo es 
desplazado al bit de acarreo del registro STATUS. El cero se desplaza al 
Bit más significativo del registro de destino. 
El operando WREG opcional determina el registro de destino. Si WREG 
se especifica, el resultado se almacena en WREG. Si no se especifica WREG, el 
El resultado se almacena en el registro de archivos.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0. 
Palabras:
1
Ciclos:
1
c
0
Ejemplo 1:
LSR.B
0x600; Desplazarse lógicamente a la derecha (0x600) uno
               ; (modo bytes) 
antes
Instrucción
después
Instrucción
Datos 600
 55FF
Datos 600
 557F
SR
 0000
SR
 0001
(C = 1)
Ejemplo 2:
LSR
0x600, WREG
; Desplazarse lógicamente a la derecha (0x600) uno
                  ; Almacenar en WREG
                  ; (modo palabra)
antes
Instrucción
después
Instrucción
Datos 600
 55FF
Datos 600
 55FF
WREG
 0000
WREG
 2AF
SR
 0000
SR
 0001
(C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 225
Instrucción 
Descripciones
5
  
LSR
Desplazamiento lógico a la derecha Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
LSR{.B} 
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
Para operación de bytes:
    0 → Wd<7>
    (Ws<7:1>) → Wd<6:0>
    (Ws<0>) → C
 Para operación de palabras:
    0 → Wd<15> 
    (Ws<15:1>) → Wd<14:0>
    (Ws<0>) → C
Estado afectado:
norte, z, c
Codificación:
1101
0001
0Bqq
qdddd
dppp
sss
Descripción:
Desplace el contenido del registro fuente Ws un bit hacia la derecha y coloque 
el resultado en el registro de destino Wd. La parte menos significativa de W es 
desplazado al bit de acarreo del registro STATUS. El cero se desplaza al 
Lo más significativo de Wd. Ya sea registrar direccionamiento directo o indirecto 
puede usarse para Ws y Wd.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
c
0
Ejemplo 1:
LSR.B
W0, W1; LSR W0 (modo byte)
                  ; Guardar resultado en W1
antes 
Instrucción
después 
Instrucción
W0
FF03
W0
FF03
W1
2378
W1
2301
SR
 0000
SR
 0001
(C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 226
© 2009 Microchip Technology Inc.
Ejemplo 2:
LSR
W0, W1; LSR W0 (modo Palabra)
                ; Guarde el resultado en W1
        
     antes 
    Instrucción
      después 
    Instrucción
W0
8000
W0
8000
W1
2378
W1
4000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 227
Instrucción 
Descripciones
5
  
LSR
Desplazamiento lógico a la derecha por literal corto 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:}
LSR
Wb, 
#lit4,
viento
Operandos:
Wb ∈ [W0 ... W15]
iluminado4 ∈ [0 ... 15]
Viento ∈ [W0 ... W15] 
Operación:
lit4<3:0> → Shift_Val
0 → Viento<15:15-Shift_Val + 1>
Wb<15:Shift_Val> → Wnd<15-Shift_Val:0>
Estado afectado:
norte, z
Codificación:
1101
1110
0www
wdddd
d100
kkkk
Descripción:
Desplazamiento lógico a la derecha del contenido del registro fuente Wb en 4 bits 
literal sin signo y almacena el resultado en el registro de destino Wnd. directo 
El direccionamiento debe usarse para Wb y Wnd.
Los bits ‘w’ seleccionan la dirección del registro base.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘k’ proporcionan el operando literal.
Nota:
Esta instrucción funciona únicamente en modo Word.
Palabras:
1
Ciclos:
1
Ejemplo 1:
LSR W4, #14, W5; LSR W4 por 14 
                      ; Almacenar el resultado en W5
antes 
Instrucción
después 
Instrucción
W4
C800
W4
C800
W5
1200
W5
0003
SR
 0000
SR
 0000
Ejemplo 2:
LSR W4, #1, W5; LSR W4 por 1
                      ; Almacenar el resultado en W5
        
     antes 
    Instrucción
      después 
    Instrucción
W4
0505
W4
0505
W5
F000
W5
0282
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 228
© 2009 Microchip Technology Inc.
 
LSR
Desplazamiento lógico a la derecha por Wns 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:}
LSR
Wb, 
WNS, 
viento
Operandos:
Wb ∈ [W0 ... W15]
Wns ∈ [W0 ...W15]
Viento ∈ [W0 ... W15]
Operación:
Wns<4:0> → Shift_Val
0 → Viento<15:15-Shift_Val + 1>
Wb<15:Shift_Val> → Wnd<15 - Shift_Val:0>
Estado afectado:
norte, z
Codificación:
1101
1110
0www
wdddd
d000
sss
Descripción:
Desplazamiento lógico hacia la derecha el contenido del registro fuente Wb por el 5 mínimo 
Bits significativos de Wns (solo hasta 15 posiciones) y almacenar el resultado en el 
registro de destino Wnd. Se debe utilizar direccionamiento directo para Wb y 
Viento.
Los bits ‘w’ seleccionan la dirección del registro base.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: Esta instrucción funciona únicamente en modo Word.
2: Si Wns es mayor que 15, Wnd se cargará con 0x0.
Palabras:
1
Ciclos:
1
Ejemplo 1:
LSR W0, W1, W2; LSR W0 por W1
                      ; Guardar resultado en W2
antes 
Instrucción
después 
Instrucción
W0
C00C
W0
C00C
W1
0001
W1
0001
W2
2390
W2
6006
SR
 0000
SR
 0000
Ejemplo 2:
LSR W5, W4, W3; LSR W5 por W4
                      ; Almacenar el resultado en W3
        
     antes 
    Instrucción
      después 
    Instrucción
W3
DD43
W3
0000
W4
000C
W4
000C
W5
0800
W5
0800
SR
 0000
SR
 0002
(Z = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 229
Instrucción 
Descripciones
5
  
MAC
Multiplicar y acumular 
Implementado en:
PIC24F
PIC24H
dsPIC30F dsPIC33F
x
x
Sintaxis: {etiqueta:} MAC
Wm*Wn, Acc {,[Wx], Wxd}
{,[Wy], Wyd}
{,AWB}
{,[Wx] + = kx, Wxd} {,[Wy] + = ky, Wyd}
{,[Wx] – = kx, 
Wxd}
{,[Wy] – = ky, Wyd}
{,[W9 + W12], 
Wxd}
{,[W11 + W12], 
Wyd}
Operandos:
Wm * Wn ∈ [W4 * W5, W4 * W6, W4 * W7, W5 * W6, W5 * W7, W6 * W7]
Acc ∈ [A,B]
Wx ∈ [W8, W9]; kx ∈ [-6, -4, -2, 2, 4, 6]; Wxd ∈ [W4 ... W7]
Wy ∈ [W10, W11]; ky ∈ [-6, -4, -2, 2, 4, 6]; Wyd ∈ [W4 ... W7]
AWB ∈ [W13, [W13] + = 2]
Operación:
(Acc(A o B)) + (Wm) * (Wn) → Acc(A o B)
([Wx]) → Wxd; (Wx) + kx → Wx
([Wy]) → Wyd; (Wy) + ky → Wy
(Acc(B o A)) redondeado → AWB
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1100
0mmmm
A0xx
yyii
iijj
jjaa
Descripción:
Multiplicar el contenido de dos registros de trabajo, opcionalmente captar previamente 
operandos en preparación para otra instrucción de tipo MAC y opcionalmente 
almacenar los resultados del acumulador no especificado. El resultado de 32 bits del firmado. 
multiplicar se extiende con signos a 40 bits y se suma al valor especificado 
acumulador. 
Los operandos Wx, Wxd, Wy y Wyd especifican operaciones de captación previa opcionales. 
que admiten direccionamiento indirecto y de compensación de registro, como se describe en 
Sección 4.14.1 “Capturas previas de MAC”. El operando AWB especifica el opcional 
almacenamiento del acumulador “otro”, como se describe en 
Sección 4.14.4 “Escritura MAC”.
Los bits ‘m’ seleccionan los registros de operandos Wm y Wn para la multiplicación.
El bit ‘A’ selecciona el acumulador para el resultado. 
Los bits ‘x’ seleccionan el destino de captación previa Wxd.
Los bits ‘y’ seleccionan el destino Wyd de captación previa.
Los bits 'i' seleccionan la operación de captación previa de Wx.
Los bits 'j' seleccionan la operación de captación previa Wy.
Los bits ‘a’ seleccionan el destino de escritura posterior del acumulador.
Nota:
El bit IF, CORCON<0>, determina si la multiplicación es 
fraccionario o un número entero.
Palabras:
1
Ciclos:
1

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 230
© 2009 Microchip Technology Inc.
Ejemplo 1:
MAC
W4*W5, A, [W8]+=6, W4, [W10]+=2, W5 
; Multiplica W4*W5 y suma a ACCA 
; Recuperar [W8] a W4, incrementar posteriormente W8 en 6
; Recuperar [W10] a W5, post-incrementar W10 en 2
; CORCON = 0x00C0 (multiplicación fraccionaria, saturación normal)
                               
antes 
Instrucción
después 
Instrucción
W4
 A022
W4
 2567
W5
 B900
W5
 909C
W8
 0A00
W8
   0A06
W10
 1800
W10
   1802
ACCA
00 1200 0000
ACCA
00 472D 2400
Datos 0A00
 2567
Datos 0A00
 2567
Datos 1800
 909C
Datos 1800
 909C
CORCÓN
 00C0
CORCÓN
 00C0
SR
 0000
SR
 0000
Ejemplo 2:
MAC
W4*W5, A, [W8]-=2, W4, [W10]+=2, W5, W13
; Multiplica W4*W5 y suma a ACCA
; Recuperar [W8] a W4, posdisminuir W8 en 2
; Recuperar [W10] a W5, post-incrementar W10 en 2
; Escribir ACCB en W13
; CORCON = 0x00D0 (multiplicación fraccionaria, supersaturación)
antes 
Instrucción
después 
Instrucción
W4
 1000
W4
 5BBE
W5
 3000
W5
   C967
W8
 0A00
W8
   09FE
W10
 1800
W10
   1802
W13
 2000
W13
   0001
ACCA
23 5000 2000
ACCA
23 5600 2000
ACCB
00 0000 8F4C
ACCB
00 0000 1F4C
Datos 0A00
 5BBE
Datos 0A00
 5BBE
Datos 1800
 C967
Datos 1800
 C967
CORCÓN
 00D0
CORCÓN
 00D0
SR
 0000
SR
 8800 (OA, OAB = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 231
Instrucción 
Descripciones
5
  
MAC
Cuadrar y acumular 
Implementado en:
PIC24F
PIC24H
dsPIC30F dsPIC33F
x
x
Sintaxis: {etiqueta:} MAC Wm*Wm, Acc {,[Wx], Wxd}
{,[Wy], Wyd}
{,[Wx] + = kx, Wxd} {,[Wy] + = ky, Wyd}
{,[Wx] – = kx, Wxd} {,[Wy] – = ky, Wyd}
{,[W9 + W12], Wxd} {,[W11 + W12], Wyd}
Operandos:
Wm * Wm ∈ [W4 * W4, W5 * W5, W6 * W6, W7 * W7]
Acc ∈ [A,B]
Wx ∈ [W8, W9]; kx ∈ [-6, -4, -2, 2, 4, 6]; Wxd ∈ [W4 ... W7]
Wy ∈ [W10, W11]; ky ∈ [-6, -4, -2, 2, 4, 6]; Wyd ∈ [W4 ... W7]
Operación:
(Acc(A o B)) + (Wm) * (Wm) → Acc(A o B)
([Wx]) → Wxd; (Wx) + kx → Wx
([Wy]) → Wyd; (Wy) + ky → Wy
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1111
00mm
A0xx
yyii
iijj
jj00
Descripción:
Cuadrar el contenido de un registro de trabajo, opcionalmente buscar previamente operandos en 
preparación para otra instrucción de tipo MAC y, opcionalmente, almacenar la 
resultados del acumulador no especificados. El resultado de 32 bits de la multiplicación con signo es 
signo extendido a 40 bits y agregado al acumulador especificado. 
Los operandos Wx, Wxd, Wy y Wyd especifican operaciones de captación previa opcionales. 
que admiten direccionamiento indirecto y de compensación de registro, como se describe en 
Sección 4.14.1 “Capturas previas de MAC”.
Los bits ‘m’ seleccionan el registro de operando Wm para el cuadrado.
El bit ‘A’ selecciona el acumulador para el resultado. 
Los bits ‘x’ seleccionan el destino de captación previa Wxd.
Los bits ‘y’ seleccionan el destino Wyd de captación previa.
Los bits 'i' seleccionan la operación de captación previa de Wx.
Los bits 'j' seleccionan la operación de captación previa Wy.
Nota:
El bit IF, CORCON<0>, determina si la multiplicación es fraccionaria.
o un número entero.
Palabras:
1
Ciclos:
1

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 232
© 2009 Microchip Technology Inc.
Ejemplo 1:
MAC
W4*W4, B, [W9+W12], W4, [W10]-=2, W5 
; Cuadre W4 y agregue a ACCB
; Recuperar [W9+W12] a W4
; Recuperar [W10] a W5, posdisminuir W10 en 2
; CORCON = 0x00C0 (multiplicación fraccionaria, saturación normal)
 
antes 
Instrucción
después 
Instrucción
W4
 A022
W4
 A230
W5
 B200
W5
 650B
W9
 0C00
W9
   0C00
W10
 1900
W10
   18FE
W12
 0020
W12
   0020
ACCB
00 2000 0000
ACCB
00 67CD 0908
Datos 0C20
 A230
Datos 0C20
 A230
Datos 1900
 650B
Datos 1900
 650B
CORCÓN
 00C0
CORCÓN
 00C0
SR
 0000
SR
 0000
Ejemplo 2:
MAC
W7*W7, A, [W11]-=2, W7
; Cuadre W7 y agregue a ACCA 
; Recuperar [W11] a W7, posdisminuir W11 en 2
; CORCON = 0x00D0 (multiplicación fraccionaria, supersaturación)
antes 
Instrucción
después 
Instrucción
W7
 76AE
W7
 23FF
W11
 2000
W11
   1FFE
ACCA
FE 9834 4500
ACCA
FF 063E 0188
Datos 2000
 23FF
Datos 2000
 23FF
CORCÓN
 00D0
CORCÓN
 00D0
SR
 0000
SR
 8800 (OA, OAB = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 233
Instrucción 
Descripciones
5
      
MOVIMIENTO
Mover f al destino 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MOVIMIENTO{.B} 
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
f) → destino designado por D
Estado afectado:
norte, z
Codificación:
1011
1111
1HAB
ffff
ffff
ffff
Descripción:
Mueva el contenido del registro de archivo especificado al registro de destino.
El operando WREG opcional determina el registro de destino. si
Se especifica WREG, el resultado se almacena en WREG. Si WREG no es
especificado, el resultado se almacena en el registro de archivos y el único efecto es
para modificar el registro ESTADO.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0.
3: Al mover datos de palabras desde la memoria de registro de archivos, el botón “MOV f
a Wnd” (página 5-147) permite cualquier registro de trabajo
(W0:W15) como registro de destino.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MOV.B
TMR0, WREG
; mover (TMR0) a WREG (modo Byte)
antes 
Instrucción
después 
Instrucción
WREG (W0)
9080
WREG (W0)
 9055
TMR0
2355
TMR0
2355
SR
 0000
SR
 0000
Ejemplo 2:
MOVIMIENTO
0x800; actualizar SR basado en (0x800) (modo Word)
antes 
Instrucción
después 
Instrucción
Datos 0800
B29F
Datos 0800
B29F
SR
 0000
SR
 0008 (n = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 234
© 2009 Microchip Technology Inc.
    
MOVIMIENTO
Mover WREG a f 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MOVIMIENTO{.B} 
WREG,
f
Operandos:
f ∈ [0 ... 8191]
Operación:
(WREG) → f
Estado afectado:
Ninguno
Codificación:
1011
0111
1B1f
ffff
ffff
ffff
Descripción:
Mueva el contenido del registro de trabajo predeterminado WREG al 
registro de archivo especificado. 
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota un movimiento de byte en lugar de
que un movimiento de palabra. Puede utilizar una extensión .W para indicar una
movimiento de palabra, pero no es obligatorio.
2: El WREG está configurado en el registro de trabajo W0.
3: Al mover datos de palabras de la matriz de registros de trabajo al archivo
memoria de registros, la instrucción “MOV Wns to f” (página 5-148)
permite que cualquier registro de trabajo (W0:W15) sea el registro fuente.
ter.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MOV.B
WREG, 0x801; mueva WREG a 0x801 (modo Byte)
antes 
Instrucción
después 
Instrucción
WREG (W0)
98F3
WREG (W0)
98F3
Datos 0800
4509
Datos 0800
F309
SR
 0000
SR
0008
(norte = 1)
Ejemplo 2:
MOV WREG, DISICNT ; mover WREG a DISICNT
antes 
Instrucción
después 
Instrucción
WREG (W0)
00A0
WREG (W0)
00A0
DISICTO
0000
DISICTO
00A0
SR
 0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 235
Instrucción 
Descripciones
5
  
MOVIMIENTO
Mover f a Wnd 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MOVIMIENTO
f,
viento
Operandos:
f ∈ [0 ... 65534]
Viento ∈ [W0 ... W15]
Operación:
(f) → Viento
Estado afectado:
Ninguno
Codificación:
1000
0fff
ffff
ffff
ffff
dddd
Descripción:
Mueva el contenido de la palabra del registro de archivo especificado a Wnd. el archivo 
El registro puede residir en cualquier parte de las 32 K palabras de la memoria de datos, pero debe 
estar alineado con las palabras. Se debe utilizar el direccionamiento directo de registro para Wnd.
Los bits 'f' seleccionan la dirección del registro del archivo.
Los bits 'd' seleccionan el registro de destino.
Nota 1: Esta instrucción opera únicamente con operandos de palabra.
2: Dado que la dirección del registro del archivo debe estar alineada con palabras, solo la
Los 15 bits superiores de la dirección del registro del archivo están codificados (el bit 0 está codificado).
se supone que es ‘0’).
3: Para mover un byte de datos de la memoria del registro de archivos, el botón “MOV f
a Destino” (página 5-145) se puede utilizar.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MOV CORCON, W12 ; mover CORCON a W12
antes 
Instrucción
después 
Instrucción
W12
78FA
W12
00F0
CORCÓN
00F0
CORCÓN
00F0
SR
 0000
SR
0000
Ejemplo 2:
MOV 0x27FE, W3; mover (0x27FE) a W3
antes 
Instrucción
después 
Instrucción
W3
0035
W3
ABCD
Datos 27FE
ABCD
Datos 27FE
ABCD
SR
 0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 236
© 2009 Microchip Technology Inc.
  
MOVIMIENTO
Mover Wns a f 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MOVIMIENTO
WNS,
f
Operandos:
f ∈ [0 ... 65534]
Wns ∈ [W0 ... W15]
Operación:
(Wns) → f 
Estado afectado:
Ninguno
Codificación:
1000
1fff
ffff
ffff
ffff
sss
Descripción:
Mueva el contenido de la palabra del registro de trabajo Wns al archivo especificado 
registrarse. El registro del archivo puede residir en cualquier lugar de las 32 000 palabras de datos. 
memoria, pero debe estar alineado con las palabras. El direccionamiento directo del registro debe ser 
utilizado para Wn.
Los bits 'f' seleccionan la dirección del registro del archivo.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: Esta instrucción opera únicamente con operandos de palabra.
2: Dado que la dirección del registro del archivo debe estar alineada con palabras, solo la
Los 15 bits superiores de la dirección del registro del archivo están codificados (el bit 0 está codificado).
se supone que es ‘0’).
3: Para mover un byte de datos a la memoria de registro de archivos, el botón “MOV WREG
a f” (página 5-146) se puede utilizar.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MOV W4, XMDOSRT; mover W4 a XMODSRT
antes 
Instrucción
después 
Instrucción
W4
1200
W4
1200
XMODSRT
1340
XMODSRT
1200
SR
 0000
SR
0000
Ejemplo 2:
MOV W8, 0x1222; mover W8 a la dirección de datos 0x1222
antes 
Instrucción
después 
Instrucción
W8
F200
W8
F200
Datos 1222
FD88
Datos 1222
F200
SR
 0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 237
Instrucción 
Descripciones
5
  
MOV.B
Mover literal de 8 bits a Wnd
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MOV.B
#lit8,
viento
Operandos:
lit8 ∈ [0 ... 255] 
Viento ∈ [W0 ... W15]
Operación:
lit8 → Viento
Estado afectado:
Ninguno
Codificación: 
1011
0011
1100
kkkk
kkkk
dddd
Descripción:
El literal de 8 bits sin signo 'k' se carga en el byte inferior de Wnd. el 
El byte superior de Wnd no se modifica. El direccionamiento directo del registro debe ser 
utilizado para viento.
Los bits 'k' especifican el valor del literal.
Los bits 'd' seleccionan la dirección del registro de trabajo.
Nota:
Esta instrucción opera en modo Byte y la extensión .B
debe ser proporcionado.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MOV.B #0x17, W5; cargue W5 con #0x17 (modo Byte)
antes 
Instrucción
después 
Instrucción
W5
7899
W5
7817
SR
 0000
SR
0000
Ejemplo 2:
MOV.B #0xFE, W9; cargar W9 con #0xFE (modo Byte)
antes 
Instrucción
después 
Instrucción
W9
AB23
W9
ABFE
SR
 0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 238
© 2009 Microchip Technology Inc.
 
MOVIMIENTO
Mover literal de 16 bits a Wnd 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MOVIMIENTO 
#lit16,
viento
Operandos:
iluminado16 ∈ [-32768 ... 65535]
Viento ∈ [W0 ... W15]
Operación:
lit16 → Viento
Estado afectado:
Ninguno
Codificación: 
0010
kkkk
kkkk
kkkk
kkkk
dddd
Descripción:
El literal de 16 bits 'k' se carga en Wnd. Registrar el direccionamiento directo debe 
ser utilizado para Wnd. 
Los bits 'k' especifican el valor del literal.
Los bits 'd' seleccionan la dirección del registro de trabajo.
Nota 1: Esta instrucción funciona sólo en modo Word.
2: El literal se puede especificar como un valor con signo [-32768:32767],
o valor sin signo [0:65535].
Palabras:
1
Ciclos:
1
Ejemplo 1:
MOV #0x4231, W13; cargar W13 con #0x4231
antes 
Instrucción
después 
Instrucción
W13
091B
W13
4231
SR
 0000
SR
0000
Ejemplo 2:
MOV #0x4, W2; cargar W2 con #0x4
antes 
Instrucción
después 
Instrucción
W2
B004
W2
0004
SR
 0000
SR
0000
Ejemplo 3:
MOV #-1000, W8; cargar W8 con #-1000
antes 
Instrucción
después 
Instrucción
W8
23FF
W8
FC18
SR
 0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 239
Instrucción 
Descripciones
5
 
MOVIMIENTO 
Mover [Ws con desplazamiento] a Wnd
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MOVIMIENTO{.B} 
[Ws + Rendija10], Viento
Operandos:
Ws ∈ [W0 ... W15]
Slit10 ∈ [-512 ... 511] para operación de bytes
Slit10 ∈ [-1024 ... 1022] (solo pares) para operación de palabra
Viento ∈ [W0 ... W15]
Operación:
[Ws + Slit10] → Wnd
Estado afectado:
Ninguno
Codificación: 
1001
0kkk
kBkk
kddd
dkkk
sss
Descripción:
El contenido de [Ws + Slit10] se carga en Wnd. En el modo Word, el 
El rango de Slit10 se incrementa a [-1024 ... 1022] y Slit10 debe estar parejo a 
mantener la alineación de la dirección de la palabra. El direccionamiento indirecto del registro debe ser 
Se debe utilizar el direccionamiento directo para la fuente y el direccionamiento directo para Wnd.
Los bits 'k' especifican el valor del literal.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits 'd' seleccionan el registro de destino.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: La extensión .B en la instrucción denota un movimiento de byte en lugar de
que un movimiento de palabra. Puede utilizar una extensión .W para indicar una
movimiento de palabra, pero no es obligatorio.
2: En modo Byte, el rango de Slit10 no se reduce como se especifica en
Sección 4.6 “Uso de operandos literales de 10 bits”, ya que el literal
representa una dirección desplazada de Ws.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MOV.B [W8+0x13], W10
; cargar W10 con [W8+0x13]
                        ; (modo bytes)
antes 
Instrucción
después 
Instrucción
W8
1008
W8
1008
W10
4009
W10
4033
Datos 101A
3312
Datos 101A
3312
SR
 0000
SR
0000
Ejemplo 2:
MOVIMIENTO [W4+0x3E8], W2
; cargar W2 con [W4+0x3E8] 
                       ; (modo palabra)
antes 
Instrucción
después 
Instrucción
W2
9088
W2
5634
W4
0800
W4
0800
Datos 0BE8
5634
Datos 0BE8
5634
SR
 0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 240
© 2009 Microchip Technology Inc.
 
MOVIMIENTO
Mover Wns a [Wd con desplazamiento]
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MOVIMIENTO{.B} 
WNS,
[Wd + Rendija10]
Operandos:
Wns ∈ [W0 ... W15]
Slit10 ∈ [-512 ... 511] en modo Byte
Slit10 ∈ [-1024 ... 1022] (solo pares) en modo Word
Wd ∈ [W0 ... W15]
Operación:
(Wns) → [Wd + Rendija10]
Estado afectado:
Ninguno
Codificación: 
1001
1kkk
kBkk
kddd
dkkk
sss
Descripción:
El contenido de Wns se almacena en [Wd + Slit10]. En modo Word, el rango 
de Slit10 se incrementa a [-1024 ... 1022] y Slit10 debe ser par a 
mantener la alineación de la dirección de la palabra. El direccionamiento directo del registro debe ser 
Se debe usar direccionamiento indirecto para Wns y para el destino.
Los bits 'k' especifican el valor del literal.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits 'd' seleccionan el registro de destino.
Los bits ‘s’ seleccionan la dirección del registro de destino.
Nota 1: La extensión .B en la instrucción denota un movimiento de byte en lugar de
que un movimiento de palabra. Puede utilizar una extensión .W para indicar una
movimiento de palabra, pero no es obligatorio.
2: En modo Byte, el rango de Slit10 no se reduce como se especifica en
Sección 4.6 “Uso de operandos literales de 10 bits”, ya que el literal
representa una dirección desplazada de Wd.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MOV.B
W0, [W1+0x7]; almacenar W0 en [W1+0x7]
                       ; (modo bytes)
antes 
Instrucción
después 
Instrucción
W0
9015
W0
9015
W1
1800
W1
1800
Datos 1806
2345
Datos 1806
1545
SR
 0000
SR
0000
Ejemplo 2:
MOVIMIENTO
W11, [W1-0x400]; almacenar W11 en [W1-0x400] 
                       ; (modo palabra)
antes 
Instrucción
después 
Instrucción
W1
1000
W1
1000
W11
8813
W11
8813
Datos 0C00
FFEA
Datos 0C00
8813
SR
 0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 241
Instrucción 
Descripciones
5
  
MOVIMIENTO
Mover Ws a Wd
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MOVIMIENTO{.B} 
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[--Ws],
[--Wd]
[++Ws],
[++Wd]
[Ws + Wb], [Wd + Wb]
Operandos:
Ws ∈ [W0 ... W15]
Wb ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Ws) → Wd
Estado afectado:
Ninguno
Codificación:
0111
1www
wbhh
disco duro
dggg
sss
Descripción:
Mueva el contenido del registro de origen al registro de destino. 
Se puede utilizar el direccionamiento directo o indirecto de registro para Ws y Wd.
Los bits 'w' definen el registro de compensación Wb.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘h’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘g’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: La extensión .B en la instrucción denota un movimiento de byte en lugar de
que un movimiento de palabra. Puede utilizar una extensión .W para indicar una
movimiento de palabra, pero no es obligatorio.
2: Cuando se utiliza el modo de direccionamiento de compensación de registro tanto para el
origen y destino, el desplazamiento debe ser el mismo porque
los bits de codificación 'w' son compartidos por Ws y Wd.
3: La instrucción “PUSH Ws” se traduce a MOV Ws, [W15++].
4: La instrucción “POP Wd” se traduce a MOV [--W15], Wd.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MOV.B [W0--], W4
; Mueva [W0] a W4 (modo Byte)
                    ; W0 posterior a la disminución
antes 
Instrucción
después 
Instrucción
W0
0A01
W0
0A00
W4
2976
W4
2989
Datos 0A00
8988
Datos 0A00
8988
SR
 0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 242
© 2009 Microchip Technology Inc.
Ejemplo 2:
MOVIMIENTO
[W6++], [W2+W3]; Mueva [W6] a [W2+W3] (modo Palabra)
                       ; W6 posterior al incremento
antes 
Instrucción
después 
Instrucción
W2
0800
W2
0800
W3
0040
W3
0040
W6
1228
W6
122A
Data 0840
9870
Datos 0840
0690
Datos 1228
0690
Datos 1228
0690
SR
 0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 243
Instrucción 
Descripciones
5
  
MOV.D
Mover palabra doble desde el origen al viento
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MOV.D
WNS,
viento
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Wns ∈ [W0, W2, W4 ... W14]
Ws ∈ [W0 ... W15]
Viento ∈ [W0, W2, W4 ... W14]
Operación:
Para direccionamiento directo de la fuente:
    Wns → Wnd
    Wns + 1 → Wnd + 1
Para direccionamiento indirecto de la fuente:
    Ver descripción
Estado afectado:
Ninguno
Codificación:
1011
1110
0000
0ddd
0ppp
sss
Descripción:
Mueve la palabra doble especificada por el origen a un destino que funcione 
par de registros (Wnd:Wnd + 1). Si se utiliza el direccionamiento directo de registro para la 
fuente, el contenido de dos registros de trabajo sucesivos (Wns:Wns + 1) 
se mueven a Wnd:Wnd + 1. Si se utiliza direccionamiento indirecto para la fuente, 
Ws especifica la dirección efectiva para la palabra menos significativa del 
doble palabra. Cualquier pre/post-incremento o pre/post-decremento ajustará Ws 
por 4 bytes para dar cabida a la palabra doble.
Los bits 'd' seleccionan el registro de destino. 
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan la dirección del primer registro fuente.
Nota 1: Esta instrucción solo opera con palabras dobles. Ver Figura 4-3
para obtener información sobre cómo se alinean las palabras dobles en la memoria.
2: Wnd debe ser un registro par que funcione.
3: La instrucción “POP.D Wnd” se traduce a MOV.D [--W15],
Viento.
Palabras:
1
Ciclos:
2
Ejemplo 1:
MOV.D W2, W6; Mover W2 a W6 (modo doble)
antes 
Instrucción
después 
Instrucción
W2
12FB
W2
12FB
W3
9877
W3
9877
W6
9833
W6
12FB
W7
FCC6
W7
9877
SR
 0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 244
© 2009 Microchip Technology Inc.
Ejemplo 2:
MOV.D
[W7--], W4
; Mueva [W7] a W4 (modo doble) 
                   ; W7 posterior a la disminución
antes 
Instrucción
después 
Instrucción
W4
B012
W4
A319
W5
FD89
W5
9927
W7
0900
W7
08FC
Datos 0900
A319
Datos 0900
A319
Datos 0902
9927
Datos 0902
9927
SR
 0000
SR
0000

© 2009 Microchip Technology Inc.
DS70157D-página 245
Instrucción 
Descripciones
5
 
MOVSAC
Operandos de captación previa y acumulador de almacenamiento
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis: {etiqueta:} MOVSAC
Acc
{,[Anx], Anxd}
{,[Wy], Wyd}
{,AWB}
{,[Wx] + = kx, Wxd} {,[Wy] + = ky, Wyd}
{,[Wx] – = kx, Wxd} {,[Wy] – = ky, Wyd}
{,[W9 + W12], Wxd} {,[W11 + W12], Wyd}
Operandos:
Acc ∈ [A,B]
Wx ∈ [W8, W9]; kx ∈ [-6, -4, -2, 2, 4, 6]; Wxd ∈ [W4 ... W7]
Wy ∈ [W10, W11]; ky ∈ [-6, -4, -2, 2, 4, 6]; Wyd ∈ [W4 ... W7]
AWB ∈ [W13, [W13] + = 2]
Operación:
([Wx]) → Wxd; (Wx) + kx → Wx
([Wy]) → Wyd; (Wy) + ky → Wy
(Acc(B o A)) redondeado → AWB
Estado afectado:
Ninguno
Codificación:
1100
0111
A0xx
yyii
iijj
jjaa
Descripción:
Opcionalmente, precarga operandos en preparación para otro tipo de MAC 
instrucción y, opcionalmente, almacenar los resultados del acumulador no especificado. incluso 
Aunque no se realiza una operación del acumulador en esta instrucción, se 
Se debe especificar el acumulador para designar qué acumulador escribir. 
atrás. 
Los operandos Wx, Wxd, Wy y Wyd especifican operaciones de captación previa opcionales. 
que admiten direccionamiento indirecto y de compensación de registro, como se describe en 
Sección 4.14.1 “Capturas previas de MAC”. El operando AWB especifica el opcional 
almacenamiento del acumulador “otro”, como se describe en 
Sección 4.14.4 “Escritura MAC”.
El bit ‘A’ selecciona el otro acumulador utilizado para la reescritura.
Los bits ‘x’ seleccionan el destino de captación previa Wxd.
Los bits ‘y’ seleccionan el destino Wyd de captación previa.
Los bits 'i' seleccionan la operación de captación previa de Wx.
Los bits 'j' seleccionan la operación de captación previa Wy.
Los bits ‘a’ seleccionan el destino de escritura posterior del acumulador.
Palabras:
1
Ciclos:
1

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 246
© 2009 Microchip Technology Inc.
Ejemplo 1:
MOVSAC
B, [W9], W6, [W11]+=4, W7, W13
; Recuperar [W9] a W6
; Recuperar [W11] a W7, post-incremento W11 en 4
; Almacenar ACCA en W13
                               
antes 
Instrucción
después 
Instrucción
W6
 A022
W6
 7811
W7
 B200
W7
 B2AF
W9
 0800
W9
   0800
W11
 1900
W11
   1904
W13
 0020
W13
   3290
ACCA
00 3290 5968
ACCA
00 3290 5968
Datos 0800
 7811
Datos 0800
 7811
Datos 1900
 B2AF
Datos 1900
 B2AF
SR
 0000
SR
 0000
Ejemplo 2:
MOVSAC
A, [W9]-=2, W4, [W11+W12], W6, [W13]+=2
; Recuperar [W9] a W4, posdisminuir W9 en 2
; Recuperar [W11+W12] a W6
; Almacene ACCB en [W13], incremente W13 en 2
antes 
Instrucción
después 
Instrucción
W4
 76AE
W4
 BB00
W6
 2000
W6
   52 CE
W9
 1200
W9
 11FE
W11
 2000
W11
   2000
W12
 0024
W12
0024
W13
 2300
W13
   2302
ACCB
00 9834 4500
ACCB
00 9834 4500
Datos 1200
 BB00
Datos 1200
 BB00
Datos 2024
 52 CE
Datos 2024
 52 CE
Datos 2300
 23FF
Datos 2300
 9834
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 247
Instrucción 
Descripciones
5
 
MPY
Multiplique Wm por Wn al acumulador 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis: {etiqueta:} MPY 
Wm * Wn, 
Acc
{,[Anx], Anxd}
{,[Wy], Wyd}
{,[Wx] + = kx, Wxd}
{,[Wy] + = ky, Wyd}
{,[Wx] – = kx, Wxd} {,[Wy] – = ky, Wyd}
{,[W9 + W12], Wxd} {,[W11 + W12], Wyd}
Operandos:
Wm * Wn ∈ [W4 * W5, W4 * W6, W4 * W7, W5 * W6, W5 * W7, W6 * W7]
Acc ∈ [A,B]
Wx ∈ [W8, W9]; kx ∈ [-6, -4, -2, 2, 4, 6]; Wxd ∈ [W4 ... W7]
Wy ∈ [W10, W11]; ky ∈ [-6, -4, -2, 2, 4, 6]; Wyd ∈ [W4 ... W7]
AWB ∈ [W13], [W13] + = 2
Operación:
(Wm) * (Wn) → Acc(A o B)
([Wx]) → Wxd; (Wx) + kx → Wx
([Wy]) → Wyd; (Wy) + ky → Wy
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1100
0mmmm
A0xx
yyii
iijj
jj11
Descripción:
Multiplicar el contenido de dos registros de trabajo, opcionalmente captar previamente 
operandos en preparación para otra instrucción de tipo MAC y opcionalmente 
almacenar los resultados del acumulador no especificado. El resultado de 32 bits del firmado. 
multiplicar se extiende con signos a 40 bits y se almacena en el valor especificado 
acumulador. 
Los operandos Wx, Wxd, Wy y Wyd especifican operaciones de captación previa opcionales. 
que admiten direccionamiento indirecto y de compensación de registro, como se describe en 
Sección 4.14.1 “Capturas previas de MAC”.
Los bits ‘m’ seleccionan los registros de operandos Wm y Wn para la multiplicación:
El bit ‘A’ selecciona el acumulador para el resultado.
Los bits ‘x’ seleccionan el destino de captación previa Wxd.
Los bits ‘y’ seleccionan el destino Wyd de captación previa.
Los bits 'i' seleccionan la operación de captación previa de Wx.
Los bits 'j' seleccionan la operación de captación previa Wy.
Nota:
El bit IF, CORCON<0>, determina si la multiplicación es 
fraccionario o un número entero.
Palabras:
1
Ciclos:
1

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 248
© 2009 Microchip Technology Inc.
Ejemplo 1:
MPY
W4*W5, A, [W8]+=2, W6, [W10]-=2, W7
; Multiplique W4*W5 y guárdelo en ACCA
; Recuperar [W8] a W6, post-incrementar W8 en 2
; Recuperar [W10] a W7, posdisminuir W10 en 2
; CORCON = 0x0000 (multiplicación fraccionaria, sin saturación)
                               
antes 
Instrucción
después 
Instrucción
W4
 C000
W4
 C000
W5
 9000
W5
 9000
W6
 0800
W6
   671F
W7
 B200
W7
 E3DC
W8
 1780
W8
   1782
W10
 2400
W10
   23FE
ACCA
FF F780 2087
ACCA
00 3800 0000
Datos 1780
 671F
Datos 1780
 671F
Datos 2400
 E3DC
Datos 2400
 E3DC
CORCÓN
 0000
CORCÓN
 0000
SR
 0000
SR
 0000
Ejemplo 2:
MPY
W6*W7, B, [W8]+=2, W4, [W10]-=2, W5
; Multiplique W6*W7 y guárdelo en ACCB
; Recuperar [W8] a W4, post-incrementar W8 en 2 
; Recuperar [W10] a W5, posdisminuir W10 en 2
; CORCON = 0x0000 (multiplicación fraccionaria, sin saturación)
antes 
Instrucción
después 
Instrucción
W4
 C000
W4
 8FDC
W5
 9000
W5
 0078
W6
 671F
W6
   671F
W7
 E3DC
W7
 E3DC
W8
 1782
W8
   1784
W10
 23FE
W10
   23FC
ACCB
00 9834 4500
ACCB
FF E954 3748
Datos 1782
 8FDC
Datos 1782
 8FDC
Datos 23FE
 0078
Datos 23FE
 0078
CORCÓN
 0000
CORCÓN
 0000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 249
Instrucción 
Descripciones
5
  
MPY
Cuadrado a acumulador
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis: {etiqueta:} MPY
Wm * Wm, Acc {,[Wx], Wxd}
{,[Wy], Wyd}
{,[Wx] + = kx, Wxd} {,[Wy] + = ky, Wyd}
{,[Wx] – = kx, Wxd} {,[Wy] – = ky, Wyd}
{,[W9 + W12], Wxd} {,[W11 + W12], Wyd}
Operandos:
Wm * Wm ∈ [W4 * W4, W5 * W5, W6 * W6, W7 * W7]
Acc ∈ [A,B]
Wx ∈ [W8, W9]; kx ∈ [-6, -4, -2, 2, 4, 6]; Wxd ∈ [W4 ... W7]
Wy ∈ [W10, W11]; ky ∈ [-6, -4, -2, 2, 4, 6]; Wyd ∈ [W4 ... W7]
Operación:
(Wm) * (Wm) → Acc(A o B)
([Wx]) → Wxd; (Wx) + kx → Wx
([Wy]) → Wyd; (Wy) + ky → Wy
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1111
00mm
A0xx
yyii
iijj
jj01
Descripción:
Cuadrar el contenido de un registro de trabajo, opcionalmente buscar previamente operandos en 
preparación para otra instrucción de tipo MAC y, opcionalmente, almacenar la 
resultados del acumulador no especificados. El resultado de 32 bits de la multiplicación con signo es 
signo extendido a 40 bits y almacenado en el acumulador especificado. 
Los operandos Wx, Wxd, Wy y Wyd especifican operaciones de captación previa opcionales. 
que admiten direccionamiento indirecto y de compensación de registro, como se describe en 
Sección 4.14.1 “Capturas previas de MAC”.
Los bits ‘m’ seleccionan el registro de operando Wm para el cuadrado.
El bit ‘A’ selecciona el acumulador para el resultado.
Los bits ‘x’ seleccionan el destino de captación previa Wxd.
Los bits ‘y’ seleccionan el destino Wyd de captación previa.
Los bits 'i' seleccionan la operación de captación previa de Wx.
Los bits 'j' seleccionan la operación de captación previa Wy.
Nota:
El bit IF, CORCON<0>, determina si la multiplicación es 
fraccionario o un número entero.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MPY
W6*W6, A, [W9]+=2, W6
; Cuadre W6 y almacene en ACCA
; Recuperar [W9] a W6, post-incrementar W9 en 2
; CORCON = 0x0000 (multiplicación fraccionaria, sin saturación)
                               
antes 
Instrucción
después 
Instrucción
W6
 6500
W6
   B865
W9
 0900
W9
   0902
ACCA
00 7C80 0908
ACCA
00 4FB2 0000
Datos 0900
 B865
Datos 0900
 B865
CORCÓN
 0000
CORCÓN
 0000
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 250
© 2009 Microchip Technology Inc.
Ejemplo 2:
MPY
W4*W4, B, [W9+W12], W4, [W10]+=2, W5
; Cuadrar W4 y almacenar en ACCB
; Recuperar [W9+W12] a W4
; Recuperar [W10] a W5, post-incrementar W10 en 2
; CORCON = 0x0000 (multiplicación fraccionaria, sin saturación)
antes 
Instrucción
después 
Instrucción
W4
 E228
W4
 8911
W5
 9000
W5
 F678
W9
 1700
W9
 1700
W10
 1B00
W10
   1B02
W12
 FF00
W12
   FF00
ACCB
00 9834 4500
ACCB
00 06F5 4C80
Datos 1600
 8911
Datos 1600
 8911
Datos 1B00
 F678
Datos 1B00
 F678
CORCÓN
 0000
CORCÓN
 0000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 251
Instrucción 
Descripciones
5
  
MPY.N
Multiplicar -Wm por Wn al acumulador 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis: {etiqueta:} MPY.N Wm * Wn, Acc {,[Wx], Wxd}
{,[Wy], Wyd}
{,[Wx] + = kx, Wxd} {,[Wy] + = ky, Wyd}
{,[Wx] – = kx, Wxd} {,[Wy] – = ky, Wyd}
{,[W9 + W12], Wxd} {,[W11 + W12], Wyd}
Operandos:
Wm * Wn ∈ [W4 * W5; W4 * W6; W4 * W7; W5 * W6; W5 * W7; W6 * W7]
Acc ∈ [A,B]
Wx ∈ [W8, W9]; kx ∈ [-6, -4, -2, 2, 4, 6]; Wxd ∈ [W4 ... W7]
Wy ∈ [W10, W11]; ky ∈ [-6, -4, -2, 2, 4, 6]; Wyd ∈ [W4 ... W7]
Operación:
-(Wm) * (Wn) → Acc(A o B)
([Wx]) → Wxd; (Wx) + kx → Wx
([Wy]) → Wyd; (Wy) + ky → Wy
Estado afectado:
OA, OB, OAB
Codificación:
1100
0mmmm
A1xx
yyii
iijj
jj11
Descripción:
Multiplicar el contenido de un registro de trabajo por el negativo del contenido. 
de otro registro de trabajo, opcionalmente buscar previamente operandos en preparación para 
otra instrucción de tipo MAC y, opcionalmente, almacenar el no especificado 
resultados del acumulador. El resultado de 32 bits de la multiplicación con signo es 
signo extendido a 40 bits y almacenado en el acumulador especificado. 
Los bits ‘m’ seleccionan los registros de operandos Wm y Wn para la multiplicación.
El bit ‘A’ selecciona el acumulador para el resultado.
Los bits ‘x’ seleccionan el destino de captación previa Wxd.
Los bits ‘y’ seleccionan el destino Wyd de captación previa.
Los bits 'i' seleccionan la operación de captación previa de Wx.
Los bits 'j' seleccionan la operación de captación previa Wy.
Nota:
El bit IF, CORCON<0>, determina si la multiplicación es fraccionaria.
o un número entero.
Palabras:
1
Ciclos:
1

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 252
© 2009 Microchip Technology Inc.
Ejemplo 1:
MPY.N
W4*W5, A, [W8]+=2, W4, [W10]+=2, W5
; Multiplique W4*W5, niegue el resultado y guárdelo en ACCA
; Recuperar [W8] a W4, post-incrementar W8 en 2
; Recuperar [W10] a W5, post-incrementar W10 en 2
; CORCON = 0x0001 (multiplicación de números enteros, sin saturación)
   
antes 
Instrucción
después 
Instrucción
W4
 3023
W4
   0054
W5
 1290
W5
   660A
W8
 0B00
W8
   0B02
W10
 2000
W10
   2002
ACCA
00 0000 2387
ACCA
FF FC82 7650
Datos 0B00
 0054
Datos 0B00
 0054
Datos 2000
 660A
Datos 2000
 660A
CORCÓN
 0001
CORCÓN
 0001
SR
 0000
SR
 0000
Ejemplo 2:
MPY.N
W4*W5, A, [W8]+=2, W4, [W10]+=2, W5
; Multiplique W4*W5, niegue el resultado y guárdelo en ACCA
; Recuperar [W8] a W4, post-incrementar W8 en 2 
; Recuperar [W10] a W5, post-incrementar W10 en 2
; CORCON = 0x0000 (multiplicación fraccionaria, sin saturación)
 
antes 
Instrucción
después 
Instrucción
W4
 3023
W4
   0054
W5
 1290
W5
   660A
W8
 0B00
W8
   0B02
W10
 2000
W10
   2002
ACCA
00 0000 2387
ACCA
FF F904 ECA0
Datos 0B00
 0054
Datos 0B00
 0054
Datos 2000
 660A
Datos 2000
 660A
CORCÓN
 0000
CORCÓN
 0000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 253
Instrucción 
Descripciones
5
  
MSC
Multiplicar y restar del acumulador
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis: {etiqueta:} MSC
Wm * Wn, Acc {,[Wx], Wxd}
{,[Wy], Wyd}
{,AWB}
{,[Wx] + = kx, Wxd} {,[Wy] + = ky, Wyd}
{,[Wx] – = kx, Wxd} {,[Wy] – = ky, Wyd}
{,[W9 + W12], Wxd} {,[W11 + W12], Wyd}
Operandos:
Wm * Wn ∈ [W4 * W5, W4 * W6, W4 * W7, W5 * W6, W5 * W7, W6 * W7]
Acc ∈ [A,B]
Wx ∈ [W8, W9]; kx ∈ [-6, -4, -2, 2, 4, 6]; Wxd ∈ [W4 ... W7]
Wy ∈ [W10, W11]; ky ∈ [-6, -4, -2, 2, 4, 6]; Wyd ∈ [W4 ... W7]
AWB ∈ [W13, [W13] + = 2]
Operación:
(Acc(A o B)) − (Wm) * (Wn) → Acc(A o B)
([Wx]) → Wxd; (Wx) + kx → Wx
([Wy]) → Wyd; (Wy) + ky → Wy
(Acc(B o A)) redondeado → AWB
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1100
0mmmm
A1xx
yyii
iijj
jjaa
Descripción:
Multiplicar el contenido de dos registros de trabajo, opcionalmente captar previamente 
operandos en preparación para otra instrucción de tipo MAC y opcionalmente 
almacenar los resultados del acumulador no especificado. El resultado de 32 bits del firmado. 
multiplicar se extiende con signos a 40 bits y se resta del valor especificado 
acumulador.
Los operandos Wx, Wxd, Wy y Wyd especifican operaciones de captación previa opcionales. 
que admiten direccionamiento indirecto y de compensación de registro como se describe en 
Sección 4.14.1 “Capturas previas de MAC”. El operando AWB especifica el opcional 
almacenamiento del acumulador “otro” como se describe en 
Sección 4.14.4 “Escritura MAC”.
Los bits ‘m’ seleccionan los registros de operandos Wm y Wn para la multiplicación.
El bit ‘A’ selecciona el acumulador para el resultado.
Los bits ‘x’ seleccionan el destino de captación previa Wxd.
Los bits ‘y’ seleccionan el destino Wyd de captación previa.
Los bits 'i' seleccionan la operación de captación previa de Wx.
Los bits 'j' seleccionan la operación de captación previa Wy.
Los bits ‘a’ seleccionan el destino de escritura posterior del acumulador.
Nota:
El bit IF, CORCON<0>, determina si la multiplicación es 
fraccionario o un número entero.
Palabras:
1
Ciclos:
1

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 254
© 2009 Microchip Technology Inc.
Ejemplo 1:
MSC
W6*W7, A, [W8]-=4, W6, [W10]-=4, W7
; Multiplica W6*W7 y resta el resultado de ACCA
; Recuperar [W8] a W6, posdisminuir W8 en 4
; Recuperar [W10] a W7, posdisminuir W10 en 4
; CORCON = 0x0001 (multiplicación de números enteros, sin saturación)
   
antes 
Instrucción
después 
Instrucción
W6
 9051
W6
   D309
W7
 7230
W7
   100B
W8
 0C00
W8
   0BFC
W10
 1C00
W10
   1BFC
ACCA
00 0567 8000
ACCA
00 3738 5ED0
Datos 0C00
 D309
Datos 0C00
 D309
Datos 1C00
 100B
Datos 1C00
 100B
CORCÓN
 0001
CORCÓN
 0001
SR
 0000
SR
 0000
Ejemplo 2:
MSC
W4*W5, B, [W11+W12], W5, W13
; Multiplica W4*W5 y resta el resultado de ACCB
; Recuperar [W11+W12] a W5
; Escribir ACCA en W13
; CORCON = 0x0000 (multiplicación fraccionaria, sin saturación)
                               
antes 
Instrucción
después 
Instrucción
W4
 0500
W4
   0500
W5
 2000
W5
   3579
W11
 1800
W11
   1800
W12
 0800
W12
   0800
W13
 6233
W13
   3738
ACCA
00 3738 5ED0
ACCA
00 3738 5ED0
ACCB
00 1000 0000
ACCB
00 0EC0 0000
Datos 2000
 3579
Datos 2000
 3579
CORCÓN
 0000
CORCÓN
 0000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 255
Instrucción 
Descripciones
5
MUL
Entero sin signo multiplicar f y WREG 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MUL{.B} 
f
Operandos:
f ∈ [0 ... 8191]
Operación:
Para operación de bytes:
    (WREG)<7:0> * (f)<7:0> → W2
Para operación de palabras:
    (WREG) * (f) → W2:W3
Estado afectado:
Ninguno
Codificación:
1011
1100
0B0f
ffff
ffff
ffff
Descripción:
Multiplique el registro de trabajo predeterminado WREG con el archivo especificado 
regístrese y coloque el resultado en el par de registros W2:W3. Ambos operandos 
y el resultado se interpreta como enteros sin signo. Si esta instrucción es 
ejecutado en modo Byte, el resultado de 16 bits se almacena en W2. En modo Palabra, 
la palabra más significativa del resultado de 32 bits se almacena en W3, y la 
La palabra menos significativa del resultado de 32 bits se almacena en W2.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0. 
3: El bit IF, CORCON<0>, no tiene ningún efecto en esta operación.
4: Esta es la única instrucción que proporciona un 8 bits 
multiplicar.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MUL.B
0x800; Multiplicar (0x800)*WREG (modo Byte)
antes 
Instrucción
después 
Instrucción
WREG (W0)
9823
WREG (W0)
9823
W2
FFFFF
W2
13B0
W3
FFFFF
W3
FFFFF
Datos 0800
2690
Datos 0800
2690
SR
 0000
SR
0000
 
Ejemplo 2:
MUL
TMR1; Multiplicar (TMR1)*WREG (modo Palabra)
antes 
Instrucción
después 
Instrucción
WREG (W0)
F001
WREG (W0)
F001
W2
0000
W2
C287
W3
0000
W3
2F5E
TMR1
3287
TMR1
3287
SR
 0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 256
© 2009 Microchip Technology Inc.
 
MUL.SS
Entero 16x16 bits Multiplicación con signo
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MUL.SS 
Wb,
Ws,
viento
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15] 
Viento ∈ [W0, W2, W4 ... W12]
Operación:
con signo (Wb) * con signo (Ws) → Wnd:Wnd + 1
Estado afectado:
Ninguno
Codificación:
1011
1001
1www
wdddd
dppp
sss
Descripción:
Multiplique el contenido de Wb por el contenido de Ws y almacene el archivo de 32 bits. 
resultan en dos registros de trabajo sucesivos. La palabra menos significativa de 
el resultado se almacena en Wnd (que debe ser un número par de trabajo 
registro), y la palabra más significativa del resultado se almacena en 
Wnd + 1. Tanto los operandos fuente como el resultado Wnd se interpretan como 
Enteros con signo en complemento a dos. El direccionamiento directo del registro debe ser 
utilizado para Wb y Wnd. Registrar direccionamiento directo o registrar direccionamiento indirecto 
puede usarse para Ws.
Los bits ‘w’ seleccionan la dirección del registro base.
Los bits 'd' seleccionan la dirección del registro de destino inferior.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: Esta instrucción funciona únicamente en modo Word.
2: Dado que el producto de la multiplicación es de 32 bits, Wnd debe ser
un registro de trabajo uniforme. Consulte la Figura 4-2 para obtener información sobre
Cómo se alinean las palabras dobles en la memoria.
3: Es posible que Wnd no sea W14, ya que W15<0> está fijado en cero. 
4: El bit IF, CORCON<0>, no tiene ningún efecto en esta operación.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MUL.SS
W0, W1, W12; Multiplicar W0*W1
                      ; Guarde el resultado en W12:W13
antes 
Instrucción
después 
Instrucción
W0
 9823
W0
 9823
W1
 67DC
W1
 67DC
W12
 FFFFF
W12
 D314
W13
 FFFFF
W13
 D5DC
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 257
Instrucción 
Descripciones
5
Ejemplo 2:
MUL.SS
W2, [--W4], W0; Pre-decremento W4
                         ; Multiplicar W2*[W4]
                         ; Guarde el resultado en W0:W1
antes 
Instrucción
después 
Instrucción
W0
FFFFF
W0
28F8
W1
FFFFF
W1
0000
W2
0045
W2
0045
W4
27FE
W4
27FC
Datos 27FC
0098
Datos 27FC
0098
SR
 0000
SR
0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 258
© 2009 Microchip Technology Inc.
 
MUL.SU
Entero 16x16 bits Multiplicación literal corta con signo-sin signo
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MUL.SU
Wb,
#lit5,
viento
Operandos:
Wb ∈ [W0 ... W15]
iluminado5 ∈ [0 ... 31]
Viento ∈ [W0, W2, W4 ... W12]
Operación:
firmado (Wb) * sin firmar lit5 → Wnd:Wnd + 1
Estado afectado:
Ninguno
Codificación:
1011
1001
0www
wdddd
d11k
kkkk
Descripción:
Multiplique el contenido de Wb por el literal de 5 bits y almacene el de 32 bits. 
resultan en dos registros de trabajo sucesivos. La palabra menos significativa de 
el resultado se almacena en Wnd (que debe ser un número par de trabajo 
registro), y la palabra más significativa del resultado se almacena en Wnd + 1. 
El operando Wb y el resultado Wnd se interpretan como dos 
complemento entero con signo. El literal se interpreta como una intersección sin firmar.
ger. Se debe utilizar el direccionamiento directo de registro para Wb y Wnd.
Los bits ‘w’ seleccionan la dirección del registro base.
Los bits 'd' seleccionan la dirección del registro de destino inferior.
Los bits 'k' definen un literal entero sin signo de 5 bits.
Nota 1: Esta instrucción funciona únicamente en modo Word.
2: Dado que el producto de la multiplicación es de 32 bits, Wnd debe ser
un registro de trabajo uniforme. Consulte la Figura 4-3 para obtener información sobre
Cómo se alinean las palabras dobles en la memoria.
3: Es posible que Wnd no sea W14, ya que W15<0> está fijado en cero. 
4: El bit IF, CORCON<0>, no tiene ningún efecto en esta operación.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MUL.SU
W0, #0x1F, W2
; Multiplica W0 por literal 0x1F
                       ; Guarde el resultado en W2:W3
antes 
Instrucción
después 
Instrucción
W0
 C000
W0
 C000
W2
 1234
W2
 4000
W3
 C9BA
W3
 FFF8
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 259
Instrucción 
Descripciones
5
Ejemplo 2:
MUL.SU
W2, #0x10, W0
; Multiplica W2 por literal 0x10
                       ; Guarde el resultado en W0:W1
antes 
Instrucción
después 
Instrucción
W0
 ABCD
W0
 2400
W1
 89B3
W1
 000F
W2
 F240
W2
 F240
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 260
© 2009 Microchip Technology Inc.
  
MUL.SU
Entero 16x16 bits Multiplicación con signo-sin signo
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MUL.SU
Wb,
Ws,
viento
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15] 
Viento ∈ [W0, W2, W4 ... W12]
Operación:
firmado (Wb) * sin firmar (Ws) → Wnd:Wnd + 1
Estado afectado:
Ninguno
Codificación:
1011
1001
0www
wdddd
dppp
sss
Descripción:
Multiplique el contenido de Wb por el contenido de Ws y almacene el archivo de 32 bits. 
resultan en dos registros de trabajo sucesivos. La palabra menos significativa de 
el resultado se almacena en Wnd (que debe ser un número par de trabajo 
registro), y la palabra más significativa del resultado se almacena en Wnd + 1. 
El operando Wb y el resultado Wnd se interpretan como dos 
complemento entero con signo. El operando Ws se interpreta como un 
entero sin signo. Se debe utilizar el direccionamiento directo de registro para Wb y 
Viento. Se puede utilizar el direccionamiento directo de registro o indirecto de registro para Ws.
Los bits ‘w’ seleccionan la dirección del registro base.
Los bits 'd' seleccionan la dirección del registro de destino inferior.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: Esta instrucción funciona únicamente en modo Word.
2: Dado que el producto de la multiplicación es de 32 bits, Wnd debe ser
un registro de trabajo uniforme. Consulte la Figura 4-3 para obtener información sobre
Cómo se alinean las palabras dobles en la memoria.
3: Es posible que Wnd no sea W14, ya que W15<0> está fijado en cero. 
4: El bit IF, CORCON<0>, no tiene ningún efecto en esta operación.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MUL.SU
W8, [W9], W0
; Multiplicar W8*[W9]
                      ; Guarde el resultado en W0:W1
antes 
Instrucción
después 
Instrucción
W0
 68DC
W0
 0000
W1
 AA40
W1
 F100
W8
 F000
W8
 F000
W9
 178C
W9
 178C
Datos 178C
 F000
Datos 178C
 F000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 261
Instrucción 
Descripciones
5
Ejemplo 2:
MUL.SU
W2, [++W3], W4
; Pre-incremento W3
                        ; Multiplicar W2*[W3]
                        ; Guarde el resultado en W4:W5
antes 
Instrucción
después 
Instrucción
W2
 0040
W2
 0040
W3
 0280
W3
 0282
W4
 1819
W4
 1A00
W5
 2021
W5
 0000
Datos 0282
 0068
Datos 0282
 0068
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 262
© 2009 Microchip Technology Inc.
 
MUL.US
Entero 16x16 bits Multiplicación sin signo-con signo
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MUL.US 
Wb,
Ws,
viento
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15] 
Viento ∈ [W0, W2, W4 ... W12]
Operación:
sin firmar (Wb) * con signo (Ws) → Wnd:Wnd + 1
Estado afectado:
Ninguno
Codificación:
1011
1000
1www
wdddd
dppp
sss
Descripción:
Multiplique el contenido de Wb por el contenido de Ws y almacene el archivo de 32 bits. 
resultan en dos registros de trabajo sucesivos. La palabra menos significativa de 
el resultado se almacena en Wnd (que debe ser un número par de trabajo 
registro), y la palabra más significativa del resultado se almacena en Wnd + 1. 
El operando Wb se interpreta como un entero sin signo. El operando Ws 
y el resultado Wnd se interpretan como complemento a dos con signo 
entero. Se debe utilizar el direccionamiento directo de registro para Wb y Wnd. 
Se puede utilizar el direccionamiento directo de registro o indirecto de registro para Ws.
Los bits ‘w’ seleccionan la dirección del registro base.
Los bits 'd' seleccionan la dirección del registro de destino inferior.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: Esta instrucción funciona únicamente en modo Word.
2: Dado que el producto de la multiplicación es de 32 bits, Wnd debe ser
un registro de trabajo uniforme. Consulte la Figura 4-3 para obtener información sobre
Cómo se alinean las palabras dobles en la memoria.
3: Es posible que Wnd no sea W14, ya que W15<0> está fijado en cero. 
4: El bit IF, CORCON<0>, no tiene ningún efecto en esta operación.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MUL.US
W0, [W1], W2
; Multiplicar W0*[W1] (sin firmar-firmado)
                      ; Guarde el resultado en W2:W3
antes 
Instrucción
después 
Instrucción
W0
 C000
W0
 C000
W1
 2300
W1
 2300
W2
 00DA
W2
 0000
W3
 CC25
W3
 F400
Datos 2300
 F000
Datos 2300
 F000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 263
Instrucción 
Descripciones
5
Ejemplo 2:
MUL.US
W6, [W5++], W10; Mult. W6*[W5] (sin firmar-firmado)
                        ; Guarde el resultado en W10:W11
                        ; W5 posterior al incremento
antes 
Instrucción
después 
Instrucción
W5
 0C00
W5
 0C02
W6
 FFFFF
W6
 FFFFF
W10
 0908
W10
 8001
W11
 6EEB
W11
 7FFE
Datos 0C00
 7FFF
Datos 0C00
 7FFF
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 264
© 2009 Microchip Technology Inc.
 
MUL.UU
Entero 16x16 bits Literal corto sin signo Multiplicar 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MUL.UU
Wb,
#lit5,
viento
Operandos:
Wb ∈ [W0 ... W15]
iluminado5 ∈ [0 ... 31]
Viento ∈ [W0, W2, W4 ... W12]
Operación:
sin firmar (Wb) * sin firmar lit5 → Wnd:Wnd + 1
Estado afectado:
Ninguno
Codificación:
1011
1000
0www
wdddd
d11k
kkkk
Descripción:
Multiplique el contenido de Wb por el literal de 5 bits y almacene el de 32 bits. 
resultan en dos registros de trabajo sucesivos. La palabra menos significativa de 
el resultado se almacena en Wnd (que debe ser un número par de trabajo 
registro), y la palabra más significativa del resultado se almacena en Wnd + 1. 
Ambos operandos y el resultado se interpretan como enteros sin signo. 
Se debe utilizar el direccionamiento directo de registro para Wb y Wnd.
Los bits ‘w’ seleccionan la dirección del registro base.
Los bits 'd' seleccionan la dirección del registro de destino inferior.
Los bits 'k' definen un literal entero sin signo de 5 bits.
Nota 1: Esta instrucción funciona únicamente en modo Word.
2: Dado que el producto de la multiplicación es de 32 bits, Wnd debe ser
un registro de trabajo uniforme. Consulte la Figura 4-3 para obtener información sobre
Cómo se alinean las palabras dobles en la memoria.
3: Es posible que Wnd no sea W14, ya que W15<0> está fijado en cero. 
4: El bit IF, CORCON<0>, no tiene ningún efecto en esta operación.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MUL.UU
W0, #0xF, W12
; Multiplica W0 por literal 0xF
                       ; Guarde el resultado en W12:W13
antes 
Instrucción
después 
Instrucción
W0
 2323
W0
 2323
W12
 4512
W12
 0F0D
W13
 7821
W13
 0002
SR
 0000
SR
 0000
 
Ejemplo 2:
MUL.UU
W7, #0x1F, W0
; Multiplica W7 por literal 0x1F
                       ; Guarde el resultado en W0:W1
antes 
Instrucción
después 
Instrucción
W0
 780B
W0
 55C0
W1
 3805
W1
 001D
W7
 F240
W7
 F240
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 265
Instrucción 
Descripciones
5
  
MUL.UU
Entero 16x16 bits Multiplicación sin signo
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
MUL.UU 
Wb,
Ws,
viento
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15] 
Viento ∈ [W0, W2, W4 ... W12]
Operación:
sin firmar (Wb) * sin firmar (Ws) → Wnd:Wnd + 1
Estado afectado:
Ninguno
Codificación:
1011
1000
0www
wdddd
dppp
sss
Descripción:
Multiplique el contenido de Wb por el contenido de Ws y almacene el archivo de 32 bits. 
resultan en dos registros de trabajo sucesivos. La palabra menos significativa de 
el resultado se almacena en Wnd (que debe ser un número par de trabajo 
registro), y la palabra más significativa del resultado se almacena en 
Wnd + 1. Tanto los operandos de origen como el resultado se interpretan como 
enteros sin signo. Se debe utilizar el direccionamiento directo de registro para Wb y 
Viento. Se puede utilizar el direccionamiento directo o indirecto del registro para Ws.
Los bits ‘w’ seleccionan la dirección del registro base.
Los bits 'd' seleccionan la dirección del registro de destino inferior.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: Esta instrucción funciona únicamente en modo Word.
2: Dado que el producto de la multiplicación es de 32 bits, Wnd debe ser
un registro de trabajo uniforme. Consulte la Figura 4-3 para obtener información sobre
Cómo se alinean las palabras dobles en la memoria.
3: Es posible que Wnd no sea W14, ya que W15<0> está fijado en cero. 
4: El bit IF, CORCON<0>, no tiene ningún efecto en esta operación.
Palabras:
1
Ciclos:
1
Ejemplo 1:
MUL.UU
W4, W0, W2
; Multiplicar W4*W0 (sin firmar-sin firmar)
                    ; Guarde el resultado en W2:W3
antes 
Instrucción
después 
Instrucción
W0
 FFFFF
W0
 FFFFF
W2
 2300
W2
 0001
W3
 00DA
W3
 FFFE
W4
 FFFFF
W4
 FFFFF
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 266
© 2009 Microchip Technology Inc.
Ejemplo 2:
MUL.UU W0, [W1++], W4
; Mult. W0*[W1] (sin firmar-sin firmar)
                       ; Guarde el resultado en W4:W5
                       ; W1 posterior al incremento
antes 
Instrucción
después 
Instrucción
W0
 1024
W0
 1024
W1
 2300
W1
 2302
W4
 9654
W4
 6D34
W5
 BDBC
W5
 0D80
Datos 2300
 D625
Datos 2300
 D625
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 267
Instrucción 
Descripciones
5
  
NEG
negar f 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
NEG{.B} 
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
(f) + 1 → destino designado por D
Estado afectado:
CC, N, OV, Z, C
Codificación:
1110
1110
0BDF
ffff
ffff
ffff
Descripción:
Calcule el complemento a dos del contenido del registro de archivos y 
coloque el resultado en el registro de destino. El operando WREG opcional 
determina el registro de destino. Si se especifica WREG, el resultado es 
almacenado en WREG. Si no se especifica WREG, el resultado se almacena en el archivo 
registrarse.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0. 
Palabras:
1
Ciclos:
1
Ejemplo 1:
NEG.B
0x880, WREG
; Negar (0x880) (modo Byte)
                    ; Guardar resultado en WREG
antes 
Instrucción
después 
Instrucción
WREG (W0)
 9080
WREG (W0)
 90AB
Datos 0880
 2355
Datos 0880
 2355
SR
 0000
SR
 0008 (n = 1)
Ejemplo 2:
NEG
0x1200; Negar (0x1200) (modo Palabra)
antes 
Instrucción
después 
Instrucción
Datos 1200
 8923
Datos 1200
 76DD
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 268
© 2009 Microchip Technology Inc.
  
NEG
Negar W
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
NEG{.B} 
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Ws) + 1 → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
1110
1010
0Bqq
qdddd
dppp
sss
Descripción:
Calcule el complemento a dos de los contenidos del registro fuente Ws 
y coloque el resultado en el registro de destino Wd. O registrarse directamente 
o se puede utilizar direccionamiento indirecto tanto para Ws como para Wd.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte. 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
NEG.B
W3, [W4++]
; Negar W3 y almacenar en [W4] (modo Byte)
                   ; W4 posterior al incremento
antes 
Instrucción
después 
Instrucción
W3
 7839
W3
 7839
W4
 1005
W4
 1006
Datos 1004
 2355
Datos 1004
 C755
SR
 0000
SR
 0008 (n = 1)
Ejemplo 2:
NEG
[W2++], [--W4]
; Pre-decremento W4 (modo Palabra)
                     ; Negar [W2] y almacenar en [W4]
                     ; W2 posterior al incremento
antes 
Instrucción
después 
Instrucción
W2
 0900
W2
0902
W4
 1002
W4
 1000
Datos 0900
 870F
Datos 0900
 870F
Datos 1000
 5105
Datos 1000
 78F1
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 269
Instrucción 
Descripciones
5
NEG
Negar acumulador
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:}
NEG 
Acc
 
 
Operandos:
Acc ∈ [A,B]
Operación:
Si (Cuenta = A): 
    -ACCA → ACCA
Más:
    -ACCB → ACCB
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1100
1011
A001
0000
0000
0000
Descripción:
Calcule el complemento a dos del contenido del objeto especificado. 
acumulador. Independientemente del modo de saturación, esta instrucción 
opera en los 40 bits del acumulador.
El bit ‘A’ especifica el acumulador seleccionado.
Palabras:
1
Ciclos:
1
Ejemplo 1:
   NEG
Un; Negar ACCA
             ; Guardar resultado en ACCA
             ; CORCON = 0x0000 (sin saturación)
                               
antes 
Instrucción
después 
Instrucción
ACCA
00 3290 59C8
ACCA
FF-CD6F A638
CORCÓN
 0000
CORCÓN
 0000
SR
 0000
SR
 0000
Ejemplo 2:
   NEG
B; Negar ACCB
             ; Guardar resultado en ACCB
             ; CORCON = 0x00C0 (saturación normal)
antes 
Instrucción
después 
Instrucción
ACCB
FF F230 10DC
 ACCB
00 0DCF EF24
CORCÓN
 00C0
CORCÓN
 00C0
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 270
© 2009 Microchip Technology Inc.
  
NOP
Sin operación
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
NOP
Operandos:
Ninguno
Operación:
Sin operación
Estado afectado:
Ninguno
Codificación:
0000
0000
xxxx
xxxx
xxxx
xxxx
Descripción:
No se realiza ninguna operación.
Los bits ‘x’ pueden tomar cualquier valor.
Palabras:
1
Ciclos:
1
Ejemplo 1:
NO ; ejecutar ninguna operación
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 1092
ordenador personal
00 1094
SR
 0000
SR
 0000
Ejemplo 2:
NO ; ejecutar ninguna operación
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 08AE
ordenador personal
00 08B0
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 271
Instrucción 
Descripciones
5
  
NOPR
Sin operación
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
NOPR
Operandos:
Ninguno
Operación:
Sin operación
Estado afectado:
Ninguno
Codificación:
1111
1111
xxxx
xxxx
xxxx
xxxx
Descripción:
No se realiza ninguna operación.
Los bits ‘x’ pueden tomar cualquier valor.
Palabras:
1
Ciclos:
1
Ejemplo 1:
NOPR ; ejecutar ninguna operación
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 2430
ordenador personal
00 2432
SR
 0000
SR
 0000
Ejemplo 2:
NOPR ; ejecutar ninguna operación
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 1466
ordenador personal
00 1468
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 272
© 2009 Microchip Technology Inc.
  
POP
Pop TOS a f
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
POP
f
Operandos:
f ∈ [0 ... 65534]
Operación:
(W15) – 2 → W15
(TOS) → f
Estado afectado:
Ninguno
Codificación:
1111
1001
ffff
ffff
ffff
fff0
Descripción:
El puntero de pila (W15) se reduce previamente en 2 y el indicador superior de pila 
(TOS) se escribe en el registro de archivo especificado, que puede residir 
en cualquier parte de las 32K palabras inferiores de la memoria de datos.
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: Esta instrucción funciona únicamente en modo Word.
2: La dirección del registro del archivo debe estar alineada con palabras.
Palabras:
1
Ciclos:
1
Ejemplo 1:
POP
0x1230; Pop TOS a 0x1230
antes 
Instrucción
después 
Instrucción
W15
 1006
W15
 1004
Datos 1004
 A401
Datos 1004
A401
Datos 1230
 2355
Datos 1230
 A401
SR
 0000
SR
 0000
Ejemplo 2:
POP
0x880; Pop TOS a 0x880
antes 
Instrucción
después 
Instrucción
W15
 2000
W15
 1FFE
Datos 0880
 E3E1
Datos 0880
 A090
Datos 1FFE
 A090
Datos 1FFE
 A090
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 273
Instrucción 
Descripciones
5
POP
Pop TOS a Wd
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
POP
Wd
[Wd]
[Wd++]
[Wd--]
[--Wd]
[++Wd]
[Wd+Wb]
Operandos:
Wd ∈ [W0 ... W15]
Wb ∈ [W0 ... W15]
Operación:
(W15) – 2 → W15
(TOS) → Wd
Estado afectado:
Ninguno
Codificación:
0111
1www
w0hh
disco duro
d100
1111
Descripción:
El puntero de pila (W15) se reduce previamente en 2 y el indicador superior de pila 
(TOS) la palabra se escribe en Wd. Ya sea registrar direccionamiento directo o indirecto 
puede usarse para Wd. 
Los bits 'w' definen el registro de compensación Wb.
Los bits ‘h’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Nota 1: Esta instrucción funciona únicamente en modo Word.
2: Esta instrucción es una versión específica de “MOV Ws, Wd”
instrucción (MOV [--W15], Wd). Se ensambla al revés como
MOV.
Palabras:
1
Ciclos:
1
Ejemplo 1:
POP
W4; Pop TOS a W4
antes 
Instrucción
después 
Instrucción
W4
 EDA8
W4
 C45A
W15
 1008
W15
 1006
Datos 1006
 C45A
Datos 1006
 C45A
SR
 0000
SR
 0000
Ejemplo 2:
POP
[++W10] ; Preincremento W10
                 ; Pop TOS a [W10]
antes 
Instrucción
después 
Instrucción
W10
 0E02
W10
 0E04
W15
 1766
W15
 1764
Datos 0E04
 E3E1
Datos 0E04
 C7B5
Datos 1764
 C7B5
Datos 1764
 C7B5
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 274
© 2009 Microchip Technology Inc.
POP.D
Doble Pop TOS para Wnd:Wnd+1
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
POP.D
viento
Operandos:
Viento ∈ [W0, W2, W4, ... W14]
Operación:
(W15) – 2 → W15
(TOS) → Viento + 1
(W15) – 2 → W15
(TOS) → Viento
Estado afectado:
Ninguno
Codificación:
1011
1110
0000
0ddd
0100
1111
Descripción:
Una palabra doble se extrae del Top-of-Stack (TOS) y se almacena en 
Wnd:Wnd + 1. La palabra más significativa se almacena en Wnd + 1, y la 
La palabra menos significativa se almacena en Wnd. Dado que una palabra doble aparece como POP, 
el puntero de pila (W15) se reduce en 4.
Los bits 'd' seleccionan la dirección del par de registros de destino. 
Nota 1: Esta instrucción opera con palabras dobles. Consulte la Figura 4-3 para
información sobre cómo se alinean las palabras dobles en la memoria.
2: Wnd debe ser un registro par que funcione.
3: Esta instrucción es una versión específica de “MOV.D Ws, Wnd”
instrucción (MOV.D [--W15], Wnd). Se ensambla al revés como
MOV.D.
Palabras:
1
Ciclos:
2
Ejemplo 1:
POP.D
W6; Doble pop TOS a W6
antes 
Instrucción
después 
Instrucción
W6
 07BB
W6
 3210
W7
 89AE
W7
 7654
W15
 0850
W15
 084C
Datos 084C
 3210
Datos 084C
 3210
Datos 084E
 7654
Datos 084E
 7654
SR
 0000
SR
 0000
Ejemplo 2:
POP.D
W0; Doble pop TOS a W0
antes 
Instrucción
después 
Instrucción
W0
 673E
W0
 791C
W1
 DD23
W1
 D400
W15
 0BBC
W15
 0BB8
Datos 0BB8
 791C
Datos 0BB8
 791C
Datos 0BBA
 D400
Datos 0BBA
 D400
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 275
Instrucción 
Descripciones
5
  
POP.S
Registros de sombras pop
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
POP.S
Operandos:
Ninguno
Operación:
Registros ocultos POP
Estado afectado:
CC, N, OV, Z, C
Codificación:
1111
1110
1000
0000
0000
0000
Descripción:
Los valores en los registros de sombra se copian en sus respectivos 
registros primarios. Los siguientes registros se ven afectados: W0-W3 y el 
Banderas de registro de ESTADO C, Z, OV, N y DC.
Nota 1: No se puede acceder directamente a los registros de sombra. ellos pueden
Sólo se puede acceder con PUSH.S y POP.S.
2: Los registros de sombra tienen sólo un nivel de profundidad.
Palabras:
1
Ciclos:
1
Ejemplo 1:
POP.S; Explota los registros de sombra 
            ; (Consulte el ejemplo 1 de PUSH.S para conocer el contenido de las sombras)
antes 
Instrucción
después 
Instrucción
W0
 07BB
W0
 0000
W1
 03FD
W1
 1000
W2
 9610
W2
 2000
W3
 7249
W3
 3000
SR
 00E0 (IPL = 7)
SR
 00E1 (IPL = 7, C = 1)
Nota:
Después de la ejecución de la instrucción, el contenido de los registros ocultos NO se modifica.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 276
© 2009 Microchip Technology Inc.
  
EMPUJAR
Empuje f a TOS
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
EMPUJAR
f
Operandos:
f ∈ [0 ... 65534]
Operación:
(f) → (TOS)
(W15) + 2 → W15
Estado afectado:
Ninguno
Codificación:
1111
1000
ffff
ffff
ffff
fff0
Descripción:
El contenido del registro de archivos especificado se escribe en el Top-of-Stack 
(TOS) y luego el puntero de pila (W15) se incrementa en 2.
El registro de archivos puede residir en cualquier parte de las 32 000 palabras de datos inferiores. 
memoria. 
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: Esta instrucción funciona únicamente en modo Word.
2: La dirección del registro del archivo debe estar alineada con palabras.
Palabras:
1
Ciclos:
1
Ejemplo 1:
EMPUJAR
0x2004; Empuje (0x2004) a TOS
antes 
Instrucción
después 
Instrucción
W15
 0B00
W15
 0B02
Datos 0B00
 791C
Datos 0B00
 D400
Datos 2004
 D400
Datos 2004
 D400
SR
 0000
SR
 0000
Ejemplo 2:
EMPUJAR
0xC0E; Empuje (0xC0E) a TOS
antes 
Instrucción
después 
Instrucción
W15
 0920
W15
 0922
Datos 0920
 0000
Datos 0920
 67AA
Datos 0C0E
 67AA
Datos 2004
 67AA
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 277
Instrucción 
Descripciones
5
  
EMPUJAR
Empuje Ws a TOS
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
EMPUJAR
Ws
[Ws]
[Ws++]
[Ws--]
[--Ws]
[++Preguntas]
[Ws+Wb]
Operandos:
Ws ∈ [W0 ... W15]
Wb ∈ [W0 ... W15]
Operación:
(Ws) → (TOS)
(W15) + 2 → W15
Estado afectado:
Ninguno
Codificación:
0111
1www
w001
1111
1ggg
sss
Descripción:
El contenido de Ws se escribe en la ubicación Top-of-Stack (TOS) y 
luego el puntero de pila (W15) se incrementa en 2.
Los bits 'w' definen el registro de compensación Wb.
Los bits ‘g’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: Esta instrucción funciona únicamente en modo Word.
2: Esta instrucción es una versión específica de “MOV Ws, Wd”
instrucción (MOV Ws, [W15++]). Se ensambla al revés como
MOV.
Palabras:
1
Ciclos:
1
Ejemplo 1:
EMPUJAR
W2; Empuje W2 a TOS
antes 
Instrucción
después 
Instrucción
W2
 6889
W2
 6889
W15
 1566
W15
 1568
Datos 1566
 0000
Datos 1566
 6889
SR
 0000
SR
 0000
Ejemplo 2:
EMPUJAR
[W5+W10] ; Empuje [W5+W10] a TOS
antes 
Instrucción
después 
Instrucción
W5
 1200
W5
 1200
W10
 0044
W10
 0044
W15
 0806
W15
 0808
Datos 0806
 216F
Datos 0806
 B20A
Datos 1244
 B20A
Datos 1244
 B20A
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 278
© 2009 Microchip Technology Inc.
  
EMPUJAR.D
Doble pulsación Wns:Wns+1 a TOS
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
EMPUJAR.D
Wns
Operandos:
Wns ∈ [W0, W2, W4 ... W14]
Operación:
(Wns) → (TOS)
(W15) + 2 → W15
(Wns + 1) → (TOS)
(W15) + 2 → W15
Estado afectado:
Ninguno
Codificación:
1011
1110
1001
1111
1000
sss0
Descripción:
Una palabra doble (Wns:Wns + 1) se EMPUJA al Top-of-Stack (TOS). 
La palabra menos significativa (Wns) se envía primero a los TOS y la palabra menos significativa (Wns). 
La palabra más significativa (Wns + 1) se EMPUJA hasta el último TOS. desde un 
Se EMPUJA una palabra doble, el puntero de pila (W15) se incrementa en 4.
Los bits ‘s’ seleccionan la dirección del par de registros fuente.
Nota 1: Esta instrucción opera con palabras dobles. Consulte la Figura 4-3 para
información sobre cómo se alinean las palabras dobles en la memoria.
2: Wns debe ser un registro par que funcione.
3: Esta instrucción es una versión específica de “MOV.D Wns, Wd”
instrucción (MOV.D Wns, [W15++]). Se ensambla al revés como
MOV.D.
Palabras:
1
Ciclos:
2
Ejemplo 1:
EMPUJAR.D
W6; Empuje W6:W7 a TOS
antes 
Instrucción
después 
Instrucción
W6
 C451
W6
 C451
W7
 3380
W7
 3380
W15
 1240
W15
 1244
Datos 1240
 B004
Datos 1240
 C451
Datos 1242
 0891
Datos 1242
 3380
SR
 0000
SR
 0000
Ejemplo 2:
EMPUJAR.D
W10; Empuje W10:W11 a TOS
antes 
Instrucción
después 
Instrucción
W10
 80D3
W10
 80D3
W11
 4550
W11
 4550
W15
 0C08
W15
 0C0C
Datos 0C08
 79B5
Datos 0C08
 80D3
Datos 0C0A
 008E
Datos 0C0A
 4550
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 279
Instrucción 
Descripciones
5
  
EMPUJAR.S
Empujar registros de sombra
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
EMPUJAR.S
Operandos:
Ninguno
Operación:
PUSH registros de sombra
Estado afectado:
Ninguno
Codificación:
1111
1110
1010
0000
0000
0000
Descripción:
El contenido de los registros primarios se copia en sus respectivos 
registros de sombra. Los siguientes registros están sombreados: W0-W3 y 
las banderas de registro de ESTADO C, Z, OV, N y DC.
Nota 1: No se puede acceder directamente a los registros de sombra. ellos pueden
Sólo se puede acceder con PUSH.S y POP.S.
2: Los registros de sombra tienen sólo un nivel de profundidad.
Palabras:
1
Ciclos:
1
Ejemplo 1:
EMPUJAR.S ; Insertar registros primarios en registros ocultos
antes 
Instrucción
después 
Instrucción
W0
 0000
W0
 0000
W1
 1000
W1
 1000
W2
 2000
W2
 2000
W3
 3000
W3
 3000
SR
 0001 (C = 1)
SR
 0001 (C = 1)
Nota:
Después de la ejecución de una instrucción, se actualiza el contenido de los registros ocultos.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 280
© 2009 Microchip Technology Inc.
  
PWRSAV
Ingrese al modo de ahorro de energía
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
PWRSAV
#lit1
Operandos:
iluminado1 ∈ [0,1]
Operación:
0 → Registro de conteo WDT
0 → Conteo A del preescalador WDT
0 → Conteo B del preescalador WDT
0 → WDTO (RCON<4>)
0 → DORMIR (RCON<3>)
0 → INACTIVO (RCON<2>)
Si (lit1 = 0):
    Ingrese al modo de suspensión
Más:
    Ingrese al modo inactivo
Estado afectado:
Ninguno
Codificación:
1111
1110
0100
0000
0000
000k
Descripción:
Coloque el procesador en el modo de ahorro de energía especificado. Si lit1 = ‘0’, 
Se ingresa al modo de suspensión. En el modo de suspensión, el reloj de la CPU y 
Los periféricos están apagados. Si se utiliza un oscilador en chip, también es 
apagado. Si lit1 = ‘1’, se ingresa al modo inactivo. En el modo inactivo, el reloj de la 
La CPU se apaga, pero la fuente de reloj permanece activa y el 
Los periféricos siguen funcionando.
Esta instrucción restablece el registro de conteo del temporizador de vigilancia y el 
Registros de conteo del preescalador. Además, los indicadores WDTO, Sleep e Idle de 
se restablecen los registros de control y sistema de reinicio (RCON). 
Nota 1: El procesador saldrá de Inactivo o Suspendido a través de una interrupción,
reinicio del procesador o tiempo de espera de vigilancia. Ver el específico
hoja de datos del dispositivo para más detalles.
2: Si se despierta del modo inactivo, Idle (RCON<2>) se establece en ‘1’ y
la fuente del reloj se aplica a la CPU.
3: Si se despierta del modo de suspensión, la suspensión (RCON<3>) se establece en ‘1’
y se inicia la fuente del reloj.
4: Si se despierta de un tiempo de espera de vigilancia, WDTO (RCON<4>)
se establece en ‘1’.
Palabras:
1
Ciclos:
1
Ejemplo 1:
PWRSAV
#0; Ingrese al modo SUEÑO
antes 
Instrucción
después 
Instrucción
SR
 0040 (IPL = 2)
SR
 0040 (IPL = 2)
Ejemplo 2:
PWRSAV
#1; Ingrese al modo inactivo
antes 
Instrucción
después 
Instrucción
SR
 0020 (IPL = 1)
SR
 0020 (IPL = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 281
Instrucción 
Descripciones
5
  
LLAMADA
Llamada relativa
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
LLAMADA  
Expr.
Operandos:
Expr puede ser una dirección, etiqueta o expresión absoluta.
Expr es resuelto por el enlazador a Slit16, donde Slit16 ∈ [-32768 ... 32767].
Operación:
(PC) + 2 → PC
(PC<15:0>) → (TOS)
(W15) + 2 → W15
(PC<22:16>) → (TOS)
(W15) + 2 → W15
(PC) + (2 * Rendija16) → PC
NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0000
0111
nnnn
nnnn
nnnn
nnnn
Descripción:
Llamada de subrutina relativa con un rango de 32K palabras de programa hacia adelante o hacia atrás 
desde la PC actual. Antes de realizar la llamada, la dirección del remitente (PC + 2) es 
EMPUJADO sobre la pila. Después de apilar la dirección del remitente, el 
El valor de 17 bits extendido por signo (2 * Slit16) se agrega al contenido de la PC 
y el resultado se almacena en el PC.
Los bits ‘n’ son un literal con signo que especifica el tamaño de la llamada relativa (en 
palabras de programa) de (PC + 2).
Nota:
Cuando sea posible, se debe utilizar esta instrucción en lugar de CALL,
ya que sólo consume una palabra de memoria del programa.
Palabras:
1
Ciclos:
2
Ejemplo 1:
012004 RLLAMADA
_Tarea1
012006 AÑADIR W0, W1, W2
   .            ...
   .            ...
012458 _Tarea1:
SUBW0, W2, W3
01245A ...       
; Llamar _Tarea1
; _Subrutina Task1
antes 
Instrucción
después 
Instrucción
ordenador personal
 01 2004
ordenador personal
01 2458
W15
    0810
W15
 0814
Datos 0810
 FFFFF
Datos 0810
 2006
Datos 0812
 FFFFF
Datos 0812
 0001
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 282
© 2009 Microchip Technology Inc.
Ejemplo 2:
00620E LLAMADA _Inicio
006210 MOV W0, [W4++]
   .            ...
   .            ...
007000 _Inicio: CLR W2
007002 ...       
; Llamar _Init
; _Init subrutina
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 620E
ordenador personal
00 7000
W15
    0C50
W15
 0C54
Datos 0C50
 FFFFF
Datos 0C50
 6210
Datos 0C52
 FFFFF
Datos 0C52
 0000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 283
Instrucción 
Descripciones
5
 
LLAMADA
Llamada relativa calculada 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
LLAMADA  
Wn
Operandos:
Wn ∈ [W0 ... W15]
Operación:
(PC) + 2 → PC
(PC<15:0>) → (TOS)
(W15) + 2 → W15
(PC<22:16>) → (TOS)
(W15) + 2 → W15
(PC) + (2 * (Wn)) → PC
NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0000
0001
0010
0000
0000
sss
Descripción:
Llamada de subrutina relativa calculada especificada por el registro de trabajo Wn. el 
El rango de llamada es de 32K palabras de programa hacia adelante o hacia atrás desde la PC actual. 
Antes de realizar la llamada, la dirección del remitente (PC + 2) se EMPUJA en el 
pila. Después de apilar la dirección del remitente, el valor de 17 bits con signo extendido (2 * 
(Wn)) se agrega al contenido de la PC y el resultado se almacena en la PC. 
Se debe utilizar el direccionamiento directo de registro para Wn.
Los bits ‘s’ seleccionan el registro fuente.
Palabras:
1
Ciclos:
2
Ejemplo 1:
00FF8C
EJ1: INC W2, W3
00FF8E...
   .            ...
   .            ...
010008 
01000A RLLAMADA
W6
01000C MOVER W4, [W10]
; Destino del RCALL
; RCALL con W6
antes 
Instrucción
después 
Instrucción
ordenador personal
 01 000A
ordenador personal
00FF8C
W6
    FFC0
W6
 FFC0
W15
    1004
W15
 1008
Datos 1004
 98FF
Datos 1004
 000C
Datos 1006
 2310
Datos 1006
 0001
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 284
© 2009 Microchip Technology Inc.
Ejemplo 2:
000302 RLLAMADA W2
000304 FF1L W0, W1
   .            ...
   .            ...
000450
EX2: BORRAR W2
000452 ...       
; RCALL con W2
; Destino del RCALL
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 0302
ordenador personal
00 0450
W2
    00A6
W2
 00A6
W15
    1004
W15
 1008
Datos 1004
 32BB
Datos 1004
 0304
Datos 1006
 901A
Datos 1006
 0000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 285
Instrucción 
Descripciones
5
 
REPETIR
Repita la siguiente instrucción ‘lit14+1’ veces
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
REPETIR  
#lit14
Operandos:
iluminado14 ∈ [0 ... 16383] 
Operación:
(lit14) → RCONTAR
(PC) + 2 → PC
Habilitar bucle de código
Estado afectado:
RA
Codificación:
0000
1001
00kk
kkkk
kkkk
kkkk
Descripción:
Repita la instrucción inmediatamente después de la instrucción REPETIR. 
(lit14 + 1) veces. La instrucción repetida (o instrucción objetivo) se lleva a cabo en 
el registro de instrucciones para todas las iteraciones y solo se recupera una vez.
Cuando se ejecuta esta instrucción, el registro RCOUNT se carga con el 
repetir el valor de conteo especificado en la instrucción. RCOUNT disminuye 
con cada ejecución de la instrucción objetivo. Cuando RCOUNT es igual 
cero, la instrucción de destino se ejecuta una vez más, y luego normal 
La ejecución de la instrucción continúa con la instrucción que sigue al objetivo. 
instrucción.
Los bits 'k' son un literal sin signo que especifica el recuento de bucles.
Características especiales, restricciones:
1.
Cuando el literal repetido es ‘0’, REPEAT tiene el efecto de un NOP y
el bit RA no está establecido.
2.
La instrucción REPEAT objetivo NO puede ser:
• una instrucción que cambia el flujo del programa
• una instrucción DO, DISI, LNK, MOV.D, PWRSAV, REPEAT o UNLK.
ción
• una instrucción de 2 palabras
Pueden producirse resultados inesperados si se utilizan estas instrucciones de destino.
Nota:
La repetición y la instrucción objetivo son interrumpibles.
Palabras:
1
Ciclos:
1
Ejemplo 1:
000452 REPETIR #9 ; Ejecutar AGREGAR 10 veces
000454 AÑADIR [W0++], W1, [W2++]; Actualización vectorial
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 0452
ordenador personal
00 0454
RCONTAR
 0000
RCONTAR
 0009
SR
 0000
SR
 0010 (AR = 1)
Ejemplo 2:
00089E REPETIR
#0x3FF; Ejecute CLR 1024 veces
0008A0 BORRAR [W6++]; Limpiar el espacio temporal
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 089E
ordenador personal
00 08A0
RCONTAR
 0000
RCONTAR
 03FF
SR
 0000
SR
 0010 (AR = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 286
© 2009 Microchip Technology Inc.
 
REPETIR
Repita la siguiente instrucción Wn+1 veces
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
REPETIR  
Wn
Operandos:
Wn ∈ [W0 ... W15] 
Operación:
(Wn<13:0>) → RCONTAR
(PC) + 2 → PC
Habilitar bucle de código
Estado afectado:
RA
Codificación:
0000
1001
1000
0000
0000
sss
Descripción:
Repita la instrucción inmediatamente después de la instrucción REPETIR. 
(Wn<13:0>) veces. La instrucción que se repetirá (o instrucción objetivo) 
se mantiene en el registro de instrucciones para todas las iteraciones y solo se recupera 
una vez.
Cuando se ejecuta esta instrucción, el registro RCOUNT se carga con el 
baje 14 bits de Wn. RCOUNT disminuye con cada ejecución de 
la instrucción objetivo. Cuando RCOUNT es igual a cero, la instrucción de destino 
se ejecuta una vez más y luego se ejecuta la instrucción normal 
continúa con la instrucción siguiendo la instrucción objetivo.
Los bits ‘s’ especifican el registro Wn que contiene el recuento de repeticiones.
Características especiales, restricciones:
1.
Cuando (Wn) = 0, REPEAT tiene el efecto de un NOP y el bit RA es
no establecido.
2.
La instrucción REPEAT objetivo NO puede ser:
• una instrucción que cambia el flujo del programa
• una instrucción DO, DISI, LNK, MOV.D, PWRSAV, REPEAT o ULNK.
ción
• una instrucción de 2 palabras
Pueden producirse resultados inesperados si se utilizan estas instrucciones de destino.
Nota:
La repetición y la instrucción objetivo son interrumpibles.
Palabras:
1
Ciclos:
1
Ejemplo 1:
000A26
REPETIR
W4; Ejecutar COM (W4+1) veces
000A28
COM[W0++], [W2++]
; Complemento vectorial
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 0A26
ordenador personal
00 0A28
W4
 0023
W4
 0023
RCONTAR
 0000
RCONTAR
 0023
SR
 0000
SR
 0010 (AR = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 287
Instrucción 
Descripciones
5
Ejemplo 2:
00089E
REPETIR
W10; Ejecutar TBLRD (W10+1) veces
0008A0
TBLRDL
[W2++], [W3++]; Decremento (0x840)
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 089E
ordenador personal
00 08A0
W10
 00FF
W10
 00FF
RCONTAR
 0000
RCONTAR
 00FF
SR
 0000
SR
 0010 (AR = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 288
© 2009 Microchip Technology Inc.
 
REINICIAR
Reiniciar
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
REINICIAR
Operandos:
Ninguno
Operación:
Forzar todos los registros afectados por un reinicio de MCLR a su reinicio 
condición.
1 → ROE (RCON<6>)
0 → ordenador personal
Estado afectado:
OA, OB, OAB, SA, SB, SAB, DA, DC, IPL<2:0>, RA, N, OV, Z, C
Codificación:
1111
1110
0000
0000
0000
0000
Descripción:
Esta instrucción proporciona una forma de ejecutar un reinicio del software. Todo el núcleo y 
Los registros periféricos tomarán su valor de encendido. La PC se configurará en 
‘0’, la ubicación de la instrucción RESET GOTO. El bit SWR, 
RCON<6>, se establecerá en ‘1’ para indicar que la instrucción RESET fue 
ejecutado.
Nota:
Consulte el manual de referencia de la familia de dispositivos específica para conocer
valor de encendido de todos los registros.
Palabras:
1
Ciclos:
1

© 2009 Microchip Technology Inc.
DS70157D-página 289
Instrucción 
Descripciones
5
Ejemplo 1:
00202A REINICIAR ; Ejecutar software RESET
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 202A
ordenador personal
00 0000
W0
 8901
W0
 0000
W1
 08BB
W1
 0000
W2
B87A
W2
 0000
W3
 872F
W3
 0000
W4
 C98A
W4
 0000
W5
 AAD4
W5
 0000
W6
 981E
W6
 0000
W7
 1809
W7
 0000
W8
C341
W8
 0000
W9
 90F4
W9
 0000
W10
 F409
W10
 0000
W11
 1700
W11
 0000
W12
 1008
W12
 0000
W13
 6556
W13
 0000
W14
 231D
W14
 0000
W15
 1704
W15
 0800
SPLIM
 1800
SPLIM
 0000
TBLPAG
 007F
TBLPAG
 0000
PSVPAG
 0001
PSVPAG
 0000
CORCÓN
 00F0
CORCÓN
 0020 (SATDW = 1)
RCON
 0000
RCON
 0040 (ROE = 1)
SR
 0021 (IPL, C = 1)
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 290
© 2009 Microchip Technology Inc.
  
REFIE
Regresar de la interrupción
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
REFIE  
Operandos:
Ninguno
Operación:
(W15) - 2 → W15
(TOS<15:8>) → (SR<7:0>)
(TOS<7>) → (IPL3, CORCON<3>)
(TOS<6:0>) → (PC<22:16>)
(W15) - 2 → W15
(TOS<15:0>) → (PC<15:0>)
NOP → Registro de instrucciones
Estado afectado:
IPL<3:0>, AR, N, OV, Z, C
Codificación:
0000
0110
0100
0000
0000
0000
Descripción:
Regreso de la Rutina de Interrupción del Servicio. La pila aparece POP, lo que 
carga el byte bajo del registro STATUS, IPL<3> (CORCON<3>) y 
el byte más significativo de la PC. La pila vuelve a aparecer, lo que 
carga los 16 bits inferiores de la PC.
Nota 1: Restauración de IPL<3> y el byte bajo del registro STATUS
restaura el nivel de prioridad de interrupción al nivel anterior a la ejecución.
La cución fue procesada.
2: Antes de ejecutar RETFIE, el indicador de interrupción apropiado
debe borrarse en el software para evitar interrupciones recursivas.
Palabras:
1
Ciclos:
3 (2 si excepción pendiente)
Ejemplo 1:
000A26 REFIE ; Regreso de ISR 
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 0A26
ordenador personal
01 0230
W15
 0834
W15
 0830
Datos 0830
 0230
Datos 0830
 0230
Datos 0832
 8101
Datos 0832
8101
CORCÓN
 0001
CORCÓN
 0001
SR
 0000
SR
 0081 (IPL = 4, C = 1)
Ejemplo 2:
008050 RETFIE ; Regreso de ISR
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 8050
ordenador personal
00 7008
W15
0926
W15
 0922
Datos 0922
 7008
Datos 0922
 7008
Datos 0924
0300
Datos 0924
0300
CORCÓN
 0000
CORCÓN
 0000
SR
 0000
SR
 0003 (Z,C=1)

© 2009 Microchip Technology Inc.
DS70157D-página 291
Instrucción 
Descripciones
5
 
RETLW
Regresar con Literal en Wn
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
RETLW{.B} #lit10,
Wn
Operandos:
lit10 ∈ [0 ... 255] para operación de bytes
lit10 ∈ [0 ... 1023] para operación de palabra
Wn ∈ [W0 ... W15]
Operación:
(W15) – 2 → W15
(TOS) → (PC<22:16>)
(W15) – 2 → W15
(TOS) → (PC<15:0>)
lit10 → Wn
Estado afectado:
Ninguno
Codificación:
0000
0101
0Bkk
kkkk
kkkk
dddd
Descripción:
Regreso de la subrutina con el literal de 10 bits sin firmar especificado almacenado 
en Wn. La pila de software aparece dos veces para restaurar la PC y el 
El literal firmado se almacena en Wn. Dado que se fabrican dos POP, la pila 
El puntero (W15) se reduce en 4.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits 'k' especifican el valor del literal.
Los bits 'd' seleccionan el registro de destino.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria. 
2: para operaciones de bytes, el literal debe especificarse como sin firmar
valor [0:255]. Consulte la Sección 4.6 “Uso de operandos literales de 10 bits”
para obtener información sobre el uso de operandos literales de 10 bits en modo Byte.
Palabras:
1
Ciclos:
3 (2 si excepción pendiente)
Ejemplo 1:
000440 RETLW.B #0xA, W0 ; Regresar con 0xA en W0 
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 0440
ordenador personal
00 7006
W0
 9846
W0
 980A
W15
 1988
W15
 1984
Datos 1984
 7006
Datos 1984
 7006
Datos 1986
 0000
Datos 1986
0000
SR
 0000
SR
 0000
Ejemplo 2:
00050A RETLW
#0x230, W2
; Regresar con 0x230 en W2
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 050A
ordenador personal
01 7008
W2
 0993
W2
 0230
W15
1200
W15
 11FC
Datos 11FC
 7008
Datos 11FC
 7008
Datos 11FE
0001
Datos 11FE
0001
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 292
© 2009 Microchip Technology Inc.
 
VOLVER
Regresar
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
VOLVER 
Operandos:
Ninguno
Operación:
(W15) – 2 → W15
(TOS) → (PC<22:16>)
(W15) – 2 → W15
(TOS) → (PC<15:0>)
NOP → Registro de instrucciones
Estado afectado:
Ninguno
Codificación:
0000
0110
0000
0000
0000
0000
Descripción:
Regreso de la subrutina. La pila de software aparece dos veces para restaurar 
la PC. Dado que se crean dos POP, el puntero de pila (W15) es 
disminuido en 4.
Palabras:
1
Ciclos:
3 (2 si excepción pendiente)
Ejemplo 1:
001A06 VOLVER ; Regreso de subrutina
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 1A06
ordenador personal
01 0004
W15
 1248
W15
 1244
Datos 1244
 0004
Datos 1244
 0004
Datos 1246
 0001
Datos 1246
0001
SR
 0000
SR
 0000
Ejemplo 2:
005404 VOLVER ; Regreso de subrutina
antes 
Instrucción
después 
Instrucción
ordenador personal
 00 5404
ordenador personal
00 0966
W15
090A
W15
 0906
Datos 0906
0966
Datos 0906
 0966
Datos 0908
0000
Datos 0908
0000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 293
Instrucción 
Descripciones
5
 
RLC
Girar a la izquierda f a través de Llevar 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
RLC{.B} 
f
{,WREG}
Operandos:
 f ∈ [0 ... 8191]
Operación:
Para operación de bytes:
    (C) → Destino<0>
    (f<6:0>) → Destino<7:1>
    (f<7>) → C
Para operación de palabras:
    (C) → Destino<0>
    (f<14:0>) → Destino<15:1>
    (f<15>) → C
Estado afectado:
norte, z, c
Codificación:
1101
0110
1HAB
ffff
ffff
ffff
Descripción:
Gire el contenido del registro de archivos f un bit hacia la izquierda a través del 
Llevar bandera y colocar el resultado en el registro de destino. La bandera de llevar 
del Registro STATUS se desplaza al bit menos significativo del 
destino y luego se sobrescribe con el bit más significativo de Ws. 
El operando WREG opcional determina el registro de destino. si 
Se especifica WREG, el resultado se almacena en WREG. Si WREG no es 
especificado, el resultado se almacena en el registro de archivos.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit ‘D’ selecciona el destino (‘0’ para f, ‘1’ para WREG).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0.
Palabras:
1
Ciclos:
1
c
Ejemplo 1:
RLC.B
0x1233; Girar a la izquierda con C (0x1233) (modo Byte)
antes 
Instrucción
después 
Instrucción
Datos 1232
 E807
Datos 1232
 D007
SR
 0000
SR
 0009 (N,C=1)
Ejemplo 2:
RLC
0x820, WREG
; Girar a la izquierda con C (0x820) (modo Word)
                    ; Almacenar resultado en WREG
antes 
Instrucción
después 
Instrucción
WREG (W0)
 5601
WREG (W0)
 42DD
Datos 0820
 216E
Datos 0820
 216E
SR
 0001 (C = 1)
SR
 0000 (C = 0)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 294
© 2009 Microchip Technology Inc.
  
RLC
Girar a la izquierda Ws mediante Carry
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
RLC{.B} 
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
Para operación de bytes:
    (C) → Wd<0>
    (Ws<6:0>) → Wd<7:1>
    (Ws<7>) → C
Para operación de palabras:
    (C) → Wd<0>
    (Ws<14:0>) → Wd<15:1>
    (Ws<15>) → C
Estado afectado:
norte, z, c
Codificación:
1101
0010
1Bqq
qdddd
dppp
sss
Descripción:
Gire el contenido del registro fuente Ws un bit hacia la izquierda hasta 
la bandera de acarreo y coloque el resultado en el registro de destino Wd. el 
El indicador de acarreo del registro STATUS se desplaza al bit menos significativo 
de Wd, y luego se sobrescribe con la parte más significativa de Ws. 
Se puede utilizar el direccionamiento directo o indirecto de registro para Ws y Wd.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
c
Ejemplo 1:
RLC.B
W0, W3; Girar a la izquierda con C (W0) (modo Byte)
                    ; Almacenar el resultado en W3
antes 
Instrucción
después 
Instrucción
W0
 9976
W0
 9976
W3
 5879
W3
 58ED
SR
 0001 (C = 1)
SR
 0009 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 295
Instrucción 
Descripciones
5
Ejemplo 2:
RLC
[W2++], [W8]
; Girar a la izquierda con C [W2] (modo Palabra)
                     ; W2 posterior al incremento
                     ; Guardar resultado en [W8]
antes 
Instrucción
después 
Instrucción
W2
 2008
W2
 200A
W8
 094E
W8
 094E
Datos 094E
 3689
Datos 094E
 8082
Datos 2008
 C041
Datos 2008
 C041
SR
 0001 (C = 1)
SR
 0009 (N,C=1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 296
© 2009 Microchip Technology Inc.
  
RLNC
Girar a la izquierda f sin llevar 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
RLNC{.B} 
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
Para operación de bytes:
    (f<6:0>) → Destino<7:1>
    (f<7>) → Destino<0>
Para operación de palabras:
    (f<14:0>) → Destino<15:1>
    (f<15>) → Destino<0>
Estado afectado:
norte, z
Codificación:
1101
0110
0BDF
ffff
ffff
ffff
Descripción:
Gire el contenido del registro de archivos f un bit hacia la izquierda y coloque el 
resultado en el registro de destino. El bit más significativo de f se almacena en 
el bit menos significativo del destino y la bandera de acarreo no está 
afectado. 
El operando WREG opcional determina el registro de destino. si 
Se especifica WREG, el resultado se almacena en WREG. Si WREG no es 
especificado, el resultado se almacena en el registro de archivos.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0.
Palabras:
1
Ciclos:
1
Ejemplo 1:
RLNC.B
0x1233; Girar a la izquierda (0x1233) (modo Byte)
antes 
Instrucción
después 
Instrucción
Datos 1232
 E807
Datos 1233
 D107
SR
 0000
SR
 0008 (n = 1)
Ejemplo 2:
RLNC
0x820, WREG
; Girar a la izquierda (0x820) (modo Word)
                     ; Almacenar resultado en WREG
antes 
Instrucción
después 
Instrucción
WREG (W0)
 5601
WREG (W0)
 42DC
Datos 0820
 216E
Datos 0820
 216E
SR
 0001 (C = 1)
SR
 0000 (C = 0)

© 2009 Microchip Technology Inc.
DS70157D-página 297
Instrucción 
Descripciones
5
  
RLNC
Girar a la izquierda Ws sin llevar
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
RLNC{.B} 
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
Para operación de bytes:
    (Ws<6:0>) → Wd<7:1>
    (Ws<7>) → Wd<0>
Para operación de palabras:
    (Ws<14:0>) → Wd<15:1>
    (Ws<15>) → Wd<0>
Estado afectado:
norte, z
Codificación:
1101
0010
0Bqq
qdddd
dppp
sss
Descripción:
Gire el contenido del registro fuente Ws un bit hacia la izquierda y coloque 
el resultado en el registro de destino Wd. La parte más significativa de W es 
almacenado en el bit menos significativo de Wd, y el indicador de acarreo no está 
afectado. Se puede utilizar el direccionamiento directo o indirecto del registro para Ws 
y Wd.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para byte, ‘1’ para palabra).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
RLNC.B
W0, W3; Girar a la izquierda (W0) (modo Byte)
                    ; Almacenar el resultado en W3
antes 
Instrucción
después 
Instrucción
W0
 9976
W0
 9976
W3
 5879
W3
 58CE
SR
 0001 (C = 1)
SR
 0009 (N,C=1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 298
© 2009 Microchip Technology Inc.
Ejemplo 2:
RLNC
[W2++], [W8]; Girar a la izquierda [W2] (modo Palabra)
                     ; W2 posterior al incremento
                     ; Guardar resultado en [W8]
antes 
Instrucción
después 
Instrucción
W2
 2008
W2
 200A
W8
 094E
W8
 094E
Datos 094E
 3689
Datos 094E
 8083
Datos 2008
 C041
Datos 2008
 C041
SR
 0001 (C = 1)
SR
 0009 (N,C=1)

© 2009 Microchip Technology Inc.
DS70157D-página 299
Instrucción 
Descripciones
5
  
RRC
Girar a la derecha f a través de Llevar 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CRR{.B} 
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
Para operación de bytes:
    (C) → Destino<7>
    (f<7:1>) → Destino<6:0>
    (f<0>) → C
Para operación de palabras:
    (C) → Destino<15>
    (f<15:1>) → Destino<14:0>
    (f<0>) → C
Estado afectado:
norte, z, c
Codificación:
1101
0111
1HAB
ffff
ffff
ffff
Descripción:
Gire el contenido del registro de archivos f un bit hacia la derecha a través del 
Llevar bandera y colocar el resultado en el registro de destino. La bandera de llevar 
del Registro STATUS se desplaza a la parte más significativa del 
destino y luego se sobrescribe con el bit menos significativo de Ws. 
El operando WREG opcional determina el registro de destino. si 
Se especifica WREG, el resultado se almacena en WREG. Si WREG no es 
especificado, el resultado se almacena en el registro de archivos.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para byte, ‘1’ para palabra).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0.
Palabras:
1
Ciclos:
1
c
Ejemplo 1:
RRC.B
0x1233; Girar a la derecha con C (0x1233) (modo Byte)
antes 
Instrucción
después 
Instrucción
Datos 1232
 E807
Datos 1232
 7407
SR
 0000
SR
 0000
Ejemplo 2:
RRC
0x820, WREG
; Girar a la derecha con C (0x820) (modo Word)
                    ; Almacenar resultado en WREG
antes 
Instrucción
después 
Instrucción
WREG (W0)
 5601
WREG (W0)
 90B7
Datos 0820
 216E
Datos 0820
 216E
SR
 0001 (C = 1)
SR
 0008 (n = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 300
© 2009 Microchip Technology Inc.
  
RRC
Girar a la derecha Ws mediante Carry
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
CRR{.B} 
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
Para operación de bytes:
    (C) → Wd<7>
    (Ws<7:1>) → Wd<6:0>
    (Ws<0>) → C
Para operación de palabras:
    (C) → Wd<15>
    (Ws<15:1>) → Wd<14:0>
    (Ws<0>) → C
Estado afectado:
norte, z, c
Codificación:
1101
0011
1Bqq
qdddd
dppp
sss
Descripción:
Gire el contenido del registro fuente Ws un bit hacia la derecha 
la bandera de acarreo y coloque el resultado en el registro de destino Wd. el 
El indicador de acarreo del registro STATUS se desplaza al bit más significativo 
de Wd, y luego se sobrescribe con el bit menos significativo de Ws. 
Se puede utilizar el direccionamiento directo o indirecto de registro para Ws y Wd.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
c
Ejemplo 1:
RRC.B
W0, W3; Girar a la derecha con C (W0) (modo Byte)
                    ; Almacenar el resultado en W3
antes 
Instrucción
después 
Instrucción
W0
 9976
W0
 9976
W3
 5879
W3
 58BB
SR
 0001 (C = 1)
SR
 0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 301
Instrucción 
Descripciones
5
Ejemplo 2:
RRC
[W2++], [W8]
; Girar a la derecha con C [W2] (modo Palabra)
                     ; W2 posterior al incremento
                     ; Guardar resultado en [W8]
antes 
Instrucción
después 
Instrucción
W2
 2008
W2
 200A
W8
 094E
W8
 094E
Datos 094E
 3689
Datos 094E
 E020
Datos 2008
 C041
Datos 2008
 C041
SR
 0001 (C = 1)
SR
 0009 (N,C=1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 302
© 2009 Microchip Technology Inc.
  
RRNC
Girar a la derecha f sin llevar 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
RRNC{.B} 
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
Para operación de bytes:
    (f<7:1>) → Destino<6:0>
    (f<0>) → Destino<7>
Para operación de palabras:
    (f<15:1>) → Destino<14:0>
    (f<0>) → Destino<15>
Estado afectado:
norte, z
Codificación:
1101
0111
0BDF
ffff
ffff
ffff
Descripción:
Gire el contenido del registro de archivos f un bit hacia la derecha y coloque el 
resultado en el registro de destino. El bit menos significativo de f se almacena en 
la parte más significativa del destino y la bandera de acarreo no está 
afectado. 
El operando WREG opcional determina el registro de destino. si 
Se especifica WREG, el resultado se almacena en WREG. Si WREG no es 
especificado, el resultado se almacena en el registro de archivos.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0.
Palabras:
1
Ciclos:
1
Ejemplo 1:
RRNC.B
0x1233; Girar a la derecha (0x1233) (modo Byte)
antes 
Instrucción
después 
Instrucción
Datos 1232
 E807
Datos 1232
 7407
SR
 0000
SR
 0000
Ejemplo 2:
RRNC
0x820, WREG
; Girar a la derecha (0x820) (modo Word)
                     ; Almacenar resultado en WREG
antes 
Instrucción
después 
Instrucción
WREG (W0)
 5601
WREG (W0)
 10B7
Datos 0820
 216E
Datos 0820
 216E
SR
 0001 (C = 1)
SR
 0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 303
Instrucción 
Descripciones
5
  
RRNC
Girar a la derecha Ws sin llevar
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
RRNC{.B} 
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
Para operación de bytes:
    (Ws<7:1>) → Wd<6:0>
    (Ws<0>) → Wd<7>
Para operación de palabras:
    (Ws<15:1>) → Wd<14:0>
    (Ws<0>) → Wd<15>
Estado afectado:
norte, z
Codificación:
1101
0011
0Bqq
qdddd
dppp
sss
Descripción:
Gire el contenido del registro fuente Ws un bit hacia la derecha y 
coloque el resultado en el registro de destino Wd. La parte menos significativa 
de Ws se almacena en el bit más significativo de Wd, y el indicador de acarreo no se 
afectado. Se puede utilizar el direccionamiento directo o indirecto del registro para Ws 
y Wd.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
RRNC.B
W0, W3; Girar a la derecha (W0) (modo Byte)
                     ; Almacenar el resultado en W3
antes 
Instrucción
después 
Instrucción
W0
 9976
W0
 9976
W3
 5879
W3
 583B
SR
 0001 (C = 1)
SR
 0001 (C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 304
© 2009 Microchip Technology Inc.
Ejemplo 2:
RRNC
[W2++], [W8]
; Girar a la derecha [W2] (modo Palabra)
                      ; W2 posterior al incremento
                      ; Guardar resultado en [W8]
antes 
Instrucción
después 
Instrucción
W2
 2008
W2
 200A
W8
 094E
W8
 094E
Datos 094E
 3689
Datos 094E
 E020
Datos 2008
 C041
Datos 2008
 C041
SR
 0000
SR
 0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 305
Instrucción 
Descripciones
5
  
SACO
Acumulador de tienda
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:} 
SACO 
Acc,
{#Rendija4,}
Wd
 
[Wd]
 
[Wd++]
 
[Wd--]
 
[--Wd]
 
[++Wd]
 
[Wd + Wb]
 
Operandos:
Acc ∈ [A,B] 
Rendija4 ∈ [-8 ... +7]
Wb, Wd ∈ [W0 ... W15]
Operación:
ShiftSlit4(Acc) (opcional)
(Acc[31:16]) → Wd
Estado afectado:
Ninguno
Codificación:
1100
1100
awww
wrrr
rhhh
dddd
Descripción:
Realice un desplazamiento opcional de 4 bits con signo del acumulador especificado, luego 
almacene el contenido desplazado de ACCxH (Acc[31:16]) en Wd. El rango de cambio 
es -8:7, donde un operando negativo indica un desplazamiento aritmético hacia la izquierda y un 
El operando positivo indica un desplazamiento aritmético a la derecha. O registrarse directamente 
o se puede utilizar direccionamiento indirecto para Wd. 
El bit ‘A’ especifica el acumulador de origen. 
Los bits ‘w’ especifican el registro de compensación Wb.
Los bits ‘r’ codifican el precambio opcional del acumulador.
Los bits ‘h’ seleccionan el modo de dirección de destino.
Los bits 'd' especifican el registro de destino Wd. 
Nota 1: Esta instrucción no modifica el contenido de Acc.
2: Esta instrucción almacena el contenido truncado de Acc. el 
La instrucción SAC.R se puede utilizar para almacenar el valor redondeado. 
contenido del acumulador.
3: Si la saturación de escritura de datos está habilitada (SATDW, CORCON<5>, 
= 1), el valor almacenado en Wd está sujeto a saturación después del 
Se realiza el turno opcional.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SACO
A, #4, W5 
; Desplazamiento a la derecha ACCA en 4 
; Almacenar el resultado en W5
; CORCON = 0x0010 (SATDW = 1)
                               
antes 
Instrucción
después 
Instrucción
W5
 B900
W5
 0120
ACCA
00 120F FF00
ACCA
00 120F FF00
CORCÓN
 0010
CORCÓN
 0010
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 306
© 2009 Microchip Technology Inc.
Ejemplo 2:
SACO
B, #-4, [W5++] 
; Desplazamiento a la izquierda ACCB en 4 
; Almacenar el resultado en [W5], post-incremento W5
; CORCON = 0x0010 (SATDW = 1)
                               
antes 
Instrucción
después 
Instrucción
W5
 2000
W5
   2002
ACCB
FF C891 8F4C
ACCB
FF C891 1F4C
Datos 2000
 5BBE
Datos 2000
 8000
CORCÓN
 0010
CORCÓN
 0010
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 307
Instrucción 
Descripciones
5
  
SAC.R
Almacenar acumulador redondeado 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:} 
SAC.R 
Acc,
{#Rendija4,}
Wd
 
 
[Wd]
 
[Wd++]
 
[Wd--]
 
[--Wd]
 
[++Wd]
 
[Wd + Wb]
 
Operandos:
Acc ∈ [A,B] 
Rendija4 ∈ [-8 ... +7]
Wb ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
ShiftSlit4(Acc) (opcional)
Ronda (Acc)
(Acc[31:16]) → Wd
Estado afectado:
Ninguno
Codificación:
1100
1101
awww
wrrr
rhhh
dddd
Descripción:
Realice un desplazamiento opcional de 4 bits con signo del acumulador especificado, luego 
almacene el contenido redondeado de ACCxH (Acc[31:16]) en Wd. el cambio 
El rango es -8:7, donde un operando negativo indica un desplazamiento aritmético hacia la izquierda. 
y un operando positivo indica un desplazamiento aritmético a la derecha. El redondeo 
El modo (convencional o convergente) se establece mediante el bit RND, 
CORCÓN<1>. Se puede utilizar el direccionamiento directo o indirecto del registro. 
para Wd.
El bit ‘A’ especifica el acumulador de origen. 
Los bits ‘w’ especifican el registro de compensación Wb.
Los bits ‘r’ codifican el precambio opcional del acumulador.
Los bits ‘h’ seleccionan el modo de dirección de destino.
Los bits 'd' especifican el registro de destino Wd. 
Nota 1: Esta instrucción no modifica el contenido del Acc.
2: Esta instrucción almacena el contenido redondeado de Acc. el 
La instrucción SAC se puede utilizar para almacenar el código truncado. 
contenido del acumulador.
3: Si la saturación de escritura de datos está habilitada (SATDW, CORCON<5>, 
= 1), el valor almacenado en Wd está sujeto a saturación después del 
Se realiza el turno opcional.
Palabras:
1
Ciclos:
1

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 308
© 2009 Microchip Technology Inc.
Ejemplo 1:
SAC.R
A, #4, W5 
; Desplazamiento a la derecha ACCA en 4 
; Almacenar resultado redondeado a W5
; CORCON = 0x0010 (SATDW = 1)
                               
antes 
Instrucción
después 
Instrucción
W5
 B900
W5
 0121
ACCA
00 120F FF00
ACCA
00 120F FF00
CORCÓN
 0010
CORCÓN
 0010
SR
 0000
SR
 0000
Ejemplo 2:
SAC.R
B, #-4, [W5++]
; Desplazamiento a la izquierda ACCB en 4 
; Almacenar el resultado redondeado en [W5], W5 posterior al incremento
; CORCON = 0x0010 (SATDW = 1)
                               
antes 
Instrucción
después 
Instrucción
W5
 2000
W5
   2002
ACCB
FF F891 8F4C
ACCB
FF F891 8F4C
Datos 2000
 5BBE
Datos 2000
 8919
CORCÓN
 0010
CORCÓN
 0010
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 309
Instrucción 
Descripciones
5
  
SE
Firmar-Extender Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SE 
Ws,
viento
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
Viento ∈ [W0 ... W15]
Operación:
Ws<7:0> → Wnd<7:0>
Si (Ws<7> = 1):
    0xFF → Viento<15:8>
Más:
   0 → Viento<15:8>
Estado afectado:
norte, z, c
Codificación:
1111
1011
0000
0ddd
dppp
sss
Descripción:
Firme y extienda el byte en Ws y almacene el resultado de 16 bits en Wnd. Cualquiera 
registrar direccionamiento directo o indirecto puede usarse para Ws, y registrar 
Se debe utilizar direccionamiento directo para Wnd. La bandera C está configurada en 
complemento de la bandera N.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: Esta operación convierte un byte en una palabra y no utiliza .B o 
Extensión .W.
2: La fuente Ws se aborda como un byte operando, por lo que cualquier 
la modificación de dirección es por ‘1’.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SE W3, W4; Firmar, extender W3 y almacenar en W4
antes 
Instrucción
después 
Instrucción
W3
 7839
W3
 7839
W4
 1005
W4
 0039
SR
 0000
SR
 0001 (C = 1)
Ejemplo 2:
SE
[W2++], W12
; Firme, extienda [W2] y almacene en W12
                 ; W2 posterior al incremento
antes 
Instrucción
después 
Instrucción
W2
 0900
W2
0901
W12
 1002
W12
 FF8F
Datos 0900
 008F
Datos 0900
 008F
SR
 0000
SR
 0008 (n = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 310
© 2009 Microchip Technology Inc.
  
SETM
Establecer para WREG 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:} 
AJUSTAR{.B} 
f
WREG
Operandos:
f ∈ [0 ... 8191] 
Operación:
Para operación de bytes:
     0xFF → destino designado por D
Para operación de palabras:
     0xFFFF → destino designado por D
Estado afectado:
Ninguno
Codificación:
1110
1111
1HAB
ffff
ffff
ffff
Descripción:
Todos los bits del registro especificado se establecen en ‘1’. Si se especifica WREG, 
Los bits de WREG están configurados. De lo contrario, los bits del registro de archivo especificado 
están establecidos. 
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SETM.B 0x891; Establecer 0x891 (modo byte)
antes 
Instrucción
después 
Instrucción
Datos 0890
 2739
Datos 0890
 FF39
SR
 0000
SR
 0000
Ejemplo 2:
SETM WREG ; Establecer WREG (modo palabra)
antes 
Instrucción
después 
Instrucción
WREG (W0)
 0900
WREG (W0)
FFFFF
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 311
Instrucción 
Descripciones
5
  
SETM
Establecer W
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
AJUSTAR{.B} 
Wd
[Wd]
[Wd++]
[Wd--]
[++Wd]
[--Wd]
Operandos:
Wd ∈ [W0 ... W15] 
Operación:
Para operación de bytes:
    0xFF → Wd para operación de bytes
Para operación de palabras:
    0xFFFF → Wd para operación de palabra
Estado afectado:
Ninguno
Codificación:
1110
1011
1Bqq
qdddd
d000
0000
Descripción:
Todos los bits del registro especificado se establecen en ‘1’. O registrarse directamente o 
Se puede utilizar direccionamiento indirecto para Wd.
Los bits 'B' seleccionan la operación de byte o palabra ('0' para palabra, '1' para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
AJUSTE B W13 ; Establecer W13 (modo Byte)
antes 
Instrucción
después 
Instrucción
W13
 2739
W13
 27FF
SR
 0000
SR
 0000
Ejemplo 2:
AJUSTE [--W6]
; Pre-decremento W6 (modo Palabra)
                 ; Establecer [W6]
antes 
Instrucción
después 
Instrucción
W6
 1250
W6
 124E
Datos 124E
 3CD9
Datos 124E
 FFFFF
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 312
© 2009 Microchip Technology Inc.
  
SFTAC
Acumulador de desplazamiento aritmético de Slit6
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:} 
SFTAC
Acc,
#rendija6
Operandos:
Acc ∈ [A,B] 
Rendija6 ∈ [-16 ... 16]
Operación:
Mayúsk(Acc) → Acc
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1100
1000
A000
0000
01kk
kkkk
Descripción:
Desplazamiento aritmético del contenido de 40 bits del acumulador especificado por el 
literal firmado de 6 bits y almacena el resultado nuevamente en el acumulador. el 
El rango de desplazamiento es -16:16, donde un operando negativo indica un desplazamiento hacia la izquierda y un 
El operando positivo indica un desplazamiento a la derecha. Cualquier bit que se desplace fuera de 
el acumulador se pierde. 
El bit ‘A’ selecciona el acumulador para el resultado.
Los bits 'k' determinan el número de bits que se desplazarán.
Nota 1: Si la saturación está habilitada para el acumulador de destino (SATA, 
CORCON<7> o SATB, CORCON<6>), el valor almacenado en 
el acumulador está sujeto a saturación.
2: Si la cantidad de cambio es mayor que 16 o menor que -16, no
Se hará una modificación al acumulador y se realizará una
Se producirá una trampa aritmética. 
Palabras:
1
Ciclos:
1
Ejemplo 1:
SFTAC
R, #12
; Desplazamiento aritmético a la derecha ACCA en 12
; Guardar resultado en ACCA
; CORCON = 0x0080 (SATA = 1)
   
antes 
Instrucción
después 
Instrucción
ACCA
00 120F FF00
ACCA
00 0001 20FF
CORCÓN
 0080
CORCÓN
 0080
SR
 0000
SR
 0000
Ejemplo 2:
SFTAC
B, #-10
; Desplazamiento aritmético a la izquierda ACCB de 10 
; Guardar resultado en ACCB
; CORCON = 0x0040 (SATB = 1)
                               
antes 
Instrucción
después 
Instrucción
ACCB
FFFF1 8F4C
ACCB
FF C63D 3000
CORCÓN
 0040
CORCÓN
 0040
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 313
Instrucción 
Descripciones
5
  
SFTAC
Acumulador de desplazamiento aritmético por Wb
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:} 
SFTAC
Acc,
Wb
Operandos:
Acc ∈ [A,B] 
Wb ∈ [W0 ... W15]
Operación:
Mayús(Wb)(Acc) → Acc
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1100
1000
A000
0000
0000
sss
Descripción:
Desplazamiento aritmético del contenido de 40 bits del acumulador especificado y almacenamiento 
el resultado de nuevo al acumulador. Los 6 bits menos significativos de Wb 
se utilizan para especificar la cantidad del turno. El rango de cambio es -16:16, donde un 
un valor negativo indica un desplazamiento hacia la izquierda y un valor positivo indica un desplazamiento hacia la derecha. 
cambio. Los bits que se sacan del acumulador se pierden. 
El bit ‘A’ selecciona el acumulador para el origen/destino.
Los bits ‘s’ seleccionan la dirección del registro de conteo de desplazamiento.
Nota 1: Si la saturación está habilitada para el acumulador de destino (SATA, 
CORCON<7> o SATB, CORCON<6>), el valor almacenado en 
el acumulador está sujeto a saturación.
2: Si la cantidad de cambio es mayor que 16 o menor que -16, no
Se hará una modificación al acumulador y se realizará una
Se producirá una trampa aritmética. 
Palabras:
1
Ciclos:
1
Ejemplo 1:
SFTAC
A, W0
; Desplazamiento aritmético ACCA por (W0)
; Guardar resultado en ACCA
; CORCON = 0x0000 (saturación deshabilitada)
   
antes 
Instrucción
después 
Instrucción
W0
 FFFC
W0
 FFFC
ACCA
00 320F AB09
ACCA
03 20FA B090
CORCÓN
 0000
CORCÓN
 0000
SR
 0000
SR
 8800 (OA, OAB = 1)
Ejemplo 2:
SFTAC
B, W12
; Desplazamiento aritmético ACCB en (W12)
; Guardar resultado en ACCB
; CORCON = 0x0040 (SATB = 1)
                               
antes 
Instrucción
después 
Instrucción
W12
 000F
W12
 000F
ACCB
FFFF1 8F4C
ACCB
FF FFFF FFE3
CORCÓN
 0040
CORCÓN
 0040
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 314
© 2009 Microchip Technology Inc.
  
SL
 Desplazamiento a la izquierda f 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SL{.B} 
f
{,WREG}
Operandos:
f ∈ [0... 8191]
Operación:
Para operación de bytes:
    (f<7>) → (C)
    (f<6:0>) → Destino<7:1>
    0 → Destino<0>
Para operación de palabras:
    (f<15>) → (C)
    (f<14:0>) → Destino<15:1>
    0 → Destino<0>
Estado afectado:
norte, z, c
Codificación:
1101
0100
0BDF
ffff
ffff
ffff
Descripción:
Mueva el contenido del registro de archivo un bit hacia la izquierda y coloque el resultado 
en el registro de destino. El bit más significativo del registro de archivo es 
se desplaza al bit de acarreo del registro ESTADO y el cero se desplaza al 
el bit menos significativo del registro de destino.
El operando WREG opcional determina el registro de destino. si 
Se especifica WREG, el resultado se almacena en WREG. Si WREG no es 
especificado, el resultado se almacena en el registro de archivos.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0.
Palabras:
1
Ciclos:
1
c
0
Ejemplo 1:
SL.B 0x909; Desplazamiento a la izquierda (0x909) (modo Byte)
antes 
Instrucción
después 
Instrucción
Datos 0908
 9439
Datos 0908
 0839
SR
 0000
SR
 0001 (C = 1)
Ejemplo 2:
SL 0x1650, WREG; Mayús a la izquierda (0x1650) (modo Word)
                       ; Almacenar resultado en WREG
antes 
Instrucción
después 
Instrucción
WREG (W0)
 0900
WREG (W0)
80CA
Datos 1650
 4065
Datos 1650
4065
SR
 0000
SR
 0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 315
Instrucción 
Descripciones
5
  
SL
Desplazamiento a la izquierda Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SL{.B} 
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
Para operación de bytes:
    (Ws<7>) → C
    (Ws<6:0>) → Wd<7:1>
    0 → Wd<0>
Para operación de palabras:
    (Ws<15>) → C
    (Ws<14:0>) → Wd<15:1>
    0 → Wd<0>
Estado afectado:
norte, z, c
Codificación:
1101
0000
0Bqq
qdddd
dppp
sss
Descripción:
Desplace el contenido del registro fuente Ws un bit hacia la izquierda y coloque 
el resultado en el registro de destino Wd. La parte más significativa de W es 
se desplaza al bit de acarreo del registro STATUS y ‘0’ se desplaza al bit 
Bit menos significativo de Wd. Ya sea registrar direccionamiento directo o indirecto 
puede usarse para Ws y Wd.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
c
0
Ejemplo 1:
SL.B
W3, W4; Desplazamiento a la izquierda W3 (modo Byte)
               ; Almacenar el resultado en W4
antes 
Instrucción
después 
Instrucción
W3
 78A9
W3
 78A9
W4
 1005
W4
 1052
SR
 0000
SR
 0001 (C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 316
© 2009 Microchip Technology Inc.
Ejemplo 2:
SL
[W2++], [W12]
; Mayús a la izquierda [W2] (modo Palabra)
                   ; Guardar resultado en [W12]
                   ; W2 posterior al incremento
antes 
Instrucción
después 
Instrucción
W2
 0900
W2
0902
W12
 1002
W12
 1002
Datos 0900
 800F
Datos 0900
 800F
Datos 1002
 6722
Datos 1002
 001E
SR
 0000
SR
 0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 317
Instrucción 
Descripciones
5
 
SL
Desplazamiento a la izquierda en literal corto 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:}
SL
Wb, 
#lit4, 
viento
Operandos:
Wb ∈ [W0 ... W15]
iluminado4 ∈ [0...15]
Viento ∈ [W0 ... W15] 
Operación:
lit4<3:0> → Shift_Val
Wnd<15:Shift_Val> = Wb<15-Shift_Val:0>
Wd<Shift_Val – 1:0> = 0
Estado afectado:
norte, z
Codificación:
1101
1101
0www
wdddd
d100
kkkk
Descripción:
Shift dejó el contenido del registro fuente Wb en 4 bits sin firmar 
literal y almacenar el resultado en el registro de destino Wnd. Cualquier pedacito 
desplazados fuera del registro fuente se pierden. El direccionamiento directo debe ser 
utilizado para Wb y Wnd.
Los bits ‘w’ seleccionan la dirección del registro base.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘k’ proporcionan el operando literal, un número entero de cinco bits.
Nota:
Esta instrucción funciona únicamente en modo Word.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SL G2, #4, G2; Desplazamiento a la izquierda W2 por 4
                  ; Guardar resultado en W2
 
antes 
Instrucción
después 
Instrucción
W2
 78A9
W2
 8A90
SR
 0000
SR
 0008 (n = 1)
Ejemplo 2:
SL G3, #12, G8
; Desplazamiento a la izquierda W3 por 12
                  ; Guardar resultado en W8
antes 
Instrucción
después 
Instrucción
W3
 0912
W3
 0912
W8
 1002
W8
 2000
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 318
© 2009 Microchip Technology Inc.
  
SL
Desplazamiento a la izquierda por Wns 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:}
SL
Wb, 
WNS, 
viento
Operandos:
Wb ∈ [W0 ... W15]
Wns ∈ [W0 ...W15]
Viento ∈ [W0 ... W15] 
Operación:
Wns<4:0> → Shift_Val
Wnd<15:Shift_Val> = Wb<15 – Shift_Val:0>
Wd<Shift_Val – 1:0> = 0
Estado afectado:
norte, z
Codificación:
1101
1101
0www
wdddd
d000
sss
Descripción:
Shift dejó el contenido del registro fuente Wb en el 5 menos significativo 
bits de Wns (sólo hasta 15 posiciones) y almacenar el resultado en el destino.
registro de ción Wnd. Todos los bits desplazados fuera del registro fuente se pierden. 
Se debe utilizar el direccionamiento directo de registro para Wb, Wns y Wnd.
Los bits ‘w’ seleccionan la dirección del registro base.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: Esta instrucción funciona únicamente en modo Word.
2: Si Wns es mayor que 15, Wnd se cargará con 0x0.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SL W0, W1, W2; Desplazar a la izquierda W0 por W1<0:4>
                  ; Guardar resultado en W2
 
antes 
Instrucción
después 
Instrucción
W0
 09A4
W0
 09A4
W1
 8903
W1
 8903
W2
 78A9
W2
 4D20
SR
 0000
SR
 0000
Ejemplo 2:
SL W4, W5, W6; Desplazar a la izquierda W4 por W5<0:4>
                  ; Almacenar el resultado en W6
antes 
Instrucción
después 
Instrucción
W4
 A409
W4
 A409
W5
 FF01
W5
 FF01
W6
 0883
W6
 4812
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 319
Instrucción 
Descripciones
5
 
SUB
Resta WREG de f
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUB{.B} 
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
f) – (WREG) → destino designado por D
Estado afectado:
CC, N, OV, Z, C
Codificación:
1011
0101
0BDF
ffff
ffff
ffff
Descripción:
Reste el contenido del registro de trabajo predeterminado WREG del 
contenido del registro de archivo especificado y coloque el resultado en el 
registro de destino. El operando WREG opcional determina el 
registro de destino. Si se especifica WREG, el resultado se almacena en WREG. 
Si no se especifica WREG, el resultado se almacena en el registro del archivo.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUB.B 0x1FFF ; Sub. WREG de (0x1FFF) (modo Byte)
               ; Almacenar el resultado en 0x1FFF
antes 
Instrucción
después 
Instrucción
WREG (W0)
 7804
WREG (W0)
 7804
Datos 1FFE
 9439
Datos 1FFE
 9039
SR
 0000
SR
 0009 (N,C=1)
Ejemplo 2:
SUB 0xA04, WREG; Sub. WREG de (0xA04) (modo Palabra)
                    ; Guardar resultado en WREG
antes 
Instrucción
después 
Instrucción
WREG (W0)
 6234
WREG (W0)
 E2EF
Datos 0A04
 4523
Datos 0A04
 4523
SR
 0000
SR
 0008 (n = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 320
© 2009 Microchip Technology Inc.
  
SUB
Restar literal de Wn
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUB{.B} 
#lit10,
Wn
Operandos:
lit10 ∈ [0 ... 255] para operación de bytes
lit10 ∈ [0 ... 1023] para operación de palabra
Wn ∈ [W0 ... W15]
Operación:
(Wn) – lit10 → Wn 
Estado afectado:
CC, N, OV, Z, C
Codificación:
1011
0001
0Bkk
kkkk
kkkk
dddd
Descripción:
Reste el operando literal sin signo de 10 bits del contenido del 
registro de trabajo Wn y almacene el resultado nuevamente en el registro de trabajo 
Wn. Se debe utilizar el direccionamiento directo de registro para Wn.
El bit ‘B’ selecciona la operación de byte o palabra.
Los bits 'k' especifican el operando literal.
Los bits 'd' seleccionan la dirección del registro de trabajo.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
2: para operaciones de bytes, el literal debe especificarse como sin firmar 
valor [0:255]. Consulte la Sección 4.6 “Uso de operaciones literales de 10 bits.
ands” para obtener información sobre el uso de operandos literales de 10 bits en bytes 
modo.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUB.B
#0x23, W0; Sub. 0x23 de W0 (modo Byte)
                    ; Guardar resultado en W0
antes 
Instrucción
después 
Instrucción
W0
 7804
W0
 78E1
SR
 0000
SR
 0008 (n = 1)
Ejemplo 2:
SUB#0x108, W4; Sub. 0x108 de W4 (modo Word)
                    ; Almacenar el resultado en W4
antes 
Instrucción
después 
Instrucción
W4
 6234
W4
 612C
SR
 0000
SR
 0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 321
Instrucción 
Descripciones
5
 
SUB
Restar literal corto de Wb
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUB{.B} 
Wb,
#lit5,
Wd
[Wd]
[Wd++]
[Wd--]
[++Wd]
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
iluminado5 ∈ [0 ... 31]
Wd ∈ [W0 ... W15]
Operación:
(Wb) – lit5 → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
0101
0www
wBqq
qdddd
d11k
kkkk
Descripción:
Reste el operando literal sin signo de 5 bits del contenido de la base 
registre Wb y coloque el resultado en el registro de destino Wd. Registrarse 
Se debe utilizar el direccionamiento directo para Wb. Registro directo o indirecto 
El direccionamiento debe usarse para Wd. 
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘k’ proporcionan el operando literal, un número entero de cinco bits.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUB.B
W4, #0x10, W5; Sub. 0x10 de W4 (modo Byte)
                       ; Almacenar el resultado en W5
antes 
Instrucción
después 
Instrucción
W4
 1782
W4
 1782
W5
 7804
W5
 7872
SR
 0000
SR
 0005 (OV, C = 1)
Ejemplo 2:
SUBW0, #0x8, [W2++]; Sub. 0x8 de W0 (modo Palabra)
                          ; Guardar resultado en [W2]
                          ; W2 posterior al incremento
antes 
Instrucción
después 
Instrucción
W0
 F230
W0
 F230
W2
 2004
W2
 2006
Datos 2004
 A557
Datos 2004
 F228
SR
 0000
SR
 0009 (N,C=1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 322
© 2009 Microchip Technology Inc.
  
SUB
Restar Ws de Wb
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUB{.B} 
Wb,
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Wb) – (Ws) → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
0101
0www
wBqq
qdddd
dppp
sss
Descripción:
Reste el contenido del registro fuente Ws del contenido del 
registro base Wb y coloque el resultado en el registro de destino Wd. 
Se debe utilizar el direccionamiento directo de registro para Wb. O registrarse directamente o 
Se puede utilizar direccionamiento indirecto para Ws y Wd.
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUB.B
W0, W1, W0; Sub. W1 de W0 (modo Byte)
                    ; Guardar resultado en W0
antes 
Instrucción
después 
Instrucción
W0
 1732
W0
 17EE
W1
 7844
W1
 7844
SR
 0000
SR
 0108 (CC, N = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 323
Instrucción 
Descripciones
5
Ejemplo 2:
SUBW7, [W8++], [W9++]; Sub. [W8] de W7 (modo Palabra)
                           ; Guardar resultado en [W9]
                           ; W8 posterior al incremento
                           ; W9 posterior al incremento
antes 
Instrucción
después 
Instrucción
W7
 2450
W7
 2450
W8
 1808
W8
 180A
W9
 2020
W9
 2022
Datos 1808
 92E4
Datos 1808
 92E4
Datos 2020
 A557
Datos 2020
 916C
SR
 0000
SR
 010C (CC, N, OV = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 324
© 2009 Microchip Technology Inc.
 
SUB
Restar acumuladores 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
Sintaxis:
{etiqueta:}
SUB 
Acc
Operandos:
Acc ∈ [A,B] 
Operación:
Si (Cuenta = A): 
    ACCA – ACCB → ACCA
Más:
    ACCB – ACCA → ACCB
Estado afectado:
OA, OB, OAB, SA, SB, SAB
Codificación:
1100
1011
A011
0000
0000
0000
Descripción:
Reste el contenido del acumulador no especificado del contenido. 
de Acc y almacene el resultado nuevamente en Acc. Esta instrucción realiza una 
Resta de 40 bits.
El bit ‘A’ especifica el acumulador de destino.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUB
Un; Restar ACCB de ACCA
             ; Guarde el resultado en ACCA
             ; CORCON = 0x0000 (sin saturación)
                               
antes 
Instrucción
después 
Instrucción
ACCA
76 120F 098A
ACCA
52 1EFC 4D73
ACCB
23 F312 aC17
ACCB
23 F312 aC17
CORCÓN
 0000
CORCÓN
 0000
SR
 0000
SR
 1100 (OA, OB = 1)
Ejemplo 2:
SUB
B; Restar ACCA de ACCB
           ; Guarde el resultado en ACCB
           ; CORCON = 0x0040 (SATB = 1)
                               
antes 
Instrucción
después 
Instrucción
ACCA
FF 9022 2EE1
ACCA
FF 9022 2EE1
ACCB
00 2456 8F4C
ACCB
00 7FFFFFFF
CORCÓN
 0040
CORCÓN
 0040
SR
 0000
SR
 1400 (SB, SAB = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 325
Instrucción 
Descripciones
5
  
SUBB
Reste WREG y bit de acarreo de f 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUBB{.B} f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
(f) – (WREG) – (C) → destino designado por D
Estado afectado:
CC, N, OV, Z, C
Codificación:
1011
0101
1HAB
ffff
ffff
ffff
Descripción:
Reste el contenido del registro de trabajo predeterminado WREG y el 
Tomar prestado el indicador (llevar el indicador inverso, C) del contenido del archivo especificado 
registrarse y colocar el resultado en el registro de destino. el opcional 
El operando WREG determina el registro de destino. Si WREG es 
especificado, el resultado se almacena en WREG. Si no se especifica WREG, el 
El resultado se almacena en el registro de archivos.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0.
3: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos 
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUBB.B 0x1FFF
; Sub. WREG y C desde (0x1FFF) (modo Byte)
               ; Almacenar el resultado en 0x1FFF
antes 
Instrucción
después 
Instrucción
WREG (W0)
 7804
WREG (W0)
 7804
Datos 1FFE
 9439
Datos 1FFE
 8F39
SR
 0000
SR
 0008 (n = 1)
Ejemplo 2:
SUBB 0xA04, WREG
; Sub. WREG y C de (0xA04) (modo Word)
                  ; Guardar resultado en WREG
antes 
Instrucción
después 
Instrucción
WREG (W0)
 6234
WREG (W0)
 0000
Datos 0A04
 6235
Datos 0A04
 6235
SR
 0000
SR
 0001 (C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 326
© 2009 Microchip Technology Inc.
  
SUBB
Restar Wn del literal con préstamo 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUBB{.B}
#lit10,
Wn
Operandos:
lit10 ∈ [0 ... 255] para operación de bytes
lit10 ∈ [0 ... 1023] para operación de palabra
Wn ∈ [W0 ... W15]
Operación:
(Wn) – lit10 – (C) → Wn 
Estado afectado:
CC, N, OV, Z, C
Codificación:
1011
0001
1 libro
kkkk
kkkk
dddd
Descripción:
Reste el operando literal de 10 bits sin signo y el indicador de préstamo (llevar 
bandera inversa, C) del contenido del registro de trabajo Wn, y almacenar 
el resultado de nuevo en el registro de trabajo Wn. Registrar direccionamiento directo 
debe usarse para Wn.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits 'k' especifican el operando literal.
Los bits 'd' seleccionan la dirección del registro de trabajo.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .w para 
denota una operación de palabra, pero no es obligatoria.
2: Para operaciones de bytes, el literal debe especificarse como un 
valor sin signo [0:255]. Consulte la Sección 4.6 “Uso de literal de 10 bits 
Operandos” para obtener información sobre el uso de operandos literales de 10 bits en 
Modo byte.
3: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos 
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUBB.B
#0x23, W0; Sub. 0x23 y C de W0 (modo Byte)
                     ; Guardar resultado en W0
antes 
Instrucción
después 
Instrucción
W0
 7804
W0
 78E0
SR
 0000
SR
 0108 (CC, N = 1)
Ejemplo 2:
SUBB#0x108, W4; Sub. 0x108 y C de W4 (modo Word)
                    ; Almacenar el resultado en W4
antes 
Instrucción
después 
Instrucción
W4
 6234
W4
 612C
SR
 0001 (C = 1)
SR
 0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 327
Instrucción 
Descripciones
5
  
SUBB
Restar literal corto de Wb con préstamo 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUBB{.B} 
Wb,
#lit5,
Wd
[Wd]
[Wd++]
[Wd--]
[++Wd]
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
iluminado5 ∈ [0 ... 31]
Wd ∈ [W0 ... W15]
Operación:
(Wb) – lit5 – (C) → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
0101
1www
wBqq
qdddd
d11k
kkkk
Descripción:
Reste el operando literal sin signo de 5 bits y el indicador de préstamo (llevar 
bandera inversa, C) del contenido del registro base Wb y coloque el 
resulta en el registro de destino Wd. El direccionamiento directo del registro debe ser 
utilizado para Wb. Se puede utilizar el direccionamiento directo o indirecto del registro para 
Wd.
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘k’ proporcionan el operando literal, un número entero de cinco bits.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
2: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos 
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUBB.B
W4, #0x10, W5
; Sub. 0x10 y C de W4 (modo Byte)
                       ; Almacenar el resultado en W5
antes 
Instrucción
después 
Instrucción
W4
 1782
W4
 1782
W5
 7804
W5
 7871
SR
 0000  
SR
 0005 (OV, C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 328
© 2009 Microchip Technology Inc.
Ejemplo 2:
SUBB
W0, #0x8, [W2++]
; Sub. 0x8 y C de W0 (modo Word)
                        ; Guardar resultado en [W2]
                        ; W2 posterior al incremento
antes 
Instrucción
después 
Instrucción
W0
 0009
W0
 0009
W2
 2004
W2
 2006
Datos 2004
 A557
Datos 2004
 0000
SR
 0020 (Z = 1)
SR
 0103 (CC, Z, C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 329
Instrucción 
Descripciones
5
  
SUBB
Resta Ws de Wb con préstamo
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUBB{.B} 
Wb,
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Wb) – (Ws) – (C) → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
0101
1www
wBqq
qdddd
dppp
sss
Descripción:
Reste el contenido del registro fuente Ws y la bandera de préstamo 
(Llevar bandera inversa, C) del contenido del registro base Wb, y 
coloque el resultado en el registro de destino Wd. Registrar direccionamiento directo 
debe usarse para Wb. Se puede utilizar el direccionamiento directo o indirecto del registro. 
para Ws y Wd.
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
2: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos 
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUBB.B
W0, W1, W0; Sub. W1 y C desde W0 (modo Byte)
                     ; Guardar resultado en W0
antes 
Instrucción
después 
Instrucción
W0
 1732
W0
 17ED
W1
 7844
W1
 7844
SR
 0000
SR
 0108 (CC, N = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 330
© 2009 Microchip Technology Inc.
Ejemplo 2:
SUBB
W7,[W8++],[W9++]; Sub. [W8] y C de W7 (modo Word)
                       ; Guardar resultado en [W9]
                       ; W8 posterior al incremento
                       ; W9 posterior al incremento
antes 
Instrucción
después 
Instrucción
W7
 2450
W7
 2450
W8
 1808
W8
 180A
W9
 2022
W9
 2024
Datos 1808
 92E4
Datos 1808
 92E4
Datos 2022
 A557
Datos 2022
 916C
SR
 0000
SR
 010C (CC, N, OV = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 331
Instrucción 
Descripciones
5
  
SUBBR
Resta f de WREG con préstamo 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUBBR{.B} f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
(WREG) – (f) – (C) → destino designado por D
Estado afectado:
CC, N, OV, Z, C
Codificación:
1011
1101
1HAB
ffff
ffff
ffff
Descripción:
Reste el contenido del registro de archivo especificado f y el indicador de préstamo 
(Lleve la bandera inversa, C) del contenido de WREG y coloque el resultado 
en el registro de destino. El operando WREG opcional determina el 
registro de destino. Si se especifica WREG, el resultado se almacena en WREG. 
Si no se especifica WREG, el resultado se almacena en el registro del archivo.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0.
3: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos 
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUBBR.B 0x803
; Sub. (0x803) y C de WREG (modo Byte)
               ; Almacenar el resultado en 0x803
antes 
Instrucción
después 
Instrucción
WREG (W0)
 7804
WREG (W0)
 7804
Datos 0802
 9439
Datos 0802
 6F39
SR
 0002 (Z = 1)
SR
 0000
Ejemplo 2:
SUBBR 0xA04, WREG; Sub. (0xA04) y C de WREG (modo Word)
                  ; Guardar resultado en WREG
antes 
Instrucción
después 
Instrucción
WREG (W0)
 6234
WREG (W0)
 FFFE
Datos 0A04
 6235
Datos 0A04
 6235
SR
 0000
SR
 0008 (n = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 332
© 2009 Microchip Technology Inc.
 
SUBBR
Resta Wb del literal corto con préstamo 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUBBR{.B} Wb,
#lit5,
Wd
[Wd]
[Wd++]
[Wd--]
[++Wd]
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
iluminado5 ∈ [0 ... 31]
Wd ∈ [W0 ... W15]
Operación:
lit5 – (Wb) – (C) → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
0001
1www
wBqq
qdddd
d11k
kkkk
Descripción:
Reste el contenido del registro base Wb y la bandera Borrow (Carry 
bandera inversa, C) del literal sin signo de 5 bits y coloque el resultado en el 
registro de destino Wd. Se debe utilizar el direccionamiento directo de registro para Wb. 
Se debe utilizar el direccionamiento directo o indirecto del registro para Wd. 
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘k’ proporcionan el operando literal, un número entero de cinco bits.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
2: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos 
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUBBR.B
W0, #0x10, W1; Sub. W0 y C desde 0x10 (modo Byte)
                       ; Guardar resultado en W1
antes 
Instrucción
después 
Instrucción
W0
 F310
W0
 F310
W1
 786A
W1
 7800
SR
 0003 (Z,C=1) 
SR
 0103 (CC, Z, C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 333
Instrucción 
Descripciones
5
Ejemplo 2:
SUBBR
W0, #0x8, [W2++]; Sub. W0 y C desde 0x8 (modo Word)
                        ; Guardar resultado en [W2]
                        ; W2 posterior al incremento
antes 
Instrucción
después 
Instrucción
W0
 0009
W0
 0009
W2
 2004
W2
 2006
Datos 2004
 A557
Datos 2004
 FFFE
SR
 0020 (Z = 1)
SR
 0108 (CC, N = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 334
© 2009 Microchip Technology Inc.
SUBBR
Resta Wb de Ws con préstamo
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUBBR{.B} Wb,
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Ws) – (Wb) – (C) → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
0001
1www
wBqq
qdddd
dppp
sss
Descripción:
Reste el contenido del registro base Wb y la bandera Borrow (Carry 
bandera inversa, C) del contenido del registro fuente Ws y lugar 
el resultado en el registro de destino Wd. Registrar el direccionamiento directo debe 
utilizarse para Wb. Se podrá utilizar el direccionamiento directo o indirecto del registro para 
Ws y Wd.
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
2: La bandera Z es “pegajosa” para ADDC, CPB, SUBB y SUBBR. Estos 
Las instrucciones solo pueden borrar Z.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUBBR.B
W0, W1, W0; Sub. W0 y C de W1 (modo Byte)
                      ; Guardar resultado en W0
antes 
Instrucción
después 
Instrucción
W0
 1732
W0
 1711
W1
 7844
W1
 7844
SR
 0000
SR
 0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 335
Instrucción 
Descripciones
5
Ejemplo 2:
SUBBR W7,[W8++],[W9++] ; Sub. W7 y C desde [W8] (modo Word)
                       ; Guardar resultado en [W9]
                       ; W8 posterior al incremento
                       ; W9 posterior al incremento
antes 
Instrucción
después 
Instrucción
W7
 2450
W7
 2450
W8
 1808
W8
 180A
W9
 2022
W9
 2024
Datos 1808
 92E4
Datos 1808
 92E4
Datos 2022
 A557
Datos 2022
 6E93
SR
 0000
SR
 0005 (OV, C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 336
© 2009 Microchip Technology Inc.
  
SUBR
Resta f de WREG
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUBR{.B}f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
(WREG) – (f) → destino designado por D
Estado afectado:
CC, N, OV, Z, C
Codificación:
1011
1101
0BDF
ffff
ffff
ffff
Descripción:
Reste el contenido del registro de archivo especificado del contenido de 
el registro de trabajo predeterminado WREG y coloque el resultado en el 
registro de destino. El operando WREG opcional determina el 
registro de destino. Si se especifica WREG, el resultado se almacena en WREG. 
Si no se especifica WREG, el resultado se almacena en el registro de archivos.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUBR.B
0x1FFF; Sub. (0x1FFF) de WREG (modo Byte)
                 ; Almacenar el resultado en 0x1FFF
antes 
Instrucción
después 
Instrucción
WREG (W0)
 7804
WREG (W0)
 7804
Datos 1FFE
 9439
Datos 1FFE
 7039
SR
 0000
SR
 0000  
Ejemplo 2:
SUBR
0xA04, WREG
; Sub. (0xA04) de WREG (modo Palabra)
                   ; Guardar resultado en WREG
antes 
Instrucción
después 
Instrucción
WREG (W0)
 6234
WREG (W0)
 FFFFF
Datos 0A04
 6235
Datos 0A04
 6235
SR
 0000
SR
 0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 337
Instrucción 
Descripciones
5
  
SUBR
Restar Wb del literal corto 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUBR{.B} 
Wb,
#lit5
Wd
[Wd]
[Wd++]
[Wd--]
[++Wd]
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
iluminado5 ∈ [0 ... 31]
Wd ∈ [W0 ... W15]
Operación:
lit5 – (Wb) → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
0001
0www
wBqq
qdddd
d11k
kkkk
Descripción:
Reste el contenido del registro base Wb de los 5 bits sin signo 
operando literal y coloque el resultado en el registro de destino Wd. 
Se debe utilizar el direccionamiento directo de registro para Wb. O registrarse directamente o 
Se puede utilizar direccionamiento indirecto para Wd. 
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘k’ proporcionan el operando literal, un número entero de cinco bits.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUBR.B
W0, #0x10, W1
; Sub. W0 de 0x10 (modo Byte)
                       ; Guardar resultado en W1
antes 
Instrucción
después 
Instrucción
W0
 F310
W0
 F310
W1
 786A
W1
 7800
SR
 0000  
SR
 0103 (CC, Z, C = 1)
Ejemplo 2:
SUBR W0, #0x8, [W2++]
; Sub. W0 de 0x8 (modo Word)
                         ; Guardar resultado en [W2]
                         ; W2 posterior al incremento
antes 
Instrucción
después 
Instrucción
W0
 0009
W0
 0009
W2
 2004
W2
 2006
Datos 2004
 A557
Datos 2004
 FFFFF
SR
 0000  
SR
 0108 (CC, N = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 338
© 2009 Microchip Technology Inc.
  
SUBR
Restar Wb de Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
SUBR{.B} 
Wb,
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Ws) – (Wb) → Wd 
Estado afectado:
CC, N, OV, Z, C
Codificación:
0001
0www
wBqq
qdddd
dppp
sss
Descripción:
Reste el contenido del registro base Wb del contenido del 
registro de origen Ws y coloque el resultado en el registro de destino Wd. 
Se debe utilizar el direccionamiento directo de registro para Wb. O registrarse directamente o 
Se puede utilizar direccionamiento indirecto para Ws y Wd.
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
SUBR.B
W0, W1, W0; Sub. W0 de W1 (modo Byte)
                     ; Guardar resultado en W0
antes 
Instrucción
después 
Instrucción
W0
 1732
W0
 1712
W1
 7844
W1
 7844
SR
 0000
SR
 0001 (C = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 339
Instrucción 
Descripciones
5
Ejemplo 2:
SUBR
W7, [W8++], [W9++]
; Sub. W7 de [W8] (modo Palabra)
                          ; Guardar resultado en [W9]
                          ; W8 posterior al incremento
                          ; W9 posterior al incremento
antes 
Instrucción
después 
Instrucción
W7
 2450
W7
 2450
W8
 1808
W8
 180A
W9
 2022
W9
 2024
Datos 1808
 92E4
Datos 1808
 92E4
Datos 2022
 A557
Datos 2022
 6E94
SR
 0000
SR
 0005 (OV, C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 340
© 2009 Microchip Technology Inc.
  
INTERCAMBIAR
Intercambio de bytes o nibble Wn
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
INTERCAMBIAR{.B}
Wn
Operandos:
Wn ∈ [W0 ... W15]
Operación:
Para operación de bytes:
    (Wn)<7:4> ↔ (Wn)<3:0> 
Para operación de palabras:
    (Wn)<15:8> ↔ (Wn)<7:0> 
Estado afectado:
Ninguno
Codificación:
1111
1101
1B00
0000
0000
sss
Descripción:
Intercambie el contenido del registro de trabajo Wn. En modo Word, los dos 
Se intercambian bytes de Wn. En modo Byte, los dos nibbles del mínimo 
Se intercambian los bytes importantes de Wn y el byte más significativo de 
Wn no ha cambiado. Se debe utilizar el direccionamiento directo de registro para Wn.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘s’ seleccionan la dirección del registro de trabajo.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
INTERCAMBIO.B
W0; Intercambio de mordiscos (W0)
antes 
Instrucción
después 
Instrucción
W0
 AB87
W0
 AB78
SR
 0000
SR
 0000  
Ejemplo 2:
INTERCAMBIAR W0; Intercambio de bytes (W0) 
antes 
Instrucción
después 
Instrucción
W0
 8095
W0
 9580
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 341
Instrucción 
Descripciones
5
  
TBLRDH
Tabla de lectura alta
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
TBLRDH{.B} [Ws],
Wd
[Ws++],
[Wd]
[Ws--],
[Wd++]
[++Ws],
[Wd--]
[--Ws],
[++Wd]
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
Para operación de bytes: 
    Si (LSB(Ws) = 1)
        0 → Wd
    más 
        Memoria de programa [(TBLPAG),(Ws)] <23:16> → Wd
Para operación de palabras:
    Memoria de programa [(TBLPAG),(Ws)] <23:16> → Wd <7:0>
    0 → Wd <15:8>
Estado afectado:
Ninguno
Codificación:
1011
1010
1Bqq
qdddd
dppp
sss
Descripción:
Leer el contenido de la palabra más significativa de la memoria del programa y 
guárdelo en el registro de destino Wd. La dirección de la palabra objetivo del programa. 
la memoria se forma concatenando el registro de puntero de tabla de 8 bits, 
TBLPAG<7:0>, con la dirección efectiva especificada por Ws. indirecto 
El direccionamiento debe usarse para W y registrar directa o indirectamente. 
El direccionamiento se puede utilizar para Wd.
En el modo Word, el cero se almacena en el byte más significativo del destino. 
registro (debido a la inexistencia de memoria de programa) y el tercer programa 
byte de memoria (PM<23:16>) en la dirección de memoria del programa especificada es 
almacenado en el byte menos significativo del registro de destino.
En modo Byte, la dirección de origen depende del contenido de Ws. Si Ws es 
no está alineado con palabras, el cero se almacena en el registro de destino (debido a 
memoria de programa inexistente). Si Ws está alineado con palabras, el tercer programa 
byte de memoria (PM<23:16>) en la dirección de memoria del programa especificada es 
almacenado en el registro de destino.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota un movimiento de bytes en lugar de
que un movimiento de palabra. Puede utilizar una extensión .W para indicar una
movimiento de palabra, pero no es obligatorio.
Palabras:
1
Ciclos:
2

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 342
© 2009 Microchip Technology Inc.
Ejemplo 1:
TBLRDH.B
[W0], [W1++]
; Leer PM (TBLPAG:[W0]) (modo Byte)
                        ; Guardar en [W1]
                        ; W1 posterior al incremento
antes 
Instrucción
después 
Instrucción
W0
    0812
W0
 0812
W1
    0F71
W1
 0F72
Datos 0F70
 0944
Datos 0F70
 EF44
Programa 01 0812
 EF 2042
Programa 01 0812
EF 2042
TBLPAG
 0001
TBLPAG
 0001
SR
 0000
SR
 0000
Ejemplo 2:
TBLRDH [W6++], W8; Leer PM (TBLPAG:[W6]) (modo Word)
                      ; Almacenar en W8
                      ; W6 posterior al incremento
antes 
Instrucción
después 
Instrucción
W6
    3406
W6
 3408
W8
    65B1
W8
 0029
Programa 00 3406
 29 2E40
Programa 00 3406
29 2E40
TBLPAG
 0000
TBLPAG
 0000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 343
Instrucción 
Descripciones
5
  
TBLRDL
Lectura de tabla baja
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
TBLRDL{.B} [Ws],
Wd
[Ws++],
[Wd]
[Ws--],
[Wd++]
[++Ws],
[Wd--]
[--Ws],
[++Wd]
[--Wd]
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
Para operación de bytes: 
    Si (LSB(Ws) = 1)
        Memoria de programa [(TBLPAG),(Ws)] <15:8> → Wd
    más 
        Memoria de programa [(TBLPAG),(Ws)] <7:0> → Wd
Para operación de palabras:
    Memoria de programa [(TBLPAG),(Ws)] <15:0> → Wd
Estado afectado:
Ninguno
Codificación:
1011
1010
0Bqq
qdddd
dppp
sss
Descripción:
Leer el contenido de la palabra menos significativa de la memoria del programa y 
guárdelo en el registro de destino Wd. La dirección de la palabra objetivo del programa. 
la memoria se forma concatenando el registro de puntero de tabla de 8 bits, 
TBLPAG<7:0>, con la dirección efectiva especificada por Ws. indirecto 
El direccionamiento debe usarse para W y registrar directa o indirectamente. 
El direccionamiento se puede utilizar para Wd.
En el modo Word, los 2 bytes inferiores de la memoria del programa se almacenan en el 
registro de destino. En modo Byte, la dirección de origen depende del 
Contenido de Ws. Si Ws no está alineado con palabras, el segundo byte del programa 
La palabra de memoria (PM<15:7>) se almacena en el registro de destino. Si Ws es 
alineado con palabras, el primer byte de la palabra de memoria del programa (PM<7:0>) es 
almacenado en el registro de destino.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para modo de palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota un movimiento de bytes en lugar de
que un movimiento de palabra. Puede utilizar una extensión .W para indicar una
movimiento de palabra, pero no es obligatorio.
Palabras:
1
Ciclos:
2

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 344
© 2009 Microchip Technology Inc.
Ejemplo 1:
TBLRDL.B
[W0++], W1
; Leer PM (TBLPAG:[W0]) (modo Byte)
                      ; Almacenar en W1
                      ; W0 posterior al incremento
antes 
Instrucción
después 
Instrucción
W0
    0813
W0
 0814
W1
    0F71
W1
 0F20
Datos 0F70
 0944
Datos 0F70
 EF44
Programa 01 0812
 EF 2042
Programa 01 0812
EF 2042
TBLPAG
 0001
TBLPAG
 0001
SR
 0000
SR
 0000
Ejemplo 2:
TBLRDL[W6], [W8++]; Leer PM (TBLPAG:[W6]) (modo Word)
                        ; Almacenar en W8
                        ; W8 posterior al incremento
antes 
Instrucción
después 
Instrucción
W6
    3406
W6
 3408
W8
    1202
W8
 1204
Datos 1202
    658B
Datos 1202
 2E40
Programa 00 3406
 29 2E40
Programa 00 3406
29 2E40
TBLPAG
 0000
TBLPAG
 0000
SR
 0000
SR
 0000

© 2009 Microchip Technology Inc.
DS70157D-página 345
Instrucción 
Descripciones
5
  
TBLWTH
Escritura de tabla alta
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
TBLWTH{.B} Ws,
[Wd]
[Ws],
[Wd++]
[Ws++],
[Wd--]
[Ws--],
[++Wd]
[++Ws],
[--Wd]
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
Para operación de bytes:
    Si (LSB(Wd) = 1)
        NOP
    más
        (Ws) → Memoria de programa [(TBLPAG), (Wd)]<23:16>
Para operación de palabras:
    (Ws)<7:0> → Memoria de programa [(TBLPAG),(Wd)] <23:16>
Estado afectado:
Ninguno
Codificación:
1011
1011
1Bqq
qdddd
dppp
sss
Descripción:
Almacene el contenido del registro fuente de trabajo Ws en el más significativo 
palabra de la memoria del programa. La dirección de la palabra de destino del miembro del programa.
La memoria se forma concatenando el registro de puntero de tabla de 8 bits, 
TBLPAG<7:0>, con la dirección efectiva especificada por Wd. Ya sea directo o 
Se puede utilizar el direccionamiento indirecto para W, y el direccionamiento indirecto debe 
utilizado para Wd.
Dado que la memoria del programa tiene 24 bits de ancho, esta instrucción sólo puede escribir en el 
byte superior de la memoria del programa (PM<23:16>). Esto se puede realizar usando 
un Wd que está alineado con palabras en modo Byte o modo Word. Si el modo Byte es 
utilizado con un Wd que no está alineado con palabras, no se realiza ninguna operación.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota un movimiento de bytes en lugar de
que un movimiento de palabra. Puede utilizar una extensión .W para indicar una palabra.
moverse, pero no es obligatorio.
Palabras:
1
Ciclos:
2

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 346
© 2009 Microchip Technology Inc.
Ejemplo 1:
TBLWTH.B
[W0++], [W1]
; Escribir [W0]... (modo byte)
                        ; a PM Latch High (TBLPAG:[W1])
                        ; W0 posterior al incremento
antes 
Instrucción
después 
Instrucción
W0
    0812
W0
 0812
W1
    0F70
W1
 0F70
Datos 0812
 0944
Datos 0812
 EF44
Programa 01 0F70
 EF 2042
Programa 01 0F70
44 2042
TBLPAG
 0001
TBLPAG
 0001
SR
 0000
SR
 0000
Nota:
Sólo se escribe en Program Latch. El contenido de la memoria del programa.
no se actualizan hasta que la memoria Flash se programa usando el
procedimiento descrito en el manual de referencia de la familia de dispositivos específica.
Ejemplo 2:
TBLWTHW6, [W8++]; Escribe W6... (modo Word)
                      ; a PM Latch High (TBLPAG:[W8])
                      ; W8 posterior al incremento
antes 
Instrucción
después 
Instrucción
W6
    0026
W6
 0026
W8
    0870
W8
 0872
Programa 00 0870
 22 3551
Programa 00 0870
26 3551
TBLPAG
 0000
TBLPAG
 0000
SR
 0000
SR
 0000
Nota:
Sólo se escribe en Program Latch. El contenido de la memoria del programa.
no se actualizan hasta que la memoria Flash se programa usando el
procedimiento descrito en el manual de referencia de la familia de dispositivos específica.

© 2009 Microchip Technology Inc.
DS70157D-página 347
Instrucción 
Descripciones
5
  
TBLWTL
Escritura de tabla baja
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
TBLWTL{.B} Ws,
[Wd]
[Ws],
[Wd++]
[Ws++],
[Wd--]
[Ws--],
[++Wd]
[++Ws],
[--Wd]
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
Para operación de bytes: 
    Si (LSB(Wd)=1)
        (Ws) → Memoria de programa [(TBLPAG), (Wd)] <15:8>
    más
        (Ws) → Memoria de programa [(TBLPAG),(Wd)] <7:0>
Para operación de palabras:
    (Ws) → Memoria de programa [(TBLPAG),(Wd)] <15:0>
Estado afectado:
Ninguno
Codificación:
1011
1011
0Bqq
qdddd
dppp
sss
Descripción:
Almacene el contenido del registro fuente de trabajo Ws al menos significativo 
palabra de la memoria del programa. La dirección de la palabra de destino del programa. 
la memoria se forma concatenando el registro de puntero de tabla de 8 bits, 
TBLPAG<7:0>, con la dirección efectiva especificada por Wd. Ya sea directo o 
Se puede utilizar el direccionamiento indirecto para W, y el direccionamiento indirecto debe 
utilizado para Wd.
En modo Word, Ws se almacena en los 2 bytes inferiores de la memoria del programa. en 
En el modo byte, el bit menos significativo de Wd determina el byte de destino. 
Si Wd no está alineado con palabras, Ws se almacena en el segundo byte del programa. 
memoria (PM<15:8>). Si Wd está alineado con palabras, Ws se almacena en el primer byte de 
memoria de programa (PM<7:0>).
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota un movimiento de bytes en lugar de
que un movimiento de palabra. Puede utilizar una extensión .W para indicar una palabra.
moverse, pero no es obligatorio.
Palabras:
1
Ciclos:
2

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 348
© 2009 Microchip Technology Inc.
Ejemplo 1:
TBLWTL.B
W0, [W1++]
; Escribe W0... (modo byte)
                      ; a PM Latch Low (TBLPAG:[W1])
                      ; W1 posterior al incremento
antes 
Instrucción
después 
Instrucción
W0
    6628
W0
 6628
W1
    1225
W1
 1226
Programa 00 1224
 78 0080
Programa 01 1224
78 2880
TBLPAG
 0000
TBLPAG
 0000
SR
 0000
SR
 0000
Nota:
Sólo se escribe en Program Latch. El contenido de la memoria del programa.
no se actualizan hasta que la memoria Flash se programa usando el
procedimiento descrito en el manual de referencia de la familia de dispositivos específica.
Ejemplo 2:
TBLWTL[W6], [W8]; Escribir [W6]... (modo Palabra)
                      ; a PM Latch Low (TBLPAG:[W8])
                      ; W8 posterior al incremento
antes 
Instrucción
después 
Instrucción
W6
    1600
W6
 1600
W8
    7208
W8
 7208
Datos 1600
    0130
Datos 1600
 0130
Programa 01 7208
 09 0002
Programa 01 7208
09 0130
TBLPAG
 0001
TBLPAG
 0001
SR
 0000
SR
 0000
Nota:
Sólo se escribe en Program Latch. El contenido de la memoria del programa.
no se actualizan hasta que la memoria Flash se programa usando el
procedimiento descrito en el manual de referencia de la familia de dispositivos específica.

© 2009 Microchip Technology Inc.
DS70157D-página 349
Instrucción 
Descripciones
5
     
ULNK
Desasignar marco de pila
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
ULNK
Operandos:
Ninguno
Operación:
W14 → W15
(W15) – 2 → W15
(TOS) → W14
Estado afectado:
Ninguno
Codificación:
1111
1010
1000
0000
0000
0000
Descripción:
Esta instrucción desasigna un marco de pila para una llamada de subrutina 
secuencia. El marco de pila se desasigna configurando el puntero de pila 
(W15) igual al puntero de marco (W14) y luego hacer estallar la pila 
para restablecer el puntero de fotograma (W14).
Palabras:
1
Ciclos:
1
Ejemplo 1:
ULNK; Desvincular el marco de la pila
antes 
Instrucción
después 
Instrucción
W14
 2002
W14
 2000
W15
 20A2
W15
 2000
Datos 2000
 2000
Datos 2000
 2000
SR
 0000
SR
 0000
 
Ejemplo 2:
ULNK; Desvincular el marco de la pila
antes 
Instrucción
después 
Instrucción
W14
 0802
W14
 0800
W15
 0812
W15
 0800
Datos 0800
 0800
Datos 0800
 0800
SR
 0000
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 350
© 2009 Microchip Technology Inc.
 
XOR
Exclusivo OR f y WREG 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
XOR{.B} 
f
{,WREG}
Operandos:
f ∈ [0 ... 8191]
Operación:
(f).XOR.(WREG) → destino designado por D
Estado afectado:
norte, z
Codificación:
1011
0110
1HAB
ffff
ffff
ffff
Descripción:
Calcule la operación OR lógica exclusiva del contenido del 
registro de trabajo predeterminado WREG y el contenido del archivo especificado 
registrarse y colocar el resultado en el registro de destino. el opcional 
El operando WREG determina el registro de destino. Si WREG es 
especificado, el resultado se almacena en WREG. Si no se especifica WREG, el 
El resultado se almacena en el registro de archivos.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
El bit 'D' selecciona el destino ('0' para WREG, '1' para registro de archivo).
Los bits 'f' seleccionan la dirección del registro del archivo.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
2: El WREG está configurado en el registro de trabajo W0.
Palabras:
1
Ciclos:
1
Ejemplo 1:
XOR.B
0x1FFF; XOR (0x1FFF) y WREG (modo Byte)
                 ; Almacenar el resultado en 0x1FFF
antes 
Instrucción
después 
Instrucción
WREG (W0)
 7804
WREG (W0)
 7804
Datos 1FFE
 9439
Datos 1FFE
 9039
SR
 0000
SR
 0008 (n = 1)
Ejemplo 2:
XOR 0xA04, WREG
; XOR (0xA04) y WREG (modo Palabra)
                    ; Guardar resultado en WREG
antes 
Instrucción
después 
Instrucción
WREG (W0)
 6234
WREG (W0)
 C267
Datos 0A04
 A053
Datos 0A04
 A053
SR
 0000
SR
 0008 (n = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 351
Instrucción 
Descripciones
5
XOR
Exclusivo OR Literal y Wn 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
XOR{.B} 
#lit10,
Wn
Operandos:
lit10 ∈ [0 ... 255] para operación de bytes
lit10 ∈ [0 ... 1023] para operación de palabra
Wn ∈ [W0 ... W15]
Operación:
lit10.XOR.(Wn) → Wn
Estado afectado:
norte, z
Codificación:
1011
0010
1 libro
kkkk
kkkk
dddd
Descripción:
Calcule la operación lógica exclusiva OR del literal de 10 bits sin signo 
operando y el contenido del registro de trabajo Wn y almacenar el resultado 
de nuevo en el registro de trabajo Wn. El direccionamiento directo del registro debe ser 
utilizado para Wn.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits 'k' especifican el operando literal.
Los bits 'd' seleccionan la dirección del registro de trabajo.
Nota 1: La extensión .B en la instrucción denota una operación de byte 
en lugar de una operación de palabras. Puede utilizar una extensión .W para 
denota una operación de palabra, pero no es obligatoria.
2: para operaciones de bytes, el literal debe especificarse como sin firmar
valor [0:255]. Consulte la Sección 4.6 “Uso de operaciones literales de 10 bits.
ands” para obtener información sobre el uso de operandos literales de 10 bits en bytes
modo.
Palabras:
1
Ciclos:
1
Ejemplo 1:
XOR.B
#0x23, W0; XOR 0x23 y W0 (modo Byte)
                     ; Guardar resultado en W0
antes 
Instrucción
después 
Instrucción
W0
 7804
W0
 7827
SR
 0000
SR
 0000  
Ejemplo 2:
XOR #0x108, W4; XOR 0x108 y W4 (modo Word)
                     ; Almacenar el resultado en W4
antes 
Instrucción
después 
Instrucción
W4
 6134
W4
 603C
SR
 0000  
SR
 0000

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 352
© 2009 Microchip Technology Inc.
  
XOR
Exclusivo OR Wb y Literal Corto 
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
XOR{.B} 
Wb,
#lit5,
Wd
[Wd]
[Wd++]
[Wd--]
[++Wd]
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
iluminado5 ∈ [0 ... 31]
Wd ∈ [W0 ... W15]
Operación:
(Wb).XOR.lit5 → Wd 
Estado afectado:
norte, z
Codificación:
0110
1www
wBqq
qdddd
d11k
kkkk
Descripción:
Calcular la operación lógica OR exclusiva del contenido de la base 
registre Wb y el operando literal de 5 bits sin signo y coloque el resultado en 
el registro de destino Wd. Se debe utilizar el direccionamiento directo de registro para 
Wb. Para Wd se puede utilizar el direccionamiento directo o indirecto del registro.
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte).
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘k’ proporcionan el operando literal, un número entero de 5 bits.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
XOR.B
W4, #0x16, W5; XOR W4 y 0x14 (modo Byte)
                         ; Almacenar el resultado en W5
antes 
Instrucción
después 
Instrucción
W4
 C822
W4
 C822
W5
 1200
W5
 1234
SR
 0000
SR
 0000
Ejemplo 2:
XOR W2, #0x1F, [W8++]
; XOR W2 por 0x1F (modo Palabra)
                          ; Guardar resultado en [W8]
                          ; W8 posterior al incremento
     antes 
    Instrucción
      después 
    Instrucción
W2
 8505
W2
 8505
W8
 1004
W8
 1006
Datos 1004
 6628
Datos 1004
 851A
SR
 0000
SR
 0008
(norte = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 353
Instrucción 
Descripciones
5
 
XOR
Exclusivo OR Wb y Ws
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
XOR{.B} 
Wb,
Ws,
Wd
[Ws],
[Wd]
[Ws++],
[Wd++]
[Ws--],
[Wd--]
[++Ws],
[++Wd]
[--Ws],
[--Wd]
Operandos:
Wb ∈ [W0 ... W15]
Ws ∈ [W0 ... W15]
Wd ∈ [W0 ... W15]
Operación:
(Wb).XOR.(Ws) → Wd 
Estado afectado:
norte, z
Codificación:
0110
1www
wBqq
qdddd
dppp
sss
Descripción:
Calcular la operación OR lógica exclusiva del contenido de la fuente 
registrar Ws y el contenido del registro base Wb, y colocar el 
resulta en el registro de destino Wd. El direccionamiento directo del registro debe ser 
utilizado para Wb. Se puede utilizar el direccionamiento directo o indirecto del registro para 
Ws y Wd.
Los bits ‘w’ seleccionan la dirección del registro base.
El bit ‘B’ selecciona la operación de byte o palabra (‘0’ para palabra, ‘1’ para byte). 
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota:
La extensión .B en la instrucción denota una operación de byte.
en lugar de una operación de palabras. Puede utilizar una extensión .W para
denota una operación de palabra, pero no es obligatoria.
Palabras:
1
Ciclos:
1
Ejemplo 1:
XOR.B
W1, [W5++], [W9++]
; XOR W1 y [W5] (modo Byte)
                           ; Guardar resultado en [W9]
                           ; W5 y W9 posteriores al incremento
antes 
Instrucción
después 
Instrucción
W1
 AAAAA
W1
 AAAAA
W5
 2000
W5
 2001
W9
 2600
W9
 2601
Datos 2000
115A
Datos 2000
115A
Datos 2600
0000
Datos 2600
00F0
SR
 0000
SR
 0008
(norte = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 354
© 2009 Microchip Technology Inc.
Ejemplo 2:
XOR
W1, W5, W9; XOR W1 y W5 (modo Palabra)
                       ; Guarde el resultado en W9
        
     antes 
    Instrucción
      después 
    Instrucción
W1
 FEDC
W1
 FEDC
W5
 1234
W5
 1234
W9
 A34D
W9
 ECE8
SR
 0000
SR
 0008
(norte = 1)

© 2009 Microchip Technology Inc.
DS70157D-página 355
Instrucción 
Descripciones
5
  
ZE
Wn de extensión cero
Implementado en:
PIC24F
PIC24H
dsPIC30F
dsPIC33F
x
x
x
x
Sintaxis:
{etiqueta:} 
ZE 
Ws,
viento
[Ws],
[Ws++],
[Ws--],
[++Ws],
[--Ws],
Operandos:
Ws ∈ [W0 ... W15]
Viento ∈ [W0 ... W15]
Operación:
Ws<7:0> → Wnd<7:0>
0 → Viento<15:8>
Estado afectado:
norte, z, c
Codificación:
1111
1011
10qq
qdddd
dppp
sss
Descripción:
Extienda a cero el byte menos significativo en el registro de trabajo de origen Ws a 
un valor de 16 bits y almacenar el resultado en el registro de trabajo de destino 
Viento. Se puede utilizar el direccionamiento directo o indirecto de registro para Ws, 
y se debe utilizar el direccionamiento directo de registro para Wnd. La bandera N es 
se borra y se establece el indicador C, porque la palabra extendida en cero siempre es 
positivo.
Los bits ‘q’ seleccionan el modo de dirección de destino.
Los bits 'd' seleccionan el registro de destino.
Los bits ‘p’ seleccionan el modo de dirección de origen.
Los bits ‘s’ seleccionan el registro fuente.
Nota 1: Esta operación convierte un byte en una palabra y no utiliza .B o 
Extensión .W.
2: La fuente Ws se aborda como un byte operando, por lo que cualquier
la modificación de dirección es por ‘1’.
Palabras:
1
Ciclos:
1
Ejemplo 1:
ZE W3, W4 ; W3 de extensión cero
              ; Almacenar el resultado en W4
antes 
Instrucción
después 
Instrucción
W3
 7839
W3
 7839
W4
 1005
W4
 0039
SR
 0000
SR
 0001 (C = 1)
Ejemplo 2:
ZE
[W2++], W12
; Extensión cero [W2]
                 ; Almacenar en W12
                 ; W2 posterior al incremento
antes 
Instrucción
después 
Instrucción
W2
 0900
W2
0901
W12
 1002
W12
 008F
Datos 0900
 268F
Datos 0900
 268F
SR
 0000
SR
 0001 (C = 1)

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 356
© 2009 Microchip Technology Inc.
NOTAS:

© 2009 Microchip Technology Inc.
DS70157D-página 357
Referencia
6
Sección 6. Referencia
DESTACADOS
Esta sección del manual contiene los siguientes temas principales:
6.1
Mapa de bits de instrucción ........................................................................................ 358
6.2
Tabla de resumen del conjunto de instrucciones................................................................ 360
6.3
Historial de revisiones................................................................................................................ 367

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 358
© 2009 Microchip Technology Inc.
6.1
 MAPA DE BITS DE INSTRUCCIONES
La codificación de instrucciones para los dispositivos de la familia MCU y DSC de 16 bits se resume en la Tabla 6-1. esto
La tabla contiene la codificación del byte más significativo (MSB) de cada instrucción. el primero
La columna de la tabla representa los bits 23:20 del código de operación y la primera fila de la tabla representa
bits 19:16 del código de operación. El primer byte del código de operación se forma tomando el valor del bit de la primera columna.
y añadiendo el valor de bit de la primera fila. Por ejemplo, el MSB de la instrucción PUSH (última fila,
novena columna) está codificado con 11111000b (0xF8).   
Nota:
El código de operación completo para cada instrucción puede ser determinado por la instrucción
descripciones en la Sección 5. “Descripciones de instrucciones”, utilizando la Tabla 5-1 a través
Tabla 5-12.

© 2009 Microchip Technology Inc. Todos los derechos reservados.
DS70157D-página 359
Sección 6. Referencia
Referencia
6
Tabla 6-1:
Codificación de instrucciones
Código de operación<19:16>
0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010
1011
1100
1101
1110
1111
Código de operación<23:20>
0000
NOP
sujetador
LLAMADA
IR A
LLAMADA
LLAMADA
—
IR A
RETLW
REFIE
VOLVER
LLAMADA
HACER(1)
REPETIR
—
—
sujetador(1)
(OA)
sujetador(1)
(OB)
sujetador(1)
(SA)
sujetador(1)
(SB)
0001
SUBR
SUBBR
0010
MOVIMIENTO
0011
sujetador
(VO)
sujetador 
(C)
sujetador
(Z)
sujetador
(norte)
sujetador
(Y)
sujetador
(LT)
sujetador
(LEU)
sujetador
BRA (NOV)
sujetador
(Carolina del Norte)
sujetador
(Nueva Zelanda)
sujetador
(NN)
sujetador
(GT)
sujetador
(GE)
sujetador
(GTU)
—
0100
AÑADIR
ADDC
0101
SUB
SUBB
0110
Y
XOR
0111
IOR
MOVIMIENTO
1000
MOVIMIENTO
1001
MOVIMIENTO
1010
BSET
BCLR
BTG
BTST
BTSTS
BTST
BTSS
BTSC
BSET
BCLR
BTG
BTST
BTSTS
BSW
BTSS
BTSC
1011
AÑADIR
ADDC
SUB
SUBB
Y
XOR
IOR
MOVIMIENTO
AÑADIR
ADDC
SUB
SUBB
Y
XOR
IOR
MOVIMIENTO
MUL.US
MUL.UU
MUL.SS
MUL.SU
TBLRDH
TBLRDL
TBLWTH
TBLWTL
MUL
SUB
SUBB
MOV.D
MOVIMIENTO
1100
MAC(1)
MPY(1)
MPY.N(1)
MSC(1)
CLRAC(1)
MAC(1)
MPY(1)
MPY.N(1)
MSC(1)
MOVSAC(1)
SFTAC(1)
AÑADIR(1)
ALC(1)
AÑADIR(1)
NEG(1)
SUB(1)
SACO(1)
SAC.R(1)
—
FF1L(1)
FF1R(1)
1101
SL
ASR
LSR
RLC
RLNC
RRC     
RRNC
SL
ASR
LSR
RLC   
RLNC
RRC 
RRNC
DIV.S
DIV.U
DIVF(2)
—
—
—
SL
ASR
LSR
FBCL
1110
CP0
CP
CPB
CP0
CP
CPB
—
—
CPSGT
CPSLT
CPSEQ
CPSNE
INC
INC2
DIC
DIC2
COM
NEG
CLR
SETM
INC
INC2
DIC
DIC2
COM
NEG
CLR
SETM
1111
DE(1)
EDAC(1)
MAC(1)
MPY(1)
—
—
—
—
EMPUJAR
POP
LNK
ULNK
SE
ZE
DISI
DAW
EXCH
INTERCAMBIAR
CLRWDT
PWRSAV
POP.S
EMPUJAR.S
REINICIAR
NOPR
Nota
1:
Esta instrucción solo está disponible para dispositivos de la familia DSPIC30F y DSPIC33F.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 360
© 2009 Microchip Technology Inc.
6.2
 TABLA RESUMEN DEL JUEGO DE INSTRUCCIONES
El conjunto completo de instrucciones del dispositivo MCU y DSC de 16 bits se resume en la Tabla 6-2. Esta tabla contiene una lista alfabética de los
conjunto de instrucciones. Incluye sintaxis del ensamblaje de instrucciones, descripción, tamaño (en palabras de 24 bits), tiempo de ejecución (en ciclos de instrucciones), afectación.
bits de estado y el número de página en la que se puede encontrar la descripción detallada. La Tabla 1-2 identifica los símbolos que se utilizan en el
Tabla resumen del conjunto de instrucciones.
 Tabla 6-2:
Tabla de resumen del conjunto de instrucciones
Sintaxis de ensamblaje
Mnemónicos, operandos
Descripción
Ciclos de palabras OA(2)
OB(2) SA(1,2) SB(1,2) OAB(2) SAB(1,2)
CC
norte
VO
z
c
Página 
Número
AÑADIR
f {,WREG} 
Destino = f + WREG
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-89
AÑADIR
#lit10,Wn
Wn = lit10 + Wn
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-90
AÑADIR
Wb,#lit5,Wd
Wd = Wb + lit5
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-91
AÑADIR
Wb,Ws,Wd
Wd = Wb + Ws
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-93
AÑADIR
Acc(2)
Añadir acumuladores
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-95
AÑADIR
Ws,#Slit4,Acc
Agregar al acumulador firmado de 16 bits
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-96
ADDC
f {,WREG}
Destino = f + WREG + (C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-98
ADDC
#lit10,Wn
Wn = lit10 + Wn + (C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-99
ADDC
Wb,#lit5,Wd
Wd = Wb + lit5 + (C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-100
ADDC
Wb,Ws,Wd
Wd = Wb + Ws + (C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-102
Y
f {,WREG}
Destino = f .Y. WREG
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-104
Y
#lit10,Wn
Wn = lit10 .Y. Wn
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-105
Y
Wb,#lit5,Wd
Wd = Wb .Y. lit5
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-106
Y
Wb,Ws,Wd
Wd = Wb .Y. Ws
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-107
ASR
f {,WREG}
Destino = desplazamiento aritmético a la derecha f
1
1
—
—
—
—
—
—
—
Ú
—
Ú
Ú
5-109
ASR
Ws,Wd
Wd = desplazamiento aritmético a la derecha Ws
1
1
—
—
—
—
—
—
—
Ú
—
Ú
Ú
5-111
ASR
Wb,#lit4,Wnd
Wnd = desplazamiento aritmético a la derecha Wb por lit4
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-113
ASR
Wb,Wns,Wnd
Wnd = desplazamiento aritmético a la derecha Wb por Wns
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-114
BCLR
f,#bit4
Poco claro f
1
1
—
—
—
—
—
—
—
—
—
—
—
5-115
BCLR
Ws,#bit4
Un poco claro Ws
1
1
—
—
—
—
—
—
—
—
—
—
—
5-116
sujetador
Expr.
Rama incondicionalmente 
1
2
—
—
—
—
—
—
—
—
—
—
—
5-117
sujetador
Wn
rama computada
1
2
—
—
—
—
—
—
—
—
—
—
—
5-118
sujetador
C,expr.
Rama si lleva
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-119
sujetador
GE,expr.
Rama si es mayor o igual
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-121
sujetador
GEU,expr.
Rama si lleva
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-122
sujetador
GT,Exp.
Rama si es mayor que
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-123
sujetador
GTU,expr.
Rama si no está firmada mayor que
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-124
Leyenda:
Ú establecido o borrado;   Ø puede borrarse, pero nunca fijarse;   × puede configurarse, pero nunca borrarse;   ‘1’ siempre configurado;   ‘0’ siempre despejado;    — sin cambios
Nota
1:
SA, SB y SAB sólo se modifican si la saturación correspondiente está habilitada, en caso contrario no se modifica.
2:
Esta instrucción/operando solo está disponible en dispositivos dsPIC30F y dsPIC33F.

© 2009 Microchip Technology Inc.
DS70157D-página 361
Sección 6. Referencia
Referencia
6
sujetador
LE, Expr.
Rama si es menor o igual
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-125
sujetador
LEU,expr.
Rama si no está firmada menor o igual
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-126
sujetador
LT,expr.
Sucursal si es menor que
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-127
sujetador
LTU,expr.
Rama si no Llevar
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-128
sujetador
N,expr.
Rama si es negativo
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-129
sujetador
NC, Expr.
Rama si no Llevar
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-130
sujetador
NN, Expr
Rama si no es Negativa
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-131
sujetador
NOV, exp.
Rama si no se desborda
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-132
sujetador
Nueva Zelanda, Expr.
Rama si no es cero
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-133
sujetador
OA, Expr(2)
Rama si el acumulador A se desborda
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-134
sujetador
OB,expr(2)
Rama si el acumulador B se desborda
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-135
sujetador
OV,expr.
Rama si se desborda
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-136
sujetador
SA, Expr(2)
Rama si el acumulador A está saturado
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-137
sujetador
SB, Expr(2)
Ramifica si el acumulador B está saturado
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-138
sujetador
Z, Expr
Rama si cero
1
1 (2)
—
—
—
—
—
—
—
—
—
—
—
5-139
BSET
f,#bit4
Juego de bits f
1
1
—
—
—
—
—
—
—
—
—
—
—
5-140
BSET
Ws,#bit4
Juego de puntas Ws
1
1
—
—
—
—
—
—
—
—
—
—
—
5-141
BSW.C
Ws,Wb
Escribe el bit C en Ws<Wb>
1
1
—
—
—
—
—
—
—
—
—
—
—
5-142
BSW.Z
Ws,Wb
Escribe el bit Z en Ws<Wb>
1
1
—
—
—
—
—
—
—
—
—
—
—
5-142
BTG
f,#bit4
Cambio de bits f
1
1
—
—
—
—
—
—
—
—
—
—
—
5-144
BTG
Ws,#bit4
Cambio de bits Ws
1
1
—
—
—
—
—
—
—
—
—
—
—
5-145
BTSC
f,#bit4
Prueba de bit f, omitir si está claro
1
1
(2 o 3)
—
—
—
—
—
—
—
—
—
—
—
5-146
BTSC
Ws,#bit4
Prueba de bits Ws, omítala si está clara
1
1
(2 o 3)
—
—
—
—
—
—
—
—
—
—
—
5-148
BTSS
f,#bit4
Prueba de bit f, omitir si está configurado
1
1
(2 o 3)
—
—
—
—
—
—
—
—
—
—
—
5-150
BTSS
Ws,#bit4
Prueba de bits Ws, omitir si está configurado
1
1
(2 o 3)
—
—
—
—
—
—
—
—
—
—
—
5-151
BTST
f,#bit4
prueba de bits f
1
1
—
—
—
—
—
—
—
—
—
Ú
—
5-153
BTST.C
Ws,#bit4
Prueba de bits Ws a C
1
1
—
—
—
—
—
—
—
—
—
—
Ú
5-154
BTST.Z
Ws,#bit4
Prueba de bits Ws a Z
1
1
—
—
—
—
—
—
—
—
—
Ú
—
5-154
BTST.C
Ws,Wb
Prueba de bits Ws<Wb> a C
1
1
—
—
—
—
—
—
—
—
—
—
Ú
5-155
BTST.Z
Ws,Wb
Prueba de bits Ws<Wb> a Z
1
1
—
—
—
—
—
—
—
—
—
Ú
—
5-155
BTSTS
f,#bit4
Prueba de bits y luego configura f
1
1
—
—
—
—
—
—
—
—
—
Ú
—
5-157
BTSTS.C
Ws,#bit4
Pruebe el bit Ws a C y luego configure
1
1
—
—
—
—
—
—
—
—
—
—
Ú
5-158
Tabla 6-2:
Tabla de resumen del conjunto de instrucciones (continuación)
Sintaxis de ensamblaje
Mnemónicos, operandos
Descripción
Ciclos de palabras OA(2)
OB(2) SA(1,2) SB(1,2) OAB(2) SAB(1,2)
CC
norte
VO
z
c
Página 
Número
Leyenda:
Ú establecido o borrado;   Ø puede borrarse, pero nunca fijarse;   × puede configurarse, pero nunca borrarse;   ‘1’ siempre configurado;   ‘0’ siempre despejado;    — sin cambios
Nota
1:
SA, SB y SAB sólo se modifican si la saturación correspondiente está habilitada, en caso contrario no se modifica.
2:
Esta instrucción/operando solo está disponible en dispositivos dsPIC30F y dsPIC33F.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 362
© 2009 Microchip Technology Inc.
BTSTS.Z
Ws,#bit4
Pruebe el bit Ws a Z y luego configure
1
1
—
—
—
—
—
—
—
—
—
Ú
—
5-158
LLAMADA
Expr.
Llamar a subrutina
2
2
—
—
—
—
—
—
—
—
—
—
—
5-159
LLAMADA
Wn
Llamar a subrutina indirecta
1
2
—
—
—
—
—
—
—
—
—
—
—
5-161
CLR
f
f = 0x0000
1
1
—
—
—
—
—
—
—
—
—
—
—
5-163
CLR
WREG
WREG = 0x0000
1
1
—
—
—
—
—
—
—
—
—
—
—
5-163
CLR
Wd
Wd = 0
1
1
—
—
—
—
—
—
—
—
—
—
—
5-164
CLR
Acc,Wx,Wxd,Wy,Wyd,AWB(2)
Limpiar acumulador
1
1
0
0
0
0
0
0
—
—
—
—
—
5-165
CLRWDT
Borrar temporizador de vigilancia
1
1
—
—
—
—
—
—
—
—
—
—
—
5-167
COM
f {,WREG}
Destino = f
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-168
COM
Ws,Wd
Wd = Ws
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-169
CP
f
Comparar (f – WREG)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-170
CP
Wb,#encendido5
Comparar (Wb – lit5)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-171
CP
Wb,Ws
Comparar (Wb – Ws)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-172
CP0
f
Comparar (f – 0x0000)
1
1
—
—
—
—
—
—
1
Ú
Ú
Ú
1
5-173
CP0
Ws
Comparar (Ws – 0x0000)
1
1
—
—
—
—
—
—
1
Ú
Ú
Ú
1
5-174
CPB
f
Comparar con pedir prestado (f – WREG – C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-175
CPB
Wb,#encendido5
Comparar con pedir prestado (Wb – lit5 – C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-176
CPB
Wb,Ws
Comparar con préstamo (Wb – Ws – C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-177
CPSEQ
Wb, Wn
Comparar (Wb con Wn), omitir si =
1
1
(2 o 3)
—
—
—
—
—
—
—
—
—
—
—
5-179
CPSGT
Wb, Wn
Comparar con signo (Wb con Wn), omitir si >
1
1
(2 o 3)
—
—
—
—
—
—
—
—
—
—
—
5-180
CPSLT
Wb, Wn
Comparar con signo (Wb con Wn), omitir si <
1
1
(2 o 3)
—
—
—
—
—
—
—
—
—
—
—
5-181
CPSNE
Wb, Wn
Comparar con signo (Wb con Wn), omitir si ≠
1
1
(2 o 3)
—
—
—
—
—
—
—
—
—
—
—
5-182
DAW.B
Wn
Wn = ajuste decimal Wn
1
1
—
—
—
—
—
—
—
—
—
—
Ú
5-183
DIC
f {,WREG} 
Destino = f – 1
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-184
DIC
Ws,Wd
Wd = Ws – 1
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-185
DIC2
f {,WREG}
Destino = f – 2
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-186
DIC2
Ws,Wd
Wd = Ws – 2
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-187
DISI
#lit14
Deshabilitar interrupciones para ciclos de instrucción lit14
1
1
—
—
—
—
—
—
—
—
—
—
—
5-188
DIV.S
Wm, Wn
División entera de 16/16 bits con signo
1
18
—
—
—
—
—
—
—
Ú
Ú
Ú
Ú
5-189
DIV.SD
Wm, Wn
División entera de 32/16 bits con signo
1
18
—
—
—
—
—
—
—
Ú
Ú
Ú
Ú
5-189
Tabla 6-2:
Tabla de resumen del conjunto de instrucciones (continuación)
Sintaxis de ensamblaje
Mnemónicos, operandos
Descripción
Ciclos de palabras OA(2)
OB(2) SA(1,2) SB(1,2) OAB(2) SAB(1,2)
CC
norte
VO
z
c
Página 
Número
Leyenda:
Ú establecido o borrado;   Ø puede borrarse, pero nunca fijarse;   × puede configurarse, pero nunca borrarse;   ‘1’ siempre configurado;   ‘0’ siempre despejado;    — sin cambios
Nota
1:
SA, SB y SAB sólo se modifican si la saturación correspondiente está habilitada, en caso contrario no se modifica.
2:
Esta instrucción/operando solo está disponible en dispositivos dsPIC30F y dsPIC33F.

© 2009 Microchip Technology Inc.
DS70157D-página 363
Sección 6. Referencia
Referencia
6
DIV.U
Wm, Wn
División entera de 16/16 bits sin signo
1
18
—
—
—
—
—
—
—
0
0
Ú
Ú
5-191
DIV.UD
Wm, Wn
División entera de 32/16 bits sin signo
1
18
—
—
—
—
—
—
—
0
Ú
Ú
Ú
5-191
DIVF
Wm, Wn(2)
División fraccionaria firmada de 16/16 bits
1
18
—
—
—
—
—
—
—
Ú
Ú
Ú
Ú
5-193
HACER
#lit14, Expr(2)
Hacer código a PC + Expr, (lit14 + 1) veces
2
2
—
—
—
—
—
—
—
—
—
—
—
5-195
HACER
Wn, Expr(2)
Hacer código a PC + Expr, (Wn + 1) veces
2
2
—
—
—
—
—
—
—
—
—
—
—
5-197
DE
Wm*Wm,Acc,Wx,Wy,Wxd(2)
Distancia euclidiana (sin acumulación)
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-199
EDAC
Wm*Wm,Acc,Wx,Wy,Wxd(2)
distancia euclidiana
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-201
EXCH
Wns,Wnd
Intercambiar Wns y Wnd
1
1
—
—
—
—
—
—
—
—
—
—
—
5-203
FBCL
Ws, viento
Encuentre el cambio de bits desde el lado izquierdo (MSb) 
1
1
—
—
—
—
—
—
—
—
—
—
Ú
5-204
FF1L
Ws, viento
Encuentra el primero desde el lado izquierdo (MSb) 
1
1
—
—
—
—
—
—
—
—
—
—
Ú
5-206
FF1R
Ws, viento
Encuentra el primero desde el lado derecho (LSb) 
1
1
—
—
—
—
—
—
—
—
—
—
Ú
5-208
IR A
Expr.
Ir a la dirección
2
2
—
—
—
—
—
—
—
—
—
—
—
5-210
IR A
Wn
Ir a la dirección indirecta
1
2
—
—
—
—
—
—
—
—
—
—
—
5-211
INC
f {,WREG} 
Destino = f + 1
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-212
INC
Ws,Wd
Wd = Ws + 1
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-213
INC2
f {,WREG}
Destino = f + 2
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-214
INC2
Ws,Wd
Wd = Ws + 2
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-215
IOR
f {,WREG} 
Destino = f .IOR. WREG
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-216
IOR
#lit10,Wn
Wn = lit10 .IOR. Wn
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-217
IOR
Wb,#lit5,Wd
Wd = Wb .IOR. lit5
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-218
IOR
Wb,Ws,Wd
Wd = Wb .IOR. Ws
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-219
ALC
Ws,#Rendija4, Acc(2)
acumulador de carga
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-221
LNK
#lit14
Puntero de marco de enlace
1
1
—
—
—
—
—
—
—
—
—
—
—
5-223
LSR
f {,WREG}
Destino = desplazamiento lógico a la derecha f
1
1
—
—
—
—
—
—
—
0
—
Ú
Ú
5-224
LSR
Ws,Wd
Wd = desplazamiento lógico a la derecha Ws
1
1
—
—
—
—
—
—
—
0
—
Ú
Ú
5-225
LSR
Wb,#lit4,Wnd
Wnd = desplazamiento lógico a la derecha Wb por lit4
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-227
LSR
Wb,Wns,Wnd
Wnd = desplazamiento lógico a la derecha Wb por Wns
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-228
MAC
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd,AWB(2)
Multiplica y acumula
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-229
MAC
Wm*Wm,Acc,Wx,Wxd,Wy,Wyd(2)
Cuadrar y acumular
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-231
MOVIMIENTO
f {,WREG} 
Mover f al destino
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-233
MOVIMIENTO
WREG,f
Mover WREG a f
1
1
—
—
—
—
—
—
—
—
—
—
—
5-234
MOVIMIENTO
f, viento
Mover f a Wnd
1
1
—
—
—
—
—
—
—
—
—
—
—
5-235
Tabla 6-2:
Tabla de resumen del conjunto de instrucciones (continuación)
Sintaxis de ensamblaje
Mnemónicos, operandos
Descripción
Ciclos de palabras OA(2)
OB(2) SA(1,2) SB(1,2) OAB(2) SAB(1,2)
CC
norte
VO
z
c
Página 
Número
Leyenda:
Ú establecido o borrado;   Ø puede borrarse, pero nunca fijarse;   × puede configurarse, pero nunca borrarse;   ‘1’ siempre configurado;   ‘0’ siempre despejado;    — sin cambios
Nota
1:
SA, SB y SAB sólo se modifican si la saturación correspondiente está habilitada, en caso contrario no se modifica.
2:
Esta instrucción/operando solo está disponible en dispositivos dsPIC30F y dsPIC33F.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 364
© 2009 Microchip Technology Inc.
MOVIMIENTO
Wns,f
Mover Wns a f
1
1
—
—
—
—
—
—
—
—
—
—
—
5-236
MOV.B
#lit8,viento
Mover literal sin firmar de 8 bits a Wnd
1
1
—
—
—
—
—
—
—
—
—
—
—
5-237
MOVIMIENTO
#lit16,viento
Mover literal de 16 bits a Wnd
1
1
—
—
—
—
—
—
—
—
—
—
—
5-238
MOVIMIENTO
[Ws+Rendija10],Wnd
Mueva [Ws + Slit10] a Wnd
1
1
—
—
—
—
—
—
—
—
—
—
—
5-239
MOVIMIENTO
Wns,[Wd+Rendija10]
Mover Wns a [Wd + Slit10]
1
1
—
—
—
—
—
—
—
—
—
—
—
5-240
MOVIMIENTO
Ws,Wd
Mover Ws a Wd
1
1
—
—
—
—
—
—
—
—
—
—
—
5-241
MOV.D
Wns,Wnd
Mover doble Wns a Wnd:Wnd + 1
1
2
—
—
—
—
—
—
—
—
—
—
—
5-243
MOV.D
Wns,Wnd
Mover doble Wns:Wns + 1 a Wnd
1
2
—
—
—
—
—
—
—
—
—
—
—
5-243
MOVSAC
Acc,Wx,Wxd,Wy,Wyd,AWB(2)
Mueva [Wx] a Wxd y [Wy] a Wyd
1
1
—
—
—
—
—
—
—
—
—
—
—
5-245
MPY
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd(2)
Multiplica Wn por Wm al acumulador
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-247
MPY
Wm*Wm,Acc,Wx,Wxd,Wy,Wyd(2)
Cuadrado al acumulador
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-249
MPY.N
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd(2)
-(Multiplicar Wn por Wm) al acumulador
1
1
0
0
—
—
0
—
—
—
—
—
—
5-251
MSC
Wm*Wn,Acc,Wx,Wxd,Wy,Wyd,AWB(2)
Multiplicar y restar del acumulador.
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-253
MUL
f
W3:W2 = f * WREG
1
1
—
—
—
—
—
—
—
—
—
—
—
5-255
MUL.SS
Wb,Ws,Wnd
{Wnd + 1,Wnd} = firmado(Wb) * firmado(Ws)
1
1
—
—
—
—
—
—
—
—
—
—
—
5-256
MUL.SU
Wb,#lit5,Wnd
{Wnd + 1,Wnd} = firmado(Wb) * sin firmar(lit5)
1
1
—
—
—
—
—
—
—
—
—
—
—
5-258
MUL.SU
Wb,Ws,Wnd
{Wnd + 1,Wnd} = con signo (Wb) * sin signo (Ws)
1
1
—
—
—
—
—
—
—
—
—
—
—
5-260
MUL.US
Wb,Ws,Wnd
{Wnd + 1,Wnd} = sin firmar (Wb) * firmado (Ws)
1
1
—
—
—
—
—
—
—
—
—
—
—
5-262
MUL.UU
Wb,#lit5,Wnd
{Wnd + 1,Wnd} = sin firmar (Wb) * sin firmar (lit5)
1
1
—
—
—
—
—
—
—
—
—
—
—
5-264
MUL.UU
Wb,Ws,Wnd
{Wnd + 1,Wnd} = sin firmar (Wb) * sin firmar (Ws)
1
1
—
—
—
—
—
—
—
—
—
—
—
5-265
NEG
f {,WREG}
Destino = f + 1
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-267
NEG
Ws,Wd
Wd = Ws + 1
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-268
NEG
Acc(2)
Negar acumulador
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-269
NOP
Sin operación
1
1
—
—
—
—
—
—
—
—
—
—
—
5-270
NOPR
Sin operación
1
1
—
—
—
—
—
—
—
—
—
—
—
5-271
POP
f
POP TOS a f
1
1
—
—
—
—
—
—
—
—
—
—
—
5-272
POP
Wd
POP TOS a Wd
1
1
—
—
—
—
—
—
—
—
—
—
—
5-273
POP.D
viento
POP doble de TOS a Wnd:Wnd + 1
1
2
—
—
—
—
—
—
—
—
—
—
—
5-274
POP.S
Registros ocultos POP
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-275
EMPUJAR
f
EMPUJE f a TOS
1
1
—
—
—
—
—
—
—
—
—
—
—
5-276
EMPUJAR
Ws
EMPUJE W a TOS
1
1
—
—
—
—
—
—
—
—
—
—
—
5-277
EMPUJAR.D
Wns
PUSH doble Wns:Wns + 1 a TOS
1
2
—
—
—
—
—
—
—
—
—
—
—
5-278
EMPUJAR.S
PUSH registros de sombra
1
1
—
—
—
—
—
—
—
—
—
—
—
5-279
PWRSAV
#lit1
Ingrese al modo de ahorro de energía
1
1
—
—
—
—
—
—
—
—
—
—
—
5-280
LLAMADA
Expr.
llamada relativa
1
2
—
—
—
—
—
—
—
—
—
—
—
5-281
Tabla 6-2:
Tabla de resumen del conjunto de instrucciones (continuación)
Sintaxis de ensamblaje
Mnemónicos, operandos
Descripción
Ciclos de palabras OA(2)
OB(2) SA(1,2) SB(1,2) OAB(2) SAB(1,2)
CC
norte
VO
z
c
Página 
Número
Leyenda:
Ú establecido o borrado;   Ø puede borrarse, pero nunca fijarse;   × puede configurarse, pero nunca borrarse;   ‘1’ siempre configurado;   ‘0’ siempre despejado;    — sin cambios
Nota
1:
SA, SB y SAB sólo se modifican si la saturación correspondiente está habilitada, en caso contrario no se modifica.
2:
Esta instrucción/operando solo está disponible en dispositivos dsPIC30F y dsPIC33F.

© 2009 Microchip Technology Inc.
DS70157D-página 365
Sección 6. Referencia
Referencia
6
LLAMADA
Wn
llamada calculada
1
2
—
—
—
—
—
—
—
—
—
—
—
5-283
REPETIR
#lit14
Repita la siguiente instrucción (lit14 + 1) veces
1
1
—
—
—
—
—
—
—
—
—
—
—
5-285
REPETIR
Wn
Repita la siguiente instrucción (Wn + 1) veces
1
1
—
—
—
—
—
—
—
—
—
—
—
5-286
REINICIAR
Restablecer dispositivo de software
1
1
—
—
—
—
—
—
—
—
—
—
—
5-288
REFIE
Retorno de habilitación de interrupción
1
3 (2)
—
—
—
—
—
—
—
Ú
Ú
Ú
Ú
5-290
RETLW
#lit10,Wn
Regresar con lit10 en Wn
1
3 (2)
—
—
—
—
—
—
—
—
—
—
—
5-291
VOLVER
Regreso de subrutina
1
3 (2)
—
—
—
—
—
—
—
—
—
—
—
5-292
RLC
f {,WREG}
Destino = girar a la izquierda hasta Llevar f
1
1
—
—
—
—
—
—
—
Ú
—
Ú
Ú
5-293
RLC
Ws,Wd
Wd = rotar a la izquierda a través de Carry Ws
1
1
—
—
—
—
—
—
—
Ú
—
Ú
Ú
5-294
RLNC
f {,WREG}
Destino = rotar a la izquierda (sin transporte) f
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-296
RLNC
Ws,Wd
Wd = girar a la izquierda (sin transporte) Ws
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-297
RRC
f {,WREG}
Destino = girar a la derecha a través de Llevar f
1
1
—
—
—
—
—
—
—
Ú
—
Ú
Ú
5-299
RRC
Ws,Wd
Wd = rotar hacia la derecha a través de Carry Ws
1
1
—
—
—
—
—
—
—
Ú
—
Ú
Ú
5-300
RRNC
f {,WREG}
Destino = rotar a la derecha (sin transporte) f
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-302
RRNC
Ws,Wd
Wd = girar a la derecha (sin transporte) Ws
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-303
SACO
Acc,#Rendija4,Wd(2)
Acumulador de tienda
1
1
—
—
—
—
—
—
—
—
—
—
—
5-305
SAC.R
Acc,#Rendija4,Wd(2)
Almacenar acumulador redondeado
1
1
—
—
—
—
—
—
—
—
—
—
—
5-307
SE
Ws,Wd
Wd = Ws con signo extendido
1
1
—
—
—
—
—
—
—
Ú
—
Ú
Ú
5-309
SETM
f
f = 0xFFFF
1
1
—
—
—
—
—
—
—
—
—
—
—
5-310
SETM
WREG
WREG = 0xFFFF
1
1
—
—
—
—
—
—
—
—
—
—
—
5-310
SETM
Ws
Ws = 0xFFFF
1
1
—
—
—
—
—
—
—
—
—
—
—
5-311
SFTAC
Acc,#Rendija6(2)
Acumulador de desplazamiento aritmético de Slit6 
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-312
SFTAC
Acc,Wb(2)
Acumulador de desplazamiento aritmético por (Wb) 
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-313
SL
f {,WREG} 
Destino = desplazamiento aritmético a la izquierda f
1
1
—
—
—
—
—
—
—
Ú
—
Ú
Ú
5-314
SL
Ws,Wd
Wd = desplazamiento aritmético a la izquierda Ws
1
1
—
—
—
—
—
—
—
Ú
—
Ú
Ú
5-315
SL
Wb,#lit4,Wnd
Wnd = desplazamiento a la izquierda Wb por lit4
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-317
SL
Wb,Wns,Wnd
Wnd = desplazamiento a la izquierda Wb por Wns
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-318
SUB
f {,WREG} 
Destino = f – WREG
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-319
SUB
#lit10,Wn
Wn = Wn – lit10
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-320
SUB
Wb,#lit5,Wd
Wd = Wb – lit5
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-321
SUB
Wb,Ws,Wd
Wd = Wb – Ws
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-322
SUB
Acc(2)
Restar acumuladores
1
1
Ú
Ú
×
×
Ú
×
—
—
—
—
—
5-324
Tabla 6-2:
Tabla de resumen del conjunto de instrucciones (continuación)
Sintaxis de ensamblaje
Mnemónicos, operandos
Descripción
Ciclos de palabras OA(2)
OB(2) SA(1,2) SB(1,2) OAB(2) SAB(1,2)
CC
norte
VO
z
c
Página 
Número
Leyenda:
Ú establecido o borrado;   Ø puede borrarse, pero nunca fijarse;   × puede configurarse, pero nunca borrarse;   ‘1’ siempre configurado;   ‘0’ siempre despejado;    — sin cambios
Nota
1:
SA, SB y SAB sólo se modifican si la saturación correspondiente está habilitada, en caso contrario no se modifica.
2:
Esta instrucción/operando solo está disponible en dispositivos dsPIC30F y dsPIC33F.

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 366
© 2009 Microchip Technology Inc.
SUBB
f {,WREG}
Destino = f – WREG – (C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-325
SUBB
#lit10,Wn
Wn = Wn – lit10 – (C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-326
SUBB
Wb,#lit5,Wd
Wd = Wb – lit5 – (C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-327
SUBB
Wb,Ws,Wd
Wd = Wb – Ws – (C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-329
SUBBR
f {,WREG} 
Destino = WREG – f – (C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-331
SUBBR
Wb,#lit5,Wd
Wd = lit5 – Wb – (C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-332
SUBBR
Wb,Ws,Wd
Wd = Ws – Wb – (C)
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ø
Ú
5-334
SUBR
f {,WREG} 
Destino = WREG – f
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-336
SUBR
Wb,#lit5,Wd
Wd = lit5 – Wb
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-337
SUBR
Wb,Ws,Wd
Wd = Ws – Wb
1
1
—
—
—
—
—
—
Ú
Ú
Ú
Ú
Ú
5-338
INTERCAMBIAR
Wn
Wn = byte o intercambio de nibble Wn
1
1
—
—
—
—
—
—
—
—
—
—
—
5-340
TBLRDH
Ws,Wd
Leer palabra de programa alta en Wd
1
2
—
—
—
—
—
—
—
—
—
—
—
5-341
TBLRDL
Ws,Wd
Leer palabra de programa baja en Wd
1
2
—
—
—
—
—
—
—
—
—
—
—
5-343
TBLWTH
Ws,Wd
Escriba Ws en la palabra de programa alta
1
2
—
—
—
—
—
—
—
—
—
—
—
5-345
TBLWTL
Ws,Wd
Escribe Ws en una palabra de programa baja
1
2
—
—
—
—
—
—
—
—
—
—
—
5-347
ULNK
Puntero de marco de desvinculación
1
1
—
—
—
—
—
—
—
—
—
—
—
5-349
XOR
f {,WREG} 
Destino = f .XOR. WREG
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-350
XOR
#lit10,Wn
Wn = lit10 .XOR. Wn
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-351
XOR
Wb,#lit5,Wd
Wd = Wb .XOR. lit5
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-352
XOR
Wb,Ws,Wd
Wd = Wb .XOR. Ws
1
1
—
—
—
—
—
—
—
Ú
—
Ú
—
5-353
ZE
Ws, viento
Wnd = Ws extendido a cero
1
1
—
—
—
—
—
—
—
0
—
Ú
1
5-355
Tabla 6-2:
Tabla de resumen del conjunto de instrucciones (continuación)
Sintaxis de ensamblaje
Mnemónicos, operandos
Descripción
Ciclos de palabras OA(2)
OB(2) SA(1,2) SB(1,2) OAB(2) SAB(1,2)
CC
norte
VO
z
c
Página 
Número
Leyenda:
Ú establecido o borrado;   Ø puede borrarse, pero nunca fijarse;   × puede configurarse, pero nunca borrarse;   ‘1’ siempre configurado;   ‘0’ siempre despejado;    — sin cambios
Nota
1:
SA, SB y SAB sólo se modifican si la saturación correspondiente está habilitada, en caso contrario no se modifica.
2:
Esta instrucción/operando solo está disponible en dispositivos dsPIC30F y dsPIC33F.

© 2009 Microchip Technology Inc.
DS70157D-página 367
Sección 6. Referencia
Referencia
6
6.3
 HISTORIAL DE REVISIONES
Revisión A 
Esta es la versión publicada inicial de este documento.
Revisión B 
Esta revisión incorpora todas las erratas conocidas al momento de la actualización de este documento.
Revisión C (febrero de 2008)
Esta revisión incluye las siguientes correcciones y actualizaciones:
• Actualizaciones de instrucciones:
- Instrucción BRA actualizada (ver “BRA”)
- Instrucción DIVF actualizada (ver “DIVF”)
- Instrucción DO actualizada (ver “DO”)
- Instrucción SUB actualizada (ver “SUB”)
Revisión D (noviembre de 2009)
Esta revisión incluye las siguientes correcciones y actualizaciones:
• Documento renombrado del Manual de referencia del programador dsPIC30F/33F a MCU de 16 bits 
y Manual de referencia del programador DSC
• El documento ha sido completamente rediseñado para adaptarse a todas las familias actuales de 16 bits: 
dsPIC30F, dsPIC33F, PIC24F y PIC24H

Manual de referencia del programador MCU y DSC de 16 bits
DS70157D-página 368
© 2009 Microchip Technology Inc.
NOTAS:

¤ 2009 Microchip Technology Inc. 
DS70157D-página 369 
Índice 
Índice 
ÍNDICE 
A 
Acumulador A, Acumulador B ................................................ 18 
Acceso al acumulador ................................................................ 73 
Uso del acumulador................................................................ 72 
Modos de direccionamiento para el registro de destino Wd ................. 85 
Modos de direccionamiento para el registro de origen Ws ......... 85 
Uso del registro de trabajo asignado................................ 67 
B 
Operaciones de bytes ................................................................ 54 
do 
Ejemplos de código 
Operación del bit de estado ’Z’ para suma de 32 bits ................ 66 
Sintaxis MAC básica................................................ 75 
Direccionamiento del registro de archivos................................ 43 
Direccionamiento de registros de archivos y WREG.................... 43 
Uso del puntero de marco................................................ 63 
Operaciones ilegales de movimiento de palabras................................ 58 
Direccionamiento Inmediato ................................................ 49 
Direccionamiento indirecto con actualización de dirección efectiva... 45 
Direccionamiento indirecto con compensación de registro................. 46 
Operaciones de movimiento de palabras legales ................................ 57 
Sintaxis del WB del acumulador MAC ................................. 77 
Sintaxis de captación previa de MAC................................ 76 
Mover con instrucciones de compensación literal.................... 46 
Instrucción MSC con dos captaciones previas y acumulador 
Responder................................................................ 77 
Normalización con FBCL ................................................ 81 
Registrar direccionamiento directo ........................................ 44 
Ejemplos de operaciones matemáticas de bytes................................ 55 
Operaciones de movimiento de bytes de muestra ................................ 54 
Escalar con FBCL................................................................ 80 
Uso del puntero de pila ................................................ 61 
F sin firmar y WREG Multiplicar (Instrucciones heredadas de MULWF) 
ción)................................................................. 69 
Uso de literales de 10 bits para operandos de bytes... 59 
Uso del registro de trabajo predeterminado WREG................ 68 
Instrucciones de sucursal condicional ................................ 65 
Registro de control central ................................................ 21 
D 
Árbol de modos de direccionamiento de datos ................................ 49 
Modos de direccionamiento de datos................................................ 42 
Registro DCOUNT ................................................................ 19 
Registro de trabajo predeterminado (WREG) ................................. 17, 68 
Apoyo al desarrollo ................................................................ 6 
DOEND Registro................................................................ 19 
Registro DOSTART ................................................................ 19 
Instrucciones del acumulador DSP ................................ 78 
Formatos de datos DSP................................................ 70 
Modos de direccionamiento indirecto DSP MAC ................................ 47 
Instrucciones DSP MAC ................................................ 74 
Descripción general de dsPIC30F/33F................................................. 12 
F 
Direccionamiento del registro de archivos................................................ 42
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               I 
Direccionamiento Inmediato ........................................................ 48 
Operandos en el conjunto de instrucciones ................................ 48 
Operandos DSP implícitos ................................................ 67 
Marco implícito y puntero de pila ................................. 67 
Mapa de bits de instrucción................................................ 358 
Ejemplo de descripción de instrucción ........................................ 88 
Descripciones de instrucciones ................................................ 89 
ADD (Agregación con signo de 16 bits al acumulador).... 96 
AGREGAR (Agregar acumuladores) ................................. 95 
AGREGAR (Agregar f a WREG)................................................. 89 
AGREGAR (Agregar literal a Wn)................................................. 90 
ADD (Agregar Wb al literal corto) ................................... 91 
AGREGAR (Agregar Wb a Ws)................................................. 93 
ADDC (Agregar f a WREG con acarreo) ........................ 98 
ADDC (Agregar literal a Wn con acarreo) ......... 99 
ADDC (Agregar Wb al literal corto con acarreo)................. 100 
ADDC (Agregar Wb a Ws con acarreo).................... 102 
Y (Y f y WREG)................................................. 104 
Y (Y Literal y Wd)................................................. 105 
AND (AND Wb y Literal Corto) ................................. 106 
Y (Y Wb y Ws) ................................................ 107 
ASR (desplazamiento aritmético a la derecha mediante literal corto).... 113 
ASR (desplazamiento aritmético a la derecha por Wns) ........................ 114 
ASR (desplazamiento aritmético a la derecha f) ................................. 109 
ASR (Desplazamiento aritmético a la derecha Ws)................................. 111 
BCLR (Borrar bits en Ws)................................................. 116 
BCLR.B (Borrar bits f) ................................................ 115 
BRA (Rama Incondicional)................................. 117 
BRA (Rama Computada)................................ 118 
BRA C (bifurcación si se lleva) ................................. 119 
BRA GE (Rama si se firma mayor que o igual). 121 
BRA GEU (Rama si no está firmado mayor o igual). 
122 
BRA GT (Rama si se firma mayor que)................. 123 
BRA GTU (Rama si no está firmado mayor que) ......... 124 
BRA LE (Rama si se firma menor que o igual)....... 125 
BRA LEU (Rama si no está firmado menor o igual) 126 
BRA LT (Rama si se firmó menos de) ................. 127 
BRA LTU (bifurcación si no se lleva) ................................. 130 
BRA LTU (Sucursal si no está firmado menos de)................. 128 
BRA N (Rama si es negativo)................................. 129 
BRA NN (Rama si no es negativo).................... 131 
BRA NOV (Rama si no se desborda).................... 132 
BRA NZ (Sucursal si no es cero)................................. 133 
BRA OA (Bifurcación si se desborda el acumulador A)....... 134 
BRA OB (bifurcación si se desborda el acumulador B)....... 135 
BRA OV (bifurcación si se desborda) ................................... 136 
BRA SA (Rama si Acumulador de Saturación A).......... 137 
BRA SB (Rama si es Acumulador de Saturación B)....... 138 
BRA Z (Rama si es cero)................................................. 139 
BSET (Configuración de bits f) ......................................... 140 
BSET (Bit establecido en Ws) ................................................ 141 
BSW (escritura de bits en Ws) ................................. 142 
BTG (alternancia de bits f)................................................. 144 
BTG (alternancia de bits en Ws)................................. 145 
BTSC (Prueba de bits f, omitir si está claro).................... 146 
BTSC (Prueba de bits Ws, omitir si está claro).................... 148 
BTSS (Prueba de bits f, omitir si está configurado) ................................. 150 
BTSS (Prueba de bits Ws, omitir si está configurado) ........................ 151 
BTST (Prueba de bits f)................................................. 153 
BTST (Prueba de bits en Ws)................................. 154, 155 
BTSTS (Prueba de bits/Establecer f)................................. 157 
BTSTS (Prueba de bits/Configuración en Ws)................................. 158 
CALL (Llamar a subrutina indirecta)................................. 161 
CALL (Llamar a subrutina)................................................. 159 
CLR (Borrar acumulador, captación previa de operandos) ......... 165 
CLR (Borrar para WREG)................................................. 163 
CLR (Borrar Wd)................................................. 164 



## Página 370

DS70157D-página 370 
¤ 2009 Microchip Technology Inc. 
Manual de referencia del programador MCU y DSC de 16 bits 
CLRWDT (Borrar temporizador de vigilancia) ................. 167 
COM (Complemento f)................................................. 168 
COM (Complemento Ws)................................................. 169 
CP (Comparar f con WREG, establecer indicadores de estado)... 170 
CP (Comparar Wb con lit5, Establecer indicadores de estado) ......... 171 
CP (Comparar Wb con Ws, establecer indicadores de estado) ........ 172 
CP0 (Comparar f con 0x0, establecer indicadores de estado) ......... 173 
CP0 (Comparar Ws con 0x0, establecer indicadores de estado) ........ 174 
CPB (Compare f con WREG usando Préstamo, Establecer estado 
Banderas)................................................................ 175 
CPB (Comparar Wb con lit5 usando Préstamo, Establecer estado 
Banderas)................................................................ 176 
CPB (Comparar Ws con Wb usando Préstamo, Establecer estado 
Banderas)................................................................ 177 
CPSEQ (Comparar Wb con Wn, omitir si es igual) ......... 179 
CPSGT (Comparación firmada Wb con Wn, omitir si es mayor 
Que)................................................................. 180 
CPSLT (Comparación firmada Wb con Wn, omitir si es menos 
Que)................................................................. 181 
CPSNE (Comparación firmada Wb con Wn, omitir si no 
Igual)................................................................ 182 
DAW.B (Ajuste decimal Wn) ................................... 183 
DEC (Disminución f) ................................................ 184 
DEC (Decremento Ws) ......................................... 185 
DEC2 (Disminución f en 2).................................... 186 
DEC2 (Disminuir Ws en 2) ................................ 187 
DISI (Desactivar interrupciones temporalmente) ................. 188 
DIV.S (División entera con signo)................................. 189 
DIV.U (División de enteros sin signo)................................. 191 
DIVF (División fraccionaria)................................................. 193 
DO (Inicializar literal de bucle de hardware).................... 195 
DO (Inicializar bucle de hardware Wn) ........................ 197 
ED (Distancia euclidiana, sin acumulación) ................ 199 
EDAC (Distancia euclidiana)................................ 201 
EXCH (Intercambio Wns y Wnd) ................................ 203 
FBCL (Buscar el primer cambio de bit desde la izquierda) ................204 
FF1L (Buscar el primero desde la izquierda) ................................ 206 
FF1R (Encontrar el primero desde la derecha) ........................ 208 
GOTO (Salto indirecto incondicional).................... 211 
GOTO (Salto incondicional) ................................ 210 
INC (Incremento f) ................................................ 212 
INC (Incremento Ws) ................................................ 213 
INC2 (Incremento f en 2)................................................. 214 
INC2 (Incrementar Ws en 2) ........................................ 215 
IOR (OR inclusivo y WREG)................................. 216 
IOR (Inclusivo OR Literal y Wn)................................. 217 
IOR (OR Inclusivo Wb y Literal Corto) ................. 218 
IOR (Inclusivo OR Wb y Ws) ................................ 219 
LAC (acumulador de carga).................................... 221 
LNK (Asignar marco de pila) ................................... 223 
LSR (desplazamiento lógico a la derecha mediante literal corto) ................. 227 
LSR (desplazamiento lógico a la derecha por Wns)................................. 228 
LSR (Desplazamiento lógico a la derecha f).................................224 
LSR (desplazamiento lógico a la derecha) ........................ 225 
MAC (multiplicar y acumular)................................. 229 
MAC (Cuadrado y Acumulado) ................................ 231 
MOV (Mover literal de 16 bits a Wn) ........................ 238 
MOV (Mover f al destino)................................. 233 
MOV (Mover f a Wnd) ................................................. 235 
MOV (Mover Wns a [Wd con desplazamiento]).................... 240 
MOV (Mover Wns a f) ................................................ 236 
MOV (Mover WREG a f) ................................. 234 
MOV (Mover Ws a Wd) ........................................ 241 
MOV (Mover Ws con desplazamiento a Wnd).................... 239 
MOV.B (Mover literal de 8 bits a Wnd) ................. 237 
MOV.D (Mover dos palabras desde el origen al viento)... 243 
MOVSAC (Prefetch Operands y Store Accumulator). 
245 
MPY (Multiplicar Wm por Wn al acumulador)................. 247 
MPY (Cuadrado a acumulador)................................. 249 
MPY.N (Multiplicar -Wm por Wn al acumulador).......... 251 
MSC (Multiplicar y Restar del Acumulador)....... 253 
MUL (Entero sin signo multiplicado f y WREG)... 255 
MUL.SS (multiplicación con signo de entero de 16 x 16 bits).... 256 
MUL.SU (Multiplicación entera de 16x16 bits con signo-sin signo). 
260 
MUL.SU (Entero de 16x16 bits con signo-sin signo de litro corto) 
al multiplicar) ........................................................ 258 
MUL.US (multiplicación entera de 16x16 bits sin signo y con signo). 
262 
MUL.UU (Entero 16x16 bits Multiplicación sin signo) ........ 265 
MUL.UU (Entero 16x16 bits Literal corto sin signo Multi- 
capa)................................................................. 264 
NEG (Negar acumulador)................................. 269 
NEG (Negar f)................................................. 267 
NEG (Negar Ws)................................................. 268 
NOP (Sin operación) ................................................ 270 
NOPR (sin operación)................................................. 271 
POP (Pop TOS a f)................................................. 272 
POP (Pop TOS a Wd)................................................. 273 
POP.D (Doble Pop TOS para enrollar/ 
Viento+1)................................................................. 274 
POP.S (Registros de sombra pop)................................. 275 
PUSH (Pulse f a TOS)................................................. 276 
PUSH (Empujar Ws a TOS)................................................. 277 
PUSH.D (Doble Empuje Wns/ 
Wns+1 a TOS)................................................. 278 
PUSH.S (Empujar registros ocultos).................... 279 
PWRSAV (Ingrese al modo de ahorro de energía)................. 280 
RCALL (llamada relativa calculada).................... 283 
RCALL (llamada relativa)................................................. 281 
REPETIR (Repetir la siguiente instrucción ’lit14’ veces) ...... 285 
REPETIR (Repetir la siguiente instrucción Wn veces) ......... 286 
REINICIAR (Reiniciar)................................................. 288 
RETFIE (Regreso de Interrupción) ................................ 290 
RETLW (Retorno con Literal en Wn)................................. 291 
REGRESO (Regreso)................................................. 292 
RLC (Girar a la izquierda f hasta Llevar).................... 293 
RLC (Girar Ws a la izquierda mediante transporte) ......... 294 
RLNC (Girar a la izquierda f sin llevar).................... 296 
RLNC (Girar a la izquierda sin llevar).................... 297 
Error 500 (Server Error)!!1500.That’s an error.There was an error. Please try again later.That’s all we know. 
RRC (Girar a la derecha Ws mediante transporte) ......... 300 
RRNC (Girar a la derecha f sin llevar).................... 302 
RRNC (Girar a la derecha Ws sin llevar)................. 303 
SAC (Acumulador de Tienda) ................................ 305 
SAC.R (Almacenar acumulador redondeado) ........................ 307 
SE (Firmar-Extender Ws)................................................. 309 
SETM (Configurar para WREG)................................................. 310 
SETM (Establecer Ws)................................................. 311 
SFTAC (Acumulador de Desplazamiento Aritmético por Slit5)... 312 
SFTAC (Acumulador de desplazamiento aritmético por Wb) .......... 313 
SL (Desplazamiento a la izquierda por literal corto)................................. 317 
SL (Desplazamiento a la izquierda por Wns)................................................. 318 
SL (Desplazamiento a la izquierda f)................................................. 314 
SL (Desplazamiento a la izquierda Ws)................................................. 315 
SUB (Restar acumuladores)................................. 324 
SUB (Restar literal de Wn) ................................ 320 
SUB (Restar literal corto de Wb).................... 321 
SUB (Restar WREG de f) ................................. 319 
SUB (Restar Ws de Wb)................................. 322 
SUBB (Restar literal corto de Wb con préstamo) 327 
SUBB (Restar Wn del Literal con Préstamo).......... 326 



## Página 371

¤ 2009 Microchip Technology Inc. 
DS70157D-página 371 
Índice 
Índice 
SUBB (Restar WREG y bit de acarreo de f) ......... 325 
SUBB (Restar Ws de Wb con préstamo)................. 329 
SUBBR (Restar f de WREG con Préstamo).......... 331 
SUBBR (Restar Wb del literal corto con préstamo).... 
332 
SUBBR (Restar Wb de Ws con préstamo) ................ 334 
SUBR (Restar f de WREG)................................. 336 
SUBR (Restar Wb del literal corto) ................. 337 
SUBR (Restar Wb de Ws) ................................ 338 
SWAP (Byte o Nibble Swap Wn).................... 340 
TBLRDH (lectura de tabla alta) ................................. 341 
TBLRDL (Lectura de tabla baja)................................. 343 
TBLWTH (Escritura alta en tabla)................................. 345 
TBLWTL (escritura baja en tabla) ................................. 347 
ULNK (marco de pila de desasignación) ........................ 349 
XOR (OR exclusivo f y WREG)................................. 350 
XOR (Exclusivo OR Literal y Wn).................... 351 
XOR (OR Exclusivo Wb y Literal Corto) ................. 352 
XOR (OR exclusivo Wb y Ws)................................. 353 
ZE (Zero-Extend Wn)................................................. 355 
Introducción a los descriptores de campos de codificación de instrucciones... 84 
Descripción general del conjunto de instrucciones ................................... 30 
Instrucciones de bits ........................................................ 36 
Comparar/Omitir instrucciones................................ 37 
Instrucciones de control................................................ 39 
Instrucciones DSP ........................................................ 39 
Grupos de instrucciones dsPIC30F/33F ........................ 30 
Instrucciones lógicas................................................................ 34 
Instrucciones de matemáticas................................................ 32 
Instrucciones de movimiento................................................ 32 
Instrucciones de flujo del programa ................................ 38 
Instrucciones de rotación/desplazamiento................................ 35 
Instrucciones de sombra/apilamiento................................ 39 
Tabla de resumen del conjunto de instrucciones................................ 360 
Símbolos del conjunto de instrucciones ........................................ 8 
(texto)................................................................................ 8 
[texto] ................................................................................ 8 
{ }................................................................................. 8 
{etiqueta:}................................................................................. 8 
#texto ................................................................................ 8 
<n:m>................................................................................ 8 
Acc................................................................................. 8 
AWB................................................................................ 8 
bit4 ................................................................................ 8 
Expr................................................................................. 8 
f................................................................................. 8 
iluminado1 ................................................................................ 8 
iluminado10 ................................................................................ 8 
lit14 ........................................................................................ 8 
lit16 ................................................................................ 8 
lit23 ................................................................................ 8 
iluminado4 ................................................................................ 8 
letra 5 ................................................................................ 8 
iluminado8 ................................................................................ 8 
Rendija10................................................................................ 8 
Rendija16................................................................................ 8 
Rendija4................................................................ 8 
Rendija5................................................................................ 8 
Condiciones de servicio................................................................ 8 
Wb................................................................................. 8 
Wd................................................................................. 8 
Wm, Wn ........................................................................ 8 
Wm*Wm................................................................ 8 
Wm*Wn................................................................................ 8 
Wn................................................................................. 8 
Viento................................................................................ 8 
Wns................................................................................ 8 
ESPOSA ................................................................................ 8 
Ws................................................................................ 8 
Wx................................................................................ 8 
Anx................................................................................. 8 
Wy................................................................................ 8 
Ancho ................................................................................ 8 
Puestos de instrucción ................................................................ 52 
Bucles DO/REPEAT................................................ 53 
Excepciones................................................................ 53 
Instrucciones que cambian el flujo del programa ......... 53 
PSV................................................................................ 53 
Detección de dependencia RAW................................ 52 
Símbolos de instrucción ........................................................ 84 
Datos enteros y fraccionarios ................................................ 70 
Representación ................................................................ 71 
Nivel de prioridad de interrupción................................................ 21 
Introducción................................................................................ 6 
METRO 
IMPERMEABLE 
Operaciones................................................................ 75 
Actualizaciones de registros de captación previa ................................ 74 
Capturas previas ................................................................ 74 
Sintaxis................................................................................ 75 
Escribir en respuesta ................................................................ 75 
Selección de reescritura del acumulador MAC................ 87 
Operandos de origen MAC o MPY (registro de trabajo diferente) 
87 
Operandos de origen MAC o MPY (mismo registro de trabajo) 87 
Objetivo manual................................................................ 6 
Modos de direccionamiento de módulo y de bits invertidos.... 47 
Instrucciones de ciclos múltiples................................................ 31 
Instrucciones de varias palabras................................................ 31 
norte 
Normalizando el acumulador con la instrucción FBCL..... 81 
oh 
Modos de direccionamiento compensado para el registro de destino Wd (con 
Compensación de registro) ................................................ 85 
Modos de direccionamiento compensado para el registro de origen Ws (con registro) 
Compensación del hermano)................................................................. 85 
PAG 
Compatibilidad del microcontrolador PIC®................................ 68 
PRODH 
Par de registros PRODL ................................................ 68 
Modos de direccionamiento del programa ................................ 51 
Métodos para modificar el flujo................................ 51 
Contador de programas ................................................................ 18 
Modelo del programador ................................................ 14 
Diagrama................................................................................ 15 
Descripciones de registros ................................................ 16 
Registro PSVPAG................................................................ 18 



## Página 372

DS70157D-página 372
¤ 2009 Microchip Technology Inc.
Manual de referencia del programador MCU y DSC de 16 bits
R
Registro RCOUNT ................................................................ 19
Registrar direccionamiento directo ................................................ 43
Registrar direccionamiento indirecto................................................ 44
Modos ................................................................................ 44
Registrar el direccionamiento indirecto y el conjunto de instrucciones... 47
Registros
Registro CORCON (Control central)................... 26, 27
SR (estado de la CPU)................................................. 23
Registro SR (estado) ................................................ 24
Documentos relacionados................................................................9
S
Escalar datos con la instrucción FBCL................................ 79
Ejemplos de escalamiento ................................................ 79
Registros sombra................................................................ 22
Uso automático................................................................ 22
Puntero de marco de pila de software ................................ 18, 62
Ejemplo ........................................................................ 63
Desbordamiento................................................................................ 64
Desbordamiento................................................................... 64
Puntero de pila de software................................................ 18, 60
Ejemplo ........................................................................ 61
Registro de límite de puntero de pila (SPLIM)................................. 18
Registro de estado................................................................ 19
Bits de estado de DSP ALU ................................. 20
Bits de estado del bucle................................................ 20
Bits de estado de MCU ALU................................ 19
Convenciones de estilo y símbolos .................................7
Convenciones de documentos................................................7
t
Registro TBLPAG ................................................................ 18
Documentación de terceros................................................ 9
Ud.
Uso de operandos literales de 10 bits................................ 59
Codificación literal de 10 bits................................................ 59
W.
Operaciones de movimiento de palabras................................................ 56
Alineación de datos en la memoria ........................................ 56
Matriz de registros de trabajo................................................ 17
x
Destino de captación previa del espacio de datos X................................ 86
Operación de captación previa del espacio de datos X ................................ 86
Y
Destino de captación previa del espacio de datos Y ................................ 87
Operación de captación previa del espacio de datos Y ................................ 86
z
Bit de estado Z ................................................................ 66


## Página 373

¤ 2009 Microchip Technology Inc.
DS70157D-página 373
índice
índice
NOTAS:


## Página 374

DS70157D-página 374
¤ 2009 Microchip Technology Inc.
AMÉRICAS
Oficina Corporativa
2355 bulevar oeste de Chandler.
Chandler, AZ 85224-6199
Teléfono: 480-792-7200 
Fax: 480-792-7277
Soporte técnico: 
http://support.microchip.com
Dirección web: 
www.microchip.com
Atlanta
Duluth, Georgia, EE.UU. 
Teléfono: 678-957-9614 
Fax: 678-957-1455
Boston
Westborough, Massachusetts, EE.UU. 
Teléfono: 774-760-0087 
Fax: 774-760-0088
chicago
Itasca, Illinois, EE.UU. 
Teléfono: 630-285-0071 
Fax: 630-285-0075
cleveland
Independencia, Ohio 
Teléfono: 216-447-0464 
Fax: 216-447-0643
dallas
Addison, Texas, EE.UU. 
Teléfono: 972-818-7423 
Fax: 972-818-2924
Detroit
Farmington Hills, Michigan, EE.UU. 
Teléfono: 248-538-2250
Fax: 248-538-2260
kokomo
Kokomo, Indiana 
Teléfono: 765-864-8360
Fax: 765-864-8387
Los Ángeles
Mission Viejo, California, EE.UU. 
Teléfono: 949-462-9523 
Fax: 949-462-9608
santaclara
Santa Clara, California, EE.UU. 
Teléfono: 408-961-6444
Fax: 408-961-6445
toronto
Mississauga, Ontario, 
Canadá
Teléfono: 905-673-0699 
Fax: 905-673-6509
ASIA/PACÍFICO
Oficina de Asia Pacífico
Suites 3707-14, Piso 37
Torre 6, La Puerta de Entrada
Ciudad portuaria, Kowloon
hong kong
Teléfono: 852-2401-1200
Fax: 852-2401-3431
Australia - Sídney
Teléfono: 61-2-9868-6733
Fax: 61-2-9868-6755
China - Pekín
Teléfono: 86-10-8528-2100 
Fax: 86-10-8528-2104
China - Chengdú
Teléfono: 86-28-8665-5511
Fax: 86-28-8665-7889
China - RAE de Hong Kong
Teléfono: 852-2401-1200 
Fax: 852-2401-3431
China - Nankín
Teléfono: 86-25-8473-2460
Fax: 86-25-8473-2470
China - Qingdao
Teléfono: 86-532-8502-7355
Fax: 86-532-8502-7205
China - Shangai
Teléfono: 86-21-5407-5533 
Fax: 86-21-5407-5066
China - Shenyang
Teléfono: 86-24-2334-2829
Fax: 86-24-2334-2393
China - Shénzhen
Teléfono: 86-755-8203-2660 
Fax: 86-755-8203-1760
China-Wuhan
Teléfono: 86-27-5980-5300
Fax: 86-27-5980-5118
China - Xiamén
Teléfono: 86-592-2388138 
Fax: 86-592-2388130
China - Xian
Teléfono: 86-29-8833-7252
Fax: 86-29-8833-7256
China - Zhuhai
Teléfono: 86-756-3210040 
Fax: 86-756-3210049
ASIA/PACÍFICO
India - Bangalore
Teléfono: 91-80-3090-4444 
Fax: 91-80-3090-4080
India - Nueva Delhi
Teléfono: 91-11-4160-8631
Fax: 91-11-4160-8632
India - Pune
Teléfono: 91-20-2566-1512
Fax: 91-20-2566-1513
Japón - Yokohama
Teléfono: 81-45-471-6166 
Fax: 81-45-471-6122
Corea - Daegu
Teléfono: 82-53-744-4301
Fax: 82-53-744-4302
Corea - Seúl
Teléfono: 82-2-554-7200
Fax: 82-2-558-5932 o 
82-2-558-5934
Malasia - Kuala Lumpur
Teléfono: 60-3-6201-9857
Fax: 60-3-6201-9859
Malasia - Penang
Teléfono: 60-4-227-8870
Fax: 60-4-227-4068
Filipinas - Manila
Teléfono: 63-2-634-9065
Fax: 63-2-634-9069
Singapur
Teléfono: 65-6334-8870
Fax: 65-6334-8850
Taiwán - Hsin Chu
Teléfono: 886-3-6578-300
Fax: 886-3-6578-370
Taiwán - Kaohsiung
Teléfono: 886-7-536-4818
Fax: 886-7-536-4803
Taiwán - Taipéi
Teléfono: 886-2-2500-6610 
Fax: 886-2-2508-0102
Tailandia - Bangkok
Teléfono: 66-2-694-1351
Fax: 66-2-694-1350
EUROPA
Austria - Gales
Teléfono: 43-7242-2244-39
Fax: 43-7242-2244-393
Dinamarca - Copenhague
Teléfono: 45-4450-2828 
Fax: 45-4485-2829
Francia - París
Teléfono: 33-1-69-53-63-20 
Fax: 33-1-69-30-90-79
Alemania - Múnich
Teléfono: 49-89-627-144-0 
Fax: 49-89-627-144-44
Italia - Milán 
Teléfono: 39-0331-742611 
Fax: 39-0331-466781
Países Bajos - Drunen
Teléfono: 31-416-690399 
Fax: 31-416-690340
España - Madrid
Teléfono: 34-91-708-08-90
Fax: 34-91-708-08-91
Reino Unido - Wokingham
Teléfono: 44-118-921-5869
Fax: 44-118-921-5820
Ventas y servicio a nivel mundial
26/03/09

