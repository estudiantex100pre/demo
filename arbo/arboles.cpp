#include <iostream>
#include <stdlib.h>
using namespace std ;

struct nodo {
	int valor ;
	nodo *der ;
	nodo *izq ;
	nodo *padre ;
};

nodo* crear(int, nodo* ) ;
void insertar(nodo *&, int, nodo*) ;
void mostrar(nodo *) ;
void preorden(nodo* arb) ;
bool buscar(nodo*, int) ;

void eliminar_nodo(nodo *arb) ;
void eliminar(nodo *arb, int v);
nodo* cambiar(nodo* arb);

bool remplazar(nodo *arb, nodo* nuevo) ;
void destruir(nodo*) ;

int main() {
	nodo *arbol =NULL ;
	int opc, n ;
	do{
		cout<<endl<<"1. agregar nodo"<<endl ;
		cout<<"2. INnodo"<<endl ;
		cout<<"3. buscar"<<endl ;
		cout<<"4. eliminar"<<endl ;
		cout<<"5. salir " ; cin>>opc ; cout<<endl ;
		switch(opc){
			case 1: cout<<"ingrese numero:" ; cin>>n ; insertar(arbol,n, NULL) ; break ;
			case 2: mostrar(arbol) ; break ;
			case 3: cout<<"ingrese numero:" ; cin>>n ;
					if(buscar(arbol, n))
						cout<<n<<" encontrado"<<endl ;
					else
					    cout<<n<<" no existe"<<endl ;
					break ;
			case 4: cout<<"ingrese numero:" ; cin>>n ; eliminar(arbol,n) ; break ;
		}
	}while(opc != 5) ;
	system("pause") ;
	return 0 ;
}

void destruir(nodo* arb){
	arb->izq=NULL ;
	arb->der=NULL;
	arb->padre=NULL ;

	delete arb ;
}
 // no se puede imprimir valores de structura nula
bool remplazar(nodo *arb, nodo* nuevo){
	if(arb->padre){
      //  cout<<arb->padre->der->valor<<" "<<arb->valor<<endl ;
	    if((arb->padre->izq !=NULL)  && (arb->valor == arb->padre->izq->valor))
	        arb->padre->izq = nuevo ;
		else if(arb->valor == arb->padre->der->valor){ system("pause") ;
                arb->padre->der = nuevo ; cout<<"golfasa"<<endl;}
	}
	else {
			if(arb->der || arb->izq){
	    	    arb->valor= nuevo->valor;
	    	    arb->der = nuevo->der;
	    	    arb->izq = nuevo-> izq ;
				if(nuevo->der)
				    nuevo->der->padre=arb ; 
				if(nuevo->izq)
				    nuevo->izq->padre=arb ;

				destruir(nuevo) ;
			}
		else arb = NULL ;
		
		return false ;
		}

	if(nuevo)
	    nuevo->padre= arb->padre ;
	    
	return true ;
}

nodo* cambiar(nodo* arb){
	if(!arb)
	    return NULL ;
	if(arb->izq)
	    return cambiar(arb->izq) ;
	else
	    return arb ;
}
//
void eliminar_nodo(nodo *arb){
	if(arb->izq && arb->der){//solo elimina nodo hoja o padres de un nodo hoja
	    nodo* aux = cambiar(arb->der) ; // aux sera el valor q se cambiara a la posicion q queremos eliminar
	    system("pause") ;
	    arb->valor=aux->valor ; // tecnicamente cambiamos el/los valor(es) que quereremos aliminar
		cout<<aux->valor;
	    system("pause") ;
		eliminar_nodo(aux) ;
	}
	else if (arb->izq) {
		        if(remplazar(arb, arb->izq))
		        	destruir(arb) ;
		}
		else if(arb->der){
		       if( remplazar(arb, arb->der) )
		   			destruir(arb) ;
			}
			else{  // elimina la raiz y ocaciona error
			   if (remplazar(arb, NULL))
		   			destruir(arb) ;
			}
		    
}

void eliminar(nodo *arb, int v){ // esto es buscar ;
	if(!arb)
	    return ;
	else if(v < arb->valor)
			eliminar(arb->izq,v) ;
		else if(v > arb->valor)
		        eliminar(arb->der,v) ;
		    else
		        eliminar_nodo(arb) ;
}

bool buscar(nodo *arbol, int num) {
	if(!arbol)
	    return false ;
	else if(arbol->valor==num)
			return true ;
		 else
		    if(num < arbol->valor)
				return buscar(arbol->izq, num) ;
			else
				return buscar(arbol->der, num) ;

}

void preorden(nodo* arb){
	if(!arb) return ;
	else{
		cout<<" "<<arb->valor<<" " ;
		preorden(arb->izq) ;
		preorden(arb->der) ;
	}
}
void mostrar(nodo * arb) { //innodo
	if(!arb)return ;
	else {
		mostrar(arb->izq) ;  //    if(ban)
		cout<<" "<<arb->valor<<" " ;
		mostrar(arb->der) ;  // if(ban)
	}

}
nodo* crear(int v, nodo *pad){
	nodo *arb = new nodo ;  
	arb->valor = v ;
	arb->der = NULL ;
	arb->izq = NULL ;
	arb->padre=pad ;
	return arb ;
}

void insertar(nodo *&arb,int num, nodo * pad){
	if(!arb)
		arb = crear(num, pad );
	else{
		int valor_arbol = arb->valor ;
		if(num < valor_arbol)
		    insertar(arb->izq, num, arb) ;
		else
		    insertar(arb->der, num, arb) ;
	}
}
