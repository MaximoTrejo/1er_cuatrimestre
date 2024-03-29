/*
 * LinkedList.c
 *
 *  Created on: 11 oct. 2022
 *      Author: river
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int len = ll_len(this);

	if(this != NULL && nodeIndex >= 0 && nodeIndex < len)
	{
		pNode = this->pFirstNode;
		for(int i=0;i<nodeIndex;i++)
		{
			pNode = pNode->pNextNode;
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


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	Node* pNode = NULL;
	Node* pNodeViejo = NULL;
	int len = ll_len(this);

	pNode = (Node*) malloc(sizeof(Node*));
	if (this != NULL && nodeIndex >= 0 && nodeIndex <= len && pNode != NULL)
		{
			if(nodeIndex == 0) //si quiero ingresarlo al indice 0
			{
				pNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pNode;
			}
			else //si ya hay nodos en la lista
			{
				pNodeViejo = getNode(this,nodeIndex - 1);
				pNode->pNextNode = pNodeViejo->pNextNode;
				pNodeViejo->pNextNode = pNode;
			}
			pNode->pElement = pElement;
			this->size++;
			returnAux = 0;
		}
    return returnAux;
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


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    if (this!=NULL && !addNode(this, len, pElement))
	{
		returnAux = 0;
	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;
    int len = ll_len(this);
    pNode = (Node*) malloc(sizeof(Node));

    if(this !=NULL && index >= 0 && index < len && pNode != NULL)
    {
        pNode = getNode(this, index);
        returnAux = pNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;
    int len = ll_len(this);
    pNode = (Node*) malloc (sizeof(Node));

    if(this != NULL && index >= 0 && index <= len)
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode = NULL;
    Node* pNodeAux = NULL;
    int len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    	pNode = getNode(this, index);
    	if(index == 0 && pNode != NULL)
    	{
    		this->pFirstNode = pNode->pNextNode;
    	}
    	else
    	{
    		pNodeAux = getNode(this, index - 1);
    		pNodeAux->pNextNode = pNode->pNextNode;
    	}
    	this->size--;
    	free(pNode);
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len = ll_len(this);

    if(this!=NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            if(!ll_remove(this, i))
            {
            	returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL && !ll_clear(this))
    {
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;
    int len = ll_len(this);
    pNode = (Node*) malloc(sizeof(Node));

    if(this != NULL)
    {
    	for(int i=0;i<=len;i++)
    	{
    		pNode = getNode(this, i);
    		if(pNode != NULL && pNode->pElement == pElement)
    		{
				returnAux = i;
				break;
    		}
    	}
    }
    return returnAux;
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

    if (this!=NULL)
    {
        if (this->size > 0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
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
    int len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len && !addNode(this, index, pElement))
	{
		returnAux = 0;
	}

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
    Node* pNode = NULL;
    int len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;
    		ll_remove(this, index);
    	}
    }
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

    if(this != NULL)
    {
    	if(ll_indexOf(this, pElement) != -1)
		{
    		returnAux = 1;
		}
    	else
    	{
    		returnAux = 0;
    	}
    }
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
    int len = ll_len(this2);

    if(this != NULL && this2 != NULL)
    {
    	if(len > 0)
    	{
    		for (int i=0; i<len; i++)
			{
				if (ll_contains(this, ll_get(this2,i)))
				{
					returnAux = 1;
				}
				else
				{
					returnAux = 0;
					break;
				}
			}
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }
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
    LinkedList* cloneThis = NULL;
    void* pElementosIndicados = NULL;
    int len = ll_len(this);

    if(this != NULL && from >= 0 && from <= len && to >= 0 && to <= len)
    {
    	cloneThis = ll_newLinkedList();
    	for(int i = from; i <= to ; i++)
    	{
    		pElementosIndicados = ll_get(this, i);
    		ll_add(cloneThis, pElementosIndicados);
    	}
    }
    return cloneThis;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneThis = NULL;
    int len = ll_len(this);

    if(this != NULL)
    {
    	cloneThis = ll_subList(this, 0, len);
    }
    return cloneThis;
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
    void* pElementoAuxiliar = NULL;
    int len = ll_len(this);
    int i;
    int j;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1) && len > 0)
    {
    	for(i=0;i<len;i++)
    	{
    		for(j=i+1;j<len;j++)
    		{
    			if(order == 0 && pFunc(ll_get(this, i), ll_get(this, j))<0)
				{
    				pElementoAuxiliar = ll_get(this,i);
					ll_set(this, i, ll_get(this,j));
					ll_set(this, j, pElementoAuxiliar);
				}
				else if(order == 1 && pFunc(ll_get(this, i), ll_get(this, j))>0)
				{
					pElementoAuxiliar = ll_get(this,i);
					ll_set(this, i, ll_get(this,j));
					ll_set(this, j, pElementoAuxiliar);
				}
    		}
    	}
    	returnAux = 0;
    }
    return returnAux;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*)){
    LinkedList* filterList;
    int len = ll_len(this);
    int i;
    if (this != NULL){
        filterList = ll_newLinkedList();
        if (filterList != NULL)
        {
            for (i=0; i<len; i++)
            {
                if (pFunc(ll_get(this, i)) != 0)
                {
                    ll_add(filterList, ll_get(this, i));
                }
            }
        }
    }
    return filterList;
}

LinkedList* ll_map(LinkedList *this, void (*pFunc)(void *element)) {
	void *aux = NULL;
	if (this != NULL && pFunc != NULL)
	{
		for (int i = 0; i < ll_len(this); i++)
		{
			aux = ll_get(this, i);
			pFunc(aux);
		}
	}
	return this;
}

int ll_count(LinkedList *this, int (*pFunc)(void *element)) {
	int retorno = 0;
	void *aux = NULL;
	if (this != NULL && pFunc != NULL)
	{
		for (int i = 0; i < ll_len(this); i++)
		{
			aux = ll_get(this, i);
			retorno = retorno + pFunc(aux);
		}
	}
	return retorno;
}
