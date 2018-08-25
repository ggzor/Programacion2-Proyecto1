#include <stdio.h>
#include "../Constructores.h"
#include "../Reservaciones.h"
#include "../Tiempo/Tiempo.h"
#include "../Interfaz.h"

Mesa *obtenerMesaDisponibleParaReservar(Restaurante *restaurante, int cantidadPersonas, Horario *horario)
{
  int puedeReservarEnMesa;
  Mesa *resultado = NULL;
  NodoMesa *mesaActual = restaurante->mesas;
  NodoReservacion *reservacionActual;

  while (mesaActual != NULL && resultado == NULL)
  {
    if (mesaActual->mesa->capacidad >= cantidadPersonas)
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

void reservar(Mesa *mesa, Reservacion *reservacion)
{
  int fueReemplazada = 0;
  NodoReservacion *actual = mesa->reservaciones;

  while (actual != NULL && !fueReemplazada)
  {
    if (!esReservacionPasada(actual->reservacion))
    {
      if (esReservacionCancelable(actual->reservacion))
      {
        if (seTranslapanHorarios(&actual->reservacion->horario, &reservacion->horario))
        {
          agregarReservacionCancelada(mesa, actual->reservacion);
          imprimirError(printf("Atención: Se ha cancelado la reservación %04X.", actual->reservacion->clave));
          actual->reservacion = reservacion;

          fueReemplazada = 1;
        }
      }
    }
    actual = actual->siguiente;
  }

  if (!fueReemplazada)
  {
    agregarReservacion(mesa, reservacion);
  }
}