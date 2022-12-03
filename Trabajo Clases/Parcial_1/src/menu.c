/*
 * menu.c
 *
 *  Created on: 2 oct 2022
 *      Author: maxim
 */



#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaLibro.h"
#include "menu.h"
#include "utn.h"

void menuInformes(){
    printf("\nMenu de informes"
            "\n1. Total y promedio de los importes, y cu�ntos libros superan ese promedio."
            "\n2. Cantidad de libros cuya fecha de publicaci�n es anterior a 01/01/2000."
    		"\n3.Salir\n");
}


void menulistar(){
	 printf("\nMenu de listar"
	            "\n1.Todas las editoriales."
	            "\n2.Todos los pa�ses."
	            "\n3.Todos los autores."
	            "\n4.Todos los libros."
			 	"\n5.Ordenar albumes por Importe o Titulo"
			 	"\n6.mostrar generos"
			 	"\n7.mostrar libros cuyo genero no sea novela "
				"\n8.mostrar libros ARG que correspondan a una editorial determinada  "
			 	"\n9.Salir.\n");
}


void menuOpciones(void){
	printf("Bienvenido");
    printf("\n1) Alta.");
    printf("\n2) Modificacion.");
    printf("\n3) Baja.");
    printf("\n4) Informar.");
    printf("\n5) Listar.");
    printf("\n6) Salir.");
}



void menuModificar(void){
	printf("MODIFICACION");
    printf("\n1) Titulo.");
    printf("\n2) FechaPublicacion.");
    printf("\n3) importe.");
    printf("\n4) Autor.");
    printf("\n5) Editorial.");
    printf("\n6) Genero.");
    printf("\n7) Salir.");
}

