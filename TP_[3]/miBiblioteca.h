/*
 * miBiblioteca.h
 *
 *  Created on: Apr 25, 2022
 *      Author: Alex Yago Fedczuk
 */

#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_

//#include "ArrayPassenger.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "LinkedList.h"
#define LEN 2000 // El maximo es 2000 pasajeros!

/** \brief Esta funcion muestra el menu de opciones del menu principal.
*   \return void
*/
void mostrarMenu();

/** \brief Esta funcion muestra el menu de opciones del menu de modificaciones.
*   \return void
*/
void mostrarMenuModificacion();

/** \brief Esta funcion muestra el menu de opciones del menu de ordenamiento.
*   \return void
*/
void mostrarMenuOrdenamiento();

/** \brief Esta funcion hardcodea x cantidad de entidades dentro de la lista indicada.
*   \param list Passenger* Pointer to array of passenger
*   \param len int Array length
*   \param int* contadorId, direccion de memoria del contador de IDs.
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - Devuelve el ID mas grande, de los valores hardcodeados.
*/
//int hardcodearEntidades(ePassenger* list, int len, int* contadorId);

/** \brief Esta funcion devuelve el valor mayor de un vector de enteros.
*   \param int vec
*   \param int len
*   \return Devuelve el mayor valor del vector.
*/
int calcularIntMayor(int vec[], int len);

/** \brief Esta funcion devuelve el valor mayor de un vector de enteros.
*   \param int vec
*   \param int len
*   \return Devuelve el mayor valor del vector.
*/
int calcularIntMayor(int vec[], int len);

/** \brief Esta funcion calcula el total de los precios de una lista.
*   \param ePassenger* list, la direccion de memoria a la lista.
*   \param int len, el tamanio de la lista.
*   \return Devuele (-1) si hay un parametro invalido - El valor del total si Ok.
*/
//float calcularTotal(ePassenger* list, int len);

/** \brief Esta funcion calcula el total de los precios de una lista.
*   \param ePassenger* list, la direccion de memoria a la lista.
*   \param int len, el tamanio de la lista.
*   \return Devuele (-1) si hay un parametro invalido - El valor del total si Ok.
*/
//float calcularTotal(ePassenger* list, int len);

/** \brief Esta funcion calcula el promedio de los precios de una lista.
*   \param ePassenger* list, la direccion de memoria a la lista.
*   \param int len, el tamanio de la lista.
*   \param float total, el total de los precios.
*   \return Devuele (-1) si hay un parametro invalido - El valor del promedio si Ok.
*/
//float calcularPromedio(ePassenger* list, int len, float total);

/** \brief Esta funcion calcula cuantos pasajeros en la lista tienen precios mayor al promedio.
*   \param ePassenger* list, la direccion de memoria a la lista.
*   \param int len, el tamanio de la lista.
*   \return Devuele (-1) si hay un parametro invalido - El valor del promedio si Ok.
*/
//int calcularPasajerosMasPromedio(ePassenger* list, int len, float promedio);

/** \brief Informa el total y promedio de los precios de los pasajeros, y quienes tienen un precio mayor a proemdio.
*   \param float* total, direccion de memoria al valor del total calculado.
*   \param float* promedio, direccion de memoria al valor del promedio calculado.
*   \param int* cantidad, direccion de memoria al valor del cantidad calculado.
*   \return Devuele (-1) si hay un parametro invalido - (0) si Ok.
*/
int informarInformacion(float* total, float* promedio, int* cantidad);

/** \brief Formaliza la cadena de caracteres ingresada por parametros.
* \param char* cadena, la cadena de caracteres a formalizar.
* \param len int, el tamanio de la cadena.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int formalizarNombre(char* cadena, int len);

/** \brief Se fija en un archivo cual es el ID maximo y devuelve ese valor.
* \param char* fileName, the name of the file.
* \return int Return (-1) if Error - the number of the maximun ID if Ok.
*/
int GetMaximumID(char* fileName);

/** \brief Guarda en un archivo el valor del ID mas grande.
* \param char* fileName, the name of the file.
* \param int* idMaximo, la direccion de memoria del ID mas grande.
* \return int Return (-1) if Error - (0) if Ok.
*/
int SaveMaximumID(char* fileName, int* idMaximo);

#endif /* MIBIBLIOTECA_H_ */
