#include "../Edicion.h"
#include "../Impresion.h"

void editarFecha(Fecha *fecha, IntervaloFechas *limites)
{
  char opcion;
  int opcionInvalida;
  int terminar = 0;
  Fecha nuevaFecha = *fecha;
  do
  {
    opcionInvalida = 0;

    imprimirIntervaloFechas(
        "La fecha debe estar entre: ",
        limites);

    printf(
        "¿Qué valor desea cambiar?\n"
        "   A.- Año\n"
        "   M.- Mes\n"
        "   D.- Día\n"
        "   F.- Finalizar edición\n");
    leerCaracter("Opción: ", &opcion);

    puts("");
    switch (opcion)
    {
    case 'A':
      leerEnteroRango(
          "Introduzca el nuevo año: ", 2000, 2100,
          &nuevaFecha.anio);
      break;
    case 'M':
      leerEnteroRango(
          "Introduzca el nuevo mes: ", 1, 12,
          &nuevaFecha.mes);
      break;
    case 'D':
      leerEnteroRango(
          "Introduzca el nuevo día: ", 1, obtenerDiasEnMes(nuevaFecha.mes, nuevaFecha.anio),
          &nuevaFecha.dia);
      break;
    case 'F':
      *fecha = nuevaFecha;
      terminar = 1;
      break;
    default:
      opcionInvalida = 1;
      puts("Opción inválida. Reintente");
      break;
    }

    if (!terminar && !opcionInvalida)
    {
      if (estaEnIntervaloFechas(limites, &nuevaFecha))
      {
        printf("Fecha actualizada: ");
        *fecha = nuevaFecha;
        imprimirFecha(&nuevaFecha);
        puts("");
      }
      else
      {
        puts("");
        puts("La fecha no está entre las fechas dadas.");

        nuevaFecha = *fecha;

        printf("La fecha siendo modificada es: ");
        imprimirFecha(fecha);
        puts("");
      }
      puts("");
    }
  } while (!terminar);
}