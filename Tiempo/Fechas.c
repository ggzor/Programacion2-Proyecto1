#include "../Tiempo.h"

int compararFechas(Fecha *fecha1, Fecha *fecha2)
{
  if (fecha1->anio < fecha2->anio)
  {
    return -1;
  }
  else if (fecha1->anio > fecha2->anio)
  {
    return 1;
  }
  else
  {
    if (fecha1->mes < fecha2->mes)
    {
      return -1;
    }
    else if (fecha1->mes > fecha2->mes)
    {
      return 1;
    }
    else
    {
      if (fecha1->dia < fecha2->dia)
      {
        return -1;
      }
      else if (fecha1->dia > fecha2->dia)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
  }
}

int sonFechasIguales(Fecha *fecha1, Fecha *fecha2)
{
  return compararFechas(fecha1, fecha2) == 0;
}

int estaEntreFechas(Fecha *fecha, Fecha *minimo, Fecha *maximo)
{
  return compararFechas(minimo, fecha) <= 0 && compararFechas(fecha, maximo) <= 0;
}

Fecha agregarMeses(int meses, Fecha fecha)
{
  Fecha nueva;
  int aniosTranscurridos = ((fecha.mes - 1) + meses) / 12;

  nueva.anio = fecha.anio + aniosTranscurridos;
  nueva.mes = (((fecha.mes - 1) + meses) % 12) + 1;
  nueva.dia = fecha.dia;

  return nueva;
}

Fecha obtenerFechaHoy()
{
  Fecha hoy = {2018, 8, 8};

  return hoy;
}

int obtenerDiasEnMes(int mes, int anio)
{
  static int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (mes == 2)
  {
    if (anio % 4 == 0 && anio % 100 == 0 && anio % 400 != 0)
      return 29;
  }

  return dias[mes - 1];
}
