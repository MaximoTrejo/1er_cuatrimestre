/*
 * utn_biblioteca.c
 *
 *  Created on: 7 sep. 2021
 *      Author: maxim
 */

#include "utn_biblioteca.h"

//-------------------------------------------------------------------------------------

// Inicialización del array, días con temperatura en 0

void inicializarArray(float arrayTemperatura[], int len,int valorInicial){

	int indice;

	for(indice=0;indice < len ;indice++)
		{
			arrayTemperatura[indice]=valorInicial;
		}
}

//---------------------------------------------------------------------------
//imprimir todo el array sin datos EJ 0 (porque en ese valor lo inicialize)
void imprimirArray(float pArrayTemperatura[],int len)
{
	int indice;
	int dia;

//indice es igual a 0 ,si indice es menor al len(de cuento es el array),se le suma 1(hasta llegar)
	for(indice=0;indice < len ;indice++)
	{
		//suma 1 para q no aparesca el 0 primero
		dia = indice+1;
		//se muestra el dia(posicion) y el valor del array(valor)
		printf("dia: %d ,temp: %f \n" ,dia,pArrayTemperatura[indice]);
	}
}



//----------------------------------------------------------------------------------
//pedirle un dia y y cargarlo en un array

void ingreseUnDia(float lista[],int len)
{
	int dia;
	float temp;
	//1)pedir al usuario
	printf("ingrese el dia");
	scanf("%d" , &dia);
	//2)pedir al usuario la temp
	printf("ingrese la temperatura");
	scanf("%f" , &temp);
	//3)transformar el dia en la posicion
	dia=dia-1;
	//cargar la temp en la pisicion del array
	lista[dia]=temp;
}
