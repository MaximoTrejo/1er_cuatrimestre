/*
 ============================================================================
 Name        : Maximo-MinimoUsuario.c
 Author      : MaximoTrejo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	int numeroUsuario;
	int maximo;
	int minimo;
	int flag = 0;
	char seguir='s';

	do {
			//pido el dato
			printf("\n ingrese un numero");
			scanf("%d", &numeroUsuario);
			fflush(stdin);//limpiar el buffer de entrada(se usa en cada SCANTF)

			//el dato entra por primera vez
			if(flag == 0){
				maximo=numeroUsuario;
				minimo=numeroUsuario;
				flag = 1;
			}else{
				//verifica si el nuevo numero que ingreso el usuario es menor o mayor
				if(numeroUsuario<minimo){
					minimo = numeroUsuario;
				}
				if(numeroUsuario>maximo){
					maximo=numeroUsuario;
				}
			}

			//final del bucle
			printf("\n Desea continuar?");
			scanf("%c",&seguir);
		}while(seguir == 's');

	printf("el numero minimo es : %d y el maximo es : %d " , minimo,maximo);
	return EXIT_SUCCESS;
}
