#include <stdio.h>
#include <stdlib.h>

typedef struct { 
int matri;
char nom[20];
int carre;
float pro;
} alumn;

void lee(FILE *); 

int main()
{
FILE *ar;
if ((ar = fopen ("ad1.dat", "r")) != NULL)
lee(ar);
else
printf("\nEl archivo no se puede abrir");
fclose(ar);
system("pause") ;
return 0 ;
}
/*void lee(FILE *ap){
	alumn datos[3];
	fread(datos, sizeof(alumn), 3, ap);

	for(int i=0 ; i<3 ; i++){
    	printf("\nMatrícula: %d", datos[i].matri);
		printf("\tCarrera: %d", datos[i].carre);
		printf("\tPromedio: %f\t ", datos[i].pro);
		puts(datos[i].nom);
	}
}*/
void lee(FILE *ap){
	alumn al;
	fread(&al, sizeof(al.matri), 1, ap);

    	printf("\nMatrícula: %d", al.matri);
	//	printf("\tCarrera: %d", al.carre);
	//	printf("\tPromedio: %f\t ", al.pro);
	//	puts(al.nom);
}
