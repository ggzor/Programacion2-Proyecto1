#include "../Impresion.h"

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
    fechaActual = &actual->reservacion->horario.fecha;
    printf("  - ");
    imprimirFecha(fechaActual);
    puts("");

    while (actual != NULL)
    {
      fechaReservacionActual = &actual->reservacion->horario.fecha;

      if (!sonFechasIguales(fechaActual, fechaReservacionActual))
      {
        fechaActual = fechaReservacionActual;

        printf("  - ");
        imprimirFecha(fechaActual);
        puts("");
      }

      imprimirIntervaloHoras(
          "    - ",
          &actual->reservacion->horario.horas);

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