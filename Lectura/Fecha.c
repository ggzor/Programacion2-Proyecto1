#include "../Lectura.h"
#include "../Tiempo/Fecha.h"

Fecha leerFecha(IntervaloFechas *limites)
{
  Fecha fecha;
  int datosCorrectos;
  int valido;

  do
  {
    imprimirIntervaloFechas("La fecha debe estar entre ", limites);
    printf("Ingrese los campos siguientes: \n");
    leerEnteroRango("Año: ", 2000, 2100, &fecha.anio);
    leerEnteroRango("Mes: ", 1, 12, &fecha.mes);
    leerEnteroRango("Día: ", 1, obtenerDiasEnMes(fecha.anio, fecha.mes), &fecha.dia);

    printf("\nLa fecha introducida es: ");
    imprimirFecha(&fecha);
    puts("");

    valido = estaEnIntervaloFechas(limites, &fecha);

    if (!valido)
    {
      puts("La fecha no está entre las fechas especificadas. Reintente.\n");
    }
  } while (!valido);

  leerSiNo("¿Son correctos los datos [s/n]? ", &datosCorrectos);

  puts("");
  if (!datosCorrectos)
  {
    editarFecha(&fecha, limites);
  }

  return fecha;
}