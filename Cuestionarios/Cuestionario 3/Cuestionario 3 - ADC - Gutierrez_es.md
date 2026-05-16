# Cuestionario 3 - ADC - Gutierrez
**Materia:** Arquitectura de Computadoras
**Temas:** Conversores ADC, DMA
**Fecha:** 16/05/2023
**Alumno:** Cristian Gutierrez
**Nota:** 90 (Aprobado)

---

## 📝 Contenido del Cuestionario

### 1. Rutina de Atención del ADC1
**Consigna:** Suponga que el ADC1 será atendido por interrupciones. Está configurado para realizar conversiones sucesivas en forma automática. El formato utilizado es entero sin signo. Complete la siguiente rutina de atención. Debe tomar valores hasta que el **valor actual** sea **igual al anterior** (en ese momento **apagar el ADC1**). El valor de interés se guardará en la variable `equal_val`.

```c
unsigned int actual;
unsigned int equal_val = 0;

void __attribute__((interrupt, auto_psv)) _AD1Interrupt(void)
{
    /* Nota del docente: El alumno escribió estas líneas pero fueron marcadas 
       como INCORRECTAS/INNECESARIAS en este contexto de autoconversión:
       AD1CON1bits.SAMP = 1; 
       while(!AD1CON1bits.DONE); 
    */

    actual = ADC1BUF0; // Lectura del buffer (inferido)

    // Lógica de comparación y apagado:
    AD1CON1bits.SAMP = 0; 
    if (actual != equal_val) {
        equal_val = actual;
    } else {
        AD1CON1bits.ADON = 0; // Apaga el ADC cuando los valores coinciden
    }
}
```

---

### 2. Tiempos de Operación del ADC
Dado el gráfico relacionado con los tiempos de operación de un ADC (ADC1):
- **(a)** Tiempo de muestreo
- **(b)** Tiempo de conversión
- **(c)** Fin de conversión

**a) ¿Qué evento puede provocar el comienzo del Tiempo de muestreo (punto (a))?**
> **Respuesta:** El evento puede ser una interrupción del ADC1 o algún procedimiento donde se encuentre la sentencia `AD1CON1bits.SAMP = 1;` (siempre y cuando el ADC1 esté activado).

**b) ¿Qué evento corresponde con el punto (b)?**
> **Respuesta:** Es el fin del muestreo. Se desconecta la entrada y comienza la conversión física de la señal analógica a digital.

**c) ¿Qué evento corresponde con el punto (c) y cómo puede detectarse?**
> **Respuesta:** Es el fin de la conversión. Se puede detectar monitoreando el bit `AD1CON1bits.DONE`, el cual debe estar en '1' cuando el proceso termina.

---

### 3. Configuración del DMA0 para ADC1
Suponga que está configurando el DMA0 para tomar los datos provenientes del ADC1.

**a) ¿Qué rol cumple el registro DMA0PAD y qué valor debería asignarle en este caso?**
> **Respuesta:** En `DMA0PAD` se coloca la dirección del periférico asociado que actuará como fuente o destino de los datos. En este caso, se debería cargar con la dirección del registro buffer del ADC1.
> **Instrucción:** `DMA0PAD = &AD1BUF0;`

**b) ¿Qué rol cumple el registro DMA0REQ y qué valor debería asignarle en este caso?**
> **Respuesta:** En `DMA0REQ` se coloca el número de IRQ (Interrupt Request) del dispositivo asociado para sincronizar la transferencia. En este caso, para el ADC1, se debe asignar el valor decimal `13`.
> **Instrucción:** `DMA0REQ = 13;`
