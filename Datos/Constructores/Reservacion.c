#include "../Constructores.h"
#include <math.h>
#include <stdlib.h>

Reservacion *crearReservacion(int cantidadPersonas, Cliente cliente, Horario horario)
{
  Reservacion *reservacion = (Reservacion *)malloc(sizeof(Reservacion));

// Generar un número aleatorio de 4 dígitos hexadecimales.
  reservacion->clave = rand() % (int)pow(16, 4);
  reservacion->cantidadPersonas = cantidadPersonas;
  reservacion->cliente = cliente;
  reservacion->horario = horario;
  reservacion->confirmada = 0;
  reservacion->cancelada = 0;
  reservacion->mesa = NULL;

  return reservacion;
}

NodoReservacion *crearNodoReservacion(Reservacion *reservacion)
{
  NodoReservacion *nodo = (NodoReservacion *)malloc(sizeof(NodoReservacion));

  nodo->reservacion = reservacion;
  nodo->siguiente = NULL;

  return nodo;
}