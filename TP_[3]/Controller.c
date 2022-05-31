#include "Controller.h"

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

int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    Passenger* pPasajero; // warning: variable 'pPasajero' set but not used
    char auxNombre[50];
    char auxApellido[50];
    char auxPrecio[50];
    char auxCodigoVuelo[4];
    char auxTipoPasajero[50];
    char auxEstadoVuelo[50];
    
    /*printf("\nIngrese el nombre del pasajero: ");
    myGets(name, NAMES_LEN);*/
    
    if(pArrayListPassenger != NULL){
        if(ll_len(pArrayListPassenger) == 1)
        {
            // Si hay solo UN pasajero en la lista agarro su ID y el nueo ID va a ser = ´id de UNICO pasajero´ + 1.
        }else{
            if(ll_len(pArrayListPassenger) > 1){
                // Calculo cual es el ID mas grande y hago que el nuevo ID sea = ´el mas grande´ + 1.
            }else{
                // Si va a ser el PRIMER pasajero de la lista, hago que el ID sea = 1.
            	pPasajero = Passenger_newParametrosCompletos("1",auxNombre,auxApellido,auxPrecio,auxTipoPasajero,auxCodigoVuelo,auxEstadoVuelo);
            }
        }
        
        retorno = 0;
    }else{
        printf("\nERROR! Sucedio algo en el controlador 02: 'controller_addPassenger'...\n");
    }
    
    return retorno;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    
    if(pArrayListPassenger != NULL){
        retorno = 0;
    }else{
        printf("\nERROR! Sucedio algo en el controlador 02: 'controller_editPassenger'...\n");
    }
    
    return retorno;
}

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int idIngresado;
    int indice;
    // Passenger* Pasajero;
    
    if(pArrayListPassenger != NULL){
    	Passenger_ListPasajeros(pArrayListPassenger);
        getNumeroInt(&idIngresado, "Ingrese el ID del pasajero que quiere remover de la lista: ", "\nError! Valor ingresado invalido!\n", 1, ll_len(pArrayListPassenger), 0, BUFFER_SIZE);
        indice = ll_indexOf(pArrayListPassenger, &idIngresado);
        // Pasajero = (Passenger*) ll_get(pArrayListPassenger, indice);
        ll_remove(pArrayListPassenger, indice);
        retorno = 0;
    }else{
        printf("\nERROR! Sucedio algo en el controlador 02: 'controller_removePassenger'...\n");
    }
    
    return retorno;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    
    if(pArrayListPassenger != NULL){
    	Passenger_ListPasajeros(pArrayListPassenger);
        retorno = 0;
    }else{
        printf("\nERROR! Sucedio algo en el controlador 02: 'controller_ListPassenger'...\n");
    }
    
    return retorno;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int order;
    
    if(pArrayListPassenger != NULL){
        getNumeroInt(&order, "\nIngrese que tipo de orden quiere que se muestre la lista A a Z (0) o Z a A (1): ", "\nError! Valor ingresado invalido!\n", 0, 1, 0, BUFFER_SIZE);
        ll_sort(pArrayListPassenger, Passenger_CompareByName, order);
        retorno = 0;
    }else{
        printf("\nERROR! Sucedio algo en el controlador 02: 'controller_sortPassenger'...\n");
    }
    
    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    FILE* pFile;
    
    if(path != NULL){
        pFile = fopen(path, "w");
        if(pFile != NULL && pArrayListPassenger != NULL){
            parser_PassengerToText(pFile, pArrayListPassenger);
        }
        fclose(pFile);
        retorno = 0;
    }else{
        printf("\nERROR! Sucedio algo en el controlador 02: 'controller_saveAsText'...\n");
    }
    
    return retorno;
}

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
    }else{
        printf("\nERROR! Sucedio algo en el controlador 02: 'controller_saveAsBinary'...\n");
    }
    
    return retorno;
}
