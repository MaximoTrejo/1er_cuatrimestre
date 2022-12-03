/*
 ============================================================================
 Name        : prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#define REINTENTOS 5
#define TAM 500


int main(void) {

	setbuf(stdout, NULL);
	char arhivoNombre[100];

	printf("ingrese el nombre del archivo");
	scanf("%s",arhivoNombre);

		if(strcmp(arhivoNombre,"datos.csv")==0){
			printf("bien");
		}else{
			printf("mal");
		}


	return EXIT_SUCCESS;
}
