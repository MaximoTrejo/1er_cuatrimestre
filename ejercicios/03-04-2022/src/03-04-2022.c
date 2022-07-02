/*
 ============================================================================
 Name        : 03-04-2022.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int dividir (float*pResultado,int operador1,int operador2);

int main(void) {

	setbuf(stdout,NULL);
	//variables
	float resultado;
	int numero1;
	int numero2;
	int respuesta;
	//pido datos
	printf("Numero 1?");
	scanf("%d", &numero1);
	printf("Numero 2?");
	scanf("%d", &numero2);
	//llamo a funcion
	respuesta =dividir(&resultado,numero1,numero2);//si lo veo en un ejemplo el & es la columna y el * es la fila (osea el dato en si)
	//respuesta
	if(respuesta==0){
		printf("El resultado es: %f",resultado);
	}else{
		printf("No es posible dividir por cero");
	}

	return EXIT_SUCCESS;
}

/*

 Si quisiera buscar algo tendria q decir en la columna1(&)  y fila2(*) esta LIBRO

 ---> &
|	 : COLUMNA 1 | COLUMNA 2 | COLUMNA 3 |
v	 1
*	 2  LIBRO
	 3
	 4
	 5


 */

//aca seria que estoy llamando a la fila(el casillero especifico) de ese dato
int dividir (float*pResultado,int operador1,int operador2){

	float resultado;
	int retorno=-1;//ERROR (se inicializa con el error para cambiarlo solo si la funcion es correcta)
	if(pResultado !=NULL && operador2 != 0){ //cada vez que resivo un puntero verifico q sea != NULL
		resultado=(float) operador1/operador2;
		*pResultado = resultado;
		retorno=0;//solo se cambia si la funcion es la correcta
	}
	return retorno;
}
