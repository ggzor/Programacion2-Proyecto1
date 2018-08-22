#ifndef _INTERFAZ_H_
#define _INTERFAZ_H_

#include <stdio.h>
#include <stdlib.h>

void leerCaracter(const char *mensaje, char *direccion);
void leerSiNo(const char *mensaje, int *direccion);
void leerEnteroRango(const char *mensaje, int minimo, int maximo, int *direccion);
void leerCadena(const char *mensaje, char *direccion);
void leerTelefono(const char *mensaje, long long *direccion);

void imprimirCadena(const char *cadena);

#define imprimirError(codigo) \
  {                           \
    enRojo({ codigo; printf("\n\n"); };);             \
  }
#define imprimirAdvertencia(codigo) \
  {                                 \
    enAmarillo(printf("> "));       \
    {                               \
      codigo;                       \
    };                              \
  }

#ifdef _WIN32
#define limpiarPantalla() system("cls")
#else
#define limpiarPantalla() system("tput reset")
#endif

#define pausar()                                \
  {                                             \
    printf("Presione enter para continuar..."); \
    getchar();                                  \
  }

#endif