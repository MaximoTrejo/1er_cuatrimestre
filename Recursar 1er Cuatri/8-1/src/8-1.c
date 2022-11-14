/*
 ============================================================================
 Name        : 8-1.c
 Author      : MaximoTrejo

 Crear la estructura Jugador (nombre, goles metidos, partidos jugados, promedio de goles).
 Crear una función que permita cargar los datos de un jugador y otra que los muestre.
 Una tercera función calculará el promedio de goles.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANT 4

typedef struct
{
	char nombre[20];
	int golesMetidos;
	int partidos;
	float promedioGoles;
	int estado;

}eJugador;


eJugador cargarJugadores();
void mostrarTicket(eJugador mostrarJugadores);
float promedioJugadores(int goles , int partidos);

int main(void) {
	setbuf(stdout, NULL);
	eJugador Jugadores[CANT];
	int cantidadDatos=0;

	for(int i=0;i<CANT ;i++){
		Jugadores[i].estado=0;
	}

	for(int i=0; i<CANT; i++){
		if( Jugadores[i].estado == 0 ) {
			Jugadores[i] = cargarJugadores();
			mostrarTicket(Jugadores[i]);
			cantidadDatos++;
			break;
		}
	}



	return EXIT_SUCCESS;
}

eJugador cargarJugadores(){
	eJugador jugadores;

	printf("ingrese el nombre: ");
	fflush(stdin);
	scanf("%[^\n]",jugadores.nombre);

	printf("goles metidos:");
	scanf("%d", &jugadores.golesMetidos);

	printf("partidos:");
	scanf("%d" ,&jugadores.partidos);

	jugadores.promedioGoles=promedioJugadores(jugadores.golesMetidos, jugadores.partidos);


	jugadores.estado=1;

	return jugadores;
}

void mostrarTicket(eJugador mostrarJugadores){
	printf("%s\t| %d\t|%d\t| promedioG %f  \n" , mostrarJugadores.nombre , mostrarJugadores.golesMetidos,  mostrarJugadores.partidos,mostrarJugadores.promedioGoles);
}


float promedioJugadores(int goles , int partidos){
	float promedio;

	if(goles>0 && partidos>0){
		promedio= (float)partidos/goles;
	}

	return promedio;
}
