/*
 ============================================================================
 Name        : 17-05-22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE * pArchivos ;
	//char saludo[20];//para leerlo

//-------------------------------------------------------------------
	//ESCRIBIR
	//txt texto
	//.bin .dat -> binarios
	//fopen (); -> puntero al archivo - 'w' -> write escritura 'r'-> read lectura

	pArchivos=fopen("data.csv","r");//si no lee nada lo crea automaticamente
	if(pArchivos != NULL){
		printf("se leyo co");
	}
	//fprintf(pArchivos,"guianni");//escribo algo en el archivo
	fclose(pArchivos);//cierro el archivo
//--------------------------------------------------------------------
	//LEER
	//pArchivos=fopen("data.txt","r");//para leer
	// GETS -> lee una cadena de caracteres
	//fgets(saludo,20,pArchivos);//resibe la cadena , el tamanio de la cadena , el archivo
	//fclose(pArchivos);
	//puts(saludo);
//--------------------------------------------------------------------









}
