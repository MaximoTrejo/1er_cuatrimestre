/*
 * Biblioteca.h
 *
 *  Created on: 11 oct. 2022
 *      Author: river
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int esNumerica(char* cadena, int limite);
int getInt(int* pResultado);
int esFlotante(char* cadena);
int getFloat(float* pResultado);
int getString(char* cadena, int longitud);
int esNombre(char* cadena,int longitud);
int getNombre(char* pResultado,int longitud);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char*, int,char*, char*, int);
int myGets(char* cadena, int longitud);
int PedirEntero (char mensaje[]);
float PedirFloat (char mensaje[]);
int PedirString (char mensaje[], char stringIngresado[], int reintentos);
int validarCodigoVuelo(char cadena[]);
int esSoloLetras(char str[]);
void menu();


#endif /* BIBLIOTECA_H_ */
