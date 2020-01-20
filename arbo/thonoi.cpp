#include <iostream>
#include <stdlib.h>
using namespace std ;

void honoi(int, int, int, int) ;
int main() {
	honoi(3,1,2,3) ;
	system("pause");
	return 0 ;
}

void honoi(int discos, int t1, int t2, int t3){
	if(discos==1)
	    cout<<"mover disco de torre "<<t1<<" a torre "<<t3<<endl;
 	else{
		honoi (discos-1, t1, t3, t2) ;
		cout<<"ti="<<t1<<" t2="<<t2<<" t3="<<t3<<endl ;
	    cout<<"mover disco de torre "<<t1<<" a torre "<<t3<<endl ;
	    honoi(discos-1, t2, t1, t3) ;
	    cout<<"ti=="<<t1<<" t2=="<<t2<<" t3=="<<t3<<endl ;
		}
}
