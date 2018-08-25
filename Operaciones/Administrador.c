#include "Administrador.h"
#include "Menus.h"

void entrarMenuAdministrador(Restaurante *restaurante)
{
  Menu("Menú del administrador:",
       {"Ver horarios de mesas", verHorariosDeMesas},
       {"Ver datos de mesa", verDatosDeMesa},
       {"Volver al menú principal", NULL});
}