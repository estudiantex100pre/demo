/*Problema PS7.1
Escribe un programa en C que, al recibir como dato una cadena de caracteres,
imprima todos los caracteres impares de la cadena.
Dato: cad[50] (donde cad representa la cadena de 50 caracteres como máximo).*/
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

using namespace std;
int c;
void imp(char*) ;
int cuenta(int, int) ;
int main(){
	char a[50] ;
	cout<<"ingrese la frase: " ;
	gets(a) ;
	c=strlen(a) ;
	imp(a) ;

	system("pause") ;
	return 0 ;
}
//13 hola 3 jose
void imp(char a[]){
	int pos=1;
//	cout<<"esto es a="<<*a<<endl ;
		if( *a != ' '){
			int x=atoi(a);
		//	cout<<"x="<<x<<endl;
			if(x){
	    		if(x%2 == 1)
	        		cout<<x<<endl ; //imprime cada impar de la cadena
				if(x>=10)
	        		pos +=cuenta(x,0) ;
				}
		}
	if( *a != '\0' )
        imp(a+pos) ;
/*	if( i<c-1)
	    imp(a+pos,i+1) ; */
}
int cuenta(int a, int i){
	if(a<10)
	    return i ;
	else
		cuenta(a/10, i+1) ;
}
