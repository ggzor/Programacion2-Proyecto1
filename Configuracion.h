#ifndef _CONFIGURACION_H_
#define _CONFIGURACION_H_

#define HoraInicio { 9, 00 }
#define HoraCierre { 18, 00 }
#define MesesParaReservarDespues 3
#define DuracionMinimaReservacion 30
#define ToleranciaEnMinutos 20
#define CantidadDigitosClave 4

#include <time.h>
#include <stdlib.h>

#define cargarConfiguracion() srand(time(NULL))

#endif