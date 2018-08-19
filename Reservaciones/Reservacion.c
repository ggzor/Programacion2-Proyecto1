#include <stdio.h>
#include "../Reservaciones.h"
#include "../Tiempo/Horario.h"

Mesa *obtenerMesaDisponibleParaReservar(Restaurante *restaurante, int cantidadPersonas, Horario *horario)
{
  int mesaContieneIntervalo;
  Mesa *resultado = NULL;
  NodoMesa *mesaActual = restaurante->mesas;
  NodoReservacion *reservacionActual;

  while (mesaActual != NULL && resultado == NULL)
  {
    if (mesaActual->mesa->capacidad >= cantidadPersonas)
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

void reservar(Mesa *mesa, Reservacion *reservacion)
{
  
}