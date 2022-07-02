/*
 ============================================================================
 Name        : 5-1.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf (stdout, NULL);
	int vector[5];
	int contPositivos=0;
	int suma=0;
/*
 * La idea de tener todo en distintos for es tener diferentes funciones para cada cosa
 */
	//funcion pedir datos
	for(int i=0; i<5; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &vector[i]);
	}
	//mostrar
	for(int i=0; i<5; i++)
	{
		printf("%d\n", vector[i]);
	}
	//suma
	for(int i=0; i<5; i++)
	{
		//suma
		suma=suma+vector[i];
	}
	//contador de positivos
	for(int i=0; i<5; i++)
	{
		//contador positivos
		if(vector[i] > 0){
			contPositivos++;
		}
	}

	//mostrar
	printf("la suma es %d" , suma);
	printf("\nla cantidad de positivos es %d", contPositivos);
	return EXIT_SUCCESS;
}


//constante no ocupa memoria
//variable ocupa memoria
//define es una constante que se carga en el precompilador
