#include "../Pruebas.h"
#include "../../Datos/Lectura.h"
#include "../../Interfaz/Interfaz.h"
#include "../../Tiempo/Impresion.h"
#include "../../Tiempo/ManejoTiempo.h"
#include <stdio.h>

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
  puts("");

  establecerAhora(nueva);

  pausar();
}