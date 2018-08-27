#include "../../Interfaz/Color.h"
#include "../Impresion.h"
#include "../InformacionReservacion.h"
#include "../../Tiempo/Impresion.h"
#include <stdio.h>

void imprimirCliente(Cliente *cliente)
{
  printf("Nombre del cliente: %s\n", cliente->nombre);
  printf("Telefono: ");
  enItalica(printf("%lld\n", cliente->telefono));
  printf("Dirección: %s\n", cliente->direccion);
}

void imprimirClaveReservacion(int clave)
{
  enVerde(printf(FormatoClaveReservacion, clave));
}

void imprimirReservacion(Reservacion *reservacion)
{
  printf("Clave de reservación: ");
  imprimirClaveReservacion(reservacion->clave);
  puts("");

  printf("Mesa: ");
  enNegritas(printf("%d", reservacion->mesa->numero));
  puts("");

  printf("Cantidad de personas: %d\n", reservacion->cantidadPersonas);

  imprimirCliente(&reservacion->cliente);

  printf("Confirmada: ");
  if (reservacion->confirmada)
  {
    enVerde(printf("⚑ Sí"));
  }
  else
  {
    if (esReservacionCancelable(reservacion))
    {
      enAmarillo(printf("🕑 No"));
    }
    else
    {
      enNegritas(printf("  No"));
    }
  }
  puts("");

  printf("Cancelada: ");
  if (reservacion->cancelada)
  {
    enRojo(printf(" ✘ Sí"));
  }
  else
  {
    enVerde(printf(" ✔ No"));
  }
  puts("");

  puts("");
  imprimirHorario(&reservacion->horario);
  puts("");
}

void imprimirListaReservaciones(NodoReservacion *lista)
{
  int indice = 0;
  NodoReservacion *actual = lista;
  if (actual == NULL)
  {
    printf("La lista está vacía\n");
  }
  else
  {
    while (actual != NULL)
    {
      enNegritas(printf("%d.-\n", ++indice));
      imprimirReservacion(actual->reservacion);
      puts("");

      actual = actual->siguiente;
    }
  }
}

void imprimirMesa(Mesa *mesa)
{
  printf("Numero de mesa: %d \n", mesa->numero);
  printf("Capacidad de la mesa: %d\n\n", mesa->capacidad);

  puts("Lista reservaciones:\n");
  imprimirListaReservaciones(mesa->reservaciones);

  enRojo(puts("Lista reservaciones canceladas:"));
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
