/*
 ============================================================================
 Name        : programParcial[1].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


float descuento(int importeProd , float porcentajeDescuento);
char invertirCadena(char primerCadena[],char cadenaInvertida[], int tamanio);

int main(void) {
	setbuf(stdout, NULL);

	char pCadena[6]={"maximo"};
	char sCadenai[6];


	int importe=100;
	float porcentaje=5;
	float descuentoFull;
	descuentoFull=descuento(importe,porcentaje);
	printf("%f",descuentoFull);


	invertirCadena(pCadena,sCadenai,6);

	printf("\n%s\n", sCadenai);

	return EXIT_SUCCESS;
}


float descuento(int importeProd , float porcentajeDescuento){
	float importeDes;
	float descuento;
	descuento = porcentajeDescuento*importeProd/100;
	importeDes=importeProd-descuento;
	return importeDes;
}


char invertirCadena(char primerCadena[],char cadenaInvertida[], int tamanio){

	char aux;
	for(int i=0;i<tamanio;i++){
		for(int j=i;j>0;j--){//empiezo en i que es el final y despues va restando uno en j hasta llegar hasta el primera posicion del array

			if(primerCadena[i] > cadenaInvertida[j]){
				aux = primerCadena[i];
				primerCadena[i]=cadenaInvertida[j];
				cadenaInvertida[j]=aux;
			}
		}
	}
	return aux;
}
