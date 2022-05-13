/*
 * miBiblioteca.c
 *
 *  Created on: Apr 25, 2022
 *      Author: Alex Yago Fedczuk
 */
#include <stdio.h>
#include <string.h>
#include "miBiblioteca.h"

void mostrarMenu(){
    printf("\nMenu pricipal\n");
    printf("1. ALTAS\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. Salir\n\n");
}

int hardcodearEntidades(ePassenger* list, int len){
	int idAux[5] = {1,2,8,4,5};
	char nameAux[5][50] = {"ana Sara","fara fareeha","bastion metzen","brigitte lindholm","coto argentino"};
	char lastNameAux[5][50] = {"amari","amari","fortaleza","reinhardt","yoteconosco"};
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
}

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

float calcularTotal(ePassenger* list, int len){
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
}

float calcularPromedio(ePassenger* list, int len, float total){
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
}

int calcularPasajerosMasPromedio(ePassenger* list, int len, float promedio){
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
}

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
