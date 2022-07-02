/*
 * computer.h
 *
 *  Created on: 28 jun. 2022
 *      Author: maxim
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_

#define REINTENTOS 5
#define TAM 1000

typedef struct
{
	int id;
	char descripcion[50];
	float precio;
	char apellido[50];
	int idTipo;

}eComputer;



eComputer* Passenger_new();
void Passenger_delete(eComputer*this);
eComputer* Passenger_newParametros(char* idStr,char* descripcionStr,char* precioStr,char* idTipoStr );
int Passenger_setId(eComputer* this,int id);
int Passenger_setNombre(eComputer* this,char* descripcion);
int Passenger_setPrecio(eComputer* this,float precio);
int Passenger_setCodigoVuelo(eComputer* this, int idTipo);


//------------------------------
int Passenger_compareByIdType(void* p1 ,void*p2);
int Passenger_compareByPrecio(void* p1 ,void*p2);
int Passenger_compareByName(void* p1 ,void*p2);
int Passenger_compareById(void* p1 ,void*p2);
//--------------------------------------
int Passenger_getIdTipo(eComputer* this,int *idTipo);
int Passenger_getPrecio(eComputer* this,float* precio);
int Passenger_getNombre(eComputer* this,char* nombre);
int Passenger_getId(eComputer* this,int *id);
//--------------------------------------------------
int controllerPrintInd(eComputer * auxComputer,int indice);

void aumentoTipo(void* this);
#endif /* COMPUTER_H_ */
