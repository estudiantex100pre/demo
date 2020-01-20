#include <iostream>
#include <stdlib.h>
using namespace std ;
class nodo {
	public:
		nodo(int v, nodo *sig = NULL): valor(v), siguiente(sig) { }
	private:
		int valor;
		nodo *siguiente;
	friend class cola;
};

class cola {
	public:
		cola() : ultimo(NULL), primero(NULL) {}
		~cola();
		void Anadir(int v);
		int Leer();
		void mostrar() ;
		
	private:
		nodo *primero, *ultimo, *aux;
};
void cola::mostrar() {
	aux=primero ;
	while(aux){
		cout<<"->"<<aux->valor ;
		aux=aux->siguiente;
	}
}

cola::~cola(){
	while(primero) Leer();
}

void cola::Anadir(int v){

	aux = new nodo(v);

	if(ultimo) ultimo->siguiente = aux;

	ultimo = aux;

	if(!primero) primero = aux;
}

int cola::Leer(){
	int v; /* variable auxiliar para retorno */

	aux = primero;
	if(!aux) return 0; /* Si no hay nodos en la pila retornamos 0 */
	
	primero = aux->siguiente;
	v = aux->valor;
	delete aux;
	if(!primero) ultimo = NULL;
	return v;
}

int main(){
	cola Cola;
	int opc ;
	do{
	cout<<endl<<"1. agrega un elemento a la cola"<<endl ;
		cout<<"2. elimina un elemento a la cola"<<endl ;
		cout<<"3. mostrar cola: "<<endl ;
		cout<<"4. salir: " ; cin>>opc ;
		cout<<endl ;
		switch (opc ) {
			case 1: cout<<endl<<"digite numero:"; cin>>opc ; Cola.Anadir(opc) ; break ;
			case 2: cout<<"eliminado numero: "<<Cola.Leer()<<endl ; break ;
			case 3: Cola.mostrar() ;
		}
	}while(opc != 4) ;

	system("PAUSE");
	return 0;
}
