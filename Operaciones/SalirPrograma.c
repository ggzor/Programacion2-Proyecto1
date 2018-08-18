#include "../Operaciones.h"
#include "../Almacenamiento.h"

void salirPrograma(Restaurante *restaurante)
{
  puts("Guardando información...");
  guardarInformacion(restaurante);
  puts("Información guardada.");
}