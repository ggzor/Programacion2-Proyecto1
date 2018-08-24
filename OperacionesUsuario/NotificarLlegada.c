#include "Menu.h"
#include "../Configuracion.h"
#include "../Reservaciones.h"
#include "../Interfaz.h"
#include "math.h"

void notificarLlegada(Restaurante *restaurante)
{
  int clave, claveMaxima = pow(16, DigitosClaveReservacion);
  Reservacion *reservacion;

  imprimirAdvertencia(printf("La clave debe estar entre %04X y %04X\n", 0, claveMaxima - 1));
  printf("Introduzca su clave de reservación: ");
  scanf("%X%*c", &clave);

  if (0 <= clave && clave < claveMaxima)
  {
    reservacion = buscarReservacionPorClave(restaurante, clave);

    if (reservacion == NULL)
    {
      reservacion = buscarReservacionCanceladaPorClave(restaurante, clave);

      if (reservacion == NULL)
      {
        imprimirError(printf("La reservación no existe."));
      }
      else
      {
        imprimirError(puts("La reservación ya fue cancelada porque excedió el tiempo de tolerancia."));
        imprimirReservacion(reservacion);
      }
    }
    else
    {
      reservacion->confirmada = 1;
      enVerde(puts("Reservación confirmada."));
    }
  }
  else
  {
    imprimirError(puts("La clave está fuera de los límites."));
  }
  pausar();
}