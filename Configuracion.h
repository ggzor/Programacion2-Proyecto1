#ifndef _CONFIGURACION_H_
#define _CONFIGURACION_H_

#define DigitosClaveReservacion 4
#define NombreArchivoMesas "Mesas.dat"
#define FormatoNombreArchivoReservaciones "Reservaciones_%d.dat"
#define FormatoNombreArchivoReservacionesCanceladas "ReservacionesCanceladas_%d.dat"

#include <time.h>
#include <stdlib.h>

#define cargarConfiguracion() srand(time(NULL))

#endif