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
	nodo *primero, *actual, *nuevo ;
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
	while(nuevo){
	    cout<<"->"<<nuevo->valor ;
	    nuevo= nuevo->siguiente;
		}
}
lista::~lista() {
	while(primero){
        nuevo=primero ;
		primero=primero->siguiente;
		delete nuevo ;}
}
void lista::insertar(int numero) {

	if(listavacia() || primero->valor > numero){
		primero = new nodo(numero) ; cout<<"hola"<<endl ;
		
		}

	else{
		actual = primero ;
		while( (actual->siguiente) && actual->siguiente->valor <= numero)
			actual = actual->siguiente ;

	    actual->siguiente = new nodo(numero, actual->siguiente) ;
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
			delete nuevo ;
			}
		else{
	  		while( (nuevo->siguiente) && nuevo->siguiente->valor <= numero ){
				anterior =nuevo ;
	       		 nuevo= nuevo->siguiente ;
					}
			if(nuevo->valor == numero) {//se encontro el elemento en la lista
			    anterior->siguiente = nuevo->siguiente;
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
