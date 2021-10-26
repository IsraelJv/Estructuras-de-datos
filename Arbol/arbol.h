#include <stdio.h>
#include <stdlib.h>

#define VERDADERO 1
#define FALSO     0

typedef struct nodo{
  int dato;
  struct nodo *enlaceDer;
  struct nodo *enlaceIzq;
} tnodo, *Nodo;

typedef struct arbol{
  Nodo raiz;
  int cantidad;
} tarbol, *Arbol;

Nodo crearNodo(void);
int escribirDato(Nodo n, int dato);
int leerDato(Nodo n, int *dato);
void destruirNodo(Nodo n);

int conectarNodoDerecho(Nodo n, Nodo conexion);
int conectarNodoIzquierdo(Nodo n, Nodo conexion);
int desconectarNodo(Nodo n);


Arbol crearArbol(void);
void destruirArbol(Arbol a);
void destruirNodosRecursivamente(Nodo central);
int insertarDato(Arbol a, int dato);
Nodo insertarDatoRecursivo(Nodo central, int dato);
int buscarDato(Arbol a,int dato);
Nodo buscarDatoRecursivo(Nodo central,int dato);
Nodo buscarMinimo(Nodo central);
Nodo buscarMaximo(Nodo central);
int eliminarDato(Arbol a,int dato);
int eliminarDatoRecursivo(Nodo central,int dato);

int recorrerArbolEnOrden(Arbol a);
int recorrerNodosEnOrden(Nodo central);
int recorrerArbolPreOrden(Arbol a);
int recorrerNodosPreOrden(Nodo central);
int recorrerArbolPosOrden(Arbol a);
int recorrerNodosPosOrden(Nodo central);

int recorrerArbolAlreves(Arbol a);
int recorrerNodosAlreves(Nodo central);
