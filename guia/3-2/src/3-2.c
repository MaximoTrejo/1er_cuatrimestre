/*
 ============================================================================
 Name        : 3-2.c
 Author      : MaximoTrejo
 Version     :Crear una función que permita determinar si un número es par o no. La función retorna 1 en caso afirmativo y 0 en caso contrario. Probar en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int parOimpar(int num);

int main(void) {
	setbuf(stdout,NULL);

	int num;
	int confirmar;
	printf("ingrese un num: ");
	fflush(stdin);
	scanf(" %d", &num);

	confirmar =parOimpar(num);
	if(confirmar==1){
		printf("el numero es par");
	}else{
		printf("el numero es impar");
	}


	return EXIT_SUCCESS;
}

int parOimpar(int num){
	int vuelta;
	if(num%2 == 0){
		vuelta=1;
	}else{
		vuelta=0;
	}
	return vuelta;
}
