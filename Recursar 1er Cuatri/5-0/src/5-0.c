/*
 ============================================================================
Pedir cinco n�meros y mostrarlos desde el �ltimo que pedi hasta el primero
Por ejemplo:
Ped�
3-5-2-4-7
Tengo que devolver
7-4-2-5-3
Haganlo con todo lo que saben hasta ahora.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main(void) {
	setbuf(stdout,NULL);

	int array[TAM];
	int i;

	for(i=0;i<TAM;i++){
		printf("ingresa un numero");
		scanf("%d", &array[i]);
	}

	for(int y=TAM;y>0;y--){
		printf("%d-",array[y-1]);
	}

	return EXIT_SUCCESS;
}
