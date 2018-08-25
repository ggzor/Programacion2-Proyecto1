#include "IntervaloHoras.h"

int estaEnIntervaloHoras(IntervaloHoras *intervalo, Hora *hora)
{
  if (compararHoras(&intervalo->inicio, hora) <= 0)
  {
    if (compararHoras(hora, &intervalo->fin) <= 0)
    {
      return 1;
    }
  }

  return 0;
}

int estaEnIntervaloHorasExclusivo(IntervaloHoras *intervalo, Hora *hora)
{
  if (compararHoras(&intervalo->inicio, hora) < 0)
  {
    if (compararHoras(hora, &intervalo->fin) < 0)
    {
      return 1;
    }
  }

  return 0;
}

int seTranslapanIntervalosHoras(IntervaloHoras *intervalo1, IntervaloHoras *intervalo2)
{
  if (compararHoras(&intervalo1->inicio, &intervalo2->inicio) == 0)
  {
    if (compararHoras(&intervalo1->fin, &intervalo2->fin) == 0)
    {
      return 1;
    }
  }

  if (estaEnIntervaloHorasExclusivo(intervalo1, &intervalo2->inicio))
    return 1;

  if (estaEnIntervaloHorasExclusivo(intervalo1, &intervalo2->fin))
    return 1;

  if (estaEnIntervaloHorasExclusivo(intervalo2, &intervalo1->inicio))
    return 1;

  if (estaEnIntervaloHorasExclusivo(intervalo2, &intervalo1->fin))
    return 1;

  return 0;
}