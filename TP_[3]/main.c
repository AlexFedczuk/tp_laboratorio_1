#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "miBiblioteca.h"
#include "inputFuntions.h"

#define ARCH "data.csv"

/****************************************************
 *
 * 			 !!!!ALERTA !!!!ALERTA ALERTAALERTAALERTA ALERTA ALERTA ALERTA ALERTAALERTA ALERTA ALERTA ALERTA!!!!
 * 			 		- Acordate de no tocar los archivos que NO son .c  o .h!
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
        
        Tengo que ver como arreglar el tema de ESTADO VUELO Y TIPO PASAJERO, ya que son INT, pero muestran una CADENA DE TEXTO.
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
                controller_editPassenger(listaPasajeros);// listo, FALTA PROBAR!
                break;
            case 5:
                controller_removePassenger(listaPasajeros); // Listo.
                break;
            case 6:
                controller_ListPassenger(listaPasajeros); // Listo.
                break;
            case 7:
                controller_sortPassenger(listaPasajeros); // Listo, solamente alfabeticamente.
                break;
            case 8:
                banderaSave = controller_saveAsText(ARCH, listaPasajeros); // Listo.
                break;
            case 9:
                banderaSave = controller_saveAsBinary(ARCH, listaPasajeros); // Listo.
                break;
            default:
                controller_exit(listaPasajeros, option, banderaSave, ARCH);// Listo.
                break;
        }
    }while(option != 10 && banderaSave != 0);


    return 0;
}
