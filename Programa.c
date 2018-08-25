#include "Configuracion.h"
#include "Datos/Almacenamiento.h"
#include "Datos/Estructuras.h"

#include "Operaciones/Menus.h"
#include "Operaciones/Administrador.h"
#include "Operaciones/Cliente.h"
#include "Operaciones/Pruebas.h"

int main(int argc, char **argv)
{
  // Establece semilla para números aleatorios.
  cargarConfiguracion();
  Restaurante *restaurante = cargarInformacion();

  Menu("Menú principal:",
       {"Cliente", entrarMenuCliente},
       {"Administrador", entrarMenuAdministrador},
       {"Pruebas", entrarMenuPruebas},
       {"Guardar y salir", NULL});

  guardarInformacion(restaurante);
  return 0;
}