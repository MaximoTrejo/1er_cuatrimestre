/*
 ============================================================================
 Name        : 17-04-2022.c
 Author      : MaximoTrejo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>//para los strings
#include "Alumno.h"
#define CANT_PERSONAS 100

int main(void) {

	Alumno auxiliar;//se crea un tipo de dato alumno
	Alumno arrayAlumnos[CANT_PERSONAS];//array
	//------------------------------------------------------------------

	//INICIALIZO
	inicializoArray(arrayAlumnos, CANT_PERSONAS);
	//---------------------
	auxiliar.altura=2.04;
	auxiliar.legajo=25;
	//para array
	strcpy(auxiliar.nombre,"MAXIMO");
	auxiliar.isEmpty=0;
	//para copiar todo
	arrayAlumnos[14]=auxiliar;//se copia todo en la posicion 14
	//mostrar
	//printf("Nombre: %s | Legajo: %d | Altura: %f ",auxiliarAlumno.nombre , auxiliarAlumno.legajo,auxiliarAlumno.altura);
	imprimirArray(arrayAlumnos,CANT_PERSONAS);
	//aceder a un array de alumnos
	//arrayAlumnos[63].altura=1.85;


//-------------------------------------------------------------------------------------------------------------------------------

	/*
	int edad;
	float altura;
	char nombre[51];
	char sexo;

	int aEdad[CANT_PERSONAS];
	float aAltura[CANT_PERSONAS];
	char aNombre[51][CANT_PERSONAS];
	char aSexo[CANT_PERSONAS];

	  * Persona
	  * nombre
	  * apellido
	  * dni
	  * cuit
	  * direccion
	  * telefono
	  * mail
	  * legajo
	  */





	return EXIT_SUCCESS;
}
