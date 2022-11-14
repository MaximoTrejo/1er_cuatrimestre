/*
 * funciones.c
 *
 *  Created on: 12 sept 2022
 *      Author: maxim
 *
 *https://onlinegdb.com/FqxHzaIoI  (clase 12/09/22)
 *
 *      https://onlinegdb.com/h6uoGfln4 (todos los tipos de ayuda)
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include "funciones.h"
#define TAM 1


void pedirDatos(char nombre[][TAM],char apellido[][TAM],int tam){

	for(int i=0 ;i<tam;i++){
		printf("ingrese un nombre");
		fflush(stdin);
		scanf("%[^\n]", nombre[i]);

		printf("ingrese un apellido");
		fflush(stdin);
		scanf("%[^\n]", apellido[i]);
	}
}



void mostrarVector(char nombre[][TAM],char apellido[][TAM],int tam){
	for(int i=0;i<tam;i++){
			printf("%s , %s \n", nombre[i],apellido[i]);
	}
}
