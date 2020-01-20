/*Problema PS 9.7
Escribe un programa en C que, al recibir como dato el archivo de acceso directo
ad5.dat que contiene los registros de los alumnos de una escuela —algunos están

repetidos— ordenados de mayor a menor en función de su matrícula, genere un
nuevo archivo pero sin registros repetidos. Los campos de las estructuras almacenadas
en el archivo son los siguientes:
• Matrícula del alumno (entero).
• Nombre del alumno (cadena de caracteres).
• Carrera en la que está inscrito (entero).
• Promedio del alumno (real).
Dato: ad5.dat */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int mat ;
	char nom[20] ;
	int carre ;
	int pro ;
} alum ;
void repetidos(FILE*, FILE*) ;

int main () {
	FILE *ar, *ar2 ;
	if((ar=fopen("ad1.dat", "r")) != NULL && (ar2=fopen("ad5new.dat", "w")) != NULL)
	    repetidos(ar , ar2) ;
	else printf("no se pudo abrir archivo ") ;
	system("pause") ;
	return 0 ;
}
/*0 5456 ---- x   5459
  1 5456 ----     5459
  
  2 5455 ---      5457
  3 5355 ---      5456
  4 5211          5455 */
void repetidos(FILE *ar, FILE *ar2 ) {
	int x, t, bloque, mat1, mat2 ;
	alum al ;
	fseek(ar, sizeof(alum), 2) ;
	bloque=sizeof(alum) ;
	t=ftell(ar) ;
	x= (t/bloque)-1 ; //cantidad de bloques
	rewind(ar);
	fread(&al, sizeof(alum), 1, ar) ;
	for(int i=0 ; i< x ; i++){
		fwrite(&al, sizeof(alum), 1, ar2 ) ;
		mat1=al.mat;
		fread(&al, sizeof(alum), 1, ar) ;
		mat2=al.mat ;
		
		while(mat2 == mat1 && (i != x-1)){
		    fread(&al, sizeof(alum), 1, ar) ;
		    mat2=al.mat ;
		    i++ ;
		}
	}
}
