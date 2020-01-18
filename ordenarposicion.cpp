#include <iostream>
#include <stdlib.h>
using namespace std ;
/*   b{ 2,3,1,0}
	 a{ 5,4,2,1}
*/
void arreglomxn(int*) ;

int main(){
	int a[12]={1,2,5,4,6,9,8,7,18,2,5,48}, b[10]={0}, aux, j, p[10] ;
	for(int i=0; i<10 ; i++)
		p[i]=a[i] ;
	arreglomxn(a) ;
/*
	for(int i=1 ; i<10 ; i++){
		aux = a[i] ;
		j=i-1 ;
		while(aux>a[j] && j>=0){
			a[j+1] = a[j] ;
			b[j+1]= b[j] ; // en b[j] para ir guardado segun sea la posicion ideal ;
			j-- ;
		}
		a[j+1]=aux ;
		b[j+1]=i ;
	}
	for(int i=0 ; i<10 ; i++)
	    cout<<i+1<<" ---> "<<b[i]+1<<": "<<a[b[i]]<<endl; */
	system("pause") ;
	return 0 ;
}
/*	1 3 5 7 2 7 4 9 6
	0 1 2 3 4 5 6 7 8

	9  7  7  6 5 3 1
	7  3  5  8 2 1 0 */
void arreglomxn(int *a){
	int b[2][12], aux, j;
	for(int i=0; i<1 ; i++)
	    for(int k=0 ; k<12 ; k++)
		//	if(i==0)
			b[i][k]= a[k] ;
		/*	else{
			cout<<"k="<<k+1<<"  ";  // wtf fila 1 agsina valores del 1 a9 solo
			b[1][k] = k ;} */
	b[1][0]=0 ; //wtf solo esta posicion agarra un dato basura
	    
	for(int i=1 ; i<12 ; i++){
		aux = b[0][i] ;
		j=i-1 ;
		while(aux>b[0][j] && j>=0){
			b[0][j+1] = b[0][j] ;
			b[1][j+1] = b[1][j] ;
			j-- ;
		}
		b[0][j+1]=aux ;
		b[1][j+1]=i ;  // lol aqui se enumeraban mi arreglo :)
	}
	for(int i=0 ; i<12 ; i++)
	    cout<<i+1<<" ---> "<<b[1][i]+1<<": "<<b[0][i]<<endl;
}
