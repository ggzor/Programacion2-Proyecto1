#include "Almacenamiento.h"
#include "Configuracion.h"
#include "Interfaz.h"
#include "Menus.h"
#include "Operaciones.h"

// El tipo de las funciones del menú principal.
typedef void (*OperacionMenu)(Restaurante *);

int main(int argc, char **argv)
{
  OperacionMenu opcionSeleccionada;
  ElementoMenu menu[] = {
      {"Hacer reservacion", hacerReservacion},
      {"Buscar reservacion", buscarReservacion},
      {"Ver horarios de mesas", verHorarios},
      {"Establecer tiempo actual", establecerTiempo},
      {"Restablecer tiempo actual", restablecerTiempo},
      {"Salir", NULL}};
  int cantidadOpciones = obtenerCantidadElementosMenu(menu);

  // Establece semilla para números aleatorios.
  cargarConfiguracion();
  Restaurante *restaurante = cargarInformacion();

  do
  {
    limpiarPantalla();
    opcionSeleccionada = ejecutarMenu("Menú principal: ", menu, cantidadOpciones);

    if (opcionSeleccionada != NULL)
    {
      limpiarPantalla();
      opcionSeleccionada(restaurante);
    }
  } while (opcionSeleccionada != NULL);

  guardarInformacion(restaurante);
  return 0;
}