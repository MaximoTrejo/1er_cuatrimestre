/*
 ============================================================================
 Name        : PARCIAL[1].c
 Author      : Maximo Trejo
 Version     : PARCIAL 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "libraryArtistMusic.h"
#include "utn.h"


int main(void) {
	setbuf(stdout, NULL);
//-------------------------------------------------
	album album[CANT];
//--------------------------------------------------
	initArtist(album,CANT);

	harcodeo(album , CANT);

	menu(album,CANT);

	return EXIT_SUCCESS;
}
