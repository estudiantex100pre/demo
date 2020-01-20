#include <iostream>
#include <stdlib.h>
using namespace std ;
 struct nodo{
	int dato ;
	nodo *sgte ;
} ;

void setcola(nodo* &frt, nodo* &fin, int ) ;
bool vacia(nodo* & frt) ;

int killcola(nodo* &frt, nodo* &fin) ;
void mostrar(nodo* &frt, nodo* & fin) ;

void agrega (nodo* &frt, nodo* & fin) ;
int elimina (nodo* &frt, nodo* & fin) ;

int main(){
	nodo* frente=NULL ;
	nodo* fin=NULL ;
	int x, res ;
	do{
		cout<<"ingrese dato:"; cin>>x ;
		setcola(frente, fin, x) ;
		cout<<"va a poner otro numero a la cola? " ; cin>>res ;
	}while(res) ;
	
	do{
		cout<<endl<<"1. agrega un elemento a la cola"<<endl ;
		cout<<"2. elimina un elemento a la cola"<<endl ;
		cout<<"3. mostrar cola: "<<endl ;
		cout<<"4. salir: " ;
		cin>>res ;
		cout<<endl ;
		switch(res){
			case 1: agrega(frente, fin) ; break ;
			case 2: if(frente !=NULL)
						cout<<killcola(frente, fin)<<" eliminado."<<endl ;
					else
					    cout<<"bobo ya no hay elementos q eliminar"<<endl ;

					break ;

			case 3: mostrar(frente, fin) ; break ;
			case 4: res=0 ; break ;
		}
	}while (res) ;

	system("pause");
	return 0 ;
}

void setcola(nodo* &frt, nodo* &fin, int num) {
	nodo *nuevo= new nodo ;
	nuevo->dato=num ;
	nuevo->sgte=NULL ;
	if(vacia(frt))
	    frt = nuevo ;
	else
		fin->sgte=nuevo ;
	fin=nuevo ;
}

bool vacia(nodo* &frt) {
	if(frt==NULL)
	    return true ;
	else
	    return false ;

}
int killcola(nodo* &frt, nodo* &fin) {
	int num=frt->dato ;
	nodo *aux=frt ;
	if(frt==fin)
	    fin=frt=NULL ;
	else
	    frt=frt->sgte ;
	delete aux ;
	return num ;
}
void mostrar(nodo* &frt, nodo* & fin){
	nodo* auxfrt=frt ;
	nodo* auxfin=frt ;
   	while(auxfrt != NULL){
		if(auxfrt != fin)
			cout<<auxfrt->dato<<", " ;
		else
		    cout<<auxfrt->dato<<"." ;
		auxfrt=auxfrt->sgte ;
	}
}

void agrega (nodo* &frt, nodo* & fin){
	int x;
	cout<<endl<<"ingrese numero:" ; cin>>x ;
	setcola(frt, fin, x) ;
}
int elimina (nodo* &frt, nodo* & fin){
	int num ;
	num=frt->dato ;
	nodo* nuevo = frt ;
		if(frt==fin)
	  	  fin=frt=NULL ;
		else
	    	frt=frt->sgte ;
	delete nuevo ;
	return num ;
}



