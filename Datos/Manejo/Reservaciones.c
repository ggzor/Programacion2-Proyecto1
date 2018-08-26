#include "../../Configuracion.h"
#include "../Manejo.h"
#include "../InformacionReservacion.h"

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

Reservacion *buscarReservacionPorClave(Restaurante *restaurante, int clave)
{
  NodoMesa *actual = restaurante->mesas;
  Reservacion *resultado = NULL;

  while (actual != NULL && resultado == NULL)
  {
    resultado = buscarEnListaReservaciones(actual->mesa->reservaciones, clave);

    if (resultado == NULL)
    {
      resultado = buscarEnListaReservaciones(actual->mesa->reservacionesCanceladas, clave);
    }

    actual = actual->siguiente;
  }

  return resultado;
}

void reservar(Mesa *mesa, Reservacion *reservacion, Reservacion **cancelada)
{
  int fueReemplazada = 0;
  NodoReservacion *actual = mesa->reservaciones;

  *cancelada = NULL;
  reservacion->mesa = mesa;
  while (actual != NULL && !fueReemplazada)
  {
    if (!esReservacionPasada(actual->reservacion))
    {
      if (esReservacionCancelable(actual->reservacion))
      {
        if (seTranslapanHorarios(&actual->reservacion->horario, &reservacion->horario))
        {
          agregarReservacionCancelada(mesa, actual->reservacion);
          actual->reservacion->cancelada = 1;
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
