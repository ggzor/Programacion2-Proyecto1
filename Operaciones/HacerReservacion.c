#include <stdio.h>

#include "../Operaciones.h"
#include "../Reservaciones.h"
#include "../Lectura.h"
#include "../Constructores.h"
#include "../Impresion.h"
#include "../Tiempo.h"
#include "../Interfaz.h"
#include "../Edicion.h"

AccionMenu HacerReservacion(Restaurante *restaurante)
{
  int cantidadPersonas;
  Intervalo intervalo;
  int continuarOtroHorario;
  Mesa *mesa;
  Cliente cliente;
  Reservacion *reservacion;
  Hora horarioInicio = {9, 0}, horarioFin = {18, 0};
  Fecha fechaInicio = obtenerFechaHoy(), fechaFin = agregarMeses(3, fechaInicio);

  int capacidadMaxima = obtenerMaximaCapacidadMesa(restaurante);

  printf("¿Cúantas personas van a asistir (Máximo %d)? ", capacidadMaxima);
  scanf("%d%*c", &cantidadPersonas);

  if (1 <= cantidadPersonas && cantidadPersonas <= capacidadMaxima)
  {
    puts("");
    intervalo = leerIntervalo(&fechaInicio, &fechaFin, &horarioInicio, &horarioFin);
    do
    {
      if (puedeReservarseEn(restaurante, cantidadPersonas, &intervalo))
      {
        printf("Hay mesas disponibles para esa fecha y hora.\n");
        printf("Por favor, ingrese sus datos:\n");
        cliente = leerCliente();

        reservacion = crearReservacion(cliente, intervalo);
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
          imprimirIntervalo(&intervalo);
          editarIntervalo(&intervalo, &fechaInicio, &fechaFin, &horarioInicio, &horarioFin);
        }
      }
    } while (continuarOtroHorario);
  }
  else
  {
    printf("La cantidad de personas debe estar entre 1 y %d.\n", capacidadMaxima);
  }

  return Continuar;
}