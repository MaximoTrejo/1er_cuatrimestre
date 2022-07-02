/*
 ============================================================================
 Name        : TrabajoPractico2-Trejo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
#include "arrayEmployees.h"

int main(void) {
	setbuf(stdout,NULL);
	//ESTRUCTURA
	Employee ArrayEmployees[EMPLOYEES_LEN];
//===================================================
	menuEmployee (ArrayEmployees,EMPLOYEES_LEN);

	return EXIT_SUCCESS;
}
