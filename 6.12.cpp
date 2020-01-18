/*En la Federación Mexicana de Fútbol se lleva información sobre el número de
asistentes mensuales en los diez estadios más importantes del país durante los últimos
cinco años. Construye un programa que genere la siguiente información:
250 Capítulo 6. Arreglos multidimensionales
a) El número de asistentes del último año en cada estadio, ordenados de
mayor a menor.
b) Los estadios que tuvieron la mayor y menor afluencia de público en los
últimos cinco años, junto con el número de asistentes.
c) El mes del último año en que cada estadio tuvo la mayor afluencia de
público, junto con el número de asistentes.
Dato: FUT[7][12][5] (arreglo tridimensional de tipo entero que contiene información
sobre asistentes a los estadios de fútbol más importantes del país).*/
#include <iostream>
#include <stdlib.h>
using namespace std ;

void leerdatos(int [10][12][5]) ;
void f1(int[][12][5]);
void prueba(int [][12][5]);

int ano=5, mes=12, est=10 ;

int main(){
	int a[10][12][5] ;
	cout<<"ingrese la asistencia mensuales "<<endl ;
//	leerdatos(a) ;
	prueba(a) ;
	f1(a) ;
	system("pause") ;
	return 0 ;
}
void f1(int a[10][12][5]){
	int sum[10]= {0}, posicion[10]={0,1,2,3,4,5,6,7,8,9} ;
	for(int i=0 ; i<est ; i++){
	    for(int j=0 ; j<mes ; j++)
	        sum[i] += a[i][j][ano-1] ;
	        cout<<sum[i]<<" " ;
	}
	int j=0, aux ;
	for(int i=1; i<est ; i++){
	    aux=sum[i] ;
	    j=i-1 ;
	    while(aux>sum[j] && j>=0){
	   		 posicion[j+1] =posicion[j] ;
	   		 j-- ;
			}
		posicion[j+1]=i ;
	}
	for(int i=0; i<est ; i++)
	    cout<<posicion[i]<<"--estadio la asistencia en el ultimo año fue:"<<sum[posicion[i]]<<endl ;
}
void leerdatos(int a[][12][5]){
	for(int k=0; k<ano ; k++)
	    for(int i=0; i<est ; i++)
	        for(int j=0; j<mes ; j++){
				cout<<"a["<<i+1<<"]["<<j+1<<"]["<<k+1<<"]" ;
				cin>>a[i][j][k] ;
			}
}
/*void prueba(int a[10][12][5]){
	for(int k=4; k<ano ; k++)
	    for(int i=0; i<est ; i++)
	        for(int j=0; j<mes ; j++){
				a[i][j][k]= i+1 ;
				if(i%2==0)
				    a[i][j][k]+= i+j ;}

}*/
