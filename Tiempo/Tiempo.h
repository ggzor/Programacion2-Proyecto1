#ifndef _TIEMPO_H_
#define _TIEMPO_H_

#include "Fecha.h"
#include "FechaHora.h"

FechaHora obtenerAhora();
void establecerAhora(FechaHora nuevoAhora);
void reestablecerAhora();

Fecha obtenerHoy();

#endif