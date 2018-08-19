#ifndef _IMPRESION_H_
#define _IMPRESION_H_

#include <stdio.h>
#include "Estructuras.h"
#include "Tiempo/Horario.h"
#include "Tiempo/IntervaloFechas.h"

void imprimirCliente(Cliente *cliente);

void imprimirFecha(Fecha *fecha);
void imprimirIntervaloFechas(const char *mensaje, IntervaloFechas *intervalo);

void imprimirHora(Hora *hora);
void imprimirIntervaloHoras(const char *mensaje, IntervaloHoras *intervalo);

void imprimirHorario(Horario *horario);

void imprimirReservacion(Reservacion *reservacion);
void imprimirMesa(Mesa *mesa);
void imprimirRestaurante(Restaurante *restaurante);


void imprimirMesaFormatoCorto(Mesa *mesa);
void imprimirHorariosRestauranteFormatoCorto(Restaurante *restaurante);

#endif