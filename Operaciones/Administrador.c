#include "Menu.h"
#include "../Impresion.h"
#include "../Interfaz.h"
#include "../Menus.h"

void entrarMenuOperacionesAdministrador(Restaurante *restaurante)
{
  OperacionRestaurante operacionSeleccionada;
  ElementoMenu menu[] = {
      {"Ver horarios de mesas", verHorariosDeMesas},
      {"Ver datos de mesa", verDatosDeMesa},
      {"Establecer tiempo", establecerTiempo},
      {"Restablecer tiempo", restablecerTiempo},
      {"Volver al menú principal", NULL}};
  int cantidadOpciones = obtenerCantidadElementosMenu(menu);

  do
  {
    limpiarPantalla();
    imprimirEncabezado();
    operacionSeleccionada = ejecutarMenu("Menú del administrador:", menu, cantidadOpciones);

    if (operacionSeleccionada != NULL)
    {
      limpiarPantalla();
      operacionSeleccionada(restaurante);
    }
  } while (operacionSeleccionada != NULL);
}