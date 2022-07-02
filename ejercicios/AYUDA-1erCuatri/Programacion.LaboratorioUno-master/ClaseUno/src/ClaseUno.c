/*
 ============================================================================
 Name        : ClaseUno.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//Solo para Windows
	setbuf(stdout,NULL);

	/*
	//NUMEROS ENTEROS %d
	int a;
	//NUMEROS DECIMALES (con coma)
	float f;
	//1 CARACTER .1 LETRA. 1 SIMBOLO
	char c;
	------------------------------------
	#LIMPIAR_BUFFER_ENTRADA fflush(stdin);
	(se usa en cada SCANTF)

	 */

	//PROGRAMA SUMAR - Restar (EJ A)
	//variables
	int numeroUno;
	int numeroDos;
	int suma;
	int resta;
	//ingrese el dato
	printf("\n Ingrese el numero: \n");
	//inicializar el dato(guardo el dato)
	scanf("%d",&numeroUno);
	//..
	printf("\n ingrese otro numero");
	scanf("%d" , &numeroDos);
	//cuenta
	suma= numeroUno+numeroDos;
	resta=numeroUno-numeroDos;
	//Mostrar cuenta
	printf("\n La suma del numero es %d" , suma);
	printf("\n La resta es : %d" , resta);

	//-------------------------------------------------------------------------------

	//VERIFICAR SI SOS MAYOR (EJ A)
	if(numeroUno>17){
		printf("\n sos mayor de edad");
	}

	//-------------------------------------------------------------------------------

	//PROGRMA HASTA Q EL USUARIO DESEA
	//variable
	int numeroUsuario;
	//bucle seguir
	char seguir;
	//bucle
	do {
		//pido el dato
		printf("\n ingrese un numero");
		scanf("%d", &numeroUsuario);
		fflush(stdin);//limpiar el buffer de entrada(se usa en cada SCANTF)


		//final del bucle
		printf("\n Desea continuar?");
		scanf("%c",&seguir);
	}while(seguir == 's');


	//Se finaliza el programa (poner siempre)
	return EXIT_SUCCESS;
}

/*
 //BUCLES
	while
	for
	do while

//GENERALMENTE
	Si se cuantas veces voy a iterar -> for
	Si no lo se -> while
	Primero quiero iterar y despues preguntar por la condicion -> do while
 */
