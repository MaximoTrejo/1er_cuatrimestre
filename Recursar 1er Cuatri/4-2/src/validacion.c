/*
 * validacion.c
 *
 *  Created on: 31 ago 2022
 *      Author: maxim
 */


#include <stdio.h>
#include <stdlib.h>
#include "transformacion.h"
#include "validacion.h"

int validarTempcelsius(){
	int num;

	printf("ingrese un numero");
	scanf("%d", &num);

	while(num < 0 || num > 100 ){

		printf("ingrese un numero entre 0 y 100: ");
		scanf("%d", &num);
	}

	return num;
}


int validarTempfahrenheit(){


	int num;
	int transformado;


	printf("ingrese un numero");
	scanf("%d", &num);

	transformado=transformarCaF(num);

	while(transformado < 32 || transformado > 212 ){

		printf("ingrese un numero entre 32 y 212: ");
		scanf("%d", &num);
	}

	return transformado;
}
