/*
 * funciones.h
 *
 *  Created on: 3 abr. 2022
 *      Author: maxim
 */

#ifndef UTN_H_
#define UTN_H_

 /**
  * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \param mensaje Es el mensaje a ser mostrado
  * \param mensajeError Es el mensaje de Error a ser mostrado
  * \param minimo Es el numero maximo a ser aceptado
  * \param maximo Es el minimo minimo a ser aceptado
  * \return Retorna 0 si se obtuvo el numero y -1 si no
  */
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
/*Brief: Solicita el ingreso por teclado de un char
 * 1er parametro es puntero donde se guardará el char ingresado
 * 2do parametro es el mensaje de solicitud del dato al usuario
 * 3er parametro es el mensaje de error ante un intento erroneo de ingreso del char
 * 4to parametro es la cantidad de intentos que se le da al usuario
 * retorna 0 si se ingreso correctamente
 * retorna -1 si no pudo ingresar correctamente el char
 */
int utn_getCaracter(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
/**
  * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \param mensaje Es el mensaje a ser mostrado
  * \param mensajeError Es el mensaje de Error a ser mostrado
  * \param minimo Es el numero maximo a ser aceptado
  * \param maximo Es el minimo minimo a ser aceptado
  * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
  *
  */
int utn_getNumeroFloat (float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int myGetsInt(char *cadena,int longitud);
#endif /* UTN_H_ */
