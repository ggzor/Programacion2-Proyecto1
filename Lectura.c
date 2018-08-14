#include <stdio.h>

#include "Lectura.h"
#include "Edicion.h"
#include "LecturaValores.h"
#include "Impresion.h"
#include "Intervalos.h"

Cliente leerCliente()
{
  int datosCorrectos;
  Cliente cliente;

  printf("Ingrese sus datos:\n");
  leerCadena("Nombre: ", cliente.nombre);
  leerCadena("Direccion: ", cliente.direccion);
  leerTelefono("Telefono: ", &cliente.telefono);

  leerSiNo("¿Son correctos los datos [s/n]? ", &datosCorrectos);

  puts("");
  if (!datosCorrectos)
  {
    editarCliente(&cliente);
  }

  return cliente;
}

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

Intervalo leerIntervalo(Fecha *fechaMinima, Fecha *fechaMaxima, Hora *horaMinima, Hora *horaMaxima)
{
  int datosCorrectos;
  Intervalo intervalo;

  puts("Especifique la fecha:");
  intervalo.fecha = leerFecha(fechaMinima, fechaMaxima);

  puts("Especifique la hora de inicio:");
  intervalo.inicio = leerHora(horaMinima, horaMaxima);

  puts("Especifique la hora de salida:");
  intervalo.fin = leerHora(&intervalo.inicio, horaMaxima);

  puts("");
  puts("Los datos recibidos son los siguientes:");
  imprimirIntervalo(&intervalo);

  leerSiNo("¿Son correctos los datos [s/n]? ", &datosCorrectos);

  puts("");
  if (!datosCorrectos)
  {
    editarIntervalo(&intervalo, fechaMinima, fechaMaxima, horaMinima, horaMaxima);
  }

  return intervalo;
}