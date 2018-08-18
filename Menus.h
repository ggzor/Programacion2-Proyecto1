#ifndef _MENUS_H_
#define _MENUS_H_

typedef struct
{
  const char *const nombre;
  void *const valor;
} ElementoMenu;
typedef ElementoMenu *Menu;

#define obtenerCantidadElementosMenu(menu) (sizeof(menu) / sizeof(ElementoMenu))
void *ejecutarMenu(const char *titulo, Menu menu, int cantidadElementos);

#endif