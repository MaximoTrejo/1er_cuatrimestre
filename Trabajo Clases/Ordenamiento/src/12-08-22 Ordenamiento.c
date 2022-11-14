/*
 ============================================================================
 Name        : Ordenamiento.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main(void) {
	setbuf(stdout,NULL);
	int i;
	int j;
	int aux;
	int numeros[TAM]={5,8,6,4,3}; //harcodeo de un array

	 for(i=0;i<TAM-1;i++){//ejemplo  i = 0 1 2 3
		 for(j=i+1;j<TAM;j++){//ejemplo j =1 2 3 4
			 if(numeros[i]>numeros[j]){
				 aux=numeros[i];
				 numeros[i]=numeros[j];
				 numeros[j]=aux;
			 }
		 }
	 }

	return EXIT_SUCCESS;
}
