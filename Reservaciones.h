#ifndef _RESERVACIONES_H_
#define _RESERVACIONES_H_

#include "Estructuras.h"
#include "Tiempo/Horario.h"

int obtenerMaximaCapacidadMesa(Restaurante *restaurante);
int obtenerCantidadMesas(Restaurante *restaurante);
Mesa *obtenerMesa(Restaurante *restaurante, int numeroMesa);
Mesa *obtenerMesaDisponibleParaReservar(Restaurante *restaurante, int cantidadPersonas, Horario *horario);
void reservar(Mesa *mesa, Reservacion *reservacion);
int esReservacionPasada(Reservacion *reservacion);
int esReservacionCancelable(Reservacion *reservacion);

#endif