#include <stdio.h>
#include "../Almacenamiento.h"
#include "../Configuracion.h"
#include "../Constructores.h"
#include "../Utilerias/DatosPrueba.h"

Restaurante *cargarInformacion()
{
  FILE *archivo;
  FILE *archivoReservaciones;
  Restaurante *restaurante = crearRestaurante();
  Mesa *mesa;
  Reservacion *reservacion;
  char nombre[50];

  archivo = fopen(NombreArchivoMesas, "rb");

  if (archivo != NULL)
  {
    mesa = (Mesa *)malloc(sizeof(Mesa));

    while (fread(mesa, sizeof(Mesa), 1, archivo) == 1)
    {
      mesa->reservaciones = NULL;
      mesa->reservacionesCanceladas = NULL;

      sprintf(nombre, FormatoNombreArchivoReservaciones, mesa->numero);
      archivoReservaciones = fopen(nombre, "rb");

      if (archivoReservaciones != NULL)
      {
        reservacion = (Reservacion *)malloc(sizeof(Reservacion));
        while (fread(reservacion, sizeof(Reservacion), 1, archivoReservaciones) == 1)
        {
          agregarReservacion(mesa, reservacion);
          reservacion = (Reservacion *)malloc(sizeof(Reservacion));
        }
        free(reservacion);

        fclose(archivoReservaciones);
      }

      sprintf(nombre, FormatoNombreArchivoReservacionesCanceladas, mesa->numero);
      archivoReservaciones = fopen(nombre, "rb");

      if (archivoReservaciones != NULL)
      {
        reservacion = (Reservacion *)malloc(sizeof(Reservacion));
        while (fread(reservacion, sizeof(Reservacion), 1, archivoReservaciones) == 1)
        {
          agregarReservacionCancelada(mesa, reservacion);
          reservacion = (Reservacion *)malloc(sizeof(Reservacion));
        }
        free(reservacion);

        fclose(archivoReservaciones);
      }

      agregarMesa(restaurante, mesa);
      mesa = (Mesa *)malloc(sizeof(Mesa));
    }

    free(mesa);
    fclose(archivo);
  }
  else
  {
    free(restaurante);
    restaurante = obtenerDatos();
  }

  return restaurante;
}