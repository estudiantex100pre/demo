/*Problema PS8.2
La Federación Mexicana de Fútbol (FEMEXFUT) almacena en un arreglo unidimensional
la información de la tabla de posiciones de sus torneos apertura y
clausura. Las estadísticas se ordenan lógicamente en función de los puntos. Se
almacena la siguiente información de cada equipo:
• Nombre del equipo (cadena de caracteres).
• Partidos jugados (entero).
• Partidos ganados (entero).
• Partidos empatados (entero).
• Partidos perdidos (entero).
	• Goles a favor (entero).
	• Goles en contra (entero).
	• Diferencia de goles (entero).
• Puntos (entero).

Dato: FUTBOL[20] (donde FUTBOL es un arreglo unidimensional de tipo estructura
EQUIPO).
Escribe un programa en C que actualice la información después de cada fecha. El
programa recibe la información de la siguiente manera:
América 0 – Puebla 2
Cruz Azul 3 – Veracruz 2
Necaxa 2 – Monterrey 3
. . .
Después de actualizar la información, el programa debe escribir la nueva tabla de
posiciones, ordenada en función de los puntos de cada equipo. */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

using namespace std ;


typedef struct {
	int golesf ;
	int golesc ;
	int dfgoles ;
}estadistica ;

typedef struct {
	char nom[20] ;
	int pj ;
	int g ;
	int e ;
	int p ;
	estadistica est ;
	int puntos ;
}equipo ;

void lectura (equipo *, int) ;
void resultados(equipo *,int) ;
void qequipo(char*, int, equipo,int) ;

int main() {
	equipo a[40] ;
	int t;
	cout<<"ingrese la cantidad de equipos: " ; cin>>t ;
	lectura(a,t) ;
	resultados(a,t)
}

void lectura(equipo a[] , int t){
	for(int i=0 ; i<t ; i++){
	    cout<<i+1<<". nombre del equipo: " ;
	    fflush(stdin);
		gets(a[i].nom) ;
	}
}

void resultados (equipo a[], t) {
	cout<<"resultado partido a partido"<<endl ;
	int = l ;
	char res[30] ;
	for(int i=0 ; i< t/2 ; i ++ ){
   	 fflush(stdin);
		gets(res) ;
		l=strlend(res) ;
		qequipo(res, l, a, t) ;
	}
}
//	real madrid 5 - barcelona 0
void qequipo(char res[], int l, equipo a[], int t){
	int golc, golv ;
	for(int i=0 ; i<l ;i++)
	    if(isdigit(res[i]))
	        gol = i ;
	for(int i=0 ; i<t ; i++){
	    int j=0 ;
	    int la= strlen(a[i].nom) ;
		while(res[j]==a[i].nom[j] && j<la)
		    j++ ;
		if(j==la)
		    a[i].pj ++ ;
		    a[i].est.golesf += golv ;
	}
		
}
