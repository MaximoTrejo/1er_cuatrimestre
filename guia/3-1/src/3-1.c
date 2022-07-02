/*
 ============================================================================
 Name        : 3-1.c
 Author      : MaximoTrejo
 Version     : Crear una función que muestre por pantalla el número flotante  que recibe como parámetro.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void mostrarNumFlotante(float numFloat);

int main(void) {
	setbuf(stdout,NULL);
	float numFloat;
	printf("ingredar un num flotante");
	scanf(" %f" , &numFloat);

	mostrarNumFlotante(numFloat);

	return EXIT_SUCCESS;
}

void mostrarNumFlotante(float numFloat)
{
	printf("el numero flotante es %f" , numFloat);
}
