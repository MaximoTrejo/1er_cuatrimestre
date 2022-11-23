/*
 * computer.c
 *
 *  Created on: 21 nov 2022
 *      Author: maxim
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "computer.h"



eComputer * list_new(){
	eComputer* pComputer;

	//creo un puntero y le asigno un espacio en memoria

	pComputer=(eComputer*)malloc(sizeof(eComputer));

	return pComputer;
}

eComputer* list_newParametros(char* idStr,char* descripcionStr,char* precioStr, char* idTipoStr){

	eComputer* pComputer=list_new();

	if( pComputer != NULL){


		com_setId(pComputer,atoi(idStr));
		com_setDescripcion(pComputer, descripcionStr);
		com_setPrecio(pComputer, atoi(precioStr));
		com_setIdTipo(pComputer, atoi(idTipoStr));

	}

	return pComputer;
}


//set y get ID
int com_setId(eComputer* this,int id){
	int retorno=-1;

	//valido que no traiga basura
	if(this != NULL && id > 0){
		//se asigno el id en la estructura
		this->id=id;
		retorno=0;
	}
	return retorno;
}


int com_getId(eComputer* this,int* id){
	int retorno=-1;

	//verifico que no traiga basura
	if(this != NULL && id != NULL){//al ser puntero verifico que no venga con basura
		//le asingno al puntero id el dato de la estructura
		*id=this->id;//guardo el legajo en el puntero y se devuelve
		retorno=0;
	}

	return retorno;
}


//set y get nombre
int com_setDescripcion(eComputer* this,char* descripcion){
	int retorno=-1;
	//valido que no traiga basura
	if(this != NULL && descripcion != NULL){
		//se asigno el id en la estructura
		strcpy(this->descripcion,descripcion);
		retorno=0;
	}
		return retorno;
}

int com_getDescripcion(eComputer* this,char* descripcion){
	int retorno=-1;
	//verifico que no traiga basura
	if(this != NULL && descripcion != NULL){//al ser puntero verifico que no venga con basura
		//en este caso estoy copiendo en el puntero el dato de la estructura
		strcpy(descripcion,this->descripcion);

		retorno=0;
	}
	return retorno;
}


//set y get precio
int com_setPrecio(eComputer* this,float precio){
	int retorno=-1;

	//valido que no traiga basura
	if(this != NULL && precio > 0){
		//se asigno el id en la estructura
		this->precio=precio;
		retorno=0;
	}
	return retorno;
}


int com_getprecio(eComputer* this,float* precio){
	int retorno=-1;

	//verifico que no traiga basura
	if(this != NULL && precio != NULL){//al ser puntero verifico que no venga con basura
		//le asingno al puntero id el dato de la estructura
		*precio=this->precio;//guardo el legajo en el puntero y se devuelve
		retorno=0;
	}

	return retorno;
}


//set y get ID
int com_setIdTipo(eComputer* this,int idTipo){
	int retorno=-1;

	//valido que no traiga basura
	if(this != NULL && idTipo > 0){
		//se asigno el id en la estructura
		this->idTipo=idTipo;
		retorno=0;
	}
	return retorno;
}


int com_getIdTipo(eComputer* this,int* idTipo){
	int retorno=-1;

	//verifico que no traiga basura
	if(this != NULL && idTipo != NULL){//al ser puntero verifico que no venga con basura
		//le asingno al puntero id el dato de la estructura
		*idTipo=this->idTipo;//guardo el legajo en el puntero y se devuelve
		retorno=0;
	}

	return retorno;
}


//-------------------------
int com_compareIdTipo(void* p1 ,void*p2){
	eComputer* unComputer;
	eComputer*otroComputer;
	int compara;

	unComputer=(eComputer*)p1;
	otroComputer=(eComputer*)p2;

	if(unComputer->idTipo > otroComputer->idTipo){
			compara = 1;//cuando p1 es mayor a p2
		}else{
			if(unComputer->idTipo < otroComputer->idTipo){
				compara=-1;//cuando p1 es menor a p2
			}
		}

	return compara;
}

//-------------------------
int filtrarIdTipo(void* this){
	/*
	 * valido retornos y variables
	 * traigo el dato (lo casteo)
	 * lo comparo con el strcmp
	 * devuelvo el retorno
	 */
	int retorno = -1;
	int auxIdTipo;//auxiliar donde guardo la categoria

	if(com_getIdTipo((eComputer*)this,&auxIdTipo)==0){

		if(auxIdTipo == 1){
			com_setIdTipo(this, atoi("DESKTOP"));
			retorno=0;
		}else{
			com_setIdTipo(this, atoi("LAPTOP"));
			retorno=0;
		}

	}

	return retorno;
}


//--------------------------------
//funcion puntero tiene como parametro un puntero a elemento
void aumentoPrecio(void* this)
{
	//creo el id tipo y el precio (donde voy a guardar el precio cuendo lo pida o busque )
	int auxIdTipo;
	float auxPrecio;
	float aumento;
	//traigo el tipo y el precio
	// tiene como parametros 1 puntero genericos que para que se transformen * hay que castiarlos a la lista del computer
	if(com_getIdTipo((eComputer*)this, &auxIdTipo)==0){
		if(auxIdTipo==1){
			com_getprecio((eComputer*)this,&auxPrecio);
			aumento=(10*auxPrecio/100)+auxPrecio;
			com_setPrecio(this, aumento);
		}else{
			com_getprecio((eComputer*)this,&auxPrecio);
			aumento=(20*auxPrecio/100)+auxPrecio;
			com_setPrecio(this, aumento);
		}
	}
}
