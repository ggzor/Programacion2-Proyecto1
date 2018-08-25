#include "Interfaz.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>

void leerCaracter(const char *mensaje, char *direccion)
{
  imprimirCadena(mensaje);
  scanf("%c%*c", direccion);
  *direccion = toupper(*direccion);
}

void leerSiNo(const char *mensaje, int *direccion)
{
  int valido;
  char opcion;
  do
  {
    leerCaracter(mensaje, &opcion);

    valido = opcion == 'S' || opcion == 'N';
    if (!valido)
    {
      puts("Elija sí (s) o no (n).\n");
    }
  } while (!valido);

  *direccion = opcion == 'S';
}

void leerEnteroRango(const char *mensaje, int minimo, int maximo, int *direccion)
{
  int valido;
  do
  {
    imprimirCadena(mensaje);
    scanf("%d%*c", direccion);

    valido = minimo <= *direccion && *direccion <= maximo;
    if (!valido)
    {
      printf("El valor debe estar entre %d y %d.\n\n", minimo, maximo);
    }
  } while (!valido);
}

void leerCadena(const char *mensaje, char *direccion)
{
  imprimirCadena(mensaje);
  scanf("%[^\n]%*c", direccion);
}

int contarDigitos(long long n)
{
  if (n < 10)
    return 1;
  else
    return 1 + contarDigitos(n / 10);
}

void leerNumero(const char *mensaje, int cantidadDigitos, long long *direccion)
{
  int valido;
  do
  {
    imprimirAdvertencia(printf("El numero debe tener %d dígitos.\n", cantidadDigitos));
    imprimirCadena(mensaje);
    scanf("%lld%*c", direccion);

    valido = contarDigitos(*direccion) == cantidadDigitos;
    if (!valido)
    {
      puts("El valor no es válido.\n");
    }
  } while (!valido);
}

void leerNumeroHexadecimal(const char *mensaje, int cantidadDigitos, int *direccion)
{
  int valido;
  int numeroMaximo = pow(16, cantidadDigitos);

  do
  {
    imprimirAdvertencia(printf("El valor debe ser un número hexadecimal de %d dígitos. (Máximo %X)\n",
                               cantidadDigitos, numeroMaximo - 1));
    imprimirCadena(mensaje);
    scanf("%X%*c", direccion);

    valido = 0 <= *direccion && *direccion < numeroMaximo;

    if (!valido)
    {
      imprimirError(puts("  El valor está fuera de los límites.\n"));
    }
  } while (!valido);
}