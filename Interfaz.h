#ifndef _INTERFAZ_H_
#define _INTERFAZ_H_

#include <stdio.h>

void leerCaracter(const char *mensaje, char *direccion);
void leerSiNo(const char *mensaje, int *direccion);
void leerEnteroRango(const char *mensaje, int minimo, int maximo, int *direccion);
void leerOpcionNumerica(const char *mensaje, int maximo, int *direccion);
void leerCadena(const char *mensaje, char *direccion);
void leerTelefono(const char *mensaje, long long *direccion);

void imprimirCadena(const char *cadena);

#endif