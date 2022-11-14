/*
 ============================================================================
Ejercicio 5-2:
Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
a) Cantidad de positivos y negativos.
b) Sumatoria de los pares.
c) El mayor de los impares.
d) Listado de los números ingresados.
e) Listado de los números pares.
f) Listado de los números de las posiciones impares.
Anexo 5-2
g) Los números que se repiten
h) Los positivos creciente y los negativos de manera decreciente
Se deberán utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void pedirNum(int numeros[], int tam ){
	for(int i=0;i<tam;i++){

		while(numeros[i] < -1000 || numeros[i] > 1000 ){

			printf("ingrese un numero entre (-1000 y 1000)");
			scanf("%d", &numeros[i]);

		}
	}
}

int mayImpar(int numeros[],int tam, int size){
	int mayorNumPar;

	if(numeros[size] > mayorNumPar){
		mayorNumPar=numeros[size];
	}

	return mayorNumPar;
}

int sumarPares(int numero[],int tam){

	int suma;
	for(int i=0;i<tam;i++){

		if(numero[i] %2==0){
			suma=suma+1;
		}else{
			mayImpar(numero,tam,i);
		}
	}

	return suma;

}


void listarNum(int numeros[],int tam){
	for(int i=0;i<tam;i++){
		printf("%d", numeros[i]);
	}
}


void listarNumPares(int numeros[],int tam){
	for(int i=0;i<tam;i++){
		if(numeros[i] %2==0){
			listarNum(numeros[i],tam);
		}
	}
}

void cantPosyNeg(int numero[],int tam){

	int punNeg=0;
	int punPos=0;
	for(int i=0;i<tam;i++){

		if(numero[i] > 0){
			punNeg++;
		}else{
			punPos++;
		}
	}
}






