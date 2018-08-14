#ifndef _MENUS_H
#define _MENUS_H

typedef enum
{
  Continuar,
  Salir
} AccionMenu;

int seleccionarOpcion(char *texto, char *textoError, int maximo);
#endif