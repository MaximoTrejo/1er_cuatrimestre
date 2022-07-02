/*
 ============================================================================
 Name        : 2-1.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);//para que funcione bien la consola(IMPORTANTE)
	//DECLARO LAS VARIABLES
	float numeros;//numeros con coma
	int i;//enteros
	float suma;//numeros con coma(declaro una valiable para poder sumar todos los numeros ingresados)

	//pido los numeros con un bucle for (si se la cantidad for sino la se do while)
	for(i=0;i<5;i++)
	{
		printf("Ingrese un numero: ");
		scanf(" %f", &numeros);
		/*
		LOGICA
		entra un numero y se guarda en suma ,entra otro numero y suma (que ya tenia guardado el numero anterior
		se suma con el nuevo numero)
		*/
		suma=suma+numeros;
	}
	 printf("el promedio es %f" , suma/i);

	return EXIT_SUCCESS;
}
