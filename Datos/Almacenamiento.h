#ifndef _ALMACENAMIENTO_H
#define _ALMACENAMIENTO_H

#include "Estructuras.h"

/* Carga la información del restaurante desde los archivos, o si no los encuentra, 
 * regresa información de prueba.
*/
Restaurante *cargarInformacion();

/* Guarda la información del restaurante en los archivos correspondientes.
*/
void guardarInformacion(Restaurante *restaurante);

#endif