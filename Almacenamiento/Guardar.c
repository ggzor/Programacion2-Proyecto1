#include <stdio.h>
#include "../Configuracion.h"
#include "../Almacenamiento.h"

NodoReservacion *extraerListaReservaciones(Mesa *mesa)
{
  return mesa->reservaciones;
}

NodoReservacion *extraerListaReservacionesCanceladas(Mesa *mesa)
{
  return mesa->reservacionesCanceladas;
}

typedef NodoReservacion *(*ExtractorLista)(Mesa *mesa);
void guardarArchivoReservaciones(Mesa *mesa, const char *formatoArchivo, ExtractorLista extractorLista)
{
  FILE *archivo;
  char nombre[50];
  NodoReservacion *reservacionActual;

  sprintf(nombre, formatoArchivo, mesa->numero);
  archivo = fopen(nombre, "wb");

  reservacionActual = extractorLista(mesa);
  while (reservacionActual != NULL)
  {
    fwrite(reservacionActual->reservacion, sizeof(Reservacion), 1, archivo);
    reservacionActual = reservacionActual->siguiente;
  }

  fclose(archivo);
}

void guardarInformacion(Restaurante *restaurante)
{
  FILE *archivoMesas;
  NodoMesa *mesaActual = restaurante->mesas;

  archivoMesas = fopen(NombreArchivoMesas, "wb");

  while (mesaActual != NULL)
  {
    fwrite(mesaActual->mesa, sizeof(Mesa), 1, archivoMesas);

    guardarArchivoReservaciones(mesaActual->mesa, FormatoNombreArchivoReservaciones,
                                extraerListaReservaciones);

    guardarArchivoReservaciones(mesaActual->mesa, FormatoNombreArchivoReservacionesCanceladas,
                                extraerListaReservacionesCanceladas);

    mesaActual = mesaActual->siguiente;
  }

  fclose(archivoMesas);
}