#include "Configuracion.h"
#include "Datos/Almacenamiento.h"
#include "Datos/Estructuras.h"
#include "Operaciones/Menus.h"

int main(int argc, char **argv)
{
  OperacionRestaurante opcionSeleccionada;
  ElementoMenu menu[] = {
      {"Usuario", entrarMenuOperacionesUsuario},
      {"Administrador", entrarMenuOperacionesAdministrador},
      {"Guardar y salir", NULL}};
  int cantidadOpciones = obtenerCantidadElementosMenu(menu);

  // Establece semilla para números aleatorios.
  cargarConfiguracion();
  Restaurante *restaurante = cargarInformacion();

  do
  {
    limpiarPantalla();
    imprimirEncabezado();

    opcionSeleccionada = ejecutarMenu("Menú principal: ", menu, cantidadOpciones);

    if (opcionSeleccionada != NULL)
    {
      opcionSeleccionada(restaurante);
    }
  } while (opcionSeleccionada != NULL);

  guardarInformacion(restaurante);
  return 0;
}