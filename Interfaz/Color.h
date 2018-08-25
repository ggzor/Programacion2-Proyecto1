#ifndef _COLOR_H_
#define _COLOR_H_

#define NEGRITAS "1"
#define ROJO "91"
#define VERDE "92"
#define AMARILLO "33"
#define AZUL "94"
#define MORADO "95"

#define seleccionarEstadoConsola(estado) printf("\e[" estado "m")
#define reestablecerEstado() seleccionarEstadoConsola("0")
#define conEstado(estado, codigo) { seleccionarEstadoConsola(estado); {codigo;}; reestablecerEstado(); }

#define enNegritas(codigo) conEstado(NEGRITAS, codigo)
#define enRojo(codigo) conEstado(ROJO, codigo)
#define enVerde(codigo) conEstado(VERDE, codigo)
#define enAmarillo(codigo) conEstado(AMARILLO, codigo)
#define enAzul(codigo) conEstado(AZUL, codigo)
#define enMorado(codigo) conEstado(MORADO, codigo)

#endif