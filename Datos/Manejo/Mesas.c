#include "../InformacionReservacion.h"
#include "../Manejo.h"
#include "stdlib.h"

int calcularMaximaCapacidadMesa(Restaurante *restaurante)
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

int calcularCantidadMesas(Restaurante *restaurante)
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

Mesa *buscarMesa(Restaurante *restaurante, int numeroMesa)
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

Mesa *buscarMesaDisponibleParaReservar(Restaurante *restaurante, int cantidadPersonas, Horario *horario)
{
  int puedeReservarEnMesa;
  Mesa *resultado = NULL;
  NodoMesa *mesaActual = restaurante->mesas;
  NodoReservacion *reservacionActual;

  while (mesaActual != NULL && resultado == NULL)
  {
    if (cantidadPersonas <= mesaActual->mesa->capacidad)
    {
      reservacionActual = mesaActual->mesa->reservaciones;

      puedeReservarEnMesa = 1;
      while (reservacionActual != NULL && puedeReservarEnMesa)
      {
        if (!esReservacionPasada(reservacionActual->reservacion))
        {
          if (!esReservacionCancelable(reservacionActual->reservacion))
          {
            if (seTranslapanHorarios(&reservacionActual->reservacion->horario, horario))
            {
              puedeReservarEnMesa = 0;
            }
          }
        }

        reservacionActual = reservacionActual->siguiente;
      }

      if (puedeReservarEnMesa)
      {
        resultado = mesaActual->mesa;
      }
    }

    mesaActual = mesaActual->siguiente;
  }

  return resultado;
}