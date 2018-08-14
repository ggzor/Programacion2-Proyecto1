#ifndef _LECTURA_H_
#define _LECTURA_H_

#include <stdio.h>
#include "./Estructuras.h"

Cliente leerCliente();
Hora leerHora(Hora *minimo, Hora *maximo);
Fecha leerFecha(Fecha *minimo, Fecha *maximo);
Intervalo leerIntervalo(Fecha *fechaMinima, Fecha *fechaMaxima, Hora *horaMinima, Hora *horaMaxima);

#endif