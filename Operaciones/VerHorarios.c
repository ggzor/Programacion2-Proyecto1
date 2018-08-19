#include <stdio.h>
#include "../Operaciones.h"
#include "../Interfaz.h"

void verHorarios(Restaurante *restaurante)
{
  puts("Los horarios por cada mesa son los siguentes:\n");
  imprimirHorariosRestauranteFormatoCorto(restaurante);

  pausar();
}