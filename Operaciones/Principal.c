#include <stdio.h>
#include "Principal.h"
#include "../Impresion.h"

AccionMenu BuscarReservacion(Restaurante *restaurante)
{
  
  return Continuar;
}

AccionMenu VerHorarios(Restaurante *restaurante)
{
  imprimirHorariosRestauranteFormatoCorto(restaurante);
  return Continuar;
}

AccionMenu SalirPrograma(Restaurante *restaurante)
{
  printf("Guardando información del restaurante...\n");
  guardarInformacion(restaurante);
  printf("Listo.\n");

  return Salir;
}