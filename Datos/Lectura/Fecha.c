#include "../Lectura.h"
#include "../../Interfaz/Interfaz.h"
#include "../../Tiempo/Impresion.h"

Fecha leerFecha(IntervaloFechas *limites)
{
  Fecha fecha;
  int fechaValida, datosCorrectos, entreLimites;

  do
  {
    imprimirAdvertencia({
      printf("La fecha debe estar entre ");
      imprimirIntervaloFechas(limites);
      puts("");
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