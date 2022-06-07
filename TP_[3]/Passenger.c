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

/*int Passenger_pedirDatosPasajero(LinkedList* pArrayListPassenger, char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr){
    int retorno = -1;
    int auxIdInt = 1;
    float auxPrecioFloat;
    int auxTipoPasajeroInt;
    int auxEstadoVueloInt;
    int result;
    
    if(idStr != NULL &&	nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && estadoVueloStr != NULL){
        if(strcmp(idStr, "1") != 0){
            auxIdInt = Passenger_CalcularMaximoID(pArrayListPassenger);
        }
        PedirNombre("\nIngrese el nombre del pasajero: ", nombreStr, 50);
        fflush(stdin);
        printf("\nnombre ingresado = %s", nombreStr);

        PedirNombre("\nIngrese el apellido del pasajero: ", apellidoStr, 50);
        fflush(stdin);
        printf("\napellido ingresado = %s", apellidoStr);

        getNumeroFloat(&auxPrecioFloat, "\nIngrese el precio: ", "\nError! Valor ingresado invalido!\n", 0, 999999999, 0, BUFFER_SIZE);
        fflush(stdin);
        printf("\nprecio ingresado = %f", auxPrecioFloat);

        getNumeroInt(&auxTipoPasajeroInt, "\nIngrese tipo de pasajero 'falta nombre'(0), 'falta nombre'(1) o 'falta nombre'(2): ", "\nError! Valor ingresado invalido!\n", 0, 2, 0, BUFFER_SIZE);
        fflush(stdin);
        printf("\ntipo pasajero ingresado = %d", auxTipoPasajeroInt);

        printf("\nIngrese el codigo de vuelo: ");
        myGets(codigoVueloStr, 4);
        fflush(stdin);
        printf("\ncodigo de vuelo ingresado = %s", codigoVueloStr);

        getNumeroInt(&auxEstadoVueloInt, "\nIngrese el estado el vuelo 'falta nombre'(0), 'falta nombre'(1) o 'falta nombre'(2): ", "\nError! Valor ingresado invalido!\n", 0, 2, 0, BUFFER_SIZE);
        fflush(stdin);
        printf("\ntipo pasajero ingresado = %d", auxEstadoVueloInt);

        printf("\nhasta llego1");
        printf("\nidStr ingresado = %s", idStr);
        printf("\nidInt calculado = %d", auxIdInt);
        //result = sprintf(idStr, "%d", auxIdInt);
        //strcpy(idStr, sprintf(str, "%d", num);); sprintf(idStr,"%d",auxIdInt);
        printf("\nhasta llego3");
        gcvt(auxPrecioFloat, 50, precioStr);
        itoa(auxTipoPasajeroInt,tipoPasajeroStr,10);
        itoa(auxEstadoVueloInt,estadoVueloStr,10);
        printf("\nhasta llego2");
        
        fflush(stdin);

        retorno = 0;
    }

    return retorno;
}*/

int Passenger_pedirDatosPasajero(LinkedList* pArrayListPassenger, char* respuesta, int* idMaximo){
    int retorno = -1;

    int id;
    char nombre[50];
    char apellido[50];
    float precio;
    int tipoPasajero;
    char codigoVuelo[4];
    int estadoVuelo;

    Passenger* pPasajero;
    Passenger* auxPasajero;

    auxPasajero = Passenger_new();

    if(pArrayListPassenger != NULL && auxPasajero != NULL && respuesta != NULL){
    	pPasajero = auxPasajero;

    	id = *idMaximo + 1;
    	*idMaximo = id;

    	PedirNombre("\nIngrese el nombre del pasajero: ", nombre, 50);
    	fflush(stdin);

    	PedirNombre("\nIngrese el apellido del pasajero: ", apellido, 50);
    	fflush(stdin);

    	getNumeroFloat(&precio, "\nIngrese el precio: ", "\nError! Valor ingresado invalido!\n", 0, 999999999, 0, BUFFER_SIZE);
    	fflush(stdin);
        
    	getNumeroInt(&tipoPasajero, "\nIngrese tipo de pasajero 'FirstClass'(0), 'ExecutiveClass'(1) o 'EconomyClass'(2): ", "\nError! Valor ingresado invalido!\n", 0, 2, 0, BUFFER_SIZE);
    	fflush(stdin);

    	printf("\nIngrese el codigo de vuelo: ");
    	myGets(codigoVuelo, 4);
    	fflush(stdin);
    	
    	getNumeroInt(&estadoVuelo, "\nIngrese el estado del vuelo 'Aterrizado'(0), 'En Horario'(1) o 'En Vuelo'(2): ", "\nError! Valor ingresado invalido!\n", 0, 2, 0, BUFFER_SIZE);
    	fflush(stdin);

    	Passenger_newParametrosCompletosAlta(pPasajero,id,nombre,apellido,precio,tipoPasajero,codigoVuelo,estadoVuelo);

    	ll_add(pArrayListPassenger, pPasajero);

    	getUnCaracter(respuesta, "\nQuiere realizar otra Alta? (s/n): ", "\nError! Valor ingresado invalido!\n", 0, BUFFER_SIZE);
    	fflush(stdin);

        retorno = 0;
    }
    
    return retorno;
}

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

Passenger* Passenger_newParametrosCompletos(int id,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr){
	Passenger* unPasajero = NULL;
	Passenger* auxPasajero;

	auxPasajero = (Passenger*) malloc(sizeof(Passenger));

	if(nombreStr != NULL &&	apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && estadoVueloStr != NULL && auxPasajero != NULL){
		unPasajero = auxPasajero;

        Passenger_setId(unPasajero, id);
        Passenger_setNombre(unPasajero, nombreStr);
        Passenger_setApellido(unPasajero, apellidoStr);
        Passenger_setPrecio(unPasajero, atof(precioStr));
        
        //printf("pasajero->precio = %f\n", unPasajero->precio);

        if(strcmp(estadoVueloStr, "Aterrizado") == 0){
            Passenger_setEstadoVuelo(unPasajero, 0);
        }else{
            if(strcmp(estadoVueloStr, "En Horario") == 0){
                Passenger_setEstadoVuelo(unPasajero, 1);
            }else{
                if(strcmp(estadoVueloStr, "En Vuelo") == 0){
                    Passenger_setEstadoVuelo(unPasajero, 2);
                }else{
                    Passenger_setEstadoVuelo(unPasajero, -1);
                }
            }
        }

        Passenger_setCodigoVuelo(unPasajero, codigoVueloStr);

        if(strcmp(tipoPasajeroStr, "FirstClass") == 0){
            Passenger_setTipoPasajero(unPasajero, 0);
        }else{
            if(strcmp(tipoPasajeroStr, "ExecutiveClass") == 0){
                Passenger_setTipoPasajero(unPasajero, 1);
            }else{
                if(strcmp(tipoPasajeroStr, "EconomyClass") == 0){
                    Passenger_setTipoPasajero(unPasajero, 2);
                }else{
                    Passenger_setTipoPasajero(unPasajero, -1);
                }
            }
        }
        Passenger_setIsEmpty(unPasajero, 0);

        //printf("\n\tcodigoVuelo: %s, tipoPasajero: %s (%d)\n",unPasajero->codigoVuelo,tipoPasajeroStr,unPasajero->tipoPasajero);
	}

	return unPasajero;
}

int Passenger_newParametrosCompletosAlta(Passenger* pPasajero,int id,char* nombre,char* apellido,float precio,int tipoPasajero,char* codigoVuelo,int estadoVuelo){
	int retorno = -1;

	if(pPasajero != NULL){
        Passenger_setId(pPasajero, id);
        Passenger_setNombre(pPasajero, nombre);
        Passenger_setApellido(pPasajero, apellido);
        Passenger_setPrecio(pPasajero, precio);
        Passenger_setTipoPasajero(pPasajero, tipoPasajero);
        Passenger_setCodigoVuelo(pPasajero, codigoVuelo);
        Passenger_setEstadoVuelo(pPasajero, estadoVuelo);
        Passenger_setIsEmpty(pPasajero, 0);

        retorno = 0;
	}

	return retorno;
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
int Passenger_modificarNombre(Passenger* pPasajero){
    int retorno = -1;
    char nombre[50];
    
    if(pPasajero != NULL){
        PedirNombre("\n\tIngrese el nuevo nombre del pasajero: ", nombre, 50);
        fflush(stdin);
        Passenger_setNombre(pPasajero, nombre);
        printf("\n\tSe le a modificado el nombre al pasajero seleccionado.\n");
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
int Passenger_modificarApellido(Passenger* pPasajero){
    int retorno = -1;
    char apellido[50];
    
    if(pPasajero != NULL){
        PedirNombre("\n\tIngrese el nuevo apellido del pasajero: ", apellido, 50);
        fflush(stdin);
        Passenger_setApellido(pPasajero, apellido);
        printf("\n\tSe le a modificado el apellido al pasajero seleccionado.\n");
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
int Passenger_modificarCodigoVuelo(Passenger* pPasajero){
    int retorno = -1;
    char codigoVuelo[50];
    
    if(pPasajero != NULL){
        printf("\nIngrese el nuevo codigo de vuelo: ");
        myGets(codigoVuelo, 4);
        fflush(stdin);
        Passenger_setCodigoVuelo(pPasajero, codigoVuelo);
        printf("\n\tSe le a modificado el codigo de vuelo al pasajero seleccionado.\n");
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
int Passenger_modificarTipoPasajero(Passenger* pPasajero){
    int retorno = -1;
    int tipoPasajero;
    
    if(pPasajero != NULL){
        getNumeroInt(&tipoPasajero, "\n\tIngrese el nuevo tipo de pasajero 'FirstClass'(0), 'ExecutiveClass'(1) o 'EconomyClass'(2): ", "\nError! Valor ingresado invalido!\n", 0, 2, 0, BUFFER_SIZE);
        fflush(stdin);
        Passenger_setTipoPasajero(pPasajero, tipoPasajero);
        printf("\n\tSe le a modificado el Tipo de Pasajero.\n");
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
int Passenger_modificarPrecio(Passenger* pPasajero){
    int retorno = -1;
    float precio;
    
    if(pPasajero != NULL){
        getNumeroFloat(&precio, "\n\tIngrese el nuevo precio: ", "\nError! Valor ingresado invalido!\n", 0, 999999999, 0, BUFFER_SIZE);
        fflush(stdin);
        Passenger_setPrecio(pPasajero, precio);
        printf("\n\tSe le a modificado el precio al pasajero seleccionado.\n");
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
int Passenger_modificarEstadoVuelo(Passenger* pPasajero){
    int retorno = -1;
    int estadoVuelo;
    
    if(pPasajero != NULL){
        getNumeroInt(&estadoVuelo, "\nIngrese el nuevo estado del vuelo 'Aterrizado'(0), 'En Horario'(1) o 'En Vuelo'(2): ", "\nError! Valor ingresado invalido!\n", 0, 2, 0, BUFFER_SIZE);
        fflush(stdin);
        Passenger_setEstadoVuelo(pPasajero, estadoVuelo);
        printf("\n\tSe le a modificado el estado de vuelo al pasajero seleccionado.\n");
        retorno = 0;
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

		if(unPasajero->id > otroPasajero->id){
			compara = 1;
		}else{
			if(unPasajero->id < otroPasajero->id){
				compara = -1;
			}
		}
		retorno = compara;
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

int Passenger_CompareByLastName(void* pUno, void* pDos){
	int retorno = -2;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		retorno = strcmp(unPasajero->apellido, otroPasajero->apellido);// Esto puede devolver -1 o 0 o 1, segun sea la comparacion de las cadenas...
	}

	return retorno;
}

int Passenger_CompareByPrice(void* pUno, void* pDos){
	int retorno = -2;
	int compara = 0;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		if(unPasajero->precio > otroPasajero->precio){
			compara = 1;
		}else{
			if(unPasajero->precio < otroPasajero->precio){
				compara = -1;
			}
		}
		retorno = compara;
	}

	return retorno;
}

int Passenger_CompareByFlyCode(void* pUno, void* pDos){
	int retorno = -2;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		retorno = strcmp(unPasajero->codigoVuelo, otroPasajero->codigoVuelo);// Esto puede devolver -1 o 0 o 1, segun sea la comparacion de las cadenas...
	}

	return retorno;
}

int Passenger_CompareByTypePassenger(void* pUno, void* pDos){
	int retorno = -2;
	int compara = 0;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		if(unPasajero->tipoPasajero > otroPasajero->tipoPasajero){
			compara = 1;
		}else{
			if(unPasajero->tipoPasajero < otroPasajero->tipoPasajero){
				compara = -1;
			}
		}
		retorno = compara;
	}

	return retorno;
}

int Passenger_CompareByStatusFlight(void* pUno, void* pDos){
	int retorno = -2;
	int compara = 0;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		if(unPasajero->estadoVuelo > otroPasajero->estadoVuelo){
			compara = 1;
		}else{
			if(unPasajero->estadoVuelo < otroPasajero->estadoVuelo){
				compara = -1;
			}
		}
		retorno = compara;
	}

	return retorno;
}

int Passenger_ListPasajeros(LinkedList* pArrayListPassenger){
    int retorno = -1;
    int tam;
    int auxId;
    char auxNombre[50];
    char auxApellido[50];
    float auxPrecio;
    char auxCodigoVuelo[4];
    int auxTipoPasajero;
    int auxEstadoVuelo;
    int auxIsEmpty;
    char tipoPasajero[50];
    char estadoVuelo[50];
    
    Passenger* pPasajero;

    if(pArrayListPassenger != NULL){
        tam = ll_len(pArrayListPassenger);
        
        
        printf("  id,           name,       lastname,        price,         flycode,               typePassenger,          statusFlight\n\n");
        for(int i = 0; i < tam; i++){
            pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
            
            Passenger_getId(pPasajero, &auxId);
            Passenger_getNombre(pPasajero, auxNombre);
            Passenger_getApellido(pPasajero, auxApellido);
            //Passenger_getPrecio(pPasajero, &auxPrecio);
            auxPrecio = pPasajero->precio;
            Passenger_getCodigoVuelo(pPasajero, auxCodigoVuelo);
            Passenger_getTipoPasajero(pPasajero, &auxTipoPasajero);
            Passenger_getEstadoVuelo(pPasajero, &auxEstadoVuelo);
            Passenger_getIsEmpty(pPasajero, &auxIsEmpty);
            
            if(auxTipoPasajero == 0){
                strcpy(tipoPasajero, "FirstClass");
            }else{
                if(auxTipoPasajero == 1){
                    strcpy(tipoPasajero, "ExecutiveClass");
                }else{
                    if(auxTipoPasajero == 2){
                        strcpy(tipoPasajero, "EconomyClass");
                    }else{
                        strcpy(tipoPasajero, " ");
                    }
                }
            }
                
            if(auxEstadoVuelo == 0){
                strcpy(estadoVuelo, "Aterrizado");
            }else{
                if(auxEstadoVuelo == 1){
                    strcpy(estadoVuelo, "En Horario");
                }else{
                    if(auxEstadoVuelo == 2){
                        strcpy(estadoVuelo, "En Vuelo");
                    }else{
                        strcpy(estadoVuelo, " ");
                    }
                }
            }
            
            if(/*auxIsEmpty != 0*/1){
                printf("%04d,%15s,%15s,   %10.2f,  %14s,             %15s,            %s\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, tipoPasajero, estadoVuelo);
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
            if(/*auxIsEmpty == 0*/1){
                if(i == 0 || idMax < auxId){
                    idMax = auxId;
                }
            }
        }
        retorno = idMax + 1;
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

int Passenger_modificarPasajero(LinkedList* pArrayListPassenger, int indice){
	int retorno = -1;
	int opcion;
	Passenger* pPasajero;
	
	if(pArrayListPassenger != NULL){
	    pPasajero = ll_get(pArrayListPassenger, indice);
	    if(pPasajero != NULL){
	        do{
	            mostrarMenuModificacion();
        	    getNumeroInt(&opcion, "\tIngrese una opcion del menu de modificacion: ", "\nError! Valor ingresado invalido!\n", 1, 7, 0, BUFFER_SIZE);
        	    fflush(stdin);
        	    
        	    switch(opcion)
        	    {
        	        case 1:
        	            Passenger_modificarNombre(pPasajero);
            	        break;
        	        case 2:
            	        Passenger_modificarApellido(pPasajero);
            	        break;
        	        case 3:
            	        Passenger_modificarPrecio(pPasajero);
            	        break;
        	        case 4:
            	        Passenger_modificarTipoPasajero(pPasajero);
            	        break;
        	        case 5:
            	        Passenger_modificarCodigoVuelo(pPasajero);
            	        break;
        	        case 6:
            	        Passenger_modificarEstadoVuelo(pPasajero);
            	        break;
        	        default:
        	            printf("\n\tSaliendo del menu de modificacion.\n");
        	            break;
        	    }
	        }while(opcion != 7);
    	    retorno = 0;
	    }
	}

	return retorno;
}
