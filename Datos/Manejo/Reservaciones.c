#include "../../Configuracion.h"
#include "../Manejo.h"
#include "../../Tiempo/Primitivas/FechaHora.h"
#include "../../Tiempo/Tiempo.h"

int esReservacionPasada(Reservacion *reservacion)
{
  FechaHora tiempoFin = obtenerFinHorario(&reservacion->horario);
  FechaHora ahora = obtenerAhora();
  return compararFechaHoras(&tiempoFin, &ahora) <= 0;
}

int esReservacionCancelable(Reservacion *reservacion)
{
  FechaHora tiempoInicio = obtenerInicioHorario(&reservacion->horario);
  FechaHora ahora = obtenerAhora();

  if (sonFechasIguales(&tiempoInicio.fecha, &ahora.fecha))
  {
    if (!reservacion->confirmada)
    {
      if (obtenerDiferenciaEnMinutosEntreHoras(&ahora.hora, &tiempoInicio.hora) > ToleranciaEnMinutos)
      {
        return 1;
      }
    }
  }

  return 0;
}

Reservacion *buscarEnListaReservaciones(NodoReservacion *lista, int clave)
{
  NodoReservacion *actual = lista;
  Reservacion *resultado = NULL;

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

Reservacion *buscarReservacionPorClave(Restaurante *restaurante, int clave, int *estaCancelada)
{
  NodoMesa *actual = restaurante->mesas;
  Reservacion *resultado = NULL;

  while (actual != NULL && resultado == NULL)
  {
    resultado = buscarEnListaReservaciones(actual->mesa->reservaciones, clave);

    if (resultado == NULL)
    {
      buscarEnListaReservaciones(actual->mesa->reservacionesCanceladas, clave);
      *estaCancelada = 1;
    }

    actual = actual->siguiente;
  }

  return resultado;
}

void reservar(Mesa *mesa, Reservacion *reservacion, Reservacion **cancelada)
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
          *cancelada = actual->reservacion;
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
