/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * Ejercicio 1:
 * crear un programa que permita registrar el valor de temperatura maxima de cada dia de un mes.
 * Definir un array de floats de 31 posiciones. Cada posicion corresponderá a un dia
 * del mes.
 * Hacer un programa con un menu de dos opciones, 1.imprimir array y 2.cargar array
 * Al elegir la opcion 1, se imprimira el indice y el valor de cada posicion del array.
 * Al elegir la opcion 2 que le pida al usuario que ingrese un numero de dia (1 a 31)
 * y luego que ingrese un valor de temperatura.
 *
 * Almacenar el valor en el indice correspondiente
 * Ambas opciones deben volver al menu ppal.
 *
 * Utilizar la funcion utn_getNumeroFloat() de la biblioteca utn.h
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
#define TEMP_LEN 31

int main(void) {

	setbuf(stdout,NULL);
	//ARRAY
	float temperaturaPorDia[TEMP_LEN]; //len o TEMP_LEN es de cuanto en es array
	//para saber que opcion eligio el usuario y poder finalizar el bucle
	int opcion;

	//inicializar array en 0
	inicializarArray(temperaturaPorDia,TEMP_LEN ,0);

	do{

		printf("1) imprimir array \n");
		printf("2) cargar array \n");
		printf("3)Salir \n");
		//lee la opcion
		printf("Elija una opcion \n");
		scanf("%d" , &opcion);


		switch(opcion){
		case 1:
			//llamo a la funcion que imrprime el array
			imprimirArray(temperaturaPorDia,TEMP_LEN);
			break;
		case 2:
			//OPCION 2
					ingreseUnDia(temperaturaPorDia,TEMP_LEN);
			break;
		}

	//si no se cumple sale del bucle, EJ 2 !=3(no se cumple)
	}while(opcion!=3);


	return EXIT_SUCCESS;
}
