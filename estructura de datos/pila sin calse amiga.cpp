#include <iostream>
#include <stdlib.h>
using namespace std ;

class pila{
	class nodo{
		public:
		int valor;
		nodo *sgte ;
			nodo(int v, nodo* s) : valor(v), sgte(s){cout<<"constructor anidado"<<endl;} ;
	};
	nodo *ultimo ;
	public:
		pila() {ultimo=NULL; cout<<"hola"<<endl;}
		void poner(int ) ;
		int quitar() ;
		void mostrar() ;
		~pila();
};

void pila:: mostrar() {
	nodo* aux = ultimo ;
	while(aux){
	    cout<<aux->valor<<endl ;
	    aux=aux->sgte;
	}
	cout<<endl<<endl ;
}

void pila::poner(int n){
	ultimo=new nodo(n,ultimo) ;
}
int pila::quitar(){
	int n;
	if(!ultimo) { cout<<"no hay elementos en la pila"<<endl;
	    return 0 ;
	}
	nodo * aux= ultimo ;
	n=aux->valor ;
	ultimo = ultimo->sgte ;
	delete aux ;
	return n ;
}
pila::~pila(){
	while(ultimo)
	    quitar() ;
}

int main() {
	pila pil ;
	pil.poner(2);
	pil.poner(4);
	pil.poner(6) ;
	pil.mostrar() ;
	cout<<"borrando"<<pil.quitar()<<endl ;
	cout<<"borrando"<<pil.quitar()<<endl ;
	cout<<"borrando"<<pil.quitar()<<endl ; cout<<endl ;
	pil.poner(10) ;
	pil.poner(20) ;
	pil.mostrar() ;

	pil.mostrar() ;
	system("pause") ;
	return 0 ;
}
