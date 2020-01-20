#include <stdio.h>
#include <stdlib.h>
typedef struct /* Declaración de la estructura alumno. */
{
int matricula;
char nombre[20];
int carrera;
float promedio;
}alumno;

int main()
	{FILE *ar;
	alumno alu[5] ;
	if ((ar = fopen ("ad10.dat", "r")) != NULL){
         rewind(ar) ;
    fread(alu, sizeof(alumno), 3, ar) ;

	for(int i=0 ; i<4 ;i++){
	    printf("\nMatricula del alumno %d: ", i);
		printf("%d", &alu[i].matricula);
		fflush(stdin);
		printf("Nombre del alumno %d: ", i);
		puts(alu[i].nombre);
		printf("Carrera del alumno %d: ", i);
		printf("%d", &alu[i].carrera);
		printf("Promedio del alumno %d: ", i);
		printf("%f \n", &alu[i].promedio);
		fflush(stdin);
		}
}
	else
	printf("\nEl archivo no se puede abrir");
	fclose(ar);
	system("pause") ;
	return 0;
	}
