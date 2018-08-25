#include "IntervaloFechas.h"

int estaEnIntervaloFechas(IntervaloFechas *intervalo, Fecha *fecha) {
  return compararFechas(&intervalo->inicio, fecha) <= 0 && compararFechas(fecha, &intervalo->fin) <= 0;
}