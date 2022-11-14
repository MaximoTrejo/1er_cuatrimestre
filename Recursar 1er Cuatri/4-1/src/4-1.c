/*
 ============================================================================
Ejercicio 4-1:
Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un
número. Utilizar la función PedirNumero de la ejercitación 3-4.
Por ejemplo:
5! = 5*4*3*2*1 = 120
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio-4-1.h"

int funcionPedirEntero();
int funcionFactoreo(int numFactoriado);

int main(void) {

	setbuf(stdout,NULL);

int numero;
int factoria;

numero = funcionPedirEntero();

factoria=funcionFactoreo(numero);

printf("el factorial del numero %d es %d", numero, factoria);

	return EXIT_SUCCESS;
}


int funcionPedirEntero(){
	int numero;

	printf("ingrese un numero: ");
	scanf("%d", &numero);

	return numero;
}



int funcionFactoreo(int numFactoriado){
	int factorial;

	if(numFactoriado == 0){
		factorial = 1;
	}else {
		factorial = numFactoriado * funcionFactoreo(numFactoriado - 1);
	}
	return factorial;
}
