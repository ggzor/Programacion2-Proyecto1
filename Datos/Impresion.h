#ifndef _IMPRESION_H_
#define _IMPRESION_H_

#include "Estructuras.h"
#define FormatoClaveReservacion "%04X"

void imprimirCliente(Cliente *cliente);
void imprimirClaveReservacion(int clave);
void imprimirReservacion(Reservacion *reservacion);
void imprimirMesa(Mesa *mesa);
void imprimirRestaurante(Restaurante *restaurante);

void imprimirMesaFormatoCorto(Mesa *mesa);
void imprimirHorariosRestauranteFormatoCorto(Restaurante *restaurante);

#endif