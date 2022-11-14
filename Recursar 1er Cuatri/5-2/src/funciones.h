/*
 ============================================================================
Ejercicio 5-2:
Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
a) Cantidad de positivos y negativos.
b) Sumatoria de los pares.
c) El mayor de los impares.
d) Listado de los números ingresados.
e) Listado de los números pares.
f) Listado de los números de las posiciones impares.
Anexo 5-2
g) Los números que se repiten
h) Los positivos creciente y los negativos de manera decreciente
Se deberán utilizar funciones y vectores.
 ============================================================================
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


void pedirNum(int numeros[], int tam );
int mayImpar(int numeros[],int tam, int size);
int sumarPares(int numero[],int tam);
void listarNumPares(int numeros[],int tam);
void listarNum(int numeros[],int tam);
void cantPosyNeg(int numero[],int tam);



#endif /* FUNCIONES_H_ */
