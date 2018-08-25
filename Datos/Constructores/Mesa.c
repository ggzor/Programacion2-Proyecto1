#include "../Constructores.h"
#include <stdlib.h>

Mesa *crearMesa(int numero, int capacidad)
{
  Mesa *mesa = (Mesa *)malloc(sizeof(Mesa));

  mesa->numero = numero;
  mesa->capacidad = capacidad;
  mesa->reservaciones = NULL;

  return mesa;
}

NodoMesa *crearNodoMesa(Mesa *mesa)
{
  NodoMesa *nodo = (NodoMesa *)malloc(sizeof(NodoMesa));

  nodo->mesa = mesa;
  nodo->siguiente = NULL;

  return nodo;
}

void agregarReservacionCancelada(Mesa *mesa, Reservacion *reservacion)
{
  NodoReservacion *nuevoNodo = crearNodoReservacion(reservacion);
  NodoReservacion *actual = mesa->reservacionesCanceladas;

  reservacion->mesa = mesa;

  if (mesa->reservacionesCanceladas == NULL)
  {
    mesa->reservacionesCanceladas = nuevoNodo;
  }
  else
  {
    while (actual->siguiente != NULL)
    {
      actual = actual->siguiente;
    }

    actual->siguiente = nuevoNodo;
  }
}

void agregarReservacion(Mesa *mesa, Reservacion *reservacion)
{
  NodoReservacion *anterior;
  NodoReservacion *actual = mesa->reservaciones;
  NodoReservacion *nuevoNodo = crearNodoReservacion(reservacion);

  FechaHora fechaHoraActual;
  FechaHora fechaHoraNueva = obtenerInicioHorario(&reservacion->horario);

  reservacion->mesa = mesa;

  if (actual == NULL)
  {
    mesa->reservaciones = nuevoNodo;
  }
  else
  {
    fechaHoraActual = obtenerInicioHorario(&actual->reservacion->horario);
    if (esAntesDeFechaHora(&fechaHoraNueva, &fechaHoraActual))
    {
      nuevoNodo->siguiente = actual;
      mesa->reservaciones = nuevoNodo;
    }
    else
    {
      do
      {
        anterior = actual;
        actual = anterior->siguiente;

        if (actual != NULL)
        {
          fechaHoraActual = obtenerInicioHorario(&actual->reservacion->horario);
        }
      } while (actual != NULL && esAntesDeFechaHora(&fechaHoraActual, &fechaHoraNueva));

      anterior->siguiente = nuevoNodo;
      nuevoNodo->siguiente = actual;
    }
  }
}