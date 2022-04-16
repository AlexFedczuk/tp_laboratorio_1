/*
 * funciones.h
 *
 *  Created on: Apr 11, 2022
 *      Author: Alex Yago Fedczuk
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/**
  @brief Hardcodea valores para la carga forzada.
  @param ...
  @param ...
  @param ...
  @returns ...
*/
void hardcodearValores(float* kmIngresados, float* precioLatam, float* precioAereolineas);
/**
  @brief Muestra el menu principal del programa.
  @param ...
  @param ...
  @param ...
  @returns ...
*/
void mostrarMenu(int opcionUnoCargada, int opcionDosCargada, float kmIngresados, float precioAereolineas, float precioLatam);
/**
  @brief Muestra el informe del programa.
  @param ...
  @param ...
  @param ...
  @returns ...
*/
void informarResultados(
		float latamDebito,
		float latamCredito,
		float latamBitcoin,
		float latamUnitario,
		float aereolineasDebito,
		float aereolineasCredito,
		float aereolineasBitcoin,
		float aereolineasUnitario,
		float diferencia);
/**
  @brief Muestra el informe de la carga forzada del programa.
  @param ...
  @param ...
  @param ...
  @returns ...
*/
void informarCargaForzada(
		float precioLatam,
		float precioAereolineas,
		float kmIngresados,
		float latamDebito,
		float latamCredito,
		float latamBitcoin,
		float latamUnitario,
		float aereolineasDebito,
		float aereolineasCredito,
		float aereolineasBitcoin,
		float aereolineasUnitario,
		float diferencia);

#endif /* FUNCIONES_H_ */
