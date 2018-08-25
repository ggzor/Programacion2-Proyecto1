#ifndef _INTERFAZ_IMPRESION_H_
#define _INTERFAZ_IMPRESION_H_

#include "Color.h"

#include <stdio.h>

#define imprimirCadena(cadena) printf("%s", cadena)

#define imprimirAdvertencia(codigo) \
  {                                 \
    enAmarillo(printf("> "));       \
    {                               \
      codigo;                       \
    };                              \
  }

#define imprimirError(codigo) \
  {                           \
    enRojo({                  \
      codigo;                 \
      printf("\n\n");         \
    };);                      \
  }

#ifdef _WIN32
#define limpiarPantalla() system("cls")
#else
#define limpiarPantalla() system("clear")
#endif

#define pausar()                                \
  {                                             \
    printf("Presione enter para continuar..."); \
    getchar();                                  \
  }

#endif