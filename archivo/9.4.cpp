#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void str(FILE*) ;
int cont=0;
int main(){
	FILE * ar ;
	ar= fopen("arc.txt", "r") ;
	char *d ;
	if(ar != NULL){
		printf("ingrese frase: ") ;
	//	gets(d) ;
		str(ar) ;
	}else printf("no se abrio archivo") ;
	system("pause") ;
	return 0 ;
}
 /*sas aasas sas sssas sas
ssssaaabbbsassbsasbbbasssss
sssssaaaaaaasssssasssassbbbsbsb
sssssabsabsbbbbsbabsas*/
void str(FILE *a) {
	char *x, cad[50] ;
	
	while(!feof(a)){
		fgets(cad, 50, a) ;
		x=strstr(x, "sas") ;
		printf("\n %s", x) ;

		while(x != NULL){
		    cont++ ;
			x=strstr(x+1, "sas") ;
			}
	}
	printf("\n %d",cont) ;
	
}
