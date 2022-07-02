/*
 ============================================================================
 Name        : 05-04-2022.c

 CARGA ELEATORIA  (tengo que saber el indice )
 CARGA SECUENCIAL (solo cuendo tengo que cargar la totalidad del vector)
 ============================================================================
 */
/*
#include <stdio.h>
#include <stdlib.h>
#define CANT5

int main(void){
	setbuf(stdout,NULL);
    int v[5], pos ;
    char seguir;

    for(int i=0 ;i<5 ;i++){
       v[i]=0; // inicializamos vector todo en 0
    }

    //dato:  0 0 0 0 0
    //indice:0 1 2 3 4

    do{
    	//pide la posicion
       printf("Ingrese posicion"); //Se puede sacar porque el usuario no debe saber la posicion
       scanf("%d", &pos);         // y encima si pone 2 veces la misma posicion se pisa

       //guarda ese valor en el vector en la pos que ya pregunto
       printf("Ingrese valor a cargar en el vector");
       scanf("%d",&v[pos]);
       fflush(stdin);
       //pregunta si quiere ingresar mas datos(parte del bucle)
       printf("Desea ingresar otro datos/n?");
       scanf("%c",&seguir);
    }while(seguir =='s');

    return 0;
}
*/
//memoria
//variable   - direccion de memoria  - dato
//vector {0} -        0x100          - 2
//vector {1} -        0x104          - 3
//vector {2} -        0x108			 - 5
//vector {3} -        0x112			 - 7
//vector {4} -        0x116  		 - 11

//v == &v[0]
//for (i =0;i<5;i++){
//     v[i]....





#include <stdio.h>
#include <stdlib.h>
#define CANT 50

int main(){

	setbuf(stdout,NULL);
    int v[CANT], i,mayor,menor,contador=0, flag, num;
    char seguir;

    for (i=0; i<CANT; i++){
        v[i] = 0;// inicializamos vector
    }

    i=0;

    do{

        if(v[i]==0){
        	printf("Ingrese valor a cargar en el vector: ");
        	scanf("%d", &v[i]);
        	contador++;
        }

        i++;

 	 	if(i < CANT){
  	  		printf("Desea ingresar otro datos(S/N)? ");
  	  		fflush(stdin);
  	  		scanf("%c", &seguir);
		}else{
			printf(	"el vector esta completo");
			seguir = 'n';
		}
	}while(seguir == 's');

    //mostrar lo que esta cargado
    for(i=0;i<CANT;i++){

    	if(v[i] != 0){ //para que no muestre los que estan vacios(los que esten en 0)
    		printf("%d | ",v[i]);
    	}
    }

    if(contador > 0){//para saber que hay datos cargados(en este caso utilizamos un do -while ,pero para saber)

    	//mayor
    	mayor=v[0];//le asigna el 0 al primero
    	for(i=0;i<CANT;i++)//recorre
    	{
    	    if(v[i]>mayor && v[i] != 0)//si el vector de la pocicion que muestre i es mayor a la variable mayor (sabiendo que mayor esta cargado con ese mismo valor) y si se cumple hay un nuevo mayor
    	    {
    	    	mayor=v[i];
    	    }
    	}

    	//menor
    	menor=v[0];//le asigna el 0 al primero
    	for(i=0;i<CANT;i++)//recorre
    	{
    	   if(v[i]<menor && v[i] != 0) // el && v[i] != 0 valida que no cuente el 0 como menor (porque sino como al principio inicialice en 0 se queda ese como menor)
    	   {
    	      menor=v[i];
    	   }
    	}

    }else{
    	printf("no hay datos cargador...");
    }

    //BUSQUEDA DE UN NUMERO

    flag=0;//por si no encuentro el numero y lo informo--la declare arriba
    printf("\nIngrese numero a buscar: ");
    scanf("%d", &num);

    for (i=0;i< CANT; i++)//lee todo el vector
    {
          if(num==v[i])//si el num ingresado es igual al numero del vector que esta corriendo el bcle
           {
                  printf("*Se encontro el numero");
                  flag=-1;//le cambio el valor si fue encontrado
                  break;//si lo encuantro salgo de una
           }
    }

    if(flag==0){  //pregunto si fue encontrado o no

    	printf("*El numero no se encontro");
    }

//---------------------------------------------
      printf("\n*El menor es %d" ,menor);
      printf("\n*El mayor es %d" ,mayor);

 	return 0;
 }


/*
  //Menu ejemplo
do{
	switch(opcion)
		case 'A':
			if(contadorElementos < CANT){
				for (i =0; i < CANT; i++){
					if( v[i] == 0 ){
						printf("Dato: ");
						scanf ("%d", &v[1]);
						contadorElementos++
						break;
					}
				 }
				break;
			}else{



			}
		case 'B':
			break;
		case 'C':
			break;
		default:
}while();

 */



/*
int main(void) {


	int vec[5];
	//CARGA SECUENCIAL
	//datos: 2 3 5 7
	//indice 0 1 2 3



	//CARGA ELEATORIA
	//datos: _ _ _ _ _
	//indice 0 1 2 3 4

	return EXIT_SUCCESS;
}
*/
