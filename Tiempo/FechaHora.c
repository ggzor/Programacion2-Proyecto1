#include "FechaHora.h"

#define MENOR -1
#define IGUAL 0
#define MAYOR 1

int compararFechaHoras(FechaHora *fechaHora1, FechaHora *fechaHora2)
{
  if (compararFechas(&fechaHora1->fecha, &fechaHora2->fecha) < 0)
  {
    return MENOR;
  }
  else if (compararFechas(&fechaHora1->fecha, &fechaHora2->fecha) > 0)
  {
    return MAYOR;
  }
  else
  {
    if (compararHoras(&fechaHora1->hora, &fechaHora2->hora) < 0)
    {
      return MENOR;
    }
    else if (compararHoras(&fechaHora1->hora, &fechaHora2->hora) > 0)
    {
      return MAYOR;
    }
    else
    {
      return IGUAL;
    }
  }
}