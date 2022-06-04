#include "Controller.h"

int controller_loadFromText(char* path, LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    FILE* pArchivo;
    
    if(path != NULL && RevisarFormatoArchivo(path) == 0){
        pArchivo = fopen(path, "r");
        
        if(pArchivo != NULL && pArrayListPassenger != NULL){
            parser_PassengerFromText(pArchivo, pArrayListPassenger);
            //printf("pasajero->precio = %f\n", pArrayListPassenger->precio);
            printf("\nSe a cargado el archivo tipo texto.\n");
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
    
    if(path != NULL && RevisarFormatoArchivo(path) == 1){
        pArchivo = fopen(path, "rb");
        
        if(pArchivo != NULL && pArrayListPassenger != NULL){
            parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
            printf("\nSe a cargado el archivo tipo binario.\n");
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
    char respuesta;
    if(pArrayListPassenger != NULL){
    	do{
    		Passenger_pedirDatosPasajero(pArrayListPassenger, &respuesta);
    	}while(respuesta != 'n');

    }else{
        printf("\nERROR! Sucedio algo en el controlador 02: 'controller_addPassenger'...\n");
    }

    return retorno;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int indice = -1;
    
    if(pArrayListPassenger != NULL){
        Passenger_ListPasajeros(pArrayListPassenger);
        Passenger_getIndicePasajero(pArrayListPassenger, &indice, "Ingrese el ID del pasajero que quiere modificar de la lista: ");
        Passenger_modificarPasajero(pArrayListPassenger, indice);
        
        retorno = 0;
    }else{
        printf("\nERROR! Sucedio algo en el controlador 02: 'controller_editPassenger'...\n");
    }
    
    return retorno;
}

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int indice = -1;
    
    if(pArrayListPassenger != NULL){
    	Passenger_ListPasajeros(pArrayListPassenger);
    	Passenger_getIndicePasajero(pArrayListPassenger, &indice, "Ingrese el ID del pasajero que quiere remover de la lista: ");
        ll_remove(pArrayListPassenger, indice);
        printf("\nSe a dado de baja el Pasajero indicado.\n");
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
        getNumeroInt(&order, "\nIngrese que tipo de orden quiere que se muestre la lista A a Z (1) o Z a A (0): ", "\nError! Valor ingresado invalido!\n", 0, 1, 0, BUFFER_SIZE);
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
        printf("\nSe a guardado el archivo como texto.\n");
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
        printf("\nSe a guardado el archivo como binario.\n");
        retorno = 0;
    }else{
        printf("\nERROR! Sucedio algo en el controlador 02: 'controller_saveAsBinary'...\n");
    }
    
    return retorno;
}

void controller_exit(LinkedList* pArrayListPassenger, int option, int bandera, char* arch){
    if(option == 10 && bandera == 1){
        printf("\nERROR! Para poder salir del programa debe guardar de alguna forma el archivo '%s'!\n", arch);
    }else{
        if(option == 10 && bandera == 0){
            ll_deleteLinkedList(pArrayListPassenger);
            printf("\nSaliendo del programa...\n");
        }
        
    }
}
