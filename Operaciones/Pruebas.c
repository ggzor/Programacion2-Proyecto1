#include "Menus.h"
#include "Pruebas.h"

void entrarMenuPruebas(Restaurante *restaurante)
{
  Menu("Menú para hacer pruebas:",
       {"Establecer tiempo", establecerTiempo},
       {"Reestablecer tiempo", restablecerTiempo},
       {"Volver al menú principal", NULL});
}