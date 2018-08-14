#include "../Tiempo.h"

int estaEntreFechas(Fecha *fecha, Fecha *minimo, Fecha *maximo)
{
  if (minimo->anio <= fecha->anio && fecha->anio <= maximo->anio)
  {
    if (minimo->anio == fecha->anio)
    {
      if (minimo->mes <= fecha->mes)
      {
        if (minimo->mes == fecha->mes)
        {
          return minimo->dia <= fecha->dia;
        }
        else
        {
          return 1;
        }
      }
    }
    else if (fecha->anio == maximo->anio)
    {
      if (fecha->mes <= maximo->mes)
      {
        if (fecha->mes == maximo->mes)
        {
          return fecha->dia <= maximo->dia;
        }
        else
        {
          return 1;
        }
      }
    }
    else
    {
      return 1;
    }
  }

  return 0;
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
  Fecha hoy = {2018, 8, 13};

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
