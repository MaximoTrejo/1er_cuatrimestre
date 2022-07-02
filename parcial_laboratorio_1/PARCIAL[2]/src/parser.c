#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "computer.h"
#include "utn.h"
#include "menu.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	char id[TAM],descripcion[TAM],precio[TAM],idTipo[TAM];
	int cantidad;
	eComputer* pAuxPasajeros;


	if(pFile != NULL && pArrayListPassenger != NULL){

		//scanf se utiliza para leer los datos//leo la primer linea , el encabezado
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo);

		do{//feof devuelve 0 si llega al final del bloque de datos y 1 si no llega
			cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo);
			//entra y si cada ves que pasa lee la cantidad de datos correctos entra y crea un nuevo pasajero

			if(cantidad < 4){
				//libera memoria
				//Passenger_delete(pAuxPasajeros);
				retorno=-1;
				break;
			}else{
				/*
				 * 1-crear nuevo pasajero en la estructura psajeros
				 * 2-ver que no este con basura
				 * 3-cargarlo en lickedlist
				 * 4-retornar
				 */
				pAuxPasajeros=Passenger_newParametros(id,descripcion,precio,idTipo);

				if(pAuxPasajeros != NULL){

					ll_add(pArrayListPassenger, pAuxPasajeros);

					retorno=0;
				}
			}

		}while(!feof(pFile));//una funcion si le llego al final de un archivo 0 mal 1 bien
	}

    return retorno;
}

