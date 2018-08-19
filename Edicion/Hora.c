#include "../Edicion.h"
#include "../Impresion.h"

void editarHora(Hora *hora, IntervaloHoras *limites)
{
  char opcion;
  int opcionInvalida;
  int terminar = 0;
  Hora nuevaHora = *hora;
  do
  {
    opcionInvalida = 0;

    imprimirIntervaloHoras(
        "La hora debe estar entre: ", limites);

    printf(
        "¿Qué valor desea cambiar?\n"
        "   H.- Hora\n"
        "   M.- Minutos\n"
        "   F.- Finalizar edición\n");
    leerCaracter("Opción: ", &opcion);

    puts("");
    switch (opcion)
    {
    case 'H':
      leerEnteroRango(
          "Introduzca la nueva hora: ", 0, 23,
          &nuevaHora.hora);
      break;
    case 'M':
      leerEnteroRango(
          "Introduzca los nuevos minutos: ", 0, 59,
          &nuevaHora.minuto);
      break;
    case 'F':
      *hora = nuevaHora;
      terminar = 1;
      break;
    default:
      opcionInvalida = 1;
      puts("Opción inválida. Reintente");
      break;
    }

    if (!terminar && !opcionInvalida)
    {
      if (estaEnIntervaloHoras(limites, &nuevaHora))
      {
        printf("Hora actualizada: ");
        *hora = nuevaHora;
        imprimirHora(&nuevaHora);
        puts("");
      }
      else
      {
        puts("");
        puts("La hora no está entre las horas dadas.");

        nuevaHora = *hora;

        printf("La hora siendo modificada es: ");
        imprimirHora(&nuevaHora);
        puts("");
      }
      puts("");
    }
  } while (!terminar);
}