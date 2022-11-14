/*
Estructuras

Ingresar los datos de 1 empleado y mostralo
Ingresar los datos de 100 empleados:
Estructura:
 - Legajo (int)
 - Apellido y Nombre (char [])
 - sexo (char)
 - salario (float)
Mostrar:
Los datos del empleado.
Los datos de cada uno de los empleados del array eEmpleado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANTIDAD 3
#define LIBRE 0
#define OCUPADO 1

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int legajo;
	float salario;
	char sexo;
	char nombre[31];
	eFecha fechaNac;
	int estado;
}eEmpleado;

int main(void){

	setbuf(stdout,NULL);

	//estructuras
	eEmpleado empleado;
	eEmpleado empleado2;

	//array de estructuras
	eEmpleado empleados[CANTIDAD];
	eEmpleado empleados2[CANTIDAD];

	int i;


	// Inicializo el estado de cada empleado del array
	for( i=0; i<CANTIDAD; i++){
		empleados[i].estado = LIBRE;
	}

	// Ingreso los datos del empleado de la variable empleado
	printf("Legajo: ");
	scanf("%d", &empleado.legajo);

	printf("Nombre: ");
	fflush(stdin);
	scanf("%[^\n]", empleado.nombre);

	printf("Sexo: ");
	fflush(stdin);
	scanf("%c", &empleado.sexo);

	printf("Salario: ");
	scanf("%f", &empleado.salario);

	printf("Fecha de nacimiento: ");
	printf("\nD%ca: ", 161);
	scanf("%d", &empleado.fechaNac.dia);
	printf("\nMes: ");
	scanf("%d", &empleado.fechaNac.mes);
	printf("\nA%co: ", 164);
	scanf("%d", &empleado.fechaNac.anio);

	empleado.estado = OCUPADO;

	// Copio los datos de cada campo de la varibale empleado
	// a la variable empleado2
	empleado2 = empleado;




//DESDE ESTA PARTE ES LO MISMO QUE ARRIBA PERO CON  ARRAY DE ESTRUCTURAS

	// Ingreso los datos de cada uno de los empleados
	// del array de la estructira eEmpleado
	for( i=0; i<CANTIDAD; i++){
		if( empleados[i].estado == LIBRE ){
			empleados[i].legajo = (i+1);

			printf("Nombre: ");
			fflush(stdin);
			scanf("%[^\n]", empleados[i].nombre);

			printf("Sexo: ");
			fflush(stdin);
			scanf("%c", &empleados[i].sexo);

			printf("Salario: ");
			scanf("%f", &empleados[i].salario);

			printf("Fecha de nacimiento: ");
			printf("\nD%ca: ", 161);
			scanf("%d", &empleados[i].fechaNac.dia);
			printf("\nMes: ");
			scanf("%d", &empleados[i].fechaNac.mes);
			printf("\nA%co: ", 164);
			scanf("%d", &empleados[i].fechaNac.anio);

			empleados[i].estado = OCUPADO;
		}
	}

	// Copio los datos de cada empleado de la variable empeleados
	// a la variable empleados2
	for( i=0; i<CANTIDAD; i++){
		empleados2[i] = empleados[i];
	}

	printf("Imprimo los datos de un unico empleado de la variable empleado");
	printf("\n%d\t%s\t\t%c\t%.2f\n\n", empleado.legajo, empleado.nombre, empleado.sexo, empleado.salario);
	for( i=0; i<50; i++){
		printf("-");
	}

	printf("\n\nImprimo los datos de un unico empleado de la varibale empleado2");
	printf("\n%d\t%s\t\t%c\t%.2f\n\n", empleado2.legajo, empleado2.nombre, empleado2.sexo, empleado2.salario);
	for( i=0; i<50; i++){
		printf("-");
	}

	printf("\n\nImprimo los datos del array de empleados");
	printf("\nLegajo\tNombre\t\tSexo\tSalario\n\n");

	for( i=0; i<CANTIDAD; i++){
		if( empleados[i].estado == OCUPADO ){
			printf("%d\t%s\t\t%c\t%.2f\n", empleados[i].legajo, empleados[i].nombre, empleados[i].sexo, empleados[i].salario);
		}
	}

	printf("\n\nImprimo los datos del array de empleados2");
	printf("\nLegajo\tNombre\t\tSexo\tSalario\n\n");

	for( i=0; i<CANTIDAD; i++){
		if( empleados2[i].estado == OCUPADO ){
			printf("%d\t%s\t\t%c\t%.2f\n", empleados2[i].legajo, empleados2[i].nombre, empleados2[i].sexo, empleados2[i].salario);
		}
	}

	return 0;
}
