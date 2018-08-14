#ifndef _MENU_PRINCIPAL_H_
#define _MENU_PRINCIPAL_H_

#include "../Estructuras.h"
#include "../Menus.h"

typedef struct
{
  char nombre[100];
  AccionMenu (*funcion)(Restaurante *restaurante);
} OperacionRestaurante;
#define tamanoOperacionRestaurante sizeof(OperacionRestaurante)

#endif