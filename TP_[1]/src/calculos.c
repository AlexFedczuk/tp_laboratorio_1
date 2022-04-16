/*
 * calculos.c
 *
 *  Created on: Apr 16, 2022
 *      Author: Alex Yago Fedczuk
 */

#include "calculos.h"

float aplicarDescuento(float numero, int descuento){
    float resultado;

    resultado = (100 - descuento) * numero / 100;

    return resultado;
}

float aplicarAumento(float numero, int aumento){
    float resultado;

    resultado = (100 + aumento) * numero / 100;

    return resultado;
}

float bitcoinAPesos(float bitcoin, float valorBitcoin){
    float resultado;

    resultado = bitcoin * valorBitcoin;

    return resultado;
}

float pesosABitcoin(float pesos, float valorPesos){
    float resultado;

    if(valorPesos != 0){
    	resultado = pesos / valorPesos;

    }

    return resultado;
}

float calcularPrecioUnitario(float pesos, float km){
    float resultado;

    if(km != 0){
    	resultado = pesos / km;
    }

    return resultado;
}

float calcularDiferencia(float valorUno, float valorDos){
    float resultado;

    resultado = valorUno - valorDos;

    if(resultado < 0){
    	resultado = resultado * (-1);
    }

    return resultado;
}
