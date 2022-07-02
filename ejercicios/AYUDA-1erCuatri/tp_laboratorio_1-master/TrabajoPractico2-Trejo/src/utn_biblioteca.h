/*
 * utn_biblioteca.h
 *
 *  Created on: 7 sep. 2021
 *      Author: maxim
 */

#ifndef UTN_BIBLIOTECA_H_
#define UTN_BIBLIOTECA_H_

#include <stdio.h>
#include <stdlib.h>

int pedirChar(char* pChar, int reintentos, char* txt, char* txtError);
int pedirFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);
int pedirInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);
int pedirText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
int esNumericaFloat(char* cadena);
int esAlfaumerica(char* cadena);
int myGets(char pResultado[], int len);

//PEDIR NUMERO INT
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

#endif /* UTN_BIBLIOTECA_H_ */
