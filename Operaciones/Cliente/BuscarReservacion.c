#include "../Cliente.h"
#include "../../Configuracion.h"
#include "../../Datos/Impresion.h"
#include "../../Datos/Manejo.h"
#include "../../Interfaz/Interfaz.h"
#include <stdio.h>

void buscarReservacion(Restaurante *restaurante)
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
      imprimirError(puts("Aviso: La reservación está cancelada."));
    }

    imprimirReservacion(reservacion);
  }

  pausar();
}