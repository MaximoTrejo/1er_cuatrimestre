/*
 ============================================================================
 Name        : sdfsdf.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *a;
	int *b;
	int c;;

	int auxa=2;
	int auxb=3;


	a=&auxa;
	b=&auxb;
	c=4;

	a=b;


printf("%d,%d,%d",*a,*b,c);
return EXIT_SUCCESS;

}
