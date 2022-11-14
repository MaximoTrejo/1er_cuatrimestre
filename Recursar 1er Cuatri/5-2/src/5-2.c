/*
 ============================================================================
Ejercicio 5-2:
Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
a) Cantidad de positivos y negativos.
b) Sumatoria de los pares.
c) El mayor de los impares.
d) Listado de los números ingresados.
e) Listado de los números pares.
f) Listado de los números de las posiciones impares.
Anexo 5-2
g) Los números que se repiten
h) Los positivos creciente y los negativos de manera decreciente
Se deberán utilizar funciones y vectores.
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
