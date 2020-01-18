/*Problema PS7.11
Escribe un programa en C que, al recibir como dato un arreglo unidimensional
de cadenas de caracteres, imprima la cadena que tiene el mayor número
de vocales.
Dato: ARC[10][50] (donde ARC representa un arreglo de cadena de caracteres de
10 filas y cada cadena puede tener 50 caracteres como máximo). */
#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<string>
#include <stdio.h>
using namespace std ;

int cuenta(char*) ;

int main() {
	char arc[10][50], cad[50] ;
	int t, x,mayor=0, pos;
	cout<<"cuantas palabras vas a poner: " ; cin>>t ;
	for(int i=0 ; i<t ; i++)	{
		cout<<i+1<<": " ;
		fflush(stdin);
		gets(arc[i]) ;
		}
	for(int i=0 ; i<t ;i++){
	    strcpy(cad, *arc) ;
		x= cuenta(cad) ;
	    if(x>mayor)
	        mayor=x ;
	        pos=i ;
		}
	system("pause") ;
	return 0 ;
}

int cuenta(char *cad){
	int i=0 ;
	while(cad[i] != '\0')
	    if(isalpha(cad[i]))
	        i++ ;
}
