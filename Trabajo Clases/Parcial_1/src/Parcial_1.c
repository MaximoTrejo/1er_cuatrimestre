/*
 ============================================================================
 Name        : Parcial_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaLibro.h"
#include "menu.h"
#include "utn.h"



int main(void) {

	setbuf(stdout, NULL);

	eLibro libros[CANT];
	eAutor autor[CANT];
	eEditorial editorial[CANT];
	ePais pais[CANT];
	eGenero genero[CANT];

	inicializarAE(libros, CANT);

	harcodeoAutor(autor, CANT);
	harcodeoPais(pais, CANT);
	harcodeoEditorial(editorial, CANT);
	harcodeoGenero(genero, CANT);

	menu(libros, CANT,autor,editorial,pais,genero);


	return EXIT_SUCCESS;
}
