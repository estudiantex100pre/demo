#include <iostream>
#include <stdlib.h>
using namespace std ;

class Tiempo {
	public:
		Tiempo() {minuto= 0 ; hora =0; cout<<"constructor x defecto"<<endl ;}
		Tiempo(int h, int m=0) : hora(h), minuto(m) {cout<<"constructor parametrizado"<<endl ;}
		/* ojo (int h=0, int m=0) nunca debe ponere todos los valores inciazidado en los parametros,
		cuando la se ha escrito un constructor por defecto ya que, al crear un objeto sin parametros
		este no tendria especificado cual seria su construtor debido que tanto el construtor por defecto y
		el constructor parametrizado podria entrar" */
		Tiempo(const Tiempo& obj) ;
		Tiempo operator++(); // Forma prefija
		Tiempo operator++(int); // Forma sufija

		Tiempo operator+(Tiempo h);
		bool operator>(Tiempo h) ;
		void Mostrar();
		Tiempo operator>>(Tiempo h);
		~Tiempo() ;
	private:
	int hora;
	int minuto;

};
Tiempo::Tiempo(const Tiempo &obj){
	hora =obj.hora ;
	minuto= obj.minuto ;
	cout<<hora<<":"<<minuto<<" construtor copia"<<" direccion:"<<this<<endl ;
}

Tiempo Tiempo::operator>>(Tiempo h)
{
if(*this > h) return *this; else return h;
}

bool Tiempo::operator>(Tiempo h)
{  cout<<hora<<" "<<h.hora<<endl;
return (hora > h.hora || (hora == h.hora && minuto > h.minuto));
}
Tiempo Tiempo::operator+(Tiempo h){
	Tiempo temp; cout<<"dir temp"<<&temp<<endl;
	temp.minuto = minuto + h.minuto;
	temp.hora = hora + h.hora;
	if(temp.minuto >= 60) {
		temp.minuto -= 60;
		temp.hora++;
	}
	return temp;
}// se retorna Tiempo(temp) este constructor y destructor nunca aparece sera por el return
//que impide que el programador observe eso..
	void Tiempo::Mostrar(){
	cout << hora << ":" << minuto << endl;

}

Tiempo::~Tiempo() {
	cout<<"destructor"<<hora<<":"<<minuto<<" direccion: "<<this<<endl ;
	system("pause") ;
}

Tiempo Tiempo::operator++(){
	minuto++;
	cout<<"operator++ sin parametros "<<this<<endl ;
	while(minuto >= 60) {
		minuto -= 60;
		hora++;
	}
	return *this; //cuaidado se destruye lo q se retorna la linea seiguiende donde se invoco
}

Tiempo Tiempo::operator++(int){
	Tiempo temp(*this); // obligatorio definir Constructor copìa sino elimina los valores al final de este metodo
	minuto++;           //aunque solo si usara memoria dinamica en un atributo ;
	while(minuto >= 60) {
		minuto -= 60;
		hora++;
	}
	return temp; //solo se usa para usar un metodo (Mostrar)
}

int main(){
	Tiempo Ahora(14,54), T1(4,45);
	cout<<&Ahora<<" "<<&T1<<endl ;
	(T1++).Mostrar();
	
	

/*  Ahora = Ahora + T1 ; /*no se invoca el constructor copia en esta agsinacion.
	Diria que es logico por que un obejeto solo tiene un constructor que fue invocado antes "ahora(14,45).
	Dicho esto siemplemente toma todos los atributos en fin de cuenta son como cualquier tipo de variables ejm:
	int x=5, y=7 ;
	x=y;
	x ya esta incializada simpletemente toma el valor y en el caso de objetos toma los atributos...
	en la funcion operator+: se crean dos objetos, uno usa constructor copia y el otro x defecto.
	Al salir de esa funcion se elimina los dos objetos. Lo curioso es que primero se elimia temp y
    luego se agsina a Ahora (Ahora= Ahora +T1), quiere decir que no esta retornado explicitamente Temp
	x q ya esta eliminadado por consiguiente es el valor que se retorna pero esto no es un tipo de dato
	(int, float, doblue, char..) es un objeto que puede tener muchos atributos y no seria logico que se
	este agsinado enteros o cualquier otro tipo de dato a objteos, por consiguiente actuara como un
	objeto igual en valores pero distinto a temp. En fin de cuentas retorna Tiempo. */
    T1.Mostrar(); cout<<endl ;
    Ahora.Mostrar(); cout<<endl ;
    system("pause") ;
//	T1 = Ahora + T1; // (1)
/*	T1.Mostrar(); cout<<endl ;
	if(Ahora>T1) cout<<"aHORA es mayor q T1"<<endl ;
	else cout<<"T1 es mayor q aHORA"<<endl ;
	cout<<endl ;
	T1 = Tiempo(2,25);//Ahora >> Tiempo(13,43) ;//>> T1 >> Tiempo(12,32);
	T1.Mostrar();*/ cout<<"chao main" ;
	system("PAUSE");
	return 0;
}
