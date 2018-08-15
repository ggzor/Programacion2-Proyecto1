#include "math.h"
#include "../Constructores.h"
#include "../Configuracion.h"

Reservacion *crearReservacion(Cliente cliente, Intervalo intervalo)
{
  Reservacion *reservacion = (Reservacion *)malloc(sizeof(Reservacion));

  reservacion->clave = rand() % (int)pow(16, DigitosClaveReservacion);
  reservacion->cliente = cliente;
  reservacion->intervalo = intervalo;

  return reservacion;
}

NodoReservacion *crearNodoReservacion(Reservacion *reservacion)
{
  NodoReservacion *nodo = (NodoReservacion *)malloc(sizeof(NodoReservacion));

  nodo->reservacion = reservacion;
  nodo->siguiente = NULL;

  return nodo;
}