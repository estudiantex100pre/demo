/*Problema PS9.9
Una comercializadora que distribuye pinturas e impermeabilizantes como principales
productos, ubicada en la ciudad de Monterrey, en México, almacena en un
archivo de acceso directo, ordenado de menor a mayor en función de la clave,
toda la información relativa a sus productos:
• Clave del producto (entero).
• Nombre del producto (cadena de caracteres).
• Existencia (entero).
• Precio unitario (real).
Escribe un programa en C que construya los siguientes módulos:
a) Ventas. El módulo registra la venta de diferentes productos a un cliente
—tienda. Obtiene el total de la venta y actualiza el inventario correspondiente.
El fin de datos para la venta de un cliente es 0.
b) Reabastecimiento. Este módulo permite actualizar el inventario al incorporar
productos —cantidades— al mismo. El fin de datos es 0.
c) Nuevos Productos. El módulo permite incorporar nuevos productos al inventario.
El fin de datos es 0. Observa que éstos se deberán insertar en la posición
que les corresponde de acuerdo con su clave. Es probable que deba generar un
nuevo archivo para resolver este módulo.
d) Inventario. El módulo permite imprimir el inventario completo.
Dato: com.dat */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct{
	int clave ;
	char nombre[20] ;
	int cantidad ;
	float precio ;
}productos ;

void f1(FILE *) ;
int main(){
	FILE *ar ;

	if( (ar=fopen("productos.dat", "r+")) != NULL ){

		f1(ar) ;

	}else printf("el archivo no se abrio") ;
	system("pause") ;
	return 0 ;
}

void f1(FILE *ar) {
	productos p ;
	int t=sizeof(productos), pos, clave1, cant, cont, ban=1;
	fseek(ar, (0)*sizeof(productos), 2) ;
	pos=ftell(ar)/t ;
	do{
		rewind(ar) ;
		cout<<"ingrese clave del producto a vender: " ; cin>>clave1 ;
		fread(&p, sizeof(productos), 1, ar) ;
		cont=0 ;
		
		while(!feof(ar) && ban>0) {
			if(clave1 == p.clave){
			    ban =0 ;
			    do{
				    cout<<"cuantos (" ; puts(p.nombre) ;
					cout<<") va vender? " ; cin>>cant ;
		    		if(cant > p.cantidad)
		        		cout<<"solo quedan "<<p.cantidad<<endl ;
            	}while(cant > p.cantidad) ;
            	p.cantidad -= cant ;
			}
			
		cont++ ;
		fread(&p, sizeof(productos), 1, ar) ;
		if(cont == pos && ban==1){
			cout<<"clave incorrecta"<<endl ;
		    ban=0 ;
			}
		}
		cout<<"va a vender otro producto?; SI-1 -- NO-0: " ; cin>>ban ;
	}while(ban) ;
}

	
