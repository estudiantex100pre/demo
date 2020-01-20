#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);

int main(){
	Nodo *lista=NULL ;
	int res ;
	do{
		cout<<"ingrese numero" ; cin>> res ;
		insertarLista(lista, res) ;
	}while(res) ;
		mostrarLista(lista) ;
	system("pause") ;
	return 0 ;
}

void insertarLista(Nodo *&lista,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;

	Nodo *aux1= lista ; // agarra la direcion q tiene lista q es la lista de main.
	Nodo *aux2 ;
	cout<<&aux1<<"="<<lista<<endl ;
	while((aux1 != NULL) && (aux1->dato < n) ){
		aux2=aux1 ;
		aux1= aux1->siguiente ;
	}
	
	if(lista == aux1){//Si la lista esta vacia
	
		lista = nuevo_nodo;//agregamos el primer nodo. ahota lista no apunta al null del main sino al nuevo nodo
		cout<<lista<<"."<<aux1<<endl ;
	
	}
	else{
			aux2->siguiente= nuevo_nodo ;
			cout<<"en else. lista:"<<lista->siguiente<<"="<<aux2->siguiente<<endl ;
		}
		
	nuevo_nodo->siguiente = aux1 ;//agregamos el nuevo nodo al final de la lista
	cout<<"aux1="<<aux1<<". "<<lista->siguiente<<endl ;
	cout<<"\tElemento "<<n<<" agregado a lista correctamente\n";
}

void mostrarLista(Nodo *lista){
	Nodo *actual ;
	actual = lista;
	while(actual != NULL){ //mientras no sea final de la lista
		cout<<actual->dato<<" -> "; //mostramos el dato
		actual = actual->siguiente; //avanzamos a la siguiente posicion de la lista
	}
}
