#include <stdio.h>
#include <stdlib.h>

#define VERDADERO 1
#define FALSO     0

typedef struct nodo{

  int dato;
  struct nodo *enlace;  	
} tnodo, *Nodo;

typedef struct cola{

  Nodo primero;
  Nodo ultimo;
  int longitud;
} tcola, *Cola;

Nodo crearNodo(void);
int escribirDato(Nodo n, int dato);
int leerDato(Nodo n, int *dato);
void destruirNodo(Nodo n);
int conectarNodo(Nodo n, Nodo conexion);
int desconectarNodo(Nodo n);
Nodo consultarEnlace(Nodo n);

Cola crearCola(void);
void destruirCola(Cola q);
int insertarDato(Cola q,int dato);
int removerDato(Cola q, int *dato);
int verificarColaVacia(Cola q);
int consultarPrimero(Cola q, int *dato);
int consultarUltimo(Cola q, int *dato);
