#include "../Pruebas.h"
#include "../../Interfaz/Interfaz.h"
#include "../../Tiempo/Impresion.h"
#include "../../Tiempo/Tiempo.h"
#include "../../Tiempo/ManejoTiempo.h"
#include <stdio.h>

void restablecerTiempo(Restaurante *restaurante)
{
  int confirmado;
  FechaHora ahora;

  puts("Reestableciendo a tiempo actual:\n");
  leerSiNo("¿Está seguro que desea restablecer el tiempo actual [s/n]? ", &confirmado);

  if (confirmado)
  {
    reestablecerAhora();
    ahora = obtenerAhora();
    printf("Tiempo actual: ");
    imprimirFechaHora(&ahora);
    puts("");
  }
  else
  {
    imprimirAdvertencia(puts("No se ha modificado el tiempo actual."));
  }

  puts("");
  pausar();
}