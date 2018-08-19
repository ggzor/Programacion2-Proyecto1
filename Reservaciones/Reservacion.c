#include <stdio.h>
#include "../Reservaciones.h"
#include "../Tiempo/Horario.h"

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

Mesa *obtenerMesaParaReservar(Restaurante *restaurante, int capacidadMesa, Horario *horario)
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
        mesaContieneIntervalo = seTranslapanHorarios(&reservacionActual->reservacion->horario, horario);

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

int puedeReservarseEn(Restaurante *restaurante, int capacidadMesa, Horario *horario)
{
  return obtenerMesaParaReservar(restaurante, capacidadMesa, horario) != NULL;
}

void reservar(Restaurante *restaurante, int capacidadMesa, Reservacion *reservacion)
{
  Mesa *mesa = obtenerMesaParaReservar(restaurante, capacidadMesa, &reservacion->horario);
  agregarReservacion(mesa, reservacion);
}