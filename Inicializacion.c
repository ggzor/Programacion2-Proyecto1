#include <stdio.h>
#include "./Inicializacion.h"
#define CantidadMesas 4

NodoMesa *nuevoNodoMesa(Mesa *mesa)
{
    NodoMesa *nodo = (NodoMesa *)malloc(sizeof(NodoMesa));

    nodo->mesa = mesa;
    nodo->siguiente = NULL;

    return nodo;
}

NodoMesa *agregarListaMesas(NodoMesa *mesas, NodoMesa *nodo)
{
    NodoMesa *actual = mesas;
    if (mesas == NULL)
    {
        return nodo;
    }
    else
    {
        while (actual->siguiente != NULL)
            actual = actual->siguiente;

        actual->siguiente = nodo;
        return mesas;
    }
}

NodoMesa *obtenerMesas()
{
    int i;
    NodoMesa *lista = NULL;
    Mesa mesas[] = {
        {1, 4, NULL},
        {2, 6, NULL},
        {3, 6, NULL},
        {4, 4, NULL}};

    for (i = 0; i < CantidadMesas; i++)
        agregarListaMesas(lista, mesas + i);

    return lista;
}