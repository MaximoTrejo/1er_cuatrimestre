/*
 ============================================================================
 Name        : parcial_2.c
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
#include "libro.h"

int main(void) {
	setbuf(stdout, NULL);
		int opcion = 0;
		char arhivoNombre[TAM];

		LinkedList * libros=ll_newLinkedList();

		do{
			opcionesMenu();
			utn_getInt(&opcion, "Ingrese la opcion", "Error", 1, 7, REINTENTOS);
				switch(opcion){
					case 1:

						printf("ingrese el nombre del archivo");
						scanf("%s",arhivoNombre);

						if(strcmp(arhivoNombre,"datos.csv")==0){

								if(controller_cargarArchivoDesdeTexto(arhivoNombre,libros)==1){
									printf("*Archivos cargados correctamente\n");
								}else{
									printf("*No se pudo cargar el archivo, pruebe nuevamente\n");
								}
						}else{
							printf("*Ingreso mal el nombre del archivo ,pruebe nuevamente[datos.csv]\n");
						}
						break;
					case 2:
						if(controller_listar(libros)==0){
							printf("*Archivos cargados correctamente\n");
						}else{
							printf("*No se pudo cargar el archivo\n");
						}
						break;
					case 3:
						if(controller_sort(libros)==0){

							controller_listar(libros);
						}else{
							printf("*No se pudo cargar el archivo\n");
						}
						break;
					case 4:
						if(controller_guardarModoTexto("ordenado.csv",libros)==0){
							printf("*Archivos cargados correctamente\n");
						}else{
							printf("*No se pudo cargar el archivo\n");
						}
						break;
					case 5:
						if(controller_map(libros)==0){
							controller_listar(libros);
							printf("*Archivos cargados correctamente\n");
						}else{
							printf("*No se pudo cargar el archivo\n");
						}
						break;
					case 6:
						if(controller_guardarModoTexto("mapeado.csv",libros)==0){
							printf("*Archivos cargados correctamente\n");
						}else{
							printf("*No se pudo cargar el archivo\n");
						}
						break;

				}
		}while(opcion != 7);
	return EXIT_SUCCESS;
}
