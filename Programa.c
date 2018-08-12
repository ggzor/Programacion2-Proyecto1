#include <stdio.h>

#include "./Estructuras.h"
#include "./DatosPrueba.h"
#include "./Impresion.h"

int main(int argc, char **argv)
{
    Restaurante *restaurante = obtenerDatos();
    imprimirRestaurante(restaurante);
    
    return 0;
}
