#include <stdlib.h>
#include "./Constructores.h"

Reservacion *crearReservacion(Cliente cliente, Intervalo intervalo)
{
    Reservacion *reservacion = (Reservacion *)malloc(sizeof(Reservacion));

    reservacion->cliente = cliente;
    reservacion->intervalo = intervalo;

    return reservacion;
}

NodoReservacion *crearNodoReservacion(Reservacion *reservacion)
{
    NodoReservacion *nodo = (NodoReservacion *)malloc(sizeof(NodoReservacion));

    nodo->reservacion = reservacion;
    nodo->siguiente = NULL;

    return nodo;
}

Mesa *crearMesa(int numero, int capacidad)
{
    Mesa *mesa = (Mesa *)malloc(sizeof(Mesa));

    mesa->numero = numero;
    mesa->capacidad = capacidad;
    mesa->reservaciones = NULL;

    return mesa;
}

NodoMesa *crearNodoMesa(Mesa *mesa)
{
    NodoMesa *nodo = (NodoMesa *)malloc(sizeof(NodoMesa));

    nodo->mesa = mesa;
    nodo->siguiente = NULL;

    return nodo;
}

void agregarReservacion(Mesa *mesa, Reservacion *reservacion)
{
    NodoReservacion *nuevoNodo = crearNodoReservacion(reservacion);
    NodoReservacion *actual = mesa->reservaciones;

    if (mesa->reservaciones == NULL)
    {
        mesa->reservaciones = nuevoNodo;
    }
    else
    {
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevoNodo;
    }
}

void agregarMesa(Restaurante *restaurante, Mesa *mesa)
{
    NodoMesa *nuevoNodo = crearNodoMesa(mesa);
    NodoMesa *actual = restaurante->mesas;

    if (restaurante->mesas == NULL)
    {
        restaurante->mesas = nuevoNodo;
    }
    else
    {
        while(actual->siguiente != NULL) {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevoNodo;
    }
}

Restaurante *crearRestaurante()
{
    Restaurante *restaurante = (Restaurante *)malloc(sizeof(Restaurante));

    restaurante->mesas = NULL;
    restaurante->reservacionesCanceladas = NULL;

    return restaurante;
}
