#ifndef _COLOR_H_
#define _COLOR_H_

#define ROJO "91"
#define VERDE "92"
#define AMARILLO "33"
#define AZUL "94"

#define seleccionarColor(color) printf("\e[" color "m")
#define reestablecerColor() seleccionarColor("0")
#define conColor(color, codigo) { seleccionarColor(color); {codigo;}; reestablecerColor(); }

#define enRojo(codigo) conColor(ROJO, codigo)
#define enVerde(codigo) conColor(VERDE, codigo)
#define enAmarillo(codigo) conColor(AMARILLO, codigo)
#define enAzul(codigo) conColor(AZUL, codigo)

#endif