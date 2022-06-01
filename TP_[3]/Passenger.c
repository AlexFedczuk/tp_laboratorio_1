/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*, La direccion de memoria donde se encuentra el nombre del archivo.
 * \param pArrayListPassenger LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */

Passenger* Passenger_new(){
    return malloc(sizeof(Passenger));
}

int Passenger_pedirDatosPasajero(LinkedList* pArrayListPassenger, char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr){
    int retorno = -1;
    int auxIdInt = 1;
    float auxPrecioFloat;
    int auxTipoPasajeroInt;
    int auxEstadoVueloInt;
    
    if(idStr != NULL &&	nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && estadoVueloStr != NULL){
        if(strcmp(idStr, "1") != 0){
            auxIdInt = Passenger_CalcularMaximoID(pArrayListPassenger);
        }
        PedirNombre("\nIngrese el nombre del pasajero: ", nombreStr, 50);
        fflush(stdin);
        PedirNombre("\nIngrese el apellido del pasajero: ", apellidoStr, 50);
        fflush(stdin);
        getNumeroFloat(&auxPrecioFloat, "\nIngrese el precio: ", "\nError! Valor ingresado invalido!\n", 0, 999999999, 0, BUFFER_SIZE);
        fflush(stdin);
        getNumeroInt(&auxTipoPasajeroInt, "\nIngrese tipo de pasajero 'falta nombre'(0), 'falta nombre'(1) o 'falta nombre'(2): ", "\nError! Valor ingresado invalido!\n", 0, 2, 0, BUFFER_SIZE);
        fflush(stdin);
        printf("\nIngrese el codigo de vuelo: ");
        myGets(codigoVueloStr, 4);
        fflush(stdin);
        getNumeroInt(&auxEstadoVueloInt, "\nIngrese el estado el vuelo ´falta nombre´(0), ´falta nombre´(1) o ´falta nombre´(2): ", "\nError! Valor ingresado invalido!\n", 0, 2, 0, BUFFER_SIZE);
        fflush(stdin);
        
        itoa(auxIdInt,idStr,50);
        gcvt(auxPrecioFloat, 50, precioStr);
        itoa(auxTipoPasajeroInt,tipoPasajeroStr,50);
        itoa(auxEstadoVueloInt,estadoVueloStr,50);
        
        retorno = 0;
    }
    
    return retorno;
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
Passenger* Passenger_newParametrosCompletos(char* idStr,
											char* nombreStr,
											char* apellidoStr,
											char* precioStr,
											char* tipoPasajeroStr,
											char* codigoVueloStr,
											char* estadoVueloStr){
	Passenger* unPasajero = NULL;
	Passenger* auxPasajero;

	auxPasajero = (Passenger*) malloc(sizeof(Passenger));

	if(idStr != NULL &&
			nombreStr != NULL &&
			apellidoStr != NULL &&
			precioStr != NULL &&
			tipoPasajeroStr != NULL &&
			codigoVueloStr != NULL &&
			estadoVueloStr != NULL &&
			auxPasajero != NULL){
		unPasajero = auxPasajero;

        Passenger_setId(unPasajero, atoi(idStr));
        Passenger_setNombre(unPasajero, nombreStr);
        Passenger_setApellido(unPasajero, apellidoStr);
        Passenger_setPrecio(unPasajero, atof(precioStr));
        Passenger_setTipoPasajero(unPasajero, atoi(tipoPasajeroStr));
        Passenger_setCodigoVuelo(unPasajero, codigoVueloStr);
        Passenger_setEstadoVuelo(unPasajero, atoi(estadoVueloStr));
        Passenger_setIsEmpty(unPasajero, 0);
	}

	return unPasajero;
}

void Passenger_delete(Passenger* this){
    
    if(this != NULL){
        free(this);
    }
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

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo){
    int retorno = -1;

    if(this != NULL){
        this->estadoVuelo = estadoVuelo;
        retorno = 0;
    }
    return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo){
    int retorno = -1;

    if(this != NULL){
        *estadoVuelo = this->estadoVuelo;
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

int Passenger_ListPasajeros(LinkedList* pArrayListPassenger){
    int retorno = -1;
    int tam; // Saque el tam del for, porque estoy testeando con unos pocos pasajeros.
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
        
        
        printf("  id,           name,       lastname,        price,         flycode, typePassenger, statusFlight\n");
        for(int i = 0; i < 50; i++){
            pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
            
            Passenger_getId(pPasajero, &auxId);
            Passenger_getNombre(pPasajero, auxNombre);
            Passenger_getApellido(pPasajero, auxApellido);
            Passenger_getPrecio(pPasajero, &auxPrecio);
            Passenger_getCodigoVuelo(pPasajero, auxCodigoVuelo);
            Passenger_getTipoPasajero(pPasajero, &auxTipoPasajero);
            Passenger_getEstadoVuelo(pPasajero, &auxEstadoVuelo);
            Passenger_getIsEmpty(pPasajero, &auxIsEmpty);
            
            if(/*auxIsEmpty != 0*/auxId > 0){
                printf("%04d,%15s,%15s,   %10.2f,  %14s,             %1d,            %1d\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
            }
        }
        retorno = 0;
    }
    
    return retorno;
}

int Passenger_CalcularMaximoID(LinkedList* pArrayListPassenger){
    int retorno = -1;
    int len;
    int idMax;
    int auxId;
    int auxIsEmpty;
    Passenger* pPasajero;
    
    if(pArrayListPassenger != NULL){
        len = ll_len(pArrayListPassenger);
        
        for(int i = 0; i < len; i++){
            pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
            
            Passenger_getId(pPasajero, &auxId);
            Passenger_getIsEmpty(pPasajero, &auxIsEmpty);
            if(auxIsEmpty == 0){
                if(i == 0 || idMax < auxId){
                    idMax = auxId;
                }
            }
        }
        retorno = idMax;
    }
    return retorno;
}

int Passenger_getIndicePasajero(LinkedList* pArrayListPassenger, int* indice, char* mensaje){
	int retorno = -1;
	int idIngresado, len, auxId;
	Passenger* pPasajero;

	if(pArrayListPassenger != NULL && indice != NULL && mensaje != NULL){
		len = ll_len(pArrayListPassenger);
		getNumeroInt(&idIngresado, mensaje, "\nError! Valor ingresado invalido!\n", 1, len, 0, BUFFER_SIZE);

		for(int i = 0; i < len; i++){
			pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_getId(pPasajero, &auxId);
			if(auxId == idIngresado){
				retorno = 0;
				break;
			}
		}
		*indice = ll_indexOf(pArrayListPassenger, pPasajero);
	}

	return retorno;
}
