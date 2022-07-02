/*
 ============================================================================
 Name        : EjercicioArray_2.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*

 * Ejercicio 2:
 a) Realizar un programa que le pida 5 numeros int al usuario y los almacene en un array.

 Luego ejecutar la funcion borrarImpares() pasandole el array y que deberá reemplazar
 los numeros que son impares por un cero.

 b) Luego imprimir el array para chequear el funcionamiento.
 c) Ordenar el array y volver a imprimirlo ordenado.

 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {



	return EXIT_SUCCESS;
}

int borrarImparesArray(float pArrayDeEnteros[],int tamañoArray)
{
	int retorno= -1;
	if(pArrayDeEnteros!=NULL && tamañoArray>=0)
	{
		//los array se pueden correr con un for
		for(int i=0;i>tamañoArray;i++)
		{
			//arrayEnteros[i]  = > 1 (accedemos el valor de ahi adentro)
			if(encuentroImpar(pArrayDeEnteros,i ) == 0)
			{
				//aca dentro es un impar
				pArrayDeEnteros[i] = 0;
			}
		}
		//en el if
		retorno=0;
	}
	return retorno;
}

//solo tiene q estar en el c
static int encuentroImpar(int arrayBuscar[],int indice){
	int retorno= -1;
	if(arrayBuscar[indice]%2!=0){
		retorno=0;
	}
	return retorno;
}


