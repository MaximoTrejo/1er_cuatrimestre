#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "menu.h"
#include "utn.h"
#include "parser.h"
#include "libro.h"


int controller_cargarArchivoDesdeTexto(char* path , LinkedList* pArrayList)
{
	int retorno=-1;

	FILE * archivo;
	archivo=fopen(path,"r");

	if(archivo != NULL){

		if(parser_FromText(archivo, pArrayList)==1){
			printf("*Se leyeron correstamente los datos \n");
			retorno=1;
		}else{
			printf("*No se leyo correstamente los datos\n");
			retorno=0;
		}
	}
    return retorno;
}

int controller_listar(LinkedList* pArrayList)
{
	int retorno=-1;
	int largo;

	int auxId;
	char auxTitulo[TAM];
	float auxImporte;
	int auxIdTipo;

	char auxTipo[TAM];

	eLibro* libro;

	if(pArrayList!=NULL){
		printf("ID\t\tDESCRIPCION\t\tPRECIO\t\tIDTIPO\n");
		largo=ll_len(pArrayList);

		for(int i=0;i<largo;i++){

			libro=ll_get(pArrayList, i);

				if(libro != NULL){

					lib_getId(libro, &auxId);
					lib_getTitulo(libro, auxTitulo);
					lib_getImporte(libro, &auxImporte);
					lib_getIdTipo(libro, &auxIdTipo);

					if(auxIdTipo==1){
						strcpy(auxTipo,"PAPEL");//copia los la cadena en el dato
					}else{
						strcpy(auxTipo,"EBOOK");
					}

					printf("%d,%s,%f,%s\n",auxId,auxTitulo,auxImporte,auxTipo);
					retorno=0;
				}
		}
	}
    return retorno;
}



int controller_sort(LinkedList* pArrayList)
{
	int retorno=-1;
	int largo;


	if(pArrayList != NULL){

		largo=ll_len(pArrayList);

		if(largo !=0){
			if(ll_sort(pArrayList,lib_compareImporte, 0)==0){
				printf("Se ordeno correctamente\n");
				retorno=0;
			}
		}
	}
    return retorno;
}


int controller_guardarModoTexto(char* path , LinkedList* pArrayList)
{
	int retorno=-1;
	int largo;

	int auxId;
	char auxTitulo[TAM];
	float auxImporte;
	int auxIdTipo;


	eLibro * libro;//puntero a estructura jugador en donde se guarda los datos
	FILE * archivo;

	if(path != NULL && pArrayList != NULL){
		largo=ll_len(pArrayList);
		archivo=fopen(path,"w");

		if(archivo != NULL){
			fprintf(archivo,"id,titulo,importe,idTipo\n");
			for(int i=0 ; i<largo;i++){

				libro=ll_get(pArrayList, i);


				lib_getId(libro, &auxId);
				lib_getTitulo(libro, auxTitulo);
				lib_getImporte(libro, &auxImporte);
				lib_getIdTipo(libro, &auxIdTipo);

				fprintf(archivo,"%d,%s,%f,%d\n",auxId,auxTitulo,auxImporte,auxIdTipo);
			}
			printf("*Se escribieron bien\n");
			retorno=0;
		}else{
			printf("Error\n");
		}
	}
	fclose(archivo);
    return retorno;
}



int controller_map(LinkedList* pArrayList){

	//valido
	int retorno = -1;
	//creo la funcion puntero
	void (*pFunc)(void *this);//es el eComputer

	if(pArrayList != NULL){
		pFunc=aumentoPrecio;//solo hace la cuanta y carga la suma en el dato
		ll_map(pArrayList, pFunc);
		retorno=0;

	}
	return retorno;
}

