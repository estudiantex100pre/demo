#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std ;

class arreglo {
	protected :
		int numero[50][50];
		int fila, col ;
	public :
		virtual void mostrar()=0 ;
		virtual void setnumero(int, int)=0 ;
		virtual void recorrer()=0 ;
};

class acomodar : public arreglo{
	public :
		void mostrar(){
			for(int i=0 ; i<fila ; i++){
			    for(int j=0 ; j<col ; j++)
			        cout<<numero[i][j]<<"  " ;
			cout<<endl ;
			}
		}
		void setnumero(int, int) ;
		void recorrer() ;
		void derecha(int,int) ;
		void abajo(int,int) ;
		void izquierda(int,int) ;
		void arrinba(int,int) ;
};

void acomodar::setnumero(int x, int y) {
	fila=x;
	col=y ;
    for(int i=0 ; i<fila ; i++){
		for(int j=0 ; j<col ; j++){
			cout<<"ingere numero: " ;
			cin>>numero[i][j] ;
			cout<<endl ;
			}
		cout<<endl ;
		}

}

void acomodar::recorrer(){
	int coli=0, colf=col-1, filai=0, filaf=fila-1, ban=1 ;
	while(ban){
	if(filai < colf){
		//derecha(filai, colf);
		for(int i=coli ; i<=colf ; i++)
		    cout<<numero[filai][i]<<"  " ;
		cout<<endl;
		filai++ ;
		}
	else ban=0 ;
	if(filai < filaf){
	   // abajo(filai,filaf) ;
	   for(int i=filai ; i<=filaf ;i++)
	        cout<<numero[i][colf]<<"  " ;
       cout<<endl;
	    colf--;
		}
	else ban=0 ;
	if(colf > coli){
//	    izquierda(cof, coli)
		for(int i=colf ; i>=coli ; i--)
		    cout<<numero[filaf][i]<<"  " ;
		cout<<endl ;
	    filaf--;
		}
	else ban=0 ;
	if(filaf > filai){
	//    arriba(filaf, filai)
	    for(int i=filaf ; i>=filai ; i--)
	        cout<<numero[i][coli]<<"  " ;
		cout<<endl ;
	    coli++ ;
		}
	else 	if(filai < colf){
		//derecha(filai, colf);
		for(int i=coli ; i<=colf ; i++)
		    cout<<numero[filai][i]<<"  " ;
		cout<<endl;
		filai++ ; ban=0 ;
		}
		else ban=0 ;


	}
}

int main() {
	arreglo *obj= new acomodar ;
	obj->setnumero(4,3) ;
	obj->mostrar() ;
	cout<<endl ;
	obj->recorrer() ;
	cout<<endl ;
	obj->mostrar() ;
	system("pause") ;
	return 0 ;
}
