/*
 ============================================================================
 Name        : TrabajoPractico1-Trejo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void) {
	//Windows
	setbuf(stdout,NULL);
	//variables
	int numeroUno;
	int numeroDos;
	float resultadoDividir;
	int suma;
	int resta;
	int multiplicacion;
	int resulFactorialA;
	int resulFactorialB;
	//variable bucle
	char seguir;
	//bucle
	do {
		//pido los datos
		printf("Ingresar 1er operando\n");
		scanf("%d" , &numeroUno);
		printf("Ingresar 2do operando \n");
		fflush(stdin);
		scanf("%d" , &numeroDos);
		suma = resultadoSuma(numeroUno,numeroDos);
		resta = resultadoResta(numeroUno,numeroDos);
		if(resultadoDivision(numeroUno,numeroDos,&resultadoDividir)==1)
		{
			printf("Pusiste un numero q no se puede dividir");
		}else
		{
			printf("El resultado de %d / %d es: %f" ,numeroUno,numeroDos,resultadoDividir);
		}
		multiplicacion = resultadoMultiplicar(numeroUno,numeroDos);
		factorialA(numeroUno,&resulFactorialA);
		factorialB(numeroDos,&resulFactorialB);
		respuestas(suma, resta , multiplicacion ,numeroUno,numeroDos,resulFactorialA,resulFactorialB);
		//final del bucle
		printf("\n\nDesea continuar? (s | n) \n");
		fflush(stdin);
		scanf("%c",&seguir);
	}while(seguir == 's' || seguir =='S');

	return EXIT_SUCCESS;
}


