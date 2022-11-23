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
		printf("  ID          NOMBRE             CATEGORIA    TIEMPO   PROMEDIO");
		for(int i=0;i<len;i++)
		{
			pParticipante = (eParticipante*) ll_get(pArrayListParticipantes, i);
			ImprimirUnParticipante(pParticipante,i);
			retorno = 0;
		}
	}
    return retorno;
}

int controller_asignacionPromedios(LinkedList* pArrayListParticipantes)
{
 int retorno = -1;
 void (*pFunc)(void *element);

 if(pArrayListParticipantes != NULL)
 {
	 pFunc = asignarPromedios;
	 ll_map(pArrayListParticipantes, pFunc);
	 retorno = 0;
 }
 return retorno;
}

LinkedList* controller_filter(LinkedList* pArrayListParticipantes, LinkedList* pArrayListaParticipantesFiltrados)
{
	int opcion;

	int (*pFunc)(void *element);
	if (pArrayListParticipantes != NULL && !utn_getNumero(&opcion, "\nIngrese una Categoria(1-MX1 // 2-MX2 // 3-MX3 // 4-SUPER_ATV): ","\nError\n",1,4,3))
	{
		switch(opcion)
		{
			case 1:
				pFunc = filtroPorCategoriaMX1;
				break;
			case 2:
				pFunc = filtroPorCategoriaMX2;
				break;
			case 3:
				pFunc = filtroPorCategoriaMX3;
				break;
			case 4:
				pFunc = filtroPorCategoriaSuper_Atv;
				break;
		}
	pArrayListaParticipantesFiltrados = ll_filter(pArrayListParticipantes, pFunc);
	}
	return pArrayListaParticipantesFiltrados;
}

int controller_sort(LinkedList* pArrayListParticipantes)
{
	int retorno = -1;
	int (*pFunc)(void *element1, void *element2);

	if(pArrayListParticipantes != NULL)
	{
		pFunc = ordenarParticipantesPorCategoria;
		ll_sort(pArrayListParticipantes, pFunc, 1);
		retorno = 0;
	}
	return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListParticipantes)
{
	int retorno = -1;
	int len = ll_len(pArrayListParticipantes);
	int auxId;
	char auxNombre[AUX_LEN];
	char auxCategoria[AUX_LEN];
	float auxTiempo;
	float auxPromedio;
	eParticipante* pParticipante = NULL;
	FILE* pArchivo = fopen(path, "w");

	if(pArchivo != NULL && pArrayListParticipantes != NULL)
	{
		fprintf(pArchivo, "id,nombre,categoria,tiempo,promedio\n");
		for(int i=0;i<len;i++)
		{
			pParticipante = (eParticipante*) ll_get(pArrayListParticipantes, i);
			if(pParticipante != NULL && !participante_getId(pParticipante,&auxId) && !participante_getNombre(pParticipante,auxNombre) &&
					!participante_getCategoria(pParticipante, auxCategoria) && !participante_getTiempo(pParticipante,&auxTiempo) && !participante_getPromedio(pParticipante,&auxPromedio))
			{
				fprintf(pArchivo,"%d,%s,%s,%.2f,%.2f\n", auxId, auxNombre, auxCategoria, auxTiempo, auxPromedio);
			}
		}
		retorno = 0;
	}

	return retorno;
}

