/*
 ============================================================================
 Name        : 17-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char descripcion[20];
	float precio;
	int stock;
}eProducto;

eProducto * hardcodear();

int main(void) {

	eProducto * pProducto;

	pProducto =hardcodear();


	//aritmetica de punteros
	printf("%s --- %f --- %d\n",(*pProducto).descripcion,(*pProducto).precio,(*pProducto).stock);//muestra el precio y el stock
	printf("%s --- %f --- %d\n",(*pProducto).descripcion,(*pProducto).precio,(*pProducto).stock);//muestra basura
	printf("%s --- %f --- %d\n",(*pProducto).descripcion,(*pProducto).precio,(*pProducto).stock);//muestra basura
	printf("%s --- %f --- %d\n",(*pProducto).descripcion,(*pProducto).precio,(*pProducto).stock);//muestra basura
	printf("%s --- %f --- %d\n",(*pProducto).descripcion,(*pProducto).precio,(*pProducto).stock);//muestra basura


	return EXIT_SUCCESS;
}


eProducto * hardcodear(){
	eProducto auxProducto;
	eProducto * pProducto;

	strcpy(auxProducto.descripcion,"iphone");
	auxProducto.precio =1000;
	auxProducto.stock=25;

	pProducto =&auxProducto;

	return pProducto;
}
