#include "lista.h"

Nodo crearNodo(void)
{
	Nodo n= NULL;
	
	n= (Nodo) malloc(sizeof(tnodo));
	
	n->enlaceIzq= NULL;
	n->enlaceDer= NULL;
	n->dato= 0;
	
	return(n);
}

int escribirDato(Nodo n, int dato)
{
  if (n==NULL)
    return(FALSO);
    
  n->dato= dato;
  return(VERDADERO);    
}

int leerDato(Nodo n, int *dato)
{
  if (n==NULL)
    return(FALSO);
    
  *dato= n->dato;
  
  return(VERDADERO);    
}

void destruirNodo(Nodo n)
{
	if (n!=NULL)
	  {
	  	n->enlaceIzq= NULL;
	  	n->enlaceDer= NULL;
	  	free(n);
	  	n= NULL;
	  }
}



int conectarNodoDerecho(Nodo n, Nodo conexion)
{
	if (n==NULL || conexion==NULL)
	  return(FALSO);
	
	n->enlaceDer= conexion;
	conexion->enlaceIzq= n;
	  
	return(VERDADERO);  
}

int conectarNodoIzquierdo(Nodo n, Nodo conexion)
{
	if (n==NULL || conexion==NULL)
	  return(FALSO);
	
	n->enlaceIzq= conexion;
	conexion->enlaceDer= n;
	  
	return(VERDADERO);  
}

int desconectarNodo(Nodo n)
{
	Nodo izq= NULL, der= NULL;
	
	if (n==NULL)
	  return(FALSO);
	
	izq= n->enlaceIzq;
	der= n->enlaceDer;
	
	if (izq!=NULL)
	  izq->enlaceDer= NULL;
	  
	if (der!=NULL) 
	  der->enlaceIzq= NULL;
	
	n->enlaceIzq= NULL;
	n->enlaceDer= NULL;
	  
	return(VERDADERO);  
}

Nodo consultarEnlaceIzquierdo(Nodo n)
{
	if (n!=NULL)
	  return(n->enlaceIzq);
	  
	return(NULL);  
}

Nodo consultarEnlaceDerecho(Nodo n)
{
	if (n!=NULL)
	  return(n->enlaceDer);
	  
	return(NULL);  
}

/*************************************/

Lista crearLista(void)
{
	Lista l= NULL;
	
	l= (Lista) malloc(sizeof(tlista));
	
	if (l!=NULL)
	  {
	  	l->longitud=0;
	  	l->primero= NULL;
	  	l->ultimo= NULL;
	  }
	
	return(l);
}

void destruirLista(Lista l)
{
	Nodo posicion= NULL, der= NULL;
	int x, sw;
	
	if (l==NULL)
	  return;
	
	posicion= l->primero;
	  
    while(1)
	{
		der= posicion->enlaceDer;
		desconectarNodo(posicion);
		destruirNodo(posicion);
		posicion= der;
		
		if (posicion==NULL)
		  break;
	}
	  
	l->primero= NULL; 
    l->ultimo= NULL;
    l->longitud= 0;
    
    free(l);
}

int insertarDatoIzquierdo(Lista l, int dato, int indice)
{
	Nodo nuevo= NULL;
	Nodo posicion= NULL;
	Nodo izq= NULL;
	int k=0;
	int sw;
	
	if (l==NULL)
	  return(FALSO);
	
	if(l->longitud!=0)
		if ((indice>=l->longitud) || (indice<0))
	  		return(FALSO); 
	  
    nuevo= crearNodo();
    
    if (nuevo==NULL)
      return(FALSO);
      
    sw= escribirDato(nuevo, dato);
    
    if (l->longitud==0)
      {
      	l->primero= nuevo;
      	l->ultimo= nuevo;      	
	  }
	  
    if (l->longitud>0)
	  {
	  	posicion= l->primero;
	  	
	  	while(1)
	  	{
	  	   	
	  	   	if (posicion==NULL)
	  	   	  return(FALSO);
	  	   	  
	  	   	if(k==indice)
	  	   		break;
	  	   	  
	  	   	posicion= posicion->enlaceDer;
	  	   	k++;
		}
		
		izq= posicion->enlaceIzq;
		
		if (izq!=NULL)
		  {
		  	sw= conectarNodoIzquierdo(nuevo, izq);
		    if (sw==FALSO)
		      return(FALSO);
		  }

		sw= conectarNodoDerecho(nuevo, posicion);
		if (sw==FALSO)
		  return(FALSO);
		
		if (indice==0)  
		  l->primero= nuevo;
	  }  
	
	l->longitud++;
	  
	return(VERDADERO);  
}

int insertarDatoDerecho(Lista l, int dato, int indice)
{
	Nodo nuevo= NULL;
	Nodo posicion= NULL;
	Nodo der= NULL;
	int k=0;
	int sw;
	
	if (l==NULL)
	  return(FALSO);
	  
	if(l->longitud!=0)
		if ((indice>=l->longitud) || (indice<0))
	  		return(FALSO); 
	  
    nuevo= crearNodo();
    
    if (nuevo==NULL)
      return(FALSO);
      
    sw= escribirDato(nuevo, dato);
    
    if (l->longitud==0)
      {
      	l->primero= nuevo;
      	l->ultimo= nuevo;      	
	  }
	  
    if (l->longitud>0)
	  {
	  	posicion= l->primero;
	  	
	  	while(1)
	  	{
	  	   	
	  	   	if (posicion==NULL)
	  	   	  return(FALSO);
	  	   	  
	  	   	if(k==indice)
	  	   		break;
	  	   	  
	  	   	posicion= posicion->enlaceDer;
	  	   	k++;
		}
		
		der= posicion->enlaceDer;
		
		if (der!=NULL)
		  {
		  	sw= conectarNodoDerecho(nuevo, der);
		    if (sw==FALSO)
		      return(FALSO);
		  }

		sw= conectarNodoIzquierdo(nuevo, posicion);
		if (sw==FALSO)
		  return(FALSO);
		
		if (indice==(l->longitud-1))  
		  l->ultimo= nuevo;
	  }  
	
	l->longitud++;
	  
	return(VERDADERO);  
}

int eliminarDato(Lista l, int *dato, int indice)
{
	Nodo posicion= NULL;
	Nodo izq= NULL;
	Nodo der= NULL;
	int k=0;
	int sw;
	
	if (l==NULL)
	  return(FALSO);
	  
	if ((indice>=l->longitud) || (indice<0))
	  return(FALSO); 
	  
    if (l->longitud>0)
	  {
	  	posicion= l->primero;
	  	
	  	while(1)
	  	{
	  	   	
	  	   	if (posicion==NULL)
	  	   	  return(FALSO);
	  	   	  
	  	   	if(k==indice)
	  	   		break;
	  	   	  
	  	   	posicion= posicion->enlaceDer;
	  	   	k++;
		}
		
		izq= posicion->enlaceIzq;
		der= posicion->enlaceDer;
		
		sw= desconectarNodo(posicion);
		if (sw==FALSO)
		  return(FALSO);
		
		sw= leerDato(posicion, dato);		 
		if (sw==FALSO)
		  return(FALSO);
		  
		destruirNodo(posicion);
		
		if (izq!=NULL)
		  izq->enlaceDer= der;
		  
		if (der!=NULL)
		  der->enlaceIzq= izq;
		  
	    if (indice==0)
		  l->primero= der;
		
		if (indice==(l->longitud-1)) 
		  l->ultimo= izq;    
		  
	  }  
	
	l->longitud--;
	  
	return(VERDADERO);  
}

int consultarDato(Lista l, int *dato, int indice)
{
	Nodo posicion= NULL;
	int k=0;
	int sw;
	
	if (l==NULL)
	  return(FALSO);
	  
	if ((indice>=l->longitud) || (indice<0))
	  return(FALSO); 
	  
    if (l->longitud>0)
	  {
	  	posicion= l->primero;
	  	
	  	while(1){
	  	   	
	  	   	if (posicion==NULL)
	  	   	  return(FALSO);
	  	   	  
	  	   	if(k==indice)
	  	   		break;
	  	   	  
	  	   	posicion= posicion->enlaceDer;
	  	   	k++;
		}

		sw= leerDato(posicion, dato);		 
		if (sw==FALSO)
		  return(FALSO);
	  
	  }  
	  
	return(VERDADERO);  
}

int obtenerLongitud(Lista l){
	
	if(l!=NULL)
		return(l->longitud);
		
	return (0);
}

void desplegarLista(Lista l){
	
	
	Nodo actual=NULL;
	
	if(l==NULL)
		return;
		
	actual=l->primero;
		
	while(actual!=NULL){
			
		printf("%d \n",actual->dato);
		actual=actual->enlaceDer;
	}
		
	printf("\n");
}
