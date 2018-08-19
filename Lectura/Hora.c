#include "../Lectura.h"

Hora leerHora(IntervaloHoras *limites)
{
  Hora hora;
  int datosCorrectos;
  int valido;

  do
  {
    imprimirIntervaloHoras("La hora debe estar entre las ", limites);
    printf("Ingrese los campos siguientes: \n");
    leerEnteroRango("Hora: ", 0, 23, &hora.hora);
    leerEnteroRango("Minuto: ", 0, 59, &hora.minuto);

    printf("\nLa hora introducida es: ");
    imprimirHora(&hora);
    puts("");

    valido = estaEnIntervaloHoras(limites, &hora);

    if (!valido)
    {
      puts("La hora no está entre las horas especificadas. Reintente.\n");
    }
  } while (!valido);

  leerSiNo("¿Son correctos los datos [s/n]? ", &datosCorrectos);

  puts("");
  if (!datosCorrectos)
  {
    editarHora(&hora, limites);
  }

  return hora;
}