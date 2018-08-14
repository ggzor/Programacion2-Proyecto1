#ifndef _LECTURA_VALORES_H_
#define _LECTURA_VALORES_H_

void leerEnteroRango(const char *mensaje, int minimo, int maximo, int *direccion);
void leerCaracter(const char *mensaje, char *direccion);
void leerSiNo(const char *mensaje, int *direccion);
void leerCadena(const char *mensaje, char *direccion);
void leerTelefono(const char *mensaje, long long *direccion);

#endif