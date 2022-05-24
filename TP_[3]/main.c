#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

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
	int cantidad;
	int order = 0;

    //int option = 0;

    LinkedList* listaPasajeros = ll_newLinkedList(); // Estamos creando una lista en memoria dinamica.

    Passenger* pasajero1 = Passenger_newParametros("1001","Papa","1");
    Passenger* pasajero2 = Passenger_newParametros("1002","Pepe","0");
    Passenger* pasajero3 = Passenger_newParametros("1003","Pipi","3");
    Passenger* pasajero4 = Passenger_newParametros("1004","Popo","3");
    Passenger* pasajero5 = Passenger_newParametros("1005","Pupu","1");
    Passenger* aux;

    ll_add(listaPasajeros, pasajero1);
    ll_add(listaPasajeros, pasajero2);
    ll_add(listaPasajeros, pasajero3);
    ll_add(listaPasajeros, pasajero4);

    ll_push(listaPasajeros, 1, pasajero5); // Aca estoy colando el pasajero 5 en el indice 1 de la lista! Corriendo el resto una posicion para "adelante".

    ll_set(listaPasajeros, 1, pasajero5); // Aca lo que haria es PISAR el psajero en el indice 1 con el nuevo pasajero 5.

    ll_remove(listaPasajeros, 2); //Aca estoy dando de baja el pasajero que se encuentra en el indice 2 de la lista.

    ll_pop(listaPasajeros, 2); //Devuelve la direccion de memoria de la entidad que se va a eliminar, o dar de baja. Pero no lo pierdo, esta bueno para probar. NO MATAS EL DATO, SOLAMENTE LO SACAS DE LA LISTA.

    cantidad = ll_len(listaPasajeros);
    printf("Cantidad de pasajeros agregados: %d\n", cantidad);

    ll_sort(listaPasajeros, Passenger_CompareByName, order); // Order puede ser 1 o 0, asi ordena d las distintas formas alfabeticamente.
    ll_sort(listaPasajeros, Passenger_CompareById, order);

    for(int i = 0; i < cantidad; i++){
    	aux = (Passenger*) ll_get(listaPasajeros, i); // Hay que castear que tipo de direccion de memoria, tipo de dato devuelve, ya que sino devuelve algo generico
    	printf("id: %4d, nombre: %s, tipo pasajero: %d\n",aux->id, aux->nombre, aux->tipoPasajero);
    }


    /*do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                break;
        }
    }while(option != 10);*/

    //puts("Hello world");
    return 0;
}

