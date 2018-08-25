#include "Color.h"
#include "Interfaz.h"
#include "Menus.h"

#include <stdio.h>

void *ejecutarMenu(const char *titulo, Menu menu, int cantidadElementos)
{
  int i, opcion;

  puts(titulo);
  for (i = 0; i < cantidadElementos; i++)
  {
    printf("   %d.- %s\n", i + 1, menu[i].nombre);
  }
  enNegritas(leerEnteroRango("Opción: ", 1, cantidadElementos, &opcion));

  return menu[opcion - 1].valor;
}