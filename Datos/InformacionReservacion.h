#ifndef _INFORMACION_RESERVACION_H_
#define _INFORMACION_RESERVACION_H_

#include "Estructuras.h"

int esReservacionPasada(Reservacion *reservacion);
int esReservacionAbandonada(Reservacion *reservacion);
int esReservacionCompletada(Reservacion *reservacion);
int esReservacionEnCurso(Reservacion *reservacion);
int esReservacionCancelable(Reservacion *reservacion);

#endif