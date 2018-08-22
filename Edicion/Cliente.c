#include <stdio.h>
#include "../Lectura.h"
#include "../Edicion.h"

void editarCliente(Cliente *cliente)
{
  char opcion;
  int opcionInvalida;
  int terminar = 0;
  do
  {
    opcionInvalida = 0;

    printf(
        "¿Qué dato desea cambiar?\n"
        "   N.- Nombre\n"
        "   D.- Dirección\n"
        "   T.- Teléfono\n"
        "   F.- Finalizar edición\n");
    leerCaracter("Opción: ", &opcion);

    puts("");
    switch (opcion)
    {
    case 'N':
      leerCadena("Introduzca el nuevo nombre: ", cliente->nombre);
      break;
    case 'D':
      leerCadena("Introduzca la nueva dirección: ", cliente->direccion);
      break;
    case 'T':
      leerTelefono("Introduzca el nuevo teléfono: ", &cliente->telefono);
      break;
    case 'F':
      terminar = 1;
      break;
    default:
      opcionInvalida = 1;
      puts("Opción inválida. Reintente.");
      break;
    }

    if (!terminar && !opcionInvalida)
    {
      puts("");
      puts("Datos actualizados:");
      imprimirCliente(cliente);
      puts("");
    }

  } while (!terminar);
}