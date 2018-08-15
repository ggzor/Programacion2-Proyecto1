#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Utilerias/DatosPrueba.h"
#include "Almacenamiento.h"
#include "Impresion.h"
#include "Operaciones.h"

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

  srand(time(NULL));
  Restaurante *restaurante = cargarInformacion();
  imprimirRestaurante(restaurante);

  while (accion == Continuar)
  {
    printf("Menú principal:\n");

    for (i = 0; i < cantidadOperaciones; i++)
    {
      printf("   %d.- %s\n", i + 1, operaciones[i].nombre);
    }
    leerOpcionNumerica("Opción: ", cantidadOperaciones, &opcion);

    printf("\n");
    accion = operaciones[opcion].funcion(restaurante);
    printf("\n");
  }

  return 0;
}