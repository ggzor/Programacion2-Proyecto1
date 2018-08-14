#include "../Lectura.h"

Hora leerHora(Hora *minimo, Hora *maximo)
{
  Hora hora;
  int datosCorrectos;
  int valido;

  do
  {
    imprimirIntervaloHoras("La hora debe estar entre las ", minimo, maximo);
    printf("Ingrese los campos siguientes: \n");
    leerEnteroRango("Hora: ", 0, 23, &hora.hora);
    leerEnteroRango("Minuto: ", 0, 59, &hora.minuto);

    printf("\nLa hora introducida es: ");
    imprimirHora(&hora);
    puts("");

    valido = estaEntreHoras(&hora, minimo, maximo);

    if (!valido)
    {
      puts("La hora no está entre las horas especificadas. Reintente.\n");
    }
  } while (!valido);

  leerSiNo("¿Son correctos los datos [s/n]? ", &datosCorrectos);

  puts("");
  if (!datosCorrectos)
  {
    editarHora(&hora, minimo, maximo);
  }

  return hora;
}