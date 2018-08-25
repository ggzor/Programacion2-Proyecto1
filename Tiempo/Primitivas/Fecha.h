#ifndef _FECHA_H_
#define _FECHA_H_

typedef struct {
  int anio;
  int mes;
  int dia;
} Fecha;

int esFechaValida(Fecha *fecha);

int compararFechas(Fecha *fecha1, Fecha *fecha2);
int sonFechasIguales(Fecha *fecha1, Fecha *fecha2);

Fecha agregarMeses(Fecha *fecha, int meses);
int obtenerDiasEnMes(int anio, int mes);
Fecha diaSiguiente(Fecha *fecha);

#endif