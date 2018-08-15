#include <stdio.h>
#include "Restaurante.h"
#include "Constructores.h"

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

Mesa *obtenerMesaParaReservar(Restaurante *restaurante, int capacidadMesa, Intervalo *intervalo)
{
  int mesaContieneIntervalo;
  Mesa *resultado = NULL;
  NodoMesa *mesaActual = restaurante->mesas;
  NodoReservacion *reservacionActual;

  while (mesaActual != NULL && resultado == NULL)
  {
    if (mesaActual->mesa->capacidad >= capacidadMesa)
    {
      mesaContieneIntervalo = 0;
      reservacionActual = mesaActual->mesa->reservaciones;

      while (reservacionActual != NULL && !mesaContieneIntervalo)
      {
        mesaContieneIntervalo = seTranslapanIntervalos(&reservacionActual->reservacion->intervalo, intervalo);

        reservacionActual = reservacionActual->siguiente;
      }

      if (!mesaContieneIntervalo)
      {
        resultado = mesaActual->mesa;
      }
    }

    mesaActual = mesaActual->siguiente;
  }

  return resultado;
}

int puedeReservarseEn(Restaurante *restaurante, int capacidadMesa, Intervalo *intervalo)
{
  return obtenerMesaParaReservar(restaurante, capacidadMesa, intervalo) != NULL;
}

void reservar(Restaurante *restaurante, int capacidadMesa, Reservacion *reservacion)
{
  Mesa *mesa = obtenerMesaParaReservar(restaurante, capacidadMesa, &reservacion->intervalo);
  agregarReservacion(mesa, reservacion);
}

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