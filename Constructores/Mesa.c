#include "../Constructores.h"

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

NodoReservacion *agregarListaReservaciones(NodoReservacion *lista, Reservacion *nuevo)
{
  NodoReservacion *nuevoNodo = crearNodoReservacion(nuevo);
  NodoReservacion *actual = lista;

  if (lista == NULL)
  {
    return nuevoNodo;
  }
  else
  {
    while (actual->siguiente != NULL)
    {
      actual = actual->siguiente;
    }

    actual->siguiente = nuevoNodo;
    return lista;
  }
}

void agregarReservacionCancelada(Mesa *mesa, Reservacion *reservacion)
{
  mesa->reservacionesCanceladas = agregarListaReservaciones(mesa->reservacionesCanceladas, reservacion);
}

void agregarReservacion(Mesa *mesa, Reservacion *reservacion)
{
  mesa->reservaciones = agregarListaReservaciones(mesa->reservaciones, reservacion);
}