/*
 ============================================================================
Realizar una función que reciba como parámetro un array de enteros, su tamaño y un entero. La
función se encargará de buscar el valor entero y borrará la primera ocurrencia del mismo. El array
deberá reestructurarse dinámicamente.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



void funcion(int *ArrayEnteros , int len ,int numEntero );

int main(void) {

	int* aux;
	aux=(int*)malloc(sizeof(int)*3);

	if(aux!=NULL){

		aux[0]=1;
		aux[1]=2;
		aux[2]=3;

		funcion(aux, 3, 2);

		for(int i=0; i< 3 ; i++){

			printf("%d\n", aux[i]);
		}
	}

	return EXIT_SUCCESS;
}


void funcion(int *ArrayEnteros , int len ,int numEntero ){

	if(ArrayEnteros != NULL && len >= 0){

		for(int i=0; i< len ; i++){

			funcionFree(ArrayEnteros , i, numEntero);

		}

	}

}


void funcionFree(int *ArrayEnteros , int len ,int numEntero ){

	int* aux;

	if(ArrayEnteros[len] == numEntero){

		aux=&ArrayEnteros[len];
		free(aux);

	}
}
