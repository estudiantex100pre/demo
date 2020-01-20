/*Problema PS9.3
Escribe un programa en C que, al recibir como dato un archivo de texto compuesto
por cadenas de caracteres, determine cuántas palabras hay en el archivo. Cada
palabra se separa por medio de un espacio en blanco. Por ejemplo, si el archivo es
el siguiente:
sa sa sa yacusá yacusá
le mando le mando le mando al maestro
El programa debe escribir que hay 13 palabras.
Dato: arc.txt*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void palabras(FILE *) ;

int main() {
	FILE *ar ;
	if ( (ar=fopen("arc34.txt", "r")) != NULL){
	palabras(ar) ;
	}
	else
		printf("no se pudo abrir archivo") ;
		
	system("pause") ;
	return 0;
}//hola-quetal-d
void palabras (FILE *ap){
	char cad[50], *cad1;
	int cont =0, i ;
	while(!feof(ap)){
		fgets(cad, 50, ap) ;
		strcat(cad," ") ;
		cad1= strstr(cad," ") ;
		puts(cad1) ;
		while(cad1 != NULL){
		    cont++ ;
			i=1 ;
			while(cad1[i]== ' ')
		    	i++ ;
		    cad1=strstr(cad1+i, " ") ;
		}
	}
	printf("hay %d palabras", cont) ;
}
