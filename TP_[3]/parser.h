#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*, La direccion de memoria donde se encuentra el archivo.
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*, La direccion de memoria donde se encuentra el archivo.
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

/** \brief Parsea los datos de los pasajeros en memoria al archivo data.csv (modo texto).
 *
 * \param path char*, La direccion de memoria donde se encuentra el archivo.
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int parser_PassengerToText(FILE* pFile , LinkedList* pArrayListPassenger);

/** \brief Parsea los datos de los pasajeros en memoria al archivo data.csv (modo binario).
 *
 * \param path char*, La direccion de memoria donde se encuentra el archivo.
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int parser_PassengerToBinary(FILE* pFile , LinkedList* pArrayListPassenger);

#endif /* PARSER_H_ */
