#ifndef _EDICION_H_
#define _EDICION_H_

#include <stdio.h>
#include "Estructuras.h"
#include "Tiempo/IntervaloHoras.h"
#include "Tiempo/IntervaloFechas.h"
#include "Tiempo/Horario.h"
#include "Tiempo/FechaHora.h"
#include "Lectura.h"

void editarCliente(Cliente *cliente);
void editarHorario(FechaHora *despuesDe, IntervaloHoras *limitesHora, Fecha *fechaMaxima, Horario *horario);

#endif