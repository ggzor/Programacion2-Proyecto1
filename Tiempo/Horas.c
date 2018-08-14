#include "../Tiempo.h"

int estaEntreHoras(Hora *hora, Hora *minimo, Hora *maximo)
{
  if (minimo->hora <= hora->hora && hora->hora <= maximo->hora)
  {
    if (minimo->hora == hora->hora)
    {
      return minimo->minuto <= hora->minuto;
    }
    else if (hora->hora == maximo->hora)
    {
      return hora->minuto <= maximo->minuto;
    }
    else
    {
      return 1;
    }
  }

  return 0;
}

int compararHoras(Hora *hora1, Hora *hora2)
{
  if (hora1->hora == hora2->hora)
  {
    if (hora1->minuto == hora2->minuto)
    {
      return 0;
    }
    else
    {
      if (hora1->minuto < hora2->minuto)
      {
        return -1;
      }
      else
      {
        return 1;
      }
    }
  }
  else
  {
    if (hora1->hora < hora2->hora)
    {
      return -1;
    }
    else
    {
      return 1;
    }
  }
}