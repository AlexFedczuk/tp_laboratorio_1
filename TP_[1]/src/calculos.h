/*
 * calculos.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Alex Yago Fedczuk
 */
#ifndef CALCULOS_H_
#define CALCULOS_H_

#define DESCUENTO 10
#define AUMENTO 10
#define VALOR_BITCOIN 4606954.55

/**
  @brief Esta funcion calcula el precio final al aplicarle un descuento igual a la constante DESCUENTO.
  @param float numero, numero a descontar.
  @param int descuento, valor del descuento.
  @returns Devuelve el valor final descontado.
*/
float aplicarDescuento(float numero, int descuento);

/**
  @brief Esta funcion calcula el precio final al aplicarle un aumento igual a la constante AUMENTO.
  @param float numero, numero a aumentar.
  @param int aumento, valor del aumneto.
  @returns Devuelve el valor final aumentado.
*/
float aplicarAumento(float numero, int aumento);

/**
  @brief Esta funcion calcula el valor de Bitcoins a Pesos.
  @param float bitcoin, numero de bitcoins.
  @param float valorBitcoin, el valor de un bitcoin.
  @returns Devuelve el valor de Pesos igual a Bitcoins, pasado por los parametros.
*/
float bitcoinAPesos(float bitcoin, float valorBitcoin);

/**
  @brief Esta funcion calcula el valor de Pesos a Bitcoins.
  @param float pesos, numero de pesos.
  @param float valorPesos, el valor de los pesos.
  @returns Devuelve el valor de Bitcoins igual a Pesos, pasado por los parametros.
*/
float pesosABitcoin(float pesos, float valorPesos);

/**
  @brief Esta funcion calcula el valor de Pesos por unidad del total de Kilometros.
  @param float pesos, numero de pesos.
  @param float km, numero de kilometros.
  @returns Devuelve el valor de Pesos por unidad del total de Kilometros ingresados por parametros.
*/
float calcularPrecioUnitario(float pesos, float km);

/**
  @brief Calcula la diferencia entre dos valores.
  @param float valorUno, el valor uno del calculo.
  @param float valorDos, el valor dos del calculo.
  @returns Devuelve la diferencia calculada entre dos valores.
*/
float calcularDiferencia(float valorUno, float valorDos);

#endif /* CALCULOS_H_ */
