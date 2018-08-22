#include <stdio.h>
#include "../Constructores.h"
#include "../Reservaciones.h"
#include "../Tiempo/Tiempo.h"

int esReservacionPasada(Reservacion *reservacion)
{
  FechaHora tiempoFin = obtenerFechaHoraFin(&reservacion->horario);
  FechaHora ahora = obtenerAhora();
  return compararFechaHoras(&tiempoFin, &ahora) <= 0;
}

int esReservacionCancelable(Reservacion *reservacion)
{
  FechaHora tiempoInicio = obtenerFechaHoraInicio(&reservacion->horario);
  FechaHora ahora = obtenerAhora();

  if (sonFechasIguales(&tiempoInicio.fecha, &ahora.fecha))
  {
    return obtenerDiferenciaEnMinutosEntreHoras(&ahora.hora, &tiempoInicio.hora) > 20;
  }
  else
  {
    return 0;
  }
}

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
  
}