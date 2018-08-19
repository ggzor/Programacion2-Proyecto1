#include <stdio.h>
#include "../Operaciones.h"

void verHorarios(Restaurante *restaurante)
{
  puts("Los horarios por cada mesa son los siguentes:\n");
  imprimirHorariosRestauranteFormatoCorto(restaurante);

  puts("Presione enter para volver al menú...");
  getchar();
}