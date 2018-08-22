#ifndef _HORARIO_H_
#define _HORARIO_H_

#include "Fecha.h"
#include "IntervaloHoras.h"
#include "FechaHora.h"

typedef struct
{
  Fecha fecha;
  IntervaloHoras horas;
} Horario;

int seTranslapanHorarios(Horario *horario1, Horario *horario2);
FechaHora obtenerFechaHoraInicio(Horario *horario);

#endif