#include <stdio.h>
#include "../Almacenamiento.h"
#include "../Configuracion.h"
#include "../Constructores.h"
#include "../Utilerias/DatosPrueba.h"

typedef void (*AgregadorLista)(Mesa *, Reservacion *);

void cargarArchivoReservaciones(Mesa *mesa, const char *formatoArchivo, AgregadorLista agregador)
{
  FILE *archivo;
  char nombre[50];
  Reservacion *reservacion;

  sprintf(nombre, formatoArchivo, mesa->numero);
  archivo = fopen(nombre, "rb");

  if (archivo != NULL)
  {
    reservacion = (Reservacion *)malloc(sizeof(Reservacion));
    while (fread(reservacion, sizeof(Reservacion), 1, archivo) == 1)
    {
      agregador(mesa, reservacion);
      reservacion = (Reservacion *)malloc(sizeof(Reservacion));
    }

    free(reservacion);
    fclose(archivo);
  }
}

Restaurante *cargarInformacion()
{
  FILE *archivo;
  Restaurante *restaurante = crearRestaurante();
  Mesa *mesa;

  archivo = fopen(NombreArchivoMesas, "rb");

  if (archivo != NULL)
  {
    mesa = (Mesa *)malloc(sizeof(Mesa));

    while (fread(mesa, sizeof(Mesa), 1, archivo) == 1)
    {
      mesa->reservaciones = NULL;
      mesa->reservacionesCanceladas = NULL;

      cargarArchivoReservaciones(mesa, FormatoNombreArchivoReservaciones, agregarReservacion);
      cargarArchivoReservaciones(mesa, FormatoNombreArchivoReservacionesCanceladas, agregarReservacionCancelada);

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