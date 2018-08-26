#include "../Cliente.h"
#include "../../Configuracion.h"
#include "../../Datos/Impresion.h"
#include "../../Datos/Manejo.h"
#include "../../Interfaz/Interfaz.h"
#include <stdio.h>

void buscarReservacion(Restaurante *restaurante)
{
  int clave, valida;
  Reservacion *reservacion;

  do
  {
    leerNumeroHexadecimal("  Introduzca su clave de reservación (0 para cancelar): ", CantidadDigitosClave, &clave);

    if (clave == 0)
    {
      return;
    }

    reservacion = buscarReservacionPorClave(restaurante, clave);

    if (reservacion == NULL)
    {
      imprimirError(printf("  La reservación no existe."));
      valida = 0;
    }
    else
    {
      if (reservacion->cancelada)
      {
        imprimirError(printf("  Aviso: La reservación está cancelada."));
      }

      imprimirReservacion(reservacion);
      valida = 1;
    }
  } while (!valida);

  pausar();
}