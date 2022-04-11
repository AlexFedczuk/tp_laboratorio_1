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

// Por alguna razon se queda en un bucle, al ingresar una opcion en el GDB Online.
void mostrarMenu(int opcionUnoCargada, int opcionDosCargada, float kmIngresados, float precioAereolineas, float precioLatam);
void informarResultados(float kmIngresados, float precioTotalLatam, float precioTotalAereolines);
float pedirNumeroFlotante(char mensaje[]);
bool parseInt(char *string, int *integer);
int pedirNumeroEntero(char mensaje[]);
bool parseFloat(char *string, float *nfloat);
float pedirNumeroFlotante(char mensaje[]);
float pedirValorNoNegativo(char mensaje[]);
float aplicarDescuento(float numero, int descuento);
float aplicarAumento(float numero, int aumento);
float bitcoinAPesos(float bitcoin, float valorBitcoin);
float pesosABitcoin(float pesos, float valorPesos);
float calcularPreciosUnitarios(float pesos, float km);
float calcularDiferencia(float valorUno, float valorDos);

#endif /* FUNCIONES_H_ */
