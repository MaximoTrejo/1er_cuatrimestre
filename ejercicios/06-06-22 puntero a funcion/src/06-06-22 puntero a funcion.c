/*
 ============================================================================
 Name        : 06-06-22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//void saludar(void);
void saludar(char* mensaje);

void despedir(char* mensaje);

void manejarSaludos(char* , void(*pFuncion)(char*));

int main(void) {
	printf("-----------------------------------\n");
	printf("Cargando en el puntero a funcion la funcion y ejecutando el puntero\n");
	printf("-----------------------------------\n\n");
	//void(*pFuncion)(void);//puntero a funcion void
	void(*pFuncion)(char*);

	pFuncion=saludar;//cuando quiero guardar una funcion en un puntero , solo escribo el nombre

	//pFuncion();

	pFuncion("1F\n");

	/****/
	pFuncion=despedir;//le puedo volver a asignar otra funcion porque es la misma firma(char*)

	pFuncion("estudien ,vagos!!!\n");
	/****/
	// todo se puede resumir psando el mensaje a la funcion de manejarSaludos
	printf("-----------------------------------\n");
	printf("Utilizando una funcion que como parametros le paso una funcion\n");
	printf("-----------------------------------\n\n");
	 manejarSaludos("1f\n",saludar);

	 manejarSaludos("estudien ,vagos!!!\n",despedir);

	return EXIT_SUCCESS;
}

/*
void saludar (void){
	printf("hola 1f");
}
*/

void saludar (char* mensaje){

	printf("hola %s\n",mensaje);
}

void despedir(char* mensaje){
	printf("nos vemos mañana .%s\n",mensaje);
}

void manejarSaludos(char* mensaje , void(*pFuncion)(char*)){
	pFuncion(mensaje);
}
