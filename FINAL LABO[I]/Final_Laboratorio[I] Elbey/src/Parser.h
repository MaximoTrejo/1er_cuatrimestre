/*
 * Parser.h
 *
 *  Created on: 11 oct. 2022
 *      Author: river
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Participante.h"
#define AUX_LEN 500

int parser_FromText(FILE* pFile , LinkedList* pArrayListParticipantes);

#endif /* PARSER_H_ */
