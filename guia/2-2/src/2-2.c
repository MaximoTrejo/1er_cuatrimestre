/*
 ============================================================================
 Name        : 2-2.c
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
		int numeros;//numeros con coma
		int i;//enteros
		int contadorPar=0;
		int contadorImpar=0;
		int menNumIngresado;
		int mayNumPar=0;
		int sumaPos=0;
		int producN=1;

		//pido los numeros con un bucle for (si se la cantidad for sino la se do while)
		for(i=0;i<10;i++)
		{
			printf("Ingrese un numero:");
			scanf(" %d", &numeros);

			if(numeros<menNumIngresado){
				menNumIngresado=numeros;
			}

			if(numeros%2 == 0){
				contadorPar++;
				if(numeros>mayNumPar){
					mayNumPar=numeros;
				}
			}else{
				contadorImpar++;
			}

			if(numeros>0){
				sumaPos=sumaPos+numeros;
			}else{
				producN=producN*numeros;
			}
		}
		printf("\nEl menor número ingresado %d",menNumIngresado);
		printf("\nLa cantidad de numeros pares es %d y la de impares es %d",contadorPar,contadorImpar);
		printf("\nEl menor número par ingresado %d",mayNumPar);
		printf("\nLa suma de los positivos es %d",sumaPos);
		printf("\nEl producto de los negativos es  %d",producN);


	return EXIT_SUCCESS;
}
