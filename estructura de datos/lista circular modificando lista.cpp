#include <iostream>
#include <stdlib.h>
using namespace std ;

class lista ;

class nodo {
	public:
		nodo(int v, nodo *sig = NULL) : valor(v), siguiente(sig){}
	private:
		int valor;
		nodo *siguiente;
	friend class lista;
};

class lista {
	private :
	nodo *primero, *actual, *nuevo, *ultimo ;
	public:
		lista(){primero=NULL ; actual=NULL;}
		void insertar(int) ;
		void eliminar(int) ;
		bool listavacia() {return (primero == NULL) ;}
		void mostrar() ;
		~lista() ;
};
void lista::mostrar() {

	nuevo=primero ;
	ultimo->siguiente =NULL ; //(nuevo != NULL)
	while(nuevo != NULL){ //(nuevo->siguiente != primero)
	    cout<<"->"<<nuevo->valor ;
	    nuevo= nuevo->siguiente;
		}
	ultimo->siguiente=primero ;
}
lista::~lista() {

	ultimo->siguiente =NULL ;
	while(primero){
        nuevo=primero ;
		primero=primero->siguiente;
		delete nuevo ;}
		system("pause") ;
}
void lista::insertar(int numero) {
	int ban=0 ;
	if(listavacia() || primero->valor > numero){
		if(primero){
		primero = new nodo(numero, primero) ;
//		ultimo= primero->siguiente ; siempre se agregara de primero x ende no sera ultimo
		ultimo->siguiente=primero ;
		}
		else {
			primero = new nodo(numero) ; cout<<"hola"<<endl ;
	  	    primero->siguiente =primero ;
	  	    ultimo =primero ;
		}
	}

	else{
		actual = primero ;
		while( (actual->siguiente != primero) && actual->siguiente->valor <= numero)
			actual = actual->siguiente ;
		  if(actual->siguiente == primero){
	      	ban= 1;}
	    actual->siguiente = new nodo(numero, actual->siguiente) ;
			if (ban){
			    ultimo=actual->siguiente;
			    cout<<"ultimo valor="<<ultimo->valor<<endl ;ban =0;}
	}
	cout<<"numero:"<<numero<<" agregado"<<endl ;
}

void lista::eliminar(int numero) {
	nodo *anterior ;
	nuevo=primero ;
	if(listavacia())
		 cout<<"no hay nada en la lista bobo"<<endl ;
	else
	    if(nuevo->valor == numero){
			primero=primero->siguiente ;
			ultimo->siguiente=primero ; cout<<primero<<"  "<<ultimo->siguiente<<endl ;
			delete nuevo ;
			}
		else{
	  		while( (nuevo->siguiente != primero) && nuevo->siguiente->valor <= numero ){
				anterior =nuevo ;
	       		 nuevo= nuevo->siguiente ;
					}
			if(nuevo->valor == numero) {//se encontro el elemento en la lista
			    anterior->siguiente = nuevo->siguiente;
			    cout<<"anterior="<<anterior<<endl ;
			    if(nuevo == ultimo){ //(nuevo == ultimo
					ultimo = anterior ; cout<<"ultimo="<<anterior<<endl ;
					}
			    delete nuevo ;
			}
			else cout<<"idiota ese numero no existe"<<endl ;
		}
}

int main(){
	lista lis;
	int opc ;
	do{
		cout<<endl<<endl<<"1- agragar numero a la lista"<<endl ;
		cout<<"2- quitar un elemento de la lista"<<endl ;
		cout<<"3- mostrar los elemento de la lista"<<endl ;
		cout<<"4- salir ;" ; cin>>opc ; cout<<endl ;
		switch(opc){
			case 1: cout<<"ingrese numero:" ; cin>>opc ; lis.insertar(opc) ; break ;
			case 2: cout<<"ingrese numero:" ; cin>>opc ; lis.eliminar(opc) ; break ;
			case 3: cout<<endl ; lis.mostrar() ;
		}
	}while(opc != 4) ;
	system("PAUSE");
	return 0;
}
