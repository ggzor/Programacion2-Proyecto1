#include "../Interfaz/Impresion.h"
#include "../Tiempo/Primitivas/FechaHora.h"
#include "../Tiempo/Tiempo.h"
#include <stdio.h>

void imprimirFechaHoraActual()
{
  FechaHora ahora = obtenerAhora();
  imprimirCadena("Fecha y hora: ");
  imprimirFechaHora(&ahora);
  puts("\n");
}

void imprimirEncabezado()
{
  enVerde(puts("Fonda Doña Yoyis"));
  imprimirFechaHoraActual();
}