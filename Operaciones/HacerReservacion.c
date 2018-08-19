#include <stdio.h>

#include "../Operaciones.h"
#include "../Reservaciones.h"
#include "../Lectura.h"
#include "../Constructores.h"
#include "../Impresion.h"
#include "../Interfaz.h"
#include "../Edicion.h"

void hacerReservacion(Restaurante *restaurante)
{
  int cantidadPersonas;
  Horario horario;
  int continuarOtroHorario;
  Mesa *mesa;
  Cliente cliente;
  Reservacion *reservacion;
  IntervaloHoras horasHabiles = {{9, 0}, {18, 0}};
  Fecha fechaInicio = {2018, 8, 11};
  IntervaloFechas fechasDisponibles = {fechaInicio, agregarMeses(&fechaInicio, 3)};
  int capacidadMaxima = obtenerMaximaCapacidadMesa(restaurante);

  printf("¿Cúantas personas van a asistir (Máximo %d)? ", capacidadMaxima);
  scanf("%d%*c", &cantidadPersonas);

  if (1 <= cantidadPersonas && cantidadPersonas <= capacidadMaxima)
  {
    puts("");
    horario = leerHorario(&fechasDisponibles, &horasHabiles);
    do
    {
      if (puedeReservarseEn(restaurante, cantidadPersonas, &horario))
      {
        printf("Hay mesas disponibles para esa fecha y hora.\n");
        printf("Por favor, ingrese sus datos:\n");
        cliente = leerCliente();

        reservacion = crearReservacion(cliente, horario);
        reservar(restaurante, cantidadPersonas, reservacion);
        mesa = buscarMesaReservacion(restaurante, reservacion);

        puts("Reservación preparada:\n");
        printf("Mesa: %d\n", mesa->numero);
        imprimirReservacion(reservacion);

        printf("\nGracias por su preferencia. Conserve su clave de reservación.\n");
        printf("\nTiene 20 minutos a partir de la hora de inicio para llegar, "
               "de lo contrario, su mesa podrá ser reasignada para otra reservación.\n");

        continuarOtroHorario = 0;
      }
      else
      {
        printf("Lo sentimos, no hay mesas disponibles en ese fecha y en ese horario.\n\n");
        leerSiNo("¿Desea reservar en otro horario [s/n]? ", &continuarOtroHorario);

        if (continuarOtroHorario)
        {
          puts("");
          imprimirHorario(&horario);
          editarHorario(&horario, &fechasDisponibles, &horasHabiles);
        }
      }
    } while (continuarOtroHorario);
  }
  else
  {
    printf("La cantidad de personas debe estar entre 1 y %d.\n", capacidadMaxima);
  }
}