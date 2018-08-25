#include "../Cliente.h"
#include "../../Configuracion.h"
#include "../../Datos/Impresion.h"
#include "../../Datos/Manejo.h"
#include "../../Interfaz/Interfaz.h"
#include <stdio.h>

void notificarLlegada(Restaurante *restaurante)
{
  int clave, estaCancelada;
  Reservacion *reservacion;

  leerNumeroHexadecimal("Introduzca su clave de reservación: ", CantidadDigitosClave, &clave);
  reservacion = buscarReservacionPorClave(restaurante, clave, &estaCancelada);

  if (reservacion == NULL)
  {
    imprimirError(printf("La reservación no existe."));
  }
  else
  {
    if (estaCancelada)
    {
      imprimirError(puts("Lo sentimos. La reservación ya fue cancelada porque excedió el tiempo de tolerancia."));
      imprimirReservacion(reservacion);
    }
    else
    {
      reservacion->confirmada = 1;
      enVerde(puts("Reservación confirmada. ✔"));
    }
  }

  pausar();
}