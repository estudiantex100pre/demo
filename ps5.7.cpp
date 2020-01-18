#include <iostream>
#include <stdlib.h>
using namespace std ;
/*Problema PS5.7
En un arreglo unidimensional de tipo real se tienen almacenadas las toneladas
mensuales de cereales cosechadas durante el año anterior en una estancia de la
pampa Argentina. Escribe un programa que calcule e imprima lo siguiente:
a) El promedio anual de toneladas cosechadas.
b) ¿Cuántos meses tuvieron una cosecha superior al promedio anual?
c) ¿En qué mes se produjo el mayor número de toneladas? ¿Cuántas fueron?
Dato: COS[12] (arreglo unidimensional de tipo real de 12 elementos). */
float promedio(float *, int) ;
int cosecha (float *, int, float*) ;
float mayorc (float* , int) ;
void leerdatos (float *, int) ;

int main() {
	float pro ;
	float a[12] ;
	leerdatos(a,12) ;
	pro=promedio(a,12) ;
	cout<<"el promedio de la toneladas cosechadas es; "<<pro<<endl ;
	cout<<"la cantidad de meses mayores al promedio anual son:"<<cosecha(a, 12, &pro)<<endl ;
	cout<<mayorc(a,12) ;
	
	system("pause") ;
	return 1 ;
	
}
float mayorc (float a[], int n) {
	int m=0, mes ;
	for(int i=0 ; i<n ; i++)
	    if(a[i]> m){
	    	m=a[i] ;
	    	mes=i ;
			}
  cout<<"en el mes "<<mes+1<<" se produjo la mayor cantidad de toneladas con:" ;
  return m ;
}
int cosecha (float *a, int b, float *c) {
	int cont=0 ;
	for(int i=0; i<b ; i++)
	    if( a[i] > *c )
	    	cont ++ ;
	return cont ;
}
float promedio(float *a, int b) {
	float sum=0.0 ;
	for(int i=0 ; i<b ; i++)
	    sum += a[i] ;
	return sum/b ;
}
void leerdatos(float *a, int b) {
	for(int i=0; i<b ; i++){
		cout<<"mes "<<i+1<<" ingrese las toneladas cosechada: " ;
		cin>> *a++ ;
	}
}
