#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std ;

template<class T>
class pila{
	template <class tn>
	class nodo{
		public:
		tn *valor;
		nodo<tn> *sgte ;
			nodo(tn& v, nodo<tn>* s) : sgte(s){valor= new tn(v); cout<<"constructor anidado"<<endl;} ;
        ~nodo() {cout<<"destructor nodo"<<endl ;delete valor ;}
	};
	
	nodo<T> *ultimo ;
	public:
		pila() {ultimo=NULL; cout<<"hola"<<endl;}
		void poner(T&) ;
		T quitar() ;
		void mostrar() ;
		void mostrarcad() ;
		~pila();
};
template<class T>
void pila<T>:: mostrarcad() {
    nodo<T>* aux = ultimo ;
	while(aux){
	    cout<<aux->valor->Lee()<<endl ;
	    aux=aux->sgte;
	}
}

template<class T>
void pila<T>:: mostrar() {
	nodo<T>* aux = ultimo ;
	if(aux->valor->Lee()) mostrarcad() ;
	while(aux){
	    cout<<*aux->valor<<endl ;
	    aux=aux->sgte;
	}
	cout<<endl<<endl ;
}
template<class T>
void pila<T>::poner(T& n){ 
	ultimo=new nodo<T>(n,ultimo) ; 
}
template<class T>
T pila<T>::quitar(){
	T n(*ultimo->valor);

	if(!ultimo) { cout<<"no hay elementos en la pila"<<endl;
	    return 0 ;
	}
	cout<<endl<<endl ;
	nodo<T> *aux= ultimo ; system("pause") ;
//	n=*aux->valor ; // n=*valor  cadena n = cadena valor
	ultimo = ultimo->sgte ;system("pause") ;
	delete aux ;
	return n ;
}
template<class T>
pila<T>::~pila(){
	while(ultimo)
	    quitar() ;
	system("pause") ; cout<<"se fue destructor pila"<<endl ;
}

template<class T>
void ingresar(pila<T> &pilachar) {
    char x[]="77" ;
    char y[]="adios" ;
    char z[]="muerto" ; 
	pilachar.poner(x) ;
	pilachar.poner(y) ;
    pilachar.poner(z) ;         //T es de tipo dato char* y nodeja crear una variable de tipo char*

}

class Cadena {
	public:
		Cadena(char *cad) {
			cadena = new char[strlen(cad)+1];
			strcpy(cadena, cad);
			cout<<"consturctor parametrizado"<<this<<endl ;
		}
		Cadena() : cadena(NULL) {cout<<"hola"<<endl ;}
		Cadena(const Cadena &c) //: cadena(NULL) {cout<<"constructor copia de Cadena"<<endl ;*this = c; cout<<"mrda"<<endl;}
{
	cadena = new char[strlen(c.cadena)+1] ;
	strcpy(cadena,c.cadena) ;
	cout<<"constructor copia de cadena"<<endl ;
}

		~Cadena() { if(cadena){ puts(cadena); cout<<this<<"chao"<<endl;  delete[] cadena;} system("pause") ; }

		Cadena &operator=(const Cadena &c) {
			cout<<this<<"  "<<&c<<endl ;
			if(this != &c) {
				if(cadena) delete[] cadena;
				if(c.cadena) {
					cadena = new char[strlen(c.cadena)+1];
					strcpy(cadena, c.cadena);
				}
				else cadena = NULL;
				}
			cout<<"q cha jago aqui"<<endl ;
			return *this;
		}

		const char* Lee() const {return cadena;}
	private:
		char *cadena;
};

int main() {
//	pila<char*> pilachar ;
	char cadxx[]="Cadena X", cadyy[]="Cadena Y ----";

	pila<Cadena> pilacadena ;
	    Cadena cadx(cadxx);
	Cadena cady(cadyy);
	pila<int> pilaint ; int x(2);
	pilaint.poner(x) ;x++ ;
    pilaint.poner(x) ;x++ ;
    pilaint.poner(x) ;
	pilaint.mostrar() ;
	pilacadena.poner(cadx) ;  //Cadena(hola mi pana)
	pilacadena.poner(cady) ;
    pilacadena.mostrar() ;

	system("pause") ; cout<<"se fue main"<<endl ;
	return 0 ;
}
