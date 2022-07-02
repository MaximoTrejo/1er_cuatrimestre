/*
 ============================================================================
 Name        : 05-04-2022.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>//biblioteca para poder usar las funciones de string(CADENAS DE CARACTERES)

#define TAM 11
#define TAMAUX 30
int main(void) {
	setbuf(stdout,NULL);

	//CADENAS DE CARACTERES(string)
	//inicialise el array
	char nombre [TAM] = "JUAN";//'\0'(si quiero un array de 10 nesetito hcer uno de 11 porque el \0 ocupa un lugar)
	char auxiliar[TAMAUX]="";

	//COMANDO PARA COPIAR
	/*
	strcpy(nombre,"MARIA");
	strcpy(auxiliar,nombre);//copie los elementos de otro array
	*/

	//hace lo mismo que strcpy pero es mas segura porque pide un parametro que busca el tamaño del array para que o tome un espacio de memoria de cualquier lado
	strncpy(auxiliar,nombre,sizeof(auxiliar));//sizeof(cuanta cuantos mide el array)

	//Cuenta el tamaño de lo que esta cargado en el array por ejemplo:char nombre [TAM] = "JUAN";(tiene cargado 4 lugares)
	//strnlen(auxiliar,sizeof(auxiliar));

	//concatenar texto
	//donde quiero concatenar | lo que quiero concatenar | tamaño del array (para que no se rompa )
	strncat(nombre,"LALA",sizeof(nombre));

	//es como un printf pero guarda en un array de caracteres
	//array donde quiero cargar | lo que quiero guardar | tamaño del array (para que no se rompa )
	//sprintf(auxiliar,"MI SIZE OF ES %d",58);
	//ESTA ES MEJOR
	snprintf(auxiliar,sizeof(auxiliar),"MI SIZE OF ES %d",58);

	printf("\n%s\n",auxiliar);
	printf("SIZE | Nombre mide %d ------ auxiliar mide %d", sizeof(nombre), sizeof(auxiliar));
	printf("\nSTRNLEN | Nombre mide %d ------ auxiliar mide %d",strnlen(nombre,sizeof(nombre)),strnlen(auxiliar,sizeof(auxiliar)));

	return EXIT_SUCCESS;
}
