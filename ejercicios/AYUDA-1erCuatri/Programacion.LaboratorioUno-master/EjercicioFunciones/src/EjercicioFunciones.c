/*
 ============================================================================
 Name        : EjercicioFunciones.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 EJERCICIO
 Un programa que pida un numero al usuario , despues que pida una operacion(+ -/ *)
 y despues que pida otro numero. Segun la operacion ingresada ,se llamara a una funcion
 que ejecute la operacion (+ - /  *) y mostrar el resultado
 */

//EJEMPLO TP 1

#include <stdio.h>
#include <stdlib.h>
int resultadoMultiplicar( int numUno, int numDos);
void respuestas(int resultado);
int resultadoDivision( int numUno, int numDos,float *resultadoDivision);
int resultadoResta(int numUno, int numDos);
int resultadoSuma(int numUno, int numDos);

int main(void) {
	setbuf(stdout,NULL);

	int numeroUno;
	int numeroDos;
	char operacion;
	int resultadoOperacion;
	float resultadoDividir;


	char seguir;
	do {

		printf("Ingrese un numero \n");
		scanf("%d" , &numeroUno);

		printf("\n Ingrese una operacion(s , r , d , m )");
		fflush(stdin);
		scanf("%c" , &operacion);

		printf("\n ingrese otro numero");
		fflush(stdin);
		scanf("%d" , &numeroDos);

			switch(operacion){
				case 's':
					resultadoOperacion=resultadoSuma(numeroUno,numeroDos);
				break;
				case 'r':
					resultadoOperacion=resultadoResta(numeroUno,numeroDos);
				break;
				case 'd':
					resultadoOperacion=resultadoDivision(numeroUno,numeroDos,&resultadoDividir);
					if(resultadoOperacion==1){
							printf("pusiste un numero q no se puede dividir");
						}else{
							printf("el resultado es : %f" ,resultadoDividir);
						}
				break;
				case 'm' :
					resultadoOperacion=resultadoMultiplicar(numeroUno,numeroDos);
				break;
			}

		if(operacion!='d'){
			respuestas(resultadoOperacion);
		}




		//final del bucle
		printf("\n Desea continuar?");
		fflush(stdin);
		scanf("%c",&seguir);
	}while(seguir == 's');






	return EXIT_SUCCESS;
}

int resultadoSuma(int numUno, int numDos){
	int suma;
	suma=numUno+numDos;
	return suma;
}

int resultadoResta(int numUno, int numDos){
	int resta;
	resta=numUno-numDos;
	return resta;
}
int resultadoDivision( int numUno, int numDos,float *resultadoDivision){
	int flag=0;
	if(numDos==0){
		flag=1;
	}else{
		*resultadoDivision=(float)numUno/numDos;
	}
	return flag;
}

int resultadoMultiplicar( int numUno, int numDos){
	int multiplicacion;
	multiplicacion=numUno*numDos;
	return multiplicacion;
}

void respuestas(int resultado){

	printf("\n el resultado de la operacion es : %d " , resultado);
}
