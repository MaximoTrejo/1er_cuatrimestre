/*
 ============================================================================
Ejercicio 3-2:
Crear una función que permita determinar si un número es par o no. La función retorna 1 en caso
afirmativo y 0 en caso contrario. Probar en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



int FuncionParoImpar(int num);
int main(void) {
	setbuf(stdout,NULL);

	int num;

	printf("ingrese un numero");
	scanf("%d", &num);

	if(FuncionParoImpar(num)==1){
		printf("el numero es par ");
	}else{
		printf("el numero es impar ");
	}


	return EXIT_SUCCESS;
}


int FuncionParoImpar(int num){
	int retorno=0;
	if(num %2==0){
		retorno=1;
	}
	return retorno;
}
