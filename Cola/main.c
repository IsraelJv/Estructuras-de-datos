#include <stdio.h>
#include <stdlib.h>
#include "cola.h"


int main(){

	Cola q=NULL;
	int c=0, lim=50, sw, x;

	q=crearCola();

	if(q!=NULL){

		sw=verificarColaVacia(q);

		if(sw==VERDADERO)
			printf("La cola esta vacia\n");
		else
			printf("La cola esta llena\n");

		for(c=0; c<lim; c++){

			sw=insertarDato(q,c);
			if(sw==VERDADERO){
				consultarUltimo(q,&x);
				printf("%d\n", x);	
			}
		}

		sw=verificarColaVacia(q);

		if(sw==VERDADERO)
			printf("La cola esta vacia\n");
		else
			printf("La cola esta llena\n");
			
		while(1){

			sw=removerDato(q,&c);
			if(sw==FALSO)
				break;
			printf("%d\n",c );
		}
		
		sw=verificarColaVacia(q);

		if(sw==VERDADERO)
			printf("La cola esta vacia\n");
		else
			printf("La cola esta llena\n");
			
		destruirCola(q);
	}

	return 0;
}
