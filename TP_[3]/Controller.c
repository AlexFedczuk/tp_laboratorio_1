#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*, La direccion de memoria donde se encuentra el nombre del archivo.
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    FILE* pArchivo;
    
    if(path != NULL){
        pArchivo = fopen(path, "r");
        
        if(pArchivo != NULL && pArrayListPassenger != NULL){
            parser_PassengerFromText(pArchivo, pArrayListPassenger);
            retorno = 0;
        }else{
            printf("\nERROR! Sucedio algo en el controlador 01: 'controller_loadFromText'...\n");
        }
        
        fclose(pArchivo);
    }else{
        printf("\nERROR! Sucedio algo en el controlador 02: 'controller_loadFromText'...\n");
    }
    
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*, La direccion de memoria donde se encuentra el nombre del archivo..
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    FILE* pArchivo;
    
    if(path != NULL){
        pArchivo = fopen(path, "rb");
        
        if(pArchivo != NULL && pArrayListPassenger != NULL){
            parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
            retorno = 0;
        }else{
            printf("\nERROR! Sucedio algo en el controlador 01: 'controller_loadFromBinary'...\n");
        }
        
        fclose(pArchivo);
    }else{
        printf("\nERROR! Sucedio algo en el controlador 02: 'controller_loadFromBinary'...\n");
    }
    
    return retorno;
}

/** \brief Alta de pasajero
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    
    if(pArrayListPassenger != NULL){
        retorno = 0;
    }
    
    return retorno;
}

/** \brief Modificar datos de pasajero
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    
    if(pArrayListPassenger != NULL){
        retorno = 0;
    }
    
    return retorno;
}

/** \brief Baja de pasajero
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int idIngresado;
    int indice;
    // Passenger* Pasajero;
    
    if(pArrayListPassenger != NULL){
        ListPassengers(pArrayListPassenger);
        getNumeroInt(&idIngresado, "Ingrese el ID del pasajero que quiere remover de la lista: ", "\nError! Valor ingresado invalido!\n", 1, ll_len(pArrayListPassenger), 0, BUFFER_SIZE);
        indice = ll_indexOf(pArrayListPassenger, &idIngresado);
        // Pasajero = (Passenger*) ll_get(pArrayListPassenger, indice);
        ll_remove(pArrayListPassenger, indice);
        retorno = 0;
    }
    
    return retorno;
}

/** \brief Listar pasajeros
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    
    if(pArrayListPassenger != NULL){
        ListPassengers(pArrayListPassenger);
        retorno = 0;
    }
    
    return retorno;
}

/** \brief Ordenar pasajeros
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int order;
    
    if(pArrayListPassenger != NULL){
        getNumeroInt(&order, "\nIngrese que tipo de orden quiere que se muestre la lista A a Z (0) o Z a A (1): ", "\nError! Valor ingresado invalido!\n", 0, 1, 0, BUFFER_SIZE);
        ll_sort(listaPasajeros, Passenger_CompareByName, order);
        retorno = 0;
    }
    
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*, La direccion de memoria donde se encuentra el nombre del archivo.
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int len;
    FILE* pFile;
    
    if(path != NULL){
        pFile = fopen(path, "w");
        if(pFile != NULL && pArrayListPassenger != NULL){
            parser_PassengerToText(pFile, pArrayListPassenger);
        }
        fclose(pFile);
        retorno = 0;
    }
    
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*, La direccion de memoria donde se encuentra el nombre del archivo.
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    FILE* pFile;
    
    if(path != NULL){
        pFile = fopen(path, "wb");
        if(pFile != NULL && pArrayListPassenger != NULL){
            parser_PassengerToBinary(pFile, pArrayListPassenger);
        }
        fclose(pFile);
        retorno = 0;
    }
    
    return retorno;
}
