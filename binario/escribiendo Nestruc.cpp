#include <stdio.h>
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
	if ((ar = fopen ("ad10.dat", "w")) != NULL){
	
	for(int i=0 ; i<4 ;i++){
	    printf("Matricula del alumno %d: ", i);
		scanf("%d", &alu[i].matricula);
		fflush(stdin);
		printf("Nombre del alumno %d: ", i);
		gets(alu[i].nombre);
		printf("Carrera del alumno %d: ", i);
		scanf("%d", &alu[i].carrera);
		printf("Promedio del alumno %d: ", i);
		scanf("%f", &alu[i].promedio);
		fflush(stdin);
		}
	fwrite(alu, sizeof(alumno), 3, ar) ;
}
	else
	printf("\nEl archivo no se puede abrir");
	fclose(ar);
	return 0;
	}
