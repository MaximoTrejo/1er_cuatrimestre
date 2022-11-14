/*
 ============================================================================
Ejercicio 3-4:
Especializar la función anterior para que permita validar el entero ingresado en un rango
determinado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MIN 10
int funcionPedirEntero();
int main(void) {

	setbuf(stdout,NULL);
	int funcion;

	funcion=funcionPedirEntero();

	printf("%d", funcion);


	return EXIT_SUCCESS;
}


int funcionPedirEntero(){
	int numero;

	printf("ingrese un numero: ");
	scanf("%d", &numero);

	while(numero > MAX || numero < MIN){//dice validar entonces uso el while para que si no ingresa un numero entre ese rango lo vuelve a preguntar

		printf("ingrese un numero entre 10 y 100: ");
		scanf("%d", &numero);
	}

	return numero;
}
