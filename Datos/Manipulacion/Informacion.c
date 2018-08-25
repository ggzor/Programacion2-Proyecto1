#include <stdio.h>
#include "../Reservaciones.h"
#include "../Tiempo/Tiempo.h"

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
    return !reservacion->confirmada && obtenerDiferenciaEnMinutosEntreHoras(&ahora.hora, &tiempoInicio.hora) > 20;
  }
  else
  {
    return 0;
  }
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

Reservacion *buscarReservacionPorClave(Restaurante *restaurante, int clave)
{
  NodoMesa *actual = restaurante->mesas;
  Reservacion *resultado = NULL;

  while (actual != NULL && resultado == NULL)
  {
    resultado = buscarEnListaReservaciones(actual->mesa->reservaciones, clave);
    actual = actual->siguiente;
  }

  return resultado;
}

Reservacion *buscarReservacionCanceladaPorClave(Restaurante *restaurante, int clave)
{
  NodoMesa *actual = restaurante->mesas;
  Reservacion *resultado = NULL;

  while (actual != NULL && resultado == NULL)
  {
    resultado = buscarEnListaReservaciones(actual->mesa->reservacionesCanceladas, clave);
    actual = actual->siguiente;
  }

  return resultado;
}