#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE * ar ;
	int i=1 ;
	char s;
	ar= fopen("arc.txt", "r") ;
	if (ar != NULL){
		while(!feof(ar)){
		s=fgetc(ar);
		printf("%d=%c.  ", i++, s) ; }// la funcion feof no se puede compara con un ciclo repetitivo//
	} //el archivo va de posicion 0 hasta 1,2,3,4... hasta que se dege de escribir en el ar.
	//simplemte la funcion feof almacena verdadero (1 o V), cuando detecta el final del archivo;
	//es decir obligatoriamente el codigo debe ir leyendo el ar hasta su final para q no sea bucle infinito.
	else printf("no se abrio archivo") ;
	
	system("pause") ;
	return 0 ;
}
