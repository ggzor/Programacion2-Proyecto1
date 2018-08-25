#include "IntervaloFechas.h"

int estaEnIntervaloFechas(IntervaloFechas *intervalo, Fecha *fecha)
{
  if (compararFechas(&intervalo->inicio, fecha) <= 0)
  {
    if (compararFechas(fecha, &intervalo->fin) <= 0)
    {
      return 1;
    }
  }

  return 0;
}