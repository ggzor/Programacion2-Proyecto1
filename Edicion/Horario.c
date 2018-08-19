#include "../Edicion.h"
#include "../Impresion.h"

void editarHorario(Horario *horario, IntervaloFechas *limitesFecha, IntervaloHoras *limitesHora)
{
  char opcion;
  int opcionInvalida;
  int terminar = 0;
  Horario nuevoHorario = *horario;
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
      imprimirFecha(&nuevoHorario.fecha);
      puts("");

      editarFecha(&nuevoHorario.fecha, limitesFecha);
      break;
    case 'I':
      imprimirCadena("Editando hora de inicio: ");
      imprimirHora(&nuevoHorario.horas.inicio);
      puts("");

      editarHora(&nuevoHorario.horas.inicio, limitesHora);
      break;
    case 'T':
      imprimirCadena("Editando hora de término: ");
      imprimirHora(&nuevoHorario.horas.fin);
      puts("");

      editarHora(&nuevoHorario.horas.fin, limitesHora);
      break;
    case 'F':
      *horario = nuevoHorario;
      terminar = 1;
      break;
    default:
      opcionInvalida = 1;
      puts("Opción inválida. Reintente");
      break;
    }

    if (!terminar && !opcionInvalida)
    {
      if (compararHoras(&nuevoHorario.horas.inicio, &nuevoHorario.horas.fin) < 0)
      {
        puts("Horario actualizado:");
        *horario = nuevoHorario;
        imprimirHorario(&nuevoHorario);
        puts("");
      }
      else
      {
        puts("");
        puts("La hora de inicio está después de la hora de término.");

        nuevoHorario = *horario;

        puts("El horario siendo modificado es:");
        imprimirHorario(&nuevoHorario);
        puts("");
      }
      puts("");
    }
  } while (!terminar);
}