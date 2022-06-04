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
*****************************************************/
int main()
{
	setbuf(stdout, NULL);
    
    int option = 0;
    int banderaLoad = 1;
    int banderaSave = 1;
    
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
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
                controller_addPassenger(listaPasajeros); // Listo.
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
            		controller_sortPassenger(listaPasajeros); // Listo, solamente alfabeticamente...
                break;
            case 8:
                banderaSave = controller_saveAsText(ARCH, listaPasajeros); // Por alguna razon no guarda el los "precios" correctos...
                break;
            case 9:
                banderaSave = controller_saveAsBinary(ARCH, listaPasajeros); // Listo.
                break;
            default:
                controller_exit(listaPasajeros, option, banderaSave, ARCH);// Listo.
        }
        fflush(stdin);
    }while(option != 10 && banderaSave != 0);


    return 0;
}
