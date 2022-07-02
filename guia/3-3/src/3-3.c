/*
 ============================================================================
 Name        : 3-3.c
 Author      : MaximoTrejo
 Version     :Crear una función que pida el ingreso de un entero y lo retorne.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int retornarEntero(void);

int main(void) {
	setbuf(stdout,NULL);
	int mostrar;
	mostrar=retornarEntero();

	printf("el numero entero es %d" , mostrar);

	return EXIT_SUCCESS;
}

int retornarEntero(void){
	int numEntero;
	printf("ingrese un num entero:");
	scanf(" %d" , &numEntero);
	return numEntero;
}
