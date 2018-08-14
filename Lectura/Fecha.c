#include "../Lectura.h"

Fecha leerFecha(Fecha *minimo, Fecha *maximo)
{
  Fecha fecha;
  int datosCorrectos;
  int valido;

  do
  {
    imprimirIntervaloFechas("La fecha debe estar entre ", minimo, maximo);
    printf("Ingrese los campos siguientes: \n");
    leerEnteroRango("Año: ", 2000, 2100, &fecha.anio);
    leerEnteroRango("Mes: ", 1, 12, &fecha.mes);
    leerEnteroRango("Día: ", 1, obtenerDiasEnMes(fecha.mes, fecha.anio), &fecha.dia);

    printf("\nLa fecha introducida es: ");
    imprimirFecha(&fecha);
    puts("");

    valido = estaEntreFechas(&fecha, minimo, maximo);

    if (!valido)
    {
      puts("La fecha no está entre las fechas especificadas. Reintente.\n");
    }
  } while (!valido);

  leerSiNo("¿Son correctos los datos [s/n]? ", &datosCorrectos);

  puts("");
  if (!datosCorrectos)
  {
    editarFecha(&fecha, minimo, maximo);
  }

  return fecha;
}