#include <stdio.h>
#include <stdlib.h>

#include "./Estructuras.h"
#include "./Informacion.h"

void intentarReservar(Restaurante *restaurante){
    int numeroPersonas;
    verificarMesaConCapacidad(restaurante, numeroPersonas);
    Intervalo horario = leerHorario();
    Mesa *mesa = obtenerMesaDisponibleEnHorario(restaurante, horario);
    Cliente cliente = leerCliente();
    Reservacion reservacion = { horario, cliente };
    realizarReservacion(mesa, reservacion);
    imprimirRecibo(mesa, reservacion);
}

int main(int argc, char **argv)
{
    int i;
    Restaurante *restaurante;
    restaurante = cargarInformacion();

    hacerReservacion(restaurante, solicitarReservacion());

    printf(
        "1.- Hacer reservación\n"
        "2.- Cancelar reservación\n"
        "3.- Buscar reservación\n"
        "4.- Reservaciones canceladas\n"
        "5.- Ver horarios de mesa\n"
        "6.- Salir\n");

    guardarInformacion(restaurante);
    return 0;
}


Cliente leerCliente();
Hora leerHora();
Fecha leerFecha();
Intervalo leerIntervalo();
