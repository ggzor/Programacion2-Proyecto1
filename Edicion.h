#ifndef _EDICION_H_
#define _EDICION_H_

#include <stdio.h>
#include "Estructuras.h"
#include "Tiempo/IntervaloHoras.h"
#include "Tiempo/IntervaloFechas.h"
#include "Tiempo/Horario.h"

void editarCliente(Cliente *cliente);
void editarHora(Hora *hora, IntervaloHoras *limites);
void editarFecha(Fecha *fecha, IntervaloFechas *limites);
void editarHorario(Horario *horario, IntervaloFechas *limitesFecha, IntervaloHoras *limitesHora);

#endif