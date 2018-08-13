#ifndef _MANEJO_ESTRUCTURAS_
#define _MANEJO_ESTRUCTURAS_

#include "./Estructuras.h"

Reservacion *crearReservacion(Cliente cliente, Intervalo intervalo);
NodoReservacion *crearNodoReservacion(Reservacion *reservacion);

Mesa *crearMesa(int numero, int capacidad);
NodoMesa *crearNodoMesa(Mesa *mesa);

void agregarReservacion(Mesa *mesa, Reservacion *reservacion);
void agregarReservacionCancelada(Mesa *mesa, Reservacion *reservacion);
void agregarMesa(Restaurante *restaurante, Mesa *mesa);

Restaurante *crearRestaurante();

#endif