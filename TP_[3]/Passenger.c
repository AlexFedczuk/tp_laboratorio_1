/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*, La direccion de memoria donde se encuentra el nombre del archivo.
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */

/** \brief Reserva en memoria un espacio del tamanio de sizeof(Passenger).
 *
 * \param 
 * \return Devuelve el resultado que devuelve malloc NULL o la direccion de memoria reservada.
 *
 */
Passenger* Passenger_new(){
    return malloc(sizeof(Passenger));
}

/** \brief Guarda los datos pasados por parametros en la entidad Passenger que se este tratando.
 *
 * \param char* idStr, La direccion de memoria donde se encuentra el ID del pasajero.
 * \param char* nombreStr, La direccion de memoria donde se encuentra el nombre del pasajero.
 * \param char* tipoPasajeroStr, La direccion de memoria donde se encuentra el tipo de pasajero del pasajero.
 * \return Devuelve (NULL) si hubo un parametro invalido - la direccion de memoria reservada si Ok.
 *
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr){
	Passenger* unPasajero = NULL;
	Passenger* auxPasajero;

	auxPasajero = Passenger_new();

	if(idStr != NULL && nombreStr != NULL && tipoPasajeroStr != NULL && auxPasajero != NULL){
		unPasajero = auxPasajero;

		unPasajero->id = atoi(idStr);
		strcpy(unPasajero->nombre, nombreStr);
		unPasajero->tipoPasajero = atoi(tipoPasajeroStr);
	}

	return unPasajero;
}

/** \brief Guarda los datos pasados por parametros en la entidad Passenger que se este tratando.
 *
 * \param char* idStr, La direccion de memoria donde se encuentra el ID del pasajero.
 * \param char* nombreStr, La direccion de memoria donde se encuentra el nombre del pasajero.
 * \param char* tipoPasajeroStr, La direccion de memoria donde se encuentra el tipo de pasajero del pasajero.
 * \return Devuelve (NULL) si hubo un parametro invalido - la direccion de memoria reservada si Ok.
 *
 */
Passenger* Passenger_newParametrosCompletos(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr){
	Passenger* unPasajero = NULL;
	Passenger* auxPasajero;

	auxPasajero = (Passenger*) malloc(sizeof(Passenger));

	if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && auxPasajero != NULL){
		unPasajero = auxPasajero;

        Passenger_setId(unPasajero, atoi(idStr));
        Passenger_setNombre(unPasajero, nombreStr);
        Passenger_setApellido(unPasajero, apellidoStr);
        Passenger_setPrecio(unPasajero, atof(precioStr));
        Passenger_setTipoPasajero(unPasajero, atoi(tipoPasajeroStr));
        Passenger_setCodigoVuelo(unPasajero, codigoVueloStr);
        Passenger_setIsEmpty(unPasajero, 0);
	}

	return unPasajero;
}

void Passenger_delete(Passenger* this){
    int retorno = -1;
    
    if(this != NULL){
        free(this);
        retorno = 0;
    }
    
    return retorno;
}

int Passenger_setId(Passenger* this,int id){
    int retorno = -1;
    
    if(this != NULL){
        this->id = id;
    }
    return retorno;
}
int Passenger_getId(Passenger* this,int* id){
    int retorno = -1;
    
    if(this != NULL){
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre){
    int retorno = -1;
    
    if(this != NULL){
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre){
    int retorno = -1;
    
    if(this != NULL){
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido){
    int retorno = -1;
    
    if(this != NULL){
        strcpy(this->apellido, apellido);
        retorno = 0;
    }
    return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido){
    int retorno = -1;
    
    if(this != NULL){
        strcpy(apellido, this->apellido);
        retorno = 0;
    }
    return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
    int retorno = -1;
    
    if(this != NULL){
        strcpy(this->codigoVuelo, codigoVuelo);
        retorno = 0;
    }
    return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
    int retorno = -1;
    
    if(this != NULL){
        strcpy(codigoVuelo, this->codigoVuelo);
        retorno = 0;
    }
    return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
    int retorno = -1;
    
    if(this != NULL){
        this->tipoPasajero = tipoPasajero;
        retorno = 0;
    }
    return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
    int retorno = -1;
    
    if(this != NULL){
        *tipoPasajero = this->tipoPasajero;
        retorno = 0;
    }
    return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio){
    int retorno = -1;
    
    if(this != NULL){
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio){
    int retorno = -1;
    
    if(this != NULL){
        *precio = this->precio;
        retorno = 0;
    }
    return retorno;
}

int Passenger_setIsEmpty(Passenger* this,int isEmpty){
    int retorno = -1;
    
    if(this != NULL){
        this->isEmpty = isEmpty;
        retorno = 0;
    }
    return retorno;
}
int Passenger_getIsEmpty(Passenger* this,int* isEmpty){
    int retorno = -1;
    
    if(this != NULL){
        *isEmpty = this->isEmpty;
        retorno = 0;
    }
    return retorno;
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

int ListPassengers(LinkedList* pArrayListPassenger){
    int retorno = -1;
    int tam;
    Passenger* pPasajero;
    int auxId;
    char auxNombre[50];
    char auxApellido[50];
    float auxPrecio;
    char auxCodigoVuelo[4];
    int auxTipoPasajero;
    int auxEstadoVuelo;
    int auxIsEmpty;
    
    if(pArrayListPassenger != NULL){
        tam = ll_len(pArrayListPassenger);
        
        
        printf("id,name,lastname,price,flycode,typePassenger,statusFlight\n");
        for(int i = 0; i < tam; i++){
            pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
            
            Passenger_getId(pPasajero, &auxId);
            Passenger_getNombre(pPasajero, auxNombre);
            Passenger_getApellido(pPasajero, auxApellido);
            Passenger_getPrecio(pPasajero, &auxPrecio);
            Passenger_getCodigoVuelo(pPasajero, auxCodigoVuelo);
            Passenger_getTipoPasajero(pPasajero, &auxTipoPasajero);
            Passenger_getEstadoVuelo(pPasajero, &auxEstadoVuelo);
            Passenger_getIsEmpty(pPasajero, &auxIsEmpty);
            
            if(auxIsEmpty != 0){
                printf("%d,%s,%s,%.2f,%s,%d,%d\n", id, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
            }
        }
        retorno = 0;
    }
    
    return retorno;
}
