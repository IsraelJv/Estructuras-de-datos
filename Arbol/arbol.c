#include "arbol.h"

Nodo crearNodo(void){
	
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
	  
	return(VERDADERO);  
}

int conectarNodoIzquierdo(Nodo n, Nodo conexion)
{
	if (n==NULL || conexion==NULL)
	  return(FALSO);
	
	n->enlaceIzq= conexion;
	  
	return(VERDADERO);  
}

int desconectarNodo(Nodo n)
{	
	if (n==NULL)
	  return(FALSO);
	
	n->enlaceIzq= NULL;
	n->enlaceDer= NULL;
	  
	return(VERDADERO);  
}


Arbol crearArbol(void)
{
	Arbol a= NULL;
	
	a= (Arbol) malloc(sizeof(tarbol));
	
	if (a!=NULL)
	  {
	  	a->cantidad=0;
	  	a->raiz=NULL;
	  }
	
	return(a);
}

void destruirArbol(Arbol a)
{
	if (a==NULL)
	  return;
	
	if(a->raiz!=NULL)
		destruirNodosRecursivamente(a->raiz);
		
	if(a->raiz!=NULL)
		destruirNodo(a->raiz);
		
	a->raiz = NULL;
	a->cantidad=0;
	
	free(a);
	
}

void destruirNodosRecursivamente(Nodo central){
	
	Nodo izq=NULL, der=NULL;
	
	if(central==NULL)
		return;
		
	izq= central->enlaceIzq;
	der=central->enlaceDer;
		
	if(izq!=NULL){
		
		central->enlaceIzq=NULL;
		destruirNodosRecursivamente(izq);
	}
				
	if(der!=NULL){
		
		central->enlaceDer=NULL;
		destruirNodosRecursivamente(der);
	}
	
	if(izq==NULL && der==NULL)
		destruirNodo(central);
}

int insertarDato(Arbol a, int dato)
{
	Nodo nuevo = NULL;

	if(a==NULL)
		return (FALSO);
		
	nuevo = insertarDatoRecursivo(a->raiz,dato);
	
	if(a->raiz==NULL)
		a->raiz=nuevo;
		
	if(nuevo!=NULL)
		a->cantidad++;
		
	return(VERDADERO);
}

Nodo insertarDatoRecursivo(Nodo central, int dato){
	
	Nodo nuevo=NULL;
	Nodo izq=NULL,der=NULL;
	
	if(central==NULL){
		
		nuevo=crearNodo();
		if(nuevo!=NULL)
			nuevo->dato=dato;
		return(nuevo);
	}
	
	izq=central->enlaceIzq;
	der=central->enlaceDer;
	
	if(dato<central->dato){
		
		nuevo = insertarDatoRecursivo(izq,dato);
		if(izq==NULL)
			central->enlaceIzq=nuevo;
	}	
	
	if(dato>central->dato){
		
		nuevo = insertarDatoRecursivo(der,dato);
		if(der==NULL)
			central->enlaceDer=nuevo;
	}
	
	return (nuevo);
}

int buscarDato(Arbol a,int dato){
	
	Nodo nodo = NULL;
	
	if(a==NULL)
		return (FALSO);
	
	if(a->raiz!=NULL)
		nodo=buscarDatoRecursivo(a->raiz,dato);
		
	if(nodo==NULL)
		return(FALSO);
		
	return (VERDADERO);
}

Nodo buscarDatoRecursivo(Nodo central,int dato){
	
	Nodo localizado=NULL;
	
	if(central==NULL)
		return NULL;
		
	if(central->dato==dato)
		return (central);
	
	if(dato<central->dato){
		
		localizado = buscarDatoRecursivo(central->enlaceIzq,dato);
	}
	
	if(dato>central->dato){
		
		localizado = buscarDatoRecursivo(central->enlaceDer,dato);
	}
		
	return (localizado);
}

Nodo buscarMinimo(Nodo central){
	
	Nodo min=NULL;
	
	if(central==NULL)
		return (NULL);
		
	min=central;
	
	while(min->enlaceIzq!=NULL)
		min=min->enlaceIzq;
		
	return(min);
}

Nodo buscarMaximo(Nodo central){
	
	Nodo max=NULL;
	
	if(central==NULL)
		return (NULL);
		
	max=central;
	
	while(max->enlaceDer!=NULL)
		max=max->enlaceDer;
		
	return(max);
}

int eliminarDato(Arbol a,int dato){
	
	int sw=FALSO;
	
	if(a==NULL)
		return (FALSO);
		
	if(a->raiz!=NULL)
		sw = eliminarDatoRecursivo(a->raiz,dato);
		
		
	return (sw);
}

int eliminarDatoRecursivo(Nodo central,int dato){
	
	Nodo localizado=NULL;
	Nodo eliminar=NULL;
	Nodo eIzq=NULL, eDer=NULL;
	Nodo cIzq=NULL,cDer=NULL;
	Nodo max=NULL, min=NULL;
	int sw = FALSO;
	
	if(central==NULL)
		return (FALSO);
	
	cIzq=central->enlaceIzq;
	cDer=central->enlaceDer;
		
	if(cIzq!=NULL)
		if(dato==cIzq->dato){
			
			eliminar=cIzq;
			eIzq=eliminar->enlaceIzq;
			eDer=eliminar->enlaceDer;
		
			if(eIzq!=NULL){
				max=buscarMaximo(cIzq);
				max->enlaceDer = cDer;
				central->enlaceIzq=eIzq;
			}else
				central->enlaceIzq = eDer;
		
			destruirNodo(eliminar);
		
			return (VERDADERO);
		}
		
	if(cDer!=NULL)	
		if(dato==cDer->dato){
		
			eliminar=cDer;
			eIzq=eliminar->enlaceIzq;
			eDer=eliminar->enlaceDer;
		
			if(eDer!=NULL){
				min=buscarMaximo(cDer);
				min->enlaceIzq = cIzq;
				
				central->enlaceDer=eDer;
			}else	
				central->enlaceDer=eIzq;
		
			destruirNodo(eliminar);
		
			return (VERDADERO);
		}
	
	if(dato<central->dato){
		
		sw = eliminarDatoRecursivo(central->enlaceIzq,dato);
	}
	
	if(dato>central->dato){
		
		sw = eliminarDatoRecursivo(central->enlaceDer,dato);
	}
		
	return (sw);
}

int recorrerArbolEnOrden(Arbol a){
	
	if(a==NULL)
		return(FALSO);
		
	if(a->raiz==NULL)
		return(FALSO);
		
	recorrerNodosEnOrden(a->raiz);
	
	printf("\n");
	
	return(VERDADERO);	
}

int recorrerNodosEnOrden(Nodo central){
	
	if(central==NULL)
		return(FALSO);
		
	recorrerNodosEnOrden(central->enlaceIzq);
	printf("%d\n",central->dato);
	recorrerNodosEnOrden(central->enlaceDer);
}

int recorrerArbolPreOrden(Arbol a){
	
	if(a==NULL)
		return(FALSO);
		
	if(a->raiz==NULL)
		return(FALSO);
		
	recorrerNodosPreOrden(a->raiz);
	
	printf("\n");
	
	return(VERDADERO);	
}

int recorrerNodosPreOrden(Nodo central){
	
	if(central==NULL)
		return(FALSO);
	
	printf("%d\n",central->dato);	
	recorrerNodosPreOrden(central->enlaceIzq);	
	recorrerNodosPreOrden(central->enlaceDer);
}

int recorrerArbolPosOrden(Arbol a){
	
	if(a==NULL)
		return(FALSO);
		
	if(a->raiz==NULL)
		return(FALSO);
		
	recorrerNodosPosOrden(a->raiz);
	
	printf("\n");
	
	return(VERDADERO);	
}

int recorrerNodosPosOrden(Nodo central){
	
	if(central==NULL)
		return(FALSO);
	
	recorrerNodosPosOrden(central->enlaceIzq);	
	recorrerNodosPosOrden(central->enlaceDer);
	printf("%d\n",central->dato);
	
}

int recorrerArbolAlreves(Arbol a){
	
	if(a==NULL)
		return(FALSO);
		
	if(a->raiz==NULL)
		return(FALSO);
		
	recorrerNodosAlreves(a->raiz);
	
	printf("\n");
	
	return(VERDADERO);
}
int recorrerNodosAlreves(Nodo central){
	
	if(central==NULL)
		return(FALSO);
	
	recorrerNodosAlreves(central->enlaceDer);	
	printf("%d\n",central->dato);
	recorrerNodosAlreves(central->enlaceIzq);
}

