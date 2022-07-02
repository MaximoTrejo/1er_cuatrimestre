/*
 * ticket.h
 *
 *  Created on: 25 abr. 2022
 *      Author: maxim
 */

#ifndef TICKET_H_
#define TICKET_H_
//-----------------
#define CANT 100
//-----------------
#define LIBRE 0
#define OCUPADO 1

//ESTRUCTURAS RELACIONADAS

typedef struct
	{
		int idDestino;
		char pais[20];
		char ciudad[20];
		int duracion;

	}eDestino;

	typedef struct
	{
			int codigo;//campos o atributos
			char nombre[20];
			char apellido[20];
			int horaSalida;
			int horaLlegada;
			int estado;
			int idDestino;//para relacionar eDestino

	}eTicket;



	eTicket pedirDatosTicket();//porque devuelve la estructura //devuelve el ticket por valor

	int BuscarEspacioLibre(eTicket listaTickets[],int tam);
	int cargarUnTicketEnLista(eTicket listaTickets[],int tam, eDestino listaDestino[], int tamDestino);
	void mostrarListadoTickets(eTicket listaTickets[],int tam);
	void mostrarTicket(eTicket unTicket);
	void inicializarTickets(eTicket lista[],int tam);
	void inicializarDestino(eDestino lista[],int tam);

#endif /* TICKET_H_ */
