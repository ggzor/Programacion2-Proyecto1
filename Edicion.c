#include <stdio.h>

#include "Edicion.h"
#include "LecturaValores.h"
#include "Impresion.h"
#include "ImpresionValores.h"
#include "Intervalos.h"

void editarCliente(Cliente *cliente)
{
  char opcion;
  int opcionInvalida;
  int terminar = 0;
  do
  {
    opcionInvalida = 0;

    printf(
        "¿Qué dato desea cambiar?\n"
        "   N.- Nombre\n"
        "   D.- Dirección\n"
        "   T.- Teléfono\n"
        "   F.- Finalizar edición\n");
    leerCaracter("Opción: ", &opcion);

    puts("");
    switch (opcion)
    {
    case 'N':
      leerCadena("Introduzca el nuevo nombre: ", cliente->nombre);
      break;
    case 'D':
      leerCadena("Introduzca la nueva dirección: ", cliente->direccion);
      break;
    case 'T':
      leerTelefono("Introduzca el nuevo teléfono: ", &cliente->telefono);
      break;
    case 'F':
      terminar = 1;
      break;
    default:
      opcionInvalida = 1;
      puts("Opción inválida. Reintente.");
      break;
    }

    if (!terminar && !opcionInvalida)
    {
      puts("");
      puts("Datos actualizados:");
      imprimirCliente(cliente);
      puts("");
    }

  } while (!terminar);
}

void editarHora(Hora *hora, Hora *minimo, Hora *maximo)
{
  char opcion;
  int opcionInvalida;
  int terminar = 0;
  Hora nuevaHora = *hora;
  do
  {
    opcionInvalida = 0;

    imprimirIntervaloHoras(
        "La hora debe estar entre: ",
        minimo, maximo);

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
      if (estaEntreHoras(&nuevaHora, minimo, maximo))
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

void editarFecha(Fecha *fecha, Fecha *minimo, Fecha *maximo)
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
        minimo, maximo);

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
      if (estaEntreFechas(&nuevaFecha, minimo, maximo))
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