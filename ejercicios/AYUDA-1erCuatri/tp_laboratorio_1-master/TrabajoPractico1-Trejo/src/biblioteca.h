/*
 * biblioteca.h
 *
 *  Created on: 18 sep. 2021
 *      Author: maxim
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>

/* breve hago la multiplicacion de 2 numeros enteros
 * param1 recibe el primer número entero, para multiplicacion
 * param2 recibe el segundo número entero para multiplicacion
* param3 recibe la direccion de la variable para guardar el resultado de la multiplicacion */
int resultadoMultiplicar( int numUno, int numDos);

/* cálculo breve de la division de 2 numeros enteros, y lo devuelve como un float
 * param1 recibe el primer número entero, para dividiendo
 * param2 recibe el segundo número entero para divisior
* param3 recibe la direccion de la variable para guardar el resultado de la divsion y lo guarda como un float */
int resultadoDivision( int numUno, int numDos,float *resultadoDivision);

/* breve cálculo de la resta de 2 numeros enteros
 * param1 recibe el primer número entero, para restar
 * param2 recibe el segundo número entero para restar*/
int resultadoResta(int numUno, int numDos);

/* breve cálculo de la suma de 2 numeros enteros
 * param1 recibe un número entero, para sumar
 * param2 recibe un número entero para sumar
 */
int resultadoSuma(int numUno, int numDos);

/* breve hago el factoreo del primer numero entero
 * param1 recibe el primer número entero, para hacer el factoreo
* param2 recibe la direccion de la variable para guardar el resultado del factoreo */
void factorialA(int num1,int* resulFactorialA);

/* breve hago el factoreo del segundo numero entero
 * param1 recibe el segundo número entero, para hacer el factoreo
* param2 recibe la direccion de la variable para guardar el resultado del factoreo */
void factorialB(int num2,int* resulFactorialB);

/*breve muestro los resultados de cada operacion
 * param1 recibe el resultado de la suma de 2 numeros enteros
 * param2 recibe el resultado de la resta de 2 numeroa enteros
 * param3 recibe el resultado de una multiplicacion de 2 numeros enteros
 * param4 recibe el numero ingresado por un usuario
 * param5 recibe el numero ingresado por un usuario
 * param6 recibe el resultado del primer numero factoriado
 * param7 recibe el resultado del segundo numero factoriado
 */
void respuestas(int suma, int resta , int multiplicacion , int A ,int B , int facA ,int facB);

#endif /* BIBLIOTECA_H_ */
