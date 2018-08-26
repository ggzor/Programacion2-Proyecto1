#include "../Pruebas.h"
#include "../../Datos/Lectura.h"
#include "../../Interfaz/Interfaz.h"
#include "../../Tiempo/Impresion.h"
#include "../../Tiempo/Tiempo.h"
#include "../../Tiempo/ManejoTiempo.h"
#include <stdio.h>

void establecerTiempo(Restaurante *restaurante)
{
  int cambiarFecha, cambiarHora, modificado = 0;
  IntervaloFechas limitesFecha = {
      {2018, 8, 1},
      {2018, 12, 31}};
  IntervaloHoras todoElDia = {
      {0, 0}, {23, 59}};
  FechaHora actual = obtenerAhora();
  FechaHora nueva = actual;

  puts("Establecer tiempo:\n");

  imprimirCadena("El tiempo actual es: ");
  imprimirFechaHora(&actual);
  puts("");

  leerSiNo("¿Desea modificar la fecha [s/n]? ", &cambiarFecha);

  if (cambiarFecha)
  {
    nueva.fecha = leerFecha(&limitesFecha);
    modificado = 1;
  }

  leerSiNo("¿Desea modificar la hora [s/n]? ", &cambiarHora);

  if (cambiarHora)
  {
    nueva.hora = leerHora(&todoElDia);
    modificado = 1;
  }

  if (modificado)
  {
    printf("Estableciendo tiempo: ");
    imprimirFechaHora(&nueva);
    puts("");

    establecerAhora(nueva);
  }
  else
  {
    imprimirAdvertencia(puts("No se modificó el tiempo actual."));
  }

  puts("");
  pausar();
}