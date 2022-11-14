/*
 * transformacion.c
 *
 *  Created on: 31 ago 2022
 *      Author: maxim
 */


#include <stdio.h>
#include <stdlib.h>
#include "transformacion.h"
#include "validacion.h"


int inicio(){
	char validacion;
	int transformar;


	printf("fahrenheit o celcius(F o C) ");
	scanf("%c",&validacion);

	if(validacion == 'F'){
		transformar=validarTempfahrenheit();
	}else{
		transformar=validarTempcelsius();
	}

	return transformar;

}



int transformarCaF(int numero){

	int transformacion;

	transformacion=(numero*2)+32;

	return transformacion;
}
