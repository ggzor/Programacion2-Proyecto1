#ifndef _LECTURA_H_
#define _LECTURA_H_

#include "Estructuras.h"
#include "../Tiempo/Intervalos/IntervaloHoras.h"
#include "../Tiempo/Intervalos/IntervaloFechas.h"

Cliente leerCliente();
Hora leerHora(IntervaloHoras *limites);
Fecha leerFecha(IntervaloFechas *limites);
Horario leerHorario(FechaHora *despuesDe, IntervaloHoras *limitesHora, Fecha *fechaMaxima, int duracionMinima);

#endif