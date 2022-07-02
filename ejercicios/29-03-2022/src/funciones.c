/*
 * funciones.c
 *
 *  Created on: 2 abr. 2022
 *      Author: maxim
 */
#include "funciones.h"
/*
 Funcion usada para verificar el ingreso de caracteres.
 Chequea para que solo sean admitidas Los Letras S o N.
 Se ingresa void y le devuelve un entero sin signo
 O si se ingreso la N
 1 si se ingreso la s
 */
unsigned int verifica(void)// unsigned es para q saber q devuelve 0 o 1
{
	char letra;
	printf("Ingrese opcion.. .S/N?");
	//letra=toupper(getche());//toupper  pasa a mayuscula un caracter//solo (char) getche (para caracteres ,cuando presiono el caracter lo voy a ver en pantalla ) getch(no lo voy a ver en pantalla)
	scanf("%c",&letra);
	fflush(stdin);
	letra=toupper(letra);
	while(letra !='S' && letra !='N'){
		printf("\nHa ingresado opcion no valida... Reintente el ingreso(S/N)... ");
		//letra=toupper(getche());
		scanf("%c",&letra);
		fflush(stdin);//limpia el buffer
		letra=toupper(letra);
	}
	return (letra=='S');//
}

//preguntar letra=toupper(getche());
