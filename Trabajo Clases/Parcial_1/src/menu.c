/*
 * menu.c
 *
 *  Created on: 2 oct 2022
 *      Author: maxim
 */



#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaLibro.h"
#include "menu.h"
#include "utn.h"

void menu (eLibro libros[],int tam,eAutor autor[] , eEditorial editorial[],ePais pais[] , eGenero genero[]){

	int opcion;//para el menu de opciones
		int flagLibros=0;
		int lugarLibre;
		int idIngresado;
		int idModificar;
		float promedio=0;
		int opcionInformes;//para el menu de Informes
		int opcionListar;//para el menu de Listar


		int buscarEditorial;

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

				   lugarLibre=BuscarLibre(libros,tam);
				   if(lugarLibre != -1){
					   if(AltaLibros(&libros[lugarLibre], autor, pais,editorial,genero) == 0){
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
				   		mostrarlibros(libros, tam ,autor,editorial,genero);

				   		if(utn_getInt(&idIngresado, "ingrese el id buscado", "Error", 1, CANT, REINTENTOS)==0){

				   			idModificar=buscarID(libros, tam, idIngresado);

				   			if(idModificar >=0){

				   				modificarLibros(libros, tam, idModificar, autor, pais, editorial,genero);
				   				//printf("ID\tTITULO\tDIA\tMES\tAÑO\tIMPORTE\tDESCRIPCIONA\tDESCRIPCIONE\n");
				   				mostrarlibros(libros, tam ,autor,editorial,genero);


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
				  		mostrarlibros(libros,tam,autor,editorial,genero);

				  		if(utn_getInt(&idIngresado, "ingrese el id ", "Error",1, CANT, REINTENTOS)==0){
				  			borrarLibros(libros, tam, idIngresado);
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
				   					printf("El total de importe es %f \n",TotalImportes(libros, tam,&promedio));
				   					printf("El promedio de los importes es %f\n", promedio);
				   					printf("La cantidad de libros que superan el promedio son %d\n", LqSuperanPromedio(libros, promedio, tam));
				   					break;
				   				case 2:
				   					printf("La cantidad de libros que cuya fecha de publicación es anterior a 01/01/2000 son  %d \n", cantidadLSF(libros, tam));
				   					 break;
				   			}
				   		}
				   	}else {
				   		printf("no hay libros cargados");
				   	}
				   break;
			   case 5:
				   if(flagLibros>0){
				   		menulistar();
				   		if(utn_getInt(&opcionListar, "ingresa la opcion\n", "error",1, 9, REINTENTOS)==0){
				   			switch(opcionListar){
				   				case 1:
				   					mostrarEditorial(editorial, tam);
				   				break;
				   				case 2:
				   					 mostrarPais(pais, tam);
				   				break;
				   				case 3:
				   					 mostrarAutor(autor, tam, pais);
				   				break;
				   				case 4:
				   					 mostrarlibros(libros, tam, autor, editorial,genero);
				   				break;
				   				case 5:
				   					 ordTituloyImporte(libros, tam);
				   					 mostrarlibros(libros, tam, autor, editorial,genero);
				   				break;
				   				case 6:
				   					mostrarGenero(genero, tam);
								break;
				   				case 7:
				   					mostLibrosNnovela(libros, tam, autor, editorial);
				   				break;
				   				case 8:


				   					//autoresAporEDet(libros, tam, editorial, autor); no llegue a convertirla en funcion

				   					//int buscarEditorial;
				   					mostrarEditorial(editorial, tam);
				   					if(utn_getInt(&buscarEditorial, "elige la editorial determianada", "Error", 1, 3, REINTENTOS)==0){
				   						if(buscarEditorial >0){
				   							for(int i=0;i<tam;i++){
				   								if(libros[i].idEditorial == buscarEditorial && libros[i].idAutor == 3 ){
				   									printf("%d\t%s\t%d\t%d\t%d\t%f\t%s\t%s\n",libros[i].codLibro,libros[i].titulo,libros[i].FechaPublicacion.dia,libros[i].FechaPublicacion.mes,libros[i].FechaPublicacion.anio,libros[i].importe ,autor[i].nombre,editorial[i].descripcion);
				   								}

				   							}
				   						}
				   					}

				   					break;
				   			}
				   		}
				   	}else {
				   		printf("no hay libros cargados");
				   	}
				   break;
			}

		}while(opcion !=6);

}


void menuInformes(){
    printf("\nMenu de informes"
            "\n1. Total y promedio de los importes, y cuántos libros superan ese promedio."
            "\n2. Cantidad de libros cuya fecha de publicación es anterior a 01/01/2000."
    		"\n3.Salir\n");
}


void menulistar(){
	 printf("\nMenu de listar"
	            "\n1.Todas las editoriales."
	            "\n2.Todos los países."
	            "\n3.Todos los autores."
	            "\n4.Todos los libros."
			 	"\n5.Ordenar albumes por Importe o Titulo"
			 	"\n6.mostrar generos"
			 	"\n7.mostrar libros cuyo genero no sea novela "
				"\n8.mostrar libros ARG que correspondan a una editorial determinada  "
			 	"\n9.Salir.\n");
}


void menuOpciones(void){
	printf("Bienvenido");
    printf("\n1) Alta.");
    printf("\n2) Modificacion.");
    printf("\n3) Baja.");
    printf("\n4) Informar.");
    printf("\n5) Listar.");
    printf("\n6) Salir.");
}

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
	indice = -1;//Si no encuentra un usuario inactivo-> Si el array está lleno.
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
