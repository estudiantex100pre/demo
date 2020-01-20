#include <iostream>
#include <stdlib.h>
using namespace std ;

struct nodo {
	int valor ;
	nodo *der ;
	nodo *izq ;
};

void insertar(nodo*&, int) ;
void mostrar(nodo*) ;
void eliminar(nodo*&, int) ;


int main(){
	nodo *arbol=NULL ;
	insertar(arbol, 20) ;
	insertar(arbol, 25) ;
	insertar(arbol, 30) ;
	insertar(arbol, 22) ;
	insertar(arbol, 24) ;
	insertar(arbol, 23) ;
	insertar(arbol, 12) ;
	insertar(arbol, 18) ;

	mostrar(arbol) ; cout<<endl;
	eliminar(arbol, 22) ;

	mostrar(arbol) ;cout<<endl;
	system("pause") ;
	return 0 ;
}

void eliminar(nodo* &arb, int dato){
	nodo* actual = arb ;
	nodo* padre =NULL ;
	nodo* hoja ;
	int aux ;
	while(actual)
	    if(actual->valor == dato)
			if(!actual->izq && !actual->der){
	    	    if(padre)
	    	        if(padre->izq == actual) padre->izq=NULL ;
	    	        else padre->der=NULL ;

		        delete actual ;  // solo elima hojas ;
		        actual=NULL ; // solo x esto se pasa x refencia el puntero arbol;
			}
			else{ // camibiar el nodo a un nodo hoja ;
			        padre = actual ;
			  	  if(actual->der){
			  	      hoja = actual->der ;
			  	      while(hoja->izq){
			  	          padre= hoja ;
			  	          hoja= hoja->izq ;
						}
					}
				    else{
				        hoja = actual->izq ;
				        while(hoja->der){
				            padre=hoja ;
				            hoja=hoja->der ;
						}
					}
				//	aux= actual->valor ;
					actual->valor = hoja->valor ;
					hoja->valor=dato ; //hoja->valor = dato ;
					actual=hoja ;
				}
			
	    else{
			padre =actual ; //padre hace la de anterior;
			if(dato < actual->valor) actual= actual->izq ;
			else if(dato > actual->valor) actual= actual->der ;
		}
}

void mostrar(nodo * arb) { //innodo
	if(!arb)return ;
	else {
		mostrar(arb->izq) ;  //    if(ban)

		cout<<" "<<arb->valor<<" " ;
		mostrar(arb->der) ;  // if(ban)
	}

}

void insertar(nodo *&arb, int x) {
	nodo *actual=arb ;
	nodo *padre= NULL ;

	while(actual /* && actual->valor != x*/){ //cuando actual consiga NULL es hay donde se inserta el valor
		padre=actual ;
		if(x < actual->valor) actual= actual->izq ; //aqui se determina a donde debe estar el valor
		else if(x >= actual->valor) actual=actual->der ;
	}
	if(!padre){
		arb = new nodo ;
		arb->valor= x ;
		arb->izq = NULL;
		arb->der = NULL ;
	}
	else
			if(x < padre->valor){
			    actual = new nodo ;
			    padre->izq = actual;
			    actual->valor=x ;
			    actual->der = actual->izq = NULL ;
			}
			else if(x >= padre->valor){
			    actual = new nodo ;
			    padre->der= actual ;
			    actual->valor=x ;
			    actual->der = actual->izq = NULL ;
			}
}
