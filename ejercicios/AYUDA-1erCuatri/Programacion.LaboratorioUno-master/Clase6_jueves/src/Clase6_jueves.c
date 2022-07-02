/*
 ============================================================================
 Name        : Clase6_jueves.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myStrLenMayusculas(char cadena[]);
int myStrlenCaracteres(char cadena[]);

int main(void) {

	setbuf(stdout,NULL);
	//CADENA DE CARACTERES

	char cadenaDeCaracteres[20]= "buenas\0 ta";//son 10 lugares contando el espacio
	//\0 es para cortar un array de caracteres ,solo se va a mostrar hasta donde puse \0
	printf("%s \n" , cadenaDeCaracteres);
	//s para char

	//--------------------------------------------------------------------------------------
	puts("----------------------------");
	//--------------------------------------------------------------------------------------
	int len = strlen(cadenaDeCaracteres);
	//para ver cuanto ocupa
	printf("LEN %d" ,len);
	//es lo que mide el array (sirve para saber cuanta memorio desperdicio)(no es una funcion)
	printf("\nSIZEOF %d \n",sizeof(cadenaDeCaracteres));

	//---------------------------------------------------
	puts("----------------------------");
	//----------------------------------------------------

	char cad1[3];
	char cad2[10]="Hola";
	//muestro
	puts(cad1);
	puts(cad2);
	//copio lo que esta en cad2 y lo manda a cad1
	strcpy(cad1,cad2);
	//muestro
	puts(cad1);
	//el hola que estaba guardado en cad2 se transforma en "chau" (lo pisa)
	strcpy(cad2,"chau");
	//lo muestra
	puts(cad2);

	//---------------------------------------------------
	puts("----------------------------");
	//----------------------------------------------------

	//el final es cauntos caracteres queres copiar de cad2 en cad1 (seria igual al strcpy +
	//un limite de lo que quiere copiar)
	//en este caso va a copiar la camtidad de caracteres que vale cad1(3) en cad1 copiando el contenido de cad2
	//(va a copiar 3(0,1,2) caracteres de cad2)
	strncpy(cad1,cad2,sizeof(cad1));
	//el -1 es para el \0 porque sino no seria una cadena valida
	cad1[sizeof(cad1)-1]='\0';
	puts(cad1);
	puts(cad2);

	//---------------------------------------------------
	puts("----------------------------");
	//----------------------------------------------------
	//EJERCICIO
	char arrayEjercicio[50]="Hola Mundos\0 Me Volver Chango";

	int mayusculas;
	int caracteres;

	mayusculas= myStrLenMayusculas(arrayEjercicio);
	printf("CONTADOS MAYUSCULAS %d" ,  mayusculas);

	caracteres= myStrlenCaracteres(arrayEjercicio);
	printf("\nCARACTERES %d" ,  caracteres);
	return EXIT_SUCCESS;
}


// ej1(recibe una cadena y devuelve la cantidad de caracteres)
//Cuenta mayusculas
int myStrLenMayusculas(char cadena[])
{
    int contMayus=-1;
    int index=0;
    if(cadena!=NULL){
    	contMayus=0;
    	while (cadena[index]!='\0')
		{
    		if(cadena[index]>='A' && cadena[index]<='Z'){
    			contMayus++;
    		}
			index++;
		}
    }
return contMayus;
}

//(lo que se quiere hacer es mostrar la cantidad de caracteres antes del \0)
int myStrlenCaracteres(char cadena[])
{
	int index=0;
	if(cadena !=NULL){
		while(cadena[index]!='\0')
		{
			index++;
		}
	}
	return index; // index coincide con la cant de letras
}
