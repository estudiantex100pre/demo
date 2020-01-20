#include <iostream>
#include <stdlib.h>
using namespace std ;

 struct nodo {
	int valor ;
	nodo* siguiente ;
	nodo* anterior ;
};

int insertar(nodo *&, int) ;
void mostrar(nodo *&) ;
void borrar(nodo*&, int) ;

int main() {
	nodo *lista =NULL ;
	insertar(lista, 10) ;
	insertar(lista, 20) ;
	insertar(lista, 30) ;
	insertar(lista, 45) ;
	insertar(lista, 5) ;
	insertar(lista, 12) ;
	mostrar(lista) ;
	borrar(lista, 30) ;
	mostrar(lista) ;
	borrar(lista, 20) ;
	borrar(lista, 10) ;
	borrar(lista, 3) ;
	mostrar(lista) ;
	system("pause") ;
	return 0 ;
}

void mostrar(nodo *& lista) {
	nodo *aux=lista ;
	nodo *aux2 ;
	while(aux){
		cout<<"->"<<aux->valor ;
		if(aux->siguiente==NULL)
			aux2=aux ;
		aux=aux->siguiente ;
	}
	cout<<endl ;
	while(aux2) {
		cout<<"<- "<<aux2->valor ;
		aux2=aux2->anterior ;
	}cout<<endl ;
}

int insertar(nodo *&lista, int v) {
	nodo *nuevo = new nodo ;
	nuevo->valor = v ;
	if(!lista  || lista->valor > v){//esta vacia o se posicionara el nuevo valor de primero xser menor ;
       	nuevo->siguiente = lista;
		nuevo->anterior= NULL ;
		if(lista) lista->anterior = nuevo ;
		lista=nuevo ;

	}
	else{ 
		nodo *actual ; //lista = primero ; //actual hace lade anterior ;
		actual= lista ;
		while(actual->siguiente && actual->siguiente->valor <= v ){
			actual=actual->siguiente ;
		}
		nuevo->siguiente = actual->siguiente ;
		actual->siguiente=nuevo ;
		nuevo->anterior = actual ;
        if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo ;
	}
}

void borrar(nodo *& lista, int v) {
	nodo *aux=lista ;
	nodo* ante ;
	if(aux){
		if(lista->valor == v) {// se elimina lista q es primer elemenot
		    lista=lista->siguiente ;
		    lista->anterior=NULL ;
		}
		else
		    while(aux->siguiente && aux->siguiente->valor <=v){
		    	ante=aux ;
		        aux=aux->siguiente ;
			}
			if(aux->valor==v) {// se encontro el valor en la lista ;
				ante->siguiente = aux->siguiente ;
			    if(aux->siguiente)
				    aux->siguiente->anterior= ante ;
			    cout<<aux->valor<<". sera eliminado"<<endl ;
				}
			else
			    cout<<"numero no existe en la lista:"<<v<<endl ;
			    
			    
	}else cout<<"lista esta vacia"<<endl ;
}
