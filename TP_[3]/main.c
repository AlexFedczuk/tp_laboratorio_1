#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "miBiblioteca.h"
#include "inputFuntions.h"

#define ARCH "data.csv"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
    
    NOTAS:
        Acordate de consultar a Gianni o otro de los chicos, si me ueden explicar otra vez cual es la forma "correcta de abrir un Archivo con fopen();"!
        
        CHEQUEAR QUE ESTAN CASTEADAS LAS LLAMADAS A FUNCIONES CON RETORNOS GENERICOS, tendria que agregarles por ej (Passenger*)!!!
        
        LO ULTIMO QUE ME QUEDE FUE EN LA "ALTA" DE PASAJEROS. TENGO QUE CODEAR PARA QUE SE PUEDAN PEDIR LOS DATOS POR CONSOLA...
*****************************************************/
int main()
{
	setbuf(stdout, NULL);
    
    int option = 0;
    
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
        mostrarMenu();
        getNumeroInt(&option, "Ingrese una opcion del menu principal: ", "\nError! Valor ingresado invalido!\n", 1, 10, 0, BUFFER_SIZE);
        switch(option)
        {
            case 1:
                controller_loadFromText(ARCH,listaPasajeros); // Ya estaria, FALTA PROBAR
                break;
            case 2:
                controller_loadFromBinary(ARCH, listaPasajeros); // Ya estaria, FALTA PROBAR
                break;
            case 3:
                controller_addPassenger(listaPasajeros); // me quede aca, SIN TERMINAR... 30-05-2022
                break;
            case 4:
                controller_editPassenger(listaPasajeros);
                break;
            case 5:
                controller_removePassenger(listaPasajeros); // Supongo que ya estaria, pero faltaria probar dichas funciones...
                break;
            case 6:
                controller_ListPassenger(listaPasajeros); // La funcion para lista ya deberia estar lista, CORROBORAR!
                break;
            case 7:
                controller_sortPassenger(listaPasajeros); // Aca ya habria una funcion de ordenamiento, alfabeticamente.
                break;
            case 8:
                controller_saveAsText(ARCH, listaPasajeros); // Ya estaria, FALTA PROBAR
                break;
            case 9:
                controller_saveAsBinary(ARCH, listaPasajeros); // Ya estaria, FALTA PROBAR
                break;
            default:
                printf("Saliendo del programa...\n");
                break;
        }
    }while(option != 10);


    return 0;
}
