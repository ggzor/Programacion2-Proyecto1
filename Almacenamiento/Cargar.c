#include <stdio.h>
#include "../Almacenamiento.h"
#include "../Configuracion.h"
#include "../Constructores.h"
#include "../Utilerias/DatosPrueba.h"

// El tipo de una función que puede agregar una reservación a una mesa
typedef void (*AgregadorLista)(Mesa *, Reservacion *);

void cargarReservacionesDesdeArchivo(Mesa *mesa, const char *formatoArchivo, AgregadorLista agregador)
{
  FILE *archivo;
  char nombreArchivo[50];
  Reservacion *reservacion;

  sprintf(nombreArchivo, formatoArchivo, mesa->numero);
  archivo = fopen(nombreArchivo, "rb");

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

      cargarReservacionesDesdeArchivo(mesa, FormatoNombreArchivoReservaciones, agregarReservacion);
      cargarReservacionesDesdeArchivo(mesa, FormatoNombreArchivoReservacionesCanceladas, agregarReservacionCancelada);

      agregarMesa(restaurante, mesa);
      mesa = (Mesa *)malloc(sizeof(Mesa));
    }

    free(mesa);
    fclose(archivo);
  }
  else
  {
    // Liberar la memoria reservada
    free(restaurante);
    // Cargar información de prueba
    restaurante = obtenerDatos();
  }

  return restaurante;
}