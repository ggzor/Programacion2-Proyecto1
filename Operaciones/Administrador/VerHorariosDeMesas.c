#include "../Administrador.h"
#include "../../Datos/Impresion.h"
#include "../../Interfaz/Interfaz.h"
#include <stdio.h>

void verHorariosDeMesas(Restaurante *restaurante)
{
  puts("Los horarios por cada mesa son los siguientes:\n");
  imprimirHorariosRestauranteFormatoCorto(restaurante);

  pausar();
}