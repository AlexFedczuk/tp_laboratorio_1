#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Retorna el tamaño del LinkedList.
 *  \param void.
 *  \return int retorno, Devuelve (NULL) si no hay memoria - Sino devuelve el puento de la cabeza de la linkedlist.
 *
 */
LinkedList* ll_newLinkedList(void){
    LinkedList* pLinkedList  = NULL;

    pLinkedList = (LinkedList*) malloc(sizeof(LinkedList*));

    if(pLinkedList != NULL){
        pLinkedList->pFirstNode = NULL;
        pLinkedList->size = 0;
    }

    return pLinkedList;
}

/** \brief Retorna un puntero al nodo que se encuentra en el índice especificado.
 *  \param pList LinkedList*, Puntero a la lista.
 *  \return int retorno, Devuelve (-1) si hay algun parametro invalido - Sino Devuelve el tamanio de la lista.
 *
 */
int ll_len(LinkedList* this){
    int retorno = -1;

    if(this != NULL){
        retorno = this->size;
    }

    return retorno;
}


/*		Retorna un puntero al nodo que se encuentra en el índice especificado. Verificando que el
	puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
	verificación falla la función retorna (NULL) y si tiene éxito retorna el puntero al nodo. */

/** \brief Retorna un puntero al nodo que se encuentra en el índice especificado.
 *  \param pList LinkedList*, Puntero a la lista.
 *  \param int nodeIndex, Indice donde se encuentra el elemento indicado.
 *  \return Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el puntero al nodo.
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex){
    static Node* pNode = NULL;
    int len = 0;

    if(this != NULL && nodeIndex > -1 && nodeIndex < this->size){
        len = ll_len(this);

        if(len > -1){
            pNode = this->pFirstNode;

            for(int i = 0; i < nodeIndex; i++){
                pNode = pNode->pNextNode;
            }
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega un nodo en la posición indexNode.
 *  \param pList LinkedList*, Puntero a la lista.
 *  \param int nodeIndex, Indice donde se ubicara el elemento.
 *  \param pElement void*, Puntero al elemento a ser agregado.
 *  \return int retorno, Devuelve (-1) si hay algun parametro invalido - (0) si Ok.
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    static int retorno = -1;
    int len;
    Node* newNode = NULL;
    Node* previousNode = NULL;
    Node* pNextNode = NULL;

    if(this != NULL && (nodeIndex > -1 && nodeIndex < this->size) && pElement != NULL){
        len = ll_len(this);

        if(len >= nodeIndex){
            newNode = (Node*) malloc(sizeof(Node));

            if(newNode != NULL){
                newNode->pElement = pElement;

                if(this->pFirstNode == NULL || nodeIndex == 0){
                    if(this->pFirstNode == NULL){
                        this->size++;
                    }

                    this->pFirstNode = newNode;
                    pNextNode = getNode(this, nodeIndex + 1);
                    newNode->pNextNode = pNextNode;

                }else{
                    previousNode = getNode(this, nodeIndex - 1);
                    pNextNode = getNode(this, nodeIndex + 1);
                    if(previousNode->pNextNode == NULL){
                        this->size++;
                    }

                    previousNode->pNextNode = newNode;
                    newNode->pNextNode = pNextNode;
                }
                retorno = 0;
            }
        }
    }

    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief Agrega un elemento al final de la lista.
 *  \param pList LinkedList*, Puntero a la lista
 *  \param pElement void*, Puntero al elemento a ser agregado.
 *  \return int retorno, Devuelve (-1) si hay algun parametro invalido - (0) si Ok.
 *
 */
int ll_add(LinkedList* this, void* pElement){
    int retorno = -1;

    if(this != NULL && pElement != NULL){
        addNode(this, ll_len(this), pElement); // No estoy seguro si deberia ser "ll_len(this)" o si "((ll_len(this)) - 1)"...
        retorno = 0;
    }

    return retorno;
}

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado.
 *  \param LinkedList* this, Puntero a la lista
 *  \param int index, el indice donde se encuentra x elemento.
 *  \return int retorno, Devuelve (NULL) si se ingresa un paranetro invalido - Sino devuelve el puento al elemento.
 *
 */
void* ll_get(LinkedList* this, int index)
{
    Node* pNodo = NULL;
    void* pRetorno = NULL;

    if(this != NULL && index > -1 && index < ll_len(this)){
        pNodo = getNode(this, index);

        if(pNodo != NULL){
            pRetorno = pNodo->pElement;
        }
    }

    return pRetorno;
}


/** \brief Inserta un elemento en el LinkedList, en el índice especificado.
 *  \param pList LinkedList*, Puntero a la lista.
 *  \param int nodeIndex, Indice donde se ubicara el elemento.
 *  \param pElement void*, Puntero al elemento.
 *  \return int retorno, Devuelve (-1) si hay algun parametro invalido - (0) si Ok.
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)// listo
{
    int retorno = -1;
    Node* pNewNode = NULL;
    Node* pPreviosNode = NULL;
    Node* pNextNode = NULL;

    if(this != NULL && index > -1 && index < ll_len(this) && pElement != NULL){
        pNewNode = (Node*) malloc(sizeof(Node));

        if(pNewNode != NULL){
            pNewNode->pElement = pElement;

            if(this->pFirstNode == NULL){
                addNode(this, index, pElement);
            }else{
                if(index == 0){
                    pNewNode->pNextNode = this->pFirstNode->pNextNode;
                    free(this->pFirstNode);
                    this->pFirstNode = pNewNode;
                }else{
                    pPreviosNode = getNode(this, index - 1);
                    pNextNode = getNode(this, index + 1);

                    if(pPreviosNode != NULL)
                    	free(pPreviosNode->pNextNode);

                    pPreviosNode->pNextNode = pNewNode;

                    pNewNode->pNextNode = pNextNode;
                }
            }
            retorno = 0;
        }
    }

    return retorno;
}


/** \brief Elimina un elemento del LinkedList, en el índice especificado.
 *  \param pList LinkedList*, Puntero a la lista.
 *  \param int nodeIndex, Indice donde se ubicara el elemento.
 *  \return int retorno, Devuelve (-1) si hay algun parametro invalido - (0) si Ok.
 *
 */
int ll_remove(LinkedList* this, int index) // Elimina el elemento de un nodo o elimina un Nodo?
{
    int retorno = -1;
    Node* pNode;
    Node* pPreviosNode;
    Node* pNextNode;

    if(this != NULL && index > -1 && index < ll_len(this)){
        pNode = getNode(this, index);
        pPreviosNode = getNode(this, index - 1);
        pNextNode = getNode(this, index + 1);

        if(pNode == NULL){
            if(index == 0){
                this->pFirstNode = pNextNode;
                free(pNode);
                this->size--;
            }else{
            	if(pPreviosNode != NULL){
            		pPreviosNode->pNextNode = pNextNode;
            		free(pNode);
            		this->size--;
            	}

            }
            retorno = 0;
        }
    }

    return retorno;
}


/** \brief Borra todos los elementos de LinkedList.
 *  \param pList LinkedList*, Puntero a la lista.
 *  \return int retorno, Devuelve (-1) si hay algun parametro invalido - (0) si Ok.
 *
 */
int ll_clear(LinkedList* this)// Elimina el elemento de un nodo o elimina un Nodo?
{
    int retorno = -1;
    Node* pNode;

    if(this != NULL){
        for(int i = ll_len(this); i > 0; i--){
            pNode = getNode(this, i);

            if(pNode != NULL){
                if(i == 0){
                    this->pFirstNode = NULL;
                    this->size = 0;

                }else{
                    this->size--;
                }
                free(pNode);
            }
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Elimina el LinkedList.
 *  \param pList LinkedList*, Puntero a la lista.
 *  \return int retorno, Devuelve (-1) si hay algun parametro invalido - (0) si Ok.
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int retorno = -1;
    int isEmpty;
    int clear;

    if(this != NULL){
    	isEmpty = ll_isEmpty(this);
    	clear = ll_clear(this);
    	free(this);

        if(isEmpty == 1 && clear == 0){
            retorno = 1;
        }else{
        	retorno = 0;
        }
    }

    return retorno;
}

/** \brief Retorna el índice de la primera aparición de un elemento (element) en el LinkedList.
 *  \param pList LinkedList*, Puntero a la lista.
 *  \param pElement void*, Puntero al elemento.
 *  \return int retorno, Devuelve (-1) si hay algun parametro invalido - Un indice si Ok.
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno = -1;
    int len;
    Node* pNode;

    if(this != NULL && pElement != NULL){
        len = ll_len(this);

        for(int i = 0; i < len; i++){
            pNode = getNode(this, i);

            if(pNode != NULL){
                if(pNode->pElement == pElement){
                    retorno = i;
                    break;
                }
            }
        }
    }

    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

