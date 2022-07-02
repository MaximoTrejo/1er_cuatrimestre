/*
 ============================================================================
 Name        : Maximo-Minimo.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int main(void) {

	setbuf(stdout,NULL);

	int maximo;
	int minimo;
	int i;
	int bufferInt;//donde guardo numero
	//bandera
	int flag = TRUE;

	for(i=0;i<5;i++){
		//pido dato
		printf("INGRESE UN NUMERO %d \n" , i+1); //el i+1 es para mostrar cuantas veces se ejecuta el bucle
		scanf("%d" , &bufferInt);
		//entra una ves ,para declarar cual el el maximo y el minimo inicial
		if(flag==TRUE){

			maximo=bufferInt;
			minimo=bufferInt;
			flag=FALSE;

		}else{

			if(bufferInt > maximo){
				maximo=bufferInt;
			}

			if(bufferInt < minimo){
				minimo=bufferInt;
			}
		}
	}
	printf("el valor maximo es : %d y el valor minimo es : %d" ,maximo,minimo);
	return EXIT_SUCCESS;
}
