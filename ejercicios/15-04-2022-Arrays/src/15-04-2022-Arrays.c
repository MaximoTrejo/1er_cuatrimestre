/*
 ============================================================================
 Name        : 15-04-2022-Arrays.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define EDADDES 5

int main(void) {
	setbuf(stdout, NULL);

	int edad;
	int arrayEdades[EDADDES];
	int i;
	float promedio; // lo puedo usar tambien de puntero

	for (i = 0; i < EDADDES; i++) {

		if (utn_getNumero(&edad, "Ingrese edad:", "Esta edad no va\n", 1, 120,
				3) == 0) {
			arrayEdades[i] = edad;
		} else {
			printf("Sonaste no tenes idea lo que es una eda'\n");
		}
	}

	//Sin puntero
	//promedio = promedioArray(arrayEdades, EDADDES);

	//Con puntero

	if(promedioArrayV2(&promedio, arrayEdades, EDADDES)==0){
		printf("Promedio de edades es : %f ", promedio);
	}else{
		printf("No se logro imprimir el puntero");
	}

	return EXIT_SUCCESS;
}

//SOLUCION 1(sin puntero)
float promedioArray(int array[], int tam) {
	float retorno;
	int acumArray = 0;

	for (int i = 0; i < tam; i++) {
		//acumulo para el promedio
		acumArray = acumArray + array[i];
	}
	//afuera del bucle
	retorno = (float) acumArray / tam;

	return retorno;
}

//SOLUCION 2(con puntero)
float promedioArrayV2(float *pPromedioResultado, int array[], int tam) {
	//retorno=-1 MAL
	//retorno =0 BIEN
	int i;
	int acumArray = 0;
	int retorno=-1;

	if (pPromedioResultado != NULL && tam > 0 && array != NULL) {

		for (i = 0; i < tam; i++) {
			acumArray = acumArray + array[i];
		}

		*pPromedioResultado = acumArray / tam;
		retorno=0;

	}

	return retorno; // OK
}
