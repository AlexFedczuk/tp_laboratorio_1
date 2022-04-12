/*
 * funciones.h
 *
 *  Created on: Apr 11, 2022
 *      Author: Alex Yago Fedczuk
 */

#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096
#define DESCUENTO 10
#define AUMENTO 10
#define VALOR_BITCOIN 4606954.55

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

// Menues
void mostrarMenu(int opcionUnoCargada, int opcionDosCargada, float kmIngresados, float precioAereolineas, float precioLatam);
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
// Parsers
bool parseInt(char *string, int *integer);
bool parseFloat(char *string, float *nfloat);
// Pedir
float pedirNumeroFlotante(char mensaje[]);
int pedirNumeroEntero(char mensaje[]);
float pedirValorNoNegativo(char mensaje[]);
// Opcion 3
float aplicarDescuento(float numero, int descuento);
float aplicarAumento(float numero, int aumento);
float bitcoinAPesos(float bitcoin, float valorBitcoin);
float pesosABitcoin(float pesos, float valorPesos);
float calcularPrecioUnitario(float pesos, float km);
float calcularDiferencia(float valorUno, float valorDos);

#endif /* FUNCIONES_H_ */
