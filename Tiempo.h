#ifndef _TIEMPO_H_
#define _TIEMPO_H_ 

#include "Estructuras.h"

int compararHoras(Hora *hora1, Hora *hora2);
int estaEntreHoras(Hora *hora, Hora *minimo, Hora *maximo);

int sonFechasIguales(Fecha *fecha1, Fecha *fecha2);
int estaEntreFechas(Fecha *fecha, Fecha *minimo, Fecha *maximo);
Fecha agregarMeses(int meses, Fecha fecha);
Fecha obtenerFechaHoy();
int obtenerDiasEnMes(int mes, int anio);

#endif