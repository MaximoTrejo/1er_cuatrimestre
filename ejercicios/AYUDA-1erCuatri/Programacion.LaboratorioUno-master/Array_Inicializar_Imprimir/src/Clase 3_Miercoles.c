/*
 ============================================================================
 Name        : Clase.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define EDADES_LEN 5
void imprimirArrayDeEdades(int pArrayEdades[],int len);
void inicializarArrayDeEdades(int pEdades[], int len,int valorInicial);

int main(void) {

	//array ESTATICAS
	int edades[EDADES_LEN];//0 al 4 : 5 elementos

	//INICIALIZAR ARRAY
	inicializarArrayDeEdades(edades,EDADES_LEN,0);

	//IMPRIMIR ARRAY CON UNA FUNCION
	imprimirArrayDeEdades(edades, EDADES_LEN);


	return EXIT_SUCCESS;
}


void inicializarArrayDeEdades(int pEdades[], int len,int valorInicial){

	int indice;

	for(indice=0;indice < len ;indice++)
		{
			pEdades[indice]=valorInicial;
		}
}


void imprimirArrayDeEdades(int pArrayEdades[],int len)
{
	int indice;

	for(indice=0;indice < len ;indice++)
	{
		printf("%d\n" , pArrayEdades[indice]);
	}
}
