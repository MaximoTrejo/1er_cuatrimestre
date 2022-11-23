/*
 * Controller.h
 *
 *  Created on: 11 oct. 2022
 *      Author: river
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "Biblioteca.h"
#include "Parser.h"
#include "Participante.h"

int controller_loadFromText(char* path,LinkedList* pArrayListParticipantes);
int controller_ListParticipantes(LinkedList* pArrayListParticipantes);
LinkedList* controller_filter(LinkedList* pArrayListParticipantes, LinkedList* pArrayListaParticipantesFiltrados);
int controller_saveAsText(char* path , LinkedList* pArrayListParticipantes);

#endif /* CONTROLLER_H_ */
