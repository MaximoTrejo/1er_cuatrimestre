/*
 ============================================================================
 Name        : PARCIAL[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "computer.h"
#include "utn.h"
#include "menu.h"
#include "parser.h"


int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	LinkedList * lComputer = ll_newLinkedList();

	do{
		opcionesMenu();
		if(utn_getInt(&opcion, "elegi una opcion\n", "error", 0, 6, REINTENTOS)==0){
			switch(opcion){

			case 1:
				if(controller_loadFromText("datos_SP.csv",lComputer)==0){
					printf("*Archivo cargado correctamente\n");
				}else{
					printf("No se pudo cargar el archivo\n");
				}
				break;
			case 2:
				if(controller_sortPassenger(lComputer)==0){
					printf("se ordeno correctamente\n");
				}else{
					printf("no se ordeno correctamente\n");
				}
				break;
			case 3:
				if(controller_ListPassenger(lComputer)==0){
					printf("Se listo correctamente\n");

				}else{
					printf("No se pudo listar \n");
				}
				break;
			case 4:
				if(controller_aumentoTipo(lComputer)== 0){
					printf("se aumento correctamente\n");
				}else{
					printf("no se aumento correctamente\n");
				}
				break;
			case 5:

				break;
			case 6:
				break;
			}

		}

	}while(opcion!=6);









	return EXIT_SUCCESS;
}
