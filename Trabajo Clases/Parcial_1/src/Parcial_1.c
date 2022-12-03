/*
 ============================================================================
 Name        : Parcial_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaLibro.h"
#include "menu.h"
#include "utn.h"

int main(void) {

	setbuf(stdout, NULL);

	eLibro libros[CANT];
	eAutor autor[CANT];
	eEditorial editorial[CANT];
	ePais pais[CANT];
	eGenero genero[CANT];

	inicializarAE(libros, CANT);
	harcodeoAutor(autor, CANT);
	harcodeoPais(pais, CANT);
	harcodeoEditorial(editorial, CANT);
	harcodeoGenero(genero, CANT);

	int opcion;//para el menu de opciones
	int flagLibros=0;
	int lugarLibre;
	int idIngresado;
	int idModificar;
	float promedio=0;
	int opcionInformes;//para el menu de Informes
	int opcionListar;//para el menu de Listar

	do{
		menuOpciones();
		if(utn_getInt(&opcion,"\nIngresar opcion","Error\n", 1, 6,REINTENTOS)==0){};

		switch(opcion)
		{
			case 1:
					   /*
					    * busco que haya un lugar libre y despues llamo a los datos si este se completa
					    * correctamente me muestra el mensaje
					    */
				lugarLibre=BuscarLibre(libros,CANT);
				if(lugarLibre != -1){
					if(altaLibros(&libros[lugarLibre], autor, pais,editorial,genero) == 0){
						flagLibros++;
						printf("el dato se cargo correctamente\n");
					}else{
						printf("el dato no se cargo\n");
					}
				}
				break;
			case 2:
					   /*
					   	* me fijo que el hayan cargado un libros
					   	* muestro los libros
					    * pregunto al usuario que libro quiere modificar
					   	* busco el id ingresado por el usuario
					   	* le muestro las opciones que puede modificar
					   	* le pregunto otra ves el dato
					   	* le muestro otra ves el dato modificado
					   	*/
				if(flagLibros>0){
					 mostrarLibros(libros, CANT ,autor,editorial,genero);
					 if(utn_getInt(&idIngresado, "ingrese el id buscado", "Error", 1, CANT, REINTENTOS)==0){
					   	idModificar=buscarID(libros, CANT, idIngresado);
					   		if(idModificar >=0){
					   			modificarLibros(libros, CANT, idModificar, autor, pais, editorial,genero);
					   			mostrarLibros(libros, CANT ,autor,editorial,genero);
					   		}else{
					   			printf("El id no existe\n ");
					   		}
					   	}
				}else{
					printf("No hay ningun libro creado");
				}
				break;
			case 3:
					   /*
					  	* me fijo que el hayan cargado un libro
					  	* muestro los libros
					  	* pregunto al usuario que libro quiere modifica
					  	* busco el id ingresado por el usuario
					  	* le cambio el estado
					  	* le confirmo al usuario que se borro
					  	*/
				if(flagLibros>0){
					mostrarLibros(libros,CANT,autor,editorial,genero);

					 if(utn_getInt(&idIngresado, "ingrese el id ", "Error",1, CANT, REINTENTOS)==0){
					  	borrarLibros(libros, CANT, idIngresado);
					  	flagLibros--;
					  }
				}else{
					printf("No hay libros cargados.....\n");
				}
				break;
			case 4:
				if(flagLibros>0){
					menuInformes();
					if(utn_getInt(&opcionInformes, "ingresa la opcion", "error",1, 3, REINTENTOS)==0){

					  switch(opcionInformes){
					   	case 1:
					   		printf("El total de importe es %f \n",TotalImportes(libros,CANT,&promedio));
					   		printf("El promedio de los importes es %f\n", promedio);
					   		printf("La cantidad de libros que superan el promedio son %d\n", LqSuperanPromedio(libros, promedio, CANT));
					   		break;
					   	case 2:
					   		printf("La cantidad de libros que cuya fecha de publicación es anterior a 01/01/2000 son  %d \n", cantidadLSF(libros, CANT));
					   		break;
					  }
					}
				}else{
					printf("No hay libros cargados\n");
				}
				break;
			case 5:
				if(flagLibros>0){
					menulistar();
					if(utn_getInt(&opcionListar, "ingresa la opcion\n", "error",1, 9, REINTENTOS)==0){
					   	switch(opcionListar){
					   		case 1:
					   			mostrarEditorial(editorial,CANT);
					   			break;
					   		case 2:
					   			mostrarPais(pais, CANT);
					   			break;
					   		case 3:
					   			mostrarAutor(autor, CANT, pais);
					   			break;
					   		case 4:
					   			mostrarLibros(libros, CANT, autor, editorial,genero);
					   			break;
					   		case 5:
					   			ordTituloyImporte(libros, CANT);
					   			mostrarLibros(libros,CANT, autor, editorial,genero);
					   			break;
					   		case 6:
					   			mostrarGenero(genero, CANT);
								break;
					   		case 7:
					   			if(mostLibrosNnovela(libros, CANT, autor, editorial)==0){
					   				printf("Se mostro correctamente\n");
					   			}else{
					   				printf("Todos los libros son novelas\n");
					   			}
					   			break;
					   		case 8:
					   			if(autoresAporEDet(libros, CANT, editorial, autor,genero)==0){
					   				printf("Se mostro correctamente\n");
					   			}else{
					   				printf("No se encontraron jugadores ARG\n");
					   			}
					   			break;
					   }
					}
				}else{
					printf("no hay libros cargados");
				}
				break;
		}

	}while(opcion !=6);

	return EXIT_SUCCESS;
}
