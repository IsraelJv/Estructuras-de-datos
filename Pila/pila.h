#define VERDADERO 1
#define FALSO     0

typedef struct nodo{

  int dato;
  struct nodo *enlace;  	
} tnodo, *Nodo;

typedef struct pila{

  Nodo base;
  Nodo tope;
  int longitud;
} tpila, *Pila;


Nodo crearNodo(void);
int escribirDato(Nodo n, int dato);
int conectarNodo(Nodo n, Nodo conexion);
int desconectarNodo(Nodo n);
void destruirNodo(Nodo n);

Nodo consultarEnlace(Nodo n);

Pila crearPila(void);
void destruirPila(Pila p);
int insertarDato(Pila p, int d);
int removerDato(Pila p, int *d);
int leerDato(Nodo n, int *dato);

int verificarPilaVacia(Pila p);
int consultarTope(Pila p, int *dato);
