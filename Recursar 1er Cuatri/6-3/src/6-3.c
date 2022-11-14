/*
 ============================================================================
Ejercicio 6-3:
Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el
apellido). Ninguna de las dos variables se puede modificar.
Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
Por ejemplo:
Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:
Gomez, Juan Ignacio



https://onlinegdb.com/NQOe34Kkp(codigo)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main(void) {

	setbuf(stdout,NULL);
	char nombre[20][1];
	char apellido[20][1];


	pedirDatos(nombre, apellido, TAM);
	mostrarVector(nombre, apellido, TAM);

	return EXIT_SUCCESS;
}
