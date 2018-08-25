#include "InformacionReservacion.h"
#include "../Tiempo/Primitivas/FechaHora.h"
#include "../Tiempo/Tiempo.h"
#include "../Configuracion.h"

int esReservacionPasada(Reservacion *reservacion)
{
  FechaHora tiempoFin = obtenerFinHorario(&reservacion->horario);
  FechaHora ahora = obtenerAhora();
  return compararFechaHoras(&tiempoFin, &ahora) <= 0;
}

int esReservacionAbandonada(Reservacion *reservacion)
{
  return esReservacionPasada(reservacion) && !reservacion->confirmada;
}

int esReservacionCompletada(Reservacion *reservacion)
{
  return esReservacionPasada(reservacion) && reservacion->confirmada;
}

int esReservacionEnCurso(Reservacion *reservacion)
{
  return !esReservacionPasada(reservacion) && reservacion->confirmada;
}

int esReservacionCancelable(Reservacion *reservacion)
{
  FechaHora tiempoInicio = obtenerInicioHorario(&reservacion->horario);
  FechaHora ahora = obtenerAhora();

  if (sonFechasIguales(&tiempoInicio.fecha, &ahora.fecha))
  {
    if (!reservacion->confirmada)
    {
      if (obtenerDiferenciaEnMinutosEntreHoras(&ahora.hora, &tiempoInicio.hora) > ToleranciaEnMinutos)
      {
        return 1;
      }
    }
  }

  return 0;
}