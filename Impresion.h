#ifndef _IMPRESION_H_
#define _IMPRESION_H_

#include "./Estructuras.h"

void imprimirCliente(Cliente cliente);

void imprimirFecha(Fecha fecha);
void imprimirHora(Hora hora);
void imprimirIntervalo(Intervalo intervalo);

void imprimirReservacion(Reservacion *reservacion);

void imprimirListaReservaciones(NodoReservacion *lista);
void imprimirMesa(Mesa *mesa);

void imprimirListaMesas(NodoMesa *lista);
void imprimirRestaurante(Restaurante *restaurante);

#endif