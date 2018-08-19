#include <stdio.h>

#include "../Operaciones.h"
#include "../Reservaciones.h"
#include "../Lectura.h"
#include "../Constructores.h"
#include "../Impresion.h"
#include "../Interfaz.h"
#include "../Edicion.h"
#include "../Tiempo/Tiempo.h"

void hacerReservacion(Restaurante *restaurante)
{
  int cantidadPersonas;
  Horario horario;
  Mesa *mesa;
  int continuarOtroHorario;
  Cliente cliente;
  Reservacion *reservacion;
  FechaHora ahora = obtenerAhora();
  IntervaloHoras horasHabiles = {{9, 0}, {18, 0}};
  Fecha fechaMaxima = agregarMeses(&ahora.fecha, 3);
  int capacidadMaxima = obtenerMaximaCapacidadMesa(restaurante);

  printf("Máximo de personas: %d\n", capacidadMaxima);
  leerEnteroRango("¿Cúantas personas van a asistir (0 para cancelar)? ", 0, capacidadMaxima, &cantidadPersonas);

  if (cantidadPersonas == 0)
  {
    return;
  }
  else
  {
    puts("");
    horario = leerHorario(&ahora, &horasHabiles, &fechaMaxima);
    do
    {
      mesa = obtenerMesaDisponibleParaReservar(restaurante, cantidadPersonas, &horario);
      if (mesa != NULL)
      {
        printf("Hay mesas disponibles para esa fecha y hora.\n");
        printf("Por favor, ingrese sus datos:\n");
        cliente = leerCliente();

        reservacion = crearReservacion(cantidadPersonas, cliente, horario);
        reservar(mesa, reservacion);

        puts("Reservación preparada:\n");
        printf("Mesa: %d\n", mesa->numero);
        imprimirReservacion(reservacion);

        printf("\nGracias por su preferencia. Conserve su clave de reservación.\n");
        printf("\nTiene 20 minutos a partir de la hora de inicio para llegar, "
               "de lo contrario, su mesa podrá ser reasignada para otra reservación.\n");

        pausar();
        continuarOtroHorario = 0;
      }
      else
      {
        printf("Lo sentimos, no hay mesas disponibles para esa cantidad de personas en ese horario.\n\n");
        leerSiNo("¿Desea reservar en otro horario [s/n]? ", &continuarOtroHorario);

        if (continuarOtroHorario)
        {
          puts("");
          imprimirHorario(&horario);
          editarHorario(&ahora, &horasHabiles, &fechaMaxima, &horario);
        }
      }
    } while (continuarOtroHorario);
  }
}