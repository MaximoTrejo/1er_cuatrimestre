/*
 ============================================================================
 Name        : Funcion.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 FUNCION SOLO PARA NUMEROS ENTEROS
*/

#include <stdio.h>
#include <stdlib.h>
//se incluye las firmas de las funciones (las h)
#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);

	int edad;
	float peso;
	char letra;
	int respuesta;

	//Caracter
		respuesta=utn_getCaracter(&letra,"Letra? \n", "\n Error la letra debe ser desde A a J \n" , 'A','J',1 );
		if(respuesta==0){
			printf("\n La letra es : %c", letra);
		}else{
			printf("\n ERROR");
		}


	//EDAD
	respuesta=utn_getNumero(&edad,"\n Edad?", "\n Error la edad debe ser desde 0 a 199 \n" , 0,199,2 );
	if(respuesta==0){
		printf("El peso es : %d", edad);
	}else{
		printf("\n ERROR");
	}

	//PESO
	respuesta=utn_getNumeroFlotante(&peso,"\n Peso?", "\n Error el peso debe ser desde 0 a 80 \n" , 0,80,3 );

	if(respuesta==0){
		printf("El peso es : %f", peso);
	}else{
		printf("\n ERROR");
	}


	return EXIT_SUCCESS;
}
