#include <stdio.h>
#include "../Configuracion.h"
#include "../Almacenamiento.h"

void guardarInformacion(Restaurante *restaurante)
{
  FILE *archivoMesas;
  FILE *archivoReservaciones;
  NodoMesa *mesaActual = restaurante->mesas;
  NodoReservacion *reservacionActual;
  char nombre[50];

  archivoMesas = fopen(NombreArchivoMesas, "wb");

  while (mesaActual != NULL)
  {
    fwrite(mesaActual->mesa, sizeof(Mesa), 1, archivoMesas);

    sprintf(nombre, FormatoNombreArchivoReservaciones, mesaActual->mesa->numero);
    archivoReservaciones = fopen(nombre, "wb");

    reservacionActual = mesaActual->mesa->reservaciones;
    while (reservacionActual != NULL)
    {
      fwrite(reservacionActual->reservacion, sizeof(Reservacion), 1, archivoReservaciones);
      reservacionActual = reservacionActual->siguiente;
    }

    fclose(archivoReservaciones);

    sprintf(nombre, FormatoNombreArchivoReservacionesCanceladas, mesaActual->mesa->numero);
    archivoReservaciones = fopen(nombre, "wb");

    reservacionActual = mesaActual->mesa->reservacionesCanceladas;
    while (reservacionActual != NULL)
    {
      fwrite(reservacionActual->reservacion, sizeof(Reservacion), 1, archivoReservaciones);
      reservacionActual = reservacionActual->siguiente;
    }

    fclose(archivoReservaciones);

    mesaActual = mesaActual->siguiente;
  }

  fclose(archivoMesas);
}