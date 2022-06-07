#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "miBiblioteca.h"
#include "inputFuntions.h"

#define ARCH "MOCK_DATA.csv"
#define ID_ARCH "idMaximo.csv"

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

*****************************************************/
int main()
{
	setbuf(stdout, NULL);
    
    int option = 0;
    int banderaLoad = 1;
    int banderaSave = 1;
    int banderaExit = 1;
    int idMaximo;

    idMaximo = GetMaximumID(ID_ARCH);
    LinkedList* listaPasajeros = ll_newLinkedList();

    while(banderaExit == 1){
        mostrarMenu();
        getNumeroInt(&option, "Ingrese una opcion del menu principal: ", "\nError! Valor ingresado invalido!\n", 1, 10, 0, BUFFER_SIZE);
        //fflush(stdin); Si dejo este 'fflush' no deja ingresar a los 'cases'...
        switch(option)
        {
            case 1:
            	if(banderaLoad == 1)
            		banderaLoad = controller_loadFromText(ARCH,listaPasajeros); // Listo.
                break;
            case 2:
            	if(banderaLoad == 1)
            		banderaLoad = controller_loadFromBinary(ARCH, listaPasajeros); // Listo.
                break;
            case 3:
                controller_addPassenger(listaPasajeros, &idMaximo); // Listo.
                break;
            case 4:
            	if(ll_len(listaPasajeros) >= 1)
            		controller_editPassenger(listaPasajeros);// Listo.
                break;
            case 5:
            	if(ll_len(listaPasajeros) >= 1)
            		controller_removePassenger(listaPasajeros); // Listo.
                break;
            case 6:
            	if(ll_len(listaPasajeros) >= 1)
            		controller_ListPassenger(listaPasajeros); // Listo.
                break;
            case 7:
            	if(ll_len(listaPasajeros) >= 1)
            		controller_sortPassenger(listaPasajeros); // Listo.
                break;
            case 8:
                banderaSave = controller_saveAsText(ARCH, listaPasajeros); // Listo. El problema era el archivo (.csv) que venia con el proyecto. 06-06-2022
                break;
            case 9:
                banderaSave = controller_saveAsBinary(ARCH, listaPasajeros); // Listo.
                break;
            case 10:
            	banderaExit = controller_exit(listaPasajeros, banderaSave, ARCH, ID_ARCH, &idMaximo);// Listo.
            	break;
            default:
                break;
        }
        fflush(stdin);
    }

    return 0;
}
