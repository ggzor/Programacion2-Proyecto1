#include "Almacenamiento.h"
#include "Configuracion.h"
#include "Interfaz.h"
#include "Menus.h"
#include "Operaciones.h"

typedef void (*OperacionMenu)(Restaurante *);

int main(int argc, char **argv)
{
  OperacionMenu opcion;
  ElementoMenu menu[] = {
      {"Hacer reservacion", hacerReservacion},
      {"Buscar reservacion", buscarReservacion},
      {"Ver horarios de mesas", verHorarios},
      {"Salir", NULL}};

  cargarConfiguracion();
  Restaurante *restaurante = cargarInformacion();
  do
  {
    limpiarPantalla();
    opcion = ejecutarMenu("Menú principal: ", menu, obtenerCantidadElementosMenu(menu));

    if (opcion != NULL)
    {
      limpiarPantalla();
      opcion(restaurante);
    }
  } while (opcion != NULL);

  return 0;
}