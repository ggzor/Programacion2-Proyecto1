#include <stdio.h>
#include "Menu.h"
#include "../Interfaz.h"

void verHorariosDeMesas(Restaurante *restaurante)
{
  puts("Los horarios por cada mesa son los siguentes:\n");
  imprimirHorariosRestauranteFormatoCorto(restaurante);

  pausar();
}