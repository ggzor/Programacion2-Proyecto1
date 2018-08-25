#include "../Impresion.h"
#include "../../Interfaz/Color.h"
#include "../../Tiempo/Impresion.h"
#include <stdio.h>

void imprimirListaReservacionesFormatoCorto(NodoReservacion *lista)
{
  NodoReservacion *actual = lista;
  Fecha *fechaActual, *fechaReservacionActual;

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

      printf("    - ");
      imprimirIntervaloHoras(&actual->reservacion->horario.horas);
      printf(" (");
      imprimirClaveReservacion(actual->reservacion->clave);
      printf(") ");
      if (actual->reservacion->confirmada)
      {
        enVerde(printf("✔"));
      }
      puts("");

      actual = actual->siguiente;
    }
  }
}

void imprimirMesaFormatoCorto(Mesa *mesa)
{
  enNegritas(printf("Mesa %d ", mesa->numero));
  printf("(%d personas):\n", mesa->capacidad);
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