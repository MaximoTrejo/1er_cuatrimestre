/*
 ============================================================================
 Name        : dfgdffgh.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int f1(int *a);
void f2(int *a , int b);
int main(void) {

	int a=2,b=2;
	f2(&a,b);
	printf("%d,%d",a,b);
	return EXIT_SUCCESS;
}

int f1(int *a){
	*a=*a**a;
	return *a;

}
void f2(int *a , int b){
	b=f1(a) * f1(&b);
}

