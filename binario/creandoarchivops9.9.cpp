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
using namespace std;

typedef struct{
	int clave ;
	char producto[20] ;
	int cantidad ;
	float precio ;
}productos ;


int main(){
	FILE *ar ;
	int x;
	productos p ;
	if((ar=fopen("productos.dat", "w")) != NULL ){
		printf("cuantos productos vas ingresar") ;
		cin>>x ;
		for(int i=0 ; i<x ; i++){
			cout<<"producto "<<i+1<<endl ;
			cout<<"ingrese clave del producto: " ; cin>> p.clave ; fflush(stdin);
			cout<<"ingrese el nombre del producto: "; gets(p.producto) ;
			cout<<"existencia: " ; cin>>p.cantidad ;
			cout<<"ingrese el precio del producto: " ; cin>>p.precio ;
			fwrite(&p, sizeof(productos), 1, ar) ;
		}
	}else printf("no se pudo abrir archivo") ;
}
