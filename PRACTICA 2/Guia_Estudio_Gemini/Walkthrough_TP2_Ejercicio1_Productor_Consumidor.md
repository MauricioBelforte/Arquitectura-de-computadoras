# Tutorial Paso a Paso: TP2 Ejercicio 1 (Productor-Consumidor)

Este documento es una recreación cronológica de cómo pensar, diseñar y programar el Ejercicio 1 del Trabajo Práctico N° 2 desde cero. El objetivo es que sirva como una lectura fluida antes de rendir o repasar el código, entendiendo el *por qué* de cada línea.

---

## 1. Entendiendo el Paradigma: Productor / Consumidor

Antes de tirar código, hay que entender qué es lo que nos pide la cátedra:
Imaginá que estás en una pizzería.
*   **El Productor (La Interrupción `INT1`):** Es el cocinero. Cada vez que alguien aprieta el botón físico, él "cocina" un dato y lo apoya en el mostrador.
*   **El Mostrador (El Buffer Circular):** Es el arreglo temporal donde los datos esperan. Es circular para no quedarse nunca sin espacio físico de memoria (cuando llega al final, vuelve a empezar en la posición 0 sobrescribiendo los datos viejísimos).
*   **El Consumidor (El `main.c`):** Es el mozo. Cada cierta cantidad de tiempo, va al mostrador, agarra todas las pizzas que haya, y las lleva a la mesa final (el arreglo definitivo llamado `logOperaciones`).
*   **El Timer (El reloj del mozo):** El mozo es inteligente. Si va al mostrador y no hay pizzas, la próxima vez tarda más en ir para no gastar energía (pasa de esperar 150us a 300us, 450us, etc). Si encuentra una pizza, se entusiasma y vuelve al ritmo rápido original de 150us.

---

## PASO 1: Configuración Inicial y Las Herramientas

Empezamos definiendo nuestras variables globales y macros que nos harán la vida más fácil.

### ¿Por qué el Prescaler es 1:1?

El enunciado pide un tiempo base de **150 microsegundos**. Esto es un tiempo extremadamente corto.
Hagamos la matemática con cada prescaler disponible para ver cuál conviene:

| Prescaler | Tcy efectivo (cada cuánto suma 1 el TMR) | PR1 necesario (150us / Tcy) | ¿Es entero? | ¿Cabe en 16 bits (máx 65535)? |
|-----------|------------------------------------------|------------------------------|-------------|-------------------------------|
| **1:1**   | 0,025 us                                | **6000**                     | ✅ Sí       | ✅ Sí (sobra espacio)         |
| 1:8       | 0,2 us                                  | 750                          | ✅ Sí       | ✅ Sí                         |
| 1:64      | 1,6 us                                  | **93,75**                    | ❌ ¡No!     | -                             |
| 1:256     | 6,4 us                                  | **23,4375**                  | ❌ ¡No!     | -                             |

**Conclusión:** Los prescalers 1:64 y 1:256 dan números con decimales. Como el registro `PR1` solo puede guardar números enteros, habría que redondear y el tiempo **nunca sería exactamente** 150us. El prescaler 1:8 también funciona, pero el 1:1 nos da la **máxima resolución posible** (el grano más fino de tiempo, 0,025us por pulso). Como 150us es un tiempo tan pequeño que entra cómodamente en un registro de 16 bits con 1:1, no necesitamos "frenar" el reloj con un prescaler mayor.

> **Regla general para elegir prescaler:** Usá el prescaler más bajo que te dé un número entero en PR1 y que no se pase de 65535. Así tenés la máxima precisión.

```c
// Definimos el tiempo base del Timer (150us a 40MHz con Prescaler 1:1)
// Cálculo: 150us / 0,025us = 6000 pulsos exactos
#define ValPR1  6000 

// Creamos un Filtro Inteligente. El enunciado dice que SOLO aceptamos números o los signos aritméticos básicos.
#define ES_CARACTER_VALIDO(c) ( (c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' )

// Variables de Comunicación entre Interrupciones y Main
int caracteresPendientes = 0; // ¿Cuántas pizzas hay en el mostrador sin retirar?
int counterTimer = 0;         // Los "ticks" de reloj de nuestro mozo.
int cantFallas = 0;           // ¿Cuántas veces el mozo fue al mostrador y estaba vacío?

// El Mostrador (Buffer Circular)
char buffer[TAM_BUFFER];    
int indBuffer = 0;          // Índice del Productor ("aguja de ESCRITURA")
int indConsum = 0;          // Índice del Consumidor ("aguja de LECTURA")

// La Mesa Final
char logOperaciones[TAM_LOG];   
int indLog = 0;                 
```

---

## PASO 2: Construyendo al Productor (Interrupción `INT1`)

El Productor vive en las sombras. Solo despierta cuando ocurre un flanco ascendente en el Pin conectado a `INT1`. Su trabajo es rápido: atrapar la tecla, validarla, y dejarla en el mostrador.

```c
void __attribute__((interrupt, auto_psv)) _INT1Interrupt( void ){
    IFS1bits.INT1IF = 0;    // 1. OBLIGATORIO: Bajar bandera para no colgar el chip
    
    char c = PORTB;         // 2. Leemos la tecla presionada desde los pines físicos
    
    // 3. ¿Es un dígito o un signo matemático?
    if (ES_CARACTER_VALIDO(c)){	
        caracteresPendientes++;   // ¡Nueva pizza en el mostrador! Avisamos al mozo sumando 1.
        buffer[indBuffer] = c;    // Guardamos el dato (En el código original usaste la macro CAR_GUARDADO)
        indBuffer++;
        
        // 4. Lógica de Buffer Circular: Si llegué al final de la mesa, vuelvo al principio.
        if (indBuffer >= TAM_BUFFER) {
            indBuffer = 0;      
        }
    }
}
```

> **Aclaración clave:** Todo dato que no pase el `if (ES_CARACTER_VALIDO)` se descarta automáticamente porque la función termina y no hace nada más.

---

## PASO 3: Construyendo el Reloj (Timer 1)

El temporizador no analiza lógica, solo marca el compás de la banda. Configuramos `PR1` a 6000 para que esta interrupción se dispare matemáticamente **cada 150 microsegundos**.

```c
void __attribute__((interrupt, auto_psv)) _T1Interrupt( void ){
    IFS0bits.T1IF = 0; 	// 1. OBLIGATORIO: Bajar bandera
    counterTimer++;     // 2. Sumamos un "tick" al reloj del mozo (pasaron 150us)
}
```

---

## PASO 4: Construyendo la Acción de Consumir

Ahora necesitamos la función que el `main.c` llamará cuando el mozo decida ir a retirar la comida.

```c
void consumirDatos(int cantidadAProcesar){
    int i;
    for (i = 0; i < cantidadAProcesar; i++){
        // Sacamos un caracter de la posición actual de lectura
        char car = buffer[indConsum];
        indConsum++; 
        
        // Guardamos en la memoria final (La mesa del cliente)
        logOperaciones[indLog] = car;
        indLog++;
        
        // Protegemos los índices circulares
        if (indLog >= TAM_LOG)    indLog = 0;
        if (indConsum >= TAM_BUFFER) indConsum = 0;
    }
}
```

---

## PASO 5: El Cerebro Maestro y El Bug de Concurrencia (`main.c`)

Aquí es donde toda la magia sucede junta. El `main` debe ejecutar el parpadeo de un LED, y manejar la "Temporización Dinámica" del consumidor.

*   Si no hay datos, espera 1 tick de más cada vez (`cantFallas` va aumentando hasta 5 o el valor `MAX_FALLAS`).
*   Si hay datos, extrae lo que haya y reinicia la espera a 0.

Aquí es donde incorporamos la corrección de la **Condición de Carrera (Race Condition)**. 

```c
int main(void) {
    config(); // Enciende los puertos y el Timer.
    
    while(1){
        // ¿Llegó el momento de que el mozo revise el mostrador?
        // El tiempo de espera es dinámico: (cantFallas + 1) * 150 microsegundos.
        if (counterTimer > cantFallas ){
            
            // Si va al mostrador y estaba vacío, la próxima vez tardará más (hasta el límite)
            if (cantFallas < MAX_FALLAS) {
                cantFallas++;           
            }
            
            // Si resulta que SÍ hay pizzas en el mostrador:
            if (caracteresPendientes > 0){       
                
                // 1. Congelamos la cantidad EXACTA que vamos a sacar ahora mismo.
                int procesados = caracteresPendientes;
                
                // 2. Consumimos esa cantidad exacta.
                consumirDatos(procesados);
                
                // 3. SOLUCIÓN AL BUG DE HARDWARE:
                // Si poníamos "caracteresPendientes = 0;", corríamos el riesgo de 
                // borrar un dato nuevo que la INT1 hubiera agregado justo una 
                // fracción de segundo antes. Para evitar colisiones:
                // a) Apagamos la interrupción (nadie puede agregar pizzas un segundo)
                // b) Restamos exactamente las pizzas que sacamos.
                // c) Volvemos a prender la interrupción.
                IEC1bits.INT1IE = 0;
                caracteresPendientes -= procesados;
                IEC1bits.INT1IE = 1;
                
                // 4. Como el mozo encontró comida, se entusiasma y vuelve al ritmo rápido (150us)
                cantFallas = 0;         
            }
            
            // Tarea en Paralelo: Parpadeo del LED
            LATA = !LATA; 
            
            // Reiniciamos el reloj para la próxima inspección
            counterTimer = 0;
        }
    }
}
```

## Resumen de la Lección
Este proyecto demuestra cómo delegar responsabilidades en un microcontrolador. 
1. `INT1` actúa como un portero asíncrono. Responde inmediatamente al estímulo físico y se encarga del filtrado sucio.
2. `Timer1` es un reloj inquebrantable de fondo que lleva la cuenta del tiempo sin que le importen los pines.
3. El bucle `main` gestiona la carga de la CPU decidiendo **cuándo** es el mejor momento energético para procesar datos (temporización dinámica), coordinando el trabajo pesado de vaciar el buffer sin interferir con las interrupciones críticas.
