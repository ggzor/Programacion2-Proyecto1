#ifndef _RESTAURANTE_H_
#define _RESTAURANTE_H_

#include "Estructuras.h"

int obtenerMaximaCapacidadMesa(Restaurante *restaurante);
int puedeReservarseEn(Restaurante *restaurante, int capacidadMesa, Intervalo *intervalo);
void reservar(Restaurante *restaurante, int capacidad, Reservacion *reservacion);

Reservacion *buscarReservacion(Restaurante *restaurante, int clave);
Reservacion *buscarReservacionCancelada(Restaurante *restaurante, int clave);
Mesa *buscarMesaReservacion(Restaurante *restaurante, Reservacion *reservacion);

#endif