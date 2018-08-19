#include "IntervaloHoras.h"

int estaEnIntervaloHoras(IntervaloHoras *intervalo, Hora *hora)
{
  return compararHoras(&intervalo->inicio, hora) <= 0 && compararHoras(hora, &intervalo->fin) <= 0;
}

int estaEnIntervaloHorasExclusivo(IntervaloHoras *intervalo, Hora *hora)
{
  return compararHoras(&intervalo->inicio, hora) < 0 && compararHoras(hora, &intervalo->fin) < 0;
}

int seTranslapanIntervalosHoras(IntervaloHoras *intervalo1, IntervaloHoras *intervalo2)
{
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