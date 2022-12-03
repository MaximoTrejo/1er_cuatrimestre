#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "libro.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_FromText(FILE* pFile , LinkedList* pArrayList)
{
	int retorno=-1;
	/*
	 * creo las variables auxiliares
	 * valido los parametros de la funcion
	 * leo el encabezado
	 * recorro todo el archivo hasta el final
	 * me fijo la cantidad de datos que lee
	 * valido que haya leido bien los datos
	 * *si los lee mal libero la memoria
	 * *si los lee bien cargo los datos por parametros
	 * valido que los haya cargado bien
	 * los guardo en la lista dinamica
	 */

	char auxId[TAM];
	char auxTitulo[TAM];
	char auxImporte[TAM];
	char auxIdTipo[TAM];

	int cantidad;//variable para guardar la cantidad de datos
	eLibro * libros;//puntero a estructura jugador en donde se guarda los datos

	if(pFile != NULL && pArrayList != NULL){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n] \n",auxId,auxTitulo,auxImporte,auxIdTipo);//falsa lectura
		while(feof(pFile)==0){
			cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n] \n",auxId,auxTitulo,auxImporte,auxIdTipo);
			if(cantidad ==4){
				libros = list_newParametros(auxId, auxTitulo, auxImporte, auxIdTipo);
				if(libros!=NULL){
					ll_add(pArrayList, libros);
					retorno=1;
				}
			}
		}
	}


    return retorno;
}






