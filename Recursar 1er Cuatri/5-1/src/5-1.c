/*
 ============================================================================
Ejercicio 5-1:
Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5


int main(void) {
	setbuf(stdout,NULL);

int numeros[TAM];
int sumar=0;//siempre inicializar todo en 0

for(int i=0;i<TAM;i++){

	printf("ingrese un numero");
	scanf("%d",&numeros[i]);

	sumar=sumar+numeros[i];

}

printf("%d",sumar);

	return EXIT_SUCCESS;
}
