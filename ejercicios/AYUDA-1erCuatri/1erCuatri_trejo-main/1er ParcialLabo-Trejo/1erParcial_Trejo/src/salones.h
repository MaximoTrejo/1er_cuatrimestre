/*
 * salones.h
 *
 *  Created on: 16 oct. 2021
 *      Author: maxim
 */

#ifndef SALONES_H_
#define SALONES_H_

#define NOMBRE_LEN 50
#define DIRECCION_LEN 20

typedef struct
{
	char nombre[NOMBRE_LEN];
	char direccion[DIRECCION_LEN];
	int tipo; // agregado!
	int id;
	int isEmpty;
}Salones;

int sal_initList(Salones array[], int len);
int sal_buscarLibre (Salones *pArray, int len);
int sal_altaArray(Salones* array,int limite, int indice, int* id);
//IMPRIMIR
int sal_imprimir(Salones* pElemento);
int sal_imprimirArray(Salones* array,int limite);
//--------
int sal_buscarId(Salones array[], int limite, int valorBuscado);

//MODIFICAR
int sal_modificar(Salones* pArray);

#endif /* SALONES_H_ */
