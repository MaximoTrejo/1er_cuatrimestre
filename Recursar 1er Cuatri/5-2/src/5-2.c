/*
 ============================================================================
Ejercicio 5-2:
Pedir el ingreso de 10 n�meros enteros entre -1000 y 1000. Determinar:
a) Cantidad de positivos y negativos.
b) Sumatoria de los pares.
c) El mayor de los impares.
d) Listado de los n�meros ingresados.
e) Listado de los n�meros pares.
f) Listado de los n�meros de las posiciones impares.
Anexo 5-2
g) Los n�meros que se repiten
h) Los positivos creciente y los negativos de manera decreciente
Se deber�n utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 10


int main(void) {
	setbuf(stdout,NULL);


	int numeros[TAM];


	pedirNum(numeros, TAM);



	return EXIT_SUCCESS;
}
