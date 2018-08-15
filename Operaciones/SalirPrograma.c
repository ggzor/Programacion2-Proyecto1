#include "../Operaciones.h"
#include "../Almacenamiento.h"

AccionMenu SalirPrograma(Restaurante *restaurante)
{
  puts("Guardando información...");
  guardarInformacion(restaurante);
  puts("Información guardada.");
  return Salir;
}