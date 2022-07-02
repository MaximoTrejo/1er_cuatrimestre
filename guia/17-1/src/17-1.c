/*
 ============================================================================
 Name        : 17-1.c
 Author      : MaximoTrejo


Realizar una función que retorne un puntero a eProducto.
Dentro de esta función deberá crear un producto hardcodeado, un puntero y se apuntará ese puntero al producto.
Mostrar el producto cargado 5 veces desde el main. Observar el comportamiento del programa.

 ============================================================================
 */

#include <stdio.h>
#include <string.h>
//para el malloc
#include <stdlib.h>

typedef struct
{
	int id;
	char descripcion[20];
	float precio;

}eProducto;

eProducto* retornarPuntero();//constructor por defecto //inicializar al producto con valores por defecto
eProducto* cargarProductoParametros(int id, char*descipcion,float precio);//constructor parametrizado

int main(void) {

eProducto *puntero;
eProducto*otro;

//--------------------------------------------------------------------------------
puntero = retornarPuntero();
if(puntero!=NULL){
	puntero->id=200;
	puntero->precio=199;
	strcpy(puntero->descripcion,"cocacola");
	printf("1.%d -- %s -- %f\n",puntero->id,puntero->descripcion , puntero->precio);
}

//----------------------------------------------------------------------------------
otro=cargarProductoParametros(22, "pepsi", 250);
if(otro!=NULL){
	printf("2.%d -- %s -- %f\n",otro->id,otro->descripcion , otro->precio);

}

//---------------------------------------
//muestra lo de la pila
//printf("%d\n",&otro);

	return EXIT_SUCCESS;
}


eProducto* retornarPuntero(){//constructor por defecto //inicializar al producto con valores por defecto

	eProducto*puntero;

	//Hace que el malloc de una direccion de memoria del tipo eProducto (puntero)
	puntero=(eProducto*)malloc(sizeof(eProducto));//esta en la biblioteca stdlib//devuelve un puntero a *void (vacio)//devuelve una direccion de memora generica

	//printf("enla funcion %d\n",&producto);


	//harcodeo los datos
	if(puntero!=NULL){
		puntero->id=105;
		strcpy(puntero->descripcion,"coca cola");
		puntero->precio=104.88;
	}
	return puntero;
}

eProducto* cargarProductoParametros(int id, char*descipcion,float precio){//constructor parametrizado
	eProducto*puntero;
		//Hace que el malloc de una direccion de memoria del tipo eProducto (puntero)
		puntero=(eProducto*)malloc(sizeof(eProducto));//esta en la biblioteca stdlib//devuelve un puntero a *void (vacio)//devuelve una direccion de memora generica

		//printf("enla funcion %d\n",&producto);

		//harcodeo los datos
		if(puntero!=NULL){
			puntero->id=id;
			strcpy(puntero->descripcion,descipcion);
			puntero->precio=precio;
		}
		return puntero;
}

/*
 * HECHO EN CLASE
 * https://onlinegdb.com/RhCKtd3Y9
 */

//sin el malloc

/*
 *  1.5 -- Hola¼þa -- 190.000000
	2.4116480 --  -- -96212784152024670000000000000000000000.000000 //basura
	3.4116480 -- A -- -96212784152024670000000000000000000000.000000//basura
	4.4116480 -- A -- -96212784152024670000000000000000000000.000000//basura
	5.4116480 -- A -- -96212784152024670000000000000000000000.000000//basura
 */
