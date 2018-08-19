#ifndef _MANEJO_ESTRUCTURAS_
#define _MANEJO_ESTRUCTURAS_

#include <stdlib.h>
#include "./Estructuras.h"

Reservacion *crearReservacion(int cantidadPersonas, Cliente cliente, Horario horario);
NodoReservacion *crearNodoReservacion(Reservacion *reservacion);

Mesa *crearMesa(int numero, int capacidad);
NodoMesa *crearNodoMesa(Mesa *mesa);
void agregarReservacion(Mesa *mesa, Reservacion *reservacion);
void agregarReservacionCancelada(Mesa *mesa, Reservacion *reservacion);

Restaurante *crearRestaurante();
void agregarMesa(Restaurante *restaurante, Mesa *mesa);

#endif