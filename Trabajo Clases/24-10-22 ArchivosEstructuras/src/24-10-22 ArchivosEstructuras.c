/*
 ============================================================================
 Name        : 24-10-22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct{

	char nombre[50];
	int edad;
	int notaFinal;

}eAlumnos;


int main(void){

	setbuf(stdout,NULL);
	eAlumnos alumnos[50];
	FILE * archivo;//apunta a cualquier cosa //el dato no se usa en binario
	FILE * archivoBinario;//apunta a cualquier cosa
	//-------------
	char auxNombre[100];//el dato no se usa en binario
	char auxEdad[5];//el dato no se usa en binario
	char Auxnota[5];//el dato no se usa en binario
	//-------------
	int edad;//el dato no se usa en binario
	int notaFinal;//el dato no se usa en binario
	int retornoFscanf;//el dato no se usa en binario

	int i;

	//archivo=fopen("alumnos.csv","r");
	archivoBinario=fopen("alumnos.bin","rb");

	/*
	 *
	 * archivo=fopen("alumnos.csv","r");
	if(archivo != NULL){
		fscanf(archivo,"%s\n",auxNombre);//falsa lectura

		while(feof(archivo)==0){//feof llega al final del archivo , sino llega devuelve 1 sino 0
		//for(int i=0;i<10;i++){
			retornoFscanf=fscanf("%[^,],%[^,],%[^\n]\n",auxNombre,auxEdad,Auxnota);

			if(retornoFscanf==3){

				edad=atoi(edad);
				notaFinal=atoi(notaFinal);
				strycpy(alumnos[i].nombre,auxNombre);
				alumnos[i].edad=edad;
				alumnos[i].notaFinal=notaFinal;
				i++;
			}
		}


		fclose(archivo);//cerrar archivo

	}else{
		printf("Error");
	}
*/

	if(archivoBinario != NULL){

			fwhire(alumnos,sizeof(eAlumnos),10,archivoBinario);//escribirlo
			//leerlo
			fread(alumnos,sizeof(eAlumnos),10,archivoBinario);

			fclose(archivoBinario);//cerrar archivo

		}else{
			printf("Error");
		}


	for(int j=0;j<10;j++){
		printf("%s-%d-%d",alumnos[j].nombre, alumnos[j].edad,alumnos[j].notaFinal);
	}

	return EXIT_SUCCESS;
}

//https://onlinegdb.com/itgmGi-cR
