#include "../Impresion.h"

void imprimirCeros(int a)
{
  if (a < 10)
  {
    printf("0");
  }
}

void imprimirCliente(Cliente *cliente)
{
  printf("Nombre: %s\n", cliente->nombre);
  printf("Telefono: %lld\n", cliente->telefono);
  printf("Dirección %s\n", cliente->direccion);
}

void imprimirFecha(Fecha *fecha)
{
  imprimirCeros(fecha->dia);
  printf("%d/", fecha->dia);
  imprimirCeros(fecha->mes);
  printf("%d/", fecha->mes);
  printf("%4d", fecha->anio);
}

void imprimirIntervaloFechas(const char *mensaje, Fecha *inicio, Fecha *fin)
{
  imprimirCadena(mensaje);
  imprimirFecha(inicio);
  printf(" - ");
  imprimirFecha(fin);
  puts("");
}

void imprimirHora(Hora *hora)
{
  imprimirCeros(hora->hora);
  printf("%d:", hora->hora);
  imprimirCeros(hora->minuto);
  printf("%d", hora->minuto);
}

void imprimirIntervaloHoras(const char *mensaje, Hora *inicio, Hora *fin)
{
  imprimirCadena(mensaje);
  imprimirHora(inicio);
  printf(" - ");
  imprimirHora(fin);
  puts("");
}

void imprimirIntervalo(Intervalo *intervalo)
{
  printf("Fecha: ");
  imprimirFecha(&intervalo->fecha);
  puts("");

  printf("Hora de inicio: ");
  imprimirHora(&intervalo->inicio);
  puts("");

  printf("Hora de fin: ");
  imprimirHora(&intervalo->fin);
  puts("");
}

void imprimirReservacion(Reservacion *reservacion)
{
  imprimirCliente(&reservacion->cliente);
  puts("");

  imprimirIntervalo(&reservacion->intervalo);
  puts("");
}

void imprimirListaReservaciones(NodoReservacion *lista)
{
  NodoReservacion *actual;
  actual = lista;
  if (actual == NULL)
  {
    printf("La lista está vacía\n");
  }
  else
  {
    while (actual != NULL)
    {
      imprimirReservacion(actual->reservacion);
      puts("");

      actual = actual->siguiente;
    }
  }
}

void imprimirMesa(Mesa *mesa)
{
  printf("Numero de mesa %d \n", mesa->numero);
  printf("Capacidad de la mesa: %d\n\n", mesa->capacidad);

  puts("Lista reservaciones:");
  imprimirListaReservaciones(mesa->reservaciones);
  puts("\n");

  puts("Lista reservaciones canceladas:");
  imprimirListaReservaciones(mesa->reservacionesCanceladas);
  puts("\n");
}

void imprimirListaMesas(NodoMesa *lista)
{
  NodoMesa *actual;
  actual = lista;
  if (actual == NULL)
  {
    printf("La lista está vacía\n");
  }
  else
  {
    while (actual != NULL)
    {
      puts("= = = = = = = = = = = = = = = =");
      imprimirMesa(actual->mesa);
      puts("");
      actual = actual->siguiente;
    }
  }
}

void imprimirRestaurante(Restaurante *restaurante)
{
  imprimirListaMesas(restaurante->mesas);
}