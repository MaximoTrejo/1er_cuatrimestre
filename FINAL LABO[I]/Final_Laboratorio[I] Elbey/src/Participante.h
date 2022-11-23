/*
 * Participante.h
 *
 *  Created on: 11 oct. 2022
 *      Author: river
 */

#ifndef PARTICIPANTE_H_
#define PARTICIPANTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Biblioteca.h"
#define AUX_LEN 500

typedef struct
{
	int id;
	char nombre[AUX_LEN];
	char categoria[AUX_LEN];
	float tiempo;
	float promedio;
}eParticipante;

eParticipante* participante_new();
eParticipante* participante_newParametros(char* idStr, char* nombreStr, char* categoriaStr, char* tiempoStr, char* promedioStr);
void participante_delete(eParticipante* this);

int participante_setId(eParticipante* this,int id);
int participante_getId(eParticipante* this,int* id);
int participante_setNombre(eParticipante* this,char* nombre);
int participante_getNombre(eParticipante* this,char* nombre);
int participante_setCategoria(eParticipante* this,char* categoria);
int participante_getCategoria(eParticipante* this,char* categoria);
int participante_setTiempo(eParticipante* this, float tiempo);
int participante_getTiempo(eParticipante* this,float* tiempo);
int participante_setPromedio(eParticipante* this, float promedio);
int participante_getPromedio(eParticipante* this,float* promedio);

int ordenarParticipantesPorCategoria(void* participante1, void* participante2);
void ImprimirUnParticipante(eParticipante* participante, int indice);
void asignarPromedios(void* participante);
int filtroPorCategoriaMX1(void* participante);
int filtroPorCategoriaMX2(void* participante);
int filtroPorCategoriaMX3(void* participante);
int filtroPorCategoriaSuper_Atv(void* participante);

#endif /* PARTICIPANTE_H_ */
