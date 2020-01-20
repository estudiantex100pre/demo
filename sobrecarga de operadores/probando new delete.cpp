#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std ;
int main(){
/*	int *x, *y, a=7;
	x=new int(a);
//	y=new int ;

	y=&a;
	delete x ;
	cout<<*y<<"  "<<*x<<endl ;*/
	char *x, *b, *c="hola" ;
	x=new char(*c) ;
	b = c ;
	delete[] x ;
	cout<<b<<"  "<<x<<endl ;
	system("pause") ;
	return 0 ;
}
