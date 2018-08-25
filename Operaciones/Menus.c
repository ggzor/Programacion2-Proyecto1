#include "../Interfaz/Color.h"
#include "../Interfaz/Interfaz.h"
#include "../Tiempo/Impresion.h"
#include "../Tiempo/Tiempo.h"
#include "Menus.h"

#include <stdio.h>

void *ejecutarMenu(const char *titulo, ElementoMenu *menu, int cantidadElementos)
{
  int i, opcion;
  ElementoMenu *actual;

  puts(titulo);
  for (i = 0; i < cantidadElementos; i++)
  {
    actual = menu + i;
    printf("   %d.- %s\n", i + 1, actual->nombre);
  }
  enNegritas(leerEnteroRango("Opción: ", 1, cantidadElementos, &opcion));

  return menu[opcion - 1].valor;
}

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