#include <stdio.h>
#include "../Reservaciones.h"

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