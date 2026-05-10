# 🎓 Guía de Examen: Productor - Consumidor (TP2-Eje1)

**Materia:** Arquitectura de Computadoras | **Micro:** dsPIC33F

Este documento resume los pasos exactos para demostrar el funcionamiento del sistema en MPLAB X.

---

## 1. Resumen Lógico (El Concepto)

El sistema funciona bajo el paradigma **Productor-Consumidor** para gestionar datos del Puerto B sin perder información.

- **PRODUCTOR (Interrupción INT1):** Cuando detecta un pulso (flanco ascendente), lee el **PORTB**, filtra si es un carácter válido ('0'-'9', '+', '-', '\*', '/') y lo guarda en el **Buffer Circular**.
- **CONSUMIDOR (Main + Timer1):** Cada **150µs** (Timer) el `main` revisa si hay datos en el buffer. Si hay, los procesa, los convierte (si es necesario) y los guarda en la tabla **Log de Operaciones**.
- **TEMPORIZACIÓN DINÁMICA:** Si no hay datos, el tiempo de espera aumenta de 150µs en 150µs (hasta 900µs). Si entra un dato, vuelve a 150µs.

---

## 2. Configuración de la "Mesa de Pruebas" (MPLAB X)

### A. Ventana de WATCHES (Lo que hay que mirar)

Agrega estas variables para demostrar que sabes qué pasa adentro:
| Variable | Valor Esperado | Significado |
| :--- | :--- | :--- |
| **`TMR1`** | Cambia rápido | Contador de hardware del Timer 1. |
| **`PR1`** | `6000` (o `0x1770`) | El límite del Timer para llegar a 150µs. |
| **`IFS1bits.INT1IF`** | `0` o `1` | La bandera que avisa que pulsaste el botón. |
| **`caracteresPendientes`**| `0, 1, 2...` | Cuántos datos hay en el buffer sin procesar. |
| **`buffer`** | Arreglo de chars | El mostrador intermedio. |
| **`logOperaciones`** | Arreglo de chars | La tabla final de datos procesados. |
| **`cantFallas`** | `0` a `5` | Indica el retraso actual (0=150µs, 5=900µs). |

### B. Configuración de STIMULUS (El "Teclado" falso)

Para enviar el carácter **'5'** (ASCII `0x35` -> Binario `0011 0101`):

1.  **Pestaña Pin Actions:** Configura los pines del Puerto B:
    - **RB0, RB2, RB4, RB5:** Set High (1)
    - **RB1, RB3, RB6, RB7:** Set Low (0)
2.  **Pin de Disparo:**
    - **INT1:** Ponlo en **Set Low**. Luego haz clic en **Fire** pasándolo a **High** (esto genera el flanco).

---

## 3. Demostración Paso a Paso (Lo que le muestras al Profe)

### Paso 1: Verificar el Corazón del Sistema (Timer)

1.  Pon un Breakpoint en `config.c` dentro de `_T1Interrupt`.
2.  Abre el **Stopwatch** y ponlo en cero.
3.  Dale a **F5 (Continue)**.
4.  **Resultado:** El Stopwatch debe marcar **6000 ciclos** o **150µs**.
    - _Explicación:_ "Aquí demuestro que el tiempo base de consumo es exacto".

### Paso 2: Producción de Datos

1.  Deja los pines RB configurados como un '5'.
2.  Dispara **INT1** (Fire High).
3.  Mira la variable `buffer` y `caracteresPendientes`.
4.  **Resultado:** `caracteresPendientes` sube a 1 y el '5' aparece en el buffer. Si ingresas 10 datos, verás que se llenan todas las posiciones (0 a 9) antes de volver a empezar.
    - _Explicación:_ "La interrupción capturó el dato del puerto y lo puso en el buffer circular".

### Paso 3: Consumo de Datos

1.  Dale a **F5 (Continue)**.
2.  Mira la variable `logOperaciones`.
3.  **Resultado:** El '5' se mantiene en el buffer (físicamente), pero ahora aparece también en el **Log**. El índice `indConsum` avanza y el LED en `PORTA` parpadea.
    - _Explicación:_ "El main detectó el tiempo del Timer, copió el dato del buffer al Log y avanzó el índice de lectura. El dato original sigue en el buffer hasta que la vuelta circular lo sobrescriba".

---

## 4. Preguntas "Trampa" de Examen

**Q: ¿Por qué usas un Buffer Circular y no guardas directo en el Log?**

- **A:** Porque la interrupción debe ser lo más rápida posible. Escribir en el log o procesar datos toma tiempo. El buffer permite que el micro reciba datos a toda velocidad y los procese cuando tenga un respiro.

**Q: ¿Por qué apagas las interrupciones en `IEC1bits.INT1IE = 0` al restar?**

- **A:** Para evitar una **condición de carrera**. La resta en C tarda varios ciclos de instrucción. Si entra una interrupción justo en el medio de la resta, el valor de `caracteresPendientes` quedaría corrupto (problema de atomicidad).

**Q: ¿Cómo sabes que el PR1 es 6000?**

- **A:** Porque Fcy = 40MHz. Tcy = 1/40MHz = 0.025µs. Si quiero 150µs: $150 / 0.025 = 6000$. En hexadecimal es `0x1770`.
