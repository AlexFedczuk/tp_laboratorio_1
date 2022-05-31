#include "parser.h"

int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    char auxId[50];
    char auxNombre[50];
    char auxApellido[50];
    char auxPrecio[50];
    char auxTipoPasajero[50];
    char auxCodigoVuelo[4];
    char auxEstadoVuelo[50];
    Passenger* pPasajero;
    
    if(pFile != NULL && pArrayListPassenger != NULL){
        do{
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxTipoPasajero,auxCodigoVuelo,auxEstadoVuelo);
            
            pPasajero = Passenger_newParametrosCompletos(auxId, auxNombre, auxApellido, auxPrecio, auxTipoPasajero, auxCodigoVuelo,auxEstadoVuelo);
            
            ll_add(pArrayListPassenger, pPasajero);
        }while(!feof(pFile));
        retorno = 0;
    }else{
        printf("\nERROR! Sucedio algo en el parser 01: 'parser_PassengerFromText'...\n");
    }
    return retorno;
}

int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    Passenger* pPasajero;
    Passenger* pAuxPasajero; // warning: unused variable 'pAuxPasajero'
    
    if(pFile != NULL && pArrayListPassenger != NULL){
        do{
            pPasajero = Passenger_new();
            if(pPasajero != NULL){
               if(fread(pPasajero, sizeof(Passenger), 1, pFile)){
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

int parser_PassengerToText(FILE* pFile, LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    Passenger* pPasajero;
    int tam;
    int auxId;
    char auxNombre[50];
    char auxApellido[50];
    float auxPrecio;
    char auxCodigoVuelo[4];
    int auxTipoPasajero;
    int auxEstadoVuelo;
    
    if(pFile != NULL && pArrayListPassenger != NULL){
            tam = ll_len(pArrayListPassenger);
            
            fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight");
            for(int i = 0; i < tam; i++){
                pPasajero = ll_get(pArrayListPassenger, i);
                
                Passenger_getId(pPasajero, &auxId);
                Passenger_getNombre(pPasajero, auxNombre);
                Passenger_getApellido(pPasajero, auxApellido);
                Passenger_getPrecio(pPasajero, &auxPrecio);
                Passenger_getCodigoVuelo(pPasajero, auxCodigoVuelo);
                Passenger_getTipoPasajero(pPasajero, &auxTipoPasajero);
                Passenger_getEstadoVuelo(pPasajero, &auxEstadoVuelo);
                
                fprintf(pFile,"%d,%s,%s,%f,%s,%d,%d", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
            }
        retorno = 0;
    }else{
        printf("\nERROR! Sucedio algo en el parser 01: 'parser_PassengerToText'...\n");
    }
    return retorno;
}

int parser_PassengerToBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int tam;
    Passenger* pPasajero;
    
    if(pFile != NULL && pArrayListPassenger != NULL){
            tam = ll_len(pArrayListPassenger);
            for(int i = 0; i < tam; i++){
                pPasajero = ll_get(pArrayListPassenger, i);
                fwrite(pPasajero, sizeof(Passenger), 1, pFile);
            }
        retorno = 0;
    }else{
        printf("\nERROR! Sucedio algo en el parser 01: 'parser_PassengerToBinary'...\n");
    }
    
    return retorno;
}









