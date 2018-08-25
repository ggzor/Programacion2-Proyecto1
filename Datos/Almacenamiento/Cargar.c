#include "../Almacenamiento.h"
#include "../Constructores.h"
#include "../Estructuras.h"
#include "NombresArchivos.h"
#include "../Pruebas.h"

#include <stdio.h>

// El tipo de una función que puede agregar una reservación a una mesa
typedef void (*AgregadorReservacion)(Mesa *, Reservacion *);

void cargarReservacionesDesdeArchivo(Mesa *mesa, const char *formatoArchivo, AgregadorReservacion agregador)
{
  FILE *archivo;
  char nombreArchivo[50];
  Reservacion *reservacion;

  // Generar nombre de archivo
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

    // Liberar reservacion creada de forma adicional
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

    // Liberar mesa creada de forma adicional
    free(mesa);

    fclose(archivo);
  }
  else
  {
    // Liberar la memoria reservada para la carga desde el archivo
    free(restaurante);

    // Cargar información de prueba
    restaurante = obtenerDatosPrueba();
  }

  return restaurante;
}