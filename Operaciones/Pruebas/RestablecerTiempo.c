#include "../Pruebas.h"
#include "../../Interfaz/Interfaz.h"
#include "../../Tiempo/Impresion.h"
#include "../../Tiempo/Tiempo.h"
#include "../../Tiempo/ManejoTiempo.h"
#include <stdio.h>

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