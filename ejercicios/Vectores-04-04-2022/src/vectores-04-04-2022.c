/*
 ============================================================================
 Name        : vectores.c
 Author      : 
 Version     :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf (stdout, NULL);
	int vector[5];

	for(int i=0; i<5; i++)
	{
	    printf("Ingrese un numero: ");
	    scanf("%d", &vector[i]);
	}

	for(int i=0; i<5; i++)
	{
	   printf("%d\n", vector[i]);
	}

	return EXIT_SUCCESS;
}
