/*
 * bibliotecaLibro.h
 *
 *  Created on: 1 oct 2022
 *      Author: maxim
 */

#ifndef BIBLIOTECALIBRO_H_
#define BIBLIOTECALIBRO_H_

#define TAM 200
#define CANT 10

#define LIBRE 0
#define OCUPADO 1

#define REINTENTOS 5

typedef struct
{
	int codPais;//autompletar
	char descripcion[TAM];
	int estado;
}ePais;

typedef struct
{
	int codAutor;//autompletar
	char nombre[TAM];
	int idNacionalidad;
}eAutor;

typedef struct
{
	int codEditorial;//autompletar
	char descripcion[TAM];
	int estado;

}eEditorial;

typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;


//PARTE 2
typedef struct
{
	int codGenero;
	char descripcion[TAM];
	int estado;

}eGenero;




typedef struct
{
	int codLibro;//autompletar
	char titulo[TAM];
	eFecha FechaPublicacion;
	float importe;
	int idAutor;
	int idEditorial;
	int estado;
	int idGenero;

}eLibro;



////@brief busca un lugar libre en todo el array de libros
////@fn int BuscarLibre(eLibro libros[],int tam);
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return indice -1[si no encontro ninguno] | indice del lugar libre si encontro uno
int BuscarLibre(eLibro libros[],int tam);
////@brief inicializo toda el array de la estrucura libros con el estado en libre
////@fn void inicializarAE(eLibro libros[],int tam);
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return void
void inicializarAE(eLibro libros[],int tam);
////@brief busco el id
////@fn int buscarID(eLibro libros[],int tam,int legajoABuscar);
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param int tam(variable de enteros que psa el tama�o del string)
////@param int legajoABuscar(variable de enteros que paso el legajo a buscar )
////@return indice de del id buscado
int buscarID(eLibro libros[],int tam,int legajoABuscar);
////@brief mostrar la estructura pais
////@fn void mostrarPais(ePais pais[] , int tam)
////@param ePais pais[](llamo a todo el string de la estructura pais)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return void
void mostrarPais(ePais pais[] , int tam);
////@brief ordena por titulo y por importe
////@fn void ordTituloyImporte(eLibro libros[], int tam)
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return void
void ordTituloyImporte(eLibro libros[], int tam);
////@brief saco el promedio de importes
////@fn float promedioImporte(int cantidadImportes , float totalImporte)
////@param int cantidadImportes(contador de importes)
////@param  float totalImporte(total de los importes cargados)
////@return promedio (promedio de importes)
float promedioImporte(int cantidadImportes , float totalImporte);
////@brief cantidad de libros que superen una fecha
////@fn int cantidadLSF(eLibro libros[], int tam)
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return contador de cantidad de libros
int cantidadLSF(eLibro libros[], int tam);
////@brief cantidad de libros que superen una el promedio de importes
////@fn int LqSuperanPromedio(eLibro libros[],float promedio , int tam)
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param int tam(variable de enteros que psa el tama�o del string)
////@param int promedio(promedio utilizado para compparar quien supera el promedio)
////@return contador de cantidad de libros que superan el promedio
int LqSuperanPromedio(eLibro libros[],float promedio , int tam);
////@brief calcula el total de importes
////@fn float TotalImportes(eLibro libros[],int tam , float * promedio)
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param int tam(variable de enteros que psa el tama�o del string)
////@param int * promedio(promedio utilizado para otra funcion )
////@return total de importes
float TotalImportes(eLibro libros[],int tam , float * promedio);
////@brief borra libros pasandole un id
////@fn int borrarLibros(eLibro libros[] , int tam,int idMod)
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param int tam(variable de enteros que psa el tama�o del string)
////@param int idMod(id que quiere borrar el usuario )
////@return retorno -1[ERROR] | retorno 0[bien]
int borrarLibros(eLibro libros[] , int tam,int idMod);
////@brief muestra un solo libro
////@fn void mostrar(eLibro libros[],eAutor autor[] , eEditorial editorial[]);
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param eAutor autor[](llamo a todo el string de la estructura autor)
////@param eEditorial editorial[](llamo a todo el string de la estructura editorial)
////@return void
void mostrarIndividual(eLibro libros[],eAutor autor[] , eEditorial editorial[],eGenero genero[]);
////@brief modifica un libro
////@fn int modificarLibros(eLibro libros[] , int tam,int idMod,eAutor autor[],ePais pais[] ,eEditorial editorial[])
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param int tam(variable de enteros que psa el tama�o del string)
////@param eAutor autor[](llamo a todo el string de la estructura autor)
////@param eEditorial editorial[](llamo a todo el string de la estructura editorial)
////@return retorno -1[ERROR] | retorno 0[bien]
int modificarLibros(eLibro libros[] , int tam,int idMod,eAutor autor[],ePais pais[] ,eEditorial editorial[],eGenero genero[]);
////@brief mostrar la estructura libros
////@fn void mostrarlibros(eLibro libros[],int tam ,eAutor autor[] ,eEditorial editorial[]);
////@param ePais pais[](llamo a todo el string de la estructura pais)
////@param int tam(variable de enteros que psa el tama�o del string)
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param eLibro eEditorial editorial[](llamo a todo el string de la estructura editorial)
////@return void
void mostrarLibros(eLibro libros[],int tam ,eAutor autor[] ,eEditorial editorial[],eGenero genero[]);
//void mostrarlibros(eLibro libros[],int tam ,eAutor autor[] ,eEditorial editorial[]);///////////////////////////////////////////////////////////////modi
////@brief mostrar la estructura autor
////@fn void mostrarAutor(eAutor autor[] , int tam , ePais pais[]);
////@param ePais pais[](llamo a todo el string de la estructura pais)
////@param int tam(variable de enteros que psa el tama�o del string)
////@param eAutor autor[](llamo a todo el string de la estructura autor)
////@return void
void mostrarAutor(eAutor autor[] , int tam , ePais pais[]);
////@brief carga manual de la estrucura pais
////@fn void harcodeoPais(ePais pais[],int tam);
////@param ePais pais[](llamo a todo el string de la estructura pais)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return void
void harcodeoPais(ePais pais[],int tam);
////@brief carga manual de la estrucura Autor
////@fn void harcodeoAutor(eAutor autor[],int tam);
////@param int tam(variable de enteros que psa el tama�o del string)
////@param eAutor autor[](llamo a todo el string de la estructura autor)
////@return void
void harcodeoAutor(eAutor autor[],int tam);
////@brief carga manual de la estrucura editorial
////@fn void harcodeoEditorial(eEditorial editorial[],int tam);
////@param eEditorial editorial[](llamo a todo el string de la estructura editorial)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return void
void harcodeoEditorial(eEditorial editorial[],int tam);
////@brief mostrar la estructura Editorial
////@fn void mostrarEditorial(eEditorial editorial[] , int tam);
////@param eEditorial editorial[](llamo a todo el string de la estructura editorial)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return void
void mostrarEditorial(eEditorial editorial[] , int tam);
////@brief alta de un libro
////@fn int AltaLibros(eLibro libros[] ,eAutor autor[],ePais pais[] ,eEditorial editorial[]);
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param eAutor autor[](llamo a todo el string de la estructura autor)
////@param eEditorial editorial[](llamo a todo el string de la estructura editorial)
////@param ePais pais[](llamo a todo el string de la estructura pais)
////@return retorno -1[ERROR] | retorno 0[bien]
int altaLibros(eLibro libros[] ,eAutor autor[],ePais pais[] ,eEditorial editorial[], eGenero genero[]);
//void mostrarGenero(eGenero genero[],int tam);
////@brief mostrar estructura genero
////@fn void mostrarAutor(eAutor autor[] , int tam , ePais pais[]);
////@param ePais pais[](llamo a todo el string de la estructura pais)
////@param int tam(variable de enteros que psa el tama�o del string)
////@param eAutor autor[](llamo a todo el string de la estructura autor)
////@return void
void mostrarGenero(eGenero genero[],int tam);
////@brief carga manual de la estrucura genero
////@fn void harcodeoGenero(eGenero genero[],int tam);
////@param eEditorial editorial[](llamo a todo el string de la estructura editorial)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return void
void harcodeoGenero(eGenero genero[],int tam);
////@brief mostrar libros cuyo genero no sea novela
////@fn void mostLibrosNnovela(eLibro libros[], int tam,eAutor autor[] ,eEditorial editorial[]);
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param eAutor autor[](llamo a todo el string de la estructura autor)
////@param eEditorial editorial[](llamo a todo el string de la estructura editorial)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return retorno -1[ERROR] | retorno 0[bien]
int mostLibrosNnovela(eLibro libros[], int tam,eAutor autor[] ,eEditorial editorial[]);
////@brief mostrar libros ARG que correspondan a una editorial determinada
////@fn int autoresAporEDet(eLibro libros[], int tam,eEditorial editorial[] ,eAutor autor[]);
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param eAutor autor[](llamo a todo el string de la estructura autor)
////@param eEditorial editorial[](llamo a todo el string de la estructura editorial)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return retorno -1[ERROR] | retorno 0[bien]
int autoresAporEDet(eLibro libros[], int tam,eEditorial editorial[] ,eAutor autor[] ,eGenero genero[]);



#endif /* BIBLIOTECALIBRO_H_ */
