/*
 ============================================================================
 Name        : 2-3.c
 Author      : MaximoTrejo

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define PASAJE 600

int main(void) {
	setbuf(stdout,NULL);
	int numCliente;
	char estadoCivil;
	int edad;
	float temCorp;
	char genero;
	char bucle;
	int contV=0;
	int mujerJ;
	int totalV;
	int numeroC;
	int contPasajeros=0;
	int contViejos=0;
	int descuento;
	do {
		printf("ingrese el num de cliente :");
		scanf(" %d",&numCliente);
		printf("\ningrese el estado Civil(S o C o V)");
		scanf(" %c",&estadoCivil);
		printf("\ningrese la edad :");
		scanf(" %d",&edad);
		printf("\ningrese su temp corporal :");
		scanf(" %f",&temCorp);
		printf("\ningrese su genero(M o F)");
		scanf(" %c",&genero);
		if(genero == 'F'){
			if(edad < mujerJ){
				mujerJ=edad;
				numeroC=numCliente;

			}
		}

		if(edad > 60){
			  contViejos=contViejos+1;
			if(estadoCivil=='V'){
				contV=contV+1;
			}
		}
		printf("\nQuiere seguir ingresando(S o N)");
		scanf(" %c",&bucle);
		contPasajeros=contPasajeros+1;

	}while(bucle != 'N');


		printf(" \nLa cantidad de personas con estado viudode más de 60 años son %d." , contV);
		printf(" \nel número de cliente y edad de la mujer soltera más joven.%d, %d" , numeroC , mujerJ);
		totalV=contPasajeros*PASAJE;
		printf("\ncuánto sale el viaje total sin descuento.%d" , totalV);

		if(contViejos>contPasajeros/2){
			descuento= totalV-(25*100/totalV);
		}

		printf("\nEl precio con descuento por viejo es.%d" , descuento);


	return EXIT_SUCCESS;
}
