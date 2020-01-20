#include <stdio.h>
#include<iostream>
#include <stdlib.h>
using namespace std ;
void leer(FILE *) ;

int main() {
	FILE *ar ;
	ar= fopen("datos.txt", "r") ;
	if( ar!=NULL){
	    leer(ar) ;
	  }else  cout<<"archivo no se pudo abrir"<<endl ;
	system("pause") ;
	return 0 ;
}
void leer(FILE *a) {
	int n, c ;
	char nik[20] ;
	float p ;
	fscanf(a,"%d",&n) ;
	cout<<n<<endl ;
	for(int i=0 ; i<n ; i++){
	p=0 ;
/*	fgets(nik, 20, a);
	cout<<"->>"<<nik ;*/
	for(int j=0; j<n ; j++){

	    fscanf(a,"%d",&c) ;
	    cout<<"->"<<c<<"<-" ;
		}
		fscanf(a,"%f", &p) ;
	cout<<">"<<p<<"<"<<endl ;
	}

}
