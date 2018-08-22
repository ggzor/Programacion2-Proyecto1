#include "../Lectura.h"
#include "../Tiempo/Fecha.h"
#include "../Interfaz.h"
#include "../Color.h"

Fecha leerFecha(IntervaloFechas *limites)
{
  Fecha fecha;
  int fechaValida, datosCorrectos, entreLimites;

  do
  {
    imprimirAdvertencia({
      imprimirIntervaloFechas("La fecha debe estar entre ", limites);
    });

    printf("  Fecha: ");
    enMorado(scanf("%d/%d/%d%*c", &fecha.dia, &fecha.mes, &fecha.anio));

    fechaValida = esFechaValida(&fecha);

    if (!fechaValida)
    {
      imprimirError(printf("  La fecha no es válida."));
    }
    else
    {
      entreLimites = estaEnIntervaloFechas(limites, &fecha);

      if (!entreLimites)
      {
        imprimirError(printf("  La fecha no está entre las fechas especificadas."));
      }
      else
      {
        leerSiNo("  ¿Son correctos los datos [s/n]? ", &datosCorrectos);
        puts("");
      }
    }
  } while (!fechaValida || !entreLimites || !datosCorrectos);

  return fecha;
}