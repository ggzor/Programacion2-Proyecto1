#include "../Edicion.h"

void editarIntervalo(Intervalo *intervalo, Fecha *fechaMinima, Fecha *fechaMaxima, Hora *horaMinima, Hora *horaMaxima)
{
  char opcion;
  int opcionInvalida;
  int terminar = 0;
  Intervalo nuevoIntervalo = *intervalo;
  do
  {
    opcionInvalida = 0;
    printf(
        "¿Qué valor desea cambiar?\n"
        "   D.- Fecha\n"
        "   I.- Hora de inicio\n"
        "   T.- Hora de término\n"
        "   F.- Finalizar edición\n");
    leerCaracter("Opción: ", &opcion);

    puts("");
    switch (opcion)
    {
    case 'D':
      imprimirCadena("Editando fecha: ");
      imprimirFecha(&nuevoIntervalo.fecha);
      puts("");

      editarFecha(&nuevoIntervalo.fecha, fechaMinima, fechaMaxima);
      break;
    case 'I':
      imprimirCadena("Editando hora de inicio: ");
      imprimirHora(&nuevoIntervalo.inicio);
      puts("");

      editarHora(&nuevoIntervalo.inicio, horaMinima, horaMaxima);
      break;
    case 'T':
      imprimirCadena("Editando hora de término: ");
      imprimirHora(&nuevoIntervalo.fin);
      puts("");

      editarHora(&nuevoIntervalo.fin, horaMinima, horaMaxima);
      break;
    case 'F':
      *intervalo = nuevoIntervalo;
      terminar = 1;
      break;
    default:
      opcionInvalida = 1;
      puts("Opción inválida. Reintente");
      break;
    }

    if (!terminar && !opcionInvalida)
    {
      if (compararHoras(&nuevoIntervalo.inicio, &nuevoIntervalo.fin) < 0)
      {
        puts("Intervalo actualizado:");
        *intervalo = nuevoIntervalo;
        imprimirIntervalo(&nuevoIntervalo);
        puts("");
      }
      else
      {
        puts("");
        puts("La hora de inicio está después de la hora de término.");

        nuevoIntervalo = *intervalo;

        puts("El intervalo siendo modificado es:");
        imprimirIntervalo(&nuevoIntervalo);
        puts("");
      }
      puts("");
    }
  } while (!terminar);
}