/*
 ============================================================================
 Name        : 2-4.c
 Author      : MaximoTrejo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	char caracter;
	int contP=0;
	//contador cuenta una cantidad fija ,siempre va a contar la misma cantidad puesta por el programador
	//aculador cuenta una cantidad variable , va acumular el numero q ingrese el usuario

	for(int i=0;i<5;i++)
	{

		printf("ingrese un caracter :");
		scanf(" %c",&caracter);

		if(caracter=='p'){
			contP=contP+1;
		}
	}

	printf("la cantidad de caracteres ingresado es %d" , contP);


	return EXIT_SUCCESS;
}
