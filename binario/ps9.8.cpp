/*Problema PS9.8
Construye un programa en C que, al recibir como dato el archivo arc.dat que
contiene información sobre la matrícula y tres calificaciones de los alumnos de
una escuela, ordene ese archivo en forma ascendente considerando la matrícula
del alumno y genere un nuevo archivo arc1.dat. Cabe destacar que la matrícula
del alumno es un valor entero y las tres calificaciones son valores reales. Por
ejemplo, si el archivo se presenta de la siguiente forma:
arc.dat
51 8.7 6.7 8.9
15 7.8 7.6 5.8
11 7.8 9.0 9.9
32 8.8 9.9 9.7
96 8.9 9.1 9.9
29 9.3 9.6 9.8
después de la ordenación debe quedar de la siguiente forma:
arc1.dat
11 7.8 9.0 9.9
15 7.8 7.6 5.8
29 9.3 9.6 9.8
32 8.8 9.9 9.7
51 8.7 6.7 8.9
96 8.9 9.1 9.9
Dato: arc.dat */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int mat ;
	char nom[20] ;
	int carre ;
	int pro ;
} alum ;
void ordenar(FILE *, FILE*) ;

int main(){
    FILE *ar, *ar2 ;
	if((ar=fopen("ad1.dat", "r")) != NULL && (ar2=fopen("ad6new.dat", "w")) != NULL)
	    ordenar(ar , ar2) ;
	else printf("no se pudo abrir archivo ") ;
	system("pause") ;
	return 0 ;
}

void ordenar(FILE *ar, FILE *ar2){
	int t, x, j, aux ;
	fseek(ar, sizeof(alum), 2) ;
	t= sizeof(alum) ;
	x= (ftell(ar) / t) -1 ;
	int mp[2][x] ;  // 54 35 67 mat
	alum al ;      //  0  1  2 pos
	rewind(ar) ;
	for(int i=0 ; i< x ; i++) {
		fread(&al, sizeof(alum), 1, ar) ;
		mp[0][i]= al.mat ; //tomo todas la matriculas
		printf("matricula %d:(%d) \n", i+1, mp[0][i]) ;
	}
	mp[1][0] =0 ;
	for(int i=1 ; i<x ; i++){
		aux= mp[0][i] ;
		j= i-1 ;
		while(aux < mp[0][j] && j >= 0){ // guardo las posiciones de menor a mayor
			mp[0][j+1]= mp[0][j];
			mp[1][j+1]= mp[1][j];
			j-- ;
			}
		mp[0][j+1]= aux ;
		mp[1][j+1]= i ;
	}
	for(int i=0 ; i< x ; i++) {
		j=mp[1][i] ;
		printf("\nposicion=%d ", j) ;
		fseek(ar, (mp[1][i])*sizeof(alum), 0) ;
		fread(&al, sizeof(alum), 1, ar) ;
		fwrite(&al, sizeof(alum), 1, ar2) ;
	}

	
}
