/*
 * calculos.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Alex Yago Fedczuk
 */

#define DESCUENTO 10
#define AUMENTO 10
#define VALOR_BITCOIN 4606954.55

#ifndef CALCULOS_H_
#define CALCULOS_H_
/**
  @brief Esta funcion calcula el precio final al aplicarle un descuento igual a la constante DESCUENTO.
  @param ...
  @param ...
  @param ...
  @returns Devuelve el valor final descontado.
*/
float aplicarDescuento(float numero, int descuento);
/**
  @brief Esta funcion calcula el precio final al aplicarle un aumento igual a la constante AUMENTO.
  @param ...
  @param ...
  @param ...
  @returns Devuelve el valor final aumentado.
*/
float aplicarAumento(float numero, int aumento);
/**
  @brief Esta funcion calcula el valor de Bitcoins a Pesos.
  @param ...
  @param ...
  @param ...
  @returns Devuelve el valor de Pesos igual a Bitcoins, pasado por los parametros.
*/
float bitcoinAPesos(float bitcoin, float valorBitcoin);
/**
  @brief Esta funcion calcula el valor de Pesos a Bitcoins.
  @param ...
  @param ...
  @param ...
  @returns Devuelve el valor de Bitcoins igual a Pesos, pasado por los parametros.
*/
float pesosABitcoin(float pesos, float valorPesos);
/**
  @brief Esta funcion calcula el valor de Pesos por unidad del total de Kilometros.
  @param ...
  @param ...
  @param ...
  @returns Devuelve el valor de Pesos por unidad del total de Kilometros ingresados por parametros.
*/
float calcularPrecioUnitario(float pesos, float km);
/**
  @brief Calcula la diferencia entre dos valores.
  @param ...
  @param ...
  @param ...
  @returns Devuelve la diferencia calculada entre dos valores.
*/
float calcularDiferencia(float valorUno, float valorDos);

#endif /* CALCULOS_H_ */
