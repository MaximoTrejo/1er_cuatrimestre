/*
 * libraryArtistMusic.c
 *
 *  Created on: 30 abr. 2022
 *      Author: maxim
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "libraryArtistMusic.h"
#include "utn.h"
//-------------------------------------------DECLARACION DE STATIC---------------------------------------------------
static void printAlbum(album artistas);
static void printGenero(album genero);
static void printTipoArtista(album tipoA);
static void printArtista(album tipoA);
static int dameUnIdNuevo(void);
static int seleccionarModificar(int *seleccionarMod);

//----------------------------------------------------------PARTE DOS-----------------------------------------------------------------
static void printTipoAlbum(album tipoTA);
//static int dameUnIdNuevoTA(void);
//------------------------------------------------------------INICIALIZAR-----------------------------------------------------------------------------------
int  initArtist(album list[],int len){

	int i;
	int retorno= -1;
	if(list != NULL && len > 0){

		for(i=0;i<len;i++){
			list[i].isEmpty= LIBRE;
		}
		retorno=0;
	}
	return retorno;
}

//-----------------------------------------------------------ALTA--------------------------------------------------
int addArtist(album listAlbum[] /*, typeAlbum listTA[] */){
	int retorno=-1;
	char auxTitulo[TAM];
	int auxDia;
	int auxMes;
	int auxAnio;
	float auxImporte;
	char auxDescripcion[TAM];
	int tipoAlbum;




	if(listAlbum != NULL){

		if(utn_getCaracter(auxTitulo,TAM, "Ingresar el titulo", "Error\n", REINTENTOS)==0){
			if(utn_getInt(&auxDia, "Ingrese dia","Error\n", 1, 31, REINTENTOS)==0){
				if(utn_getInt(&auxMes,"Ingresar mes","Error\n", 1, 12, REINTENTOS)==0){
					if(utn_getInt(&auxAnio, "Ingresar a�o", "Error\n", 1, 9999, REINTENTOS)==0){
						if(utn_getNumeroFloat(&auxImporte, "Importe", "Error\n", 1, 9999, REINTENTOS)==0){
							printf("TIPO DE ALBUM\n");
							if(utn_getInt(&tipoAlbum,"[1]vunilo\n[2]cinta\n[3]CD\n", "Error\n", 1, 3, REINTENTOS)==0){
								if(utn_getCaracter(auxDescripcion, TAM, "Ingrese la descripcion", "Error\n", REINTENTOS)==0){

								strncpy(listAlbum->titulo,auxTitulo,sizeof(listAlbum->titulo));
								listAlbum->fechaPubli.dia=auxDia;
								listAlbum->fechaPubli.mes=auxMes;
								listAlbum->fechaPubli.anio=auxAnio;

								listAlbum->importe=auxImporte;
								listAlbum->codAlbum=dameUnIdNuevo();
								listAlbum->isEmpty=OCUPADO;

								listAlbum->tipoAlbum.codtypeAlmbum=tipoAlbum;
								strncpy(listAlbum->tipoAlbum.descripcion,auxDescripcion,sizeof(listAlbum->tipoAlbum.descripcion));




								//----------------------------------------------
								/*
								listAlbum->genero.codGenero=1;
								strncpy(listAlbum->genero.descripcion,"descripcion1",sizeof(listAlbum->genero.descripcion));
								listAlbum->tipoArtista.codTypeArt=1;
								strncpy(listAlbum->tipoArtista.typeDes,"descripcion1",sizeof(listAlbum->tipoArtista.typeDes));
								listAlbum->artista.codArtista=1;
								strncpy(listAlbum->artista.nombre,"The Beatles",sizeof(listAlbum->artista.nombre));




								strncpy(listTA->descripcion,auxDescripcion,sizeof(listTA->descripcion));
								listTA->codtypeAlmbum=dameUnIdNuevoTA();
								listTA->isEmpty=OCUPADO;
								*/
								retorno=0;
								}
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

/*
static int dameUnIdNuevoTA(void) //privada del archivo
{
	static int contador=3;
	contador++;//es global : mantiene su valor
	return contador;
}

*/

static int dameUnIdNuevo(void) //privada del archivo
{
	static int contador=4;
	contador++;//es global : mantiene su valor
	return contador;
}

int bucarLibre(album artic[], int len)
{
	int retorno=-1;
	int i;

	if(artic !=NULL && len>0)
	{
		for(i=0; i<len ;i++)
		{
			if(artic[i].isEmpty==LIBRE)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

//------------------------------------------------------------------------IMPRIMIR-----------------------------------------------------------------------------------
static void printAlbum(album alb){//paso la dreccion de memoria , apunta a la direccion de memoria del indice donde se encuentra el dato

	/*
	 * typedef struct
{
	int codtypeAlmbum;//autompletar
	char descripcion[TAM];

}typeAlbum;//genero
//-----------------------PARTE DOS----------------------------

typedef struct
{
	gender genero;
	typeArtist tipoArtista;
	artist artista;
	int codAlbum;//autompletar
	char titulo[TAM];//validar
	fechAlbum fechaPubli;//validar
	float importe;//validar
	typeAlbum tipoAlbum;//parte dos
	int isEmpty ;
	int codigoArtista;

}album;
	 */
	printf("%d\t%s\t%d\t%d\t%d\t%f\t%d\t\t%s\n",alb.codAlbum, alb.titulo,alb.fechaPubli.dia,alb.fechaPubli.mes,alb.fechaPubli.anio,alb.importe,alb.tipoAlbum.codtypeAlmbum,alb.tipoAlbum.descripcion);
}

void imprimirAlbum(album list[], int len) {
int i;
	if(list != NULL && len > 0 ) {
		printf("ID\tTITULO\tDIA\tMES\tA�O\tIMPORTE\t\ttypeAlbum\tdescripcion\n");
		for(i=0; i<len; i++){
			if(list[i].isEmpty==OCUPADO){
				printAlbum(list[i]);
			}
		}
	}
}


void imprimirGenero(album list[], int len){
int i;
	if(list != NULL && len > 0 ){
			for(i=0; i<len; i++){
				if(list[i].isEmpty==OCUPADO){
					printGenero(list[i]);
				}
			}
	}
}

static void printGenero(album genero){//paso la dreccion de memoria , apunta a la direccion de memoria del indice donde se encuentra el dato
	printf("%d\t%s\n",genero.genero.codGenero,genero.genero.descripcion);
}


void imprimirTipoArtista(album list[], int len){
int i;
	if(list != NULL && len > 0 ){
			for(i=0; i<len; i++){
				if(list[i].isEmpty==OCUPADO){
					printTipoArtista(list[i]);
				}
			}
	}
}

static void printTipoArtista(album tipoA){//paso la dreccion de memoria , apunta a la direccion de memoria del indice donde se encuentra el dato
	printf("%d\t%s\n",tipoA.tipoArtista.codTypeArt,tipoA.tipoArtista.typeDes);
}


void imprimirArtistas(album list[], int len){
int i;
	if(list != NULL && len > 0 ){
			for(i=0; i<len; i++){
				if(list[i].isEmpty==OCUPADO){
					printArtista(list[i]);
				}
			}
	}
}

static void printArtista(album tipoA){//paso la dreccion de memoria , apunta a la direccion de memoria del indice donde se encuentra el dato
	printf("%d\t%s\n",tipoA.artista.codArtista,tipoA.artista.nombre);
}


//-----------------------------------PARTE DOS------------------------------------

void imprimirTipoAlbum(album list[],int len){
int i;
	if(list != NULL && len > 0 ){
		printf("ID\tDESCRIPCION\n");
			for(i=0; i<len; i++){
				if(list[i].isEmpty==OCUPADO){
					printTipoAlbum(list[i]);
				}
			}
	}
}

static void printTipoAlbum(album tipoTA){//paso la dreccion de memoria , apunta a la direccion de memoria del indice donde se encuentra el dato
	printf("%d\t%s\n",tipoTA.tipoAlbum.codtypeAlmbum,tipoTA.tipoAlbum.descripcion);
}

//----------------------------------------------------------------------MODIFICACION--------------------------------------------------------------

int buscarId(album list[], int len,int id){
int retorno=-1;
int i;
if(list !=NULL && len > 0 && id >= 0)
{
	for(i=0; i<len ; i++)
	{
		if(list[i].codAlbum == id && list[i].isEmpty == OCUPADO)
		{
			retorno = i;
			break;
		}
	}
}
return retorno;//retorna el id (si hay un error retorna -1)
}

static int seleccionarModificar(int *seleccionarMod){
	int retorno=-1;
	int auxSelecion;

	selecModificar();
	if(utn_getInt(&auxSelecion, "\nElegi la opcion:","error", 1, 5, REINTENTOS)==0){
		retorno=0;
		*seleccionarMod=auxSelecion;
	}
	return retorno;
}

int modificarArtists(album list[]/*,typeAlbum listTA[] */,int len , int idMod){
	int retorno=-1;
	int campoMod;
	char auxList[len];
	int auxDia;
	int auxMes;
	int auxAnio;
	float auxFloat;
	//--------segunda parte----
	char auxDescripcion[len];
	int auxTypealbum;

	if(seleccionarModificar(&campoMod)==0){
		switch(campoMod){
		case 1:
			if(utn_getCaracter(auxList, len,"Ingresar el titulo", "Error\n", REINTENTOS)==0){
				strcpy(list[idMod].titulo,auxList);
				puts("Se modifico correctamente\n");
				retorno=0;
			}
			break;
		case 2:
			if(utn_getInt(&auxDia, "Ingrese dia","Error\n", 1, 31, REINTENTOS)==0){
				if(utn_getInt(&auxMes,"Ingresar mes","Error\n", 1, 12, REINTENTOS)==0){
					if(utn_getInt(&auxAnio, "Ingresar a�o", "Error\n", 1, 9999, REINTENTOS)==0){
						list[idMod].fechaPubli.dia=auxDia;
						list[idMod].fechaPubli.mes=auxMes;
						list[idMod].fechaPubli.anio=auxAnio;
						puts("Se modifico correctamente\n");
						retorno=0;
					}
				}
			}
			break;
		case 3:
			if(utn_getNumeroFloat(&auxFloat,"Ingrese importe", "Error\n", 1, 9999, REINTENTOS)==0){
				list[idMod].importe=auxFloat;
				puts("Se modifico correctamente\n");
				retorno=0;
			}
			break;

		case 4 :
			if(utn_getInt(&auxTypealbum, "[1]vunilo\n[2]cinta\n[3]CD\n", "Error\n", 1, 3, REINTENTOS)==0){
				list[idMod].tipoAlbum.codtypeAlmbum=auxTypealbum;
				puts("Se modifico correctamente\n");
				retorno=0;
			}

			break;

		case 5:
			if(utn_getCaracter(auxDescripcion, len,"Ingresar descripcion ", "Error\n", REINTENTOS)==0){
				strcpy(list[idMod].tipoAlbum.descripcion,auxDescripcion);
				puts("Se modifico correctamente\n");
				retorno=0;
			}
			break;

		default:
			printf("Esa opcion no se encuentra(no se modifico el ID)\n");
			break;
		}
	}


return retorno;
}

//------------------------------------------------------------REMOVE--------------------------------------------------

int removeArtist(album list[], int len , int id){
	int retorno=-1;
	int i;
	int confirmar;

		for(i=0; i<len; i++){
			if(list[i].codAlbum == id  && list[i].isEmpty==OCUPADO){

				if(utn_getInt(&confirmar, "Dar de baja?[1(S)|2(N)]", "Error\n", 1, 2, REINTENTOS)==0){
					if(confirmar==1){
						list[i].isEmpty=LIBRE;
						printf("Los datos han sido borrado...\n");
						retorno=0;
					}else{
						printf("Los datos no han sido borrado...\n");
					}
					break;
				}
			}
		}
	return retorno;
}

//-------------------------------------------------------------MENU---------------------------------------------------------------------

void menu(album list[], int len){

	int opcion;//opcion de menu opciones
	int lugarLibre;//lugar libre del primer
	int flagPrimerPos=1;//pasa saber el primer lugar
	int opcionInforme;//opciones de punto 4(informar)
	int total;//el total de todos los importes
	float promedioInforme;//puntero para hacer el promedio
	int superAlb;//albunes que superan el promedio
	int cantFechaM;//cantidad de albunes que son menores a la fecha del 1/1/2000. //BUUUUUUUUUUUG me cuanta 10 nose donde va el break
	int opcionListar;//opcion de listar(punto 5)
	//int opcionLCinco;//opcion listar para el punto 5 del listar
	int buscarF;
	int fechaBuscada;
	int buscarArtistaM;
	//int artistaBuscarM;

	int cantSoli;

	do{
		menuOpciones();
		if(utn_getInt(&opcion, "\nIngresar opcion", "Error\n", 1, 6,REINTENTOS)==0){};

		switch(opcion){
			case 1:
				lugarLibre=bucarLibre(list,len);
				if(lugarLibre != -1){
					//addArtist(&list[lugarLibre] , &tipoAlbum[lugarLibre]);
					addArtist(&list[lugarLibre]);
					flagPrimerPos=1;
				}else{
					printf("\nNo hay espacio");
				}
				break;
			case 2:

				if(flagPrimerPos == 1){

					imprimirAlbum(list, len);
					//imprimirTipoAlbum(tipoAlbum, len);

					//-------------------------------
					int idIngresado;
					int idModificar;

					if(utn_getInt(&idIngresado, "\nIngrese el ID ", "Error\n", 0, 999, REINTENTOS)==0){
						idModificar=buscarId(list,len,idIngresado);

						if(idModificar >= 0){
							modificarArtists(list,len,idModificar);
							printf("ID\tTITULO\tDIA\tMES\tA�O\tIMPORTE\t\ttypeAlbum\tdescripcion\n");
							printAlbum(list[idModificar]);
							//printf("ID\tDESCRIPCION");
							//printTipoAlbum(tipoAlbum[idModificar]);

						}else{
							printf("El id no existe\n");
						}

					}
				}else{
					printf("No hay empleados cargados.....\n");
				}

				break;

			case 3:
				if(flagPrimerPos==1){
					imprimirAlbum(list, len);
					//------------------------------------
					int auxCodigo;

					if(utn_getInt(&auxCodigo,"\nIngrese el ID", "Error\n", 1, 2000, REINTENTOS)==0){

						removeArtist(list, len, auxCodigo);
					}

				}else{
					printf("No hay empleados cargados.....\n");
				}

				break;

			case 4:
				if(flagPrimerPos==1){
					opcionesInformes();
					if(utn_getInt(&opcionInforme,"Opcion", "Error\n", 1, 4, REINTENTOS)==0){
						switch(opcionInforme){
						case 1:
							total=totalInforme(list,len,&promedioInforme);
							superAlb=superAlbunes(list, len, promedioInforme);
							printf("*El total de precios es  %d \n",total);
							printf("*El promedio de precios es %f",promedioInforme);
							printf("\n*La cantidad de pasajeros que superan al promedio es %d\n",superAlb);
							break;
						case 2:
							cantFechaM=cantAlbunesFecha(list,len);
							printf("*Cantidad de �lbumes menor al 1/1/2000 es %d\n ",cantFechaM);
							break;
						case 3:
							if(utn_getInt(&buscarF, "\nIngrese anio ", "Error", 0, 9999, REINTENTOS)==0){

								cantSoli=cantSolista(list,len,buscarF);
								printf("\nla cantidad es %d\n", cantSoli);

							}
							break;
						case 4:
							//SALIR
							break;
						}
					}
				}else{
					printf("no hay empleados cargados");
				}
				break;
			case 5:
				if(flagPrimerPos==1){
					listar();
					if(utn_getInt(&opcionListar,"\nOpcion", "Error\n", 1, 15, REINTENTOS)==0){
						switch(opcionListar){
						case 1:
							imprimirGenero(list, len);
							break;
						case 2:
							imprimirTipoArtista(list,len);
							break;
						case 3:
							imprimirArtistas(list,len);
							break;
						case 4:
							imprimirAlbum(list, len);
							break;
						case 5:
							if(sortAlbunesImporte(list,len)==0){
								imprimirAlbum(list, len);
							}
							break;
						case 6:
							printAlbunesFecha(list,len);
							break;
						case 7:
							total=totalInforme(list,len,&promedioInforme);
							printSuperAlbunes(list,len,promedioInforme);
							break;
						case 8:
							todosAA(list,len );
							break;
						case 9:

							if(utn_getInt(&buscarF, "\nIngrese fecha ", "Error", 0, 9999, REINTENTOS)==0){
								fechaBuscada=buscarFecha(list,len,buscarF);

								if(fechaBuscada >= 0){
									printf("ID\tTITULO\tDIA\tMES\tA�O\tIMPORTE\t\ttypeAlbum\tdescripcion\n");
									printAlbum(list[fechaBuscada]);

								}else{
									printf("La fecha no existe\n");
								}
							}
							break;
						case 10:
							albunesCaros(list, len);
							break;

						case 11:
							imprimirTipoAlbum(list, len);
							break;

						case 12:
							albunesNVinilo(list,len);
							//albunesNVinilo(list,tipoAlbum,len);
							break;
						case 13:


							/*
							 *
							if(utn_getInt(&buscarF, "\nIngrese fecha ", "Error", 0, 9999, REINTENTOS)==0){
								fechaBuscada=buscarFecha(list,len,buscarF);

								if(fechaBuscada >= 0){
									printf("genero\tdescripcion\tid\ttipoArtista\tid\tNOMBRE ARTISTA\t\tID\tTITULO\tDIA\tMES\tA�O\tIMPORTE\t\ttypeAlbum\tdescripcion\n");
									printAlbum(list[fechaBuscada]);

								}else{
									printf("La fecha no existe\n");
								}
							}
							 */

							opcionArtista();
							if(utn_getInt(&buscarArtistaM, "\nopcion", "error\n", 1, 3, REINTENTOS)==0){
								//artistaBuscarM=buscarArtista(list, len, buscarArtistaM);
								if(buscarArtistaM > 0 ){
									for(int i=0;i<len;i++){
										if(list[i].tipoAlbum.codtypeAlmbum == 1 && (list[i].codigoArtista == buscarArtistaM)){
											printAlbum(list[i]);
										}
									}
								}else{
									printf("el artista no tiene vinilos\n");
								}



							}else{
								printf("ese artista no existe no existe\n");
							}
							break;


						}
					}
				}else{
					printf("no hay empleados cargados");
				}
		}

	}while(opcion!=6);
}

//-----------------------------------------------LISTAR-----------------------------------------------------------------------------------
//El �lbum o los �lbumes m�s caros.
void albunesCaros(album list[] , int len){
	int mayorImpote=0;
	for(int i=0;i<len;i++){
		if(list[i].importe > mayorImpote && list[i].isEmpty==OCUPADO){
			mayorImpote=list[i].importe;
		}
	}
	printf("El importe mas grande es:\n");
	for(int i=0;i<len ;i++){
		//si el list importe es el de la variable mayorImporte muestro toda la lista
		if(list[i].importe == mayorImpote){
			printAlbum(list[i]);
		}
	}
}
//Todos los �lbumes de un a�o determinado.
int buscarFecha(album list[], int len,int fecha){
int retorno=-1;
int i;
if(list !=NULL && len > 0 && fecha >= 0)
{
	for(i=0; i<len ; i++)
	{
		if(list[i].fechaPubli.anio == fecha  && list[i].isEmpty == OCUPADO)
		{
			retorno = i;
			break;
		}
	}
}
return retorno;//retorna el id (si hay un error retorna -1)
}



//Todos los �lbumes de cada artista.
void todosAA(album list[], int len ){

	for(int i=0;i<3;i++){//atistas
		printf("%d , %s\n",list[i].artista.codArtista,list[i].artista.nombre);
		for(int j=0;j<len;j++){//albunes
			if(list[j].isEmpty==OCUPADO && list[i].artista.codArtista == list[j].codigoArtista ){
				printf("   \t --> %d\t%s\t,%d\t,%d\t,%d\t,%f\n",list[j].codAlbum, list[j].titulo,list[j].fechaPubli.dia,list[j].fechaPubli.mes,list[j].fechaPubli.anio,list[j].importe);

			}
		}
	}
}



//Todos los �lbumes que superan el promedio de los importes.
void printSuperAlbunes(album list[],int len, float promedio){
	if(list != NULL && len > 0){
		printf("ID\tTITULO\tDIA\tMES\tA�O\tIMPORTE\t\ttypeAlbum\tdescripcion\n");
		for(int i=0;i<len;i++){
			if(list[i].isEmpty==OCUPADO){
				if(list[i].importe > promedio){
					printAlbum(list[i]);
				}
			}
		}
	}
}
//Todos los �lbumes cuya fecha de publicaci�n es anterior a 1/1/2000.
void printAlbunesFecha(album fecha[],int len){
	if(fecha!=NULL && len > 0){
		printf("ID\tTITULO\tDIA\tMES\tA�O\tIMPORTE\t\ttypeAlbum\tdescripcion\n");
		for(int i=0;i<len;i++){
			if(fecha[i].fechaPubli.anio < 2000 && fecha[i].isEmpty==OCUPADO){
				printAlbum(fecha[i]);
			}
		}
	}
}

//----------------------------------INFORME DE ORDENAMIENTO----------------------
int sortAlbunesImporte(album list[], int len)//desendente
{
	int retorno=-1;
	album aux;
	int i;
	int j;

		for(i=0;i<len-1; i++){

			for(j=i+1;j<len; j++){
				if(list[i].importe < list[j].importe || strncmp(list[i].titulo,list[j].titulo,TAM) > 0){
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
						retorno=0;
					}
				}
			}

	return retorno;
}
/*
int sortAlbunesTitulo(album list[], int len)//ascendente
{
	int retorno=-1;
	album aux;
	int i;
	int j;
		for(i=0;i<len-1; i++){

			for(j=i+1;j<len; j++){
				if(strncmp(list[i].titulo,list[j].titulo,TAM) > 0 ){
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
					retorno=0;
				}
			}
		}
	return retorno;
}
*/
//--------------------------------------INFORMES-------------------------------
int superAlbunes(album list[],int len, float promedio){
	int retorno=0;
	int contSuperPas=0;
	if(list != NULL && len > 0){
		for(int i=0;i<len;i++){
			if(list[i].isEmpty==OCUPADO){
				if(list[i].importe > promedio){
					contSuperPas++;
					retorno=contSuperPas;
				}
			}
		}
	}

	return retorno;
}

int totalInforme( album list[],int len,float*promedio){
	int retorno=0;
	int contTotal=0;
	int contImporte=0;
	if(list != NULL && len > 0){
		for(int i=0;i<len;i++){
			if(list[i].isEmpty==OCUPADO){
				contTotal=contTotal+list[i].importe;
				contImporte++;
				retorno=contTotal;
			}
		}

		*promedio=promedioInforme(contImporte,contTotal);
	}

	return retorno;
}

float promedioInforme(int contImporte , int totaInformes ){
	float retorno=0;
	if(contImporte > 0 && totaInformes > 0){
		retorno=(float)totaInformes/contImporte;
	}

	return retorno;
}

int cantAlbunesFecha(album fecha[],int len){
	int contFecha=0;
	if(fecha!=NULL && len > 0){
		for(int i=0;i<len;i++){
			if(fecha[i].fechaPubli.anio < 2000 && fecha[i].isEmpty==OCUPADO){
				contFecha++;
			}
		}
	}
	return contFecha;
}

//--------------------------------ENUNCIADOS-------------------------------
void opcionesInformes(){
    printf("\nMenu de informes"
            "\n1. Total y promedio de los importes, y cu�ntos �lbumes superan ese promedio."
            "\n2. Cantidad de �lbumes cuya fecha de publicaci�n es anterior a 1/1/2000"
            "\n3. (recuperatorio) informar la cantidad de solistas de un a�o determinado."
    		"\n4.Salir\n");
}

void listar(){
	 printf("\nMenu de listar"
	            "\n1.Todos los generos"
	            "\n2.Todos los tipos de artistas musicales"
	            "\n3.Todos los artistas"
	            "\n4.Todos los albumes"
			 	"\n5.Ordenar albumes por Importe o Titulo"
			 	"\n6.Todos los �lbumes cuya fecha de publicaci�n es anterior a 1/1/2000."
			 	"\n7.Todos los �lbumes que superan el promedio de los importes."
			 	"\n8.Todos los �lbumes de cada artista."
			 	"\n9.Todos los �lbumes de un a�o determinado."
			 	"\n10.El �lbum o los �lbumes m�s caros."
			 	"\n-----------------------------------------------------"
			 	 "\n11.Listar todos los tipos de albunes"
			 	 "\n12.Listar todos los albunes que no sean de vinilo"
			 	 "\n13.Listar todos los albunes segun un artista determinado"
			 	"\n14.Salir.");
}

void listarCinco(){
	printf("\n1.Importe"
		   "\n2.Titulo"
		   "\n3.Salir");
}

void selecModificar(){
	printf("\n1-Titulo");
	printf("\n2-Fecha");
	printf("\n3-Importe");
	printf("\n---PARTE DOS---");
	printf("\n4.Tipo de album");
	printf("\n5.Descripcion de tipo de album");
}

void menuOpciones(){
	printf("Bienvenido");
    printf("\n1) Alta.");
    printf("\n2) Modificacion.");
    printf("\n3) Baja.");
    printf("\n4) Informar.");
    printf("\n5) Listar.");
    printf("\n6) Salir.");
}

void opcionArtista(){
	printf("\n1.The Beatles");
	printf("\n2.Michael Jackson");
	printf("\n3.Bob Marley");

}
//----------------------------------------------------------------------------HARCODEO----------------------------------------------

void harcodeo(album listAlbum[],int tam){

	//harcodeoGenero(listAlbum, tam);
	//harcodeoArtista(listA, tam);
	//harcodeoTipoArtista(listTA, tam);
	harcodeoAlbumes(listAlbum, tam);
	//harcodeoTypeAlbum(listTypeAlbum,tam);
}

/*
void harcodeoGenero(album list[],int tam){
	album carga[3]={
			{1,"descipcion1"},
			{2,"descipcion2"},
			{3,"descipcion3"},
					}; //harcodeo (cargo manual)

	for(int i=0; i<3; i++){
		list[i]=carga[i];
	}

}
*/
/*
void harcodeoArtista(artist list[],int tam){
	artist carga[3]={
			{1,"The Beatles",OCUPADO},
			{2,"Michael Jackson",OCUPADO},
			{3,"Bob Marley",OCUPADO},
					}; //harcodeo (cargo manual)

	for(int i=0; i<3; i++){
		list[i]=carga[i];
	}

}

void harcodeoTipoArtista(typeArtist list[],int tam){
	typeArtist carga[2]={
			{1,"SOLISTA",OCUPADO},
			{2,"BANDA",OCUPADO},
					}; //harcodeo (cargo manual)

	for(int i=0; i<2; i++){
		list[i]=carga[i];
	}

}
*/

/*
 * typedef struct
{
	int codAlbum;//autompletar
	char titulo[TAM];//validar
	fechAlbum fechaPubli;//validar
	float importe;//validar
	typeAlbum tipoAlbum;//parte dos
	int isEmpty ;

}album
 */
void harcodeoAlbumes(album list[],int tam){
	album carga[4]={
			{{1,"ROCK"},{1,"SOLISTA"},{1,"The Beatles"},1,"h",{12,3,1900},700,{3,"CD"},OCUPADO,1},
			{{2,"POP"},{2,"BANDA  "},{2,"Michael Jackson"},2,"a",{1,12,1800},400,{2,"CINTA"},OCUPADO,2},
			{{3,"METAL"},{1,"SOLISTA"},{3,"Bob Marley"},3,"z",{31,6,2001},1100,{1,"VINILO"},OCUPADO,3},
			{{4,"REGUE"},{2,"BANDA  "},{1,"The Beatles"},4,"f",{14,3,1900},1100,{1,"VINILO"},OCUPADO,1}
					}; //harcodeo (cargo manual)
	for(int i=0; i<4; i++){
		list[i]=carga[i];
	}

}

/*
void harcodeoTypeAlbum(typeAlbum list[],int tam){
	typeAlbum carga[3]={
				{1,"VINILO",OCUPADO},
				{2,"CINTA",OCUPADO},
				{3,"CD",OCUPADO},
						}; //harcodeo (cargo manual)

		for(int i=0; i<3; i++){
			list[i]=carga[i];
		}

}
*/
//--------------------------------PARTE DOS ---------------------------
void albunesNVinilo(album list[],int tam ){
	for(int i=0;i<tam ;i++){//tipoalbum
		if(list[i].isEmpty == OCUPADO && list[i].tipoAlbum.codtypeAlmbum != 1 ){
			printAlbum(list[i]);
		}
	}
}


int buscarArtista(album list[],int len ,int artista){
	int retorno=-1;
	int i;
	if(list !=NULL && len > 0 && artista >= 0){
		for(i=0 ; i<len ; i++){
			if(list[i].artista.codArtista == artista && list[i].isEmpty==OCUPADO){
				retorno=i;
			}
		}
	}
	return retorno;
}


int cantSolista(album list[], int len , int fecha){

	int retorno=0;
	int contSuperPas=0;
	int fechaBuscada;

	if(list != NULL && len > 0 ){

		fechaBuscada =buscarFecha(list, len, fecha);

		if(fechaBuscada>=0){

			for(int i=0;i<len;i++){

				if(list[i].isEmpty==OCUPADO && fecha == list[i].fechaPubli.anio ){
					contSuperPas++;
				}
			}
		}else{
			printf("esa fecha no existe\n");
		}
		retorno=contSuperPas;
	}

		return retorno;
}
