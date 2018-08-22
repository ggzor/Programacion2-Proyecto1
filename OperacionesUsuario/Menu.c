#include "Menu.h"

#include "../Impresion.h"
#include "../Interfaz.h"
#include "../Menus.h"

void entrarMenuOperacionesUsuario(Restaurante *restaurante)
{
  OperacionRestaurante operacionSeleccionada;
  ElementoMenu menu[] = {
      {"Hacer reservación", hacerReservacion},
      {"Buscar reservación", buscarReservacion},
      {"Notificar llegada", notificarLlegada},
      {"Volver al menú principal", NULL}};
  int cantidadOpciones = obtenerCantidadElementosMenu(menu);

  do
  {
    limpiarPantalla();
    imprimirEncabezado();
    operacionSeleccionada = ejecutarMenu("Menú del cliente:", menu, cantidadOpciones);

    if (operacionSeleccionada != NULL)
    {
      limpiarPantalla();
      operacionSeleccionada(restaurante);
    }
  } while (operacionSeleccionada != NULL);
}