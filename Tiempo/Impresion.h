#ifndef _IMPRESION_TIEMPO_H_
#define _IMPRESION_TIEMPO_H_

#include "Primitivas/Fecha.h"
#include "Intervalos/IntervaloFechas.h"

#include "Primitivas/Hora.h"
#include "Intervalos/IntervaloHoras.h"

#include "Primitivas/FechaHora.h"
#include "Horario.h"

void imprimirFecha(Fecha *fecha);
void imprimirIntervaloFechas(IntervaloFechas *intervalo);

void imprimirHora(Hora *hora);
void imprimirIntervaloHoras(IntervaloHoras *intervalo);

void imprimirFechaHora(FechaHora *fechaHora);
void imprimirHorario(Horario *horario);

#endif