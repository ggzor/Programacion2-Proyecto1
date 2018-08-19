#include "Hora.h"

int esHoraValida(Hora *hora)
{
  return 0 < hora->hora && hora->hora < 24 && 0 < hora->minuto && hora->minuto < 60;
}

#define MENOR -1
#define IGUAL 0
#define MAYOR 1

int compararHoras(Hora *hora1, Hora *hora2)
{
  if (hora1->hora < hora2->hora)
  {
    return MENOR;
  }
  else if (hora1->hora > hora2->hora)
  {
    return MAYOR;
  }
  else
  {
    if (hora1->minuto < hora2->minuto)
    {
      return MENOR;
    }
    else if (hora1->minuto > hora2->minuto)
    {
      return MAYOR;
    }
    else
    {
      return IGUAL;
    }
  }
}