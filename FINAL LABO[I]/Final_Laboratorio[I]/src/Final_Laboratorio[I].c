/*
 ============================================================================
 Name        : Final_Laboratorio[I].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define AUX_LEN 500
#include "Controller.h"
#include "Biblioteca.h"
#include "LinkedList.h"
#include "Participante.h"

int main(void) {

	setbuf(stdout, NULL);
		int opcion = 0;
		LinkedList* listaParticipantes = ll_newLinkedList();
		LinkedList* listaParticipantesFiltrados = ll_newLinkedList();

		do{
			menu();
			if(!utn_getNumero(&opcion,"\n\nIngrese una opcion: ","\n¡Error!\n",1,6,3))
			{
				switch(opcion)
				{
					case 1:
						if(!controller_loadFromText("datos_RSP_M1.csv",listaParticipantes))
							{
								printf("\n¡Funciono la carga del archivo!\n");
							}
						break;
					case 2:
						if(!ll_sort(listaParticipantes,ordenarEquiposPorScore,0))
						{
							printf("\n¡Se ordeno el archivo!\n");
						}
						break;
					case 3:
						controller_ListParticipantes(listaParticipantes);
						break;
					case 4:
						listaParticipantesFiltrados = controller_filter(listaParticipantes, listaParticipantesFiltrados);
						if(listaParticipantesFiltrados != NULL)
						{
							printf("\n¡El filtro se aplico correctamente!\n");
							controller_ListParticipantes(listaParticipantesFiltrados);
						}

						break;
					case 5:
						if(!controller_saveAsText("filtrado.csv",listaParticipantesFiltrados))
						{
							printf("\n¡Se guardo el archivo filtrado.csv!\n");
						}
						break;
					case 6:
						break;
				}
			}
		}while(opcion != 6);
	return EXIT_SUCCESS;
}
