#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(){

	Pila p=NULL;
	int c=0, lim=50, sw, x;

	p=crearPila();

	if(p!=NULL){

		sw=verificarPilaVacia(p);

		if(sw==VERDADERO)
			printf("La pila esta vacia\n");
		else
			printf("La pila esta llena\n");

		for(c=0; c<lim; c++){

			sw=insertarDato(p,c);
			if(sw==VERDADERO){
				consultarTope(p,&x);
				printf("%d\n", x);	
			}
		}

		sw=verificarPilaVacia(p);

		if(sw==VERDADERO)
			printf("La pila esta vacia\n");
		else
			printf("La pila esta llena\n");
			
		while(1){

			sw=removerDato(p,&c);
			if(sw==FALSO)
				break;
			printf("%d\n",c );
		}
		
		sw=verificarPilaVacia(p);

		if(sw==VERDADERO)
			printf("La pila esta vacia\n");
		else
			printf("La pila esta llena\n");
			
		destruirPila(p);
	}
	return 0;
}

