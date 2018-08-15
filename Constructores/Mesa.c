#include "../Constructores.h"

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

NodoReservacion *agregarListaReservaciones(NodoReservacion *lista, Reservacion *nuevo)
{
  NodoReservacion *nuevoNodo = crearNodoReservacion(nuevo);
  NodoReservacion *actual = lista;

  if (lista == NULL)
  {
    return nuevoNodo;
  }
  else
  {
    while (actual->siguiente != NULL)
    {
      actual = actual->siguiente;
    }

    actual->siguiente = nuevoNodo;
    return lista;
  }
}

void agregarReservacionCancelada(Mesa *mesa, Reservacion *reservacion)
{
  mesa->reservacionesCanceladas = agregarListaReservaciones(mesa->reservacionesCanceladas, reservacion);
}

void agregarReservacion(Mesa *mesa, Reservacion *reservacion)
{
  int antesPrimero, despuesActual = 0;
  NodoReservacion *anterior, *actual = mesa->reservaciones;
  NodoReservacion *nuevoNodo = crearNodoReservacion(reservacion);

  Fecha *fechaActual, *fechaNueva = &reservacion->intervalo.fecha;
  Hora *horaActual, *horaNueva = &reservacion->intervalo.inicio;

  if (actual == NULL)
  {
    mesa->reservaciones = nuevoNodo;
  }
  else
  {
    fechaActual = &actual->reservacion->intervalo.fecha;
    horaActual = &actual->reservacion->intervalo.inicio;

    antesPrimero = compararFechas(fechaNueva, fechaActual) == 0 && compararHoras(horaNueva, horaActual) < 0;
    if (compararFechas(fechaNueva, fechaActual) < 0 || antesPrimero)
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
          fechaActual = &actual->reservacion->intervalo.fecha;
          horaActual = &actual->reservacion->intervalo.inicio;

          despuesActual = compararFechas(fechaActual, fechaNueva) == 0 && compararHoras(horaActual, horaNueva) < 0;
        }
      } while (actual != NULL && (compararFechas(fechaActual, fechaNueva) < 0 || despuesActual));

      anterior->siguiente = nuevoNodo;
      nuevoNodo->siguiente = actual;
    }
  }
}