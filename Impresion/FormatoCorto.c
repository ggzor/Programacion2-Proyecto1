#include "../Impresion.h"
#include "../Tiempo.h"

void imprimirListaReservacionesFormatoCorto(NodoReservacion *lista)
{
  Fecha *fechaActual, *fechaReservacionActual;
  NodoReservacion *actual = lista;

  if (actual == NULL)
  {
    printf("La lista está vacía.\n");
  }
  else
  {
    fechaActual = &actual->reservacion->intervalo.fecha;
    printf("  - ");
    imprimirFecha(fechaActual);
    puts("");

    while (actual != NULL)
    {
      fechaReservacionActual = &actual->reservacion->intervalo.fecha;

      if (!sonFechasIguales(fechaActual, fechaReservacionActual))
      {
        fechaActual = fechaReservacionActual;

        printf("  - ");
        imprimirFecha(fechaActual);
        puts("");
      }

      imprimirIntervaloHoras(
          "    - ",
          &actual->reservacion->intervalo.inicio,
          &actual->reservacion->intervalo.fin);

      actual = actual->siguiente;
    }
  }
}

void imprimirMesaFormatoCorto(Mesa *mesa)
{
  printf("Mesa %d (%d personas):\n", mesa->numero, mesa->capacidad);
  imprimirListaReservacionesFormatoCorto(mesa->reservaciones);
}

void imprimirListaMesasFormatoCorto(NodoMesa *lista)
{
  NodoMesa *actual = lista;

  if (actual == NULL)
  {
    printf("La lista está vacía\n");
  }
  else
  {
    while (actual != NULL)
    {
      imprimirMesaFormatoCorto(actual->mesa);
      puts("");
      actual = actual->siguiente;
    }
  }
}

void imprimirHorariosRestauranteFormatoCorto(Restaurante *restaurante)
{
  imprimirListaMesasFormatoCorto(restaurante->mesas);
}