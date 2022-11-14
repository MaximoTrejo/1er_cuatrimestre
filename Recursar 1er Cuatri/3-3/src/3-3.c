/*
 ============================================================================
Ejercicio 3-3:
Crear una función que pida el ingreso de un entero y lo retorne.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

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

	printf("ingrese un numero");
	scanf("%d", &numero);

	return numero;
}




