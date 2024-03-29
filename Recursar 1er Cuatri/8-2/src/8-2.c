/*
 ============================================================================
 Name        : 8-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 200
#define CANT 10

#define LIBRE 0
#define OCUPADO 1

#define REINTENTOS 5

typedef struct
	{
		char descripcion[20];
		int idProducto;
		int nacionalidad;
		int tipo;
		float precios;
		int estado;

	}eProductos;

void menuOpciones(void);
int Alta(eProductos productos);
static int dameUnIdNuevo(void);
int modificar(eProductos productos[], int tam,int idMod);
int baja(eProductos productos[] , int tam,int idMod);


int main(void) {

	int opcion;
		int lugarLibre;
		int flagJugadores=0;
		int idIngresado;
		int idModificar;
		int opcionListar;
		float promedio=0;

		do{

			menuOpciones();
			if(utn_getInt(&opcion,"ingrese la opcion", "Error", 1, 5, REINTENTOS)==0){}
			switch(opcion){
			case 1:


				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			}
		}while(opcion!=5);


	return EXIT_SUCCESS;
}






void menuOpciones(void){
	printf("Bienvenido");
    printf("\n1) Alta.");
    printf("\n2) Modificacion.");
    printf("\n3) Baja.");
    printf("\n4) Informar.");
    printf("\n5) Salir.");
}


int Alta(eProductos productos[]){
	int retorno=-1;//validacion que esta todo ok
	char auxdescripcion[TAM];//aux donde se va a cargar el dato
	int auxNacional;
	int auxtipo;
	float auxprecios;

	if(productos!=NULL){//si esta vacio

		if(utn_getCaracter(auxdescripcion, TAM, "ingrese la descripcion", "error", REINTENTOS)==0){
			if(utn_getInt(&auxNacional, "ingrese la nacionalidad", "error", 1, 3, REINTENTOS)==0){
				if(utn_getInt(&auxtipo, "ingrese el tipo", "error", 1, 4, REINTENTOS)==0){
					if(utn_getNumeroFloat(&auxprecios, "ingrese el importe", "error", 1, 9999, REINTENTOS)==0){

						strncpy(productos->descripcion,auxdescripcion,sizeof(productos->descripcion));
						productos->nacionalidad=auxNacional;
						productos->tipo=auxtipo;
						productos->precios=auxprecios;
						productos->estado=OCUPADO;
						productos->idProducto=dameUnIdNuevo();
						retorno=0;
					}
				}
			}
		}
	}
	return retorno;
}

static int dameUnIdNuevo(void) //privada del archivo
{
	static int contador=0;
	contador++;//es global : mantiene su valor
	return contador;
}


int modificar(eProductos productos[], int tam,int idMod){
	int retorno=-1;//validacion que esta todo ok
	int opcion;
	char auxdescripcion[TAM];//aux donde se va a cargar el dato
	int auxNacional;
	int auxtipo;
	float auxprecios;

	menuModificar();
	if(utn_getInt(&opcion, "ingrese la opcion", "Error", 1, 7, REINTENTOS)==0){
		switch(opcion){
		case 1:
			if(utn_getCaracter(auxdescripcion, TAM, "ingrese la descripcion", "error", REINTENTOS)==0){
				strncpy(productos[idMod].descripcion,auxdescripcion,sizeof(productos->descripcion));
				retorno=0;
			}
			break;
		case 2:
			if(utn_getInt(&auxNacional, "ingrese la nacionalidad", "Error", 1, 3, REINTENTOS)==0){
				productos[idMod].nacionalidad=auxNacional;
				retorno=0;
			}
			break;
		case 3:
			if(utn_getInt(&auxtipo, "ingrese la tipo", "Error", 1, 4, REINTENTOS)==0){
				productos[idMod].tipo=auxtipo;
				retorno=0;
			}
			break;
		case 4:
			if(utn_getNumeroFloat(&auxprecios, "ingrese el precio", "Error", 1,9999, REINTENTOS)==0){
				productos[idMod].precios=auxprecios;
				retorno=0;
			}
			break;
		}
	}

	return retorno;
}


void menuModificar(void){
	printf("MODIFICACION");
    printf("\n1) Producto.");
    printf("\n2) Descripcion");
    printf("\n3) Nacionalidad");
    printf("\n4) Precio");
    printf("\n5) Salir.");
}


int baja(eProductos productos[] , int tam,int idMod){

	int retorno=-1;
	int confirmar;
	if(productos !=NULL && tam > 0 && idMod >= 0){

		for(int i=0;i<tam;i++){
			if(productos[i].estado==OCUPADO && productos[i].idProducto==idMod){
				if(utn_getInt(&confirmar,"Dar de baja?[1(S)|2(N)]","Error",1, 2, REINTENTOS)==0){
					productos[i].estado=LIBRE;
					printf("El dato se elimino correctamente\n");
					retorno=0;
				}else{
					printf("El dato no se elimino correctamente\n");
				}
			}
		}

	}
	return retorno;
}

void mostrar(eProductos productos[], int tam){

	if(productos !=NULL) {

		printf("ID\tDescripcion\tNacionalidad\tTipo\tPrecio\n");
		for(int i=0;i<tam;i++){
			if(productos[i].estado==OCUPADO){
				mostrar(&productos[i]);
			}
		}

	}else{
		printf("ERROR");
	}
}


void mostrar(eProductos productos[]){
	printf("%d\t%s\t%d\t%d\t%f\n",productos->idProducto,productos->descripcion,productos->nacionalidad,productos->tipo,productos->precios);
}



