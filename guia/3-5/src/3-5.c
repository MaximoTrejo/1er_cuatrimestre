/*
 ============================================================================
 Name        : 3-5.c
 Author      : MaximoTrejo
 Version     :

 Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4 combinaciones. (Apunta a que entiendan el concepto de independencia del código)
	int Sumar1(int, int);
	int Sumar2(void);
	void  Sumar3(int, int);
	void Sumar4(void);

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int SumarUno(int numUno, int numDos);
int SumarDos(void);
void SumarTres(int numUno, int numDos);
void SumarCuatro(void);

int main(void) {
	setbuf(stdout,NULL);
	int numUno;
	int numDos;
	int sumarUno;
	int sumarDos;
	printf("\ningrese un numero");
	scanf(" %d" , &numUno);
	printf("\ningrese un numero");
	scanf(" %d" , &numDos);
	//--------------------------------------------
	sumarUno=SumarUno(numUno, numDos);
	printf("el resultado es %d" ,  sumarUno);
	//----------------------------------------
	sumarDos=SumarDos();
	printf("el resultado es %d" ,  sumarDos);
	//--------------------------------------------
	SumarTres(numUno, numDos);
	//--------------------------------------------
	SumarCuatro();

	return EXIT_SUCCESS;
}

int SumarUno(int numUno, int numDos){
	int sumar;
	sumar =numUno+numDos;
	return sumar;
}

int SumarDos(void){
	int numUno;
	int numDos;
	int sumar;
	printf("\ningrese un numero");
	scanf(" %d" , &numUno);
	printf("\ningrese un numero");
	scanf(" %d" , &numDos);
	sumar =numUno+numDos;
	return sumar;
}

void SumarTres(int numUno, int numDos){
	int sumar;
	sumar =numUno+numDos;
	printf("el resultado es %d" ,  sumar);


}
void SumarCuatro(void){
	int numUno;
	int numDos;
	int sumar;
	printf("\ningrese un numero");
	scanf(" %d" , &numUno);
	printf("\ningrese un numero");
	scanf(" %d" , &numDos);
	sumar =numUno+numDos;
	printf("el resultado es %d" ,  sumar);
}
