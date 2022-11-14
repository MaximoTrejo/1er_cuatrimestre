/*
 ============================================================================
 Name        : 1er.c
 Author      : MaximoTrejo
 EJERCICIO   : 1-1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);//para que funcione bien la consola(IMPORTANTE)
	int unNumero;//declaro la variable
	int otroNumero;//declaro la variable
	printf("Ingresa un numero:");//printf sirve para imprimir en pantalla
	scanf("%d", &unNumero);//scanf para guardar el dato (uso el & para guardarlo en una direccion de memoria)
	//     ^           ^
	//	   |	       |
	// Tipo de dato    Nombre de la variable(uso el & para guardarlo en una direccion de memoria // si tiene
	//                                       como tipo de dato %s no va el &)
	//
	printf("Ingresa otro numero:");
	scanf("%d", &otroNumero);
	printf("La suma entre  %d y %d da como resultado %d",unNumero,otroNumero, unNumero + otroNumero);
	//muestro
	return EXIT_SUCCESS;
}
