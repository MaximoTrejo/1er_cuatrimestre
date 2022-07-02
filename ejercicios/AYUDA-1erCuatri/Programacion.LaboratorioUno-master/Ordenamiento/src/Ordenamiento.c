/*
 ============================================================================
 Name        : Ordenamiento.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define COD_AREA 5
int imprimirEnteros(int arrayImprimir[], int tam);
void imprimirElemento(int elemento,int indice);
int ordenarArray(int arrayAOrdenar[] , int tam);

int main(void) {


	int codigoArea[COD_AREA]={8,20,134,23,50};
	int cantidadVueltas=0;

	imprimirEnteros(codigoArea,COD_AREA);
	ordenarArray(codigoArea,COD_AREA);
	imprimirEnteros(codigoArea,COD_AREA);


	printf("cantidad vueltas %d" , cantidadVueltas);

	//indice 0 1 2 3 4
	//valor 8 20 134 23 50

	//num 8 (guardo momentariamente el 8)
	//numero a remplazar 134

	//bucaria el mas grande
	//134
	//indice 2

	//indice 0 1 2 3 4
	//valor 134 20 8 23 50


	//indice 0 1 2 3
	//valor 8 20 23 50

	//134 50 23 20 8


	return EXIT_SUCCESS;
}


//imprimir array int
int imprimirEnteros(int arrayImprimir[], int tam)
{
	int retorno = -1;
	if(arrayImprimir != NULL && tam >= 0)
	{
		for(int i = 0 ; i < tam ; i++)
		{
			imprimirElemento(arrayImprimir[i], i);
		}
		retorno=0;
	}
	return retorno;
}

void imprimirElemento(int elemento,int indice){
	printf("ELEMENTO DEBUG %d  , POSICION %d ",elemento,indice);
}


//---------------------------------------------------
int ordenarArray(int arrayAOrdenar[] , int tam)
{
	int retorno=-1;
	int flagSwap;
	int aux;//variable temporal
	int contadorVueltas=0;
	int limite=tam;
	//----------------------------------------------
	if (arrayAOrdenar != NULL && tam >= 0)
	{
		do
		{
			flagSwap=0;//esto es pensar que esta ordenado
			limite=limite-1;
			for(int i =0 ; i< limite ;i++)
			{
				//se cambia el signo asendente(menor a mayor)
				if(arrayAOrdenar[i]<arrayAOrdenar[i+1])
				{
					flagSwap=1;//consideramos que le array esta desordenado
					aux=arrayAOrdenar[i];//aux 8 //guardas
					arrayAOrdenar[i]=arrayAOrdenar[i+1];//array[i] 20 //cambia al siguiente
					arrayAOrdenar[i+1]=aux; //array[i+1] 8 //
				}
			}
			contadorVueltas++;
		}while(flagSwap==1);

		retorno=contadorVueltas;
	}
	return retorno;
}




