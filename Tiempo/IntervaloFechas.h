#ifndef _INTERVALO_FECHAS_H_
#define _INTERVALO_FECHAS_H_

#include "Fecha.h"

typedef struct
{
  Fecha inicio;
  Fecha fin;
} IntervaloFechas;

int estaEnIntervaloFechas(IntervaloFechas *intervalo, Fecha *fecha);

#endif