/*
 * menu.h
 *
 *  Created on: 2 oct 2022
 *      Author: maxim
 */

#ifndef MENU_H_
#define MENU_H_

#define TAM 200
#define CANT 10

#define LIBRE 0
#define OCUPADO 1

#define REINTENTOS 5


////@brief esqueleto del sistema
////@fn void menu (eLibro libros[],int tam,eAutor autor[] , eEditorial editorial[],ePais pais[]);
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param int tam(variable de enteros que psa el tama�o del string)
////@param eAutor autor[](llamo a todo el string de la estructura autor)
////@param eEditorial editorial[](llamo a todo el string de la estructura editorial)
////@param ePais pais[](llamo a todo el string de la estructura pais)
////@return void
void menu (eLibro libros[],int tam,eAutor autor[] , eEditorial editorial[],ePais pais[] , eGenero genero[]);
////@brief busco el id
////@fn int buscarID(eLibro libros[],int tam,int legajoABuscar);
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param int tam(variable de enteros que psa el tama�o del string)
////@param int legajoABuscar(variable de enteros que paso el legajo a buscar )
////@return indice de del id buscado
int buscarID(eLibro libros[],int tam,int legajoABuscar);
////@brief menu con las opciones de Informes
////@fn void menuInformes();
////@return void
void menuInformes();
////@brief inicializo toda el array de la estrucura libros con el estado en libre
////@fn void inicializarAE(eLibro libros[],int tam);
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return void
void inicializarAE(eLibro libros[],int tam);
////@brief menu con las opciones de Opciones
////@fn void menuOpciones(void);
////@return void
void menuOpciones(void);
////@brief busca un lugar libre en todo el array de libros
////@fn int BuscarLibre(eLibro libros[],int tam);
////@param eLibro libros[](llamo a todo el string de la estructura libros)
////@param int tam(variable de enteros que psa el tama�o del string)
////@return indice -1[si no encontro ninguno] | indice del lugar libre si encontro uno
int BuscarLibre(eLibro libros[],int tam);
////@brief menu con las opciones de listar
////@fn void menulistar();
////@return void
void menulistar();

#endif /* MENU_H_ */
