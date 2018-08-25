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

Fecha diaSiguiente(Fecha *fecha)
{
  Fecha nueva = *fecha;

  if (fecha->mes == 12 && fecha->dia == 31)
  {
    nueva.anio += 1;
  }

  if (obtenerDiasEnMes(fecha->anio, fecha->mes) == fecha->dia)
  {
    nueva.mes = ((nueva.mes) % 12) + 1;
  }

  nueva.dia = (nueva.dia + 1) % obtenerDiasEnMes(fecha->anio, fecha->mes);

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

int esFechaValida(Fecha *fecha)
{
  if (fecha->anio >= 0)
  {
    if (1 <= fecha->mes && fecha->mes <= 12)
    {
      if (1 <= fecha->dia && fecha->dia <= obtenerDiasEnMes(fecha->anio, fecha->mes))
      {
        return 1;
      }
    }
  }

  return 0;
}