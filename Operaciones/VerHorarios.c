#include "../Operaciones.h"

AccionMenu VerHorarios(Restaurante *restaurante)
{
  puts("Los horarios por cada mesa son los siguentes:\n");
  imprimirHorariosRestauranteFormatoCorto(restaurante);
  return Continuar;
}