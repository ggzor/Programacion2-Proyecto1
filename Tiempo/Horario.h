#ifndef _HORARIO_H_
#define _HORARIO_H_

#include "Fecha.h"
#include "IntervaloHoras.h"

typedef struct {
  Fecha fecha;
  IntervaloHoras horas;
} Horario;

int seTranslapanHorarios(Horario *horario1, Horario *horario2);

#endif