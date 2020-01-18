/*Problema PS6.3
Escribe un programa que intercambie las M filas de un arreglo bidimensional. Los
elementos de la primera fila se intercambian con los de la ultima fila, los del segundo
con los de la penultima, y asi sucesivamente.
Dato: MAT [M][N] (arreglo bidimensional de tipo real de M filas y N columnas,
1 . M . 50 y 1 . N . 50). */
#include <iostream>
#include <stdlib.h>
#include<conio.h>

using namespace std ;

//void pedirdatos(int**,int, int) ;
void pedirdatos(int, int) ;
void mostrar(int**, int, int) ;
void intercambia(int**, int, int) ;
int **matriz ;
int main(){
	int  /* **matriz */ nfila, ncol ;
	cout<<"ingres numero de filas:" ; cin>>nfila ;
	cout<<endl<<"ingrese numer de columnas:" ; cin>>ncol ; cout<<endl ;

//	pedirdatos(matriz, nfila, ncol) ; // se debe inicializar primero para enviar x parametros
    pedirdatos(nfila, ncol) ;     //seria como enviar un arreglo mxn vacion matriz[][]
	mostrar(matriz, nfila, ncol) ;
	intercambia(matriz, nfila, ncol);
	cout<<endl ;
	mostrar(matriz, nfila, ncol) ;

	for(int i=0 ; i<nfila ; i++){
	    delete[] matriz[i] ;}
	    
	delete[] matriz ;
	system("pause");
	return 0 ;

}
void mostrar(int **m, int f, int c){
	for(int i=0 ; i<f ; i++){
	    for(int j=0 ; j<c ; j++)
	        cout<<*(*(m+i)+j)<<"    " ;
	 cout<<endl ;
	 }
}
void intercambia(int **bidi, int f, int c){
	int final=f, i=0, aux ;
	while(i < f-1){
	   	 for(int j=0 ; j<c ; j++){
			aux= *(*(bidi+i)+j) ; //bidi[i][j]
			*(*(bidi+i)+j) = *(*(bidi+(f-1))+j)  ; //*(*(puntero_matriz1+i)+j)
			*(*(bidi+(f-1))+j) = aux ;
			}
		i++ ;
		f-- ;
	}

}
void pedirdatos(int f, int c){
	matriz = new int*[f] ;
	for(int i=0 ; i< f ; i++)
	    matriz[i]=new int[c] ;
	    
	for(int i=0 ; i<f ; i++)
	    for(int j=0 ; j<c ; j++)
			*(*(matriz+i)+j)=i+j ;
			/*
  	puntero_matriz1 = new int*[nFilas]; //Reservar memoria para las filas
	for(int i=0;i<nFilas;i++){
		puntero_matriz1[i] = new int[nCol]; //Reservar memoria para las columnas
	}*/

}
