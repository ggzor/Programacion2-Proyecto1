#include "../Impresion.h"
#include "../../Interfaz/Color.h"
#include "../../Interfaz/Interfaz.h"
#include "../../Tiempo/Impresion.h"
#include "../InformacionReservacion.h"
#include <stdio.h>

void imprimirEstadoReservacion(Reservacion *reservacion)
{
  if (esReservacionCompletada(reservacion))
  {
    enVerde(printf("✔"));
  }
  else if (reservacion->cancelada)
  {
    enRojo(printf("✘"));
  }
  else if (esReservacionAbandonada(reservacion))
  {
    enRojo(printf("🕑"));
  }
  else if (esReservacionCancelable(reservacion))
  {
    enAmarillo(printf("🕑"));
  }
  else if (esReservacionEnCurso(reservacion))
  {
    enVerde(printf("⚑"));
  }
}

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

      imprimirEstadoReservacion(actual->reservacion);

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

  if (mesa->reservacionesCanceladas != NULL)
  {
    puts("");
    enRojo(puts("  Canceladas:"));
    imprimirListaReservacionesFormatoCorto(mesa->reservacionesCanceladas);
  }
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

#define imprimirSimbolo(simbolo, color, nombre, mensaje) \
  {                                                      \
    conEstado(color, printf("   %s   ", simbolo));       \
    enItalica(printf("%s: ", nombre));                   \
    puts(mensaje);                                       \
  }

void imprimirHorariosRestauranteFormatoCorto(Restaurante *restaurante)
{
  enItalica(puts("Leyenda:"));
  imprimirSimbolo("✔", VERDE, "Completada", "Se confirmó la llegada y ya transcurrió el tiempo reservado.");
  imprimirSimbolo("✘", ROJO, "Cancelada", "Se canceló la reservación.");
  imprimirSimbolo("🕑", ROJO, "Abandonada", "No se confirmó la llegada y ya transcurrió el tiempo reservado.");
  imprimirSimbolo("🕑", AMARILLO, "Cancelable", "Aún no se confirma la llegada y ya ha pasado el tiempo de tolerancia.");
  imprimirSimbolo("⚑", VERDE, "En curso", "Se confirmó la llegada, pero aún no transcurré el tiempo reservado.");
  puts("");

  imprimirListaMesasFormatoCorto(restaurante->mesas);
}