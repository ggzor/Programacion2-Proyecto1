#include "../Lectura.h"
#include "../../Interfaz/Interfaz.h"
#include "../../Tiempo/Impresion.h"

Horario leerHorario(FechaHora *despuesDe, IntervaloHoras *limitesHora, Fecha *fechaMaxima, int duracionMinima)
{
  int valido, datosCorrectos = 0;
  Horario horario;

  IntervaloFechas limitesFecha = {despuesDe->fecha, *fechaMaxima};
  IntervaloHoras intervaloHoras = *limitesHora;

  // Si es despues de la hora de cierre.
  if (compararHoras(&despuesDe->hora, &limitesHora->fin) >= 0)
  {
    limitesFecha.inicio = diaSiguiente(&limitesFecha.inicio);
  }

  do
  {
    puts("Especifique la fecha:");
    horario.fecha = leerFecha(&limitesFecha);

    if (sonFechasIguales(&horario.fecha, &despuesDe->fecha))
    {
      intervaloHoras.inicio = *obtenerHoraMayor(&despuesDe->hora, &limitesHora->inicio);
    }

    do
    {
      puts("Especifique la hora de inicio:");
      horario.horas.inicio = leerHora(&intervaloHoras);

      intervaloHoras.inicio = horario.horas.inicio;

      puts("Especifique la hora de salida:");
      imprimirAdvertencia(printf("La duración del intervalo debe ser de al menos %d minutos.\n", duracionMinima));
      horario.horas.fin = leerHora(&intervaloHoras);

      valido = obtenerDiferenciaEnMinutosEntreHoras(&horario.horas.fin, &horario.horas.inicio) >= duracionMinima;

      if (!valido)
      {
        imprimirError(printf("  La duración es menor que la requerida."));

        if (sonFechasIguales(&horario.fecha, &despuesDe->fecha))
        {
          intervaloHoras.inicio = *obtenerHoraMayor(&despuesDe->hora, &limitesHora->inicio);
        }
        else
        {
          intervaloHoras.inicio = limitesHora->inicio;
        }
      }
    } while (!valido);

    puts("");
    puts("Los datos recibidos son los siguientes:");
    imprimirHorario(&horario);
    leerSiNo("¿Son correctos los datos [s/n]? ", &datosCorrectos);
  } while (!datosCorrectos);

  return horario;
}