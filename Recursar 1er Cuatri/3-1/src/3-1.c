/*
 ============================================================================
Ejercicio 3-1:
Crear una funci�n que muestre por pantalla el n�mero flotante que recibe como par�metro.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void funcionNF(float num);

int main(void) {
	setbuf(stdout,NULL);

	float num;

	printf("ingrese un numero");
	scanf("%f", &num);

	funcionNF(num);

	return EXIT_SUCCESS;
}


void funcionNF(float num){

	printf("el numero floatante es %f",num);
}
