/*
 ============================================================================
 Name        : Clase3Lunes.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"


int main(void) {

	setbuf(stdout,NULL);
	char caracterAPedir;

	if(utn_pedirCharAUsuario(&caracterAPedir,65,90,2,"Ingrese un caracter: \n " , "Error!!! \n")==0){
		printf("Salio todo bien! el caracter es %c",caracterAPedir);
	}

	return EXIT_SUCCESS;
}




