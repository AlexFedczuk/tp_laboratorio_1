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
#include "inputFuntions.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[50]; // Lo modifique, ya que no entraban la cantidad de caracteres que figuraban en el archivo.scv, [4].
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

//int Passenger_pedirDatosPasajero(LinkedList* pArrayListPassenger, char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr);

/** \brief Se encarga de pedir los datos del pasajero necesesarios para darlo de alta..
 *
 * \param char* respuesta, La direccion de memoria donde esta la respuesta para cargar otro pasajero o no.
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_pedirDatosPasajero(LinkedList* pArrayListPassenger, char* respuesta, int* idMaximo);

/** \brief Se encarga de cargar los datos del pasajero a memoria.
 *
 * \param char* idStr, el ID del pasajero.
 * \param char* nombreStr, la direccion de momoria donde esta el nombre del pasajero.
 * \param char* tipoPasajeroStr, la direccion de momoria donde esta el tipo de pasjero que es.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr);

/** \brief Se encarga de cargar los datos completos del pasajero a memoria.
 *
 * \param int id, el ID del pasajero.
 * \param char* nombreStr, la direccion de momoria donde esta el nombre del pasajero.
 * \param char* apellidoStr, la direccion de momoria donde esta el apellido del pasajero.
 * \param char* precioStr, la direccion de momoria donde esta el precio.
 * \param char* tipoPasajeroStr, la direccion de momoria donde esta el tipo de pasjero que es.
 * \param char* codigoVueloStr, la direccion de momoria donde esta el codigo de vuelo.
 * \param char* estadoVueloStr, la direccion de momoria donde esta el estado del vuelo.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
Passenger* Passenger_newParametrosCompletos(int id,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr);

/** \brief Se encarga de cargar los datos completos del pasajero a memoria durante una Alta.
 *
 * \param int id, el ID del pasajero.
 * \param char* nombreStr, la direccion de momoria donde esta el nombre del pasajero.
 * \param char* apellidoStr, la direccion de momoria donde esta el apellido del pasajero.
 * \param char* precioStr, la direccion de momoria donde esta el precio.
 * \param char* tipoPasajeroStr, la direccion de momoria donde esta el tipo de pasjero que es.
 * \param char* codigoVueloStr, la direccion de momoria donde esta el codigo de vuelo.
 * \param char* estadoVueloStr, la direccion de momoria donde esta el estado del vuelo.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_newParametrosCompletosAlta(Passenger* pPasajero,int id,char* nombre,char* apellido,float precio,int tipoPasajero,char* codigoVuelo,int estadoVuelo);

/** \brief Se encarga de eliminar un pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
void Passenger_delete(Passenger* this);

/** \brief Se encarga de "setear" el ID del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param int id, el ID del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_setId(Passenger* this,int id);

/** \brief Se encarga de obtener el ID del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param int id, el ID del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_getId(Passenger* this,int* id);

/** \brief Se encarga de "setear" el nombre del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param char* nombre, el nombre del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_setNombre(Passenger* this,char* nombre);

/** \brief Se encarga de obtener el nombre del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param char* nombre, el nombre del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_getNombre(Passenger* this,char* nombre);

/** \brief Se encarga de modificar el nombre del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_modificarNombre(Passenger* pPasajero);

/** \brief Se encarga de "setear" el apellido del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param char* apellido, el apellido del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_setApellido(Passenger* this,char* apellido);

/** \brief Se encarga de obtener el apellido del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param char* apellido, el apellido del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_getApellido(Passenger* this,char* apellido);

/** \brief Se encarga de modificar el apellido del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_modificarApellido(Passenger* pPasajero);

/** \brief Se encarga de "setear" el codigo de vuelo del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param char* codigoVuelo, el codigo de vuelo del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/** \brief Se encarga de obtener el codigo de vuelo del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param char* codigoVuelo, el codigo de vuelo del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/** \brief Se encarga de modificar el codigo de vuelo del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_modificarCodigoVuelo(Passenger* this);

/** \brief Se encarga de "setear" el tipo de pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param int tipoPasajero, el tipo de pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);

/** \brief Se encarga de obtener el tipo de pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param int* tipoPasajero, el tipo de pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/** \brief Se encarga de modificar el tipo de pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_modificarTipoPasajero(Passenger* pPasajero);

/** \brief Se encarga de "setear" el precio.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param float precio, el precio del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_setPrecio(Passenger* this,float precio);

/** \brief Se encarga de obtener el precio del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param float* precio, el precio del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_getPrecio(Passenger* this,float* precio);

/** \brief Se encarga de modificar el precio del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_modificarTipoPasajero(Passenger* pPasajero);

/** \brief Se encarga de "setear" el isEmpty.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param int isEmpty, el isEmpty del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_setIsEmpty(Passenger* this,int isEmpty);

/** \brief Se encarga de obtener el isEmpty del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param int* isEmpty, el isEmpty del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_getIsEmpty(Passenger* this,int* isEmpty);

/** \brief Se encarga de "setear" el estado de vuelo del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param int estadoVuelo, el estado de vuelo del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 */
int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);

/** \brief Se encarga de obtener el estado de vuelo del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \param int* estadoVuelo, el estado de vuelo del pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 */
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);

/** \brief Se encarga de modificar el estado de vuelo del pasajero.
 *
 * \param Passenger* this, la direccion de memoria donde esta el pasajero.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_modificarEstadoVuelo(Passenger* pPasajero);

/** \brief Se encarga de ordenar por "ID" x elemento (pasajeros) por ejemplo.
 *
 * \param void* pUno, la direccion de memoria de x elemento uno.
 * \param void* pDos, la direccion de memoria de x elemento dos.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_CompareById(void* pUno, void* pDos);

/** \brief Se encarga de ordenar por "nombre" x elemento (pasajeros) por ejemplo.
 *
 * \param void* pUno, la direccion de memoria de x elemento uno.
 * \param void* pDos, la direccion de memoria de x elemento dos.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_CompareByName(void* pUno, void* pDos);

/** \brief Se encarga de ordenar por "apellido" x elemento (pasajeros) por ejemplo.
 *
 * \param void* pUno, la direccion de memoria de x elemento uno.
 * \param void* pDos, la direccion de memoria de x elemento dos.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_CompareByLastName(void* pUno, void* pDos);

/** \brief Se encarga de ordenar por "Precio" x elemento (pasajeros) por ejemplo.
 *
 * \param void* pUno, la direccion de memoria de x elemento uno.
 * \param void* pDos, la direccion de memoria de x elemento dos.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_CompareByPrice(void* pUno, void* pDos);

/** \brief Se encarga de ordenar por "Codigo de Vuelo" x elemento (pasajeros) por ejemplo.
 *
 * \param void* pUno, la direccion de memoria de x elemento uno.
 * \param void* pDos, la direccion de memoria de x elemento dos.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_CompareByFlyCode(void* pUno, void* pDos);

/** \brief Se encarga de ordenar por "Tipo de Pasajero" x elemento (pasajeros) por ejemplo.
 *
 * \param void* pUno, la direccion de memoria de x elemento uno.
 * \param void* pDos, la direccion de memoria de x elemento dos.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_CompareByTypePassenger(void* pUno, void* pDos);

/** \brief Se encarga de ordenar por "Estado del Vuelo" x elemento (pasajeros) por ejemplo.
 *
 * \param void* pUno, la direccion de memoria de x elemento uno.
 * \param void* pDos, la direccion de memoria de x elemento dos.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Passenger_CompareByStatusFlight(void* pUno, void* pDos);

/** \brief Lista los pasajeros de la linkedlist.
 *
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - El numero del ID mas grande si Ok.
 *
 */
int Passenger_ListPasajeros(LinkedList* pArrayListPassenger);

/** \brief Calcula el ID mas grande de todos los pasajeros en la lista.
 *
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - El numero del ID mas grande si Ok.
 *
 */
int Passenger_CalcularMaximoID(LinkedList* pArrayListPassenger);

/** \brief Obtiene el indice del pasajero indicado.
 *
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \param int* indice, La direccion de memoria donde se encuentra el indice.
 * \param mensaje, el mensaje que se mostrara por consola.
 * \return Devuelve (-1) si hubo un parametro invalido - El numero del ID mas grande si Ok.
 *
 */
int Passenger_getIndicePasajero(LinkedList* pArrayListPassenger, int* indice, char* mensaje);

/** \brief Modifica x dato del pasajero.
 *
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \param int indice, el indice donde esta el pasajero a modificar.
 * \return Devuelve (-1) si hubo un parametro invalido - El numero del ID mas grande si Ok.
 *
 */
int Passenger_modificarPasajero(LinkedList* pArrayListPassenger, int indice);

#endif /* PASSENGER_H_ */
