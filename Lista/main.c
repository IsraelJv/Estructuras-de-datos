#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
	
	Lista lista=NULL;
	int i=0, x=0;
	int sw=0;
	
	lista =crearLista();
	
	if(lista!=NULL){
		
		for(x=0;x<100;x++)
			insertarDatoDerecho(lista,x,x-1);
			//insertarDatoIzquierdo(lista,x,0);
			
		desplegarLista(lista);
		
		sw=eliminarDato(lista, &x, 99);
		if(sw==VERDADERO)
			printf("dato=%d\n",x);
		else
			printf("No se pudo imprimir\n");
			
		sw=eliminarDato(lista, &x, 99);
		if(sw==VERDADERO)
			printf("dato=%d\n",x);
		else
			printf("No se pudo imprimir\n");
		desplegarLista(lista);
		destruirLista(lista);
		
	}
	
	return 0;
}
