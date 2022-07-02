/*
 ============================================================================
 Name        : Menu-04-04-2022.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout,NULL);
	//REPETITIVA (while o do while)
	//sELECCION MULTIPLE (switch)

	int opcion;
	do{

		printf("1.SUMAR");
		printf("\n2.RESTAR");
		printf("\n3.MULTIPLICAR");
		printf("\n4.DIVIDIR");
		printf("\n5.SALIR");
		printf("\nIngrese una opcion");
		scanf("%d" ,&opcion);

		switch(opcion)
		{
			case 1 :
				printf("Estoy sumando..\n");
			break;
			case 2 :
				printf("Estoy restando..\n");
			break;
			case 3 :
				printf("Estoy multiplicando..\n");
			break;
			case 4 :
				printf("Estoy dividiendo..\n");
			break;
			case 5 :

				printf("Gracias por usar nuestro programa..\n");
			break;
		}

	}while(opcion!=5);

	return EXIT_SUCCESS;
}

