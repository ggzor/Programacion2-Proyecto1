#include "Menu.h"
#include "../Interfaz.h"
#include <math.h>
#include "../Configuracion.h"
#include "../Impresion.h"
#include "../Reservaciones.h"

void buscarReservacion(Restaurante *restaurante)
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
        imprimirError(puts("La reservación está cancelada."));
        imprimirReservacion(reservacion);
      }
    }
    else
    {
      imprimirReservacion(reservacion);
    }
  }
  else
  {
    imprimirError(puts("La clave está fuera de los límites."));
  }
  pausar();
}