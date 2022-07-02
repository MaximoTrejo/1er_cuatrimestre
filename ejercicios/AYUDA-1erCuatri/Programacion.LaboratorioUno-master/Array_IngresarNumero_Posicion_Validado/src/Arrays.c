/*
 ============================================================================
 Name        : Arrays.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int utn_pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);

int main(void) {
	setbuf(stdout,NULL);

	float arrayNumeros[5];

	for(int i = 0;i<5;i++){

		utn_pedirFloatAUsuario(&arrayNumeros[i],1,31,2,"ingrese un numero: \n ","Error! fuera de rango");
	}

	for(int i = 0;i<5;i++){
		printf("\n En la posicion i %d : se encuentra el numero %f " , i ,arrayNumeros[i]);
	}

	return EXIT_SUCCESS;
}

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
