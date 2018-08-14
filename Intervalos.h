#ifndef _INTERVALOS_H_
#define _INTERVALOS_H_ 

#include "Estructuras.h"

int estaEntreHoras(Hora *hora, Hora *minimo, Hora *maximo);
int estaEntreFechas(Fecha *fecha, Fecha *minimo, Fecha *maximo);
int compararHoras(Hora *hora1, Hora *hora2);

int obtenerDiasEnMes(int mes, int anio);

Fecha obtenerFechaHoy();
Fecha agregarMeses(int meses, Fecha fecha);

#endif