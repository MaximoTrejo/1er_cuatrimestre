/*
 ============================================================================
Ejercicio 3-5:
Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4
combinaciones.
int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int suma1(int num1 ,int num2);
int suma2();
void suma3(int num1 ,int num2);
void suma4();

int main(void) {

	setbuf(stdout,NULL);

int sumar1;
int sumar2;
int num1=2;
int num2=2;

sumar1 = suma1(num1 ,num2);
printf("el resueltado de la suma es %d\n", sumar1);
printf("termino el suma1\n");
//------------------------------------------------------------------
sumar2= suma2();
printf("el resueltado de la suma es %d\n", sumar2);
printf("termino el suma2\n");
//------------------------------------------------------------------
suma3(num1 ,num2);
printf("termino el suma3\n");
//------------------------------------------------------------------
suma4();
printf("termino el suma4\n");
//------------------------------------------------------------------

	return EXIT_SUCCESS;
}


int suma1(int num1 ,int num2){

	int suma;
	suma=num1+ num2;
	return suma;
}

int suma2(){
	int num1;
	int num2;
	int suma;
	printf("ingrese un numero");
	scanf("%d", &num1);
	printf("ingrese un numero");
	scanf("%d", &num2);
	suma=num1+num2;
	return suma;
}

void suma3(int num1 ,int num2){
	int suma;
	suma=num1+num2;
	printf("el resueltado de la suma es %d\n", suma);
}

void suma4(){
	int num1;
	int num2;
	int suma;
	printf("ingrese un numero");
	scanf("%d", &num1);
	printf("ingrese un numero");
		scanf("%d", &num2);
	suma=num1+num2;
	printf("el resueltado de la suma es %d\n", suma);
}
