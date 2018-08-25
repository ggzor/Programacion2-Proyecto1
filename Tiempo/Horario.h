#ifndef _HORARIO_H_
#define _HORARIO_H_

#include "Primitivas/Fecha.h"
#include "Primitivas/FechaHora.h"
#include "Intervalos/IntervaloHoras.h"

typedef struct
{
  Fecha fecha;
  IntervaloHoras horas;
} Horario;

int seTranslapanHorarios(Horario *horario1, Horario *horario2);

FechaHora obtenerFechaHoraInicio(Horario *horario);
FechaHora obtenerFechaHoraFin(Horario *horario);

#endif