/*
 * funciones.h
 *
 *  Created on: Apr 11, 2022
 *      Author: Alex Yago Fedczuk
 */
#ifndef INPUT_FUNTIONS_H_
#define INPUT_FUNTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096

/**
  @brief Esta funcion se encarga de validar que se ingreso un valor de tipo entero por consola.
  @param char *string, el valor como cadena.
  @param int *integer, el valor pasado a numero entero.
  @returns Deveuelve un valor de tipo Booleano.
*/
bool parseInt(char *string, int *integer);

/**
  @brief Esta funcion se encarga de validar que se ingreso un valor de tipo flotante por consola.
  @param char *string, el valor como cadena.
  @param float *nfloat, el valor pasado a numero flotante.
  @returns Deveuelve un valor de tipo Booleano.
*/
bool parseFloat(char *string, float *nfloat);

/**
  @brief Esta funcion se encarga de pedir por consola el ingreso de un valor de tipo flotante.
  @param char mensaje[], mensaje a mostrar al usuario.
  @returns Deveuelve un valor de tipo Flotante.
*/
float pedirNumeroFlotante(char mensaje[]);

/**
  @brief Esta funcion se encarga de pedir por consola el ingreso de un valor de tipo entero.
  @param char mensaje[], mensaje a mostrar al usuario.
  @returns Deveuelve un valor de tipo Entero.
*/
int pedirNumeroEntero(char mensaje[]);

/**
  @brief Esta funcion se encarga de pedir por consola el ingreso de un valor de tipo entero NO negativo.
  @param char mensaje[], mensaje a mostrar al usuario.
  @returns Deveuelve un valor de tipo Entero NO negativo.
*/
float pedirValorNoNegativo(char mensaje[]);

#endif /* INPUT_FUNTIONS_H_*/
