#ifndef _MENUS_H_
#define _MENUS_H_

#include "../Datos/Estructuras.h"
#include "../Interfaz/Interfaz.h"

// El tipo de las funciones del menú principal
typedef void (*OperacionRestaurante)(Restaurante *);

typedef struct
{
  const char *const nombre;
  void *const valor;
} ElementoMenu;

void imprimirEncabezado();
#define obtenerCantidadElementosMenu(menu) (sizeof(menu) / sizeof(ElementoMenu))
void *ejecutarMenu(const char *titulo, ElementoMenu *menu, int cantidadElementos);

#define Menu(titulo, args...)                                                \
  {                                                                          \
    OperacionRestaurante operacionSeleccionada;                              \
    ElementoMenu menu[] = {args};                                            \
    int cantidadElementos = obtenerCantidadElementosMenu(menu);              \
                                                                             \
    do                                                                       \
    {                                                                        \
      limpiarPantalla();                                                     \
      imprimirEncabezado();                                                  \
      operacionSeleccionada = ejecutarMenu(titulo, menu, cantidadElementos); \
                                                                             \
      if (operacionSeleccionada != NULL)                                     \
      {                                                                      \
        limpiarPantalla();                                                   \
        operacionSeleccionada(restaurante);                                  \
      }                                                                      \
    } while (operacionSeleccionada != NULL);                                 \
  }

#endif