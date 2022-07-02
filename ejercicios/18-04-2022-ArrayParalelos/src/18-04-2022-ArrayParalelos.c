/*
 ============================================================================
 Name        : 18-04-2022.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */



// para cambiar todo ctrl+f y reemplazar todo




#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 50//COLUMNAS //tamaño de las letras que puede poner el usuario
#define CANT 3//FILAS  // cantidad de datos que puede ingresar

void cargarVector(char nombreCliente[][CANT],char apellidoCliente[][CANT],int horaReserva[CANT],int llegada[CANT],int filas);
void mostrarVector(char nombreCliente[][CANT],char apellidoCliente[][CANT],int horaReserva[CANT],int llegada[CANT],int filas);
void ordenarVectorPorApellido(char nombreCliente[][CANT],char apellidoCliente[][CANT],int horaReserva[CANT],int llegada[CANT],int filas);



int main(void) {

	setbuf(stdout,NULL);
	char nombreCliente[TAM][CANT];//el 50 es el largo del nombre y el len es la cantidad del nombres que va a guardar
	char apellidoCliente[TAM][CANT];
	int horaReserva[TAM];
	int horaLlegada[TAM];

	cargarVector(nombreCliente,apellidoCliente,horaReserva,horaLlegada,CANT);
	ordenarVectorPorApellido(nombreCliente,apellidoCliente,horaReserva,horaLlegada,CANT);
	mostrarVector(nombreCliente,apellidoCliente,horaReserva,horaLlegada,CANT);


	return EXIT_SUCCESS;
}


void cargarVector(char nombreCliente[][CANT],char apellidoCliente[][CANT],int horaReserva[CANT],int llegada[CANT],int filas){
	for(int i=0;i<filas;i++){

			printf("Ingrese el nombre");
			fflush(stdin);
			scanf("%[^\n]",nombreCliente[i]);//para que puedan poner los espacios
			printf("Ingrese el apellido");
			fflush(stdin);
			scanf("%[^\n]",apellidoCliente[i]);//al lado de TAM le pongo i porque la cantidad de veces que tiene que cargar es lo que busca no el tamaño
			printf("Ingrese la horas de reserva");
			fflush(stdin);
			scanf("%d",&horaReserva[i]);
		}
}

void mostrarVector(char nombreCliente[][CANT],char apellidoCliente[][CANT],int horaReserva[CANT],int llegada[CANT],int filas){
	for(int i=0;i<filas;i++){
			printf("NOMBRE: %s\t| APELLIDO %s\t| HORA: %d\t|\n", nombreCliente[i],apellidoCliente[i],horaReserva[i]);
	}
}


void ordenarVectorPorApellido(char nombreCliente[][CANT],char apellidoCliente[][CANT],int horaReserva[CANT],int llegada[CANT],int filas){

	char auxiliar[30];
	int auxHora;
	int auxLlegada;

	for(int i=0;i<filas - 1;i++){

		for(int j=i+1 ;j<filas;j++){

			if(strcmp(apellidoCliente[i],apellidoCliente[j])>0){

				strcpy(auxiliar,apellidoCliente[i]);
				strcpy(apellidoCliente[i],apellidoCliente[j]);
				strcpy(apellidoCliente[j],auxiliar);
				//-------------
				strcpy(auxiliar,nombreCliente[i]);
				strcpy(nombreCliente[i],nombreCliente[j]);
				strcpy(nombreCliente[j],auxiliar);
				//-------------
				auxHora=horaReserva[i];
				horaReserva[i]=horaReserva[j];
				horaReserva[j]=auxHora;
				//------
				auxLlegada=llegada[i];
				llegada[i]=llegada[j];
				llegada[j]=auxLlegada;
			}
		}
	}
}
