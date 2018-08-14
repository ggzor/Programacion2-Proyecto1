#include <stdio.h>
#include <ctype.h>
#include "Menus.h"

int seleccionarOpcion(char *texto, char *textoError, int maximo)
{
  int opcion;
  int valido = 0;

  while (!valido)
  {
    imprimirCadena(texto);
    scanf("%d%*c", &opcion);

    valido = 1 <= opcion && opcion <= maximo;

    if (!valido)
    {
      printf("%s\n", textoError);
    }
  }

  return opcion - 1;
}

