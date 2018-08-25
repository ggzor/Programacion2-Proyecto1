#include "Menu.h"
#include "../Impresion.h"
#include "../Interfaz.h"
#include "../Reservaciones.h"

void verDatosDeMesa(Restaurante *restaurante)
{
  int verOtraMesa, numeroMesa;
  int cantidadMesas = obtenerCantidadMesas(restaurante);
  Mesa *mesa;

  do
  {
    puts("\n");
    imprimirAdvertencia(printf("El número de mesa debe estar entre 1 y %d.\n", cantidadMesas));
    leerEnteroRango("Introduzca el número de mesa de la que desea ver sus datos: ", 1, cantidadMesas, &numeroMesa);

    mesa = obtenerMesa(restaurante, numeroMesa);
    imprimirMesa(mesa);

    leerSiNo("¿Desea ver los datos de otra mesa [s/n]?: ", &verOtraMesa);
  } while (verOtraMesa);
}