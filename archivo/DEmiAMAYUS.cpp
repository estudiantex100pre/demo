#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std ;

/* Reemplaza palabras.
El programa lee cadenas de caracteres de un archivo y cada que vez que
.encuentra la palabra M�xico escrita en forma incorrecta �la primera con
.min�scula� la reemplaza por su forma correcta y escribe la cadena en otro
.archivo. */

void cambia(FILE *, FILE *);

int main(){
	FILE *ar;
	FILE *ap;
	ar = fopen("arc.txt", "r"); /* Se abre el archivo arc.txt para lectura. */
	ap = fopen("arc34.txt", "w"); /* Se abre el archivo arc1.txt para escritura. */
	if ((ar != NULL) && (ap != NULL)){
		cambia(ar, ap);
		fclose(ar);
		fclose(ap);
	}else
		printf("No se pueden abrir los archivos");
	system("\npause") ;
	return 0 ;
}

void cambia(FILE *ap1, FILE *ap2){
/* Esta funci�n reemplaza en la cadena de caracteres la palabra m�xico escrita
.con min�sculas �la primera letra� por su forma correcta y escribe la cadena
.de caracteres en un nuevo archivo. */

	int i, j, k;
	char cad[50]="hola q tal", aux[50];
	char *cad1;
	char *cad2 ;
	cad1=cad ;
	puts(cad1) ;
	cout<<*cad1<<endl ;
	while (!feof(ap1)){
		fgets(cad, 50, ap1);
		cad1=cad;
		puts(cad1) ;
		cad2 = strstr(cad1, "mexico");



		while (cad2!=NULL){
			cad2[0]='M'; //Reemplaza la letra min�scula por la may�scula.
			i = strlen(cad1);
			j = strlen(cad2);
			k = i - j; 

			if (k){
				strncpy(aux, cad1, k);
				aux[k] = '\0';
				
				strcat(aux, cad2);
				cad1= aux ;
			}else
				cad1= cad2;
		puts(cad1) ;
		cad2 = strstr(cad1, "mexico");

		}
		
	fputs(cad1, ap2); // Se escribe la cadena correcta en el archivo ap2.
	}
}
