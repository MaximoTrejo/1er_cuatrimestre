/*
 * libraryArtistMusic.h
 *
 *  Created on: 30 abr. 2022
 *      Author: maxim
 */

#ifndef LIBRARYARTISTMUSIC_H_
#define LIBRARYARTISTMUSIC_H_

#define TAM 200//tama�o de los titulos, desc , ect
#define CANT 10//cantidad de datos que se pueden cargar en el array

#define LIBRE 0
#define OCUPADO 1

#define REINTENTOS 5

typedef struct
{
	int codGenero;//autompletar
	char descripcion[TAM];

}gender;//genero
//-----------------------------------------------------------

typedef struct
{
	int codTypeArt;//autompletar
	char typeDes[TAM];

}typeArtist;//tipo artista

//--------------------------------------------------------------------
typedef struct
{
	int codArtista;//autompletar
	char nombre[TAM];

}artist;//artista

//-----------------------------------------------------------
typedef struct
{
	int dia;
	int mes;
	int anio;

}fechAlbum;
//-----------------------PARTE DOS----------------------------
typedef struct
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





//-----------------------------------INICIALIZAR------------------------------------------------------
////@brief inicializa todo el string en 0
////@fn int initArtist(album list[],int tam);
////@param album list[](llamo a todo el string de la estructura album)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return 0[BIEN] | -1[MAL]
int initArtist(album list[],int tam);
//------------------------------------ALTA--------------------------------------------------------------------
////@brief busca un lugar libre em la estructura album viendo si la cantidad del string no este llena
////@fn int bucarLibre(album artic[], int len);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tama�o del string)
////@return retorna el lugar libre
int bucarLibre(album artic[], int len);
////@brief cargo 1 lugar del string de la estructura album
////@fn int addArtist(album listAlbum[]);
////@param album list[](llamo a todo el string de la estructura album)
////@return 0[BIEN] | -1[MAL]
int addArtist(album listAlbum[]);
//int addArtist(album listAlbum[] , typeAlbum listTA[] );
//------------------------------------MODIFICAR-----------------------------------------------------------
////@brief busca si el id que ingreso el usuario es igual al id que esta cargado en el string
////@fn int buscarId(album list[], int len,int id);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tama�o del string)
////@param int id(id ingresado por el usuario)
////@return retorna el id | -1[MAL]
int buscarId(album list[], int len,int id);
////@brief modifica uno de los campos que esta cargado en el string
////@fn int modificarArtists(album list[], int len , int idMod);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tama�o del string)
////@param int idMod(id que el usuario quiere modificar )
////@return 0[BIEN] | -1[MAL]
int modificarArtists(album list[]/*,typeAlbum listTA[] */,int len , int idMod);
//int modificarArtists(album list[],typeAlbum listTA[] ,int len , int idMod);
//----------------------------BAJA------------------------------------------------------------------------
////@brief borra de manera logica los datos del string
////@fn int removeArtist(album list[], int len , int id);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tama�o del string)
////@param int id(id que quiere eliminar )
////@return retorna el id | -1[MAL]
int removeArtist(album list[], int len , int id);
//------------------------------------------MENU-------------------------------------------------------------------
////@brief esqueleto de todo el programa , lugar donde estan todas las opciones y funcionalidades
////@fn void menu(album list[],gender genero[],typeArtist typeA[],artist artistas[], int len);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tama�o del string)
////@param gender genero[](llamo a todo el string de la estructura genero)
////@param typeArtist typeA[](llamo a todo el string de la estructura tipo de artista)
////@param artist artistas[](llamo a todo el string de la estructura artista)
////@return no retorno nada es (void)
void menu(album list[], int len);
//-------------------------------------LISTAR-------------------------------
////@brief muestra la cuales son los albunes que son anteriores a 1/1/2000
////@fn void printAlbunesFecha(album fecha[],int len);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tama�o del string)
////@return no retorno nada es (void)
void printAlbunesFecha(album fecha[],int len);

////@brief muestra la cuales son los albunes que superan el promedio
////@fn void printSuperAlbunes(album list[],int len, float promedio);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tama�o del string)
////@param float promedio(promedio antes calculado que sirve para determinar cuales son los que superan el promedio)
////@return no retorno nada es (void)
void printSuperAlbunes(album list[],int len, float promedio);
////@brief muestro todos los albunes de cada artista
////@fn void todosAA(album list[],artist artistas[], int len );
////@param album list[](llamo a todo el string de la estructura album)
////@param artist artistas[](llamo a todo el string de la estructura artistas)
////@param int len(variable de enteros que psa el tama�o del string)
////@return no retorno nada es (void)
void todosAA(album list[], int len );
//void todosAA(album list[],artist artistas[], int len );
////@brief busco una fecha pidiendo el a�o
////@fn int buscarFecha(album list[], int len,int fecha);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tama�o del string)
////@param int fecha(a�o que quiera buscar el usuario)
////@return retorna el id | -1[MAL]
int buscarFecha(album list[], int len,int fecha);
////@brief busca el mas caro de todos los albunes y los muestra (si tienen el mismo importe lo muestra)
////@fn void albunesCaros(album list[] , int len);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tama�o del string)
////@return no retorno nada es (void)
void albunesCaros(album list[] , int len);
//-------------------------------INFORMAR-----------------------
////@brief cantidad de albunes que superan al promedio
////@fn int superAlbunes(album list[],int len, float promedio);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tama�o del string)
////@param float promedio(promedio antes calculado que sirve para determinar cuales son los que superan el promedio)
////@return retorna la cantidad de albunes que superan el promedio
int superAlbunes(album list[],int len, float promedio);
////@brief suma todos los importes
////@fn int totalInforme( album list[],int len,float*promedio);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tama�o del string)
////@param float *promedio(variable donde se va a guardar el promedio)
////@return retorna el total
int totalInforme( album list[],int len,float*promedio);
////@brief se calcula el promedio
////@fn float promedioInforme(int contImporte , int totaInformes );
////@param int contImporte(contador de importes )
////@param int totalInformes (total de imformes , es el total del importe)
////@return retorna el promedio
float promedioInforme(int contImporte , int totaInformes );
////@brief cantidad de albunes cuta fecha sea menor al 1/1/2000
////@fn int cantAlbunesFecha(album fecha[],int len);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tama�o del string)
////@return retorna la cantidad de albunes
int cantAlbunesFecha(album fecha[],int len);
//---------------------------ENUNCIADOS-------------------------------
////@brief todos las opciones de listar
////@fn void listar();
////@param no tiene ningun parametro es (void)
////@return no retorno nada es (void)
void listar();
////@brief todos las opciones de listar del punto 5
////@fn void listarCinco();
////@param no tiene ningun parametro es (void)
////@return no retorno nada es (void)
void listarCinco();
////@brief todos las opciones de informes
////@fn void opcionesInformes();
////@param no tiene ningun parametro es (void)
////@return no retorno nada es (void)
void opcionesInformes();
////@brief todos las opciones de modificar
////@fn void selecModificar();
////@param no tiene ningun parametro es (void)
////@return no retorno nada es (void)
void selecModificar();
////@brief todos las opciones del menu
////@fn void menuOpciones();
////@param no tiene ningun parametro es (void)
////@return no retorno nada es (void)
void menuOpciones();
//------------------------IMPRIMIR--------------------------------------------
////@brief imprime los datos de la estructura album
////@fn void imprimirAlbum(album list[], int len);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tama�o del string)
////@return no retorno nada es (void)
void imprimirAlbum(album list[], int len);
////@brief imprime los datos de la estructura genero
////@fn void imprimirGenero(gender list[], int len);
////@param gender list[](llamo a todo el string de la estructura genero)
////@param int len(variable de enteros que psa el tama�o del string)
////@return no retorno nada es (void)
void imprimirGenero(album list[], int len);
//void imprimirGenero(gender list[], int len);
////@brief imprime los datos de la estructura tipo de artista
////@fn void imprimirTipoArtista(typeArtist list[], int len);
////@param typeArtist list[](llamo a todo el string de la estructura tipo de artistas)
////@param int len(variable de enteros que psa el tama�o del string)
////@return no retorno nada es (void)
void imprimirTipoArtista(album list[], int len);
//void imprimirTipoArtista(typeArtist list[], int len);
////@brief imprime los datos de la estructura artista
////@fn void imprimirArtistas(artist list[], int len);
////@param artist list[](llamo a todo el string de la estructura artistas)
////@param int len(variable de enteros que psa el tama�o del string)
////@return no retorno nada es (void)
void imprimirArtistas(album list[], int len);
//---------------ORDENAR-----------------------------------------------------------------
////@brief odena de manera(descendentemente) los importes
////@fn int sortAlbunesImporte(album* list, int len);
////@param album* list(llamo a todo el string de la estructura artistas)(como un puntero)
////@param int len(variable de enteros que psa el tama�o del string)
////@return 0[BIEN] | -1[MAL]
int sortAlbunesImporte(album* list, int len);
//-----HARCODEO-----------------------------------------------------------------------
////@brief funcion donde guardo todos los harcodeos
////@fn void harcodeo(gender listG[],artist listA[],typeArtist listTA[],album listAlbum[],int tam);
////@param album listAlbum[](llamo a todo el string de la estructura album)
////@param int tam(variable de enteros que psa el tama�o del string)
////@param gender listG[](llamo a todo el string de la estructura genero)
////@param typeArtist ListaTA[](llamo a todo el string de la estructura tipo de artista)
////@param artist listA[](llamo a todo el string de la estructura artista)
////@return no retorno nada es (void)
void harcodeo(album listAlbum[],int tam);
////@brief le cargo datos a la estructura genero
////@fn void harcodeoGenero(gender list[],int tam);
////@param gender list[](llamo a todo el string de la estructura genero)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return no retorno nada es (void)
void harcodeoGenero(gender list[],int tam);
////@brief le cargo datos a la estructura artistas
////@fn void harcodeoArtista(artist list[],int tam);
////@param artist list[](llamo a todo el string de la estructura artistas)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return no retorno nada es (void)
void harcodeoArtista(artist list[],int tam);
////@brief le cargo datos a la estructura Tipo de artistas
////@fn void harcodeoTipoArtista(typeArtist list[],int tam);
////@param typeArtist list[](llamo a todo el string de la estructura Tipo de sartistas)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return no retorno nada es (void)
void harcodeoTipoArtista(typeArtist list[],int tam);
////@brief le cargo datos a la estructura albumes
////@fn void harcodeoAlbumes(album list[],int tam);
////@param album list[](llamo a todo el string de la estructura album)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return no retorno nada es (void)
void harcodeoAlbumes(album list[],int tam);
//------------------------------------------------------------------------------PARTE DOS--------------------
//void harcodeoTypeAlbum(typeAlbum list[],int tam);
void imprimirTipoAlbum(album list[],int len);
//void albunesNVinilo(album list[],typeAlbum listTA[],int tam );
void albunesNVinilo(album list[],int tam );
int buscarArtista(album list[],int len ,int artista);
void opcionArtista();
#endif /* LIBRARYARTISTMUSIC_H_ */



int cantSolista(album list[], int len , int fecha);
