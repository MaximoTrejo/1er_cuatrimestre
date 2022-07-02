/*
 * ticket.c
 *
 *  Created on: 25 abr. 2022
 *      Author: maxim
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ticket.h"



void mostrarTicket(eTicket unTicket){
	printf("%d | %s |%s |%d | %d | %d |\n " , unTicket.codigo , unTicket.nombre , unTicket.apellido ,unTicket.horaLlegada ,unTicket.horaSalida,unTicket.idDestino);
}

eTicket pedirDatosTicket( eDestino listaDestino[], int tamDestino){
	eTicket miTicket;
	//para poner un codigo automatico
	//miTicket.codigo=codigo;

	printf("ingrese codigo de vuelo: ");
	fflush(stdin);
	scanf("%d" ,&miTicket.codigo);

	printf("ingrese el nombre: ");
	fflush(stdin);
	scanf("%[^\n]" ,miTicket.nombre);//le saco el & porque es una cadena

	printf("ingrese el apellido: ");
	fflush(stdin);
	scanf("%[^\n]" ,miTicket.apellido);

	printf("ingrese horario de llegada: ");
	fflush(stdin);
	scanf("%d" ,&miTicket.horaLlegada);

	printf("ingrese horario de salida: ");
	fflush(stdin);
	scanf("%d" ,&miTicket.horaSalida);

	//-----DESTINO-----
	printf("DESTINO");
	for(int i=0; i<tamDestino;i++){
		printf("\n%d %s %s", listaDestino[i].idDestino , listaDestino[i].ciudad,listaDestino[i].pais);
	}
	printf("\nselecciona un pais");
	scanf("%d" , &miTicket.idDestino);

	miTicket.estado=OCUPADO;
	return miTicket;
}

int BuscarEspacioLibre(eTicket listaTickets[],int tam){
 int retorno;//infrx
 retorno=-1;//lo inicializo en error
 for(int i=0;i<tam;i++){
	 if(listaTickets[i].estado==LIBRE){

		 retorno=i;
		 break;
	 }
 }

 return retorno;
}

int cargarUnTicketEnLista(eTicket listaTickets[],int tam, eDestino listaDestino[], int tamDestino){
	int retorno;

	retorno=BuscarEspacioLibre(listaTickets, tam);
	if(retorno!=-1){
		listaTickets[retorno] = pedirDatosTicket(listaDestino,tamDestino);
	}

	return retorno ;
}

void mostrarListadoTickets(eTicket listaTickets[],int tam){
	int i;
	for(i=0; i<CANT; i++){
		if(listaTickets[i].estado == OCUPADO ){

			mostrarTicket(listaTickets[i]);
		}
	}


}

void inicializarTickets(eTicket lista[],int tam){
	eTicket carga[5]={
			{1,"maxi","trejo",02,06,OCUPADO,2},
			{2,"Harry","Martin",02,06,OCUPADO,2},
			{3,"german","Martin",02,06,OCUPADO,1},
			{4,"facu","elbey",02,06,OCUPADO,2},
			{5,"facundo","palmito",02,06,OCUPADO,3},
					}; //harcodeo (cargo manual)

	for(int i=0; i<5; i++){
		lista[i]=carga[i];
	}

}

void inicializarDestino(eDestino lista[],int tam){
	eDestino carga[3]={
			{1,"EEUU","miami",12},
			{2,"Espa�a","Barcelona",14},
			{3,"Francia","Paris",16}
					};

	for(int i=0;i<3;i++){
		lista[i]=carga[i];
	}
}
