#include <time.h>
#include "Tiempo.h"

FechaHora ahoraDeComputadora();
int cambiado = 0;
FechaHora ahora;

FechaHora obtenerAhora()
{
  if (cambiado)
  {
    return ahora;
  }
  else
  {
    return ahoraDeComputadora();
  }
}

void establecerAhora(FechaHora nuevoAhora)
{
  ahora = nuevoAhora;
  cambiado = 1;
}

void reestablecerAhora()
{
  cambiado = 0;
}

Fecha obtenerHoy()
{
  return obtenerAhora().fecha;
}

// Basado en: https://stackoverflow.com/questions/1442116/how-to-get-the-date-and-time-values-in-a-c-program
FechaHora ahoraDeComputadora()
{
  time_t tiempo = time(NULL);
  struct tm valores = *localtime(&tiempo);

  FechaHora ahora = {
      {.anio = valores.tm_year + 1900,
       .mes = valores.tm_mon + 1,
       .dia = valores.tm_mday},
      {.hora = valores.tm_hour,
       .minuto = valores.tm_min}};
       
  return ahora;
}