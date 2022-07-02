/*
 ============================================================================
 Name        : claseDos.c
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

	//CON FLAG(bandera)
	//defino
int bufferInt;
int maximo;
int minimo;
int flag = TRUE ;
//bucle
	for(int i =0;i<5;i++){
		//pido dato
		printf("ingresa un num ");
		scanf(" %d", &bufferInt);
		//entro para poner al primer numro ingresado como maximo y minimo
		if(flag==TRUE){
			maximo=bufferInt;
			minimo=bufferInt;
			//cambio el valor para que solo entre la primera vez
			flag=FALSE;
		}else{
			if(bufferInt>maximo){
				maximo=bufferInt;
			}
			if(bufferInt<minimo){
				minimo=bufferInt;
			}
		}
	}
	return EXIT_SUCCESS;
}
