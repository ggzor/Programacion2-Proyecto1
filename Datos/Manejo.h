#ifndef _DATOS_MANEJO_H_
#define _DATOS_MANEJO_H_

#include "Estructuras.h"
#include "../Tiempo/Horario.h"

int calcularMaximaCapacidadMesa(Restaurante *restaurante);
int calcularCantidadMesas(Restaurante *restaurante);
Mesa *buscarMesa(Restaurante *restaurante, int numeroMesa);
Mesa *buscarMesaDisponibleParaReservar(Restaurante *restaurante, int cantidadPersonas, Horario *horario);

int esReservacionPasada(Reservacion *reservacion);
int esReservacionCancelable(Reservacion *reservacion);
Reservacion *buscarReservacionPorClave(Restaurante *restaurante, int clave, int *estaCancelada);
void reservar(Mesa *mesa, Reservacion *reservacion, Reservacion **cancelada);

#endif