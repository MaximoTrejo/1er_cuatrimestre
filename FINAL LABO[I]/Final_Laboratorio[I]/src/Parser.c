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
    char auxEdad[AUX_LEN];
    char auxIdCategoria[AUX_LEN];
    char auxScore[AUX_LEN];

    if(pFile != NULL && pArrayListParticipantes != NULL)
    {
         l =fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxEdad, auxIdCategoria,auxScore); //voy a leer los titulos
        while(!feof(pFile))
        {
            l = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxEdad, auxIdCategoria,auxScore); //leemos los equipos
            if(l == 5 && auxParticipante != NULL)
            {
            	auxParticipante = participante_newParametros(auxId, auxNombre, auxEdad, auxIdCategoria,auxScore);
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

