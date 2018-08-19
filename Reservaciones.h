#ifndef _RESERVACIONES_H_
#define _RESERVACIONES_H_

#include "Estructuras.h"
#include "Tiempo/Horario.h"

int obtenerMaximaCapacidadMesa(Restaurante *restaurante);
Mesa *obtenerMesaDisponibleParaReservar(Restaurante *restaurante, int cantidadPersonas, Horario *horario);
void reservar(Mesa *mesa, Reservacion *reservacion);

#endif