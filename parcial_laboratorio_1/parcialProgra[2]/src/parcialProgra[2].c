/*
 ============================================================================
 1. (4 puntos) Crear un array de caracteres (con vocales y consonantes) en memoria din�mica y
 una funci�n que reciba dicho array. La funci�n deber� ajustar el tama�o del array a la cantidad
 consonantes que haya en el mismo qued�ndose �nicamente con los elementos que cumplan con dicha caracter�stica.
 Ej: (perro)->(prr)

3.  (2 Puntos) Crear una funci�n que guarde en un archivo binario el contenido del
array generado en el punto 1. Leerlo en otra funci�n y mostrarlo.
 ============================================================================
 */


/*
 * 2. (4 Puntos) Elija 5 de los siguientes conceptos (mas el obligatorio) y
 * realice un p�rrafo en donde se pueda observar la relaci�n entre los conceptos
 * (No realizar definiciones del estilo copy-paste)
 *
 *
 * El puntero se puede relacionar con punteros a funci�n ya que puedo almacenar la
 * direcci�n de memoria y utilizar ese puntero o funci�n en cualquier parte del c�digo ,
 * sus formas de llamarlas son diferentes , ya que un puntero solo se puede acceder a el
 * mediante el operador  * y en punteros a funci�n debo agregarle el tipo de la funci�n
 * (*nombre ) y el tipo * estos puntero se guardan en el heap o mont�n en ese espacio es
 * donde tambi�n se encuentra la memoria din�mica se puede relacionar con el heap o mont�n
 * ya que ah� es donde se almacena toda variable din�mica para esta debemos utilizar la
 * funci�n malloc que lo que hace es crear un espacio en memoria  (reserva memoria de la RAM )
 * ,y se puede relacionar con el free ya que esta funci�n puede borrar dicho espacio en memoria .
 *
 */







#include <stdio.h>
#include <stdlib.h>


int main(void) {


	 FILE * pFile;
	 pFile = fopen("data.bin", "wb");

	 char * aux;
	 aux =(char*)malloc(sizeof(char)*5);

	 aux[0]='p';
	 aux[1]='e';
	 aux[2]='r';
	 aux[3]='r';
	 aux[4]='o';


	return EXIT_SUCCESS;
}


int leerfuncion(int * aux , int len ){
	int retorno=-1;
	for(int i =0;i<len;i++){
		if(aux[i] == "e" || aux[i] == "o"){
			delete(aux);
			retorno=0;
		}
	}
	return retorno;
}

void delete(char *this){
	free(this);
}

int funcion(FILE * pFile, int * array){
	int retorno=-1;
	int leer;
	char num[5];
	while(!feof(pFile)){
		leer=fprintf(pFile,"%[^,]",num);
	}
	fclose(pFile);
	return retorno;
}


int mostrar(char * aux , int len){

	int retorno=0;
	if(aux!=NULL){

		for(int i=0;i<len ;i++){

			printf("%c",aux[i]);
		}
	}
	return retorno;
}
