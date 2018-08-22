#include <stdio.h>
#include "../Almacenamiento.h"
#include "../Configuracion.h"
#include "../Interfaz.h"

// El tipo de una función que obtiene una lista de reservaciones desde una mesa.
typedef NodoReservacion *(*ExtractorLista)(Mesa *mesa);
NodoReservacion *extraerListaReservaciones(Mesa *mesa) { return mesa->reservaciones; }
NodoReservacion *extraerListaReservacionesCanceladas(Mesa *mesa) { return mesa->reservacionesCanceladas; }

void guardarReservacionesEnArchivo(Mesa *mesa, const char *formatoArchivo, ExtractorLista extractorLista)
{
  FILE *archivo;
  char nombreArchivo[50];
  NodoReservacion *reservacionActual;

  sprintf(nombreArchivo, formatoArchivo, mesa->numero);
  archivo = fopen(nombreArchivo, "wb");

  if (archivo != NULL)
  {
    reservacionActual = extractorLista(mesa);
    while (reservacionActual != NULL)
    {
      fwrite(reservacionActual->reservacion, sizeof(Reservacion), 1, archivo);
      reservacionActual = reservacionActual->siguiente;
    }

    fclose(archivo);
  }
  else
  {
    imprimirError(printf("No se pudieron guardar las reservaciones de la mesa %d.", mesa->numero));
  }
}

void guardarInformacion(Restaurante *restaurante)
{
  FILE *archivoMesas;
  NodoMesa *mesaActual = restaurante->mesas;

  archivoMesas = fopen(NombreArchivoMesas, "wb");

  if (archivoMesas != NULL)
  {
    while (mesaActual != NULL)
    {
      fwrite(mesaActual->mesa, sizeof(Mesa), 1, archivoMesas);

      guardarReservacionesEnArchivo(mesaActual->mesa, FormatoNombreArchivoReservaciones,
                                    extraerListaReservaciones);

      guardarReservacionesEnArchivo(mesaActual->mesa, FormatoNombreArchivoReservacionesCanceladas,
                                    extraerListaReservacionesCanceladas);

      mesaActual = mesaActual->siguiente;
    }

    fclose(archivoMesas);
  }
  else
  {
    imprimirError(printf("No se pudieron guardar la información de las mesas del restaurante."));
  }
}