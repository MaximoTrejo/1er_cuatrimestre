/*
 * arrayEmpoyees.h
 *
 *  Created on: 10 oct. 2021
 *      Author: maxim
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
//---------------------------------------
#define EMPLOYEES_LEN 20
#define EMPLOYEES_NAME_LASNAME 51
#define OCUPADO 0
#define VACIO 1
#define INTENTOS 3

typedef struct{
	int id;//tipo
	float salary;//precio
	int sector;//id
	char name[51];//nombre
	char lasName[51];// direccion
	//-----------------------------------
	int isEmpty;//bandera //0:ocupado  1:vacio/libre
}Employee; //pantalla


/*brief Para indicar que todas las posiciones en la matriz esten vacias, esta funciin coloca la bandera (isEmpty) en VERDADERO en todas las posiciones de la matriz
 *\param list Employee[] Puntero a la variedad de empleados
 *\param len int Longitud de la matriz
 *\return int Return (-1) si Error - (1) si esta bien
 */
int initEmployees(Employee list[], int len);

/*brief Agregar en una lista existente de empleados los valores recibidos como parametros en la primera posiciin vacia
 *\param list employee* es el punto de mi array del main
* \return int Return (-1) si Error - (0) si esta bien*/
int addEmployee(Employee* list);

/*\brief Busca un empleado en el array
* \param list Employee* pasa la array
* \param len int pasa el tamaño de la array
* \return Return devuelve la ID*/
int findEmployeeById(Employee* list, int len,int id);

/*\brief Elimina de manera  logica (isEmpty Flag en 1) un empleado recibiendo como parametro su Id.
* \param list Employee* pasa la array
*/
void removeEmployee(Employee* list, int len);

/*
  \ brief Busca un lugar vacio en el array y lo carga en esa posicion
* \ param list Emplloyee *
*/
void alta(Employee* list);

/*
  \ brief Busca un lugar vacio en el array y lo carga en esa posicion
* \ param list Emplloyee *
* \param len int pasa el tamaño de la array
*/
void modificarMenu(Employee* list , int len);

/*
  \ brief imprime una sola posicion del array
* \ param list Emplloyee *
* \param len int pasa el tamaño de la array
  \Return (-1) si Error - (0) si esta bien
*/
int imprimirPantalla(Employee* list ,int len );

/*
 * \brief se fija si la posicion del array esta ocupada o no .Y si no lo esta muestra una posicion del array
 * \param list Emplloyee *
 * \param len int pasa el tamaño de la array
 * return retorna [-1] Error o retorna[0] Exito
 */
int cli_imprimir(Employee* list);

/** \brief  busca en el campo isEmpty del array, con 0 para saber que esta libre
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return retorna [-1] Error o retorna[1] Exito
*/
int buscarLibreR (Employee* list, int len,int *posicion);

/*
  \ brief Busca un lugar libre del array
* \ param list Emplloyee *
* \ param len int
* \ param id
* \ param pFoundDisplayPosition
* \ return retorno [-1]ERROR , retorno[1]EXITO
*/
int buscarPorId (Employee list[], int len, int id, int* pFoundDisplayPosition);

/*
  \ brief subMenu del menu , pide los campos para modificar
* \ param list Emplloyee *
* \ return status [-1]ERROR , status[1]EXITO
*/
int modificarOpciones(Employee* list);

/*
  \ brief menu principal ,muestra 4 opciones
* \ param list Emplloyee *
* \ param len int
*/
void menuEmployee (Employee list[], int len);

/*
  \ brief Hace el promedio de las posiciones del array que no estan ocupadas .Hace el total de salarios ingresados.Cuenta cuantos sueldos son mayor al promedio
* \ param *array
* \ param int len
* \ return estado ERROR[-1] EXITO[0]
*/
int promedio(Employee* array , int len);

/*
  \ brief Ordena el array de cliente por nombre
* \ param array Array de clientes
* \ param limite limite del array de clientes
* \ return retorna el incide de la posicion vacia y -1[error]
*/
int cli_ordenarPorNormbre(Employee *array , int limite);


#endif /* ARRAYEMPLOYEES_H_ */
