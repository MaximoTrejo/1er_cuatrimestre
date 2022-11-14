/*
 ============================================================================
 Name        : 26-10-22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

	int legajo;
	char nombre[50];
	int materias;

}eAlumnos;

//funciones
eAlumnos* newAlumno();
eAlumnos* newAlumnoParametrizado(int legajo, char* nombre , int cantidad);
void deleteAlumno(eAlumnos * miAlmuno);
int set_Legajo(eAlumnos * miAlmuno,int legajo);
int get_Legajo(eAlumnos * miAlmuno,int * legajo);

int main(void) {

	//creo un puntero de la estructura para asignarla al malloc
	eAlumnos* alumnos;

	//valiables auxiliares
	int auxLegajo;

	//------------CREO ESPACIO EN MEMORIA---------------	//----------------------CARGO LOS DATOS----------------
	alumnos=newAlumnoParametrizado(1000, "matias", 3);

	//----------------------VALIDO QUE LA ESTRUCTURA NO VENGA CON BASURA---------------

	if(alumnos != NULL){

		//-------------MUESTRO-----------------
		printf("legajo\t\tnombre\t\tmaterias\n");

		get_Legajo(alumnos, &auxLegajo);

		printf("%d\t\t%s\t\t%d\n",auxLegajo,alumnos->nombre,alumnos->materias);

		//si quiero modificar el dato llamo al setter para que asigne el nuevo valor a la estructura
		set_Legajo(alumnos, 20);
		get_Legajo(alumnos, &auxLegajo);
		printf("%d\t\t%s\t\t%d\n",auxLegajo,alumnos->nombre,alumnos->materias);
	}else{
		printf("la memoria esta llena");
	}


	//---------LIBERO ESPACIO EN MEMORIA--------------
	free(alumnos);


	return EXIT_SUCCESS;
}



//constructores por defecto o sin parametros
//reserva espacio en memoria


eAlumnos* newAlumno(){

	eAlumnos* pAlumnos;

	pAlumnos=(eAlumnos*)malloc(sizeof(eAlumnos));

	return pAlumnos;
}



//constructores parametrizados o con parametros
eAlumnos* newAlumnoParametrizado(int legajo, char* nombre , int cantidad){
	eAlumnos* pAlumnos;
	pAlumnos=newAlumno();

	if(pAlumnos != NULL){

		set_Legajo(pAlumnos, legajo);

		strcpy(pAlumnos->nombre,nombre);
		pAlumnos->materias=cantidad;
	}

	return pAlumnos;


}


//destructor //libera el espacio en memoria
void deleteAlumno(eAlumnos * miAlmuno){

	if(miAlmuno != NULL){
		free(miAlmuno);
	}
}


//setters (solo escritura ,le permita cargar un dato)
int set_Legajo(eAlumnos * miAlmuno,int legajo){
	int retorno=-1;

	if(miAlmuno != NULL && legajo > 0){
		miAlmuno->legajo=legajo;
		retorno=0;
	}
	return retorno;
}

//getters(solo lectura, permite devolver un dato)
int get_Legajo(eAlumnos * miAlmuno,int * legajo){//lo hago puntero al parametro porue necesito retornarlo
	int retorno=-1;
	if(miAlmuno != NULL && legajo != NULL){//al ser puntero verifico que no venga con basura
		*legajo=miAlmuno->legajo;//guardo el legajo en el puntero y se devuelve
		retorno=0;
	}

	return retorno;
}
