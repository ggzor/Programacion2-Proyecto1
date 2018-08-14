#include "../Lectura.h"

Cliente leerCliente()
{
  int datosCorrectos;
  Cliente cliente;

  leerCadena("Nombre: ", cliente.nombre);
  leerCadena("Direccion: ", cliente.direccion);
  leerTelefono("Telefono: ", &cliente.telefono);

  leerSiNo("¿Son correctos los datos [s/n]? ", &datosCorrectos);

  puts("");
  if (!datosCorrectos)
  {
    editarCliente(&cliente);
  }

  return cliente;
}