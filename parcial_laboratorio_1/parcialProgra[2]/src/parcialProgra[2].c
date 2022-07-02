/*
 ============================================================================
 1. (4 puntos) Crear un array de caracteres (con vocales y consonantes) en memoria dinámica y
 una función que reciba dicho array. La función deberá ajustar el tamaño del array a la cantidad
 consonantes que haya en el mismo quedándose únicamente con los elementos que cumplan con dicha característica.
 Ej: (perro)->(prr)

3.  (2 Puntos) Crear una función que guarde en un archivo binario el contenido del
array generado en el punto 1. Leerlo en otra función y mostrarlo.
 ============================================================================
 */


/*
 * 2. (4 Puntos) Elija 5 de los siguientes conceptos (mas el obligatorio) y
 * realice un párrafo en donde se pueda observar la relación entre los conceptos
 * (No realizar definiciones del estilo copy-paste)
 *
 *
 * El puntero se puede relacionar con punteros a función ya que puedo almacenar la
 * dirección de memoria y utilizar ese puntero o función en cualquier parte del código ,
 * sus formas de llamarlas son diferentes , ya que un puntero solo se puede acceder a el
 * mediante el operador  * y en punteros a función debo agregarle el tipo de la función
 * (*nombre ) y el tipo * estos puntero se guardan en el heap o montón en ese espacio es
 * donde también se encuentra la memoria dinámica se puede relacionar con el heap o montón
 * ya que ahí es donde se almacena toda variable dinámica para esta debemos utilizar la
 * función malloc que lo que hace es crear un espacio en memoria  (reserva memoria de la RAM )
 * ,y se puede relacionar con el free ya que esta función puede borrar dicho espacio en memoria .
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
