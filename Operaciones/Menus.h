#ifndef _MENUS_H_
#define _MENUS_H_

#include "../Datos/Estructuras.h"
#include "../Tiempo/Primitivas/FechaHora.h"

// El tipo de las funciones del menú principal
typedef void (*OperacionRestaurante)(Restaurante *, FechaHora *ahora);

typedef struct
{
  const char *const nombre;
  void *const valor;
} ElementoMenu;

// Un menú es una lista de elementos de menú
typedef ElementoMenu *Menu;

#define obtenerCantidadElementosMenu(menu) (sizeof(menu) / sizeof(ElementoMenu))
void *ejecutarMenu(const char *titulo, Menu menu, int cantidadElementos);

#endif