#include "../Cliente.h"
#include "../../Configuracion.h"
#include "../../Datos/Constructores.h"
#include "../../Datos/Impresion.h"
#include "../../Datos/Lectura.h"
#include "../../Datos/Manejo.h"
#include "../../Interfaz/Interfaz.h"
#include "../../Tiempo/Tiempo.h"
#include <stdio.h>

void hacerReservacion(Restaurante *restaurante)
{
  int continuarOtroHorario;

  int cantidadPersonas;
  Horario horario;
  Cliente cliente;
  Mesa *mesa;
  Reservacion *reservacion;
  Reservacion **reservacionCancelada;

  FechaHora ahora = obtenerAhora();
  IntervaloHoras horasHabiles = {HoraInicio, HoraCierre};
  Fecha fechaMaxima = agregarMeses(&ahora.fecha, MesesParaReservarDespues);
  int capacidadMaxima = calcularMaximaCapacidadMesa(restaurante);

  printf("Máximo de personas: %d\n", capacidadMaxima);
  leerEnteroRango("¿Cúantas personas van a asistir (0 para cancelar)? ", 0, capacidadMaxima, &cantidadPersonas);

  if (cantidadPersonas == 0)
  {
    return;
  }
  else
  {
    do
    {
      puts("");
      horario = leerHorario(&ahora, &horasHabiles, &fechaMaxima, DuracionMinimaReservacion);
      mesa = buscarMesaDisponibleParaReservar(restaurante, cantidadPersonas, &horario);
      if (mesa != NULL)
      {
        printf("Hay mesas disponibles para esa fecha y hora.\n");
        printf("Por favor, ingrese sus datos:\n");
        cliente = leerCliente();

        reservacion = crearReservacion(cantidadPersonas, cliente, horario);
        reservar(mesa, reservacion, reservacionCancelada);

        puts("Reservación preparada:\n");
        printf("Mesa: %d\n", mesa->numero);
        imprimirReservacion(reservacion);

        printf("\nGracias por su preferencia. Conserve su clave de reservación.\n");
        printf("\nTiene 20 minutos a partir de la hora de inicio para llegar, "
               "de lo contrario, su mesa podrá ser reasignada para otra reservación.\n");
        pausar();

        if (*reservacionCancelada != NULL)
        {
          imprimirError(puts("Aviso: Se ha cancelado la siguiente reservación."));
          imprimirReservacion(*reservacionCancelada);
        }

        continuarOtroHorario = 0;
      }
      else
      {
        printf("Lo sentimos, no hay mesas disponibles para esa cantidad de personas en ese horario.\n\n");
        leerSiNo("¿Desea reservar en otro horario [s/n]? ", &continuarOtroHorario);
      }
    } while (continuarOtroHorario);
  }
}