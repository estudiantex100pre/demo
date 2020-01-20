#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std ;

template <class T>
class Tabla {
	public:
		Tabla(int nElem);
		~Tabla();
		T& operator[](int indice) { cout<<&pT[indice]<<endl ;return pT[indice]; } // &pT[0], return &pT[0];
	private:
		T *pT;
		int nElementos;
};
// Definición:
template <class T>
Tabla<T>::Tabla(int nElem) : nElementos(nElem) {
	pT = new T[nElementos]; system("pause") ;//aqui no se usa el opertaor ;
	//en caso de tipo cadena sera *pt = new T[nElementos]
//en caso de T sea de tipo char*	**pT=new T*[nElementos]
}

template <class T>
Tabla<T>::~Tabla() {
	cout<<"<zzzzzz<zzz<<"<<endl ;
	delete[] pT;
	cout<<"destructor tabla"<<endl ;
	system("pause") ;
}

class Cadena {
	public:
		Cadena(char *cad) {
			cadena = new char[strlen(cad)+1];
			strcpy(cadena, cad);
			cout<<"consturctor parametrizado"<<this<<endl ;
		}
		Cadena() : cadena(NULL) {cout<<"hola"<<endl ;}
		Cadena(const Cadena &c) : cadena(NULL) {*this = c;}
		
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
			return *this;
		}
		
		const char* Lee() const {return cadena;}
	private:
		char *cadena;
};

/*ostream& operator<<(ostream &os, const Cadena& cad){
	os << cad.Lee();
	return os;
}*/

int main(){
    const int ELEMENTOS=3;
    Tabla<Cadena> TablaCad(ELEMENTOS);
	char cadena[20];
		
	for(int i = 0; i < ELEMENTOS; i++) {
		sprintf(cadena, "Numero: %5d", i);
		TablaCad[i] = cadena; //Cadena(cadena) objeto temporal  *pT= Cadena(cadena)
	}
	strcpy(cadena, "Modificada");
	for(int i = 0; i < ELEMENTOS; i++)
		cout << "TablaCad[" << i << "] = " << TablaCad[i].Lee() << endl; //TablaCad[i].Lee() de pros :V

	system("pause") ;
	return 0 ;
}
