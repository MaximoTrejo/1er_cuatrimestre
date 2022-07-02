/*
 * Alumno.h
 *
 *  Created on: 17 abr. 2022
 *      Author: MaximoTrejo
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

//ESTRUCTURAS
typedef struct
{
		int legajo;
		char nombre[51];
		float altura;
		int isEmpty;
}Alumno;

/*
* \brief Imprino el array de alunnos
* \paran pArray Punter0 al array de alumnos
* \paran longitud Define el tamaño del array
* \return Retorna 0 (EXITO) si OK y -1 (ERROR)
*/
int imprimirArray(Alumno*pArray , int limite);

/*
 * \brief Inicializo el array de alunnos
 * \paran parray Puntero al array de alumnos
 * \paran langitud Define el tamaño del array
 * \return Retona 0 (EXITO) si OK y -1 (ERRÖR)
 */
int inicializoArray(Alumno*pArray , int limite);
#endif /* ALUMNO_H_ */
