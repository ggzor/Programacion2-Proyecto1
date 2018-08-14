#ifndef _EDICION_H_
#define _EDICION_H_

#include "Estructuras.h"

void editarCliente(Cliente *cliente);
void editarHora(Hora *hora, Hora *minimo, Hora *maximo);
void editarFecha(Fecha *fecha, Fecha *minimo, Fecha *maximo);
void editarIntervalo(Intervalo *intervalo, Fecha *fechaMinima, Fecha *fechaMaxima, Hora *horaMinima, Hora *horaMaxima);

#endif