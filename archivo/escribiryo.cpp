#include <stdio.h>
#include<iostream>
#include <stdlib.h>
using namespace std ;
void escribir(FILE *) ;
int main () {
	FILE *ar ;
	ar= fopen("datos.txt", "w") ;
	if(ar != NULL){
	escribir(ar) ;
	}else
	cout<<"no se pudo abrir achivo"<<endl ;
	system("pause") ;
	return 0 ;
}
void escribir (FILE *arc){
	int alumnos, cali, matricula  ;
	char nombre[20] ;
	float pro ;
	cout<<"cuantos alumnos va registrar"<<endl ;
	cin>>alumnos ;
	fprintf (arc, "%d\n", alumnos) ;
	for(int j=0 ; j<alumnos ; j++){
        pro=0.0 ;
        fflush(stdin);
	/*	cout<<"ingrese nombre del estudiante "<<j+1<<":" ;
		gets(nombre) ;
		fputs(nombre, arc) ;*/
		for(int i=0 ; i<alumnos ; i++){
			cout<<"ingrese nota "<< i+1<<":" ;
			cin>>cali ;
			fprintf(arc, "%d ", cali) ;
			pro +=cali ;
		}
		fprintf(arc, "%.2f\n", pro/alumnos ) ;
	}
}
