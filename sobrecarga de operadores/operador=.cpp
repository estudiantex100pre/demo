#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std ;
class Cadena {
	public:
		Cadena(char *cad);
		Cadena() : cadena(NULL) {cout<<"construtor x defecto"<<endl ;};
	//	Cadena(const Cadena& obj) ;
		Cadena(const Cadena &c) : cadena(NULL) { *this = c; cout<<"constructor copia"<<endl ;}
		Cadena& operator=(const Cadena&) ; // es de tipo cadena solo x q e sposible igualden mas de dos objetos.


        Cadena operator+(const Cadena &);
        
		~Cadena() { cout<<cadena<<" destruido de la clase "<<this<<endl ;delete[] cadena;  system("pause"); };
		void Mostrar() const;
		void cambiar(char * cad) {
			delete [] cadena ;
			cadena = new char[strlen(cad)+1] ;
			strcpy(cadena, cad) ;
		}
	private:
		char *cadena;
};
/*Cadena::Cadena(const Cadena& obj){
	cadena = new char[strlen(obj.cadena)+1] ;
	strcpy(cadena,obj.cadena) ;
	cout<<"constructor copia"<<endl ;
}*/

Cadena Cadena::operator+(const Cadena &c)
{
	Cadena temp;
	cout<<&temp<<"   "<<&c<<endl ;
	temp.cadena = new char[strlen(c.cadena)+strlen(cadena)+1];
	strcpy(temp.cadena, cadena);
	strcat(temp.cadena, c.cadena);
	return temp; //deberia eliminarse temp a igual q sus atributos(cadena *).
	//como que el compilador sabe de esto y lo soluciona diria con un construtor copia bien definido.
}

Cadena &Cadena::operator=(const Cadena &c){
	system("pause") ;
	cout<<this<<"   "<<&c<<endl ;
	if(this != &c) { // this es una direccion
		puts(cadena) ;
		if(cadena) delete[] cadena ;
		if(c.cadena) {
			cadena = new char[strlen(c.cadena)+1];
			cout<<"ahora sera " ;puts(c.cadena) ;
			strcpy(cadena, c.cadena);
		}
		else{ cadena = new char[5] ; cadena="else";}
	}
	return *this; // el valor q tiene lad direccion this
	cout<<"coño e la madre"<<endl ;
}

Cadena::Cadena(char *cad){
	cadena = new char[strlen(cad)+1];
	strcpy(cadena, cad);
	cout<<"constructor parametrizado"<<endl ;
}

void Cadena::Mostrar() const{
	cout<<"la cadena es:"<<cadena<<endl;
}

int main(){
    Cadena C1 ;
    char* x="hola" ;
	Cadena C2(" primera parte"), C4("c4");  // C2=C1 (no entra en el operator=)o C2(C1) asi nunca se usa el constructor x defecto ; si no estan inizializazdos los obejtos;
//	C1 = C2 + " hola" ;	C1=C2+C4 ;
	C1= x ;
	C1.Mostrar() ;


	system("pause") ;
	return 0 ;
}
