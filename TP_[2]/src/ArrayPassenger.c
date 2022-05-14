/*
 * ArrayPassenger.c
 *
 *  Created on: Apr 25, 2022
 *      Author: Alex Yago Fedczuk
 *
 *      FALTA, MIRAR BIEN LA HOJA
 */
#include <stdio.h>
#include "ArrayPassenger.h"

int initPassengers(ePassenger* list, int len){
    int result = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            list[i].isEmpty = 1;
        }
        result = 0;
    }

    return result;
}

int inicializarEntidades(ePassenger* list, int len){
    int result = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            list[i].id = 0;
            strcpy(list[i].name, " ");
            strcpy(list[i].lastName, " ");
            list[i].price = -1;
            strcpy(list[i].flyCode, " ");
            list[i].typePassenger = -1;
            list[i].statusFlight = -1;
        }
        result = 0;
    }

    return result;
}

int cargarPasajero(ePassenger list[], int len, int contadorId)
{
    int id;
    char name[NAMES_LEN];
    char lastName[NAMES_LEN];
    float price;
    char flyCode[10];
    int typePassenger;
    int statusFlight;
    char respuesta;
    int bandera = 0;

    do{
        if(bandera == 0){
            id = contadorId;
        }
        else{
            id++;
        }

        printf("\nIngrese el nombre del pasajero: ");
        myGets(name, NAMES_LEN);
        formalizarNombre(name, strlen(name));

        printf("\nIngrese el apellido del pasajero: ");
        myGets(lastName, NAMES_LEN);
        formalizarNombre(lastName, strlen(lastName));

        getNumeroFloat(&price, "\nIngrese el precio: ", "\nError! Valor ingresado invalido!\n", 0, 999999999, 0, BUFFER_SIZE);

        printf("\nIngrese el codigo de vuelo: ");
        myGets(flyCode, 10);

        getNumeroInt(&typePassenger, "\nIngrese tipo de pasajero (0) o (1): ", "\nError! Valor ingresado invalido!\n", 0, 1, 0, BUFFER_SIZE);
        getNumeroInt(&statusFlight, "\nIngrese el estado del vuelo (0) o (1): ", "\nError! Valor ingresado invalido!\n", 0, 1, 0, BUFFER_SIZE);

        if(addPassenger(list, len, id, name, lastName, price, typePassenger, statusFlight, flyCode) == -1){
            printf("\nError! Invalid length or NULL pointer, al agregar el pasajero a la lista!\n");
        }else{
            printf("\nEl pasajero se a dado de alta.\n");
        }

        printf("\nDesea cargar otro pasajero(s/n)?: ");
        fflush(stdin);
        scanf("%c", &respuesta);
        //getUnCaracter(&respuesta,"\nDesea cargar otro pasajero(s/n)?: ", "\nError! Valor ingresado invalido!\n", 0, BUFFER_SIZE);
        respuesta = tolower(respuesta);
        if(respuesta == 'n')
            break;

        bandera = 1;
    }
    while(respuesta != 'n');
    //fflush(stdin);

    return id;
}

int formalizarNombre(char* cadena, int len){
    int retorno = -1;
    if(cadena != NULL && len > 0){
        for(int i = 0; i < len; i++){
            if((i == 0 && isalpha(cadena[i])) || (cadena[i - 1] == ' ' && isalpha(cadena[i]))){
                cadena[i] = toupper(cadena[i]);
            }else{
                cadena[i] = tolower(cadena[i]);
            }
        }
        retorno = 0;
    }
    return retorno;
}

int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, int statusFlight, char flyCode[]){
	int espacioVacio;
	int resultado = -1;

	espacioVacio = buscarEspacioVacio(list, len);

	if(list != 0 && len > 0 && espacioVacio != -1)
	{
		list[espacioVacio].id = id;
	    strcpy(list[espacioVacio].name, name);
	    strcpy(list[espacioVacio].lastName, lastName);
	    list[espacioVacio].price = price;
	    strcpy(list[espacioVacio].flyCode, flyCode);
	    list[espacioVacio].typePassenger = typePassenger;
	    list[espacioVacio].statusFlight = statusFlight;
	    list[espacioVacio].isEmpty = 0;
	    resultado = 0;
	}

	return resultado;
}

int buscarEspacioVacio(ePassenger* list, int len){
    int result = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            if(list[i].isEmpty == 1)
            {
                result = i;
                break;
            }else{
                result = -2;
            }
        }
    }
    return result;
}

int printPassenger(ePassenger* list, int length)
{
    int result = -1;

    if(list != NULL && length > 0){
        printf("\n");
        for(int i = 0; i < length; i++){
        	if(list[i].isEmpty == 0){
        		printf("ID: %04d, Name: %20s, Last Name: %20s, Price: %11.2f, Fly Code: %10s, Type Passenger: %2d, Status Flight: %2d\n",
                                                                                                                                    list[i].id,
                                                                                                                                    list[i].name,
                                                                                                                                    list[i].lastName,
                                                                                                                                    list[i].price,
                                                                                                                                    list[i].flyCode,
                                                                                                                                    list[i].typePassenger,
                                                                                                                                    list[i].statusFlight);
        	}
        }
        result = 0;
    }

    return result;
}

int findPassengerById(ePassenger* list, int len, int id){
	int index = -1;

	if(list != NULL && len > 0 && id > 0){
		for(int i = 0; i < len; i++){
			if(list[i].id == id){
				index = i;
				break;
			}
		}
	}

	return index;
}

int removePassenger(ePassenger* list, int len, int id){
	int result = -1;

	if(list != NULL && len > 0 && id > 0){
		for(int i = 0; i < len; i++){
			if(list[i].id == id){
				list[i].isEmpty = 1;
				result = 0;
				break;
			}
		}
	}

	return result;
}

int darBajaPasajero(ePassenger* list, int len){
	int idIngresado;
	int index;
	int result = -1;

	if(list != NULL && len > 0){
		do{
			idIngresado = pedirNumeroEntero("\nIngrese el ID del pasajero que quiere dar de baja: ");
			if(idIngresado < 1){
				printf("\nError! El ID debe ser mayor a cero (0)!\n");
			}else{
				index = findPassengerById(list, len, idIngresado);
				if(index == -1){
					printf("\nError! Invalid length or NULL pointer received or passenger not found!\n");
				}else{
					result = removePassenger(list, len, idIngresado);
					printf("\nEl pasajero seleccioando fue dado de baja.\n");
				}
			}
		}while(idIngresado < 1 || index == -1);
	}
	return result;
}

int modificarPasajero(ePassenger* list, int len){
	int idIngresado;
	int index;
	int result = -1;

	if(list != NULL && len > 0){
		do{
			getNumeroInt(&idIngresado, "\nIngrese el ID del pasajero que quiere modificar: ", "\nError! Valor ingresado invalido!\n", 1, 1000000, 0, BUFFER_SIZE);
			index = findPassengerById(list, len, idIngresado);
			if(index == -1){
				printf("\nError! Invalid length or NULL pointer received or passenger not found!\n");
			}else{
				if(menuModificacion(list, index, NAMES_LEN) == -1){
				    printf("\nError! Invalid length or NULL pointer received or passenger not found!\n");
				}else{
				    printf("\nEl pasajero a sido modificado.\n");
				}
			}
		}while(index == -1);
		result = 0;
	}
	return result;
}

int menuModificacion(ePassenger* list, int index, int buffer){
	int result = -1;
	int opcionMenu;

	if(list != NULL && index > -1 && buffer > 0){
		do{
			mostarMenuModificacion();
			getNumeroInt(&opcionMenu, "\n\tIngrese una opcion del Menu de Modificacion: ", "\nError! Valor ingresado invalido!\n", 1, 6, 0, BUFFER_SIZE);
			switch(opcionMenu){
				case 1:
					printf("\n\tIngrese el nuevo nombre del pasajero: ");
					myGets(list[index].name, BUFFER_SIZE);
					break;
				case 2:
					printf("\n\tIngrese el nuevo nombre del pasajero: ");
					myGets(list[index].lastName, BUFFER_SIZE);
					break;
				case 3:
					getNumeroFloat(&list[index].price, "\n\tIngrese el nuevo precio: ", "\nError! Valor ingresado invalido!\n", 0, 999999999, 0, BUFFER_SIZE);
					break;
				case 4:
					getNumeroInt(&list[index].typePassenger, "\n\tIngrese tipo de pasajero (0) o (1): ", "\nError! Valor ingresado invalido!\n", 0, 1, 0, BUFFER_SIZE);
					break;
				case 5:
					printf("\n\tIngrese el codigo de vuelo: ");
					myGets(list[index].flyCode, BUFFER_SIZE);
					break;
				default:
					system("pause");
					break;
			}
		}while(opcionMenu != 6);
		result = 0;
	}
	return result;
}

void mostarMenuModificacion(){
	printf("\n\tMenu de Modificacion\n");
	printf("\t1. NOMBRE\n");
	printf("\t2. APELLIDO\n");
	printf("\t3. PRECIO\n");
	printf("\t4. TIPO DE PASAJERO\n");
	printf("\t5. CODIGO DE VUELO\n");
	printf("\t6. Salir\n\n");
}

int sortPassengers(ePassenger* list, int len, int order)
{
    int retorno = -1;

    if(list != NULL && len > 0 && (order == 0 || order == 1)){
        if(order == 0){
            ordenarAlfabeticamenteAaZ(list, len);
        }else{
            ordenarAlfabeticamenteZaA(list, len);
        }
        retorno = 0;
    }
    return retorno;
}

int ordenarAlfabeticamenteAaZ(ePassenger* list, int len){
    int result = -1;
    ePassenger aux;
    if(list != NULL && len > 0){
       for(int i = 0; i < len - 1; i++){
            for(int j = i + 1; j < len; j++){
                if(strcmp(list[i].lastName,list[j].lastName) > 0){
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }else if(strcmp(list[i].lastName, list[j].lastName) == 0){
                    if(list[i].typePassenger > list[j].typePassenger){
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
        result = 0;
    }
    return result;
}

int ordenarAlfabeticamenteZaA(ePassenger* list, int len){
    int result = -1;
    ePassenger aux;
    if(list != NULL && len > 0){
       for(int i = 0; i < len - 1; i++){
            for(int j = i + 1; j < len; j++){
                if(strcmp(list[i].lastName,list[j].lastName) < 0){
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                }else if(strcmp(list[i].lastName, list[j].lastName) == 0){
                    if(list[i].typePassenger > list[j].typePassenger){
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
        result = 0;
    }
    return result;
}

int printPassengerByCode(ePassenger* list, int length)
{
    int result = -1;

    if(list != NULL && length > 0){
        printf("\n");
        for(int i = 0; i < length; i++){
        	if(list[i].isEmpty == 0 && list[i].statusFlight == 1){
        		printf("ID: %04d, Name: %20s, Last Name: %20s, Price: %11.2f, Fly Code: %10s, Type Passenger: %2d, Status Flight: %2d\n",
                                                                                                                                    list[i].id,
                                                                                                                                    list[i].name,
                                                                                                                                    list[i].lastName,
                                                                                                                                    list[i].price,
                                                                                                                                    list[i].flyCode,
                                                                                                                                    list[i].typePassenger,
                                                                                                                                    list[i].statusFlight);
        	}
        }
        result = 0;
    }

    return result;
}

int sortPassengersByCode(ePassenger* list, int len, int order){
    int retorno = -1;

    if(list != NULL && len > 0 && (order == 0 || order == 1)){
        // Aca el ordenamiento...
        if(order == 0){
            ordenarPorCodigoUP(list, len);
        }else{
            ordenarPorCodigoDOWN(list, len);
        }
        retorno = 0;
    }

    return retorno;
}

int ordenarPorCodigoUP(ePassenger* list, int len){
    int result = -1;
    ePassenger aux;
    if(list != NULL && len > 0){
       for(int i = 0; i < len - 1; i++){
            for(int j = i + 1; j < len; j++){
                if(strcmp(list[i].flyCode,list[j].flyCode) > 0){
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }else if(strcmp(list[i].flyCode, list[j].flyCode) == 0){
                    if(list[i].statusFlight < list[j].statusFlight){
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
        result = 0;
    }
    return result;
}

int ordenarPorCodigoDOWN(ePassenger* list, int len){
    int result = -1;
    ePassenger aux;
    if(list != NULL && len > 0){
       for(int i = 0; i < len - 1; i++){
            for(int j = i + 1; j < len; j++){
                if(strcmp(list[i].flyCode,list[j].flyCode) < 0){
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }else if(strcmp(list[i].flyCode, list[j].flyCode) == 0){
                    if(list[i].statusFlight > list[j].statusFlight){
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
        result = 0;
    }
    return result;
}
