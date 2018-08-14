#include <stdio.h>

#include "Utilerias/DatosPrueba.h"
#include "Operaciones/Principal.h"

int main(int argc, char **argv)
{
  int i, opcion;

  OperacionRestaurante operaciones[] = {
      {"Hacer reservacion", HacerReservacion},
      {"Buscar reservacion", BuscarReservacion},
      {"Ver horarios de mesas", VerHorarios},
      {"Salir", SalirPrograma}};
  int cantidadOperaciones = sizeof(operaciones) / tamanoOperacionRestaurante;
  AccionMenu accion = Continuar;

  Restaurante *restaurante = obtenerDatos();

  while (accion == Continuar)
  {
    printf("Menú principal:\n");

    for (i = 0; i < cantidadOperaciones; i++)
    {
      printf("   %d.- %s\n", i + 1, operaciones[i].nombre);
    }
    opcion = seleccionarOpcion("Opción: ", "Opción no válida.", cantidadOperaciones);

    printf("\n");
    accion = operaciones[opcion].funcion(restaurante);
    printf("\n");
  }

  return 0;
}