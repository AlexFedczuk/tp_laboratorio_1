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
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
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
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
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
    
    if(pArrayListPassenger != NULL){
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
    
    if(pArrayListPassenger != NULL){
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
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    
    if(path != NULL && pArrayListPassenger != NULL){
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
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    
    if(path != NULL && pArrayListPassenger != NULL){
        retorno = 0;
    }
    
    return retorno;
}
