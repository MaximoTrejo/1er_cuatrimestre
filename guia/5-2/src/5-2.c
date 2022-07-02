/*
 ============================================================================
 Name        : 5-2.c
 Author      : MaximoTrejo
 EJERCICIO
 	Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
	Cantidad de positivos y negativos.
	Sumatoria de los pares.
	El mayor de los impares.
	Listado de los números ingresados.
	Listado de los números pares.
	Listado de los números de las posiciones impares.

	Anexo 5-2
	Los números que se repiten
	Los positivos creciente y los negativos de manera decreciente
	Se deberán utilizar funciones y vectores.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define MIN -1000

int pedirNum(int vector[],int size);
void cantidadPosNeg(int vector[],int size);
void numeroImpar(int vector[],int size);
void mostrarListado(int vector[],int size);
void posicionesImpares(int vector[],int size);
void repetidos(int vector[],int size);
int main(void) {
	setbuf (stdout, NULL);
	int vector[5];
	int size=5;

	if(pedirNum(vector,size)==0){

		cantidadPosNeg(vector,size);
		numeroImpar(vector,size);
		mostrarListado(vector,size);
		posicionesImpares(vector,size);
		repetidos(vector,size);
	}

	return EXIT_SUCCESS;
}

int pedirNum(int vector[],int size){
	int retorno=-1;
	for(int i=0; i<size; i++)
	{
		do{
			printf("Ingrese un numero: ");
			scanf("%d", &vector[i]);
			if(vector[i] <= MAX && vector[i] >= MIN){
				retorno=0;
			}else{
			printf("\nvolve a ingresar el numero");
			}
		}while(retorno != 0);
	}
	return retorno;
}

void cantidadPosNeg(int vector[],int size){
	int contPos=0;
	int contNeg=0;
	for(int i=0;i<size;i++){
		if(vector[i]>0){
			contPos++;
		}
		if(vector[i]<0){
			contNeg++;
		}
	}
	printf("la cantidad de pos es %d y neg es %d" ,contPos,contNeg);
}

void numeroImpar(int vector[],int size){
	int numeroImpar;
	for(int i=0;i<size;i++){
		if(vector[i]%2==1){//o %2 !=0
			if(vector[i]<numeroImpar){
				numeroImpar=vector[i];
			}

		}
	}
	printf("\nEl mayor de los impares es %d",numeroImpar);
}


void mostrarListado(int vector[],int size){
	printf("\nLos numeros ingresados son:");
	for(int i=0;i<size;i++){
		printf("%d - ", vector[i]);
	}
	printf("\nLos numeros pares ingresados son ");
	for(int i=0;i<size;i++){
		if(vector[i]%2==0){
			printf("%d - " , vector[i]);
		}
	}
}



void posicionesImpares(int vector[],int size){
	printf("\nLos numeros ingresados en las posiciones impares son");
	for(int i=0;i<size;i=i+2){
		printf(" %d ", vector[i]);
	}
}


void repetidos(int vector[],int size){
	printf("\nlos repetidos son ");
	for(int i=0;i<size - 1;i++){
		for(int j=i+1;j<size;j++){
			if(vector[i]== vector[j]){
				printf(" %d  " ,vector[i]);
			}
		}
	}
}
