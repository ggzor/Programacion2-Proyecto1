#ifndef _INTERVALO_HORAS_H_
#define _INTERVALO_HORAS_H_

#include "Hora.h"

typedef struct {
  Hora inicio;
  Hora fin;
} IntervaloHoras;

int estaEnIntervaloHoras(IntervaloHoras *intervalo, Hora *hora);
int seTranslapanIntervalosHoras(IntervaloHoras *intervalo1, IntervaloHoras *intervalo2);

#endif