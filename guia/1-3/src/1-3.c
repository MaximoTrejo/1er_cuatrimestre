/*
 ============================================================================
 Name        : 3er.c
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
	int numUno;//declaro la variable
	int numDos;//declaro la variable
	int numTres;
	printf("Ingresa un numero:");//printf sirve para imprimir en pantalla
	scanf("%d", &numUno);//scanf para guardar el dato (uso el & para guardarlo en una direccion de memoria)
	printf("Ingresa otro numero:");
	scanf("%d", &numDos);
	printf("Ingresa otro numero:");
	scanf("%d", &numTres);

	/*
	 PASOS
	 1-ver si son distintos (si los 3 o 2 son iguales no hay numero del medio)
	 2-comparar los 3 numeros para saber cual es el del medio
	 3-mostrar un mensaje por si son iguales
	 */

	if(numUno!=numDos && numUno!=numTres && numDos!= numTres){ //todos son distintos
		if((numUno>numDos && numUno<numTres)||(numUno<numDos && numUno>numTres)){
			printf("El numero del medio es %d",numUno);
		}else if((numDos>numUno && numDos<numTres)||(numDos<numUno && numDos>numTres)){
			printf("El numero del medio es %d",numDos);
		}else{
			printf("El numero del medio es %d",numTres);
		}
	}else{
		printf("Hay numeros repetidos");
	}

	/*
	 LOGICA
	 Si numUno es mayor a numDos y si numUno es menor a numTres el numero del medio es numUNO y
	 el otro verificas que numDos y numTres no sean mayores o menores a numUno
	 (porque sino numUno no seria el del medio)
	 */






	return EXIT_SUCCESS;
}
