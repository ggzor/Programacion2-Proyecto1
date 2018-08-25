#include "Cliente.h"
#include "Menus.h"

void entrarMenuCliente(Restaurante *restaurante)
{
  Menu("Menú del cliente:",
       {"Hacer reservación", hacerReservacion},
       {"Buscar reservación", buscarReservacion},
       {"Notificar llegada", notificarLlegada},
       {"Volver al menú principal", NULL});
}