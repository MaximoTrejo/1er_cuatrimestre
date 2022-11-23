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
	int edad;
	int idCategoria;
	int score;
}eParticipante;

eParticipante* participante_new();
eParticipante* participante_newParametros(char* idStr, char* nombreStr, char* edadStr, char* idCategoriaStr, char* scoreStr);
void participante_delete(eParticipante* this);

int participante_setId(eParticipante* this,int id);
int participante_getId(eParticipante* this,int* id);
int participante_setNombre(eParticipante* this,char* nombre);
int participante_getNombre(eParticipante* this,char* nombre);
int participante_setEdad(eParticipante* this, int edad);
int participante_getEdad(eParticipante* this,int* edad);
int participante_setIdCategoria(eParticipante* this, int idCategoria);
int participante_getIdCategoria(eParticipante* this,int* idCategoria);
int participante_setScore(eParticipante* this, int score);
int participante_getScore(eParticipante* this,int* score);

int ordenarEquiposPorScore(void* participante1, void* participante2);
void ImprimirUnParticipante(eParticipante* participante, int indice);
int filtroPorIdCategoriaMenor(void* participante);
int filtroPorIdCategoriaMayor(void* participante);

#endif /* PARTICIPANTE_H_ */
