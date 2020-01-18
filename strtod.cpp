#include <stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
int main() {
	char d[20]="hola2do", b ;
	int a=5;
	b=d[5];
	a = atoi((d+4)) ;
	cout<<b<<endl<<a<<endl ;
/*	gets(d) ;
	double x ;
	x=strtod(d, &a) ;
//	cout<<atof(d)<<endl ;
	cout<<d<<"   "<<x<<"     "<<*a<<endl ;
	puts(a) ;*/
	system("pause") ;
	return 0 ;
}
