/*
 * Parser.c
 *
 *  Created on: 11 oct. 2022
 *      Author: river
 */
#include "Parser.h"

int parser_FromText(FILE* pFile, LinkedList* pArrayListParticipantes)
{
    int retorno = -1;
    int l = 0;
    eParticipante* auxParticipante = participante_new();
    char auxId[AUX_LEN];
    char auxNombre[AUX_LEN];
    char auxCategoria[AUX_LEN];
    char auxTiempo[AUX_LEN];
    char auxPromedio[AUX_LEN];

    if(pFile != NULL && pArrayListParticipantes != NULL)
    {
         l =fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxCategoria, auxTiempo,auxPromedio); //voy a leer los titulos
        while(!feof(pFile))
        {
            l = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxCategoria, auxTiempo,auxPromedio); //leemos los equipos
            if(l == 5 && auxParticipante != NULL)
            {
            	auxParticipante = participante_newParametros(auxId, auxNombre, auxCategoria, auxTiempo,auxPromedio);
                if(auxParticipante != NULL )
                {
                	ll_add(pArrayListParticipantes, auxParticipante);
                    retorno = 0;
                }
            }
            else
            {
                break;
				retorno=-1;
            }
        }
    }
    return retorno;
}

