/*
 * salones.c
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


static int dameUnIdNuevo(void);
static int seleccionarCampo (int* campoModificar);
static void mostrarCampos (void);
static int getTipo (int* pTipo);
static int getNombre (char pNombre[]);
static int getDireccion (char pDireccion[]);

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int sal_initList(Salones array[], int len)
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
int sal_buscarLibre (Salones *pArray, int len)
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
 * \brief Da de alta una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int sal_altaArray(Salones* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Salones bufferSalones;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferSalones.nombre,NOMBRE_LEN,"\nIngrese su nombre:","\nERROR\n",2) == 0 &&
			utn_getDescripcion(bufferSalones.direccion,DIRECCION_LEN,"\nIngrese su direccion:","\nERROR\n",2) == 0 &&
			utn_getNumero(&bufferSalones.tipo,"\nIngrese el tipo del salon [0:SHOPPING 1:LOCAL]:","\nERROR\n",0,1,2)==0)
		{
			respuesta = 0;
			bufferSalones.id = dameUnIdNuevo();
			bufferSalones.isEmpty = 0;
			array[indice] = bufferSalones;
		}
	}
	return respuesta;
}


//genera numeros id
static int dameUnIdNuevo(void)//privada del arcivo
{
	static int contador=0;
	contador++;//es global : mantiene su valor
	return contador;
}



/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int sal_imprimir(Salones* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %s - %d",pElemento->id,pElemento->nombre,pElemento->direccion,pElemento->tipo);
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
int sal_imprimirArray(Salones* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			sal_imprimir(&array[i]);
		}
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array cliente Array de cliente
* \param limite int TamaÃ±o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int sal_buscarId(Salones array[], int limite, int valorBuscado)
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


//_--------------------------------------------------------------
int sal_modificar(Salones* pArray)
{
	int status = -1;
	int campoModificar;
	int auxTipo;
	char auxNombre[128];
	char auxDireccion[128];

	if (pArray != NULL)
	{
		if (seleccionarCampo(&campoModificar) == 1)
		{
			status = 1;
			switch (campoModificar)
			{
				case 1:
					if (getTipo(&auxTipo) == 1)
					{
						pArray->tipo = auxTipo;
					}
					break;

				case 2:
					if (getNombre(auxNombre) == 1)
					{
						strncpy(pArray-> nombre, auxNombre, 128);
					}
					break;
				case 3:
					if (getDireccion(auxDireccion) == 1)
					{
						strncpy(pArray->direccion, auxDireccion, 128);
					}
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
	if (utn_getNumero(&auxSeleccionarCampo,"\nElegi una opcion para modificar:","Error",1,3,2) == 0)
	{
		status = 1;
		*campoModificar = auxSeleccionarCampo;
	}
	return status;
}

static void mostrarCampos (void)
{
	printf("\n1. Tipo ");
	printf("\n2. Nombre");
	printf("\n3. Direccion");
}

static int getTipo (int* pTipo)
{
	int status = -1;
	char mensaje[100];
	int auxTipo;
	strncpy(mensaje,"\nIngrese el tipo del salon [0:SHOPPING 1:LOCAL]:",sizeof(mensaje));
	if (utn_getNumero(&auxTipo,mensaje,"Error",0,1,2) == 0)
	{
		status = 1;
		*pTipo = auxTipo;
	}
	return status;
}


static int getNombre (char pNombre[])
{
	int status = -1;
	char mensaje[100];
	char auxName[128];
	strncpy(mensaje, "\nIngrese el nombre",sizeof(mensaje));
	if (utn_getNombre(auxName,128,mensaje, "Error",2) == 0)
	{
		status = 1;
		strncpy(pNombre, auxName, 128);
	}
	return status;
}

static int getDireccion (char pDireccion[])
{
	int status = -1;
	char mensaje[100];
	char auxDireccion[128];
	strncpy(mensaje, "\nIngrese la dirección",sizeof(mensaje));
	if (utn_getDescripcion(auxDireccion, 128, mensaje, "Error",2) == 0)
	{
		status = 1;
		strncpy(pDireccion, auxDireccion,128);
	}
	return status;
}


