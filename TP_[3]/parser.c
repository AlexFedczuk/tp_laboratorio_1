#include "parser.h"

int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger)
{
    int retorno = -1;

    char auxId[50];
    int id;
    char auxNombre[50];
    char auxApellido[50];
    char auxPrecio[50];
    char auxTipoPasajero[50];
    char auxCodigoVuelo[50];
    char auxEstadoVuelo[50];
    Passenger* pPasajero;
    
    if(pFile != NULL && pArrayListPassenger != NULL){
    	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxTipoPasajero,auxCodigoVuelo,auxEstadoVuelo);
        do{
        	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);

        	if(ll_len(pArrayListPassenger) >= 1){
        	  	id = Passenger_CalcularMaximoID(pArrayListPassenger);
        	}else{
        	  	id = 1;
        	}
        	pPasajero = Passenger_newParametrosCompletos(id, auxNombre, auxApellido, auxPrecio, auxTipoPasajero, auxCodigoVuelo,auxEstadoVuelo);
        	//printf("pasajero->precio = %f\n", pPasajero->precio);
        	ll_add(pArrayListPassenger, pPasajero);
        	//printf("despues de ll_add pasajero->precio = %f\n", pPasajero->precio);
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
    int bandera = 0;
    int id;
    Passenger* pPasajero;
    
    if(pFile != NULL && pArrayListPassenger != NULL){
        do{
            pPasajero = Passenger_new();
            if(pPasajero != NULL){
               if(fread(pPasajero, sizeof(Passenger), 1, pFile)){
            	   if(bandera != 0){
            		   if(ll_len(pArrayListPassenger) >= 1){
            			   id = Passenger_CalcularMaximoID(pArrayListPassenger);
            		   }else{
            			   id = 1;
            		   }
            		   Passenger_setId(pPasajero, id);
            	       ll_add(pArrayListPassenger, pPasajero);
            	   }else{
            		   bandera = 1;
            	   }
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


    int tam;
    int auxId;
    char auxNombre[50];
    char auxApellido[50];
    float auxPrecio = -1;
    char auxCodigoVuelo[4];
    int auxTipoPasajero;
    char tipoPasajeroChar[50];
    int auxEstadoVuelo;
    char estadoVueloChar[50];
    
    Passenger* pPasajero;

    if(pFile != NULL && pArrayListPassenger != NULL){
            tam = ll_len(pArrayListPassenger);
            
            fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
            for(int i = 0; i < tam; i++){
            	//printf("\nentro 2, i = (%d)\n", i);
                pPasajero = ll_get(pArrayListPassenger, i);
                


                Passenger_getId(pPasajero, &auxId);
                Passenger_getNombre(pPasajero, auxNombre);
                Passenger_getApellido(pPasajero, auxApellido);
                Passenger_getPrecio(pPasajero, &auxPrecio);
                //auxPrecio = pPasajero->precio; /* Al parecer el error entre campos se debia al archivo original. 06-06-2022*/
                Passenger_getCodigoVuelo(pPasajero, auxCodigoVuelo);
                Passenger_getTipoPasajero(pPasajero, &auxTipoPasajero);
                Passenger_getEstadoVuelo(pPasajero, &auxEstadoVuelo);
                
                if(auxTipoPasajero == 0){
                    strcpy(tipoPasajeroChar, "FirstClass");
                }else{
                    if(auxTipoPasajero == 1){
                        strcpy(tipoPasajeroChar, "ExecutiveClass");
                    }else{
                        if(auxTipoPasajero == 2){
                            strcpy(tipoPasajeroChar, "EconomyClass");
                        }else{
                            strcpy(tipoPasajeroChar, " ");
                        }
                    }
                }
                
                if(auxEstadoVuelo == 0){
                    strcpy(estadoVueloChar, "Aterrizado");
                }else{
                    if(auxEstadoVuelo == 1){
                        strcpy(estadoVueloChar, "En Horario");
                    }else{
                        if(auxEstadoVuelo == 2){
                            strcpy(estadoVueloChar, "En Vuelo");
                        }else{
                            strcpy(estadoVueloChar, " ");
                        }
                    }
                }
                
                fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, tipoPasajeroChar, estadoVueloChar);
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
