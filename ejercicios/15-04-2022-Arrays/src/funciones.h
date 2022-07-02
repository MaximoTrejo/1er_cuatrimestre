/*
 * funciones.h
 *
 *  Created on: 3 abr. 2022
 *      Author: maxim
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);
int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos);

float promedioArray(int array[], int tam);
float promedioArrayV2(float *pPromedioResultado, int array[], int tam);
#endif /* FUNCIONES_H_ */
