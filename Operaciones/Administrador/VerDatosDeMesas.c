#include "../Administrador.h"
#include "../../Datos/Impresion.h"
#include "../../Datos/Manejo.h"
#include "../../Interfaz/Interfaz.h"
#include <stdio.h>

void verDatosDeMesa(Restaurante *restaurante)
{
  int verOtraMesa, numeroMesa;
  int cantidadMesas = calcularCantidadMesas(restaurante);
  Mesa *mesa;

  do
  {
    puts("\n");
    imprimirAdvertencia(printf("El número de mesa debe estar entre 1 y %d.\n", cantidadMesas));
    leerEnteroRango("Introduzca el número de mesa de la que desea ver sus datos: ", 1, cantidadMesas, &numeroMesa);

    mesa = buscarMesa(restaurante, numeroMesa);
    imprimirMesa(mesa);

    leerSiNo("¿Desea ver los datos de otra mesa [s/n]?: ", &verOtraMesa);
  } while (verOtraMesa);
}