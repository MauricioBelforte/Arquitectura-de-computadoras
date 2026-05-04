// =========================================================================
// DEFINICIONES DE CONSTANTES Y MACROS (Configuraciones del Sistema)
// =========================================================================

#define TRUE 1

// Límite de intentos del mozo antes de esperar el tiempo máximo (900us)
// Cada falla suma 150us de espera. 5 fallas + 1 base = 6 * 150 = 900us.
#define MAX_FALLAS 5

// Tamaños de los arreglos en RAM (Memoria de Datos)
#define TAM_BUFFER 10   // El "mostrador" tiene espacio para 10 caracteres
#define TAM_LOG 50      // La "mesa final" guarda un historial de 50 operaciones

// MACRO: CAR_GUARDADO
// Esta es una macro "con trampa" porque hace dos cosas a la vez:
// 1. Usa 'indBuffer' como dirección para guardar el carácter.
// 2. Inmediatamente después, incrementa 'indBuffer' (gracias al ++ postfijo).
// Es como si el cocinero apoyara la pizza y diera un paso a la derecha automáticamente.
#define CAR_GUARDADO buffer[indBuffer++]

// MACRO: FIN_DE_BUFFER(i)
// Es el sensor de "fin de mesa". Recibe un índice 'i' y chequea si ya llegamos 
// al límite del arreglo. 
// Nota: Usamos (TAM_BUFFER - 1) porque los arreglos en C empiezan en 0. 
// Si el tamaño es 10, las posiciones son 0 a 9. Si i es 9, ya estamos al final.
#define FIN_DE_BUFFER(i) (i >= (TAM_BUFFER - 1))

// =========================================================================
// PROTOTIPOS DE FUNCIONES (Declaraciones para que el compilador las conozca)
// =========================================================================
void config( void );
void Init_Timer1(void);