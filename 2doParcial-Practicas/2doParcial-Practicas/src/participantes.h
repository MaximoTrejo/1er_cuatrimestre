/*
 * participantes.h
 *
 *  Created on: 20 nov 2022
 *      Author: maxim
 */

#ifndef PARTICIPANTES_H_
#define PARTICIPANTES_H_


typedef struct
{
	int id;
	char nombre[100];
	char categoria[30];
	int tiempo;
	float promedio;

}eParticipantes;


eParticipantes * list_new();
eParticipantes* list_newParametros(char* idStr,char* nombreStr,char* categoriaStr, char* tiempoStr, char* promedioStr);
int par_setId(eParticipantes* this,int id);
int par_getId(eParticipantes* this,int* id);
int par_setNombre(eParticipantes* this,char* nombre);
int par_getNombre(eParticipantes* this,char* nombre);
int par_setCategoria(eParticipantes* this,char* categoria);
int par_getCategoria(eParticipantes* this,char* Categoria);
int par_setTiempo(eParticipantes* this,int tiempo);
int par_getTiempo(eParticipantes* this,int*tiempo);
int par_setPromedio(eParticipantes* this,float promedio);
int par_getPromedio(eParticipantes* this,float*promedio);



void asignarPromedio(void* this);
int filtrarTipoMX1(void* this);
int par_compareCategoria(void* p1 ,void*p2);


#endif /* PARTICIPANTES_H_ */
