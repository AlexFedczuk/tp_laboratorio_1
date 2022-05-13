/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Alex Yago Fedczuk
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

int main()
{
	setbuf(stdout, NULL);

    int opcionMenu;
    int opcionUnoCargada;
    int contadorId;
    int orden;
    float totalPrecios;
    float promedioPrecios;
    int cantidadPasajerosMasPromedio;

    ePassenger passengerList[LEN];

    opcionUnoCargada = 0;
    contadorId = 0;

    if(initPassengers(passengerList, LEN) == -1)
            printf("\nError! Invalid length or NULL pointer, al inicializar la lista de pasageros!\n");
    if(inicializarEntidades(passengerList, LEN) == -1)
            printf("\nError! Invalid length or NULL pointer, al inicializar la lista de pasageros!\n");

    /*contadorId = hardcodearEntidades(passengerList, LEN);
    if(contadorId == -1)
    	printf("\nError! Invalid length or NULL pointer, al hardcodear la lista de pasageros!\n");*/

    do{
        mostrarMenu();
        getNumeroInt(&opcionMenu, "Ingrese una opcion del menu principal: ", "\nError! Valor ingresado invalido!\n", 1, 6, 0, BUFFER_SIZE); // Por alguna razon salta el mensaje de error caudo termino de realizar una ALTA.
        switch(opcionMenu)
        {
            case 1:
            	if(buscarEspacioVacio(passengerList, LEN) != -2){
            		contadorId++;
            		contadorId = cargarPasajero(passengerList, LEN, contadorId);
            		opcionUnoCargada = 1;
            	}else{
            		printf("\nERROR! Ya no quedan espacios en el programa para ingresar mas pasajeros!\n");
            	}
                break;
            case 2:
            	if(opcionUnoCargada == 1){
            		printPassenger(passengerList, LEN);
            		if(modificarPasajero(passengerList, LEN) == -1)
            		            printf("\nError! Invalid length or NULL pointer, al querer ingresar a la opcion 2 del Menu Principal!\n");
            	}else{
            	    printf("\nERROR! Se debe ingresar algun pasajero para realizar una modificacion!\n");
            	}
            	break;
            case 3:
                if(opcionUnoCargada == 1){
                	printPassenger(passengerList, LEN);
                	darBajaPasajero(passengerList, LEN);
                }else{
                	printf("\nERROR! Se debe ingresar algun pasajero para realizar una baja!\n");
                }
                break;
            case 4:
            	if(opcionUnoCargada == 1){
            	    getNumeroInt(&orden, "\nIngrese tipo de orden del listado de pasajeros A a Z(0) o Z a A(1): ", "\nError! Valor ingresado invalido!\n", 0, 1, 0, BUFFER_SIZE);
            	    sortPassengers(passengerList, LEN, orden);
            		printPassenger(passengerList, LEN);
            		totalPrecios = calcularTotal(passengerList, LEN);
            		promedioPrecios = calcularPromedio(passengerList, LEN, totalPrecios);
            		cantidadPasajerosMasPromedio = calcularPasajerosMasPromedio(passengerList, LEN, promedioPrecios);
            		informarInformacion(&totalPrecios, &promedioPrecios, &cantidadPasajerosMasPromedio);
            		getNumeroInt(&orden, "\nIngrese tipo de orden del listado de pasajeros por Codigo de Vuelo A a Z(0) o Z a A(1): ", "\nError! Valor ingresado invalido!\n", 0, 1, 0, BUFFER_SIZE);
            		sortPassengersByCode(passengerList, LEN, orden);
            		printPassengerByCode(passengerList, LEN);
            	}else{
            		printf("\nERROR! Se debe ingresar algun pasajero para realizar un informe!\n");
            	}
                break;
            case 5:
            	// En este caso se permite el hardcodeo de x cantidad de pasajeros.
            	contadorId = hardcodearEntidades(passengerList, LEN, &contadorId);
            	printf("\nSe a realizado la carga forzada de Pasajeros.\n");
            	opcionUnoCargada = 1;
                break;
            default:
                system("pause");
                system("cls");// Por alguna razon, no la reconoce la funcion...
                break;
        }
    }while(opcionMenu != 6);

    return 0;
}
