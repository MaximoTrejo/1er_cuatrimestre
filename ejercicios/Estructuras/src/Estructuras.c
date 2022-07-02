/*
 ============================================================================
 Name        : Estructuras.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 *
//Porcentaje que representa cada de destino en funcion del total de tickets
//El o los Destinos mas concurridos
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ticket.h"

int main(void) {
	setbuf(stdout, NULL);
//--------------------------------
	int i;
	int opcion;
	int flag=0 ;
	int cantidadDatos = 0;
	int opcionModificar;
	char confirmar;
	int retorno;
	//int cantidadCodigo=0;

	//eTicket unVuelo = {1000,"Juan","Gomez",17};//se pueden las 2 porque estan en una espacio de memoria (jarcodear)
	//unVuelo=pedirDatosTicket();
	//mostrarTicket(unVuelo);

	eDestino listaDestino[CANT] ;
	eTicket tickets[CANT];
	int auxCodigo;

	//inicializamos los estados en cero
	for(int i=0;i<CANT ;i++){
		tickets[i].estado=LIBRE;
	}

	inicializarTickets(tickets, CANT);
	inicializarDestino(listaDestino,CANT);
	cantidadDatos=5;

	do{

			printf("1.Alta");
			printf("\n2.baja");
			printf("\n3.modificacion");
			printf("\n4 listar");
			printf("\n5.buscar dato");
			printf("\n6.salir");
			printf("\nOpcion");
			scanf("%d" ,&opcion);

			switch(opcion)
			{
				case 1:
					//ALTA
					retorno=cargarUnTicketEnLista(tickets, CANT, listaDestino, CANT);

					switch(retorno){
						case -1:
							printf("no hay espacio");
							break;
						default:
							printf("ticket cargado\n");
							cantidadDatos++;

							break;
					}
				break;


				//BAJA
				case 2:


					if(cantidadDatos > 0){

						printf("Codigo a borrar:  ");
						scanf("%d" , &auxCodigo);
						for(i=0; i<CANT; i++){
							if(tickets[i].codigo == auxCodigo && tickets[i].estado == 1 ){
								mostrarTicket(tickets[i]);
								printf("dar de baja?[S|N]");
								fflush(stdin);
								scanf("%c",&confirmar);
								if(confirmar=='s'){
									/*
									tickets[i].codigo=0;
									tickets[i].nombre[0] = '\0';
									tickets[i].apellido[0] = '\0';
									tickets[i].horarioSalida= 0;
									tickets[i].horarioLlegada= 0;
									*/
									tickets[i].estado = 0;
									cantidadDatos--;
									printf("los datos han sido borrado...");
								}else{
									printf("los datos no han sido borrado...");
								}

								break;
							}
						}

					}else{
						printf("No hay datos cargados...");
					}

				break;

				case 3:
					//MODIFICACION
					if(cantidadDatos > 0){

						printf("Codigo a modificar:  ");
						scanf("%d" , &auxCodigo);

						for(i=0; i<CANT; i++){

							if(tickets[i].codigo == auxCodigo && tickets[i].estado == 1 ){
								do{
									printf("Menu modificar");
									printf("\n1.Codigo");
									printf("\n2.nombre");
									printf("\n3.Apellido");
									printf("\n4.Horario de salida");
									printf("\n5.Horario de llegada");
									printf("\n6.Salir");
									printf("\nOpcion..");
									scanf("%d" ,&opcionModificar);

									switch(opcionModificar){
										case 1:
											printf("codigo");
											scanf("%d",&tickets[i].codigo);
										break;
										case 2:
											printf("nombre");
											fflush(stdin);
											scanf("%[^\n]",tickets[i].nombre);
										break;

										case 3:
											printf("apellido");
											fflush(stdin);
											scanf("%[^\n]",tickets[i].apellido);
										break;
										case 4:
											printf("horario de salida");
											scanf("%d",&tickets[i].horaSalida);
										break;
										case 5:
											printf("horario de llegada");
											scanf("%d",&tickets[i].horaLlegada);
									    break;
										case 6:
											printf("Saliendo del menu de modificacion");
										break;
										default:
											printf("la opcion ingresada es incorrecta...");
									}

								}while(opcionModificar !=6 );
								//tickets[i] = pedirDatosTicket();
								break;
							}
						}
					}else{

						printf("No hay datos cargados...");
					}

				break;

				case 4:
					//LISTAR
					if(cantidadDatos > 0){

						mostrarListadoTickets(tickets, CANT);

					}else{
						printf("No hay datos cargados...");
					}

				break;

				case 5:

					//BUSCAR UN DATO
					 if( cantidadDatos > 0) {
						 //buscar un numero dentro del vector
						 flag = 0;

						 printf("Ingrese codigo a buscar: ");
						 scanf("%d", &auxCodigo);

						 for(i=0; i<CANT; i++){
							 if(auxCodigo == tickets[i].codigo && tickets[i].estado== 1){
								 /* asignacionesy modificaciones*/
								 printf("Se encontro el numero");
								 flag = 1;
								 break;
							  }
						 }
						if( flag == 0 ) {
						printf("El dato no se encontro");
						}
					 }else{

						 printf("No hay datos cargados...");
					 }
				break;

				case 6:


					break;

				case 7:
					//MOSTRAR DESTINO


					for(int i=0;i<CANT;i++){//lista tickets
						if(tickets[i].estado==OCUPADO){
							for(int j=0;j<3;j++){//destinos
								if(tickets[i].idDestino == listaDestino[j].idDestino){//match de listaDestino (ids) fk(tickets)-pk(destinos)
									printf("%d | %s | %s | %s , %s | %d\n" , tickets[i].codigo , tickets[i].nombre ,tickets[i].apellido , listaDestino[j].ciudad , listaDestino[j].pais ,listaDestino[j].duracion);
									break;
								}
							}

						}

					}
					break;

				case 8:

					for(int i=0;i<3;i++){//destinos
						printf("%s , %s\n ",listaDestino[i].ciudad, listaDestino[i].pais);

						for(int j=0;j<CANT;j++){//tickets
							if(tickets[j].estado == OCUPADO &&  listaDestino[i].idDestino == tickets[j].idDestino){

								printf(" \t -> %s %s | %d\n", tickets[j].nombre , tickets[j].apellido , tickets[j].horaSalida);

							}
						}
					}
					break;

				default:
					printf("La opcion no es valida\n");
			}

		}while(opcion != 5);

	return EXIT_SUCCESS;

}

