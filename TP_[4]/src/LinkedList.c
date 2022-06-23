// int ll_remove(LinkedList* this, int index); Elimina el elemento de un nodo o elimina un Nodo?
// int ll_clear(LinkedList* this); Elimina (libera, free) el elemento de un nodo y elimina (libera, free) un Nodo?
// int ll_push(LinkedList* this, int index, void* pElement); tengo que probarlo en un cas real!
// void* ll_pop(LinkedList* this, int index); Deberia reservar un espaco en memoria para este nodo que voy a sacar de la lista, hay que probar en un caso real!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


/*
Esto estaba cuando descargue el proyecto:
static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);
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
static Node* getNode(LinkedList* this, int nodeIndex){
    static Node* pNode = NULL;
    int len = 0;

    if(this != NULL && nodeIndex > -1 && nodeIndex < this->size){
        len = ll_len(this);

        if(len > -1){
            pNode = this->pFirstNode;

            for(int i = 0; i < nodeIndex; i++){
		    if(i == nodeIndex){
			    pNode = pNode->pNextNode;
		    }                
            }
        }
    }

    return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

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

                if(/*this->pFirstNode == NULL ||*/ nodeIndex == 0){
                    if(this->pFirstNode == NULL)
                        this->size++;
			
                    this->pFirstNode = newNode;
                    pNextNode = getNode(this, nodeIndex + 1);
                    newNode->pNextNode = pNextNode;

                }else{
                    previousNode = getNode(this, nodeIndex - 1);
                    pNextNode = getNode(this, nodeIndex + 1);
			
                    if(previousNode->pNextNode == NULL)
                        this->size++;

                    previousNode->pNextNode = newNode;
                    newNode->pNextNode = pNextNode;
                }
                retorno = 0;
            }
        }
    }

    return retorno;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

int ll_add(LinkedList* this, void* pElement){
    int retorno = -1;

    if(this != NULL && pElement != NULL){
        addNode(this, ll_len(this), pElement);
        retorno = 0;
    }

    return retorno;
}

void* ll_get(LinkedList* this, int index)
{
    Node* pNodo;
    void* pRetorno;

    if(this != NULL && index > -1 && index < ll_len(this)){
        pNodo = getNode(this, index);

        if(pNodo != NULL){
            pRetorno = pNodo->pElement;
        }
    }

    return pRetorno;
}

int ll_set(LinkedList* this, int index, void* pElement)
{
    int retorno = -1;
    Node* pNewNode = NULL;
    Node* pPreviosNode = NULL;
    Node* pNextNode = NULL;

    if(this != NULL && (index > -1 && index < ll_len(this))){
        pNewNode = (Node*) malloc(sizeof(Node));

        if(pNewNode != NULL){
            pNewNode->pElement = pElement;

            /*if(this->pFirstNode == NULL){
                addNode(this, index, pElement);
            }else{*/
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
            //}

        }
        retorno = 0;
    }

    return retorno;
}

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

        if(pNode != NULL){
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

        }
        retorno = 0;
    }

    return retorno;
}

int ll_clear(LinkedList* this)// Elimina (libera, free) el elemento de un nodo y elimina (libera, free) un Nodo?
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

int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno = -1;
    int len;
    Node* pNode;

    if(this != NULL){
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

int ll_isEmpty(LinkedList* this)
{
    int retorno = -1;
    int len;

    if(this != NULL){
    	retorno = 1;
        len = ll_len(this);

        if(len > 0){
            retorno = 0;
        }
    }

    return retorno;
}

int ll_push(LinkedList* this, int index, void* pElement)// Me parece que tengo que agregar un nodo a la lista, en el medio de esta funcion...
{
    int retorno = -1;
    int len;
    int flag = index;
    Node* pNode;
    Node* pNextNode;
    void* pOldElement = NULL;
    void* pOldElement2 = NULL;

    if(this != NULL && (index > -1 && index < ll_len(this)) && pElement != NULL){
        len = ll_len(this);

        for(int i = index; i < len; i++){
            if(i == flag){

                pNode = getNode(this, i);

                if(pNode != NULL){
                    pOldElement = pNode->pElement;

                    pNode->pElement = pElement;
                }

                pNextNode = getNode(this, i + 1);

                if(pNextNode != NULL){
                    pOldElement2 = pNextNode->pElement;

                    pNextNode->pElement = pOldElement;
                }
                this->size++;
            }else{
                pNode = getNode(this, i);

                if(pNode != NULL){
                    pOldElement = pNode->pElement;

                    pNode->pElement = pOldElement2;
                }

                pNextNode = getNode(this, i + 1);

                if(pNextNode != NULL){
                    pOldElement2 = pNextNode->pElement;

                    pNextNode->pElement = pOldElement;
                }
            }
        }
        retorno = 0;
    }

    return retorno;
}

void* ll_pop(LinkedList* this, int index)
{
    void* retorno = NULL;

    if(this != NULL && index > -1 && index < ll_len(this)){
        retorno = ll_get(this, index);
        ll_remove(this, index);
    }

    return retorno;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int retorno = -1;

    if(this != NULL){
    	retorno = 1;

        if(ll_indexOf(this, pElement) == -1){
            retorno = 0;
        }
    }

    return retorno;
}

int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int retorno = -1;
    int len;
    Node* pNodo;

    if(this != NULL && this2 != NULL){
        retorno = 1;

        len = ll_len(this2);

        for(int i = 0; i < len; i++){
            pNodo = ll_get(this2, i);

            if(ll_contains(this, pNodo->pElement) == 0){
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    int len;
    LinkedList* cloneArray;
    Node* pNodo;

    if(this != NULL && (from > -1 && from < to) && to > from){
        len = ll_len(this);
        cloneArray = ll_newLinkedList();

        if(cloneArray != NULL && to <= len){
            for(int i = from; i < to; i++){
                pNodo = getNode(this, i);

                if(pNodo != NULL)
                    ll_add(cloneArray, pNodo);
            }
        }
    }

    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    int len;
    LinkedList* cloneArray;

    if(this != NULL && cloneArray != NULL){
        len = ll_len(this);
        cloneArray = ll_subList(this, 0, len);
    }

    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int retorno = -1;
    int len;
    int result;
    void* pAuxElemt;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1)){
        len = ll_len(this);

        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){

                result = pFunc(ll_get(this, i), ll_get(this, j));
                if(result == 1 && order == 1){
                    pAuxElemt = ll_get(this, i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAuxElemt);
                }else{
                    if(result == -1 && order == 0){
                        pAuxElemt = ll_get(this, j);
                        ll_set(this, j, ll_get(this, i));
                        ll_set(this, i, pAuxElemt);
                    }
                }

            }
        }
        retorno = 0; // Me decia que estaba mal si devolvia 1, el tester.
    }

    return retorno;
}
