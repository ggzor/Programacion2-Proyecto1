#include <stdio.h>
#include "Menu.h"
#include "../Impresion.h"
#include "../Tiempo/Tiempo.h"
#include "../Interfaz.h"

void restablecerTiempo(Restaurante *restaurante)
{
  FechaHora ahora;

  puts("Reestableciendo a tiempo actual.");
  reestablecerAhora();
  ahora = obtenerAhora();
  printf("Tiempo actual: ");
  imprimirFechaHora(&ahora);

  pausar();
}