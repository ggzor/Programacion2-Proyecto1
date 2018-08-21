#include "../Interfaz.h"
#include "../Color.h"

void imprimirCadena(const char *cadena)
{
  printf("%s", cadena);
}

void imprimirError(const char *error)
{
  enRojo(printf("%s\n\n", error));
}