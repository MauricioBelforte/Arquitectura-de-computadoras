# TP2 - Interrupciones y Timers

1
Arquitectura de Computadoras
2026
Departamento de Informática
Universidad Nacional de la Patagonia San Juan Bosco

2
Interrupciones y Timers
Microcontroladores
dsPIC33F
Arquitectura de Computadoras 2026

3
Temario
• Contexto:
– Entrada/Salida programada (Polling)
– Entrada/Salida atendida por Interrupciones
– Entrada/Salida atendida por DMA
• Interrupciones en la familia dsPIC33F
• Ejemplo de programación de Interrupciones para E/S
• Timers en la familia dsPIC33F
• Ejemplo de programación de Interrupciones para
 temporización/sincronización (utilizando Timers)
• Ambiente de desarrollo y simulación
(Aclaración: No está toda la información en las diapositivas!)
Arquitectura de Computadoras 2026

4
Contexto
• Entrada/Salida programada (Polling)
Consulta (o escritura) periódica por parte del
programa principal.
• Entrada/Salida atendida por Interrupciones
La ejecución se deriva a una rutina de atención. Menos
intervención de la CPU.
• Entrada/Salida atendida por DMA
Método muy eficiente para transferir datos entre periféricos
(registros SFR) y buffers o variables en RAM, con mínima
intervención de la CPU.
• Otro uso de las interrupciones
– Acciones temporizadas/sincronizadas (uso de Timers)
Arquitectura de Computadoras 2026

5
Interrupciones en la familia dsPIC33F
• La ejecución se deriva a una rutina de atención. Se resguardan
previamente el PC y SR (8 bits) en la pila. Ante la instrucción
RETFIE se recupera el estado (de la pila) y continua la
ejecución del programa que fue interrumpido.
Ejemplo de rutina de atención del Timer1:
void __attribute__((interrupt, auto_psv)) _T1Interrupt( void ) {
    IFS0bits.T1IF = 0;
    …
    …
    …
} // El compilador pone acá una instrucción RETFIE
Arquitectura de Computadoras 2026

6
Interrupciones en la familia dsPIC33F
• Se resguardan previamente el PC y SR (8 bits). También el
IPL3.
Arquitectura de Computadoras 2026

7
Interrupciones en la familia dsPIC33F
• Ante la instrucción RETFIE se recupera el estado (de la pila)
y continua la ejecución el programa interrumpido.
Arquitectura de Computadoras 2026
Ver instrucción RETFIE en el “Set de instrucciones completo”
disponible en el Aula Virtual.

8
Interrupciones en la familia dsPIC33F
- Pueden interrumpir los dispositivos internos y muchos pines
conectados al exterior
• Existe una tabla de vectores que contiene las direcciones de
las rutinas de atención
Arquitectura de Computadoras 2026

9
• Tabla de Vectores de Interrupción
Arquitectura de Computadoras 2026
Interrupciones en la familia dsPIC33F

10
• Para cada fuente de interrupción existen bits para:
– Habilitar/Deshabilitar (xIE) (Interrupt Enable, 1 bit)
– Chequear ocurrencia (xIF) (Interrupt Flag, 1 bit)
– Asignar prioridades (xIP) (Interrupt Priority, 3 bits)
• Se encuentran en registros especiales
Arquitectura de Computadoras 2026
Interrupciones en la familia dsPIC33F

11
Ejemplo de programación de Interrupciones para E/S
Problema propuesto
Comandar un LED con un pulsador. Mientras
el pulsador esté presionado, el LED deberá
estar encendido. Y viceversa. Pulsador en
PORTC (bit14), LED en PORTD (bit 12).
Solución utilizando Change Notification
int main(void) {
    ini();
    while(1);
}
void ini(void) {
    CNEN1bits.CN0IE = 1;
    IEC1bits.CNIE = 1;
    TRISC = 0xFFFF; // bit 14 e
    TRISD = 0xEFFF; // bit 12 s
}
void __attribute__((interrupt, auto_psv)) _CNInterrupt( void ) {
    IFS1bits.CNIF = 0;
    if(PORTCbits.RC14)
        PORTDbits.RD12 = 1;
    else
        PORTDbits.RD12 = 0;
}
Arquitectura de Computadoras 2026

12
Prioridades de las interrupciones
• Existe un orden natural dado por la ubicación en la Tabla de
Vectores de Interrupción (IVT)
• La CPU tiene una prioridad de 4 bits IPL<3:0>
• El bit IPL<3> está en el registro CORCON (NO accesible al
programador). Se setea ante un TRAP (no enmascarable).
• IPL<2:0> está en el registro SR y se pueden modificar.
• Los dispositivos pueden tener prioridades de 0 a 7.
• La prioridad de un dispositivo debe ser mayor (estrictamente)
que la de la CPU para que el dispositivo pueda interrumpir.
Arquitectura de Computadoras 2026

13
Diagramas de tiempos de las interrupciones (1)
Arquitectura de Computadoras 2026

14
Diagramas de tiempos de las interrupciones (1)
Arquitectura de Computadoras 2026

15
Diagramas de tiempos de las interrupciones (1)
Arquitectura de Computadoras 2026

16
Diagramas de tiempos de las interrupciones (1)
Arquitectura de Computadoras 2026

17
Timers en la familia dsPIC33F
• 9 timers en total, desde Timer1 hasta Timer9, todos de 16 bits.
• Un timer cuenta pulsos de reloj hasta que se cumple una
 condición, por la cual genera una interrupción.
• Hay varias fuentes de reloj disponibles.
• El Timer1 puede usarse con un oscilador independiente, de baja
 frecuencia, para implementar Reloj de Tiempo Real (RTC).
• Los restantes timers pueden usarse de a pares (Timer2/3,
 Timer4/5, etc.) para implementar timers de 32 bits.
Arquitectura de Computadoras 2026

18
Timers en la familia dsPIC33F
Registros asociados a los timers
Arquitectura de Computadoras 2026
Tomando el Timer1:
Se configura y se activa en T1CON.
TMR1 se incrementa en cada pulso de reloj.
La condición de interrupción es TMR1 == PR1.
(Esto es igual para todos los timers usados individualmente.)

19
Timers en la familia dsPIC33F
Arquitectura de Computadoras 2026

20
Ejemplo de programación de Interrupciones
para Temporización
Problema propuesto
Generar una interrupción cada
doce ciclos de instrucción.
(Solución con Timer1)
int main(void) {
    config();
    while(1);
}
void config(void) {
        //Configurar Timer1
        T1CONbits.TON = 0;
        T1CONbits.TCS = 0;
        T1CONbits.TCKPS = 0;
        TMR1 = 0;
        PR1 = 11; // Ojo! Cada doce!
        //Configurar Interrupción.
        IPC0bits.T1IP = 1; // Prioridad 1
        IFS0bits.T1IF = 0;
        IEC0bits.T1IE = 1;
        T1CONbits.TON = 1; // Start!
 }
void __attribute__((interrupt, auto_psv)) 
_T1Interrupt( void ) {
    // Hacer algo interesante acá.
    IFS0bits.T1IF = 0;
}
Arquitectura de Computadoras 2026

21
Cálculo de tiempos con timers
Tener en cuenta:
Fcy = Fosc/2
Tcy = 1/Fcy
Tiempo entre interrupciones (t):
t = Tcy * Prescaler * PR
Ejemplo para T1:
t = Tcy * Prescaler * PR1
(Prescaler determinado por T1CONbits.TCKPS)
Arquitectura de Computadoras 2026
Fcy: Frecuencia de instrucción
Fosc: Frecuencia de oscilador
Tcy: Período de instrucción

22
Ejemplo de programación de Interrupciones
para Temporización
Problema propuesto: Generar una interrupción cada 100 ms.
Solución con Timer1 (t = Tcy * Prescaler * PR1)
Supongamos una Fcy = 40Mhz, entonces Tcy = 1/40 = 0.025us
Probemos con Prescaler 1:64 (es decir T1CONbits.TCKPS = 2)
100ms = 0.025us * 64 * PR1
PR1 = 100000us/(0.025us * 64)
PR1 = 62500
Arquitectura de Computadoras 2026

23
Ejemplo de programación de Interrupciones
para Temporización
Problema propuesto
Generar una interrupción cada
100 ms. (Dato: Fcy = 40Mhz)
Solución con Timer1
int main(void) {
    config();
    while(1);
}
void config(void) {
        //Configurar Timer1
        T1CONbits.TON = 0;
        T1CONbits.TCS = 0;
        T1CONbits.TCKPS = 2; // 1:64
        TMR1 = 0;
        PR1 = 62500;
        //Configurar Interrupción.
        IPC0bits.T1IP = 1; // Prioridad 1
        IFS0bits.T1IF = 0;
        IEC0bits.T1IE = 1;
        T1CONbits.TON = 1; // Start!
 }
void __attribute__((interrupt, auto_psv)) 
_T1Interrupt( void ) {
    // Este código se ejecuta cada 100 ms.
    IFS0bits.T1IF = 0;
}
Arquitectura de Computadoras 2026

24
Ambiente de 
desarrollo y 
simulación

25
Bibliografía
• Resumen de temas (elaborado por la cátedra)
• Sección 7.0 Interrupt Controller, del Datasheet de dsPIC33F
• Sección 6 Interrupts del Family Reference Manual (dsPIC33F)
• Sección 12.0 Timer1, del Datasheet de dsPIC33F
• Sección 13.0 Timer2/3, Timer4/5, Timer6/7, Timer8/9,
 del Datasheet de dsPIC33F
Arquitectura de Computadoras 2026
