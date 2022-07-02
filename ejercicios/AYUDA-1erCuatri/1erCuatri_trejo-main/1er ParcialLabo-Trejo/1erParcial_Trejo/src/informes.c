/*
 * informes.c
 *
 *  Created on: 17 oct. 2021
 *      Author: maxim
 */


#include <stdio.h>
#include <stdlib.h>
#include "salones.h"
#include "arcades.h"
#include "utn.h"
#include "informes.h"

int info_imprimirArcadesySalones(Arcades* arrayArcades,int limiteArcades,Salones* arraySalones,int limiteSalones)
{
	int retorno = -1;
	int i;
	int indiceArraySelones;
	int idPantalla;
	if(arrayArcades != NULL && limiteArcades > 0 && arraySalones != NULL && limiteSalones > 0 )
	{
		for(i=0;i<limiteArcades;i++)
		{
			if(arrayArcades[i].isEmpty == 0 )
			{
				retorno = 0;
				idPantalla = arrayArcades[i].idSalon;
				indiceArraySelones = sal_buscarId(arraySalones,limiteSalones,idPantalla);

				printf("\nID: %d - %s - %s - %d - %d - %d",arrayArcades[i].id,arrayArcades[i].nombre,arrayArcades[i].nacionalidad,arrayArcades[i].tipo,arrayArcades[i].cantidadJugadores,arrayArcades[i].capacidadFichas);
				printf("-ID: %d - %s - %s - %d",arraySalones[indiceArraySelones].id,arraySalones[indiceArraySelones].nombre,arraySalones[indiceArraySelones].direccion,arraySalones[indiceArraySelones].tipo);
			}
		}
	}
	return retorno;
}
