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

int obtenerDiferenciaEnMinutosEntreHoras(Hora *hora1, Hora *hora2)
{
  int resultado;
  Hora *mayor = hora1;
  Hora *menor = hora2;

  if (compararHoras(hora2, hora1) > 0)
  {
    mayor = hora2;
    menor = hora1;
  }

  // Acompletar la hora
  resultado += 60 - menor->minuto;

  // Diferencia en horas, considerando que ya se acompleto.
  resultado += (mayor->hora - (menor->hora + 1)) * 60;

  // Minutos desde la hora completada hasta la hora mayor
  resultado += mayor->minuto;

  return resultado;
}