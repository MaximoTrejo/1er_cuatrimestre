/*
 ============================================================================
 Name        : ClaseUnoBis.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//Cuando se compile en todas las var CLIENTES van a ser 3 (sirve para pruebas)
#define CLIENTES 3

int main(void) {

	setbuf(stdout,NULL);

	//variables
	int numeroUno;
	int acumPromedio = 0;
	float promedio;
	int contador= 0;
	int i;

	//bucle
	for(i=0;i<CLIENTES;i++){
		//pedido al usuario
		printf("\n Ingrese el numero \n");
		scanf("%d" , &numeroUno);

		acumPromedio=acumPromedio+numeroUno;
		contador=contador+1;
	}

	//lo que hace poner el (float) el convertir ese numero el float (numero)para la cuenta;
	promedio =(float) acumPromedio/contador;

	//mostrar
	printf("\n El promedio es : %f" , promedio);


	//final programa
	return EXIT_SUCCESS;
}
