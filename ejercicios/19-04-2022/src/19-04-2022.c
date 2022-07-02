/*
 ============================================================================
 Name        : 19-04-2022.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3
//Legajo e=>101; 1=>102
//apellidoNombre e=> "Gomez Juan"; 1=> "Perez ALberio"
//sector 0=> "Sistemas"; 1=>"RRHH"
//fechaDeIngreso
//sexo
//fechaDeNacimiento
//DNI

//Vectorees paralelos -> Estructuras(vectores de estructuras)

typedef struct {
	int dia;
	int mes;
	int anio;
} eFecha;

typedef struct {
	char nombre[31];
	int nota;
	char asignatura[31];
	eFecha fechaNacimiento; //declaro una variable para igualarla y aparece aca
} eAlumno;

typedef struct{
	char nombre[20];
	int nota;
}ePersona;


int main(void) {
	setbuf(stdout, NULL);
	ePersona pers[MAX], aux;
	int i ;
	int j;
	//int auxNota;
	//int auxNombre[20];

	for(i=0; i<MAX; i++){
		 printf("Nombre: ");
		 fflush(stdin);
		 scanf("%s", pers[i].nombre);

		 printf("Nota: ");
		 scanf("%d", &pers[i].nota);
	 }

	for(i=0;i<MAX-1; i++){

		for(j=i+1;j<MAX; j++){
			if((strcmp(pers[i].nombre, pers[j].nombre)) > 0) {

				/*A a la Z (forma mal)
				auxNota=pers[i].nota;
				pers[i].nota=pers[j].nota;
				pers[j].nota=auxNota;
				//--------------------
				strcpy(auxNombre,pers[i].nombre);
				strcpy(pers[i].nombre , pers[j].nombre);
				strcpy(pers[j].nombre,auxNombre);
				*/
				//Z a la A (forma bien)
				aux=pers[i];
				pers[i]=pers[j];
				pers[j]=aux;

			}
		}
	}

	for(i=0;i<MAX;i++){
		printf("%s | %d | \n" , pers[i].nombre, pers[i].nota);
	}

return EXIT_SUCCESS;
}

	/*
	 int main(void) {
	 setbuf(stdout, NULL);
	 eAlumno alu[3];
	 int i;
	 for(i=0;i<3; i++){
	 printf("Ingrese nombre: ");
	 fflush(stdin);
	 scanf("%s",alu[i].nombre);

	 printf("Ingrese nota: ");
	 fflush(stdin);
	 scanf("%d",&alu[i].nota);
	 }
	 printf("nombre\t\tNota");
	 printf("-----------------------------");
	 for(i=0;i<3;i++){
	 printf("\n%s\t%d", alu[i].nombre , alu[i].nota);
	 }
	 return EXIT_SUCCESS;
	 }
	 */

	/*
	 int main(void){
	 setbuf(stdout, NULL);
	 eAlumno alu1,alu2;
	 printf("ingrese nombre");
	 fflush(stdin);
	 scanf("%s" , alu1.nombre);//no le pones porque esta guardando el dato  //va el & cuando la llamo

	 printf("asignatira:");
	 fflush(stdin);
	 scanf("%s" , alu1.asignatura);

	 printf("nota:");
	 fflush(stdin);
	 scanf("%d" , &alu1.nota);

	 printf("dia:");
	 fflush(stdin);
	 scanf("%d" , &alu1.fechaNacimiento.dia);

	 printf("mes:");
	 fflush(stdin);
	 scanf("%d" , &alu1.fechaNacimiento.mes);

	 printf("año:");
	 fflush(stdin);
	 scanf("%d" , &alu1.fechaNacimiento.anio);



	 alu2=alu1;//solo si completa todos los campos


	 //strcpy(alu2.nombre,alu1.nombre);//bien
	 //strcpy(alu2.asignatura,alu1.asignatura);//bien
	 //alu2.nombre=alu1.nombre;//mal
	 //alu2.nota=alu1.nota;//bien

	 printf("%s | %s | %d  |%d-%d-%d",alu2.nombre,alu2.asignatura,alu2.nota, alu2.fechaNacimiento.dia,alu2.fechaNacimiento.mes,alu2.fechaNacimiento.anio);


	 return EXIT_SUCCESS;
	 }
	 */

//eEmpleados empleado;
//eEmpleados empleados[50];
//empleados.nombre //como se llama al vector
//empleados[0].nombre//como lo lleno y le doy la posicion

//cadena de caracteres sin & , si la mascara es %s es sin
//con & si las mascaras son las normales d f c
