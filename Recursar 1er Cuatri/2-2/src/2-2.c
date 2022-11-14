/*
 ============================================================================
Ingresar 10 números enteros, distintos de cero. Mostrar:
a. Cantidad de pares e impares.
b. El menor número ingresado.
c. De los pares el mayor número ingresado.
d. Suma de los positivos.
e. Producto de los negativos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int numeros;
	int menorNumero;
	int mayorNumPar=0;
	int sumaPos=0;
	int productoN=0;
	int contPar=0;
	int contImpar=0;

	for(int i=0;i<3;i++){

		printf("ingrese un numero");
		scanf("%d",&numeros);

		if(numeros < menorNumero){
			menorNumero=numeros;
		}

		if(numeros%2 ==0){
			contPar++;
			if(numeros > mayorNumPar){
				mayorNumPar=numeros;
			}
		}else{
			contImpar++;
		}

		if(numeros > 0){
			sumaPos=sumaPos+numeros;

		}else{
			productoN=productoN*numeros;
		}


	}


printf("Cantidad de pares e impares %d,%d \n", contPar,contImpar);
printf("De los pares el mayor número ingresado %d\n",mayorNumPar);
printf("El menor número ingresado %d.\n", menorNumero);
printf("Suma de los positivos.%d\n", sumaPos);
printf("Producto de los negativos.%d\n", productoN);
	return EXIT_SUCCESS;
}
