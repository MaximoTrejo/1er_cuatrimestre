/*
 * libro.h
 *
 *  Created on: 23 nov 2022
 *      Author: alumno
 */

#ifndef LIBRO_H_
#define LIBRO_H_


typedef struct
{
	int id;
	char titulo[100];
	float importe;
	int idTipo;

}eLibro;

eLibro * list_new();
eLibro* list_newParametros(char* idStr,char* tituloStr,char* importeStr, char* idTipoStr);

int lib_setId(eLibro* this,int id);
int lib_getId(eLibro* this,int* id);

int lib_setTitulo(eLibro* this,char* titulo);
int lib_getTitulo(eLibro* this,char* titulo);

int lib_setImporte(eLibro* this,float importe);
int lib_getImporte(eLibro* this,float* importe);

int lib_setIdTipo(eLibro* this,int idTipo);
int lib_getIdTipo(eLibro* this,int* idTipo);

int lib_compareImporte(void* p1 ,void*p2);
void aumentoPrecio(void* this);

#endif /* LIBRO_H_ */
