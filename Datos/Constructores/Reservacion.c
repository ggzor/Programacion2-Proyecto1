#include "../Constructores.h"
#include <stdlib.h>

Reservacion *crearReservacion(int clave, int cantidadPersonas, Cliente cliente, Horario horario)
{
  Reservacion *reservacion = (Reservacion *)malloc(sizeof(Reservacion));

  reservacion->clave = clave;
  reservacion->cantidadPersonas = cantidadPersonas;
  reservacion->cliente = cliente;
  reservacion->horario = horario;
  reservacion->confirmada = 0;

  return reservacion;
}

NodoReservacion *crearNodoReservacion(Reservacion *reservacion)
{
  NodoReservacion *nodo = (NodoReservacion *)malloc(sizeof(NodoReservacion));

  nodo->reservacion = reservacion;
  nodo->siguiente = NULL;

  return nodo;
}