/*
 * utn_biblioteca.c
 *
 *  Created on: 7 sep. 2021
 *      Author: maxim
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn_biblioteca.h"

static int esNumericaInt(char cadenaNumeros[]);
static int esTexto (char* cadena);

//_------------------------------------------------------------------------------------
/*
* \brief pide un char al ususario
* \param puntero char, reintentos y textos de pedido y erro
* \return Retorna -1  salio mal, 0 salio bien y 2 sin reintento
*/
int pedirChar(char* pChar, int reintentos, char* txt, char* txtError)
{
	int retorno=-1;
	int i;
	char bufferCadenaAux[32];
	if(pChar != NULL && reintentos >=0 && txt != NULL && txtError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("\n%s\n", txt);
			fflush(stdin);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
				{
				//if(es loque necesite)
				strncpy(pChar, bufferCadenaAux,1);
					retorno = 0;
					break;
				}else
				{
						printf("%s", txtError);
				}
		}
	}
	return retorno;
}
//-------------------------------------------------------------------------------------
/*
  * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \param mensaje Es el mensaje a ser mostrado
  * \param mensajeError Es el mensaje de Error a ser mostrado
  * \param minimo Es el numero maximo a ser aceptado
  * \param maximo Es el minimo minimo a ser aceptado
  * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int pedirFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos)
 {
 	int retorno = -1;
 	float bufferInt;
 	int i;
 	char bufferCadenaAux[32];

 	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >= 0)
 	{
 		for(i=0; i<=intentos; i++)
 		{
 			printf("%s", mensaje);
 			fflush(stdin);
 			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
 			{
 				if(esNumericaFloat(bufferCadenaAux)==0)
 					{
 					bufferInt = atof(bufferCadenaAux);
 					if(bufferInt >= minimo && bufferInt <= maximo)
 						{
 							*pResultado = bufferInt;
 							retorno = 0;
 							break;
 						}else
 							{
 							printf("%s", mensajeError);
 							}
 					}
 				else
 					{
 					printf("%s", mensajeError);
 					}
 			}
 			else
 				{
 				printf("%s", mensajeError);
 				}
 		}
 		if(retorno==-1)
 		{
 			printf("\nTe quedaste sin intentos\n");
 		}
 	}
 	return retorno;
 }

//--------------------------------------------------------------------------------
/*
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param len Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*/
int myGets(char pResultado[], int len)
{
    int retorno=-1;
    int indexFinal;
    //windows
    fflush( stdout );
    //
    //
    if(fgets(pResultado,len,stdin)!=NULL)
    {
    	fflush(stdin);
        // borro el \n del final
        indexFinal = strlen(pResultado)-1;
        if(pResultado[indexFinal] == '\n')
        {
            pResultado[indexFinal] = '\0';
        }
        retorno = 0;
    }
    return retorno;
}
//-----------------------------------------------------------------------------------------------------
/*
  * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \param mensaje Es el mensaje a ser mostrado
  * \param mensajeError Es el mensaje de Error a ser mostrado
  * \param minimo Es el numero maximo a ser aceptado
  * \param maximo Es el minimo minimo a ser aceptado
  * \return Retorna 0 si se obtuvo el numero(EXITO) y -1 si no(MAL)
 */
int pedirInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos)
 {
 	int retorno = -1;
 	int bufferInt;
 	int i;
 	char bufferCadenaAux[32];

 	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >= 0)
 	{
 		for(i=0; i<=intentos; i++)
 		{
 			printf("%s", mensaje);
 			fflush(stdin);
 			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
 			{
 				if(esNumericaInt(bufferCadenaAux)==0)
 					{
 					bufferInt = atoi(bufferCadenaAux);
 					if(bufferInt >= minimo && bufferInt <= maximo)
 						{
 							*pResultado = bufferInt;
 							retorno = 0;
 							break;
 						}else
 							{
 							printf("%s", mensajeError);
 							}
 					}
 				else
 					{
 					printf("%s", mensajeError);
 					}
 			}
 			else
 				{
 				printf("%s", mensajeError);
 				}
 		}
 		if(retorno==-1)
 		{
 			printf("\nTe quedaste sin intentos\n");
 		}
 	}
 	return retorno;
 }

//------------------------------------------------------------------------------------------------------------------
//utn_pedirNumeroInt
/**
 * \brief: Pide al usuario que ingrese un número de tipo int y lo valida.
 * 			Retorna 1 si fue exitoso y 0 si no lo fue
 * \param valorMinimo: int que representa el valor mínimo que puede ingresar el usuario
 * \param valorMaximo: int que representa el valor máximo que puede ingresar el usuario
 * \param intentos: int que representa la cantidad de reintentos permitidos
 * \param mensaje: string que se imprime por consola al usuario a modo informativo
 * \param *pNumero: puntero de la dirección en memoria donde se guardará el resultado
 * \param mensajeError: string que se imprime por consola al usuario cuando se cometieron todos los intentos permitidos
 * \return 1 si fue exitoso y 0 si no lo fue
 */
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;
	int bufferInt;
	int i;
	char bufferCadenaAux[16];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{

		for(i=0; i<=reintentos; i++)
		{
			printf("%s", mensaje);
			fflush( stdout );

			//if(scanf("%d", &bufferInt)==1)
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				// el usuario ingreso algo
				// lo valido, para ver si los simbolos ingresados son numericos
				if(esNumericaInt(bufferCadenaAux)==0)
				{
					// si son numericos, convierto la cadena a INT
					bufferInt = atoi(bufferCadenaAux);

					if(bufferInt >= minimo && bufferInt <= maximo){
						*pResultado = bufferInt;
						retorno = 0;
						break;
					}else{
						printf("%s", mensajeError);
					}
				}
				else {
					printf("%s", mensajeError);
				}
			}
			else {
				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}

//-----------------------------------------------------------------
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero  y -1 (ERROR) si no
*/
static int esNumericaInt(char cadenaNumeros[])
{
	int i=0;
	int retorno=-1;
	if(cadenaNumeros!=NULL && strlen(cadenaNumeros)> 0)
	{
		retorno=0;
		while(cadenaNumeros[i]!='\0')
		{
			if(cadenaNumeros[i]<'0'||cadenaNumeros[i]> '9')
			{
			retorno=-1;
			break;
			}
			i++;
		}
	}
	return retorno;
}

//--------------------------------------------------------------------------------------------
/*
* \brief Verifica si la cadena ingresada es numerica con numeros flotantes
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 0 (EXITO) si la cadena es numerica y -1 (MAL) si no lo es
*/
int esNumericaFloat(char* cadena)
 {
 	int i=0;
 	int retorno = -1;
 	int contNeg=0;
 	int contPuntos=0;
 	if(cadena != NULL && strlen(cadena) > 0)
 	{
 		retorno=0;
 		while(cadena[i] != '\0')
 			{
 				if(cadena[i] < '0' || cadena[i] > '9')
 					{
 					if(cadena[i]=='-' || cadena[i]=='.')
 						{
 							if(cadena[i]=='-')
 							{
 								contNeg++;
 								if(i!=0)
 								{
 									retorno = -1;
 									break;
 								}
 							}
 							if(cadena[i]=='.')
 							{
 								contPuntos++;
 							}
 						}else
 						{
 							retorno = -1;
 							break;
 						}
 					}
 				i++;
 			}
 		if(contNeg>1 ||contPuntos>1)
 		{
 			retorno=-1;
 		}
 	}
 	return retorno;
 }

//----------------------------------------------------------------------------------
/**
* \brief Verifica si la cadena ingresada es alfanumerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 0 (EXITO) si la cadena es alfanumerica y -1 (MAL) si no lo es
*/
int esAlfaumerica(char* cadena)
{
	int i=0;
	int retorno = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
			{
				if((cadena[i]<48||cadena[i]>57)&&(cadena[i]< 65||cadena[i]>90)&&(cadena[i]<97||cadena[i]>122))//0-9 48-57 A-Z 65-90 a-z 97-122
					{
						if (cadena[i]==32)
						{

						}else
						{
							retorno = -1;
							break;
						}
					}
				i++;
			}
	}
	return retorno;
}

//---------------------------------------------------------------------------------
/*
 \brief pide un texto al ususario
 \param puntero char, tamaño del array , textos de pedido , error y reintentos
 \return Retorna -1  salio mal, 0 salio bien y 2 sin reintento
*/
int pedirText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno=-1;
	char bufferCadenaAux[128];
	int i;

	if(pResultado != NULL && reintentos >0 && len>0 && mensaje != NULL && mensajeError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",mensaje);

			if (myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esTexto(bufferCadenaAux)==0)
				{

					retorno = 0; // OK
					strncpy (pResultado,bufferCadenaAux,len);
					break;
					}else
					{
						printf("%s\n",mensajeError);
					}

				} else
				{
					printf("%s\n",mensajeError);
				}

			}
	}
	return retorno;
}

/*
 \brief verifica si es texto
 \param cadena char*
 \return Retorna -1  salio mal, 0 salio bien y 2 sin reintento
*/
static int esTexto (char cadena[])
{
	int retorno;
	int i;

	retorno=-1;
	i=0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		retorno=0;
		while(cadena[i]!='\0')
		{
			if((cadena[i]>='A'&&cadena[i]<='z')||cadena[i]==32||cadena[i]=='.'||cadena[i]==',')
			{
				if(cadena[i]>'Z'&&cadena[i]<'a')
				{
					retorno=-1;
					break;
				}
				i++;

			} else
			{
				retorno=-1;
				break;
			}

		}
	}
	return retorno;
}

