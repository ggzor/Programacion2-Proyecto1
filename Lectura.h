#ifndef _LECTURA_H_
#define _LECTURA_H_

#include <stdio.h>
#include "./Estructuras.h"
#include "Tiempo/IntervaloHoras.h"
#include "Tiempo/IntervaloFechas.h"
#include "Tiempo/Horario.h"
#include "Tiempo/FechaHora.h"
#include "Edicion.h"
#include "Impresion.h"

Cliente leerCliente();
Hora leerHora(IntervaloHoras *limites);
Fecha leerFecha(IntervaloFechas *limites);
Horario leerHorario(FechaHora *despuesDe, IntervaloHoras *limitesHora, Fecha *fechaMaxima, int duracionMinima);

#endif