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
#include <string.h>

int main(void) {
	setbuf(stdout,NULL);
	FILE * archivo;//apunta a cualquier cosa
	FILE * archivoBinario;
	char texto[20]="hola mundo 1k";
	int numero = 12345;
	//int cantidadBytes;

	//archivo=fopen("archivo.txt","w");//crear archivo
	archivo=fopen("archivo.txt","r");

	//w solo escritura (para archivo de texto)(si no existe lo crea ) y los sobreescribe
	//r lectura para archivo de texto
	//rb(archivos binarios)
	//wb(archivos binarios)

	if(archivo !=NULL){

		//(informacion que va a escribir) , (tamanio del dato que estoy escribiendo) , (cantidad de elementos), (donde lo va a escribir ).
		//fwrite(texto,sizeof(char),strlen(texto),archivo);//para binarios
		//fprintf(archivo,"%s",texto);//escribimos arvhivos de texto

		//----------------
		//fseek(archivo,0L,SEEK_END);
		//cantidadBytes=ftell(archivo);                      //devuelve la cantidad de bytes
		//rewind(archivo);
		//fread(texto,sizeof(char),cantidadBytes,archivo);
		//-----------------

		//archivo , formato del dato , donde guarda el dato
		fscanf(archivo ,"%[^\n]", texto);
		//donde se guarda el archivo , cantidad de bytes, archivo de texto
		//fgets(texto,cantidadBytes,archivo);
		printf("%s",texto);
		fclose(archivo);
	}
	else{
		printf("no se pudo abrir el archivo");
	}


	//archivo binario

	archivoBinario=fopen("archivoBinario.bin","wb");

	if(archivo !=NULL){

			//(informacion que va a escribir) , (tamanio del dato que estoy escribiendo) , (cantidad de elementos), (donde lo va a escribir ).
			//alos int , float les paso en el primer campo la direxion de memoria
			fwrite(&numero,sizeof(char),1,archivoBinario);//para binarios

			fread(&numero,sizeof(char),1,archivoBinario);

			printf("\n%d",numero);
			fclose(archivoBinario);
		}
		else{
			printf("no se pudo abrir el archivo");
		}


	return EXIT_SUCCESS;
}


//https://www.onlinegdb.com/IruD2MwJH

