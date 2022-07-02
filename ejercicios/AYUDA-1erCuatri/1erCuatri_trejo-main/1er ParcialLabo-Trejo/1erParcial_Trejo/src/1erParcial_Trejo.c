/*
 ============================================================================
 Name        : 1erParcial_Trejo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "salones.h"
#include "arcades.h"
#include "utn.h"
#include "informes.h"

#define CANTIDAD_SALONES 100
#define CANTIDAD_ARCADES 100

int main(void) {
	setbuf(stdout,NULL);
	Salones arraySalones[CANTIDAD_SALONES];
	Arcades arrayArcades[CANTIDAD_ARCADES];
	int auxBuscar;
	int auxBuscarArcades;
	int idSalones=0;
	int idArcades=0;
	int auxId;
	//Variables
	int opcion;

	if(sal_initList(arraySalones,CANTIDAD_SALONES) == 1)
	{
		printf("Array inicializado correctamente. \n");
	}

	if(arc_initList(arrayArcades,CANTIDAD_ARCADES) == 1)
	{
		printf("Array inicializado correctamente. \n");
	}

	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar salon"
							"\n2.Modificar salon"
							"\n3.Imprimir salones"
							"\n4.Incorporar arcade"
							"\n5--"
							"\n6.Eliminar arcade"
							"\n7.Imprimir arcade"
							"\n8.--"
							"\n9.--"
							"\n10.Salir\n\n",
							"\nError opcion invalida",1,10,2) )
		{

			switch(opcion)
			{
			case 1:
				auxBuscar = sal_buscarLibre(arraySalones,CANTIDAD_SALONES);
				if(auxBuscar >= 0)
				{
					if(sal_altaArray(arraySalones,CANTIDAD_SALONES,auxBuscar,&idSalones) == 0)
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				sal_imprimirArray(arraySalones,CANTIDAD_SALONES);
				if(utn_getNumero(&auxId,"\nIndique el ID del Salon a modificar","\nID invalido",0,100,0) == 0)
				{
					auxBuscar = sal_buscarId(arraySalones,CANTIDAD_SALONES,auxId);
					if(	auxBuscar >= 0)
					{
						sal_modificar(&arraySalones[idSalones]);
						sal_imprimirArray(arraySalones,CANTIDAD_SALONES);
					}
				}
				break;

			case 3:
				sal_imprimirArray(arraySalones,CANTIDAD_SALONES);
				break;
			case 4:
				auxBuscarArcades = arc_buscarLibre(arrayArcades,CANTIDAD_ARCADES);
				if(auxBuscarArcades >= 0)
				{
					sal_imprimirArray(arraySalones,CANTIDAD_SALONES);
					if(	utn_getNumero(&auxId,"\nId del Salon: ","\nError",0,10000,2) == 0 &&
						sal_buscarId(arraySalones,CANTIDAD_SALONES,auxId) != -1)
					{
						arc_altaArray(arrayArcades,CANTIDAD_ARCADES,auxBuscarArcades,&idArcades,auxId);
					}
					else
					{
						printf("\nEL ID NO EXISTE");
					}
				}
				break;
			case 5:

				arc_imprimirArray(arrayArcades,CANTIDAD_ARCADES);
				if(	utn_getNumero(&auxId,"\nId del Arcade: ","\nError",0,10000,2) == 0)
				{

					auxBuscar = arc_buscarId(arrayArcades,CANTIDAD_ARCADES,auxId);
					if(	auxBuscar >= 0)
					{
						arc_modificar(&arrayArcades[idSalones]);
						arc_imprimirArray(arrayArcades,CANTIDAD_ARCADES);
					}
				}
				else
				{
					printf("\nEL ID NO EXISTE");
				}
				break;
			case 6:

				if(info_imprimirArcadesySalones(arrayArcades,CANTIDAD_ARCADES,arraySalones,CANTIDAD_SALONES)==0)
				{
					if(	utn_getNumero(&auxId,"\nId del Arcade: ","\nError",0,10000,2) == 0)
					{
						if(utn_getNumero(&auxId,"\nID ARCADE A CANCELAR? ","\nERROR",0,10000,2)==0)
						{
							auxBuscar = arc_buscarId(arrayArcades,CANTIDAD_ARCADES,auxId);
							if(auxBuscar != -1)
							{
								arc_bajaArray(arrayArcades,CANTIDAD_ARCADES,auxBuscar);
							}
						}
					}
				}
				else
				{
					printf("\nCUIT NO ENCONTRADO");
				}
				break;
			case 7:

				arc_imprimirArray(arrayArcades,CANTIDAD_ARCADES);

				break;
			case 8:


				break;
			case 9:
				break;
			case 10:
				break;

			}

		}
	}while(opcion != 10);

	return EXIT_SUCCESS;
}


