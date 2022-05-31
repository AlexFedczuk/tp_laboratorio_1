/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int estadoVuelo;
	int isEmpty;

}Passenger;

/** \brief Reserva en memoria un espacio del tamanio de sizeof(Passenger).
 *
 * \param
 * \return Devuelve el resultado que devuelve malloc NULL o la direccion de memoria reservada.
 *
 */
Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr);
Passenger* Passenger_newParametrosCompletos(char* idStr,
											char* nombreStr,
											char* apellidoStr,
											char* precioStr,
											char* tipoPasajeroStr,
											char* codigoVueloStr,
											char* estadoVueloStr);

// Aca le agrego el parametro de el puntero a donde apunta la entidad que quiero borrar.
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setIsEmpty(Passenger* this,int isEmpty);
int Passenger_getIsEmpty(Passenger* this,int* isEmpty);

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);

// Va a trabajar con direcciones de memoria para comparar los datos.
int Passenger_CompareByName(void* pUno, void* pDos);
int Passenger_CompareById(void* pUno, void* pDos);

int Passenger_ListPasajeros(LinkedList* pArrayListPassenger);

#endif /* PASSENGER_H_ */
