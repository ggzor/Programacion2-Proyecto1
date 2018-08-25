#include "../../Interfaz/Color.h"
#include "../Impresion.h"
#include <stdio.h>

void imprimirCliente(Cliente *cliente)
{
  printf("Nombre: %s\n", cliente->nombre);
  printf("Telefono: %lld\n", cliente->telefono);
  printf("Dirección %s\n", cliente->direccion);
}

void imprimirClaveReservacion(int clave)
{
  enVerde(printf(FormatoClaveReservacion, clave));
}

void imprimirReservacion(Reservacion *reservacion)
{
  printf("Clave de reservación: ");
  imprimirClaveReservacion(reservacion->clave);
  puts("\n");

  printf("Cantidad de personas: %d\n", reservacion->cantidadPersonas);
  imprimirCliente(&reservacion->cliente);

  printf("Confirmada: ");
  if (reservacion->confirmada)
  {
    enVerde(printf("✔"));
  }
  else
  {
    enAmarillo(printf("No."));
  }
  puts("\n");

  imprimirHorario(&reservacion->horario);
  puts("");
}

void imprimirListaReservaciones(NodoReservacion *lista)
{
  NodoReservacion *actual = lista;
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
