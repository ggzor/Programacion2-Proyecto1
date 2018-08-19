#include "../Operaciones.h"
#include "../Lectura.h"
#include "../Tiempo/Tiempo.h"
#include "../Interfaz.h"

void establecerTiempo(Restaurante *restaurante)
{
  IntervaloFechas limitesFecha = {
      {2000, 1, 1},
      {2100, 1, 1}};
  IntervaloHoras todoElDia = {
      {0, 0}, {23, 59}};
  FechaHora nueva;

  puts("Seleccione los valores para el tiempo actual: ");
  nueva.fecha = leerFecha(&limitesFecha);
  nueva.hora = leerHora(&todoElDia);

  printf("Estableciendo tiempo: ");
  imprimirFechaHora(&nueva);

  establecerAhora(nueva);

  pausar();
}