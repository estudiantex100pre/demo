/*Problema PS9.5
Escribe un programa en C que, al recibir como dato un archivo de texto compuesto
por cadenas de caracteres, forme un nuevo archivo en el cual las cadenas aparezcan
intercambiadas: la última con la primera, la penúltima con la segunda, y
así sucesivamente.
Dato: arc.txt*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursivo(FILE *, FILE*) ;
void guarda(char [][50], char*) ;
int cont= 0 ;
int main(){
	FILE *ar, *arc ;
	if((ar=fopen("arc.txt", "r")) != NULL && (arc=fopen("arc2.txt", "w")) != NULL){
		recursivo(ar, arc) ;
	}else printf("nose pudo abrir achivo") ;
	system("pause") ;
	return 0 ;
}

void recursivo(FILE  *ar1 ,FILE *ar2){
	char b[50], aux[50][50] ;
	while(!feof(ar1)){
		fgets(b, 50, ar1);
		int j=0 ;
		while(j<50 ){
			if(b[j] != '\n' && b[j] != '\0'){
		    aux[cont][j] = b[j] ; j++ ;}
		    else {aux[cont][j] = '\0' ; j++ ;}

			}
	//	strcpy(aux[cont], b) ;
		cont++ ;
	}
	cont-- ;

	    
	while(cont >= 0){
		puts(aux[cont]) ;
		fputs(aux[cont], ar2) ;
		fputs("\n", ar2) ;
		cont-- ;}
		
	printf("%d", cont) ;
	
}
void guarda(char a[][50],char *b){
	strcpy(a[cont], b) ;
	puts(a[cont]) ;
}
