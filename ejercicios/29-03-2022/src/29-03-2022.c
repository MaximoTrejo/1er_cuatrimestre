/*
 ============================================================================
 Name        : 29-03-2022.c
 Author      : MaximoTrejo
 ============================================================================
 */

#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

    int esValido;
    esValido = verifica();

    if(esValido == 1){
        printf("Es S");
    }
    else{
        printf("Es N");
    }
    return EXIT_SUCCESS;
}

//cuerpo desarrollo C
//prototipos h
