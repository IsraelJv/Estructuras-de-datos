#include <stdio.h>
#include <stdlib.h>

#define VERDADERO 1
#define FALSO     0

typedef struct nodo{
  int dato;
  struct nodo *enlaceDer;
  struct nodo *enlaceIzq;
} tnodo, *Nodo;

typedef struct lista{
  Nodo primero;
  Nodo ultimo;
  int longitud;
} tlista, *Lista;

Nodo crearNodo(void);
int escribirDato(Nodo n, int dato);
int leerDato(Nodo n, int *dato);
void destruirNodo(Nodo n);

int conectarNodoDerecho(Nodo n, Nodo conexion);
int conectarNodoIzquierdo(Nodo n, Nodo conexion);
int desconectarNodo(Nodo n);
Nodo consultarEnlaceIzquierdo(Nodo n);
Nodo consultarEnlaceDerecho(Nodo n);

Lista crearLista(void);
void destruirLista(Lista l);
int insertarDatoIzquierdo(Lista l, int dato, int indice);
int insertarDatoDerecho(Lista l, int dato, int indice);
int eliminarDato(Lista l, int *dato, int indice);
int consultarDato(Lista l, int *dato, int indice);
int obtenerLongitud(Lista l);
void desplegarLista(Lista l);
