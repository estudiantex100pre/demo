/*Problema PS7.9
Escribe un programa en C que, al recibir como dato una cadena de caracteres,
imprima la cadena en forma inversa. Por ejemplo, si la cadena es la siguiente:
mundo del economía novena la es México
el programa debe imprimirla de esta forma:
México es la novena economía del mundo
Dato: cad[50] (donde cad representa la cadena de 50 caracteres como máximo). */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std ;
 // hola jesu s subero
void imprime(char*,int) ;
void rc(char *, int) ;
int x ;
int main() {
	char cad[50] ;
	cout<<"ingrese la frase: " ;
	gets(cad) ;
	x= strlen(cad) ;
	rc(cad,0) ;
/*	strcat(cad," ") ;
	for(int i=x-2 ; i>=0 ; i--)
	    if(cad[i]== ' ' || i==0)
			if(i==0 && cad[0] != ' ')
				imprime(cad, i) ;
			else{
	        	imprime(cad, i+1) ;
				while(cad[i-1] ==' ')
	       		 i--;}*/

		cout<<endl ;
	system("pause") ;
	return 0 ;
}

void imprime(char *a, int b){
	char t ;
	do{
        fflush(stdin);
        t=a[b] ;
	    putchar(t) ;
		b++ ;

	}while(a[b] != ' ') ;

	cout<<" " ;
                //reccursividad ocaciona impresion de elementos basura
}                                   //ni el flush evita el buffer
//	hola jesus subero
void rc(char cad[], int i){
	if(i != x )
	    rc(cad,i+1) ;
	if(cad[i]==' '){

	    imprime(cad,i+1) ;}
	if(i==0){

	    imprime(cad,i) ;}
}
