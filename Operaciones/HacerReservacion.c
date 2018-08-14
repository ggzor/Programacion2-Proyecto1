#include <stdio.h>

#include "Principal.h"
#include "../Restaurante.h"
#include "../Lectura.h"
#include "../Constructores.h"
#include "../Impresion.h"
#include "../Intervalos.h"

AccionMenu HacerReservacion(Restaurante *restaurante)
{
  int cantidadPersonas;
  Intervalo intervalo;
  int continuarOtroHorario;
  Mesa *mesa;
  Cliente cliente;
  Reservacion *reservacion;
  Hora horarioInicio = { 9, 0 }, horarioFin = { 18, 0 };
  Fecha fechaInicio = obtenerFechaHoy(), fechaFin = agregarMeses(3, fechaInicio);

  int capacidadMaxima = obtenerMaximaCapacidadMesa(restaurante);

  printf("¿Cúantas personas van a asistir (Máximo %d)? ", capacidadMaxima);
  scanf("%d%*c", &cantidadPersonas);

  if (1 <= cantidadPersonas && cantidadPersonas <= capacidadMaxima)
  {
    do
    {
      printf("¿En qué fecha y hora quiere reservar?\n");
      intervalo = leerIntervalo(&fechaInicio, &fechaFin, &horarioInicio, &horarioFin);

      if (puedeReservarseEn(restaurante, intervalo))
      {
        printf("Hay mesas disponibles para esa fecha y hora.\n");
        printf("Por favor, ingrese sus datos:\n");
        cliente = leerCliente();

        printf("Realizando reservación...\n");
        reservacion = crearReservacion(cliente, intervalo);
        reservar(restaurante, reservacion);
        printf("Reservación preparada:\n");
        imprimirReservacion(reservacion);
        printf("\nGracias por su preferencia. Conserve su clave de reservación.\n");
        printf("\nTiene 20 minutos a partir de la hora de inicio para llegar, "
               "de lo contrario, su mesa podrá ser reasignada para otra reservación.\n");
      }
      else
      {
        printf("Lo sentimos, no hay mesas disponibles en ese horario.\n\n");
        printf("¿Desea reservar en otro horario [s/n]? ");
        continuarOtroHorario = leerSiNo();
      }
    } while (continuarOtroHorario == 1);
  }
  else
  {
    printf("La cantidad de personas debe estar entre 1 y %d.\n", capacidadMaxima);
  }

  return Continuar;
}