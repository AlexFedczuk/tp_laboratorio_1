/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr){
	Passenger* unPasajero;
	Passenger* auxPasajero;

	auxPasajero = (Passenger*) malloc(sizeof(Passenger));

	if(idStr != NULL && nombreStr != NULL && tipoPasajeroStr != NULL && auxPasajero != NULL){
		unPasajero = auxPasajero;

		unPasajero->id = atoi(idStr);
		strcpy(unPasajero->nombre, nombreStr);
		unPasajero->tipoPasajero = atoi(tipoPasajeroStr);
	}

	return unPasajero;
}

int Passenger_CompareByName(void* pUno, void* pDos){
	int retorno = -2;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		retorno = strcmp(unPasajero->nombre, otroPasajero->nombre);// Esto puede devolver -1 o 0 o 1, segun sea la comparacion de las cadenas...
	}

	return retorno;
}

int Passenger_CompareById(void* pUno, void* pDos){
	int retorno = -2;
	int compara = 0;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		if(unPasajero->nombre > otroPasajero->nombre){
			compara = 1;
		}else{
			if(unPasajero->nombre < otroPasajero->nombre){
				compara = -1;
			}
		}
		retorno = compara;
	}

	return retorno;
}
