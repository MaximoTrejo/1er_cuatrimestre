/*
 * menu.c
 *
 *  Created on: 25 may. 2022
 *      Author: maxim
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "computer.h"
#include "utn.h"
#include "menu.h"
#include "parser.h"

void opcionesMenu(void){
	printf(
	"Menu:\n"
	"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
	"2. Ordenar lista\n"
	"3. imprimir\n"
	"4. Aumentar precio\n"
	"5. guardar\n"
	"6. Salir\n");
}

void selecModificar(){
	printf("\n1-nombre");
	printf("\n2-apellido");
	printf("\n3-Precio");
	printf("\n4-TipoPasajero");
	printf("\n5-CodigoVuelo");
}


void opcionesOrdenar(){
	printf("\n1-Id");
	printf("\n2-descripcion");
	printf("\n3-Precio");
	printf("\n4-idTipo");
}

void opcionsort(){
	printf("\n1-Ascendente");
	printf("\n2-Descendente");
}
