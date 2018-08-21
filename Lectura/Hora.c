#include "../Lectura.h"
#include "../Interfaz.h"
#include "../Color.h"

Hora leerHora(IntervaloHoras *limites)
{
  Hora hora;
  int horaValida, entreLimites, datosCorrectos;

  do
  {
    enAmarillo(printf("> "));
    imprimirIntervaloHoras("La hora debe estar entre las ", limites);

    printf("  Hora: ");
    enAzul(scanf("%d:%d%*c", &hora.hora, &hora.minuto));

    horaValida = esHoraValida(&hora);

    if (!horaValida)
    {
      imprimirError("  La hora no es válida.");
    }
    else
    {
      entreLimites = estaEnIntervaloHoras(limites, &hora);

      if (!entreLimites)
      {
        imprimirError("  La hora no está entre las horas especificadas.");
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