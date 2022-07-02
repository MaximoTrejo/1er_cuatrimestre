/*
 * arcades.h
 *
 *  Created on: 16 oct. 2021
 *      Author: maxim
 */

#ifndef ARCADES_H_
#define ARCADES_H_

#define NOMBREJUEGO_LEN 63
#define NACIONALIDAD_LEN 50

typedef struct
{
	int tipo;
	char nacionalidad[NACIONALIDAD_LEN];;
	int cantidadJugadores;
	int capacidadFichas;
	int id;
	int idSalon;
	char nombre[NOMBREJUEGO_LEN];
	int isEmpty;
}Arcades;

int arc_initList(Arcades array[], int len);
int arc_altaArray(Arcades* array,int limite, int indice, int* idArcade, int idSalones);
int arc_buscarLibre (Arcades *pArray, int len);
int arc_imprimirArray(Arcades* array,int limite);
int arc_imprimir(Arcades* pElemento);
int arc_modificar(Arcades* pArray);
int arc_buscarId(Arcades array[], int limite, int valorBuscado);
int arc_imprimirNombres(Arcades* array,int limite);
int arc_imprimirAux(Arcades* pElemento);

int arc_bajaArray(Arcades* array,int limite, int indice);

#endif /* ARCADES_H_ */
