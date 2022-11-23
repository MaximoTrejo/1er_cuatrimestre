/*
 ============================================================================
 Name        : 2doParcial-Practicas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "menu.h"
#include "utn.h"
#include "parser.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion = 0;

	LinkedList * participantes=ll_newLinkedList();
	LinkedList * auxParticipantesFiltrados=ll_newLinkedList();

	do{
		opcionesMenu();
		utn_getInt(&opcion, "Ingrese la opcion", "Error", 1, 11, REINTENTOS);
			switch(opcion){
				case 1:
					/*
					 *llamo al controller ,lo valido
					 *muestro que lo cargo bien
					 *
					*/
					if(controller_cargarArchivoDesdeTexto("enduro.csv",participantes)==1){
					   printf("*Archivos cargados correctamente\n");
					}else{
					   printf("*No se pudo cargar el archivo\n");
					}
					break;
				case 2:
					if(controller_listar(participantes)==1){
						printf("*Archivos cargados correctamente\n");
					}else{
						printf("*No se pudo cargar el archivo\n");
					}
					break;
				case 3:
					if(controller_asignarPromedio(participantes)==0){
						controller_listar(participantes);
						printf("*Archivos cargados correctamente\n");
					}else{
						printf("*No se pudo cargar el archivo\n");
					}
					break;
				case 4:
					/*
					 * tengo que crear una lista para guardar los filtrados
					 * guardo los filtrados
					 * valido que haya datos en la lista
					 * mustro los filtrados
					 * llamo a controller_guardarArchivoDesdeText(tambien los crea porque escribe)
					 * confirmo con un mensaje
					 */
					auxParticipantesFiltrados=controller_filtrar(participantes, auxParticipantesFiltrados);
					if(auxParticipantesFiltrados != NULL){
						controller_listar(auxParticipantesFiltrados);
						if(controller_guardarModoTexto("filtrados.csv", auxParticipantesFiltrados)==0){
							printf("*Archivos cargados correctamente\n");
						}
					}

					break;
				case 5:
					if(controller_sortPassenger(participantes)==0){
						controller_listar(participantes);
						printf("*Archivos cargados correctamente\n");
					}else{
						printf("*No se pudo cargar el archivo\n");
					}

					break;
				case 6:
					if(controller_guardarModoTexto("enduro.csv", participantes)==0){
						printf("*Archivos cargados correctamente\n");
					}else{
						printf("*No se pudo cargar el archivo\n");
					}
					break;

			}
	}while(opcion != 7);

	return EXIT_SUCCESS;
}
