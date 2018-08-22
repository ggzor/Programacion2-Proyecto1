#include <stdio.h>
#include "../Reservaciones.h"

int obtenerCantidadMesas(Restaurante *restaurante)
{
  int cantidad = 0;
  NodoMesa *actual = restaurante->mesas;

  while (actual != NULL)
  {
    cantidad += 1;
    actual = actual->siguiente;
  }

  return cantidad;
}

int obtenerMaximaCapacidadMesa(Restaurante *restaurante)
{
  int maximo = 0;
  int capacidadActual;
  NodoMesa *actual = restaurante->mesas;

  while (actual != NULL)
  {
    capacidadActual = actual->mesa->capacidad;
    maximo = capacidadActual > maximo ? capacidadActual : maximo;

    actual = actual->siguiente;
  }

  return maximo;
}

Mesa *obtenerMesa(Restaurante *restaurante, int numeroMesa)
{
  Mesa *resultado = NULL;
  NodoMesa *actual = restaurante->mesas;

  while (actual != NULL && resultado == NULL)
  {
    if (actual->mesa->numero == numeroMesa)
    {
      resultado = actual->mesa;
    }
    actual = actual->siguiente;
  }

  return resultado;
}