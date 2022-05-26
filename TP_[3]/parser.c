#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*, La direccion de memoria donde se encuentra el archivo.
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    char auxId[50];
    char auxNombre[50];
    char auxApellido[50];
    char auxPrecio[50];
    char auxTipoPasajero[50];
    char auxCodigoVuelo[50];
    Passenger* pPasajero;
    
    if(pFile != NULL && pArrayListPassenger != NULL){
        do{
            fscanf("%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxTipoPasajero,auxCodigoVuelo);
            
            pPasajero = Passenger_newParametrosCompletos(auxId, auxNombre, auxApellido, auxPrecio, auxTipoPasajero, auxCodigoVuelo);
            
            ll_add(pArrayListPassenger, pPasajero);
        }while(!feof(pFile));
        retorno = 0;
    }else{
        printf("\nERROR! Sucedio algo en el parser 01: 'parser_PassengerFromText'...\n");
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*, La direccion de memoria donde se encuentra el archivo.
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    Passenger* pPasajero;
    Passenger* pAuxPasajero;
    
    if(pFile != NULL && pArrayListPassenger != NULL){
        do{
            pPasajero = Passenger_new();
            if(pPasajero != NULL){
               if(fread(pasajero, sizeof(Passenger), 1, pFile)){
                   ll_add(pArrayListPassenger, pPasajero);
               }
            }else{
                printf("\nERROR! No se pudo conseguir memoria para agregar otro pasajero!\n");
            }
        }while(!feof(pFile));
        retorno = 0;
    }else{
        printf("\nERROR! Sucedio algo en el parser 01: 'parser_PassengerFromBinary'...\n");
    }
    return retorno;
}









