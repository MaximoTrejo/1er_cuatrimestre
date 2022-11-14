/*
 ============================================================================
 Name        : ArrayParalelos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 3



int main(void)
{
	setbuf(stdout,NULL);

	int dni[] = {30000,30001,30002};
	char nombre[][25]= {{"David"},{"Matias"},{"Thiago"}};
	float sueldo[]= {20000,19000,19000};
	char division[]= {'K','K','K' };
	int i;
	int j;
	int auxInt;
	float auxFloat;
	char auxChar;
	char auxCadena[25];




	printf("dni   nombre  division  sueldo\n");

	for(i=0;i<CANTIDAD;i++)
	{
		printf("%d %s %c %f\n",dni[i],nombre[i],division[i],sueldo[i]);
	}



	//ORDENAMIENTO
	for(i=0;i<CANTIDAD-1;i++)
	{
		for(j=i+1;j<CANTIDAD;j++)
		{
				// tomo el criterio por el cual ordenar
			if(strcmp(nombre[i],nombre[j])<0) ///CAMBIANDO EL SIGNO SABES SI ES ASC O DESC
			{
					//realizo el swap de los nombres
					strcpy(auxCadena,nombre[i]);
					strcpy(nombre[i],nombre[j]);
					strcpy(nombre[j],auxCadena);

					//realizo el swap de los dni
					auxInt = dni[i];
					dni[i] = dni[j];
					dni[j] = auxInt;

					//realizo el swap de los sueldos
					auxFloat = sueldo[i];
					sueldo[i] = sueldo[j];
					sueldo[j] = auxFloat;
					//realizo el swap de las divisiones
					auxChar = division[i];
					division[i] = division[j];
					division[j] = auxChar;


			}
		}
	}



	printf("dni   nombre  division  sueldo\n");

	for(i=0;i<CANTIDAD;i++)
	{
		printf("%d %3s %3c %20f\n",dni[i],nombre[i],division[i],sueldo[i]);
	}



	return EXIT_SUCCESS;
}

