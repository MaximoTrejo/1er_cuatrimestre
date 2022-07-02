/*
 ============================================================================
 Name        : Funciones.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//declaro la funcion
int sumarEnteros(int numUno , int numDos);
int restarEnteros(int numUno , int numDos);
int multiplicarEnteros(int numUno , int numDos);
int divisiones(int numUno , int numDos , float *resultadoDivision);
void respuestas(int suma, int resta , int multiplicacion);

int main(void) {

	setbuf(stdout,NULL);

	int numeroUno;
	int numeroDos;
	int suma;
	int resta;
	int multiplicacion;
	int division;
	//variable solo utilizada para guardar el dato POR REFERENCIA "*"
	float resultadoOperacion;

	printf("ingrese un numero\n");
	scanf ("%d",&numeroUno);

	printf("ingrese otro numero\n");
	scanf("%d" , &numeroDos);

	//se utilizan las funciones

	suma = sumarEnteros(numeroUno ,numeroDos);

	resta =restarEnteros(numeroUno ,numeroDos);

	multiplicacion = multiplicarEnteros(numeroUno , numeroDos);

	division= divisiones(numeroUno ,numeroDos ,&resultadoOperacion);

	//verifica si el numero q ingreso no es 0
	if(division==1){
		printf("pusiste un numero q no se puede dividir");
	}else{
		printf("el resultado es : %f" , resultadoOperacion);
	}


	respuestas(suma,resta , multiplicacion);

	//final del programa
	return EXIT_SUCCESS;
}

//Funciones(siempre se hacen al final del programa

int sumarEnteros(int numUno , int numDos){
 	 int sumar;
  	 sumar = numUno + numDos;
  	 return sumar;
}

int restarEnteros(int numUno , int numDos){
	int restar;
	restar=numUno-numDos;
	return restar;
}

int multiplicarEnteros(int numUno , int numDos){
	int multiplicar;
	multiplicar=numUno*numDos;
	return multiplicar;
}

//funcion por referencia
int divisiones(int numUno , int numDos , float *resultadoDivision){

	//se crea para validar (como el flag)
	int retorno=0;
	//si el numero q ingresa el usuario es distinto de 0 hace la cuenta ,sino avisa q hay un error
	if(numDos!= 0 ){
			*resultadoDivision= (float)numUno/numDos;
	}else {
		retorno = 1;
	}
	//retorna el dato ,por si es 0 o 1
	return retorno;
}

void respuestas(int suma, int resta , int multiplicacion){

	printf("\n el resultado de la suma es: %d ,  el resultado de la resta es : %d ,  el resultado de la multiplicacion es %d " , suma , resta  , multiplicacion );
}

