/*
 ============================================================================
Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la
aplicación con distintos valores.
Ejemplo 1: 3 - 5 - 7 - 9 - 1
Ejemplo 2: 2 - 1 - 8 -1 - 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	int numeros;
	int suma=0;
	float promedio;
	int i;

	for(i=0;i<5;i++){
		printf("ingresar un numero");
		scanf("%d", &numeros);
		suma=suma+numeros;
	}
	promedio = suma/5;
	printf("El promedio de los numeros ingresados es %f", promedio);

	return EXIT_SUCCESS;
}
