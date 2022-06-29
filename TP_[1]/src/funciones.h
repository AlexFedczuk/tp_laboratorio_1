/*
 * funciones.h
 *
 *  Created on: Apr 11, 2022
 *      Author: Alex Yago Fedczuk
 */
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
  @brief Hardcodea valores para la carga forzada.
  @param float* kmIngresados, km a hardcodear.
  @param float* precioLatam, precio a hardcodear.
  @param float* precioAereolineas, precio a hardcodear.
  @returns void
*/
void hardcodearValores(float* kmIngresados, float* precioLatam, float* precioAereolineas);

/**
  @brief Muestra el menu principal del programa.
  @param int opcionUnoCargada, valor de la opcion uno.
  @param int opcionDosCargada, valor de la opcion dos.
  @param float kmIngresados, valor de los km.
  @param float precioAereolineas, valor del precio Aereolineas.
  @param float precioLatam, valor del precio Latam.
  @returns void
*/
void mostrarMenu(int opcionUnoCargada, int opcionDosCargada, float kmIngresados, float precioAereolineas, float precioLatam);

/**
  @brief Muestra el informe del programa.
  @param float latamDebito, valor a informar.
  @param float latamCredito, valor a informar.
  @param float latamBitcoin, valor a informar.
  @param float latamUnitario, valor a informar.
  @param float aereolineasDebito, valor a informar.
  @param float aereolineasCredito, valor a informar.
  @param float aereolineasBitcoin, valor a informar.
  @param float aereolineasUnitario, valor a informar.
  @param float diferencia, valor a informar.
  @returns void
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
  @param float precioLatam, valor hardcodeado a mostrar.
  @param float precioAereolineas, valor hardcodeado a mostrar.
  @param float kmIngresados, valor hardcodeado a mostrar.
  @param float latamDebito, valor hardcodeado a mostrar.
  @param float latamCredito, valor hardcodeado a mostrar.
  @param float latamBitcoin, valor hardcodeado a mostrar.
  @param float latamUnitario, valor hardcodeado a mostrar.
  @param float aereolineasDebito, valor hardcodeado a mostrar.
  @param float aereolineasCredito, valor hardcodeado a mostrar.
  @param float aereolineasBitcoin, valor hardcodeado a mostrar.
  @param float aereolineasUnitario, valor hardcodeado a mostrar.
  @param float diferencia, valor hardcodeado a mostrar.
  @returns void
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
