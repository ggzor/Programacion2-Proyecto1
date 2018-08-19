#ifndef _FECHA_HORA_H_
#define _FECHA_HORA_H_

#include "Fecha.h"
#include "Hora.h"

typedef struct
{
  Fecha fecha;
  Hora hora;
} FechaHora;

int compararFechaHoras(FechaHora *fechaHora1, FechaHora *fechaHora2);

#endif