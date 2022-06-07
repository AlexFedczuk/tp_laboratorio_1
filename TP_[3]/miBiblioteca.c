/*
 * miBiblioteca.c
 *
 *  Created on: Apr 25, 2022
 *      Author: Alex Yago Fedczuk
 */
#include "miBiblioteca.h"

void mostrarMenu(){
    printf("\nMenu pricipal\n");
    printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de pasajero\n");
    printf("4. Modificar datos de pasajero\n");
    printf("5. Baja de pasajero\n");
    printf("6. Listar pasajeros\n");
    printf("7. Ordenar pasajeros\n");
    printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n\n");
}

void mostrarMenuModificacion(){
    printf("\n\tMenu de Modificacion\n");
    printf("\t1. Nombre.\n");
    printf("\t2. Apellido.\n");
    printf("\t3. Precio.\n");
    printf("\t4. Tipo de pasajero.\n");
    printf("\t5. Codigo de vuelo.\n");
    printf("\t6. Estado de vuelo.\n");
    printf("\t7. Salir\n\n");
}

void mostrarMenuOrdenamiento(){
	printf("\n\tMenu de Ordenamiento\n");
	printf("\t1. ID.\n");
	printf("\t2. Nombre.\n");
	printf("\t3. Apellido.\n");
	printf("\t4. Precio.\n");
	printf("\t5. Tipo de pasajero.\n");
	printf("\t6. Codigo de vuelo.\n");
	printf("\t7. Estado de vuelo.\n");
	printf("\t8. Salir\n\n");
}

/*int hardcodearEntidades(ePassenger* list, int len, int* contadorId){
	int idAux[5] = {*contadorId + 1,*contadorId + 2,*contadorId + 3,*contadorId + 4,*contadorId + 5};
	char nameAux[5][50] = {"Ana Sara","Fara Fareeha","Bastion Metzen","Brigitte Lindholm","Coto Argentino"};
	char lastNameAux[5][50] = {"Amari","Amari","Fortaleza","Reinhardt","Yo Te Conosco"};
	int priceAux[5] = {15000.234,20500.12,2225750.56,55400.78,42600.12};
	char flyCodeAux[5][50] = {"ar 1140","br 3251","eu 1234","ar 1278","ar 4500"};
	int typePassengerAux[5] = {0,1,1,0,1};
	int statusFlightAux[5] = {1,1,1,1,0};
	int isEmptyAux[5] = {0,0,0,0,0};
	int result = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < 5; i++){
	        list[i].id = idAux[i];
	        strcpy(list[i].name, nameAux[i]);
	        strcpy(list[i].lastName, lastNameAux[i]);
	        list[i].price = priceAux[i];
	        strcpy(list[i].flyCode, flyCodeAux[i]);
	        list[i].typePassenger = typePassengerAux[i];
	        list[i].statusFlight = statusFlightAux[i];
	        list[i].isEmpty = isEmptyAux[i];
		}
		result = 0;
	}

	result = calcularIntMayor(idAux, 5);

	return result;
}*/

int calcularIntMayor(int vec[], int len){
	int result;

	for(int i = 0; i < len; i++){
		if(i == 0){
			result = vec[i];
		}else if(result < vec[i]){
			result = vec[i];
		}
	}

	return result;
}

/*float calcularTotal(ePassenger* list, int len){
    float retorno = -1;

    if(list != NULL && len > 0){
        retorno = 0;
        for(int i = 0; i < len; i++){
            if(list[i].isEmpty == 0){
                retorno = retorno + list[i].price;
            }
        }
    }

    return retorno;
}*/

/*float calcularPromedio(ePassenger* list, int len, float total){
    float retorno = -1;
    int contador = 0;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            if(list[i].isEmpty == 0){
                contador++;
            }
        }

        if(contador != 0){
            retorno = total / contador;
        }
    }
    return retorno;
}*/

/*int calcularPasajerosMasPromedio(ePassenger* list, int len, float promedio){
    int contador = -1;

    if(list != NULL && len > 0){
        contador = 0;
        for(int i = 0; i < len; i++){
            if(list[i].isEmpty == 0 && list[i].price > promedio){
                contador++;
            }
        }
    }
    return contador;
}*/

int informarInformacion(float* total, float* promedio, int* cantidad){
    int retorno = -1;
    float totalAux,promedioAux;
    int cantidadAux;



    if(total != NULL && promedio != NULL && cantidad != NULL){
        totalAux = *total;
        promedioAux = *promedio;
        cantidadAux = *cantidad;
        printf("\nTotal de los precios de pasajeros: %.2f\nPromedio de los precios de pasajeros: %.2f\nCantidad de pasajeros que superan el promedio: %d\n",totalAux,promedioAux,cantidadAux);
        retorno = 0;
    }
    return retorno;
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

int GetMaximumID(char* fileName){
	int retorno = -1;
	char idStr[10];
	FILE* pArchivo = NULL;

	if(fileName != NULL){
		pArchivo = fopen(fileName, "r");
		if(pArchivo != NULL){
			do{
				fscanf(pArchivo,"%[^\n]\n",idStr);
			}while(!feof(pArchivo));

			fclose(pArchivo);

			retorno = atoi(idStr);
		}
	}

	return retorno;
}

int SaveMaximumID(char* fileName, int* idMaximo){
	int retorno = -1;
	FILE* pArchivo = NULL;

	if(fileName != NULL && idMaximo != NULL){
		pArchivo = fopen(fileName, "w");

		if(pArchivo != NULL){
			fprintf(pArchivo,"%d\n", *idMaximo);

			retorno = 0;
		}
		fclose(pArchivo);
	}
	return retorno;
}
