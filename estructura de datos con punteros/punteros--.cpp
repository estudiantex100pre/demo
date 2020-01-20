#include <iostream>
#include <stdlib.h>
using namespace std ;

int a=3, b=5, c=7, d=9 ;

int main(){
	cout<<"a="<<&a ;
    cout<<", b="<<&b ;
    cout<<", c="<<&c ;
    cout<<", d="<<&d<<endl ;
	int *y ;
	y= &d ; cout<< *y<<" "<<y<<endl ;
//	*(y--) ;
	cout<<"y="<<*y--<<"direccion"<<y<<endl ;
	cout<<"="<<--*y<<endl;
	cout<<" direccion"<<y<<endl ;
//	cout<<"y="<<--*y--<<"direcion"<<y<<endl ;
	cout<<"="<<*y++<<"direciion"<<y<<endl ;
	cout<<"="<<++*y<<"direcion"<<y<<endl ;
	cout<<"direcion d"<<&d<<endl<<&c<<endl<<&b<<endl<<&a ;
	system ("pause") ;
	return 0 ;
}
