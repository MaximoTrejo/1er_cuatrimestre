/*
 ============================================================================
 Name        : 3-4.c
 Author      : MaximoTrejo
 Version     :Especializar la función anterior para que permita validar el entero ingresado en un rango determinado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MIN 10
#define MAX 100


int ValidarRango();

int main(void) {
	setbuf(stdout,NULL);
	int validar;

	validar=ValidarRango();
	printf("el num ingresado es %d" , validar);

	return EXIT_SUCCESS;
}

int ValidarRango(){
	int num;
	printf("ingrese un numero entre el 10 y el 100");
	scanf(" %d" , &num);
	while(num < MIN || num >MAX){// si una de las 2 condiciones se cumple entra
	// 2 es menor que 10 0 2 es mayor que 100
	//	V           0               F
		printf("el numero no esta entre 10 y 100 , ingresa un num:");
		scanf("  %d" , &num);
	}
	return num;
}
