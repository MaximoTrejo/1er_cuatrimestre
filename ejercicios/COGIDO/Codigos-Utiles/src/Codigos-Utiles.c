/*
 ============================================================================
 Name        : Codigos-Utiles.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//1)declaro funcion
int sumarNumeros(int numUno, int numDos); //prototipo o declaracion

int main(void) {
	setbuf(stdout, NULL);
	int numUno;
	int numDos;
	int suma; //creo una variable para guardar el resultado de la funcion
	//llamada a la funcion (la guarde en suma)

	printf("ingrese un num: ");
	fflush(stdin);//limpia el buffer
	scanf(" %d" , &numUno);
	printf("ingrese un num: ");
	fflush(stdin);
	scanf(" %d" , &numDos);
	suma = sumarNumeros(numUno, numDos);
	printf("El resultado es %d", suma);
	return EXIT_SUCCESS;
}

//2)implementacion o desarrollo
int sumarNumeros(int numUno, int numDos) {
	int resultado;	//como la variable sumar
	resultado = numUno + numDos;
	return resultado;	//retorna el resultado de la cuenta(sumar)
}
