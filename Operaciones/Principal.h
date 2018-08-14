#ifndef _OPERACIONES_PRINCIPAL_H_
#define _OPERACIONES_PRINCIPAL_H_

#include "../Menus/MenuPrincipal.h"

AccionMenu HacerReservacion(Restaurante *restaurante);
AccionMenu BuscarReservacion(Restaurante *restaurante);
AccionMenu VerHorarios(Restaurante *restaurante);
AccionMenu SalirPrograma(Restaurante *restaurante);

#endif