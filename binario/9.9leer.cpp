#include <stdio.h>
#include <stdlib.h>
/* Alumnos.
El programa lee bloques —variables de tipo estructura alumno— de un archivo
.de acceso directo. */
typedef struct { /* Declaración de la estructura alumno. */
int matri;
char nom[20];
int carre;
float pro;
} alumn;

void lee(FILE *); /* Prototipo de función. */

int main()
{
FILE *ar;
if ((ar = fopen ("productos.dat", "r")) != NULL)
lee(ar);
else
printf("\nEl archivo no se puede abrir");
fclose(ar);
system("pause") ;
return 0 ;
}
void lee(FILE *ap)
/* Esta función se utiliza para leer bloques de un archivo de acceso directo. */
{
alumn al;
int t=sizeof(alumn), i, z ;
fread(&al, sizeof(alumn), 1, ap);
/* Observa que la función fread tiene los mismos argumentos que la función
.fwrite del programa anterior. También es importante tomar nota de que cuando
.tenemos que leer los registros de un archivo utilizando una estructura
.repetitiva como el while, debemos realizar una primera lectura antes de
.ingresar al ciclo y luego las siguientes dentro del ciclo, pero como última
.instrucción del mismo. Esto se debe a que la lógica que siguen las
.instrucciones fwrite y fread es moverse y leer o escribir, según sea el caso.
.Si no lo hiciéramos de esta forma, terminaríamos escribiendo la información
.del último registro dos veces. Vamos a realizar un ejemplo sencillo para
.comprobar esto. */
while (!feof(ap))
{
// fread(&al, sizeof(alumn), 1, ap);
    z=ftell(ap) ;
	i=z/t ;
     printf("\nregistro: %d/%d %d",z,t, i);
    printf("\nMatrícula: %d", al.matri);
printf("\tCarrera: %d", al.carre);
printf("\tPromedio: %f\t ", al.pro);
puts(al.nom);
fread(&al, sizeof(alumn), 1, ap);
}
}
