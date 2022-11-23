/*
 * menu.c
 *
 *  Created on: 5 nov 2022
 *      Author: maxim
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"


void opcionesMenu(void){
	printf(
	"Menu:\n"
	"1. Cargar de archivos .csv\n"
	"2. Imprimir Lista\n"
	"3. Asignar Promedios\n"
	"4. Filtrar por tipo\n"
	"5. Mostrar posiciones\n"
	"6. Guardar Posiciones\n"
	"7. Salir\n");
}



void opcionFiltrarTipo(void){
	printf(
		"1.MX1 \n"
		"2.MX2 \n"
		"3.MX3 \n"
		"4.SUPER_ATV \n"
		"5. Salir\n");
}

