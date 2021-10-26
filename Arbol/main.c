#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main() {
	
	Arbol arbol = NULL;
	
	arbol = crearArbol();
	
	if(arbol!=NULL){
		
		insertarDato(arbol,72);
		insertarDato(arbol,7);
		insertarDato(arbol,13);
		insertarDato(arbol,9);
		insertarDato(arbol,23);
		insertarDato(arbol,12);
		insertarDato(arbol,78);
		insertarDato(arbol,55);
		
		insertarDato(arbol,17);
		insertarDato(arbol,41);
		insertarDato(arbol,36);
		insertarDato(arbol,99);
		insertarDato(arbol,32);
		insertarDato(arbol,31);
		insertarDato(arbol,63);
		insertarDato(arbol,28);
		
		insertarDato(arbol,10);
		insertarDato(arbol,30);
		insertarDato(arbol,67);
		insertarDato(arbol,2);
		insertarDato(arbol,8);
		insertarDato(arbol,5);
		insertarDato(arbol,88);
		insertarDato(arbol,43);
		
		eliminarDato(arbol,31);
		
		recorrerArbolEnOrden(arbol);
		
		
		destruirArbol(arbol);
	}
	
	return 0;
}
