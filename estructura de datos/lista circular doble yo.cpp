#include <iostream>
#include <stdlib.h>
using namespace std ;

class nodo {
	int valor ;
	nodo * siguiente ;
	nodo *anterior ;
	public :
		nodo(int v, nodo *sgte=NULL, nodo* antes =NULL) : valor(v), siguiente(sgte), anterior(antes) {}
	friend class lista ;
};
class lista{
	nodo *primero, *ultimo, *aux ;
	public :
		lista(){primero=NULL; ultimo=NULL ;}
		void insertar(int v) ;
		void mostrar() ;

};

void lista::mostrar() {
	aux=primero ;
	do{
	    cout<<"->"<<aux->valor ;
	    aux=aux->siguiente ;
	}while(aux !=primero) ;
	cout<<endl ;
	aux=ultimo ;
	do{
	    cout<<"<- "<<aux->valor ;
	    aux=aux->anterior;
	}while(aux != ultimo ) ;
	cout<<endl ;
}

void lista::insertar(int v){
	if(primero && primero->valor < v){
        aux=primero ; // aux sera el anterior del nuevo nodo ;
		while(aux->siguiente != primero && aux->siguiente->valor <= v)
			aux=aux->siguiente ;
		aux->siguiente = new nodo(v, aux->siguiente, aux) ;
		if(aux==ultimo) ultimo=aux->siguiente ;
	/*	aux=aux->siguiente ;
		aux->siguiente->anterior= aux ;*/
   		  aux->siguiente->siguiente->anterior= aux->siguiente ; //alv :V
	}
	else {
		primero= new nodo(v, primero, ultimo) ;
		if(primero->anterior){
		    primero->siguiente->anterior = primero ; // ultimo->anterior=primero
		    ultimo->siguiente = primero ; //
		    cout<<"hola"<<primero->valor<<endl ;
			}
		else {// solo entra aqui en el caso q lista este vacia ;
		    cout<<primero->valor<<"else"<<endl ;
		    primero->anterior = primero ;
		    primero->siguiente= primero ;
		    ultimo = primero ;
		}
	}
}

int main() {
	lista lis ;
	lis.insertar(10) ;
	lis.insertar(20) ;
	lis.insertar(15) ;
	lis.insertar(30) ;
	lis.mostrar() ; cout<<endl ;
	lis.insertar(5) ;
	lis.insertar(50) ;
	lis.insertar(12) ;
	lis.mostrar() ;
	system("pause") ;
	return 0 ;

}
