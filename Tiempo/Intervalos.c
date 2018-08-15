#include "../Tiempo.h"

int seTranslapanIntervalos(Intervalo *intervalo1, Intervalo *intervalo2)
{
  if (sonFechasIguales(&intervalo1->fecha, &intervalo2->fecha))
  {
    if (compararHoras(&intervalo1->inicio, &intervalo2->fin) < 0)
    {
      if (compararHoras(&intervalo1->fin, &intervalo2->inicio) > 0)
      {
        return 1;
      }
    }
    if (compararHoras(&intervalo2->inicio, &intervalo1->fin) < 0)
    {
      if (compararHoras(&intervalo2->fin, &intervalo1->inicio) > 0)
      {
        return 1;
      }
    }
  }

  return 0;
}