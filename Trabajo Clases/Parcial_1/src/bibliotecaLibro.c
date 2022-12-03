/*
 * bibliotecaLibro.c
 *
 *  Created on: 1 oct 2022
 *      Author: maxim
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaLibro.h"
#include "menu.h"
#include "utn.h"

static int dameUnIdNuevo(void);

void inicializarAE(eLibro libros[],int tam){
	for(int i=0; i<tam; i++)
	{
			libros[i].estado = LIBRE;
	}
}

//Devuelve el indice del proximo empleado inactivo que encuentre
int BuscarLibre(eLibro libros[],int tam)
{
	int indice;
	indice = -1;//Si no encuentra un usuario inactivo-> Si el array est� lleno.
	if(libros !=NULL && tam>0){

		for(int i=0; i<tam; i++)
		{
			if(libros[i].estado == LIBRE)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

//Devuelve el indice de un empleado en cuestion
int buscarID(eLibro libros[],int tam,int legajoABuscar)
{
	int indice;
	indice = -1;//Si no encuentra al usuario

	for(int i=0; i<tam; i++)
    {
	   if(libros[i].estado == OCUPADO && libros[i].codLibro == legajoABuscar )
	   {
		   indice = i;
		   break;
	   }
    }
	return indice;
}

int altaLibros(eLibro libros[] ,eAutor autor[],ePais pais[] ,eEditorial editorial[], eGenero genero[]){
	int retorno=-1;//validacion que esta todo ok
	char auxTitulo[TAM];//aux donde se va a cargar el dato
	int auxDia;//aux donde se va a cargar el dato
	int auxMes;//aux donde se va a cargar el dato
	int auxAnio;//aux donde se va a cargar el dato
	float auxImporte;//aux donde se va a cargar el dato
	int auxAutor;
	int auxEditorial;
	int auxGenero;
	if(libros!=NULL){//si esta vacio

		if(utn_getCaracter(auxTitulo, TAM, "ingrese el titulo", "error", REINTENTOS)==0){
			if(utn_getInt(&auxDia, "ingrese el dia", "error", 1, 31, REINTENTOS)==0){
				if(utn_getInt(&auxMes, "ingrese el mes", "error", 1, 12, REINTENTOS)==0){
					if(utn_getInt(&auxAnio, "ingrese el anio", "error", 1, 9999, REINTENTOS)==0){
						if(utn_getNumeroFloat(&auxImporte, "ingrese el importe", "error", 1, 9999, REINTENTOS)==0){
							mostrarAutor(autor, CANT, pais);
							if(utn_getInt(&auxAutor, "ingrese el Autor", "error", 1, 3, REINTENTOS)==0){
								mostrarEditorial(editorial, CANT);
								if(utn_getInt(&auxEditorial, "ingrese la editorial", "error", 1, 3, REINTENTOS)==0){
									mostrarGenero(genero, CANT);
									if(utn_getInt(&auxGenero, "ingrese genero", "Error", 1, 5, REINTENTOS)==0){


										strncpy(libros->titulo,auxTitulo,sizeof(libros->titulo));
										libros->FechaPublicacion.dia=auxDia;
										libros->FechaPublicacion.mes=auxMes;
										libros->FechaPublicacion.anio=auxAnio;
										libros->importe=auxImporte;
										libros->estado=OCUPADO;
										libros->codLibro=dameUnIdNuevo();
										libros->idAutor=auxAutor;
										libros->idEditorial=auxEditorial;
										libros->idGenero=auxGenero;
										retorno=0;
									}
								}
							}
						}
					}
				}

			}
		}
	}
	return retorno;
}

int modificarLibros(eLibro libros[] , int tam,int idMod,eAutor autor[],ePais pais[] ,eEditorial editorial[],eGenero genero[]){

	int retorno=-1;//validacion que esta todo ok
	char auxTitulo[TAM];//aux donde se va a cargar el dato
	int auxDia;//aux donde se va a cargar el dato
	int auxMes;//aux donde se va a cargar el dato
	int auxAnio;//aux donde se va a cargar el dato
	float auxImporte;//aux donde se va a cargar el dato
	int auxAutor;
	int auxEditorial;
	int auxGenero;
	int opcion;

	menuModificar();
	if(utn_getInt(&opcion,"ingrese la opcion ", "Error", 1, 6, REINTENTOS)==0){


		switch(opcion){
		case 1:
			if(utn_getCaracter(auxTitulo, TAM, "ingrese el titulo","Error", REINTENTOS)==0){
				strncpy(libros[idMod].titulo,auxTitulo,sizeof(libros->titulo));
				retorno=0;
			}
				break;
		case 2:
			if(utn_getInt(&auxDia, "ingrese el dia", "Error", 1, 31, REINTENTOS)==0){
				if(utn_getInt(&auxMes, "ingrese el mes", "Error", 1, 12, REINTENTOS)==0){
					if(utn_getInt(&auxAnio, "ingrese el mes", "Error", 1, 9999, REINTENTOS)==0){

					libros[idMod].FechaPublicacion.dia=auxDia;
					libros[idMod].FechaPublicacion.mes=auxMes;
					libros[idMod].FechaPublicacion.anio=auxAnio;
					retorno=0;
					}
				}
			}
				break;
		case 3:
			if(utn_getNumeroFloat(&auxImporte, "ingresar el importe", "Error", 1, 9999, REINTENTOS)==0){
				libros[idMod].importe=auxImporte;
				retorno=0;
			}
				break;
		case 4:
			mostrarAutor(autor, CANT, pais);
			if(utn_getInt(&auxAutor, "ingrese el Autor", "error", 1, 3, REINTENTOS)==0){
				libros[idMod].idAutor=auxAutor;
				retorno=0;
			}
			break;
		case 5:
			mostrarEditorial(editorial, CANT);
			if(utn_getInt(&auxEditorial, "ingrese la editorial", "error", 1, 3, REINTENTOS)==0){
				libros[idMod].idEditorial=auxEditorial;
				retorno=0;
			}
			break;
		case 6:
			mostrarGenero(genero, tam);
			if(utn_getInt(&auxGenero, "ingrese el genero", "Error", 1, 5, REINTENTOS)==0){
				libros[idMod].idGenero=auxGenero;
				retorno=0;
			}
			break;
		}

	}

	return retorno;
}


int borrarLibros(eLibro libros[] , int tam,int idMod){

	int retorno=-1;

	if(libros !=NULL && tam > 0 && idMod >= 0){

		for(int i=0;i<tam;i++){
			if(libros[i].estado==OCUPADO && libros[i].codLibro==idMod){

				libros[i].estado=LIBRE;
				printf("El dato se elimino correctamente\n");
				retorno=0;

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



void harcodeoAutor(eAutor autor[],int tam){
	eAutor auxAutor[3]={
		{1,"nombre1",1},
		{2,"nombre2",2},
		{3,"nombre3",3},
	};
	for(int i=0;i<3;i++){
		 autor[i]=auxAutor[i];
	}
}

void harcodeoPais(ePais pais[],int tam){
	ePais auxPais[3]={
		{1,"pais1",OCUPADO},
		{2,"pais2",OCUPADO},
		{3,"ARG",OCUPADO},
	};
	for(int i=0;i<3;i++){
		pais[i]=auxPais[i];
	}
}

void harcodeoEditorial(eEditorial editorial[],int tam){
	eEditorial auxEditorial[3]={
		{1,"descripcion1",OCUPADO},
		{2,"descripcion2",OCUPADO},
		{3,"descripcion3",OCUPADO},
	};
	for(int i=0;i<3;i++){
		editorial[i]=auxEditorial[i];
	}
}


void mostrarEditorial(eEditorial editorial[] , int tam){
	if(editorial != NULL && tam>0){
		printf("CODEDITORIAL\tDESCRIPCION\n");
		for(int i=0;i<tam;i++){
			if(editorial[i].estado==OCUPADO){
				printf("%d\t\t%s\t\n",editorial[i].codEditorial,editorial[i].descripcion);
			}
		}
	}
}
void mostrarAutor(eAutor autor[] , int tam , ePais pais[]){
	printf("CODAUTOR\tNOMBRE\t\tNACIONALIDAD\n");
	for(int i=0; i<tam; i++){
			for(int j=0; j<3; j++ ){
				if( autor[i].idNacionalidad == pais[j].codPais ){
					printf("%d\t\t%s\t\t%s\n",autor[i].codAutor,autor[i].nombre, pais[i].descripcion);
				}

			}

		}
}

//prueba
void mostrarLibros(eLibro libros[],int tam ,eAutor autor[] ,eEditorial editorial[],eGenero genero[]){

	if(libros != NULL && autor!= NULL && editorial != NULL && genero !=NULL && tam > 0 ) {

		printf("ID\tTITULO\tDIA\tMES\tA�O\tIMPORTE\tDESCRIPCIONA\tDESCRIPCIONE\t GENERO\n");
		for(int i=0;i<tam;i++){
			if(libros[i].estado==OCUPADO){
				for(int j=0; j<3; j++ ){
					if(libros[i].idAutor == autor[j].codAutor ){
						for(int h=0; h<3; h++ ){
							if(libros[i].idEditorial == editorial[h].codEditorial){
								for (int g=0; g<5; g++ ){
									if(libros[i].idGenero == genero[g].codGenero){
										mostrarIndividual(&libros[i],&autor[j], &editorial[h], &genero[g]);
									}
								}
							}
						}
					}
				}
			}
		}
	}else{
		printf("ERROR");
	}
}
void mostrarIndividual(eLibro libros[],eAutor autor[] , eEditorial editorial[],eGenero genero[]){
	printf("%d\t%s\t%d\t%d\t%d\t%f\t%s\t%s\t%s\n",libros->codLibro,libros->titulo,libros->FechaPublicacion.dia,libros->FechaPublicacion.mes,libros->FechaPublicacion.anio,libros->importe ,autor->nombre,editorial->descripcion,genero->descripcion);
}


float TotalImportes(eLibro libros[],int tam , float * promedio){
	float total=0;
	int contImporte=0;
	if(libros !=NULL && tam>0){
		for(int i=0;i<tam;i++){
			if(libros[i].estado==OCUPADO ){
				total=total+libros[i].importe;
				contImporte++;
			}
		}
		*promedio=promedioImporte(contImporte, total);
	}
	return total;
}

float promedioImporte(int cantidadImportes , float totalImporte){

	int promedio=0;

	if(cantidadImportes>0 && totalImporte>0){
		promedio=totalImporte/(float)cantidadImportes;
	}

	return promedio;
}


int LqSuperanPromedio(eLibro libros[],float promedio , int tam){
	int contLibrosSP=0;

	if(promedio>0){
		for(int i=0;i<tam;i++){
			if(promedio > libros[i].importe && libros[i].estado==OCUPADO){
				contLibrosSP++;
			}
		}
	}
	return contLibrosSP;
}

int cantidadLSF(eLibro libros[], int tam){
	int contSF=0;

	if(libros != NULL && tam>0){
		for(int i=0;i<tam;i++){
			if(libros[i].FechaPublicacion.anio <= 2000 && libros[i].estado==OCUPADO){
				contSF++;
			}
		}
	}
	return contSF;
}


void mostrarPais(ePais pais[] , int tam){
	if(pais != NULL && tam>0){
		printf("CODPAIS\tDESCRIPCION\n");
		for(int i=0;i<tam;i++){
			if(pais[i].estado==OCUPADO){
				printf("%d\t%s\t\n",pais[i].codPais,pais[i].descripcion);
			}
		}
	}
}


void ordTituloyImporte(eLibro libros[], int tam){
	if(libros !=NULL && tam > 0){
		eLibro auxLibro;
		for( int i=0; i< tam-1; i++){
				for( int j=i+1; j<tam; j++ ){
					if( libros[i].importe < libros[j].importe ){//descendente
						auxLibro = libros[i];
						libros[i] = libros[j];
						libros[j] = auxLibro;
					}
					// 'I1' < 'I2' || 'I1' == 'I2' || 'T1' == 'T2'
					else{
						if( libros[i].importe == libros[j].importe ){
							if( strcmp( libros[i].titulo, libros[j].titulo ) > 0 ){//asceendente
								auxLibro = libros[i];
								libros[i] = libros[j];
								libros[j] = auxLibro;
							}

						}
					}
				}
		}
	}
}


//PARTE 2
void harcodeoGenero(eGenero genero[],int tam){
	eGenero auxGenero[5]={
		{1,"Narrativo",OCUPADO},
		{2,"Lirico",OCUPADO},
		{3,"Dramatico",OCUPADO},
		{4,"Didactico",OCUPADO},
		{5,"Novela",OCUPADO},
	};
	for(int i=0;i<5;i++){
		genero[i]=auxGenero[i];
	}
}


void mostrarGenero(eGenero genero[],int tam){
	int i;
	if(genero != NULL && tam>0){
		printf("CODGENERO\tDESCRIPCION\n");
		for(i=0;i<tam;i++){
			if(genero[i].estado==OCUPADO){
				printf("%d\t\t%s\t\n",genero[i].codGenero,genero[i].descripcion);
			}
		}
	}
}

int mostLibrosNnovela(eLibro libros[], int tam,eAutor autor[] ,eEditorial editorial[]){
	int retorno=-1;
	printf("ID\tTITULO\tDIA\tMES\tA�O\tIMPORTE\tDESCRIPCIONA\tDESCRIPCIONE\n");
	for(int i=0;i<tam;i++){

		if(libros[i].estado==OCUPADO && libros[i].idGenero != 5){
			printf("%d\t%s\t%d\t%d\t%d\t%f\t%s\t%s\n",libros[i].codLibro,libros[i].titulo,libros[i].FechaPublicacion.dia,libros[i].FechaPublicacion.mes,libros[i].FechaPublicacion.anio,libros[i].importe ,autor[i].nombre,editorial[i].descripcion);
			retorno=0;
		}
	}
	return retorno;
}



int autoresAporEDet(eLibro libros[], int tam,eEditorial editorial[] ,eAutor autor[] ,eGenero genero[]){

	int buscarEditorial;
	int retorno=-1;
	mostrarEditorial(editorial, tam);
	if(utn_getInt(&buscarEditorial, "elige la editorial determianada", "Error", 1, 3, REINTENTOS)==0){
		if(buscarEditorial >0){
			for(int i=0;i<tam;i++){

				for(int j=0; j<3; j++ ){
					for(int h=0; h<3; h++ ){
						for (int g=0; g<5; g++ ){
							if(libros[i].idAutor == autor[j].codAutor ){
								if(libros[i].idEditorial == editorial[h].codEditorial){
									if(libros[i].idGenero == genero[g].codGenero){
										if(libros[i].idEditorial == buscarEditorial && libros[i].idAutor == 3){
											printf("%d\t%s\t%d\t%d\t%d\t%f\t%s\t%s\t%s\n",libros[i].codLibro,libros[i].titulo,libros[i].FechaPublicacion.dia,libros[i].FechaPublicacion.mes,libros[i].FechaPublicacion.anio,libros[i].importe ,autor[j].nombre,editorial[h].descripcion ,genero[g].descripcion);
											retorno=0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}
