/*
 * biblioteca.c
 *
 *  Created on: 18 sep. 2021
 *      Author: maxim
 */

#include "biblioteca.h"

//------------------------------------------------------------
int resultadoSuma(int numUno, int numDos)
{
	int suma;
	suma=numUno+numDos;
	return suma;
}
//------------------------------------------------------------
int resultadoResta(int numUno, int numDos){
	int resta;
	resta=numUno-numDos;
	return resta;
}
//------------------------------------------------------------
int resultadoDivision( int numUno, int numDos,float *resultadoDivision){
	int flag=0;
	if(numDos==0){
		flag=1;
	}else{
		*resultadoDivision=(float)numUno/numDos;
	}
	return flag;
}
//------------------------------------------------------------
int resultadoMultiplicar( int numUno, int numDos){
	int multiplicacion;
	multiplicacion=numUno*numDos;
	return multiplicacion;
}


//------------------------------------------------------------
void factorialA(int num1,int* resulFactorialA){

	int i;
	*resulFactorialA = 1;
	for(i = 1;i<=num1; i++){
		*resulFactorialA *= i;
	}
}

void factorialB(int num2,int* resulFactorialB){
	int i;
	*resulFactorialB = 1;
		for(i = 1;i<=num2; i++){
			*resulFactorialB *= i;
		}
}
//-------------------------------------------------------
void respuestas(int suma, int resta , int multiplicacion , int A ,int B , int facA ,int facB){

	printf("\nEl resultado de %d + %d es: %d" ,A,B,suma);
	printf("\nEl resultado de %d - %d es: %d",A,B,resta);
	printf("\nEl resultado de %d * %d es: %d",A,B, multiplicacion);
	printf("\nEl factorial de %d es: %d y El factorial de %d es: %d ",A,facA,B,facB);
}
