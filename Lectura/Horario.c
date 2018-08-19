#include "../Lectura.h"

Horario leerHorario(IntervaloFechas *limitesFecha, IntervaloHoras *limitesHora)
{
  int datosCorrectos;
  Horario horario;

  puts("Especifique la fecha:");
  horario.fecha = leerFecha(limitesFecha);

  puts("Especifique la hora de inicio:");
  horario.horas.inicio = leerHora(limitesHora);

  puts("Especifique la hora de salida:");
  horario.horas.fin = leerHora(limitesHora);

  puts("");
  puts("Los datos recibidos son los siguientes:");
  imprimirHorario(&horario);

  leerSiNo("¿Son correctos los datos [s/n]? ", &datosCorrectos);

  puts("");
  if (!datosCorrectos)
  {
    editarHorario(&horario, limitesFecha, limitesHora);
  }

  return horario;
}