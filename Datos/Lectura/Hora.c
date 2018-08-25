#include "../Lectura.h"
#include "../../Interfaz/Interfaz.h"
#include "../../Tiempo/Impresion.h"

Hora leerHora(IntervaloHoras *limites)
{
  Hora hora;
  int horaValida, entreLimites, datosCorrectos;

  do
  {
    imprimirAdvertencia({
      printf("La hora debe estar entre las ");
      imprimirIntervaloHoras(limites);
      puts("");
    });

    printf("  Hora: ");
    enAzul(scanf("%d:%d%*c", &hora.hora, &hora.minuto));

    horaValida = esHoraValida(&hora);

    if (!horaValida)
    {
      imprimirError(printf("  La hora no es válida."));
    }
    else
    {
      entreLimites = estaEnIntervaloHoras(limites, &hora);

      if (!entreLimites)
      {
        imprimirError(printf("  La hora no está entre las horas especificadas."));
      }
      else
      {
        leerSiNo("  ¿Son correctos los datos [s/n]? ", &datosCorrectos);
        puts("");
      }
    }
  } while (!horaValida || !entreLimites || !datosCorrectos);

  return hora;
}