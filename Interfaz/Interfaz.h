#ifndef _INTERFAZ_H_
#define _INTERFAZ_H_

#include "Impresion.h"

void leerCaracter(const char *mensaje, char *direccion);
void leerSiNo(const char *mensaje, int *direccion);
void leerEnteroRango(const char *mensaje, int minimo, int maximo, int *direccion);
void leerCadena(const char *mensaje, char *direccion);
void leerNumero(const char *mensaje, int cantidadDigitos, long long *direccion);
void leerNumeroHexadecimal(const char *mensaje, int cantidadDigitos, int *direccion);

#endif