/*
 ============================================================================
 Name        : 19-10-22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//obligatorio la bliblioteca
#include <stdlib.h>


int main(void) {

	int * pNumero;
	int * auxNumero;

	// void* malloc(unsignet int numbytes);
	pNumero=(int*)malloc(sizeof(int)*4);//para recervar espacio de memoria de un entero ///si la RAM se queda sin memoria devuelve NULL

	if(pNumero != NULL){

		*pNumero =10;
		printf("%d",*pNumero);


		//realloc agranda el espacio de memoria
		auxNumero=realloc(pNumero,sizeof(int) * 8);

		if(auxNumero !=NULL){
			pNumero = auxNumero;
		}

	}else{
		printf("No hay espacio en memoria");
	}


	//free libera memoria
	if(pNumero != NULL){
		free(pNumero);
	}

	return EXIT_SUCCESS;
}
