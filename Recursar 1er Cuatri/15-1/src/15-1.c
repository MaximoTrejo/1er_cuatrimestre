/*
 ============================================================================
 Name        : 15-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int ordenarEnteros(int vector[] ,int tam);
int swap(int * vA ,int *vB);
void mostrar(int vector[] , int tam);

int main(void) {

	int vector[5]={5,3,2,1,6};//creo el vector

	ordenarEnteros(vector, 5);//funcion que ordena

	mostrar(vector, 5);//funcion que muestra

	return EXIT_SUCCESS;
}



int ordenarEnteros(int vector[] ,int tam){
	int retorno=-1;

	for (int i = 0 ; i < tam -1 ; i ++ ){ //recorre el vector

		for(int j = i+1 ; j<tam ;j++){//recore el vector pero una posicion adelante

			if (vector[i] > vector[j]){//criterio (> desc  < asc)

				swap(&vector[i], &vector[j]);//swap(es el pasaje de los datos), le paso la direccion de memoria con la posicion
				retorno=0;
			}
		}
	}

	return retorno;
}



int swap(int * vA ,int *vB){
	int retorno=-1;
	int pAux; //donde guardo el dato

	if(vA!=NULL && vB !=NULL){//valida que no tenga basura


		//El pasaje se puede pensar como si queres pasar los datos de un vaso de agua a otro

		pAux = *vA; //guardo el dato en el auxiliar
		*vA = *vB; //paso el dato de B a A
		*vB = pAux;//paso del dato B al Aux

		retorno=0;
	}


	return retorno;
}


void mostrar(int *vector , int tam){

	for (int i = 0 ; i < tam ; i ++ ){
		printf("%d\t ",vector[i]);
	}
}
