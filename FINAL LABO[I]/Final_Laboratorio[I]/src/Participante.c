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

eParticipante* participante_newParametros(char* idStr, char* nombreStr, char* edadStr, char* idCategoriaStr, char* scoreStr)
{
	eParticipante* participanteNuevo = participante_new();

	if(participanteNuevo != NULL && !participante_setId(participanteNuevo, atoi(idStr)) && !participante_setNombre(participanteNuevo, nombreStr) &&
			!participante_setEdad(participanteNuevo, atoi(edadStr)) && !participante_setIdCategoria(participanteNuevo, atoi(idCategoriaStr)) && !participante_setScore(participanteNuevo,atoi(scoreStr)))
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

int participante_setEdad(eParticipante* this, int edad)
{
	int retorno = -1;

	if(this != NULL && edad != -1)
	{
		this->edad = edad;
		retorno = 0;
	}

	return retorno;
}

int participante_getEdad(eParticipante* this,int* edad)
{
	int retorno = -1;

	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;
		retorno = 0;
	}

	return retorno;
}

int participante_setIdCategoria(eParticipante* this, int idCategoria)
{
	int retorno = -1;

	if(this != NULL && idCategoria != -1)
	{
		this->idCategoria = idCategoria;
		retorno = 0;
	}

	return retorno;
}

int participante_getIdCategoria(eParticipante* this,int* idCategoria)
{
	int retorno = -1;

	if(this != NULL && idCategoria != NULL)
	{
		*idCategoria = this->idCategoria;
		retorno = 0;
	}

	return retorno;
}

int participante_setScore(eParticipante* this, int score)
{
	int retorno = -1;

	if(this != NULL && score != -1)
	{
		this->score = score;
		retorno = 0;
	}

	return retorno;
}

int participante_getScore(eParticipante* this,int* score)
{
	int retorno = -1;

	if(this != NULL && score != NULL)
	{
		*score = this->score;
		retorno = 0;
	}

	return retorno;
}

int ordenarEquiposPorScore(void* participante1, void* participante2)
{
	int retorno = 0;
	int scoreParticipante1;
	int scoreParticipante2;

	if(participante1 != NULL && participante2 != NULL &&
		!participante_getScore(participante1, &scoreParticipante1) && !participante_getScore(participante2, &scoreParticipante2))
	{
		if(scoreParticipante1<scoreParticipante2)
		{
			retorno = 1;
		}
		else if(scoreParticipante1>scoreParticipante2)
		{
			retorno = -1;
		}
	}
	return retorno;
}

void ImprimirUnParticipante(eParticipante* participante, int indice)
{
	int auxId;
	char auxNombre[AUX_LEN];
	int auxEdad;
	int auxIdCategoria;
	int score;
	char descripcionIdCategoria[AUX_LEN];

	if(participante != NULL && !participante_getId(participante, &auxId) && !participante_getNombre(participante, auxNombre) &&
		!participante_getEdad(participante, &auxEdad) && !participante_getIdCategoria(participante, &auxIdCategoria) && !participante_getScore(participante, &score))
		{
			switch(auxIdCategoria)
			{
			 case 1:
				 strcpy(descripcionIdCategoria, "MENOR");
				 break;
			 case 2:
				 strcpy(descripcionIdCategoria, "MAYOR");
				 break;
			}
			printf("\n| %-4d| %-50s| %-5d| %5s| %-20d|",
					auxId, auxNombre, auxEdad, descripcionIdCategoria, score);
		}
}

int filtroPorIdCategoriaMenor(void* participante)
{
	int retorno = -1;
	int auxIdCategoria;

	if(!participante_getIdCategoria((eParticipante*)participante, &auxIdCategoria) && auxIdCategoria == 1)
	{
		retorno = 0;
	}

	return retorno;
}

int filtroPorIdCategoriaMayor(void* participante)
{
	int retorno = -1;
	int auxIdCategoria;

	if(!participante_getIdCategoria((eParticipante*)participante, &auxIdCategoria) && auxIdCategoria == 2)
	{
		retorno = 0;
	}

	return retorno;
}
