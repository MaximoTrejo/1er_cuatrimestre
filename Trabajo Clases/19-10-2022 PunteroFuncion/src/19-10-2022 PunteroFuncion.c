/*
 ============================================================================
 Name        : 19-10-2022.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void sumar(int parametroA, int parametroB, int* pResultado);
void restar(int parametroA, int parametroB, int* pResultado);
void multiplicar(int parametroA, int parametroB, int* pResultado);
void dividir(int parametroA, int parametroB, int* pResultado );
int calculadora( int parametroA, int parametroB, void(*pFuncion)(int,int,int*));

int main(void)
{
    int auxiliar;//donde guardo el resultado

    auxiliar = calculadora(10 , 5 , restar);
    printf("El resultado de la resta es %d\n",auxiliar);

    auxiliar = calculadora(10 , 10 , sumar);
    printf("El resultado de la resta es %d\n",auxiliar);

    auxiliar = calculadora(10 , 0 , dividir);
    printf("El resultado de la divicion es %d\n",auxiliar);

    auxiliar = calculadora(10 , 2 , multiplicar);
    printf("El resultado de la multiplicacion es %d\n",auxiliar);

    return 0;
}

//funcion calcular (1er numero a calcular , 2do numero a calcular , funcion (puede tener cualquier nombre))
int calculadora( int parametroA, int parametroB, void(*pFuncion)(int,int,int*))
{
    int auxResultado = 0;//donde guardo el resultado

    pFuncion(parametroA , parametroB , &auxResultado);

    return auxResultado;
}

void sumar(int parametroA, int parametroB, int* pResultado)
{
    *pResultado = parametroA + parametroB;
}


void restar(int parametroA, int parametroB, int* pResultado)
{
    *pResultado = parametroA - parametroB;
}


void dividir(int parametroA, int parametroB, int* pResultado ){
	if(parametroA > 0 && parametroB > 0){
		*pResultado =parametroA / parametroB;
	}else{
		printf("no puede dividir por 0\n");
	}
}

void multiplicar(int parametroA, int parametroB, int* pResultado){
	*pResultado=parametroA * parametroB;
}


//https://www.onlinegdb.com/fork/mWah8gmmq
