/*
 * libro.c
 *
 *  Created on: 23 nov 2022
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "libro.h"

eLibro * list_new(){
	eLibro* pLibro;

	//creo un puntero y le asigno un espacio en memoria

	pLibro=(eLibro*)malloc(sizeof(eLibro));

	return pLibro;
}


eLibro* list_newParametros(char* idStr,char* tituloStr,char* importeStr, char* idTipoStr){

	eLibro* pLibro=list_new();

	if( pLibro != NULL){

		lib_setId(pLibro,atoi(idStr));
		lib_setTitulo(pLibro, tituloStr);
		lib_setImporte(pLibro,  atoi(importeStr));
		lib_setIdTipo(pLibro, atoi(idTipoStr));

	}

	return pLibro;
}



//set y get ID
int lib_setId(eLibro* this,int id){
	int retorno=-1;

	//valido que no traiga basura
	if(this != NULL && id > 0){
		//se asigno el id en la estructura
		this->id=id;
		retorno=0;
	}
	return retorno;
}


int lib_getId(eLibro* this,int* id){
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
int lib_setTitulo(eLibro* this,char* titulo){
	int retorno=-1;
	//valido que no traiga basura
	if(this != NULL &&  titulo != NULL){
		//se asigno el id en la estructura
		strcpy(this->titulo,titulo);
		retorno=0;
	}
		return retorno;
}

int lib_getTitulo(eLibro* this,char* titulo){
	int retorno=-1;
	//verifico que no traiga basura
	if(this != NULL && titulo != NULL){//al ser puntero verifico que no venga con basura
		//en este caso estoy copiendo en el puntero el dato de la estructura
		strcpy(titulo,this->titulo);

		retorno=0;
	}
	return retorno;
}


//set y get precio
int lib_setImporte(eLibro* this,float importe){
	int retorno=-1;

	//valido que no traiga basura
	if(this != NULL && importe > 0){
		//se asigno el id en la estructura
		this->importe=importe;
		retorno=0;
	}
	return retorno;
}


int lib_getImporte(eLibro* this,float* importe){
	int retorno=-1;

	//verifico que no traiga basura
	if(this != NULL && importe != NULL){//al ser puntero verifico que no venga con basura
		//le asingno al puntero id el dato de la estructura
		*importe=this->importe;//guardo el legajo en el puntero y se devuelve
		retorno=0;
	}

	return retorno;
}

//set y get ID
int lib_setIdTipo(eLibro* this,int idTipo){
	int retorno=-1;

	//valido que no traiga basura
	if(this != NULL && idTipo > 0){
		//se asigno el id en la estructura
		this->idTipo=idTipo;
		retorno=0;
	}
	return retorno;
}


int lib_getIdTipo(eLibro* this,int* idTipo){
	int retorno=-1;

	//verifico que no traiga basura
	if(this != NULL && idTipo != NULL){//al ser puntero verifico que no venga con basura
		//le asingno al puntero id el dato de la estructura
		*idTipo=this->idTipo;//guardo el legajo en el puntero y se devuelve
		retorno=0;
	}

	return retorno;
}

int lib_compareImporte(void* p1 ,void*p2){
	eLibro* unLibro;
	eLibro*otroLibro;
	int compara;

	unLibro=(eLibro*)p1;
	otroLibro=(eLibro*)p2;

	if(unLibro->importe > otroLibro->importe){
			compara = 1;//cuando p1 es mayor a p2
		}else{
			if(unLibro->importe < otroLibro->importe){
				compara=-1;//cuando p1 es menor a p2
			}
		}
	return compara;
}


void aumentoPrecio(void* this)
{
	//creo el id tipo y el precio (donde voy a guardar el precio cuendo lo pida o busque )
	int auxIdTipo;
	float auxPrecio;
	float aumento;
	//traigo el tipo y el precio
	// tiene como parametros 1 puntero genericos que para que se transformen * hay que castiarlos a la lista del computer

	if(lib_getIdTipo((eLibro*)this, &auxIdTipo)==0){
		if(auxIdTipo==1){
			lib_getImporte((eLibro*)this, &auxPrecio);
			aumento=(10*auxPrecio/100)+auxPrecio;
			lib_setImporte(this, aumento);

		}else{
			lib_getImporte((eLibro*)this, &auxPrecio);
			aumento=(20*auxPrecio/100)+auxPrecio;
			lib_setImporte(this, aumento);
		}
	}
}
