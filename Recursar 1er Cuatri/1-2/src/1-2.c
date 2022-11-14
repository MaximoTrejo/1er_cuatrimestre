/*
 ============================================================================
 Name        : 2do.c
 Author      : MaximoTrejo
 EJERCICIO   : 1-2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);//para que funcione bien la consola(IMPORTANTE)
	int numUno;//declaro la variable
	int numDos;//declaro la variable
	int numTres;
	printf("Ingresa un numero:");//printf sirve para imprimir en pantalla
	scanf("%d", &numUno);//scanf para guardar el dato (uso el & para guardarlo en una direccion de memoria)
	printf("Ingresa otro numero:");
	scanf("%d", &numDos);
	printf("Ingresa otro numero:");
	scanf("%d", &numTres);

	/*
	 LOGICA
	 Si el numero uno es mayor al 2 y si el num uno es mayor al 3 entpnces el numero uno es el mas grande
	 */
	if(numUno>=numDos && numUno>numTres){
		printf("El mayor de los números es el primero ");
	}else if(numDos>=numUno && numUno>numTres){
		printf("El mayor de los números es el segundo ");
	}else{
		printf("El mayor de los números es el tercero ");
	}


	return EXIT_SUCCESS;
}
