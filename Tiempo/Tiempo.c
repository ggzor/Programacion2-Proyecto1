#include "Tiempo.h"
#include <time.h>

// Basado en: https://stackoverflow.com/questions/1442116/how-to-get-the-date-and-time-values-in-a-c-program
FechaHora obtenerAhora()
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

Fecha obtenerHoy()
{
  return obtenerAhora().fecha;
}