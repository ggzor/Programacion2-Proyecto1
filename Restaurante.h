#ifndef _RESTAURANTE_H_
#define _RESTAURANTE_H_

#include "Estructuras.h"

int obtenerMaximaCapacidadMesa(Restaurante *restaurante);
int puedeReservarseEn(Restaurante *restaurante, Intervalo intervalo);
void reservar(Restaurante *restaurante, Reservacion *reservacion);

#endif