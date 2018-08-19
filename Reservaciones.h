#ifndef _RESERVACIONES_H_
#define _RESERVACIONES_H_

#include "Estructuras.h"

int obtenerMaximaCapacidadMesa(Restaurante *restaurante);
int puedeReservarseEn(Restaurante *restaurante, int capacidadMesa, Horario *horario);
void reservar(Restaurante *restaurante, int capacidad, Reservacion *reservacion);

Reservacion *buscarReservacionRestaurante(Restaurante *restaurante, int clave);
Reservacion *buscarReservacionCancelada(Restaurante *restaurante, int clave);
Mesa *buscarMesaReservacion(Restaurante *restaurante, Reservacion *reservacion);

#endif