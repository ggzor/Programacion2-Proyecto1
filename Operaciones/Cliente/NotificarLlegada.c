#include "../Cliente.h"
#include "../../Configuracion.h"
#include "../../Datos/Impresion.h"
#include "../../Datos/Manejo.h"
#include "../../Datos/InformacionReservacion.h"
#include "../../Interfaz/Interfaz.h"
#include "../../Tiempo/Tiempo.h"
#include <stdio.h>

void notificarLlegada(Restaurante *restaurante)
{
  int clave, estaCancelada;
  FechaHora inicioReservacion;
  FechaHora ahora;
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
      if (reservacion->confirmada)
      {
        imprimirAdvertencia(puts("La reservación ya había sido confirmada."));
      }
      else
      {
        if (esReservacionPasada(reservacion))
        {
          imprimirError(puts("Lo sentimos. El tiempo asignado para esta reservación ya ha terminado."));
        }
        else
        {
          ahora = obtenerAhora();
          inicioReservacion = obtenerInicioHorario(&reservacion->horario);

          if (compararFechaHoras(&ahora, &inicioReservacion) < 0)
          {
            imprimirError(puts("Sólo se puede confirmar una reservación hasta que empiece el horario en el que se reservó."))
          }
          else
          {
            reservacion->confirmada = 1;
            enVerde(puts("Reservación confirmada. ✔"));
          }
        }
      }
    }
  }

  pausar();
}