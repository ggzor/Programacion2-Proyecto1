#include "Impresion.h"
#include <stdio.h>

void imprimirFecha(Fecha *fecha)
{
  enMorado(printf("%02d/%02d/%04d", fecha->dia, fecha->mes, fecha->anio));
}

void imprimirIntervaloFechas(IntervaloFechas *intervalo)
{
  imprimirFecha(&intervalo->inicio);
  printf(" - ");
  imprimirFecha(&intervalo->fin);
}

void imprimirHora(Hora *hora)
{
  enAzul(printf("%02d:%02d", hora->hora, hora->minuto));
}

void imprimirIntervaloHoras(IntervaloHoras *intervalo)
{
  imprimirHora(&intervalo->inicio);
  printf(" - ");
  imprimirHora(&intervalo->fin);
}

void imprimirFechaHora(FechaHora *fechaHora)
{
  imprimirFecha(&fechaHora->fecha);
  putchar(' ');
  imprimirHora(&fechaHora->hora);
}

void imprimirHorario(Horario *horario)
{
  printf("Fecha: ");
  imprimirFecha(&horario->fecha);
  puts("");

  printf("Hora de inicio: ");
  imprimirHora(&horario->horas.inicio);
  puts("");

  printf("Hora de fin: ");
  imprimirHora(&horario->horas.fin);
  puts("");
}