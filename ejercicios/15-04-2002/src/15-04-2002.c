/*
 ============================================================================
 Name        : 15-04-2002.c
 Author      : 
 Version     :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define EDADDES 5

// EJERCICIO: Pedirle al usuario 5 edades y LUEGO
// imprimir las 5 edades. Definir un array de 5 posiciones.
// y usar la funcion utn getNumero() para pedir los valores

int main(void) {
	setbuf(stdout,NULL);

	int edad ;
	int arrayEdades[EDADDES];
	int i;

//CARGAR (recorro para cargar de forma secuencial(uno detras del otro))
for(i=0;i<EDADDES;i++){

	if(utn_getNumero(&edad,"Ingrese edad:", "Esta edad no va\n",1,120,3)==0){
	//if(utn_getNumero(&arrayEdades[i],"Ingrese edad:", "Esta edad no va\n",1,120,3)==0){(sacando la variable edad)
		//printf("Ingresaste edad: d\n", edad);
		//en edaddes escribp edad en la posicion "i"
		arrayEdades[i]=edad;
	}
	else{
	   printf("Sonaste no tenes idea lo que es una eda'\n");
	}

}

	imprimirArrayD(arrayEdades,EDADDES);

	return EXIT_SUCCESS;
}
//REGLA DE ORO
//EL NOMBRE DEL ARRAY ES LA DIRECCION DE MEMORIA DONDE COMIENZA EL ARRAY
//AL RECIBIR UN ARRAY TAMBIEN SE RECIBE SU TAMA�O

//recibir array -> por referencia (no se hace una copia , es el mismo)(como psar la direccion de memoria)
void imprimirArray(int array[]){//sintaxis para escribir un array en una funcion

	//MOSTRAR (recorro para imprimir)
	for(int i=0;i<EDADDES;i++)
	{
		printf("%d  ", array[i]);
	}

}


//array de diferentes tama�os
 void imprimirArrayD(int array[],int tam){

	//MOSTRAR (recorro para imprimir)
	for(int i=0;i<tam;i++)
	{
		printf("%d  ", array[i]);
	}

}


/*

 // PASAJE POR REFERENCIA // &
  *
	void imprimirArray (int e){
  	  int j;
  	  *e = 9; //leo o escribo el valor
  	 }


// PASAJE POR VALOR // sin &
	void imprimirArray(int e)
	{
  	  int j;
  	  // no puedo escribir la variable de afuera
  	  j=e+7 ; //leo el valor
  	}

 */


 //-----------------------------LLENAR UN ARRAY-------------------------------------

 /*
//LLENAR UN ARRAY

	//ARRAY de 7 lugares (seria del 0 al 6 )
	int numeros [7];

	//Ejemplo 1 con do While
	int X=0;
	do{
	    numeros [X] = 5;
	    X=X+1;
	}while(X<7);

//--------------------------------------------------
	// Ejemplo 2 con FOR
	int i;

	for (i=0; i<7; i++) // de e a 6
	{
	    numeros[i] = 5;

	}


  */
