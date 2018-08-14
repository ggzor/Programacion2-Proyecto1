#include "../Interfaz.h"

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

void leerOpcionNumerica(const char *mensaje, int maximo, int *direccion)
{
  int valido;
  do
  {
    imprimirCadena(mensaje);
    scanf("%d%*c", direccion);

    valido = 1 <= *direccion && *direccion <= maximo;

    if (!valido)
    {
      puts("Opción no válida. Reintente.\n");
    }
  } while (!valido);

  *direccion -= 1;
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

void leerTelefono(const char *mensaje, long long *direccion)
{
  int valido;
  do
  {
    imprimirCadena(mensaje);
    scanf("%lld%*c", direccion);

    valido = contarDigitos(*direccion) == 10;
    if (!valido)
    {
      puts("El teléfono no es válido. Reintente.\n");
    }
  } while (!valido);
}