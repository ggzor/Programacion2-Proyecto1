#include <stdio.h>
#include "../Reservaciones.h"

Reservacion *buscarReservacionEnLista(NodoReservacion *lista, int clave)
{
  Reservacion *resultado = NULL;
  NodoReservacion *actual = lista;

  while (actual != NULL && resultado == NULL)
  {
    if (actual->reservacion->clave == clave)
    {
      resultado = actual->reservacion;
    }

    actual = actual->siguiente;
  }

  return resultado;
}

Reservacion *buscarReservacionEnMesa(Mesa *mesa, int clave)
{
  return buscarReservacionEnLista(mesa->reservaciones, clave);
}

Reservacion *buscarReservacionCanceladaEnMesa(Mesa *mesa, int clave)
{
  return buscarReservacionEnLista(mesa->reservacionesCanceladas, clave);
}

Reservacion *buscarReservacion(Restaurante *restaurante, int clave)
{
  NodoMesa *actual = restaurante->mesas;
  Reservacion *resultado = NULL;

  while (actual != NULL && resultado == NULL)
  {
    resultado = buscarReservacionEnMesa(actual->mesa, clave);
    actual = actual->siguiente;
  }

  return resultado;
}

Reservacion *buscarReservacionCancelada(Restaurante *restaurante, int clave)
{
  NodoMesa *actual = restaurante->mesas;
  Reservacion *resultado = NULL;

  while (actual != NULL && resultado == NULL)
  {
    resultado = buscarReservacionCanceladaEnMesa(actual->mesa, clave);
    actual = actual->siguiente;
  }

  return resultado;
}

Mesa *buscarMesaReservacion(Restaurante *restaurante, Reservacion *reservacion)
{
  NodoMesa *actual = restaurante->mesas;
  Mesa *resultado = NULL;

  while (actual != NULL && resultado == NULL)
  {
    if (buscarReservacionEnMesa(actual->mesa, reservacion->clave) != NULL)
    {
      resultado = actual->mesa;
    }

    actual = actual->siguiente;
  }

  return resultado;
}