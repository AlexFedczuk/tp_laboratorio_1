/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas

// Va a crear la lista en memoria
LinkedList* ll_newLinkedList(void);

// Saca el largo de la lista, CUANTOS PASAJEROS POR EJMPLO
int ll_len(LinkedList* this);

Node* test_getNode(LinkedList* this, int nodeIndex);

int test_addNode(LinkedList* this, int nodeIndex, void* pElement);

// agrega un pasajero, tiene un puntero tipo void, eso es un puntero generico
int ll_add(LinkedList* this, void* pElement);

// Devuelve el "indice" de donde esta ubicado un pasajero por ejemplo
void* ll_get(LinkedList* this, int index);

// Este sirve para modificar un dato de un pasajero
int ll_set(LinkedList* this, int index, void* pElement);

// Puede "colar " un pasajero en x lugar, y empuja el resto para adelante, lo INSERTAS en x lugar de la lista (?)
int ll_push(LinkedList* this, int index, void* pElement);

// Esto da de baja Logica un pasajero.
int ll_remove(LinkedList* this, int index);

// Limpia/Inicializa todo los elementos de la lista, aun asi existe, por lo tanto se pueden seguir agregando entidades...
int ll_clear(LinkedList* this);

// Borra de forma fisica todo lo de la lista, destruye la lista, se pierde el espacio en memoria reserbado por el sistema operativo.
int ll_deleteLinkedList(LinkedList* this);

// Devuelve el indice de x elemento...
int ll_indexOf(LinkedList* this, void* pElement);

// Este te dice si esta vacia o no la lista (?)
int ll_isEmpty(LinkedList* this);

// Aca lo que hace es devolver un puntero generico, la direccion de memoria del elemnto que eliminaste. Elimina entidades esto...
void* ll_pop(LinkedList* this,int index);

// Me dice si un x elemnto esta dentro de la lista
int ll_contains(LinkedList* this, void* pElement);

// Aca compara dos listas y supongo que te dicen si son iguales?
int ll_containsAll(LinkedList* this,LinkedList* this2);

//
LinkedList* ll_subList(LinkedList* this,int from,int to);

// Te devuelve una lista duplicada.
LinkedList* ll_clone(LinkedList* this);

// Este ordena la lista....
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
