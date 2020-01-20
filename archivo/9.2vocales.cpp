/*Problema PS9.2
Escribe un programa en C que, al recibir como dato el archivo arc.txt compuesto
por cadenas de caracteres, calcule el número de cada una de las vocales que se encuentra
en el archivo. Por ejemplo, si el archivo contiene las siguientes cadenas de
caracteres:
México es la novena economía del mundo,
pero tiene más pobres que la mayoría de los países europeos
con macroeconomías peores que la de México.
El programa debe dar los siguientes resultados:
a: 11
e: 19
i: 7
o: 17
u: 4
Dato: arc.txt*/
#include <stdio.h>
#include <stdlib.h>
void vocales(FILE*);
int main(){
	FILE *ar ;
	if( (ar=fopen("arc.txt", "r")) != NULL ){
		vocales(ar) ;
	}else printf("no se pudo abirir el arhcivo") ;
	system("pause") ;
	return 0 ;
}

void vocales(FILE *ap) {
	char v ;
	int a=0,e=0,i=0,o=0,u=0;
	while(!feof(ap))
		switch (v=fgetc(ap)){
			case 'a': a++; break ;
			case 'e': e++; break ;
			case 'i': i++; break ;
			case 'o': o++; break ;
			case 'u': u++; break ;
			default: break ;
		}
	printf("cantidad de letras:\n") ;
	printf("a=%d\ne=%d\ni=%d\no=%d\nu=%d\n", a, e, i, o, u) ;
}
