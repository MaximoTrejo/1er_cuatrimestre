/*
 ============================================================================
 Name        : dfgdfg.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *p;//no pasa nada si no se usa
	char cad[]="fichero.txt";
	char op[]="w";
	p=fopen(cad,op);


	return EXIT_SUCCESS;

}

