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
			if(!utn_getNumero(&opcion,"\n\nIngrese una opcion: ","\n¡Error!\n",1,7,3))
			{
				switch(opcion)
				{
					case 1:
						if(!controller_loadFromText("enduro.csv",listaParticipantes))
							{
								printf("\n¡Funciono la carga del archivo!\n");
							}
						break;
					case 2:
						controller_ListParticipantes(listaParticipantes);
						break;
					case 3:
						if(!controller_asignacionPromedios(listaParticipantes))
						{
							controller_ListParticipantes(listaParticipantes);
						}
						break;
					case 4:
						listaParticipantesFiltrados = controller_filter(listaParticipantes, listaParticipantesFiltrados);
						if(listaParticipantesFiltrados != NULL)
						{
							controller_ListParticipantes(listaParticipantesFiltrados);

							if(!controller_saveAsText("filtrado.csv",listaParticipantesFiltrados))
							{
								printf("\n¡Se guardo el archivo filtrado.csv!\n");
							}
						}
						break;
					case 5:
						if(!controller_sort(listaParticipantes))
						{
							controller_ListParticipantes(listaParticipantes);
						}
						break;
					case 6:
						if(!controller_saveAsText("enduro.csv",listaParticipantes))
						{
							printf("\n¡Se guardo el archivo enduro!\n");
						}
						break;
					case 7:
						break;
				}
			}
		}while(opcion != 7);
	return EXIT_SUCCESS;
}
