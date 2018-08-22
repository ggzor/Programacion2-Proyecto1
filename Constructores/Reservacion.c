#include "math.h"
#include "../Constructores.h"
#include "../Configuracion.h"

Reservacion *crearReservacion(int cantidadPersonas, Cliente cliente, Horario horario)
{
  Reservacion *reservacion = (Reservacion *)malloc(sizeof(Reservacion));

  // Generar un número aleatorio de 4 dígitos hexadecimales.
  reservacion->clave = rand() % (int)pow(16, DigitosClaveReservacion);
  reservacion->cantidadPersonas = cantidadPersonas;
  reservacion->cliente = cliente;
  reservacion->horario = horario;

  return reservacion;
}

NodoReservacion *crearNodoReservacion(Reservacion *reservacion)
{
  NodoReservacion *nodo = (NodoReservacion *)malloc(sizeof(NodoReservacion));

  nodo->reservacion = reservacion;
  nodo->siguiente = NULL;

  return nodo;
}