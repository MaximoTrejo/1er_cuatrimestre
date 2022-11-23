/*
 * Participante.c
 *
 *  Created on: 11 oct. 2022
 *      Author: river
 */
#include "Participante.h"

eParticipante* participante_new()
{
	eParticipante* nuevoParticipante = (eParticipante*) malloc(sizeof(eParticipante));
	return nuevoParticipante;
}

eParticipante* participante_newParametros(char* idStr, char* nombreStr, char* categoriaStr, char* tiempoStr, char* promedioStr)
{
	eParticipante* participanteNuevo = participante_new();

	if(participanteNuevo != NULL && !participante_setId(participanteNuevo, atoi(idStr)) && !participante_setNombre(participanteNuevo, nombreStr) &&
			!participante_setCategoria(participanteNuevo, categoriaStr) && !participante_setTiempo(participanteNuevo, atof(tiempoStr)) && !participante_setPromedio(participanteNuevo,atof(promedioStr)))
	{
	}
	else
	{
		participante_delete(participanteNuevo);
	}

	return participanteNuevo;
}

void participante_delete(eParticipante* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int participante_setId(eParticipante* this,int id)
{
	int retorno = -1;

	if(this != NULL && id != -1)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int participante_getId(eParticipante* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int participante_setNombre(eParticipante* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int participante_getNombre(eParticipante* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int participante_setCategoria(eParticipante* this,char* categoria)
{
	int retorno = -1;
	if(this != NULL && categoria != NULL)
	{
		strcpy(this->categoria, categoria);
		retorno = 0;
	}
	return retorno;
}

int participante_getCategoria(eParticipante* this,char* categoria)
{
	int retorno = -1;

	if(this != NULL && categoria != NULL)
	{
		strcpy(categoria, this->categoria);
		retorno = 0;
	}
	return retorno;
}

int participante_setTiempo(eParticipante* this, float tiempo)
{
	int retorno = -1;

	if(this != NULL && tiempo != -1)
	{
		this->tiempo = tiempo;
		retorno = 0;
	}

	return retorno;
}

int participante_getTiempo(eParticipante* this,float* tiempo)
{
	int retorno = -1;

	if(this != NULL && tiempo != NULL)
	{
		*tiempo = this->tiempo;
		retorno = 0;
	}

	return retorno;
}

int participante_setPromedio(eParticipante* this, float promedio)
{
	int retorno = -1;

	if(this != NULL && promedio != -1)
	{
		this->promedio = promedio;
		retorno = 0;
	}

	return retorno;
}

int participante_getPromedio(eParticipante* this,float* promedio)
{
	int retorno = -1;

	if(this != NULL && promedio != NULL)
	{
		*promedio = this->promedio;
		retorno = 0;
	}

	return retorno;
}

void ImprimirUnParticipante(eParticipante* participante, int indice)
{
	int auxId;
	char auxNombre[AUX_LEN];
	char auxCategoria[AUX_LEN];
	float auxTiempo;
	float auxPromedio;

	if(participante != NULL && !participante_getId(participante, &auxId) && !participante_getNombre(participante, auxNombre) &&
		!participante_getCategoria(participante, auxCategoria) && !participante_getTiempo(participante, &auxTiempo) && !participante_getPromedio(participante, &auxPromedio))
		{
			printf("\n| %-4d| %-20s| %-15s| %5.2f| %-10.2f|",
					auxId, auxNombre, auxCategoria, auxTiempo, auxPromedio);
		}
}

int filtroPorCategoriaMX1(void* participante)
{
	int retorno = -1;
	char auxCategoria[AUX_LEN];

	if(!participante_getCategoria((eParticipante*)participante, auxCategoria))
	{
		if(strcmp(auxCategoria, "MX1") != 0)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int filtroPorCategoriaMX2(void* participante)
{
	int retorno = -1;
	char auxCategoria[AUX_LEN];

	if(!participante_getCategoria((eParticipante*)participante, auxCategoria))
		{
			if(strcmp(auxCategoria, "MX2") != 0)
			{
				retorno = 0;
			}
		}

	return retorno;
}

int filtroPorCategoriaMX3(void* participante)
{
	int retorno = -1;
	char auxCategoria[AUX_LEN];

	if(!participante_getCategoria((eParticipante*)participante, auxCategoria))
		{
			if(strcmp(auxCategoria, "MX3") != 0)
			{
				retorno = 0;
			}
		}

	return retorno;
}

int filtroPorCategoriaSuper_Atv(void* participante)
{
	int retorno = -1;
	char auxCategoria[AUX_LEN];

	if(!participante_getCategoria((eParticipante*)participante, auxCategoria))
		{
			if(strcmp(auxCategoria, "SUPER_ATV") != 0)
			{
				retorno = 0;
			}
		}

	return retorno;
}

void asignarPromedios(void* participante)
{
	float auxTiempo;

	if(!participante_getTiempo((eParticipante*) participante, &auxTiempo))
	{
		if(auxTiempo < 15)
		{
			participante_setPromedio((eParticipante*) participante, 6);
		} else if(auxTiempo > 14 && auxTiempo <= 20 ){
			participante_setPromedio((eParticipante*) participante, 8);
			}else if(auxTiempo > 20){
			participante_setPromedio((eParticipante*) participante, 10);
				}
	}
}

int ordenarParticipantesPorCategoria(void* participante1, void* participante2)
{
	int retorno = 0;
	char categoriaParticipante1[AUX_LEN];
	char categoriaParticipante2[AUX_LEN];

	if(participante1 != NULL && participante2 != NULL &&
		!participante_getCategoria(participante1, categoriaParticipante1) && !participante_getCategoria(participante2, categoriaParticipante2))
	{
		if(strcmp(categoriaParticipante1, categoriaParticipante2) > 0)
		{
			retorno = 1;
		}
		else if(strcmp(categoriaParticipante1, categoriaParticipante2) < 0)
		{
			retorno = -1;
		}
	}
	return retorno;
}

