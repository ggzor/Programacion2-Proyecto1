#include "../Lectura.h"
#include "../../Interfaz/Interfaz.h"

Cliente leerCliente()
{
  int datosCorrectos;
  Cliente cliente;

  do
  {
    leerCadena("Nombre: ", cliente.nombre);
    leerCadena("Direccion: ", cliente.direccion);
    leerNumero("Telefono: ", 10, &cliente.telefono);

    leerSiNo("¿Son correctos los datos [s/n]? ", &datosCorrectos);

    puts("");
  } while (!datosCorrectos);

  return cliente;
}