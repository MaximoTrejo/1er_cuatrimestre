/*
 ============================================================================
 Name        : 10-05-22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//puntero a estructura
typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

/*
 * *(puntero)
[](array)

&intVar (muestra la primera posicion)
//-----------------------------------------
PUNTERO
guarda la direccion de memoria de otra variable "apunta a otra variable"
 */



void funcion(int*p1);
int main(void) {

	setbuf(stdout, NULL);
	//------------------------------
	//declaracion de un puntero
	int* pEntero = NULL;//siempre se inicializa en nulo
	//puntero a estructura
	//eFecha* pFechaNac = NULL;//(*)operador de indireccion
	//----------------------------------------------
	//ACEDER A UN PUNTERO (guerdar algo)
	int varEntera=5;
printf("------------MUESTRA EL VALOR DEL PUNTERO------------\n");
	printf("%p\n",pEntero);//me va a mostrar NULL //lo que esta cargado                                  /*
printf("-------MUESTRA LA DIRECCION DE MEMORIA DEL PUNTERO----------\n");								//*son 2 cosas distintas
	printf("%p\n",&pEntero);//me va a mostrar la direccion de memoria//puede mostrar cualquier cosa     */

	pEntero = &varEntera;//el & hace referencia a la dieccion de memoria //aca estoy guarddando la direccion de memoria de varEntero;


	//------------------------------------------------------------------------------------------------------------------------------------
	printf("-------MUESTRA EL VALOR DE LA VARIABLE (LO NORMAL)----------\n");
	printf("%d wooow\n",varEntera);//aca me muestra 5 (si le pongo el & es la direccion de memoria y no va a ser 5)
	printf("-------MUESTRA LA DIRECCION DE MEMORIA DE LA VARIABLE VAR ENTERA---------\n");
	printf("%p\n",pEntero);//aca estot mostrando la direccion de memoria de varEntero pero porque yo llene el dato en la linea 37
	//muestra direccion de memoria de pEntero
	printf("-------MUESTRO LA DIRECCION DE MEMORIA DEL PUNTERO----------\n");
	printf("%p\n",&pEntero);

	//--------------------------------
	*pEntero = 10;//puedo modificar el valor de la direccion de memoria que esta en varEntero
	printf("-------MUESTRO EL VALOR DE LA VARIABLE VAR ENTERA----------\n");
	printf("%d\n",*pEntero);//la %p es solo para la direccion de memoria //me da el valor de varEntero
	printf("-------MUESTRA EL VALOR DE VAR ENTERA----------\n");
	printf("%d wooow\n",varEntera); //modifico el valor por referencia
	//operador de direccion , devuelve el valor de la direccion de memoria
	//-----------------------------
	//aca le paso la direccion de memoria
	funcion(&varEntera);
	printf("-------MUESTRA EL VALOR DE LA VARIABLE VAR ENTERO Q FUE MODIFICADA POR REFERENCIA----------\n");
	printf("%d\n",varEntera);
//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//EJERCICIO
	//https://onlinegdb.com/YFfL9iL3W
//-----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * ARITMETICA DE PUNTEROS
 * https://onlinegdb.com/l_207jXhb
 */
//-----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * PUNTERO A ESTRUCTURA
 * https://onlinegdb.com/91GhvMTzl
 */
//-----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * PUNTERO A ARRAY DE ESTRUCTURA
 * https://onlinegdb.com/UYUmYhqRf
 */
//-----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * OPERADOR FECHA
 * https://onlinegdb.com/_HUuvZWXC
 */
	return EXIT_SUCCESS;
}
//aca modifico el valor de la direccion de memoria que pase por parametro y la modifico
void funcion(int*p1){
	*p1=3;
}
