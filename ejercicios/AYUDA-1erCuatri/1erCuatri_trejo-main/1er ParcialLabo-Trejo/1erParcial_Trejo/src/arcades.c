/*
 * arcades.c
 *
 *  Created on: 16 oct. 2021
 *      Author: maxim
 */

#include "salones.h"
#include "arcades.h"
#include "utn.h"
#include "informes.h"
//sino , no anda el NULL
#include <stdio.h>
#include <string.h>


static int arc_dameUnIdNuevo(void);
static int seleccionarCampo (int* campoModificar);
static void mostrarCampos (void);
static int getCantidadJugadores (int* pCantidadJugadores);
static int getNombre (char pNombre[]);

int arc_initList(Arcades array[], int len)
{

	int indice;
	int banderaTodoBien;

	banderaTodoBien=0;

	if(array != NULL && len > 0)
	{
		banderaTodoBien=1;
		for(indice=0;indice < len ;indice++)
		{
			array[indice].isEmpty = 1;
		}
	}
	return banderaTodoBien;
}


/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int arc_buscarLibre (Arcades *pArray, int len)
{
	 int retorno=-1;//status
	 int i;//index
	 if(pArray!=NULL && len>0)
	 {
		 for (i = 0;  i< len; ++i)
		 {
			if(pArray[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		 }
	 }
	 return retorno;
}


/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int arc_imprimir(Arcades* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %s - %d - %d - %d",pElemento->id,pElemento->nombre,pElemento->nacionalidad,pElemento->tipo,pElemento->cantidadJugadores,pElemento->capacidadFichas);
	}
	return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int arc_imprimirArray(Arcades* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			arc_imprimir(&array[i]);
		}
	}
	return respuesta;
}




int arc_altaArray(Arcades* array,int limite, int indice, int* idArcade, int idSalones)
{
	int respuesta = -1;
	Arcades bufferArcades;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idArcade != NULL)
	{
		if(	utn_getNombre(bufferArcades.nombre,NOMBREJUEGO_LEN,"\nIngrese el nombre del juego:","\nERROR\n",2) == 0 &&

				utn_getDescripcion(bufferArcades.nacionalidad,NACIONALIDAD_LEN,"\nIngrese la nacionalidad:","\nERROR\n",2) == 0 &&

				utn_getNumero(&bufferArcades.capacidadFichas,"\nIngrese la capacidad de fichas:","\nERROR\n",0,9999,2)==0 &&

				utn_getNumero(&bufferArcades.cantidadJugadores,"\nIngrese la capacidad de jugadpres:","\nERROR\n",0,9999,2)==0 &&

				utn_getNumero(&bufferArcades.tipo,"\nIngrese el tipo del salon [0:MONO 1:ESTÉREO]:","\nERROR\n",0,1,2)==0)
		{
			respuesta = 0;
			bufferArcades.idSalon = idSalones;
			bufferArcades.id = arc_dameUnIdNuevo();
			bufferArcades.isEmpty = 0;
			array[indice] = bufferArcades;
		}
	}
	return respuesta;
}

//genera numeros id
static int arc_dameUnIdNuevo(void)//privada del arcivo
{
	static int contador=0;
	contador++;//es global : mantiene su valor
	return contador;
}



int arc_buscarId(Arcades array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado  && array[i].isEmpty==0)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}


int arc_modificar(Arcades* pArray)
{
	int status = -1;
	int campoModificar;
	int auxCantidadJugadores;
	char auxNombre[128];

	if (pArray != NULL)
	{
		if (seleccionarCampo(&campoModificar) == 1)
		{
			status = 1;
			switch (campoModificar)
			{
				case 1:
					if (getCantidadJugadores(& auxCantidadJugadores) == 1)
					{
						pArray->cantidadJugadores =  auxCantidadJugadores;
					}
					break;

				case 2:
					//funcion mostrar nombre;
					arc_imprimirNombres(pArray,128);
					if (getNombre(auxNombre) == 1)
					{
						strncpy(pArray-> nombre, auxNombre, 128);
					}
					break;
			}
		}
	}
	return status;
}

static int seleccionarCampo (int* campoModificar)
{
	int status = -1;
	int auxSeleccionarCampo;

	mostrarCampos ();
	if (utn_getNumero(&auxSeleccionarCampo,"\nElegi una opcion para modificar:","Error",1,2,2) == 0)
	{
		status = 1;
		*campoModificar = auxSeleccionarCampo;
	}
	return status;
}

static void mostrarCampos (void)
{
	printf("\n1. La cantidad de jugadores ");
	printf("\n2. Nombre del juego");
}

static int getCantidadJugadores (int* pCantidadJugadores)
{
	int status = -1;
	char mensaje[100];
	int auxTipo;
	strncpy(mensaje,"\nIngrese la cantidad de jugadores:",sizeof(mensaje));
	if (utn_getNumero(&auxTipo,mensaje,"Error",0,1,2) == 0)
	{
		status = 1;
		*pCantidadJugadores = auxTipo;
	}
	return status;
}

static int getNombre (char pNombre[])
{
	int status = -1;
	char mensaje[100];
	char auxName[128];
	strncpy(mensaje, "\nIngrese el nombre del juego",sizeof(mensaje));
	if (utn_getNombre(auxName,128,mensaje, "Error",2) == 0)
	{
		status = 1;
		strncpy(pNombre, auxName, 128);
	}
	return status;
}
//MAAAAL
int arc_imprimirNombres(Arcades* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			arc_imprimirAux(&array[i]);
		}
	}
	return respuesta;
}

int arc_imprimirAux(Arcades* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nNombre: %s ",pElemento->nombre);
	}
	return retorno;
}
//-------------------------------------------------------------------------------------------

/**
 * \brief Actualiza una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int arc_bajaArray(Arcades* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}






