/*
 * Controller.c
 *
 *  Created on: 11 oct. 2022
 *      Author: river
 */
#include "Controller.h"

int controller_loadFromText(char* path ,LinkedList* pArrayListParticipantes)
{
	int retorno = -1;
	FILE* pArchivo = fopen(path,"r");

	if(pArchivo != NULL && pArrayListParticipantes != NULL && !parser_FromText(pArchivo, pArrayListParticipantes))
	{
		retorno = 0;
	}
	else
	{
		printf("\n\nError en la carga de este archivo!");
	}
	fclose(pArchivo);
    return retorno;
}

int controller_ListParticipantes(LinkedList* pArrayListParticipantes)
{
	int retorno = -1;
	int len;
	eParticipante* pParticipante;

	len = ll_len(pArrayListParticipantes);
	if(pArrayListParticipantes != NULL)
	{
		printf("  ID                     NOMBRE                             EDAD  DESCRIP        SCORE");
		for(int i=0;i<len;i++)
		{
			pParticipante = (eParticipante*) ll_get(pArrayListParticipantes, i);
			ImprimirUnParticipante(pParticipante,i);
			retorno = 0;
		}
	}
    return retorno;
}

LinkedList* controller_filter(LinkedList* pArrayListParticipantes, LinkedList* pArrayListaParticipantesFiltrados)
{
	int opcion;

	int (*pFunc)(void *element);
	if (pArrayListParticipantes != NULL && !utn_getNumero(&opcion, "\nIngrese una Categoria(1-Menor // 2-Mayor): ","\nError\n",1,2,3))
	{
		switch(opcion)
		{
			case 1:
				pFunc = filtroPorIdCategoriaMenor;
				break;
			case 2:
				pFunc = filtroPorIdCategoriaMayor;
				break;
		}
	pArrayListaParticipantesFiltrados = ll_filter(pArrayListParticipantes, pFunc);
	}
	return pArrayListaParticipantesFiltrados;
}

int controller_saveAsText(char* path , LinkedList* pArrayListParticipantes)
{
	int retorno = -1;
	int len = ll_len(pArrayListParticipantes);
	int auxId;
	char auxNombre[AUX_LEN];
	int auxEdad;
	int auxIdCategoria;
	int auxScore;
	eParticipante* pParticipante = NULL;
	FILE* pArchivo = fopen(path, "w");

	if(pArchivo != NULL && pArrayListParticipantes != NULL)
	{
		fprintf(pArchivo, "id,nombre,edad,idCategoria,score\n");
		for(int i=0;i<len;i++)
		{
			pParticipante = (eParticipante*) ll_get(pArrayListParticipantes, i);
			if(pParticipante != NULL && !participante_getId(pParticipante,&auxId) && !participante_getNombre(pParticipante,auxNombre) &&
					!participante_getEdad(pParticipante, &auxEdad) && !participante_getIdCategoria(pParticipante,&auxIdCategoria) && !participante_getScore(pParticipante,&auxScore))
			{
				fprintf(pArchivo,"%d,%s,%d,%d,%d\n", auxId, auxNombre, auxEdad, auxIdCategoria, auxScore);
			}
		}
		retorno = 0;
	}

	return retorno;
}

