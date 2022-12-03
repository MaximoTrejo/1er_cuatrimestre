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


////@brief menu con las opciones de Informes
////@fn void menuInformes();
////@return void
void menuInformes();
////@brief menu con las opciones de Opciones
////@fn void menuOpciones(void);
////@return void
void menuOpciones(void);
////@brief menu con las opciones de listar
////@fn void menulistar();
////@return void
void menulistar();
////@brief menu con las opciones de modificar
////@fn void menuModificar(void);
////@return void
void menuModificar(void);

#endif /* MENU_H_ */
