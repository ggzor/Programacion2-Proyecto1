#include "Almacenamiento.h"
#include "Configuracion.h"
#include "Interfaz.h"
#include "Menus.h"
#include "Operaciones.h"

typedef void (*OperacionMenu)(Restaurante *);

int main(int argc, char **argv)
{
  OperacionMenu opcionSeleccionada;
  ElementoMenu menu[] = {
      {"Hacer reservacion", hacerReservacion},
      {"Buscar reservacion", buscarReservacion},
      {"Ver horarios de mesas", verHorarios},
      {"Salir", NULL}};
  int cantidadOpciones = obtenerCantidadElementosMenu(menu);

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

  return 0;
}