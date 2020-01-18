/*Problema PS7.4
Construye un programa que, al recibir como dato una cadena de caracteres
que exprese una fecha en formato (dd/mm/aa), genere otra cadena con la misma
fecha pero con formato (dd de nombre del mes de aaaa). Por ejemplo, si la
fecha se ingresa de esta forma:
06/08/05
la nueva cadena debe indicar lo siguiente:

06 de Agosto de 2005
Dato: cad[30] (donde cad representa la cadena de 30 caracteres como máximo).*/
#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include <ctype.h>

using namespace std ;

char* formato(char*) ;



int main (){
	char cad[9], *j, *b;
	int x=0 ;
	cout<<"ingrese fecha: "<<endl ;
	gets(cad)  ; //tonteria validar fechare es facil ;V
	j=formato(cad) ;
	b=strstr(cad, "/") ;
	b=strstr(b+1, "/") ;
	x=atoi(b+1) ;
	if(x<=19)
	    x +=2000 ;
	else
	    x +=1900 ;
	cout<<cad[0]<<cad[1]<<" de "<<j<<" de "<<x<< endl ;
/*	a= "joula" ;
	cout<<a<<endl ;
	puts(a) ;¨*/
	
/*	a=strstr (cad , "/");
	x=atoi(a+1) ;          //a=/08/95
	cout<<a<<"  "<<x<<endl ;  //atoi=08
	cout<<cad<<endl ;*/
	system("pause") ;
	return 0 ;
}

char* formato (char *cad){
	int x ;
	char *a;
	a= strstr (cad , "/") ;
	switch (atoi(a+1)){
		case 1: a="enero" ; break ;
		case 2:(a="febrero") ; break ;
		case 3:(a= "Marzo") ; break ;
		case 4: (a= "Abril") ; break ;
		case 5: (a= "Mayo") ; break ;
		case 6: (a= "Junio") ; break ;
		case 7: (a= "Julio") ; break ;
		case 8: (a= "agosto") ; break ;
		case 9: (a= "Septiembre") ; break ;
		case 10: (a= "Octubre") ; break ;
		case 11: (a= "Noviembre") ; break ;
		case 12: (a= "Diciembre") ; break ;
		}
	return a ;
}

