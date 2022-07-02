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

int utn_pedirCharAUsuario(char* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);
int utn_pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);
int utn_pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);

#endif /* UTN_BIBLIOTECA_H_ */
