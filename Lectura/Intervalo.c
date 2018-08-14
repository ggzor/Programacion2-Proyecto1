#include "../Lectura.h"

Intervalo leerIntervalo(Fecha *fechaMinima, Fecha *fechaMaxima, Hora *horaMinima, Hora *horaMaxima)
{
  int datosCorrectos;
  Intervalo intervalo;

  puts("Especifique la fecha:");
  intervalo.fecha = leerFecha(fechaMinima, fechaMaxima);

  puts("Especifique la hora de inicio:");
  intervalo.inicio = leerHora(horaMinima, horaMaxima);

  puts("Especifique la hora de salida:");
  intervalo.fin = leerHora(&intervalo.inicio, horaMaxima);

  puts("");
  puts("Los datos recibidos son los siguientes:");
  imprimirIntervalo(&intervalo);

  leerSiNo("¿Son correctos los datos [s/n]? ", &datosCorrectos);

  puts("");
  if (!datosCorrectos)
  {
    editarIntervalo(&intervalo, fechaMinima, fechaMaxima, horaMinima, horaMaxima);
  }

  return intervalo;
}