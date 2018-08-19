#include "Fecha.h"

#define MENOR -1
#define IGUAL 0
#define MAYOR 1

int compararFechas(Fecha *fecha1, Fecha *fecha2)
{
  if (fecha1->anio < fecha2->anio)
  {
    return MENOR;
  }
  else if (fecha1->anio > fecha2->anio)
  {
    return MAYOR;
  }
  else
  {
    if (fecha1->mes < fecha2->mes)
    {
      return MENOR;
    }
    else if (fecha1->mes > fecha2->mes)
    {
      return MAYOR;
    }
    else
    {
      if (fecha1->dia < fecha2->dia)
      {
        return MENOR;
      }
      else if (fecha1->dia > fecha2->dia)
      {
        return MAYOR;
      }
      else
      {
        return IGUAL;
      }
    }
  }
}

int sonFechasIguales(Fecha *fecha1, Fecha *fecha2)
{
  return compararFechas(fecha1, fecha2) == 0;
}

Fecha agregarMeses(Fecha *fecha, int meses)
{
  Fecha nueva;
  int maximoDiasEnMes;

  int aniosTranscurridos = ((fecha->mes - 1) + meses) / 12;

  nueva.anio = fecha->anio + aniosTranscurridos;
  nueva.mes = (((fecha->mes - 1) + meses) % 12) + 1;
  nueva.dia = fecha->dia;

  // Ajustar dias del mes
  maximoDiasEnMes = obtenerDiasEnMes(nueva.anio, nueva.mes);
  if (nueva.dia > maximoDiasEnMes)
    nueva.dia = maximoDiasEnMes;

  return nueva;
}

int obtenerDiasEnMes(int anio, int mes)
{
  static int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (mes == 2)
  {
    if (anio % 4 == 0 && anio % 100 == 0 && anio % 400 != 0)
      return 29;
  }

  return dias[mes - 1];
}