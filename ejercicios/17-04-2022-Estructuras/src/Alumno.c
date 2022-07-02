/*
 * Alumno.c
 *
 *  Created on: 17 abr. 2022
 *      Author: MaximoTrejo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>//para los strings
#include "Alumno.h"



int imprimirArray(Alumno*pArray , int limite){
	int retorno=-1;
	if(pArray != NULL && limite > 0){
		for(int i=0 ; i < limite ;i++){
			if(pArray[i].isEmpty == 0){
				printf("Nombre: %s | Legajo: %d | Altura: %f \n",pArray[i].nombre , pArray[i].legajo,pArray[i].altura);
			}
		}
		retorno=0;
	}
	return retorno;
}


int inicializoArray(Alumno*pArray , int limite){
	int retorno=-1;
	if(pArray != NULL && limite > 0){
		for(int i=0 ; i < limite ;i++){
			pArray[i].isEmpty = 1;
		}
		retorno=0;
	}
	return retorno;
}
