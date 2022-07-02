/*
 ============================================================================
 Name        : 16-05-22-memoriaDinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 //HACER EJERCICIO
 //17-2
 //17-3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define T 5

int main(void) {

	setbuf(stdout,NULL);

	//en el (monton o heap) es una memoria que pido para guardar los datos ,uno debajo de otro ,no puedo guerdar datos intercalado


	//int vector[5];//existe en la pila NO en el monton
	int *pVector;//Esta en La pila, pero apunta al monton
	pVector=(int*) malloc (sizeof(int)*T);//trabajarlo de manera dinamica (+5 elLementos).... (-2 elementos) // pongo con un define la T por si necesito mas lugar en el monton
	//en el pVector le estoy pasasndo el primer lugar del espacio de memoria que le pedi al malloc
	int *aux;

	if(pVector!=NULL){
		//cargo el dato
	    for(int i=0; i<T; i++){

	        printf("Ingrese un numero: ");
	        scanf("%d", pVector + i); //o pVector[i]; // utilizo el pVecto+ i
	    }
	    //imprimo
	    for(int i=0; i<T; i++)
	    {
	      printf("%d\n",*(pVector + i));
	    }

	    printf("Agrego 5 mas: \n");
	    //lo hace en el aux para no guardar lo nuevo en el espacio del anterior
	    aux=realloc(pVector,sizeof(int)*T+5);
	    if(aux != NULL){
	    	pVector=aux;
	    	for(int i=T;i<T+5;i++){
	    		 printf("Ingrese un numero: ");
	    		 scanf("%d", pVector + i);
	    	}
	    	for(int i=0; i<T; i++)
	    	{
	    		printf("%d\n",*(pVector + i));
	    	}
	    	printf("Ahora quiero quedarme con 3 \n");
	    	//lo hace en el aux para no guardar lo nuevo en el espacio del anterior
	    	aux=realloc(pVector,sizeof(int)*(T-2));//reasignar espacio en memoria , agrego o saco ,
	    	if(aux!=NULL){
	    		pVector=aux;
	    		free(aux);
	    		for(int i=0; i<T+5; i++)
	    		{
	    			printf("%d\n",*(pVector + i));
	    		}
	    	}

	    }

	}


	return EXIT_SUCCESS;
}
