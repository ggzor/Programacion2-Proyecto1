#ifndef _IMPRESION_H_
#define _IMPRESION_H_

#include <stdio.h>
#include "Estructuras.h"

void imprimirCliente(Cliente *cliente);

void imprimirFecha(Fecha *fecha);
void imprimirIntervaloFechas(const char *mensaje, Fecha *minimo, Fecha *maximo);

void imprimirHora(Hora *hora);
void imprimirIntervaloHoras(const char *mensaje, Hora *minimo, Hora *maximo);

void imprimirIntervalo(Intervalo *intervalo);

void imprimirReservacion(Reservacion *reservacion);
void imprimirMesa(Mesa *mesa);
void imprimirRestaurante(Restaurante *restaurante);


void imprimirMesaFormatoCorto(Mesa *mesa);
void imprimirHorariosRestauranteFormatoCorto(Restaurante *restaurante);

#endif