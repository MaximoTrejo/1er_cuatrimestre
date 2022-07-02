/*
 * utn_biblioteca.c
 *
 *  Created on: 7 sep. 2021
 *      Author: maxim
 */

#include "utn_biblioteca.h"


int utn_pedirCharAUsuario(char* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
	char buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			fflush(stdin);
			salidaScanf=scanf("%c", &buffer);

			printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				printf("el caracter 94 %c \n",94);
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}

//-------------------------------------------------------------------------------------

int utn_pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError)
{
	float buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			salidaScanf=scanf("%f", &buffer);

			printf("\nLa salida del scanf es : %d\n\n",salidaScanf);

			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{

				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}

//--------------------------------------------------------------------------------


