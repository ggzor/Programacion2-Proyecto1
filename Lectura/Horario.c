#include "../Lectura.h"

Horario leerHorario(FechaHora *despuesDe, IntervaloHoras *limitesHora, Fecha *fechaMaxima)
{
  int datosCorrectos;
  Horario horario;

  IntervaloFechas limitesFecha = {
      despuesDe->fecha, *fechaMaxima};
  IntervaloHoras intervaloHoras = *limitesHora;

  puts("Especifique la fecha:");
  horario.fecha = leerFecha(&limitesFecha);

  if (sonFechasIguales(&horario.fecha, &despuesDe->fecha))
  {
    intervaloHoras.inicio = *obtenerHoraMayor(&despuesDe->hora, &limitesHora->inicio);
  }

  puts("Especifique la hora de inicio:");
  horario.horas.inicio = leerHora(&intervaloHoras);

  intervaloHoras.inicio = horario.horas.inicio;

  puts("Especifique la hora de salida:");
  horario.horas.fin = leerHora(&intervaloHoras);

  puts("");
  puts("Los datos recibidos son los siguientes:");
  imprimirHorario(&horario);

  leerSiNo("¿Son correctos los datos [s/n]? ", &datosCorrectos);

  puts("");
  if (!datosCorrectos)
  {
    editarHorario(despuesDe, limitesHora, fechaMaxima, &horario);
  }

  return horario;
}