#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

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

Pila crearPila(void){

	Pila p= NULL;
	
	p= (Pila) malloc(sizeof(tpila));
	
	p->base= NULL;
	p->tope= NULL;
	p->longitud= 0;
	
	return(p);
}

void destruirPila(Pila p){

	Nodo aux= NULL;
	int sw= FALSO;
	int x;
	
	if (p==NULL)
	  return;
	  
	while(1){

	  sw= removerDato(p, &x);
	  
	  if (sw==FALSO)
	    return;
	}  
	  
	p->tope= NULL;  
	p->base= NULL;
	
	free(p);
	p= NULL;  	  
}

int insertarDato(Pila p, int d){

	Nodo nuevo=NULL;
	int sw;
	
	if (p==NULL)
	  return(FALSO);
	  
	nuevo= crearNodo();
	
	if (nuevo==NULL)  
	  return(FALSO);
	
	sw= escribirDato(nuevo, d);

    if (sw==VERDADERO){

      	if (p->base==NULL || p->longitud==0)
      	  p->base= nuevo;
      	  
      	sw= conectarNodo(nuevo, p->tope);  
      	
		if (sw==FALSO)
		  return(FALSO);
		    
      	p->tope= nuevo;  
      	p->longitud++;

	}
	return(VERDADERO);  
}

int removerDato(Pila p, int *d){

	Nodo aux=NULL;
	int sw= FALSO;
	
	if (p==NULL)
	  return(FALSO);
	  
	if (p->longitud==0 || p->base==NULL || p->tope==NULL)
	  return(FALSO);
	
	aux= p->tope;  
	sw= leerDato(aux, d); 
	   if (sw==FALSO)
	     return(FALSO);
		  
	p->tope= consultarEnlace(aux);
	
	sw= desconectarNodo(aux);
	   if (sw==FALSO)
	     return(FALSO);
		 	
	destruirNodo(aux);
	aux=NULL;
		 	
	p->longitud--;

    if (p->longitud==1)
      p->base= p->tope;
    
	if (p->longitud==0){	  
	
	   p->tope= NULL;
	   p->base= NULL;  
    }
      
    return(VERDADERO);
}

int verificarPilaVacia(Pila p){

	if(p==NULL)
		return(VERDADERO);

	if(p->longitud==0)
		return(VERDADERO);

	return(FALSO);
}

int consultarTope(Pila p, int *dato){

	int sw=FALSO;

	if(p==NULL)
		return(FALSO);

	if (p->longitud>0)
		sw=leerDato(p->tope, dato);

	return(sw);
}
