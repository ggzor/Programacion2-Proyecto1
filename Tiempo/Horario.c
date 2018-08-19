#include "Horario.h"

int seTranslapanHorarios(Horario *horario1, Horario *horario2)
{
  if (sonFechasIguales(&horario1->fecha, &horario2->fecha))
  {
    if (seTranslapanIntervalosHoras(&horario1->horas, &horario2->horas))
    {
      return 1;
    }
  }
  return 0;
}