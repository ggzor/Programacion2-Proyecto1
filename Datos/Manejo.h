#ifndef _DATOS_MANEJO_H_
#define _DATOS_MANEJO_H_

#include "Estructuras.h"
#include "../Tiempo/Horario.h"

int calcularMaximaCapacidadMesa(Restaurante *restaurante);
int calcularCantidadMesas(Restaurante *restaurante);
Mesa *buscarMesa(Restaurante *restaurante, int numeroMesa);
Mesa *buscarMesaDisponibleParaReservar(Restaurante *restaurante, int cantidadPersonas, Horario *horario);

Reservacion *buscarReservacionPorClave(Restaurante *restaurante, int clave);
void reservar(Mesa *mesa, Reservacion *reservacion, Reservacion **cancelada);

#endif