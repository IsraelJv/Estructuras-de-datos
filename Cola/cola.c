#include "cola.h"

Cola crearCola(void){

	Cola q= NULL;
	
	q=(Cola) malloc(sizeof(tcola));
	
	if(q!=NULL){
		q->primero= NULL;
		q->ultimo= NULL;
		q->longitud= 0;
	}
	return(q);
}

void destruirCola(Cola q){

	int x, sw;

	if(q==NULL)
		return;

	while(1){

	  sw= removerDato(q, &x);
	  
	  if (sw==FALSO)
	    break;
	}

	q->primero=NULL;
	q->ultimo=NULL;
	q->longitud=0;

	free(q);
}

int insertarDato(Cola q,int dato){

	int sw;

	Nodo nuevo=NULL;

	if(q==NULL)
		return (FALSO);

	nuevo=crearNodo();

	if(nuevo==NULL)
		return(FALSO);

	sw=escribirDato(nuevo,dato);

	if(q->longitud==0){

		q->primero=nuevo;
		q->ultimo=nuevo;
	}

	if(q->longitud>0){

		sw=conectarNodo(q->ultimo, nuevo);

		if(sw==FALSO)
			return (FALSO);

		q->ultimo=nuevo;
	}

	q->longitud++;
	return(VERDADERO);
}

int removerDato(Cola q, int *dato){

	Nodo aux=NULL;
	int sw;

	if(q==NULL)
		return (FALSO);

	if(q->longitud<=0)
		return (FALSO);

	sw=leerDato(q->primero, dato);

	if(sw==FALSO)
		return(FALSO);

	aux=consultarEnlace(q->primero);
	sw=desconectarNodo(q->primero);

	if(sw==FALSO)
		return(FALSO);

	destruirNodo(q->primero);
	q->primero=aux;
	q->longitud--;

	return (VERDADERO);
}

int verificarColaVacia(Cola q){

	if(q==NULL)
		return(VERDADERO);

	if(q->longitud==0)
		return(VERDADERO);

	return(FALSO);
}

int consultarPrimero(Cola q, int *dato){

	int sw=FALSO;

	if(q==NULL)
		return(FALSO);

	if (q->longitud>0&&q->primero!=NULL)
		sw=leerDato(q->primero, dato);

	return(sw);
}

int consultarUltimo(Cola q, int *dato){

	int sw=FALSO;

	if(q==NULL)
		return(FALSO);

	if (q->longitud>0&&q->ultimo!=NULL)
		sw=leerDato(q->ultimo, dato);

	return(sw);
}



//Codigo reciclado
Nodo crearNodo(void){

	Nodo n= NULL;
	
	n= (Nodo) malloc(sizeof(tnodo));
	
	n->enlace= NULL;
	n->dato= 0;
	
	return(n);
}

int escribirDato(Nodo n, int dato){

  if (n==NULL)
    return(FALSO);
    
  n->dato= dato;
  return(VERDADERO);    
}
int leerDato(Nodo n, int *dato){

  if (n==NULL)
    return(FALSO);
    
  *dato= n->dato;
  
  return(VERDADERO);    
}

void destruirNodo(Nodo n){

	if (n!=NULL){

	  	n->enlace= NULL;
	  	free(n);
	  	n= NULL;
	}
}

int conectarNodo(Nodo n, Nodo conexion){

	if (n==NULL)
	  return(FALSO);
	
	n->enlace= conexion;
	  
	return(VERDADERO);  
}

int desconectarNodo(Nodo n){

	if (n==NULL)
	  return(FALSO);
	
	n->enlace= NULL;
	  
	return(VERDADERO);  
}

Nodo consultarEnlace(Nodo n){

	if (n!=NULL)
	  return(n->enlace);
	  
	return(NULL);  
}
