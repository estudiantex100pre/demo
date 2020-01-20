#include <stdio.h>
#include <stdlib.h>
/* Ordena de menor a mayor.
El programa ordena de menor a mayor en función de la matrícula, creando un
.nuevo archivo, un archivo de acceso directo compuesto por estructuras y
.ordenado de mayor a menor. */
typedef struct /* Declaración de la estructura alumno. */
{
int matricula;
char nombre[20];
int carrera;
float promedio;
} alumno;

void ordena(FILE *, FILE *); /* Prototipo de función. */

int main()
{
FILE *ar1, *ar2;
ar1 = fopen("ad1.dat", "r");
ar2 = fopen("ad6.dat", "w");
if ((ar1 != NULL) && (ar2 != NULL))
ordena(ar1, ar2);
else
printf("\nEl o los archivos no se pudieron abrir");
fclose(ar1);
fclose(ar2);
system("pause") ;
return 0 ;
}

void ordena(FILE *ap1, FILE *ap2)
/* Esta función ordena de menor a mayor un archivo compuesto por estructuras,
.en función de su matrícula, y genera un nuevo archivo. */
{
alumno alu;
int t, n, i, tam;
t = sizeof(alumno);
fseek (ap1, sizeof(alumno), 2);
tam= ftell(ap1) ; //96
n = (tam / t) -1 ; //96/ 32 -1 = 2
printf(" (%d/%d)  -1=%d ",tam, t, n) ;
/* Se obtiene el número de registros que componen el archivo. El valor de n,
.a su vez, se utilizará para posicionarnos en el archivo. */
rewind(ap1);
for (i = (n-1); i >= 0; i--) // Se utiliza un ciclo descendente.
{
	printf("\n %d", i) ; // i=2-1=1 ;
fseek(ap1, i * sizeof(alumno), 0);
fread(&alu, sizeof(alumno), 1, ap1);
fwrite(&alu, sizeof(alumno), 1, ap2);
}
/*for (int i=1 ; i<=n ; i++){
    printf("\n %d", i) ; // i=2-1=1
    fseek(ap1, i * -sizeof(alumno), 2);
	fread(&alu, sizeof(alumno), 1, ap1);
	fwrite(&alu, sizeof(alumno), 1, ap2);
}*/
}
